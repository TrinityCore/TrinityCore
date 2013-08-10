/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "RBAC.h"
#include "AccountMgr.h"
#include "DatabaseEnv.h"
#include "Log.h"

void RBACRole::GrantPermission(uint32 permissionId)
{
    if (permissionId < RBAC_PERM_MAX)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACRole::GrantPermission (Role %u, Permission %u). Ok", GetId(), permissionId);
        _perms.set(permissionId);
    }
    else
        TC_LOG_ERROR(LOG_FILTER_RBAC, "RBACRole::GrantPermission (Role %u, Permission %u). Permission not lower than %u",
                       GetId(), permissionId, RBAC_PERM_MAX);
}

void RBACRole::RevokePermission(uint32 permissionId)
{
    if (permissionId < RBAC_PERM_MAX)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACRole::RevokePermission (Role %u, Permission %u). Ok", GetId(), permissionId);
        _perms.reset(permissionId);
    }
    else
        TC_LOG_ERROR(LOG_FILTER_RBAC, "RBACRole::RevokePermission (Role %u, Permission %u). Permission not lower than %u",
                       GetId(), permissionId, RBAC_PERM_MAX);
}

void RBACGroup::GrantRole(uint32 roleId)
{
    TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACRole::GrantPermission (Role %u, Permission %u). Ok", GetId(), roleId);
    _roles.insert(roleId);
}

void RBACGroup::RevokeRole(uint32 roleId)
{
    TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACRole::GrantPermission (Role %u, Permission %u). Ok", GetId(), roleId);
    _roles.erase(roleId);
}

RBACCommandResult RBACData::AddGroup(uint32 groupId, int32 realmId /* = 0 */)
{
    // Check if group Id exists
    RBACGroup const* group = sAccountMgr->GetRBACGroup(groupId);
    if (!group)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::AddGroup [Id: %u Name: %s] (Group %u, RealmId %d). Group does not exists",
                       GetId(), GetName().c_str(), groupId, realmId);
        return RBAC_ID_DOES_NOT_EXISTS;
    }

    // Already added?
    std::pair<std::set<uint32>::iterator, bool> ret = _groups.insert(groupId);
    if (!ret.second)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::AddGroup [Id: %u Name: %s] (Group %u, RealmId %d). Group Already added",
                       GetId(), GetName().c_str(), groupId, realmId);
        return RBAC_CANT_ADD_ALREADY_ADDED;
    }

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::AddGroup [Id: %u Name: %s] (Group %u, RealmId %d). Added and DB updated",
                       GetId(), GetName().c_str(), groupId, realmId);
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_RBAC_ACCOUNT_GROUP);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, groupId);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);

        CalculateNewPermissions();
    }
    else
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::AddGroup [Id: %u Name: %s] (Group %u, RealmId %d). Added",
                       GetId(), GetName().c_str(), groupId, realmId);

    return RBAC_OK;
}

RBACCommandResult RBACData::RemoveGroup(uint32 groupId, int32 realmId /* = 0 */)
{
    // could remove it?
    if (!_groups.erase(groupId))
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RemoveGroup [Id: %u Name: %s] (Group %u, RealmId %d). Group not in list",
                       GetId(), GetName().c_str(), groupId, realmId);
        return RBAC_CANT_REVOKE_NOT_IN_LIST;
    }

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RemoveGroup [Id: %u Name: %s] (Group %u, RealmId %d). Removed and DB updated",
                       GetId(), GetName().c_str(), groupId, realmId);
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_RBAC_ACCOUNT_GROUP);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, groupId);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);

        CalculateNewPermissions();
    }
    else
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RemoveGroup [Id: %u Name: %s] (Group %u, RealmId %d). Removed",
                       GetId(), GetName().c_str(), groupId, realmId);

    return RBAC_OK;
}

