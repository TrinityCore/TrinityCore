/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "ulduar.h"
#include <limits>

enum Spells
{
    // Thorim
    SPELL_SHEAT_OF_LIGHTNING    = 62276,
    SPELL_STORMHAMMER           = 62042,
    SPELL_DEAFENING_THUNDER     = 62470,
    SPELL_CHARGE_ORB            = 62016,
    SPELL_SUMMON_LIGHTNING_ORB  = 62391,
    SPELL_TOUCH_OF_DOMINION     = 62565,
    SPELL_CHAIN_LIGHTNING       = 62131,
    SPELL_LIGHTNING_CHARGE      = 62279,
    SPELL_LIGHTNING_DESTRUCTION = 62393,
    SPELL_LIGHTNING_RELEASE     = 62466,
    SPELL_LIGHTNING_PILLAR      = 62976,
    SPELL_UNBALANCING_STRIKE    = 62130,
    SPELL_BERSERK_PHASE_1       = 62560,
    SPELL_BERSERK_PHASE_2       = 26662,

    // Pre-phase adds (pre-arena)
    SPELL_ACID_BREATH_10            = 62315,
    SPELL_ACID_BREATH_25            = 62415,
    SPELL_SWEEP_10                  = 62316,
    SPELL_SWEEP_25                  = 62417,
    SPELL_DEVASTATE                 = 62317,
    SPELL_HEROIC_SWIPE              = 62444,
    SPELL_BARBED_SHOT               = 62318,
    SPELL_SHOOT                     = 16496,
    SPELL_RENEW_10                  = 62333,
    SPELL_RENEW_25                  = 62441,
    SPELL_GREATER_HEAL_10           = 62334,
    SPELL_GREATER_HEAL_25           = 62442,

    // Arena adds
    SPELL_MORTAL_STRIKE         = 35054,
    SPELL_LOW_BLOW              = 62326,
    SPELL_RUNIC_LIGHTNING_10    = 62327,
    SPELL_RUNIC_LIGHTNING_25    = 62445,
    SPELL_RUNIC_STRIKE          = 62322,
    SPELL_WHIRLING_TRIP         = 64151,
    SPELL_CLEAVE                = 42724,
    // Secondary spells
    SPELL_WHIRLWIND             = 33500,
    SPELL_PUMMEL                = 38313,
    SPELL_RUNIC_SHIELD_10       = 62321,
    SPELL_RUNIC_SHIELD_25       = 62529,
    SPELL_IMPALE_10             = 62331,
    SPELL_IMPALE_25             = 62418,
    SPELL_SHIELD_SMASH_10       = 62332,
    SPELL_SHIELD_SMASH_25       = 62420,
    // Some tertiary skills
    SPELL_RUNIC_MENDING         = 62328,

    // Sif
    SPELL_FROSTBOLT_VOLLEY      = 62580,
    SPELL_FROSTNOVA             = 62597,
    SPELL_BLIZZARD              = 62576,
    SPELL_FROSTBOLT             = 69274
};

enum Events
{
    // Thorim
    EVENT_SAY_AGGRO_2                   = 1,
    EVENT_STORMHAMMER                   = 2,
    EVENT_CHARGE_ORB                    = 3,
    EVENT_SUMMON_WARBRINGER             = 4,
    EVENT_SUMMON_EVOKER                 = 5,
    EVENT_SUMMON_COMMONER               = 6,
    EVENT_BERSERK_PHASE_1               = 7,
    EVENT_BERSERK_PHASE_2               = 8,
    EVENT_UNBALANCING_STRIKE            = 9,
    EVENT_CHAIN_LIGHTNING               = 10,
    EVENT_TRANSFER_ENERGY               = 11,
    EVENT_RELEASE_LIGHTNING_CHARGE      = 12,

    // Thorim's controller
    EVENT_CHECK_PLAYER_IN_RANGE         = 13,   // used also by Pre-phase adds
    EVENT_CHECK_WIPE                    = 14,

    // Pre-phase adds
    EVENT_PRIMARY_SKILL                 = 15,
    EVENT_SECONDARY_SKILL               = 16,

    // Arena adds
    EVENT_ADD_CHARGE                    = 17,

    // Runic Colossus
    EVENT_BARRIER                       = 18,
    EVENT_SMASH                         = 19,
    EVENT_SMASH_WAVE                    = 20,
    EVENT_RUNIC_SMASH                   = 21,

    // Ancient rune giant
    EVENT_STOMP                         = 22,
    EVENT_DETONATION                    = 23,

    // Sif
    EVENT_FROSTBOLT                     = 24,
    EVENT_FROSTBOLT_VOLLEY              = 25,
    EVENT_BLIZZARD                      = 26,
    EVENT_FROSTNOVA                     = 27
};

enum Phases
{
    // Thorim
    PHASE_IDLE                  = 0,    // also used by Runic Colossus
    PHASE_PRE_ARENA_ADDS        = 1,
    PHASE_ARENA_ADDS            = 2,
    PHASE_ARENA                 = 3,

    // Runic Colossus
    PHASE_RUNIC_SMASH           = 4,
    PHASE_MELEE                 = 5,
};

enum Yells
{
    // Thorim
    SAY_AGGRO_1     = 0,
    SAY_AGGRO_2     = 1,
    SAY_SPECIAL     = 2,
    SAY_JUMPDOWN    = 3,
    SAY_SLAY        = 4,
    SAY_BERSERK     = 5,
    SAY_WIPE        = 6,
    SAY_DEATH       = 7,
    SAY_END_NORMAL  = 8,
    SAY_END_HARD    = 9,

    // Runic Colossus
    EMOTE_BARRIER   = 0
};

enum Actions
{
    ACTION_PREPHASE_ADDS_DIED       = 1,
    ACTION_DOSCHEDULE_RUNIC_SMASH   = 2,
    ACTION_BERSERK                  = 3,
    ACTION_UPDATE_PHASE             = 4,
};

enum Misc
{
    MAX_HARD_MODE_TIME      = 3*MINUTE*IN_MILLISECONDS
};

// Achievements
#define ACHIEVEMENT_SIFFED                      RAID_MODE(2977, 2978)
#define ACHIEVEMENT_LOSE_ILLUSION               RAID_MODE(3176, 3183)

enum Creatures
{
    NPC_SIF                         = 33196,
    NPC_LIGHTNING_ORB               = 33138,
    NPC_THUNDER_ORB                 = 33378,
    NPC_THORIM_COMBAT_TRIGGER       = 34055,
    NPC_THORIM_GOLEM_RH_BUNNY       = 33140,
    NPC_THORIM_GOLEM_LH_BUNNY       = 33141
};

#define SPELL_AURA_OF_CELERITY                  62320
#define SPELL_CHARGE                            32323

enum GameObjects
{
    GO_LEVER                = 179148,
    GO_DARK_IRON_PORTCULLIS = 194560
};

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
#define SPELL_HOLY_SMITE    RAID_MODE(62335, 62443)

struct SummonLocation
{
    Position pos;
    uint32 entry;
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

enum Index
{
    // skills
    INDEX_PRIMARY                   = 1,
    INDEX_SECONDARY                 = 2,

    // arena adds
    INDEX_BEHEMOTH                  = 3,
    INDEX_MERCENARY_CAPTAIN_A       = 4,
    INDEX_MERCENARY_SOLDIER_A       = 5,
    INDEX_DARK_RUNE_ACOLYTE         = 6,
    INDEX_MERCENARY_CAPTAIN_H       = 7,
    INDEX_MERCENARY_SOLDIER_H       = 8,
    INDEX_PRE_ADD_NONE              = 9,

