#pragma once
#include<iostream>
#include<string>
#include <chrono>
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



};

