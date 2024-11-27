#include "LinearList.h"
#include <Windows.h>
void inputClientData(Client& cl, std::istream& stream);

int main()
{
	SetConsoleOutputCP(1251);

	Client cl1;
	Client cl2;
	Client cl3;
	Client cl4;
	std::ifstream file("data.txt");
	std::ofstream out_file("out_data.txt");

	inputClientData(cl1, std::cin);
	inputClientData(cl2, std::cin);
	inputClientData(cl3, std::cin);
	inputClientData(cl4, std::cin);

	cl1.printClientData(std::cout);
	cl2.printClientData(std::cout);
	cl3.printClientData(std::cout);
	cl4.printClientData(std::cout);

}

void inputClientData(Client& cl, std::istream& stream)
{
	if (&stream == &std::cin)
	{
		std::cout << "Введите информацию о клиенте(Номер телефона, ФИО, Дата заключения договора, Тариф, Баланс, Регион:'\n";
		cl.fillClientData(stream);
	}
	else
		cl.fillClientData(stream);
}
