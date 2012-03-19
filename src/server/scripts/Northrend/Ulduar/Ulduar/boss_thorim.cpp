/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ulduar.h"

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
    SPELL_BERSERK_PHASE_2                       = 26662
};

enum Phases
{
    PHASE_NULL,
    PHASE_1,
    PHASE_2
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
    EVENT_RELEASE_ENERGY
};

enum Yells
{
    SAY_AGGRO_1                                 = -1603270,
    SAY_AGGRO_2                                 = -1603271,
    SAY_SPECIAL_1                               = -1603272,
    SAY_SPECIAL_2                               = -1603273,
    SAY_SPECIAL_3                               = -1603274,
    SAY_JUMPDOWN                                = -1603275,
    SAY_SLAY_1                                  = -1603276,
    SAY_SLAY_2                                  = -1603277,
    SAY_BERSERK                                 = -1603278,
    SAY_WIPE                                    = -1603279,
    SAY_DEATH                                   = -1603280,
    SAY_END_NORMAL_1                            = -1603281,
    SAY_END_NORMAL_2                            = -1603282,
    SAY_END_NORMAL_3                            = -1603283,
    SAY_END_HARD_1                              = -1603284,
    SAY_END_HARD_2                              = -1603285,
    SAY_END_HARD_3                              = -1603286,
    SAY_YS_HELP                                 = -1603287
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

#define ACTION_INCREASE_PREADDS_COUNT           1
#define ACTION_RUNIC_SMASH                      2
#define ACTION_BERSERK                          3
#define MAX_HARD_MODE_TIME                      180000 // 3 Minutes

// Achievements
#define ACHIEVEMENT_SIFFED                      RAID_MODE(2977, 2978)
#define ACHIEVEMENT_LOSE_ILLUSION               RAID_MODE(3176, 3183)

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
    NPC_SIF                         = 33196,
    NPC_LIGHTNING_ORB               = 33138,
    NPC_POWER_SOURCE                = 34055, // bad id
    NPC_GOLEM_BUNNY                 = 33140  // 33141
};

const uint32 ARENA_PHASE_ADD[]                  = {32876, 32904, 32878, 32877, 32874, 32875, 33110};

#define SPELL_ARENA_PRIMARY(i)                  RAID_MODE(SPELL_ARENA_PRIMARY_N[i],SPELL_ARENA_PRIMARY_H[i])

const uint32 SPELL_ARENA_PRIMARY_N[]            = {35054, 62326, 62327, 62322, 64151, 42724, 62333};
const uint32 SPELL_ARENA_PRIMARY_H[]            = {35054, 62326, 62445, 62322, 64151, 42724, 62441};
#define SPELL_ARENA_SECONDARY(i)                RAID_MODE(SPELL_ARENA_SECONDARY_N[i],SPELL_ARENA_SECONDARY_H[i])
const uint32 SPELL_ARENA_SECONDARY_N[]          = {15578, 38313, 62321, 0, 62331, 62332, 62334};
const uint32 SPELL_ARENA_SECONDARY_H[]          = {15578, 38313, 62529, 0, 62418, 62420, 62442};
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


