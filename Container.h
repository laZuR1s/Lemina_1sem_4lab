#pragma once

#include "LinearList.h"
#include "Client.h"
#include <vector>
#include <iostream>

class Container {
private:
    LinearList* list;

public:
    Container();
    ~Container();

    void add_to_start(const Client& cleint);
    void add_to_end(const Client& client);
    void add_at_position(const Client& client, size_t position);

    void remove_from_start();
    void remove_from_end();
    void remove_at_position(size_t position);

    Client find_by_index(int index);

    void clear();

    void get_specific_client(std::string combination, std::string tariff,std::string region,std::ostream& stream);
    void get_another_specific_client_and_remove(std::string tariff, std::chrono::year_month_day& contractDate,std::ostream& stream);
    void sort_clients();


    size_t get_list_size() { return list->get_size(); };
    bool is_empty() { return list->is_empty(); };

    void print_all(std::ostream &stream);
};