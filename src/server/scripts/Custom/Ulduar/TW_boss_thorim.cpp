/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "../../Northrend/Ulduar/Ulduar/ulduar.h"

// Thorim Spells
enum Spells
{
    SPELL_SHEAT_OF_LIGHTNING                    = 62276,
    SPELL_STORMHAMMER                           = 62042,
    SPELL_DEAFENING_THUNDER                     = 62470,
    SPELL_CHARGE_ORB                            = 62016,
    SPELL_SUMMON_LIGHTNING_ORB                  = 62391,
    SPELL_TOUCH_OF_DOMINION                     = 62565,
    SPELL_CHAIN_LIGHTNING                       = 62131,
    SPELL_CHAIN_LIGHTNING_25                    = 64390,
    SPELL_LIGHTNING_CHARGE                      = 62279,
    SPELL_LIGHTNING_DESTRUCTION                 = 62393,
    SPELL_LIGHTNING_RELEASE                     = 62466,
    SPELL_LIGHTNING_PILLAR                      = 62976,
    SPELL_UNBALANCING_STRIKE                    = 62130,
    SPELL_BERSERK_PHASE_1                       = 62560,
    SPELL_BERSERK_PHASE_2                       = 26662,

    SPELL_ACHIEVEMENT_CHECK                     = 64985,
    SPELL_ACHIEVEMENT_SIFFED                    = 64980,

    // Used by traps
    SPELL_PARALYTIC_FIELD           = 63540,
    SPELL_PARALYTIC_FIELD2          = 62241,
};

enum Phases
{
    PHASE_NULL,
    PHASE_1,
    PHASE_2,
    PHASE_OUTRO,
};

enum Events
{
    EVENT_SAY_AGGRO_2 = 1,
    EVENT_STORMHAMMER,
    EVENT_CHARGE_ORB,
    EVENT_SUMMON_WARBRINGER,
    EVENT_SUMMON_EVOKER,
    EVENT_SUMMON_COMMONER,
    EVENT_BERSERK,
    EVENT_UNBALANCING_STRIKE,
    EVENT_CHAIN_LIGHTNING,
    EVENT_TRANSFER_ENERGY,
    EVENT_RELEASE_ENERGY,

    EVENT_CLOSE_ARENA_DOOR,
    EVENT_BUNNY_VISUAL_CHECK,
    EVENT_END_NORMAL_1,
    EVENT_END_NORMAL_2,
    EVENT_END_NORMAL_3,
    EVENT_END_HARD_1,
    EVENT_END_HARD_2,
    EVENT_END_HARD_3,
    EVENT_SIFFED
};

enum Yells
{
    SAY_AGGRO_1                                 = 21,
    SAY_SPECIAL_1                               = 1,
    SAY_SPECIAL_2                               = 2,
    SAY_SPECIAL_3                               = 3,
    SAY_JUMPDOWN                                = 4,
    SAY_SLAY                                    = 5,
    SAY_BERSERK                                 = 6,
    SAY_WIPE                                    = 7,
    SAY_DEATH                                   = 8,
    SAY_END_NORMAL_1                            = 9,
    SAY_END_NORMAL_2                            = 10,
    SAY_END_NORMAL_3                            = 11,
    SAY_END_HARD_1                              = 12,
    SAY_END_HARD_2                              = 13,
    SAY_END_HARD_3                              = 14,
    //SAY_YS_HELP                               = -1603287 -- Not sure what would be this one

    SAY_AGGRO_2                                 = 20,
};

#define EMOTE_BARRIER                           "Runic Colossus surrounds itself with a crackling Runic Barrier!"
#define EMOTE_MIGHT                             "Ancient Rune Giant fortifies nearby allies with runic might!"

// Thorim Pre-Phase Adds
enum PreAdds
{
    BEHEMOTH,
    MERCENARY_CAPTAIN_A,
    MERCENARY_SOLDIER_A,
    DARK_RUNE_ACOLYTE,
    MERCENARY_CAPTAIN_H,
    MERCENARY_SOLDIER_H
};

enum PreAddSpells
{
    SPELL_ACID_BREATH               = 62315,
    SPELL_ACID_BREATH_H             = 62415,
    SPELL_SWEEP                     = 62316,
    SPELL_SWEEP_H                   = 62417,

    SPELL_DEVASTATE                 = 62317,
    SPELL_HEROIC_SWIPE              = 62444,

    SPELL_BARBED_SHOT               = 62318,
    SPELL_SHOOT                     = 16496,

    SPELL_RENEW                     = 62333,
    SPELL_RENEW_H                   = 62441,
    SPELL_GREATER_HEAL              = 62334,
    SPELL_GREATER_HEAL_H            = 62442
};

const uint32 PRE_PHASE_ADD[]                    = {32882, 32908, 32885, 32886, 32907, 32883};
#define SPELL_PRE_PRIMARY(i)                    RAID_MODE(SPELL_PRE_PRIMARY_N[i],SPELL_PRE_PRIMARY_H[i])
const uint32 SPELL_PRE_PRIMARY_N[]              = {SPELL_ACID_BREATH,   SPELL_DEVASTATE,    SPELL_BARBED_SHOT, SPELL_RENEW,    SPELL_DEVASTATE, SPELL_BARBED_SHOT};
const uint32 SPELL_PRE_PRIMARY_H[]              = {SPELL_ACID_BREATH_H, SPELL_DEVASTATE,    SPELL_BARBED_SHOT, SPELL_RENEW_H,  SPELL_DEVASTATE, SPELL_BARBED_SHOT};
#define SPELL_PRE_SECONDARY(i)                  RAID_MODE(SPELL_PRE_SECONDARY_N[i],SPELL_PRE_SECONDARY_H[i])
const uint32 SPELL_PRE_SECONDARY_N[]            = {SPELL_SWEEP,     SPELL_HEROIC_SWIPE,     SPELL_SHOOT,    SPELL_GREATER_HEAL,     SPELL_HEROIC_SWIPE, SPELL_SHOOT};
const uint32 SPELL_PRE_SECONDARY_H[]            = {SPELL_SWEEP_H,   SPELL_HEROIC_SWIPE,     SPELL_SHOOT,    SPELL_GREATER_HEAL_H,   SPELL_HEROIC_SWIPE, SPELL_SHOOT};
#define SPELL_HOLY_SMITE                        RAID_MODE(62335, 62443)