class boss_thorim : public CreatureScript
{
public:
    boss_thorim() : CreatureScript("boss_thorim") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_thorimAI(creature);
    }

    struct boss_thorimAI : public BossAI
    {
        boss_thorimAI(Creature* creature) : BossAI(creature, BOSS_THORIM)
        {
            Wipe = false;
            EncounterFinished = false;
            homePosition = creature->GetHomePosition();
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
        Position homePosition;

        void Reset()
        {
            if (EncounterFinished)
                return;

            if (Wipe)
                DoScriptText(SAY_WIPE, me);

            _Reset();

            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE | UNIT_FLAG_NON_ATTACKABLE);

            phase = PHASE_NULL;
            Wipe = false;
            HardMode = false;
            OrbSummoned = false;
            summonChampion = false;
            _checkTargetTimer = 7000;
            PreAddsCount = 0;

            // Respawn Mini Bosses
            for (uint8 i = DATA_RUNIC_COLOSSUS; i <= DATA_RUNE_GIANT; ++i)
                if (Creature* MiniBoss = me->GetCreature(*me, instance->GetData64(i)))
                    MiniBoss->Respawn(true);

            // Spawn Pre-Phase Adds
            for (uint8 i = 0; i < 6; ++i)
                me->SummonCreature(preAddLocations[i].entry,preAddLocations[i].x, preAddLocations[i].y, preAddLocations[i].z, preAddLocations[i].o,
                TEMPSUMMON_CORPSE_TIMED_DESPAWN, 3000);

            if (GameObject* go = me->FindNearestGameObject(GO_LEVER, 500))
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        }

        void KilledUnit(Unit* /*victim*/)
        {
            if (!(rand()%5))
                DoScriptText(RAND(SAY_SLAY_1, SAY_SLAY_2), me);
        }

        void EncounterIsDone()
        {
            if (EncounterFinished)
                return;

            EncounterFinished = true;
            DoScriptText(SAY_DEATH, me);
            me->setFaction(35);
            me->ForcedDespawn(7000);
            EnterEvadeMode();

            if (instance)
            {
                // Kill credit
                instance->DoUpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_BE_SPELL_TARGET, 64985);
                // Lose Your Illusion
                if (HardMode)
                {
                    instance->DoCompleteAchievement(ACHIEVEMENT_LOSE_ILLUSION);
                    me->SummonGameObject(RAID_MODE(CACHE_OF_STORMS_HARDMODE_10, CACHE_OF_STORMS_HARDMODE_25), 2134.58f, -286.908f, 419.495f, 1.55988f, 0, 0, 1, 1, 604800);
                }
                else
                    me->SummonGameObject(RAID_MODE(CACHE_OF_STORMS_10, CACHE_OF_STORMS_25), 2134.58f, -286.908f, 419.495f, 1.55988f, 0, 0, 1, 1, 604800);
            }

            _JustDied();
        }

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(SAY_AGGRO_1, me);
            _EnterCombat();

            // Spawn Thunder Orbs
            for (uint8 n = 0; n < 7; ++n)
                me->SummonCreature(33378, PosOrbs[n], TEMPSUMMON_CORPSE_DESPAWN);

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

            if (Creature* runic = me->GetCreature(*me, instance->GetData64(DATA_RUNIC_COLOSSUS)))
            {
                runic->setActive(true);
                runic->AI()->DoAction(ACTION_RUNIC_SMASH);
            }

            if (GameObject* go = me->FindNearestGameObject(GO_LEVER, 500.0f))
                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
        }

        void EnterEvadeMode()
        {
            if (!_EnterEvadeMode())
                return;

            me->SetHomePosition(homePosition);
            me->GetMotionMaster()->MoveTargetedHome();
            Reset();
        }

        void UpdateAI(uint32 const diff)
        {
            if (!UpdateVictim())
                return;

            if (phase == PHASE_2 && me->getVictim() && !IN_ARENA(me->getVictim()))
            {
                me->getVictim()->getHostileRefManager().deleteReference(me);
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

            // still needed?
            if (phase == PHASE_2 && !IN_ARENA(me))
            {
                EnterEvadeMode();
                return;
            }

            events.Update(diff);
            _DoAggroPulse(diff);
            EncounterTime += diff;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (phase == PHASE_1)
            {
                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SAY_AGGRO_2:
                            DoScriptText(SAY_AGGRO_2, me);
                            break;
                        case EVENT_STORMHAMMER:
                            DoCast(SPELL_STORMHAMMER);
                            events.ScheduleEvent(EVENT_STORMHAMMER, urand(15, 20) *IN_MILLISECONDS, 0, PHASE_1);
                            break;
                        case EVENT_CHARGE_ORB:
                            DoCastAOE(SPELL_CHARGE_ORB);
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
                            DoScriptText(SAY_BERSERK, me);
                            break;
                    }
                }
            }
            else
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
                                DoCast(source, SPELL_LIGHTNING_RELEASE);
                            DoCast(me, SPELL_LIGHTNING_CHARGE, true);
                            events.ScheduleEvent(EVENT_TRANSFER_ENERGY, 8000, 0, PHASE_2);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK_PHASE_2);
                            DoScriptText(SAY_BERSERK, me);
                            break;
                    }
                }
            }

            DoMeleeAttackIfReady();
        }

        void DoAction(int32 const action)
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
            }

            if (PreAddsCount >= 6 && !Wipe)
            {
                // Event starts
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                events.Reset();
                DoZoneInCombat();
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

        void DamageTaken(Unit* attacker, uint32 &damage)
        {
            if (damage >= me->GetHealth())
            {
                damage = 0;
                EncounterIsDone();
            }

            if (phase == PHASE_1 && attacker && instance)
            {
                Creature* colossus = me->GetCreature(*me, instance->GetData64(DATA_RUNIC_COLOSSUS));
                Creature* giant = me->GetCreature(*me, instance->GetData64(DATA_RUNE_GIANT));
                if (colossus && colossus->isDead() && giant && giant->isDead() && me->IsWithinDistInMap(attacker, 10.0f) && attacker->ToPlayer())
                {
                    DoScriptText(SAY_JUMPDOWN, me);
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
                    if (EncounterTime <= MAX_HARD_MODE_TIME)
                    {
                        HardMode = true;
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
    };
};


class npc_thorim_pre_phase : public CreatureScript
{
public:
    npc_thorim_pre_phase() : CreatureScript("npc_thorim_pre_phase") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_thorim_pre_phaseAI (pCreature);
    }

    struct npc_thorim_pre_phaseAI : public ScriptedAI
    {
        npc_thorim_pre_phaseAI(Creature *pCreature) : ScriptedAI(pCreature)
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

        void Reset()
        {
            PrimaryTimer = urand(3000, 6000);
            SecondaryTimer = urand (12000, 15000);
        }

        void JustDied(Unit* /*victim*/)
        {
            if (Creature* pThorim = me->GetCreature(*me, pInstance->GetData64(BOSS_THORIM)))
                pThorim->AI()->DoAction(ACTION_INCREASE_PREADDS_COUNT);
        }

        void UpdateAI(uint32 const diff)
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
                    target = me->getVictim();
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
                    target = me->getVictim();
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

class npc_thorim_arena_phase : public CreatureScript
{
    public:
        npc_thorim_arena_phase() : CreatureScript("npc_thorim_arena_phase") { }

        struct npc_thorim_arena_phaseAI : public ScriptedAI
        {
            npc_thorim_arena_phaseAI(Creature* creature) : ScriptedAI(creature)
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

            void DamageTaken(Unit* attacker, uint32 &damage)
            {
                if (!isOnSameSide(attacker))
                    damage = 0;
            }

            void Reset()
            {
                _PrimaryTimer = urand(3000, 6000);
                _SecondaryTimer = urand (7000, 9000);
                _ChargeTimer = 8000;
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (_id == DARK_RUNE_WARBRINGER)
                    DoCast(me, SPELL_AURA_OF_CELERITY);
            }

            // this should only happen if theres no alive player in the arena -> summon orb
            // might be called by mind control release or controllers death?
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
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (me->getVictim() && !isOnSameSide(me->getVictim()))
                {
                    me->getVictim()->getHostileRefManager().deleteReference(me);
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
                        target = me->getVictim();

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
                        target = me->getVictim();

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

                if (_id == DARK_RUNE_ACOLYTE)
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
            return new npc_thorim_arena_phaseAI(creature);
        }
};

class npc_runic_colossus : public CreatureScript
{
    public:
        npc_runic_colossus() : CreatureScript("npc_runic_colossus") { }

        struct npc_runic_colossusAI : public ScriptedAI
        {
            npc_runic_colossusAI(Creature* creature) : ScriptedAI(creature), summons(me)
            {
                instance = creature->GetInstanceScript();
                SetImmuneToPushPullEffects(true);
            }

            void Reset()
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

            void JustSummoned(Creature* summon)
            {
                summons.Summon(summon);
            }

            void JustDied(Unit* /*victim*/)
            {
                // Runed Door opened
                if (instance)
                    instance->SetData(DATA_RUNIC_DOOR, GO_STATE_ACTIVE);
            }

            void DoAction(int32 const action)
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

            void EnterCombat(Unit* /*who*/)
            {
                RunicSmashPhase = 0;
                me->InterruptNonMeleeSpells(true);
            }

            void UpdateAI(uint32 const diff)
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
                    me->MonsterTextEmote(EMOTE_BARRIER, 0, true);
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
            return new npc_runic_colossusAI(creature);
        }
};

class npc_runic_smash : public CreatureScript
{
    public:
        npc_runic_smash() : CreatureScript("npc_runic_smash") { }

        struct npc_runic_smashAI : public Scripted_NoMovementAI
        {
            npc_runic_smashAI(Creature* creature) : Scripted_NoMovementAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(16925);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                ExplodeTimer = 10000;
            }

            void SetData(uint32 /*type*/, uint32 data)
            {
                ExplodeTimer = data;
            }

            void UpdateAI(uint32 const diff)
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
            return new npc_runic_smashAI(creature);
        }
};

class npc_ancient_rune_giant : public CreatureScript
{
public:
    npc_ancient_rune_giant() : CreatureScript("npc_ancient_rune_giant") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_ancient_rune_giantAI(creature);
    }

    struct npc_ancient_rune_giantAI : public ScriptedAI
    {
        npc_ancient_rune_giantAI(Creature* creature) : ScriptedAI(creature), summons(me)
        {
            instance = creature->GetInstanceScript();
            SetImmuneToPushPullEffects(true);
        }

        InstanceScript* instance;
        SummonList summons;

        uint32 StompTimer;
        uint32 DetonationTimer;

        void Reset()
        {
            StompTimer = urand(10000, 12000);
            DetonationTimer = 25000;

            me->GetMotionMaster()->MoveTargetedHome();

            // Stone Door closed
            if (instance)
                instance->SetData(DATA_STONE_DOOR, GO_STATE_READY);

            // Spawn trashes
            summons.DespawnAll();
            for (uint8 i = 0; i < 5; i++)
                me->SummonCreature(giantAddLocations[i].entry,giantAddLocations[i].x,giantAddLocations[i].y,giantAddLocations[i].z,giantAddLocations[i].o,TEMPSUMMON_CORPSE_TIMED_DESPAWN,3000);
        }

        void JustSummoned(Creature *summon)
        {
            summons.Summon(summon);
        }

        void EnterCombat(Unit* /*who*/)
        {
            me->MonsterTextEmote(EMOTE_MIGHT, 0, true);
            DoCast(me, SPELL_RUNIC_FORTIFICATION, true);
        }

        void JustDied(Unit* /*victim*/)
        {
            // Stone Door opened
            if (instance)
                instance->SetData(DATA_STONE_DOOR, GO_STATE_ACTIVE);
        }

        void UpdateAI(uint32 const diff)
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

class npc_sif : public CreatureScript
{
public:
    npc_sif() : CreatureScript("npc_sif") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_sifAI(creature);
    }

    struct npc_sifAI : public ScriptedAI
    {
        npc_sifAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_PACIFIED);
        }

        uint32 FrostTimer;
        uint32 VolleyTimer;
        uint32 BlizzardTimer;
        uint32 NovaTimer;

        void Reset()
        {
            FrostTimer = 2000;
            VolleyTimer = 15000;
            BlizzardTimer = 30000;
            NovaTimer = urand(20000, 25000);
        }

        void UpdateAI(uint32 const diff)
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

class NotInArenaCheck
{
    public:
        bool operator() (Unit* unit)
        {
            return !IN_ARENA(unit);
        }
};

class spell_stormhammer_targeting : public SpellScriptLoader
{
    public:
        spell_stormhammer_targeting() : SpellScriptLoader("spell_stormhammer_targeting") { }

        class spell_stormhammer_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_stormhammer_targeting_SpellScript);

            void FilterTargets(std::list<Unit*>& unitList)
            {
                _target = NULL;
                unitList.remove_if(NotInArenaCheck());

                if (unitList.empty())
                    return;

                std::list<Unit*>::iterator itr = unitList.begin();
                std::advance(itr, urand(0, unitList.size() - 1));
                _target = *itr;
                unitList.clear();
                unitList.push_back(_target);
            }

            void SetTarget(std::list<Unit*>& unitList)
            {
                unitList.clear();

                if (_target)
                    unitList.push_back(_target);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_stormhammer_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_stormhammer_targeting_SpellScript::SetTarget, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
                OnUnitTargetSelect += SpellUnitTargetFn(spell_stormhammer_targeting_SpellScript::SetTarget, EFFECT_2, TARGET_UNIT_SRC_AREA_ENEMY);
            }

            Unit* _target;
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_stormhammer_targeting_SpellScript();
        }
};

class achievement_who_needs_bloodlust : public AchievementCriteriaScript
{
    public:
        achievement_who_needs_bloodlust() : AchievementCriteriaScript("achievement_who_needs_bloodlust")
        {
        }

        bool OnCheck(Player* player, Unit* /*target*/)
        {
            if (!player)
                return false;

            if (player->HasAura(SPELL_AURA_OF_CELERITY))
                return true;

            return false;
        }
};

/*
-- Thorim
UPDATE `creature_template` SET `speed_walk` = 1.66667, `mechanic_immune_mask` = 650854239, `flags_extra` = 1, `ScriptName` = 'boss_thorim' WHERE `entry` = 32865;
UPDATE `creature_template` SET `speed_walk` = 1.66667, `baseattacktime` = 1500, `equipment_id` = 1844, `mechanic_immune_mask` = 650854239 WHERE `entry` = 33147;
DELETE FROM `creature` WHERE `id`=32865;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`) VALUES
(32865, 603, 3, 1, 28977, 0, 2134.967, -298.962, 438.331, 1.57, 604800, 0, 0, 4183500, 425800, 0, 1);
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62042;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
('62042','62470','1','Thorim: Deafening Thunder');

-- Charge Orb
DELETE FROM conditions WHERE SourceEntry = 62016;
INSERT INTO `conditions` VALUES
('13','0','62016','0','18','1','33378','0','0','',NULL);
UPDATE `creature_template` SET `unit_flags` = 33685508 WHERE `entry` = 33378;

-- Gate
DELETE FROM `gameobject_scripts` WHERE `id`=55194;
INSERT INTO `gameobject_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(55194, 0, 11, 34155, 15, '0', 0, 0, 0, 0);
DELETE FROM `gameobject_template` WHERE `entry`=194265;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `ScriptName`, `WDBVerified`) VALUES
('194265','1','295','Lever','','','','35','48','3','0','0','0','0','0','0','0','0','6000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','','0');
UPDATE `gameobject` SET `id` = 194265, `rotation2` = 1, `rotation3` = 0, `spawntimesecs` = 7200, `animprogress` = 100 WHERE `guid` = 55194;

-- Cleanup
DELETE FROM `creature` WHERE `id` IN (32885, 32883, 32908, 32907, 32882, 33110, 32886, 32879, 32892, 33140, 33141, 33378, 32874, 32875)
OR guid IN (136694, 136695, 136666, 136706, 136754, 136653, 136756, 136757, 136725, 136718);

-- Pre adds
UPDATE `creature_template` SET `equipment_id` = 1849, `ScriptName` = 'npc_thorim_pre_phase' WHERE `entry` = 32885;
UPDATE `creature_template` SET `equipment_id` = 1849 WHERE `entry` = 33153;
UPDATE `creature_template` SET `ScriptName` = 'npc_thorim_pre_phase' WHERE `entry` = 32883;
UPDATE `creature_template` SET `equipment_id` = 1847 WHERE `entry` = 33152;
UPDATE `creature_template` SET `equipment_id` = 1850, `ScriptName` = 'npc_thorim_pre_phase' WHERE `entry` = 32908;
UPDATE `creature_template` SET `equipment_id` = 1850 WHERE `entry` = 33151;
UPDATE `creature_template` SET `ScriptName` = 'npc_thorim_pre_phase' WHERE `entry` = 32907;
UPDATE `creature_template` SET `equipment_id` = 1852 WHERE `entry` = 33150;
UPDATE `creature_template` SET `ScriptName` = 'npc_thorim_pre_phase' WHERE `entry` = 32882;
UPDATE `creature_template` SET `ScriptName` = 'npc_thorim_pre_phase' WHERE `entry` = 32886;
UPDATE `creature_template` SET `modelid1` = 16925, `modelid2` = 0 WHERE `entry`IN (33378, 32892);

-- Thorim Mini bosses
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854239, `flags_extra` = 1, `ScriptName` = 'npc_runic_colossus' WHERE `entry` = 32872;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854239, `flags_extra` = 1, `ScriptName` = 'npc_ancient_rune_giant' WHERE `entry` = 32873;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854239, `flags_extra` = 1, `ScriptName` = 'npc_sif' WHERE `entry` = 33196;
UPDATE `creature_template` SET `ScriptName` = 'npc_thorim_arena_phase' WHERE `entry` IN (32876, 32904, 32878, 32877, 32874, 32875, 33110);
DELETE FROM `creature_addon` WHERE `guid`IN (136059, 136816);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
('136059','0','0','0','1','0','40775 0'),
('136816','0','0','0','1','0','40775 0');
*/

void AddSC_boss_thorim()
{
    new boss_thorim();
    new npc_thorim_pre_phase();
    new npc_thorim_arena_phase();
    new npc_runic_colossus();
    new npc_runic_smash();
    new npc_ancient_rune_giant();
    new npc_sif();
    new spell_stormhammer_targeting();
    new achievement_who_needs_bloodlust();
}
