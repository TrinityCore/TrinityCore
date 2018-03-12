/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
Scripts by Loukie
SDName: Molten Front
SD%Complete: 20%
SDComment: Placeholder
SDCategory: Molten Front
EndScriptData */

/* ContentData
EndContentData */

#include "AchievementMgr.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "GameObject.h"
#include "ScriptedGossip.h"

enum Spells
{

};

enum eEvents
{
    // npc_pyrelord
    EVENT_INCINERATE = 1,
    EVENT_BACKDRAFT = 2,

    //npc_ancient_charhound
    EVENT_FLAME_LASH = 3,
    EVENT_LEAPING_BITE = 4,
    EVENT_SLEEPING_SLEEP = 5,

    //npc_ancient_charhound
    EVENT_INCATFORM = 6,
    EVENT_PYROBLAST = 7,
    EVENT_SCORCH = 8,

    //npc_subterranean_magma_worm
    EVENT_LAVA_SHOWER = 9,
    EVENT_BURNING_HUNGER = 10,

    EVENT_ONE = 11,
    EVENT_TWO = 12,
    EVENT_THREE = 13,
    EVENT_FOUR = 14,
    EVENT_FIVE = 15,
    EVENT_SIX = 16,
    EVENT_CHECK = 17
};

/*######
# npc_pyrelord - 52683
######*/

class npc_pyrelord : public CreatureScript
{
public:
    npc_pyrelord() : CreatureScript("npc_pyrelord") {}

    struct npc_pyrelordAI : public ScriptedAI
    {
        npc_pyrelordAI(Creature *c) : ScriptedAI(c) {}

        uint32 spell_2_Timer;
        uint32 spell_1_Timer;

        void JustDied(Unit* /*killer*/) override
        {
            me->Respawn();
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (i->GetSource()->IsAlive())
            if (me->GetExactDist(i->GetSource()) < 40.0f)
                i->GetSource()->TeleportTo(861, 1166.23f, 532.65f, 18.0f, 0.0f);
        }

        void EnterCombat(Unit* /*pWho*/) override
        {
            DoCast(79938);
        }

        void Reset() override
        {
            spell_1_Timer = 2000;
            spell_2_Timer = 6000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (spell_1_Timer <= diff)
            {
                if (!me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCast(me->GetVictim(), 79938);
                    spell_1_Timer = 2000;
                }
            }
            else spell_1_Timer -= diff;

            if (spell_2_Timer <= diff)
            {
                if (!me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCast(me->GetVictim(), 98839);
                    spell_2_Timer = 6000;
                }
            }
            else spell_2_Timer -= diff;
            DoMeleeAttackIfReady();

        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_pyrelordAI(pCreature);
    }
};

/*######
# npc_ancient_charhound - 54339
######*/

class npc_ancient_charhound : public CreatureScript
{
public:
    npc_ancient_charhound() : CreatureScript("npc_ancient_charhound") {}

    struct npc_ancient_charhoundAI : public ScriptedAI
    {
        npc_ancient_charhoundAI(Creature *c) : ScriptedAI(c) {}

        uint32 spell_1_Timer;
        uint32 spell_2_Timer;
        uint32 spell_3_Timer;

        void EnterCombat(Unit* /*pWho*/) override
        {
            DoCast(98701);
        }

        void Reset() override
        {
            spell_1_Timer = 3000;
            spell_2_Timer = 6000;
            spell_3_Timer = 14000;
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (spell_1_Timer <= diff)
            {
                if (!me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCast(me->GetVictim(), 3356);
                    spell_1_Timer = 3000;
                }
            }
            else spell_1_Timer -= diff;

            if (spell_2_Timer <= diff)
            {
                if (!me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCast(me->GetVictim(), 98701);
                    spell_2_Timer = 6000;
                }
            }
            else spell_2_Timer -= diff;

            if (spell_3_Timer <= diff)
            {
                if (!me->IsWithinMeleeRange(me->GetVictim()))
                {
                    DoCast(me->GetVictim(), 42648);
                    spell_3_Timer = 14000;
                }
            }
            else spell_3_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_ancient_charhoundAI(pCreature);
    }
};

/*######
# npc_druid_of_the_flame - 54343
######*/

class npc_druid_of_the_flame : public CreatureScript
{
public:
    npc_druid_of_the_flame() : CreatureScript("npc_druid_of_the_flame") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_druid_of_the_flameAI(pCreature);
    }

    struct npc_druid_of_the_flameAI : public ScriptedAI
    {
        npc_druid_of_the_flameAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_INCATFORM, 2000);
            events.ScheduleEvent(EVENT_PYROBLAST, 3000);
            events.ScheduleEvent(EVENT_SCORCH, 6000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_INCATFORM:
                    DoCast(me, 97678);
                    events.ScheduleEvent(EVENT_PYROBLAST, 3000);
                    break;
                case EVENT_PYROBLAST:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, 17273);
                    break;
                case EVENT_SCORCH:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, 13878);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_subterranean_magma_worm - 53112
######*/

class npc_subterranean_magma_worm : public CreatureScript
{
public:
    npc_subterranean_magma_worm() : CreatureScript("npc_subterranean_magma_worm") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_subterranean_magma_wormAI(pCreature);
    }

    struct npc_subterranean_magma_wormAI : public Scripted_NoMovementAI
    {
        npc_subterranean_magma_wormAI(Creature* pCreature) :
        Scripted_NoMovementAI(pCreature)
        {
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_LAVA_SHOWER, 15000);
            events.ScheduleEvent(EVENT_BURNING_HUNGER, urand(9000, 17000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_LAVA_SHOWER:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, 97549);
                    events.ScheduleEvent(EVENT_LAVA_SHOWER, 55000);
                    break;
                case EVENT_BURNING_HUNGER:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, 98268);
                    events.RescheduleEvent(EVENT_BURNING_HUNGER, urand(12000, 17000));
                    break;
                }
            }
            DoSpellAttackIfReady(97306);
        }
    };
};

/*######
# npc_ancient_firelord - 53864
######*/

