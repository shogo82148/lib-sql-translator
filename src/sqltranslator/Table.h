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
    std::vector<Constraint> get_constraints() const {
        return constraints;
    }

    Table();
    virtual ~Table();
};

} /* namespace sqltranslator */

#endif /* TABLE_H_ */
