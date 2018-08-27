/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "CombatAI.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "Player.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellHistory.h"
#include "Vehicle.h"

enum PlansVsZombies
{
    // Quest related
    QUEST_BASIC_BOTANY                  = 28733,
    CREDIT_BASIC_BOTANY                 = 49189,

    QUEST_FLOWER_POWER                  = 28617,
    CREDIT_FLOWER_POWER                 = 49542,

    // Brazie Vehicle
    SPELL_PROGRESS_BAR                  = 92259,
    SPELL_50_POWER                      = 91987,
    SPELL_CREATE_LAWMOWER               = 91680,
    SPELL_CREATE_EMPTY_SPOT             = 91676,
    SPELL_CREATE_SPITTER_TARGET         = 91988,
    SPELL_CREATE_GOAL_STALKER           = 91740,
    SPELL_CREATE_BATTERY                = 92816,
    SPELL_CREATE_RANDOM_SUN_POWER       = 91741,
    SPELL_SPITTER_HIGHLIGHT             = 92276,
    SPELL_SUNFLOWER_HIGHLIGHT           = 94032,
    SPELL_EJECT_ALL_PASSENGERS          = 68576,

    SPELL_PLANT_SPITTER                 = 91649,
    SPELL_PLANT_SUNFLOWER               = 91646,
    SPELL_PLANT_FREEZYA                 = 92440,

    // Player Spells
    SPELL_CREATE_BOTANISTS_VEHICLE      = 91683,
    SPELL_CREATE_ZOMBIE                 = 91739,
    SPELL_CREATE_GHOUL                  = 91834,
    SPELL_CREATE_RANDOM_FREEZYA_SACK    = 92435,
    SPELL_GET_FREEZYA_SEEDS             = 92434,

    NPC_SPITTER_TARGET                  = 49385,
    NPC_EMPTY_SPOT                      = 49190,
    NPC_PLACE_IT_HERE                   = 51098,
    NPC_SOLAR_POWER                     = 49194,
    NPC_SPITTER                         = 49200,
    NPC_SUNFLOWER                       = 49193,
    NPC_ZOMBIE                          = 49209,
    NPC_GHOUL                           = 49232,
    NPC_FREEZYA_SEEDS                   = 49604,
    NPC_FREEZYA                         = 49618,
    NPC_GOAL_STALKER                    = 49210,
    NPC_FERTILITIZE_O_TRON_2000         = 49192,

    // Empty Spot
    SPELL_HEALTH_TRIGGER                = 93006,
    SPELL_VENOM_SPIT                    = 91748,
    SPELL_SUNLIGHT                      = 93968,
    SPELL_FREEZYA_BLAST                 = 92441,

    // Solar Power
    SPELL_GAIN_SOLAR_POWER_SPELLCLICK   = 91687,
    SPELL_GAIN_SOLAR_POWER_ENERGIZE     = 94068,

    // Zombie
    SPELL_ZOMBIE_GROWL                  = 93961,
    // SPELL_HEALTH_TRIGGER                = 93006,
    SPELL_LEAKING_GUTS                  = 93244,
    SPELL_GHOUL_GROWL                   = 93962,
    SPELL_BUCKET_HEAD                   = 93230,
    SPELL_BUCKET                        = 93236,

    // Fertilitize-o-tron 2000
    SPELL_LAWNMOWER_STARTUP_SOUND       = 93969,
    SPELL_DAZED                         = 1604,
    SPELL_PLAGUE_GAS                    = 92084,

    // Texts
    SAY_ANNOUNCE_TUTORIAL_1             = 49559,
    SAY_ANNOUNCE_TUTORIAL_2             = 49553,
    SAY_ANNOUNCE_TUTORIAL_3             = 49558,
    SAY_ANNOUNCE_TUTORIAL_4             = 49552,
    SAY_ANNOUNCE_MASSIVE_WAVE           = 49409,
    SAY_ANNOUNCE_PLANT_SUNFLOWER        = 49566,
    SAY_ANNOUNCE_PLANT_MORE_SUNFLOWERS  = 49567,
    SAY_ANNOUNCE_DROPPED_SEED           = 49685,
    SAY_ANNOUNCE_LEVEL_1_COMPLETE       = 49551,

    SAY_ANNOUNCE_GAINED_FREEZYA_SEEDS   = 0,
    SAY_ANNOUNCE_GAINED_STRANGLER_SEEDS = 1,
    SAY_ANNOUNCE_ZOMBIES_ATE_BRAIN      = 2,

    // Events
    EVENT_SPITTER_HIGHLIGHT             = 1,
    EVENT_SUMMON_SOLAR_POWER            = 2,
    EVENT_CREATE_ZOMBIE                 = 3,
    EVENT_MOVE_TO_GOAL_POSITION         = 4,
    EVENT_CHECK_VICTIM_STATE            = 5,
    EVENT_ANNOUNCE_GOOD_JOB             = 6,
    EVENT_ANNOUNCE_PLACING_SPITTERS     = 7,
    EVENT_ANNOUNCE_MASSIVE_WAVE         = 8,
    EVENT_ANNOUNCE_TUTORIAL_COMPLETED   = 9,
    EVENT_EJECT_PASSENGER               = 10,
    EVENT_SUNFLOWER_HIGHLIGHT           = 11,
    EVENT_ANNOUNCE_PLANT_MORE_FLOWERS   = 12,
    EVENT_SUNLIGHT                      = 13,
    EVENT_CREATE_GHOUL                  = 14,
    EVENT_KILL_LANE                     = 15,
    EVENT_PLAGUE_GAS                    = 16,
    EVENT_ANNOUNCE_LEVEL_1_COMPLETED    = 17,

    // Actions
    ACTION_FIRST_SPITTER_PLANTED        = 1,
    ACTION_ZOMBIE_DAMAGED               = 2,
    ACTION_ZOMBIE_DIED                  = 3,
    ACTION_GHOUL_DAMAGED                = 4,
    ACTION_QUEST_FAILED                 = 5,

