#ifndef PGSQLOPERATION_H_INCLUDED
#define PGSQLOPERATION_H_INCLUDED

#include <ace/Method_Request.h>
#include <ace/Activation_Queue.h>

#include "QueryResult.h"

//- Forward declare (don't include header to prevent circular includes)
class PreparedStatement;

//- Union that holds element data
union SQLElementUnion
{
    PreparedStatement* stmt;
    const char* query;
};

//- Type specifier of our element data
enum SQLElementDataType
{
    SQL_ELEMENT_RAW,
    SQL_ELEMENT_PREPARED,
};

//- The element
struct SQLElementData
{
    SQLElementUnion element;
    SQLElementDataType type;
};

//- For ambigious resultsets
union SQLResultSetUnion
{
    PreparedResultSet* presult;
    ResultSet* qresult;
};

class PgSQLConnection;

class SQLOperation : public ACE_Method_Request
{

};

#endif // PGSQLOPERATION_H_INCLUDED
