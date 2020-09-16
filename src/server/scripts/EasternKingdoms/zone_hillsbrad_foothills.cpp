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
#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "CombatAI.h"
#include "GridNotifiersImpl.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "PassiveAI.h"
#include "PhasingHandler.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellHistory.h"
#include "TemporarySummon.h"
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
    EVENT_ANNOUNCE_LEVEL_COMPLETED      = 9,
    EVENT_EJECT_PASSENGER               = 10,
    EVENT_SUNFLOWER_HIGHLIGHT           = 11,
    EVENT_ANNOUNCE_PLANT_MORE_FLOWERS   = 12,
    EVENT_SUNLIGHT                      = 13,
    EVENT_CREATE_GHOUL                  = 14,
    EVENT_KILL_LANE                     = 15,
    EVENT_PLAGUE_GAS                    = 16,

    // Actions
    ACTION_FIRST_SPITTER_PLANTED        = 1,
    ACTION_FIRST_SUNFLOWER_PLANTED      = 2,
    ACTION_ZOMBIE_DAMAGED               = 3,
    ACTION_ZOMBIE_DIED                  = 4,
    ACTION_GHOUL_DAMAGED                = 5,
    ACTION_QUEST_FAILED                 = 6,

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
    LEVEL_1                             = 1
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

Position const SolarPowerJumpPos    = { -64.24827f, 181.3004f, 53.97961f };
Position const FreezyaSeedSummonPos = { -49.3594f,  220.245f,  56.35883f, 0.01745329f };
Position const FreezyaSeedJumpPos   = { -116.2847f, 216.7865f, 53.2755f };

struct npc_brazie_the_bonatist_vehicle : public VehicleAI
{
    npc_brazie_the_bonatist_vehicle(Creature* creature) : VehicleAI(creature), _summons(me), _currentLevel(LEVEL_TUTORIAL),
        _deadZombieCount(0), _damagedZombieCount(0), _damagedGhoulCount(0), _currentStage(0)
    {
        Inizialize();
    }

