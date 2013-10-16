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
    rbac::RBACData* rbac;
    bool needDelete;
};

class rbac_commandscript : public CommandScript
{
public:
    rbac_commandscript() : CommandScript("rbac_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand rbacAccountCommandTable[] =
        {
            {        "list", rbac::RBAC_PERM_COMMAND_RBAC_ACC_PERM_LIST,   true, &HandleRBACPermListCommand,    "", NULL },
            {       "grant", rbac::RBAC_PERM_COMMAND_RBAC_ACC_PERM_GRANT,  true, &HandleRBACPermGrantCommand,   "", NULL },
            {        "deny", rbac::RBAC_PERM_COMMAND_RBAC_ACC_PERM_DENY,   true, &HandleRBACPermDenyCommand,    "", NULL },
            {      "revoke", rbac::RBAC_PERM_COMMAND_RBAC_ACC_PERM_REVOKE, true, &HandleRBACPermRevokeCommand,  "", NULL },
            {          NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand rbacCommandTable[] =
        {
            {    "account", rbac::RBAC_PERM_COMMAND_RBAC_ACC,  true, NULL, "", rbacAccountCommandTable },
            {       "list", rbac::RBAC_PERM_COMMAND_RBAC_LIST, true, &HandleRBACListPermissionsCommand, "", NULL },
            {         NULL, 0, false, NULL, "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            {       "rbac", rbac::RBAC_PERM_COMMAND_RBAC, true, NULL, "", rbacCommandTable },
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
        rbac::RBACData* rdata = NULL;
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
            data->rbac = new rbac::RBACData(accountId, accountName, realmID, AccountMgr::GetSecurity(accountId, realmID));
            data->rbac->LoadFromDB();
            data->needDelete = true;
        }
        else
            data->rbac = rdata;

        data->id = id;
        data->realmId = realmId;
        return data;
    }

    static bool HandleRBACPermGrantCommand(ChatHandler* handler, char const* args)
    {
        RBACCommandData* command = ReadParams(handler, args);

        if (!command)
        {
            handler->SetSentErrorMessage(true);
            return false;
        }

        rbac::RBACCommandResult result = command->rbac->GrantPermission(command->id, command->realmId);
        rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(command->id);

        switch (result)
        {
            case rbac::RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED_IN_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case rbac::RBAC_IN_DENIED_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED_IN_DENIED_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case rbac::RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case rbac::RBAC_ID_DOES_NOT_EXISTS:
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

        rbac::RBACCommandResult result = command->rbac->DenyPermission(command->id, command->realmId);
        rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(command->id);

        switch (result)
        {
            case rbac::RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED_IN_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case rbac::RBAC_IN_GRANTED_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED_IN_GRANTED_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case rbac::RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case rbac::RBAC_ID_DOES_NOT_EXISTS:
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

        rbac::RBACCommandResult result = command->rbac->RevokePermission(command->id, command->realmId);
        rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(command->id);

        switch (result)
        {
            case rbac::RBAC_CANT_REVOKE_NOT_IN_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_REVOKED_NOT_IN_LIST, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case rbac::RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_REVOKED, command->id, permission->GetName().c_str(),
                    command->realmId, command->rbac->GetId(), command->rbac->GetName().c_str());
                break;
            case rbac::RBAC_ID_DOES_NOT_EXISTS:
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

        handler->PSendSysMessage(LANG_RBAC_LIST_HEADER_GRANTED, command->rbac->GetId(), command->rbac->GetName().c_str());
        rbac::RBACPermissionContainer const& granted = command->rbac->GetGrantedPermissions();
        if (granted.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (rbac::RBACPermissionContainer::const_iterator itr = granted.begin(); itr != granted.end(); ++itr)
            {
                rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(*itr);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
            }
        }

        handler->PSendSysMessage(LANG_RBAC_LIST_HEADER_DENIED, command->rbac->GetId(), command->rbac->GetName().c_str());
        rbac::RBACPermissionContainer const& denied = command->rbac->GetDeniedPermissions();
        if (denied.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (rbac::RBACPermissionContainer::const_iterator itr = denied.begin(); itr != denied.end(); ++itr)
            {
                rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(*itr);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
            }
        }
        handler->PSendSysMessage(LANG_RBAC_LIST_HEADER_DENIED, command->rbac->GetId(), command->rbac->GetName().c_str());
        rbac::RBACPermissionContainer const& defaultPermissions = sAccountMgr->GetRBACDefaultPermissions(command->rbac->GetSecurityLevel());
        if (defaultPermissions.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (rbac::RBACPermissionContainer::const_iterator itr = defaultPermissions.begin(); itr != defaultPermissions.end(); ++itr)
            {
                rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(*itr);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
            }
        }

        delete command;

        return true;
    }

    static bool HandleRBACListPermissionsCommand(ChatHandler* handler, char const* args)
    {
        uint32 id = 0;
        if (char* param1 = strtok((char*)args, " "))
          id = atoi(param1);

        if (!id)
        {
            rbac::RBACPermissionsContainer const& permissions = sAccountMgr->GetRBACPermissionList();
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMISSIONS_HEADER));
            for (rbac::RBACPermissionsContainer::const_iterator it = permissions.begin(); it != permissions.end(); ++it)
            {
                rbac::RBACPermission const* permission = it->second;
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
            }
        }
        else
        {
            rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(id);
            if (!permission)
            {
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, id);
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMISSIONS_HEADER));
            handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMS_LINKED_HEADER));
            rbac::RBACPermissionContainer const& permissions = permission->GetLinkedPermissions();
            for (rbac::RBACPermissionContainer::const_iterator it = permissions.begin(); it != permissions.end(); ++it)
                if (rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(*it))
                    handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName().c_str());
        }

        return true;
    }
};

void AddSC_rbac_commandscript()
{
    new rbac_commandscript();
}
