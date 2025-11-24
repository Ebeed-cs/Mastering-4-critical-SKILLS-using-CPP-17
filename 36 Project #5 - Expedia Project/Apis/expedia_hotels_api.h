/*
 * expedia_hotels_api.h
 *
 *  Created on: Sep 22, 2020
 *      Author: moustafa
 */

#ifndef EXPEDIA_HOTELS_API_H_
#define EXPEDIA_HOTELS_API_H_

#include <iostream>
#include <iomanip>
#include <vector>
#include "../Utils.h"
#include <string>
using namespace std;

class RoomBase {
public:
	string room_type;
	int available;
	double price_per_night;
	string date_from;
	string date_to;
	string country;
	string city;

	// Default constructor
	RoomBase() : available(0), price_per_night(0.0) {}

	void read() {
		std::cout << "\n=== Enter Room Information ===\n";
		std::cout << "(Enter actual data or '.' for any)\n\n";

		std::cout << "Country: ";
		std::getline(std::cin >> std::ws, country);

		std::cout << "City: ";
		std::getline(std::cin >> std::ws, city);

		std::cout << "Check-in Date (DD/MM/YYYY): ";
		std::getline(std::cin >> std::ws, date_from);

		std::cout << "Check-out Date (DD/MM/YYYY): ";
		std::getline(std::cin >> std::ws, date_to);

		std::cout << "===============================\n";
	}

	// Parameterized constructor
	RoomBase(string rt, int av, double ppn, string df, string dt, string co, string ci)
		: room_type(rt), available(av), price_per_night(ppn),
		date_from(df), date_to(dt), country(co), city(ci) {
	}

	virtual ~RoomBase() {}
};

class HiltonRoom : public RoomBase {
public:
	HiltonRoom() : RoomBase() {}
	HiltonRoom(string rt, int av, double ppn, string df, string dt, string co, string ci)
		: RoomBase(rt, av, ppn, df, dt, co, ci) {
	}
};

class MarriottFoundRoom : public RoomBase {
public:
	MarriottFoundRoom() : RoomBase() {}
	MarriottFoundRoom(string rt, int av, double ppn, string df, string dt, string co, string ci)
		: RoomBase(rt, av, ppn, df, dt, co, ci) {
	}
};

class HiltonHotelAPI {
public:
	static vector<HiltonRoom> SearchRooms(string country, string city, string from_date, string to_date, int needed_rooms) {
		vector<HiltonRoom> rooms = {
			{ "Interior View", 6, 200.0, "22-11-2025", "10-02-2025", "Egypt", "Tanta" },
			{ "City View", 4, 350.0, "01-02-2025", "12-02-2025", "Egypt", "Cairo" },
			{ "Deluxe Suite", 2, 750.0, "05-02-2025", "15-02-2025", "UAE", "Dubai" },
			{ "Sea View", 5, 600.0, "10-02-2025", "20-02-2025", "Greece", "Athens" },
			{ "Mountain View", 3, 420.0, "03-03-2025", "10-03-2025", "Switzerland", "Zurich" },
			{ "Garden View", 7, 280.0, "15-02-2025", "25-02-2025", "Egypt", "Alexandria" },
			{ "Penthouse Suite", 1, 1200.0, "20-02-2025", "28-02-2025", "USA", "New York" },
			{ "Family Room", 8, 350.0, "02-03-2025", "12-03-2025", "France", "Paris" },
			{ "Executive Room", 5, 500.0, "18-02-2025", "28-02-2025", "Germany", "Berlin" },
			{ "Ocean Front", 2, 900.0, "25-02-2025", "05-03-2025", "Thailand", "Phuket" }
		};

		Utils::DateParts client_from(from_date);
		Utils::DateParts client_to(to_date);

		vector<HiltonRoom> result;
		for (auto& r : rooms) {
			Utils::DateParts flight_from(r.date_from);
			Utils::DateParts flight_to(r.date_to);
			if (country != r.country && country != ".") continue;
			if (city != r.city && city != ".") continue;
			if (from_date != "." && client_from.year != flight_from.year) continue;
			if (from_date != "." && client_from.month != flight_from.month) continue;
			if (from_date != "." && client_from.day < flight_from.day) continue;
			if (to_date != "." && client_to.year != flight_to.year) continue;
			if (to_date != "." && client_to.month != flight_to.month) continue;
			if (to_date != "." && client_to.day > flight_to.day) continue;
			if (needed_rooms > r.available && needed_rooms != 0) continue;

			result.push_back(r);
		}
		return result;
	}