enum Actions
{
    ACTION_INCREASE_PREADDS_COUNT          = 1,
    ACTION_RUNIC_SMASH                     = 2,
    ACTION_BERSERK                         = 3,
    ACTION_CLOSE_ARENA_DOOR                = 4
};

// Thorim Arena Phase Adds
enum ArenaAdds
{
    DARK_RUNE_CHAMPION,
    DARK_RUNE_COMMONER,
    DARK_RUNE_EVOKER,
    DARK_RUNE_WARBRINGER,
    IRON_RING_GUARD,
    IRON_HONOR_GUARD
};

enum Creatures
{
    NPC_LIGHTNING_ORB               = 33138,
    NPC_POWER_SOURCE                = 34055, // bad id
    NPC_GOLEM_BUNNY                 = 33140,  // 33141
    NPC_CHARGED_ORB                 = 33378,
    NPC_TENTACLE_OF_YOGG_SARON      = 34266
};

enum Data
{
    DATA_LOSE_YOUR_ILLUSION,
    DATA_DONT_STAND_IN_THE_LIGHTNING,
};

const uint32 ARENA_PHASE_ADD[]                  = {32876, 32904, 32878, 32877, 32874, 32875, 33110};

#define SPELL_ARENA_PRIMARY(i)                  RAID_MODE(SPELL_ARENA_PRIMARY_N[i],SPELL_ARENA_PRIMARY_H[i])

const uint32 SPELL_ARENA_PRIMARY_N[]            = {35054, 62326, 62327, 62322, 64151, 42724, 62333};
const uint32 SPELL_ARENA_PRIMARY_H[]            = {35054, 62326, 62445, 62322, 64151, 42724, 62441};
#define SPELL_ARENA_SECONDARY(i)                RAID_MODE(SPELL_ARENA_SECONDARY_N[i],SPELL_ARENA_SECONDARY_H[i])
const uint32 SPELL_ARENA_SECONDARY_N[]          = {15578, 38313, 62321, 62331, 62332, 62334};
const uint32 SPELL_ARENA_SECONDARY_H[]          = {15578, 38313, 62529, 62418, 62420, 62442};
#define SPELL_AURA_OF_CELERITY                  62320
#define SPELL_CHARGE                            32323
#define SPELL_RUNIC_MENDING                     RAID_MODE(62328, 62446)

#define GO_LEVER                                194265

// Runic Colossus (Mini Boss) Spells
enum RunicSpells
{
    SPELL_SMASH                                 = 62339,
    SPELL_RUNIC_BARRIER                         = 62338,
    SPELL_RUNIC_CHARGE                          = 62613,
    SPELL_RUNIC_SMASH                           = 62465,
    SPELL_RUNIC_SMASH_LEFT                      = 62057,
    SPELL_RUNIC_SMASH_RIGHT                     = 62058
};

// Ancient Rune Giant (Mini Boss) Spells
enum AncientSpells
{
    SPELL_RUNIC_FORTIFICATION                   = 62942,
    SPELL_RUNE_DETONATION                       = 62526,
    SPELL_STOMP                                 = 62411
};

// Sif Spells
enum SifSpells
{
    SPELL_FROSTBOLT_VOLLEY                      = 62580,
    SPELL_FROSTNOVA                             = 62597,
    SPELL_BLIZZARD                              = 62576,
    SPELL_FROSTBOLT                             = 69274
};

enum ThorimChests
{
    CACHE_OF_STORMS_10                          = 194312,
    CACHE_OF_STORMS_HARDMODE_10                 = 194313,
    CACHE_OF_STORMS_25                          = 194315,
    CACHE_OF_STORMS_HARDMODE_25                 = 194314
};

const Position Pos[7] =
{
    {2095.53f, -279.48f, 419.84f, 0.504f},
    {2092.93f, -252.96f, 419.84f, 6.024f},
    {2097.86f, -240.97f, 419.84f, 5.643f},
    {2113.14f, -225.94f, 419.84f, 5.259f},
    {2156.87f, -226.12f, 419.84f, 4.202f},
    {2172.42f, -242.70f, 419.84f, 3.583f},
    {2171.92f, -284.59f, 419.84f, 2.691f}
};

const Position PosOrbs[7] =
{
    {2104.99f, -233.484f, 433.576f, 5.49779f},
    {2092.64f, -262.594f, 433.576f, 6.26573f},
    {2104.76f, -292.719f, 433.576f, 0.78539f},
    {2164.97f, -293.375f, 433.576f, 2.35619f},
    {2164.58f, -233.333f, 433.576f, 3.90954f},
    {2145.81f, -222.196f, 433.576f, 4.45059f},
    {2123.91f, -222.443f, 433.576f, 4.97419f}
};

const Position PosCharge[7] =
{
    {2108.95f, -289.241f, 420.149f, 5.49779f},
    {2097.93f, -262.782f, 420.149f, 6.26573f},
    {2108.66f, -237.102f, 420.149f, 0.78539f},
    {2160.56f, -289.292f, 420.149f, 2.35619f},
    {2161.02f, -237.258f, 420.149f, 3.90954f},
    {2143.87f, -227.415f, 420.149f, 4.45059f},
    {2125.84f, -227.439f, 420.149f, 4.97419f}
};

#define POS_X_ARENA  2181.19f
#define POS_Y_ARENA  -299.12f

#define IN_ARENA(who) (who->GetPositionX() < POS_X_ARENA && who->GetPositionY() > POS_Y_ARENA)
#define IS_HEALER(who) (who->GetEntry() == 32886 || who->GetEntry() == 32878 || who->GetEntry() ==  33110)

struct SummonLocation
{
    float x,y,z,o;
    uint32 entry;
};

SummonLocation preAddLocations[]=
{
    {2149.68f, -263.477f, 419.679f, 3.120f, 32882},
    {2131.31f, -271.640f, 419.840f, 2.188f, 32908},
    {2127.24f, -259.182f, 419.974f, 5.917f, 32885},
    {2123.32f, -254.770f, 419.840f, 6.170f, 32885},
    {2120.10f, -258.990f, 419.840f, 6.250f, 32885},
    {2129.09f, -277.142f, 419.756f, 1.222f, 32886}
};

SummonLocation colossusAddLocations[]=
{
    {2218.38f, -297.50f, 412.18f, 1.030f, 32874},
    {2235.07f, -297.98f, 412.18f, 1.613f, 32874},
    {2235.26f, -338.34f, 412.18f, 1.589f, 32874},
    {2217.69f, -337.39f, 412.18f, 1.241f, 32874},
    {2227.58f, -308.30f, 412.18f, 1.591f, 33110},
    {2227.47f, -345.37f, 412.18f, 1.566f, 33110}
};

