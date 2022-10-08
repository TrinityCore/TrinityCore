/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "siege_of_orgrimmar.hpp"
#include "Vehicle.h"
#include "InstanceScript.h"
#include "SpellMgr.h"

enum ScriptedTexts
{
    SAY_ZAELA_AGGRO     = 0,
    SAY_ZAELA_ADDS      = 1,
    SAY_ZAELA_TOWERS    = 2,
    SAY_ZAELA_EVENT_1   = 3,
    SAY_ZAELA_EVENT_2   = 4,
    SAY_ZAELA_EVENT_3   = 5,
};

#define SAY_ZAELA_DEATH_SOUND 38392

Position galakrasNpcPos[4] =
{
    { 1360.96f, -5404.39f, 10.32f, 1.75f}, // jaina moves at the ship
    { 1360.96f, -5404.39f, 10.32f, 4.89f}, // jaina's orientation

    { 1431.70f, -4898.23f, 11.34f, 1.75f}, // jaina/lor'themar position after intro
    { 1421.77f, -4901.12f, 11.36f, 1.76f}  // wrynn/sylvanas position after intro
};

enum Spells
{
    // Common
    SPELL_IN_A_TOWER                        = 147317,
    SPELL_TOWER_STRENGTH                    = 148120,

    // Kor'kron Elite Sniper
    SPELL_SNIPED                            = 146743,

    // Anti-Air Turret
    SPELL_ANTI_AIR_CANNON                   = 146488,
    SPELL_ANTI_AIR_CANNON_AURA              = 147514,

    // Master Cannoneer Dagryn
    SPELL_SHOOT                             = 146773,

    SPELL_MUZZLE_SPRAY                      = 147825,
    SPELL_MUZZLE_SPAY_2                     = 147823, // triggered by 147825
    SPELL_MUZZLE_SPRAY_DMG                  = 147824, // triggered by 147823
    SPELL_MUZZLE_SPRAY_DUMMY                = 147830,

    // Lieutenant Krugruk
    SPELL_THUNDER_CLAP                      = 147683,
    SPELL_ARCING_SMASH                      = 147688,

    // Dragonmaw Flameslinger
    SPELL_FLAME_ARROWS                      = 146763, // cast 3 secs
    SPELL_FLAME_ARROWS_2                    = 147552, // cast 4 secs, not used ?
    SPELL_FLAME_ARROWS_AOE                  = 147438, // targetting ?
    SPELL_FLAME_ARROWS_DMG                  = 146764,
    SPELL_FLAME_ARROWS_PERIODIC             = 146765,

    // High Enforcer Thranok
    SPELL_CRUSHERS_CALL_AOE                 = 146769,
    SPELL_CRUSHERS_CALL_TRIGGER             = 146778,
    SPELL_CRUSHERS_CALL_AOE_2               = 146775,
    SPELL_CRUSHERS_CALL_JUMP                = 146780,
    SPELL_SHATTERING_CLEAVE                 = 146849,
    SPELL_SKULL_CRACKER                     = 146848,

    // Kogra the Snake
    SPELL_CURSE_OF_VENOM                    = 147711,
    SPELL_POISON_TIPPED_BLADES              = 146902,
    SPELL_VENOM_BOLT_VOLLEY                 = 147713,

    // Dragonmaw Bonecrusher
    SPELL_SHATTERING_ROAR                   = 147204,
    SPELL_FRACTURE                          = 146899,
    SPELL_FRACTURE_DMG                      = 146901,

    // Dragonmaw Ebon Stalker
    SPELL_SHADOW_ASSAULT                    = 146868,
    SPELL_SHADOW_ASSAULT_DMG                = 146872,
    SPELL_SHADOW_STALK                      = 146864,

    // Dragonmaw Flagbearer
    SPELL_DRAGONMAW_FLAGBEARER              = 145232,
    SPELL_WAR_BANNER_SUMMON                 = 146736,
    SPELL_WAR_BANNER_AURA                   = 146735,
    SPELL_WAR_BANNER_VISUAL                 = 147328,

    // Dragommaw Grunt (1)
    SPELL_THROW_AXE                         = 147669,

    // Dragonmaw Grunt (2)
    SPELL_DRAGONS_CLEAVE                    = 148025,
    SPELL_FIXATE                            = 148243,

    // Dragonmaw Proto-drake
    SPELL_DRAKE_FIRE_AOE                    = 148351,
    SPELL_DRAKE_FIRE_MISSILE                = 148352,
    SPELL_DRAKE_FIRE_DMG                    = 148560,
    SPELL_FLAME_BREATH                      = 146776,

    // Dragonmaw Tidal Shaman
    SPELL_CHAIN_HEAL                        = 146757,
    SPELL_HEALING_TIDE_TOTEM                = 146753,
    SPELL_HEALING_TIDE_AURA                 = 146725,
    SPELL_HEALING_TIDE_HEAL                 = 146726,
    SPELL_TIDAL_WAVE_AOE                    = 148522,
    SPELL_TIDAL_WAVE_DUMMY                  = 148519,
    SPELL_TIDAL_WAVE_DMG                    = 147820,

    // Galakras
    SPELL_EJECT_ALL_PASSENGERS              = 50630,

    SPELL_PULSING_FLAMES                    = 147042,
    SPELL_PULSING_FLAMES_DMG                = 147043,

    SPELL_FLAMES_OF_GALAKROND               = 147068,
    SPELL_FLAMES_OF_GALAKROND_AREATRIGGER   = 146991,
    SPELL_FLAMES_OF_GALAKROND_DMG           = 146992,
    SPELL_FLAMES_OF_GALAKROND_PERIODIC      = 147029,

    // Demolitions Crew
    SPELL_GOT_THE_BOMB                      = 147966,
    SPELL_THE_MOST_COMPLICATED_BOMB_1       = 147916,   // for right tower
    SPELL_THE_MOST_COMPLICATED_BOMB_2       = 147897,   // for left tower

    // Kor'kron Demolisher
    SPELL_BOMBARD_MISSILE_1                 = 148301, // hit onpy players
    SPELL_BOMBARD_MISSILE_2                 = 148302,
    SPELL_BOMBART_DMG_1                     = 148310,
    SPELL_BOMBART_DMG_2                     = 148311,
};

enum Adds
{
    NPC_KORKRON_ELITE_SNIPER    = 72261,
    NPC_ANTI_AIR_TURRET         = 72408,
    NPC_MASTER_CANNONEER_DAGRYN = 72356,
    NPC_LIEUTENANT_KRUGRUK      = 72357,
    NPC_HIGH_ENFORCER_THRANOK   = 72355,
    NPC_KORGRA_THE_SNAKE        = 72456,
    NPC_DRAGONMAW_FLAMESLINGER  = 72353,
    NPC_DRAGONMAW_BONECRUSHER   = 72945,
    NPC_DRAGONMAW_EBON_STALKER  = 72352,
    NPC_DRAGONMAW_FLAGBEARER    = 72942,
    NPC_DRAGONMAW_GRUNT_1       = 72941, // called by galakras
    NPC_DRAGONMAW_GRUNT_2       = 73530, // near towers
    NPC_DRAGONMAW_PROTO_DRAKE   = 72943,
    NPC_DRAGONMAW_TIDAL_SHAMAN  = 72958,
    NPC_HEALING_TIDE_TOTEM      = 73094,
    NPC_KORKRON_DEMOLISHER      = 72947,

    NPC_TOWER_LEFT              = 73565,
    NPC_TOWER_RIGHT             = 73628,

    NPC_DEMOLITIONS_EXPERT_1    = 73495,    // right tower
    NPC_DEMOLITIONS_ASSISTANT_1 = 73496,    // right tower
    NPC_DEMOLITIONS_EXPERT_2    = 73493,    // left tower
    NPC_DEMOLITIONS_ASSISTANT_2 = 73494,    // left tower
};

enum Events
{
    // Galakras
    EVENT_DOWN = 1,
    EVENT_AGGRO,
    EVENT_PULSING_FLAMES,
    EVENT_FLAMES_OF_GALAKROND,
    EVENT_SPAWN_LEFT_DEMOLISHER,
    EVENT_SPAWN_RIGHT_DEMOLISHER,

    //
    EVENT_SHOOT,
    EVENT_MUZZLE_SPRAY,

    EVENT_THUNDER_CLAP,
    EVENT_ARCING_SMASH,

    EVENT_FLAME_ARROWS,

    // High Enforcer Thranok
    EVENT_CRUSHERS_CALL,
    EVENT_SHATTERING_CLEAVE,
    EVENT_SKULL_CRACKER,

    // Kogra the Snake
    EVENT_VENOM_BOLT_VOLLEY,
    EVENT_POISON_TIPPED_BLADES,

    // Dragonmaw Bonecrusher
    EVENT_SHATTERING_ROAR,
    EVENT_FRACTURE,

    // Dragonmaw Ebon Stalker
    EVENT_SHADOW_ASSAULT,
    EVENT_SHADOW_STALK,

    // Dragonmaw Flagbearer
    EVENT_WAR_BANNER,

    // Dragommaw Grunt (1)
    EVENT_THROW_AXE,

    // Dragonmaw Grunt (2)
    EVENT_DRAGONS_CLEAVE,
    EVENT_FIXATE,

    // Dragonmaw Proto-drake
    EVENT_DRAKE_FIRE_AOE,
    EVENT_FLAME_BREATH,

    // Dragonmaw Tidal Shaman
    EVENT_CHAIN_HEAL,
    EVENT_HEALING_TIDE_TOTEM,
    EVENT_TIDAL_WAVE,

