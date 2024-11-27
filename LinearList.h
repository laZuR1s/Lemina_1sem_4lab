#pragma once
#include"Client.h"
#include<vector>

class LinearList
{
private:
	std::vector<Client> list;
public:
    bool is_empty() { return list.empty(); };
    void add_to_start(const Client& client);
    void add_to_end(const Client& client);
    void add_after(int index, const Client& client);
    void remove_from_start();
    void remove_from_end();
    void remove_by_index(int index);
    Client* find_by_index(int index);
    void clear();
    std::vector<Client>& get_all();
    size_t get_size() const;

};
