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

#include "culling_of_stratholme.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureTextMgr.h"
#include "EventMap.h"
#include "GameObject.h"
#include "GameTime.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Log.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellInfo.h"
#include "TemporarySummon.h"
#include "WorldStatePackets.h"
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 *  Culling of Stratholme encounters:
 *  0 - Meathook
 *  1 - Salramm the Fleshcrafter
 *  2 - Chrono-Lord Epoch
 *  3 - Mal'Ganis
 *  4 - Infinite Corruptor (Heroic only)
 */

enum COSEvents
{
    EVENT_GUARDIAN_TICK = 1,
    EVENT_RESPAWN_ARTHAS,
    EVENT_CRIER_CALL_TO_GATES,
    EVENT_SCOURGE_WAVE,
    EVENT_CRIER_ANNOUNCE_WAVE
};

enum COSEntries
{
    NPC_GENERIC_BUNNY        = 28960,
    NPC_CRATE_HELPER         = 27827,
    NPC_CHROMIE              = 26527, // first chromie - we don't need the other two for anything
    NPC_INFINITE_CORRUPTOR   = 32273,
    NPC_GUARDIAN_OF_TIME     = 32281,
    NPC_TIME_RIFT            = 28409,
    NPC_LORDAERON_CRIER      = 27913,
    NPC_DEVOURING_GHOUL      = 28249,
    NPC_ENRAGED_GHOUL        = 27729,
    NPC_NECROMANCER          = 28200,
    NPC_CRYPT_FIEND          = 27734,
    NPC_ACOLYTE              = 27731,
    NPC_CRYPT_STALKER        = 28199,
    NPC_ABOMINATION          = 27736,
    NPC_MEATHOOK             = 26529,
    NPC_SALRAMM              = 26530,

    GO_MALGANIS_GATE_2       = 187723,
    GO_EXIT_GATE             = 191788,

    SPELL_CRATES_KILL_CREDIT = 58109
};

enum COSYells
{
    CRIER_SAY_CALL_TO_GATES    = 0,
    CRIER_SAY_KINGS_SQUARE     = 1,
    CRIER_SAY_MARKET_ROW       = 2,
    CRIER_SAY_FESTIVAL_LANE    = 3,
    CRIER_SAY_ELDERS_SQUARE    = 4,
    CRIER_SAY_TOWN_HALL        = 5,

    CHROMIE_WHISPER_GUARDIAN_1 = 0,
    CHROMIE_WHISPER_GUARDIAN_2 = 1,
    CHROMIE_WHISPER_GUARDIAN_3 = 2
};

enum COSWorldStates
{
    WORLDSTATE_SHOW_CRATES        = 3479,
    WORLDSTATE_CRATES_REVEALED    = 3480,
    WORLDSTATE_WAVE_COUNT         = 3504,
    WORLDSTATE_WAVE_MARKER_ES     = 3581,
    WORLDSTATE_WAVE_MARKER_FL     = 3582,
    WORLDSTATE_WAVE_MARKER_KS     = 3583,
    WORLDSTATE_WAVE_MARKER_MR     = 3584,
    WORLDSTATE_WAVE_MARKER_TH     = 3585,
    WORLDSTATE_TIME_GUARDIAN      = 3931,
    WORLDSTATE_TIME_GUARDIAN_SHOW = 3932
};

enum COSWaveLocations
{
    WAVE_LOC_MIN = CRIER_SAY_KINGS_SQUARE,
    WAVE_LOC_MAX = CRIER_SAY_TOWN_HALL,
    WAVE_MARKER_MIN = WORLDSTATE_WAVE_MARKER_ES,
    WAVE_MARKER_MAX = WORLDSTATE_WAVE_MARKER_TH
};

enum COSMisc
{
    NUM_PLAGUE_CRATES   = 5,
    NUM_SCOURGE_WAVES   = 10,
    MAX_SPAWNS_PER_WAVE = 6,
    WAVE_MEATHOOK       = 5,
    WAVE_SALRAMM        = 10
};

DoorData const doorData[] =
{
    { GO_MALGANIS_GATE_2, DATA_MAL_GANIS, DOOR_TYPE_ROOM },
    { GO_EXIT_GATE,       DATA_MAL_GANIS, DOOR_TYPE_PASSAGE },
    { 0,                  0,              DOOR_TYPE_ROOM } // END
};

