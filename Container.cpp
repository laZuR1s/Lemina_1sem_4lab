#include "Container.h"

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

Client* Container::find_by_index(int index)
{
	return list->find_by_index(index);
}

void Container::clear()
{
	list->clear();
}

void Container::print_all(std::ostream stream)
{
	if (is_empty()) {
		stream << "The container is empty.\n";
		return;
	}

	for (size_t i = 0; i < get_list_size(); ++i) {
		Client* client = find_by_index(static_cast<int>(i));
		if (client) {
			client->printClientData(stream);
			stream << "\n";
		}
		else {
			stream << "Error accessing client at index " << i << ".\n";
		}
	}
}