class npc_ancient_firelord : public CreatureScript
{
public:
    npc_ancient_firelord() : CreatureScript("npc_ancient_firelord") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_ancient_firelordAI(pCreature);
    }

    struct npc_ancient_firelordAI : public ScriptedAI
    {
        npc_ancient_firelordAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, 4000);
            events.ScheduleEvent(EVENT_TWO, 6000);
            events.ScheduleEvent(EVENT_THREE, 9000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, 100270);
                    events.ScheduleEvent(EVENT_ONE, 4000);
                    break;
                case EVENT_TWO:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, 100267);
                    events.ScheduleEvent(EVENT_TWO, 6000);
                    break;
                case EVENT_THREE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, 100378);
                    events.ScheduleEvent(EVENT_THREE, 9000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_firehawk - 53245,53249
######*/

class npc_firehawk : public CreatureScript
{
public:
    npc_firehawk() : CreatureScript("npc_firehawk") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firehawkAI(pCreature);
    }

    struct npc_firehawkAI : public ScriptedAI
    {
        npc_firehawkAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, 4000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 43509, true);
                    events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_bear_cub - 40240
######*/

class npc_bear_cub : public CreatureScript
{
public:
    npc_bear_cub() : CreatureScript("npc_bear_cub") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_bear_cubAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(pPlayer);
        pPlayer->KilledMonsterCredit(40240);
        pPlayer->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101181, 0, 0, pCreature);

        pCreature->DespawnOrUnsummon();

        return true;
    }

    struct npc_bear_cubAI : public ScriptedAI
    {
        npc_bear_cubAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_squirrel - 52195
######*/

class npc_squirrel : public CreatureScript
{
public:
    npc_squirrel() : CreatureScript("npc_squirrel") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_squirrelAI(pCreature);
    }

    struct npc_squirrelAI : public ScriptedAI
    {
        npc_squirrelAI(Creature* c) : ScriptedAI(c)
        {
            kick = false;
        }

        EventMap events;
        bool kick;

        void MoveInLineOfSight(Unit* who) override
        {
            Creature* creature1 = GetClosestCreatureWithEntry(me, 39939, 15.0f);
            Creature* creature2 = GetClosestCreatureWithEntry(me, 39974, 15.0f);
            Creature* creature3 = GetClosestCreatureWithEntry(me, 52816, 15.0f);
            Creature* creature4 = GetClosestCreatureWithEntry(me, 52219, 15.0f);

            if (!creature1 && !creature2 && !creature3 && !creature4)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
            {
                if (me->GetDistance(who) > 15.0f)
                    return;
                else
                {
                    DoCast(who, 96514, true);
                    kick = true;
                }
            }
            else
            {
                if (me->GetDistance(who) > 15.0f)
                    return;
                if (kick == true)
                    who->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 100964, 0, 0, me);
            }
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
        }
    };
};

/*######
# npc_child_of_tortolla - 52177
######*/

class npc_child_of_tortolla : public CreatureScript
{
public:
    npc_child_of_tortolla() : CreatureScript("npc_child_of_tortolla") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_child_of_tortollaAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(pPlayer);
        pPlayer->KilledMonsterCredit(52208);
        pPlayer->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 98102, 0, 0, pCreature);

        pCreature->DespawnOrUnsummon();

        return true;
    }

    struct npc_child_of_tortollaAI : public ScriptedAI
    {
        npc_child_of_tortollaAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_alpine_songbird - 52595
######*/

class npc_alpine_songbird : public CreatureScript
{
public:
    npc_alpine_songbird() : CreatureScript("npc_alpine_songbird") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_alpine_songbirdAI(pCreature);
    }

    struct npc_alpine_songbirdAI : public ScriptedAI
    {
        npc_alpine_songbirdAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 10.0f)
                return;

            who->ToPlayer()->KilledMonsterCredit(52595);

            if (who->ToPlayer()->GetQuestStatus(29147) == QUEST_STATUS_INCOMPLETE)
            {
                if (Aura * aura = who->GetAura(98027))
                {
                    if (aura->GetStackAmount() < 67)
                    {
                        uint32 stack = aura->GetStackAmount() + 1;
                        me->SetAuraStack(98027, who, stack);
                    }
                    if (aura->GetStackAmount() > 64)
                        who->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 100957, 0, 0, me);
                }
                else
                    me->SetAuraStack(98027, who, 1);

                me->DespawnOrUnsummon();
            }
        }

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_forest_owl - 52596
######*/

class npc_forest_owl : public CreatureScript
{
public:
    npc_forest_owl() : CreatureScript("npc_forest_owl") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_forest_owlAI(pCreature);
    }

    struct npc_forest_owlAI : public ScriptedAI
    {
        npc_forest_owlAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 10.0f)
                return;

            who->ToPlayer()->KilledMonsterCredit(52596);

            if (who->ToPlayer()->GetQuestStatus(29147) == QUEST_STATUS_INCOMPLETE)
            {
                if (Aura * aura = who->GetAura(98027))
                {
                    if (aura->GetStackAmount() < 67)
                    {
                        uint32 stack = aura->GetStackAmount() + 5;
                        me->SetAuraStack(98027, who, stack);
                    }
                    if (aura->GetStackAmount() > 64)
                        who->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 100957, 0, 0, me);
                }
                else
                    me->SetAuraStack(98027, who, 5);

                me->DespawnOrUnsummon();
            }
        }

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_goldwing_hawk - 52594
######*/

class npc_goldwing_hawk : public CreatureScript
{
public:
    npc_goldwing_hawk() : CreatureScript("npc_goldwing_hawk") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_goldwing_hawkAI(pCreature);
    }

    struct npc_goldwing_hawkAI : public ScriptedAI
    {
        npc_goldwing_hawkAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 10.0f)
                return;

            who->ToPlayer()->KilledMonsterCredit(52594);

            if (who->ToPlayer()->GetQuestStatus(29147) == QUEST_STATUS_INCOMPLETE)
            {
                if (Aura * aura = who->GetAura(98027))
                {
                    if (aura->GetStackAmount() < 67)
                    {
                        uint32 stack = aura->GetStackAmount() + 15;
                        me->SetAuraStack(98027, who, stack);
                    }
                    if (aura->GetStackAmount() > 64)
                        who->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 100957, 0, 0, me);
                }
                else
                    me->SetAuraStack(98027, who, 15);

                me->DespawnOrUnsummon();
            }
        }

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_pyrachnis - 52749
######*/

