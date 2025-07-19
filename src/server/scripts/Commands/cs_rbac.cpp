/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ScriptMgr.h"
#include "AccountMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "Config.h"
#include "Language.h"
#include "Player.h"
#include "RealmList.h"
#include "World.h"
#include "WorldSession.h"

struct RBACCommandData
{
    RBACCommandData(rbac::RBACData* rbac_, bool needDelete_) : rbac(rbac_), needDelete(needDelete_) { }
    RBACCommandData(RBACCommandData const&) = delete;
    ~RBACCommandData()
    {
        if (needDelete)
            delete rbac;
    }

    rbac::RBACData* rbac = nullptr;
    bool needDelete = false;
};

using namespace Trinity::ChatCommands;

class rbac_commandscript : public CommandScript
{
public:
    rbac_commandscript() : CommandScript("rbac_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable rbacAccountCommandTable =
        {
            { "list",   HandleRBACPermListCommand,   rbac::RBAC_PERM_COMMAND_RBAC_ACC_PERM_LIST,   Console::Yes },
            { "grant",  HandleRBACPermGrantCommand,  rbac::RBAC_PERM_COMMAND_RBAC_ACC_PERM_GRANT,  Console::Yes },
            { "deny",   HandleRBACPermDenyCommand,   rbac::RBAC_PERM_COMMAND_RBAC_ACC_PERM_DENY,   Console::Yes },
            { "revoke", HandleRBACPermRevokeCommand, rbac::RBAC_PERM_COMMAND_RBAC_ACC_PERM_REVOKE, Console::Yes },
        };

        static ChatCommandTable rbacCommandTable =
        {
            { "account", rbacAccountCommandTable },
            { "list",    HandleRBACListPermissionsCommand, rbac::RBAC_PERM_COMMAND_RBAC_LIST, Console::Yes },
        };

        static ChatCommandTable commandTable =
        {
            { "rbac", rbacCommandTable },
        };

        return commandTable;
    }

    static RBACCommandData GetRBACData(AccountIdentifier account)
    {
        if (account.IsConnected())
            return { account.GetConnectedSession()->GetRBACData(), false };

        uint32 realmId = sRealmList->GetCurrentRealmId().Realm;
        rbac::RBACData* rbac = new rbac::RBACData(account.GetID(), account.GetName(), realmId, AccountMgr::GetSecurity(account.GetID(), realmId));
        rbac->LoadFromDB();

        return { rbac, true };
    }

