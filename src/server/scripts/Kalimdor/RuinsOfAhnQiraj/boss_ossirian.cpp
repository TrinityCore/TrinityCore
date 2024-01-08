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

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MiscPackets.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ruins_of_ahnqiraj.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "Weather.h"

enum Texts
{
    SAY_SUPREME             = 0,
    SAY_INTRO               = 1,
    SAY_AGGRO               = 2,
    SAY_SLAY                = 3,
    SAY_DEATH               = 4
};

enum Spells
{
    SPELL_CURSE_OF_TONGUES  = 25195,
    SPELL_CYCLONE           = 25189,
    SPELL_SAND_STORM        = 25160,
    SPELL_STOMP             = 25188,
    SPELL_SUPREME           = 25176,
    SPELL_SUMMON            = 20477,
    SPELL_SUMMON_CRYSTAL    = 25192,

    SPELL_WEAKNESS_FIRE     = 25177,
    SPELL_WEAKNESS_FROST    = 25178,
    SPELL_WEAKNESS_NATURE   = 25180,
    SPELL_WEAKNESS_ARCANE   = 25181,
    SPELL_WEAKNESS_SHADOW   = 25183
};

enum Actions
{
    ACTION_TRIGGER_WEAKNESS = 1
};

enum Events
{
    EVENT_SILENCE           = 1,
    EVENT_CYCLONE           = 2,
    EVENT_STOMP             = 3
};

uint8 const NUM_CRYSTALS = 12;

Position CrystalCoordinates[NUM_CRYSTALS] =
{
    { -9188.4404296875f, 1940.2099609375f, 85.6390991210937f, 3.17650008201599f },
    { -9244.41015625f, 1808.97998046875f, 85.6390991210937f, 5.63741016387939f },
    { -9248.41015625f, 1974.82995605469f, 85.6390991210937f, 5.89920997619629f },
    { -9282.080078125f, 1887.33996582031f, 85.6390991210937f, 2.00712990760803f },
    { -9299.73046875f, 1748.44995117187f, 85.6390991210937f, 1.44861996173859f },
    { -9357.8603515625f, 1929.07995605469f, 85.6390991210937f, 1.06465005874634f },
    { -9367.169921875f, 1780.89001464844f, 85.6390991210937f, 1.90241003036499f },
    { -9383.2900390625f, 2012.68005371094f, 85.6511001586914f, 2.93214988708496f },
    { -9406.099609375f, 1862.38000488281f, 85.6390991210937f, 6.2308201789856f },
    { -9407.7197265625f, 1960.2099609375f, 85.6390991210937f, 1.11700999736786f },
    { -9432.400390625f, 1782.53002929687f, 85.6390991210937f, 5.86430978775024f },
    { -9506.1904296875f, 1865.56994628906f, 85.6390991210937f, 4.27606010437012f }
};

float RoomRadius = 165.0f;
uint8 const NUM_TORNADOS = 5; /// @todo This number is completly random!
uint8 const NUM_WEAKNESS = 5;
uint32 const SpellWeakness[NUM_WEAKNESS] = { SPELL_WEAKNESS_FIRE, SPELL_WEAKNESS_FROST, SPELL_WEAKNESS_NATURE, SPELL_WEAKNESS_ARCANE, SPELL_WEAKNESS_SHADOW };
Position const RoomCenter = { -9343.041992f, 1923.278198f, 85.555984f, 0.0 };

class boss_ossirian : public CreatureScript
{
    public:
        boss_ossirian() : CreatureScript("boss_ossirian") { }

        struct boss_ossirianAI : public BossAI
        {
            boss_ossirianAI(Creature* creature) : BossAI(creature, DATA_OSSIRIAN)
            {
                Initialize();
                SaidIntro = false;
            }

            void Initialize()
            {
                CrystalIterator = 0;
                TriggerGUID.Clear();
                CrystalGUID.Clear();
            }

            ObjectGuid TriggerGUID;
            ObjectGuid CrystalGUID;
            uint8 CrystalIterator;
            bool SaidIntro;

            void Reset() override
            {
                _Reset();
                Initialize();
            }

            void SpellHit(WorldObject* caster, SpellInfo const* spellInfo) override
            {
                for (uint8 i = 0; i < NUM_WEAKNESS; ++i)
                {
                    if (spellInfo->Id == SpellWeakness[i])
                    {
                        me->RemoveAurasDueToSpell(SPELL_SUPREME);
                        // Despawn used crystal
                        if (GameObject* crystal = GetClosestGameObjectWithEntry(caster, GO_OSSIRIAN_CRYSTAL, 5.0f))
                            crystal->Delete();
                        if (Creature* creatureCaster = caster->ToCreature())
                            creatureCaster->DespawnOrUnsummon();
                        SpawnNextCrystal();
                    }
                }
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_TRIGGER_WEAKNESS)
                    if (Creature* Trigger = ObjectAccessor::GetCreature(*me, TriggerGUID))
                        if (!Trigger->HasUnitState(UNIT_STATE_CASTING))
                            Trigger->CastSpell(Trigger, SpellWeakness[urand(0, 4)], false);
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);
                events.Reset();
                events.ScheduleEvent(EVENT_SILENCE, 30s);
                events.ScheduleEvent(EVENT_CYCLONE, 20s);
                events.ScheduleEvent(EVENT_STOMP, 30s);

