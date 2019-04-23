/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * Copyright (C) 2008-2014 Forgotten Lands <http://www.forgottenlands.eu/>
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
SDName: boss_echo_of_tyrande
SD%Complete:
SDComment:
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "end_time.h"
#include "SpellAuraEffects.h"
#include "SpellInfo.h"
#include "MotionMaster.h"
#include "MovementPackets.h"
#include "MoveSplineInit.h"
#include <G3D/Vector3.h>

enum Spells
{
    // Tyrande
    SPELL_MOONBOLT                      = 102193,
    SPELL_STARDUST                      = 102173,
    SPELL_MOONLANCE                     = 102151,
    SPELL_LUNAR_GUIDANCE                = 102472,
    SPELL_TEARS_OF_ELUNE                = 102241,
    SPELL_TEARS_OF_ELUNE_AOE            = 102243,
    SPELL_DARK_MOONLIGHT                = 102414,
    SPELL_EYES_OF_THE_GODDESS           = 102181,

    // Misc
    SPELL_MOONLANCE_AOE                 = 102150,
    SPELL_MOONLANCE_FORK_SUMMON         = 102152,
    SPELL_PIERCING_GAZE_OF_ELUNE        = 102182,

};

enum Events
{
    EVENT_MOONBOLT                     = 1,
    EVENT_STARDUST,
    EVENT_MOONLANCE,
    EVENT_LUNAR_GUIDANCE,
    EVENT_TEARS_OF_ELUNE,
    EVENT_TEARS_OF_ELUNE_AOE,
    EVENT_EYES_OF_THE_GODDESS,

};

enum Misc
{
    NPC_TYRANDE_ENTRY                   = 54544,
    NPC_MOONLANCE_TRIPLE_FIRST          = 54580,
    NPC_MOONLANCE_TRIPLE_SECOND         = 54582,
    NPC_MOONLANCE_TRIPLE_THIRD          = 54581,
    NPC_EYES_OF_THE_GODDESS_FIRST       = 54594,
    NPC_EYES_OF_THE_GODDESS_SECOND      = 54597,
};

class boss_echo_of_tyrande : public CreatureScript
{
    public:
        boss_echo_of_tyrande() : CreatureScript("boss_echo_of_tyrande") { }

        struct boss_echo_of_tyrandeAI : public BossAI
        {
            boss_echo_of_tyrandeAI(Creature* creature) : BossAI(creature, DATA_TYRANDE), Summons(me)
            {
                instance = creature->GetInstanceScript();
                SetCombatMovement(false);
            }

            InstanceScript* instance;
            EventMap events;
            SummonList Summons;
            uint8 PhaseCount;

            void Reset() override
            {
                _Reset();
                events.Reset();

                Summons.DespawnAll();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();

                PhaseCount = 0;

                me->SetFacingToObject(me->GetVictim());

                events.ScheduleEvent(EVENT_MOONBOLT, 1000);
                events.ScheduleEvent(EVENT_STARDUST, 15000);
                events.ScheduleEvent(EVENT_MOONLANCE, 5000);
            }

            void InitializeAI() override
            {
                // ToDo:
                // Trash event!
                DoAction(ACTION_TYRANDE_START);
            }

            void KilledUnit(Unit* /*victim*/) override
            {
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                instance->SetData(DATA_BOSS_COUNT, 1);
            }

            void JustSummoned(Creature* summon) override
            {
                Summons.Summon(summon);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                case ACTION_TYRANDE_START:
                    me->setActive(true);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    break;
                }
            }

            void UpdateAI(uint32 diff) override

            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if ((me->HealthBelowPct(80) && PhaseCount == 0) || (me->HealthBelowPct(55) && PhaseCount == 1))
                {
                    events.Reset();
                    events.ScheduleEvent(EVENT_LUNAR_GUIDANCE, 1000);
                    events.ScheduleEvent(EVENT_EYES_OF_THE_GODDESS, 5000);
                    PhaseCount++;
                }

