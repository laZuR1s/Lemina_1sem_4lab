#include "LinearList.h"

void LinearList::add_to_start(const Client& client)
{
	list.insert(list.begin(), client);
}

void LinearList::add_to_end(const Client& client)
{
	list.push_back(client);
}

void LinearList::add_after(int index, const Client& client)
{
	list.insert(list.begin() + index + 1, client);
}

void LinearList::remove_from_start()
{
	if (!list.empty())
	{
		list.erase(list.begin());
	}
}

void LinearList::remove_from_end()
{
	if (!list.empty())
	{
		list.pop_back();
	}
}

void LinearList::remove_by_index(int index)
{
	if (index >= 0 && index < list.size()) {
		list.erase(list.begin() + index);
	}
}

Client* LinearList::find_by_index(int index)
{
	if (index >= 0 && index < list.size())
		return &list[index];
	return nullptr;
}

void LinearList::clear()
{
	list.clear();
}

std::vector<Client>& LinearList::get_all()
{
	return list;
}

size_t LinearList::get_size() const
{
	return list.size();
}


