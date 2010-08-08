#include "PreparedStatements.h"

void PreparedStatementHolder::_prepareStatement(const char* name, const char* sql, Database *db, uint32 &count)
{
    const char prefix[] = "PREPARE ";
    size_t querySize = 8 + strlen(name) + 6 + strlen(sql) + 2 + 1;
    char* query = new char[querySize];
    strcpy(query, prefix);
    strcat(query, name);
    strcat(query, " FROM ");
    strcat(query, "'");
    strcat(query, sql);
    strcat(query, "'");

    DEBUG_LOG("Preparing statement: %s", query);
    db->Execute(query);

    delete[] query;
    ++count;
}

void PreparedStatementHolder::LoadAuthserver(Database *db, uint32 &count)
{
    _prepareStatement("auth_ping", "SELECT 1 FROM realmlist LIMIT 1", db, count);
};

void PreparedStatementHolder::Execute(Database *db, const char *name)
{
    const char prefix[] = "EXECUTE ";
    size_t querySize = 8 + strlen(name) + 1;
    char* query = new char[querySize];
    strcpy(query, prefix);
    strcat(query, name);

    DEBUG_LOG("Prepared statement: %s", query);
    db->Execute(query);
    delete[] query;
}

void PreparedStatementHolder::PExecute(Database *db, const char *name, const char* args)
{
    // NOTE: if args == NULL, we're crashing here. No need to waste performance on checking;
    // devs must make sure they use PExecute for args and Execute for no args.

    const char prefix[] = "EXECUTE ";
    size_t querySize = 8 + strlen(name) + 7 + strlen(args) + 1;
    char* query = new char[querySize];
    strcpy(query, prefix);
    strcat(query, name);
    strcat(query, " USING ");
    strcat(query, args);

    DEBUG_LOG("Prepared statement (parsed args): %s", query);
    db->Execute(query);
    delete[] query;
}

QueryResult_AutoPtr PreparedStatementHolder::Query(Database *db, const char *name)
{
    QueryResult_AutoPtr _return = QueryResult_AutoPtr(NULL);

    const char prefix[] = "EXECUTE ";
    size_t querySize = 8 + strlen(name) + 1;
    char* query = new char[querySize];
    strcpy(query, prefix);
    strcat(query, name);

    DEBUG_LOG("Prepared statement with resultset: %s", query);
    _return = db->Query(query);
    delete[] query;
    return _return;
}

QueryResult_AutoPtr PreparedStatementHolder::PQuery(Database *db, const char *name, const char *args)
{
    // NOTE: if args == NULL, we're crashing here. No need to waste performance on checking;
    // devs must make sure they use PQuery for args and Query for no args.

    QueryResult_AutoPtr _return = QueryResult_AutoPtr(NULL);

    const char prefix[] = "EXECUTE ";
    size_t querySize = 8 + strlen(name) + 7 + strlen(args) + 1;
    char* query = new char[querySize];
    strcpy(query, prefix);
    strcat(query, name);
    strcat(query, " USING ");
    strcat(query, args);

    DEBUG_LOG("Prepared statement with resultset (parsed args): %s", query);
    _return = db->Query(query);
    delete[] query;
    return _return;
}