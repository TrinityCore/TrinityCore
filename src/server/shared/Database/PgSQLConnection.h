
#include <ace/Activation_Queue.h>

#include "DatabaseWorkerPool.h"
#include "Transaction.h"
#include "Util.h"

#ifndef POSTGRESQLCONNECTION_H_INCLUDED
#define POSTGRESQLCONNECTION_H_INCLUDED

class DatabaseWorker;
class PreparedStatement;
class PgSQLPreparedStatement;
class PingOperation;

enum ConnectionFlags
{
    CONNECTION_ASYNC = 0x1,
    CONNECTION_SYNCH = 0x2,
    CONNECTION_BOTH = CONNECTION_ASYNC | CONNECTION_SYNCH,
};

struct PgSQLConnectionInfo
{
    PgSQLConnectionInfo() {}
    PgSQLConnectionInfo(const std::string& infoString)
    {
        Tokens tokens(infoString, ';');

        if (tokens.size() != 5)
            return;

        uint8 i = 0;

        host.assign(tokens[i++]);
        port_or_socket.assign(tokens[i++]);
        user.assign(tokens[i++]);
        password.assign(tokens[i++]);
        database.assign(tokens[i++]);
    }

    std::string user;
    std::string password;
    std::string database;
    std::string host;
    std::string port_or_socket;
};

struct PreparedStatementTable
{
    uint32 index;
    const char* query;
    ConnectionFlags type;
};

typedef std::map<uint32 /*index*/, std::pair<const char* /*query*/, ConnectionFlags /*sync/async*/> > PreparedStatementMap;

#define PREPARE_STATEMENT(a, b, c) m_queries[a] = std::make_pair(strdup(b), c);

class PgSQLConnection
{
    template <class T> friend class DatabaseWorkerPool;
    friend class PingOperation;

    public:
        PgSQLConnection(PgSQLConnectionInfo& connInfo);                               //! Constructor for synchronous connections.
        PgSQLConnection(ACE_Activation_Queue* queue, PgSQLConnectionInfo& connInfo);  //! Constructor for asynchronous connections.
        virtual ~PgSQLConnection();

        virtual bool Open();
        void Close();

    public:
        bool Execute(const char* sql);
        bool Execute(PreparedStatement* stmt);
        ResultSet* Query(const char* sql);
        PreparedResultSet* Query(PreparedStatement* stmt);
/*        bool _Query(const char *sql, PGresult **pResult, MYSQL_FIELD **pFields, uint64* pRowCount, uint32* pFieldCount);*/
        bool _Query(PreparedStatement* stmt, PGresult **pResult, uint64* pRowCount, uint32* pFieldCount);

        void BeginTransaction();
        void RollbackTransaction();
        void CommitTransaction();
        bool ExecuteTransaction(SQLTransaction& transaction);

        operator bool () const { return m_Postgres != NULL; }
        void Ping() { /*pg_ping(m_Postgres);*/ } //TODO Fil

        uint32 GetLastError() { return 0; /*pg_last_error(m_Postgres);*/ } //TODO Fil

    protected:
        bool LockIfReady()
        {
            /// Tries to acquire lock. If lock is acquired by another thread
            /// the calling parent will just try another connection
            return m_Mutex.tryacquire() != -1;
        }

        void Unlock()
        {
            /// Called by parent databasepool. Will let other threads access this connection
            m_Mutex.release();
        }
/*
        MYSQL* GetHandle()  { return m_Mysql; }*/
        PgSQLPreparedStatement* GetPreparedStatement(uint32 index);
/*        void PrepareStatement(uint32 index, const char* sql, ConnectionFlags flags);

        bool PrepareStatements();
        virtual void DoPrepareStatements() = 0;
*/
    protected:
#ifdef DO_POSTGRESQL
        std::vector<PgSQLPreparedStatement*> m_stmts;
#else
        std::vector<MySQLPreparedStatement*> m_stmts;         //! PreparedStatements storage
#endif
        PreparedStatementMap                 m_queries;       //! Query storage
        bool                                 m_reconnecting;  //! Are we reconnecting?
        bool                                 m_prepareError;  //! Was there any error while preparing statements?

    private:
        bool _HandleMySQLErrno(uint32 errNo);

    private:
        ACE_Activation_Queue* m_queue;                      //! Queue shared with other asynchronous connections.
        DatabaseWorker*       m_worker;                     //! Core worker task.
        PGconn *              m_Postgres;                      //! MySQL Handle.
#ifdef DO_POSTGRESQL
        PgSQLConnectionInfo&  m_connectionInfo;
#else
        MySQLConnectionInfo&  m_connectionInfo;             //! Connection info (used for logging)
#endif
        ConnectionFlags       m_connectionFlags;            //! Connection flags (for preparing relevant statements)
        ACE_Thread_Mutex      m_Mutex;
};

#endif // POSTGRESQLCONNECTION_H_INCLUDED