SummonLocation giantAddLocations[]=
{
    {2198.05f, -428.77f, 419.95f, 6.056f, 32875},
    {2220.31f, -436.22f, 412.26f, 1.064f, 32875},
    {2158.88f, -441.73f, 438.25f, 0.127f, 32875},
    {2198.29f, -436.92f, 419.95f, 0.261f, 33110},
    {2230.93f, -434.27f, 412.26f, 1.931f, 33110}
};

// Forwarding definition, since required by add-location and predicates
enum ArenaAddEntries
{
    NPC_DARK_RUNE_CHAMPION      = 32876,
    NPC_DARK_RUNE_COMMONER      = 32904,
    NPC_DARK_RUNE_EVOKER        = 32878,
    NPC_DARK_RUNE_WARBRINGER    = 32877,
    NPC_IRON_RING_GUARD         = 32874,
    NPC_IRON_HONOR_GUARD        = 32875,
    NPC_DARK_RUNE_ACOLYTE_ARENA = 32886,
    NPC_DARK_RUNE_ACOLYTE_TUNNEL= 33110
};

struct BerserkSelector
{
    bool operator() (WorldObject* unit)
    {
        if (unit->GetTypeId() != TYPEID_PLAYER)
        {
            // This doesn't work
            /*for (uint8 i = 0; i < 8; i++)
                if (unit->GetEntry() == (uint32)ArenaAddEntries(i))
                    return false;*/

            // Terribly ugly - TODO: conditions at database?
            if (unit->GetEntry() == NPC_THORIM || unit->GetEntry() == NPC_RUNIC_COLOSSUS || unit->GetEntry() == NPC_RUNE_GIANT || 
                unit->GetEntry() == NPC_DARK_RUNE_CHAMPION || unit->GetEntry() == NPC_DARK_RUNE_COMMONER || unit->GetEntry() == NPC_DARK_RUNE_EVOKER ||
                unit->GetEntry() == NPC_DARK_RUNE_WARBRINGER || unit->GetEntry() == NPC_IRON_RING_GUARD || unit->GetEntry() == NPC_IRON_HONOR_GUARD ||
                unit->GetEntry() == NPC_DARK_RUNE_ACOLYTE_ARENA || unit->GetEntry() == NPC_DARK_RUNE_ACOLYTE_TUNNEL)
                return false;
        }

        return true;
    }
};