    INDEX_DARK_RUNE_CHAMPION        = 10,
    INDEX_DARK_RUNE_COMMONER        = 11,
    INDEX_DARK_RUNE_EVOKER          = 12,
    INDEX_DARK_RUNE_WARBRINGER      = 13,
    INDEX_IRON_RING_GUARD           = 14,
    INDEX_IRON_HONOR_GUARD          = 15,
    INDEX_ARENA_DARK_RUNE_ACOLYTE   = 16,
    INDEX_ARENA_ADD_NONE            = 17
};

SummonLocation preAddLocations[]=
{
    {{2149.68f, -263.477f, 419.679f, 3.120f}, NPC_JORMUNGAR_BEHEMOTH},
    {{2131.31f, -271.640f, 419.840f, 2.188f}, NPC_MERCENARY_CAPTAIN_A},
    {{2127.24f, -259.182f, 419.974f, 5.917f}, NPC_MERCENARY_CAPTAIN_A},
    {{2123.32f, -254.770f, 419.840f, 6.170f}, NPC_MERCENARY_CAPTAIN_A},
    {{2120.10f, -258.990f, 419.840f, 6.250f}, NPC_MERCENARY_CAPTAIN_A},
    {{2129.09f, -277.142f, 419.756f, 1.222f}, NPC_DARK_RUNE_ACOLYTE}
};

const uint32 PrePhaseAddList[] = {NPC_JORMUNGAR_BEHEMOTH, NPC_MERCENARY_CAPTAIN_A, NPC_MERCENARY_SOLDIER_A, NPC_DARK_RUNE_ACOLYTE, NPC_MERCENARY_CAPTAIN_H, NPC_MERCENARY_SOLDIER_H};
const uint32 PrePhaseAddSpells_Primary[2][6] =
{
    {SPELL_ACID_BREATH_10, SPELL_DEVASTATE, SPELL_BARBED_SHOT, SPELL_RENEW_10, SPELL_DEVASTATE, SPELL_BARBED_SHOT},
    {SPELL_ACID_BREATH_25, SPELL_DEVASTATE, SPELL_BARBED_SHOT, SPELL_RENEW_25, SPELL_DEVASTATE, SPELL_BARBED_SHOT}
};
const uint32 PrePhaseAddSpells_Secondary[2][6] =
{
    {SPELL_SWEEP_10, SPELL_HEROIC_SWIPE, SPELL_SHOOT, SPELL_GREATER_HEAL_10, SPELL_HEROIC_SWIPE, SPELL_SHOOT},
    {SPELL_SWEEP_25, SPELL_HEROIC_SWIPE, SPELL_SHOOT, SPELL_GREATER_HEAL_25, SPELL_HEROIC_SWIPE, SPELL_SHOOT}
};

const uint32 ArenaAddSpells_Primary[2][7] =
{
    {SPELL_MORTAL_STRIKE, SPELL_LOW_BLOW, SPELL_RUNIC_LIGHTNING_10, SPELL_RUNIC_STRIKE, SPELL_WHIRLING_TRIP, SPELL_CLEAVE, SPELL_RENEW_10},
    {SPELL_MORTAL_STRIKE, SPELL_LOW_BLOW, SPELL_RUNIC_LIGHTNING_25, SPELL_RUNIC_STRIKE, SPELL_WHIRLING_TRIP, SPELL_CLEAVE, SPELL_RENEW_25}
};
const uint32 ArenaAddSpells_Secondary[2][7] =
{
    {SPELL_WHIRLWIND, SPELL_PUMMEL, SPELL_RUNIC_SHIELD_10, 0, SPELL_IMPALE_10, SPELL_SHIELD_SMASH_10, SPELL_GREATER_HEAL_10},
    {SPELL_WHIRLWIND, SPELL_PUMMEL, SPELL_RUNIC_SHIELD_25, 0, SPELL_IMPALE_25, SPELL_SHIELD_SMASH_25, SPELL_GREATER_HEAL_25}
};

SummonLocation colossusAddLocations[]=
{
    {{2218.38f, -297.50f, 412.18f, 1.030f}, 32874},
    {{2235.07f, -297.98f, 412.18f, 1.613f}, 32874},
    {{2235.26f, -338.34f, 412.18f, 1.589f}, 32874},
    {{2217.69f, -337.39f, 412.18f, 1.241f}, 32874},
    {{2227.58f, -308.30f, 412.18f, 1.591f}, 33110},
    {{2227.47f, -345.37f, 412.18f, 1.566f}, 33110}
};

SummonLocation giantAddLocations[]=
{
    {{2198.05f, -428.77f, 419.95f, 6.056f}, 32875},
    {{2220.31f, -436.22f, 412.26f, 1.064f}, 32875},
    {{2158.88f, -441.73f, 438.25f, 0.127f}, 32875},
    {{2198.29f, -436.92f, 419.95f, 0.261f}, 33110},
    {{2230.93f, -434.27f, 412.26f, 1.931f}, 33110}
};

class HealerCheck
{
    public:
        HealerCheck(bool shouldBe): __shouldBe(shouldBe) {}
        bool operator() (const Unit* unit)
        {
            return __shouldBe ? __IsHealer(unit) : !__IsHealer(unit);
        }
    private:
        bool __shouldBe;
        bool __IsHealer(const Unit* who)
        {
            return (who->GetEntry() == NPC_DARK_RUNE_ACOLYTE || who->GetEntry() == NPC_DARK_RUNE_EVOKER || who->GetEntry() == NPC_DARK_RUNE_ACOLYTE_ARENA || who->GetEntry() == NPC_DARK_RUNE_ACOLYTE_TUNNEL);
        }
};

class ArenaAreaCheck
{
    public:
        ArenaAreaCheck(bool shouldBeIn): __shouldBeIn(shouldBeIn) {}
        bool operator() (const WorldObject* unit)
        {
            return __shouldBeIn ? __IsInArena(unit) : !__IsInArena(unit);
        }
    private:
        bool __shouldBeIn;
        bool __IsInArena(const WorldObject* who)
        {
            return (who->GetPositionX() < POS_X_ARENA && who->GetPositionY() > POS_Y_ARENA);    // TODO: Check if this is ok, end positions ? 
        }
};

struct BerserkSelector
{
    bool operator() (WorldObject* unit)
    {
        if (unit->GetTypeId() != TYPEID_PLAYER)
        {
            for (uint8 i = 0; i < 8; i++)
                if (unit->GetEntry() == (uint32)ArenaAddEntries(i))
                    return false;

            if (unit->GetEntry() == NPC_THORIM || unit->GetEntry() == NPC_RUNIC_COLOSSUS || unit->GetEntry() == NPC_RUNE_GIANT)
                return false;
        }

        return true;
    }
};

class npc_thorim_controller : public CreatureScript
{
    public:
        npc_thorim_controller() : CreatureScript("npc_thorim_controller") {}
        
        struct npc_thorim_controllerAI : public ScriptedAI
        {
            npc_thorim_controllerAI(Creature* creature) : ScriptedAI(creature), _summons(me)
            {
                me->SetCanFly(true);
                me->SetVisible(false);
                _instance = creature->GetInstanceScript();
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);
                _gotActivated = false;
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
            }

            void Reset()
            {
                _gotActivated = false;
                _instance->HandleGameObject(_instance->GetData64(GO_THORIM_LIGHTNING_FIELD), true); // Open the entrance door.
                _events.ScheduleEvent(EVENT_CHECK_PLAYER_IN_RANGE, 10*IN_MILLISECONDS);
            }

            void JustSummoned(Creature* summon)
            {
                _summons.Summon(summon);
                summon->AI()->AttackStart(SelectTarget(SELECT_TARGET_RANDOM));
            }

