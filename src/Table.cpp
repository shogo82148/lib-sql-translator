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

Table::Table() {
    // TODO Auto-generated constructor stub

}

Table::~Table() {
    // TODO Auto-generated destructor stub
}

} /* namespace sqltranslator */
