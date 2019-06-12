#include <iostream>
#include <string>
#include "weather.h"
#include "date.h"

using namespace std;

const double F_TO_C = 5 / 9;
const double C_TO_F = 9 / 5;

Image::Image(int w, int h, std::string flnm)
    : width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}

// copy constructor:
Image::Image(const Image& img2) {
	width = img2.width;
	height = img2.height;
	filename = img2.filename;
	image_buf = new char[image_sz()];
	for (int i = 0; i < image_sz(); i++){
		image_buf[i] = img2.image_buf[i];
	}

}

// destructor
Image::~Image() {
	delete image_buf;
	image_buf = nullptr;
}

// assignment operator:
Image& Image::operator=(const Image& img2) {
	if (this != &img2){
		delete image_buf;
		image_buf = nullptr;
		width = img2.width;
		height = img2.height;
		filename = img2.filename;
		image_buf = new char[image_sz()];
		for (int i = 0; i<image_sz(); i++){
			image_buf[i] = img2.image_buf[i];
		}
	return *this;
	}
}

int Image::image_sz() {
    return width * height;
}


void Image::copy_fields(const Image& img2) {
}


    /*
     * Setting `display() = 0` here makes this an abstract
     * class that can't be implemented.
     * */
string Image::display(std::string s) {
    return "Displaying image " + s;
}

/*
 * A constructor for weather class.
 * */
Weather::Weather(string nm, GPS loc) :
    station_nm(nm), my_loc(loc) {
}


string Weather::get_name() const{
    return station_nm;
}

int Weather::get_rating() const{
	return rating;
}

void Weather::set_rating(int new_rating){
	rating = new_rating;
}

void Weather::add_reading(WReading wr){
	wreadings.push_back(wr);
}

double WReading::get_tempF() {
    return (temperature * C_TO_F) + 32;
}

ostream& operator << (ostream& os, const Weather& w){
	int rating = w.get_rating();
	os << w.station_nm << ": rating " << rating << endl;
	for (WReading i : w.wreadings){
		os << i << endl;
	}
	return os;
}

ostream& operator << (ostream& os, const WReading& wr){
	os << "Date: " << wr.date << " Temperature: " << wr.temperature << " Humidity: " << wr.humidity << " Windspeed: " << wr.windspeed << endl;
	return os;
}


ostream& operator << (ostream& os, const GPS& gps){
	os << gps.latitude << " " << gps.longitude << endl;
	return os;
}