class npc_pyrachnis : public CreatureScript
{
public:
    npc_pyrachnis() : CreatureScript("npc_pyrachnis") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_pyrachnisAI(pCreature);
    }

    struct npc_pyrachnisAI : public ScriptedAI
    {
        npc_pyrachnisAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(3000, 7000));
            events.ScheduleEvent(EVENT_TWO, urand(9000, 10000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 97515, true);
                    events.ScheduleEvent(EVENT_ONE, urand(5000, 8000));
                    break;
                case EVENT_TWO:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 97516, true);
                    events.ScheduleEvent(EVENT_TWO, urand(4000, 7000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_tooga - 52425
######*/

class npc_tooga : public CreatureScript
{
public:
    npc_tooga() : CreatureScript("npc_tooga") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_toogaAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* /*pCreature*/) override
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(pPlayer);

        if (pPlayer->GetQuestStatus(29122) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* nemesis = pPlayer->SummonCreature(52383, 4595.44f, -1949.5f, 1180.39f, 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                nemesis->AI()->AttackStart(pPlayer);
        }
        return true;
    }

    struct npc_toogaAI : public ScriptedAI
    {
        npc_toogaAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //    me->CastSpell(pTarget, 97515, true);
                    //events.ScheduleEvent(EVENT_ONE, urand(5000,8000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_nemesis - 52383
######*/

class npc_nemesis : public CreatureScript
{
public:
    npc_nemesis() : CreatureScript("npc_nemesis") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_nemesisAI(pCreature);
    }

    struct npc_nemesisAI : public ScriptedAI
    {
        npc_nemesisAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(3000, 7000));
            //events.ScheduleEvent(EVENT_TWO, urand(9000,10000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 96917, true);
                    events.ScheduleEvent(EVENT_ONE, urand(15000, 18000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_lylagar - 52766
######*/

class npc_lylagar : public CreatureScript
{
public:
    npc_lylagar() : CreatureScript("npc_lylagar") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_lylagarAI(pCreature);
    }

    struct npc_lylagarAI : public ScriptedAI
    {
        npc_lylagarAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
            //events.ScheduleEvent(EVENT_TWO, urand(9000,10000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 84867, true);
                    events.ScheduleEvent(EVENT_ONE, urand(5000, 9000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_millagazor - 52649
######*/

class npc_millagazor : public CreatureScript
{
public:
    npc_millagazor() : CreatureScript("npc_millagazor") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_millagazorAI(pCreature);
    }

    struct npc_millagazorAI : public ScriptedAI
    {
        npc_millagazorAI(Creature* c) : ScriptedAI(c)
        {
            phase2 = false;
            phase3 = false;
        }

        EventMap events;
        bool phase2, phase3;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
            //events.ScheduleEvent(EVENT_TWO, urand(9000,10000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (HealthBelowPct(10) && !phase2)
            {
                phase2 = true;
                if (Creature* creature1 = me->SummonCreature(52594, me->GetPositionX(), me->GetPositionY() + 20, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                    creature1->AI()->AttackStart(me);
                if (Creature* creature2 = me->SummonCreature(52596, me->GetPositionX(), me->GetPositionY() - 20, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                    creature2->AI()->AttackStart(me);
                if (Creature* creature3 = me->SummonCreature(52595, me->GetPositionX() + 20, me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                    creature3->AI()->AttackStart(me);
                if (Creature* creature4 = me->SummonCreature(52595, me->GetPositionX() - 20, me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                    creature4->AI()->AttackStart(me);
                events.ScheduleEvent(EVENT_TWO, 10000);
            }

            if (HealthBelowPct(5) && !phase3)
            {
                phase3 = true;
                me->DespawnOrUnsummon();
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 11839, true);
                    events.ScheduleEvent(EVENT_ONE, urand(4000, 6000));
                    break;
                case EVENT_TWO:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        pTarget->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_KILL_CREATURE, 52649, 0, 0, me);
                        pTarget->ToPlayer()->KilledMonsterCredit(52649);
                        me->DespawnOrUnsummon();
                    }
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_galenges - 52399
######*/

class npc_galenges : public CreatureScript
{
public:
    npc_galenges() : CreatureScript("npc_galenges") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_galengesAI(pCreature);
    }

    struct npc_galengesAI : public ScriptedAI
    {
        npc_galengesAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
            events.ScheduleEvent(EVENT_TWO, urand(27000, 30000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 82615, true);
                    events.ScheduleEvent(EVENT_ONE, urand(2000, 3000));
                    break;
                case EVENT_TWO:
                    if (Creature* malorne = me->SummonCreature(53493, me->GetPositionX(), me->GetPositionY() + 20, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 20000))
                    {
                        malorne->AI()->AttackStart(me);
                        me->AI()->AttackStart(malorne);
                    }
                    if (HealthBelowPct(5))
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        {
                            pTarget->ToPlayer()->KilledMonsterCredit(52399);
                            pTarget->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 100979, 0, 0, me);
                        }
                        me->DespawnOrUnsummon(0);
                    }
                    events.ScheduleEvent(EVENT_THREE, urand(27000, 30000));
                    break;
                case EVENT_THREE:
                    if (Creature* malorne = me->SummonCreature(53493, me->GetPositionX(), me->GetPositionY() + 20, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 20000))
                    {
                        malorne->AI()->AttackStart(me);
                        me->AI()->AttackStart(malorne);
                    }
                    if (HealthBelowPct(5))
                    {
                        if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                            pTarget->ToPlayer()->KilledMonsterCredit(52399);
                        me->DespawnOrUnsummon(0);
                    }
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_arch_druid_hamuul_runetotem - 52838
######*/

class npc_arch_druid_hamuul_runetotem : public CreatureScript
{
public:
    npc_arch_druid_hamuul_runetotem() : CreatureScript("npc_arch_druid_hamuul_runetotem") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_arch_druid_hamuul_runetotemAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* /*pCreature*/) override
    {
        if (pPlayer->GetQuestStatus(29199))
        {
            if (pPlayer->GetCurrency(416) >= 20)
                return false;

            return true;
        }

        return false;
    }

    struct npc_arch_druid_hamuul_runetotemAI : public ScriptedAI
    {
        npc_arch_druid_hamuul_runetotemAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 20.0f)
                return;

            if (who->ToPlayer()->GetQuestStatus(29195) == QUEST_STATUS_INCOMPLETE)
            {
                Creature* leyara = GetClosestCreatureWithEntry(who, 52863, 50.0f);
                if (!leyara)
                if (Creature* leyara2 = who->SummonCreature(52863, 4672.59f, -2067.19f, 1224.8f, 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                    leyara2->AI()->AttackStart(who);
            }
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_leyara - 52863
######*/

class npc_leyara : public CreatureScript
{
public:
    npc_leyara() : CreatureScript("npc_leyara") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_leyaraAI(pCreature);
    }

    struct npc_leyaraAI : public ScriptedAI
    {
        npc_leyaraAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void JustDied(Unit* /*killer*/) override
        {
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (i->GetSource()->IsAlive())
            if (me->GetExactDist(i->GetSource()) < 50.0f)
                i->GetSource()->KilledMonsterCredit(52863);
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
            events.ScheduleEvent(EVENT_TWO, urand(9000, 10000));
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 35377, true);
                    events.ScheduleEvent(EVENT_ONE, urand(4000, 6000));
                    break;
                case EVENT_TWO:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 97721, true);
                    events.ScheduleEvent(EVENT_TWO, urand(12000, 15000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_elderlimb - 52906
######*/

class npc_elderlimb : public CreatureScript
{
public:
    npc_elderlimb() : CreatureScript("npc_elderlimb") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_elderlimbAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* /*pCreature*/) override
    {
        if (pPlayer->GetQuestStatus(29283) == QUEST_STATUS_COMPLETE)
        {
            if (pPlayer->GetCurrency(416) >= 125)
                return false;

            return true;
        }
        return false;
    }

    struct npc_elderlimbAI : public ScriptedAI
    {
        npc_elderlimbAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 20.0f)
                return;

            if (who->ToPlayer()->GetQuestStatus(29197) == QUEST_STATUS_INCOMPLETE)
            {
                Creature* raging = GetClosestCreatureWithEntry(who, 52557, 20.0f);
                if (!raging)
                if (Creature* raging2 = me->SummonCreature(52557, who->GetPositionX(), who->GetPositionY(), who->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                {
                    raging2->AI()->AttackStart(who);
                    who->ToPlayer()->KilledMonsterCredit(52906);
                }
            }
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_thisalee_crow - 52907
######*/

class npc_thisalee_crow : public CreatureScript
{
public:
    npc_thisalee_crow() : CreatureScript("npc_thisalee_crow") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_thisalee_crowAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101176, 0, 0, pCreature);
        return false;
    }

    struct npc_thisalee_crowAI : public ScriptedAI
    {
        npc_thisalee_crowAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 20.0f)
                return;

            if (who->ToPlayer()->GetQuestStatus(29197) == QUEST_STATUS_INCOMPLETE)
            {
                Creature* raging = GetClosestCreatureWithEntry(who, 52557, 20.0f);
                if (!raging)
                if (Creature* raging2 = me->SummonCreature(52557, who->GetPositionX(), who->GetPositionY(), who->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                {
                    raging2->AI()->AttackStart(who);
                    who->ToPlayer()->KilledMonsterCredit(52907);
                }
            }
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_tholo_whitehoof - 52903
######*/

class npc_tholo_whitehoof : public CreatureScript
{
public:
    npc_tholo_whitehoof() : CreatureScript("npc_tholo_whitehoof") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_tholo_whitehoofAI(pCreature);
    }

    struct npc_tholo_whitehoofAI : public ScriptedAI
    {
        npc_tholo_whitehoofAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 20.0f)
                return;

            if (who->ToPlayer()->GetQuestStatus(29197) == QUEST_STATUS_INCOMPLETE)
            {
                Creature* raging = GetClosestCreatureWithEntry(who, 52557, 20.0f);
                if (!raging)
                if (Creature* raging2 = me->SummonCreature(52557, who->GetPositionX(), who->GetPositionY(), who->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000))
                {
                    raging2->AI()->AttackStart(who);
                    who->ToPlayer()->KilledMonsterCredit(52903);
                }
            }
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_melfurion_stormrage - 52845
######*/

class npc_melfurion_stormrage : public CreatureScript
{
public:
    npc_melfurion_stormrage() : CreatureScript("npc_melfurion_stormrage") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_melfurion_stormrageAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101174, 0, 0, pCreature);
        return false;
    }

    struct npc_melfurion_stormrageAI : public ScriptedAI
    {
        npc_melfurion_stormrageAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 10.0f)
                return;

            if (who->ToPlayer()->GetQuestStatus(29198) == QUEST_STATUS_INCOMPLETE)
            {
                Creature* raging1 = me->SummonCreature(52557, me->GetPositionX(), me->GetPositionY() + 2, who->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
                Creature* raging2 = me->SummonCreature(52557, me->GetPositionX(), me->GetPositionY() - 2, who->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
                Creature* raging3 = me->SummonCreature(52557, me->GetPositionX() + 2, me->GetPositionY(), who->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
                Creature* raging4 = me->SummonCreature(52557, me->GetPositionX() - 2, me->GetPositionY(), who->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
                raging1->AI()->AttackStart(who);
                raging2->AI()->AttackStart(who);
                raging3->AI()->AttackStart(who);
                raging4->AI()->AttackStart(who);
                who->ToPlayer()->KilledMonsterCredit(52845);
            }
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_leyara2 - 53014
######*/

class npc_leyara2 : public CreatureScript
{
public:
    npc_leyara2() : CreatureScript("npc_leyara2") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_leyara2AI(pCreature);
    }

    struct npc_leyara2AI : public ScriptedAI
    {
        npc_leyara2AI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 10.0f)
                return;

            if (who->ToPlayer()->GetQuestStatus(29200) == QUEST_STATUS_INCOMPLETE)
                who->ToPlayer()->KilledMonsterCredit(53014);
            if (who->ToPlayer()->GetQuestStatus(29310) == QUEST_STATUS_INCOMPLETE)
                who->ToPlayer()->KilledMonsterCredit(53302);
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_molten_behemoth - 52552
######*/

class npc_molten_behemoth : public CreatureScript
{
public:
    npc_molten_behemoth() : CreatureScript("npc_molten_behemoth") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_molten_behemothAI(pCreature);
    }

    struct npc_molten_behemothAI : public ScriptedAI
    {
        npc_molten_behemothAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
            //events.ScheduleEvent(EVENT_TWO, urand(9000,10000));
        }

        void JustDied(Unit* /*killer*/) override
        {
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (i->GetSource()->IsAlive())
            if (me->GetExactDist(i->GetSource()) < 50.0f)
            if (i->GetSource())
                i->GetSource()->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101167, 0, 0, me);
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 97243, true);
                    events.ScheduleEvent(EVENT_ONE, urand(8000, 12000));
                    break;/*
                          case EVENT_TWO:
                          if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                          me->CastSpell(pTarget, 97721, true);
                          events.ScheduleEvent(EVENT_ONE, urand(12000,15000));
                          break;    */
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_rayne_feathersong - 52467
######*/

class npc_rayne_feathersong : public CreatureScript
{
public:
    npc_rayne_feathersong() : CreatureScript("npc_rayne_feathersong") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_rayne_feathersongAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        Creature* summoned = GetClosestCreatureWithEntry(pPlayer, 53083, 100.0f);

        if (!summoned)
        if (pPlayer->GetQuestStatus(29143) == QUEST_STATUS_INCOMPLETE)
        {
            pCreature->SummonCreature(53083, pPlayer->GetPositionX(), pPlayer->GetPositionY(), pPlayer->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
            return true;
        }
        return false;
    }

    struct npc_rayne_feathersongAI : public ScriptedAI
    {
        npc_rayne_feathersongAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:

                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //me->CastSpell(pTarget, 97243, true);
                    //events.ScheduleEvent(EVENT_ONE, urand(8000,12000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};


/*######
# npc_cinderweb_spinner2 - 52981
######*/

class npc_cinderweb_spinner2 : public CreatureScript
{
public:
    npc_cinderweb_spinner2() : CreatureScript("npc_cinderweb_spinner2") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_cinderweb_spinner2AI(pCreature);
    }

    struct npc_cinderweb_spinner2AI : public ScriptedAI
    {
        npc_cinderweb_spinner2AI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(500, 1000));
            //events.ScheduleEvent(EVENT_TWO, urand(9000,10000));
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        pTarget->ToPlayer()->TeleportTo(861, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0.0f);
                        me->CastSpell(pTarget, 97959, true);
                        me->AI()->AttackStart(pTarget);
                        break;
                    }
                    events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
                    break;/*
                          case EVENT_TWO:
                          if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                          me->CastSpell(pTarget, 97721, true);
                          events.ScheduleEvent(EVENT_ONE, urand(12000,15000));
                          break;    */
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_Achievement_helper - 529810
######*/

class npc_Achievement_helper : public CreatureScript
{
public:
    npc_Achievement_helper() : CreatureScript("npc_Achievement_helper") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_Achievement_helperAI(pCreature);
    }

    struct npc_Achievement_helperAI : public ScriptedAI
    {
        npc_Achievement_helperAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (me->GetDistance(who) > 1.0f)
                return;

            AchievementEntry const* king_of_the_spider_hill = sAchievementStore.LookupEntry(5872);
            who->ToPlayer()->CompletedAchievement(king_of_the_spider_hill);
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_fireside_chat - 52921(101179) - 53259(101177) - 52824(101182) - 52134(101173) - 52986(101170) - 52669(101175) - 52845(101174 - ok) - 52907(101176 - ok)
######*/

class npc_fireside_chat : public CreatureScript
{
public:
    npc_fireside_chat() : CreatureScript("npc_fireside_chat") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_fireside_chatAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        if (pCreature->GetEntry() == 52921)
            pPlayer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101179, 0, 0, pCreature);
        else if (pCreature->GetEntry() == 53259)
            pPlayer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101177, 0, 0, pCreature);
        else if (pCreature->GetEntry() == 52824)
            pPlayer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101182, 0, 0, pCreature);
        else if (pCreature->GetEntry() == 52134)
            pPlayer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101173, 0, 0, pCreature);
        else if (pCreature->GetEntry() == 52986)
            pPlayer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101170, 0, 0, pCreature);
        else if (pCreature->GetEntry() == 52669)
        {
            pPlayer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101175, 0, 0, pCreature);
            if (pPlayer->GetQuestStatus(29279) == QUEST_STATUS_COMPLETE || pPlayer->GetQuestStatus(29281) == QUEST_STATUS_COMPLETE)
            {
                if (pPlayer->GetCurrency(416) >= 125)
                    return false;

                return true;
            }
        }

        return false;
    }

    struct npc_fireside_chatAI : public ScriptedAI
    {
        npc_fireside_chatAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:

                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //me->CastSpell(pTarget, 97243, true);
                    //events.ScheduleEvent(EVENT_ONE, urand(8000,12000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_currency_required_quest_taker - 52490(29181) - 52493(29214) - 52669(29279) - 52669(29281) - 52906(29283)
######*/

class npc_currency_required_quest_taker : public CreatureScript
{
public:
    npc_currency_required_quest_taker() : CreatureScript("npc_currency_required_quest_taker") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_currency_required_quest_takerAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        if (pCreature->GetEntry() == 52490 && pPlayer->GetQuestStatus(29181) == QUEST_STATUS_COMPLETE)
        {
            if (pPlayer->GetCurrency(416) >= 150)
                return false;

            return true;
        }
        else if (pCreature->GetEntry() == 52493 && pPlayer->GetQuestStatus(29214) == QUEST_STATUS_COMPLETE)
        {
            if (pPlayer->GetCurrency(416) >= 150)
                return false;

            return true;
        }

        return false;
    }

    struct npc_currency_required_quest_takerAI : public ScriptedAI
    {
        npc_currency_required_quest_takerAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    return;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_flamewaker_shaman - 53093
######*/

class npc_flamewaker_shaman : public CreatureScript
{
public:
    npc_flamewaker_shaman() : CreatureScript("npc_flamewaker_shaman") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_flamewaker_shamanAI(pCreature);
    }

    struct npc_flamewaker_shamanAI : public ScriptedAI
    {
        npc_flamewaker_shamanAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
            events.ScheduleEvent(EVENT_TWO, urand(7000, 9000));
            events.ScheduleEvent(EVENT_THREE, urand(12000, 15000));
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 15096, true);
                    events.ScheduleEvent(EVENT_ONE, urand(15000, 18000));
                    break;
                case EVENT_TWO:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 32062, true);
                    events.ScheduleEvent(EVENT_TWO, urand(12000, 15000));
                    break;
                case EVENT_THREE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        me->CastSpell(pTarget, 98210, true);
                        if (Creature* helper = me->SummonCreature(530930, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 5000))
                            helper->AI()->AttackStart(me);
                    }
                    events.ScheduleEvent(EVENT_THREE, urand(8000, 15000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_flamewaker_shaman_helper - 530930
######*/

class npc_flamewaker_shaman_helper : public CreatureScript
{
public:
    npc_flamewaker_shaman_helper() : CreatureScript("npc_flamewaker_shaman_helper") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_flamewaker_shaman_helperAI(pCreature);
    }

    struct npc_flamewaker_shaman_helperAI : public ScriptedAI
    {
        npc_flamewaker_shaman_helperAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, 1000);
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetEntry() == 53093)
            {
                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if (i->GetSource()->IsAlive())
                if (me->GetExactDist(i->GetSource()) < 100.0f)
                    i->GetSource()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 100992, 0, 0, me);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    DoCast(98185);
                    events.ScheduleEvent(EVENT_ONE, 1000);
                    break;
                }
            }
        }
    };
};


/*######
# npc_flamewaker_hunter - 53143
######*/

class npc_flamewaker_hunter : public CreatureScript
{
public:
    npc_flamewaker_hunter() : CreatureScript("npc_flamewaker_hunter") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_flamewaker_hunterAI(pCreature);
    }

    struct npc_flamewaker_hunterAI : public ScriptedAI
    {
        npc_flamewaker_hunterAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(1000, 2000));
            events.ScheduleEvent(EVENT_TWO, urand(7000, 10000));
            events.ScheduleEvent(EVENT_THREE, urand(15000, 18000));
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 98393, true);
                    events.ScheduleEvent(EVENT_ONE, urand(2000, 3000));
                    break;
                case EVENT_TWO:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 82707, true);
                    events.ScheduleEvent(EVENT_TWO, urand(9000, 12000));
                    break;
                case EVENT_THREE:
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if (Creature* helper = me->SummonCreature(531430, pTarget->GetPositionX(), pTarget->GetPositionY() + urand(1, 3), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 3000))
                        {
                            if (Creature* helper2 = me->SummonCreature(531431, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ() + 20, 0, TEMPSUMMON_TIMED_DESPAWN, 7000))
                                helper2->AI()->AttackStart(helper);

                            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                            if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->GetSource()->IsAlive())
                            if (me->GetExactDist(i->GetSource()) < 7.0f)
                                helper->AI()->AttackStart(i->GetSource());
                        }
                    }
                    events.ScheduleEvent(EVENT_FOUR, 1500);
                    events.ScheduleEvent(EVENT_THREE, urand(8000, 15000));
                    break;
                case EVENT_FOUR:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if (Creature* helper = me->SummonCreature(531430, pTarget->GetPositionX(), pTarget->GetPositionY() - urand(1, 3), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 3000))
                        {
                            if (Creature* helper2 = me->SummonCreature(531431, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ() + 20, 0, TEMPSUMMON_TIMED_DESPAWN, 7000))
                                helper2->AI()->AttackStart(helper);

                            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                            if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->GetSource()->IsAlive())
                            if (me->GetExactDist(i->GetSource()) < 7.0f)
                                helper->AI()->AttackStart(i->GetSource());
                        }
                    }
                    events.ScheduleEvent(EVENT_FIVE, 1500);
                    break;
                case EVENT_FIVE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if (Creature* helper = me->SummonCreature(531430, pTarget->GetPositionX() + urand(1, 3), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 3000))
                        {
                            if (Creature* helper2 = me->SummonCreature(531431, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ() + 20, 0, TEMPSUMMON_TIMED_DESPAWN, 7000))
                                helper2->AI()->AttackStart(helper);

                            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                            if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->GetSource()->IsAlive())
                            if (me->GetExactDist(i->GetSource()) < 7.0f)
                                helper->AI()->AttackStart(i->GetSource());
                        }
                    }
                    events.ScheduleEvent(EVENT_SIX, 1500);
                    break;
                case EVENT_SIX:
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        if (Creature* helper = me->SummonCreature(531430, pTarget->GetPositionX() - urand(1, 3), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 3000))
                        {
                            if (Creature* helper2 = me->SummonCreature(531431, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ() + 20, 0, TEMPSUMMON_TIMED_DESPAWN, 7000))
                                helper2->AI()->AttackStart(helper);

                            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                            if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                            if (i->GetSource()->IsAlive())
                            if (me->GetExactDist(i->GetSource()) < 7.0f)
                                helper->AI()->AttackStart(i->GetSource());
                        }
                    }
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_flamewaker_hunter_helper2 - 530931
######*/

class npc_flamewaker_hunter_helper2 : public CreatureScript
{
public:
    npc_flamewaker_hunter_helper2() : CreatureScript("npc_flamewaker_hunter_helper2") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_flamewaker_hunter_helper2AI(pCreature);
    }

    struct npc_flamewaker_hunter_helper2AI : public ScriptedAI
    {
        npc_flamewaker_hunter_helper2AI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Creature* helper1 = GetClosestCreatureWithEntry(me, 531430, 50.0f);
            me->CastSpell(helper1, 98393, true);
            events.ScheduleEvent(EVENT_ONE, 2000);
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    me->DespawnOrUnsummon();
                    break;
                }
            }
        }
    };
};

/*######
# npc_flamewaker_hunter_helper - 530930
######*/

class npc_flamewaker_hunter_helper : public CreatureScript
{
public:
    npc_flamewaker_hunter_helper() : CreatureScript("npc_flamewaker_hunter_helper") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_flamewaker_hunter_helperAI(pCreature);
    }

    struct npc_flamewaker_hunter_helperAI : public ScriptedAI
    {
        npc_flamewaker_hunter_helperAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, 2000);
        }

        void JustDied(Unit* /*killer*/) override
        {
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                {
                                  me->CastSpell(me, 98371, true);
                                  Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                                  if (!PlayerList.isEmpty())
                                  for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                  if (i->GetSource()->IsAlive())
                                  {
                                      if (me->GetExactDist(i->GetSource()) > 10.0f)
                                          i->GetSource()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 100996, 0, 0, me);
                                  }
                                  events.ScheduleEvent(EVENT_TWO, 1000);
                }
                    break;
                case EVENT_TWO:
                    me->DespawnOrUnsummon();
                    break;
                }
            }
        }
    };
};

