/*
 * Field.cpp
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#include "sqltranslator/Field.h"

namespace sqltranslator {

Field::Field() {
    data_type = SQLType::UNKNOWN_TYPE;
    is_auto_increment = false;
    is_nullable = true;
    has_default_value = false;
}

Field::~Field() {
    // TODO Auto-generated destructor stub
}

} /* namespace sqltranslator */