	static void print(const vector<HiltonRoom>& rooms) {
		cout << "\n=========== Hilton Hotel Rooms Search Results ===========\n\n";

		if (rooms.empty()) {
			cout << "\nNo rooms found matching your search criteria.\n";
			return;
		}

		int count = 0;
		for (const auto& r : rooms) {
			cout << "Room #" << ++count << endl;
			cout << "  Room Type       : " << r.room_type << endl;
			cout << "  Available Rooms : " << r.available << endl;
			cout << "  Price per Night : $" << fixed << setprecision(2) << r.price_per_night << endl;
			cout << "  Date Range      : " << r.date_from << "  ->  " << r.date_to << endl;
			cout << "  Location        : " << r.city << ", " << r.country << endl;
			cout << "--------------------------------------------------------" << endl;
		}

		cout << "\nTotal Rooms Found : " << rooms.size() << endl;
		cout << "========================================================\n";
	}

};


class MarriottHotelAPI {
public:
	static vector<MarriottFoundRoom> FindRooms(string from_date, string to_date, string country, string city, int needed_rooms) {
		vector<MarriottFoundRoom> rooms = {
			{ "City View", 8, 320.0, "29-01-2025", "10-02-2025", "Egypt", "Cairo" },
			{ "Deluxe Suite", 3, 780.0, "01-02-2025", "12-02-2025", "UAE", "Dubai" },
			{ "Garden View", 6, 290.0, "05-02-2025", "15-02-2025", "Egypt", "Alexandria" },
			{ "Ocean View", 4, 650.0, "10-02-2025", "20-02-2025", "Greece", "Santorini" },
			{ "Mountain View", 5, 400.0, "03-03-2025", "13-03-2025", "Switzerland", "Zurich" },
			{ "Executive Room", 7, 520.0, "15-02-2025", "25-02-2025", "Germany", "Berlin" },
			{ "Family Suite", 10, 450.0, "20-02-2025", "28-02-2025", "France", "Paris" },
			{ "Presidential Suite", 2, 1250.0, "18-02-2025", "28-02-2025", "USA", "New York" },
			{ "Skyline View", 5, 560.0, "25-02-2025", "05-03-2025", "UK", "London" },
			{ "Beachfront Villa", 3, 980.0, "02-03-2025", "12-03-2025", "Thailand", "Phuket" }
		};

		Utils::DateParts client_from(from_date);
		Utils::DateParts client_to(to_date);

		vector<MarriottFoundRoom> result;
		for (auto& r : rooms) {
			Utils::DateParts room_from(r.date_from);
			Utils::DateParts room_to(r.date_to);

			if (country != r.country && country != ".") continue;
			if (city != r.city && city != ".") continue;
			if (from_date != "." && client_from.year != room_from.year) continue;
			if (from_date != "." && client_from.month != room_from.month) continue;
			if (from_date != "." && client_from.day < room_from.day) continue;
			if (to_date != "." && client_to.year != room_to.year) continue;
			if (to_date != "." && client_to.month != room_to.month) continue;
			if (to_date != "." && client_to.day > room_to.day) continue;
			if (needed_rooms > r.available && needed_rooms != 0) continue;

			result.push_back(r);
		}
		return result;
	}

	static void print(const vector<MarriottFoundRoom>& rooms) {
		cout << "\n=========== Marriott Hotel Rooms Search Results ===========\n\n";

		if (rooms.empty()) {
			cout << "\nNo rooms found matching your search criteria.\n";
			return;
		}

		int count = 0;
		for (const auto& r : rooms) {
			cout << "Room #" << ++count << endl;
			cout << "  Room Type       : " << r.room_type << endl;
			cout << "  Available Rooms : " << r.available << endl;
			cout << "  Price per Night : $" << fixed << setprecision(2) << r.price_per_night << endl;
			cout << "  Date Range      : " << r.date_from << "  ->  " << r.date_to << endl;
			cout << "  Location        : " << r.city << ", " << r.country << endl;
			cout << "------------------------------------------------------------" << endl;
		}

		cout << "\nTotal Rooms Found : " << rooms.size() << endl;
		cout << "============================================================\n";
	}
};

#endif /* EXPEDIA_HOTELS_API_H_ */
