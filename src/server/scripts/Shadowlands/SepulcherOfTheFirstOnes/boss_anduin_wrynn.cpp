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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "DB2Stores.h"
#include "CellImpl.h"
#include "TaskScheduler.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "G3DPosition.hpp"
#include "MoveSplineInitArgs.h"
#include <G3D/Box.h>
#include <G3D/CoordinateFrame.h>
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MovementTypedefs.h"
#include "Object.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "TemporarySummon.h"
#include "UpdateFields.h"
#include "G3D/Vector2.h"
#include "Unit.h"
#include "sepulcher_of_the_first_ones.h"
#include "Weather.h"
#include "GameObjectAI.h"
#include "Containers.h"



enum Spells
{
    // Generic
    SPELL_ANDUIN_PLUNGE_KINGSMOURNE = 369125,
    SPELL_WILLPOWER_DISPLAY = 365177,
    SPELL_WILLPOWER = 365217,
    SPELL_SOUL_DESPAWN = 362766,
    SPELL_SHADESTEP = 363976,
    SPELL_ANDUIN_PROGRESSION_AURA = 369317,
    SPELL_ANDUIN_WILLPOWER_PERIODIC = 366848,
    SPELL_ANDUIN_SOUL_GHOST = 369016,

    // Dark Zeal
    SPELL_DARK_ZEAL_AURA = 364247,
    SPELL_DARK_ZEAL_BUFF = 364248,

    // Hopebreaker
    SPELL_HOPEBREAKER = 361815,
    SPELL_HOPEBREAKER_DAMAGE = 361816,
    SPELL_HOPEBREAKER_DEBUFF = 361817,
    SPELL_HOPEBREAKER_DEBUFF_DAMAGE = 361818,
    SPELL_HOPEBREAKER_CLEAR = 364237,

    // Domination Word: Pain
    SPELL_DOMINATION_WORD_PAIN = 366849,

    // Befouled Barrier
    SPELL_BEFOULED_BARRIER = 365295,
    SPELL_BEFOULED_BARRIER_BLACK_RING = 365633,
    SPELL_BEFOULED_ERUPTION = 365853,
    SPELL_BEFOULED_BARRIER_SPHERE_AREATRIGGER = 365173, 
    SPELL_BEFOULED_BARRIER_DEBUFF = 365293, 
    SPELL_BEFOULED_BARRIER_CLEAR = 369871,
    SPELL_BEFOULED_BARRIER_EXPLODE = 365300,

    // Blasphemy
    SPELL_BLASPHEMY = 361989,
    SPELL_BLASPHEMY_PRE_HIT = 364239, 
    SPELL_BLASPHEMY_OVERCONFIDENCE = 361990,
    SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER = 361992,
    SPELL_BLASPHEMY_HOPELESSNESS = 361991,
    SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER = 361993,
    SPELL_BLASPHEMY_SUCCESS = 362014, 
    SPELL_BLASPHEMY_EXPLODE = 361999, 
    SPELL_BLASPHEMY_DAMAGE_LFR = 366933,
    SPELL_CANCEL_BLASPHEMY = 370161, // if odd number of players in raid, 1 player doesn't get it
    SPELL_BLASPHEMY_IMMUNE = 370407, // coming out of Kingsmourne temporary immune applied on players with kingsmourne

    // Kingsmourne Hungers
    SPELL_KINGSMOURNE_HUNGERS = 362405, 
    SPELL_KINGSMOURNE_HUNGERS_DAMAGE_IDK = 362406,
    SPELL_KINGSMOURNE_HUNGERS_DAMAGE = 362407, 
    SPELL_LOST_SOUL_DIMENSION = 362055, 
    SPELL_LOST_SOUL = 362472, // summons npc
    SPELL_LOST_SOUL_GRACE = 370068, 
    SPELL_LOST_SOUL_CLEAR = 365641,
    SPELL_CANCEL_LOST_SOUL = 367774,
    SPELL_SEVERED_SOUL = 367769, // Mythic
    SPELL_LOST_SOUL_MYTHIC = 367770, // Summmons lost soul, player is summoner
    SPELL_LOST_SOUL_MIRROR_IMAGE = 362402,
    SPELL_SCARRED_SOUL = 365445,
    SPELL_MIRROR_IMAGE = 362474, 
    SPELL_FEIGN_DEATH = 114371, 
    SPELL_BANISH_SOUL = 367771,
    SPELL_MIRROR_IMAGE_IGNORE_PHASE_SHIFT = 362473,

    // Rain of Despair (Big add)
    SPELL_RAIN_OF_DESPAIR = 362391,
    SPELL_ANDUIN_SOUL_DESPAIR = 365220,
    SPELL_RAIN_OF_DESPAIR_MELEE = 362393,
    SPELL_RAIN_OF_DESPAIR_RANGED = 362396,
    SPELL_RAIN_OF_DESPAIR_EXPLOSION = 362392,

    // Wicked Star
    SPELL_WICKED_STAR = 365030, 
    SPELL_WICKED_STAR_POINTER = 365021, 
    SPELL_WICKED_STAR_AREATRIGGER = 365017,
    SPELL_WICKED_STAR_DAMAGE_SILENCE = 365024, 
    SPELL_WICKED_STAR_EMPOWERMENT = 365112,
    SPELL_WICKED_STAR_IDK = 365992, 
    SPELL_WICKED_STAR_TARGETED = 366674, 
    SPELL_WICKED_STAR_IDK_3 = 369280,

    // Empowered Wicked Star
    SPELL_EMPOWERED_WICKED_STAR = 367631,
    SPELL_EMPOWERED_WICKED_STAR_POINTER = 367632,
    SPELL_EMPOWERED_WICKED_STAR_AREATRIGGER = 367621,
    SPELL_EMPOWERED_WICKED_STAR_DAMAGE_SILENCE = 367634,

    // Force of Will
    SPELL_FORCE_OF_WILL = 368913,
    SPELL_CANCEL_FORCE_OF_WILL = 368978,

    // Fiendish Soul
    SPELL_NECROTIC_CLAWS_LEAP = 363019,
    SPELL_NECROTIC_CLAWS_DEBUFF = 363020,   
    SPELL_SOUL_EXPLOSION_TARGET = 363029,
    SPELL_SOUL_EXPLOSION_TRIGGER_MISSILE = 363030,
    SPELL_SOUL_EXPLOSION_DAMAGE = 363031,

    // Monstrous Soul
    SPELL_UNRAVELING_FRENZY_PERIODIC = 363027,
    SPELL_UNRAVELING_FRENZY = 363028,
    SPELL_NECROTIC_DETONATION = 363024,
    
    // Grim Reflections
    SPELL_GRIM_REFLECTIONS = 365120,
    SPELL_GRIM_REFLECTIONS_SUMMON = 365121,
    SPELL_GRIM_REFLECTIONS_DEST_SUMMON = 365039,
    SPELL_CALAMITY_STATE_VISUAL = 361685, 
    SPELL_WICKED_STAR_PROTECTION = 370400,
    SPELL_PSYCHIC_TERROR = 365008,
    SPELL_GRIM_FATE = 367932,

    // Beacon of Hope
    SPELL_BEACON_OF_HOPE = 365872,
    SPELL_BEACON_OF_HOPE_AREATRIGGER = 362702,

    // Purging Light
    SPELL_PURGING_LIGHT = 368428, 

    // Hopelessness
    SPELL_HOPELESSNESS = 365958,
    SPELL_HOPELESSNESS_MISSILE = 365962,
    SPELL_HOPELESSNESS_HOPELESSNESS_AREATRIGGER = 365966,
    SPELL_HOPELESSNESS_EXPLODE = 365971,

    // Empowered Hopebreaker
    SPELL_EMPOWERED_HOPEBREAKER = 365805,
    SPELL_EMPOWERED_HOPEBREAKER_EXPLOSION = 365806,

    // Anduin's Hope
    SPELL_ANDUIN_SLOW = 365218,
    SPELL_GLOOM = 364031,

    // Remnant of a Fallen King
    SPELL_DOMINATION_GRASP = 365216, 
    SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER = 362505, 
    SPELL_SHADE_VISUAL = 362490, // Runic Power
    SPELL_REMNANT_SPAWN = 362500, // Triggers Remorseless Winter
    SPELL_DARK_PRESENCE = 368986,
    SPELL_WEATHER_COSMETIC = 362493, // Cast by the remnant on all players
    SPELL_SPAWN_REMNANT = 362497, // Cast by Anduin
    SPELL_REMNANT_TIMER = 365291,
    SPELL_RETURN_TO_KINGSMOURNE = 363022,
    SPELL_RETURN_TO_KINGSMOURNE_VISUALS = 363021,
    SPELL_SHADE_DESPAWN_CEREMONY = 363023,


    // Remorseless Winter
    SPELL_REMORSELESS_WINTER = 362542, 
    SPELL_REMORSELESS_WINTER_PERIODIC = 362543, // Cast AOE
    SPELL_REMORSELESS_WINTER_DEBUFF_DAMAGE = 362545, // Debuff Damage
    SPELL_REMORSELESS_WINTER_CLEAR = 370619,

    // Army of the Dead
    SPELL_ARMY_OF_THE_DEAD = 362862,
    SPELL_ECHOES_OF_ANDORHAL = 362863,
    SPELL_ECHOES_OF_ANDORHAL_FIENDISH_GHOULS = 362864,
    SPELL_ECHOES_OF_ANDORHAL_MONSTROUS_SOUL = 363025,

    // March of the Damned
    SPELL_MARCH_OF_THE_DAMNED = 363116, // Wall
    SPELL_MARCH_OF_THE_DAMNED_PERIODIC = 363233,
    SPELL_MARCH_OF_THE_DAMNED_AREATRIGGER = 363133,
    SPELL_MARCH_OF_THE_DAMNED_DAMAGE = 364020,
    SPELL_DESPAWN_WALLS = 371694,

    // Soul Reaper
    SPELL_SOUL_REAPER = 362771,
    SPELL_SOUL_REAPER_PHYSICAL_DAMAGE = 362772,
    SPELL_SOUL_REAPER_SHADOWFROST_DAMAGE = 362773,
    SPELL_SOUL_REAPER_DEBUFF = 362774,
    SPELL_SOUL_REAPER_ATTACK_SPEED = 362775,

    // Finish Encounter
    SPELL_ANDUIN_KNEEL_POSE = 369367,
    SPELL_FINAL_MOVIE = 367306,
    SPELL_AWARD_ANDUIN_KILL = 359476, // players cast on themselves

    // Sylvanas Spells
    SPELL_SHOOT_BOW = 364068,
    SPELL_TUMBLE = 364069,

    // Jaina Spells
    SPELL_BLINK = 362844,
    SPELL_FROSTBOLT = 362843,

    // Uther Spells
    SPELL_BLADE_OF_JUSTICE = 363971,
    SPELL_UTHER_CHARGE = 363972,

    SPELL_GENERIC_BLINK = 363984,

};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_REMNANT,
    PHASE_TWO,
    PHASE_REMNANT_TWO,
    PHASE_THREE,

};

enum Data
{
    DATA_REQUIRED_HEALING = 1,
    DATA_ABSORBED_HEALING,
    DATA_ANDUIN_WRYNN_EQUIP_KINGSMOURNE = 183938,

};

enum Events
{
    // Anduin Wrynn
    EVENT_EVADE_CHECK = 1,
    EVENT_HOPEBREAKER,
    EVENT_DOMINATION_WORD_PAIN,
    EVENT_BEFOULED_BARRIER,
    EVENT_UPDATE_BEFOULED_BARRIER,
    EVENT_BLASPHEMY,
    EVENT_HOPELESSNESS,
    EVENT_WICKED_STAR,
    EVENT_EMPOWERED_WICKED_STAR,
    EVENT_KINGSMOURNE_HUNGERS,
    EVENT_INTERMISSION_ONE,
    EVENT_INTERMISSION_TWO,
    EVENT_GRIM_REFLECTIONS,
    EVENT_BEACON_OF_HOPE,
    EVENT_EMPOWERED_HOPEBREAKER,
    EVENT_START_INTERMISSION,
    EVENT_SUMMON_ARTHAS,
    EVENT_NPC_DESPAWN,
    EVENT_BANISH_SOUL,
    EVENT_FINISH_INTRODUCTION,
    EVENT_INTRODUCTION_FINISH,


    // Kingsmourne Room
    EVENT_ANDUIN_SOUL,
    EVENT_ESCAPE_PLATFORM,
    EVENT_DESPAWN_SELF,


    // Remnant of a Fallen King
    EVENT_REMNANT_INTERMISSION_ONE,
    EVENT_REMNANT_INTERMISSION_TWO,
    EVENT_ARMY_OF_THE_DEAD,
    EVENT_SOUL_REAPER,
    EVENT_RETURN_TO_KINGSMOURNE,
    EVENT_CANCEL_EVENTS,

    // Fiendish Soul
    EVENT_GHOUL_LEAP,
    EVENT_NECROTIC_CLAWS,

    // Monstrous Soul
    EVENT_UNRAVELING_FRENZY,

    // Grim Reflections
    EVENT_PSYCHIC_TERROR,
    EVENT_GRIM_REFLECTION_IMMUNITY,

    // Sylvanas Windrunner
    EVENT_TUMBLE,

    // Uther the Lightbringer
    EVENT_BLADE_OF_JUSTICE,

    // Jaina Proudmoore
    EVENT_FROSTBOLT,
    EVENT_BLINK,
    
};

enum Actions
{
    ACTION_START_INTRODUCTION = 1,
    ACTION_FINISH_INTRODUCTION,
    ACTION_START_OUTRODUCTION,
    ACTION_CANCEL_EVENTS,
    ACTION_SUMMON_SOULS,
    ACTION_ARTHAS_INTERMISSION_UTHER,
    ACTION_ARTHAS_INTERMISSION_SYLVANAS,
    ACTION_EXIT_INTERMISSION,
    ACTION_ACTIVATE_REMNANT,
    ACTION_SUMMON_KINGSMOURNE_SOULS,
    ACTION_END_ENCOUNTER,

    // Fiendish Soul
    ACTION_SOUL_EXPLOSION,
    
    // Monstrous Soul
    ACTION_NECROTIC_DETONATION,

    // Grim Reflections
    ACTION_EMPOWER_REFLECTIONS,

    // Lost Soul
    ACTION_RESTORE_SOUL,

};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_HOPEBREAKER = 1,
    SAY_BEFOULED_BARRIER = 2,
    SAY_BLASPHEMY = 3,
    SAY_ANNOUNCE_BLASPHEMY = 4,
    SAY_ANNOUNCE_KINGSMOURNE_HUNGERS = 5,
    SAY_KINGSMOURNE_HUNGERS = 6,
    SAY_WICKED_STAR = 7,
    SAY_ANNOUNCE_WICKED_STAR = 8,
    SAY_GRIM_REFLECTIONS = 9,
    SAY_SLAY = 10,
    SAY_EMPOWERED_HOPEBREAKER = 11,
    SAY_DISENGAGE = 12,
};

enum Conversations
{
    CONVERSATION_INTRO = 17835,
    CONVERSATION_ARTHAS_UTHER = 17921,
    CONVERSATION_ARTHAS_SYLVANAS = 17923, 
    CONVERSATION_ANDUIN_PHASE_THREE = 17924,
    CONVERSATION_ANDUIN_OUTRODUCTION = 17836,
};

enum SpawnGroups
{
    SPAWN_GROUP_INITIAL = 0
};

enum Points
{
    POINT_ANDUIN_SOUL = 1,
    POINT_ESCAPE_PLATFORM = 2,
    POINT_MARCH_OF_THE_DAMNED = 3,
};

enum SpellVisuals
{
    SPELL_VISUAL_IDK = 114658, // Cast by Anduin
    SPELL_VISUAL_CHEST_LOOT = 114023,

};

enum MiscData
{
    MUSIC_ANDUIN_ENGAGED = 193829,
    MUSIC_ARTHAS_UTHER = 193832,
    MUSIC_ARTHAS_SYLVANAS = 193831,

};

