#include "Client.h"

Client::Client()
{
}

Client::Client(std::string phoneNumber, std::string fullName,
	std::chrono::year_month_day contractDate, std::string tariffName, double balance, std::string region)
{
	this->phoneNumber = phoneNumber;
	this->fullName = fullName;
	this->contractDate = contractDate;
	this->tariffName = tariffName;
	this->balance = balance;
	this->region = region;

}

void Client::fillClientData(std::istream& stream)
{
	std::string dateStr;
	int year, month, day;

	stream >> phoneNumber;
	stream.ignore();
	std::getline(stream, fullName);
	stream >> dateStr;
	std::stringstream dateStream(dateStr);
	char delimiter;
	dateStream >> day >> delimiter >> month >> delimiter >> year;
	contractDate = std::chrono::year_month_day{ std::chrono::year{year},
		std::chrono::month{static_cast<unsigned>(month)}, std::chrono::day{static_cast<unsigned>(day)} };

	stream >> tariffName;
	stream >> balance;
	stream >> region;

}

void Client::printClientData(std::ostream& stream)
{
	stream << phoneNumber << '\n';
	stream << fullName << '\n';
	stream << contractDate.day() << ' ';
	stream << contractDate.month() << ' ';
	stream << contractDate.year() << '\n';
	stream << tariffName << '\n';
	stream << balance << '\n';
	stream << region << '\n';

}

std::string Client::get_phoneNumber()
{
	return phoneNumber;
}

std::string Client::get_tariffName()
{
	return tariffName;
}

std::string Client::get_region()
{
	return region;
}

std::chrono::year_month_day Client::get_contractDate()
{
	return contractDate;
}

double Client::get_balance()
{
	return balance;
}

std::string Client::get_fullName()
{
	return fullName;
}