COSProgressStates GetStableStateFor(COSProgressStates const state)
{
    switch (state)
    {
        case JUST_STARTED:
        default:
            return JUST_STARTED;
        case CRATES_IN_PROGRESS:
            return CRATES_IN_PROGRESS;
        case CRATES_DONE:
            return CRATES_DONE;
        case UTHER_TALK:
        case PURGE_PENDING:
        case PURGE_STARTING:
        case WAVES_IN_PROGRESS:
            return PURGE_PENDING;
        case WAVES_DONE:
        case TOWN_HALL_PENDING:
        case TOWN_HALL:
            return TOWN_HALL_PENDING;
        case TOWN_HALL_COMPLETE:
        case GAUNTLET_TRANSITION:
        case GAUNTLET_PENDING:
        case GAUNTLET_IN_PROGRESS:
            return GAUNTLET_PENDING;
        case GAUNTLET_COMPLETE:
        case MALGANIS_IN_PROGRESS:
            return GAUNTLET_COMPLETE;
        case COMPLETE:
            return COMPLETE;
    }
}

static Position const CorruptorPos = { 2331.642f, 1273.273f, 132.9524f, 3.717551f };
static Position const GuardianPos = { 2321.489f, 1268.383f, 132.8507f, 0.418879f };
static Position const CorruptorRiftPos = { 2443.626f, 1280.450f, 133.0066f, 1.727876f };

static std::array<std::array<uint32, MAX_SPAWNS_PER_WAVE>, NUM_SCOURGE_WAVES> const HeroicWaves =
{
    {
        { { NPC_DEVOURING_GHOUL, NPC_DEVOURING_GHOUL, NPC_DEVOURING_GHOUL                                      } }, // wave 1
        { { NPC_DEVOURING_GHOUL, NPC_ENRAGED_GHOUL,   NPC_NECROMANCER                                          } }, // wave 2
        { { NPC_DEVOURING_GHOUL, NPC_ENRAGED_GHOUL,   NPC_NECROMANCER,   NPC_CRYPT_FIEND                       } }, // wave 3
        { { NPC_NECROMANCER,     NPC_CRYPT_FIEND,     NPC_ACOLYTE,       NPC_ACOLYTE, NPC_ACOLYTE, NPC_ACOLYTE } }, // wave 4
        { { 0                                                                                                  } }, // wave 5, meathook (special)
        { { NPC_DEVOURING_GHOUL, NPC_NECROMANCER,     NPC_CRYPT_FIEND,   NPC_CRYPT_STALKER                     } }, // wave 6
        { { NPC_DEVOURING_GHOUL, NPC_ENRAGED_GHOUL,   NPC_ENRAGED_GHOUL, NPC_ABOMINATION                       } }, // wave 7
        { { NPC_DEVOURING_GHOUL, NPC_ENRAGED_GHOUL,   NPC_NECROMANCER,   NPC_ABOMINATION                       } }, // wave 8
        { { NPC_DEVOURING_GHOUL, NPC_NECROMANCER,     NPC_CRYPT_FIEND,   NPC_ABOMINATION                       } }, // wave 9
        { { 0                                                                                                  } } // wave 10, salramm (special)
    }
};

struct WaveLocation
{
    COSWorldStates const WorldState;
    std::array<Position, MAX_SPAWNS_PER_WAVE> SpawnPoints;
};

