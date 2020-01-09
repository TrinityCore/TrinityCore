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
SDName: boss_Akilzon
SD%Complete: 75%
SDComment: Missing timer for Call Lightning and Sound ID's
SQLUpdate:
#Temporary fix for Soaring Eagles

EndScriptData */

#include "ScriptMgr.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "Weather.h"
#include "zulaman.h"

enum Spells
{
    SPELL_STATIC_DISRUPTION     = 43622,
    SPELL_STATIC_VISUAL         = 45265,
    SPELL_CALL_LIGHTNING        = 43661, // Missing timer
    SPELL_GUST_OF_WIND          = 43621,
    SPELL_ELECTRICAL_STORM      = 43648,
    SPELL_BERSERK               = 45078,
    SPELL_ELECTRICAL_OVERLOAD   = 43658,
    SPELL_EAGLE_SWOOP           = 44732,
    SPELL_ZAP                   = 43137,
    SPELL_SAND_STORM            = 25160
};

enum Says
{
    SAY_AGGRO                   = 0,
    SAY_SUMMON                  = 1,
    SAY_INTRO                   = 2, // Not used in script
    SAY_ENRAGE                  = 3,
    SAY_KILL                    = 4,
    SAY_DEATH                   = 5
};

enum Misc
{
    NPC_SOARING_EAGLE           = 24858,
    SE_LOC_X_MAX                = 400,
    SE_LOC_X_MIN                = 335,
    SE_LOC_Y_MAX                = 1435,
    SE_LOC_Y_MIN                = 1370
};

enum Events
{
    EVENT_STATIC_DISRUPTION     = 1,
    EVENT_GUST_OF_WIND          = 2,
    EVENT_CALL_LIGHTNING        = 3,
    EVENT_ELECTRICAL_STORM      = 4,
    EVENT_RAIN                  = 5,
    EVENT_SUMMON_EAGLES         = 6,
    EVENT_STORM_SEQUENCE        = 7,
    EVENT_ENRAGE                = 8
};

class boss_akilzon : public CreatureScript
{
    public:
        boss_akilzon() : CreatureScript("boss_akilzon") { }

        struct boss_akilzonAI : public BossAI
        {
            boss_akilzonAI(Creature* creature) : BossAI(creature, BOSS_AKILZON)
            {
                Initialize();
            }

            void Initialize()
            {
                TargetGUID.Clear();
                CloudGUID.Clear();
                CycloneGUID.Clear();
                for (ObjectGuid& guid : BirdGUIDs)
                    guid.Clear();

                StormCount = 0;
                isRaining = false;
            }