            void SummonedCreatureDies(Creature* summon, Unit* killer)
            {
                _summons.Despawn(summon);
                if (_summons.empty())
                {
                    uint64 attackTarget = 0;
                    if (killer != 0)
                        if (Player* player = killer->ToPlayer())
                            attackTarget = player->GetGUID();
                    
                    if (attackTarget == 0)
                        if (Player* target = me->SelectNearestPlayer(30.0f))
                            attackTarget = target->GetGUID();
                    
                    if (Creature* thorim = ObjectAccessor::GetCreature(*me, _instance->GetData64(BOSS_THORIM)))
                        thorim->AI()->SetGUID(attackTarget, ACTION_PREPHASE_ADDS_DIED);
                    _instance->HandleGameObject(_instance->GetData64(GO_THORIM_LIGHTNING_FIELD), false); // Close the entrance door.
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (_instance && _instance->GetBossState(BOSS_THORIM) == DONE)
                    return;

                _events.Update(diff);
                // MoveInLineOfSight does not seem to work here, so...
                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CHECK_PLAYER_IN_RANGE:
                            if (!_gotActivated)
                            {
                                Player* player = 0;
                                Trinity::AnyPlayerInObjectRangeCheck u_check(me, 50.0f, true);
                                Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, player, u_check);
                                me->VisitNearbyObject(50.0f, searcher);
                                if (player)
                                    if (!player->isGameMaster())
                                    {
                                        for (uint8 i = 0; i < 6; i++)   // Spawn Pre-Phase Adds
                                            me->SummonCreature(preAddLocations[i].entry, preAddLocations[i].pos, TEMPSUMMON_CORPSE_DESPAWN);

                                        if (Creature* thorim = me->GetCreature(*me, _instance->GetData64(BOSS_THORIM)))
                                            thorim->AI()->DoAction(ACTION_UPDATE_PHASE);

                                        _gotActivated = true;
                                        _events.ScheduleEvent(EVENT_CHECK_WIPE, 3*IN_MILLISECONDS);
                                    }
                                if (!_gotActivated)
                                    _events.ScheduleEvent(EVENT_CHECK_PLAYER_IN_RANGE, 1*IN_MILLISECONDS);
                            }
                            break;
                        case EVENT_CHECK_WIPE:
                            {
                                Player* player = NULL;
                                Trinity::AnyPlayerInObjectRangeCheck u_check(me, 50.0f, true);
                                Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, player, u_check);
                                me->VisitNearbyObject(50.0f, searcher);
                                if (player)
                                    _events.ScheduleEvent(EVENT_CHECK_WIPE, 3*IN_MILLISECONDS);
                                // if we wiped
                                else
                                {
                                    if (Creature* thorim = me->GetCreature(*me, _instance->GetData64(BOSS_THORIM)))
                                        thorim->AI()->DoAction(ACTION_BERSERK);

                                    _gotActivated = false;
                                    // despawn pre-arena adds
                                    std::list<Creature*> spawnList;
                                    for (uint8 i = 0; i < 6; i++)
                                        me->GetCreatureListWithEntryInGrid(spawnList, preAddLocations[i].entry, 100.0f);

                                    if (!spawnList.empty())
                                        for (std::list<Creature*>::iterator itr = spawnList.begin(); itr != spawnList.end(); itr++)
                                            (*itr)->DespawnOrUnsummon();

                                    std::list<Creature*> addList;
                                    me->GetCreatureListWithEntryInGrid(addList, NPC_IRON_RING_GUARD, 200.0f);
                                    me->GetCreatureListWithEntryInGrid(addList, NPC_DARK_RUNE_ACOLYTE_TUNNEL, 200.0f);
                                    me->GetCreatureListWithEntryInGrid(addList, NPC_IRON_HONOR_GUARD, 200.0f);

                                    if (!addList.empty())
                                        for (std::list<Creature*>::iterator itr = addList.begin(); itr != addList.end(); itr++)
                                            (*itr)->RemoveAurasDueToSpell(SPELL_BERSERK_PHASE_1);

                                    if (Creature* colossus = me->FindNearestCreature(NPC_RUNIC_COLOSSUS, 200.0f))
                                        colossus->AI()->Reset();

                                    if (Creature* giant = me->FindNearestCreature(NPC_RUNE_GIANT, 200.0f))
                                        giant->AI()->Reset();
                                }
                                break;
                            }
                        default:
                            break;
                    }
                }
            }

            private:
                bool _gotActivated;
                EventMap _events;
                InstanceScript* _instance;
                SummonList _summons;
        };

        CreatureAI* GetAI(Creature* c) const
        {
            return new npc_thorim_controllerAI(c);
        }
};

const uint32 ArenaAddEntries[]                  = { NPC_DARK_RUNE_CHAMPION, NPC_DARK_RUNE_COMMONER, NPC_DARK_RUNE_EVOKER, NPC_DARK_RUNE_WARBRINGER, 
                                                    NPC_IRON_RING_GUARD, NPC_IRON_HONOR_GUARD, NPC_DARK_RUNE_ACOLYTE_ARENA, NPC_DARK_RUNE_ACOLYTE_TUNNEL };

class boss_thorim : public CreatureScript
{
    public:
        boss_thorim() : CreatureScript("boss_thorim") {}

        struct boss_thorimAI : public BossAI
        {
            boss_thorimAI(Creature* creature) : BossAI(creature, BOSS_THORIM)
            {
                _gotAddsWiped = false;
                _gotEncounterFinished = false;
                _homePosition = creature->GetHomePosition();
            }

            void Reset()
            {
                _Reset();
                _gotEncounterFinished = _gotEncounterFinished || (instance && instance->GetBossState(BOSS_THORIM) == DONE);
                if (_gotEncounterFinished) // May be called during fight if Thorim gets outfight... hm, should _not_ happen regularly
                {
                    me->setFaction(FACTION_FRIENDLY);
                    return;
                }

                if (_gotAddsWiped)
                    Talk(SAY_WIPE);

                me->SetReactState(REACT_PASSIVE);

                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);