    // Kor'kron Demolisher
    EVENT_MOVE_TO_ATTACK,
    EVENT_BOMBARD,
};

enum Actions
{
    ACTION_LEFT_TOWER_BROKEN    = 1,
    ACTION_RIGHT_TOWER_BROKEN,
    ACTION_LEFT_TOWER_DEFENDER_DIED,
    ACTION_RIGHT_TOWER_DEFENDER_DIED,
    ACTION_LEFT_TOWER_ALL_DEFENDERS_DIED,
    ACTION_RIGHT_TOWER_ALL_DEFENDERS_DIED,
    ACTION_GALAKRAS_DOWN,
};

enum DisplayIds
{
    DISPLAY_ITEM_KORKRON_HAND_CANNON        = 103953,
    DISPLAY_ITEM_DAGRYN_DISCARDED_LONGBOW   = 104735,
    DISPLAY_TEM_ARCWEAVER_SPELL_SWORD       = 112787,
};

enum eData
{
    DATA_WAVE_SPAWNED   = 1,
    DATA_LEFT_TOWER_DEFENDER,
    DATA_RIGHT_TOWER_DEFENDER,
    DATA_LEFT_TOWER_ATTACKER,
    DATA_RIGHT_TOWER_ATTACKER,
    DATA_LEFT_TOWER_DEFENDER_DIED,
    DATA_RIGHT_TOWER_DEFENDER_DIED,
    DATA_RIGHT_TOWER_ALL_DEFENDERS_DIED,
    DATA_LEFT_TOWER_ALL_DEFENDERS_DIED,
    DATA_DEFENDERS_LEFT,
    DATA_LAST_FLAMES_OF_GALAKROND_TARGET,
};

enum TowerDefenders
{
    DEFENDER_NONE           = 0,
    LEFT_TOWER_DEFENDER     = 1,
    RIGHT_TOWER_DEFENDER    = 2,
};

enum TowerAttackers
{
    ATTACKER_NONE           = 0,
    LEFT_TOWER_ATTACKER     = 1,
    RIGHT_TOWER_ATTACKER    = 2,
};

struct StaticAddInfo
{
    uint32 entry;
    Position pos;
};

const Position sniperPos = {1342.19f, -4702.86f, 36.93f, 5.09f};

#define TOWER_TURRETS_COUNT 2
const Position turretPos[TOWER_TURRETS_COUNT] =
{
    {1372.11f, -4851.76f, 72.05f, 5.48f}, // left
    {1457.19f, -4818.57f, 68.80f, 4.30f}  // right
};

#define FIRST_BOSS_WAVE 3
#define FIRST_TOWER_WAVE 4
#define SECOND_BOSS_WAVE 6
#define SECOND_TOWER_WAVE 8

#define ANTI_AIR_TURRET_COOLDOWN 4000
#define ANTI_AIR_TURRET_HITS 2

#define TOWER_ADDS_COUNT 8
#define DEFENDERS_COUNT (TOWER_ADDS_COUNT - 1)
const StaticAddInfo leftTowerAdds[TOWER_ADDS_COUNT] =
{
    { NPC_LIEUTENANT_KRUGRUK, {1363.26f, -4843.40f, 71.82f, 2.38f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1381.14f, -4840.58f, 71.61f, 5.67f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1376.99f, -4846.52f, 71.77f, 5.70f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1364.22f, -4856.67f, 71.51f, 5.31f} },
    { NPC_DRAGONMAW_GRUNT_2, {1363.53f, -4837.55f, 33.08f, 5.48f} },
    { NPC_DRAGONMAW_GRUNT_2, {1360.16f, -4840.86f, 33.06f, 5.48f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1359.52f, -4835.97f, 33.11f, 5.48f} },
    { NPC_TOWER_LEFT, {1361.79f, -4837.99f, 33.08f, 5.47f} }
};
const StaticAddInfo rightTowerAdds[TOWER_ADDS_COUNT] =
{
    { NPC_MASTER_CANNONEER_DAGRYN, {1461.62f, -4807.18f, 68.47f, 1.26f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1450.27f, -4815.10f, 68.39f, 4.12f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1465.98f, -4822.74f, 68.32f, 4.25f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1462.31f, -4822.44f, 68.52f, 4.25f} },
    { NPC_DRAGONMAW_GRUNT_2, {1459.45f, -4804.19f, 29.68f, 4.36f} },
    { NPC_DRAGONMAW_GRUNT_2, {1463.44f, -4805.61f, 29.67f, 4.36f} },
    { NPC_DRAGONMAW_FLAMESLINGER, {1462.74f, -4800.81f, 29.68f, 4.36f} },
    { NPC_TOWER_RIGHT, {1462.65f, -4804.30f, 29.68f, 4.40f} }
};

enum Timers
{
    TIMER_WAVE_FIRST    = 5000,
    TIMER_WAVE          = 55000,
    TIMER_DEMOLISHER    = 20000,
    TIMER_ADDS_DESPAWN  = 5000,
};

const Position addsSpawnPos[1] =
{
    { 1407.03f, -4815.50f, 21.13f, 5.07f }
};

const Position demolisherAttackPos[4] =
{
    { 1409.67f, -4820.75f, 19.98f, 3.52f},  // facing to left tower
    { 1409.67f, -4820.75f, 19.98f, 0.27f},  // facing to right tower

    { 1361.79f, -4837.99f, 33.08f, 5.47f},  // attack left tower
    { 1462.65f, -4804.30f, 29.68f, 4.40f}   // attack right tower
};

const Position fallPos = { 1408.86f, -4814.65f, 21.14f, 4.93f};

enum Points
{
    POINT_DEMOLISHER_ATTACK_LEFT    = 1,
    POINT_DEMOLISHER_ATTACK_RIGHT   = 2,
};

class AddsController
{
    public:

        AddsController(Creature* owner) : m_Owner(owner)
        {
            m_IsActive = false;
            m_WaveTimer = TIMER_WAVE_FIRST;
            m_WaveCounter = 0;
        }

        void Reset()
        {
            Stop();

            m_WaveCounter = 0;
            m_WaveTimer = TIMER_WAVE_FIRST;
        }

        void Activate() { m_IsActive = true; }
        void Stop() { m_IsActive = false; }
        void SetWaveTimer(uint32 timer) { m_WaveTimer = timer; }
        uint32 GetWaveCounter() { return m_WaveCounter; }

        void Update(const uint32 diff)
        {
            if (!m_IsActive)
                return;

            if (m_WaveTimer <= diff)
            {
                m_WaveTimer = TIMER_WAVE;

                m_WaveCounter++;

                ProcessWave(m_WaveCounter);
            }
            else
            {
                m_WaveTimer -= diff;
            }
        }

    private:

        void ProcessWave(uint32 waveCounter)
        {
            std::vector<uint32> creatureEntries;

            if (waveCounter == FIRST_BOSS_WAVE)
            {
                CreateFirstBossWave(creatureEntries);
            }
            else if (waveCounter == SECOND_BOSS_WAVE)
            {
                CreateSecondBossWave(creatureEntries);
            }
            else
            {
                CreateAddsWave(creatureEntries);
            }

            m_Owner->AI()->SetData(DATA_WAVE_SPAWNED, waveCounter);

            for (uint32 creatureEntry : creatureEntries)
            {
                if (Creature* pCreature = m_Owner->SummonCreature(creatureEntry, addsSpawnPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, TIMER_ADDS_DESPAWN))
                {
                    // The creature ai is a tower defender with 'defensive' state
                    // But if it's summoned by boss it should be aggressive
                    if (pCreature->GetEntry() == NPC_DRAGONMAW_FLAMESLINGER)
                    {
                        pCreature->SetReactState(REACT_AGGRESSIVE);
                    }
                }
            }
        }

        void CreateFirstBossWave(std::vector<uint32>& creatureEntries)
        {
            AddEntriesWithChance(creatureEntries, NPC_KORGRA_THE_SNAKE, 1, 100);
            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_EBON_STALKER, 2, 100);
        }

        void CreateSecondBossWave(std::vector<uint32>& creatureEntries)
        {
            AddEntriesWithChance(creatureEntries, NPC_HIGH_ENFORCER_THRANOK, 1, 100);
            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_TIDAL_SHAMAN, 1, 100);
            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_FLAGBEARER, 1, 100);
            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_GRUNT_1, 1, 100);
        }

        void CreateAddsWave(std::vector<uint32>& creatureEntries)
        {
            // bonecrusher
            // tidal shaman
            // grunts 1-3
            // flagbearer
            // flameslinger
            // 3-7 adds

            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_BONECRUSHER, 1, 50);
            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_TIDAL_SHAMAN, 1, 50);
            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_FLAMESLINGER, 2, 50);
            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_FLAGBEARER, 1, 50);
            AddEntriesWithChance(creatureEntries, NPC_DRAGONMAW_GRUNT_1, urand(1, 3), 100);
        }

        void AddEntriesWithChance(std::vector<uint32>& list, uint32 entry, uint32 count, uint32 chance)
        {
            if (!count)
                return;

            if (roll_chance_i(chance))
            {
                for (uint32 i = 0; i < count; ++i)
                {
                    list.push_back(entry);
                }
            }
        }

    private:

        Creature* m_Owner;
        uint32 m_WaveTimer;
        bool m_IsActive;
        uint32 m_WaveCounter;
};

class FlamesOfGalakrond
{
    private:

        struct FlamesData
        {
            FlamesData() :
                spellAreaTriggerGuid(ObjectGuid::Empty), targetGuid(ObjectGuid::Empty), targetsHitCount(0)
            {

            }