    // Misc
    SEAT_0                              = 0,

    MAX_TARGET_POSITIONS                = 5,
    MAX_EMPTY_SPOT_POSITIONS            = 40,
    CENTER_ZOMBIE_LANE_INDEX            = 2,

    POINT_GOAL_STALKER                  = 1,
    POINT_SPITTER_TARGET                = 2,

    DATA_CURRENT_ENTRY                  = 1,

    PHASE_ID_QUEST                      = 365,

    // Levels
    LEVEL_TUTORIAL                      = 0,
    LEVEL_1                             = 1,
};

Position const LawnMowerPositions[MAX_TARGET_POSITIONS]
{
    { -116.5816f, 237.6823f, 53.2755f },
    { -116.2934f, 228.9896f, 53.2755f },
    { -116.0833f, 220.7691f, 53.2755f },
    { -116.2674f, 213.0243f, 53.2755f },
    { -115.9132f, 204.6198f, 53.2755f }
};

Position const GoalStalkerPositions[MAX_TARGET_POSITIONS]
{
    { -116.5816f, 237.6823f, 53.2755f },
    { -116.2934f, 228.9896f, 53.2755f },
    { -116.0833f, 220.7691f, 53.2755f },
    { -116.2674f, 213.0243f, 53.2755f },
    { -115.9132f, 204.6198f, 53.2755f }
};

Position const SpitterTargetPositions[MAX_TARGET_POSITIONS]
{
    { -39.83333f, 237.441f,  53.27685f },
    { -40.13715f, 229.6163f, 53.33047f },
    { -40.10764f, 221.4618f, 53.27604f },
    { -40.06424f, 212.9444f, 53.3602f  },
    { -40.14236f, 205.0538f, 53.27604f }
};

Position const EmptySpotPositions[MAX_EMPTY_SPOT_POSITIONS]
{
    { -108.7604f, 221.0226f, 53.35883f },
    { -108.3733f, 212.9219f, 53.35883f },
    { -108.3108f, 229.2309f, 53.35883f },
    { -107.9792f, 203.8629f, 53.35883f },
    { -100.1684f, 220.6615f, 53.35883f },
    { -99.92188f, 212.1406f, 53.35883f },
    { -99.9375f,  204.8385f, 53.35883f },
    { -100.0399f, 229.7882f, 53.35883f },
    { -108.5486f, 237.4844f, 53.35883f },
    { -91.59549f, 220.8715f, 53.35883f },
    { -91.51563f, 212.7379f, 53.35883f },
    { -100.3385f, 237.2656f, 53.35883f },
    { -91.68056f, 229.1997f, 53.35883f },
    { -91.32291f, 204.5434f, 53.35883f },
    { -91.77604f, 237.5816f, 53.35883f },
    { -83.93403f, 213.066f,  53.35883f },
    { -83.21354f, 220.8542f, 53.35883f },
    { -83.61459f, 204.592f,  53.35883f },
    { -83.80903f, 229.6788f, 53.35883f },
    { -83.52257f, 237.217f,  53.35883f },
    { -75.24827f, 213.3108f, 53.35883f },
    { -75.00174f, 220.9861f, 53.35883f },
    { -75.34375f, 204.5382f, 53.35883f },
    { -75.25521f, 229.5278f, 53.35883f },
    { -75.10416f, 238.0816f, 53.35883f },
    { -66.7934f,  213.071f,  53.35883f },
    { -66.5469f,  220.747f,  53.35883f },
    { -66.8889f,  204.299f,  53.35883f },
    { -66.8003f,  229.288f,  53.35883f },
    { -66.6493f,  237.842f,  53.35883f },
    { -58.4965f,  212.372f,  53.35883f },
    { -58.25f,    220.047f,  53.35883f },
    { -58.5035f,  228.589f,  53.35883f },
    { -58.592f,   203.599f,  53.35883f },
    { -58.3524f,  237.142f,  53.35883f },
    { -49.6059f,  212.569f,  53.35883f },
    { -49.3594f,  220.245f,  53.35883f },
    { -49.6128f,  228.786f,  53.35883f },
    { -49.7014f,  203.797f,  53.35883f },
    { -49.4618f,  237.34f,   53.35883f }
};

float const EmptySpotOrientation = 6.143559f;
float const LawnmowerOrientation = 6.178465f;
float const SpitterTargetOrientation = 6.232892f;
float const GoalStalkerOrientation = 6.178465f;

Position const SolarPowerJumpPos = { -64.24827f, 181.3004f, 53.97961f };

Position const FreezyaSeedSummonPos = { -49.3594f, 220.245f, 56.35883f, 0.01745329f };
Position const FreezyaSeedJumpPos = { -116.2847f, 216.7865f, 53.2755f };

class npc_brazie_the_bonatist_vehicle : public CreatureScript
{
    public:
        npc_brazie_the_bonatist_vehicle() : CreatureScript("npc_brazie_the_bonatist_vehicle") { }

        struct npc_brazie_the_bonatist_vehicleAI : public VehicleAI
        {
            npc_brazie_the_bonatist_vehicleAI(Creature* creature) : VehicleAI(creature), _summons(me)
            {
                Inizialize();
            }

            void Inizialize()
            {
                _currentLevel = 1;
                _deadZombieCount = 0;
                _damagedZombieCount = 0;
                _damagedGhoulCount = 0;
                _currentStage = 0;

                if (Unit* charmer = me->GetCharmerOrOwner())
                {
                    if (Player* player = charmer->ToPlayer())
                    {
                        if (player->GetQuestStatus(QUEST_BASIC_BOTANY) != QUEST_STATUS_REWARDED)
                            _currentLevel = LEVEL_TUTORIAL;
                        else if (player->GetQuestStatus(QUEST_BASIC_BOTANY) == QUEST_STATUS_REWARDED
                            && player->GetQuestStatus(QUEST_FLOWER_POWER) != QUEST_STATUS_REWARDED)
                            _currentLevel = LEVEL_1;
                    }
                }
                SetupActionBar();
            }