Position const DominationGraspCenter = { -3825.0601f, -2715.4600f, 91.3567, 1.6260f };

Position const IntermissionAssisters[3] =
{
    { -3828.472f, -2688.191f, 91.2652f, 1.9153f }, // Sylvanas
    { -3819.519f, -2687.170f, 91.2652f, 2.1812f }, // Uther
    { -3824.960f, -2692.550f, 91.2652f, 1.5733f }, // Jaina

};

Position const AnduinsDespair = { -3828.355957f, -2704.1875f, 91.350716f, 4.982021f };

Position const AnduinsSoul = { -3825.060059f, -2715.459961f, 91.356697f, 1.626040f };

Position const AnduinsDoubt[4] =
{
    {  -3852.638916f, -2687.373291f, 91.348526f, 5.560700f }, // Right of Uther
    {  -3852.845459f, -2742.732666f, 91.348534f, 0.961583f }, // Next Right
    {  -3797.704834f, -2686.685791f, 91.348526f, 3.804689f }, // Left of Sylvanas
    {  -3799.805664f, -2740.925293f, 91.348541f, 2.247305f }, // Next Left
};

Position const AnduinsHope[4] =
{
    {  -3825.149414f, -2711.508789f, 91.354919f, 1.463445f }, // In front of Anduin
    {  -3828.751709f, -2715.171875f, 91.354919f, 3.221487f }, // Left of Anduin
    {  -3821.041748f, -2715.296875f, 91.354889f, 0.046978f }, // Right of Anduin
    {  -3825.180664f, -2719.208252f, 91.354820f, 4.741285f }, // Behind Anduin

};

Position const RemnantofaFallenKing = { -3825.2466f, -2700.0486f, 91.3650f, 1.3762f };

Position const GrimReflections[4] =
{
    { -3825.389f, -2739.4202f, 91.431305f, 4.8445f}, // back side of Anduin
    { -3849.8438f, -2715.0574f, 91.40953f, 2.9961f}, // left side of Anduin
    { -3825.4966f, -2692.6199f, 91.487495f, 1.4654f}, // in front of Anduin
    { -3800.6980f, -2715.4340f, 91.390780f, 6.2769f}, // right side of Anduin
};

Position const MarchOfTheDamned[8] =
{
    { -3839.8489f, -2679.7708f, 91.53031f, 5.1081f }, // First right
    { -3860.8940f, -2701.0051f, 91.53032f, 5.9010f }, // Second Right
    { -3860.5696f, -2729.7344f, 91.53032f, 0.3886f }, // Third Right
    { -3839.6390f, -2750.8890f, 91.53032f, 1.1935f }, // Fourth Right
    { -3811.0625f, -2679.6528f, 91.53031f, 4.3362f }, // First left
    { -3789.8125f, -2700.5088f, 91.53032f, 3.5383f }, // Second Left
    { -3789.2812f, -2729.3160f, 91.53032f, 2.7669f }, // Third Left
    { -3810.4290f, -2751.0903f, 91.53032f, 1.9584f } // Fourth Left side
};

Position const BeaconOfHope = { -3825.0417f, -2715.3923f, 91.3568f, 0.0f };

Position const ChestLoot = { -3840.99f, -2741.78f, 91.2652f, 1.33493f };

template<typename T>
struct Timers : public std::list<T>
{
    Timers() = default;

    Timers(const std::initializer_list<T>& _list) :
        std::list<T>(_list) {};

    T nextTimer()
    {
        if (this->empty())
            throw std::logic_error("Timers is empty!");

        T timer = this->front();
        if (this->size() > 1)
            this->pop_front();

        return timer;
    }
};

Timers<uint32> HopeBreakerP1{ 31900, 28000, 29900, 29900 };
Timers<uint32> HopeBreakerP2 { 24900, 32900, 29000, 28900 };
Timers<uint32> BefouledBarrierTimerP1 { 51900, 48000 };
Timers<uint32> BefouledBarrierTimerP2 { 47000 };
Timers<uint32> BlasphemyAll { 49900, 54900 };
Timers<uint32> DominationWordPainP1 { 13000, 13000, 10000, 15000, 13100, 12900, 13000, 13900, 12200, 14800 };
Timers<uint32> DominationWordPainP2 { 13000, 13000, 17700, 8100, 13000, 13000, 14400, 11200, 12200 };
Timers<uint32> WickedStarP1 { 34900, 29900 };
Timers<uint32> WickedStarP2 { 39000, 25900, 30800, 19100 };

class StandStill : public BasicEvent
{
public:
    StandStill(Unit* actor, bool paused) : _actor(actor), _paused(paused) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        if (_paused)
        {
            _actor->GetMotionMaster()->Clear();
            _actor->StopMoving();
            _actor->AttackStop();
            _actor->AddUnitState(UNIT_STATE_ROOT);
        }
        else
        {
            _actor->ToCreature()->SetReactState(REACT_AGGRESSIVE);
            _actor->ClearUnitState(UNIT_STATE_ROOT);
        }
        return true;
    }

private:
    Unit* _actor;
    bool _paused;
};

class ActivateGhouls : public BasicEvent
{
public:
    ActivateGhouls(Creature* summoner, Creature* owner)
        : _summonerGuid(summoner->GetGUID()), _owner(owner)
    {
    }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        if (Creature* _summoner = ObjectAccessor::GetCreature(*_owner, _summonerGuid))
            if (Unit* target = _summoner->AI()->SelectTarget(SelectTargetMethod::Random, 0))
            {
                _owner->SetReactState(REACT_AGGRESSIVE);
                _owner->AI()->AttackStart(target);
            }
        return true;
    }


private:
    ObjectGuid _summonerGuid;
    Creature* _owner;
};

class ExactDistanceCheck
{
public:
    ExactDistanceCheck(Unit* source, float dist) : _source(source), _dist(dist) { }

    bool operator()(WorldObject* unit)
    {
        return _source->GetExactDist2d(unit) > _dist;
    }

private:
    Unit* _source;
    float _dist;
};


// Anduin Wrynn - 181954
struct boss_anduin_wrynn : public BossAI
{
    boss_anduin_wrynn(Creature* creature) : BossAI(creature, DATA_ANDUIN_WRYNN),
        _dominationWordCount(0), encounterEnded(false), isInphaseThree(false), _bridgeUsed(false)
    {
        Initialize();
    }

    void Initialize()
    {
        if (GameObject* bridge = me->FindNearestGameObject(GAMEOBJECT_BRIDGE_AFTER_ANDUIN, 500.0f))
        {
            if (instance->GetData(DATA_ANDUIN_WRYNN_INTRODUCTION) != DONE && _bridgeUsed == false)
                bridge->SetLootState(GO_READY);
                bridge->UseDoorOrButton(0, false);
                _bridgeUsed = true;
        }

        _dominationWordCount = 0;
        isInPhaseTwo = false;
        isInphaseThree = false;
        me->SetFaction(14);

        if (encounterEnded != false)
        { 
            if (GameObject* bridge = me->FindNearestGameObject(GAMEOBJECT_BRIDGE_AFTER_ANDUIN, 500.0f))
            {
                bridge->SetLootState(GO_READY);
                bridge->UseDoorOrButton(0, false);
            }
            // Need a better way to handle this
        } 
    }

    void HandleIntroduction()
    {
        if (instance->GetData(DATA_ANDUIN_WRYNN_INTRODUCTION) == DONE)
        {
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetImmuneToAll(false);
            me->SetSpeed(MOVE_RUN, 11.0f);
            me->RemoveAurasDueToSpell(SPELL_ANDUIN_PLUNGE_KINGSMOURNE);
        }
        else
        {
            DoCastSelf(SPELL_ANDUIN_PLUNGE_KINGSMOURNE);
            me->SetUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
            me->SetImmuneToAll(true);
            me->SetSpeed(MOVE_WALK, 10.0f);

            
        }
    }

    void DoCheckEvade()
    {
        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
            if (Player* player = i->GetSource())
                if (player->IsAlive() && IsInBoundary(player) && !player->IsGameMaster())
                    return;

        EnterEvadeMode(EvadeReason::NoHostiles);
    }