/*######
# npc_flamewaker_sentinel - 53085
######*/

class npc_flamewaker_sentinel : public CreatureScript
{
public:
    npc_flamewaker_sentinel() : CreatureScript("npc_flamewaker_sentinel") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_flamewaker_sentinelAI(pCreature);
    }

    struct npc_flamewaker_sentinelAI : public ScriptedAI
    {
        npc_flamewaker_sentinelAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                me->CastSpell(pTarget, 32323, true);
            events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
            events.ScheduleEvent(EVENT_TWO, urand(22000, 29000));
        }

        void JustDied(Unit* killer) override
        {
            if (me->HasAura(98169))
                killer->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_KILL_CREATURE, 53085, 0, 0, me);
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 79881, true);
                    events.ScheduleEvent(EVENT_ONE, urand(4000, 7000));
                    break;
                case EVENT_TWO:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 98169, true);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_emberspit_scorpion - 53240
######*/

class npc_emberspit_scorpion : public CreatureScript
{
public:
    npc_emberspit_scorpion() : CreatureScript("npc_emberspit_scorpion") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_emberspit_scorpionAI(pCreature);
    }

    struct npc_emberspit_scorpionAI : public ScriptedAI
    {
        npc_emberspit_scorpionAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                me->CastSpell(pTarget, 53148, true);
            events.ScheduleEvent(EVENT_ONE, urand(3000, 5000));
        }

        void JustDied(Unit* /*killer*/) override
        {
            //if (killer)
            //killer->ToPlayer()->KilledMonsterCredit(53263);
            me->SummonCreature(53387, me->GetPositionX(), me->GetPositionY() + urand(4, 7), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 5000);
            me->SummonCreature(53013, me->GetPositionX(), me->GetPositionY() + urand(4, 7), me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 5000);
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 11985, true);
                    events.ScheduleEvent(EVENT_ONE, urand(9000, 12000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_trained_firehawk - 53297
######*/

class npc_trained_firehawk : public CreatureScript
{
public:
    npc_trained_firehawk() : CreatureScript("npc_trained_firehawk") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_trained_firehawkAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(pPlayer);

        if (pPlayer->GetQuestStatus(29290) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->TeleportTo(861, 365.84f, -353.13f, 219.64f, 0.0f);
            Creature* windsong = GetClosestCreatureWithEntry(pCreature, 53259, 20.0f);
            if (!windsong)
            {
                pPlayer->EnterVehicle(pCreature, 0);
                pCreature->GetMotionMaster()->MovePoint(0, 514.87f, -467.04f, 188.76f);
            }

        }

        return true;
    }

    struct npc_trained_firehawkAI : public ScriptedAI
    {
        npc_trained_firehawkAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    break;
                }
            }
        }
    };
};