            void Reset() override
            {
                Inizialize();
            }

            void JustSummoned(Creature* summon) override
            {
                _summons.Summon(summon);

                if (summon->GetEntry() == NPC_EMPTY_SPOT)
                    _spotGUIDs.push_back(summon->GetGUID());
            }

            void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
            {
                if (!passenger)
                    return;

                if (apply)
                {
                    PhasingHandler::AddPhase(passenger, PHASE_ID_QUEST, true);
                    passenger->CastSpell(passenger, SPELL_PROGRESS_BAR, true);
                    SetupSpawns();

                    me->SetPower(POWER_ENERGY, 0);

                    // Scheduling first events
                    if (_currentLevel == LEVEL_TUTORIAL)
                    {
                        _events.ScheduleEvent(EVENT_SPITTER_HIGHLIGHT, Seconds(1));
                        _events.ScheduleEvent(EVENT_SUMMON_SOLAR_POWER, Seconds(1));
                    }
                    else if (_currentLevel == LEVEL_1)
                    {
                        _events.ScheduleEvent(EVENT_SUNFLOWER_HIGHLIGHT, Seconds(1));
                        _nextSolarPowerSeconds = Seconds(5);
                        _events.ScheduleEvent(EVENT_SUMMON_SOLAR_POWER, _nextSolarPowerSeconds + Milliseconds(500));
                        _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, Seconds(41));

                    }

                }
                else
                {
                    _events.Reset();
                    passenger->RemoveAurasDueToSpell(SPELL_PROGRESS_BAR);
                    passenger->RemoveAurasDueToSpell(SPELL_CREATE_BOTANISTS_VEHICLE);
                    PhasingHandler::RemovePhase(passenger, PHASE_ID_QUEST, true);
                    _summons.DespawnAll();
                    me->DespawnOrUnsummon(Milliseconds(100));
                }
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_GET_FREEZYA_SEEDS:
                        me->m_spells[2] = SPELL_PLANT_FREEZYA;
                        if (Player* player = caster->ToPlayer())
                        {
                            Talk(SAY_ANNOUNCE_GAINED_FREEZYA_SEEDS, player);
                            player->VehicleSpellInitialize();
                        }
                        break;
                    default:
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_FIRST_SPITTER_PLANTED:
                        _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, Milliseconds(500));
                        break;
                    case ACTION_ZOMBIE_DAMAGED:
                        _damagedZombieCount++;
                        if (_currentLevel == LEVEL_TUTORIAL && _currentStage < 2)
                            EnterNextStage();
                        if (_currentLevel == LEVEL_1)
                        {
                            if (_currentStage == 0 && _damagedZombieCount == 1)
                                EnterNextStage();
                            if (_currentStage == 1 && _damagedZombieCount == 2)
                                EnterNextStage();
                        }
                        break;
                    case ACTION_ZOMBIE_DIED:
                        _deadZombieCount++;
                        if (_currentLevel == LEVEL_TUTORIAL)
                        {
                            if (_deadZombieCount == 3)
                                EnterNextStage();
                            if (_deadZombieCount == 8)
                                EnterNextStage();
                        }

                        if (_currentLevel == LEVEL_1)
                        {
                            if (_deadZombieCount == 4 && _currentStage == 2)
                                EnterNextStage();
                            if (_deadZombieCount == 11 && _currentStage == 3)
                                EnterNextStage();
                            if (_deadZombieCount == 27 && _currentStage == 4)
                                EnterNextStage();
                        }
                        break;
                    case ACTION_GHOUL_DAMAGED:
                        _damagedGhoulCount++;
                        if (_currentLevel == LEVEL_1)
                        {
                            if (_damagedGhoulCount == 1)
                            {
                                if (Unit* charmer = me->GetCharmerOrOwner())
                                {
                                    if (Player* player = charmer->ToPlayer())
                                    {
                                        player->Whisper(SAY_ANNOUNCE_DROPPED_SEED, player, true);
                                        player->CastSpell(player, SPELL_CREATE_RANDOM_FREEZYA_SACK, true);
                                    }
                                }
                            }
                        }
                        break;
                    case ACTION_QUEST_FAILED:
                        if (Unit* charmer = me->GetCharmerOrOwner())
                        {
                            if (Player* player = charmer->ToPlayer())
                            {
                                if (_currentLevel == LEVEL_TUTORIAL)
                                    player->FailQuest(QUEST_BASIC_BOTANY);
                                else if (_currentLevel == LEVEL_1)
                                    player->FailQuest(QUEST_FLOWER_POWER);
                            }
                        }