    void IntermissionPositions()
    {
        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER);
        Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE);

        if (!sylvanas || !uther || !jaina)
            return;

        sylvanas->CastSpell(Position(IntermissionAssisters[0]), SPELL_GENERIC_BLINK, false);
        sylvanas->AttackStop();
        uther->CastSpell(Position(IntermissionAssisters[1]), SPELL_GENERIC_BLINK, false);
        uther->AttackStop();
        jaina->CastSpell(Position(IntermissionAssisters[2]), SPELL_GENERIC_BLINK, false);
        jaina->AttackStop();

    }


    void JustAppeared() override
    {
        IntermissionPositions();
        //events.ScheduleEvent(EVENT_INTERMISSION_ONE, 1s);
        //DoCastSelf(SPELL_BEFOULED_BARRIER);
        scheduler.ClearValidator();
        instance->SetData(DATA_ANDUIN_WRYNN, DONE);
        me->SetVirtualItem(0, DATA_ANDUIN_WRYNN_EQUIP_KINGSMOURNE);
        instance->SetData(DATA_ANDUIN_WRYNN_INTRODUCTION, DONE);
        //DoAction(ACTION_FINISH_INTRODUCTION);
        // Sometimes Anduin spawns without equipped Kingsmourne so equipping it from here
        //HandleIntroduction();
        _dominationWordCount = 0; // we will use this to reset his mechanics before intermission as it's the last spell cast
        //me->AddUnitMovementFlag(MOVEMENTFLAG_ROOT); // for some reason he will not stop and cast his abilities unless he has this flag
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetPowerType(POWER_ENERGY, true);
        me->ModifyPower(POWER_ENERGY, 0, true);
        DoCastSelf(SPELL_WILLPOWER_DISPLAY, true);
        DoCastSelf(SPELL_DARK_ZEAL_AURA, true);
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 0);
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_INTERMISSION, 0);

    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        Talk(SAY_DISENGAGE);

        _EnterEvadeMode();
        summons.DespawnAll();
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 0);
        instance->SetData(DATA_ANDUIN_WRYNN, NOT_STARTED);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPEBREAKER_DEBUFF);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_REMORSELESS_WINTER_PERIODIC);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOMINATION_WORD_PAIN);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WEATHER_COSMETIC);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LOST_SOUL_DIMENSION);
        instance->SetBossState(DATA_ANDUIN_WRYNN, NOT_STARTED);
        _DespawnAtEvade();

        if (GameObject* bridge = me->FindNearestGameObject(GAMEOBJECT_BRIDGE_TO_ANDUIN, 500.0f))
        {
            bridge->SetGoState(GO_STATE_READY);
            bridge->RemoveFlag(GO_FLAG_IN_USE);
        }

    }

    void Reset() override
    {
        _Reset();
        _dominationWordCount = 0;
        me->SummonCreatureGroup(SPAWN_GROUP_INITIAL);
        events.Reset();
        //instance->SetData(DATA_ANDUIN_WRYNN_INTRODUCTION, NOT_STARTED);

    }

    void KilledUnit(Unit* victim) override
    {

        Talk(SAY_SLAY);

    }

    //void SpellHitTarget(WorldObject* target, SpellInfo const* spell) override
    //{
    //    switch (spell->Id)
    //    {
    //    case SPELL_KINGSMOURNE_HUNGERS_DAMAGE:
    //    {
    //        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
    //        {
    //            target->CastSpell(target, SPELL_SEVERED_SOUL);

    //        } 
    //        break;
    //    }

    //    }
    //}


    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
        case NPC_BEFOULED_BARRIER:
        {
            summon->SetReactState(REACT_PASSIVE);
            summon->CastSpell(summon, SPELL_BEFOULED_ERUPTION, true);
            summon->CastSpell(summon, SPELL_BEFOULED_BARRIER_SPHERE_AREATRIGGER, true);
            summon->CastSpell(summon, SPELL_BEFOULED_BARRIER_BLACK_RING, true);
            break;
        }

        case BOSS_REMNANT_OF_A_FALLEN_KING:
        {
            summon->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            summon->CastSpell(summon, SPELL_REMNANT_SPAWN);
            summon->SetReactState(REACT_PASSIVE);
            break;
        }

        case NPC_MARCH_OF_THE_DAMNED:
        {
            summon->SetSpeedRate(MOVE_RUN, 0.55f);
            summon->SetReactState(REACT_PASSIVE);
            summon->CastSpell(summon, SPELL_MARCH_OF_THE_DAMNED_AREATRIGGER, true);
            Position exitPlatform = summon->GetFirstCollisionPosition(100.0f, 0.0f);
            summon->GetMotionMaster()->MovePoint(POINT_MARCH_OF_THE_DAMNED, exitPlatform, false, true);

            break;
        }

        case NPC_BEACON_OF_HOPE:
        {
            summon->SetReactState(REACT_PASSIVE);
            summon->CastSpell(summon, SPELL_BEACON_OF_HOPE_AREATRIGGER, false);
            break;
        }
            break;

        default:
            break;
        }
    }
    

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        switch (summon->GetEntry())
        {
            case NPC_ANDUIN_DOUBT:
            {

                break;
            }
            case NPC_ANDUIN_DESPAIR:
            {
                summon->ToTempSummon()->SetTempSummonType(TEMPSUMMON_CORPSE_DESPAWN);
                break;
            }

            case NPC_GRIM_REFLECTION:
            {
                summon->GetGUID();
                summon->AI()->DoAction(ACTION_EMPOWER_REFLECTIONS);
                summon->ToTempSummon()->SetTempSummonType(TEMPSUMMON_MANUAL_DESPAWN);
                summon->DespawnOrUnsummon(1s);
                break;
            }

            case NPC_LOST_SOUL:
            {
                summon->GetAI()->DoAction(ACTION_RESTORE_SOUL);
            }


            break;
        default:
            break;
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 1);
        instance->SetData(DATA_ANDUIN_WRYNN, DONE);
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        DoCastSelf(369317);
        //PhaseEvents(PHASE_ONE);
        //events.ScheduleEvent(EVENT_INTERMISSION_ONE, 1s);
        Talk(SAY_AGGRO);

        scheduler.Schedule(10s, [this](TaskContext /*task*/)
            {
                if (GameObject* bridge = me->FindNearestGameObject(GAMEOBJECT_BRIDGE_TO_ANDUIN, 500.0f))
                {
                    bridge->SetLootState(GO_READY);
                    bridge->UseDoorOrButton(0, false);
                }
            });     
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
        case ACTION_FINISH_INTRODUCTION:
        {
            scheduler.Schedule(3s, [this](TaskContext /*task*/)
                {
                    instance->SetData(DATA_ANDUIN_WRYNN_INTRODUCTION, DONE);
                });
            break;
        }

        case ACTION_START_INTRODUCTION:
        {
            instance->SetData(DATA_ANDUIN_WRYNN_INTRODUCTION, IN_PROGRESS);
            scheduler.Schedule(37s, [this](TaskContext /*task*/)
                {
                    instance->SetData(DATA_ANDUIN_WRYNN_INTRODUCTION, DONE);
                });

            if (Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER))
            {
                if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE))
                    {
                        ObjectGuid utherGUID = uther->GetGUID();
                        ObjectGuid sylvanasGUID = sylvanas->GetGUID();
                        ObjectGuid jainaGUID = jaina->GetGUID();

                        
                        Conversation* introductionAnduin = Conversation::CreateConversation(CONVERSATION_INTRO, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false);
                        introductionAnduin->AddActor(NPC_UTHER_THE_LIGHTBRINGER, 1, utherGUID);
                        introductionAnduin->AddActor(NPC_SYLVANAS_WINDRUNNER, 2, sylvanasGUID);
                        introductionAnduin->AddActor(NPC_LADY_JAINA_PROUDMOORE, 3, jainaGUID);
                        introductionAnduin->Start();

                    }
                }
            }
            
            
            break;
        }

        case ACTION_START_OUTRODUCTION:
        {

            if (Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER))
            {
                if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
                {
                    if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE))
                    {
                        if (Creature* firim = instance->GetCreature(DATA_FIRIM))
                        { 
                            
                            ObjectGuid utherGUID = uther->GetGUID();
                            ObjectGuid sylvanasGUID = sylvanas->GetGUID();
                            ObjectGuid jainaGUID = jaina->GetGUID();

                            Conversation* introductionAnduin = Conversation::CreateConversation(CONVERSATION_ANDUIN_OUTRODUCTION, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false);
                            introductionAnduin->AddActor(NPC_LADY_JAINA_PROUDMOORE, 1, jainaGUID);
                            introductionAnduin->AddActor(NPC_SYLVANAS_WINDRUNNER, 2, sylvanasGUID);
                            introductionAnduin->AddActor(NPC_UTHER_THE_LIGHTBRINGER, 3, utherGUID);
                            introductionAnduin->AddActor(NPC_FIRIM, 4, firim->GetGUID());
                            introductionAnduin->Start();
                        }

                    }
                }
            }


            break;
        }
        

        case ACTION_SUMMON_SOULS:
        {
            if (Creature* anduinSoul = instance->GetCreature(DATA_ANDUIN_SOUL))
            { 
                anduinSoul->GetAI()->DoAction(ACTION_SUMMON_KINGSMOURNE_SOULS);
            }
            break;
        }
        case ACTION_CANCEL_EVENTS:
        {
            events.CancelEvent(EVENT_HOPEBREAKER);
            events.CancelEvent(EVENT_DOMINATION_WORD_PAIN);
            events.CancelEvent(EVENT_BEFOULED_BARRIER);
            events.CancelEvent(EVENT_KINGSMOURNE_HUNGERS);
            events.CancelEvent(EVENT_WICKED_STAR);
            events.CancelEvent(EVENT_BLASPHEMY);
            events.CancelEvent(EVENT_GRIM_REFLECTIONS);
            _dominationWordCount = 0;
            break;
        }

        case ACTION_ARTHAS_INTERMISSION_UTHER:
        {
            instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_INTERMISSION, 1);
            instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 0);
            if (Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER))
            {
                ObjectGuid utherGUID = uther->GetGUID();
                Conversation* conversationUther = Conversation::CreateConversation(CONVERSATION_ARTHAS_UTHER, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false);
                conversationUther->AddActor(NPC_UTHER_THE_LIGHTBRINGER, 1, utherGUID);
                conversationUther->Start();
            }
            break;

        }

        case ACTION_ARTHAS_INTERMISSION_SYLVANAS:
        {
            instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_INTERMISSION, 2);
            instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 0);
            if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            {
                ObjectGuid sylvanasGUID = sylvanas->GetGUID();
                Conversation* conversationSylvanas = Conversation::CreateConversation(CONVERSATION_ARTHAS_SYLVANAS, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false);
                conversationSylvanas->AddActor(NPC_SYLVANAS_WINDRUNNER, 1, sylvanasGUID);
                conversationSylvanas->Start();

            }
            break;
        }

        case ACTION_EXIT_INTERMISSION:
        {
            if (isInPhaseTwo == false && HealthAbovePct(10))
            {
                isInPhaseTwo = true;
                PhaseEvents(PHASE_TWO);
                me->RemoveUnitFlag(UNIT_FLAG_STUNNED);

                scheduler.Schedule(3s, [this](TaskContext /*task*/)
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                    });
            }

            else if (isInPhaseTwo == true && HealthAbovePct(10))
            {
                isInphaseThree = true;
                PhaseEvents(PHASE_THREE);
                me->RemoveUnitFlag(UNIT_FLAG_STUNNED);

                scheduler.Schedule(6s, [this](TaskContext /*task*/)
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                    });
            }
            break;
        }

        case ACTION_END_ENCOUNTER:
        {
            EndEncounter();
            break;
        }

        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {


        scheduler.Update(diff);
        
        if (!UpdateVictim())
            return;
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_EVADE_CHECK:
            {
                DoCheckEvade();
                events.Repeat(1s);
                break;
            }
            case EVENT_HOPEBREAKER:
            {
                Talk(SAY_HOPEBREAKER);
                DoCastSelf(SPELL_HOPEBREAKER);
                (events.IsInPhase(PHASE_ONE) ?
                    events.Repeat(Milliseconds(HopeBreakerP1.nextTimer())) :
                    events.Repeat(Milliseconds(HopeBreakerP2.nextTimer())));
                break;
            }

            case EVENT_FINISH_INTRODUCTION:
            {
                instance->SetData(DATA_ANDUIN_WRYNN_INTRODUCTION, DONE);
                break;
            }

            case EVENT_EMPOWERED_HOPEBREAKER:
            {
                Talk(SAY_EMPOWERED_HOPEBREAKER);
                DoCastSelf(SPELL_EMPOWERED_HOPEBREAKER, false);
                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                {
                    events.Repeat(65500ms);
                }
                else
                    events.Repeat(58400ms);
                break;
            }

            case EVENT_DOMINATION_WORD_PAIN:
            {
                _dominationWordCount++;
                std::list<Unit*> targets;
                SelectTargetList(targets, 5, SelectTargetMethod::Random, 0, 500.0f, true, true); // TODO: change based on difficulty
                for (Unit* target : targets)
                    DoCast(target, SPELL_DOMINATION_WORD_PAIN);
                (events.IsInPhase(PHASE_ONE) ?
                    events.Repeat(Milliseconds(DominationWordPainP1.nextTimer())) :
                    events.Repeat(Milliseconds(DominationWordPainP2.nextTimer())));

                if (events.IsInPhase(PHASE_ONE) && _dominationWordCount == 11)
                { 
                        DoAction(ACTION_CANCEL_EVENTS);
                }

                else if (events.IsInPhase(PHASE_TWO) && _dominationWordCount == 11)
                {
                        DoAction(ACTION_CANCEL_EVENTS);
                }
                break;

            }

            case EVENT_BEFOULED_BARRIER:
            {
                DoCastSelf(SPELL_BEFOULED_BARRIER);
                Talk(SAY_BEFOULED_BARRIER);
                (events.IsInPhase(PHASE_ONE) ?
                    events.Repeat(Milliseconds(BefouledBarrierTimerP1.nextTimer())) :
                    events.Repeat(Milliseconds(BefouledBarrierTimerP2.nextTimer())));
                break;
            }

            case EVENT_BLASPHEMY:
            {
                DoCastAOE(SPELL_BLASPHEMY);
                Talk(SAY_ANNOUNCE_BLASPHEMY);
                Talk(SAY_BLASPHEMY);
                events.Repeat(Milliseconds(BlasphemyAll.nextTimer()));
                break;
            }

            case EVENT_HOPELESSNESS:
            {
                DoCastAOE(SPELL_HOPELESSNESS);
                Talk(SAY_ANNOUNCE_BLASPHEMY);
                Talk(SAY_BLASPHEMY);
                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC)
                {
                    events.Repeat(65500ms);
                }
                else
                    events.Repeat(58400ms);
                break;
            }

            case EVENT_WICKED_STAR:
            {
                
                DoCastSelf(SPELL_WICKED_STAR);
                Talk(SAY_WICKED_STAR);

                // 3 stars for Normal and Heroic - to be handled by the spell script alone / 6 for Mythic other 3 added on event
                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                {
                    std::list<Player*> playerList;
                    GetPlayerListInGrid(playerList, me, 300.0f);
                    Trinity::Containers::RandomResize(playerList, 3);

                    if (Unit* targetOne = SelectTarget(SelectTargetMethod::Random, 0, 300.0f, true, false, -SPELL_WICKED_STAR_TARGETED || -SPELL_WICKED_STAR_POINTER))
                    { 
                        ObjectGuid targetOneGUID = targetOne->GetGUID();
                        DoCast(targetOne, SPELL_WICKED_STAR_POINTER, true);
                        if (Player* wickedStarOne = targetOne->ToPlayer())
                            playerList.remove(wickedStarOne);

                    }

                    Unit* secondStar = playerList.front();
                    Unit* thirdStar = playerList.back();

                    ObjectGuid starTwoGUID = secondStar->GetGUID();
                    ObjectGuid starThreeGUID = thirdStar->GetGUID();

                scheduler.Schedule(3009ms, [this, starTwoGUID](TaskContext /*task*/)
                    {

                        if (Player* target = ObjectAccessor::GetPlayer(*me, starTwoGUID))
                        {
                            me->CastSpell(target, SPELL_WICKED_STAR_POINTER, true);

                        }
                    });

                scheduler.Schedule(6009s, [this, starThreeGUID](TaskContext /*task*/)
                    {
                        if (Player* target = ObjectAccessor::GetPlayer(*me, starThreeGUID))
                        {
                            me->CastSpell(target, SPELL_WICKED_STAR_POINTER, true);

                        }
                    });

                }

                    (events.IsInPhase(PHASE_ONE) ?
                        events.Repeat(Milliseconds(WickedStarP1.nextTimer())) :
                        events.Repeat(Milliseconds(WickedStarP2.nextTimer())));
                break;

            }

            case EVENT_EMPOWERED_WICKED_STAR:
            {
                Talk(SAY_WICKED_STAR);

                break;
            }

            case EVENT_KINGSMOURNE_HUNGERS:
            {
                
                DoCastVictim(SPELL_KINGSMOURNE_HUNGERS, false);
                Talk(SAY_ANNOUNCE_KINGSMOURNE_HUNGERS);
                Talk(SAY_KINGSMOURNE_HUNGERS);
                events.Repeat(60s);
                break;
            }

            case EVENT_GRIM_REFLECTIONS:
            {
                Talk(SAY_GRIM_REFLECTIONS);
                DoCastSelf(SPELL_GRIM_REFLECTIONS);
                events.Repeat(87000ms);
                break;

            }

            case EVENT_BEACON_OF_HOPE:
            {
                DoCastSelf(SPELL_BEACON_OF_HOPE);
                break;
            }

            


            case EVENT_INTERMISSION_ONE:
            {
                scheduler.Schedule(1ms, [this](TaskContext /*task*/)
                    {
                        me->AttackStop();
                        me->SetReactState(REACT_PASSIVE);
                        DoCastSelf(SPELL_SHADESTEP);
                        me->NearTeleportTo(DominationGraspCenter, false);
                        IntermissionPositions();
                    });


                scheduler.Schedule(1204ms, [this](TaskContext /*task*/)
                    {

                        DoAction(ACTION_ARTHAS_INTERMISSION_UTHER);
                        
                    });

                scheduler.Schedule(2204ms, [this](TaskContext /*task*/)
                    {

                        me->SetFacingTo(1.626040f);

                    });

                scheduler.Schedule(4s, [this](TaskContext /*task*/)
                    {                
                        DoCastSelf(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
                        DoCastSelf(SPELL_FORCE_OF_WILL);
                        DoCastSelf(SPELL_HOPEBREAKER_CLEAR);
                        me->SummonCreature(BOSS_REMNANT_OF_A_FALLEN_KING, RemnantofaFallenKing, TEMPSUMMON_MANUAL_DESPAWN);
                    if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                    {
                        me->CastSpell(arthas, SPELL_DOMINATION_GRASP, false);
                        me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                    }
                    });

                scheduler.Schedule(5s, [this](TaskContext /*task*/)
                    {
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                        }
                    });

                scheduler.Schedule(6s, [this](TaskContext /*task*/)
                    {
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                        }
                    });

                scheduler.Schedule(7s, [this](TaskContext /*task*/)
                    {
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                        }
                    });

                scheduler.Schedule(8100ms, [this](TaskContext /*task*/)
                    {
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                            arthas->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                            arthas->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                            arthas->SetReactState(REACT_PASSIVE);

                            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                            {
                                DoCastSelf(SPELL_MARCH_OF_THE_DAMNED_PERIODIC);
                            }
                        }
                    });

                break;
            }

            case EVENT_INTERMISSION_TWO:
            {
                scheduler.Schedule(1ms, [this](TaskContext /*task*/)
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->CastSpell(Position{ DominationGraspCenter }, SPELL_SHADESTEP, false);
                        me->NearTeleportTo(DominationGraspCenter, false);
                    });


                scheduler.Schedule(1204ms, [this](TaskContext /*task*/)
                    {
                        DoAction(ACTION_ARTHAS_INTERMISSION_SYLVANAS);
                    });

                scheduler.Schedule(2204ms, [this](TaskContext /*task*/)
                    {

                        me->SetFacingTo(1.626040f);

                    });

                scheduler.Schedule(4s, [this](TaskContext /*task*/)
                    {
                        me->SetFacingTo(1.626040f);
                        DoCastSelf(SPELL_FORCE_OF_WILL);
                        DoCastSelf(SPELL_HOPEBREAKER_CLEAR);
                        DoCastSelf(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
                        me->SummonCreature(BOSS_REMNANT_OF_A_FALLEN_KING, RemnantofaFallenKing, TEMPSUMMON_MANUAL_DESPAWN);
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_DOMINATION_GRASP, false);
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                        }
                    });

                scheduler.Schedule(5s, [this](TaskContext /*task*/)
                    {
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                        }
                    });

                scheduler.Schedule(6s, [this](TaskContext /*task*/)
                    {
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                        }
                    });

                scheduler.Schedule(7s, [this](TaskContext /*task*/)
                    {
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                        }
                    });

                scheduler.Schedule(8s, [this](TaskContext /*task*/)
                    {
                        DoCastSelf(SPELL_MARCH_OF_THE_DAMNED_PERIODIC);
                        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                        {
                            me->CastSpell(arthas, SPELL_SPAWN_REMNANT, false);
                            arthas->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
                            arthas->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                        }  
                    });

                break;
            }
            
            case EVENT_START_INTERMISSION:
            {
                DoCastSelf(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
                me->SummonCreature(BOSS_REMNANT_OF_A_FALLEN_KING, RemnantofaFallenKing, TEMPSUMMON_MANUAL_DESPAWN);
                break;
            }


            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

    void PhaseEvents(uint8 phase)
    {
        events.Reset();

        switch (phase)
        {
        case PHASE_ONE:
        {
            events.SetPhase(PHASE_ONE);
            if (me->GetMap()->GetDifficultyID() == DIFFICULTY_LFR_NEW)
            {
                DoCastSelf(SPELL_ANDUIN_WILLPOWER_PERIODIC, true);
            }

            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_LFR_NEW)
            {
                events.ScheduleEvent(EVENT_KINGSMOURNE_HUNGERS, 45000ms);
            }
                /*events.ScheduleEvent(EVENT_HOPEBREAKER, 5000ms);
                events.ScheduleEvent(EVENT_BEFOULED_BARRIER, 17000ms);
                events.ScheduleEvent(EVENT_BLASPHEMY, 30000ms);                
                events.ScheduleEvent(EVENT_WICKED_STAR, 55000ms);
                events.ScheduleEvent(EVENT_DOMINATION_WORD_PAIN, 7000ms);*/
                events.ScheduleEvent(EVENT_INTERMISSION_ONE, 1s);        
                break;
            }
        

            case PHASE_TWO:
            {
                events.SetPhase(PHASE_TWO);
                if (me->GetMap()->GetDifficultyID() == DIFFICULTY_LFR_NEW)
                {
                    DoCastSelf(SPELL_ANDUIN_WILLPOWER_PERIODIC, true);
                }

                if (me->GetMap()->GetDifficultyID() != DIFFICULTY_LFR_NEW)
                {
                    events.ScheduleEvent(EVENT_KINGSMOURNE_HUNGERS, 48600ms);
                }

                events.ScheduleEvent(EVENT_GRIM_REFLECTIONS, 8500ms);
                events.ScheduleEvent(EVENT_BEFOULED_BARRIER, 80600ms);
                events.ScheduleEvent(EVENT_HOPEBREAKER, 13600ms);
                events.ScheduleEvent(EVENT_WICKED_STAR, 18600ms);
                events.ScheduleEvent(EVENT_DOMINATION_WORD_PAIN, 10600ms);
                events.ScheduleEvent(EVENT_INTERMISSION_TWO, 155s);
                break;

            }

            case PHASE_THREE:
            {
                events.SetPhase(PHASE_THREE);
                Conversation* conversationFinal = Conversation::CreateConversation(CONVERSATION_ANDUIN_PHASE_THREE, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false);
                conversationFinal->Start();
                events.ScheduleEvent(EVENT_BEACON_OF_HOPE, 3000ms);
                events.ScheduleEvent(EVENT_EMPOWERED_HOPEBREAKER, 11000ms);
                events.ScheduleEvent(EVENT_HOPELESSNESS, 21500ms);
                events.ScheduleEvent(EVENT_EMPOWERED_WICKED_STAR, 41000ms);
                break;
            }
        }
    }

    void ExitIntermission()
    {
        if (isInPhaseTwo == true && HealthAbovePct(10))
        {
            isInphaseThree = true;
            PhaseEvents(PHASE_THREE);
            me->RemoveUnitFlag(UNIT_FLAG_STUNNED);

            scheduler.Schedule(3s, [this](TaskContext /*task*/)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                });
        }


        else if (isInPhaseTwo == false && HealthAbovePct(10))
        {

            isInPhaseTwo = true;
            PhaseEvents(PHASE_TWO);
            me->RemoveUnitFlag(UNIT_FLAG_STUNNED);

            scheduler.Schedule(3s, [this](TaskContext /*task*/)
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                });
        }

    }

    //void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    //{
    //    if (damage < me->GetHealth())
    //        return;

    //    else
    //    {
    //        me->SetHealth(1);
    //        damage = 0;
    //    }

    //}

    void EndEncounter()
    {
        encounterEnded = true;
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_COMPLETED, 1);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPEBREAKER_DEBUFF);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPELESSNESS_HOPELESSNESS_AREATRIGGER);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BEFOULED_BARRIER_EXPLODE);
        me->InterruptNonMeleeSpells(true);

        Map::PlayerList const& players = me->GetMap()->GetPlayers();
        for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
            if (Player* player = i->GetSource())
            { 
                player->AttackStop();
                player->InterruptNonMeleeSpells(true);
            }

        events.Reset();
        summons.DespawnAll();
        me->SetReactState(REACT_PASSIVE);
        me->SetFaction(35);
        DoCastSelf(SPELL_ANDUIN_KNEEL_POSE);
        Talk(SAY_DISENGAGE);
        instance->SetBossState(DATA_ANDUIN_WRYNN, DONE);

        if (GameObject* bridge = me->FindNearestGameObject(GAMEOBJECT_BRIDGE_TO_ANDUIN, 500.0f))
        {
            bridge->SetLootState(GO_READY);
            bridge->UseDoorOrButton(0, false);
        }

        if (GameObject* bridgeCredit = me->FindNearestGameObject(GAMEOBJECT_BRIDGE_AFTER_ANDUIN, 500.0f))
        {
            bridgeCredit->SetLootState(GO_READY);
            bridgeCredit->UseDoorOrButton(0, false);
        }

        if (GameObject* chest = me->SummonGameObject(GAMEOBJECT_ANDUIN_CHEST_LOOT, ChestLoot, QuaternionData::fromEulerAnglesZYX(3.27f, 0.0f, 0.0f), 7_days))
        {
            //chest->SendPlaySpellVisual(chest->GetPosition(), SPELL_VISUAL_CHEST_LOOT, 0, 0, 0, false);
        }

        scheduler.Schedule(5s, [this](TaskContext /*task*/)
            {
                instance->DoCastSpellOnPlayers(SPELL_FINAL_MOVIE);
            });
        
    }


