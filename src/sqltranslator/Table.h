/*
 * Table.h
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#ifndef TABLE_H_
#define TABLE_H_

#include <map>
#include <vector>
#include <string>

#include "Object.h"
#include "Field.h"
#include "Index.h"
#include "Constraint.h"

namespace sqltranslator {

class Table: public Object {
private:
    std::vector<Constraint> constraints;
    std::vector<Index> indices;
    std::map<std::string, Field> fields;
public:
    std::vector<std::string> comments;

    Table& add_constraint(const Constraint& c);
    Table& drop_constraint(const std::string& name);
    Table& drop_constraint(const Constraint& c) {
        return drop_constraint(c.name);
    }
    std::vector<Constraint> get_constraints() const {
        return constraints;
    }
    std::vector<Constraint> unique_constraints() const;
    std::vector<Constraint> fkey_constraints() const;

    Table& add_index(const Index& index);
    Table& drop_index(const std::string& name);
    Table& drop_index(const Index& i) {
        return drop_index(i.name);
    }
    std::vector<Index> get_indices() const {
        return indices;
    }

    Table();
    virtual ~Table();
};

} /* namespace sqltranslator */

#endif /* TABLE_H_ */
