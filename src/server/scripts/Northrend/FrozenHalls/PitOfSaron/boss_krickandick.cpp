/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include "pit_of_saron.h"

/*
 * SDComment: Spell Explosive barrage is not working.
 */

enum Spells
{
    SPELL_PURSUED                               = 68987,
    SPELL_CONFUSION                             = 69029,
    SPELL_EXPLOSIVE_BARRAGE                     = 69263,
    SPELL_MIGHTY_KICK                           = 69021,
    SPELL_POISON_NOVA                           = 68989,
    H_SPELL_POISON_NOVA                         = 70434,
    SPELL_SHADOW_BOLT                           = 69028,
    SPELL_TOXIC_WASTE                           = 69024,
    H_SPELL_TOXIC_WASTE                         = 70436,
};

enum Yells
{
    // Krick
    SAY_KRICK_AGGRO                             = -1658010,
    SAY_KRICK_SLAY_1                            = -1658011,
    SAY_KRICK_SLAY_2                            = -1658012,
    SAY_KRICK_BARRAGE_1                         = -1658013,
    SAY_KRICK_BARRAGE_2                         = -1658014,
    SAY_KRICK_POISON_NOVA                       = -1658015,
    SAY_KRICK_CHASE_1                           = -1658016,
    SAY_KRICK_CHASE_2                           = -1658017,
    SAY_KRICK_CHASE_3                           = -1658018,

    // Ick
    SAY_ICK_POISON_NOVA                         = -1658020,
    SAY_ICK_CHASE_1                             = -1658021,

    // OUTRO
    SAY_KRICK_OUTRO_1                           = -1658030,
    SAY_JAYNA_OUTRO_2                           = -1658031,
    SAY_SYLVANAS_OUTRO_2                        = -1658032,
    SAY_KRICK_OUTRO_3                           = -1658033,
    SAY_JAYNA_OUTRO_4                           = -1658034,
    SAY_SYLVANAS_OUTRO_4                        = -1658035,
    SAY_KRICK_OUTRO_5                           = -1658036,
    SAY_TYRANNUS_OUTRO_7                        = -1658037,
    SAY_KRICK_OUTRO_8                           = -1658038,
    SAY_TYRANNUS_OUTRO_9                        = -1658039,
    SAY_JAYNA_OUTRO_10                          = -1658040,
    SAY_SYLVANAS_OUTRO_10                       = -1658041,
};

enum Events
{
    EVENT_NONE,
    EVENT_PURSUE,
    EVENT_MIGHTY_KICK,
    EVENT_POISON_NOVA,
    EVENT_EXPLOSIVE_BARRAGE,
    EVENT_END_EXPLOSIVE_BARRAGE,

    // Krick
    EVENT_SHADOW_BOLT,
    EVENT_TOXIC_WASTE,

    // Krick OUTRO
    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3,
    EVENT_OUTRO_4,
    EVENT_OUTRO_5,
    EVENT_OUTRO_6,
    EVENT_OUTRO_7,
    EVENT_OUTRO_8,
    EVENT_OUTRO_9,
    EVENT_OUTRO_10,
    EVENT_OUTRO_11,
    EVENT_OUTRO_12,
    EVENT_OUTRO_END,
};

enum KrickPhase
{
    PHASE_COMBAT,
    PHASE_OUTRO,
};

enum Actions
{
    ACTION_OUTRO,
};

enum Misc
{
    SEAT_KRICK = 0,

    // events GCD. Shall not be 0.
    GCD_1 = 1,
};

// Krick is the Gnome.
// Ick is the Mount
// Common Events are handled/triggered by Ick that "drive" Krick through DoAction.

