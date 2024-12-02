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

    Client* find_by_index(int index);

    void clear();

    void get_employees_younger_than(int year, int min_experience);
    void get_by_department_and_remove(int department_code);
    void sort_employees();

    size_t get_list_size() { return list->get_size(); };
    bool is_empty() { return list->is_empty(); };

    void print_all(std::ostream stream);
    friend std::ostream& operator<<(std::ostream& os, const Container& container);
};