/*######
# npc_firehawk_helper - 532971-9
######*/

class npc_firehawk_helper : public CreatureScript
{
public:
    npc_firehawk_helper() : CreatureScript("npc_firehawk_helper") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_firehawk_helperAI(pCreature);
    }

    struct npc_firehawk_helperAI : public ScriptedAI
    {
        npc_firehawk_helperAI(Creature* c) : ScriptedAI(c)
        {
            kick = false;
        }

        EventMap events;
        bool kick;

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) > 10.0f)
                return;

            if (me->GetEntry() == 532971)
                who->GetMotionMaster()->MovePoint(0, 560.34f, -604.76f, 204.38f);
            if (me->GetEntry() == 532972)
                who->GetMotionMaster()->MovePoint(0, 892.18f, -455.54f, 237.11f);
            if (me->GetEntry() == 532973)
                who->GetMotionMaster()->MovePoint(0, 878.91f, -371.4f, 221.36f);
            if (me->GetEntry() == 532974)
                who->GetMotionMaster()->MovePoint(0, 826.62f, -379.41f, 233.25f);
            if (me->GetEntry() == 532975)
                who->GetMotionMaster()->MovePoint(0, 804.6f, -191.4f, 254.07f);
            if (me->GetEntry() == 532976)
                who->GetMotionMaster()->MovePoint(0, 773.41f, -325.75f, 212.82f);
            if (me->GetEntry() == 532977)
                who->GetMotionMaster()->MovePoint(0, 669.86f, -384.36f, 191.38f);
            if (me->GetEntry() == 532978)
                who->GetMotionMaster()->MovePoint(0, 598.43f, -519.02f, 192.0f);
            if (me->GetEntry() == 532979)
                who->GetMotionMaster()->MovePoint(0, 509.3f, -443.67f, 165.64f);
            if (me->GetEntry() == 532980)
            if (who->GetTypeId() == TYPEID_PLAYER)
                who->ToPlayer()->TeleportTo(861, 1244.75f, 530.091f, 59.8688f, 0.0f);
        }

        void Reset() override
        {
            me->SetCanFly(true);
            me->SetDisableGravity(true);
            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //DoCast(pTarget, 43509, true);
                    //events.ScheduleEvent(EVENT_ONE, 8000);
                    break;
                }
            }
        }
    };
};

