package main

import (
	"fmt"
	"image"
	"image/color"
	"image/color/palette"
	"image/draw"
	"image/jpeg"
	"image/png"
	"math"
	"math/rand"
	"os"
	"strconv"
	"time"
)

func main() {

	rand.Seed(time.Now().Unix())

	fmt.Println("Something you can do")
	fmt.Println("A: Create a random rect on an image")
	fmt.Println("B: Merge two pictures into one")
	fmt.Println("C1: Flip horizontal; C2: Flip vertical")
	fmt.Println("D: Rotate (clockwise, 90°)")
	fmt.Println("E: Convert an image to a gray scale image")
	fmt.Println("F: Zoom in or out (losing clarity)")
	fmt.Println("G: Cut picture to several parts by color (doesn't work well)")
	fmt.Println("H: Blur picture")

	var s string
	fmt.Scanln(&s)

	if s == "A" || s == "a" {
		Random_color_rect()
	} else if s == "B" || s == "b" {
		Merge()
	} else if s == "C1" || s == "c1" || s == "C2" || s == "c2" {
		Flip(s)
	} else if s == "D" || s == "d" {
		rotate()
	} else if s == "E" || s == "e" {
		Turn_gray()
	} else if s == "F" || s == "f" {
		Zoom()
	} else if s == "G" || s == "g" {
		Cut_by_color()
	} else if s == "H" || s == "h" {
		Blur()
	}

}

//some Common Functions (first letter lowercase)

func handle_error(err error) {
	if err != nil {
		fmt.Println(err)
	}
}

func decode_img(f *os.File, f_name string) image.Image {
	var img image.Image
	var err error

	if f_name[len(f_name)-3:] == "jpg" || f_name[len(f_name)-4:] == "jpeg" {
		img, err = jpeg.Decode(f)
		handle_error(err)
	} else if f_name[len(f_name)-3:] == "png" {
		img, err = png.Decode(f)
		handle_error(err)
	}

	return img
}

func encode_img(f *os.File, f_name string, img image.Image) {
	var err error
	if f_name[len(f_name)-3:] == "jpg" || f_name[len(f_name)-4:] == "jpeg" {
		err = jpeg.Encode(f, img, nil) //nil for DefaultQuality
		handle_error(err)
	} else if f_name[len(f_name)-3:] == "png" {
		err = png.Encode(f, img)
		handle_error(err)
	}
}

func get_src_img() image.Image {

	fmt.Println("Input the name of the original image (only accept .png/.jpg/.jpeg file)") //get file name
	var file_name string
	fmt.Scanln(&file_name)

	src_file, err := os.Open(file_name) //read file
	handle_error(err)
	defer src_file.Close()

	img := decode_img(src_file, file_name) //turn the img file into data

	return img
}

func get_dst_file(img draw.Image) {

	fmt.Println("Input the name of the new image (only accept .png/.jpg/.jpeg file)")
	var file_name string
	fmt.Scanln(&file_name)

	dst_file, err := os.Create(file_name)
	handle_error(err)
	defer dst_file.Close()

	encode_img(dst_file, file_name, img)
}

func color_distance(color_1, color_2 color.Color) float64 {
	/* to distinguish how much is the two colors' difference */

	type RGB struct {
		R uint32
		G uint32
		B uint32
	}
	var RGB_1, RGB_2 RGB

	RGB_1.R, RGB_1.G, RGB_1.B, _ = color_1.RGBA()
	RGB_2.R, RGB_2.G, RGB_2.B, _ = color_2.RGBA()
	/*get r,g,b of two color and calculate the difference*/
	r := math.Abs(float64(RGB_1.R) - float64(RGB_2.R))
	g := math.Abs(float64(RGB_1.G) - float64(RGB_2.G))
	b := math.Abs(float64(RGB_1.B) - float64(RGB_2.B))

	return (r + g + b) //plus r,g,b difference as the total difference
}

//Functions with specific functions (First letter uppercase)