                if (me->HealthBelowPct(30) && PhaseCount == 2)
                {
                    events.Reset();
                    events.ScheduleEvent(EVENT_TEARS_OF_ELUNE, 1000);
                    PhaseCount++;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                    case EVENT_MOONBOLT:
                        DoCastVictim(SPELL_MOONBOLT);
                        events.ScheduleEvent(EVENT_MOONBOLT, urand(1000, 3000));
                        break;
                    case EVENT_STARDUST:
                    {
                        ThreatContainer::StorageType threatlist = me->getThreatManager().getThreatList();
                        for (ThreatContainer::StorageType::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
                        {
                            if (Unit* unit = ObjectAccessor::GetUnit(*me, (*itr)->getUnitGuid()))
                                if (unit->IsPlayer())
                                    me->CastSpell(unit, SPELL_STARDUST, false);
                        }
                        events.ScheduleEvent(EVENT_STARDUST, urand(8000, 12000));
                        break;
                    }
                    case EVENT_MOONLANCE:
                        if (SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
                        {
                            DoCastAOE(SPELL_MOONLANCE);
                            events.ScheduleEvent(EVENT_MOONLANCE, urand(4000, 8000));
                        }
                        break;
                    case EVENT_LUNAR_GUIDANCE:
                        DoCastAOE(SPELL_LUNAR_GUIDANCE);
                        events.ScheduleEvent(EVENT_MOONBOLT, urand(1000, 3000));
                        events.ScheduleEvent(EVENT_STARDUST, urand(8000, 12000));
                        events.ScheduleEvent(EVENT_MOONLANCE, urand(9000, 12000));
                        break;
                    case EVENT_TEARS_OF_ELUNE:
                        DoCastAOE(SPELL_TEARS_OF_ELUNE);
                        events.ScheduleEvent(EVENT_TEARS_OF_ELUNE_AOE, 500);
                        events.ScheduleEvent(EVENT_MOONBOLT, urand(1000, 3000));
                        events.ScheduleEvent(EVENT_STARDUST, urand(8000, 12000));
                        events.ScheduleEvent(EVENT_MOONLANCE, urand(9000, 12000));
                        break;
                    case EVENT_TEARS_OF_ELUNE_AOE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_TEARS_OF_ELUNE_AOE, true);
                        events.ScheduleEvent(EVENT_TEARS_OF_ELUNE_AOE, 500);
                    case EVENT_EYES_OF_THE_GODDESS:
                        if (PhaseCount > 2)
                            return;
                        DoCastAOE(SPELL_EYES_OF_THE_GODDESS);
                        events.ScheduleEvent(EVENT_EYES_OF_THE_GODDESS, 22000);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_echo_of_tyrandeAI(creature);
        }
};

class npc_moonlance_single : public CreatureScript
{
    public:
        npc_moonlance_single() : CreatureScript("npc_moonlance_single") { }

        struct npc_moonlance_singleAI : public ScriptedAI
        {
            npc_moonlance_singleAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            void Reset() override
            {
                me->SetSpeed(MOVE_RUN, 1.5f);
                me->CastSpell(me, SPELL_MOONLANCE_AOE, true);
                if (Creature* tyrande = GetClosestCreatureWithEntry(me, NPC_TYRANDE_ENTRY, 75.0f))
                {
                    if (Unit* target = tyrande->AI()->SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
                    {
                        float targetPosX = tyrande->GetPositionX();
                        float targetPosY = tyrande->GetPositionY();
                        float targetPosZ = tyrande->GetPositionZ();
                        me->SetFacingToObject(target);
                        float targetOrie = tyrande->GetOrientation();

                        float dist = 100.0f;
                        me->GetMotionMaster()->Clear();
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->MovePoint(0, targetPosX + dist * cos(targetOrie), targetPosY + dist * sin(targetOrie), targetPosZ);
                    }
                }

                if (AuraEffect* aurEff = me->GetAuraEffect(102150, EFFECT_0))
                    aurEff->SetPeriodicTimer(1000);
            }

            void JustSummoned(Creature* summon) override
            {
                uint32 count = 0;
                switch (summon->GetEntry())
                {
                    case NPC_MOONLANCE_TRIPLE_FIRST:
                        count = 0;
                        break;
                    case NPC_MOONLANCE_TRIPLE_SECOND:
                        count = 1;
                        break;
                    case NPC_MOONLANCE_TRIPLE_THIRD:
                        count = 2;
                        break;
                    default:
                        break;
                }

                me->SetSpeed(MOVE_RUN, 1.5f);
                summon->SetReactState(REACT_PASSIVE);
                summon->CastSpell(summon, SPELL_MOONLANCE_AOE, true);
                if (AuraEffect* aurEff = summon->GetAuraEffect(102150, EFFECT_0))
                    aurEff->SetPeriodicTimer(1000);
                float dir =(me->GetOrientation() - (0.52f) + count * (0.52f));
                if (dir >6.28f)
                    dir-=6.28f;
                summon->GetMotionMaster()->MovePoint(0, me->GetPositionX() + 120  * cos(dir), me->GetPositionY() + 120  * sin(dir), me->GetPositionZ());
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (Creature* tyrande = GetClosestCreatureWithEntry(me, NPC_TYRANDE_ENTRY, 75.0f))
                {
                    if (me->GetDistance2d(tyrande) > 10.0f)
                    {
                        DoCast(SPELL_MOONLANCE_FORK_SUMMON);
                        me->DespawnOrUnsummon();
                    }
                }
            }

            private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetEndTimelAI<npc_moonlance_singleAI>(creature);
        }
};

class npc_eye_of_the_goddess : public CreatureScript
{
    public:
        npc_eye_of_the_goddess() : CreatureScript("npc_eye_of_the_goddess") { }