/*######
# death_from_above - 53240
######*/

class death_from_above : public CreatureScript
{
public:
    death_from_above() : CreatureScript("death_from_above") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new death_from_aboveAI(pCreature);
    }

    struct death_from_aboveAI : public ScriptedAI
    {
        death_from_aboveAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void JustDied(Unit* /*killer*/) override
        {
            Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
            if (!PlayerList.isEmpty())
            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
            if (i->GetSource()->IsAlive())
            if (me->GetExactDist(i->GetSource()) < 120.0f)
            {
                if (me->GetEntry() == 54252)
                    i->GetSource()->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101098, 0, 0, me);
                if (me->GetEntry() == 54253)
                    i->GetSource()->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101097, 0, 0, me);
                if (me->GetEntry() == 54254)
                    i->GetSource()->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101099, 0, 0, me);
                if (me->GetEntry() == 54255)
                    i->GetSource()->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101100, 0, 0, me);
                if (me->GetEntry() == 54256)
                    i->GetSource()->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101101, 0, 0, me);
                if (me->GetEntry() == 54257)
                    i->GetSource()->ToPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, 101103, 0, 0, me);
            }
        }

        void KilledUnit(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //me->CastSpell(pTarget, 11985, true);
                    //events.ScheduleEvent(EVENT_ONE, urand(9000,12000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

class go_ungoro_soil : public GameObjectScript
{
public:
    go_ungoro_soil() : GameObjectScript("go_ungoro_soil") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(29249) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(53084);
            go->SummonCreature(53013, go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 180000);
            CloseGossipMenuFor(player);
            return false;
        }
        return true;
    }
};