            FlamesData(ObjectGuid triggerGuid, ObjectGuid target) :
                spellAreaTriggerGuid(triggerGuid), targetGuid(target), targetsHitCount(0)
            {
            }

            ObjectGuid spellAreaTriggerGuid;
            ObjectGuid targetGuid;
            uint32 targetsHitCount;
        };

    public:

        void Reset()
        {
            m_Flames.clear();
        }

        void AddFlame(ObjectGuid triggerGuid, ObjectGuid targetGuid)
        {
            if (m_Flames.find(triggerGuid) != m_Flames.end())
                return;

            m_Flames[triggerGuid] = FlamesData(triggerGuid, targetGuid);
        }

        void RemoveFlame(ObjectGuid triggerGuid)
        {
            std::map<ObjectGuid, FlamesData>::iterator itr = m_Flames.find(triggerGuid);
            if (itr != m_Flames.end())
            {
                m_Flames.erase(itr);
            }
        }

        void FlameHitTarget(ObjectGuid triggerGuid)
        {
            if (m_Flames.find(triggerGuid) == m_Flames.end())
                return;

            ++m_Flames[triggerGuid].targetsHitCount;
        }

        uint32 GetFlameHitCount(ObjectGuid triggerGuid)
        {
            if (m_Flames.find(triggerGuid) == m_Flames.end())
                return 0;

             return m_Flames[triggerGuid].targetsHitCount;
        }

    private:

        std::map<ObjectGuid, FlamesData> m_Flames;

};

class boss_galakras : public CreatureScript
{
    public:
        boss_galakras() : CreatureScript("boss_galakras") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_galakrasAI(creature);
        }

        struct boss_galakrasAI : public BossAI
        {
            boss_galakrasAI(Creature* creature) : BossAI(creature, DATA_GALAKRAS), m_AddsController(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                me->SetBoundingRadius(15);
                me->SetCombatReach(15);
            }

            void Reset()
            {
                _Reset();

                me->SetReactState(REACT_PASSIVE);

                SpawnSniper();
                SpawnZaela();

                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);

                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));

                m_IsDown = false;
                //resetTurretHitsTimer = ANTI_AIR_TURRET_COOLDOWN;
                //turretHitsCounter = 0;

                RemoveInstanceAuras();

                m_AddsController.Reset();
                m_FlamesOfGalakrond.Reset();
            }

            void EnterCombat(Unit* who)
            {
                SpawnTurrets();

                SendZaelaTalk(SAY_ZAELA_AGGRO);

                m_AddsController.SetWaveTimer(TIMER_WAVE_FIRST);
                m_AddsController.Activate();

                instance->SetBossState(DATA_GALAKRAS, IN_PROGRESS);
            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_START_GALAKRAS)
                {
                    ProcessStartGalakras();
                }
                else if (action == ACTION_GALAKRAS_DOWN)
                {
                    ProcessDown();
                }
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_WAVE_SPAWNED)
                {
                    uint32 waveCounter = data;

                    if (waveCounter == FIRST_TOWER_WAVE)
                    {
                        ProcessLeftTowerBroken();
                    }
                    else if (waveCounter == SECOND_TOWER_WAVE)
                    {
                        ProcessRightTowerBroken();
                    }
                }
                else if (type == DATA_LEFT_TOWER_DEFENDER_DIED)
                {
                    EntryCheckPredicate pred(NPC_TOWER_LEFT);
                    summons.DoAction(ACTION_LEFT_TOWER_DEFENDER_DIED, pred);
                }
                else if (type == DATA_RIGHT_TOWER_DEFENDER_DIED)
                {
                    EntryCheckPredicate pred(NPC_TOWER_RIGHT);
                    summons.DoAction(ACTION_RIGHT_TOWER_DEFENDER_DIED, pred);
                }
                else if (type == DATA_RIGHT_TOWER_ALL_DEFENDERS_DIED)
                {
                    EntryCheckPredicate pred(NPC_ANTI_AIR_TURRET);
                    summons.DoAction(ACTION_RIGHT_TOWER_ALL_DEFENDERS_DIED, pred);
                }
                else if (type == DATA_LEFT_TOWER_ALL_DEFENDERS_DIED)
                {
                    EntryCheckPredicate pred(NPC_ANTI_AIR_TURRET);
                    summons.DoAction(ACTION_LEFT_TOWER_ALL_DEFENDERS_DIED, pred);
                }
            }

            void EnterEvadeMode(EvadeReason why)
            {
                SendResetGalakras();

                BossAI::EnterEvadeMode(why);
            }

            void JustDied(Unit* who)
            {
                _JustDied();

                me->RemoveAllAreaTriggers();
                RemoveInstanceAuras();

                m_AddsController.Reset();
                m_FlamesOfGalakrond.Reset();
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);

                if (summon->GetReactState() != ReactStates::REACT_DEFENSIVE)
                {
                    if (me->IsInCombat())
                        DoZoneInCombat(summon);
                }
            }

            FlamesOfGalakrond& GetFlamesOfGalakrond()
            {
                return m_FlamesOfGalakrond;
            }

            ObjectGuid GetObjectGuid(uint32 type)
            {
                if (type == DATA_LAST_FLAMES_OF_GALAKROND_TARGET)
                {
                    return m_LastFlamesOfGalakrondGuid;
                }

                return ObjectGuid::Empty;
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                m_AddsController.Update(diff);

                events.Update(diff);

                //ResetHitsCount(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPAWN_LEFT_DEMOLISHER:
                            SpawnLeftTowerDemolisher();
                            break;
                        case EVENT_SPAWN_RIGHT_DEMOLISHER:
                            SpawnRightTowerDemolisher();
                            break;
                        case EVENT_DOWN:
                            //me->GetMotionMaster()->MoveFall();
                            MoveCustomFall();
                            events.ScheduleEvent(EVENT_AGGRO, 4000);
                            break;
                        case EVENT_AGGRO:
                            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
                            me->SetReactState(REACT_AGGRESSIVE);

                            events.ScheduleEvent(EVENT_PULSING_FLAMES, 39000);
                            events.ScheduleEvent(EVENT_FLAMES_OF_GALAKROND, 8000);
                            break;
                        case EVENT_PULSING_FLAMES:
                            DoCast(me, SPELL_PULSING_FLAMES);
                            events.ScheduleEvent(EVENT_PULSING_FLAMES, 25000);
                            break;
                        case EVENT_FLAMES_OF_GALAKROND:
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 0.0f, true);
                            if (!target)
                                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);

                            if (target)
                            {
                                m_LastFlamesOfGalakrondGuid = target->GetGUID();
                                DoCast(target, SPELL_FLAMES_OF_GALAKROND);
                            }

                            events.ScheduleEvent(EVENT_FLAMES_OF_GALAKROND, 6000);

                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            void RemoveInstanceAuras()
            {
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_IN_A_TOWER);
                instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_TOWER_STRENGTH);
            }

            void SpawnSniper()
            {
                me->SummonCreature(NPC_KORKRON_ELITE_SNIPER, sniperPos);
            }

            void SpawnZaela()
            {
                if (Creature* pZaela = me->SummonCreature(NPC_WARLORD_ZAELA, *me))
                {
                    pZaela->SetDisableGravity(true);
                    pZaela->EnterVehicle(me);
                }
            }

            void SpawnTurrets()
            {
                if (Creature* pCreature = me->SummonCreature(NPC_ANTI_AIR_TURRET, turretPos[0]))
                {
                    pCreature->AI()->SetData(DATA_LEFT_TOWER_DEFENDER, 1);
                }

                if (Creature* pCreature = me->SummonCreature(NPC_ANTI_AIR_TURRET, turretPos[1]))
                {
                    pCreature->AI()->SetData(DATA_RIGHT_TOWER_DEFENDER, 1);
                }
            }

            void SpawnLeftTowerAdds()
            {
                for (uint8 i = 0; i < TOWER_ADDS_COUNT; ++i)
                {
                    if (Creature* pCreature = me->SummonCreature(leftTowerAdds[i].entry, leftTowerAdds[i].pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, TIMER_ADDS_DESPAWN))
                    {
                        pCreature->AI()->SetData(DATA_LEFT_TOWER_DEFENDER, 1);
                    }
                }
            }

            void SpawnRightTowerAdds()
            {
                for (uint8 i = 0; i < TOWER_ADDS_COUNT; ++i)
                {
                    if (Creature* pCreature = me->SummonCreature(rightTowerAdds[i].entry, rightTowerAdds[i].pos, TEMPSUMMON_CORPSE_TIMED_DESPAWN, TIMER_ADDS_DESPAWN))
                    {
                        pCreature->AI()->SetData(DATA_RIGHT_TOWER_DEFENDER, 1);
                    }
                }
            }

            void SpawnLeftTowerDemolisher()
            {
                if (Creature* pDemolisher = me->SummonCreature(NPC_KORKRON_DEMOLISHER, addsSpawnPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, TIMER_ADDS_DESPAWN))
                {
                    pDemolisher->AI()->SetData(DATA_LEFT_TOWER_ATTACKER, DONE);
                }
            }

            void SpawnRightTowerDemolisher()
            {
                if (Creature* pDemolisher = me->SummonCreature(NPC_KORKRON_DEMOLISHER, addsSpawnPos[0], TEMPSUMMON_CORPSE_TIMED_DESPAWN, TIMER_ADDS_DESPAWN))
                {
                    pDemolisher->AI()->SetData(DATA_RIGHT_TOWER_ATTACKER, DONE);
                }
            }

            void ProcessStartGalakras()
            {
                DoZoneInCombat();
            }

            void ProcessLeftTowerBroken()
            {
                SendZaelaTalk(SAY_ZAELA_TOWERS);

                EntryCheckPredicate pred(NPC_ANTI_AIR_TURRET);
                summons.DoAction(ACTION_LEFT_TOWER_BROKEN, pred);

                SpawnLeftTowerAdds();

                events.ScheduleEvent(EVENT_SPAWN_LEFT_DEMOLISHER, TIMER_DEMOLISHER);
            }

            void ProcessRightTowerBroken()
            {
                SendZaelaTalk(SAY_ZAELA_TOWERS);

                EntryCheckPredicate pred(NPC_ANTI_AIR_TURRET);
                summons.DoAction(ACTION_RIGHT_TOWER_BROKEN, pred);

                SpawnRightTowerAdds();

                events.ScheduleEvent(EVENT_SPAWN_RIGHT_DEMOLISHER, TIMER_DEMOLISHER);
            }

            void ProcessDown()
            {
                if (m_IsDown)
                    return;

                //turretHitsCounter++;
                //if (turretHitsCounter < ANTI_AIR_TURRET_HITS)
                //{
                //    return;
                //}

                m_IsDown = true;

                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);

                if (Creature* pZaela = instance->instance->GetCreature(instance->GetObjectGuid(DATA_WARLORD_ZAELA)))
                {
                    pZaela->PlayDirectSound(SAY_ZAELA_DEATH_SOUND);
                    pZaela->DespawnOrUnsummon();
                }

                m_AddsController.Stop();

                DummyEntryCheckPredicate predicate;
                summons.DoAction(ACTION_GALAKRAS_DOWN, predicate);

                events.ScheduleEvent(EVENT_DOWN, 4000);
            }

            /*void ResetHitsCount(const uint32 diff)
            {
                if (!turretHitsCounter)
                    return;

                if (resetTurretHitsTimer <= diff)
                {
                    resetTurretHitsTimer = ANTI_AIR_TURRET_COOLDOWN;

                    turretHitsCounter = 0;
                }
                else
                {
                    resetTurretHitsTimer -= diff;
                }
            }*/

            void SendZaelaTalk(uint32 talkId)
            {
                if (Creature* pZaela = instance->instance->GetCreature(instance->GetObjectGuid(DATA_WARLORD_ZAELA)))
                {
                    // maybe do it with doaction
                    pZaela->AI()->Talk(talkId);
                }
            }

            void SendResetGalakras()
            {
                instance->SetData(DATA_RESET_GALAKRAS, DONE);
            }

            void MoveCustomFall()
            {
                Movement::MoveSplineInit init(me);
                init.MoveTo(fallPos.GetPositionX(), fallPos.GetPositionY(), fallPos.GetPositionZ(), false);
                init.SetFall();
                init.Launch();
            }

        private:

            bool m_IsDown;
            AddsController m_AddsController;
            FlamesOfGalakrond m_FlamesOfGalakrond;
            ObjectGuid m_LastFlamesOfGalakrondGuid;
            //uint32 resetTurretHitsTimer;
            //uint32 turretHitsCounter;
        };
};