                        Talk(SAY_ANNOUNCE_ZOMBIES_ATE_BRAIN);
                        _summons.DespawnEntry(NPC_ZOMBIE);
                        _summons.DespawnEntry(NPC_GHOUL);
                        _events.Reset();
                        _events.ScheduleEvent(EVENT_EJECT_PASSENGER, Seconds(2) + Milliseconds(300));
                        break;
                    default:
                        break;
                }
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SPITTER_HIGHLIGHT:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                            {
                                if (Player* player = charmer->ToPlayer())
                                    player->Whisper(SAY_ANNOUNCE_TUTORIAL_1, player, true);

                                charmer->CastSpell(charmer, SPELL_SPITTER_HIGHLIGHT, true);
                            }
                            break;
                        case EVENT_SUMMON_SOLAR_POWER:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                            {
                                uint8 randomPositionIndex = urand(0, MAX_EMPTY_SPOT_POSITIONS - 1);
                                Position pos = EmptySpotPositions[randomPositionIndex];
                                float angle = frand(0, float(M_PI * 2));
                                float x = pos.GetPositionX() + cos(angle) * 3;
                                float y = pos.GetPositionY() + sin(angle) * 3;

                                charmer->CastSpell(x, y, pos.GetPositionZ() + 50.0f, SPELL_CREATE_RANDOM_SUN_POWER, true);

                                if (_currentLevel == LEVEL_TUTORIAL)
                                    _events.Repeat(Seconds(4));
                                else if (_currentLevel == LEVEL_1)
                                {
                                    if (_nextSolarPowerSeconds == Seconds(5))
                                    {
                                        _nextSolarPowerSeconds = Seconds(10);
                                        _events.Repeat(_nextSolarPowerSeconds);
                                    }
                                    else
                                    {
                                        _nextSolarPowerSeconds = Seconds(5);
                                        _events.Repeat(_nextSolarPowerSeconds);
                                    }
                                }
                            }
                            break;
                        case EVENT_CREATE_ZOMBIE:
                        {
                            uint8 index = urand(0, MAX_TARGET_POSITIONS - 1);

                            if (_currentLevel == LEVEL_TUTORIAL)
                                index = CENTER_ZOMBIE_LANE_INDEX;

                            Position pos = SpitterTargetPositions[index];
                            float angle = pos.GetAngle(GoalStalkerPositions[index]);
                            if (Unit* charmer = me->GetCharmerOrOwner())
                                charmer->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), angle, SPELL_CREATE_ZOMBIE, true);
                            break;
                        }
                        case EVENT_ANNOUNCE_GOOD_JOB:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                            {
                                if (Player* player = charmer->ToPlayer())
                                    player->Whisper(SAY_ANNOUNCE_TUTORIAL_2, player, true);
                            }
                            _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, Milliseconds(1));
                            break;
                        case EVENT_ANNOUNCE_PLACING_SPITTERS:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                            {
                                if (Player* player = charmer->ToPlayer())
                                {
                                    player->Whisper(SAY_ANNOUNCE_TUTORIAL_3, player, true);
                                    player->SetPower(POWER_ALTERNATE_POWER, 1);
                                }
                            }
                            _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, Milliseconds(1));
                            break;
                        case EVENT_ANNOUNCE_MASSIVE_WAVE:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                            {
                                if (Player* player = charmer->ToPlayer())
                                {
                                    player->Whisper(SAY_ANNOUNCE_MASSIVE_WAVE, player, true);

                                    if (_currentLevel == LEVEL_TUTORIAL)
                                        player->SetPower(POWER_ALTERNATE_POWER, 3);
                                    if (_currentLevel == LEVEL_1)
                                        player->SetPower(POWER_ALTERNATE_POWER, 4);
                                }
                            }
                            break;
                        case EVENT_ANNOUNCE_TUTORIAL_COMPLETED:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                            {
                                if (Player* player = charmer->ToPlayer())
                                {
                                    player->Whisper(SAY_ANNOUNCE_TUTORIAL_4, player, true);
                                    player->RemoveAurasDueToSpell(SPELL_PROGRESS_BAR);
                                    player->KilledMonsterCredit(CREDIT_BASIC_BOTANY);
                                }
                            }
                            break;
                        case EVENT_EJECT_PASSENGER:
                            DoCastSelf(SPELL_EJECT_ALL_PASSENGERS, true);
                            break;
                        case EVENT_SUNFLOWER_HIGHLIGHT:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                            {
                                if (Player* player = charmer->ToPlayer())
                                    player->Whisper(SAY_ANNOUNCE_PLANT_SUNFLOWER, player, true);

                                charmer->CastSpell(charmer, SPELL_SUNFLOWER_HIGHLIGHT, true);
                            }
                            _events.ScheduleEvent(EVENT_ANNOUNCE_PLANT_MORE_FLOWERS, Seconds(1));
                            break;
                        case EVENT_ANNOUNCE_PLANT_MORE_FLOWERS:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                                if (Player* player = charmer->ToPlayer())
                                    player->Whisper(SAY_ANNOUNCE_PLANT_MORE_SUNFLOWERS, player, true);
                            break;
                        case EVENT_CREATE_GHOUL:
                        {
                            uint8 index = urand(0, MAX_TARGET_POSITIONS - 1);

                            Position pos = SpitterTargetPositions[index];
                            float angle = pos.GetAngle(GoalStalkerPositions[index]);
                            if (Unit* charmer = me->GetCharmerOrOwner())
                                charmer->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), angle, SPELL_CREATE_GHOUL, true);
                            break;
                        }
                        case EVENT_ANNOUNCE_LEVEL_1_COMPLETED:
                            if (Unit* charmer = me->GetCharmerOrOwner())
                            {
                                if (Player* player = charmer->ToPlayer())
                                {
                                    player->Whisper(SAY_ANNOUNCE_LEVEL_1_COMPLETE, player, true);
                                    player->RemoveAurasDueToSpell(SPELL_PROGRESS_BAR);
                                    player->KilledMonsterCredit(CREDIT_FLOWER_POWER);
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }

            }

            bool IsSpotFree(Position const pos)
            {
                for (ObjectGuid guid : _spotGUIDs)
                {
                    if (Creature* spot = ObjectAccessor::GetCreature(*me, guid))
                        if (spot->GetDistance(pos) <= 5.0f)
                            if (spot->IsAIEnabled)
                                if (spot->AI()->GetData(DATA_CURRENT_ENTRY) == NPC_EMPTY_SPOT)
                                    return true;
                }

                return false;
            }

        private:
            void SetupSpawns()
            {
                Unit* charmer = me->GetCharmerOrOwner();
                if (!charmer)
                    return;

                for (uint8 i = 0; i < MAX_TARGET_POSITIONS; i++)
                {
                    Position pos = LawnMowerPositions[i];
                    charmer->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), LawnmowerOrientation, SPELL_CREATE_LAWMOWER, true);

                    pos = GoalStalkerPositions[i];
                    charmer->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), GoalStalkerOrientation, SPELL_CREATE_GOAL_STALKER, true);

                    pos = SpitterTargetPositions[i];
                    charmer->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SpitterTargetOrientation, SPELL_CREATE_SPITTER_TARGET, true);
                }

                for (uint8 i = 0; i < MAX_EMPTY_SPOT_POSITIONS; i++)
                {
                    Position pos = EmptySpotPositions[i];
                    charmer->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), EmptySpotOrientation, SPELL_CREATE_EMPTY_SPOT, true);
                }
            }

            void SetupActionBar()
            {
                if (_currentLevel == LEVEL_TUTORIAL)
                    me->m_spells[0] = SPELL_PLANT_SPITTER;
                else if (_currentLevel == LEVEL_1)
                {
                    me->m_spells[0] = SPELL_PLANT_SUNFLOWER;
                    me->m_spells[1] = SPELL_PLANT_SPITTER;
                }
            }

            void EnterNextStage()
            {
                _currentStage++;

                // Tutorial Stages
                if (_currentLevel == LEVEL_TUTORIAL)
                {
                    if (_currentStage == 1)
                        _events.ScheduleEvent(EVENT_ANNOUNCE_GOOD_JOB, Milliseconds(1));

                    if (_currentStage == 2)
                        _events.ScheduleEvent(EVENT_ANNOUNCE_PLACING_SPITTERS, Milliseconds(1));

                    if (_currentStage == 3)
                    {
                        _events.ScheduleEvent(EVENT_ANNOUNCE_MASSIVE_WAVE, Milliseconds(1));
                        CreateZombies(5, Seconds(1) + Milliseconds(800), Seconds(3));
                    }

                    if (_currentStage == 4)
                    {
                        _events.Reset();
                        _events.ScheduleEvent(EVENT_ANNOUNCE_TUTORIAL_COMPLETED, Milliseconds(1));
                        _events.ScheduleEvent(EVENT_EJECT_PASSENGER, Seconds(1) + Milliseconds(600));
                    }
                }

                // Level 1 Stages
                if (_currentLevel == LEVEL_1)
                {
                    if (_currentStage == 1)
                    {
                        if (Unit* charmer = me->GetCharmerOrOwner())
                            if (Player* player = charmer->ToPlayer())
                                player->SetPower(POWER_ALTERNATE_POWER, 1);

                        CreateZombies(2, Seconds(5), Seconds(7));
                    }

                    if (_currentStage == 2)
                    {
                        if (Unit* charmer = me->GetCharmerOrOwner())
                            if (Player* player = charmer->ToPlayer())
                                player->SetPower(POWER_ALTERNATE_POWER, 2);


                        CreateZombies(3, Seconds(8), Seconds(7));
                    }

                    if (_currentStage == 3)
                    {
                        if (Unit* charmer = me->GetCharmerOrOwner())
                            if (Player* player = charmer->ToPlayer())
                                player->SetPower(POWER_ALTERNATE_POWER, 3);

                        CreateZombies(3, Seconds(35), Seconds(5));
                        CreateGhouls(2, Seconds(6), Seconds(39));
                    }

                    if (_currentStage == 4)
                    {
                        _events.ScheduleEvent(EVENT_ANNOUNCE_MASSIVE_WAVE, Milliseconds(500));
                        CreateZombies(2, Seconds(2), Seconds(3));
                        CreateZombies(5, Seconds(2), Seconds(3));
                        CreateZombies(1, Seconds(20), Seconds(0));
                        CreateZombies(2, Seconds(20), Seconds(2));
                        CreateZombies(1, Seconds(29), Seconds(0));
                        CreateZombies(1, Seconds(29), Seconds(0));

                        CreateGhouls(2, Seconds(8), Seconds(3));
                        CreateGhouls(1, Seconds(26), Seconds(0));
                        CreateGhouls(1, Seconds(26), Seconds(0));
                    }

                    if (_currentStage == 5)
                    {
                        _events.Reset();
                        _events.ScheduleEvent(EVENT_ANNOUNCE_LEVEL_1_COMPLETED, Milliseconds(1));
                        _events.ScheduleEvent(EVENT_EJECT_PASSENGER, Seconds(1) + Milliseconds(600));
                    }
                }
            }

            void CreateZombies(uint8 amount, Milliseconds const& delay, Milliseconds const& repeatTimer)
            {
                for (uint8 i = 0; i < amount; i++)
                    _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, delay + (repeatTimer * i));
            }

            void CreateGhouls(uint8 amount, Milliseconds const& delay, Milliseconds const& repeatTimer)
            {
                for (uint8 i = 0; i < amount; i++)
                    _events.ScheduleEvent(EVENT_CREATE_GHOUL, delay + (repeatTimer * i));
            }

            EventMap _events;
            SummonList _summons;
            GuidVector _spotGUIDs;
            uint8 _currentLevel;
            uint8 _deadZombieCount;
            uint8 _damagedZombieCount;
            uint8 _damagedGhoulCount;
            uint8 _currentStage;
            Seconds _nextSolarPowerSeconds;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_brazie_the_bonatist_vehicleAI(creature);
        }
};