/*######
# npc_little_lasher - 53013
######*/

class npc_little_lasher : public CreatureScript
{
public:
    npc_little_lasher() : CreatureScript("npc_little_lasher") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_little_lasherAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(pPlayer);

        if (pPlayer->GetQuestStatus(29254) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->KilledMonsterCredit(53079);
            Creature* avrilla = GetClosestCreatureWithEntry(pCreature, 52489, 200.0f);
            if (avrilla)
                pCreature->GetMotionMaster()->MovePoint(0, avrilla->GetPositionX(), avrilla->GetPositionY(), avrilla->GetPositionZ());

        }

        return true;
    }

    struct npc_little_lasherAI : public ScriptedAI
    {
        npc_little_lasherAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    break;
                }
            }
        }
    };
};

/*######
# npc_hyjal_druid - 525010
######*/

class npc_hyjal_druid : public CreatureScript
{
public:
    npc_hyjal_druid() : CreatureScript("npc_hyjal_druid") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_hyjal_druidAI(pCreature);
    }

    struct npc_hyjal_druidAI : public ScriptedAI
    {
        npc_hyjal_druidAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) > 20.0f)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Creature* flamewatch = GetClosestCreatureWithEntry(me, 52399, 20.0f);
            Creature* flamewatch2 = GetClosestCreatureWithEntry(me, 52663, 20.0f);
            Creature* pyrelord = GetClosestCreatureWithEntry(me, 52998, 20.0f);
            if (flamewatch)
                me->AI()->AttackStart(flamewatch);
            else if (flamewatch2)
                me->AI()->AttackStart(flamewatch2);
            else if (pyrelord)
                me->AI()->AttackStart(pyrelord);
            else if (who->ToPlayer()->GetQuestStatus(29205) == QUEST_STATUS_INCOMPLETE && !pyrelord && !flamewatch)
                who->ToPlayer()->KilledMonsterCredit(53012);
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_flame_protection_rune - 52884,52885,52886,52887,52888,52889,52890,53887
######*/

class npc_flame_protection_rune : public CreatureScript
{
public:
    npc_flame_protection_rune() : CreatureScript("npc_flame_protection_rune") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_flame_protection_runeAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(pPlayer);

        if (pPlayer->GetQuestStatus(29210) == QUEST_STATUS_INCOMPLETE)
        {
            pCreature->DespawnOrUnsummon();

            return false;
        }

        return true;
    }

    struct npc_flame_protection_runeAI : public ScriptedAI
    {
        npc_flame_protection_runeAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    break;
                }
            }
        }
    };
};

/*######
# npc_flame_protection_rune1 - 528840
######*/

class npc_flame_protection_rune1 : public CreatureScript
{
public:
    npc_flame_protection_rune1() : CreatureScript("npc_flame_protection_rune1") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_flame_protection_rune1AI(pCreature);
    }

    struct npc_flame_protection_rune1AI : public ScriptedAI
    {
        npc_flame_protection_rune1AI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) > 100.0f)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            Creature* rune1 = GetClosestCreatureWithEntry(me, 52884, 200.0f);
            Creature* rune2 = GetClosestCreatureWithEntry(me, 52885, 200.0f);
            Creature* rune3 = GetClosestCreatureWithEntry(me, 52886, 200.0f);
            Creature* rune4 = GetClosestCreatureWithEntry(me, 52887, 200.0f);
            Creature* rune5 = GetClosestCreatureWithEntry(me, 52888, 200.0f);
            Creature* rune6 = GetClosestCreatureWithEntry(me, 52889, 200.0f);
            Creature* rune7 = GetClosestCreatureWithEntry(me, 52890, 200.0f);
            Creature* rune8 = GetClosestCreatureWithEntry(me, 53887, 200.0f);
            if (!rune1 && !rune2 && !rune3 && !rune4 && !rune5 && !rune6 && !rune7 && !rune8)
                who->ToPlayer()->KilledMonsterCredit(52891);
        }

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    break;
                }
            }
        }
    };
};

class go_solar_core : public GameObjectScript
{
public:
    go_solar_core() : GameObjectScript("go_solar_core") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (player->GetQuestStatus(29211) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(52950);
            go->RemoveFromWorld();
            CloseGossipMenuFor(player);
            return false;
        }
        return true;
    }
};

/*######
# npc_druid_of_the_flame_molten_front - 52871,52872
######*/