typedef boss_galakras::boss_galakrasAI GalakrasAI;

class npc_galakras_warlord_zaela : public CreatureScript
{
    public:
        npc_galakras_warlord_zaela() : CreatureScript("npc_galakras_warlord_zaela") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_warlord_zaelaAI(creature);
        }

        struct npc_galakras_warlord_zaelaAI : public ScriptedAI
        {
            npc_galakras_warlord_zaelaAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);

                me->setActive(true);
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_SECOND_INTRO_GALAKRAS)
                {
                    Talk(SAY_ZAELA_EVENT_3);
                }
            }

            void JustDied(Unit* who)
            {

            }

            void UpdateAI(const uint32 diff)
            {

            }

        private:

        };
};

class npc_galakras_korkron_elite_sniper : public CreatureScript
{
    public:
        npc_galakras_korkron_elite_sniper() : CreatureScript("npc_galakras_korkron_elite_sniper") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_korkron_elite_sniperAI(creature);
        }

        struct npc_galakras_korkron_elite_sniperAI : public Scripted_NoMovementAI
        {
            npc_galakras_korkron_elite_sniperAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);

                // wrong item
                SetEquipmentSlots(false, 0, 0, DISPLAY_ITEM_KORKRON_HAND_CANNON);

                shootTimer = 3000;
            }

            void UpdateAI(const uint32 diff)
            {
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                // TODO: maybe it's better to put the function in MoveInLineOfSight
                ShootAtNearPlayer(diff);
            }

        private:

            void ShootAtNearPlayer(const uint32 diff)
            {
                if (shootTimer <= diff)
                {
                    shootTimer = 3000;
                    if (Player* player = GetNearestPlayer())
                    {
                        DoCast(player, SPELL_SNIPED);
                    }
                }
                else
                {
                    shootTimer -= diff;
                }
            }

            Player* GetNearestPlayer()
            {
                Player* player = me->SelectNearestPlayer(100.0f);

                // HACK: temporary for debugging
                if (player && player->IsGameMaster())
                    return NULL;

                return player;
            }

        private:

            uint32 shootTimer;

        };
};

struct npc_galakras_tower_defender : public ScriptedAI
{
    public:

        npc_galakras_tower_defender(Creature* creature) : ScriptedAI(creature)
        {
            //ApplyAllImmunities(true);

            me->setActive(true);
            me->SetReactState(REACT_DEFENSIVE);

            pInstance = creature->GetInstanceScript();
            m_Defender = TowerDefenders::DEFENDER_NONE;
        }

        void SetData(uint32 type, uint32 data)
        {
            if (type == DATA_LEFT_TOWER_DEFENDER)
            {
                m_Defender = LEFT_TOWER_DEFENDER;
            }
            else if (type == DATA_RIGHT_TOWER_DEFENDER)
            {
                m_Defender = RIGHT_TOWER_DEFENDER;
            }
        }

        void JustDied(Unit* killer)
        {
            if (Creature* pGalakras = GetGalakras())
            {
                if (m_Defender == TowerDefenders::LEFT_TOWER_DEFENDER)
                {
                    pGalakras->AI()->SetData(DATA_LEFT_TOWER_DEFENDER_DIED, DONE);
                }
                else if (m_Defender == TowerDefenders::RIGHT_TOWER_DEFENDER)
                {
                    pGalakras->AI()->SetData(DATA_RIGHT_TOWER_DEFENDER_DIED, DONE);
                }
            }
        }

    protected:

        bool IsLeftTower() const { return m_Defender == TowerDefenders::LEFT_TOWER_DEFENDER; }
        bool IsRightTower() const { return m_Defender == TowerDefenders::RIGHT_TOWER_DEFENDER; }

    protected:

        InstanceScript* pInstance;
        TowerDefenders m_Defender;

    protected:

        Creature* GetGalakras()
        {
            if (pInstance)
            {
                return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_GALAKRAS));
            }

            return NULL;
        }
};

struct npc_galakras_tower_defender_NoMovement : npc_galakras_tower_defender
{
    public:

        npc_galakras_tower_defender_NoMovement(Creature* creature) : npc_galakras_tower_defender(creature)
        {
        }

        void AttackStart(Unit* who)
        {
            if (!who)
                return;

            if (me->Attack(who, true))
                DoStartNoMovement(who);
        }
};

class npc_galakras_master_cannoneer_dagryn : public CreatureScript
{
    public:
        npc_galakras_master_cannoneer_dagryn() : CreatureScript("npc_galakras_master_cannoneer_dagryn") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_master_cannoneer_dagrynAI(creature);
        }

        struct npc_galakras_master_cannoneer_dagrynAI : public npc_galakras_tower_defender_NoMovement
        {
            npc_galakras_master_cannoneer_dagrynAI(Creature* creature) : npc_galakras_tower_defender_NoMovement(creature)
            {
                SetEquipmentSlots(false, -1, -1, DISPLAY_ITEM_KORKRON_HAND_CANNON);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_SHOOT, 1000);
                events.ScheduleEvent(EVENT_MUZZLE_SPRAY, urand(5000, 10000));
            }

            void JustDied(Unit* who)
            {
                npc_galakras_tower_defender_NoMovement::JustDied(who);

                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHOOT:
                            DoCastVictim(SPELL_SHOOT);
                            events.ScheduleEvent(EVENT_SHOOT, 1500);
                            break;
                        case EVENT_MUZZLE_SPRAY:
                            // HACK: UpdateVictim triggers SelectVictim, that triggers SetInFront and change orientation before starting cast
                            // It's bad ((
                            // Set correct orientation again
                            me->SetFacingToObject(me->GetVictim());
                            me->SetOrientation(me->GetAngle(me->GetVictim()));
                            DoCastVictim(SPELL_MUZZLE_SPRAY);
                            events.ScheduleEvent(EVENT_MUZZLE_SPRAY, urand(25000, 30000));
                            break;
                    }
                }
            }

        private:

        };
};

