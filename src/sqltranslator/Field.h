/*
 * Field.h
 *
 *  Created on: 2014/05/20
 *      Author: shogo
 */

#ifndef FIELD_H_
#define FIELD_H_

#include <vector>
#include <string>
#include "Object.h"

namespace sqltranslator {
enum class SQLType :int {
    GUID                           = -11,
    WLONGVARCHAR                   = -10,
    WVARCHAR                       =  -9,
    WCHAR                          =  -8,
    BIT                            =  -7,
    TINYINT                        =  -6,
    BIGINT                         =  -5,
    LONGVARBINARY                  =  -4,
    VARBINARY                      =  -3,
    BINARY                         =  -2,
    LONGVARCHAR                    =  -1,
    UNKNOWN_TYPE                   =   0,
    ALL_TYPES                      =   0,
    CHAR                           =   1,
    NUMERIC                        =   2,
    DECIMAL                        =   3,
    INTEGER                        =   4,
    SMALLINT                       =   5,
    FLOAT                          =   6,
    REAL                           =   7,
    DOUBLE                         =   8,
    DATETIME                       =   9,
    DATE                           =   9,
    INTERVAL                       =  10,
    TIME                           =  10,
    TIMESTAMP                      =  11,
    VARCHAR                        =  12,
    BOOLEAN                        =  16,
    UDT                            =  17,
    UDT_LOCATOR                    =  18,
    ROW                            =  19,
    REF                            =  20,
    BLOB                           =  30,
    BLOB_LOCATOR                   =  31,
    CLOB                           =  40,
    CLOB_LOCATOR                   =  41,
    ARRAY                          =  50,
    ARRAY_LOCATOR                  =  51,
    MULTISET                       =  55,
    MULTISET_LOCATOR               =  56,
    TYPE_DATE                      =  91,
    TYPE_TIME                      =  92,
    TYPE_TIMESTAMP                 =  93,
    TYPE_TIME_WITH_TIMEZONE        =  94,
    TYPE_TIMESTAMP_WITH_TIMEZONE   =  95,
    INTERVAL_YEAR                  = 101,
    INTERVAL_MONTH                 = 102,
    INTERVAL_DAY                   = 103,
    INTERVAL_HOUR                  = 104,
    INTERVAL_MINUTE                = 105,
    INTERVAL_SECOND                = 106,
    INTERVAL_YEAR_TO_MONTH         = 107,
    INTERVAL_DAY_TO_HOUR           = 108,
    INTERVAL_DAY_TO_MINUTE         = 109,
    INTERVAL_DAY_TO_SECOND         = 110,
    INTERVAL_HOUR_TO_MINUTE        = 111,
    INTERVAL_HOUR_TO_SECOND        = 112,
    INTERVAL_MINUTE_TO_SECOND      = 113,
};

class Field: public Object {
public:
    SQLType data_type = SQLType::UNKNOWN_TYPE;
    std::string name;
    bool is_auto_increment = false;
    bool is_nullable = true;
    bool has_default_value = false;
    std::string default_value;
    std::vector<std::string> comments;
    int order = 0;

    Field();
    Field(const std::string& name);
    Field(const std::string& name, SQLType data_type, const std::string& default_value);
    virtual ~Field();
};

} /* namespace sqltranslator */

#endif /* FIELD_H_ */