private:
    uint8 _dominationWordCount;
    TaskScheduler scheduler;
    std::vector<ObjectGuid> _wickedStarTargetGUIDs;
    bool isInPhaseTwo;
    bool encounterEnded;
    bool isInphaseThree;
    bool _bridgeUsed;

};

int32 absorbAmount;
int32 GetAbsorbAmount()
{
    return absorbAmount;
}

uint32 GetRequiredHealing(Unit* caster)
{
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_BEFOULED_BARRIER_DEBUFF, caster->GetMap()->GetDifficultyID());
    uint32 requiredHealing = spellInfo->GetEffect(EFFECT_0).CalcValue();
    return requiredHealing;
}

uint32 RemainingHealing(Unit* caster, uint32 actualHealing)
{
    uint32 requiredHealing = GetRequiredHealing(caster);

    if (actualHealing >= requiredHealing)
    {
        return 0;
    }
    else
    {
        return requiredHealing - actualHealing;
    }
}



// Befouled Barrier - 184585
struct npc_anduin_wrynn_befouled_barrier : public ScriptedAI
{
    npc_anduin_wrynn_befouled_barrier(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
        _events.ScheduleEvent(EVENT_NPC_DESPAWN, 30s);
        _events.ScheduleEvent(EVENT_UPDATE_BEFOULED_BARRIER, 1s);
        me->SetReactState(REACT_PASSIVE);

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
            case EVENT_NPC_DESPAWN:
                //me->DespawnOrUnsummon(1s);
                break;

            case EVENT_UPDATE_BEFOULED_BARRIER:
            {
                SetData(DATA_REQUIRED_HEALING, GetData(DATA_ABSORBED_HEALING));
            }
            default:
                break;
            }
        }

    }

    uint32 GetRequiredHealing() const
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_BEFOULED_BARRIER_DEBUFF, me->GetMap()->GetDifficultyID());
        return spellInfo->GetEffect(EFFECT_0).CalcValue();
    }

    uint32 GetCurrentHealing() const
    {

    }

    void SetCurrentHealing(uint32 currentHealing)
    {


    }


    void Reset() override
    {
        _events.Reset();
        me->SetReactState(REACT_PASSIVE);
    }


private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;

};

// Empty Vessel - 183452
struct npc_anduin_wrynn_empty_vessel : public ScriptedAI
{
    npc_anduin_wrynn_empty_vessel(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);

    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (!summoner->IsPlayer())
            return;

        if (!summoner)
            return;

        summoner->CastSpell(me, SPELL_MIRROR_IMAGE);
        DoCast(me, SPELL_FEIGN_DEATH);
    }

    void Reset() override
    {
        _events.Reset();

    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

// Lost Soul - 185607
struct npc_anduin_wrynn_lost_soul : public ScriptedAI
{
    npc_anduin_wrynn_lost_soul(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(EVENT_BANISH_SOUL, 1ms);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (!summoner->IsPlayer())
            return;

        if (!summoner)
            return;

        summoner->CastSpell(me, SPELL_LOST_SOUL_MIRROR_IMAGE);
    }

    void JustDied(Unit* killer) override
    {
        DoAction(ACTION_RESTORE_SOUL);
        me->DespawnOrUnsummon(2s);       
    }

    void Reset() override
    {
        _events.Reset();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {

        case ACTION_RESTORE_SOUL:
        {
            if (Unit* summoner = me->ToTempSummon()->GetSummonerUnit())
            {
                if (!summoner)
                    return;

                summoner->RemoveAurasDueToSpell(SPELL_SEVERED_SOUL);
                summoner->NearTeleportTo(me->GetPosition(), false);
            }
            break;
        }

        default:
            break;
        }
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
            case EVENT_BANISH_SOUL:
                DoCastSelf(SPELL_BANISH_SOUL);
                _events.Repeat(1ms);
                break;
            default:
                break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
};

// Anduin's Soul - 184519
struct npc_anduin_wrynn_anduin_soul : public ScriptedAI
{
    npc_anduin_wrynn_anduin_soul(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()), _summons(me) { }

    void JustAppeared() override
    {
        me->SetDisableGravity(true, true);
        me->SetHoverHeight(30.0f);
    }

    void Reset() override
    {
        _summons.DespawnAll();
        DoCastSelf(SPELL_ANDUIN_SOUL_GHOST, true);
    }

    void JustSummoned(Creature* who) override
    {
        _summons.Summon(who);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _summons.DespawnAll();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _summons.DespawnAll();
        DoCastSelf(SPELL_ANDUIN_SOUL_GHOST, true);
    }

    void DoAction(int32 action) override
    {
        Creature* anduin = _instance->GetCreature(DATA_ANDUIN_SOUL);
        if (!anduin)
            return;

        switch (action)
        {

        case ACTION_SUMMON_KINGSMOURNE_SOULS:
        {
            me->SummonCreature(NPC_ANDUIN_DESPAIR, AnduinsDespair, TEMPSUMMON_TIMED_DESPAWN, 40s);
            for (uint8 i = 0; i < 4; i++)
            {
                me->SummonCreature(NPC_ANDUIN_DOUBT, AnduinsDoubt[i], TEMPSUMMON_TIMED_DESPAWN, 40s);
                me->SummonCreature(NPC_ANDUIN_HOPE, AnduinsHope[i], TEMPSUMMON_TIMED_DESPAWN, 40s);
            }
            break;
        }
        default:
            break;
        }
    }

private:
    SummonList _summons;
    EventMap _events;
    InstanceScript* const _instance;
    TaskScheduler _scheduler;
};

// Anduin's Despair - 184520
struct npc_anduin_wrynn_anduin_despair : public ScriptedAI
{
    npc_anduin_wrynn_anduin_despair(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
        DoCastSelf(SPELL_RAIN_OF_DESPAIR);
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustDied(Unit* killer) override
    {
        DoCastSelf(SPELL_SOUL_DESPAWN);
        if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_WRYNN))
        {
            anduin->CastSpell(anduin, SPELL_WILLPOWER, true);
            me->DespawnOrUnsummon(2s);
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// Anduin's Doubt - 184494
struct npc_anduin_wrynn_anduin_doubt : public ScriptedAI
{
    npc_anduin_wrynn_anduin_doubt(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustAppeared() override
    {
        DoZoneInCombat();
        me->SetSpeed(MOVE_WALK, 0.550000011920928955f);
        me->GetMotionMaster()->MovePoint(POINT_ANDUIN_SOUL, AnduinsSoul);

    }

    void JustDied(Unit* killer) override
    {
        DoCastSelf(SPELL_SOUL_DESPAWN);
        if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_WRYNN))
        {
            me->DespawnOrUnsummon(1s);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
        case POINT_ANDUIN_SOUL:
            me->DespawnOrUnsummon(1ms);
            break;

        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {

        _events.Update(diff);
        _scheduler.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_ANDUIN_SOUL:
                me->GetMotionMaster()->MovePoint(POINT_ANDUIN_SOUL, AnduinsSoul);
                _events.Repeat(1ms);
                break;
            default:
                break;
            }
        }

    }

private:
    EventMap _events;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// Anduin's Hope - 184493
struct npc_anduin_wrynn_anduin_hope : public ScriptedAI
{
    npc_anduin_wrynn_anduin_hope(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        me->SetRegenerateHealth(false);
        me->SetHealth(1.0f);
        me->SetReactState(REACT_PASSIVE);

    }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_HEROIC_RAID || me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
        {
            DoCastSelf(SPELL_GLOOM);
        }

        DoZoneInCombat();
        me->SetHealth(1.0f);
        me->SetSpeed(MOVE_RUN, 1.0f);
        me->SetReactState(REACT_PASSIVE);
        Position exitPlatform = me->GetFirstCollisionPosition(100.0f, 0.0f);
        me->GetMotionMaster()->MovePoint(POINT_ESCAPE_PLATFORM, exitPlatform);

        _scheduler.Schedule(40s, [this](TaskContext /*task*/)
            {
                me->DespawnOrUnsummon();
            });

    }

    void HealReceived(Unit* healer, uint32& heal) override
    {
        if (me->HealthAbovePctHealed(100, heal))
        {
            DoCastSelf(SPELL_SOUL_DESPAWN);

            if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_WRYNN))
            {
                anduin->CastSpell(anduin, SPELL_WILLPOWER, true);
                me->DespawnOrUnsummon(1s);
            }          
        }
    }

    

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
        case POINT_ESCAPE_PLATFORM:
            if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_WRYNN))
            {
                DoCastSelf(SPELL_SOUL_DESPAWN);
                me->DespawnOrUnsummon(1s);
            } 
            break;

        default:
            break;
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    Position _anduinHope;
    TaskScheduler _scheduler;
};

// Fiendish Soul - 183669
struct npc_anduin_wrynn_fiendish_soul : public ScriptedAI
{
public:
    npc_anduin_wrynn_fiendish_soul(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustEngagedWith(Unit* who) override
    {
        _events.ScheduleEvent(EVENT_GHOUL_LEAP, 1s);
        _events.ScheduleEvent(EVENT_NECROTIC_CLAWS, 5s);

    }

    void JustDied(Unit* /*killer*/) override
    {
        if (me->GetMapId() == DIFFICULTY_HEROIC_RAID || me->GetMapId() == DIFFICULTY_MYTHIC_RAID)
        { 
            DoAction(ACTION_SOUL_EXPLOSION);
        }
    }


    void DoAction(int32 action) override
    {
        switch (action)
        {

        case ACTION_SOUL_EXPLOSION:
        {
            std::list<Player*> targetList;
            GetPlayerListInGrid(targetList, me, 300.0f);
            for (Player* target : targetList)
                me->CastSpell(target, SPELL_SOUL_EXPLOSION_TRIGGER_MISSILE, true);
            break;
        }

        default:
            break;
        }
    }


    void UpdateAI(uint32 diff) override
    {

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        _scheduler.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GHOUL_LEAP:
                {
                    std::list<Player*> targetList;
                    GetPlayerListInGrid(targetList, me, 300.0f);
                    for (Player* target : targetList)
                        me->CastSpell(target, SPELL_NECROTIC_CLAWS_LEAP, true);

                    _scheduler.Schedule(1ms, [this](TaskContext /*task*/)
                        {
                            DoCastVictim(SPELL_NECROTIC_CLAWS_DEBUFF);
                        });

                    _events.Repeat(10s);
                    break;

                }

                case EVENT_NECROTIC_CLAWS:
                {
                    DoCastVictim(SPELL_NECROTIC_CLAWS_DEBUFF);
                    _events.Repeat(5s);
                    break;
                }

            default:
                break;
            }

        }
        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// Monstrous Soul - 183671
struct npc_anduin_wrynn_monstrous_soul : public ScriptedAI
{
public:
    npc_anduin_wrynn_monstrous_soul(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustEngagedWith(Unit* who) override
    {
        DoCastSelf(SPELL_UNRAVELING_FRENZY_PERIODIC, true);

    }

    void DamageTaken(Unit* /*attacker*/, uint32& /*damage*/, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (!HealthAbovePct(35))
        {
            DoAction(ACTION_NECROTIC_DETONATION);
        }
    }


    void DoAction(int32 action) override
    {
        switch (action)
        {

        case ACTION_NECROTIC_DETONATION:
        {
            DoCastSelf(SPELL_NECROTIC_DETONATION);
            break;
        }
        break;
        default:
            break;
        }
    }


    void UpdateAI(uint32 diff) override
    {

        if (!UpdateVictim())
            return;

        _events.Update(diff);
        _scheduler.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// Remnant of a Fallen King - 183463
struct boss_remnant_of_a_fallen_king : public BossAI
{
    boss_remnant_of_a_fallen_king(Creature* creature) : BossAI(creature, DATA_REMNANT_OF_A_FALLEN_KING) { }


    void JustAppeared() override
    {
        scheduler.ClearValidator();
        me->SetObjectScale(1.0f);
        me->SetPowerType(POWER_ENERGY, true);
        DoCastSelf(SPELL_SHADE_VISUAL);
        me->SetFaction(16);
         Map::PlayerList const& players = me->GetMap()->GetPlayers();
         for (Map::PlayerList::const_iterator i = players.begin(); i != players.end(); ++i)
             if (Player* player = i->GetSource())
                 me->CastSpell(player, SPELL_WEATHER_COSMETIC, true);
         instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPEBREAKER);
         me->SetReactState(REACT_PASSIVE);

    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {

        _EnterEvadeMode();
        summons.DespawnAll();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WEATHER_COSMETIC);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_REMORSELESS_WINTER_PERIODIC);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NECROTIC_CLAWS_DEBUFF);
    }