static const std::array<WaveLocation, WAVE_LOC_MAX - WAVE_LOC_MIN + 1> WaveLocations =
{
    {
        { // King's Square
            WORLDSTATE_WAVE_MARKER_KS,
            {
                {
                    { 2131.474f, 1352.615f, 131.372f, 6.10960f },
                    { 2131.463f, 1357.127f, 131.587f, 5.95173f },
                    { 2129.795f, 1345.093f, 131.194f, 0.17905f },
                    { 2136.235f, 1347.894f, 131.628f, 0.20262f },
                    { 2138.219f, 1356.240f, 132.169f, 5.95173f },
                    { 2140.584f, 1351.624f, 132.142f, 6.08525f }
                }
            }
        },
        { // Market Row
            WORLDSTATE_WAVE_MARKER_MR,
            {
                {
                    { 2226.364f, 1331.808f, 127.0193f, 3.298672f },
                    { 2229.934f, 1329.146f, 127.057f,  3.24605f },
                    { 2225.028f, 1327.269f, 127.791f,  3.03792f },
                    { 2223.844f, 1335.282f, 127.749f,  3.47774f },
                    { 2222.192f, 1330.859f, 127.526f,  3.18793f },
                    { 2225.865f, 1331.029f, 127.007f,  3.18793f }
                }
            }
        },
        { // Festival Lane
            WORLDSTATE_WAVE_MARKER_FL,
            {
                {
                    { 2183.596f, 1238.823f, 136.551f, 2.16377f },
                    { 2181.420f, 1237.357f, 136.565f, 2.16377f },
                    { 2178.692f, 1237.446f, 136.694f, 1.99098f },
                    { 2184.980f, 1242.458f, 136.772f, 2.59181f },
                    { 2176.873f, 1240.463f, 136.420f, 2.10094f },
                    { 2181.523f, 1244.298f, 136.338f, 2.38997f }
                }
            }
        },
        { // Elders' Square
            WORLDSTATE_WAVE_MARKER_ES,
            {
                {
                    { 2267.003f, 1168.055f, 137.821f, 2.79050f },
                    { 2264.392f, 1162.145f, 137.910f, 2.39937f },
                    { 2262.785f, 1166.648f, 138.053f, 2.71353f },
                    { 2265.214f, 1170.771f, 137.972f, 2.80385f },
                    { 2259.745f, 1159.360f, 138.198f, 2.34047f },
                    { 2264.222f, 1171.708f, 138.047f, 2.82742f }
                }
            }
        },
        { // Town Hall
            WORLDSTATE_WAVE_MARKER_TH,
            {
                {
                    { 2351.656f, 1218.682f, 130.062f, 4.63383f },
                    { 2354.921f, 1218.425f, 130.280f, 4.63383f },
                    { 2347.516f, 1216.976f, 130.491f, 5.02496f },
                    { 2356.508f, 1216.656f, 130.445f, 4.29061f },
                    { 2346.674f, 1216.739f, 130.576f, 5.32341f },
                    { 2351.728f, 1214.561f, 130.255f, 4.61891f }
                }
            }
        }
    }
};

class instance_culling_of_stratholme : public InstanceMapScript
{
    public:
        instance_culling_of_stratholme() : InstanceMapScript("instance_culling_of_stratholme", 595) { }