class npc_brazie_fertilitize_o_tron_2000 : public CreatureScript
{
    public:
        npc_brazie_fertilitize_o_tron_2000() : CreatureScript("npc_brazie_fertilitize_o_tron_2000") { }

        struct npc_brazie_fertilitize_o_tron_2000AI : public ScriptedAI
        {
            npc_brazie_fertilitize_o_tron_2000AI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* summoner) override
            {
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);

                if (Creature* vehicle = summoner->GetVehicleCreatureBase())
                    if (vehicle->IsAIEnabled)
                        vehicle->AI()->JustSummoned(me);
            }

            void AttackStart(Unit* who) override
            {
                 if (me->GetPosition().GetExactDist(who->GetPosition()) > 3.0f)
                     return;

                if (Creature* spitterTarget = me->FindNearestCreature(NPC_SPITTER_TARGET, 150.0f, true))
                {
                    Position pos = me->GetPosition();
                    pos.SetOrientation(pos.GetAngle(spitterTarget));

                    if (pos.HasInLine(who, 5.0f))
                        CreatureAI::AttackStart(who);
                }
            }

            void JustEngagedWith(Unit* who) override
            {
                DoCast(who, SPELL_DAZED, true);
                DoCastSelf(SPELL_LAWNMOWER_STARTUP_SOUND, true);
                me->SetReactState(REACT_PASSIVE);
                me->AttackStop();
                _events.ScheduleEvent(EVENT_KILL_LANE, Milliseconds(300));
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                if (id == POINT_SPITTER_TARGET)
                    me->DespawnOrUnsummon();
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_KILL_LANE:
                            if (Creature* spitterTarget = me->FindNearestCreature(NPC_SPITTER_TARGET, 150.0f, true))
                                me->GetMotionMaster()->MovePoint(POINT_SPITTER_TARGET, spitterTarget->GetPosition(), false);
                            _events.ScheduleEvent(EVENT_PLAGUE_GAS, Milliseconds(200));
                            break;
                        case EVENT_PLAGUE_GAS:
                            DoCastAOE(SPELL_PLAGUE_GAS, true);
                            _events.Repeat(Milliseconds(500));
                            break;
                        default:
                            break;
                    }
                }

            }
        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_brazie_fertilitize_o_tron_2000AI(creature);
        }
};

