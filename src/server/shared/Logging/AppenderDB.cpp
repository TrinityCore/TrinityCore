#include "AppenderDB.h"

/* FIXME
#include "DatabaseWorkerPool.h"
#include "Implementation/LoginDatabase.h" // For logging
extern DatabaseWorkerPool LoginDatabase;
*/

AppenderDB::AppenderDB(uint8 id, std::string const& name, LogLevel level, uint8 realmId):
Appender(id, name, APPENDER_DB, level), realm(realmId), enable(false)
{
}

AppenderDB::~AppenderDB()
{
}

void AppenderDB::_write(LogMessage& /*message*/)
{
/* FIXME
    if (enable)
        LoginDatabase.PExecute("INSERT INTO logs (time, realm, type, severity, string) "
            "VALUES (" UI64FMTD ", %u, %u, '%s');", message.mtime, realm, message.type, message.level, message.text.c_str());
*/
}

void AppenderDB::setEnable(bool _enable)
{
    enable = _enable;
}