        struct instance_culling_of_stratholme_InstanceMapScript : public InstanceScript
        {
            instance_culling_of_stratholme_InstanceMapScript(InstanceMap* map) : InstanceScript(map), _currentState(JUST_STARTED), _infiniteGuardianTimeout(0), _waveCount(0), _currentSpawnLoc(0)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                _currentWorldStates[WORLDSTATE_SHOW_CRATES] = _currentWorldStates[WORLDSTATE_CRATES_REVEALED] = _currentWorldStates[WORLDSTATE_WAVE_COUNT] = _currentWorldStates[WORLDSTATE_TIME_GUARDIAN_SHOW] = _currentWorldStates[WORLDSTATE_TIME_GUARDIAN] = 0;
                _sentWorldStates = _currentWorldStates;
                _plagueCrates.reserve(NUM_PLAGUE_CRATES);
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& packet) override
            {
                for (WorldStateMap::const_iterator itr = _sentWorldStates.begin(); itr != _sentWorldStates.end(); ++itr)
                    packet.Worldstates.emplace_back(itr->first, itr->second);
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _currentState << ' ' << _infiniteGuardianTimeout;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                // read current instance progress from save data, then regress to the previous stable state
                uint32 state = JUST_STARTED;
                time_t infiniteGuardianTime = 0;
                data >> state;
                data >> infiniteGuardianTime; // UNIX timestamp

                COSProgressStates loadState = GetStableStateFor(COSProgressStates(state));
                SetInstanceProgress(loadState, true);

                if (infiniteGuardianTime)
                {
                    _infiniteGuardianTimeout = infiniteGuardianTime;
                    events.ScheduleEvent(EVENT_GUARDIAN_TICK, 0s);
                }

                time_t timediff = (infiniteGuardianTime - GameTime::GetGameTime());
                if (!infiniteGuardianTime)
                    timediff = -1;

                TC_LOG_DEBUG("scripts.cos", "instance_culling_of_stratholme::ReadSaveDataMore: Loaded with state %u and guardian timeout at %zu minutes %zu seconds from now", (uint32)loadState, timediff / MINUTE, timediff % MINUTE);
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_GM_OVERRIDE:
                        SetInstanceProgress(COSProgressStates(data), true);
                        break;
                    case DATA_ARTHAS_DIED:
                        // Respawn everything, then regress to last stable state
                        _arthasGUID = ObjectGuid::Empty;
                        SetInstanceProgress(GetStableStateFor(_currentState), true);
                        break;
                    case DATA_CRATES_START:
                        if (_currentState == JUST_STARTED)
                            SetInstanceProgress(CRATES_IN_PROGRESS, false);
                        break;
                    case DATA_CRATE_REVEALED:
                        if (uint32 missingCrates = MissingPlagueCrates())
                            SetWorldState(WORLDSTATE_CRATES_REVEALED, NUM_PLAGUE_CRATES - missingCrates);
                        else
                            SetInstanceProgress(CRATES_DONE, false);
                        break;
                    case DATA_UTHER_FINISHED:
                        if (_currentState == UTHER_TALK)
                            SetInstanceProgress(PURGE_PENDING, false);
                        break;
                    case DATA_SKIP_TO_PURGE:
                        if (_currentState <= CRATES_DONE)
                            SetInstanceProgress(PURGE_PENDING, false);
                        break;
                    case DATA_START_WAVES:
                        if (_currentState == PURGE_STARTING)
                            SetInstanceProgress(WAVES_IN_PROGRESS, false);
                        break;
                    case DATA_REACH_TOWN_HALL:
                        if (_currentState == WAVES_DONE)
                            SetInstanceProgress(TOWN_HALL_PENDING, false);
                        break;
                    case DATA_TOWN_HALL_DONE:
                        if (_currentState == TOWN_HALL)
                            SetInstanceProgress(TOWN_HALL_COMPLETE, false);
                        break;
                    case DATA_GAUNTLET_REACHED:
                        if (_currentState == GAUNTLET_TRANSITION)
                            SetInstanceProgress(GAUNTLET_PENDING, false);
                        break;
                    case DATA_GAUNTLET_DONE:
                        if (_currentState == GAUNTLET_IN_PROGRESS)
                            SetInstanceProgress(GAUNTLET_COMPLETE, false);
                        break;
                    case DATA_MALGANIS_DONE:
                        if (_currentState == MALGANIS_IN_PROGRESS)
                            SetInstanceProgress(COMPLETE, false);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (_currentState != WAVES_IN_PROGRESS || _waveSpawns.empty())
                    return;

                // if this is a wave spawn...
                auto it = _waveSpawns.find(unit->GetGUID());
                if (it == _waveSpawns.end())
                    return;

                // ... then erase it from our list, then check if there are no more spawns alive...
                _waveSpawns.erase(it);
                if (!_waveSpawns.empty())
                    return;

                // ... and if there are none, the wave is done and we progress

                // clear existing world markers
                for (uint32 marker = WAVE_MARKER_MIN; marker <= WAVE_MARKER_MAX; ++marker)
                    SetWorldState(COSWorldStates(marker), 0, false);
                PropagateWorldStateUpdate();

                // schedule next wave if applicable
                if (_waveCount < NUM_SCOURGE_WAVES)
                    events.ScheduleEvent(EVENT_SCOURGE_WAVE, (_waveCount == WAVE_MEATHOOK) ? 20s : 1s);
                else
                    SetInstanceProgress(WAVES_DONE, false);
            }