                _phase = PHASE_IDLE;
                _gotAddsWiped = false;
                _hardMode = false;
                _gotBerserkedAndOrbSummoned = false;
                _summonChampion = false;
                _checkTargetTimer = 7*IN_MILLISECONDS;
                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_THORIM_CTRL)))
                    ctrl->AI()->Reset();

                // Respawn Mini Bosses
                for (uint8 i = DATA_RUNIC_COLOSSUS; i <= DATA_RUNE_GIANT; i++)  // TODO: Check if we can move this, it's a little bit crazy.
                    if (Creature* MiniBoss = ObjectAccessor::GetCreature(*me, instance->GetData64(i)))
                        MiniBoss->Respawn(true);
                
                if (GameObject* go = me->FindNearestGameObject(GO_LEVER, 500.0f))
                    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                instance->HandleGameObject(instance->GetData64(GO_THORIM_LIGHTNING_FIELD), true); // Open the entrance door if the raid got past the first adds, since in this case, it will not be performed by the controller bunny.
            }

            void KilledUnit(Unit* /*victim*/)
            {
                if (!urand(0,5))
                    Talk(SAY_SLAY);
            }

            void EncounterPostProgress()
            {
                if (_gotEncounterFinished)  // lock, function should not be called twice
                    return;

                _gotEncounterFinished = true;
                Talk(SAY_DEATH);
                me->setFaction(FACTION_FRIENDLY);
                me->DespawnOrUnsummon(7*IN_MILLISECONDS);
                me->RemoveAllAuras();
                me->RemoveAllAttackers();
                me->AttackStop();
                me->CombatStop(true);

                if (Creature* ctrl = ObjectAccessor::GetCreature(*me, instance->GetData64(NPC_THORIM_CTRL)))
                    ctrl->DespawnOrUnsummon();

                // Kill credit
                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 64985);
                // Lose Your Illusion
                if (_hardMode)
                {
                    instance->DoCompleteAchievement(ACHIEVEMENT_LOSE_ILLUSION);
                    me->SummonGameObject(RAID_MODE(CACHE_OF_STORMS_HARDMODE_10, CACHE_OF_STORMS_HARDMODE_25), 2134.58f, -286.908f, 419.495f, 1.55988f, 0.0f, 0.0f, 1.0f, 1.0f, WEEK);
                }
                else
                {
                    if (GameObject* go = me->SummonGameObject(RAID_MODE(CACHE_OF_STORMS_10, CACHE_OF_STORMS_25), 2134.58f, -286.908f, 419.495f, 1.55988f, 0, 0, 1, 1, WEEK))
                        go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                }

                _JustDied();
            }

            void EnterCombat(Unit* who)
            {
                _EnterCombat();
                Talk(SAY_AGGRO_1);

                // Spawn Thunder Orbs
                for (uint8 n = 0; n < 7; n++)
                    if (Creature* thunderOrb = me->SummonCreature(NPC_THUNDER_ORB, PosOrbs[n], TEMPSUMMON_CORPSE_DESPAWN))
                    {
                        thunderOrb->SetDisplayId(thunderOrb->GetCreatureTemplate()->Modelid2);
                        thunderOrb->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }
                
                _encounterTime = 0;
                _phase = PHASE_ARENA_ADDS;
                events.SetPhase(PHASE_ARENA_ADDS);
                DoCast(me, SPELL_SHEAT_OF_LIGHTNING);
                events.ScheduleEvent(EVENT_STORMHAMMER, 40*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);
                events.ScheduleEvent(EVENT_CHARGE_ORB, 30*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);
                events.ScheduleEvent(EVENT_SUMMON_WARBRINGER, 25*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);
                events.ScheduleEvent(EVENT_SUMMON_EVOKER, 30*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);
                events.ScheduleEvent(EVENT_SUMMON_COMMONER, 35*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);
                events.ScheduleEvent(EVENT_BERSERK_PHASE_1, 5*MINUTE*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);
                events.ScheduleEvent(EVENT_SAY_AGGRO_2, 10*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);

                if (Creature* runic = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_RUNIC_COLOSSUS)))
                {
                    runic->setActive(true);
                    runic->AI()->DoAction(ACTION_DOSCHEDULE_RUNIC_SMASH);  // Signals runic smash rotation
                }

                if (GameObject* go = me->FindNearestGameObject(GO_LEVER, 500.0f))
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                me->SetFacingToObject(who);
            }

            void EnterEvadeMode()
            {
                if (!_EnterEvadeMode())
                    return;

                me->SetHomePosition(_homePosition);
                me->GetMotionMaster()->MoveTargetedHome();
                Reset();
            }

            void UpdateAI(const uint32 diff)
            {
                if (!UpdateVictim())
                    return;

                if (_phase == PHASE_ARENA_ADDS && me->getVictim() && ArenaAreaCheck(false)(me->getVictim()))
                {
                    me->getVictim()->getHostileRefManager().deleteReference(me);
                    return;
                }

                if (_checkTargetTimer < diff)
                {
                    if (!SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    {
                        EnterEvadeMode();
                        return;
                    }
                    _checkTargetTimer = 7*IN_MILLISECONDS;
                }
                else
                    _checkTargetTimer -= diff;

                // Thorim should be inside the arena during phase 3
                if (_phase == PHASE_ARENA && ArenaAreaCheck(false)(me))
                {
                    EnterEvadeMode();
                    return;
                }

                _encounterTime += diff;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SAY_AGGRO_2:
                            Talk(SAY_AGGRO_2);
                            break;
                        case EVENT_STORMHAMMER:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                                DoCast(target, SPELL_STORMHAMMER, true);
                            events.ScheduleEvent(EVENT_STORMHAMMER, urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS), 0, PHASE_ARENA_ADDS);
                            break;
                        case EVENT_CHARGE_ORB:
                            DoCastAOE(SPELL_CHARGE_ORB);
                            events.ScheduleEvent(EVENT_CHARGE_ORB, urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS), 0, PHASE_ARENA_ADDS);
                            break;
                        case EVENT_SUMMON_WARBRINGER:
                            me->SummonCreature(ArenaAddEntries[3], Pos[rand()%7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS);
                            if (_summonChampion)
                            {
                                me->SummonCreature(ArenaAddEntries[0], Pos[rand()%7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS);
                                _summonChampion = false;
                            }
                            else
                                _summonChampion = true;
                            events.ScheduleEvent(EVENT_SUMMON_WARBRINGER, 20*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);
                            break;
                        case EVENT_SUMMON_EVOKER:
                            me->SummonCreature(ArenaAddEntries[2], Pos[rand() % 7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_SUMMON_EVOKER, urand(23*IN_MILLISECONDS, 27*IN_MILLISECONDS), 0, PHASE_ARENA_ADDS);
                            break;
                        case EVENT_SUMMON_COMMONER:
                            for (uint8 n = 0; n < urand(5, 7); ++n)
                                me->SummonCreature(ArenaAddEntries[1], Pos[rand()%7], TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS);
                            events.ScheduleEvent(EVENT_SUMMON_COMMONER, 30*IN_MILLISECONDS, 0, PHASE_ARENA_ADDS);
                            break;
                        case EVENT_BERSERK_PHASE_1:
                            DoCast(me, SPELL_BERSERK_PHASE_1);
                            me->SummonCreature(NPC_LIGHTNING_ORB, 2192.0f, -263.0f, 414.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 30*IN_MILLISECONDS);
                            //DoCast(me, SPELL_SUMMON_LIGHTNING_ORB, true);
                            Talk(SAY_BERSERK);
                            break;
                        // Phase 3 stuff
                        case EVENT_UNBALANCING_STRIKE:
                            DoCastVictim(SPELL_UNBALANCING_STRIKE);
                            events.ScheduleEvent(EVENT_UNBALANCING_STRIKE, 26*IN_MILLISECONDS, 0, PHASE_ARENA);
                            break;
                        case EVENT_CHAIN_LIGHTNING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_CHAIN_LIGHTNING);
                            events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, urand(7*IN_MILLISECONDS, 15*IN_MILLISECONDS), 0, PHASE_ARENA);
                            break;
                        case EVENT_TRANSFER_ENERGY:
                            if (Creature* source = me->SummonCreature(NPC_THORIM_COMBAT_TRIGGER, PosCharge[urand(0, 6)], TEMPSUMMON_TIMED_DESPAWN, 9*IN_MILLISECONDS))
                                source->CastSpell(source, SPELL_LIGHTNING_PILLAR, true);
                            events.ScheduleEvent(EVENT_RELEASE_LIGHTNING_CHARGE, 8*IN_MILLISECONDS, 0, PHASE_ARENA);
                            break;
                        case EVENT_RELEASE_LIGHTNING_CHARGE:
                            if (Creature* source = me->FindNearestCreature(NPC_THORIM_COMBAT_TRIGGER, 100.0f))
                                DoCast(source, SPELL_LIGHTNING_RELEASE);
                            DoCast(me, SPELL_LIGHTNING_CHARGE, true);
                            events.ScheduleEvent(EVENT_TRANSFER_ENERGY, 8*IN_MILLISECONDS, 0, PHASE_ARENA);
                            break;
                        case EVENT_BERSERK_PHASE_2:
                            DoCast(me, SPELL_BERSERK_PHASE_2);
                            Talk(SAY_BERSERK);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_BERSERK:
                        if (!_gotBerserkedAndOrbSummoned)
                        {
                            if (_phase == PHASE_ARENA)
                                return;

                            DoCast(me, SPELL_BERSERK_PHASE_1);
                            me->SummonCreature(NPC_LIGHTNING_ORB, 2192.0f, -263.0f, 414.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 30*IN_MILLISECONDS);
                            Talk(SAY_BERSERK);
                            _gotBerserkedAndOrbSummoned = true;
                        }
                        break;
                    case ACTION_UPDATE_PHASE:
                        _phase = PHASE_PRE_ARENA_ADDS;
                        break;
                    default:
                        break;
                }
            }

            void SetGUID(uint64 /*guid*/, int32 data)
            {
                switch (data)
                {
                    case ACTION_PREPHASE_ADDS_DIED:
                        if (!_gotAddsWiped)
                        {
                            _gotAddsWiped = true;
                            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            events.Reset();
                            DoZoneInCombat();
                        }
                        break;
                    default:
                        break;
                }
            }

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
                if (me->isInCombat())
                    DoZoneInCombat(summon);

                if (summon->GetEntry() == NPC_LIGHTNING_ORB)
                    summon->CastSpell(summon, SPELL_LIGHTNING_DESTRUCTION, true);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {                
                summons.Despawn(summon);
                summon->RemoveCorpse(false);
            }

            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    EncounterPostProgress();
                }

                if (_phase == PHASE_ARENA_ADDS && attacker && instance)
                {
                    Creature* colossus = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_RUNIC_COLOSSUS));
                    Creature* giant = ObjectAccessor::GetCreature(*me, instance->GetData64(DATA_RUNE_GIANT));
                    if (colossus && colossus->isDead() && giant && giant->isDead() && me->IsWithinDistInMap(attacker, 50.0f) && attacker->ToPlayer())
                    {
                        Talk(SAY_JUMPDOWN);
                        _phase = PHASE_ARENA;
                        events.SetPhase(PHASE_ARENA);
                        me->RemoveAurasDueToSpell(SPELL_SHEAT_OF_LIGHTNING);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
                        me->GetMotionMaster()->MoveJump(2134.79f, -263.03f, 419.84f, 10.0f, 20.0f);
                        summons.DespawnEntry(NPC_THUNDER_ORB); // despawn charged orbs
                        events.ScheduleEvent(EVENT_UNBALANCING_STRIKE, 15*IN_MILLISECONDS, 0, PHASE_ARENA);
                        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 20*IN_MILLISECONDS, 0, PHASE_ARENA);
                        events.ScheduleEvent(EVENT_TRANSFER_ENERGY, 20*IN_MILLISECONDS, 0, PHASE_ARENA);
                        events.ScheduleEvent(EVENT_BERSERK_PHASE_2, 5*MINUTE*IN_MILLISECONDS, 0, PHASE_ARENA);
                        // Check for Hard Mode
                        if (_encounterTime <= MAX_HARD_MODE_TIME)
                        {
                            _hardMode = true;
                            // Summon Sif
                            me->SummonCreature(NPC_SIF, 2149.27f, -260.55f, 419.69f, 2.527f, TEMPSUMMON_CORPSE_DESPAWN);
                            // Achievement Siffed
                            if (instance)
                                instance->DoCompleteAchievement(ACHIEVEMENT_SIFFED);
                        }
                        else
                            me->AddAura(SPELL_TOUCH_OF_DOMINION, me);
                    }
                }
            }

            private:
                Phases _phase;
                uint8 _preAddsCount;
                uint32 _encounterTime;
                uint32 _checkTargetTimer;
                bool _gotAddsWiped;
                bool _hardMode;
                bool _gotBerserkedAndOrbSummoned;
                bool _gotEncounterFinished;
                bool _summonChampion;
                Position _homePosition;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<boss_thorimAI>(creature);
        }
};

