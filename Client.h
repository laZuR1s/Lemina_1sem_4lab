#pragma once
#include<iostream>
#include<string>
#include <chrono>
#include <Windows.h>
#include<fstream>

class Client
{
private:
	std::string phoneNumber{};
	std::string fullName{};
	std::chrono::year_month_day contractDate{};
	std::string tariffName{};
	double balance{};
	std::string region{};
public:
	Client();
	Client(std::string phoneNumber, std::string fullName, std::chrono::year_month_day contractDate,
		std::string tariffName, double balance, std::string region);
	void fillClientData(std::istream& stream);
	void printClientData(std::ostream& stream);

	std::string get_phoneNumber();
	std::string get_tariffName();
	std::string get_region();
	std::chrono::year_month_day get_contractDate();
	double get_balance();
	std::string get_fullName();



};