func Random_color_rect() {

	img := get_src_img()

	color_pic := image.NewRGBA(image.Rect(0, 0, rand.Intn(img.Bounds().Dx()), rand.Intn(img.Bounds().Dy())))
	//color size is random and smaller than src img
	color := palette.Plan9[rand.Intn(256)]
	//random color
	draw.Draw(color_pic, color_pic.Bounds(), &image.Uniform{color}, image.ZP, draw.Src)
	//fill color//image.ZP is Point{0,0}
	img_draw := image.NewRGBA(img.Bounds())
	draw.Draw(img_draw, img_draw.Bounds(), img, image.ZP, draw.Src)
	//turn image.Image into draw.Image, cuz draw.Draw()'s fist argument has to be draw.Image
	x0 := rand.Intn(img_draw.Bounds().Dx())
	y0 := rand.Intn(img_draw.Bounds().Dy())
	draw.Draw(img_draw, image.Rect(x0, y0, x0+color_pic.Bounds().Dx(), y0+color_pic.Bounds().Dy()), color_pic, image.ZP, draw.Src)
	//in a random place, draw the random color rect

	get_dst_file(img_draw)
}

func Merge() {

	var file_name_1, file_name_2 string

	fmt.Println("Input the name of the two original pictures, separate with space key (only accept .png/.jpg/.jpeg file)")
	fmt.Scanln(&file_name_1, &file_name_2)
	//open file and decode the two pics
	f1, err := os.Open(file_name_1)
	handle_error(err)
	defer f1.Close()
	f2, err := os.Open(file_name_2)
	handle_error(err)
	defer f2.Close()
	img1 := decode_img(f1, file_name_1)
	img2 := decode_img(f2, file_name_2)

	//find the smallest bound (the common part)of the two
	var x_min, y_min int
	if img1.Bounds().Dx() < img2.Bounds().Dx() {
		x_min = img1.Bounds().Dx()
	} else {
		x_min = img2.Bounds().Dx()
	}
	if img1.Bounds().Dy() < img2.Bounds().Dy() {
		y_min = img1.Bounds().Dy()
	} else {
		y_min = img2.Bounds().Dy()
	}

	dst := image.NewRGBA(image.Rect(0, 0, x_min, y_min)) //the bound of dst should be the common part

	//fill dst, every pixel is random to be from src1 or src2
	for x := 0; x < x_min; x++ {
		for y := 0; y < y_min; y++ {
			if rand.Intn(2) == 1 {
				dst.Set(x, y, img1.At(x, y))
			} else {
				dst.Set(x, y, img2.At(x, y))
			}
		}
	}

	get_dst_file(dst)
}

func Flip(di string) { // need one argument to know flip direction, horizontal or vertical

	src := get_src_img()

	dst := image.NewRGBA(src.Bounds())

	for x := 0; x < dst.Bounds().Dx(); x++ {
		for y := 0; y < dst.Bounds().Dy(); y++ {
			if di == "C1" || di == "c1" { //flip horizontal
				dst.Set(x, y, src.At(src.Bounds().Dx()-x, y))
			} else { //flip vertical
				dst.Set(x, y, src.At(x, src.Bounds().Dy()-y))
			}
		}
	}

	get_dst_file(dst)
}

func rotate() {

	img := get_src_img()

	dst := image.NewRGBA(image.Rect(0, 0, img.Bounds().Dy(), img.Bounds().Dx())) //exchange the height and width of src

	/*I've tried to rotate the pic directly, but I didn't work it out, so I spend two step to make it,
	first get it symmetry to y=x, then flip it horizontally*/
	for x := 0; x < dst.Bounds().Dx(); x++ {
		for y := 0; y < dst.Bounds().Dy(); y++ {
			dst.Set(x, y, img.At(y, x)) //symmetry to y=x
		}
	}

	real_dst := image.NewRGBA(dst.Bounds())

	for x := 0; x < real_dst.Bounds().Dx(); x++ {
		for y := 0; y < real_dst.Bounds().Dy(); y++ {
			real_dst.Set(x, y, dst.At(dst.Bounds().Dx()-x, y)) //flip it horizontally
		}
	}

	get_dst_file(real_dst)
}

func Turn_gray() { //uses of Alpha is same like Gray
	img := get_src_img()
	dst := image.NewGray(img.Bounds())

	for x := 0; x < img.Bounds().Dx(); x++ {
		for y := 0; y < img.Bounds().Dy(); y++ {
			dst.Set(x, y, img.At(x, y))
		}
	}

	get_dst_file(dst)
}