RBACCommandResult RBACData::GrantRole(uint32 roleId, int32 realmId /* = 0*/)
{
    // Check if role Id exists
    RBACRole const* role = sAccountMgr->GetRBACRole(roleId);
    if (!role)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantRole [Id: %u Name: %s] (Role %u, RealmId %d). Role does not exists",
                       GetId(), GetName().c_str(), roleId, realmId);
        return RBAC_ID_DOES_NOT_EXISTS;
    }

    // Check if already added in denied list
    if (_deniedRoles.find(roleId) != _deniedRoles.end())
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantRole [Id: %u Name: %s] (Role %u, RealmId %d). Role in deny list",
                       GetId(), GetName().c_str(), roleId, realmId);
        return RBAC_IN_DENIED_LIST;
    }

    // Already added?
    std::pair<std::set<uint32>::iterator, bool> ret = _grantedRoles.insert(roleId);
    if (!ret.second)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantRole [Id: %u Name: %s] (Role %u, RealmId %d). Role already granted",
                       GetId(), GetName().c_str(), roleId, realmId);
        return RBAC_CANT_ADD_ALREADY_ADDED;
    }

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantRole [Id: %u Name: %s] (Role %u, RealmId %d). Ok and DB updated",
                       GetId(), GetName().c_str(), roleId, realmId);
        SaveRole(roleId, true, realmId);
        CalculateNewPermissions();
    }
    else
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantRole [Id: %u Name: %s] (Role %u, RealmId %d). Ok",
                       GetId(), GetName().c_str(), roleId, realmId);

    return RBAC_OK;
}

RBACCommandResult RBACData::DenyRole(uint32 roleId, int32 realmId /* = 0*/)
{
    // Check if role Id exists
    RBACRole const* role = sAccountMgr->GetRBACRole(roleId);
    if (!role)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyRole [Id: %u Name: %s] (Role %u, RealmId %d). Role does not exists",
                       GetId(), GetName().c_str(), roleId, realmId);
        return RBAC_ID_DOES_NOT_EXISTS;
    }

    // Check if already added in granted list
    if (_grantedRoles.find(roleId) != _grantedRoles.end())
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyRole [Id: %u Name: %s] (Role %u, RealmId %d). Role in grant list",
                       GetId(), GetName().c_str(), roleId, realmId);
        return RBAC_IN_GRANTED_LIST;
    }

    // Already added?
    std::pair<std::set<uint32>::iterator, bool> ret = _deniedRoles.insert(roleId);
    if (!ret.second)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyRole [Id: %u Name: %s] (Role %u, RealmId %d). Role already denied",
                       GetId(), GetName().c_str(), roleId, realmId);
        return RBAC_CANT_ADD_ALREADY_ADDED;
    }

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyRole [Id: %u Name: %s] (Role %u, RealmId %d). Ok and DB updated",
                       GetId(), GetName().c_str(), roleId, realmId);
        SaveRole(roleId, false, realmId);
        CalculateNewPermissions();
    }
    else
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyRole [Id: %u Name: %s] (Role %u, RealmId %d). Ok",
                       GetId(), GetName().c_str(), roleId, realmId);

    return RBAC_OK;
}

void RBACData::SaveRole(uint32 roleId, bool granted, int32 realmId)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_RBAC_ACCOUNT_ROLE);
    stmt->setUInt32(0, GetId());
    stmt->setUInt32(1, roleId);
    stmt->setBool(2, granted);
    stmt->setInt32(3, realmId);
    LoginDatabase.Execute(stmt);
}

RBACCommandResult RBACData::RevokeRole(uint32 roleId, int32 realmId /* = 0*/)
{
    uint8 revoked = _grantedRoles.erase(roleId) + _deniedRoles.erase(roleId);

    // could remove it?
    if (!revoked)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RevokeRole [Id: %u Name: %s] (Role %u, RealmId %d). Not granted or revoked",
                       GetId(), GetName().c_str(), roleId, realmId);
        return RBAC_CANT_REVOKE_NOT_IN_LIST;
    }

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RevokeRole [Id: %u Name: %s] (Role %u, RealmId %d). Ok and DB updated",
                       GetId(), GetName().c_str(), roleId, realmId);
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_RBAC_ACCOUNT_ROLE);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, roleId);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);

        CalculateNewPermissions();
    }
    else
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RevokeRole [Id: %u Name: %s] (Role %u, RealmId %d). Ok",
                       GetId(), GetName().c_str(), roleId, realmId);

    return RBAC_OK;
}

