/*
 * Field_test.cpp
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#include "gtest/gtest.h"
#include "src/sqltranslator/Field.h"

namespace sqltranslator {

TEST(field, constractor) {
    Field f;
    EXPECT_EQ("", f.name);
    EXPECT_EQ(false, f.has_default_value);
    EXPECT_EQ("", f.default_value);
}

TEST(field, constractorName) {
    Field f("field");
    EXPECT_EQ("field", f.name);
    EXPECT_EQ(false, f.has_default_value);
    EXPECT_EQ("", f.default_value);
}

TEST(field, constractorDefaultValue) {
    Field f("field", SQLType::CHAR, "value");
    EXPECT_EQ("field", f.name);
    EXPECT_EQ(true, f.has_default_value);
    EXPECT_EQ("value", f.default_value);
}

} /* namespace sqltranslator */
