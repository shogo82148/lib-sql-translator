/*
 * Constraint.h
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#ifndef CONSTRAINT_H_
#define CONSTRAINT_H_

#include <vector>
#include <string>
#include "Object.h"

namespace sqltranslator {

enum class ConstraintType {
    PRIMARY_KEY = 0,
    UNIQUE      = 1,
    CHECK_C     = 2,
    FOREIGN_KEY = 3,
    NOT_NULL    = 4,
};

enum class MatchType {
    FULL,
    PARTIAL,
    SIMPLE,
};

class Constraint: public Object {
public:
    std::string name;
    std::string expression;
    std::string on_delete;
    std::string on_update;
    ConstraintType type;
    MatchType match_type;
    bool deferrable;
    std::vector<std::string> fields;

    Constraint();
    virtual ~Constraint();
};

} /* namespace sqltranslator */

#endif /* CONSTRAINT_H_ */