RBACCommandResult RBACData::GrantPermission(uint32 permissionId, int32 realmId /* = 0*/)
{
    // Check if permission Id exists
    RBACPermission const* perm = sAccountMgr->GetRBACPermission(permissionId);
    if (!perm)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Permission does not exists",
                       GetId(), GetName().c_str(), permissionId, realmId);
        return RBAC_ID_DOES_NOT_EXISTS;
    }

    // Check if already added in denied list
    if (_deniedPerms.test(permissionId))
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Permission in deny list",
                       GetId(), GetName().c_str(), permissionId, realmId);
        return RBAC_IN_DENIED_LIST;
    }

    // Already added?
    if (_grantedPerms.test(permissionId))
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Permission already granted",
                       GetId(), GetName().c_str(), permissionId, realmId);
        return RBAC_CANT_ADD_ALREADY_ADDED;
    }

    _grantedPerms.set(permissionId);

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Ok and DB updated",
                       GetId(), GetName().c_str(), permissionId, realmId);
        SavePermission(permissionId, true, realmId);
        CalculateNewPermissions();
    }
    else
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::GrantPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Ok",
                       GetId(), GetName().c_str(), permissionId, realmId);

    return RBAC_OK;
}

RBACCommandResult RBACData::DenyPermission(uint32 permissionId, int32 realmId /* = 0*/)
{
    // Check if permission Id exists
    RBACPermission const* perm = sAccountMgr->GetRBACPermission(permissionId);
    if (!perm)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Permission does not exists",
                       GetId(), GetName().c_str(), permissionId, realmId);
        return RBAC_ID_DOES_NOT_EXISTS;
    }

    // Check if already added in granted list
    if (_grantedPerms.test(permissionId))
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Permission in grant list",
                       GetId(), GetName().c_str(), permissionId, realmId);
        return RBAC_IN_GRANTED_LIST;
    }

    // Already added?
    if (_deniedPerms.test(permissionId))
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Permission already denied",
                       GetId(), GetName().c_str(), permissionId, realmId);
        return RBAC_CANT_ADD_ALREADY_ADDED;
    }

    _deniedPerms.set(permissionId);

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Ok and DB updated",
                       GetId(), GetName().c_str(), permissionId, realmId);
        SavePermission(permissionId, false, realmId);
        CalculateNewPermissions();
    }
    else
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::DenyPermission [Id: %u Name: %s] (Permission %u, RealmId %d). Ok",
                       GetId(), GetName().c_str(), permissionId, realmId);

    return RBAC_OK;
}

void RBACData::SavePermission(uint32 permission, bool granted, int32 realmId)
{
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_RBAC_ACCOUNT_PERMISSION);
    stmt->setUInt32(0, GetId());
    stmt->setUInt32(1, permission);
    stmt->setBool(2, granted);
    stmt->setInt32(3, realmId);
    LoginDatabase.Execute(stmt);
}

RBACCommandResult RBACData::RevokePermission(uint32 permissionId, int32 realmId /* = 0*/)
{
    // Check if it's present in any list
    if (!_grantedPerms.test(permissionId) && !_deniedPerms.test(permissionId))
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RevokePermission [Id: %u Name: %s] (Permission %u, RealmId %d). Not granted or revoked",
                       GetId(), GetName().c_str(), permissionId, realmId);
        return RBAC_CANT_REVOKE_NOT_IN_LIST;
    }

    _grantedPerms.reset(permissionId);
    _deniedPerms.reset(permissionId);

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RevokePermission [Id: %u Name: %s] (Permission %u, RealmId %d). Ok and DB updated",
                       GetId(), GetName().c_str(), permissionId, realmId);
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_RBAC_ACCOUNT_PERMISSION);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, permissionId);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);

        CalculateNewPermissions();
    }
    else
        TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::RevokePermission [Id: %u Name: %s] (Permission %u, RealmId %d). Ok",
                       GetId(), GetName().c_str(), permissionId, realmId);

    return RBAC_OK;
}

