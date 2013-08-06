/*
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

// http://www.wowhead.com/quest=14069
// npc_deffiant_troll
enum NPC_DeffiantTroll
{
    DEFFIANT_KILL_CREDIT               = 34830,
    SPELL_LIGHTNING_VISUAL             = 45870,
    SPELL_ENRAGE                       = 45111,
    QUEST_GOOD_HELP_IS_HARD_TO_FIND    = 14069,
    GO_DEPOSIT                         = 195489,
};

enum Yells
{
    SAY_WORK = 0
};

class npc_defiant_troll : public CreatureScript
{
public:
    npc_defiant_troll() : CreatureScript("npc_defiant_troll") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_defiant_trollAI(creature);
    }

    struct npc_defiant_trollAI : public ScriptedAI
    {
        npc_defiant_trollAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 rebuffTimer;
        bool work;

        void Reset () OVERRIDE
        {
            rebuffTimer = 0;
            work = false;
            me->CastSpell(me, SPELL_ENRAGE, true);
        }

        void MovementInform(uint32 /*type*/, uint32 id) OVERRIDE
        {
            if (id == 1)
                work = true;
        }

        bool IsWorking() const { return work; }

        void UpdateAI(const uint32 diff) OVERRIDE
        {
            if (work == true)
                me->HandleEmoteCommand(467);

            if (rebuffTimer <= diff)
            {
                Reset();
                
                switch (urand(0, 2))
                {
                    case 0:
                        me->HandleEmoteCommand(412);
                        break;
                    case 1:
                        me->HandleEmoteCommand(10);
                        break;
                    case 2:
                        me->HandleEmoteCommand(0);
                        break;
                }
                rebuffTimer = 120000;                 //Rebuff again in 2 minutes
            }
            else
                rebuffTimer -= diff;

            if (!UpdateVictim())
                return;

            //DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* player, Creature* creature) OVERRIDE
    {
        if (player->GetQuestStatus(QUEST_GOOD_HELP_IS_HARD_TO_FIND) == QUEST_STATUS_INCOMPLETE && !CAST_AI(npc_defiant_troll::npc_defiant_trollAI, creature->AI())->IsWorking())
        {
            player->CastSpell(creature, SPELL_LIGHTNING_VISUAL, true);
            player->KilledMonsterCredit(DEFFIANT_KILL_CREDIT, creature->GetGUID());
            creature->AI()->Talk(SAY_WORK);
            creature->RemoveAllAuras();

            if (GameObject* Deposit = creature->FindNearestGameObject(GO_DEPOSIT, 20))
                creature->GetMotionMaster()->MovePoint(1, Deposit->GetPositionX()-1, Deposit->GetPositionY(), Deposit->GetPositionZ());

            if (player->GetQuestStatus(QUEST_GOOD_HELP_IS_HARD_TO_FIND) == QUEST_STATUS_COMPLETE) 
                 player->RemoveAura(SPELL_LIGHTNING_VISUAL);

            player->CLOSE_GOSSIP_MENU();

            return true;
        }

        player->CLOSE_GOSSIP_MENU();

        return false;
    }
};

void AddSC_kezan()
{
    new npc_defiant_troll();
}