func Zoom() {

	img := get_src_img()
	fmt.Println("Input zoom scale factor(e.g. *0.5 means the height and width of new image is 0.5 times of the old one)")
	fmt.Print("*")
	var times float32
	fmt.Scanln(&times)

	x := int(float32(img.Bounds().Dx()) * times)
	y := int(float32(img.Bounds().Dy()) * times)
	dst := image.NewRGBA(image.Rect(0, 0, x, y))

	for i := 0; i < x; i++ {
		for j := 0; j < y; j++ {
			dst.Set(i, j, img.At(int(float32(i)/times), int(float32(j)/times)))
		}
	}

	get_dst_file(dst)
}

func Cut_by_color() {

	type pic struct {
		img        draw.Image
		main_color color.Color //similar colors(in range of main_color +/- distance_limit) will be put in one pic
	}
	var pics []pic
	var distance_limit float64 = 50000

	src := get_src_img()

	for x := 0; x < src.Bounds().Dx(); x++ {
		for y := 0; y < src.Bounds().Dy(); y++ { //traversal all pixels

			var added int = 0 //if the pixel have been put

			for i, _ := range pics { // if the pixel's color is similar to a pic that exists, put it in
				if added == 0 && color_distance(pics[i].main_color, src.At(x, y)) < distance_limit {
					pics[i].img.Set(x, y, src.At(x, y))
					added = 1
				}
			}

			if added == 0 { //if the pixel's color is far different from all pics' that exits
				var new_pic pic //create a new pic, the pixel's color is the main_color
				new_pic.img = image.NewRGBA(src.Bounds())
				new_pic.img.Set(x, y, src.At(x, y))
				new_pic.main_color = src.At(x, y)
				pics = append(pics, new_pic)
			}
		}
	}

	fmt.Println("set the name of the collection of the pictures")
	var name string
	fmt.Scanln(&name)
	for i, _ := range pics { //traversal all the created images, get dst file
		f_name := name + strconv.Itoa(i) + ".png" //file name, .png's default alpha is 0
		dst_file, err := os.Create(f_name)
		handle_error(err)
		defer dst_file.Close()
		encode_img(dst_file, f_name, pics[i].img)
	}
}

func Blur() {
	img := get_src_img()
	dst := image.NewRGBA(image.Rect(0, 0, img.Bounds().Dx(), img.Bounds().Dy()))
	var col [25]color.Color
	var sumR, sumG, sumB uint32
	//Use the average value of the surrounding pixel color as the color of the pixel
	for x := 0; x < img.Bounds().Dx(); x++ {
		for y := 0; y < img.Bounds().Dy(); y++ {
			col[0] = img.At(x-1, y-1)
			col[1] = img.At(x, y-1)
			col[2] = img.At(x+1, y-1)
			col[3] = img.At(x-1, y)
			col[4] = img.At(x, y)
			col[5] = img.At(x+1, y)
			col[6] = img.At(x-1, y+1)
			col[7] = img.At(x, y+1)
			col[8] = img.At(x+1, y+1)

			col[9] = img.At(x-2, y-2)
			col[10] = img.At(x-1, y-2)
			col[11] = img.At(x, y-2)
			col[12] = img.At(x+1, y-2)
			col[13] = img.At(x+2, y-2)
			col[14] = img.At(x-2, y-1)
			col[15] = img.At(x+2, y-1)
			col[16] = img.At(x-2, y)
			col[17] = img.At(x+2, y)
			col[18] = img.At(x-2, y+1)
			col[19] = img.At(x+2, y+1)
			col[20] = img.At(x-2, y+2)
			col[21] = img.At(x-1, y+2)
			col[22] = img.At(x, y+2)
			col[23] = img.At(x+1, y+2)
			col[24] = img.At(x+2, y+2)

			sumR = 0
			sumG = 0
			sumB = 0
			for _, c := range col {
				R, G, B, _ := c.RGBA()
				sumR += R
				sumG += G
				sumB += B
			}
			R := sumR / 25
			G := sumG / 25
			B := sumB / 25
			var dst_col color.NRGBA64 = color.NRGBA64{uint16(R), uint16(G), uint16(B), 0xffff}
			dst.Set(x, y, dst_col)
		}
	}
	get_dst_file(dst)
}
