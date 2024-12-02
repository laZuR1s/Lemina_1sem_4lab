#include "Container.h"
#include <algorithm>

Container::Container()
{
	list = new LinearList();
}

Container::~Container()
{
	delete list;
}

void Container::add_to_start(const Client& client)
{
	list->add_to_start(client);
}

void Container::add_to_end(const Client& client)
{
	list->add_to_end(client);
}

void Container::add_at_position(const Client& client, size_t position)
{
	list->add_after(position, client);
}

void Container::remove_from_start()
{
	list->remove_from_start();
}

void Container::remove_from_end()
{
	list->remove_from_end();
}

void Container::remove_at_position(size_t position)
{
	list->remove_by_index(position);
}

Client Container::find_by_index(int index)
{
	return list->find_by_index(index);
}

void Container::clear()
{
	list->clear();
}

void Container::get_specific_client(std::string combination, std::string tariff, std::string region,std::ostream& stream)
{
	for (int i = 0; i < list->get_size(); i++)
	{
		Client client = list->find_by_index(static_cast<int>(i));
		if (client.get_phoneNumber().find(combination) == 0 && client.get_tariffName() == tariff && client.get_region() == region) {
			client.printClientData(stream);
			stream << '\n';
		}
	}
}

void Container::get_another_specific_client_and_remove(std::string tariff, std::chrono::year_month_day& date, std::ostream& stream)
{
	auto& clients = list->get_all();
	auto it = clients.begin();
	while (it != clients.end()) {
		if (it->get_balance()<0 && it->get_tariffName() == tariff && it->get_contractDate().year() > date.year() || it->get_contractDate().year() == date.year() && it->get_contractDate().month() > date.month() ||
			it->get_contractDate().year() == date.year() && it->get_contractDate().month() == date.month()&&it->get_contractDate().day() > date.day())
		{
			it->printClientData(stream);
			stream << '\n';
			it = clients.erase(it);
		}
		else {
			++it;
		}
	}
}

void Container::sort_clients()
{
	auto& allClients = list->get_all();

	std::sort(allClients.begin(), allClients.end(), []( Client& a,  Client& b) {
		if (a.get_region() != b.get_region()) {
			return a.get_region() < b.get_region();
		}
		if (a.get_contractDate() != b.get_contractDate()) {
			return a.get_contractDate() < b.get_contractDate();
		}
		return a.get_fullName() < b.get_fullName();
		});
}

void Container::print_all(std::ostream& stream)
{
	if (is_empty()) {
		stream << "The container is empty.\n";
		return;
	}

	for (size_t i = 0; i < get_list_size(); ++i) {
		Client client = find_by_index(static_cast<int>(i));
			client.printClientData(stream);
			stream << "\n";
	}
}



