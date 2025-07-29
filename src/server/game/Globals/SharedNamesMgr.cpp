#include "SharedNamesMgr.h"
#include "Realm.h"

void SharedNamesMgr::AddSharedName(SharedNameType type, std::string const& name, uint32 guid) const
{
    auto* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_SHARED_NAMES);
    stmt->setUInt32(0, to_underlying(type));
    stmt->setUInt32(1, guid);
    stmt->setString(2, name);
    stmt->setUInt32(3, realm.Id.Realm);
    stmt->setUInt32(4, realm.groupId);
    LoginDatabase.Execute(stmt);
}

void SharedNamesMgr::DeleteSharedName(SharedNameType type, uint32 guid) const
{
    auto* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_SHARED_NAMES_BY_GUID);
    stmt->setUInt32(0, to_underlying(type));
    stmt->setUInt32(1, guid);
    stmt->setUInt32(2, realm.Id.Realm);
    LoginDatabase.Execute(stmt);
}

void SharedNamesMgr::UpdateSharedName(SharedNameType type, std::string const& newName, uint32 guid) const
{
    auto* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_SHARED_NAME_BY_GUID);
    stmt->setString(0, newName);
    stmt->setUInt32(1, to_underlying(type));
    stmt->setUInt32(2, guid);
    stmt->setUInt32(3, realm.Id.Realm);
    LoginDatabase.Execute(stmt);
}

QueryCallback SharedNamesMgr::GetSharedNameCheckQueryCallback(SharedNameType type, std::string const& name) const
{
    LoginDatabasePreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_SHARED_NAMES_BY_NAME);
    stmt->setUInt32(0, to_underlying(type));
    stmt->setString(1, name);
    stmt->setUInt32(2, realm.groupId);
    return LoginDatabase.AsyncQuery(stmt);
}
