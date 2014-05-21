/*
 * Index.h
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#ifndef INDEX_H_
#define INDEX_H_

#include <vector>
#include <string>
#include "Object.h"

namespace sqltranslator {

enum class IndexType {
    unique     = 0,
    normal     = 1,
    fulltext   = 2,
    full_text  = 2,
    spatial    = 3
};

class Index: public Object {
public:
    std::string name;
    IndexType type;
    std::vector<std::string> fields;
    std::vector<std::string> options;

    Index();
    virtual ~Index();
};

} /* namespace sqltranslator */

#endif /* INDEX_H_ */