/************************************************************************/
/* Pre-Phase adds                                                       */
/* Note: The behavior script below will be registered for all pre-phase */
/* indices, so we need some helpers for managing their spells and       */
/* entries.                                                             */
/************************************************************************/
class PrePhaseAddHelper
{
    public:
        PrePhaseAddHelper(Difficulty raidDifficulty)
        {
            if (raidDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || raidDifficulty == RAID_DIFFICULTY_25MAN_HEROIC) // should not be heroic, just for the case
                _is10Man = false;
            else
                _is10Man = true;
        }

        uint8 operator[](uint32 creatureEntry)
        {
            for (uint8 i = 0; i < 6; i++)
                if (PrePhaseAddList[i] == creatureEntry)
                    return i;
            return INDEX_PRE_ADD_NONE;
        }

        uint32 operator()(uint8 myId, Index idx)
        {
            if (myId < INDEX_PRE_ADD_NONE)
            {
                if (idx == INDEX_PRIMARY)
                    return PrePhaseAddSpells_Primary[_is10Man][myId];
                else
                    return PrePhaseAddSpells_Secondary[_is10Man][myId];
            }
            return 0;
        }

    private:    
        bool _is10Man;
};

class npc_thorim_pre_phase_add : public CreatureScript
{
    public:
        npc_thorim_pre_phase_add() : CreatureScript("npc_thorim_pre_phase_add") {}

        struct npc_thorim_pre_phaseAI : public ScriptedAI
        {
            npc_thorim_pre_phaseAI(Creature *pCreature) : ScriptedAI(pCreature), _myHelper(GetDifficulty())
            {
                _instance = pCreature->GetInstanceScript();
                me->SetReactState(REACT_AGGRESSIVE);
                _myIndex = _myHelper[me->GetEntry()];
                _amIHealer = HealerCheck(true)(me);
            }

            void Reset()
            {
                _events.Reset();
                _events.ScheduleEvent(EVENT_CHECK_PLAYER_IN_RANGE, 1*IN_MILLISECONDS);
            }

            void IsSummonedBy(Unit* /*summoner*/)
            {
                Reset();
            }

            void EnterCombat(Unit* /*target*/)
            {
                _events.ScheduleEvent(EVENT_PRIMARY_SKILL, urand(3*IN_MILLISECONDS, 6*IN_MILLISECONDS));
                _events.ScheduleEvent(EVENT_SECONDARY_SKILL, urand (12*IN_MILLISECONDS, 15*IN_MILLISECONDS));
            }

            void JustDied(Unit* /*victim*/)
            {
                if (Creature* pThorim = ObjectAccessor::GetCreature(*me, _instance->GetData64(BOSS_THORIM)))
                    pThorim->AI()->DoAction(ACTION_PREPHASE_ADDS_DIED);
            }

            void AttackStart(Unit* target)
            {
                if (_myIndex == INDEX_DARK_RUNE_ACOLYTE)
                    AttackStartCaster(target, 30.0f);
                else
                    ScriptedAI::AttackStart(target);
            }

            void UpdateAI(uint32 const diff)
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
                        case EVENT_CHECK_PLAYER_IN_RANGE:
                            if (!me->isInCombat())
                            {
                                Player* player = 0;
                                Trinity::AnyPlayerInObjectRangeCheck u_check(me, 70.0f, true);
                                Trinity::PlayerSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, player, u_check);
                                me->VisitNearbyObject(30.0f, searcher);
                                if (player)
                                    if (!player->isGameMaster())
                                        AttackStart(player);

