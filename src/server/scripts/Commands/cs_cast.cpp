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
Name: cast_commandscript
%Complete: 100
Comment: All cast related commands
Category: commandscripts
EndScriptData */

#include "ScriptMgr.h"
#include "Chat.h"
#include "Creature.h"
#include "Language.h"
#include "Player.h"
#include "RBAC.h"
#include "SpellMgr.h"
#include "WorldSession.h"

class cast_commandscript : public CommandScript
{
public:
    cast_commandscript() : CommandScript("cast_commandscript") { }

    std::vector<ChatCommand> GetCommands() const override
    {
        static std::vector<ChatCommand> castCommandTable =
        {
            { "back",   rbac::RBAC_PERM_COMMAND_CAST_BACK,   false, &HandleCastBackCommand,  "" },
            { "dist",   rbac::RBAC_PERM_COMMAND_CAST_DIST,   false, &HandleCastDistCommand,  "" },
            { "self",   rbac::RBAC_PERM_COMMAND_CAST_SELF,   false, &HandleCastSelfCommand,  "" },
            { "target", rbac::RBAC_PERM_COMMAND_CAST_TARGET, false, &HandleCastTargetCommad, "" },
            { "dest",   rbac::RBAC_PERM_COMMAND_CAST_DEST,   false, &HandleCastDestCommand,  "" },
            { "",       rbac::RBAC_PERM_COMMAND_CAST,        false, &HandleCastCommand,      "" },
        };
        static std::vector<ChatCommand> commandTable =
        {
            { "cast",   rbac::RBAC_PERM_COMMAND_CAST,        false, nullptr,                    "", castCommandTable },
        };
        return commandTable;
    }

    static bool CheckSpellExistsAndIsValid(ChatHandler* handler, uint32 spellId)
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (!spellInfo)
        {
            handler->PSendSysMessage(LANG_COMMAND_NOSPELLFOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!SpellMgr::IsSpellValid(spellInfo, handler->GetSession()->GetPlayer()))
        {
            handler->PSendSysMessage(LANG_COMMAND_SPELL_BROKEN, spellId);
            handler->SetSentErrorMessage(true);
            return false;
        }
        return true;
    }

    static bool HandleCastCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Unit* target = handler->getSelectedUnit();
        if (!target)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);
        if (!spellId)
            return false;

        if (!CheckSpellExistsAndIsValid(handler, spellId))
            return false;

        char* triggeredStr = strtok(nullptr, " ");
        if (triggeredStr)
        {
            int l = strlen(triggeredStr);
            if (strncmp(triggeredStr, "triggered", l) != 0)
                return false;
        }

        TriggerCastFlags triggered = (triggeredStr != nullptr) ? TRIGGERED_FULL_DEBUG_MASK : TRIGGERED_NONE;
        handler->GetSession()->GetPlayer()->CastSpell(target, spellId, triggered);

        return true;
    }

    static bool HandleCastBackCommand(ChatHandler* handler, char const* args)
    {
        Creature* caster = handler->getSelectedCreature();
        if (!caster)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);
        if (!spellId)
            return false;

        if (!CheckSpellExistsAndIsValid(handler, spellId))
            return false;

        char* triggeredStr = strtok(nullptr, " ");
        if (triggeredStr)
        {
            int l = strlen(triggeredStr);
            if (strncmp(triggeredStr, "triggered", l) != 0)
                return false;
        }

        TriggerCastFlags triggered = (triggeredStr != nullptr) ? TRIGGERED_FULL_DEBUG_MASK : TRIGGERED_NONE;
        caster->CastSpell(handler->GetSession()->GetPlayer(), spellId, triggered);

        return true;
    }

    static bool HandleCastDistCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);
        if (!spellId)
            return false;

        if (!CheckSpellExistsAndIsValid(handler, spellId))
            return false;

        char* distStr = strtok(nullptr, " ");

        float dist = 0;

        if (distStr)
            sscanf(distStr, "%f", &dist);

        char* triggeredStr = strtok(nullptr, " ");
        if (triggeredStr)
        {
            int l = strlen(triggeredStr);
            if (strncmp(triggeredStr, "triggered", l) != 0)
                return false;
        }

        TriggerCastFlags triggered = (triggeredStr != nullptr) ? TRIGGERED_FULL_DEBUG_MASK : TRIGGERED_NONE;
        float x, y, z;
        handler->GetSession()->GetPlayer()->GetClosePoint(x, y, z, dist);
        handler->GetSession()->GetPlayer()->CastSpell({ x, y, z }, spellId, triggered);

        return true;
    }

    static bool HandleCastSelfCommand(ChatHandler* handler, char const* args)
    {
        if (!*args)
            return false;

        Unit* target = handler->getSelectedUnit();

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);
        if (!spellId)
            return false;

        if (!CheckSpellExistsAndIsValid(handler, spellId))
            return false;

        target->CastSpell(target, spellId, false);

        return true;
    }

    static bool HandleCastTargetCommad(ChatHandler* handler, char const* args)
    {
        Creature* caster = handler->getSelectedCreature();
        if (!caster)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        if (!caster->GetVictim())
        {
            handler->SendSysMessage(LANG_SELECTED_TARGET_NOT_HAVE_VICTIM);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);
        if (!spellId)
            return false;

        if (!CheckSpellExistsAndIsValid(handler, spellId))
            return false;

        char* triggeredStr = strtok(nullptr, " ");
        if (triggeredStr)
        {
            int l = strlen(triggeredStr);
            if (strncmp(triggeredStr, "triggered", l) != 0)
                return false;
        }

        TriggerCastFlags triggered = (triggeredStr != nullptr) ? TRIGGERED_FULL_DEBUG_MASK : TRIGGERED_NONE;
        caster->CastSpell(caster->GetVictim(), spellId, triggered);

        return true;
    }

    static bool HandleCastDestCommand(ChatHandler* handler, char const* args)
    {
        Unit* caster = handler->getSelectedUnit();
        if (!caster)
        {
            handler->SendSysMessage(LANG_SELECT_CHAR_OR_CREATURE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        // number or [name] Shift-click form |color|Hspell:spell_id|h[name]|h|r or Htalent form
        uint32 spellId = handler->extractSpellIdFromLink((char*)args);
        if (!spellId)
            return false;

        if (!CheckSpellExistsAndIsValid(handler, spellId))
            return false;

        char* posX = strtok(nullptr, " ");
        char* posY = strtok(nullptr, " ");
        char* posZ = strtok(nullptr, " ");

        if (!posX || !posY || !posZ)
            return false;

        float x = float(atof(posX));
        float y = float(atof(posY));
        float z = float(atof(posZ));

        char* triggeredStr = strtok(nullptr, " ");
        if (triggeredStr)
        {
            int l = strlen(triggeredStr);
            if (strncmp(triggeredStr, "triggered", l) != 0)
                return false;
        }

        TriggerCastFlags triggered = (triggeredStr != nullptr) ? TRIGGERED_FULL_DEBUG_MASK : TRIGGERED_NONE;
        caster->CastSpell({ x, y, z }, spellId, triggered);

        return true;
    }
};

void AddSC_cast_commandscript()
{
    new cast_commandscript();
}