class npc_galakras_lieutenant_krugruk : public CreatureScript
{
    public:
        npc_galakras_lieutenant_krugruk() : CreatureScript("npc_galakras_lieutenant_krugruk") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_lieutenant_krugrukAI(creature);
        }

        struct npc_galakras_lieutenant_krugrukAI : public npc_galakras_tower_defender
        {
            npc_galakras_lieutenant_krugrukAI(Creature* creature) : npc_galakras_tower_defender(creature)
            {
                SetEquipmentSlots(false, DISPLAY_TEM_ARCWEAVER_SPELL_SWORD, 0, 0);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_THUNDER_CLAP, urand(4000, 5000));
                events.ScheduleEvent(EVENT_ARCING_SMASH, urand(10000, 12000));
            }

            void JustDied(Unit* who)
            {
                npc_galakras_tower_defender::JustDied(who);

                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_THUNDER_CLAP:
                            DoCastAOE(SPELL_THUNDER_CLAP);
                            events.ScheduleEvent(EVENT_THUNDER_CLAP, urand(10000, 11000));
                            break;
                        case EVENT_ARCING_SMASH:
                            // HACK: UpdateVictim triggers SelectVictim, that triggers SetInFront and change orientation before starting cast
                            // It's bad ((
                            // Set correct orientation again
                            me->SetFacingToObject(me->GetVictim());
                            me->SetOrientation(me->GetAngle(me->GetVictim()));
                            DoCastVictim(SPELL_ARCING_SMASH);
                            events.ScheduleEvent(EVENT_ARCING_SMASH, urand(25000, 30000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_galakras_dragonmaw_flameslinger : public CreatureScript
{
    public:
        npc_galakras_dragonmaw_flameslinger() : CreatureScript("npc_galakras_dragonmaw_flameslinger") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_dragonmaw_flameslingerAI(creature);
        }

        struct npc_galakras_dragonmaw_flameslingerAI : public npc_galakras_tower_defender_NoMovement
        {
            npc_galakras_dragonmaw_flameslingerAI(Creature* creature) : npc_galakras_tower_defender_NoMovement(creature)
            {
                SetEquipmentSlots(false, 0, 0, DISPLAY_ITEM_DAGRYN_DISCARDED_LONGBOW);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_FLAME_ARROWS, 1000);
            }

            void JustDied(Unit* who)
            {
                npc_galakras_tower_defender_NoMovement::JustDied(who);

                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FLAME_ARROWS:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                DoCast(target, SPELL_FLAME_ARROWS);
                            }
                            events.ScheduleEvent(EVENT_FLAME_ARROWS, urand(4000, 5000));
                            break;
                    }
                }
            }
        };
};

class npc_galakras_high_enforcer_thranok : public CreatureScript
{
    public:
        npc_galakras_high_enforcer_thranok() : CreatureScript("npc_galakras_high_enforcer_thranok") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_high_enforcer_thranokAI(creature);
        }

        struct npc_galakras_high_enforcer_thranokAI : public ScriptedAI
        {
            npc_galakras_high_enforcer_thranokAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_CRUSHERS_CALL, urand(10000, 12000));
                events.ScheduleEvent(EVENT_SHATTERING_CLEAVE, 7500);
                events.ScheduleEvent(EVENT_SKULL_CRACKER, urand(25000, 30000));
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CRUSHERS_CALL:
                            DoCastAOE(SPELL_CRUSHERS_CALL_AOE);
                            events.ScheduleEvent(EVENT_CRUSHERS_CALL, urand(20000, 30000));
                            break;
                        case EVENT_SHATTERING_CLEAVE:
                            DoCastVictim(SPELL_SHATTERING_CLEAVE);
                            events.ScheduleEvent(EVENT_SHATTERING_CLEAVE, 7500);
                            break;
                        case EVENT_SKULL_CRACKER:
                            DoCast(me, SPELL_SKULL_CRACKER);
                            events.ScheduleEvent(EVENT_SKULL_CRACKER, 30000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_galakras_korgra_the_snake : public CreatureScript
{
    public:
        npc_galakras_korgra_the_snake() : CreatureScript("npc_galakras_korgra_the_snake") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_korgra_the_snakeAI(creature);
        }

        struct npc_galakras_korgra_the_snakeAI : public ScriptedAI
        {
            npc_galakras_korgra_the_snakeAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                curseOfVenomDone = false;
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_POISON_TIPPED_BLADES, urand(3000, 5000));
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (CheckForCurseOfVenom())
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_POISON_TIPPED_BLADES:
                            DoCastVictim(SPELL_POISON_TIPPED_BLADES);
                            break;
                        case EVENT_VENOM_BOLT_VOLLEY:
                            DoCastAOE(SPELL_VENOM_BOLT_VOLLEY);
                            events.ScheduleEvent(EVENT_VENOM_BOLT_VOLLEY, 10000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:

            bool CheckForCurseOfVenom()
            {
                if (curseOfVenomDone)
                    return false;

                if (!me->HealthBelowPct(50))
                    return false;

                curseOfVenomDone = true;

                DoCast(me, SPELL_CURSE_OF_VENOM);

                events.CancelEvent(EVENT_POISON_TIPPED_BLADES);
                events.ScheduleEvent(EVENT_VENOM_BOLT_VOLLEY, urand(2000, 3000));

                return true;
            }

        private:

            bool curseOfVenomDone;
        };
};

class npc_galakras_dragonmaw_bonecrusher : public CreatureScript
{
    public:
        npc_galakras_dragonmaw_bonecrusher() : CreatureScript("npc_galakras_dragonmaw_bonecrusher") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_dragonmaw_bonecrusherAI(creature);
        }

        struct npc_galakras_dragonmaw_bonecrusherAI : public ScriptedAI
        {
            npc_galakras_dragonmaw_bonecrusherAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_SHATTERING_ROAR, urand(5000, 8000));
                events.ScheduleEvent(EVENT_FRACTURE, urand(5000, 12000));
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHATTERING_ROAR:
                            DoCastAOE(SPELL_SHATTERING_ROAR);
                            events.ScheduleEvent(EVENT_SHATTERING_ROAR, urand(10000, 15000));
                            break;
                        case EVENT_FRACTURE:
                            //DoCastAOE(SPELL_FRACTURE);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        };
};

class npc_galakras_dragonmaw_ebon_stalker : public CreatureScript
{
    public:
        npc_galakras_dragonmaw_ebon_stalker() : CreatureScript("npc_galakras_dragonmaw_ebon_stalker") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_dragonmaw_ebon_stalkerAI(creature);
        }

        struct npc_galakras_dragonmaw_ebon_stalkerAI : public ScriptedAI
        {
            npc_galakras_dragonmaw_ebon_stalkerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_SHADOW_STALK, urand(5000, 12000));
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SHADOW_STALK:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_SHADOW_STALK);
                            events.ScheduleEvent(EVENT_SHADOW_ASSAULT, 500);
                            events.ScheduleEvent(EVENT_SHADOW_STALK, urand(15000, 20000));
                            break;
                        case EVENT_SHADOW_ASSAULT:
                            DoCast(SPELL_SHADOW_ASSAULT);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        };
};

class npc_galakras_dragonmaw_flagbearer : public CreatureScript
{
    public:
        npc_galakras_dragonmaw_flagbearer() : CreatureScript("npc_galakras_dragonmaw_flagbearer") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_dragonmaw_flagbearerAI(creature);
        }

        struct npc_galakras_dragonmaw_flagbearerAI : public ScriptedAI
        {
            npc_galakras_dragonmaw_flagbearerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                me->AddAura(SPELL_DRAGONMAW_FLAGBEARER, me);
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_WAR_BANNER, urand(7000, 10000));
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WAR_BANNER:
                            DoCast(me, SPELL_WAR_BANNER_SUMMON);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_galakras_war_banner : public CreatureScript
{
    public:
        npc_galakras_war_banner() : CreatureScript("npc_galakras_war_banner") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_war_bannerAI(creature);
        }

        struct npc_galakras_war_bannerAI : public Scripted_NoMovementAI
        {
            npc_galakras_war_bannerAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();

                checkCreaturesTimer = 1000;
                despawnTimer = 10000;
                m_IsActive = true;
            }

            void Reset()
            {

            }

            void JustDied(Unit* who)
            {
                StopApplyingAuras();
            }

            void UpdateAI(const uint32 diff)
            {
                if (CheckDespawn(diff))
                {
                    return;
                }

                CheckCreatures(diff);
            }

        private:

            class AllCreatures
            {
                public:
                    AllCreatures(const WorldObject* object, float maxRange) : m_pObject(object), m_fRange(maxRange) {}
                    bool operator() (Unit* unit)
                    {
                        switch (unit->GetEntry())
                        {
                            case NPC_MASTER_CANNONEER_DAGRYN:
                            case NPC_LIEUTENANT_KRUGRUK:
                            case NPC_HIGH_ENFORCER_THRANOK:
                            case NPC_KORGRA_THE_SNAKE:
                            case NPC_DRAGONMAW_FLAMESLINGER:
                            case NPC_DRAGONMAW_BONECRUSHER:
                            case NPC_DRAGONMAW_EBON_STALKER:
                            case NPC_DRAGONMAW_FLAGBEARER:
                            case NPC_DRAGONMAW_GRUNT_1:
                            case NPC_DRAGONMAW_GRUNT_2:
                            case NPC_DRAGONMAW_PROTO_DRAKE:
                            case NPC_DRAGONMAW_TIDAL_SHAMAN:
                                return m_pObject->GetDistance(unit) <= m_fRange;
                            default:
                                return false;
                        }

                        return false;
                    }

                private:
                    const WorldObject* m_pObject;
                    float m_fRange;
            };

        private:

            bool CheckDespawn(const uint32 diff)
            {
                if (!m_IsActive)
                    return true;

                if (despawnTimer <= diff)
                {
                    m_IsActive = false;

                    StopApplyingAuras();

                    return true;
                }
                else
                {
                    despawnTimer -= diff;
                }

                return false;
            }

            void CheckCreatures(const uint32 diff)
            {
                if (!m_IsActive)
                    return;

                if (checkCreaturesTimer <= diff)
                {
                    checkCreaturesTimer = 4000;

                    std::list<Creature*> creatures;

                    SelectCreatures(creatures, 20.0f);

                    for (std::list<Creature*>::iterator itr = creatures.begin(); itr != creatures.end(); ++itr)
                    {
                        if (creatureGuids.find((*itr)->GetGUID()) != creatureGuids.end())
                            continue;

                        creatureGuids.insert((*itr)->GetGUID());

                        (*itr)->AddAura(SPELL_WAR_BANNER_AURA, (*itr));
                    }

                    for (std::set<ObjectGuid>::iterator itr = creatureGuids.begin(); itr != creatureGuids.end();)
                    {
                        ObjectGuid creatureGuid = (*itr);

                        Unit* creature = ObjectAccessor::GetUnit(*me, creatureGuid);
                        if (!creature)
                        {
                            itr = creatureGuids.erase(itr);
                            continue;
                        }

                        if (!creature->IsAlive() || me->GetDistance(creature) > 20.0f)
                        {
                            creature->RemoveAura(SPELL_WAR_BANNER_AURA);
                            itr = creatureGuids.erase(itr);
                            continue;
                        }

                        ++itr;
                    }
                }
                else
                {
                    checkCreaturesTimer -= diff;
                }
            }

            void SelectCreatures(std::list<Creature*>& creatureList, float range)
            {
                CellCoord pair(Trinity::ComputeCellCoord(me->GetPositionX(), me->GetPositionY()));
                Cell cell(pair);
                cell.SetNoCreate();

                AllCreatures check(me, range);
                Trinity::CreatureListSearcher<AllCreatures> searcher(me, creatureList, check);
                TypeContainerVisitor<Trinity::CreatureListSearcher<AllCreatures>, GridTypeMapContainer> visitor(searcher);

                cell.Visit(pair, visitor, *(me->GetMap()), *me, range);
            }

            void StopApplyingAuras()
            {
                m_IsActive = false;

                for (std::set<ObjectGuid>::iterator itr = creatureGuids.begin(); itr != creatureGuids.end(); ++itr)
                {
                    ObjectGuid creatureGuid = (*itr);

                    Unit* creature = ObjectAccessor::GetUnit(*me, creatureGuid);
                    if (!creature)
                    {
                        continue;
                    }

                    creature->RemoveAura(SPELL_WAR_BANNER_AURA);
                }

                creatureGuids.clear();
            }

        private:

            InstanceScript* pInstance;
            uint32 checkCreaturesTimer;
            std::set<ObjectGuid> creatureGuids;
            bool m_IsActive;
            uint32 despawnTimer;
        };
};