        struct npc_eye_of_the_goddessAI : public ScriptedAI
        {
            npc_eye_of_the_goddessAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
            }

            bool rotationStart;

            void FillCirclePath(Position const& centerPos, float radius, float z, Movement::PointsArray& path, bool clockwise)
            {
                float step = clockwise ? -M_PI / 8.0f : M_PI / 8.0f;
                float angle = centerPos.GetAngle(me->GetPositionX(), me->GetPositionY());

                for (uint8 i = 0; i < 16; angle += step, ++i)
                {
                    G3D::Vector3 point;
                    point.x = centerPos.GetPositionX() + radius * cosf(angle);
                    point.y = centerPos.GetPositionY() + radius * sinf(angle);
                    point.z = z; // Don't use any height getters unless all bugs are fixed.
                    path.push_back(point);
                }
            }

            void InitializeAI() override
            {
                rotationStart = false;

                me->GetMotionMaster()->Clear();
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_PASSIVE);

                if (me->GetEntry() == NPC_EYES_OF_THE_GODDESS_FIRST)
                    me->GetMotionMaster()->MoveCharge(2839.03f, 28.3f, me->GetPositionZ(), 5.5f);

                if (me->GetEntry() == NPC_EYES_OF_THE_GODDESS_SECOND)
                    me->GetMotionMaster()->MoveCharge(2819.51f, 79.67f, me->GetPositionZ(), 5.5f);

                DoCastAOE(SPELL_PIERCING_GAZE_OF_ELUNE);
                if (Aura* aur = me->GetAura(SPELL_PIERCING_GAZE_OF_ELUNE))
                    aur->SetDuration(25000);
            }

            void UpdateAI(uint32 /*diff*/) override
            {
                if (Creature* tyrande = GetClosestCreatureWithEntry(me, NPC_TYRANDE_ENTRY, 75.0f))
                {
                    if (me->GetDistance2d(tyrande) > 20.0f && !rotationStart)
                    {
                        Position pos = tyrande->GetPosition();
                        rotationStart = true;
                        me->GetMotionMaster()->Clear();

                        Movement::MoveSplineInit init(me);
                        FillCirclePath(pos, 20.0f, me->GetPositionZ() + 0.1f, init.Path(), true);
                        init.SetFly();
                        init.SetCyclic();
                        init.SetVelocity(8.5f);
                        init.Launch();
                    }
                }
            }

            private:
            InstanceScript* _instance;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetEndTimelAI<npc_eye_of_the_goddessAI>(creature);
        }
};

void AddSC_boss_echo_of_tyrande()
{
    new boss_echo_of_tyrande();
    new npc_moonlance_single();
    new npc_eye_of_the_goddess();
}