class npc_brazie_spot : public CreatureScript
{
    public:
        npc_brazie_spot() : CreatureScript("npc_brazie_spot") { }

        struct npc_brazie_spotAI : public ScriptedAI
        {
            npc_brazie_spotAI(Creature* creature) : ScriptedAI(creature)
            {
                Initialize();
            }

            void Initialize()
            {
                _currentEntry = me->GetEntry();
            }

            void DamageTaken(Unit* attacker, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;

                    me->SetFullHealth();
                    me->UpdateEntry(NPC_EMPTY_SPOT);
                    _currentEntry = NPC_EMPTY_SPOT;
                    me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
                    me->AttackStop();
                    me->SetFacingTo(me->GetHomePosition().GetOrientation());
                    _events.Reset();
                }
            }

            void IsSummonedBy(Unit* summoner) override
            {
                me->m_SightDistance = 150.0f;
                me->m_CombatDistance = 150.0f;

                me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);

                if (Creature* vehicle = summoner->GetVehicleCreatureBase())
                    if (vehicle->IsAIEnabled)
                        vehicle->AI()->JustSummoned(me);
            }

            void AttackStart(Unit* who) override
            {
                if (_currentEntry == NPC_EMPTY_SPOT || _currentEntry == NPC_SUNFLOWER)
                    return;

                if (who->GetEntry() != NPC_ZOMBIE && who->GetEntry() != NPC_GHOUL)
                    return;

                if (Creature* spitterTarget = me->FindNearestCreature(NPC_SPITTER_TARGET, 150.0f, true))
                {
                    Position pos = me->GetPosition();
                    pos.SetOrientation(pos.GetAngle(spitterTarget));

                    if (pos.HasInLine(who, 5.0f))
                    {
                        me->SetFacingToObject(spitterTarget);
                        me->SetNoCallAssistance(true);
                        CreatureAI::AttackStart(who);
                    }
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_CURRENT_ENTRY)
                    return _currentEntry;

                return 0;
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                switch (spell->Id)
                {
                    case SPELL_PLANT_SPITTER:
                        me->UpdateEntry(NPC_SPITTER);
                        _currentEntry = NPC_SPITTER;
                        break;
                    case SPELL_PLANT_SUNFLOWER:
                        me->UpdateEntry(NPC_SUNFLOWER);
                        _currentEntry = NPC_SUNFLOWER;
                        _events.ScheduleEvent(EVENT_SUNLIGHT, Seconds(16));
                        break;
                    case SPELL_PLANT_FREEZYA:
                        me->UpdateEntry(NPC_FREEZYA);
                        _currentEntry = NPC_FREEZYA;
                        break;
                    default:
                        break;
                }

                if (spell->Id != SPELL_PLAGUE_GAS)
                    me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUNLIGHT:
                            DoCastSelf(SPELL_SUNLIGHT, true);
                            if (TempSummon* summon = me->ToTempSummon())
                            {
                                if (Unit* summoner = summon->GetSummoner())
                                {
                                    uint8 randomPositionIndex = urand(0, MAX_EMPTY_SPOT_POSITIONS - 1);
                                    Position pos = EmptySpotPositions[randomPositionIndex];
                                    float angle = frand(0, float(M_PI * 2));
                                    float x = pos.GetPositionX() + cos(angle) * 3;
                                    float y = pos.GetPositionY() + sin(angle) * 3;

                                    summoner->CastSpell(x, y, pos.GetPositionZ() + 50.0f, SPELL_CREATE_RANDOM_SUN_POWER, true);
                                }
                            }
                            _events.Repeat(Seconds(17));
                            break;
                        default:
                            break;
                    }
                }

                if (_currentEntry == NPC_SPITTER)
                    DoSpellAttackIfReady(SPELL_VENOM_SPIT);
                else if (_currentEntry == NPC_FREEZYA)
                    DoSpellAttackIfReady(SPELL_FREEZYA_BLAST);
            }

        private:
            EventMap _events;
            uint32 _currentEntry;
            GuidVector _zombieGuids;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_brazie_spotAI(creature);
        }
};

class npc_brazie_zombie : public CreatureScript
{
    public:
        npc_brazie_zombie() : CreatureScript("npc_brazie_zombie") { }

        struct npc_brazie_zombieAI : public ScriptedAI
        {
            npc_brazie_zombieAI(Creature* creature) : ScriptedAI(creature)
            {
                Inizialize();
            }

            void Inizialize()
            {
                _pathIndex = 0;
                _notifiedLowHealth = false;
            }

