/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
SDName: Isle_of_Queldanas
SD%Complete: 100
SDComment: Quest support: 11541
SDCategory: Isle Of Quel'Danas
EndScriptData */

/* ContentData
npc_greengill_slave
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "SpellInfo.h"

/*######
## npc_greengill_slave
######*/

enum GreengillSlave
{
    NPC_DARKSPINE_MYRIDON       = 25060,
    QUEST_GREENGILL_COAST       = 11541,
    SPELL_ENRAGE                = 45111,
    SPELL_ORB_MURLOC_CONTROL    = 45109,
    SPELL_GREENGILL_SLAVE_FREED = 45110
};

class npc_greengill_slave : public CreatureScript
{
public:
    npc_greengill_slave() : CreatureScript("npc_greengill_slave") { }

    struct npc_greengill_slaveAI : public ScriptedAI
    {
        npc_greengill_slaveAI(Creature* creature) : ScriptedAI(creature) { }

        void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
        {
            Player* player = caster->ToPlayer();

            if (!player)
                return;

            if (spellInfo->Id == SPELL_ORB_MURLOC_CONTROL && !me->HasAura(SPELL_ENRAGE))
            {
                if (player->GetQuestStatus(QUEST_GREENGILL_COAST) == QUEST_STATUS_INCOMPLETE)
                    DoCast(player, SPELL_GREENGILL_SLAVE_FREED, true);

                DoCast(me, SPELL_ENRAGE);

                if (Creature* Myrmidon = me->FindNearestCreature(NPC_DARKSPINE_MYRIDON, 70))
                {
                    me->AddThreat(Myrmidon, 100000.0f);
                    AttackStart(Myrmidon);
                }
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_greengill_slaveAI(creature);
    }
};

void AddSC_isle_of_queldanas()
{
    new npc_greengill_slave();
}
