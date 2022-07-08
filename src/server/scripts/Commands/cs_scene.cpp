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

#include "ScriptMgr.h"
#include "Chat.h"
#include "ChatCommand.h"
#include "DB2Stores.h"
#include "Language.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "RBAC.h"
#include "WorldSession.h"

using namespace Trinity::ChatCommands;

class scene_commandscript : public CommandScript
{
public:
    scene_commandscript() : CommandScript("scene_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable sceneCommandTable =
        {
            { "debug",          HandleDebugSceneCommand,       rbac::RBAC_PERM_COMMAND_SCENE_DEBUG,        Console::No },
            { "play",           HandlePlaySceneCommand,        rbac::RBAC_PERM_COMMAND_SCENE_PLAY,         Console::No },
            { "playpackage",    HandlePlayScenePackageCommand, rbac::RBAC_PERM_COMMAND_SCENE_PLAY_PACKAGE, Console::No },
            { "cancel",         HandleCancelSceneCommand,      rbac::RBAC_PERM_COMMAND_SCENE_CANCEL,       Console::No }
        };
        static ChatCommandTable commandTable =
        {
            { "scene",          sceneCommandTable }
        };
        return commandTable;
    }

    static bool HandleDebugSceneCommand(ChatHandler* handler)
    {
        if (Player* player = handler->GetSession()->GetPlayer())
        {
            player->GetSceneMgr().ToggleDebugSceneMode();
            handler->PSendSysMessage(player->GetSceneMgr().IsInDebugSceneMode() ? LANG_COMMAND_SCENE_DEBUG_ON : LANG_COMMAND_SCENE_DEBUG_OFF);
        }

        return true;
    }

    static bool HandlePlaySceneCommand(ChatHandler* handler, uint32 sceneId)
    {
        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sObjectMgr->GetSceneTemplate(sceneId))
            return false;

        target->GetSceneMgr().PlayScene(sceneId);
        return true;
    }

    static bool HandlePlayScenePackageCommand(ChatHandler* handler, uint32 sceneScriptPackageId, Optional<uint32> flags)
    {
        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sSceneScriptPackageStore.HasRecord(sceneScriptPackageId))
            return false;

        target->GetSceneMgr().PlaySceneByPackageId(sceneScriptPackageId, static_cast<SceneFlag>(flags.value_or(0)));
        return true;
    }

    static bool HandleCancelSceneCommand(ChatHandler* handler, uint32 sceneScriptPackageId)
    {
        Player* target = handler->getSelectedPlayerOrSelf();

        if (!target)
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!sSceneScriptPackageStore.HasRecord(sceneScriptPackageId))
            return false;

        target->GetSceneMgr().CancelSceneByPackageId(sceneScriptPackageId);
        return true;
    }
};

void AddSC_scene_commandscript()
{
    new scene_commandscript();
}