class boss_ick : public CreatureScript
{
public:
    boss_ick() : CreatureScript("boss_ick") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_ickAI(pCreature);
    }

    struct boss_ickAI : public ScriptedAI
    {
        boss_ickAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;

        EventMap events;

        void Reset()
        {
            events.Reset();

            if (pInstance)
                pInstance->SetData(DATA_KRICKANDICK_EVENT, NOT_STARTED);
        }

        Creature* GetKrick()
        {
            return me->GetCreature(*me, pInstance ? pInstance->GetData64(DATA_KRICK) : 0);
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_KRICKANDICK_EVENT, IN_PROGRESS);

            Creature* pKrick = GetKrick();
            if (!pKrick)
                pKrick = me->SummonCreature(CREATURE_KRICK, *me, TEMPSUMMON_MANUAL_DESPAWN);

            if (pKrick)
                DoScriptText(SAY_KRICK_AGGRO, pKrick);

            events.ScheduleEvent(EVENT_MIGHTY_KICK, 20000, GCD_1);
            events.ScheduleEvent(EVENT_PURSUE, 30000, GCD_1);
            events.ScheduleEvent(EVENT_POISON_NOVA, 30000, GCD_1);
            events.ScheduleEvent(EVENT_EXPLOSIVE_BARRAGE, 35000);
            events.ScheduleEvent(EVENT_TOXIC_WASTE, 5000);
            events.ScheduleEvent(EVENT_SHADOW_BOLT, 15000);
        }

        void EnterEvadeMode()
        {
            me->GetMotionMaster()->Clear();
            ScriptedAI::EnterEvadeMode();
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (Creature* pKrick = GetKrick())
            {
                if (pKrick->AI())
                    pKrick->AI()->DoAction(ACTION_OUTRO);
            }

            if (pInstance)
                pInstance->SetData(DATA_KRICKANDICK_EVENT, DONE);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!me->isInCombat())
                return;

            if (!me->getVictim() && me->getThreatManager().isThreatListEmpty())
            {
                EnterEvadeMode();
                return;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            switch(events.ExecuteEvent())
            {
                case EVENT_PURSUE:
                    if (Creature* pKrick = GetKrick())
                        DoScriptText(RAND(SAY_KRICK_CHASE_1,SAY_KRICK_CHASE_2,SAY_KRICK_CHASE_3), pKrick);

                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                    {
                        me->Attack(pTarget,false);
                        DoScriptText(SAY_ICK_CHASE_1, me, pTarget);
                        DoCast(pTarget, SPELL_PURSUED);
                    }

                    DoCast(SPELL_CONFUSION);
                    events.ScheduleEvent(EVENT_PURSUE, 30000, GCD_1);
                    return;

                case EVENT_MIGHTY_KICK:
                    DoCast(me->getVictim(), SPELL_MIGHTY_KICK);
                    events.ScheduleEvent(EVENT_MIGHTY_KICK, 25000, GCD_1);
                    return;

                case EVENT_POISON_NOVA:
                    if (Creature* pKrick = GetKrick())
                        DoScriptText(SAY_KRICK_POISON_NOVA, pKrick);

                    DoScriptText(SAY_ICK_POISON_NOVA, me);
                    DoCastAOE(SPELL_POISON_NOVA);
                    events.ScheduleEvent(EVENT_POISON_NOVA, 30000, GCD_1);
                    return;

                case EVENT_TOXIC_WASTE:
                    DoCast(me->getVictim(), SPELL_TOXIC_WASTE);
                    events.ScheduleEvent(EVENT_TOXIC_WASTE, 5000);
                    return;

                case EVENT_SHADOW_BOLT:
                    DoCast(me->getVictim(), SPELL_SHADOW_BOLT);
                    events.ScheduleEvent(EVENT_SHADOW_BOLT, 15000);
                    return;

                case EVENT_EXPLOSIVE_BARRAGE:
                    if (Creature *pKrick = GetKrick())
                    {
                        DoScriptText(SAY_KRICK_BARRAGE_1, pKrick);
                        DoScriptText(SAY_KRICK_BARRAGE_2, pKrick);
                    }

                    DoCastAOE(SPELL_EXPLOSIVE_BARRAGE);
                    me->GetMotionMaster()->MoveIdle();
                    events.DelayEvents(20000, GCD_1); // 2 sec cast + 18 sec
                    events.ScheduleEvent(EVENT_END_EXPLOSIVE_BARRAGE, 20000);
                    return;

                case EVENT_END_EXPLOSIVE_BARRAGE:
                    me->GetMotionMaster()->Clear();
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                    events.ScheduleEvent(EVENT_EXPLOSIVE_BARRAGE, 25000);
                    break;
            }

            DoMeleeAttackIfReady();
        }
    };

};

