#include "LinearList.h"
#include "Container.h"
#include <Windows.h>
#include<functional>

void inputClientData(Client& cl, std::istream& stream);
int main_menu();
int list_menu();
int cont_menu();
template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message);
Client fillData(int input_choice);
std::chrono::year_month_day inputDate();

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
				list_choice = list_menu();
				switch (list_choice)
				{
				case 1: {
					int input_choice;
					validation(input_choice, [](int x) {return x >= 1 && x <= 2; }, "Введите вариант ввода(1.Файл; 2.Клавиатура): ");
					container.add_to_start(fillData(input_choice));
					break;
				}
				case 2: {
					int input_choice;
					validation(input_choice, [](int x) {return x >= 1 && x <= 2; }, "Введите вариант ввода(1.Файл; 2.Клавиатура): ");
					container.add_to_end(fillData(input_choice));
					break;
				}
				case 3: {
					int input_choice;
					validation(input_choice, [](int x) {return x >= 1 && x <= 2; }, "Введите вариант ввода(1.Файл; 2.Клавиатура): ");
					size_t index;
					size_t size = container.get_list_size();
					validation(index, [size](int x) {return x >= 0 && x <= size; }, "Введите позицию на которую хотите добавить элемент: ");
					container.add_at_position(fillData(input_choice), index);
					break;
				}
				case 4: {
					if (container.is_empty())
						std::cout << "Список пуст\n";
					else
					{
						container.remove_from_start();
					}
					break;
				}
				case 5: {
					if (container.is_empty())
						std::cout << "Список пуст\n";
					else
					{
						container.remove_from_end();
					}
					break;
				}
				case 6: {
					if (container.is_empty())
						std::cout << "Список пуст\n";
					else
					{
						size_t index;
						size_t size = container.get_list_size();
						validation(index, [size](int x) {return x >= 0 && x <= size; }, "Введите позицию: ");
						container.remove_at_position(index);
					}
					break;
				}
				case 7: {
					size_t index;
					size_t size = container.get_list_size();
					validation(index, [size](int x) {return x >= 0 && x <= size-1; }, "Введите позицию: ");
					Client client = container.find_by_index(index);
					client.printClientData(std::cout);
					break;
				}
				case 8: {
					container.clear();
					break;
				}
				}
			} while (list_choice != 9);
			break;
		}
		case 2:
		{
			int cont_choice;
			do {
				cont_choice = cont_menu();
				switch (cont_choice)
				{
				case 1: {
					int input_choice;
					validation(input_choice, [](int x) {return x >= 1 && x <= 2; }, "Введите вариант ввода(1.Файл; 2.Клавиатура): ");
					container.add_to_end(fillData(input_choice));
					break;
				}
				case 2: {
					std::string combination, tariff, region;
					std::cout << "Введите комбинацию номера телефона, тариф и регион: ";
					std::cin >> combination >> tariff >> region;
					std::cout << '\n';
					container.get_specific_client(combination,tariff,region,std::cout);
					break;
				}
				case 3:
				{
					std::string tariff;
					double balance;
					std::cout << "Введите название тарифа: ";
					std::cin >> tariff;

					std::chrono::year_month_day date = inputDate();

					container.get_another_specific_client_and_remove(tariff, date, std::cout);
					break;
				}
				case 4:
				{
					container.sort_clients();
					break;
				}
				case 5:
				{
					container.print_all(std::cout);
				}
				}
			} while (cont_choice != 6);
			break;
		}
		}

	} while (choice != 3);

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
	std::cout << "1. Проверить методы списка\n";
	std::cout << "2. Проверить методы контейнера\n";
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
}

int cont_menu()
{
	std::cout << "\nМетоды контейнера\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. Добавить клиента\n";
	std::cout << "2. Получить список всех клиентов, номер телефона которых начинается с заданной комбинации, имеющих заданный тариф в заданном регионе\n";
	std::cout << "3. Получить список всех клиентов на заданном тарифе, дата подключения которых позже заданной, и сумма на счете отрицательная.При этом удалить выбранных клиентов из Контейнера\n";
	std::cout << "4. Упорядочить клиентов по региону, дате заключения договора и ФИО\n";
	std::cout << "5. Показать всех клиентов\n";
	
	std::cout << "6. Вернуться в главное меню\n";
	std::cout << "-----------------------------------------------------\n";

	std::function<bool(int)> foo;
	foo = [](int x)->bool {return x >= 1 && x <= 6; };
	int choice;
	validation(choice, foo, "");
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}

Client fillData(int input_choice)
{
	Client client;

	if (input_choice == 1)
	{
		std::string fileName;
		std::cout << "Введите название файла: ";
		std::cin >> fileName;
		std::ifstream file(fileName);
		client.fillClientData(file);
	}
	else
		client.fillClientData(std::cin);

	return client;
}

std::chrono::year_month_day inputDate() {
	int year, month, day;
	char delimiter;
	std::cout << "Введите дату: ";
	std::string dateInput;
	std::cin >> dateInput;
	std::istringstream dateStream(dateInput);
	dateStream >> day >> delimiter >> month >> delimiter >> year;
	return std::chrono::year(year) / std::chrono::month(month) / std::chrono::day(day);
}