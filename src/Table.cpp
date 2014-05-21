/*
 * Table.cpp
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#include "sqltranslator/Table.h"

namespace sqltranslator {

Table& Table::add_constraint(const Constraint& c) {
    constraints.push_back(c);
    return *this;
}

Table& Table::drop_constraint(const std::string& name) {
    auto c = std::find_if(
            constraints.begin(), constraints.end(),
            [&](const Constraint& c){ return c.name == name; });
    if(c == constraints.end()) {
        throw "constraint not found";
    }
    constraints.erase(c);
    return *this;
}

std::vector<Constraint> Table::unique_constraints() const {
    std::vector<Constraint> v;
    for(auto &c: constraints) {
        if(c.type == ConstraintType::UNIQUE) {
            v.push_back(c);
        }
    }
    return v;
}

std::vector<Constraint> Table::fkey_constraints() const {
    std::vector<Constraint> v;
    for(auto &c: constraints) {
        if(c.type == ConstraintType::FOREIGN_KEY) {
            v.push_back(c);
        }
    }
    return v;
}

Table& Table::add_index(const Index& index) {
    indices.push_back(index);
    return *this;
}

Table& Table::drop_index(const std::string& name) {
    auto i = std::find_if(
            indices.begin(), indices.end(),
            [&](const Index& i){ return i.name == name; });
    if(i == indices.end()) {
        throw "index not found";
    }
    indices.erase(i);
    return *this;
}

Table::Table() {
    // TODO Auto-generated constructor stub

}

Table::~Table() {
    // TODO Auto-generated destructor stub
}

} /* namespace sqltranslator */