    static bool HandleRBACPermGrantCommand(ChatHandler* handler, Optional<AccountIdentifier> account, uint32 permId, Optional<int32> realmId)
    {
        if (!account)
            account = AccountIdentifier::FromTarget(handler);
        if (!account)
            return false;

        if (handler->HasLowerSecurityAccount(nullptr, account->GetID(), true))
            return false;

        if (!realmId)
            realmId = -1;

        RBACCommandData data = GetRBACData(*account);

        rbac::RBACCommandResult result = data.rbac->GrantPermission(permId, *realmId);
        rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(permId);

        switch (result)
        {
            case rbac::RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED_IN_LIST, permId, permission->GetName(),
                                         *realmId, account->GetID(), account->GetName());
                break;
            case rbac::RBAC_IN_DENIED_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED_IN_DENIED_LIST, permId, permission->GetName(),
                                         *realmId, account->GetID(), account->GetName());
                break;
            case rbac::RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_GRANTED, permId, permission->GetName(),
                                         *realmId, account->GetID(), account->GetName());
                break;
            case rbac::RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, permId);
                break;
            default:
                break;
        }

        return true;
    }

    static bool HandleRBACPermDenyCommand(ChatHandler* handler, Optional<AccountIdentifier> account, uint32 permId, Optional<int32> realmId)
    {
        if (!account)
            account = AccountIdentifier::FromTarget(handler);
        if (!account)
            return false;

        if (handler->HasLowerSecurityAccount(nullptr, account->GetID(), true))
            return false;

        if (!realmId)
            realmId = -1;

        RBACCommandData data = GetRBACData(*account);

        rbac::RBACCommandResult result = data.rbac->DenyPermission(permId, *realmId);
        rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(permId);

        switch (result)
        {
            case rbac::RBAC_CANT_ADD_ALREADY_ADDED:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED_IN_LIST, permId, permission->GetName(),
                                         *realmId, account->GetID(), account->GetName());
                break;
            case rbac::RBAC_IN_GRANTED_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED_IN_GRANTED_LIST, permId, permission->GetName(),
                                         *realmId, account->GetID(), account->GetName());
                break;
            case rbac::RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_DENIED, permId, permission->GetName(),
                                         *realmId, account->GetID(), account->GetName());
                break;
            case rbac::RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, permId);
                break;
            default:
                break;
        }

        return true;
    }

    static bool HandleRBACPermRevokeCommand(ChatHandler* handler, Optional<AccountIdentifier> account, uint32 permId, Optional<int32> realmId)
    {
        if (!account)
            account = AccountIdentifier::FromTarget(handler);
        if (!account)
            return false;

        if (handler->HasLowerSecurityAccount(nullptr, account->GetID(), true))
            return false;

        if (!realmId)
            realmId = -1;

        RBACCommandData data = GetRBACData(*account);

        rbac::RBACCommandResult result = data.rbac->RevokePermission(permId, *realmId);
        rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(permId);

        switch (result)
        {
            case rbac::RBAC_CANT_REVOKE_NOT_IN_LIST:
                handler->PSendSysMessage(LANG_RBAC_PERM_REVOKED_NOT_IN_LIST, permId, permission->GetName(),
                                         *realmId, account->GetID(), account->GetName());
                break;
            case rbac::RBAC_OK:
                handler->PSendSysMessage(LANG_RBAC_PERM_REVOKED, permId, permission->GetName(),
                                         *realmId, account->GetID(), account->GetName());
                break;
            case rbac::RBAC_ID_DOES_NOT_EXISTS:
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, permId);
                break;
            default:
                break;
        }

        return true;
    }

    static bool HandleRBACPermListCommand(ChatHandler* handler, Optional<AccountIdentifier> account)
    {
        if (!account)
            account = AccountIdentifier::FromTarget(handler);
        if (!account)
            return false;

        RBACCommandData data = GetRBACData(*account);

        handler->PSendSysMessage(LANG_RBAC_LIST_HEADER_GRANTED, data.rbac->GetId(), data.rbac->GetName());
        rbac::RBACPermissionContainer const& granted = data.rbac->GetGrantedPermissions();
        if (granted.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (uint32 grantedId : granted)
            {
                rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(grantedId);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName());
            }
        }

        handler->PSendSysMessage(LANG_RBAC_LIST_HEADER_DENIED, data.rbac->GetId(), data.rbac->GetName());
        rbac::RBACPermissionContainer const& denied = data.rbac->GetDeniedPermissions();
        if (denied.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (uint32 deniedId : denied)
            {
                rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(deniedId);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName());
            }
        }
        handler->PSendSysMessage(LANG_RBAC_LIST_HEADER_BY_SEC_LEVEL, data.rbac->GetId(), data.rbac->GetName(), data.rbac->GetSecurityLevel());
        rbac::RBACPermissionContainer const& defaultPermissions = sAccountMgr->GetRBACDefaultPermissions(data.rbac->GetSecurityLevel());
        if (defaultPermissions.empty())
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_EMPTY));
        else
        {
            for (uint32 defaultPermission : defaultPermissions)
            {
                rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(defaultPermission);
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName());
            }
        }

        return true;
    }

    static bool HandleRBACListPermissionsCommand(ChatHandler* handler, Optional<uint32> permId)
    {
        if (!permId)
        {
            rbac::RBACPermissionsContainer const& permissions = sAccountMgr->GetRBACPermissionList();
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMISSIONS_HEADER));
            for (auto const& [_, permission] : permissions)
            {
                handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName());
            }
        }
        else
        {
            rbac::RBACPermission const* permission = sAccountMgr->GetRBACPermission(*permId);
            if (!permission)
            {
                handler->PSendSysMessage(LANG_RBAC_WRONG_PARAMETER_ID, *permId);
                handler->SetSentErrorMessage(true);
                return false;
            }

            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMISSIONS_HEADER));
            handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, permission->GetId(), permission->GetName());
            handler->PSendSysMessage("%s", handler->GetTrinityString(LANG_RBAC_LIST_PERMS_LINKED_HEADER));
            for (uint32 linkedPerm : permission->GetLinkedPermissions())
                if (rbac::RBACPermission const* rbacPermission = sAccountMgr->GetRBACPermission(linkedPerm))
                    handler->PSendSysMessage(LANG_RBAC_LIST_ELEMENT, rbacPermission->GetId(), rbacPermission->GetName());
        }

        return true;
    }
};

void AddSC_rbac_commandscript()
{
    new rbac_commandscript();
}