class npc_galakras_dragonmaw_grunt_1 : public CreatureScript
{
    public:
        npc_galakras_dragonmaw_grunt_1() : CreatureScript("npc_galakras_dragonmaw_grunt_1") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_dragonmaw_grunt_1AI(creature);
        }

        struct npc_galakras_dragonmaw_grunt_1AI : public ScriptedAI
        {
            npc_galakras_dragonmaw_grunt_1AI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {

            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                }

                DoMeleeAttackIfReady();
            }

        };
};

class npc_galakras_dragonmaw_grunt_2 : public CreatureScript
{
    public:
        npc_galakras_dragonmaw_grunt_2() : CreatureScript("npc_galakras_dragonmaw_grunt_2") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_dragonmaw_grunt_2AI(creature);
        }

        struct npc_galakras_dragonmaw_grunt_2AI : public npc_galakras_tower_defender
        {
            npc_galakras_dragonmaw_grunt_2AI(Creature* creature) : npc_galakras_tower_defender(creature)
            {

            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();

                me->SetReactState(REACT_DEFENSIVE);
            }

            void EnterCombat(Unit* who)
            {

            }

            void JustDied(Unit* who)
            {
                npc_galakras_tower_defender::JustDied(who);

                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                }

                DoMeleeAttackIfReady();
            }

        };
};

class npc_galakras_dragonmaw_proto_drake : public CreatureScript
{
    public:
        npc_galakras_dragonmaw_proto_drake() : CreatureScript("npc_galakras_dragonmaw_proto_drake") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_dragonmaw_proto_drakeAI(creature);
        }

        struct npc_galakras_dragonmaw_proto_drakeAI : public ScriptedAI
        {
            npc_galakras_dragonmaw_proto_drakeAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {

            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                }

                DoMeleeAttackIfReady();
            }

        };
};

class npc_galakras_dragonmaw_tidal_shaman : public CreatureScript
{
    public:
        npc_galakras_dragonmaw_tidal_shaman() : CreatureScript("npc_galakras_dragonmaw_tidal_shaman") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_dragonmaw_tidal_shamanAI(creature);
        }

        struct npc_galakras_dragonmaw_tidal_shamanAI : public ScriptedAI
        {
            npc_galakras_dragonmaw_tidal_shamanAI(Creature* creature) : ScriptedAI(creature)
            {
                me->setActive(true);
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_CHAIN_HEAL, urand(5000, 12000));
                events.ScheduleEvent(EVENT_HEALING_TIDE_TOTEM, urand(10000, 20000));
                events.ScheduleEvent(EVENT_TIDAL_WAVE, 1000);
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TIDAL_WAVE:
                            DoCastAOE(SPELL_TIDAL_WAVE_AOE);
                            events.ScheduleEvent(EVENT_TIDAL_WAVE, 2000);
                            break;
                        case EVENT_HEALING_TIDE_TOTEM:
                            DoCast(me, SPELL_HEALING_TIDE_TOTEM);
                            break;
                        case EVENT_CHAIN_HEAL:
                            DoCast(me, SPELL_CHAIN_HEAL);
                            events.ScheduleEvent(EVENT_CHAIN_HEAL, urand(10000, 15000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        };
};

class npc_galakras_healing_tide_totem : public CreatureScript
{
    public:
        npc_galakras_healing_tide_totem() : CreatureScript("npc_galakras_healing_tide_totem") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_healing_tide_totemAI(creature);
        }

        struct npc_galakras_healing_tide_totemAI : public Scripted_NoMovementAI
        {
            npc_galakras_healing_tide_totemAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);

                pInstance = creature->GetInstanceScript();
            }

            void Reset()
            {
                me->AddAura(SPELL_HEALING_TIDE_AURA, me);
            }

            void UpdateAI(const uint32 diff)
            {

            }

        private:

            InstanceScript* pInstance;
        };
};

class npc_galakras_anti_air_turret : public CreatureScript
{
    public:
        npc_galakras_anti_air_turret() : CreatureScript("npc_galakras_anti_air_turret") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_anti_air_turretAI(creature);
        }

        // prevent menu
        bool OnGossipHello(Player* player, Creature* creature) override
        {
            return true;
        }

        struct npc_galakras_anti_air_turretAI : public ScriptedAI
        {
            npc_galakras_anti_air_turretAI(Creature* creature) : ScriptedAI(creature)
            {
                //me->SetUnitFlags(UnitFlags(UNIT_FLAG_DISABLE_MOVE);
                SetCombatMovement(false);
                me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));

                pInstance = creature->GetInstanceScript();
                cooldownTimer = 0;
            }

            void Reset()
            {
                enabled = true;
            }

            void sGossipHello(Player* player) override
            {
                if (!enabled)
                    return;

                if (cooldownTimer)
                    return;

                if (!player->IsInCombat())
                    return;

                if (me->FindNearestCreature(NPC_LIEUTENANT_KRUGRUK, 10.0f) ||
                    me->FindNearestCreature(NPC_MASTER_CANNONEER_DAGRYN, 10.0f))
                    return;

                if (Creature* pGalakras = GetGalakras())
                {
                    cooldownTimer = ANTI_AIR_TURRET_COOLDOWN;
                    DoCast(pGalakras, SPELL_ANTI_AIR_CANNON);
                }
             }

            void DoAction(const int32 action)
            {
                if (action == ACTION_RIGHT_TOWER_ALL_DEFENDERS_DIED)
                {
                    if (IsRightTower())
                    {
                        me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
                    }
                }
                else if (action == ACTION_LEFT_TOWER_ALL_DEFENDERS_DIED)
                {
                    if (IsLeftTower())
                    {
                        me->SetUnitFlags(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));
                    }
                }
                else if (action == ACTION_GALAKRAS_DOWN)
                {
                    enabled = false;
                    me->RemoveUnitFlag(UnitFlags(UNIT_NPC_FLAG_GOSSIP));
                    me->SetUnitFlags(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC));

                    if (me->GetVehicleKit())
                    {
                        me->GetVehicleKit()->RemoveAllPassengers();
                    }
                }
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_LEFT_TOWER_DEFENDER)
                {
                    m_IsLeftTower = true;
                }
                else if (type == DATA_RIGHT_TOWER_DEFENDER)
                {
                    m_IsLeftTower = false;
                }
            }

            void UpdateAI(const uint32 diff)
            {
                if (!cooldownTimer)
                    return;

                if (cooldownTimer <= diff)
                {
                    cooldownTimer = 0;
                }
                else
                {
                    cooldownTimer -= diff;
                }
            }

        private:

            Creature* GetGalakras()
            {
                if (pInstance)
                {
                    return pInstance->instance->GetCreature(pInstance->GetObjectGuid(DATA_GALAKRAS));
                }

                return NULL;
            }

            bool IsLeftTower() const { return m_IsLeftTower; }
            bool IsRightTower() const { return !m_IsLeftTower; }

        private:

            InstanceScript* pInstance;
            bool m_IsLeftTower;
            uint32 cooldownTimer;
            bool enabled;
        };
};