            void IsSummonedBy(Unit* summoner) override
            {
                me->m_SightDistance = 3.0f;
                me->m_CombatDistance = 3.0f;

                me->SetWalk(true);

                if (Creature* vehicle = summoner->GetVehicleCreatureBase())
                    if (vehicle->IsAIEnabled)
                        vehicle->AI()->JustSummoned(me);

                for (uint8 i = 0; i < MAX_TARGET_POSITIONS; i++)
                    if (me->GetPosition().GetExactDist(SpitterTargetPositions[i]) <= 1.0f)
                        _pathIndex = i;

                if (me->GetEntry() == NPC_ZOMBIE)
                    DoCastSelf(SPELL_ZOMBIE_GROWL);
                else if (me->GetEntry() == NPC_GHOUL)
                {
                    me->SetDisplayId(me->GetCreatureTemplate()->Modelid4);
                    DoCastSelf(SPELL_GHOUL_GROWL, true);
                    DoCastSelf(SPELL_BUCKET_HEAD, true);
                }

                _events.ScheduleEvent(EVENT_MOVE_TO_GOAL_POSITION, Seconds(2) + Milliseconds(400));
            }

            void AttackStart(Unit* who) override
            {
                // Just to make sure that a zombie wont call nearby zombies for aid
                if (who->GetDistance(me) > 3.0f)
                    return;

                // If we have a plant very close to us we assume that this plant has been added afterwards
                if (me->GetPosition().GetExactDist(who) < 3.0f)
                    return;

                // Do not attack plants behind me if they got replanted
                if (!who->isInFront(me, 1.8f))
                    return;


                Position pos = me->GetPosition();
                pos.SetOrientation(pos.GetAngle(GoalStalkerPositions[_pathIndex]));

                if (pos.HasInLine(who, 4.8f))
                {
                    if (Creature* target = who->ToCreature())
                    {
                        if (target->IsAIEnabled)
                        {
                            if (target->AI()->GetData(DATA_CURRENT_ENTRY) != NPC_EMPTY_SPOT || target->GetEntry() == NPC_FERTILITIZE_O_TRON_2000)
                            {
                                me->SetNoCallAssistance(true);
                                me->StopMoving();
                                CreatureAI::AttackStart(who);
                            }
                        }
                    }
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                if (TempSummon* summon = me->ToTempSummon())
                    if (Unit* summoner = summon->GetSummoner())
                        if (Creature* vehicle = summoner->GetVehicleCreatureBase())
                            if (vehicle->IsAIEnabled)
                                vehicle->AI()->DoAction(ACTION_ZOMBIE_DIED);

                me->DespawnOrUnsummon(Seconds(4));
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (me->HealthBelowPctDamaged(50, damage) && !_notifiedLowHealth)
                {
                    if (me->GetEntry() == NPC_ZOMBIE)
                        DoCastSelf(SPELL_LEAKING_GUTS, true);
                    else if (me->GetEntry() == NPC_GHOUL)
                    {
                        me->RemoveAurasDueToSpell(SPELL_BUCKET_HEAD);
                        DoCastSelf(SPELL_BUCKET, true);
                    }

                    if (TempSummon* summon = me->ToTempSummon())
                    {
                        if (Unit* summoner = summon->GetSummoner())
                        {
                            if (Creature* vehicle = summoner->GetVehicleCreatureBase())
                            {
                                if (vehicle->IsAIEnabled)
                                {
                                    if (me->GetEntry() == NPC_ZOMBIE)
                                        vehicle->AI()->DoAction(ACTION_ZOMBIE_DAMAGED);
                                    else if (me->GetEntry() == NPC_GHOUL)
                                        vehicle->AI()->DoAction(ACTION_GHOUL_DAMAGED);
                                }
                            }
                        }
                    }

                    _notifiedLowHealth = true;
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                if (id == POINT_GOAL_STALKER)
                    if (me->GetPosition().GetExactDist(GoalStalkerPositions[_pathIndex]) <= 0.1f)
                        if (TempSummon* summon = me->ToTempSummon())
                            if (Unit* summoner = summon->GetSummoner())
                                if (Creature* vehicle = summoner->GetVehicleCreatureBase())
                                    if (vehicle->IsAIEnabled)
                                        vehicle->AI()->DoAction(ACTION_QUEST_FAILED);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MOVE_TO_GOAL_POSITION:
                            me->GetMotionMaster()->MovePoint(POINT_GOAL_STALKER, GoalStalkerPositions[_pathIndex], false);
                            _events.ScheduleEvent(EVENT_CHECK_VICTIM_STATE, Seconds(1));
                            break;
                        case EVENT_CHECK_VICTIM_STATE:
                            if (Unit* victim = me->GetVictim())
                            {
                                if (Creature* target = victim->ToCreature())
                                {
                                    if (target->IsAIEnabled)
                                    {
                                        if (target->AI()->GetData(DATA_CURRENT_ENTRY) == NPC_EMPTY_SPOT)
                                        {
                                            me->AttackStop();
                                            me->SetWalk(true);
                                            me->GetMotionMaster()->MovePoint(POINT_GOAL_STALKER, GoalStalkerPositions[_pathIndex], false);
                                        }
                                    }
                                }
                            }

                            _events.Repeat(Seconds(1));
                            break;
                        default:
                            break;
                    }
                }
                DoMeleeAttackIfReady();

            }
        private:
            EventMap _events;
            uint8 _pathIndex;
            bool _notifiedLowHealth;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_brazie_zombieAI(creature);
        }
};

class npc_brazie_vehicle_notifier : public CreatureScript
{
    public:
        npc_brazie_vehicle_notifier() : CreatureScript("npc_brazie_vehicle_notifier") { }

        struct npc_brazie_vehicle_notifierAI : public ScriptedAI
        {
            npc_brazie_vehicle_notifierAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* summoner) override
            {
                switch (me->GetEntry())
                {
                    case NPC_SOLAR_POWER:
                    case NPC_FREEZYA_SEEDS:
                        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                        me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        break;
                    case NPC_PLACE_IT_HERE:
                        me->Relocate(EmptySpotPositions[0]);
                        me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                        break;
                    default:
                        me->SetDisplayId(me->GetCreatureTemplate()->Modelid1);
                        break;
                }

                if (Creature* vehicle = summoner->GetVehicleCreatureBase())
                    if (vehicle->IsAIEnabled)
                        vehicle->AI()->JustSummoned(me);
            }