class npc_druid_of_the_flame_molten_front : public CreatureScript
{
public:
    npc_druid_of_the_flame_molten_front() : CreatureScript("npc_druid_of_the_flame_molten_front") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_druid_of_the_flame_molten_frontAI(pCreature);
    }

    struct npc_druid_of_the_flame_molten_frontAI : public ScriptedAI
    {
        npc_druid_of_the_flame_molten_frontAI(Creature* c) : ScriptedAI(c)
        {
            phase = false;
        }

        EventMap events;
        bool phase;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_ONE, urand(2000, 5000));
            events.ScheduleEvent(EVENT_TWO, urand(7000, 10000));
        }


        void SpellHit(Unit* /*caster*/, const SpellInfo* spell) override
        {
            if (spell->Id == 98628)
            {
                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if (i->GetSource()->IsAlive())
                if (me->GetExactDist(i->GetSource()) < 50.0f)
                if (i->GetSource()->GetQuestStatus(29297) == QUEST_STATUS_INCOMPLETE)
                if (me->HasAura(98827))
                {
                    i->GetSource()->KilledMonsterCredit(53251);
                    me->DespawnOrUnsummon();
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            if (HealthBelowPct(50) && !phase)
            {
                phase = true;
                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                if (i->GetSource()->IsAlive())
                if (me->GetExactDist(i->GetSource()) < 50.0f)
                if (i->GetSource()->GetQuestStatus(29192) == QUEST_STATUS_INCOMPLETE)
                if (Creature* shadowwarden = me->SummonCreature(52804, me->GetPositionX(), me->GetPositionY() + 10, me->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 5000))
                {
                    i->GetSource()->KilledMonsterCredit(52815);
                    shadowwarden->AI()->AttackStart(me);
                    me->CastSpell(me, 97565, true);
                }
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 17273, true);
                    events.ScheduleEvent(EVENT_ONE, urand(15000, 18000));
                    break;
                case EVENT_TWO:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        me->CastSpell(pTarget, 13878, true);
                    events.ScheduleEvent(EVENT_TWO, urand(10000, 12000));
                    events.ScheduleEvent(EVENT_THREE, urand(5000, 10000));
                    break;
                case EVENT_THREE:
                    if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    if (pTarget)
                    if (pTarget->ToPlayer()->GetQuestStatus(29297) == QUEST_STATUS_INCOMPLETE)
                    {
                        me->CastSpell(me, 98827, true);
                        me->SetCanFly(true);
                        me->SetDisableGravity(true);
                        me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->SetDisplayId(38814);
                        me->GetMotionMaster()->MovePoint(0, pTarget->GetPositionX() + 10, pTarget->GetPositionY() + 10, pTarget->GetPositionZ() + 10);
                    }
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_cinderweb_cocoon - 52751,52783,52784,52989,52991,52992
######*/

class npc_cinderweb_cocoon : public CreatureScript
{
public:
    npc_cinderweb_cocoon() : CreatureScript("npc_cinderweb_cocoon") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_cinderweb_cocoonAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        CloseGossipMenuFor(pPlayer);

        if (pPlayer->GetQuestStatus(29189) == QUEST_STATUS_INCOMPLETE)
        {
            pPlayer->KilledMonsterCredit(52751);
            pCreature->DespawnOrUnsummon();
            return false;
        }

        return true;
    }

    struct npc_cinderweb_cocoonAI : public ScriptedAI
    {
        npc_cinderweb_cocoonAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            //events.ScheduleEvent(EVENT_ONE, 100);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:
                    break;
                }
            }
        }
    };
};

/*######
# npc_molten_front_vendor - 53882,53214,53881
######*/

class npc_molten_front_vendor : public CreatureScript
{
public:
    npc_molten_front_vendor() : CreatureScript("npc_molten_front_vendor") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_molten_front_vendorAI(pCreature);
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        if (pCreature->GetEntry() == 53882)
        {
            if (pPlayer->GetQuestStatus(29284))
                return false;
            else
                return true;
        }
        if (pCreature->GetEntry() == 53214)
        {
            if (pPlayer->GetQuestStatus(29282))
                return false;
            else
                return true;
        }
        if (pCreature->GetEntry() == 53881)
        {
            if (pPlayer->GetQuestStatus(29280))
                return false;
            else
                return true;
        }
        return true;
    }

    struct npc_molten_front_vendorAI : public ScriptedAI
    {
        npc_molten_front_vendorAI(Creature* c) : ScriptedAI(c)
        {
        }

        EventMap events;

        void Reset() override
        {
            //me->SetCanFly(true);
            //me->SetDisableGravity(true);
            //me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ONE:

                    //if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    //me->CastSpell(pTarget, 97243, true);
                    //events.ScheduleEvent(EVENT_ONE, urand(8000,12000));
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };
};

/*######
# npc_fireland_teleporter - 100005
######*/

class npc_fireland_teleporter : public CreatureScript
{
public:
    npc_fireland_teleporter() : CreatureScript("npc_fireland_teleporter") { }

    CreatureAI* GetAI(Creature* pCreature) const override
    {
        return new npc_fireland_teleporterAI(pCreature);
    }

    struct npc_fireland_teleporterAI : public ScriptedAI
    {
        npc_fireland_teleporterAI(Creature* c) : ScriptedAI(c)
        {
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->GetDistance(who) > 15.0f)
                return;

            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (who->ToPlayer()->GetQuestStatus(29201) == QUEST_STATUS_COMPLETE)
                who->ToPlayer()->TeleportTo(720, -551.815f, 320.05f, 115.489f, 5.94812f);
        }
    };
};


void AddSC_molten_front()
{
    new npc_pyrelord();
    new npc_ancient_charhound();
    new npc_druid_of_the_flame();
    new npc_subterranean_magma_worm();
    new npc_ancient_firelord();
    new npc_firehawk();
    new npc_bear_cub();
    new npc_squirrel();
    new npc_child_of_tortolla();
    new npc_alpine_songbird();
    new npc_forest_owl();
    new npc_goldwing_hawk();
    new npc_pyrachnis();
    new npc_tooga();
    new npc_nemesis();
    new npc_lylagar();
    new npc_millagazor();
    new npc_galenges();
    new npc_arch_druid_hamuul_runetotem();
    new npc_leyara();
    new npc_elderlimb();
    new npc_thisalee_crow();
    new npc_tholo_whitehoof();
    new npc_melfurion_stormrage();
    new npc_leyara2();
    new npc_molten_behemoth();
    new npc_rayne_feathersong();
    new npc_cinderweb_spinner2();
    new npc_Achievement_helper();
    new npc_fireside_chat();
    new npc_currency_required_quest_taker();
    new npc_flamewaker_shaman();
    new npc_flamewaker_shaman_helper();
    new npc_flamewaker_hunter();
    new npc_flamewaker_hunter_helper2();
    new npc_flamewaker_hunter_helper();
    new npc_flamewaker_sentinel();
    new npc_emberspit_scorpion();
    new npc_trained_firehawk();
    new npc_firehawk_helper();
    new go_ungoro_soil;
    new npc_little_lasher();
    new npc_hyjal_druid();
    new npc_flame_protection_rune();
    new npc_flame_protection_rune1();
    new go_solar_core;
    new npc_druid_of_the_flame_molten_front();
    new npc_cinderweb_cocoon();
    new npc_molten_front_vendor();
    new npc_fireland_teleporter();
}