                                _events.ScheduleEvent(EVENT_CHECK_PLAYER_IN_RANGE, 1*IN_MILLISECONDS);
                            }
                            break;
                        case EVENT_PRIMARY_SKILL:
                            if (Unit* target = _amIHealer ? (me->GetHealthPct() > 40? DoSelectLowestHpFriendly(40) : me) : me->getVictim())
                            {
                                DoCast(target, _myHelper(_myIndex, INDEX_PRIMARY));
                                _events.RescheduleEvent(EVENT_PRIMARY_SKILL, urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS));
                            }
                            else
                                _events.RescheduleEvent(EVENT_PRIMARY_SKILL, urand(2*IN_MILLISECONDS, 3*IN_MILLISECONDS));
                            break;
                        case EVENT_SECONDARY_SKILL:
                            if (_amIHealer ? (me->GetHealthPct() > 40? DoSelectLowestHpFriendly(40) : me) : me->getVictim())
                            {
                                DoCast(_myHelper(_myIndex, INDEX_SECONDARY));
                                _events.RescheduleEvent(EVENT_PRIMARY_SKILL, urand(4*IN_MILLISECONDS, 8*IN_MILLISECONDS));
                            }
                            else
                                _events.RescheduleEvent(EVENT_PRIMARY_SKILL, urand(1*IN_MILLISECONDS, 2*IN_MILLISECONDS));
                            break;
                        default:
                            break;
                    }
                }

                if (_myIndex == INDEX_DARK_RUNE_ACOLYTE)
                    DoSpellAttackIfReady(SPELL_HOLY_SMITE);
                else
                    DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                PrePhaseAddHelper _myHelper;
                uint8 _myIndex;
                EventMap _events;
                bool _amIHealer;
        };

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return GetUlduarAI<npc_thorim_pre_phaseAI>(pCreature);
        }
};

/************************************************************************/
/* Adds in arena-phase                                                  */
/* Note: The behavior script below will be registered for all           */
/* arena-phase indices, so we need some helpers for managing their      */
/* spells and entries.                                                  */
/************************************************************************/
class ArenaPhaseAddHelper
{
    public:
        ArenaPhaseAddHelper(Difficulty raidDifficulty)
        {
            if (raidDifficulty == RAID_DIFFICULTY_25MAN_NORMAL || raidDifficulty == RAID_DIFFICULTY_25MAN_HEROIC) // should not be heroic, just for the case
                _is10Man = false;
            else
                _is10Man = true;
        }

        uint8 operator[](uint32 creatureEntry)
        {
            for (uint8 i = 0; i < 8; i++)
                if (ArenaAddEntries[i] == creatureEntry)
                    return i;
            return INDEX_ARENA_ADD_NONE;
        }

        uint32 operator()(uint8 myId, Index idx)
        {
            if (myId < INDEX_ARENA_ADD_NONE)
            {
                if (idx == INDEX_PRIMARY)
                    return ArenaAddSpells_Primary[_is10Man][myId];
                else
                    return ArenaAddSpells_Secondary[_is10Man][myId];
            }
            return 0;
        }

    private:
        bool _is10Man;
};

class npc_thorim_arena_phase_add : public CreatureScript
{
    public:
        npc_thorim_arena_phase_add() : CreatureScript("npc_thorim_arena_phase_add") {}

        struct npc_thorim_arena_phaseAI : public ScriptedAI
        {
            npc_thorim_arena_phaseAI(Creature* creature) : ScriptedAI(creature), _myHelper(GetDifficulty())
            {
                _instance = creature->GetInstanceScript();
                _myIndex = _myHelper[me->GetEntry()];
                _isInArena = ArenaAreaCheck(false)(me);
                _amIhealer = HealerCheck(true)(me);
            }

            bool isOnSameSide(const Unit* who)
            {
                return (_isInArena == ArenaAreaCheck(false)(who));
            }

            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (!isOnSameSide(attacker))
                    damage = 0;
            }

            void Reset()
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                _events.ScheduleEvent(EVENT_PRIMARY_SKILL, urand(3*IN_MILLISECONDS, 6*IN_MILLISECONDS));
                _events.ScheduleEvent(EVENT_SECONDARY_SKILL, urand (7*IN_MILLISECONDS, 9*IN_MILLISECONDS));
                if (_myIndex == INDEX_DARK_RUNE_CHAMPION)
                    _events.ScheduleEvent(EVENT_ADD_CHARGE, 8*IN_MILLISECONDS);
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (_myIndex == INDEX_DARK_RUNE_WARBRINGER)
                    DoCast(me, SPELL_AURA_OF_CELERITY);
            }

            // this should only happen if theres no alive player in the arena -> summon orb
            // might be called by mind control release or controllers death
            void EnterEvadeMode()
            {
                if (Creature* thorim = me->GetCreature(*me, _instance ? _instance->GetData64(BOSS_THORIM) : 0))
                    thorim->AI()->DoAction(ACTION_BERSERK);
                _EnterEvadeMode();
                me->GetMotionMaster()->MoveTargetedHome();
                Reset();
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (me->getVictim() && !isOnSameSide(me->getVictim()))
                {
                    me->getVictim()->getHostileRefManager().deleteReference(me);
                    return;
                }

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_PRIMARY_SKILL:
                            if (Unit* target = _amIhealer ? (me->GetHealthPct() > 40 ? DoSelectLowestHpFriendly(40) : me) : me->getVictim())
                            {
                                if (_myIndex == INDEX_DARK_RUNE_EVOKER)  // Specialize
                                    DoCast(target, SPELL_RUNIC_MENDING);
                                else
                                    DoCast(target, _myHelper(_myIndex, INDEX_PRIMARY));

                                _events.RescheduleEvent(EVENT_PRIMARY_SKILL, urand(3*IN_MILLISECONDS, 6*IN_MILLISECONDS));
                            }
                            else
                                _events.RescheduleEvent(EVENT_PRIMARY_SKILL, urand(1*IN_MILLISECONDS, 2*IN_MILLISECONDS));
                            break;
                        case EVENT_SECONDARY_SKILL:
                            if (Unit* target = _amIhealer ? (me->GetHealthPct() > 40 ? DoSelectLowestHpFriendly(40) : me) : me->getVictim())
                            {
                                if (uint32 spellID = _myHelper(_myIndex, INDEX_SECONDARY))
                                    DoCast(target, spellID);
                                _events.RescheduleEvent(EVENT_SECONDARY_SKILL, urand(12*IN_MILLISECONDS, 16*IN_MILLISECONDS));
                            }
                            else
                                _events.RescheduleEvent(EVENT_SECONDARY_SKILL, urand(2*IN_MILLISECONDS, 4*IN_MILLISECONDS));
                            break;
                        case EVENT_ADD_CHARGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                                DoCast(target, SPELL_CHARGE);
                            _events.ScheduleEvent(EVENT_ADD_CHARGE, 12*IN_MILLISECONDS);
                            break;
                        default:
                            break;
                    }
                }

                if (_myIndex == INDEX_ARENA_DARK_RUNE_ACOLYTE)
                    DoSpellAttackIfReady(SPELL_HOLY_SMITE);
                else
                    DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* _instance;
            uint8 _myIndex;
            EventMap _events;
            ArenaPhaseAddHelper _myHelper;
            bool _isInArena;
            bool _amIhealer;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<npc_thorim_arena_phaseAI>(creature);
        }
};

class npc_runic_colossus : public CreatureScript
{
    public:
        npc_runic_colossus() : CreatureScript("npc_runic_colossus") {}

        struct npc_runic_colossusAI : public ScriptedAI
        {
            npc_runic_colossusAI(Creature* creature) : ScriptedAI(creature), _summons(me)
            {
                _instance = creature->GetInstanceScript();
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            }

