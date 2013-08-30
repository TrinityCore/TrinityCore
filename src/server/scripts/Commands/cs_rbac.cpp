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

/* ScriptData
Name: rbac_commandscript
%Complete: 100
Comment: All role based access control related commands (including account related)
Category: commandscripts
EndScriptData */

#include "AccountMgr.h"
#include "Config.h"
#include "Chat.h"
#include "Language.h"
#include "Player.h"
#include "ScriptMgr.h"

struct RBACCommandData
{
    RBACCommandData(): id(0), realmId(0), rbac(NULL), needDelete(false) { }
    ~RBACCommandData()
    {
        if (needDelete)
            delete rbac;
    }

    uint32 id;
    int32 realmId;
    RBACData* rbac;
    bool needDelete;
};

class rbac_commandscript : public CommandScript
{
public:
    rbac_commandscript() : CommandScript("rbac_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand rbacGroupsCommandTable[] =
        {
            {         "add", RBAC_PERM_COMMAND_RBAC_ACC_GROUP_ADD,  true, &HandleRBACGroupAddCommand,    "", NULL },
            {      "remove", RBAC_PERM_COMMAND_RBAC_ACC_GROUP_DEL,  true, &HandleRBACGroupRemoveCommand, "", NULL },
            {            "", RBAC_PERM_COMMAND_RBAC_ACC_GROUP, true, &HandleRBACGroupListCommand,   "", NULL },
            {          NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand rbacRolesCommandTable[] =
        {
            {       "grant", RBAC_PERM_COMMAND_RBAC_ACC_ROLE_GRANT,  true, &HandleRBACRoleGrantCommand,   "", NULL },
            {        "deny", RBAC_PERM_COMMAND_RBAC_ACC_ROLE_DENY,   true, &HandleRBACRoleDenyCommand,    "", NULL },
            {      "revoke", RBAC_PERM_COMMAND_RBAC_ACC_ROLE_REVOKE, true, &HandleRBACRoleRevokeCommand,  "", NULL },
            {            "", RBAC_PERM_COMMAND_RBAC_ACC_ROLE,   true, &HandleRBACRoleListCommand,    "", NULL },
            {          NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand rbacPermsCommandTable[] =
        {
            {       "grant", RBAC_PERM_COMMAND_RBAC_ACC_PERM_GRANT,  true, &HandleRBACPermGrantCommand,   "", NULL },
            {        "deny", RBAC_PERM_COMMAND_RBAC_ACC_PERM_DENY,   true, &HandleRBACPermDenyCommand,    "", NULL },
            {      "revoke", RBAC_PERM_COMMAND_RBAC_ACC_PERM_REVOKE, true, &HandleRBACPermRevokeCommand,  "", NULL },
            {            "", RBAC_PERM_COMMAND_RBAC_ACC_PERM,   true, &HandleRBACPermListCommand,    "", NULL },
            {          NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand rbacListCommandTable[] =
        {
            {      "groups", RBAC_PERM_COMMAND_RBAC_LIST_GROUPS, true, &HandleRBACListGroupsCommand,      "", NULL },
            {       "roles", RBAC_PERM_COMMAND_RBAC_LIST_ROLES,  true, &HandleRBACListRolesCommand,       "", NULL },
            { "permissions", RBAC_PERM_COMMAND_RBAC_LIST_PERMS,  true, &HandleRBACListPermissionsCommand, "", NULL },
            {          NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand rbacAccountCommandTable[] =
        {
            {       "group", RBAC_PERM_COMMAND_RBAC_ACC_GROUP, true, NULL, "", rbacGroupsCommandTable },
            {        "role", RBAC_PERM_COMMAND_RBAC_ACC_ROLE,  true, NULL, "", rbacRolesCommandTable },
            {  "permission", RBAC_PERM_COMMAND_RBAC_ACC_PERM,  true, NULL, "", rbacPermsCommandTable },
            {            "", RBAC_PERM_COMMAND_RBAC_ACC,       true, &HandleRBACAccountPermissionCommand, "", NULL },
            {          NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand rbacCommandTable[] =
        {
            {    "account", RBAC_PERM_COMMAND_RBAC_ACC,  true, NULL, "", rbacAccountCommandTable },
            {       "list", RBAC_PERM_COMMAND_RBAC_LIST, true, NULL, "", rbacListCommandTable },
            {         NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            {       "rbac", RBAC_PERM_COMMAND_RBAC, true, NULL, "", rbacCommandTable },
            {         NULL, 0, false, NULL, "", NULL }
        };

        return commandTable;
    }

    static RBACCommandData* ReadParams(ChatHandler* handler, char const* args, bool checkParams = true)
    {
        if (!args)
            return NULL;

        char* param1 = strtok((char*)args, " ");
        char* param2 = strtok(NULL, " ");
        char* param3 = strtok(NULL, " ");

        int32 realmId = -1;
        uint32 accountId = 0;
        std::string accountName;
        uint32 id = 0;
        RBACCommandData* data = NULL;
        RBACData* rdata = NULL;
        bool useSelectedPlayer = false;

        if (checkParams)
        {
            if (!param3)
            {
                if (param2)
                    realmId = atoi(param2);

                if (param1)
                    id = atoi(param1);

                useSelectedPlayer = true;
            }
            else
            {
                id = atoi(param2);
                realmId = atoi(param3);
            }

            if (!id)
            {
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, id);
                handler->SetSentErrorMessage(true);
                return NULL;
            }

            if (realmId < -1 || !realmId)
            {
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_REALM, realmId);
                handler->SetSentErrorMessage(true);
                return NULL;
            }
        }
        else if (!param1)
            useSelectedPlayer = true;

        if (useSelectedPlayer)
        {
            Player* player = handler->getSelectedPlayer();
            if (!player)
                return NULL;

            rdata = player->GetSession()->GetRBACData();
            accountId = rdata->GetId();
            AccountMgr::GetName(accountId, accountName);
        }
        else
        {
            accountName = param1;

            if (AccountMgr::normalizeString(accountName))
                accountId = AccountMgr::GetId(accountName);

            if (!accountId)
            {
                handler->PSendSysMessage(LANG_ACCOUNT_NOT_EXIST, accountName.c_str());
                handler->SetSentErrorMessage(true);
                return NULL;
            }
        }

        if (checkParams && handler->HasLowerSecurityAccount(NULL, accountId, true))
            return NULL;

        data = new RBACCommandData();

        if (!rdata)
        {
            data->rbac = new RBACData(accountId, accountName, realmID);
            data->rbac->LoadFromDB();
            data->needDelete = true;
        }
        else
            data->rbac = rdata;

        data->id = id;
        data->realmId = realmId;
        return data;
    }

    static bool HandleRBACGroupAddCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        RBACCommandResult result = command->rbac->AddGroup(command->id, command->realmId);
        RBACGroup const* group = sAccountMgr->GetRBACGroup(command->id);

        switch (result)
        {
            case RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_GROUP_IN_LIST, command->id, group->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_GROUP_ADDED, command->id, group->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, command->id);
                break;
            default:
                break;
        }

        delete command;

        return true;
    }

    static bool HandleRBACGroupRemoveCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        RBACCommandResult result = command->rbac->RemoveGroup(command->id, command->realmId);
        RBACGroup const* group = sAccountMgr->GetRBACGroup(command->id);

        switch (result)
        {
            case RBAC_CANT_REVOKE_NOT_IN_LIST:
                handler->PSendSysMessage(LANG_RBAC_GROUP_NOT_IN_LIST, command->id, group->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_GROUP_REMOVED, command->id, group->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, command->id);
                break;
            default:
                break;
        }

        delete command;

        return true;
    }

    static bool HandleRBACGroupListCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args, false);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_RBAC_GROUP_LIST_HEADER, command->rbac->GetId(), command->rbac->GetName().c_str());
        RBACGroupContainer const& groups = command->rbac->GetGroups();
        if (groups.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (RBACGroupContainer::const_iterator it = groups.begin(); it != groups.end(); ++it)
            {
                RBACGroup const* group = sAccountMgr->GetRBACGroup(*it);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, group->GetId(), group->GetName().c_str());
            }
        }

        delete command;

        return true;
    }

    static bool HandleRBACRoleGrantCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        RBACCommandResult result = command->rbac->GrantRole(command->id, command->realmId);
        RBACRole const* role = sAccountMgr->GetRBACRole(command->id);

        switch (result)
        {
            case RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_ROLE_GRANTED_IN_LIST, command->id, role->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_IN_DENIED_LIST:
                handler->PSendSysMessage(LANG_RBAC_ROLE_GRANTED_IN_DENIED_LIST, command->id, role->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_ROLE_GRANTED, command->id, role->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, command->id);
                break;
            default:
                break;
        }

        delete command;

        return true;
    }

    static bool HandleRBACRoleDenyCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        RBACCommandResult result = command->rbac->DenyRole(command->id, command->realmId);
        RBACRole const* role = sAccountMgr->GetRBACRole(command->id);

        switch (result)
        {
            case RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_ROLE_DENIED_IN_LIST, command->id, role->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_IN_GRANTED_LIST:
                handler->PSendSysMessage(LANG_RBAC_ROLE_DENIED_IN_GRANTED_LIST, command->id, role->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_ROLE_DENIED, command->id, role->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, command->id);
                break;
            default:
                break;
        }

        delete command;

        return true;
    }

    static bool HandleRBACRoleRevokeCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        RBACCommandResult result = command->rbac->RevokeRole(command->id, command->realmId);
        RBACRole const* role = sAccountMgr->GetRBACRole(command->id);

        switch (result)
        {
            case RBAC_CANT_REVOKE_NOT_IN_LIST:
                handler->PSendSysMessage(LANG_RBAC_ROLE_REVOKED_NOT_IN_LIST, command->id, role->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_ROLE_REVOKED, command->id, role->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, command->id);
                break;
            default:
                break;
        }

        delete command;

        return true;
    }

    static bool HandleRBACRoleListCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args, false);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_RBAC_ROLE_LIST_HEADER_GRANTED, command->rbac->GetId(), command->rbac->GetName().c_str());
        RBACGroupContainer const& granted = command->rbac->GetGrantedRoles();
        if (granted.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (RBACRoleContainer::const_iterator it = granted.begin(); it != granted.end(); ++it)
            {
                RBACRole const* role = sAccountMgr->GetRBACRole(*it);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, role->GetId(), role->GetName().c_str());
            }
        }

        handler->PSendSysMessage(LANG_RBAC_ROLE_LIST_HEADER_DENIED, command->rbac->GetId(), command->rbac->GetName().c_str());
        RBACGroupContainer const& denied = command->rbac->GetDeniedRoles();
        if (denied.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (RBACRoleContainer::const_iterator it = denied.begin(); it != denied.end(); ++it)
            {
                RBACRole const* role = sAccountMgr->GetRBACRole(*it);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, role->GetId(), role->GetName().c_str());
            }
        }

        delete command;

        return true;
    }

    static bool HandleRBACPermGrantCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        RBACCommandResult result = command->rbac->GrantPermission(command->id, command->realmId);
        RBACPermission const* permission = sAccountMgr->GetRBACPermission(command->id);

        switch (result)
        {
            case RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED_IN_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_IN_DENIED_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED_IN_DENIED_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, command->id);
                break;
            default:
                break;
        }

        delete command;

        return true;
    }

    static bool HandleRBACPermDenyCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        RBACCommandResult result = command->rbac->DenyPermission(command->id, command->realmId);
        RBACPermission const* permission = sAccountMgr->GetRBACPermission(command->id);

        switch (result)
        {
            case RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED_IN_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_IN_GRANTED_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED_IN_GRANTED_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, command->id);
                break;
            default:
                break;
        }

        delete command;

        return true;
    }

    static bool HandleRBACPermRevokeCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        RBACCommandResult result = command->rbac->RevokePermission(command->id, command->realmId);
        RBACPermission const* permission = sAccountMgr->GetRBACPermission(command->id);

        switch (result)
        {
            case RBAC_CANT_REVOKE_NOT_IN_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_REVOKED_NOT_IN_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_REVOKED, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, command->id);
                break;
            default:
                break;
        }

        delete command;

        return true;
    }

    static bool HandleRBACPermListCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args, false);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_RBAC_PERM_LIST_HEADER_GRANTED, command->rbac->GetId(), command->rbac->GetName().c_str());
        RBACPermissionContainer const& granted = command->rbac->GetGrantedPermissions();
        if (!granted.any())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (uint32 i = 0; i < RBAC_PERM_MAX; ++i)
                if (granted.test(i))
                {
                    RBACPermission const* permission = sAccountMgr->GetRBACPermission(i);
                    handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
                }
        }

        handler->PSendSysMessage(LANG_RBAC_PERM_LIST_HEADER_DENIED, command->rbac->GetId(), command->rbac->GetName().c_str());
        RBACPermissionContainer const& denied = command->rbac->GetDeniedPermissions();
        if (!denied.any())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (uint32 i = 0; i < RBAC_PERM_MAX; ++i)
                if (denied.test(i))
                {
                    RBACPermission const* permission = sAccountMgr->GetRBACPermission(i);
                    handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
                }
        }

        delete command;

        return true;
    }

    static bool HandleRBACAccountPermissionCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args, false);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_RBAC_PERM_LIST_GLOBAL, command->rbac->GetId(), command->rbac->GetName().c_str());
        RBACPermissionContainer const& permissions = command->rbac->GetPermissions();
        if (!permissions.any())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (uint32 i = 0; i < RBAC_PERM_MAX; ++i)
                if (permissions.test(i))
                {
                    RBACPermission const* permission = sAccountMgr->GetRBACPermission(i);
                    handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
                }
        }

        delete command;

        return true;
    }

    static bool HandleRBACListGroupsCommand(ChatHandler* handler, char const* args)
    {
        uint32 id = 0;
        if (char* param1 = strtok((char*)args, " "))
          id = atoi(param1);

        if (!id)
        {
            RBACGroupsContainer const& groups = sAccountMgr->GetRBACGroupList();
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_GROUPS_HEADER));
            for (RBACGroupsContainer::const_iterator it = groups.begin(); it != groups.end(); ++it)
            {
                RBACGroup const* group = it->second;
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, group->GetId(), group->GetName().c_str());
            }
        }
        else
        {
            RBACGroup const* group = sAccountMgr->GetRBACGroup(id);
            if (!group)
            {
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, id);
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_GROUPS_HEADER));
            handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, group->GetId(), group->GetName().c_str());
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_ROLES_HEADER));
            RBACRoleContainer const& roles = group->GetRoles();
            if (roles.empty())
                handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
            else
            {
                for (RBACRoleContainer::const_iterator it = roles.begin(); it != roles.end(); ++it)
                {
                    RBACRole const* role = sAccountMgr->GetRBACRole(*it);
                    handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, role->GetId(), role->GetName().c_str());
                }
            }
        }

        return true;
    }

    static bool HandleRBACListRolesCommand(ChatHandler* handler, char const* args)
    {
        uint32 id = 0;
        if (char* param1 = strtok((char*)args, " "))
          id = atoi(param1);

        if (!id)
        {
            RBACRolesContainer const& roles = sAccountMgr->GetRBACRoleList();
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_ROLES_HEADER));
            for (RBACRolesContainer::const_iterator it = roles.begin(); it != roles.end(); ++it)
            {
                RBACRole const* role = it->second;
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, role->GetId(), role->GetName().c_str());
            }
        }
        else
        {
            RBACRole const* role = sAccountMgr->GetRBACRole(id);
            if (!role)
            {
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, id);
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_ROLES_HEADER));
            handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, role->GetId(), role->GetName().c_str());
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMISSIONS_HEADER));
            RBACPermissionContainer const& permissions = role->GetPermissions();
            if (!permissions.any())
                handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
            else
            {
                for (uint32 i = 0; i < RBAC_PERM_MAX; ++i)
                    if (permissions.test(i))
                    {
                        RBACPermission const* permission = sAccountMgr->GetRBACPermission(i);
                        handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
                    }
            }
        }

        return true;
    }

    static bool HandleRBACListPermissionsCommand(ChatHandler* handler, char const* args)
    {
        uint32 id = 0;
        if (char* param1 = strtok((char*)args, " "))
          id = atoi(param1);

        if (!id)
        {
            RBACPermissionsContainer const& permissions = sAccountMgr->GetRBACPermissionList();
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMISSIONS_HEADER));
            for (RBACPermissionsContainer::const_iterator it = permissions.begin(); it != permissions.end(); ++it)
            {
                RBACPermission const* permission = it->second;
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
            }
        }
        else
        {
            RBACPermission const* permission = sAccountMgr->GetRBACPermission(id);
            if (!permission)
            {
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, id);
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMISSIONS_HEADER));
            handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
        }

        return true;
    }
};

void AddSC_rbac_commandscript()
{
    new rbac_commandscript();
}