class TW_boss_thorim : public CreatureScript
{
public:
    TW_boss_thorim() : CreatureScript("TW_boss_thorim") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_boss_thorimAI(creature);
    }

    struct TW_boss_thorimAI : public BossAI
    {
        TW_boss_thorimAI(Creature* creature) : BossAI(creature, BOSS_THORIM)
        {
            homePosition = creature->GetHomePosition();
            EncounterFinished = false;
            Wipe = false;
        }

        Phases phase;

        uint8 PreAddsCount;
        uint32 EncounterTime;
        uint32 _checkTargetTimer;
        bool Wipe;
        bool HardMode;
        bool OrbSummoned;
        bool EncounterFinished;
        bool summonChampion;
        bool LightningAchievement;
        Position homePosition;
        ObjectGuid SifGUID;

        void Reset() override
        {
            if (EncounterFinished)
                return;

            if (Wipe)
            {
                instance->SetBossState(BOSS_THORIM, FAIL);
                if (GameObject* lightning = me->FindNearestGameObject(GO_THORIM_LIGHTNING_FIELD, 500))
                    lightning->SetGoState(GO_STATE_ACTIVE);
                if (Creature* Sif = me->FindNearestCreature(NPC_SIF, 200.0f))
                    Sif->DespawnOrUnsummon();
                Talk(SAY_WIPE);
            }

            _Reset();

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);

            phase = PHASE_NULL;
            HardMode = false;
            OrbSummoned = false;
            summonChampion = false;
            LightningAchievement = true;
            Wipe = false;
            EncounterFinished = false;
            _checkTargetTimer = 7000;
            PreAddsCount = 0;

            if (Creature* Sif = ObjectAccessor::GetCreature(*me, SifGUID))
                Sif->DespawnOrUnsummon();
            SifGUID.Clear();

            // Respawn Mini Bosses
            for (uint8 i = DATA_RUNIC_COLOSSUS; i <= DATA_RUNE_GIANT; ++i)
                if (Creature* MiniBoss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(i)))
                    MiniBoss->Respawn(true);

            // Spawn Pre-Phase Adds
            for (uint8 i = 0; i < 6; ++i)
                me->SummonCreature(preAddLocations[i].entry,preAddLocations[i].x, preAddLocations[i].y, preAddLocations[i].z, preAddLocations[i].o,
                TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

            if (GameObject* go = me->FindNearestGameObject(GO_LEVER, 500))
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() == TYPEID_PLAYER)
            {
                Talk(SAY_SLAY);
                instance->SetData(DATA_CRITERIA_THORIM, 1);
            }
        }

        void EncounterIsDone()
        {
            if (EncounterFinished)
                return;

            phase = PHASE_OUTRO;
            EncounterFinished = true;
            Talk(SAY_DEATH);

            if (instance)
            {
                // Lose Your Illusion
                if (HardMode)
                {
                    me->SummonGameObject(RAID_MODE(CACHE_OF_STORMS_HARDMODE_10, CACHE_OF_STORMS_HARDMODE_25), 2134.58f, -286.908f, 419.495f, 1.55988f, 0, 0, 1, 1, 604800);
                    events.ScheduleEvent(EVENT_END_HARD_1, 5000);
                }
                else
                {
                    events.ScheduleEvent(EVENT_END_NORMAL_1, 5000);
                    me->SummonGameObject(RAID_MODE(CACHE_OF_STORMS_10, CACHE_OF_STORMS_25), 2134.58f, -286.908f, 419.495f, 1.55988f, 0, 0, 1, 1, 604800);
                }
            
                if (GameObject* lightning = me->FindNearestGameObject(GO_THORIM_LIGHTNING_FIELD, 500.0f))
                    if (lightning->GetGoState() == GO_STATE_READY)
                        lightning->SetGoState(GO_STATE_ACTIVE);

                DoCastAOE(SPELL_ACHIEVEMENT_CHECK);
                me->setFaction(FACTION_FRIENDLY);
            }
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO_1);
            _EnterCombat();

            // Spawn Thunder Orbs
            for (uint8 n = 0; n < 7; ++n)
                me->SummonCreature(NPC_CHARGED_ORB, PosOrbs[n], TEMPSUMMON_CORPSE_DESPAWN);

            Wipe = true;
            EncounterTime = 0;
            phase = PHASE_1;
            events.SetPhase(PHASE_1);
            DoCast(me, SPELL_SHEAT_OF_LIGHTNING);
            events.ScheduleEvent(EVENT_STORMHAMMER, 40000, 0, PHASE_1);
            events.ScheduleEvent(EVENT_CHARGE_ORB, 30000, 0, PHASE_1);
            events.ScheduleEvent(EVENT_SUMMON_WARBRINGER, 25000, 0, PHASE_1);
            events.ScheduleEvent(EVENT_SUMMON_EVOKER, 30000, 0, PHASE_1);
            events.ScheduleEvent(EVENT_SUMMON_COMMONER, 35000, 0, PHASE_1);
            events.ScheduleEvent(EVENT_BERSERK, 360000, 0, PHASE_1);
            events.ScheduleEvent(EVENT_SAY_AGGRO_2, 10000, 0, PHASE_1);

            if (Creature* runic = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RUNIC_COLOSSUS)))
                runic->AI()->DoAction(ACTION_RUNIC_SMASH);

            if (GameObject* go = me->FindNearestGameObject(GO_LEVER, 500.0f))
                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

            if (instance)
                instance->SetBossState(BOSS_THORIM, IN_PROGRESS);
        }

        void EnterEvadeMode() override
        {
            if (!_EnterEvadeMode())
                return;

            me->SetHomePosition(homePosition);
            me->GetMotionMaster()->MoveTargetedHome();
            Reset();
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_LOSE_YOUR_ILLUSION:
                    return HardMode;
                case DATA_DONT_STAND_IN_THE_LIGHTNING:
                    return LightningAchievement;
                default:
                    break;
            }

            return 0;
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
        {
            if (target->GetTypeId() == TYPEID_PLAYER && spell->Id == SPELL_LIGHTNING_RELEASE)
                LightningAchievement = false;
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            
            if (phase == PHASE_1)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SAY_AGGRO_2:
                            Talk(SAY_AGGRO_2);
                            if (Creature* Sif = me->SummonCreature(NPC_SIF, me->GetPositionX() + 10, me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 175000))
                            {
                                SifGUID = Sif->GetGUID();
                                Sif->setFaction(FACTION_FRIENDLY);
                            }
                            break;
                        case EVENT_STORMHAMMER:
                            DoCast(SPELL_STORMHAMMER);
                            events.ScheduleEvent(EVENT_STORMHAMMER, urand(15, 20) *IN_MILLISECONDS, 0, PHASE_1);
                            break;
                        case EVENT_CHARGE_ORB:
                            me->CastCustomSpell(SPELL_CHARGE_ORB, SPELLVALUE_MAX_TARGETS, 1, NULL);
                            events.ScheduleEvent(EVENT_CHARGE_ORB, urand(15, 20) *IN_MILLISECONDS, 0, PHASE_1);
                            break;
                        case EVENT_SUMMON_WARBRINGER:
                            me->SummonCreature(ARENA_PHASE_ADD[3], Pos[rand()%7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            if (summonChampion)
                            {
                                me->SummonCreature(ARENA_PHASE_ADD[0], Pos[rand()%7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                                summonChampion = false;
                            }
                            else
                                summonChampion = true;
                            events.ScheduleEvent(EVENT_SUMMON_WARBRINGER, 20000, 0, PHASE_1);
                            break;
                        case EVENT_SUMMON_EVOKER:
                            me->SummonCreature(ARENA_PHASE_ADD[2], Pos[rand()%7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            events.ScheduleEvent(EVENT_SUMMON_EVOKER, urand(23, 27) *IN_MILLISECONDS, 0, PHASE_1);
                            break;
                        case EVENT_SUMMON_COMMONER:
                            for (uint8 n = 0; n < urand(5, 7); ++n)
                                me->SummonCreature(ARENA_PHASE_ADD[1], Pos[rand()%7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
                            events.ScheduleEvent(EVENT_SUMMON_COMMONER, 30000, 0, PHASE_1);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK_PHASE_1);
                            DoCast(me, SPELL_SUMMON_LIGHTNING_ORB, true);
                            Talk(SAY_BERSERK);
                            break;
                        case EVENT_CLOSE_ARENA_DOOR:
                            instance->DoUseDoorOrButton(instance->GetGuidData(GO_THORIM_DARK_IRON_PROTCULLIS));
                            break;
                    }
                }
            }
            else if (phase == PHASE_2)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UNBALANCING_STRIKE:
                            DoCastVictim(SPELL_UNBALANCING_STRIKE);
                            events.ScheduleEvent(EVENT_UNBALANCING_STRIKE, 26000, 0, PHASE_2);
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                                DoCast(target, RAID_MODE<uint32>(SPELL_CHAIN_LIGHTNING, SPELL_CHAIN_LIGHTNING_25));
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(7, 15) *IN_MILLISECONDS, 0, PHASE_2);
                            break;
                        case EVENT_TRANSFER_ENERGY:
                            if (Creature* source = me->SummonCreature(NPC_POWER_SOURCE, PosCharge[urand(0, 6)], TEMPSUMMON_TIMED_DESPAWN, 9000))
                                source->CastSpell(source, SPELL_LIGHTNING_PILLAR, true);
                            events.ScheduleEvent(EVENT_RELEASE_ENERGY, 8000, 0, PHASE_2);
                            break;
                        case EVENT_RELEASE_ENERGY:
                            if (Creature* source = me->FindNearestCreature(NPC_POWER_SOURCE, 100.0f))
                            {
                                me->SetOrientation(me->GetAngle(source));
                                DoCast(source, SPELL_LIGHTNING_RELEASE);
                            }
                            DoCast(me, SPELL_LIGHTNING_CHARGE, true);
                            events.ScheduleEvent(EVENT_TRANSFER_ENERGY, 8000, 0, PHASE_2);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK_PHASE_2);
                            Talk(SAY_BERSERK);
                            break;
                        case EVENT_SIFFED:
                            DoCastAOE(SPELL_ACHIEVEMENT_SIFFED);
                            break;
                    }
                }
            }
            else if (phase == PHASE_OUTRO)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                         case EVENT_END_NORMAL_1:
                             Talk(SAY_END_NORMAL_1);
                             events.ScheduleEvent(EVENT_END_NORMAL_2, 15000);
                             break;
                         case EVENT_END_NORMAL_2:
                             Talk(SAY_END_NORMAL_2);
                             events.ScheduleEvent(EVENT_END_NORMAL_3, 15000);
                             break;
                        case EVENT_END_NORMAL_3:
                            Talk(SAY_END_NORMAL_3);
                            me->DespawnOrUnsummon(10000);
                            _JustDied();
                            break;
                        case EVENT_END_HARD_1:
                            Talk(SAY_END_HARD_1);
                            if (Creature* Sif = me->FindNearestCreature(NPC_SIF, 200.0f))
                            {
                                DoCast(Sif, SPELL_STORMHAMMER, true);
                                Sif->SetVisible(false);
                                if (Creature* tentacle = me->SummonCreature(NPC_TENTACLE_OF_YOGG_SARON, Sif->GetPositionX(), Sif->GetPositionY(), Sif->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 15000))
                                    tentacle->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                                Sif->DespawnOrUnsummon();
                            }
                            events.ScheduleEvent(EVENT_END_HARD_2, 15000);
                            break;
                        case EVENT_END_HARD_2:
                            Talk(SAY_END_HARD_2);
                            events.ScheduleEvent(EVENT_END_HARD_3, 15000);
                            break;
                        case EVENT_END_HARD_3:
                            Talk(SAY_END_HARD_3);
                            me->DespawnOrUnsummon(10000);
                            _JustDied();
                            break;
                    }
                }
            }

            if (!UpdateVictim())
                return;

            if (phase == PHASE_2 && me->GetVictim() && !IN_ARENA(me->GetVictim()))
            {
                me->GetVictim()->getHostileRefManager().deleteReference(me);
                return;
            }

            if (_checkTargetTimer < diff)
            {
                // workaround, see mimiron script
                if (!SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                {
                    EnterEvadeMode();
                    return;
                }
                _checkTargetTimer = 7000;
            }
            else
                _checkTargetTimer -= diff;

            if (phase == PHASE_2 && !IN_ARENA(me))
            {
                EnterEvadeMode();
                return;
            }

            //_DoAggroPulse(diff);
            EncounterTime += diff;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            DoMeleeAttackIfReady();
        }

        void DoAction(int32 action) override
        {
            switch (action)
            {
                case ACTION_BERSERK:
                    if (phase != PHASE_1)
                        return;

                    if (!OrbSummoned)
                    {
                        events.RescheduleEvent(EVENT_BERSERK, 1000);
                        OrbSummoned = true;
                    }
                    return;
                case ACTION_INCREASE_PREADDS_COUNT:
                    ++PreAddsCount;
                    break;
                case ACTION_CLOSE_ARENA_DOOR:
                    events.ScheduleEvent(EVENT_CLOSE_ARENA_DOOR, 10000);
                    break;
            }

            if (PreAddsCount >= 6 && !Wipe)
            {
                if (instance)
                    instance->SetBossState(BOSS_THORIM, IN_PROGRESS);
                // Event starts
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                events.Reset();
                DoZoneInCombat();
            }
        }

        void JustSummoned(Creature* summon) override
        {
            summons.Summon(summon);
            if (me->IsInCombat())
                DoZoneInCombat(summon);

            if (summon->GetEntry() == NPC_LIGHTNING_ORB)
                summon->CastSpell(summon, SPELL_LIGHTNING_DESTRUCTION, true);
        }

        void DamageTaken(Unit* attacker, uint32 &damage) override
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EncounterIsDone();
            }

            if (phase == PHASE_1 && attacker && instance)
            {
                Creature* colossus = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RUNIC_COLOSSUS));
                Creature* giant = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_RUNE_GIANT));
                if (colossus && colossus->isDead() && giant && giant->isDead() && me->IsWithinDistInMap(attacker, 10.0f) && attacker->ToPlayer())
                {
                    if (Creature* Sif = ObjectAccessor::GetCreature(*me, SifGUID))
                        Sif->DespawnOrUnsummon();

                    Talk(SAY_JUMPDOWN);
                    phase = PHASE_2;
                    events.SetPhase(PHASE_2);
                    me->RemoveAurasDueToSpell(SPELL_SHEAT_OF_LIGHTNING);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                    me->GetMotionMaster()->MoveJump(2134.79f, -263.03f, 419.84f, 10.0f, 20.0f);
                    summons.DespawnEntry(33378); // despawn charged orbs
                    events.ScheduleEvent(EVENT_UNBALANCING_STRIKE, 15000, 0, PHASE_2);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 20000, 0, PHASE_2);
                    events.ScheduleEvent(EVENT_TRANSFER_ENERGY, 20000, 0, PHASE_2);
                    events.ScheduleEvent(EVENT_BERSERK, 300000, 0, PHASE_2);
                    // Hard Mode
                    if (EncounterTime <= 3*MINUTE*IN_MILLISECONDS)
                    {
                        HardMode = true;
                        events.ScheduleEvent(EVENT_SIFFED, 5000);
                        me->SummonCreature(NPC_SIF, 2149.27f, -260.55f, 419.69f, 2.527f, TEMPSUMMON_CORPSE_DESPAWN);
                    }
                    else
                        me->AddAura(SPELL_TOUCH_OF_DOMINION, me);
                }
            }
        }
    };
};