class npc_galakras_tower : public CreatureScript
{
    public:
        npc_galakras_tower() : CreatureScript("npc_galakras_tower") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_towerAI(creature);
        }

        struct npc_galakras_towerAI : public npc_galakras_tower_defender_NoMovement
        {
            npc_galakras_towerAI(Creature* creature) : npc_galakras_tower_defender_NoMovement(creature)
            {
                playersSelectTimer = 2000;
                defendersLeft = DEFENDERS_COUNT;
            }

            void Reset()
            {

            }

            void DoAction(const int32 action)
            {
                if (action == ACTION_LEFT_TOWER_DEFENDER_DIED)
                {
                    HandleLeftTowerDefenderDied();
                }
                else if (action == ACTION_RIGHT_TOWER_DEFENDER_DIED)
                {
                    HandleRightTowerDefenderDied();
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_DEFENDERS_LEFT)
                {
                    return defendersLeft;
                }

                return 0;
            }

            void DamageTaken(Unit* who, uint32& damage) override
            {
                damage = 0;
            }

            void UpdateAI(const uint32 diff)
            {
                SelectPlayers(diff);
            }

        private:

            class AnyPlayerInObjectRange2dCheck
            {
                public:
                    AnyPlayerInObjectRange2dCheck(WorldObject const* obj, float range) : _obj(obj), _range(range) {}
                    bool operator()(Player* u)
                    {
                        if (_obj->GetDistance2d(u) > _range)
                            return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _range;
            };

        private:

            void SelectPlayers(const uint32 diff)
            {
                if (playersSelectTimer <= diff)
                {
                    playersSelectTimer = 3000;

                    std::list<Player*> players;
                    SelectPlayersOnGrid(players, 15.0f);
                    for (Player* player : players)
                    {
                        if (IsPlayerInTower(player->GetGUID()))
                            continue;

                        ApplyTowerAurasOnPlayer(player, true);
                        m_PlayersInTower.insert(player->GetGUID());
                    }

                    for (std::set<ObjectGuid>::iterator itr = m_PlayersInTower.begin(); itr != m_PlayersInTower.end();)
                    {
                        ObjectGuid playerGuid = (*itr);

                        Player* player = ObjectAccessor::FindPlayer(playerGuid);
                        if (!player)
                        {
                            itr = m_PlayersInTower.erase(itr);
                            continue;
                        }

                        float dist = me->GetDistance2d(player);
                        if (dist > 15.0f)
                        {
                            ApplyTowerAurasOnPlayer(player, false);
                            itr = m_PlayersInTower.erase(itr);
                            continue;
                        }

                        ++itr;
                    }
                }
                else
                {
                    playersSelectTimer -= diff;
                }
            }

            bool IsPlayerInTower(ObjectGuid guid) const
            {
                return (m_PlayersInTower.find(guid) != m_PlayersInTower.end());
            }

            void ApplyTowerAurasOnPlayer(Player* player, bool apply)
            {
                if (apply)
                {
                    me->AddAura(SPELL_IN_A_TOWER, player);
                    me->AddAura(SPELL_TOWER_STRENGTH, player);
                }
                else
                {
                    player->RemoveAura(SPELL_IN_A_TOWER);
                    player->RemoveAura(SPELL_TOWER_STRENGTH);
                }
            }

            void SelectPlayersOnGrid(std::list<Player*>& players, float range)
            {
                AnyPlayerInObjectRange2dCheck checker(me, range);
                Trinity::PlayerListSearcher<AnyPlayerInObjectRange2dCheck> searcher(me, players, checker);
                //me->VisitNearbyWorldObject(range, searcher);
                Cell::VisitWorldObjects(me, searcher, range);
            }

            void HandleLeftTowerDefenderDied()
            {
                if (!IsLeftTower())
                    return;

                if (defendersLeft == 0)
                    return;

                defendersLeft--;

                if (defendersLeft == 0)
                {
                    SendAllDefendersDied();
                }
            }

            void HandleRightTowerDefenderDied()
            {
                if (!IsRightTower())
                    return;

                if (defendersLeft == 0)
                    return;

                defendersLeft--;

                if (defendersLeft == 0)
                {
                    SendAllDefendersDied();
                }
            }

            void SendAllDefendersDied()
            {
                if (Creature* pGalakras = GetGalakras())
                {
                    if (IsLeftTower())
                    {
                        pGalakras->AI()->SetData(DATA_LEFT_TOWER_ALL_DEFENDERS_DIED, DONE);
                    }
                    else if (IsRightTower())
                    {
                        pGalakras->AI()->SetData(DATA_RIGHT_TOWER_ALL_DEFENDERS_DIED, DONE);
                    }
                }
            }

        private:

            uint32 playersSelectTimer;
            std::set<ObjectGuid> m_PlayersInTower;
            uint32 defendersLeft;
        };
};

class npc_galakras_korkron_demolisher : public CreatureScript
{
    public:
        npc_galakras_korkron_demolisher() : CreatureScript("npc_galakras_korkron_demolisher") { }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_galakras_korkron_demolisherAI(creature);
        }

        struct npc_galakras_korkron_demolisherAI : public ScriptedAI
        {
            npc_galakras_korkron_demolisherAI(Creature* creature) : ScriptedAI(creature)
            {
                //ApplyAllImmunities(true);

                me->setActive(true);

                me->SetReactState(REACT_PASSIVE);

                m_TowerAttacker = TowerAttackers::ATTACKER_NONE;
            }

            void Reset()
            {
                events.Reset();
                summons.DespawnAll();
            }

            void EnterCombat(Unit* who)
            {
                events.ScheduleEvent(EVENT_MOVE_TO_ATTACK, 500);
            }

            void SetData(uint32 type, uint32 data)
            {
                if (type == DATA_LEFT_TOWER_ATTACKER)
                {
                    m_TowerAttacker = TowerAttackers::LEFT_TOWER_ATTACKER;
                }
                else if (type == DATA_RIGHT_TOWER_ATTACKER)
                {
                    m_TowerAttacker = TowerAttackers::RIGHT_TOWER_ATTACKER;
                }
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type == POINT_MOTION_TYPE)
                {
                    if (id == POINT_DEMOLISHER_ATTACK_LEFT)
                    {
                        me->GetMotionMaster()->MovementExpired(false);
                        me->SetFacingTo(me->GetAngle(&demolisherAttackPos[2]));
                        events.ScheduleEvent(EVENT_BOMBARD, 1000);
                    }
                    else if (id == POINT_DEMOLISHER_ATTACK_RIGHT)
                    {
                        me->GetMotionMaster()->MovementExpired(false);
                        me->SetFacingTo(me->GetAngle(&demolisherAttackPos[3]));
                        events.ScheduleEvent(EVENT_BOMBARD, 1000);
                    }
                }
            }

            void JustDied(Unit* who)
            {
                events.Reset();
                summons.DespawnAll();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_TO_ATTACK:
                            if (IsLeftTowerAttacker())
                            {
                                me->GetMotionMaster()->MovePoint(POINT_DEMOLISHER_ATTACK_LEFT, demolisherAttackPos[0]);
                            }
                            else if (IsRightTowerAttacker())
                            {
                                me->GetMotionMaster()->MovePoint(POINT_DEMOLISHER_ATTACK_RIGHT, demolisherAttackPos[1]);
                            }
                            break;
                        case EVENT_BOMBARD:
                            if (IsLeftTowerAttacker())
                            {
                                me->CastSpell(demolisherAttackPos[2], 148302, false);
                            }
                            else if (IsRightTowerAttacker())
                            {
                                me->CastSpell(demolisherAttackPos[3], 148302, false);
                            }
                            events.ScheduleEvent(EVENT_BOMBARD, 5000);
                            break;
                    }
                }
            }

        private:

            bool IsRightTowerAttacker() const { return m_TowerAttacker == TowerAttackers::RIGHT_TOWER_ATTACKER; }
            bool IsLeftTowerAttacker() const { return m_TowerAttacker == TowerAttackers::LEFT_TOWER_ATTACKER; }

        private:

            TowerAttackers m_TowerAttacker;

        };
};

class spell_galakras_flame_arrows_missile : public SpellScriptLoader
{
    public:
        spell_galakras_flame_arrows_missile() : SpellScriptLoader("spell_galakras_flame_arrows_missile") { }

        class spell_galakras_flame_arrows_missile_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_galakras_flame_arrows_missile_SpellScript);

            void HandleHit(SpellEffIndex effIndex)
            {
                if (!GetCaster())
                    return;

                // HACK: do this because
                // 1. spellEffect is SPELL_EFFECT_TRIGGER_MISSILE
                // 2. TargetA is TARGET_DEST_TARGET_ENEMY
                // 3. so spell is not dest, and it executes with caster as target
                // we should prevent it and cast spell right
                PreventHitEffect(effIndex);

                Unit* target = GetExplTargetUnit();
                if (!target)
                    return;

                GetCaster()->CastSpell(target, SPELL_FLAME_ARROWS_DMG, true);
            }

            void Register()
            {
                OnEffectHit += SpellEffectFn(spell_galakras_flame_arrows_missile_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_galakras_flame_arrows_missile_SpellScript();
        }
};

class spell_galakras_crushers_call_aoe : public SpellScriptLoader
{
    public:
        spell_galakras_crushers_call_aoe() : SpellScriptLoader("spell_galakras_crushers_call_aoe") { }

        class spell_galakras_crushers_call_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_galakras_crushers_call_aoe_SpellScript);

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                // TODO: Use trigger spell, but not jump spell

                GetHitUnit()->CastSpell(GetCaster(), SPELL_CRUSHERS_CALL_JUMP, true);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_galakras_crushers_call_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_galakras_crushers_call_aoe_SpellScript();
        }
};