                DoCastSelf(SPELL_SUPREME);
                Talk(SAY_AGGRO);

                Map* map = me->GetMap();

                WorldPackets::Misc::Weather weather(WEATHER_STATE_HEAVY_SANDSTORM, 1.0f);
                map->SendToPlayers(weather.Write());

                for (uint8 i = 0; i < NUM_TORNADOS; ++i)
                {
                    Position Point = me->GetRandomPoint(RoomCenter, RoomRadius);
                    if (Creature* Tornado = map->SummonCreature(NPC_SAND_VORTEX, Point))
                        Tornado->CastSpell(Tornado, SPELL_SAND_STORM, true);
                }

                SpawnNextCrystal();
            }

            void KilledUnit(Unit* /*victim*/) override
            {
                Talk(SAY_SLAY);
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                Cleanup();
                summons.DespawnAll();
                BossAI::EnterEvadeMode(why);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Cleanup();
                _JustDied();
            }

            void Cleanup()
            {
                if (GameObject* Crystal = ObjectAccessor::GetGameObject(*me, CrystalGUID))
                    Crystal->Use(me);
            }

            void SpawnNextCrystal()
            {
                if (CrystalIterator == NUM_CRYSTALS)
                    CrystalIterator = 0;

                if (Creature* Trigger = me->SummonCreature(NPC_OSSIRIAN_TRIGGER, CrystalCoordinates[CrystalIterator]))
                {
                    TriggerGUID = Trigger->GetGUID();
                    if (GameObject* Crystal = Trigger->SummonGameObject(GO_OSSIRIAN_CRYSTAL, CrystalCoordinates[CrystalIterator], QuaternionData::fromEulerAnglesZYX(CrystalCoordinates[CrystalIterator].GetOrientation(), 0.0f, 0.0f), Seconds::max(), GO_SUMMON_TIMED_DESPAWN))
                    {
                        CrystalGUID = Crystal->GetGUID();
                        ++CrystalIterator;
                    }
                }
            }

            void MoveInLineOfSight(Unit* who) override

            {
                if (!SaidIntro)
                {
                    Talk(SAY_INTRO);
                    SaidIntro = true;
                }
                BossAI::MoveInLineOfSight(who);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                // No kiting!
                if (me->GetDistance(me->GetVictim()) > 60.00f && me->GetDistance(me->GetVictim()) < 120.00f)
                    DoCastVictim(SPELL_SUMMON);

                bool ApplySupreme = true;

                if (me->HasAura(SPELL_SUPREME))
                    ApplySupreme = false;
                else
                {
                    for (uint8 i = 0; i < NUM_WEAKNESS; ++i)
                    {
                        if (me->HasAura(SpellWeakness[i]))
                        {
                            ApplySupreme = false;
                            break;
                        }
                    }
                }

                if (ApplySupreme)
                {
                    DoCastSelf(SPELL_SUPREME);
                    Talk(SAY_SUPREME);
                }

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SILENCE:
                            DoCastAOE(SPELL_CURSE_OF_TONGUES);
                            events.ScheduleEvent(EVENT_SILENCE, 20s, 30s);
                            break;
                        case EVENT_CYCLONE:
                            DoCastVictim(SPELL_CYCLONE);
                            events.ScheduleEvent(EVENT_CYCLONE, 20s);
                            break;
                        case EVENT_STOMP:
                            DoCastSelf(SPELL_STOMP);
                            events.ScheduleEvent(EVENT_STOMP, 30s);
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetAQ20AI<boss_ossirianAI>(creature);
        }
};

class go_ossirian_crystal : public GameObjectScript
{
    public:
        go_ossirian_crystal() : GameObjectScript("go_ossirian_crystal") { }

        struct go_ossirian_crystalAI : public GameObjectAI
        {
            go_ossirian_crystalAI(GameObject* go) : GameObjectAI(go), instance(go->GetInstanceScript()) { }

            InstanceScript* instance;

            bool OnGossipHello(Player* player) override
            {
                // Crystal animation on use
                me->SetLootState(GO_ACTIVATED);
                Creature* ossirian = player->FindNearestCreature(NPC_OSSIRIAN, 30.0f);
                if (!ossirian || instance->GetBossState(DATA_OSSIRIAN) != IN_PROGRESS)
                    return false;

                ossirian->AI()->DoAction(ACTION_TRIGGER_WEAKNESS);
                return true;
            }
        };

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return GetAQ20AI<go_ossirian_crystalAI>(go);
        }
};

void AddSC_boss_ossirian()
{
    new boss_ossirian();
    new go_ossirian_crystal();
}