            void SetGuidData(uint32 type, ObjectGuid guid) override
            {
                switch (type)
                {
                    case DATA_GM_RECALL:
                    {
                        Creature* arthas = instance->GetCreature(_arthasGUID);
                        Position const& target = arthas ? arthas->GetPosition() : GetArthasSnapbackFor(_currentState);

                        for (auto itr = instance->GetPlayers().begin(); itr != instance->GetPlayers().end(); ++itr)
                        {
                            if (Player* player = itr->GetSource())
                                if (player->GetGUID() == guid || !player->IsGameMaster())
                                {
                                    player->CombatStop(true);
                                    const float offsetDist = 10;
                                    float myAngle = rand_norm() * 2.0 * M_PI;
                                    Position myTarget(target.GetPositionX() + std::sin(myAngle) * offsetDist, target.GetPositionY() + std::sin(myAngle) * offsetDist, target.GetPositionZ(), myAngle + M_PI);
                                    player->NearTeleportTo(myTarget);
                                }
                        }
                        break;
                    }
                    case DATA_UTHER_START:
                        if (_currentState == CRATES_DONE)
                            SetInstanceProgress(UTHER_TALK, false);
                        break;
                    case DATA_START_PURGE:
                        InitiateArthasEvent(PURGE_PENDING, PURGE_STARTING, ACTION_START_RP_EVENT2, guid);
                        break;
                    case DATA_START_TOWN_HALL:
                        InitiateArthasEvent(TOWN_HALL_PENDING, TOWN_HALL, ACTION_START_RP_EVENT3, guid);
                        break;
                    case DATA_TO_GAUNTLET:
                        InitiateArthasEvent(TOWN_HALL_COMPLETE, GAUNTLET_TRANSITION, ACTION_START_RP_EVENT4_1, guid);
                        break;
                    case DATA_START_GAUNTLET:
                        InitiateArthasEvent(GAUNTLET_PENDING, GAUNTLET_IN_PROGRESS, ACTION_START_RP_EVENT4_2, guid);
                        break;
                    case DATA_START_MALGANIS:
                        InitiateArthasEvent(GAUNTLET_COMPLETE, MALGANIS_IN_PROGRESS, ACTION_START_RP_EVENT5, guid);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_INSTANCE_PROGRESS)
                    return _currentState;
                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (type == DATA_INFINITE_CORRUPTOR && state == DONE)
                {
                    events.CancelEvent(EVENT_GUARDIAN_TICK);
                    SetWorldState(WORLDSTATE_TIME_GUARDIAN_SHOW, 0, false);
                    SetWorldState(WORLDSTATE_TIME_GUARDIAN, 0);
                }

                if (!InstanceScript::SetBossState(type, state))
                    return false;

                return true;
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_GUARDIAN_TICK: // regular ticks at :00 seconds on the timer, and then at 04:30 remaining for the chromie whisper
                        {                         // we do the whisper as a guardian tick because i don't want to duplicate the real-time code
                            if (instance->GetSpawnMode() != DUNGEON_DIFFICULTY_HEROIC)
                                return;

                            time_t secondsToGuardianDeath = _infiniteGuardianTimeout - GameTime::GetGameTime();
                            if (secondsToGuardianDeath <= 0)
                            {
                                _infiniteGuardianTimeout = 0;
                                SetWorldState(WORLDSTATE_TIME_GUARDIAN_SHOW, 0, false);
                                SetWorldState(WORLDSTATE_TIME_GUARDIAN, 0);

                                if (Creature* corruptor = instance->GetCreature(_corruptorGUID))
                                {
                                    corruptor->AI()->DoAction(-ACTION_CORRUPTOR_LEAVE);
                                    if (Creature* guardian = instance->GetCreature(_guardianGUID))
                                        Unit::Kill(corruptor, guardian); // @todo is there some spell for this?
                                }
                                SetBossState(DATA_INFINITE_CORRUPTOR, FAIL);
                            }
                            else
                            {
                                time_t minutes = (secondsToGuardianDeath - 1) / MINUTE;
                                time_t seconds = ((secondsToGuardianDeath - 1) % MINUTE) + 1;

                                // chromie whispers - we only ever tick at :00 and :30, but give some leeway in case of slow tick rate
                                if (minutes == 24 && seconds >= 45)
                                    if (Creature* chromie = instance->GetCreature(_chromieGUID))
                                        chromie->AI()->Talk(CHROMIE_WHISPER_GUARDIAN_1);
                                if (minutes == 4 && seconds < 45)
                                    if (Creature* chromie = instance->GetCreature(_chromieGUID))
                                        chromie->AI()->Talk(CHROMIE_WHISPER_GUARDIAN_2);
                                if (minutes == 0)
                                    if (Creature* chromie = instance->GetCreature(_chromieGUID))
                                        chromie->AI()->Talk(CHROMIE_WHISPER_GUARDIAN_3);

                                // update the timer state
                                SetWorldState(WORLDSTATE_TIME_GUARDIAN_SHOW, 1, false);
                                SetWorldState(WORLDSTATE_TIME_GUARDIAN, minutes + 1);
                                if (minutes == 4 && seconds > 30)
                                    events.Repeat(Seconds(seconds - 30));
                                else
                                    events.Repeat(Seconds(seconds));
                            }
                            break;
                        }
                        case EVENT_RESPAWN_ARTHAS:
                            TC_LOG_DEBUG("scripts.cos", "instance_culling_of_stratholme::Update: Spawning new Arthas for instance...");
                            instance->SummonCreature(NPC_ARTHAS, GetArthasSnapbackFor(_currentState));
                            events.CancelEvent(EVENT_RESPAWN_ARTHAS); // make sure we don't have two scheduled
                            break;
                        case EVENT_CRIER_CALL_TO_GATES:
                            if (_currentState == CRATES_DONE)
                                if (Creature* crier = instance->GetCreature(_crierGUID))
                                    crier->AI()->Talk(CRIER_SAY_CALL_TO_GATES);
                            break;
                        case EVENT_SCOURGE_WAVE:
                        {
                            if (_currentState != WAVES_IN_PROGRESS)
                                break;

                            ++_waveCount;
                            SetWorldState(WORLDSTATE_WAVE_COUNT, _waveCount);

                            uint8 spawnLoc = urand(WAVE_LOC_MIN, WAVE_LOC_MAX);
                            while (spawnLoc == _currentSpawnLoc) // don't allow repeats
                                spawnLoc = urand(WAVE_LOC_MIN, WAVE_LOC_MAX);
                            WaveLocation const& spawnLocation = WaveLocations[spawnLoc - WAVE_LOC_MIN];

                            switch (_waveCount)
                            {
                                case WAVE_MEATHOOK:
                                    if (Creature* spawn = instance->SummonCreature(NPC_MEATHOOK, spawnLocation.SpawnPoints[0]))
                                        _waveSpawns.insert(spawn->GetGUID());
                                    break;
                                case WAVE_SALRAMM:
                                    if (Creature* spawn = instance->SummonCreature(NPC_SALRAMM, spawnLocation.SpawnPoints[0]))
                                        _waveSpawns.insert(spawn->GetGUID());
                                    break;
                                default:
                                    if (instance->GetSpawnMode() == DUNGEON_DIFFICULTY_HEROIC)
                                    {
                                        for (uint32 i = 0; i < MAX_SPAWNS_PER_WAVE; ++i)
                                            if (uint32 entry = HeroicWaves[_waveCount - 1][i])
                                                if (Creature* spawn = instance->SummonCreature(entry, spawnLocation.SpawnPoints[i]))
                                                    _waveSpawns.insert(spawn->GetGUID());
                                    }
                                    else
                                    {
                                        for (uint32 i = 0; i <= 1; ++i)
                                            if (Creature* spawn = instance->SummonCreature(NPC_DEVOURING_GHOUL, spawnLocation.SpawnPoints[i]))
                                                _waveSpawns.insert(spawn->GetGUID());
                                    }
                                    break;
                            }

                            for (uint32 marker = WAVE_MARKER_MIN; marker <= WAVE_MARKER_MAX; ++marker)
                                SetWorldState(COSWorldStates(marker), 0, false);
                            SetWorldState(spawnLocation.WorldState, 1);

                            events.RescheduleEvent(EVENT_CRIER_ANNOUNCE_WAVE, 2s);
                            _currentSpawnLoc = spawnLoc;
                            break;
                        }
                        case EVENT_CRIER_ANNOUNCE_WAVE:
                            if (_currentState == WAVES_IN_PROGRESS)
                                if (Creature* crier = instance->GetCreature(_crierGUID))
                                    crier->AI()->Talk(_currentSpawnLoc);
                            break;
                        default:
                            break;
                    }
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_CHROMIE:
                        _chromieGUID = creature->GetGUID();
                        creature->setActive(true);
                        break;
                    case NPC_INFINITE_CORRUPTOR:
                        _corruptorGUID = creature->GetGUID();
                        creature->setActive(true);
                        break;
                    case NPC_GUARDIAN_OF_TIME:
                        _guardianGUID = creature->GetGUID();
                        creature->setActive(true);
                        break;
                    case NPC_GENERIC_BUNNY:
                        _genericBunnyGUID = creature->GetGUID();
                        creature->setActive(true);
                        break;
                    case NPC_CRATE_HELPER:
                        _plagueCrates.push_back(creature->GetGUID());
                        break;
                    case NPC_ARTHAS:
                        TC_LOG_DEBUG("scripts.cos", "instance_culling_of_stratholme::OnCreatureCreate: Arthas spawned at %s", creature->GetPosition().ToString().c_str());
                        _arthasGUID = creature->GetGUID();
                        creature->setActive(true);
                        break;
                    case NPC_LORDAERON_CRIER:
                        _crierGUID = creature->GetGUID();
                        creature->setActive(true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* object) override
            {
                switch (object->GetEntry())
                {
                    case GO_HIDDEN_PASSAGE:
                        _passageGUID = object->GetGUID();
                        object->setActive(true);
                        object->SetGoState(_currentState <= GAUNTLET_TRANSITION ? GO_STATE_READY : GO_STATE_ACTIVE);
                        break;
                    default:
                        break;
                }
            }

