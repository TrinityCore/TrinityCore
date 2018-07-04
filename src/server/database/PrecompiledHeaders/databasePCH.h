#include "Define.h"
#include "Errors.h"
#include "Field.h"
#include "Log.h"
#include "MySQLConnection.h"
#include "PreparedStatement.h"
#include "QueryResult.h"
#include "SQLOperation.h"
#include "Transaction.h"
#ifdef _WIN32 // hack for broken mysql.h not including the correct winsock header for SOCKET definition, fixed in 5.7
#include <winsock2.h>
#endif
#include <mysql.h>
#include <string>
#include <vector>