class TW_npc_thorim_pre_phase : public CreatureScript
{
public:
    TW_npc_thorim_pre_phase() : CreatureScript("TW_npc_thorim_pre_phase") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new TW_npc_thorim_pre_phaseAI (pCreature);
    }

    struct TW_npc_thorim_pre_phaseAI : public ScriptedAI
    {
        TW_npc_thorim_pre_phaseAI(Creature *pCreature) : ScriptedAI(pCreature)
        {
            pInstance = pCreature->GetInstanceScript();
            me->setFaction(14);
            for (uint8 i = 0; i < 6; ++i)
                if (me->GetEntry() == PRE_PHASE_ADD[i])
                    id = PreAdds(i);

            healer = IS_HEALER(me);
        }

        InstanceScript* pInstance;
        PreAdds id;
        uint32 PrimaryTimer;
        uint32 SecondaryTimer;
        bool healer;

        void Reset() override
        {
            PrimaryTimer = urand(3000, 6000);
            SecondaryTimer = urand (12000, 15000);
        }

        void JustDied(Unit* /*victim*/) override
        {
            if (Creature* pThorim = ObjectAccessor::GetCreature(*me, pInstance->GetGuidData(BOSS_THORIM)))
                pThorim->AI()->DoAction(ACTION_INCREASE_PREADDS_COUNT);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (PrimaryTimer <= diff)
            {
                Unit* target = NULL;
                if (healer)
                {
                    if (!(target = DoSelectLowestHpFriendly(30)))
                        target = me;
                }else
                {
                    target = me->GetVictim();
                }

                if (target)
                {
                    DoCast(target,SPELL_PRE_PRIMARY(id));
                    PrimaryTimer = urand(15000, 20000);
                }
            }
            else PrimaryTimer -= diff;

            if (SecondaryTimer <= diff)
            {
                Unit* target = NULL;
                if (healer)
                {
                    if (!(target = DoSelectLowestHpFriendly(30)))
                        target = me;
                }else
                {
                    target = me->GetVictim();
                }

                if (target)
                {
                    DoCast(SPELL_PRE_SECONDARY(id));
                    SecondaryTimer = urand(4000, 8000);
                }
            }
            else SecondaryTimer -= diff;

            if (id == DARK_RUNE_ACOLYTE)
                DoSpellAttackIfReady(SPELL_HOLY_SMITE);
            else
                DoMeleeAttackIfReady();
        }
    };
};