            void InitiateArthasEvent(COSProgressStates fromState, COSProgressStates toState, COSInstanceActions startAction, ObjectGuid starterGUID)
            {
                if (_currentState != fromState)
                    return;
                SetInstanceProgress(toState, false);
                if (Creature* arthas = instance->GetCreature(_arthasGUID))
                    arthas->AI()->SetGUID(starterGUID, -startAction);
            }

            void SetInstanceProgress(COSProgressStates state, bool force)
            {
                TC_LOG_DEBUG("scripts.cos", "instance_culling_of_stratholme::SetInstanceProgress: Instance progress is now 0x%X", (uint32)state);
                _currentState = state;

                /* Spawn group management */
                SetSpawnGroupState(SPAWNGRP_CHROMIE_MID, (state >= CRATES_DONE), force);
                SetSpawnGroupState(SPAWNGRP_CRATE_HELPERS, (state == CRATES_IN_PROGRESS || state == CRATES_DONE), true);
                SetSpawnGroupState(SPAWNGRP_GAUNTLET_TRASH, (state == WAVES_IN_PROGRESS), force);
                SetSpawnGroupState(SPAWNGRP_UNDEAD_TRASH, (state >= WAVES_IN_PROGRESS && state < GAUNTLET_COMPLETE), force);
                SetSpawnGroupState(SPAWNGRP_RESIDENTS, (state < WAVES_IN_PROGRESS), true);

                /* Arthas management */
                if (state > CRATES_DONE)
                {   // there might be an Arthas instance in the dungeon somewhere
                    // notify him of the change so he can adjust
                    Creature* arthas = instance->GetCreature(_arthasGUID);
                    if (arthas)
                    {
                        if (force)
                        {
                            arthas->DespawnOrUnsummon();
                            arthas = nullptr;
                        }
                        else
                            arthas->AI()->DoAction(-ACTION_PROGRESS_UPDATE);
                    }

                    if (!arthas) // if there is currently no arthas, then we need to spawn one
                        events.ScheduleEvent(EVENT_RESPAWN_ARTHAS, 1s);
                }
                else if (Creature* arthas = instance->GetCreature(_arthasGUID)) // there shouldn't be any Arthas around
                    arthas->DespawnOrUnsummon();

                /* World state management */
                // Plague crates
                if (state == CRATES_IN_PROGRESS)
                {
                    SetWorldState(WORLDSTATE_SHOW_CRATES, 1, false);
                    SetWorldState(WORLDSTATE_CRATES_REVEALED, 0, false);
                }
                else if (state == CRATES_DONE)
                {
                    SetWorldState(WORLDSTATE_SHOW_CRATES, 1, false);
                    SetWorldState(WORLDSTATE_CRATES_REVEALED, NUM_PLAGUE_CRATES, false);
                }
                else
                {
                    SetWorldState(WORLDSTATE_SHOW_CRATES, 0, false);
                    SetWorldState(WORLDSTATE_CRATES_REVEALED, state == JUST_STARTED ? 0 : NUM_PLAGUE_CRATES, false);
                }
                // Scourge wave counter
                if (state == WAVES_DONE)
                    SetWorldState(WORLDSTATE_WAVE_COUNT, NUM_SCOURGE_WAVES, false);
                else
                    SetWorldState(WORLDSTATE_WAVE_COUNT, 0, false);

                PropagateWorldStateUpdate();

                // Hidden Passage status handling
                if (GameObject* passage = instance->GetGameObject(_passageGUID))
                    passage->SetGoState(state <= GAUNTLET_TRANSITION ? GO_STATE_READY : GO_STATE_ACTIVE);

                switch (state)
                {
                    case CRATES_DONE:
                        if (Creature* bunny = instance->GetCreature(_genericBunnyGUID))
                            bunny->CastSpell(nullptr, SPELL_CRATES_KILL_CREDIT, TRIGGERED_FULL_MASK);
                        events.ScheduleEvent(EVENT_CRIER_CALL_TO_GATES, 5s);
                        break;
                    case WAVES_IN_PROGRESS:
                        _waveCount = 0;
                        _currentSpawnLoc = 0;
                        _waveSpawns.clear();
                        events.ScheduleEvent(EVENT_SCOURGE_WAVE, 1s);
                        SpawnInfiniteCorruptor();
                        break;
                    default:
                        break;
                }

                if (force)
                {
                    // Forced transitions are regressions (event failures) or GM overrides; respawn all dead creatures, and despawn any temporary summons
                    events.Reset();
                    instance->DeleteRespawnTimes();

                    // Reset respawn time on all permanent spawns, despawn all temporary spawns
                    // @todo dynspawn, this won't work
                    std::vector<Creature*> toDespawn;
                    std::unordered_map<ObjectGuid, Creature*> const& objects = instance->GetObjectsStore().GetElements()._elements._element;
                    for (std::unordered_map<ObjectGuid, Creature*>::const_iterator itr = objects.cbegin(); itr != objects.cend(); ++itr)
                    {
                        if (itr->second && (itr->second->isDead() || !itr->second->GetSpawnId() || itr->second->GetOriginalEntry() != itr->second->GetEntry()))
                        {
                            if (itr->second->getDeathState() == DEAD) // despawned, not corpse
                                itr->second->SetRespawnTime(1);
                            else
                                toDespawn.push_back(itr->second);
                        }
                    }

                    for (Creature* creature : toDespawn)
                    {
                        if (creature->GetSpawnId())
                            creature->SetRespawnTime(1);
                        creature->DespawnOrUnsummon(0s, 1s);
                    }

                    SpawnInfiniteCorruptor();
                    events.RescheduleEvent(EVENT_RESPAWN_ARTHAS, 1s);
                }

                SaveToDB();
            }

