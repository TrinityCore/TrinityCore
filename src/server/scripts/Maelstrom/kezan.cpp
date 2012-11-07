/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "SpellMgr.h"
#include "Player.h"
#include "Creature.h"

// q 14069
enum NPC_DeffiantTroll
{
    DEFIANT_KILL_CREDIT               = 34830,
    SPELL_LIGHTNING_VISUAL            = 66306,
    QUEST_GOOD_HELP_IS_HARD_TO_FIND   = 14069,
    GO_DEPOSIT                        = 195492,
};

enum Yells
{
    SAY_WORK_1    = -1100000,
    SAY_WORK_2    = -1100001,
    SAY_WORK_3    = -1100002,
    SAY_WORK_4    = -1100003,
    SAY_WORK_5    = -1100004,
    SAY_WORK_6    = -1100005,
    SAY_WORK_7    = -1100006,
    SAY_WORK_8    = -1100007,
};

class npc_defiant_troll : public CreatureScript
{
    public:
    npc_defiant_troll() : CreatureScript("npc_defiant_troll") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_defiant_trollAI(creature);
    }

    struct npc_defiant_trollAI : public ScriptedAI
    {
        npc_defiant_trollAI(Creature* creature) : ScriptedAI(creature) {}

        uint32 rebuffTimer;
        bool work;

        void Reset ()
        {
            rebuffTimer = 0;
            work = false;
        }

        void MovementInform(uint32 /*type*/, uint32 id)
        {
            if (id == 1)
                work = true;
        }

        void SpellHit(Unit* caster, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_LIGHTNING_VISUAL && caster->GetTypeId() == TYPEID_PLAYER && caster->ToPlayer()->GetQuestStatus(QUEST_GOOD_HELP_IS_HARD_TO_FIND) == QUEST_STATUS_INCOMPLETE && work == false)
            {
                caster->ToPlayer()->KilledMonsterCredit(DEFIANT_KILL_CREDIT, me->GetGUID());
                switch (urand(0, 7))
                {
                    case 0:
                        DoScriptText(SAY_WORK_1, me);
                        break;
                    case 1:
                        DoScriptText(SAY_WORK_2, me);
                        break;
                    case 2:
                        DoScriptText(SAY_WORK_3, me);
                        break;
                    case 3:
                        DoScriptText(SAY_WORK_4, me);
                        break;
                    case 4:
                        DoScriptText(SAY_WORK_5, me);
                        break;
                    case 5:
                        DoScriptText(SAY_WORK_6, me);
                        break;
                    case 6:
                        DoScriptText(SAY_WORK_7, me);
                        break;
                    case 7:
                        DoScriptText(SAY_WORK_8, me);
                        break;
                }
                me->RemoveAllAuras();
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                
                if (GameObject* Deposit = me->FindNearestGameObject(GO_DEPOSIT, 200))
                    me->GetMotionMaster()->MovePoint(1, Deposit->GetPositionX()-1, Deposit->GetPositionY(), Deposit->GetPositionZ());
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (work == true)
                me->HandleEmoteCommand(467);

            if (rebuffTimer <= diff)
            {
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
                rebuffTimer = 120000;
            }
            else
                rebuffTimer -= diff;

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_GOOD_HELP_IS_HARD_TO_FIND) == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(creature, SPELL_LIGHTNING_VISUAL, true);
            SpellEntry const* spell = sSpellStore.LookupEntry(SPELL_LIGHTNING_VISUAL);
            CAST_AI(npc_defiant_troll::npc_defiant_trollAI, creature->AI())->SpellHit(player, spell);
            return true;
        }
        else
        {
            creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            return true;
        }
    }
};

// q 28414
class npc_fourth_and_goal_target : public CreatureScript
{
public:
    npc_fourth_and_goal_target() : CreatureScript("npc_fourth_and_goal_target") { }

    struct npc_fourth_and_goal_targetAI : public ScriptedAI
    {
        npc_fourth_and_goal_targetAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset() {}

        void UpdateAI(const uint32 diff)
        {
            Unit* target = NULL;
            target = me->SelectNearestTarget(5.0f);
            if (target && target->GetTypeId() == TYPEID_PLAYER)
                if (target->ToPlayer()->GetQuestStatus(28414) == QUEST_STATUS_INCOMPLETE)
                    target->ToPlayer()->KilledMonsterCredit(37203, 0);
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_fourth_and_goal_targetAI(creature);
    }
};

void AddSC_kezan()
{
    new npc_fourth_and_goal_target;
    new npc_defiant_troll;
}