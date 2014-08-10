/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Bloodmyst_Isle
SD%Complete: 80
SDComment: Quest support: 9670
SDCategory: Bloodmyst Isle
EndScriptData */

/* ContentData
npc_webbed_creature
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"

/*######
## npc_webbed_creature
######*/

//possible creatures to be spawned
uint32 const possibleSpawns[32] = {17322, 17661, 17496, 17522, 17340, 17352, 17333, 17524, 17654, 17348, 17339, 17345, 17359, 17353, 17336, 17550, 17330, 17701, 17321, 17680, 17325, 17320, 17683, 17342, 17715, 17334, 17341, 17338, 17337, 17346, 17344, 17327};

enum WebbedCreature
{
    NPC_EXPEDITION_RESEARCHER                     = 17681
};

class npc_webbed_creature : public CreatureScript
{
public:
    npc_webbed_creature() : CreatureScript("npc_webbed_creature") { }

    struct npc_webbed_creatureAI : public ScriptedAI
    {
        npc_webbed_creatureAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override { }

        void EnterCombat(Unit* /*who*/) override { }

        void JustDied(Unit* killer) override
        {
            uint32 spawnCreatureID = 0;

            switch (urand(0, 2))
            {
                case 0:
                    if (Player* player = killer->ToPlayer())
                        player->KilledMonsterCredit(NPC_EXPEDITION_RESEARCHER, 0);
                    break;
                case 1:
                case 2:
                    spawnCreatureID = possibleSpawns[urand(0, 30)];
                    break;
            }

            if (spawnCreatureID)
                me->SummonCreature(spawnCreatureID, 0.0f, 0.0f, 0.0f, me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 60000);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_webbed_creatureAI(creature);
    }
};

void AddSC_bloodmyst_isle()
{
    new npc_webbed_creature();
}