        private:
            typedef std::unordered_map<uint32, uint32> WorldStateMap;

            uint32 MissingPlagueCrates() const
            {
                uint32 returnValue = 0;
                for (ObjectGuid const& crateHelperGUID : _plagueCrates)
                    if (Creature* crateHelper = instance->GetCreature(crateHelperGUID))
                        if (crateHelper->IsAlive() && !crateHelper->AI()->GetData(DATA_CRATE_REVEALED))
                            ++returnValue;
                return returnValue;
            }

            void SpawnInfiniteCorruptor()
            {
                if (!_infiniteGuardianTimeout && instance->GetSpawnMode() == DUNGEON_DIFFICULTY_HEROIC && (GetBossState(DATA_INFINITE_CORRUPTOR) != DONE && GetBossState(DATA_INFINITE_CORRUPTOR) != FAIL))
                {
                    instance->SummonCreature(NPC_TIME_RIFT, CorruptorRiftPos);
                    instance->SummonCreature(NPC_GUARDIAN_OF_TIME, GuardianPos);
                    instance->SummonCreature(NPC_INFINITE_CORRUPTOR, CorruptorPos);
                    _infiniteGuardianTimeout = GameTime::GetGameTime() + 25 * MINUTE;
                    events.ScheduleEvent(EVENT_GUARDIAN_TICK, 6s);
                }
            }