            void Reset()
            {
                me->setActive(false);
                me->GetMotionMaster()->MoveTargetedHome();
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveAurasDueToSpell(SPELL_BERSERK_PHASE_1);
                _phase = PHASE_IDLE;
                me->SetReactState(REACT_AGGRESSIVE);
                // Runed Door closed
                if (_instance)
                    _instance->SetData(DATA_RUNIC_DOOR, GO_STATE_READY);

                // Spawn trashes
                _summons.DespawnAll();
                for (uint8 i = 0; i < 6; i++)
                    me->SummonCreature(colossusAddLocations[i].entry, colossusAddLocations[i].pos.GetPositionX(), colossusAddLocations[i].pos.GetPositionY(), colossusAddLocations[i].pos.GetPositionZ(),
                    colossusAddLocations[i].pos.GetOrientation(), TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3*IN_MILLISECONDS);
            }

            void JustSummoned(Creature* summon)
            {
                _summons.Summon(summon);
            }

            void JustDied(Unit* /*victim*/)
            {
                // Runed Door opened
                if (_instance)
                    _instance->SetData(DATA_RUNIC_DOOR, GO_STATE_ACTIVE);
            }

            void DoAction(int32 const action)
            {
                switch (action)
                {
                    case ACTION_DOSCHEDULE_RUNIC_SMASH:
                        _events.ScheduleEvent(EVENT_RUNIC_SMASH, 1*IN_MILLISECONDS, 0, PHASE_RUNIC_SMASH);
                        _phase = PHASE_RUNIC_SMASH;
                        break;
                    default:
                        break;
                }
            }

            void DoRunicSmash(bool side)
            {
                for (uint8 i = 0; i < 9; i++)
                    if (Creature* bunny = me->SummonCreature(NPC_THORIM_GOLEM_RH_BUNNY, side ? 2236.0f : 2219.0f, i * 10 - 380.0f, 412.2f, 0, TEMPSUMMON_TIMED_DESPAWN, 5*IN_MILLISECONDS))
                        bunny->AI()->SetData(1, (i + 1)* 200);

                for (uint8 i = 0; i < 9; i++)
                    if (Creature* bunny = me->SummonCreature(NPC_THORIM_GOLEM_LH_BUNNY, side ? 2246.0f : 2209.0f, i * 10 - 380.0f, 412.2f, 0, TEMPSUMMON_TIMED_DESPAWN, 5*IN_MILLISECONDS))
                        bunny->AI()->SetData(1, (i + 1)* 200);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _phase = PHASE_MELEE;
                _events.ScheduleEvent(EVENT_BARRIER, urand(12*IN_MILLISECONDS, 15*IN_MILLISECONDS), 0, PHASE_MELEE);
                _events.ScheduleEvent(EVENT_SMASH, urand (15*IN_MILLISECONDS, 18*IN_MILLISECONDS), 0, PHASE_MELEE);
                _events.ScheduleEvent(EVENT_ADD_CHARGE, urand (20*IN_MILLISECONDS, 24*IN_MILLISECONDS), 0, PHASE_MELEE);

                me->InterruptNonMeleeSpells(true);
            }

            void UpdateAI(uint32 const diff)
            {
                if (_phase == PHASE_IDLE || (!UpdateVictim() && _phase != PHASE_RUNIC_SMASH))
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BARRIER:
                            Talk(EMOTE_BARRIER);
                            DoCast(me, SPELL_RUNIC_BARRIER);
                            _events.ScheduleEvent(EVENT_BARRIER, urand(35*IN_MILLISECONDS, 45*IN_MILLISECONDS), PHASE_MELEE);
                            return;
                        case EVENT_SMASH:
                            DoCast(me, SPELL_SMASH);
                            _events.ScheduleEvent(EVENT_SMASH, urand(15*IN_MILLISECONDS, 18*IN_MILLISECONDS), PHASE_MELEE);
                            return;
                        case EVENT_ADD_CHARGE:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, -8.0f, true))
                            {
                                DoCast(target, SPELL_RUNIC_CHARGE);
                                _events.RescheduleEvent(EVENT_ADD_CHARGE, 20*IN_MILLISECONDS, 0, PHASE_MELEE);
                            }
                            else
                                _events.RescheduleEvent(EVENT_ADD_CHARGE, 2*IN_MILLISECONDS, 0,PHASE_MELEE);
                            return;
                        case EVENT_RUNIC_SMASH:
                            _side = urand(0, 1);
                            if (_side == 0)
                                DoCast(me, SPELL_RUNIC_SMASH_RIGHT);
                            else
                                DoCast(me, SPELL_RUNIC_SMASH_LEFT);

                            _events.ScheduleEvent(EVENT_SMASH_WAVE, 5.5*IN_MILLISECONDS, 0, PHASE_RUNIC_SMASH);
                            _events.ScheduleEvent(EVENT_RUNIC_SMASH, 8*IN_MILLISECONDS, 0, PHASE_RUNIC_SMASH);
                            return;
                        case EVENT_SMASH_WAVE:
                            if (!UpdateVictim())
                                DoRunicSmash(_side);
                            return;
                        default:
                            return;
                    }
                }
                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                SummonList _summons;
                EventMap _events;
                Phases _phase;
                bool _side;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<npc_runic_colossusAI>(creature);
        }
};

class npc_runic_smash : public CreatureScript
{
    public:
        npc_runic_smash() : CreatureScript("npc_runic_smash") {}

        struct npc_runic_smashAI : public ScriptedAI
        {
            npc_runic_smashAI(Creature* creature) : ScriptedAI(creature)
            {
                SetCombatMovement(false);

                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(me->GetCreatureTemplate()->Modelid2);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            }

            void Reset()
            {
                _explodeTimer = 10*IN_MILLISECONDS;
            }

            void SetData(uint32 /*type*/, uint32 data)
            {
                _explodeTimer = data;
            }

            void UpdateAI(uint32 const diff)
            {
                if (_explodeTimer <= diff)
                {
                    DoCastAOE(SPELL_RUNIC_SMASH, true);
                    _explodeTimer = 10*IN_MILLISECONDS;
                }
                else
                    _explodeTimer -= diff;
            }

            private:
                uint32 _explodeTimer;
        };


        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<npc_runic_smashAI>(creature);
        }
};

#define EMOTE_MIGHT                             "Ancient Rune Giant fortifies nearby allies with runic might!"

class npc_ancient_rune_giant : public CreatureScript
{
    public:
        npc_ancient_rune_giant() : CreatureScript("npc_ancient_rune_giant") {}

        struct npc_ancient_rune_giantAI : public ScriptedAI
        {
            npc_ancient_rune_giantAI(Creature* creature) : ScriptedAI(creature), _summons(me)
            {
                _instance = creature->GetInstanceScript();
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            }

            void Reset()
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                _events.ScheduleEvent(EVENT_STOMP, urand(10*IN_MILLISECONDS, 12*IN_MILLISECONDS));
                _events.ScheduleEvent(EVENT_DETONATION, 25*IN_MILLISECONDS);
                me->RemoveAurasDueToSpell(SPELL_BERSERK_PHASE_1);

                me->GetMotionMaster()->MoveTargetedHome();

                // Stone Door closed
                if (_instance)
                    _instance->SetData(DATA_STONE_DOOR, GO_STATE_READY);

                // Spawn trashes
                _summons.DespawnAll();
                for (uint8 i = 0; i < 5; i++)
                    me->SummonCreature(giantAddLocations[i].entry, giantAddLocations[i].pos.GetPositionX(), giantAddLocations[i].pos.GetPositionY(), giantAddLocations[i].pos.GetPositionZ(),
                    giantAddLocations[i].pos.GetOrientation(),TEMPSUMMON_CORPSE_TIMED_DESPAWN,3*IN_MILLISECONDS);
            }

            void JustSummoned(Creature *summon)
            {
                _summons.Summon(summon);
            }

