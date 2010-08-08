#ifndef sPreparedStatement

#include "ace/Singleton.h"
#include "Database/DatabaseEnv.h"

class PreparedStatementHolder
{
    public:
        ///- Load prepare statements on database $db and increase $count for every statement
        void LoadCharacters(Database *db, uint32 &count);
        void LoadAuthserver(Database *db, uint32 &count);
        void LoadWorldserver(Database *db, uint32 &count);

        ///- Executes prepared statement that doesn't require feedback with name $name on database $db
        void Execute(Database *db, const char* name);
        ///- Executes prepared statement that doesn't require feedback with name $name and args $args
        ///- on database $db
        void PExecute(Database *db, const char* name, const char* args);

        ///- Executes a prepared statement without args on db $db with name $name and puts the result set in a pointer.
        QueryResult_AutoPtr Query(Database* db, const char* name);
        ///- Executes a prepared statement with args $args on db $db with name $name and put the result set in a pointer.
        QueryResult_AutoPtr PQuery(Database* db, const char* name, const char* args);

    private:
        void _prepareStatement(const char* name, const char* sql, Database *db, uint32 &count);

};
#define sPreparedStatement (*ACE_Singleton<PreparedStatementHolder, ACE_Null_Mutex>::instance())
#endif