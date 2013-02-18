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

RBACCommandResult RBACData::AddGroup(uint32 groupId, int32 realmId /* = 0 */)
{
    // Check if group Id exists
    RBACGroup const* group = sAccountMgr->GetRBACGroup(groupId);
    if (!group)
        return RBAC_ID_DOES_NOT_EXISTS;

    // Already added?
    std::pair<std::set<uint32>::iterator, bool> ret = _groups.insert(groupId);
    if (!ret.second)
        return RBAC_CANT_ADD_ALREADY_ADDED;

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_INS_RBAC_ACCOUNT_GROUP);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, groupId);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);

        CalculateNewPermissions();
    }

    return RBAC_OK;
}

RBACCommandResult RBACData::RemoveGroup(uint32 groupId, int32 realmId /* = 0 */)
{
    // could remove it?
    if (!_groups.erase(groupId))
        return RBAC_CANT_REVOKE_NOT_IN_LIST;

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_RBAC_ACCOUNT_GROUP);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, groupId);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);

        CalculateNewPermissions();
    }

    return RBAC_OK;
}

RBACCommandResult RBACData::GrantRole(uint32 roleId, int32 realmId /* = 0*/)
{
    // Check if role Id exists
    RBACRole const* role = sAccountMgr->GetRBACRole(roleId);
    if (!role)
        return RBAC_ID_DOES_NOT_EXISTS;

    // Check if already added in denied list
    if (_deniedRoles.find(roleId) != _deniedRoles.end())
        return RBAC_IN_DENIED_LIST;

    // Already added?
    std::pair<std::set<uint32>::iterator, bool> ret = _grantedRoles.insert(roleId);
    if (!ret.second)
        return RBAC_CANT_ADD_ALREADY_ADDED;

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        SaveRole(roleId, true, realmId);
        CalculateNewPermissions();
    }

    return RBAC_OK;
}

RBACCommandResult RBACData::DenyRole(uint32 roleId, int32 realmId /* = 0*/)
{
    // Check if role Id exists
    RBACRole const* role = sAccountMgr->GetRBACRole(roleId);
    if (!role)
        return RBAC_ID_DOES_NOT_EXISTS;

    // Check if already added in granted list
    if (_grantedRoles.find(roleId) != _grantedRoles.end())
        return RBAC_IN_GRANTED_LIST;

    // Already added?
    std::pair<std::set<uint32>::iterator, bool> ret = _deniedRoles.insert(roleId);
    if (!ret.second)
        return RBAC_CANT_ADD_ALREADY_ADDED;

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        SaveRole(roleId, false, realmId);
        CalculateNewPermissions();
    }

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
        return RBAC_CANT_REVOKE_NOT_IN_LIST;

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_RBAC_ACCOUNT_ROLE);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, roleId);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);

        CalculateNewPermissions();
    }

    return RBAC_OK;
}

RBACCommandResult RBACData::GrantPermission(uint32 permissionId, int32 realmId /* = 0*/)
{
    // Check if permission Id exists
    RBACPermission const* perm = sAccountMgr->GetRBACPermission(permissionId);
    if (!perm)
        return RBAC_ID_DOES_NOT_EXISTS;

    // Check if already added in denied list
    if (_deniedPerms.test(permissionId))
        return RBAC_IN_DENIED_LIST;

    // Already added?
    if (_grantedPerms.test(permissionId))
        return RBAC_CANT_ADD_ALREADY_ADDED;

    _grantedPerms.set(permissionId);

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        SavePermission(permissionId, true, realmId);
        CalculateNewPermissions();
    }

    return RBAC_OK;
}

RBACCommandResult RBACData::DenyPermission(uint32 permissionId, int32 realmId /* = 0*/)
{
    // Check if permission Id exists
    RBACPermission const* perm = sAccountMgr->GetRBACPermission(permissionId);
    if (!perm)
        return RBAC_ID_DOES_NOT_EXISTS;

    // Check if already added in granted list
    if (_grantedPerms.test(permissionId))
        return RBAC_IN_GRANTED_LIST;

    // Already added?
    if (_deniedPerms.test(permissionId))
        return RBAC_CANT_ADD_ALREADY_ADDED;

    _deniedPerms.set(permissionId);

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        SavePermission(permissionId, false, realmId);
        CalculateNewPermissions();
    }

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

RBACCommandResult RBACData::RevokePermission(uint32 permission, int32 realmId /* = 0*/)
{
    // Check if it's present in any list
    if (!_grantedPerms.test(permission) && !_deniedPerms.test(permission))
        return RBAC_CANT_REVOKE_NOT_IN_LIST;

    _grantedPerms.reset(permission);
    _deniedPerms.reset(permission);

    // Do not save to db when loading data from DB (realmId = 0)
    if (realmId)
    {
        PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_DEL_RBAC_ACCOUNT_PERMISSION);
        stmt->setUInt32(0, GetId());
        stmt->setUInt32(1, permission);
        stmt->setInt32(2, realmId);
        LoginDatabase.Execute(stmt);

        CalculateNewPermissions();
    }

    return RBAC_OK;
}

void RBACData::LoadFromDB()
{
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

    // Add default groups
    RBACGroupContainer const& groups = sAccountMgr->GetRBACDefaultGroups();
    for (RBACGroupContainer::const_iterator itr = groups.begin(); itr != groups.end(); ++itr)
        AddGroup(*itr);

    // Force calculation of permissions, it wasn't performed at load time
    // while adding groups, roles and permissions
    CalculateNewPermissions();
}

void RBACData::CalculateNewPermissions()
{
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