class boss_krick : public CreatureScript
{
public:
    boss_krick() : CreatureScript("boss_krick") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_krickAI(pCreature);
    }

    struct boss_krickAI : public ScriptedAI
    {
        boss_krickAI(Creature *c) : ScriptedAI(c)
        {
            pInstance = c->GetInstanceScript();
        }

        InstanceScript* pInstance;
        EventMap events;

        KrickPhase  phase;
        uint64 uiNpcOutroDialog;
        uint64 uiTyrannus;

        void Reset()
        {
            uiNpcOutroDialog = 0;
            uiTyrannus = 0;
            phase = PHASE_COMBAT;

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetVisible(false);
        }

        Creature* GetIck()
        {
            return me->GetCreature(*me, pInstance ? pInstance->GetData64(DATA_ICK) : 0);
        }

        void KilledUnit(Unit * victim)
        {
            if (victim == me)
                return;

            DoScriptText(RAND(SAY_KRICK_SLAY_1,SAY_KRICK_SLAY_2), me);
        }

        void DamageTaken(Unit * /*pDoneBy*/, uint32 &uiDamage)
        {
            // if killed whatever the reason, it breaks the outro
            uiDamage = 0;
        }

        void DoAction(const int32 actionId)
        {
            switch(actionId)
            {
                case ACTION_OUTRO:
                {
                    Position pos;
                    if (Creature* pIck = GetIck())
                    {
                        // TODO: tele on Ick then run some distance.
                        pIck->GetNearPosition(pos, 5.0f, 3.14f);
                        me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 0.0f);
                    }
                    me->SetVisible(true);

                    Creature* pJainaOrSylvanas = me->GetCreature(*me, pInstance->GetData64(DATA_JAINA_SYLVANAS_1));
                    if (pJainaOrSylvanas) {
                        Position pos;
                        me->GetNearPosition(pos, 5.0f, 0);
                        pJainaOrSylvanas->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(),
                            pos.GetAngle(me->GetPositionX(), me->GetPositionY()));
                    }
                    else {
                        if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_ALLIANCE)
                            pJainaOrSylvanas = me->SummonCreature(NPC_SYLVANAS_PART1, *me, TEMPSUMMON_MANUAL_DESPAWN);
                        else
                            pJainaOrSylvanas = me->SummonCreature(NPC_JAINA_PART1, *me, TEMPSUMMON_MANUAL_DESPAWN);
                    }

                    if (pJainaOrSylvanas)
                    {
                        pJainaOrSylvanas->SetOrientation(pJainaOrSylvanas->GetAngle(me->GetPositionX(), me->GetPositionY()));
                        me->SetOrientation(me->GetAngle(pJainaOrSylvanas->GetPositionX(), pJainaOrSylvanas->GetPositionY()));
                        uiNpcOutroDialog = pJainaOrSylvanas->GetGUID();
                    }

                    phase = PHASE_OUTRO;
                    events.Reset();
                    events.ScheduleEvent(EVENT_OUTRO_1, 1000);
                    break;
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (phase == PHASE_OUTRO)
            {
                if (!pInstance)
                    return;

                events.Update(diff);
                switch(events.ExecuteEvent())
                {
                    case EVENT_OUTRO_1:
                    {
                        DoScriptText(SAY_KRICK_OUTRO_1, me);
                        events.ScheduleEvent(EVENT_OUTRO_2, 14000);
                        break;
                    }
                    case EVENT_OUTRO_2:
                    {
                        Creature* pNpcDialog = me->GetCreature(*me, uiNpcOutroDialog);
                        if (pNpcDialog)
                        {
                            if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_ALLIANCE)
                                DoScriptText(SAY_JAYNA_OUTRO_2, pNpcDialog);
                            else
                                DoScriptText(SAY_SYLVANAS_OUTRO_2, pNpcDialog);
                        }
                        events.ScheduleEvent(EVENT_OUTRO_3, 8500);
                        break;
                    }
                    case EVENT_OUTRO_3:
                        DoScriptText(SAY_KRICK_OUTRO_3, me);
                        events.ScheduleEvent(EVENT_OUTRO_4, 12000);
                        break;
                    case EVENT_OUTRO_4:
                    {
                        Creature* pNpcDialog = me->GetCreature(*me, uiNpcOutroDialog);
                        if (pNpcDialog)
                        {
                            if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_ALLIANCE)
                                DoScriptText(SAY_JAYNA_OUTRO_4, pNpcDialog);
                            else
                                DoScriptText(SAY_SYLVANAS_OUTRO_4, pNpcDialog);
                        }
                        events.ScheduleEvent(EVENT_OUTRO_5, 8000);
                        break;
                    }
                    case EVENT_OUTRO_5:
                        DoScriptText(SAY_KRICK_OUTRO_5, me);
                        events.ScheduleEvent(EVENT_OUTRO_6, 4000);
                        break;
                    case EVENT_OUTRO_6:
                        // TODO spawn Tyrannus at some distance and MovePoint near-by (flying on rimefang)
                        // store uiTyrannus
                        // Adjust timer so tyrannus has time to come
                        uiTyrannus = (pInstance ? pInstance->GetData64(DATA_TYRANNUS) : 0);
                        events.ScheduleEvent(EVENT_OUTRO_7, 1);
                        break;
                    case EVENT_OUTRO_7:
                        if (Creature *pTyrannus = me->GetCreature(*me, uiTyrannus))
                            DoScriptText(SAY_TYRANNUS_OUTRO_7, pTyrannus);
                        events.ScheduleEvent(EVENT_OUTRO_8, 7000);
                        break;
                    case EVENT_OUTRO_8:
                        DoScriptText(SAY_KRICK_OUTRO_8, me);
                        // TODO: Tyrannus starts killing Krick.
                        // there shall be some visual spell effect
                        events.ScheduleEvent(EVENT_OUTRO_9, 6000);
                        break;
                    case EVENT_OUTRO_9:
                        // tyrannus kills krick
                        me->SetStandState(UNIT_STAND_STATE_DEAD);
                        me->SetHealth(0);

                        if (Creature *pTyrannus = me->GetCreature(*me, uiTyrannus))
                            DoScriptText(SAY_TYRANNUS_OUTRO_9, pTyrannus);

                        events.ScheduleEvent(EVENT_OUTRO_10, 12000);
                        break;
                    case EVENT_OUTRO_10:
                    {
                        Creature* pNpcDialog = me->GetCreature(*me, uiNpcOutroDialog);
                        if (pNpcDialog)
                        {
                            if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_ALLIANCE)
                                DoScriptText(SAY_JAYNA_OUTRO_10, pNpcDialog);
                            else
                                DoScriptText(SAY_SYLVANAS_OUTRO_10, pNpcDialog);
                        }

                        // End of OUTRO. for now...
                        events.ScheduleEvent(EVENT_OUTRO_END, 8000);
                        break;
                    }
                    case EVENT_OUTRO_END:
                    {
                        Creature* pNpcDialog = me->GetCreature(*me, uiNpcOutroDialog);
                        if (pNpcDialog)
                            pNpcDialog->DisappearAndDie();

                        me->DisappearAndDie();
                        break;
                    }
                }
                return;
            }
        }
    };

};



void AddSC_boss_ick()
{
    new boss_ick();
    new boss_krick();
}