            void SetWorldState(COSWorldStates state, uint32 value, bool immediate = true)
            {
                TC_LOG_DEBUG("scripts.cos", "instance_culling_of_stratholme::SetWorldState: %u %u", uint32(state), value);
                _currentWorldStates[state] = value;
                if (immediate)
                    PropagateWorldStateUpdate();
            }

            void PropagateWorldStateUpdate()
            {
                TC_LOG_DEBUG("scripts.cos", "instance_culling_of_stratholme::PropagateWorldStateUpdate: Propagate world states");
                for (WorldStateMap::const_iterator it = _currentWorldStates.begin(); it != _currentWorldStates.end(); ++it)
                {
                    uint32& sent = _sentWorldStates[it->first];
                    if (sent != it->second)
                    {
                        TC_LOG_DEBUG("scripts.cos", "instance_culling_of_stratholme::PropagateWorldStateUpdate: Sending world state %u (%u)", it->first, it->second);
                        DoUpdateWorldState(it->first, it->second);
                        sent = it->second;
                    }
                }
            }

            void SetSpawnGroupState(COSInstanceEntries group, bool state, bool force)
            {
                if (state)
                    instance->SpawnGroupSpawn(group, true);
                else if (force)
                    instance->SpawnGroupDespawn(group, true);
                else
                    instance->SetSpawnGroupInactive(group);
            }

            EventMap events;
            COSProgressStates _currentState;
            WorldStateMap _sentWorldStates;
            WorldStateMap _currentWorldStates;
            time_t _infiniteGuardianTimeout;

            // Generic
            ObjectGuid _chromieGUID;
            ObjectGuid _corruptorGUID;
            ObjectGuid _guardianGUID;
            ObjectGuid _genericBunnyGUID;
            std::vector<ObjectGuid> _plagueCrates;

            ObjectGuid _arthasGUID;
            ObjectGuid _crierGUID;

            // Scourge Waves
            uint32 _waveCount;
            uint8 _currentSpawnLoc;
            std::unordered_set<ObjectGuid> _waveSpawns;

            // Gauntlet
            ObjectGuid _passageGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_culling_of_stratholme_InstanceMapScript(map);
        }
};

void AddSC_instance_culling_of_stratholme()
{
    new instance_culling_of_stratholme();
}