            void Reset() override
            {
                _Reset();

                Initialize();

                SetWeather(WEATHER_STATE_FINE, 0.0f);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                _JustEngagedWith();

                events.ScheduleEvent(EVENT_STATIC_DISRUPTION, 10s, 20s); // 10 to 20 seconds (bosskillers)
                events.ScheduleEvent(EVENT_GUST_OF_WIND, 20s, 30s);      // 20 to 30 seconds(bosskillers)
                events.ScheduleEvent(EVENT_CALL_LIGHTNING, 10s, 20s);    // totaly random timer. can't find any info on this
                events.ScheduleEvent(EVENT_ELECTRICAL_STORM, 1min);                // 60 seconds(bosskillers)
                events.ScheduleEvent(EVENT_RAIN, 47s, 52s);
                events.ScheduleEvent(EVENT_ENRAGE, 10*MINUTE*IN_MILLISECONDS);      // 10 minutes till enrage(bosskillers)

                Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                _JustDied();
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void SetWeather(WeatherState weather, float grade)
            {
                Map* map = me->GetMap();
                if (!map->IsDungeon())
                    return;

                map->SendToPlayers(WorldPackets::Misc::Weather(weather, grade).Write());
            }

            void HandleStormSequence(Unit* Cloud) // 1: begin, 2-9: tick, 10: end
            {
                if (StormCount < 10 && StormCount > 1)
                {
                    // deal damage
                    int32 bp0 = 800;
                    for (uint8 i = 2; i < StormCount; ++i)
                        bp0 *= 2;

                    std::list<Unit*> tempUnitMap;
                    Trinity::AnyAoETargetUnitInObjectRangeCheck u_check(me, me, SIZE_OF_GRIDS);
                    Trinity::UnitListSearcher<Trinity::AnyAoETargetUnitInObjectRangeCheck> searcher(me, tempUnitMap, u_check);
                    Cell::VisitAllObjects(me, searcher, SIZE_OF_GRIDS);

                    // deal damage
                    for (std::list<Unit*>::const_iterator i = tempUnitMap.begin(); i != tempUnitMap.end(); ++i)
                    {
                        if (Unit* target = (*i))
                        {
                            if (Cloud && !Cloud->IsWithinDist(target, 6, false))
                            {
                                CastSpellExtraArgs args;
                                args.TriggerFlags = TRIGGERED_FULL_MASK;
                                args.OriginalCaster = me->GetGUID();
                                args.AddSpellMod(SPELLVALUE_BASE_POINT0, bp0);
                                Cloud->CastSpell(target, SPELL_ZAP, args);
                            }
                        }
                    }

                    // visual
                    float x, y, z;
                    z = me->GetPositionZ();
                    uint8 maxCount = 5 + rand32() % 5;
                    for (uint8 i = 0; i < maxCount; ++i)
                    {
                        x = 343.0f + rand32() % 60;
                        y = 1380.0f + rand32() % 60;
                        if (Unit* trigger = me->SummonTrigger(x, y, z, 0, 2000))
                        {
                            trigger->SetFaction(FACTION_FRIENDLY);
                            trigger->SetMaxHealth(100000);
                            trigger->SetHealth(100000);
                            trigger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            if (Cloud)
                            {
                                CastSpellExtraArgs args;
                                args.TriggerFlags = TRIGGERED_FULL_MASK;
                                args.OriginalCaster = Cloud->GetGUID();
                                args.AddSpellMod(SPELLVALUE_BASE_POINT0, bp0);
                                Cloud->CastSpell(trigger, SPELL_ZAP, args);
                            }
                        }
                    }
                }

                ++StormCount;

                if (StormCount > 10)
                {
                    StormCount = 0; // finish
                    events.ScheduleEvent(EVENT_SUMMON_EAGLES, 5s);
                    me->InterruptNonMeleeSpells(false);
                    CloudGUID.Clear();
                    if (Cloud)
                        Cloud->KillSelf();
                    SetWeather(WEATHER_STATE_FINE, 0.0f);
                    isRaining = false;
                }
                events.ScheduleEvent(EVENT_STORM_SEQUENCE, 1s);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STATIC_DISRUPTION:
                            {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                            if (!target)
                                target = me->GetVictim();
                            if (target)
                            {
                                TargetGUID = target->GetGUID();
                                DoCast(target, SPELL_STATIC_DISRUPTION, false);
                            }
                            /*if (float dist = me->IsWithinDist3d(target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 5.0f) dist = 5.0f;
                            SDisruptAOEVisual_Timer = 1000 + floor(dist / 30 * 1000.0f);*/
                            events.ScheduleEvent(EVENT_STATIC_DISRUPTION, 10s, 18s);
                            break;
                            }
                        case EVENT_GUST_OF_WIND:
                            {
                                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1);
                                if (!target)
                                    target = me->GetVictim();
                                if (target)
                                    DoCast(target, SPELL_GUST_OF_WIND);
                                events.ScheduleEvent(EVENT_GUST_OF_WIND, 20s, 30s);
                                break;
                            }
                        case EVENT_CALL_LIGHTNING:
                            DoCastVictim(SPELL_CALL_LIGHTNING);
                            events.ScheduleEvent(EVENT_CALL_LIGHTNING, 12s, 17s); // totaly random timer. can't find any info on this
                            break;
                        case EVENT_ELECTRICAL_STORM:
                            {
                                Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50, true);
                                if (!target)
                                {
                                    EnterEvadeMode();
                                    return;
                                }
                                target->CastSpell(target, 44007, true); // cloud visual
                                DoCast(target, SPELL_ELECTRICAL_STORM, false); // storm cyclon + visual
                                float x, y, z;
                                target->GetPosition(x, y, z);
                                /// @todo: fix it in correct way, that causes player to can fly until logout
                                /*
                                if (target)
                                {
                                    target->SetDisableGravity(true);
                                    target->MonsterMoveWithSpeed(x, y, me->GetPositionZ()+15, 0);
                                }
                                */

                                Unit* Cloud = me->SummonTrigger(x, y, me->GetPositionZ()+16, 0, 15000);
                                if (Cloud)
                                    {
                                        CloudGUID = Cloud->GetGUID();
                                        Cloud->SetDisableGravity(true);
                                        Cloud->StopMoving();
                                        Cloud->SetObjectScale(1.0f);
                                        Cloud->SetFaction(FACTION_FRIENDLY);
                                        Cloud->SetMaxHealth(9999999);
                                        Cloud->SetHealth(9999999);
                                        Cloud->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                    }
                                StormCount = 1;
                                events.ScheduleEvent(EVENT_ELECTRICAL_STORM, 1min); // 60 seconds(bosskillers)
                                events.ScheduleEvent(EVENT_RAIN, 47s, 52s);
                                break;
                            }
                        case EVENT_RAIN:
                            if (!isRaining)
                            {
                                SetWeather(WEATHER_STATE_HEAVY_RAIN, 0.9999f);
                                isRaining = true;
                            }
                            else
                                events.ScheduleEvent(EVENT_RAIN, 1s);
                            break;
                        case EVENT_STORM_SEQUENCE:
                            {
                                Unit* target = ObjectAccessor::GetUnit(*me, CloudGUID);
                                if (!target || !target->IsAlive())
                                {
                                    EnterEvadeMode();
                                    return;
                                }
                                else if (Unit* Cyclone = ObjectAccessor::GetUnit(*me, CycloneGUID))
                                    Cyclone->CastSpell(target, SPELL_SAND_STORM, true); // keep casting or...
                                HandleStormSequence(target);
                                break;
                            }
                        case EVENT_SUMMON_EAGLES:
                            Talk(SAY_SUMMON);

