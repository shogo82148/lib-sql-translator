/*
 * Field.cpp
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#include "sqltranslator/Field.h"

namespace sqltranslator {

Field::Field() {
}

Field::Field(const std::string& name) :name(name) {
}

Field::Field(const std::string& name, SQLType data_type, const std::string& default_value)
    : name(name)
    , data_type(data_type)
    , default_value(default_value)
    , has_default_value(true) {
}

Field::~Field() {
    // TODO Auto-generated destructor stub
}

} /* namespace sqltranslator */