    void ContinueAttacking()
    {
        Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER);
        Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER);
        Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE);

        sylvanas->GetAI()->AttackStartCaster(me, 25.0f);
        uther->GetAI()->AttackStart(me);
        jaina->GetAI()->AttackStartCaster(me, 25.0f);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
    }


    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {

            case NPC_FIENDISH_SOUL:
            case NPC_MONSTROUS_SOUL:
                summon->SetReactState(REACT_PASSIVE);
                summon->m_Events.AddEvent(new ActivateGhouls(me, summon), summon->m_Events.CalculateTime(5s));
                break;

        default:
            break;
        }

    }
    void DoAction(int32 action) override
    {
        switch (action)
        {

        case ACTION_ACTIVATE_REMNANT:
        {
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            DoCastAOE(SPELL_DARK_PRESENCE);
            DoZoneInCombat();

            scheduler.Schedule(2s, [this](TaskContext task)
                {
                    {
                        events.ScheduleEvent(EVENT_ARMY_OF_THE_DEAD, 1ms);
                        events.ScheduleEvent(EVENT_SOUL_REAPER, 8000ms);
                        events.ScheduleEvent(EVENT_RETURN_TO_KINGSMOURNE, 68s);
                        me->SetReactState(REACT_AGGRESSIVE);
                        ContinueAttacking();
                        
                    }
                });

            break;

        }     

        default:
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {

        events.Update(diff);

        if (!UpdateVictim())
            return;

        scheduler.Update(diff);

        

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {

                case EVENT_RETURN_TO_KINGSMOURNE:
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->InterruptNonMeleeSpells(true);

                    if (Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN))
                    {
                        DoCast(anduin, SPELL_RETURN_TO_KINGSMOURNE, true);
                        DoCast(anduin, SPELL_RETURN_TO_KINGSMOURNE_VISUALS);
                    }
                    break;
                }

                case EVENT_ARMY_OF_THE_DEAD:
                {
                    DoCastSelf(SPELL_ARMY_OF_THE_DEAD);
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.Repeat(36900ms);
                    break;
                }

                case EVENT_SOUL_REAPER:
                {
                    DoCastVictim(SPELL_SOUL_REAPER, false);
                    events.Repeat(12s);
                    break;

                }

            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap events;
    TaskScheduler scheduler;
};

// Grim Reflection - 183033
struct npc_anduin_wrynn_grim_reflection : public ScriptedAI
{
    npc_anduin_wrynn_grim_reflection(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
        SetCombatMovement(false);
        DoCastSelf(SPELL_CALAMITY_STATE_VISUAL);
        DoZoneInCombat();
        me->SetReactState(REACT_AGGRESSIVE);
        _events.ScheduleEvent(EVENT_PSYCHIC_TERROR, 1ms);

        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_LFR_NEW || me->GetMap()->GetDifficultyID() == DIFFICULTY_NORMAL_RAID)
            // Wicked Stars do not Empower Reflections below Heroic
        {
            _events.ScheduleEvent(EVENT_GRIM_REFLECTION_IMMUNITY, 1ms);
        }           
    }

    void JustDied(Unit* killer) override
    {
        if (me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
        { 
            DoCastAOE(SPELL_GRIM_FATE);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_PSYCHIC_TERROR:
                DoCastSelf(SPELL_PSYCHIC_TERROR);
                _events.Repeat(Seconds(2));
                break;

            case EVENT_GRIM_REFLECTION_IMMUNITY:
            {
                DoCastSelf(SPELL_WICKED_STAR_PROTECTION);
                _events.Repeat(1s);
                break;
            }

            break;
            default:
                break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

    }

private:
    EventMap _events;
    TaskScheduler _scheduler;
    InstanceScript* _instance;
};


// 183666 - Sylvanas Windrunner
struct npc_anduin_wrynn_sylvanas : public ScriptedAI
{
    npc_anduin_wrynn_sylvanas(Creature* creature) : ScriptedAI(creature, DATA_SYLVANAS_WINDRUNNER),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {

        damage = 0;
    }

    void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) override
    {

        damage = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        AddThreat(who, 500000.0f);
        _events.ScheduleEvent(EVENT_TUMBLE, 10s);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_TUMBLE:
            {
                DoCastSelf(SPELL_TUMBLE);
                _events.Repeat(10s);
                break;
            }

            default:
                break;
            }
        }

        DoSpellAttackIfReady(SPELL_SHOOT_BOW);
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
};

// 183664 - Jaina Proudmoore
struct npc_anduin_wrynn_jaina : public ScriptedAI
{
    npc_anduin_wrynn_jaina(Creature* creature) : ScriptedAI(creature, DATA_JAINA_PROUDMOORE),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void Reset() override
    {
        _events.Reset();
    }


    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        damage = 0;
    }

    void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) override
    {
        damage = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
            _events.ScheduleEvent(EVENT_BLINK, 10s);
        
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_BLINK:
            {
                DoCastSelf(SPELL_BLINK);
                _events.Repeat(60s);
                break;
            }

            case EVENT_FROSTBOLT:
            {
                DoCastVictim(SPELL_FROSTBOLT);
                _events.Repeat(1s);
                break;
            }
                

            default:
                break;
            }
        }

        DoSpellAttackIfReady(SPELL_FROSTBOLT);
    }


private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
};

// 183665 - Uther The Lightbringer
struct npc_anduin_wrynn_uther : public ScriptedAI
{
    npc_anduin_wrynn_uther(Creature* creature) : ScriptedAI(creature, DATA_UTHER_THE_LIGHTBRINGER),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        damage = 0;
    }

    void DamageDealt(Unit* /*victim*/, uint32& damage, DamageEffectType /*damageType*/) override
    {
        damage = 0;
    }

    void JustEngagedWith(Unit* who) override
    {
        _events.ScheduleEvent(EVENT_BLADE_OF_JUSTICE, 1s);
        DoCastVictim(SPELL_UTHER_CHARGE);
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);

        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_BLADE_OF_JUSTICE:
            {
                DoCastVictim(SPELL_BLADE_OF_JUSTICE);
                _events.Repeat(10s);
                break;
            }

            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
};

// 369317 - Anduin Progression Aura (Can't be reduced < 1 hp)
class spell_anduin_wrynn_progression_aura : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_progression_aura);

    bool Load() override
    {
        return true;
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        amount = -1;
        canBeRecalculated = true;
    }

    void Trigger(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        if (!GetTarget()->GetAura(SPELL_ANDUIN_PROGRESSION_AURA))
            return;

        if (dmgInfo.GetDamage() <= GetTarget()->GetHealth())
            return;

        if (dmgInfo.GetDamage() >= GetTarget()->GetHealth())
        {
            absorbAmount = dmgInfo.GetDamage();
            if (!triggered)
            {
                GetTarget()->SetHealth(1);
                GetTarget()->CastSpell(GetTarget(), SPELL_ANDUIN_KNEEL_POSE);
                GetTarget()->GetAI()->DoAction(ACTION_END_ENCOUNTER);
                GetTarget()->SetFaction(35);
                triggered = true;
                absorbAmount = dmgInfo.GetDamage();
            }
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_progression_aura::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_anduin_wrynn_progression_aura::Trigger, EFFECT_0);
    }

private:
    bool triggered;
};

// 366848 - Anduin Willpower Periodic (Only LFR)
class spell_anduin_wrynn_energize_willpower_lfr : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_energize_willpower_lfr);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();        
        powerGained = _anduinRegenCycle[powerRegenCycle++];

        if (powerRegenCycle >= 22)
            powerRegenCycle = 0;

        target->ModifyPower(target->GetPowerType(), powerGained);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anduin_wrynn_energize_willpower_lfr::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    uint8 powerRegenCycle = 0;
    uint32 powerGained = 0;
    static constexpr std::array<int32, 22> _anduinRegenCycle =
    { 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 }; // 0.681 willpower per second as on Retail
    
};

// Dark Zeal - 364247
class spell_anduin_wrynn_dark_zeal : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_dark_zeal);

    bool Load() override
    {
        currentTank = ObjectGuid::Empty;
        return true;
    }

    void OnProc(AuraEffect* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = eventInfo.GetActor();
        Unit* target = eventInfo.GetActionTarget();

        GetCaster()->CastSpell(GetCaster(), SPELL_DARK_ZEAL_BUFF, true);

        if (!caster || !target)
            return;

        if (target->GetGUID() == currentTank)
            return;

        PreventDefaultAction();
        caster->RemoveAura(SPELL_DARK_ZEAL_BUFF);
        currentTank = target->GetGUID();
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_anduin_wrynn_dark_zeal::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

private:
    ObjectGuid currentTank;
};

// Hopebreaker - 361815
class spell_anduin_wrynn_hopebreaker : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_hopebreaker);

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HOPEBREAKER_DAMAGE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HOPEBREAKER_DEBUFF, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_hopebreaker::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Hopebreaker Periodic - 361817
class spell_anduin_wrynn_hopebreaker_periodic : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_hopebreaker_periodic);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        GetCaster()->CastSpell(GetTarget(), SPELL_HOPEBREAKER_DEBUFF_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anduin_wrynn_hopebreaker_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// Hopebreaker Damage - 361818
class spell_anduin_wrynn_hopebreaker_damage : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_hopebreaker_damage);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (!caster)
            return;

        Aura* hopebreaker = target->GetAura(SPELL_HOPEBREAKER_DEBUFF);
        uint8 hopebreakerStacks = hopebreaker->GetStackAmount();
        SetHitDamage(int32(GetHitDamage() * (uint8)hopebreakerStacks));

    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_hopebreaker_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Befouled Barrier - 365173, AT - 24332  NYI
/*struct at_anduin_wrynn_befouled_barrier : AreaTriggerAI
{
    at_anduin_wrynn_befouled_barrier(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnInitialize() override
    {
        TaggedPosition<Position::XY> pointA = TaggedPosition<Position::XY>(0.0f, 1.0f);
        TaggedPosition<Position::XY> pointB = { 1.0f, 1.0f };
        //at->SetTimeToTargetScale(500);
        //at->SetOverrideScaleCurve(true, pointA, pointB, at->GetTimeSinceCreated(), pointB.Pos.m_positionY);
    }

    void OnUpdate(uint32 diff) override
    {
        if (updateTimer <= diff)
        {
            updateTimer = 1000;

            float sizeChange = 0.1f;

            //TaggedPosition<Position::XY> pointA = TaggedPosition<Position::XY>(0.0f, at->GetOverrideScaleCurve().point0.Pos.m_positionY);
            TaggedPosition<Position::XY> pointB = { 1.0f, pointB.Pos.m_positionY + sizeChange };

            float newRadius = 6.0f * pointB.Pos.m_positionY;

            //at->SetRadius(newRadius);
            //at->SetOverrideScaleCurve(true, pointA, pointB, at->GetTimeSinceCreated(), 33554432u);
            
        }
        else
            updateTimer -= diff;
    }

    void OnUnitEnter(Unit* unit) override
    {
        at->GetCaster()->CastSpell(unit, SPELL_BEFOULED_BARRIER_DEBUFF, true);
    }

    void OnUnitExit(Unit* unit) override
    {

        if (unit->HasAura(SPELL_BEFOULED_BARRIER_DEBUFF))
            unit->RemoveAura(SPELL_BEFOULED_BARRIER_DEBUFF);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    float maxRadius = 12.0f;
    uint32 updateTimer;
    uint32 healingRequired;
    uint32 healingDone;
}; */

// March of the Damned - 363133, AT - 24093  NYI
struct at_anduin_wrynn_march_of_the_damned : AreaTriggerAI
{
    at_anduin_wrynn_march_of_the_damned(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }



    void OnUnitEnter(Unit* unit) override
    {
        at->GetCaster()->CastSpell(unit, SPELL_MARCH_OF_THE_DAMNED_DAMAGE, true);
    }

    void OnUnitExit(Unit* unit) override
    {

        if (unit->HasAura(SPELL_MARCH_OF_THE_DAMNED_DAMAGE))
            unit->RemoveAura(SPELL_MARCH_OF_THE_DAMNED_DAMAGE);
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};




// 365173 - Befouled Barrier
//class spell_anduin_wrynn_befouled_barrier_at_aura : public AuraScript
//{
//    PrepareAuraScript(spell_anduin_wrynn_befouled_barrier_at_aura);
//
////public:
////    void BarrierAbsorbDone(uint32 absorbAmount)
////    {
////        _absorbDone += absorbAmount;
////
////        // @TODO: update barrier size here
////
////        if (_absorbDone < _absorbRequired)
////            return;
////
////        // remove barrier, we're done healing
////        if (Creature* target = GetTarget()->ToCreature())
////            target->DespawnOrUnsummon();
////    }
//
//private:
//    bool Validate(SpellInfo const* /*spellInfo*/) override
//    {
//        return ValidateSpellInfo(
//            {
//                SPELL_BEFOULED_BARRIER_DEBUFF, // = 365293
//                SPELL_BEFOULED_BARRIER_EXPLODE   // @TODO: fixme
//            });
//    }
//
//    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_BEFOULED_BARRIER_DEBUFF, GetTarget()->GetMap()->GetDifficultyID()))
//            _absorbRequired = spellInfo->GetEffect(EFFECT_0).CalcValue(GetTarget());
//    }
//
//    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//
//        // only do explo if expires
//        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        GetTarget()->CastSpell(nullptr, SPELL_BEFOULED_BARRIER_EXPLODE);
//    }
//
//    void Register() override
//    {
//        AfterEffectApply += AuraEffectRemoveFn(spell_anduin_wrynn_befouled_barrier_at_aura::OnApply, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
//        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_befouled_barrier_at_aura::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
//    }
//
//    uint32 _absorbDone = 0;
//    uint32 _absorbRequired = 0;
//};



// Befouled Barrier - 365173, AT - 24332  NYI
struct at_anduin_wrynn_befouled_barrier : AreaTriggerAI
{
    at_anduin_wrynn_befouled_barrier(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger), _instance(at->GetInstanceScript()) { }

    void OnInitialize() override
    {
        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_BEFOULED_BARRIER_DEBUFF, at->GetCaster()->GetMap()->GetDifficultyID()))
            _absorbRequired = spellInfo->GetEffect(EFFECT_0).CalcValue(at->GetCaster());

        at->SetTimeToTargetScale(30000);

        // The aura is handling it automatically
        at->SetDuration(-1);
    }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        /*_scheduler.Schedule(500ms, [this](TaskContext context)
        {
            float lastRadius = at->GetScaleCurveValue(m_areaTriggerData->OverrideScaleCurve, GetProgress())
            AreaTriggerScaleCurveTemplate curveTemplate;
            curveTemplate.StartTimeOffset = at->GetElapsedTimeForMovement();

            AreaTriggerScaleCurvePointsTemplate curve;
            curve.Mode = CurveInterpolationMode::Linear;
            curve.Points[0] = DBCPosition2D(0, 1.0f);
            curve.Points[1] = DBCPosition2D(1, 12.0f);
            curveTemplate.Curve = curve;
            at->SetTestData(curveTemplate);
        });*/
    }

    void OnUpdate(uint32 diff) override
    {
        // @TODO: calculate barrier size dynamically
    }

    void OnUnitEnter(Unit* unit) override
    {
        at->GetCaster()->CastSpell(unit, SPELL_BEFOULED_BARRIER_DEBUFF, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        if (unit->HasAura(SPELL_BEFOULED_BARRIER_DEBUFF))
            unit->RemoveAura(SPELL_BEFOULED_BARRIER_DEBUFF);
    }


public:
    void Absorb(uint32 absorbAmount)
    {
        _absorbDone += absorbAmount;

        if (_absorbDone < _absorbRequired)
            return;

        Unit* target = at->GetTarget();
        if (!target)
            return;

        // remove barrier, we're done healing
        if (Creature* creature = target->ToCreature())
            creature->DespawnOrUnsummon();
    }

    uint32 GetRemainingAbsorb()
    {
        return _absorbRequired - _absorbDone;
    }

private:
    uint32 _absorbDone = 0;
    uint32 _absorbRequired = 0;
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 365293 - Befouled Barrier Absorb 365295
class spell_anduin_wrynn_befouled_barrier_absorb : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_befouled_barrier_absorb);

    void OnHealAbsorb(AuraEffect* /*aurEff*/, HealInfo& healInfo, uint32& absorbAmount)
    {
        absorbAmount = CalculatePct(healInfo.GetHeal(), GetEffectInfo(EFFECT_2).CalcValue());

        Unit* caster = GetCaster();
        if (!caster)
            return;

        AreaTrigger* barrier = caster->GetAreaTrigger(SPELL_BEFOULED_BARRIER_SPHERE_AREATRIGGER);
        if (!barrier)
            return;

        at_anduin_wrynn_befouled_barrier* barrierScript = dynamic_cast<at_anduin_wrynn_befouled_barrier*>(barrier->AI());
        if (!barrierScript)
            return;

        barrierScript->Absorb(absorbAmount);
    }

    void Register() override
    {
        OnEffectAbsorbHeal += AuraEffectAbsorbHealFn(spell_anduin_wrynn_befouled_barrier_absorb::OnHealAbsorb, EFFECT_0, SPELL_AURA_SCHOOL_HEAL_ABSORB);
    }
};