class spell_galakras_anti_air_cannon_aura : public SpellScriptLoader
{
    public:
        spell_galakras_anti_air_cannon_aura() : SpellScriptLoader("spell_galakras_anti_air_cannon_aura") { }

        class spell_galakras_anti_air_cannon_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_galakras_anti_air_cannon_aura_AuraScript);

            void HandleApply(AuraEffect const* aurEff, AuraEffectHandleModes mode)
            {
                if (!GetUnitOwner())
                    return;

                if (Aura* aur = GetAura())
                {
                    uint8 stacks = aur->GetStackAmount();

                    if (stacks >= ANTI_AIR_TURRET_HITS)
                    {
                        if (Creature* pGalakras = GetUnitOwner()->ToCreature())
                        {
                            pGalakras->AI()->DoAction(ACTION_GALAKRAS_DOWN);
                        }
                    }
                }
                //if (Creature* pGalakras = GetUnitOwner()->ToCreature())
                //{
                //    pGalakras->AI()->DoAction(ACTION_GALAKRAS_DOWN);
                //}
            }

            void Register()
            {
                AfterEffectApply += AuraEffectRemoveFn(spell_galakras_anti_air_cannon_aura_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_STRANGULATE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_galakras_anti_air_cannon_aura_AuraScript();
        }
};

class spell_galakras_tower_strength : public SpellScriptLoader
{
    public:
        spell_galakras_tower_strength() : SpellScriptLoader("spell_galakras_tower_strength") { }

        class spell_galakras_tower_strength_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_galakras_tower_strength_AuraScript);

            void HandlePeriodicTick(AuraEffect const* aurEff)
            {
                if (!GetUnitOwner())
                    return;

                ObjectGuid casterGuid = GetCasterGUID();

                Unit* owner = GetUnitOwner();

                Creature* caster = ObjectAccessor::GetCreature(*owner, casterGuid);
                if (!caster)
                {
                    Remove();
                    return;
                }

                uint32 defendersLeft = caster->AI()->GetData(DATA_DEFENDERS_LEFT);
                if (!defendersLeft)
                {
                    Remove();
                    return;
                }

                uint32 currentPower = owner->GetPower(POWER_ALTERNATE_POWER);
                uint32 newPower = 100 - ((DEFENDERS_COUNT - defendersLeft) * 10);

                if (currentPower != newPower)
                {
                    owner->SetPower(POWER_ALTERNATE_POWER, newPower);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_galakras_tower_strength_AuraScript::HandlePeriodicTick, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_galakras_tower_strength_AuraScript();
        }
};

class spell_galakras_tidal_wave_aoe : public SpellScriptLoader
{
    public:
        spell_galakras_tidal_wave_aoe() : SpellScriptLoader("spell_galakras_tidal_wave_aoe") { }

        class spell_galakras_tidal_wave_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_galakras_tidal_wave_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResize(targets, 1);
            }

            void HandleHitTarget(SpellEffIndex effIndex)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetHitUnit(), SPELL_TIDAL_WAVE_DUMMY, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_TIDAL_WAVE_DMG, true);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_galakras_tidal_wave_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_galakras_tidal_wave_aoe_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_galakras_tidal_wave_aoe_SpellScript();
        }
};

class spell_galakras_shattering_roar : public SpellScriptLoader
{
    public:
        spell_galakras_shattering_roar() : SpellScriptLoader("spell_galakras_shattering_roar") { }

        class spell_galakras_shattering_roar_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_galakras_shattering_roar_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_IN_A_TOWER));
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_galakras_shattering_roar_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_galakras_shattering_roar_SpellScript();
        }
};

struct spell_area_galakras_flame_arrows_dmg : AreaTriggerAI
{
    spell_area_galakras_flame_arrows_dmg(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* target)
    {
        if (!at->GetCaster())
            return;

        if (!target->isTargetableForAttack())
            return;

        at->GetCaster()->AddAura(SPELL_FLAME_ARROWS_PERIODIC, target);
    }

    void OnUnitExit(Unit* target)
    {
        target->RemoveAura(SPELL_FLAME_ARROWS_PERIODIC);
    }
};

struct spell_area_galakras_flames_of_galakrond : AreaTriggerAI
{
    spell_area_galakras_flames_of_galakrond(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate() override
    {
        Unit* caster = ObjectAccessor::GetUnit(*at, at->GetCasterGuid());
        if (!caster)
            return;

        Creature* pCreature = caster->ToCreature();
        if (!pCreature)
            return;

        InstanceScript* pinstance = pCreature->GetInstanceScript();
        ObjectGuid targetGuid = pinstance->GetObjectGuid(DATA_LAST_FLAMES_OF_GALAKROND_TARGET);
        //ObjectGuid targetGuid = pCreature->GetAI()->GetData(DATA_LAST_FLAMES_OF_GALAKROND_TARGET);

        Unit* target = ObjectAccessor::GetUnit(*at, targetGuid);
        if (!target)
            return;

        at->Relocate(*pCreature);
        //at->SetSource(*pCreature);

        at->SetDestination(*target, 0);
        //trigger->SetTrajectory(AreatriggerInterpolation::AREATRIGGER_INTERPOLATION_LINEAR);

        if (GalakrasAI* galakrasAI = CAST_AI(GalakrasAI, pCreature->GetAI()))
        {
            galakrasAI->GetFlamesOfGalakrond().AddFlame(at->GetGUID(), targetGuid);
        }
    }

    void OnUnitEnter(Unit* target)
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (!target->isTargetableForAttack())
            return;

        //if (target->HasAura(SPELL_FLAMES_OF_GALAKROND_PERIODIC))
        //    return false;

        caster->AddAura(SPELL_FLAMES_OF_GALAKROND_PERIODIC, target);

        if (Creature* pCreature = caster->ToCreature())
        {
            if (GalakrasAI* galakrasAI = CAST_AI(GalakrasAI, pCreature->GetAI()))
            {
                galakrasAI->GetFlamesOfGalakrond().FlameHitTarget(at->GetGUID());
            }
        }
    }

    void OnUnitExit(Unit* target)
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        Creature* pCreature = caster->ToCreature();
        if (!pCreature)
            return;

        uint32 hitCount = 0;
        if (GalakrasAI* galakrasAI = CAST_AI(GalakrasAI, pCreature->GetAI()))
        {
            hitCount = galakrasAI->GetFlamesOfGalakrond().GetFlameHitCount(at->GetGUID());
        }

        // We need to change spell damage and cast spell with position
        // there is no default function to to it

        SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_FLAMES_OF_GALAKROND_DMG);
        if (!l_SpellInfo)
            return;

        int32 reduceCoeff = pCreature->GetMap()->IsHeroic() ? 200000 : 100000;
        //int32 damage = l_SpellInfo->Effects[EFFECT_0].CalcValue();
        int32 damage = l_SpellInfo->GetEffect(EFFECT_0)->CalcValue();

        int32 totalDamage = damage - (reduceCoeff * hitCount);
        if (totalDamage < 100000)
            totalDamage = urand(50000, 100000);

        CustomSpellValues l_Values;
        l_Values.AddSpellMod(SpellValueMod::SPELLVALUE_BASE_POINT0, totalDamage);

        SpellCastTargets l_Targets;
        l_Targets.SetDst(*at);

        caster->CastSpell(l_Targets, l_SpellInfo, &l_Values, TriggerCastFlags::TRIGGERED_FULL_MASK);

        if (GalakrasAI* galakrasAI = CAST_AI(GalakrasAI, pCreature->GetAI()))
        {
            galakrasAI->GetFlamesOfGalakrond().RemoveFlame(at->GetGUID());
        }
    }
};

void AddSC_boss_galakras()
{
    new boss_galakras();                            // 72249
    new npc_galakras_warlord_zaela();               // 72248
    new npc_galakras_korkron_elite_sniper();        // 72261
    new npc_galakras_master_cannoneer_dagryn();     // 72356
    new npc_galakras_lieutenant_krugruk();          // 72357
    new npc_galakras_dragonmaw_flameslinger();      // 72353
    new npc_galakras_high_enforcer_thranok();       // 72355
    new npc_galakras_korgra_the_snake();            // 72456
    new npc_galakras_dragonmaw_bonecrusher();       // 72945
    new npc_galakras_dragonmaw_ebon_stalker();      // 72352
    new npc_galakras_dragonmaw_flagbearer();        // 72942
    new npc_galakras_war_banner();                  // 73088
    new npc_galakras_dragonmaw_grunt_1();           // 72941
    new npc_galakras_dragonmaw_grunt_2();           // 73530
    new npc_galakras_dragonmaw_proto_drake();       // 72943
    new npc_galakras_dragonmaw_tidal_shaman();      // 72958
    new npc_galakras_healing_tide_totem();          // 73094
    new npc_galakras_anti_air_turret();             // 72408
    new npc_galakras_tower();                       // 73565 73628
    new npc_galakras_korkron_demolisher();          // 72947

    new spell_galakras_flame_arrows_missile();      // 146763, 147552
    new spell_galakras_crushers_call_aoe();         // 146769
    new spell_galakras_anti_air_cannon_aura();      // 147514
    new spell_galakras_tower_strength();            // 148120
    new spell_galakras_tidal_wave_aoe();            // 148522
    new spell_galakras_shattering_roar();           // 147204

    RegisterAreaTriggerAI(spell_area_galakras_flame_arrows_dmg);     // 146764
    RegisterAreaTriggerAI(spell_area_galakras_flames_of_galakrond);  // 146991
}
