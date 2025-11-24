#ifndef EXPEDIA_FLIGHTS_API_H_
#define EXPEDIA_FLIGHTS_API_H_

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class AirCanadaCustomerInfo {
public:
	string userName;
	string name;
	string email;
};

class AirCanadaFlight {
public:
	double price;
	string date_time_from;
	string date_time_to;
	string from;
	string to;
};

class AirCanadaOnlineAPI {
public:
	static vector<AirCanadaFlight> GetFlights(string from, string from_date, string to, string to_date, int adults, int children) {
		vector<AirCanadaFlight> flights = {
			{ 680.0, "20-11-2025", "22-11-2025", "Egypt", "Germany" },
			{ 720.0, "22-01-2025", "30-01-2025", "UAE", "Germany" },
			{ 640.0, "25-01-2025", "02-02-2025", "France", "Germany" },
			{ 930.0, "27-01-2025", "27-02-2025", "India", "Canada" },
			{ 1020.0, "01-02-2025", "08-02-2025", "USA", "Japan" },
			{ 970.0, "03-02-2025", "10-02-2025", "Australia", "Japan" },
			{ 880.0, "05-02-2025", "13-02-2025", "Egypt", "Thailand" },
			{ 940.0, "08-02-2025", "15-02-2025", "Spain", "South Africa" },
			{ 1010.0, "10-02-2025", "18-02-2025", "Canada", "Brazil" },
			{ 895.0, "12-02-2025", "20-02-2025", "Turkey", "Germany" }
		};
		return flights;
	}

	static bool ReserveFlight(const AirCanadaFlight& flight, const AirCanadaCustomerInfo& info) {
		cout << "Reservation Confirmed!" << endl;
		cout << "Customer: " << info.name << " (" << info.userName << ")" << endl;
		cout << "Email: " << info.email << endl;
		cout << "Flight Details:" << endl;
		cout << "From: " << flight.from << "  ->  To: " << flight.to << endl;
		cout << "Departure: " << flight.date_time_from << "  |  Arrival: " << flight.date_time_to << endl;
		cout << "Total Price: $" << flight.price << endl;
		cout << "----------------------------------------" << endl;
		return true;
	}
};

class TurkishFlight {
public:
	double cost;
	string datetime_from;
	string datetime_to;
	string from;
	string to;
};

class TurkishCustomerInfo {
public:
	string userName;
	string name;
	string email;
	int adults;
	int children;
	int infants;
};

class TurkishAirlinesOnlineAPI {
public:
	TurkishFlight cilentFlight;
	TurkishCustomerInfo cuInfo;

	void SetFromToInfo(string datetime_from, string from, string datetime_to, string to) {
		cilentFlight.datetime_from = datetime_from;
		cilentFlight.datetime_to = datetime_to;
		cilentFlight.from = from;
		cilentFlight.to = to;
	}

	void SetPassengersInfo(int infants, int childern, int adults) {
		cuInfo.adults = adults;
		cuInfo.children = childern;
		cuInfo.infants = infants;
	}

	static vector<TurkishFlight> GetAvailableFlights() {
		vector<TurkishFlight> flights = {
			{ 320.0, "15-01-2025", "22-11-2025", "Egypt", "Turkey" },
			{ 580.0, "20-01-2025", "21-01-2025", "UAE", "Germany" },
			{ 740.0, "25-01-2025", "26-01-2025", "France", "Japan" },
			{ 410.0, "28-01-2025", "29-01-2025", "Turkey", "Italy" },
			{ 960.0, "02-02-2025", "03-02-2025", "India", "Canada" },
			{ 520.0, "05-02-2025", "06-02-2025", "Qatar", "United Kingdom" },
			{ 690.0, "10-02-2025", "11-02-2025", "Egypt", "Germany" },
			{ 870.0, "15-02-2025", "16-02-2025", "Saudi Arabia", "France" },
			{ 1050.0, "20-02-2025", "21-02-2025", "USA", "Turkey" },
			{ 780.0, "25-02-2025", "26-02-2025", "Spain", "Thailand" }
		};
		return flights;
	}

	static bool ReserveFlight(const TurkishCustomerInfo& info, const TurkishFlight& flight) {
		cout << "=============================================\n";
		cout << "  Turkish Airlines - Flight Reservation\n";
		cout << "=============================================\n";
		cout << " Passenger Information:\n";
		cout << "---------------------------------------------\n";
		cout << "User Name: " << info.userName << endl;
		cout << "Full Name: " << info.name << endl;
		cout << "Email: " << info.email << endl;
		cout << "Adults: " << info.adults << " | Children: " << info.children << " | Infants: " << info.infants << endl;
		cout << "---------------------------------------------\n";
		cout << " Flight Details:\n";
		cout << "---------------------------------------------\n";
		cout << "From: " << flight.from << "   ->   To: " << flight.to << endl;
		cout << "Departure Date: " << flight.datetime_from << endl;
		cout << "Arrival Date:   " << flight.datetime_to << endl;
		cout << "Ticket Cost: $" << flight.cost << endl;
		cout << "---------------------------------------------\n";
		cout << " Reservation confirmed successfully!\n";
		cout << "A confirmation email will be sent to: " << info.email << endl;
		cout << "=============================================\n\n";
		return true;
	}
};

#endif /* EXPEDIA_FLIGHTS_API_H_ */