// Befouled Barrier Expire - 365173
class spell_anduin_wrynn_befouled_barrier_expire : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_befouled_barrier_expire);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            AreaTrigger* barrier = GetTarget()->GetAreaTrigger(SPELL_BEFOULED_BARRIER_SPHERE_AREATRIGGER);
            if (!barrier)
                return;

            at_anduin_wrynn_befouled_barrier* barrierScript = dynamic_cast<at_anduin_wrynn_befouled_barrier*>(barrier->AI());
            if (!barrierScript)
                return;

            target->CastSpell(target, SPELL_BEFOULED_BARRIER_EXPLODE, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_BASE_POINT1, barrierScript->GetRemainingAbsorb()));
        }

        if (Creature* creatureTarget = target->ToCreature())
            creatureTarget->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_befouled_barrier_expire::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);

    }
};

// Blasphemy - 361989
class spell_anduin_wrynn_blasphemy : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_blasphemy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLASPHEMY_OVERCONFIDENCE, SPELL_BLASPHEMY_HOPELESSNESS });
    }

    void OnPrecast() override
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_BLASPHEMY_PRE_HIT, true);
    }

    void HandleDebuff(SpellEffIndex /*effIndex*/)
    {
        uint32* spellId = Trinity::Containers::MapGetValuePtr(_spellAssignments, GetHitUnit()->GetGUID());
        if (!spellId)
            return;
        GetCaster()->CastSpell(GetHitUnit(), *spellId, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target) -> bool
            {
                if (!target->IsPlayer() || target->ToPlayer()->HasAura(SPELL_LOST_SOUL_GRACE))
                // We must also filter players who left the chamber earlier than the 40 second debuff
                return true;

        return false;
            });

        int8 hopelessnessAffected = std::floor(targets.size() / 2);
        int8 maxAffected = hopelessnessAffected * 2;
        Trinity::Containers::RandomResize(targets, maxAffected);

        for (WorldObject* target : targets)
        {
            if (hopelessnessAffected > 0)
            {
                _spellAssignments[target->GetGUID()] = SPELL_BLASPHEMY_HOPELESSNESS;
                hopelessnessAffected--;
            }
            else
                _spellAssignments[target->GetGUID()] = SPELL_BLASPHEMY_OVERCONFIDENCE;

            maxAffected--;
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_blasphemy::HandleDebuff, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_blasphemy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }

private:
    std::unordered_map<ObjectGuid /*player*/, uint32 /*spell*/> _spellAssignments;
};

// Blasphemy Initial - 364239
class spell_anduin_wrynn_blasphemy_init : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_blasphemy_init);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target) -> bool
            {
                if (!target->IsPlayer() || target->ToPlayer()->HasAura(SPELL_LOST_SOUL_GRACE) ||
                (!target->GetEntry() == NPC_SYLVANAS_WINDRUNNER ||
                    !target->GetEntry() == NPC_UTHER_THE_LIGHTBRINGER ||
                    !target->GetEntry() == NPC_LADY_JAINA_PROUDMOORE))
                    // We must also filter players who left the chamber earlier than the 40 second debuff
                    return true;

        return false;
            });

    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_blasphemy_init::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// Blasphemy ATs 361992 Overconfidence | 361993 Hopelessness
struct at_anduin_wrynn_blasphemy : AreaTriggerAI
{
    at_anduin_wrynn_blasphemy(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer() || unit->HasAura(SPELL_BLASPHEMY_PRE_HIT))
            return;

        if (!unit->IsAlive())
            at->Remove();

        if (unit->HasAura(at->GetSpellId()))
        {
            unit->CastSpell(unit, SPELL_BLASPHEMY_EXPLODE, true);
            unit->RemoveAurasDueToSpell(at->GetSpellId());
            if (Unit* target = at->GetTarget())
            {
                target->CastSpell(target, SPELL_BLASPHEMY_EXPLODE, true);
                target->RemoveAurasDueToSpell(at->GetSpellId());
            }
        }

        else if (at->GetSpellId() == SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER && unit->HasAura(SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER))
        {
            unit->RemoveAurasDueToSpell(SPELL_BLASPHEMY_OVERCONFIDENCE);
            unit->RemoveAurasDueToSpell(SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER);
            unit->CastSpell(unit, SPELL_BLASPHEMY_SUCCESS, true);
            if (Unit* target = at->GetTarget())
            {
                target->RemoveAurasDueToSpell(SPELL_BLASPHEMY_HOPELESSNESS);
                target->RemoveAurasDueToSpell(SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER);
                target->CastSpell(target, SPELL_BLASPHEMY_SUCCESS, true);
            }
        }

        else if (at->GetSpellId() == SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER && unit->HasAura(SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER))
        {
            unit->RemoveAurasDueToSpell(SPELL_BLASPHEMY_HOPELESSNESS);
            unit->RemoveAurasDueToSpell(SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER);
            unit->CastSpell(unit, SPELL_BLASPHEMY_SUCCESS, true);
            if (Unit* target = at->GetTarget())
            {
                target->RemoveAurasDueToSpell(SPELL_BLASPHEMY_OVERCONFIDENCE);
                target->RemoveAurasDueToSpell(SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER);
                target->CastSpell(target, SPELL_BLASPHEMY_SUCCESS, true);
            }
        }

        else
        {
            if (at->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID) // On Mythic players walking in with no debuff also trigger explosion
            {
                if (!unit->HasAura(SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER || SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER))
                {
                    if (Unit* target = at->GetTarget())
                    {
                        target->CastSpell(target, SPELL_BLASPHEMY_EXPLODE, true);
                    }
                }
            }
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsAlive() && unit->HasAura(at->GetSpellId()))
            unit->RemoveAurasDueToSpell(at->GetSpellId());

    }

private:
    InstanceScript* _instance;
};

// Blasphemy Expire - 361992, 361993
class spell_anduin_wrynn_hopelessness_overconfidence : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_hopelessness_overconfidence);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({
            SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER,
            SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER
            });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_BLASPHEMY_EXPLODE, true);
        }

    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_hopelessness_overconfidence::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// Wicked Star - 365030
class spell_anduin_wrynn_wicked_star : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo ({ SPELL_WICKED_STAR_POINTER });
    }

    PrepareAuraScript(spell_anduin_wrynn_wicked_star);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetCaster()->GetAI()->SelectTarget(SelectTargetMethod::Random, 0, 300.0f, true, false, -SPELL_WICKED_STAR_POINTER))
            GetCaster()->CastSpell(target, SPELL_WICKED_STAR_POINTER, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_wicked_star::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);

    }
};

// Wicked Star Pointer 365021
class spell_anduin_wrynn_wicked_star_pointer : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_WICKED_STAR_TARGETED });
    }

    PrepareAuraScript(spell_anduin_wrynn_wicked_star_pointer);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetCaster()->CastSpell(GetTarget(), SPELL_WICKED_STAR_TARGETED, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {

        Unit* caster = GetCaster();
        if (!caster)
            return;

        float angle = GetCaster()->GetAbsoluteAngle(GetTarget());
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN);

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            anduin->CastSpell(Position(
                GetCaster()->GetPositionX(),
                GetCaster()->GetPositionY(),
                GetCaster()->GetPositionZ(), angle),
                SPELL_WICKED_STAR_AREATRIGGER, true);
            
        }

    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_wicked_star_pointer::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_wicked_star_pointer::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);    
    }
};

// Wicked Star - 365017 - AT 24741
struct at_anduin_wrynn_wicked_star : AreaTriggerAI
{
    at_anduin_wrynn_wicked_star(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
        {
            _casterCurrentPosition = caster->GetPosition();
            
            // Note: max distance irrelevant since it will bounce the moment it reaches the boundary
            float wickedStarXOffSet = 100.0f;

            Position destPos = _casterCurrentPosition;
            
            at->MovePositionToFirstCollision(destPos, wickedStarXOffSet, 0.0f);

            PathGenerator firstPath(at);
            firstPath.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), false);

            G3D::Vector3 const& endPoint = firstPath.GetPath().back();

            at->InitSplines(firstPath.GetPath(), at->GetDistance(endPoint.x, endPoint.y, endPoint.z) * 26.67f);
        }
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (std::find(_affectedUnits.begin(), _affectedUnits.end(), unit->GetGUID()) == _affectedUnits.end())
            {
                excludeUnit = false;
                if (unit->GetEntry() == NPC_SYLVANAS_WINDRUNNER || unit->GetEntry() == NPC_UTHER_THE_LIGHTBRINGER ||
                    unit->GetEntry() == NPC_LADY_JAINA_PROUDMOORE || unit->GetEntry() == BOSS_ANDUIN_WRYNN)
                {
                    excludeUnit = true;
                }

                if (!excludeUnit && caster->IsValidAttackTarget(unit))
                    caster->CastSpell(unit, SPELL_WICKED_STAR_DAMAGE_SILENCE, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)));
                if (!excludeUnit && caster->IsValidAssistTarget(unit))
                    caster->CastSpell(unit, SPELL_WICKED_STAR_EMPOWERMENT, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)));

                _affectedUnits.push_back(unit->GetGUID());
            }
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        if (Unit* caster = at->GetCaster())
        {
            if (std::find(_affectedUnits.begin(), _affectedUnits.end(), unit->GetGUID()) == _affectedUnits.end())
            {
                excludeUnit = false;

                if (unit->GetEntry() == NPC_SYLVANAS_WINDRUNNER || unit->GetEntry() == NPC_UTHER_THE_LIGHTBRINGER ||
                    unit->GetEntry() == NPC_LADY_JAINA_PROUDMOORE || unit->GetEntry() == BOSS_ANDUIN_WRYNN)
                {
                    excludeUnit = true;
                }

                if (!excludeUnit && caster->IsValidAttackTarget(unit))
                    caster->CastSpell(unit, SPELL_WICKED_STAR_DAMAGE_SILENCE, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)));
                if (!excludeUnit && caster->IsValidAssistTarget(unit))
                    caster->CastSpell(unit, SPELL_WICKED_STAR_EMPOWERMENT, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)));

                _affectedUnits.push_back(unit->GetGUID());
            }
        }
    }

    void OnDestinationReached() override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (at->GetDistance(_casterCurrentPosition) > 0.05f)
        {
            _affectedUnits.clear();

            ReturnToCaster();
        }
        else
            at->Remove();
    }

    void ReturnToCaster()
    {
        _scheduler.Schedule(0ms, [this](TaskContext task)
            {
                if (Unit* caster = at->GetCaster())
                {
                    _randomPosition = caster->GetFirstCollisionPosition(900.0f, caster->GetAbsoluteAngle(_randomPosition));
                    Position nextTrajectory = _randomPosition;
                    Movement::PointsArray returnSplinePoints;

                    returnSplinePoints.push_back(PositionToVector3(at));
                    returnSplinePoints.push_back(PositionToVector3(at));
                    returnSplinePoints.push_back(PositionToVector3(_randomPosition));
                    returnSplinePoints.push_back(PositionToVector3(_randomPosition));

                    at->InitSplines(returnSplinePoints, at->GetDistance(_randomPosition) / 14 * 600);
                }
            });

        _scheduler.Schedule(8400ms, [this](TaskContext task)
            {
                if (Unit* caster = at->GetCaster())
                {
                    ReturnToCaster();
                }
            });
    }

    void NextTrajectory()
    {

    }

private:
    TaskScheduler _scheduler;
    Position _casterCurrentPosition;
    Position _randomPosition;
    Position _targetCurrentPosition;
    std::vector<ObjectGuid> _affectedUnits;
    bool excludeUnit;
};

// Empowered Wicked Star - 367631
class spell_anduin_wrynn_empowered_wicked_star : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_EMPOWERED_WICKED_STAR_POINTER });
    }

    PrepareAuraScript(spell_anduin_wrynn_empowered_wicked_star);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* target = GetCaster()->GetAI()->SelectTarget(SelectTargetMethod::Random, 0, 300.0f, true, false, -SPELL_EMPOWERED_WICKED_STAR_POINTER))
            GetCaster()->CastSpell(target, SPELL_EMPOWERED_WICKED_STAR_POINTER, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_empowered_wicked_star::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);

    }
};

// Empowered Wicked Star Pointer - 367632
class spell_anduin_wrynn_empowered_wicked_star_pointer : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_WICKED_STAR_TARGETED });
    }

    PrepareAuraScript(spell_anduin_wrynn_empowered_wicked_star_pointer);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetCaster()->CastSpell(GetTarget(), SPELL_WICKED_STAR_TARGETED, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {

        Unit* caster = GetCaster();
        if (!caster)
            return;

        float angle = GetCaster()->GetAbsoluteAngle(GetTarget());
        InstanceScript* instance = GetTarget()->GetInstanceScript();
        Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN);

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            anduin->CastSpell(Position(
                GetCaster()->GetPositionX(),
                GetCaster()->GetPositionY(),
                GetCaster()->GetPositionZ(), angle),
                SPELL_EMPOWERED_WICKED_STAR_AREATRIGGER, true);

        }

    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_empowered_wicked_star_pointer::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_empowered_wicked_star_pointer::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

