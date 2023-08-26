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

#include "PhasingHandler.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum AssaultMisc
{
    SPELL_DARK_PORTAL_RUN_AWAY = 158985,

    QUEST_THE_COST_OF_WAR      = 34420
};

// 78558 - Archmage Khadgar
struct npc_assault_archmage_khadgar : public ScriptedAI
{
    npc_assault_archmage_khadgar(Creature* creature) : ScriptedAI(creature) { }

    void OnQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_THE_COST_OF_WAR)
            player->CastSpell(player, SPELL_DARK_PORTAL_RUN_AWAY);
    }
};

// 621 - Dark Portal: Run away
class scene_dark_portal_run_away : public SceneScript
{
public:
    scene_dark_portal_run_away() : SceneScript("scene_dark_portal_run_away") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->RemoveAurasDueToSpell(SPELL_DARK_PORTAL_RUN_AWAY);
        PhasingHandler::OnConditionChange(player);
    }
};

void AddSC_assault_on_the_dark_portal()
{
    RegisterCreatureAI(npc_assault_archmage_khadgar);
    new scene_dark_portal_run_away();
};