            void EnterCombat(Unit* /*who*/)
            {
                me->MonsterTextEmote(EMOTE_MIGHT, 0, true);
                me->CastSpell(me, SPELL_RUNIC_FORTIFICATION);
            }

            void JustDied(Unit* /*victim*/)
            {
                // Stone Door opened
                if (_instance)
                    _instance->SetData(DATA_STONE_DOOR, GO_STATE_ACTIVE);
            }

            void UpdateAI(uint32 const diff)
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
                        case EVENT_STOMP:
                            DoCast(me, SPELL_STOMP);
                            _events.ScheduleEvent(EVENT_STOMP, urand(10*IN_MILLISECONDS, 12*IN_MILLISECONDS));
                            return;
                        case EVENT_DETONATION:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            {
                                DoCast(target, SPELL_RUNE_DETONATION);
                                _events.RescheduleEvent(EVENT_DETONATION, urand(10*IN_MILLISECONDS, 12*IN_MILLISECONDS));
                            }
                            else
                                _events.RescheduleEvent(EVENT_DETONATION, urand(2*IN_MILLISECONDS, 3*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
                DoMeleeAttackIfReady();
            }

            private:
                InstanceScript* _instance;
                SummonList _summons;
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<npc_ancient_rune_giantAI>(creature);
        }
};

class npc_sif : public CreatureScript
{
    public:
        npc_sif() : CreatureScript("npc_sif") {}

        struct npc_sifAI : public ScriptedAI
        {
            npc_sifAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
            }

            void Reset()
            {
                _events.ScheduleEvent(EVENT_FROSTBOLT, 2*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 15*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_BLIZZARD, 30*IN_MILLISECONDS);
                _events.ScheduleEvent(EVENT_FROSTNOVA, urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS));
            }

            void UpdateAI(uint32 const diff)
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
                        case EVENT_FROSTBOLT:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
                                DoCast(target, SPELL_FROSTBOLT);
                            _events.ScheduleEvent(EVENT_FROSTBOLT, 4*IN_MILLISECONDS);
                            return;
                        case EVENT_FROSTBOLT_VOLLEY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
                            {
                                DoResetThreat();
                                me->AddThreat(target, std::numeric_limits<float>::max());
                                DoCast(target, SPELL_FROSTBOLT_VOLLEY, true);
                                _events.RescheduleEvent(EVENT_FROSTBOLT_VOLLEY, urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS));
                            }
                            else
                                _events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, urand(1.5*IN_MILLISECONDS, 2*IN_MILLISECONDS));
                            return;
                        case EVENT_BLIZZARD:
                            DoCast(me, SPELL_BLIZZARD, true);
                            _events.ScheduleEvent(EVENT_BLIZZARD, 45*IN_MILLISECONDS);
                            return;
                        case EVENT_FROSTNOVA:
                            DoCastAOE(SPELL_FROSTNOVA, true);
                            _events.ScheduleEvent(EVENT_FROSTNOVA, urand(20*IN_MILLISECONDS, 25*IN_MILLISECONDS));
                            return;
                        default:
                            return;
                    }
                }
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetUlduarAI<npc_sifAI>(creature);
        }
};

class npc_lightning_orb : public CreatureScript
{
    public:
        npc_lightning_orb() : CreatureScript("npc_lightning_orb") { }

        struct npc_lightning_orbAI : public ScriptedAI
        {
            npc_lightning_orbAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset()
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                me->GetMotionMaster()->MovePath(NPC_LIGHTNING_ORB, false);
            }

            void UpdateAI(uint32 const /*diff*/) {}
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_lightning_orbAI(creature);
        }
};

class spell_stormhammer_targeting : public SpellScriptLoader
{
    public:
        spell_stormhammer_targeting() : SpellScriptLoader("spell_stormhammer_targeting") {}

        class spell_stormhammer_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_stormhammer_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                _target = NULL;
                targets.remove_if(ArenaAreaCheck(false));

                if (targets.empty())
                    return;

                _target = Trinity::Containers::SelectRandomContainerElement(targets);
                SetTarget(targets);
            }

            void SetTarget(std::list<WorldObject*>& targets)
            {
                targets.clear();

                if (_target)
                    targets.push_back(_target);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_stormhammer_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_stormhammer_targeting_SpellScript::SetTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_stormhammer_targeting_SpellScript::SetTarget, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            private:
                WorldObject* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_stormhammer_targeting_SpellScript();
        }
};

class spell_thorim_charge_orb_targeting : public SpellScriptLoader
{
    public:
        spell_thorim_charge_orb_targeting() : SpellScriptLoader("spell_thorim_charge_orb_targeting") {}

        class spell_thorim_charge_orb_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thorim_charge_orb_targeting_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                _target = NULL;

                if (targets.empty())
                    return;

                // Charge Orb should be cast always only on 1 orb
                _target = Trinity::Containers::SelectRandomContainerElement(targets);
                SetTarget(targets);
            }

            void SetTarget(std::list<WorldObject*>& targets)
            {
                targets.clear();

                if (_target)
                    targets.push_back(_target);
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thorim_charge_orb_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thorim_charge_orb_targeting_SpellScript::SetTarget, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }

            private:
                WorldObject* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thorim_charge_orb_targeting_SpellScript();
        }
};

class spell_thorim_berserk : public SpellScriptLoader
{
    public:
        spell_thorim_berserk() : SpellScriptLoader("spell_thorim_berserk") {}

        class spell_thorim_berserk_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thorim_berserk_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(BerserkSelector());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thorim_berserk_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
            }

            private:
                WorldObject* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thorim_berserk_SpellScript();
        }
};

class spell_thorim_lightning_destruction : public SpellScriptLoader
{
    public:
        spell_thorim_lightning_destruction() : SpellScriptLoader("spell_thorim_lightning_destruction") {}

        class spell_thorim_lightning_destruction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thorim_lightning_destruction_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(ArenaAreaCheck(true));
                targets.remove_if(PlayerOrPetCheck());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thorim_lightning_destruction_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thorim_lightning_destruction_SpellScript();
        }
};

class spell_thorim_runic_fortification : public SpellScriptLoader
{
    public:
        spell_thorim_runic_fortification() : SpellScriptLoader("spell_thorim_runic_fortification") { }

        class spell_thorim_runic_fortification_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_thorim_runic_fortification_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(NoPlayerOrPetCheck());
            }

            void Register()
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thorim_runic_fortification_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thorim_runic_fortification_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_thorim_runic_fortification_SpellScript::FilterTargets, EFFECT_2, TARGET_UNIT_SRC_AREA_ENTRY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_thorim_runic_fortification_SpellScript();
        }
};

class go_thorim_lever : public GameObjectScript
{
    public:
        go_thorim_lever() : GameObjectScript("go_thorim_lever") {}

        bool OnGossipHello(Player* /*pPlayer*/, GameObject* pGo)
        {
            if (GameObject* door = pGo->FindNearestGameObject(GO_DARK_IRON_PORTCULLIS, 15.f))
            {
                door->UseDoorOrButton();
                pGo->UseDoorOrButton();
                return true;
            }
            return false;
        }
};

void AddSC_boss_thorim()
{
    new boss_thorim();
    new npc_thorim_controller();
    new npc_thorim_pre_phase_add();
    new npc_thorim_arena_phase_add();
    new npc_runic_colossus();
    new npc_runic_smash();
    new npc_ancient_rune_giant();
    new npc_sif();
    new npc_lightning_orb();

    new spell_stormhammer_targeting();
    new spell_thorim_berserk();
    new spell_thorim_charge_orb_targeting();
    new spell_thorim_lightning_destruction();
    new spell_thorim_runic_fortification();

    new go_thorim_lever();
}
