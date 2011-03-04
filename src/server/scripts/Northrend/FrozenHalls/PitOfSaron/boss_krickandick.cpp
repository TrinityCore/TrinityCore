/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

enum Spells
{
        SPELL_PURSUIT                   = 68987,
        SPELL_EXPLOSIVE_BARRAGE         = 69263,                    // Boss Channel Cast von Explosives Sperrfeuer - hält 18 Sek.
        SPELL_EXPLOSIVE_BARRAGE_TRIGGER = 69015,                    // Spawnt NPC 36610 - Explodierende Kugel
        SPELL_EXPLOSIVE_BARRAGE_VISUAL  = 69017,                    // Explodierende Kugel Visual
#define SPELL_EXPLOSIVE_BARRAGE_DAMAGE  DUNGEON_MODE(69019,70433)   // Explosion der Explodierenden Kugel
        SPELL_MIGHTY_KICK               = 69021,
#define SPELL_POISON_NOVA               DUNGEON_MODE(68989,70434)
        SPELL_SHADOW_BOLT               = 69028
#define SPELL_TOXIC_WASTE               DUNGEON_MODE(69024,70436)
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
    SAY_SYLVANAS_OUTRO_10                       = -1658041
};

enum Events
{
    EVENT_NONE,
    EVENT_PURSUIT_CAST,
    EVENT_PURSUIT_RUN,
    EVENT_PURSUIT_STOP,
    EVENT_MIGHTY_KICK,
    EVENT_POISON_NOVA,
    EVENT_EXPLOSIVE_BARRAGE,
    EVENT_EXPLOSIVE_BARRAGE_TRIGGER,
    EVENT_EXPLOSIVE_BARRAGE_GROW,
    EVENT_EXPLOSIVE_BARRAGE_DAMAGE,
    EVENT_EXPLOSIVE_BARRAGE_END,

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
    EVENT_OUTRO_END
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
    SEAT_KRICK = 0
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
            PursuitTarget = NULL;
            pKrick = NULL;
            FirstTime = true;
        }

        InstanceScript* pInstance;
        EventMap events;
        EventMap eventsT;
        Unit* PursuitTarget;
        Creature* pKrick;
        bool InPursuit,
            FirstTime;

        void Reset()
        {
            events.Reset();
            eventsT.Reset();

            if (pInstance)
            {
                if (!pKrick)
                {
                    Position pos;
                    me->GetNearPosition(pos, 5, 360);
                    if (pKrick = me->SummonCreature(CREATURE_KRICK, pos, TEMPSUMMON_MANUAL_DESPAWN))
                        pInstance->SetData64(DATA_KRICK, pKrick->GetGUID());
                }
                else if (!FirstTime)
                {
                    pKrick->ExitVehicle();
                    pKrick->JumpTo(2,2);
                    pKrick->AI()->EnterEvadeMode();
                }

                if (FirstTime)
                    pInstance->SetData(DATA_KRICKANDICK_EVENT, NOT_STARTED);
                else
                    pInstance->SetData(DATA_KRICKANDICK_EVENT, FAIL);
            }
            InPursuit = false;
            FirstTime = false;
        }

        Creature* GetKrick()
        {
            return me->GetCreature(*me, pInstance ? pInstance->GetData64(DATA_KRICK) : 0);
        }

        void EnterCombat(Unit * /*who*/)
        {
            if (pInstance)
                pInstance->SetData(DATA_KRICKANDICK_EVENT, IN_PROGRESS);

            if (pKrick)
            {
                pKrick->EnterVehicle(me);
                DoScriptText(SAY_KRICK_AGGRO, pKrick);
            }
            events.ScheduleEvent(EVENT_MIGHTY_KICK, 5000);
            events.ScheduleEvent(EVENT_PURSUIT_CAST, 35000);
            events.ScheduleEvent(EVENT_POISON_NOVA, 25000);
            events.ScheduleEvent(EVENT_EXPLOSIVE_BARRAGE, 10000);
            events.ScheduleEvent(EVENT_TOXIC_WASTE, 100);
            events.ScheduleEvent(EVENT_SHADOW_BOLT, 5000);
        }

        void JustDied(Unit* /*pKiller*/)
        {
            if (pKrick)
            {
                pKrick->ExitVehicle();
                pKrick->JumpTo(2,2);

                if (pKrick->AI())
                    pKrick->AI()->DoAction(ACTION_OUTRO);
            }

            if (pInstance)
                pInstance->SetData(DATA_KRICKANDICK_EVENT, DONE);
        }

        void DoCreateTriggerOnEveryPlayer() // Workaround für nicht existierenden Triggerspell 69357
        {
            if (pInstance)
            {
                Map::PlayerList const &pl = pInstance->instance->GetPlayers();
                if (!pl.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = pl.begin(); itr != pl.end(); ++itr)
                    {
                        Player *member = itr->getSource();
    
                        if (!member || !member->isAlive() || member->isGameMaster() || !member->isGMVisible())
                            continue;

                        member->CastSpell(member, SPELL_EXPLOSIVE_BARRAGE_TRIGGER, true);
                    }
                }
            }
        }

        void DoRemoveToMuchArrowsOnPlayers(Unit *realTarget) // Workaround für Pfeile auf allen Spielern (durch SPELL_PURSUIT)
        {
            if (pInstance && realTarget)
            {
                Map::PlayerList const &pl = pInstance->instance->GetPlayers();
                if (!pl.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = pl.begin(); itr != pl.end(); ++itr)
                    {
                        Player *member = itr->getSource();
    
                        if (!member || !member->isAlive() || member->GetGUID() == realTarget->GetGUID())
                            continue;

                        member->RemoveAurasDueToSpell(SPELL_PURSUIT);
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);
            eventsT.Update(diff);

            if (me->HasAura(SPELL_EXPLOSIVE_BARRAGE))
            {
                switch(eventsT.ExecuteEvent())
                {
                    case EVENT_EXPLOSIVE_BARRAGE_TRIGGER:
                        DoCreateTriggerOnEveryPlayer();
                        eventsT.RescheduleEvent(EVENT_EXPLOSIVE_BARRAGE_TRIGGER, 3000);
                        break;
                }
            }

            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            switch(events.ExecuteEvent())
            {
                case EVENT_PURSUIT_CAST:
                    if (pKrick = GetKrick())
                        DoScriptText(RAND(SAY_KRICK_CHASE_1,SAY_KRICK_CHASE_2,SAY_KRICK_CHASE_3), pKrick);
                    me->GetMotionMaster()->MoveIdle();
                    DoCast(me, SPELL_PURSUIT); // Castzeit 5 Sek. - hält 12 Sek. an.
                    InPursuit = true;
                    events.RescheduleEvent(EVENT_PURSUIT_CAST, 60000);
                    events.ScheduleEvent(EVENT_PURSUIT_RUN, 5000);
                    break;
                case EVENT_PURSUIT_RUN:
                    if (PursuitTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true, SPELL_PURSUIT))
                    {
                        DoRemoveToMuchArrowsOnPlayers(PursuitTarget);
                        DoScriptText(SAY_ICK_CHASE_1, me, PursuitTarget);
                        if (SpellEntry const *SpE = sSpellStore.LookupEntry(SPELL_PURSUIT))
                        {
                            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_THREAT|SPELL_EFFECT_THREAT_ALL|SPELL_EFFECT_REDIRECT_THREAT|SPELL_EFFECT_PULL|
                                SPELL_EFFECT_FORCE_DESELECT|SPELL_EFFECT_KNOCK_BACK|SPELL_EFFECT_PULL_TOWARDS, true);
                            DoResetThreat();
                            me->AddThreat(PursuitTarget, 10000000, SPELL_SCHOOL_MASK_NORMAL, SpE);
                            me->GetMotionMaster()->MoveChase(PursuitTarget);
                            me->Attack(PursuitTarget, true);
                            events.CancelEvent(EVENT_PURSUIT_RUN);
                            events.ScheduleEvent(EVENT_PURSUIT_STOP, 12000);
                        }
                    }
                    break;
                case EVENT_PURSUIT_STOP:
                    DoResetThreat();
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_THREAT|SPELL_EFFECT_THREAT_ALL|SPELL_EFFECT_REDIRECT_THREAT|SPELL_EFFECT_PULL|
                        SPELL_EFFECT_FORCE_DESELECT|SPELL_EFFECT_KNOCK_BACK|SPELL_EFFECT_PULL_TOWARDS, false);
                    PursuitTarget = NULL;
                    InPursuit = false;
                    events.CancelEvent(EVENT_PURSUIT_STOP);
                    break;
                case EVENT_MIGHTY_KICK:
                    if (InPursuit)
                    {
                        events.RescheduleEvent(EVENT_MIGHTY_KICK, urand(10000,15000));
                        break;
                    }
                    DoCastVictim(SPELL_MIGHTY_KICK);
                    events.RescheduleEvent(EVENT_MIGHTY_KICK, urand(10000,20000));
                    break;
                case EVENT_POISON_NOVA:
                    if (InPursuit)
                    {
                        events.RescheduleEvent(EVENT_POISON_NOVA, 1000);
                        break;
                    }
                    if (pKrick = GetKrick())
                        DoScriptText(SAY_KRICK_POISON_NOVA, pKrick);
                    DoScriptText(SAY_ICK_POISON_NOVA, me);
                    DoCastAOE(SPELL_POISON_NOVA);
                    events.RescheduleEvent(EVENT_POISON_NOVA, 35000);
                    break;
                case EVENT_TOXIC_WASTE:
                    if (InPursuit)
                    {
                        events.RescheduleEvent(EVENT_TOXIC_WASTE, 1000);
                        break;
                    }
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        DoCast(pTarget, SPELL_TOXIC_WASTE);
                    events.RescheduleEvent(EVENT_TOXIC_WASTE, urand(5000,10000));
                    break;
                case EVENT_SHADOW_BOLT:
                    if (InPursuit)
                    {
                        events.RescheduleEvent(EVENT_SHADOW_BOLT, 1000);
                        break;
                    }
                    DoCastVictim(SPELL_SHADOW_BOLT);
                    events.RescheduleEvent(EVENT_SHADOW_BOLT, urand(5000,15000));
                    break;
                case EVENT_EXPLOSIVE_BARRAGE:
                    if (InPursuit)
                    {
                        events.RescheduleEvent(EVENT_EXPLOSIVE_BARRAGE, 1000);
                        break;
                    }
                    if (Creature *pKrick = GetKrick())
                    {
                        DoScriptText(SAY_KRICK_BARRAGE_1, pKrick);
                        DoScriptText(SAY_KRICK_BARRAGE_2, pKrick);
                    }
                    me->GetMotionMaster()->MoveIdle();
                    DoCast(me, SPELL_EXPLOSIVE_BARRAGE);
                    events.RescheduleEvent(EVENT_EXPLOSIVE_BARRAGE, 60000);
                    eventsT.ScheduleEvent(EVENT_EXPLOSIVE_BARRAGE_TRIGGER, 2000);
                    events.ScheduleEvent(EVENT_EXPLOSIVE_BARRAGE_END, 20000);
                    break;
                case EVENT_EXPLOSIVE_BARRAGE_END:
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                    eventsT.CancelEvent(EVENT_EXPLOSIVE_BARRAGE_TRIGGER);
                    events.CancelEvent(EVENT_EXPLOSIVE_BARRAGE_END);
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

        KrickPhase phase;
        uint64 uiNpcOutroDialog;
        uint64 uiTyrannus;

        void Reset()
        {
            uiNpcOutroDialog = 0;
            uiTyrannus = 0;
            phase = PHASE_COMBAT;

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
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
                        pIck->GetNearPosition(pos, 5.0f, 3.14f);
                        me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 0.0f);
                    }

                    Creature* pJainaOrSylvanas = me->GetMap()->GetCreature(pInstance->GetData64(DATA_JAINA_SYLVANAS_1));
                    if (pJainaOrSylvanas)
                    {
                        Position pos;
                        me->GetNearPosition(pos, 5.0f, 0);
                        pJainaOrSylvanas->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(),
                            pos.GetAngle(me->GetPositionX(), me->GetPositionY()));

                        if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_NEUTRAL)
                        {
                            Position pos;
                            pJainaOrSylvanas->GetNearPosition(pos, 2, 0);

                            if (pJainaOrSylvanas->GetEntry() == NPC_SYLVANAS_PART1)
                                pJainaOrSylvanas->SummonCreature(NPC_JAINA_PART1, pos);
                            else
                                pJainaOrSylvanas->SummonCreature(NPC_SYLVANAS_PART1, pos);
                        }
                    }
                    else
                    {
                        if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_HORDE)
                            pJainaOrSylvanas = me->SummonCreature(NPC_SYLVANAS_PART1, *me, TEMPSUMMON_MANUAL_DESPAWN);
                        else if (pInstance->GetData(DATA_TEAM_IN_INSTANCE) == TEAM_ALLIANCE)
                            pJainaOrSylvanas = me->SummonCreature(NPC_JAINA_PART1, *me, TEMPSUMMON_MANUAL_DESPAWN);
                        else
                        {
                            Position pos;
                            me->GetNearPosition(pos, 5, 360);
                            pJainaOrSylvanas = me->SummonCreature(NPC_JAINA_PART1, pos, TEMPSUMMON_MANUAL_DESPAWN);
                            if (pJainaOrSylvanas)
                            {
                                pJainaOrSylvanas->GetNearPosition(pos, 5, 360);
                                pJainaOrSylvanas->SummonCreature(NPC_SYLVANAS_PART1, pos);
                            }
                        }
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

                TeamId team = TeamId(pInstance->GetData(DATA_TEAM_IN_INSTANCE));

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
                        Creature* pNpcDialog = me->GetMap()->GetCreature(uiNpcOutroDialog);
                        if (pNpcDialog)
                        {
                            if (team == TEAM_ALLIANCE)
                                DoScriptText(SAY_JAYNA_OUTRO_2, pNpcDialog);
                            else if (team == TEAM_HORDE)
                                DoScriptText(SAY_SYLVANAS_OUTRO_2, pNpcDialog);
                            else
                            {
                                DoScriptText(SAY_JAYNA_OUTRO_2, pNpcDialog);
                                DoScriptText(SAY_SYLVANAS_OUTRO_2, pNpcDialog);
                            }
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
                        Creature* pNpcDialog = me->GetMap()->GetCreature(uiNpcOutroDialog);
                        if (pNpcDialog)
                        {
                            if (team == TEAM_ALLIANCE)
                                DoScriptText(SAY_JAYNA_OUTRO_4, pNpcDialog);
                            else if (team == TEAM_HORDE)
                                DoScriptText(SAY_SYLVANAS_OUTRO_4, pNpcDialog);
                            else
                            {
                                DoScriptText(SAY_JAYNA_OUTRO_4, pNpcDialog);
                                DoScriptText(SAY_SYLVANAS_OUTRO_4, pNpcDialog);
                            }
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
                        if (Creature *pTyrannus = me->GetMap()->GetCreature(uiTyrannus))
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

                        if (Creature *pTyrannus = me->GetMap()->GetCreature(uiTyrannus))
                            DoScriptText(SAY_TYRANNUS_OUTRO_9, pTyrannus);

                        events.ScheduleEvent(EVENT_OUTRO_10, 12000);
                        break;
                    case EVENT_OUTRO_10:
                    {
                        Creature* pNpcDialog = me->GetMap()->GetCreature(uiNpcOutroDialog);
                        if (pNpcDialog)
                        {
                            if (team == TEAM_ALLIANCE)
                                DoScriptText(SAY_JAYNA_OUTRO_10, pNpcDialog);
                            else if (team == TEAM_HORDE)
                                DoScriptText(SAY_SYLVANAS_OUTRO_10, pNpcDialog);
                            else
                            {
                                DoScriptText(SAY_JAYNA_OUTRO_10, pNpcDialog);
                                DoScriptText(SAY_SYLVANAS_OUTRO_10, pNpcDialog);
                            }
                        }

                        // End of OUTRO. for now...
                        events.ScheduleEvent(EVENT_OUTRO_END, 8000);
                        break;
                    }
                    case EVENT_OUTRO_END:
                    {
                        Creature* pNpcDialog = me->GetMap()->GetCreature(uiNpcOutroDialog);
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

class mob_explodierende_kugel_ick : public CreatureScript
{
public:
    mob_explodierende_kugel_ick() : CreatureScript("mob_explodierende_kugel_ick") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_explodierende_kugel_ickAI(pCreature);
    }

    struct mob_explodierende_kugel_ickAI: public ScriptedAI
    {
        mob_explodierende_kugel_ickAI(Creature *c) : ScriptedAI(c)
        {
            c->GetMotionMaster()->MoveIdle();
            c->SetDisplayId(11686);
            uiGrowCnt = 0;
            fScale = 0;
        }

        EventMap events;
        uint8 uiGrowCnt;
        float fScale;

        void Reset()
        {
            DoCast(me, SPELL_EXPLOSIVE_BARRAGE_VISUAL);

            events.Reset();
            events.ScheduleEvent(EVENT_EXPLOSIVE_BARRAGE_GROW, 2000);

            if (CreatureInfo const * CrI = me->GetCreatureInfo())
                fScale = CrI->scale;
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_EXPLOSIVE_BARRAGE_GROW:
                        if (fScale)
                        {
                            ++uiGrowCnt;
                            fScale+=0.4f;
                            me->SetFloatValue(OBJECT_FIELD_SCALE_X, fScale);
                            events.RescheduleEvent(EVENT_EXPLOSIVE_BARRAGE_GROW, 2000);
                        }
                        if (uiGrowCnt == 3)
                        {
                            events.ScheduleEvent(EVENT_EXPLOSIVE_BARRAGE_DAMAGE, 500);
                            events.CancelEvent(EVENT_EXPLOSIVE_BARRAGE_GROW);
                        }
                        break;
                    case EVENT_EXPLOSIVE_BARRAGE_DAMAGE:
                        DoCast(me, SPELL_EXPLOSIVE_BARRAGE_DAMAGE, true);
                        me->RemoveAurasDueToSpell(SPELL_EXPLOSIVE_BARRAGE_VISUAL);
                        events.CancelEvent(EVENT_EXPLOSIVE_BARRAGE_DAMAGE);
                        break;
                }
            }
        }
    };
};

void AddSC_boss_ick()
{
    new boss_ick();
    new boss_krick();
    new mob_explodierende_kugel_ick();
}
