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
SDName: Uldaman
SD%Complete: 100
SDComment: Quest support: 2240, 2278 + 1 trash mob.
SDCategory: Uldaman
EndScriptData */

/* ContentData
npc_jadespine_basilisk
go_keystone_chamber
at_map_chamber
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "uldaman.h"

/*######
## npc_jadespine_basilisk
######*/

enum Spells
{
    SPELL_CRYSTALLINE_SLUMBER   = 3636,
};

class npc_jadespine_basilisk : public CreatureScript
{
    public:

        npc_jadespine_basilisk()
            : CreatureScript("npc_jadespine_basilisk")
        {
        }

        struct npc_jadespine_basiliskAI : public ScriptedAI
        {
            npc_jadespine_basiliskAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                uiCslumberTimer = 2000;
            }

            uint32 uiCslumberTimer;

            void Reset() override
            {
                Initialize();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
            }

            void UpdateAI(uint32 uiDiff) override
            {
                //Return since we have no target
                if (!UpdateVictim())
                    return;

                //uiCslumberTimer
                if (uiCslumberTimer <= uiDiff)
                {
                    //Cast
                    DoCastVictim(SPELL_CRYSTALLINE_SLUMBER, true);

                    //Stop attacking target thast asleep and pick new target
                    uiCslumberTimer = 28000;

                    me->GetThreatManager().ResetThreat(me->GetVictim());

                } else uiCslumberTimer -= uiDiff;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetUldamanAI<npc_jadespine_basiliskAI>(creature);
        }
};

/*######
## go_keystone_chamber
######*/

class go_keystone_chamber : public GameObjectScript
{
    public:
        go_keystone_chamber() : GameObjectScript("go_keystone_chamber") { }

        struct go_keystone_chamberAI : public GameObjectAI
        {
            go_keystone_chamberAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool GossipHello(Player* /*player*/) override
            {
                instance->SetData(DATA_IRONAYA_SEAL, IN_PROGRESS); //door animation and save state.
                return false;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetUldamanAI<go_keystone_chamberAI>(go);
        }
};

/*######
## at_map_chamber
######*/

enum MapChamber
{
    QUEST_HIDDEN_CHAMBER = 2240
};

class AreaTrigger_at_map_chamber : public AreaTriggerScript
{
    public:

        AreaTrigger_at_map_chamber()
            : AreaTriggerScript("at_map_chamber")
        {
        }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool /*entered*/) override
        {
            if (player->GetQuestStatus(QUEST_HIDDEN_CHAMBER) == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(QUEST_HIDDEN_CHAMBER);

            return true;
        }
};

void AddSC_uldaman()
{
    new npc_jadespine_basilisk();
    new go_keystone_chamber();
    new AreaTrigger_at_map_chamber();
}
