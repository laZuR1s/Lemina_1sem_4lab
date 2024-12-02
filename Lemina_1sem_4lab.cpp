#include "LinearList.h"
#include "Container.h"
#include <Windows.h>
#include<functional>

void inputClientData(Client& cl, std::istream& stream);
int main_menu();
int list_menu();
template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message);


int main()
{
	SetConsoleOutputCP(1251);
	
	Container container;
	int choice;
	do
	{
		choice = main_menu();
		switch (choice)
		{
		case 1:
		{
			int list_choice;
			do {
		case 1: {}

			} while (list_choice != 9);
			break;
		}
		case 2:
		{


			break;
		}
		}

	} while (choice != 3);


	//Client cl1;
	//Client cl2;
	//Client cl3;
	//Client cl4;
	//std::ifstream file("data.txt");
	//std::ofstream out_file("out_data.txt");

	//inputClientData(cl1, file);
	/*inputClientData(cl2, std::cin);
	inputClientData(cl3, std::cin);
	inputClientData(cl4, std::cin);*/

	//cl1.printClientData(std::cout);
	/*cl2.printClientData(std::cout);
	cl3.printClientData(std::cout);
	cl4.printClientData(std::cout)*/;

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

template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message)
{
	std::cout << message << "\n>>> ";
	while (!(std::cin >> x && condition(x)))
	{
		std::cout << "Ошибка ввода!" << '\n';
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << message << "\n>>> ";
	}
}

int main_menu()
{
	std::cout << "\nМЕНЮ\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. Заполнить из файла\n";
	std::cout << "2. Решить задачу\n";
	std::cout << "3. Выход\n";
	std::cout << "-----------------------------------------------------\n";

	std::function<bool(int)> foo;
	foo = [](int x)->bool {return x >= 1 && x <= 3; };
	int choice;
	validation(choice, foo, "");
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}

int list_menu()
{
	std::cout << "\nМетоды списка\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. Добавить в начало\n";
	std::cout << "2. Добавить в конец\n";
	std::cout << "3. Добавить за индексом\n";
	std::cout << "4. Удалить из начала\n";
	std::cout << "5. Удалить из конца\n";
	std::cout << "6. Удалить по индексу\n";
	std::cout << "7. Найти по индексу\n";
	std::cout << "8. Очистить список\n";
	std::cout << "9. Вернуться в главное меню\n";
	std::cout << "-----------------------------------------------------\n";

	std::function<bool(int)> foo;
	foo = [](int x)->bool {return x >= 1 && x <= 9; };
	int choice;
	validation(choice, foo, "");
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
	return 0;
}