    void Inizialize()
    {
        // Figure out at what level we currently are
        InitializeLevel();

        // Add available plants to vehicle action bar depending on level progress
        SetupActionBar();

        // Start events for each corresponding level
        switch (_currentLevel)
        {
            case LEVEL_TUTORIAL:
                _timeUntilNextSolarPower = 4s;
                _events.ScheduleEvent(EVENT_SPITTER_HIGHLIGHT, 1s);
                _events.ScheduleEvent(EVENT_SUMMON_SOLAR_POWER, 1s);
                break;
            case LEVEL_1:
                _timeUntilNextSolarPower = 5s;
                _events.ScheduleEvent(EVENT_SUNFLOWER_HIGHLIGHT, 1s);
                _events.ScheduleEvent(EVENT_SUMMON_SOLAR_POWER, _timeUntilNextSolarPower + 500ms);
                _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, 41s);
                break;
                default:
            break;
        }
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);

        if (summon->GetEntry() == NPC_EMPTY_SPOT)
            _spotGUIDs.push_back(summon->GetGUID());
    }

    void PassengerBoarded(Unit* passenger, int8 /*seatId*/, bool apply) override
    {
        if (!passenger || passenger->GetTypeId() != TYPEID_PLAYER || !me->GetCharmerOrOwner())
            return;

        if (apply)
        {
            PhasingHandler::AddPhase(passenger, PHASE_ID_QUEST, true);
            passenger->CastSpell(passenger, SPELL_PROGRESS_BAR, true);
            SetupSpawns();
        }
        else
        {
            _events.Reset();
            passenger->RemoveAurasDueToSpell(SPELL_PROGRESS_BAR);
            passenger->RemoveAurasDueToSpell(SPELL_CREATE_BOTANISTS_VEHICLE);
            PhasingHandler::RemovePhase(passenger, PHASE_ID_QUEST, true);
            _summons.DespawnAll();
            me->DespawnOrUnsummon(100ms);
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
                me->RemoveAurasDueToSpell(SPELL_SPITTER_HIGHLIGHT);
                _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, 500ms);
                if (Creature* highlight = me->FindNearestCreature(NPC_PLACE_IT_HERE, 100.0f, true))
                    highlight->DespawnOrUnsummon();
                break;
            case ACTION_FIRST_SUNFLOWER_PLANTED:
                me->RemoveAurasDueToSpell(SPELL_SUNFLOWER_HIGHLIGHT);
                if (Creature* highlight = me->FindNearestCreature(NPC_PLACE_IT_HERE, 100.0f, true))
                    highlight->DespawnOrUnsummon();
                break;
            case ACTION_ZOMBIE_DAMAGED:
                _damagedZombieCount++;
                switch (_currentLevel)
                {
                    case LEVEL_TUTORIAL:
                        if (_currentStage < 2)
                            EnterNextStage();
                        break;
                    case LEVEL_1:
                        if (_currentStage == 0 && _damagedZombieCount == 1)
                            EnterNextStage();
                        if (_currentStage == 1 && _damagedZombieCount == 2)
                            EnterNextStage();
                        break;
                    default:
                        break;
                }
                break;
            case ACTION_ZOMBIE_DIED:
                _deadZombieCount++;
                switch (_currentLevel)
                {
                    case LEVEL_TUTORIAL:
                        if (_deadZombieCount == 3)
                            EnterNextStage();
                        if (_deadZombieCount == 8)
                            EnterNextStage();
                        break;
                    case LEVEL_1:
                        if (_deadZombieCount == 4 && _currentStage == 2)
                            EnterNextStage();
                        if (_deadZombieCount == 11 && _currentStage == 3)
                            EnterNextStage();
                        if (_deadZombieCount == 27 && _currentStage == 4)
                            EnterNextStage();
                        break;
                    default:
                        break;
                }
                break;
            case ACTION_GHOUL_DAMAGED:
                _damagedGhoulCount++;
                switch (_currentLevel)
                {
                    case LEVEL_1:
                        if (_damagedGhoulCount == 1)
                        {
                            if (Player* player = GetPlayer())
                            {
                                player->Whisper(SAY_ANNOUNCE_DROPPED_SEED, player, true);
                                player->CastSpell(player, SPELL_CREATE_RANDOM_FREEZYA_SACK, true);
                            }
                        }
                        break;
                    default:
                        break;
                }
                break;
            case ACTION_QUEST_FAILED:
                if (Player* player = GetPlayer())
                {
                    switch (_currentLevel)
                    {
                        case LEVEL_TUTORIAL:
                            player->FailQuest(QUEST_BASIC_BOTANY);
                            break;
                        case LEVEL_1:
                            player->FailQuest(QUEST_FLOWER_POWER);
                            break;
                        default:
                            break;
                    }
                }
                Talk(SAY_ANNOUNCE_ZOMBIES_ATE_BRAIN);
                _summons.DespawnEntry(NPC_ZOMBIE);
                _summons.DespawnEntry(NPC_GHOUL);
                _events.Reset();
                _events.ScheduleEvent(EVENT_EJECT_PASSENGER, 2s + 300ms);
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
                case EVENT_SUNFLOWER_HIGHLIGHT:
                {
                    uint32 textId = 0;
                    uint32 spellId = 0;

                    switch (eventId)
                    {
                        case EVENT_SPITTER_HIGHLIGHT:
                            textId = SAY_ANNOUNCE_TUTORIAL_1;
                            spellId = SPELL_SPITTER_HIGHLIGHT;
                            break;
                        case EVENT_SUNFLOWER_HIGHLIGHT:
                            textId = SAY_ANNOUNCE_PLANT_SUNFLOWER;
                            spellId = SPELL_SUNFLOWER_HIGHLIGHT;
                            break;
                        default:
                            break;
                    }

                    if (Player* player = GetPlayer())
                    {
                        player->Whisper(textId, player, true);
                        player->CastSpell(player, spellId, true);
                    }
                    if (eventId == EVENT_SUNFLOWER_HIGHLIGHT)
                        _events.ScheduleEvent(EVENT_ANNOUNCE_PLANT_MORE_FLOWERS, 1s);
                    break;
                }
                case EVENT_SUMMON_SOLAR_POWER:
                {
                    uint8 randomPositionIndex = urand(0, MAX_EMPTY_SPOT_POSITIONS - 1);
                    Position pos = EmptySpotPositions[randomPositionIndex];
                    float angle = frand(0, float(M_PI * 2));
                    float x = pos.GetPositionX() + cos(angle) * 3;
                    float y = pos.GetPositionY() + sin(angle) * 3;

                    GetPlayer()->CastSpell({ x, y, pos.GetPositionZ() + 50.0f }, SPELL_CREATE_RANDOM_SUN_POWER, true);

                    switch (_currentLevel)
                    {
                        case LEVEL_TUTORIAL:
                            _events.Repeat(_timeUntilNextSolarPower);
                            break;
                        case LEVEL_1:
                            if (_timeUntilNextSolarPower == 5s)
                                _timeUntilNextSolarPower = 10s;
                            else
                                _timeUntilNextSolarPower = 5s;
                            _events.Repeat(_timeUntilNextSolarPower);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case EVENT_CREATE_ZOMBIE:
                case EVENT_CREATE_GHOUL:
                {
                    // The tutorial quest only spawns zombies in the center lane
                    uint8 index = _currentLevel == LEVEL_TUTORIAL ? CENTER_ZOMBIE_LANE_INDEX : urand(0, MAX_TARGET_POSITIONS - 1);
                    Position pos = SpitterTargetPositions[index];
                    float angle = pos.GetAngle(GoalStalkerPositions[index]);

                    uint32 spellId = 0;
                    switch (eventId)
                    {
                        case EVENT_CREATE_ZOMBIE:
                            spellId = SPELL_CREATE_ZOMBIE;
                            break;
                        case EVENT_CREATE_GHOUL:
                            spellId = SPELL_CREATE_GHOUL;
                            break;
                        default:
                            break;
                    }

                    if (Player* player = GetPlayer())
                        player->CastSpell({ pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), angle }, spellId, true);
                    break;
                }
                case EVENT_ANNOUNCE_GOOD_JOB:
                    if (Player* player = GetPlayer())
                        player->Whisper(SAY_ANNOUNCE_TUTORIAL_2, player, true);
                    _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, 1ms);
                    break;
                case EVENT_ANNOUNCE_PLACING_SPITTERS:
                    if (Player* player = GetPlayer())
                        player->Whisper(SAY_ANNOUNCE_TUTORIAL_3, player, true);
                    _events.ScheduleEvent(EVENT_CREATE_ZOMBIE, 1ms);
                    break;
                case EVENT_ANNOUNCE_MASSIVE_WAVE:
                    if (Player* player = GetPlayer())
                        player->Whisper(SAY_ANNOUNCE_MASSIVE_WAVE, player, true);
                    break;
                case EVENT_ANNOUNCE_LEVEL_COMPLETED:
                {
                    if (Player* player = GetPlayer())
                    {
                        uint32 textId = 0;
                        uint32 creditEntry = 0;
                        switch (_currentLevel)
                        {
                            case LEVEL_TUTORIAL:
                                textId = SAY_ANNOUNCE_TUTORIAL_4;
                                creditEntry = CREDIT_BASIC_BOTANY;
                                break;
                            case LEVEL_1:
                                textId = SAY_ANNOUNCE_LEVEL_1_COMPLETE;
                                creditEntry = CREDIT_FLOWER_POWER;
                                break;
                            default:
                                break;
                        }

                        player->Whisper(textId, player, true);
                        player->RemoveAurasDueToSpell(SPELL_PROGRESS_BAR);
                        player->KilledMonsterCredit(creditEntry);
                    }
                    break;
                }
                case EVENT_EJECT_PASSENGER:
                    DoCastSelf(SPELL_EJECT_ALL_PASSENGERS, true);
                    break;
                case EVENT_ANNOUNCE_PLANT_MORE_FLOWERS:
                    if (Player* player = GetPlayer())
                        player->Whisper(SAY_ANNOUNCE_PLANT_MORE_SUNFLOWERS, player, true);
                    break;
                default:
                    break;
            }
        }

    }

