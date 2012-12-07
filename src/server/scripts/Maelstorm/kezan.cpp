/*
 * Copyright (C) 2011-2012 Project SkyFire <http://www.projectskyfire.org/>
 *
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

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "SpellMgr.h"
#include "Player.h"
#include "Creature.h"

// npc_deffiant_troll
enum NPC_DeffiantTroll
{
    DEFFIANT_KILL_CREDIT               = 34830,
    SPELL_LIGHTNING_VISUAL             = 45870,
    QUEST_GOOD_HELP_IS_HARD_TO_FIND    = 14069,
    GO_DEPOSIT                         = 195489,
};

#define SAY_WORK_1 "Oops, break's over."
#define SAY_WORK_2 "Don't tase me, mon!"
#define SAY_WORK_3 "I report you to HR!"
#define SAY_WORK_4 "Work was bettah in da Undermine!"
#define SAY_WORK_5 "I'm going. I'm going!"
#define SAY_WORK_6 "Sorry, mon. It won't happen again."
#define SAY_WORK_7 "What I doin' wrong? Don't I get a lunch and two breaks a day, mon?"
#define SAY_WORK_8 "Ouch! Dat hurt!"

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
            if (spell->Id == SPELL_LIGHTNING_VISUAL && caster->GetTypeId() == TYPEID_PLAYER
                && caster->ToPlayer()->GetQuestStatus(QUEST_GOOD_HELP_IS_HARD_TO_FIND) == QUEST_STATUS_INCOMPLETE && work == false)
            {
                caster->ToPlayer()->KilledMonsterCredit(DEFFIANT_KILL_CREDIT, me->GetGUID());
                switch (urand(0, 7))
                {
                    case 0:
                        me->MonsterYell(SAY_WORK_1, LANG_UNIVERSAL, 0);
                        break;
                    case 1:
                        me->MonsterYell(SAY_WORK_2, LANG_UNIVERSAL, 0);
                        break;
                    case 2:
                        me->MonsterYell(SAY_WORK_3, LANG_UNIVERSAL, 0);
                        break;
                    case 3:
                        me->MonsterYell(SAY_WORK_4, LANG_UNIVERSAL, 0);
                        break;
                    case 4:
                        me->MonsterYell(SAY_WORK_5, LANG_UNIVERSAL, 0);
                        break;
                    case 5:
                        me->MonsterYell(SAY_WORK_6, LANG_UNIVERSAL, 0);
                        break;
                    case 6:
                        me->MonsterYell(SAY_WORK_7, LANG_UNIVERSAL, 0);
                        break;
                    case 7:
                        me->MonsterYell(SAY_WORK_8, LANG_UNIVERSAL, 0);
                        break;
                }
                me->RemoveAllAuras();
                if (GameObject* Deposit = me->FindNearestGameObject(GO_DEPOSIT, 20))
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
                rebuffTimer = 120000;                 //Rebuff agian in 2 minutes
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
        return false;
    }
};

// this can be moved to SAI.
// npc_fourth_and_goal_target - http://www.wowhead.com/npc=37203/fourth-and-goal-target
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