                            float x, y, z;
                            me->GetPosition(x, y, z);

                            for (uint8 i = 0; i < 8; ++i)
                            {
                                Unit* bird = ObjectAccessor::GetUnit(*me, BirdGUIDs[i]);
                                if (!bird) //they despawned on die
                                {
                                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    {
                                        x = target->GetPositionX() + irand(-10, 10);
                                        y = target->GetPositionY() + irand(-10, 10);
                                        z = target->GetPositionZ() + urand(16, 20);
                                        if (z > 95)
                                            z = 95.0f - urand(0, 5);
                                    }
                                    Creature* creature = me->SummonCreature(NPC_SOARING_EAGLE, x, y, z, 0, TEMPSUMMON_CORPSE_DESPAWN, 0);
                                    if (creature)
                                    {
                                        AddThreat(me->GetVictim(), 1.0f, creature);
                                        creature->AI()->AttackStart(me->GetVictim());
                                        BirdGUIDs[i] = creature->GetGUID();
                                    }
                                }
                            }
                            break;
                        case EVENT_ENRAGE:
                             Talk(SAY_ENRAGE);
                             DoCast(me, SPELL_BERSERK, true);
                            events.ScheduleEvent(EVENT_ENRAGE, 10min);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            private:
                ObjectGuid BirdGUIDs[8];
                ObjectGuid TargetGUID;
                ObjectGuid CycloneGUID;
                ObjectGuid CloudGUID;
                uint8  StormCount;
                bool   isRaining;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulAmanAI<boss_akilzonAI>(creature);
        }
};

class npc_akilzon_eagle : public CreatureScript
{
    public:
        npc_akilzon_eagle() : CreatureScript("npc_akilzon_eagle") { }

        struct npc_akilzon_eagleAI : public ScriptedAI
        {
            npc_akilzon_eagleAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                EagleSwoop_Timer = urand(5000, 10000);
                arrived = true;
                TargetGUID.Clear();
            }

            uint32 EagleSwoop_Timer;
            bool arrived;
            ObjectGuid TargetGUID;

            void Reset() override
            {
                Initialize();
                me->SetDisableGravity(true);
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                DoZoneInCombat();
            }

            void MoveInLineOfSight(Unit* /*who*/) override { }


            void MovementInform(uint32, uint32) override
            {
                arrived = true;
                if (TargetGUID)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, TargetGUID))
                        DoCast(target, SPELL_EAGLE_SWOOP, true);
                    TargetGUID.Clear();
                    me->SetSpeedRate(MOVE_RUN, 1.2f);
                    EagleSwoop_Timer = urand(5000, 10000);
                }
            }

            void UpdateAI(uint32 diff) override
            {
                if (EagleSwoop_Timer <= diff)
                    EagleSwoop_Timer = 0;
                else
                    EagleSwoop_Timer -= diff;

                if (arrived)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    {
                        float x, y, z;
                        if (EagleSwoop_Timer)
                        {
                            x = target->GetPositionX() + irand(-10, 10);
                            y = target->GetPositionY() + irand(-10, 10);
                            z = target->GetPositionZ() + urand(10, 15);
                            if (z > 95)
                                z = 95.0f - urand(0, 5);
                        }
                        else
                        {
                            target->GetContactPoint(me, x, y, z);
                            z += 2;
                            me->SetSpeedRate(MOVE_RUN, 5.0f);
                            TargetGUID = target->GetGUID();
                        }
                        me->GetMotionMaster()->MovePoint(0, x, y, z);
                        arrived = false;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetZulAmanAI<npc_akilzon_eagleAI>(creature);
        }
};

void AddSC_boss_akilzon()
{
    new boss_akilzon();
    new npc_akilzon_eagle();
}
