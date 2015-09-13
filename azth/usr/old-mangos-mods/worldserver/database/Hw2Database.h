/* 
 * File:   Hw2DBImplement.h
 * Author: giuseppe
 *
 * Created on 19 agosto 2013, 12.49
 */

#ifndef HW2DATABASE_H
#define	HW2DATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class HW2DatabaseConnection : public MySQLConnection
{
    public:
        //- Constructors for sync and async connections
        HW2DatabaseConnection(MySQLConnectionInfo& connInfo) : MySQLConnection(connInfo) {}
        HW2DatabaseConnection(ACE_Activation_Queue* q, MySQLConnectionInfo& connInfo) : MySQLConnection(q, connInfo) {}

        //- Loads database type specific prepared statements
        void DoPrepareStatements();
};

typedef DatabaseWorkerPool<HW2DatabaseConnection> Hw2DatabaseWorkerPool;

enum Hw2DatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */

    HW2_SEL_TEST,
    HW2_DEL_TEST,

    MAX_HW2DATABASE_STATEMENTS
};

#endif	/* HW2DATABASE_H */

