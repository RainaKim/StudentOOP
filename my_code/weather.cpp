#include <iostream>
#include <string>
#include "weather.h"
#include "date.h"

using namespace std;

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