class TW_npc_thorim_arena_phase : public CreatureScript
{
    public:
        TW_npc_thorim_arena_phase() : CreatureScript("TW_npc_thorim_arena_phase") { }

        struct TW_npc_thorim_arena_phaseAI : public ScriptedAI
        {
            TW_npc_thorim_arena_phaseAI(Creature* creature) : ScriptedAI(creature)
            {
                _instance = creature->GetInstanceScript();
                me->setFaction(14);
                for (uint8 i = 0; i < 7; ++i)
                    if (me->GetEntry() == ARENA_PHASE_ADD[i])
                        _id = ArenaAdds(i);

                _IsInArena = IN_ARENA(me);
                _healer = IS_HEALER(me);
            }

            bool isOnSameSide(const Unit* who)
            {
                return (_IsInArena == IN_ARENA(who));
            }

            void DamageTaken(Unit* attacker, uint32 &damage) override
            {
                if (!isOnSameSide(attacker))
                    damage = 0;
            }

            void Reset() override
            {
                _PrimaryTimer = urand(3000, 6000);
                _SecondaryTimer = urand (7000, 9000);
                _ChargeTimer = 8000;
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (me->IsWithinDistInMap(who, 10.0f))
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (_id == DARK_RUNE_WARBRINGER)
                    DoCast(me, SPELL_AURA_OF_CELERITY);
            }

            // this should only happen if theres no alive player in the arena -> summon orb
            // might be called by mind control release or controllers death?
            void EnterEvadeMode() override
            {
                if (Creature* thorim = ObjectAccessor::GetCreature(*me, _instance->GetGuidData(BOSS_THORIM)))
                    thorim->AI()->DoAction(ACTION_BERSERK);
                _EnterEvadeMode();
                me->GetMotionMaster()->MoveTargetedHome();
                Reset();
            }

             void KilledUnit(Unit* who) override
             {
                 if (who->GetTypeId() == TYPEID_PLAYER)
                     me->GetInstanceScript()->SetData(DATA_CRITERIA_THORIM, 1);
             }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (me->GetVictim() && !isOnSameSide(me->GetVictim()))
                {
                    me->GetVictim()->getHostileRefManager().deleteReference(me);
                    return;
                }

                if (_PrimaryTimer <= diff)
                {
                    Unit* target = NULL;
                    if (_healer && _id != 32878)
                    {
                        if (!(target = DoSelectLowestHpFriendly(30)))
                            target = me;
                    }
                    else
                        target = me->GetVictim();

                    DoCast(SPELL_ARENA_PRIMARY(_id));
                    _PrimaryTimer = urand(3000, 6000);
                }
                else
                    _PrimaryTimer -= diff;

                if (_SecondaryTimer <= diff)
                {
                    Unit* target = NULL;
                    if (_healer)
                    {
                        if (!(target = DoSelectLowestHpFriendly(30)))
                            target = me;
                    }
                    else
                        target = me->GetVictim();

                    if (target)
                    {
                        DoCast(SPELL_ARENA_SECONDARY(_id));
                        _SecondaryTimer = urand(12000, 16000);
                    }
                }
                else
                    _SecondaryTimer -= diff;

                if (_ChargeTimer <= diff)
                {
                    if (_id == DARK_RUNE_CHAMPION)
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                            DoCast(target, SPELL_CHARGE);
                    _ChargeTimer = 12000;
                }
                else
                    _ChargeTimer -= diff;

                if (_id == DARK_RUNE_WARBRINGER)
                    DoSpellAttackIfReady(SPELL_HOLY_SMITE);
                else
                    DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            ArenaAdds _id;
            uint32 _PrimaryTimer;
            uint32 _SecondaryTimer;
            uint32 _ChargeTimer;
            bool _IsInArena;
            bool _healer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_thorim_arena_phaseAI(creature);
        }
};

class TW_npc_runic_colossus : public CreatureScript
{
    public:
        TW_npc_runic_colossus() : CreatureScript("TW_npc_runic_colossus") { }

        struct TW_npc_runic_colossusAI : public ScriptedAI
        {
            TW_npc_runic_colossusAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
                //SetImmuneToPushPullEffects(true);
            }

            void Reset() override
            {
                BarrierTimer = urand(12000, 15000);
                SmashTimer = urand (15000, 18000);
                ChargeTimer = urand (20000, 24000);

                RunicSmashPhase = 0;
                RunicSmashTimer = 1000;
                Side = 0;

                me->setActive(false);
                me->GetMotionMaster()->MoveTargetedHome();

                // Runed Door closed
                if (instance)
                    instance->SetData(DATA_RUNIC_DOOR, GO_STATE_READY);

                // Spawn trashes
                summons.DespawnAll();
                for (uint8 i = 0; i < 6; i++)
                    me->SummonCreature(colossusAddLocations[i].entry, colossusAddLocations[i].x, colossusAddLocations[i].y, colossusAddLocations[i].z,
                    colossusAddLocations[i].o, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);
            }

            void MoveInLineOfSight(Unit* who) override
            {
                if (me->IsWithinDistInMap(who, 30.0f))
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    me->GetInstanceScript()->SetData(DATA_CRITERIA_THORIM, 1);
            }