//// Empowered Wicked Star 367621  AT - 24599
//struct at_anduin_wrynn_wicked_star : AreaTriggerAI
//{
//    at_anduin_wrynn_wicked_star(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}
//
//    void OnInitialize() override
//    {
//        if (Unit* caster = at->GetCaster())
//        {
//            _casterCurrentPosition = caster->GetPosition();
//            _randomPosition = caster->GetRandomPoint(DominationGraspCenter, frand(20.0f, 30.0f));
//
//            // Note: max distance irrelevant since it will bounce the moment it reaches the boundary
//            float wickedStarXOffSet = 100.0f;
//
//            Position destPos = _casterCurrentPosition;
//            Position randomPos = _randomPosition;
//            at->MovePositionToFirstCollision(destPos, wickedStarXOffSet, 0.0f);
//
//            PathGenerator firstPath(at);
//            firstPath.CalculatePath(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ(), false);
//
//            G3D::Vector3 const& endPoint = firstPath.GetPath().back();
//
//            at->InitSplines(firstPath.GetPath(), at->GetDistance(endPoint.x, endPoint.y, endPoint.z) * 14.67f);
//        }
//    }
//
//    void OnUpdate(uint32 diff) override
//    {
//        _scheduler.Update(diff);
//    }
//
//    void OnUnitEnter(Unit* unit) override
//    {
//        if (Unit* caster = at->GetCaster())
//        {
//            if (std::find(_affectedUnits.begin(), _affectedUnits.end(), unit->GetGUID()) == _affectedUnits.end())
//            {
//                excludeUnit = false;
//                if (unit->GetEntry() == NPC_SYLVANAS_WINDRUNNER || unit->GetEntry() == NPC_UTHER_THE_LIGHTBRINGER ||
//                    unit->GetEntry() == NPC_LADY_JAINA_PROUDMOORE || unit->GetEntry() == BOSS_ANDUIN_WRYNN)
//                {
//                    excludeUnit = true;
//                }
//
//                if (!excludeUnit && caster->IsValidAttackTarget(unit))
//                    caster->CastSpell(unit, SPELL_EMPOWERED_WICKED_STAR_DAMAGE_SILENCE, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)));
//
//                _affectedUnits.push_back(unit->GetGUID());
//            }
//        }
//    }
//
//    void OnUnitExit(Unit* unit) override
//    {
//        if (Unit* caster = at->GetCaster())
//        {
//            if (std::find(_affectedUnits.begin(), _affectedUnits.end(), unit->GetGUID()) == _affectedUnits.end())
//            {
//                excludeUnit = false;
//
//                if (unit->GetEntry() == NPC_SYLVANAS_WINDRUNNER || unit->GetEntry() == NPC_UTHER_THE_LIGHTBRINGER ||
//                    unit->GetEntry() == NPC_LADY_JAINA_PROUDMOORE || unit->GetEntry() == BOSS_ANDUIN_WRYNN)
//                {
//                    excludeUnit = true;
//                }
//
//                if (!excludeUnit && caster->IsValidAttackTarget(unit))
//                    caster->CastSpell(unit, SPELL_EMPOWERED_WICKED_STAR_DAMAGE_SILENCE, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)));
//
//                _affectedUnits.push_back(unit->GetGUID());
//            }
//        }
//    }
//
//    void OnDestinationReached() override
//    {
//        Unit* caster = at->GetCaster();
//        if (!caster)
//            return;
//
//        if (at->GetDistance(_casterCurrentPosition) > 0.05f)
//        {
//            _affectedUnits.clear();
//
//            ReturnToCaster();
//        }
//        else
//            at->Remove();
//    }
//
//    void ReturnToCaster()
//    {
//        _scheduler.Schedule(0ms, [this](TaskContext task)
//            {
//                if (Unit* caster = at->GetCaster())
//                {
//
//                    Movement::PointsArray returnSplinePoints;
//
//                    returnSplinePoints.push_back(PositionToVector3(at));
//                    returnSplinePoints.push_back(PositionToVector3(at));
//                    returnSplinePoints.push_back(PositionToVector3(_randomPosition));
//                    returnSplinePoints.push_back(PositionToVector3(_randomPosition));
//
//                    at->InitSplines(returnSplinePoints, at->GetDistance(_randomPosition) / 24 * 600);
//
//                    task.Repeat(250ms);
//                }
//            });
//    }
//
//private:
//    TaskScheduler _scheduler;
//    Position _casterCurrentPosition;
//    Position _randomPosition;
//    Position _targetCurrentPosition;
//    std::vector<ObjectGuid> _affectedUnits;
//    bool excludeUnit;
//};

// Kingsmourne Hungers - 362405
class spell_anduin_wrynn_kingsmourne_hungers : public SpellScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({
            SPELL_KINGSMOURNE_HUNGERS_DAMAGE,
            SPELL_LOST_SOUL_DIMENSION,
            SPELL_SEVERED_SOUL });
    }

    PrepareSpellScript(spell_anduin_wrynn_kingsmourne_hungers);

    // Prevent swinging empty-handed when casts overlap
    void OnPreCast() 
    {
        GetCaster()->PlayOneShotAnimKitId(ANIM_SHEATHE);
    }

    void HandleDummyEffect(SpellEffIndex effIndex)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_KINGSMOURNE_HUNGERS_DAMAGE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_LOST_SOUL_DIMENSION, true);
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_LOST_SOUL, true);

        if (GetCaster()->GetMapId() == DIFFICULTY_MYTHIC_RAID)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_SEVERED_SOUL, true);
        }
    }

    void OnCast()
    {
        GetCaster()->GetAI()->DoAction(ACTION_SUMMON_SOULS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_kingsmourne_hungers::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_anduin_wrynn_kingsmourne_hungers::OnCast);
    }
};

// Lost Soul Dimension - 362055
class spell_anduin_wrynn_lost_soul : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_LOST_SOUL_GRACE });
    }

    PrepareAuraScript(spell_anduin_wrynn_lost_soul);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        lostSoulPosition = GetTarget()->GetPosition();
        GetTarget()->CastSpell(GetTarget(), SPELL_LOST_SOUL_GRACE, true);   

    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        switch (GetTargetApplication()->GetRemoveMode())
        {
        case AURA_REMOVE_BY_ENEMY_SPELL:
        {
            if (GetTarget()->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
            {
                GetTarget()->NearTeleportTo(lostSoulPosition, false);
            }

            break;
        }
        case AURA_REMOVE_BY_EXPIRE:
        {
            if (GetTarget()->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                // On Mythic on aura expiry, player is slain
            {               
                GetTarget()->KillSelf();                
            }

            GetTarget()->CastSpell(GetTarget(), SPELL_SCARRED_SOUL, true);
            break;
        }
        case AURA_REMOVE_BY_DEATH:
            GetTarget()->NearTeleportTo(lostSoulPosition, true);
            if (GetTarget()->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
                // On Mythic on aura expiry, player is slain
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_SCARRED_SOUL, true);
            }
            
            break;
        default:
            return;
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_lost_soul::OnApply, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_lost_soul::OnRemove, EFFECT_1, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
    }

private:
    ObjectGuid _playerGUID;
    Position lostSoulPosition;
};

// Anduin Soul AT - 24744
struct at_anduin_wrynn_anduin_soul : AreaTriggerAI
{
    at_anduin_wrynn_anduin_soul(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnInitialize() override
    {
        if (!_instance)
            return;

    }

    void OnUnitEnter(Unit* unit) override
    {
        
    }

private:
    InstanceScript* _instance;
};

// Rain of Despair - 362391
class spell_anduin_despair_rain_of_despair : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({
            SPELL_RAIN_OF_DESPAIR_EXPLOSION,
            SPELL_RAIN_OF_DESPAIR_MELEE,
            SPELL_RAIN_OF_DESPAIR_RANGED });
    }

    PrepareAuraScript(spell_anduin_despair_rain_of_despair);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        std::list<Player*> targetList;
        GetPlayerListInGrid(targetList, GetTarget(), 300.0f);
        for (Player* target : targetList)
            GetTarget()->CastSpell(target, GetEffectInfo(EFFECT_0).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anduin_despair_rain_of_despair::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        
    }
};

// Rain of Despair Ranged - 362396
class spell_anduin_despair_rain_of_despair_ranged : public SpellScript
{
    PrepareSpellScript(spell_anduin_despair_rain_of_despair_ranged);

    void SetDest(SpellDestination& dest)
    {

        if (InstanceScript* _instance = GetCaster()->GetInstanceScript())
        {
            Map::PlayerList const& PlayerList = _instance->instance->GetPlayers();
            std::list<Player*> rangedTarget;
            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    Player* _player = i->GetSource();
                    if (_player && _player->IsAlive())
                    {
                        if (_player->GetDistance(GetCaster()) > 12.0f)
                        {
                            rangedTarget.push_back(_player);
                        }
                        // Choose any target if less than 3 are far away
                        
                        else if (rangedTarget.size() < 3)
                        {
                            rangedTarget.push_back(_player);
                        }
                    }
                }
            }

            // Something is wrong and always the same target is selected TODO
            for (uint8 i = 0; i < 3; i++)
            {
                for (std::list<Player*>::iterator it = rangedTarget.begin(); it != rangedTarget.end(); ++it)
                {
                    Position pos = (*it)->GetPosition();
                    dest.Relocate(pos);
                }
            }            
        }
    }

    void Register() override
    {        
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_anduin_despair_rain_of_despair_ranged::SetDest, EFFECT_0, TARGET_DEST_DEST_RANDOM);
    }
};

// Rain of Despair Melee - 362393
class spell_anduin_despair_rain_of_despair_melee : public SpellScript
{
    PrepareSpellScript(spell_anduin_despair_rain_of_despair_melee);

    void SetDest(SpellDestination& dest)
    {

        if (InstanceScript* _instance = GetCaster()->GetInstanceScript())
        {
            Map::PlayerList const& PlayerList = _instance->instance->GetPlayers();
            std::list<Player*> meleeTarget;
            if (!PlayerList.isEmpty())
            {
                for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                {
                    Player* _player = i->GetSource();
                    if (_player && _player->IsAlive())
                    {
                        if (_player->GetDistance(GetCaster()) < 8.0f)
                        {
                            meleeTarget.push_back(_player);
                        }
                        // Choose any target if less than 3 are far away

                        else if (meleeTarget.size() < 3)
                        {
                            meleeTarget.push_back(_player);
                        }
                    }
                }
            }

            // Something is wrong and always the same target is selected TODO
            for (uint8 i = 0; i < 3; i++)
            {
                for (std::list<Player*>::iterator it = meleeTarget.begin(); it != meleeTarget.end(); ++it)
                {
                    Position pos = (*it)->GetPosition();
                    dest.Relocate(pos);
                }
            }
        }
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_anduin_despair_rain_of_despair_melee::SetDest, EFFECT_0, TARGET_DEST_DEST_RANDOM);
    }
};

// Force of Will - 368913
class spell_anduin_wrynn_force_of_will : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_force_of_will);

    void RecalculateHook(AuraEffect const* /*aurEffect*/, int32& amount, bool& canBeRecalculated)
    {
        amount = int32(GetCaster()->GetPower(POWER_ENERGY));
        canBeRecalculated = false;
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        GetCaster()->SetPower(POWER_ENERGY, 0);

        if (Aura* willPower = GetTarget()->GetAura(SPELL_FORCE_OF_WILL))
            willPower->RecalculateAmountOfEffects();

    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_force_of_will::RecalculateHook, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_force_of_will::RecalculateHook, EFFECT_1, SPELL_AURA_MOD_SUMMON_DAMAGE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_force_of_will::RecalculateHook, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_force_of_will::RecalculateHook, EFFECT_4, SPELL_EFFECT_DUMMY);
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_force_of_will::OnApply, EFFECT_0, SPELL_EFFECT_DUMMY, AURA_EFFECT_HANDLE_REAL);

    }
};

// March of the Damned - 363233 
class spell_anduin_wrynn_march_of_the_damned : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_march_of_the_damned);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Don't summon wall on aura granted
        if (aurEff->GetTickNumber() == 1)
            return;

        std::vector<Position> _marchOfTheDamned(std::begin(MarchOfTheDamned), std::end(MarchOfTheDamned));

            if (_marchOfTheDamned.empty())
                return;

            size_t randomIndex = rand() % _marchOfTheDamned.size();
            Position chosenPosition = _marchOfTheDamned[randomIndex];
            _marchOfTheDamned.erase(_marchOfTheDamned.begin() + randomIndex);

            GetCaster()->SummonCreature(NPC_MARCH_OF_THE_DAMNED, chosenPosition, TEMPSUMMON_TIMED_DESPAWN, 20s);
    }   

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anduin_wrynn_march_of_the_damned::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

};

// Remnant Aura - 362500 
class spell_remnant_of_a_fallen_king_spawn : public AuraScript
{

    PrepareAuraScript(spell_remnant_of_a_fallen_king_spawn);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        InstanceScript* instance = GetTarget()->GetInstanceScript();

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            GetTarget()->SetObjectScale(5.0f);
            GetTarget()->GetAI()->DoAction(ACTION_ACTIVATE_REMNANT);
            GetTarget()->CastSpell(GetTarget(), SPELL_REMNANT_TIMER);
            
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_remnant_of_a_fallen_king_spawn::OnRemove, EFFECT_2, SPELL_AURA_TRIGGER_SPELL_ON_EXPIRE, AURA_EFFECT_HANDLE_REAL);
    }
};

// Dark Presence - 368986
class spell_anduin_wrynn_dark_presence : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_dark_presence);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        for (std::list<WorldObject*>::iterator itr = unitList.begin(); itr != unitList.end();)
        {
            if ((*itr)->GetEntry() == NPC_GRIM_REFLECTION)
                ++itr;
            else
                unitList.erase(itr++);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_dark_presence::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_dark_presence::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_dark_presence::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// Severed Soul - 367769
class spell_anduin_wrynn_severed_soul : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_severed_soul);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Position soulPosition = GetCaster()->GetPosition();

    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        switch (GetTargetApplication()->GetRemoveMode())
        {
        case AURA_REMOVE_BY_DEATH:
        case AURA_REMOVE_BY_CANCEL:
        case AURA_REMOVE_BY_DEFAULT:
        case AURA_REMOVE_BY_ENEMY_SPELL:
        {

            GetCaster()->CastSpell(GetCaster(), SPELL_CANCEL_LOST_SOUL, true);

            if (TempSummon* summon = GetTarget()->ToTempSummon())
            {
                if (summon->GetSummonerUnit() == GetCaster())
                {
                    
                    GetCaster()->NearTeleportTo(Position(soulPosition), false);
                };
                    
            }
        }
        break;
        default:
            return;
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_severed_soul::OnApply, EFFECT_0, SPELL_AURA_LINKED_SUMMON, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_severed_soul::OnRemove, EFFECT_1, SPELL_AURA_TRIGGER_SPELL_ON_EXPIRE, AURA_EFFECT_HANDLE_REAL);
    }

private:
    Position soulPosition;

};

// Lost Soul Mirror Image - 362402 
class spell_anduin_wrynn_lost_soul_mirror_image : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_lost_soul_mirror_image);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        ObjectGuid casterGuid = GetCaster()->GetGUID();

        targets.remove_if([casterGuid](WorldObject* target) -> bool
            {
                if (TempSummon* summon = target->ToUnit()->ToTempSummon())
                {
                    if (target->ToUnit()->ToTempSummon()->GetSummonerGUID() == casterGuid)
                        return false;
                }
        return true;
            });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_lost_soul_mirror_image::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_lost_soul_mirror_image::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_lost_soul_mirror_image::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_lost_soul_mirror_image::FilterTargets, EFFECT_3, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};


// Return to Kingsmourne - 363021
class spell_remnant_of_a_fallen_king_return_to_kingsmourne : public AuraScript
{
    PrepareAuraScript(spell_remnant_of_a_fallen_king_return_to_kingsmourne);

    void OnPrecast()
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;
        Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN);
        GetCaster()->CastSpell(anduin, SPELL_RETURN_TO_KINGSMOURNE, false);
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;
        Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN);
        GetCaster()->CastSpell(anduin, SPELL_RETURN_TO_KINGSMOURNE, true);
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
        {
            if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
            {
                if (arthas->IsAIEnabled())
                    arthas->DespawnOrUnsummon();
            }

            if (Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN))
            {
                if (anduin->IsAIEnabled())
                {
                    anduin->RemoveAurasDueToSpell(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
                    anduin->AI()->DoAction(ACTION_EXIT_INTERMISSION);
                    anduin->AI()->DoCastSelf(SPELL_CANCEL_FORCE_OF_WILL);
                    instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_INTERMISSION, 0);
                    instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 1);
                }
            }
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_remnant_of_a_fallen_king_return_to_kingsmourne::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_remnant_of_a_fallen_king_return_to_kingsmourne::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// Return to Kingsmourne - 363022

//// Return to Kingsmourne Visuals - 363023
//class spell_remnant_of_a_fallen_kings_despawn : public SpellScript
//{
//    PrepareSpellScript(spell_remnant_of_a_fallen_kings_despawn);
//
//    void SetTarget(WorldObject*& target)
//    {
//        target = GetCaster();
//    }
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        targets.remove_if([](WorldObject* target) -> bool
//            {
//                if ((target->GetEntry() == BOSS_ANDUIN_WRYNN))
//                    // We must also filter players who left the chamber earlier than the 40 second debuff
//                    return false;
//
//        return true;
//            });
//
//    }
//
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_remnant_of_a_fallen_kings_despawn::FilterTargets, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
//        //OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_throw_lance_trigger_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
//    }
//private:
//    InstanceScript* _instance;
//};

// Grim Reflections - 365120
class spell_anduin_wrynn_grim_reflections : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_grim_reflections);

    void HandleCast()
    {
        uint8 reflectionsNumber = GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID ? 4 : 3;
        std::vector<Position> grimReflections(std::begin(GrimReflections), std::end(GrimReflections));
        Trinity::Containers::RandomResize(grimReflections, reflectionsNumber);
        for (uint8 i = 0; i < reflectionsNumber; i++)
        {
            GetCaster()->CastSpell(Position(grimReflections[i]), SPELL_GRIM_REFLECTIONS_SUMMON, true);
        }
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_anduin_wrynn_grim_reflections::HandleCast);
    }
};

