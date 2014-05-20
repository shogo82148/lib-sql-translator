/*
 * Table_test.cpp
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#include "gtest/gtest.h"
#include "src/sqltranslator/Table.h"
#include "src/sqltranslator/Constraint.h"

namespace sqltranslator {

TEST(table, constraints) {
    Constraint c1, c2;
    c1.name = "constraint 1";
    c2.name = "constraint 2";

    Table t;
    t.add_constraint(c1);
    t.add_constraint(c2);

    {
        auto constraints = t.get_constraints();
        EXPECT_EQ(2, constraints.size());
        EXPECT_EQ("constraint 1", constraints[0].name);
        EXPECT_EQ("constraint 2", constraints[1].name);
    }

    t.drop_constraint("constraint 2");
    {
        auto constraints = t.get_constraints();
        EXPECT_EQ(1, constraints.size());
        EXPECT_EQ("constraint 1", constraints[0].name);
    }
}

TEST(table, uniqueConstraints) {
    Constraint c1, c2;
    c1.name = "constraint 1";
    c2.type = constraint_type::PRIMARY_KEY;
    c2.name = "constraint 2";
    c2.type = constraint_type::UNIQUE;

    Table t;
    t.add_constraint(c1);
    t.add_constraint(c2);

    auto constraints = t.unique_constraints();
    EXPECT_EQ(1, constraints.size());
    EXPECT_EQ("constraint 2", constraints[0].name);
}

TEST(table, fkeyConstraints) {
    Constraint c1, c2;
    c1.name = "constraint 1";
    c2.type = constraint_type::PRIMARY_KEY;
    c2.name = "constraint 2";
    c2.type = constraint_type::FOREIGN_KEY;

    Table t;
    t.add_constraint(c1);
    t.add_constraint(c2);

    auto constraints = t.fkey_constraints();
    EXPECT_EQ(1, constraints.size());
    EXPECT_EQ("constraint 2", constraints[0].name);
}

TEST(table, index) {
    Index i1, i2;
    i1.name = "index1";
    i2.name = "index2";

    Table t;
    t.add_index(i1);
    t.add_index(i2);

    {
        auto indices = t.get_indices();
        EXPECT_EQ(2, indices.size());
        EXPECT_EQ("index1", indices[0].name);
        EXPECT_EQ("index2", indices[1].name);
    }
}

} /* namespace sqltranslator */