            void JustDied(Unit* /*victim*/) override
            {
                // Runed Door opened
                if (instance)
                    instance->SetData(DATA_RUNIC_DOOR, GO_STATE_ACTIVE);
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_RUNIC_SMASH:
                        RunicSmashPhase = 1;
                        break;
                }
            }

            void DoRunicSmash()
            {
                for (uint8 i = 0; i < 9; i++)
                    if (Creature* bunny = me->SummonCreature(NPC_GOLEM_BUNNY, Side ? 2236.0f : 2219.0f, i * 10 - 380.0f, 412.2f, 0, TEMPSUMMON_TIMED_DESPAWN, 5000))
                        bunny->AI()->SetData(1, (i + 1)* 200);

                for (uint8 i = 0; i < 9; i++)
                    if (Creature* bunny = me->SummonCreature(NPC_GOLEM_BUNNY, Side ? 2246.0f : 2209.0f, i * 10 - 380.0f, 412.2f, 0, TEMPSUMMON_TIMED_DESPAWN, 5000))
                        bunny->AI()->SetData(1, (i + 1)* 200);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                RunicSmashPhase = 0;
                me->InterruptNonMeleeSpells(true);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void UpdateAI(uint32 diff) override
            {
                if (RunicSmashPhase == 1)
                {
                    if (RunicSmashTimer <= diff)
                    {
                        Side = urand(0, 1);
                        DoCast(me, Side ? SPELL_RUNIC_SMASH_LEFT : SPELL_RUNIC_SMASH_RIGHT);
                        RunicSmashTimer = 1000;
                        RunicSmashPhase = 2;
                    }
                    else RunicSmashTimer -= diff;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (RunicSmashPhase == 2)
                {
                    RunicSmashPhase = 1;
                    DoRunicSmash();
                }

                if (!UpdateVictim())
                    return;

                if (BarrierTimer <= diff)
                {
                    me->TextEmote(EMOTE_BARRIER, 0, true);
                    DoCast(me, SPELL_RUNIC_BARRIER);
                    BarrierTimer = urand(35000, 45000);
                }
                else BarrierTimer -= diff;

                if (SmashTimer <= diff)
                {
                    DoCast(me, SPELL_SMASH);
                    SmashTimer = urand (15000, 18000);
                }
                else SmashTimer -= diff;

                if (ChargeTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -8, true))
                        DoCast(target, SPELL_RUNIC_CHARGE);
                    ChargeTimer = 20000;
                }
                else ChargeTimer -= diff;

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* instance;
            SummonList summons;

            uint8 Side;
            uint8 RunicSmashPhase;
            uint32 BarrierTimer;
            uint32 SmashTimer;
            uint32 ChargeTimer;
            uint32 RunicSmashTimer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_runic_colossusAI(creature);
        }
};

class TW_npc_runic_smash : public CreatureScript
{
    public:
        TW_npc_runic_smash() : CreatureScript("TW_npc_runic_smash") { }

        struct TW_npc_runic_smashAI : public ScriptedAI
        {
            TW_npc_runic_smashAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(16925);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                ExplodeTimer = 10000;
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    me->GetInstanceScript()->SetData(DATA_CRITERIA_THORIM, 1);
            }

            void SetData(uint32 /*type*/, uint32 data) override
            {
                ExplodeTimer = data;
            }

            void UpdateAI(uint32 diff) override
            {
                if (ExplodeTimer <= diff)
                {
                    DoCastAOE(SPELL_RUNIC_SMASH, true);
                    ExplodeTimer = 10000;
                }
                else ExplodeTimer -= diff;
            }

        private:
            uint32 ExplodeTimer;
        };


        CreatureAI* GetAI(Creature* creature) const
        {
            return new TW_npc_runic_smashAI(creature);
        }
};

class TW_npc_ancient_rune_giant : public CreatureScript
{
public:
    TW_npc_ancient_rune_giant() : CreatureScript("TW_npc_ancient_rune_giant") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_ancient_rune_giantAI(creature);
    }

    struct TW_npc_ancient_rune_giantAI : public ScriptedAI
    {
        TW_npc_ancient_rune_giantAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
            //SetImmuneToPushPullEffects(true);
        }

        InstanceScript* instance;
        SummonList summons;

        uint32 StompTimer;
        uint32 DetonationTimer;

        void Reset() override
        {
            StompTimer = urand(10000, 12000);
            DetonationTimer = 25000;

            me->GetMotionMaster()->MoveTargetedHome();
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

            // Stone Door closed
            if (instance)
                instance->SetData(DATA_STONE_DOOR, GO_STATE_READY);

            // Spawn trashes
            summons.DespawnAll();
            for (uint8 i = 0; i < 5; i++)
                me->SummonCreature(giantAddLocations[i].entry,giantAddLocations[i].x,giantAddLocations[i].y,giantAddLocations[i].z,giantAddLocations[i].o,TEMPSUMMON_CORPSE_TIMED_DESPAWN,3000);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                me->GetInstanceScript()->SetData(DATA_CRITERIA_THORIM, 1);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (me->IsWithinDistInMap(who, 30.0f))
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC);
        }

        void JustSummoned(Creature *summon) override
        {
            summons.Summon(summon);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->TextEmote(EMOTE_MIGHT, 0, true);
            DoCast(me, SPELL_RUNIC_FORTIFICATION, true);
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void JustDied(Unit* /*victim*/) override
        {
            // Stone Door opened
            if (instance)
                instance->SetData(DATA_STONE_DOOR, GO_STATE_ACTIVE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (StompTimer <= diff)
            {
                DoCast(me, SPELL_STOMP);
                StompTimer = urand(10000, 12000);
            }
            else StompTimer -= diff;

            if (DetonationTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                    DoCast(target, SPELL_RUNE_DETONATION);
                DetonationTimer = urand(10000, 12000);
            }
            else DetonationTimer -= diff;

            DoMeleeAttackIfReady();
        }
    };
};