public:
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
    Player* GetPlayer() { return me->GetCharmerOrOwner()->ToPlayer(); }

    void SetupSpawns()
    {
        Unit* charmer = me->GetCharmerOrOwner();
        if (!charmer)
            return;

        for (uint8 i = 0; i < MAX_TARGET_POSITIONS; i++)
        {
            Position pos = LawnMowerPositions[i];
            charmer->CastSpell({ pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), LawnmowerOrientation }, SPELL_CREATE_LAWMOWER, true);

            pos = GoalStalkerPositions[i];
            charmer->CastSpell({ pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), GoalStalkerOrientation }, SPELL_CREATE_GOAL_STALKER, true);

            pos = SpitterTargetPositions[i];
            charmer->CastSpell({ pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SpitterTargetOrientation }, SPELL_CREATE_SPITTER_TARGET, true);
        }

        for (uint8 i = 0; i < MAX_EMPTY_SPOT_POSITIONS; i++)
        {
            Position pos = EmptySpotPositions[i];
            charmer->CastSpell({ pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), EmptySpotOrientation }, SPELL_CREATE_EMPTY_SPOT, true);
        }
    }

    void InitializeLevel()
    {
        if (Player* player = GetPlayer())
        {
            if (player->GetQuestStatus(QUEST_BASIC_BOTANY) == QUEST_STATUS_REWARDED
                && player->GetQuestStatus(QUEST_FLOWER_POWER) != QUEST_STATUS_REWARDED)
                _currentLevel = LEVEL_1;
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

        switch (_currentLevel)
        {
            case LEVEL_TUTORIAL:
                if (_currentStage == 1)
                    _events.ScheduleEvent(EVENT_ANNOUNCE_GOOD_JOB, 1ms);
                else if (_currentStage == 2)
                    _events.ScheduleEvent(EVENT_ANNOUNCE_PLACING_SPITTERS, 1ms);
                else if (_currentStage == 3)
                    StartMassiveWave();
                else if (_currentStage == 4)
                {
                    FinishLevel();
                    return;
                }
                break;
            case LEVEL_1:
                if (_currentStage == 1)
                    CreateZombies(2, 5s, 7s);
                else if (_currentStage == 2)
                    CreateZombies(3, 8s, 7s);
                else if (_currentStage == 3)
                {
                    CreateZombies(3, 35s, 5s);
                    CreateGhouls(2, 6s, 39s);
                }
                else if (_currentStage == 4)
                    StartMassiveWave();
                else if (_currentStage == 5)
                {
                    FinishLevel();
                    return;
                }
                break;
            default:
                break;
        }

        GetPlayer()->ModifyPower(POWER_ALTERNATE_POWER, 1);
    }

    void StartMassiveWave()
    {
        switch (_currentLevel)
        {
            case LEVEL_TUTORIAL:
                _events.ScheduleEvent(EVENT_ANNOUNCE_MASSIVE_WAVE, 1ms);
                CreateZombies(5, 1s + 800ms, 3s);
                break;
            case LEVEL_1:
                _events.ScheduleEvent(EVENT_ANNOUNCE_MASSIVE_WAVE, 500ms);
                CreateZombies(2, 2s, 3s);
                CreateZombies(5, 2s, 3s);
                CreateZombies(1, 20s, 0s);
                CreateZombies(2, 20s, 2s);
                CreateZombies(1, 29s, 0s);
                CreateZombies(1, 29s, 0s);

                CreateGhouls(2, 8s, 3s);
                CreateGhouls(1, 26s, 0s);
                CreateGhouls(1, 26s, 0s);
                break;
            default:
                break;
        }
    }

    void FinishLevel()
    {
        _events.Reset();
        _events.ScheduleEvent(EVENT_ANNOUNCE_LEVEL_COMPLETED, 1ms);
        _events.ScheduleEvent(EVENT_EJECT_PASSENGER, 1s + 600ms);
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
    Seconds _timeUntilNextSolarPower;
};

struct npc_brazie_fertilitize_o_tron_2000 : public ScriptedAI
{
    npc_brazie_fertilitize_o_tron_2000(Creature* creature) : ScriptedAI(creature) { }

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

struct npc_brazie_spot : public ScriptedAI
{
    npc_brazie_spot(Creature* creature) : ScriptedAI(creature)
    {
        Initialize();
    }

    void Initialize()
    {
        _currentEntry = me->GetEntry();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
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
                _events.ScheduleEvent(EVENT_SUNLIGHT, 16s);
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

                        summoner->CastSpell({ x, y, pos.GetPositionZ() + 50.0f }, SPELL_CREATE_RANDOM_SUN_POWER, true);
                    }
                }
                _events.Repeat(17s);
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

struct npc_brazie_zombie : public ScriptedAI
{
    npc_brazie_zombie(Creature* creature) : ScriptedAI(creature), _pathIndex(0), _notifiedLowHealth(false)
    {
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

        _events.ScheduleEvent(EVENT_MOVE_TO_GOAL_POSITION, 2s + 400ms);
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

    void JustDied(Unit* /*killer*/) override
    {
        if (TempSummon* summon = me->ToTempSummon())
            if (Unit* summoner = summon->GetSummoner())
                if (Creature* vehicle = summoner->GetVehicleCreatureBase())
                    if (vehicle->IsAIEnabled)
                        vehicle->AI()->DoAction(ACTION_ZOMBIE_DIED);

        me->DespawnOrUnsummon(4s);
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
                    _events.ScheduleEvent(EVENT_CHECK_VICTIM_STATE, 1s);
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
                    _events.Repeat(1s);
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

struct npc_brazie_vehicle_notifier : public ScriptedAI
{
    npc_brazie_vehicle_notifier(Creature* creature) : ScriptedAI(creature) { }

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

class spell_brazie_summon_plant : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_SUNFLOWER_HIGHLIGHT,
                SPELL_SPITTER_HIGHLIGHT
            });
    }

    SpellCastResult CheckLocation()
    {
        if (Creature* creature = GetCaster()->ToCreature())
            if (CAST_AI(npc_brazie_the_bonatist_vehicle,
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
        if (!caster || caster->GetTypeId() != TYPEID_UNIT)
            return;

        Creature* creature = caster->ToCreature();

        if (creature->IsAIEnabled)
        {
            if (creature->HasAura(SPELL_SUNFLOWER_HIGHLIGHT))
                creature->AI()->DoAction(ACTION_FIRST_SUNFLOWER_PLANTED);

            if (creature->HasAura(SPELL_SPITTER_HIGHLIGHT))
                creature->AI()->DoAction(ACTION_FIRST_SPITTER_PLANTED);
        }
    }

    void Register() override
    {
        OnCheckCast.Register(&spell_brazie_summon_plant::CheckLocation);
        OnEffectHitTarget.Register(&spell_brazie_summon_plant::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        OnEffectHit.Register(&spell_brazie_summon_plant::PreventEffect, EFFECT_0, SPELL_EFFECT_TRANS_DOOR);
    }
};

class spell_brazie_highlight : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.Relocate(EmptySpotPositions[0]);
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_brazie_highlight::SetDest, EFFECT_1, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_brazie_create_random_seed_sack : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CREATE_RANDOM_FREEZYA_SACK });
    }

    void SetDest(SpellDestination& dest)
    {
        if (GetSpellInfo()->Id == SPELL_CREATE_RANDOM_FREEZYA_SACK)
            dest.Relocate(FreezyaSeedSummonPos);
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_brazie_create_random_seed_sack::SetDest, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

class spell_brazie_spit : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_VENOM_SPIT,
                SPELL_FREEZYA_BLAST
            });
    }

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
        OnObjectAreaTargetSelect.Register(&spell_brazie_spit::FilterTargets, EFFECT_ALL, TARGET_UNIT_CONE_ENEMY_104);
    }
};

void AddSC_hillsbrad_foothills()
{
    RegisterCreatureAI(npc_brazie_the_bonatist_vehicle);
    RegisterCreatureAI(npc_brazie_fertilitize_o_tron_2000);
    RegisterCreatureAI(npc_brazie_spot);
    RegisterCreatureAI(npc_brazie_zombie);
    RegisterCreatureAI(npc_brazie_vehicle_notifier);
    RegisterSpellScript(spell_brazie_summon_plant);
    RegisterSpellScript(spell_brazie_highlight);
    RegisterSpellScript(spell_brazie_create_random_seed_sack);
    RegisterSpellScript(spell_brazie_spit);
}