void RBACData::LoadFromDB()
{
    TC_LOG_INFO(LOG_FILTER_RBAC, "RBACData::LoadFromDB [Id: %u Name: %s]", GetId(), GetName().c_str());
    TC_LOG_DEBUG(LOG_FILTER_RBAC, "RBACData::LoadFromDB [Id: %u Name: %s]: Loading groups", GetId(), GetName().c_str());

    // Load account group that affect current realm
    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_RBAC_ACCOUNT_GROUPS);
    stmt->setUInt32(0, GetId());
    stmt->setInt32(1, GetRealmId());
    PreparedQueryResult result = LoginDatabase.Query(stmt);

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            AddGroup(fields[0].GetUInt32());
        }
        while (result->NextRow());
    }

    TC_LOG_DEBUG(LOG_FILTER_RBAC, "RBACData::LoadFromDB [Id: %u Name: %s]: Loading roles", GetId(), GetName().c_str());
    // Load account roles (granted and denied) that affect current realm
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_RBAC_ACCOUNT_ROLES);
    stmt->setUInt32(0, GetId());
    stmt->setInt32(1, GetRealmId());
    result = LoginDatabase.Query(stmt);

    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            if (fields[1].GetBool())
                GrantRole(fields[0].GetUInt32());
            else
                DenyRole(fields[0].GetUInt32());
        }
        while (result->NextRow());
    }

    TC_LOG_DEBUG(LOG_FILTER_RBAC, "RBACData::LoadFromDB [Id: %u Name: %s]: Loading permissions", GetId(), GetName().c_str());
    // Load account permissions (granted and denied) that affect current realm
    stmt = LoginDatabase.GetPreparedStatement(LOGIN_SEL_RBAC_ACCOUNT_PERMISSIONS);
    stmt->setUInt32(0, GetId());
    stmt->setInt32(1, GetRealmId());

    result = LoginDatabase.Query(stmt);
    if (result)
    {
        do
        {
            Field* fields = result->Fetch();
            if (fields[1].GetBool())
                GrantPermission(fields[0].GetUInt32());
            else
                DenyPermission(fields[0].GetUInt32());
        }
        while (result->NextRow());
    }

    TC_LOG_DEBUG(LOG_FILTER_RBAC, "RBACData::LoadFromDB [Id: %u Name: %s]: Adding default groups", GetId(), GetName().c_str());
    // Add default groups
    RBACGroupContainer const& groups = sAccountMgr->GetRBACDefaultGroups();
    for (RBACGroupContainer::const_iterator itr = groups.begin(); itr != groups.end(); ++itr)
        AddGroup(*itr);

    TC_LOG_DEBUG(LOG_FILTER_RBAC, "RBACData::LoadFromDB [Id: %u Name: %s]: Calculating global permissions", GetId(), GetName().c_str());
    // Force calculation of permissions, it wasn't performed at load time
    // while adding groups, roles and permissions
    CalculateNewPermissions();
}

void RBACData::CalculateNewPermissions()
{
    TC_LOG_TRACE(LOG_FILTER_RBAC, "RBACData::LoadFromDB [Id: %u Name: %s]: Calculating global permissions", GetId(), GetName().c_str());
    // Get the list of directly granted roles
    RBACRoleContainer tempGrantedRoles = GetGrantedRoles();

    // Add those roles inherited from groups
    for (RBACGroupContainer::const_iterator itGroup = _groups.begin(); itGroup != _groups.end(); ++itGroup)
    {
        RBACGroup const* group = sAccountMgr->GetRBACGroup(*itGroup);
        if (!group) // Should never happen due to foreign keys in DB
            continue;

        RBACRoleContainer const& roles = group->GetRoles();
        for (RBACRoleContainer::const_iterator it = roles.begin(); it != roles.end(); ++it)
            tempGrantedRoles.insert(*it);
    }

    // Get the list of granted permissions
    _globalPerms = GetGrantedPermissions();

    // Add those permissions inherited from roles granted
    for (RBACRoleContainer::const_iterator it = tempGrantedRoles.begin(); it != tempGrantedRoles.end(); ++it)
        if (RBACRole const* role = sAccountMgr->GetRBACRole(*it))
            _globalPerms |= role->GetPermissions();

    // Remove denied permissions from the list
    _globalPerms &= ~GetDeniedPermissions();

    // Remove those permissions inherited from denied roles
    for (RBACRoleContainer::const_iterator it = _deniedRoles.begin(); it != _deniedRoles.end(); ++it)
        if (RBACRole const* role = sAccountMgr->GetRBACRole(*it))
           _globalPerms &= ~role->GetPermissions();
}