// Grim Fate - 367932
class spell_anduin_wrynn_grim_fate : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_grim_fate);

    void FilterTargets(std::list<WorldObject*>& unitList)
    {
        for (std::list<WorldObject*>::iterator itr = unitList.begin(); itr != unitList.end();)
        {
            if ((*itr)->GetEntry() == NPC_GRIM_REFLECTION)
                ++itr;
            else
                unitList.erase(itr++);
        }
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_grim_fate::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_grim_fate::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
    }
};

// Beacon of Hope 365872
class spell_anduin_wrynn_beacon_of_hope : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_beacon_of_hope);

    void OnCast()
    {
        GetCaster()->SummonCreature(NPC_BEACON_OF_HOPE, BeaconOfHope, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_anduin_wrynn_beacon_of_hope::OnCast);
    }
};

// Beacon of Hope - AT 24247 
struct at_anduin_wrynn_beacon_of_hope : AreaTriggerAI
{
    at_anduin_wrynn_beacon_of_hope(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer() || !unit->HasAura(SPELL_HOPELESSNESS_HOPELESSNESS_AREATRIGGER))
            return;

        if (Creature* beacon = _instance->GetCreature(DATA_BEACON_OF_HOPE))
        {
            beacon->CastSpell(beacon, SPELL_PURGING_LIGHT, true);
            unit->RemoveAurasDueToSpell(SPELL_HOPELESSNESS_HOPELESSNESS_AREATRIGGER);

        }

        if (at->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
        {
            // Shoot fragment of Hope NYI
        }
       
    }

private:
    InstanceScript* _instance;
};

// Hopelessness - 365958
class spell_anduin_wrynn_hopelessness : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_hopelessness);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HOPELESSNESS_MISSILE });
    }

    void OnPrecast() override
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_BLASPHEMY_PRE_HIT, true);
    }

    void HandleDebuff(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HOPELESSNESS_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_hopelessness::HandleDebuff, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Hopelessness 365966 - AT 24443
struct at_anduin_wrynn_hopelessness : AreaTriggerAI
{
    at_anduin_wrynn_hopelessness(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer() || unit->HasAura(SPELL_BLASPHEMY_PRE_HIT))
            return;

        if (!unit->IsAlive())
            at->Remove();

        if (unit->HasAura(at->GetSpellId()))
        {
            unit->CastSpell(unit, SPELL_BLASPHEMY_EXPLODE, true);
            if (Unit* target = at->GetTarget())
            {
                target->CastSpell(target, SPELL_BLASPHEMY_EXPLODE, true);
            }
        }

    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsAlive() && unit->HasAura(at->GetSpellId()))
            unit->RemoveAurasDueToSpell(at->GetSpellId());
    }

private:
    InstanceScript* _instance;
};

// Hopelessness Expire - 365966
class spell_anduin_wrynn_hopelessness_expire : public AuraScript
{
    PrepareAuraScript(spell_anduin_wrynn_hopelessness_expire);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_HOPELESSNESS_HOPELESSNESS_AREATRIGGER });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        switch (GetTargetApplication()->GetRemoveMode())
        {
        case AURA_REMOVE_BY_ENEMY_SPELL:
        case AURA_REMOVE_BY_EXPIRE:
        case AURA_REMOVE_BY_DEATH:
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_HOPELESSNESS_EXPLODE, true);
        }
            break;
        default:
            return;
        }        
    }    

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_hopelessness_expire::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// Empowered Hopebreaker - 365805
class spell_anduin_wrynn_empowered_hopebreaker : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_empowered_hopebreaker);

    void OnPrecast() override
    {
        GetCaster()->m_Events.AddEvent(new StandStill(GetCaster(), true), GetCaster()->m_Events.CalculateTime(1ms));
    }

    void HandleAfterCast()
    {
        GetCaster()->m_Events.AddEvent(new StandStill(GetCaster(), false), GetCaster()->m_Events.CalculateTime(3100ms));
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_anduin_wrynn_empowered_hopebreaker::HandleAfterCast);
    }
};

// Empowered Hopebreaker Periodic - 365806
class spell_anduin_wrynn_empowered_hopebreaker_periodic : public SpellScript
{
    PrepareSpellScript(spell_anduin_wrynn_empowered_hopebreaker_periodic);

    void HandleCast(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HOPEBREAKER_DAMAGE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HOPEBREAKER_DEBUFF, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_empowered_hopebreaker_periodic::HandleCast, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Remnant Timer Runic Power - 365291 
class spell_remnant_of_a_fallen_king_energize_runic_power : public AuraScript
{
    PrepareAuraScript(spell_remnant_of_a_fallen_king_energize_runic_power);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        powerGained = _anduinRegenCycle[powerRegenCycle++];

        if (powerRegenCycle >= 3)
            powerRegenCycle = 0;

        target->ModifyPower(target->GetPowerType(), powerGained);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_remnant_of_a_fallen_king_energize_runic_power::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

private:
    uint8 powerRegenCycle = 0;
    uint32 powerGained = 0;
    static constexpr std::array<int32, 22> _anduinRegenCycle =
    { 1, 2, 2 }; // 1.66 runic power per second on Retail

};

// Army of the Dead - 362862
class spell_remnant_of_a_fallen_king_army_of_the_dead : public SpellScript
{
    PrepareSpellScript(spell_remnant_of_a_fallen_king_army_of_the_dead);

    void OnPrecast() override
    {
        GetCaster()->m_Events.AddEvent(new StandStill(GetCaster(), true), GetCaster()->m_Events.CalculateTime(1ms));
    }

    void HandleAfterCast()
    {
        GetCaster()->m_Events.AddEvent(new StandStill(GetCaster(), false), GetCaster()->m_Events.CalculateTime(4100ms));

        Position summonSoul = GetCaster()->GetNearPosition(frand(30.0f, 50.0f), frand(0.0f, 3.5f));

        if (GetCaster()->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC_RAID)
            GetCaster()->CastSpell(Position(summonSoul), SPELL_ECHOES_OF_ANDORHAL_MONSTROUS_SOUL, true);

    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_remnant_of_a_fallen_king_army_of_the_dead::HandleAfterCast);
    }
};

// Echoes of Andorhal - 362863 
class spell_remnant_of_a_fallen_king_echoes_of_andorhal : public SpellScript
{
    PrepareSpellScript(spell_remnant_of_a_fallen_king_echoes_of_andorhal);

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Position const echoesSummon = GetCaster()->GetRandomPoint(DominationGraspCenter, frand(20.5f, 30.0f));
        dest.Relocate(echoesSummon);
    }



    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_remnant_of_a_fallen_king_echoes_of_andorhal::SetDest, EFFECT_0, TARGET_DEST_DEST_RANDOM);

    }
};

// Remorseless Winter Periodic - 362543
class spell_remnant_of_a_fallen_king_remorseless_winter_periodic : public AuraScript
{
    PrepareAuraScript(spell_remnant_of_a_fallen_king_remorseless_winter_periodic);
    
    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        GetCaster()->CastSpell(GetTarget(), SPELL_REMORSELESS_WINTER_DEBUFF_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_remnant_of_a_fallen_king_remorseless_winter_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// Remorseless Winter Damage - 362545
class spell_remnant_of_a_fallen_king_remorseless_winter_damage : public SpellScript
{
    PrepareSpellScript(spell_remnant_of_a_fallen_king_remorseless_winter_damage);

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (!caster)
            return;

        Aura* remorselessWinter = target->GetAura(SPELL_REMORSELESS_WINTER_PERIODIC);
        uint8 remorselessWinterStacks = remorselessWinter->GetStackAmount();
        SetHitDamage(int32(GetHitDamage() * (uint8)remorselessWinterStacks));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_remnant_of_a_fallen_king_remorseless_winter_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// Soul Reaper - 362771
class spell_remnant_of_a_fallen_king_soul_reaper : public SpellScript
{
    PrepareSpellScript(spell_remnant_of_a_fallen_king_soul_reaper);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo
        ({
            SPELL_SOUL_REAPER_PHYSICAL_DAMAGE,
            SPELL_SOUL_REAPER_SHADOWFROST_DAMAGE,
            SPELL_SOUL_REAPER_DEBUFF,
            SPELL_SOUL_REAPER_ATTACK_SPEED,
            });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SOUL_REAPER_PHYSICAL_DAMAGE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SOUL_REAPER_SHADOWFROST_DAMAGE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SOUL_REAPER_DEBUFF, true);
        GetCaster()->CastSpell(GetCaster(), SPELL_SOUL_REAPER_ATTACK_SPEED, true);
        GetCaster()->resetAttackTimer(BASE_ATTACK);

    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_remnant_of_a_fallen_king_soul_reaper::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Anduin Wrynn Introduction 26 Custom AT
struct at_anduin_wrynn_introduction : AreaTriggerAI
{
    at_anduin_wrynn_introduction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!_instance || _instance->GetData(DATA_ANDUIN_WRYNN_INTRODUCTION) != NOT_STARTED || !unit->IsPlayer())
            return;

        if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_WRYNN))
        {
            anduin->GetAI()->DoAction(ACTION_START_INTRODUCTION);

        }

    }

public:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 17835 - Anduin Introduction
class conversation_anduin_introduction : public ConversationScript
{
public:
    conversation_anduin_introduction() : ConversationScript("conversation_anduin_introduction") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        if (Creature* uther = creator->GetInstanceScript()->GetCreature(DATA_UTHER_THE_LIGHTBRINGER))
            conversation->AddActor(NPC_UTHER_THE_LIGHTBRINGER, 1, uther->GetGUID());
        if (Creature* sylvanas = creator->GetInstanceScript()->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            conversation->AddActor(NPC_SYLVANAS_WINDRUNNER, 2, sylvanas->GetGUID());
        if (Creature* jaina = creator->GetInstanceScript()->GetCreature(DATA_JAINA_PROUDMOORE))
            conversation->AddActor(NPC_LADY_JAINA_PROUDMOORE, 3, jaina->GetGUID());
    }

};

// 17921 - Arthas to Uther Intermission
class conversation_arthas_uther : public ConversationScript
{
public:
    conversation_arthas_uther() : ConversationScript("conversation_arthas_uther") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        if (Creature* uther = creator->GetInstanceScript()->GetCreature(DATA_UTHER_THE_LIGHTBRINGER))
            conversation->AddActor(NPC_UTHER_THE_LIGHTBRINGER, 1, uther->GetGUID());
    }
};

// 17923 - Arthas to Sylvanas Intermission
class conversation_arthas_sylvanas : public ConversationScript
{
public:
    conversation_arthas_sylvanas() : ConversationScript("conversation_arthas_sylvanas") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {
        if (Creature* sylvanas = creator->GetInstanceScript()->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            conversation->AddActor(NPC_SYLVANAS_WINDRUNNER, 1, sylvanas->GetGUID());
    }
};

// 17836 - Anduin Outroduction
class conversation_anduin_outroduction : public ConversationScript
{
public:
    conversation_anduin_outroduction() : ConversationScript("conversation_anduin_outroduction") { }

    void OnConversationCreate(Conversation* conversation, Unit* creator) override
    {

        if (Creature* jaina = creator->GetInstanceScript()->GetCreature(DATA_JAINA_PROUDMOORE))
            conversation->AddActor(NPC_LADY_JAINA_PROUDMOORE, 1, jaina->GetGUID());
        if (Creature* sylvanas = creator->GetInstanceScript()->GetCreature(DATA_SYLVANAS_WINDRUNNER))
            conversation->AddActor(NPC_SYLVANAS_WINDRUNNER, 2, sylvanas->GetGUID());
        if (Creature* uther = creator->GetInstanceScript()->GetCreature(DATA_UTHER_THE_LIGHTBRINGER))
            conversation->AddActor(NPC_UTHER_THE_LIGHTBRINGER, 3, uther->GetGUID());
        if (Creature* firim = creator->GetInstanceScript()->GetCreature(DATA_FIRIM))
            conversation->AddActor(NPC_FIRIM, 4, firim->GetGUID());

    }

};


void AddSC_boss_anduin_wrynn()
{
    RegisterSepulcherOfTheFirstOnesCreatureAI(boss_anduin_wrynn);
    RegisterSepulcherOfTheFirstOnesCreatureAI(boss_remnant_of_a_fallen_king);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_sylvanas);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_jaina);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_uther);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_befouled_barrier);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_empty_vessel);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_lost_soul);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_anduin_soul);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_anduin_despair);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_anduin_doubt);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_anduin_hope);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_monstrous_soul);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_fiendish_soul);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_grim_reflection);

    RegisterSpellScript(spell_anduin_wrynn_energize_willpower_lfr);
    RegisterSpellScript(spell_anduin_wrynn_dark_zeal);

    RegisterSpellScript(spell_anduin_wrynn_hopebreaker);
    RegisterSpellScript(spell_anduin_wrynn_hopebreaker_periodic);
    RegisterSpellScript(spell_anduin_wrynn_hopebreaker_damage);

    RegisterAreaTriggerAI(at_anduin_wrynn_befouled_barrier);
    RegisterSpellScript(spell_anduin_wrynn_befouled_barrier_absorb);
    RegisterSpellScript(spell_anduin_wrynn_befouled_barrier_expire);

    RegisterAreaTriggerAI(at_anduin_wrynn_blasphemy);
    RegisterSpellScript(spell_anduin_wrynn_blasphemy);
    RegisterSpellScript(spell_anduin_wrynn_hopelessness_overconfidence);

    RegisterAreaTriggerAI(at_anduin_wrynn_wicked_star);
    RegisterSpellScript(spell_anduin_wrynn_wicked_star);
    RegisterSpellScript(spell_anduin_wrynn_wicked_star_pointer);

    RegisterSpellScript(spell_anduin_wrynn_kingsmourne_hungers);
    RegisterSpellScript(spell_anduin_wrynn_lost_soul);
    RegisterSpellScript(spell_anduin_wrynn_lost_soul_mirror_image);
    RegisterSpellScript(spell_anduin_wrynn_severed_soul);

    RegisterAreaTriggerAI(at_anduin_wrynn_anduin_soul);
    RegisterSpellScript(spell_anduin_despair_rain_of_despair);
    RegisterSpellScript(spell_anduin_despair_rain_of_despair_ranged);
    RegisterSpellScript(spell_anduin_despair_rain_of_despair_melee);

    RegisterSpellScript(spell_anduin_wrynn_force_of_will);

    RegisterAreaTriggerAI(at_anduin_wrynn_march_of_the_damned);
    RegisterSpellScript(spell_anduin_wrynn_march_of_the_damned);
    RegisterSpellScript(spell_anduin_wrynn_dark_presence);
    RegisterSpellScript(spell_anduin_wrynn_grim_reflections);
    RegisterSpellScript(spell_anduin_wrynn_grim_fate);

    RegisterAreaTriggerAI(at_anduin_wrynn_beacon_of_hope);
    RegisterSpellScript(spell_anduin_wrynn_beacon_of_hope);

    RegisterSpellScript(spell_anduin_wrynn_empowered_hopebreaker);
    RegisterSpellScript(spell_anduin_wrynn_empowered_hopebreaker_periodic);

    RegisterAreaTriggerAI(at_anduin_wrynn_hopelessness);
    RegisterSpellScript(spell_anduin_wrynn_hopelessness);
    RegisterSpellScript(spell_anduin_wrynn_hopelessness_expire);

    RegisterSpellScript(spell_remnant_of_a_fallen_king_spawn);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_energize_runic_power);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_army_of_the_dead);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_echoes_of_andorhal);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_soul_reaper);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_remorseless_winter_periodic);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_remorseless_winter_damage);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_return_to_kingsmourne);

    RegisterAreaTriggerAI(at_anduin_wrynn_introduction);

    new conversation_anduin_introduction();
    new conversation_arthas_uther();
    new conversation_arthas_sylvanas();
    new conversation_anduin_outroduction();

    RegisterSpellScript(spell_anduin_wrynn_blasphemy_init);
    RegisterSpellScript(spell_anduin_wrynn_progression_aura);
}