class TW_npc_sif : public CreatureScript
{
public:
    TW_npc_sif() : CreatureScript("TW_npc_sif") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_npc_sifAI(creature);
    }

    struct TW_npc_sifAI : public ScriptedAI
    {
        TW_npc_sifAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            instance = me->GetInstanceScript();
        }

        uint32 FrostTimer;
        uint32 VolleyTimer;
        uint32 BlizzardTimer;
        uint32 NovaTimer;

        InstanceScript* instance;

        void Reset() override
        {
            FrostTimer = 2000;
            VolleyTimer = 15000;
            BlizzardTimer = 30000;
            NovaTimer = urand(20000, 25000);
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
                me->GetInstanceScript()->SetData(DATA_CRITERIA_THORIM, 1);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (FrostTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60, true))
                    DoCast(target, SPELL_FROSTBOLT);
                FrostTimer = 4000;
            }
            else FrostTimer -= diff;

            if (VolleyTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40, true))
                {
                    DoResetThreat();
                    me->AddThreat(target, 5000000.0f);
                    DoCast(target, SPELL_FROSTBOLT_VOLLEY, true);
                }
                VolleyTimer = urand(15000, 20000);
            }
            else VolleyTimer -= diff;

            if (BlizzardTimer <= diff)
            {
                DoCast(me, SPELL_BLIZZARD, true);
                BlizzardTimer = 45000;
            }
            else BlizzardTimer -= diff;

            if (NovaTimer <= diff)
            {
                DoCastAOE(SPELL_FROSTNOVA, true);
                NovaTimer = urand(20000, 25000);
            }
            else NovaTimer -= diff;
        }
    };
};

class TW_thorim_trap_bunny : public CreatureScript
{
public:
    TW_thorim_trap_bunny() : CreatureScript("TW_thorim_trap_bunny") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new TW_thorim_trap_bunnyAI(creature);
    }

    struct TW_thorim_trap_bunnyAI : public ScriptedAI
    {
        TW_thorim_trap_bunnyAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->AddUnitState(UNIT_STATE_ROOT);
            instance = me->GetInstanceScript();
            HasStunAura = false;
        }

        InstanceScript* instance;
        EventMap events;
        bool HasStunAura;

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->IsWithinDistInMap(me, 12.0f) && who->GetTypeId() == TYPEID_PLAYER && !HasStunAura)
            {
                DoCast(me, SPELL_PARALYTIC_FIELD);
                HasStunAura = true;
                events.ScheduleEvent(EVENT_BUNNY_VISUAL_CHECK, 15000);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);
            while (uint32 eventId = events.ExecuteEvent())
            {
                if (eventId == EVENT_BUNNY_VISUAL_CHECK && HasStunAura)
                    HasStunAura = false;                  
            }
        }
    };
};

class NotInArenaCheck
{
    public:
        bool operator() (WorldObject* unit)
        {
            return !IN_ARENA(unit);
        }
};

class TW_spell_stormhammer_targeting : public SpellScriptLoader
{
    public:
        TW_spell_stormhammer_targeting() : SpellScriptLoader("TW_spell_stormhammer_targeting") { }

        class TW_spell_stormhammer_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_stormhammer_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                _target = NULL;
                unitList.remove_if(NotInArenaCheck());

                if (unitList.empty())
                    return;

                _target = Trinity::Containers::SelectRandomContainerElement(unitList);
                SetTarget(unitList);
            }

            void SetTarget(std::list<WorldObject*>& unitList)
            {
                unitList.clear();

                if (_target)
                    unitList.push_back(_target);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_stormhammer_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_stormhammer_targeting_SpellScript::SetTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_stormhammer_targeting_SpellScript::SetTarget, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            WorldObject* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_stormhammer_targeting_SpellScript();
        }
};

class TW_go_thorim_lever : public GameObjectScript
{
    public:
       TW_go_thorim_lever() : GameObjectScript("TW_go_thorim_lever") { }

       bool OnGossipHello(Player* /*player*/, GameObject* go) override
       {
           if (GameObject* porticullis = go->FindNearestGameObject(GO_THORIM_DARK_IRON_PROTCULLIS, 50.0f))
               go->GetInstanceScript()->DoUseDoorOrButton(porticullis->GetGUID());

           if (Creature* thorim = go->FindNearestCreature(BOSS_THORIM, 50.0f))
               thorim->AI()->DoAction(ACTION_CLOSE_ARENA_DOOR);

           go->UseDoorOrButton();
           go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
           
           return true;
       }
};

class TW_spell_thorim_berserk : public SpellScriptLoader
{
    public:
        TW_spell_thorim_berserk() : SpellScriptLoader("TW_spell_thorim_berserk") {}

        class TW_spell_thorim_berserk_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_thorim_berserk_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(BerserkSelector());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_thorim_berserk_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_thorim_berserk_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            }

            private:
                WorldObject* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_thorim_berserk_SpellScript();
        }
};

class TW_spell_thorim_runic_fortification : public SpellScriptLoader
{
    public:
        TW_spell_thorim_runic_fortification() : SpellScriptLoader("TW_spell_thorim_runic_fortification") { }

        class TW_spell_thorim_runic_fortification_SpellScript : public SpellScript
        {
            PrepareSpellScript(TW_spell_thorim_runic_fortification_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(NoPlayerOrPetCheck());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_thorim_runic_fortification_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_thorim_runic_fortification_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(TW_spell_thorim_runic_fortification_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new TW_spell_thorim_runic_fortification_SpellScript();
        }
};

class TW_achievement_siffed_and_lose_your_illusion : public AchievementCriteriaScript
{
    public:
        TW_achievement_siffed_and_lose_your_illusion() : AchievementCriteriaScript("TW_achievement_siffed_and_lose_your_illusion")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Thorim = target->ToCreature())
                if (Thorim->AI()->GetData(DATA_LOSE_YOUR_ILLUSION))
                    return true;

            return false;
        }
};

class TW_achievement_dont_stand_in_the_lightning : public AchievementCriteriaScript
{
    public:
        TW_achievement_dont_stand_in_the_lightning() : AchievementCriteriaScript("TW_achievement_dont_stand_in_the_lightning")
        {
        }

        bool OnCheck(Player* /*player*/, Unit* target) override
        {
            if (!target)
                return false;

            if (Creature* Thorim = target->ToCreature())
                if (Thorim->AI()->GetData(DATA_DONT_STAND_IN_THE_LIGHTNING))
                    return true;

            return false;
        }
};

void AddSC_TW_boss_thorim()
{
    new TW_boss_thorim();
    new TW_npc_thorim_pre_phase();
    new TW_npc_thorim_arena_phase();
    new TW_npc_runic_colossus();
    new TW_npc_runic_smash();
    new TW_npc_ancient_rune_giant();
    new TW_npc_sif();
    new TW_spell_stormhammer_targeting();
    new TW_go_thorim_lever();
    new TW_spell_thorim_berserk();
    new TW_achievement_siffed_and_lose_your_illusion();
    new TW_achievement_dont_stand_in_the_lightning();
    new TW_spell_thorim_runic_fortification();
    new TW_thorim_trap_bunny();
}