            void SpellHit(Unit* caster, SpellInfo const* spell) override
            {
                if (!caster)
                    return;

                switch (spell->Id)
                {
                    case SPELL_GAIN_SOLAR_POWER_SPELLCLICK:
                        if (Unit* vehicle = caster->GetVehicleCreatureBase())
                            DoCast(vehicle, SPELL_GAIN_SOLAR_POWER_ENERGIZE, true);
                        me->GetMotionMaster()->MoveJump(SolarPowerJumpPos, 45.0f, 20.0f);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        me->DespawnOrUnsummon(Seconds(2));
                        break;
                    case SPELL_GET_FREEZYA_SEEDS:
                        me->GetMotionMaster()->MoveJump(FreezyaSeedJumpPos, 45.0f, 20.0f);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
                        me->DespawnOrUnsummon(Seconds(2));
                        break;
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_brazie_vehicle_notifierAI(creature);
        }
};

class spell_brazie_summon_plant : public SpellScriptLoader
{
    public:
        spell_brazie_summon_plant() : SpellScriptLoader("spell_brazie_summon_plant") { }

        class spell_brazie_summon_plant_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brazie_summon_plant_SpellScript);

            SpellCastResult CheckLocation()
            {
                if (Creature* creature = GetCaster()->ToCreature())
                    if (CAST_AI(npc_brazie_the_bonatist_vehicle::npc_brazie_the_bonatist_vehicleAI,
                        creature->AI())->IsSpotFree(GetExplTargetDest()->GetPosition()))
                        return SPELL_CAST_OK;

                return SPELL_FAILED_BAD_TARGETS;
            }

            void PreventEffect(SpellEffIndex effIndex)
            {
                PreventHitEffect(effIndex);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                Creature* creature = caster->ToCreature();
                if (!creature)
                    return;

                Unit* target = GetHitUnit();
                if (!target)
                    return;

                if (Creature* dummy = target->FindNearestCreature(NPC_PLACE_IT_HERE, 150.0f, true))
                {
                    dummy->DespawnOrUnsummon();

                    switch (GetSpellInfo()->Id)
                    {
                        case SPELL_PLANT_SPITTER:
                            if (creature->HasAura(SPELL_SPITTER_HIGHLIGHT))
                            {
                                creature->RemoveAurasDueToSpell(SPELL_SPITTER_HIGHLIGHT);
                                if (creature->IsAIEnabled)
                                    creature->AI()->DoAction(ACTION_FIRST_SPITTER_PLANTED);
                            }
                            break;
                        case SPELL_PLANT_SUNFLOWER:
                            if (creature->HasAura(SPELL_SUNFLOWER_HIGHLIGHT))
                                creature->RemoveAurasDueToSpell(SPELL_SUNFLOWER_HIGHLIGHT);
                            break;
                        default:
                            break;
                    }
                }
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_brazie_summon_plant_SpellScript::CheckLocation);
                OnEffectHitTarget += SpellEffectFn(spell_brazie_summon_plant_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
                OnEffectHit += SpellEffectFn(spell_brazie_summon_plant_SpellScript::PreventEffect, EFFECT_0, SPELL_EFFECT_TRANS_DOOR);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_brazie_summon_plant_SpellScript();
        }
};

class spell_brazie_highlight : public SpellScriptLoader
{
    public:
        spell_brazie_highlight() : SpellScriptLoader("spell_brazie_highlight") { }

        class spell_brazie_highlight_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brazie_highlight_SpellScript);

            void SetDestPosition(SpellEffIndex /*effIndex*/)
            {
                const_cast<WorldLocation*>(GetExplTargetDest())->Relocate(EmptySpotPositions[0]);
                GetHitDest()->Relocate(EmptySpotPositions[0]);
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_brazie_highlight_SpellScript::SetDestPosition, EFFECT_1, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_brazie_highlight_SpellScript();
        }
};

class spell_brazie_create_random_seed_sack : public SpellScriptLoader
{
    public:
        spell_brazie_create_random_seed_sack() : SpellScriptLoader("spell_brazie_create_random_seed_sack") { }

        class spell_brazie_create_random_seed_sack_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brazie_create_random_seed_sack_SpellScript);

            void SetDestPosition(SpellEffIndex /*effIndex*/)
            {
                Position const pos = GetSpellInfo()->Id == SPELL_CREATE_RANDOM_FREEZYA_SACK ? FreezyaSeedSummonPos : GetExplTargetDest()->GetPosition();

                const_cast<WorldLocation*>(GetExplTargetDest())->Relocate(pos);
                GetHitDest()->Relocate(pos);
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_brazie_create_random_seed_sack_SpellScript::SetDestPosition, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_brazie_create_random_seed_sack_SpellScript();
        }
};

class spell_brazie_spit : public SpellScriptLoader
{
    public:
        spell_brazie_spit() : SpellScriptLoader("spell_brazie_spit") { }

        class spell_brazie_spit_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brazie_spit_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.empty())
                    return;

                if (GetSpellInfo()->Id == SPELL_VENOM_SPIT)
                {
                    targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));
                    targets.resize(1);
                }
                else
                {
                    std::list<WorldObject*> targetsBackup = targets;
                    targetsBackup.remove_if(Trinity::UnitAuraCheck(true, SPELL_FREEZYA_BLAST));
                    if (targetsBackup.empty())
                    {
                        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));
                        targets.resize(1);
                    }
                    else
                    {
                        targets = targetsBackup;
                        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster(), true));
                        targets.resize(1);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_brazie_spit_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_CONE_ENEMY_104);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_brazie_spit_SpellScript();
        }
};

void AddSC_hillsbrad_foothills()
{
    new npc_brazie_the_bonatist_vehicle();
    new npc_brazie_fertilitize_o_tron_2000();
    new npc_brazie_spot();
    new npc_brazie_zombie();
    new npc_brazie_vehicle_notifier();
    new spell_brazie_summon_plant();
    new spell_brazie_highlight();
    new spell_brazie_create_random_seed_sack();
    new spell_brazie_spit();
}
