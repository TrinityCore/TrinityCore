/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "Spell.h"
#include "Vehicle.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CreatureTextMgr.h"
#include "MoveSplineInit.h"
#include "firelands.h"

#define QUEST_HEART_FLAME           29307 // Heart of Flame quest.
#define NPC_SMASH                   53266 // Sulfuras Smash main NPC trigger.
#define NPC_PLATFORM_STALKER        53952 // For Dreadflames.
#define MAX_ENGULFING_FLAME_COUNT   19     // Engulfing Flames count.
#define GO_CACHE_OF_THE_FIRELORD    208967 // Loot chest

enum Yells
{
    SAY_AGGRO = 0,
    SAY_DEATH = 1,
    SAY_KILL_1 = 2,
    SAY_KILL_2 = 3,
    SAY_KILL_3 = 4,
    SAY_ENRAGE_TEXT = 5,
    SAY_INTERMISSION2 = 6,
    SAY_INTERMISSION1 = 7,
    SAY_PHASE_2 = 8,
    SAY_PHASE_3 = 9,
    SAY_PURGE = 10,
    SAY_DEATH_H = 11,
    SAY_SULFURAS_SMASH = 12,
    SAY_PHASE_HEROIC_TEXT = 13,
    SAY_ENGULFING_FLAMES_TEXT = 14,

// boss raid announces
    SAY_ENRAGE = 15,
    SAY_SMASH = 16,
    SAY_SPLITTING = 17,
    SAY_SONS = 18,
    SAY_NEW_PHASE = 19,
    SAY_ENGULFING = 20,
    SAY_WORLD = 21,
    SAY_METEOR = 22,
    SAY_HEROIC_PHASE = 23,
    SAY_AID = 24,
};

enum Spells
{
    /*** RAGNAROS ***/

    SPELL_SUBMERGE_SELF             = 100312, // Intro
    SPELL_RAGE_OF_RAGNAROS          = 101110, // Quest check all phases.
    SPELL_MOLTEN_HEART              = 101125, // Quest - when dead, targets player with quest and gives him heart.
    SPELL_BASE_VISUAL               = 98860,  // Base for ragnaros belly-down (fire circle puffy stuff)

    // Phase 1
    SPELL_WRATH_OF_RAGNAROS         = 98263,
    SPELL_HAND_OF_RAGNAROS          = 98237,
    SPELL_MAGMA_TRAP                = 98164,  // triggers 98170 which summons npc (53086).
    SPELL_MAGMA_TRAP_VISUAL         = 98179,
    SPELL_MAGMA_TRAP_ERUPTION       = 98175,
    SPELL_MAGMA_TRAP_VULNERABILITY  = 100238, // Add with AddAura!
    SPELL_BURNING_WOUND             = 99401,  // demands tank rotation - you don't say?!
    SPELL_MAGMA_BLAST               = 98313,  // enrage no range all p1
    SPELL_SULFURAS_SMASH_RAG_SELF   = 98710,  // Visual smash
    SPELL_SULFURAS_SMASH_VISUAL     = 98712,
    SPELL_TARGET_SULFURAS           = 98706,  // summons 53268 for 10 seconds - NOT NEEDED, manual summon @locations.

    // Intermissions
    SPELL_SPLITTING_BLOW_SOUTH      = 98951,
    SPELL_SPLITTING_BLOW_MID        = 98952,
    SPELL_SPLITTING_BLOW_NORTH      = 98953, // 98953 and 98951 - are same visual, trigger 99012 (which triggers 99056 summon Sons periodic).
    SPELL_SUBMERGE                  = 98982,  // in transition phases, w/ lava bolt casts
    SPELL_DISABLE_ANIM              = 16245,  // hack to prevent him getting up from the lava again.
    SPELL_LAVA_BOLTS                = 98981,
    SPELL_SULFURAS_AURA             = 100456, // Warning marker + periodic damage
    SPELL_SOF_MISSILE               = 99050,
    SPELL_SOF_MISSILE_TRIGGER       = 99051,

    // Phase 2
    //SPELL_ENGULFING_FLAMES          = 99171,  // p2 3 w 100185 damage - Requires Visuals 99216 Near / 99217 Middle / 99218 Far
    SPELL_ENGULFING_FLAMES          = 99172,  // on self
    SPELL_VISUAL_ENGULFING          = 99216,
    SPELL_DAMAGE_ENGULFING          = 100185,
    SPELL_WORLD_IN_FLAMES           = 100190, // p2 3 engulfing flames cast 2 sec- heroic
    SPELL_MOLTEN_SEED_VISUAL        = 98520,  // just the visual.
    SPELL_MOLTEN_SEED_MISSILE       = 98495,  // the actual damage of the 98520
    SPELL_MOLTEN_SEED_DAMAGE        = 98498,

    // Phase 3
    SPELL_LIVING_METEOR             = 99268,  // phase 3-99317 spell summon
    SPELL_SUMMON_LIVING_METEOR      = 99317,

    // Heroic
    SPELL_SUPERHEATED               = 100593, // Heroic - stacks spell soft enrage
    SPELL_EMPOWER                   = 100604, // Heroic - very violent spell to check spell 100605 for other effects
    SPELL_DELUGE                    = 100758,
    SPELL_CLOUDBURST                = 100757,
    SPELL_CAST_CLOUDBURST           = 100714,
    SPELL_ENTRAPPING                = 100653,
    SPELL_DREADFLAME                = 100675, // http://www.wowhead.com/spell=100675 ragnaros cast on random target on the ground. it targets mob called dreadflame, hits it and spawns dreadflame spawn, new mob that does the actual work
    SPELL_DREADFLAME_SUMMON         = 100679,
    SPELL_DREADFLAME_DAMAGE         = 100941,
    SPELL_DREADFLAME_VISUAL         = 100691, // or a funky dummy = funky visual 100692
    SPELL_METEOR_OF_FROST           = 100567,
    SPELL_VISUAL_BREATH             = 100478,
    SPELL_PROTECT_SUPERHEAT         = 100503, // protects from Superheated
    SPELL_WATER_VISUAL              = 69657,  // totally wrong but will announce dreadflame end
    SPELL_NATURE                    = 34770,  // totally wrong, but visual for roots
    SPELL_VISUAL_ROOTS              = 96527,

    /*** Creatures & Summons ****/

    // Splitting Blow 53393
    SPELL_SUMMON_SULFURAS           = 99056,  // then summon sons of flame 53140

    // Sulfuras Smash 53268
    SPELL_SULFURAS_SMASH_DAMAGE     = 98708,  // on self when spawned by 98706

    // Lava Wave 53363
    SPELL_LAVA_WAVE                 = 98873,
    SPELL_LAVA_WAVE_SUMMON_FRONT    = 98874,
    SPELL_LAVA_WAVE_SUMMON_RIGHT    = 98875,
    SPELL_LAVA_WAVE_SUMMON_LEFT     = 98876,

    // Engulfing Flames 53485
    SPELL_ENGULFING_FLAMES_DAMAGE   = 100185, // on self

    // Molten Seed 53186
    SPELL_MOLTEN_INFERNO            = 98518, // after 10 secs and spawns molten elemental

    // Living Meteor 53500
    SPELL_IMPACT                    = 99287,  // triggered by distance
    SPELL_COMBUSTIBLE               = 99296,  // + aura knockb to dmg
    SPELL_COMBUSTION                = 100249, // on hit
    SPELL_INCR_RUN_PERIODIC_AURA    = 100278, // triggers periodic 10% speed
    SPELL_INCR_RUN_AURA             = 100277,
    SPELL_LAVALOGGED                = 101088, // near lava wave
    SPELL_FLAMING_FIXATE            = 99849,  //  visual on chased player

    // Son of Flame 53140 p5 6
    SPELL_BURNING_SPEED             = 99414,  // aura speed
    SPELL_SUPERNOVA                 = 99112,  // if reaches hammer
    SPELL_VISUAL_PRESPAWN           = 98983,  // fire beam.
    SPELL_HIT_ME                    = 100446, // dodge, hit chance.

    // Lava Scion 53231 p6 only intermission 2
    SPELL_BLAZING_HEAT              = 100460, // trail - !Needs script!
    SPELL_BLAZING_HEAT_SUMMON       = 99129,
    SPELL_BLAZING_HEAT_VISUAL       = 99128,

    // Molten Elemental 53189 summ by molten inferno p2
    SPELL_ELEMENTAL_FIXATE          = 82850,
    SPELL_MOLTEN_POWER              = 100157, // empower other elementals 6y periodic

    SPELL_BERSERK                   = 47008
};

enum Points
{
    POINT_SIDE = 1,
};

enum Events
{
    // Ragnaros
    EVENT_SULFURAS_SMASH = 1, // P1 - 3 fire pools on the ground - 93824 visual, after 4 secs comes the drop.
    // Npc 53266 is summoned in front where hammer will hit (boss summons npc in one of 5 designated locations), it casts damage spell 98608 @self after 4s (Boss casts 98710 on self after 1.5s),
    // and summons three 53268 npc's, one on each side, which summon the waves and the waves go forward.
    EVENT_SUL_SMASH,
    EVENT_SUL_SMASH_END,
    EVENT_LAVA_WAVE,
    EVENT_WRATH_OF_RAGNAROS,   // P1 - 25p 3 targets, damage, knockback - 98263
    EVENT_HAND_OF_RAGNAROS,    // P1 - damage to all melee, knockback - 98237
    EVENT_MAGMA_TRAP, // P1 - missile, persists till someone detonates it. who does is blown into air, and 80k damage -> whole raid.
    // missile is 98164 (triggers 98170 which summons npc 53086), npc visual is 98179, damage on trigger is 98175, vulnerability is 100238 (add with addaura).
    EVENT_MAGMA_BLAST,         // P1 enrage out of range - 98313

    EVENT_EMPOWER,
    EVENT_DREADFLAME,
    EVENT_SUBMERGE,
    EVENT_SONS_OF_FLAME,
    EVENT_MOLTEN_SEED,
    EVENT_RAGE_OF_RAGNAROS,     // Check items and quest.
    EVENT_ENFULGING_FLAMES,
    EVENT_WORLD_FLAMES1,
    EVENT_WORLD_FLAMES2,
    EVENT_WORLD_FLAMES3,
    EVENT_METEORITE,

    EVENT_SUPERHEATED,
    EVENT_BREATH_OF_FROST,
    EVENT_ENRAGE,               // 18 minutes.

    EVENT_DIE,

    // Sulfuras, Hand of Ragnaros
    EVENT_HEROIC_DANCE,

    // Molten Seed
    EVENT_CHECK_SPELL,

    // Molten Elemental
    EVENT_CHECK_ELEMENTALS_RANGE,

    // Sulfuras Smash
    EVENT_SMASH,

    // Living Meteore
    EVENT_NEW_FOLLOW,
    EVENT_CAST_COMBUSTIBLE,
    EVENT_CHECK_DISTANCE,
    EVENT_CHECK_TARGET,

    // Event Phase Chain
    EVENT_PHASE_ONE,
    EVENT_PHASE_TWO,
    EVENT_PHASE_THREE,
    EVENT_PHASE_FOUR,
    EVENT_INTERMISSION_1,
    EVENT_INTERMISSION_2
};

enum Actions
{
    ACTION_START_DANCE = 1,
};

/*** Engulfing Flames ***/

Position const EngulfingPos[3][MAX_ENGULFING_FLAME_COUNT] =
{
    {
        { 1046.256f, -110.471f, 55.804f, 4.893f },
        { 1053.341f, -7.916f,   55.781f, 6.141f },
        { 1030.295f, -9.514f,   55.803f, 5.601f },
        { 1017.908f, -23.645f,  55.791f, 5.766f },
        { 1009.825f, -40.884f,  55.774f, 5.984f },
        { 1003.884f, -59.484f,  55.765f, 0.018f },
        { 1009.150f, -78.064f,  55.770f, 0.147f },
        { 1019.707f, -95.570f,  55.809f, 0.300f },
        { 1029.262f, -113.527f, 55.802f, 0.756f },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   }
    },
    {
        { 1076.27f, -99.7064f, 55.3409f, 1.51573f },
        { 1074.2f,  -14.966f,  55.789f,  4.663f },
        { 1057.85f, -15.04f,   55.782f,  4.963f },
        { 1040.76f, -23.403f,  55.924f,  5.343f },
        { 1029.4f,  -38.686f,  55.79f,   5.747f },
        { 1025.55f, -57.613f,  55.779f,  6.175f },
        { 1029.92f, -76.6036f, 55.3567f, 0.384757f },
        { 1038.03f, -93.194f,  55.923f,  0.393f },
        { 1058.22f, -99.8895f, 55.3427f, 1.22513f },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   },
        { 0.0f,      0.0f,      0.0f,    0.0f   }
    },
    {
        { 1040.5f,  2.655f,    55.802f, 5.391f },
        { 1030.8f,  -10.481f,  55.802f, 5.635f },
        { 1015.16f, -22.79f,   55.794f, 5.679f },
        { 1002.33f, -38.069f,  55.79f,  5.989f },
        { 999.63f,  -57.194f,  55.797f, 6.228f },
        { 1001.68f, -76.356f,  55.786f, 0.271f },
        { 1012.75f, -93.56f,   55.796f, 0.409f },
        { 1035.38f, -124.228f, 55.803f, 1.361f },
        { 1028.33f, -105.794f, 55.802f, 0.615f },
        { 1025.5f,  2.655f,    55.802f, 5.391f },
        { 1015.8f,  -10.481f,  55.802f, 5.635f },
        { 1000.16f, -22.79f,   55.794f, 5.679f },
        { 987.328f, -38.069f,  55.79f,  5.989f },
        { 984.63f,  -57.194f,  55.797f, 6.228f },
        { 986.682f, -76.356f,  55.786f, 0.271f },
        { 997.749f, -93.56f,   55.796f, 0.409f },
        { 1020.38f, -124.228f, 55.803f, 1.361f },
        { 1013.34f, -105.794f, 55.802f, 0.615f },
        { 0.0f,      0.0f,      0.0f,    0.0f  }
    }
};

/*** Sons of Flame ***/

const Position HammerMiddleSummons[] =
{
    //West Side
    { 1008.976f, -87.395f, 55.452f, 1.030f },
    { 1037.130f, -101.037f, 55.544f, 2.130f },
    { 1057.177f, -103.765f, 55.342f, 2.330f },
    { 1076.355f, -101.017f, 55.342f, 2.677f },
    //East Side
    { 1012.901f, -26.540f, 55.482f, 4.874f },
    { 1037.587f, -13.490f, 55.555f, 4.658f },
    { 1055.858f, -11.348f, 55.346f, 3.927f },
    { 1074.467f, -12.893f, 55.342f, 3.715f }
};

const Position HammerWestSummons[] =
{
    //West Side
    { 999.768f, -69.833f, 55.485f, 5.887f },
    { 1057.177f, -103.765f, 55.342f, 2.330f },
    { 1076.355f, -101.017f, 55.342f, 2.677f },
    //East Side
    { 999.505f, -45.725f, 55.476f, 5.435f },
    { 1012.901f, -26.540f, 55.482f, 4.874f },
    { 1037.587f, -13.490f, 55.555f, 4.658f },
    { 1055.858f, -11.348f, 55.346f, 3.927f },
    { 1074.467f, -12.893f, 55.342f, 3.715f }
};

const Position HammerEastSummons[] =
{
    //West Side
    { 999.768f, -69.833f, 55.485f, 5.887f },
    { 1008.976f, -87.395f, 55.452f, 1.030f },
    { 1037.130f, -101.037f, 55.544f, 2.130f },
    { 1057.177f, -103.765f, 55.342f, 2.330f },
    { 1076.355f, -101.017f, 55.342f, 2.677f },
    //East Side
    { 999.505f, -45.725f, 55.476f, 5.435f },
    { 1055.858f, -11.348f, 55.346f, 3.927f },
    { 1074.467f, -12.893f, 55.342f, 3.715f }
};

/*** Splitting Blow ***/
Position const SummonPositions[3] =
{
    { 1039.649f, -88.337f, 55.781f, 4.18f },  // 1 Bottom
    { 1028.017f, -58.241f, 55.781f, 3.12f },  // 2 Middle for Sulfuras
    { 1039.866f, -28.044f, 55.781f, 2.21f },  // 3 Top
};

/*** Lava Scion ***/
Position const SpawnPos[2] =
{
    { 980.100f, -30.100f, 55.100f, 4.57f },   // spawnpos1
    { 980.100f, -80.100f, 55.100f, 1.42f },   // spawnpos2
};

/*** Heroic Npc's ***/
Position const HeroPos[3] =
{
    { 985.100f, -59.000f, 55.800f, 6.20f },   // Malfurion
    { 990.000f, -78.000f, 55.800f, 0.15f },   // Cenarius
    { 975.000f, -40.000f, 55.800f, 5.40f },   // Hamuul
};

Position const middlePos = { 1077.47f, -57.95f, 52.8f, 3.14f };

uint32 const CreaturesToDespawnOnReset[] =
{
    NPC_LAVA_WAVE,
    NPC_MAGMA_TRAP,
    NPC_LIVING_METEOR
};

/*####################
 # RAGNAROS FIRELANDS #
 ####################*/

class boss_ragnaros_firelands: public CreatureScript
{
    public:
        boss_ragnaros_firelands() : CreatureScript("boss_ragnaros_firelands") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_ragnaros_firelandsAI(creature);
        }

        struct boss_ragnaros_firelandsAI: public BossAI
        {
                boss_ragnaros_firelandsAI(Creature* creature) : BossAI(creature, DATA_RAGNAROS)
                {
                    creature->ApplySpellImmune(0, IMMUNITY_ID, SPELL_LAVALOGGED, true);
                    introDone = false;
                }

                Creature* smash;
                Creature* splitting;
                uint8 sonOfFlameCount;
                bool HeartCheck, introDone, intermission1, intermission1InProgress, intermission2, intermission2InProgress, phase3, inMeleeRange, heroicPhase, died;

                void Reset() override
                {
                    _Reset();

                    if (!me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL))
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);

                    if (!introDone)
                        me->AddAura(SPELL_SUBMERGE_SELF, me);
                    else
                        me->AddAura(SPELL_BASE_VISUAL, me);

                    me->setActive(true);
                    me->SetObjectScale(2.0f);

                    //despawn lava wave & magma trap
                    std::list<Creature*> creaturesToDespawn;
                    for (auto creatureEntry: CreaturesToDespawnOnReset)
                        me->GetCreatureListWithEntryInGridAppend(creaturesToDespawn, creatureEntry, 100.0f);

                    for (auto creature: creaturesToDespawn)
                        creature->DespawnOrUnsummon();

                    intermission1           = false;
                    intermission1InProgress = false;
                    intermission2           = false;
                    intermission2InProgress = false;
                    HeartCheck              = false;
                    phase3                  = false;
                    inMeleeRange            = false;
                    heroicPhase             = false;
                    died                    = false;
                    sonOfFlameCount         = 0;

                    events.ScheduleEvent(EVENT_PHASE_ONE, 100);
                }

                void EnterEvadeMode(EvadeReason /*why*/) override
                {
                    Reset();

                    me->GetMotionMaster()->MoveTargetedHome();
                    me->SetHealth(me->GetMaxHealth());
                    me->AddAura(SPELL_BASE_VISUAL, me);
                    if (me->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE))
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                    if (instance)
                    {
                        instance->SetData(DATA_RAGNAROS, FAIL);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                    }

                    _EnterEvadeMode();
                }

                void MoveInLineOfSight(Unit* who) override
                {
                    if (!introDone && who->IsWithinDistInMap(me, 40.0f))
                    {
                        Talk(SAY_AGGRO);
                        introDone = true;
                        me->AddAura(SPELL_BASE_VISUAL, me);
                        me->SetByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->RemoveAura(SPELL_SUBMERGE_SELF);
                    }
                }

                void KilledUnit(Unit * /*victim*/) override
                {
                    Talk(RAND(SAY_KILL_1, SAY_KILL_2, SAY_KILL_3));
                }

                void JustDied(Unit * /*victim*/) override
                {
                    _JustDied();

                    if (IsHeroic())
                        Talk(SAY_DEATH_H);

                    if (HeartCheck)
                        me->SummonCreature(NPC_HEART_OF_RAGNAROS, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);

                    if (instance)
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove

                    std::list<Creature*> creaturesToDespawn;
                    for (auto creatureEntry: CreaturesToDespawnOnReset)
                        me->GetCreatureListWithEntryInGridAppend(creaturesToDespawn, creatureEntry, 100.0f);

                    for (auto creature: creaturesToDespawn)
                        creature->DespawnOrUnsummon();
                }

                void EnterCombat(Unit* /*who*/) override
                {
                    me->AddAura(SPELL_BASE_VISUAL, me);

                    if (instance)
                    {
                        instance->SetData(DATA_RAGNAROS, IN_PROGRESS);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me); // Add
                    }

                    events.ScheduleEvent(EVENT_ENRAGE, 18 * MINUTE * IN_MILLISECONDS);

                    _EnterCombat();
                }

                void DoAction(int32 const action) override
                {
                    switch (action)
                    {
                        case ACTION_START_DANCE:
                        {
                            me->SetFlag(UNIT_FIELD_FLAGS_2, 0x20);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                            me->SetDisableGravity(true);
                            Movement::MoveSplineInit init(me);
                            init.SetOrientationFixed(true);
                            init.Launch();
                            break;
                        }
                    }
                }

                void JustSummoned(Creature *summon) override
                {
                    summons.Summon(summon);
                    summon->setActive(true);

                    if (me->IsInCombat())
                        summon->AI()->DoZoneInCombat();

                    switch (summon->GetEntry())
                    {
                        case NPC_ENGULFING_FLAMES:
                            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            summon->CastSpell(summon, SPELL_VISUAL_ENGULFING, false);
                            break;

                        case NPC_MOLTEN_SEED:
                            summon->CastSpell(summon, SPELL_MOLTEN_SEED_VISUAL, false);
                            break;

                        case NPC_PLATFORM_STALKER:
                            summon->SetInCombatWithZone();
                            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            if (Creature* ragnaros = me->FindNearestCreature(NPC_RAGNAROS, 40.0f, true))
                                ragnaros->CastSpell(summon, SPELL_DREADFLAME, true);
                            summon->SetReactState(REACT_PASSIVE);
                            break;

                        case NPC_DREADFLAME_SPAWN:
                            summon->SetFlag(UNIT_FIELD_FLAGS,
                                    UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            summon->CastSpell(summon, SPELL_DREADFLAME_SUMMON, false);
                            summon->SetReactState(REACT_PASSIVE);
                            break;

                        case NPC_DREADFLAME:
                            summon->SetFlag(UNIT_FIELD_FLAGS,
                                    UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                            summon->CastSpell(summon, SPELL_DREADFLAME_VISUAL, false);
                            summon->CastSpell(summon, SPELL_DREADFLAME_DAMAGE, false);
                            summon->SetReactState(REACT_PASSIVE);
                            break;

                        case NPC_CENARIUS:
                        case NPC_MALFURION:
                        case NPC_HAMUUL:
                            summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE);
                            break;

                        default:
                            break;
                    }
                }

                void SummonedCreatureDespawn(Creature* summon) override
                {
                    summons.Despawn(summon);

                    switch (summon->GetEntry())
                    {
                        case NPC_SON_OF_FLAME:
                        {
                            if (intermission1InProgress || intermission2InProgress)
                                if (!--sonOfFlameCount)
                                    events.RescheduleEvent(intermission1InProgress ? EVENT_PHASE_TWO: EVENT_PHASE_THREE, 100);
                        }
                    }
                }

                void PrepareTransition()
                {
                    me->RemoveAurasDueToSpell(SPELL_BASE_VISUAL);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    me->GetMotionMaster()->Clear();
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    Talk(SAY_SPLITTING);

                    uint8 randomPos = urand(0, 2);

                    splitting = me->SummonCreature(NPC_SPLITTING_BLOW,
                        SummonPositions[randomPos].GetPositionX(), SummonPositions[randomPos].GetPositionY(),
                        SummonPositions[randomPos].GetPositionZ(), SummonPositions[randomPos].GetOrientation(),
                        TEMPSUMMON_CORPSE_DESPAWN, 1000);

                    sonOfFlameCount = 8;
                    for (uint32 x = 0; x < 8; ++x)
                        if (Creature* sonOfFlame = me->SummonCreature(NPC_SON_OF_FLAME, HammerEastSummons[x], TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 57500))
                            me->CastSpell(sonOfFlame, SPELL_SOF_MISSILE, false);

                    me->SetFacingToObject(splitting);
                    Movement::MoveSplineInit init(me);
                    init.SetOrientationFixed(true);
                    init.Launch();
                    DoCast(me, SPELL_SPLITTING_BLOW_SOUTH + randomPos); // 98951, 98952, 98953
                }

                void UpdateAI(uint32 diff) override
                {
                    if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                        return;

                    if (HealthBelowPct(71) && !intermission1)
                    {
                        Talk(SAY_INTERMISSION1);
                        events.ScheduleEvent(EVENT_INTERMISSION_1, 1000);
                        intermission1 = true;
                        intermission1InProgress = true;
                    }

                    if (HealthBelowPct(41) && !intermission2)
                    {
                        Talk(SAY_INTERMISSION2);
                        events.ScheduleEvent(EVENT_INTERMISSION_2, 1000);
                        intermission2 = true;
                        intermission2InProgress = true;
                    }

                    if (HealthBelowPct(11) && !IsHeroic() && !died)
                    {
                        Talk(SAY_DEATH);

                        me->AttackStop();
                        me->CastStop();
                        me->SetReactState(REACT_PASSIVE);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->RemoveAllAuras();
                        if (instance->GetData(DATA_TEAM) == ALLIANCE)
                        {
                            me->SummonGameObject(GO_CACHE_OF_THE_FIRELORD, 1016.043f, -57.436f, 55.333f, 3.151f, QuaternionData(), 30000);
                        }
                        else
                        {
                            me->SummonGameObject(GO_CACHE_OF_THE_FIRELORD_H, 1016.043f, -57.436f, 55.333f, 3.151f, QuaternionData(), 30000);
                        }


                        if (HeartCheck)
                            me->SummonCreature(NPC_HEART_OF_RAGNAROS, me->GetPositionX(), me->GetPositionY(),
                                    me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);

                        if (instance)
                        {
                            instance->SetData(DATA_RAGNAROS, DONE);
                            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me); // Remove
                        }

                        events.ScheduleEvent(EVENT_DIE, 2000);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_SUBMERGE);
                        died = true;
                    }
                    else if (HealthBelowPct(11) && IsHeroic() && !heroicPhase)
                    {
                        Talk(SAY_PHASE_HEROIC_TEXT);
                        Talk(SAY_HEROIC_PHASE);
                        events.ScheduleEvent(EVENT_PHASE_FOUR, 1000);
                        heroicPhase = true;
                    }

                    events.Update(diff);

                    while (uint32 eventId = events.ExecuteEvent())
                    {
                        switch (eventId)
                        {
                            case EVENT_DIE:
                                me->Kill(me);
                                break;

                            case EVENT_ENRAGE:
                                DoCast(me, SPELL_BERSERK);
                                break;

                                /**** STAGE 1 : By Fire Be Purged! ****/

                            case EVENT_PHASE_ONE:
                                Talk(SAY_PURGE);
                                DoCast(me, SPELL_BURNING_WOUND);
                                events.ScheduleEvent(EVENT_SULFURAS_SMASH, 30000);
                                events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, urand(4500, 6000));
                                events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, 24000);
                                events.ScheduleEvent(EVENT_MAGMA_TRAP, 16000);
                                events.ScheduleEvent(EVENT_MAGMA_BLAST, 5000);
                                events.ScheduleEvent(EVENT_RAGE_OF_RAGNAROS, 2500);
                                break;

                            case EVENT_RAGE_OF_RAGNAROS:
                                if (!IsHeroic()) // Only on normal.
                                {
                                    std::list<HostileReference*> m_threatlist = me->getThreatManager().getThreatList();
                                    for (std::list<HostileReference*>::const_iterator i = m_threatlist.begin();
                                            i != m_threatlist.end(); ++i)
                                    {
                                        if (Unit* unit = ObjectAccessor::GetUnit(*me, (*i)->getUnitGuid()))
                                            if (unit->GetTypeId() == TYPEID_PLAYER)
                                                if (Player* player = unit->ToPlayer())
                                                    if (player->hasQuest(QUEST_HEART_FLAME))
                                                        if (player->GetQuestStatus(QUEST_HEART_FLAME)
                                                                == QUEST_STATUS_INCOMPLETE)
                                                        {
                                                            if (!player->HasAura(SPELL_RAGE_OF_RAGNAROS))
                                                                player->CastSpell(player, SPELL_RAGE_OF_RAGNAROS, true);
                                                            HeartCheck = true;
                                                        }
                                    }
                                }
                                break;

                            case EVENT_SULFURAS_SMASH:
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                                {
                                    Talk(SAY_SULFURAS_SMASH);
                                    me->GetMotionMaster()->Clear();
                                    me->AttackStop();
                                    Position pos;
                                    pos.Relocate(me);
                                    me->MovePosition(pos, 60.0f, me->GetRelativeAngle(target));
                                    pos.m_positionZ = 55.8f;
                                    smash = me->SummonCreature(NPC_SMASH, pos, TEMPSUMMON_CORPSE_DESPAWN, 1000);
                                    events.ScheduleEvent(EVENT_SUL_SMASH, 1500);

                                    events.ScheduleEvent(EVENT_SULFURAS_SMASH, urand(26000, 34000));
                                }
                                break;
                            }
                            case EVENT_SUL_SMASH:
                            {
                                if (!smash)
                                    break;

                                Talk(SAY_SMASH);
                                me->SetFacingToObject(smash);
                                DoCast(me, SPELL_SULFURAS_SMASH_RAG_SELF);

                                events.ScheduleEvent(EVENT_SUL_SMASH_END, 2500);
                                break;
                            }
                            case EVENT_SUL_SMASH_END:
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 80.0f, true))
                                    me->AI()->AttackStart(target);
                                break;
                            }
                            case EVENT_MAGMA_TRAP: // Not on tank!
                            {
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2, 200.0f, true)) // SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me))
                                    me->CastSpell(target, SPELL_MAGMA_TRAP, true);
                                events.ScheduleEvent(EVENT_MAGMA_TRAP, urand(23000, 29000));
                                break;
                            }
                            case EVENT_WRATH_OF_RAGNAROS: // Not on tank!
                            {
                                std::list<Unit*> targets;
                                SelectTargetList(targets, RAID_MODE<int32>(1, 3, 1, 3), SELECT_TARGET_RANDOM, 200.0f, true);
                                if (!targets.empty())
                                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                        DoCast(*itr, SPELL_WRATH_OF_RAGNAROS);
                                events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, urand(27000, 33000));
                                break;
                            }
                            case EVENT_HAND_OF_RAGNAROS:
                                DoCast(me, SPELL_HAND_OF_RAGNAROS);
                                events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, urand(23000, 28000));
                                break;

                            case EVENT_MAGMA_BLAST:
                                if (Unit* target = me->GetVictim())
                                {
                                    if (target->IsWithinDistInMap(me, 1.0f)) // check if tank is in melee range.
                                        inMeleeRange = true;
                                    else // Killing tank softly with his song.
                                    {
                                        inMeleeRange = false;
                                        Talk(SAY_ENRAGE);
                                        DoCast(target, SPELL_MAGMA_BLAST);
                                    }
                                }
                                events.ScheduleEvent(EVENT_MAGMA_BLAST, urand(4000, 5000));
                                break;

                                // ====== INTERMISSION 1 : Minions of Fire! ====== //

                            case EVENT_INTERMISSION_1:
                                me->RemoveAurasDueToSpell(SPELL_BASE_VISUAL);
                                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                me->GetMotionMaster()->Clear();
                                me->AttackStop();
                                me->SetReactState(REACT_PASSIVE);
                                Talk(SAY_SPLITTING);

                                PrepareTransition();

                                events.CancelEvent(EVENT_SULFURAS_SMASH);
                                events.CancelEvent(EVENT_WRATH_OF_RAGNAROS);
                                events.CancelEvent(EVENT_HAND_OF_RAGNAROS);
                                events.CancelEvent(EVENT_MAGMA_TRAP);
                                events.CancelEvent(EVENT_MAGMA_BLAST);
                                events.ScheduleEvent(EVENT_SUBMERGE, 8000);
                                events.ScheduleEvent(EVENT_PHASE_TWO, 45000);
                                break;

                            case EVENT_SUBMERGE:
                                me->AddAura(SPELL_SUBMERGE, me);
                                break;

                                /**** STAGE 2 : Sulfuras Will Be Your End! ****/

                            case EVENT_PHASE_TWO:
                            {
                                Talk(SAY_PHASE_2);
                                Movement::MoveSplineInit init(me);
                                init.SetOrientationFixed(false);
                                init.Launch();
                                me->RemoveAurasDueToSpell(SPELL_DISABLE_ANIM);
                                me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                                me->AddAura(SPELL_BASE_VISUAL, me);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                Talk(SAY_NEW_PHASE);
                                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 80.0f, true))
                                    me->AI()->AttackStart(target);

                                intermission1InProgress = false;

                                if (IsHeroic())
                                {
                                    events.ScheduleEvent(EVENT_SULFURAS_SMASH, 6000);
                                    events.ScheduleEvent(EVENT_WORLD_FLAMES1, 60000); // 30 in p3
                                }
                                else
                                {
                                    events.ScheduleEvent(EVENT_SULFURAS_SMASH, 15500);
                                    events.ScheduleEvent(EVENT_ENFULGING_FLAMES, 30000);
                                }
                                events.ScheduleEvent(EVENT_MOLTEN_SEED, urand(18500, 24000));
                                events.ScheduleEvent(EVENT_MAGMA_BLAST, 5000);
                            }
                                break;

                            case EVENT_MOLTEN_SEED:
                            {
                                std::list<Unit*> targets;
                                SelectTargetList(targets, RAID_MODE<int32>(10, 20, 10, 20), SELECT_TARGET_RANDOM,
                                        200.0f, true);
                                if (!targets.empty())
                                    for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
                                    {
                                        DoCast((*itr), SPELL_MOLTEN_SEED_MISSILE);
                                        me->SummonCreature(NPC_MOLTEN_SEED, (*itr)->GetPositionX(),
                                                (*itr)->GetPositionY(), (*itr)->GetPositionZ(),
                                                (*itr)->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);
                                    }

                                events.ScheduleEvent(EVENT_MOLTEN_SEED, 60000);
                            }
                                break;

                            case EVENT_ENFULGING_FLAMES:
                            {
                                Talk(SAY_ENGULFING);
                                Talk(SAY_ENGULFING_FLAMES_TEXT);
                                DoCast(me, SPELL_ENGULFING_FLAMES);

                                uint8 posRand = urand(0, 2);
                                for (uint32 i = 0; i < MAX_ENGULFING_FLAME_COUNT; ++i)
                                {
                                    if (EngulfingPos[posRand][i].GetPositionX() <= 1.0f)
                                        break;

                                    me->SummonCreature(NPC_ENGULFING_FLAMES, EngulfingPos[posRand][i], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                                }

                                events.ScheduleEvent(EVENT_ENFULGING_FLAMES, 30000);
                                break;
                            }
                            case EVENT_WORLD_FLAMES1:
                            {
                                DoCast(me, SPELL_WORLD_IN_FLAMES);
                                Talk(SAY_WORLD);

                                for (uint32 i = 0; i < MAX_ENGULFING_FLAME_COUNT; ++i)
                                {
                                    if (EngulfingPos[0][i].GetPositionX() <= 1.0f)
                                        break;

                                    me->SummonCreature(NPC_ENGULFING_FLAMES, EngulfingPos[0][i], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                                }

                                events.ScheduleEvent(EVENT_WORLD_FLAMES2, 3500);
                                events.ScheduleEvent(EVENT_WORLD_FLAMES3, 7000);

                                events.ScheduleEvent(EVENT_WORLD_FLAMES1, phase3 ? 30000 : 60000); // 30 in p3
                                break;
                            }
                            case EVENT_WORLD_FLAMES2:
                            {
                                for (uint32 i = 0; i < MAX_ENGULFING_FLAME_COUNT; ++i)
                                {
                                    if (EngulfingPos[1][i].GetPositionX() <= 1.0f)
                                        break;

                                    me->SummonCreature(NPC_ENGULFING_FLAMES, EngulfingPos[1][i], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                                }
                                break;
                            }
                            case EVENT_WORLD_FLAMES3:
                            {
                                for (uint32 i = 0; i < MAX_ENGULFING_FLAME_COUNT; ++i)
                                {
                                    if (EngulfingPos[2][i].GetPositionX() <= 1.0f)
                                        break;

                                    me->SummonCreature(NPC_ENGULFING_FLAMES, EngulfingPos[2][i], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                                }
                                break;
                            }
                                // =====  INTERMISSION 2 : Denizens of Flame! ====== //

                            case EVENT_INTERMISSION_2:
                                PrepareTransition();

                                for (uint8 i = 0; i < 2; i++)
                                    me->SummonCreature(NPC_LAVA_SCION, SpawnPos[i], TEMPSUMMON_CORPSE_DESPAWN, 1000);

                                events.CancelEvent(EVENT_SULFURAS_SMASH);
                                events.CancelEvent(EVENT_MOLTEN_SEED);
                                events.CancelEvent(EVENT_MAGMA_BLAST);
                                if (IsHeroic())
                                    events.CancelEvent(EVENT_WORLD_FLAMES1);
                                else
                                    events.CancelEvent(EVENT_ENFULGING_FLAMES);

                                events.ScheduleEvent(EVENT_SUBMERGE, 8000);
                                events.ScheduleEvent(EVENT_PHASE_THREE, 45000);
                                break;

                                /**** STAGE 3 : Begone From My Realm! ****/

                            case EVENT_PHASE_THREE:
                            {
                                Talk(SAY_PHASE_3);
                                Movement::MoveSplineInit init(me);
                                init.SetOrientationFixed(false);
                                init.Launch();
                                me->RemoveAurasDueToSpell(SPELL_DISABLE_ANIM);
                                me->RemoveAurasDueToSpell(SPELL_SUBMERGE);
                                me->AddAura(SPELL_BASE_VISUAL, me);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                                Talk(SAY_NEW_PHASE);
                                if (Unit* target = SelectTarget(SELECT_TARGET_NEAREST, 0, 80.0f, true))
                                    me->AI()->AttackStart(target);

                                intermission2InProgress = false;

                                phase3 = true;

                                if (IsHeroic())
                                {
                                    events.ScheduleEvent(EVENT_SULFURAS_SMASH, 15500);
                                    events.ScheduleEvent(EVENT_WORLD_FLAMES1, 30000);
                                }
                                else
                                {
                                    events.ScheduleEvent(EVENT_SULFURAS_SMASH, 15500);
                                    events.ScheduleEvent(EVENT_ENFULGING_FLAMES, 40000);
                                }
                                events.ScheduleEvent(EVENT_METEORITE, 45000);
                                events.ScheduleEvent(EVENT_MAGMA_BLAST, 5000);
                            }
                                break;

                            case EVENT_METEORITE:
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 2, 200.0f, true))
                                    DoCast(target, SPELL_LIVING_METEOR);
                                events.ScheduleEvent(EVENT_METEORITE, 45000);
                                break;

                                /**** STAGE 4 : The True Power of the Firelord! ****/

                            case EVENT_PHASE_FOUR:
                                Talk(SAY_AID);
                                Talk(SAY_PHASE_HEROIC_TEXT);
                                me->RemoveAurasDueToSpell(SPELL_BASE_VISUAL);
                                me->SetHealth(me->GetMaxHealth() / 2);
                                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
                                me->SetObjectScale(1.2f);
                                events.ScheduleEvent(EVENT_SUPERHEATED, 10000);
                                events.ScheduleEvent(EVENT_EMPOWER, 12000);
                                events.ScheduleEvent(EVENT_HEROIC_DANCE, 2000);
                                break;

                            case EVENT_HEROIC_DANCE:
                                if (Creature* malfurion = me->SummonCreature(NPC_MALFURION, HeroPos[0].GetPositionX(),
                                        HeroPos[0].GetPositionY(), HeroPos[0].GetPositionZ(),
                                        HeroPos[0].GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000))
                                    malfurion->AI()->DoAction(ACTION_START_DANCE);
                                if (Creature* cenarius = me->SummonCreature(NPC_CENARIUS, HeroPos[1].GetPositionX(),
                                        HeroPos[1].GetPositionY(), HeroPos[1].GetPositionZ(),
                                        HeroPos[1].GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000))
                                    cenarius->AI()->DoAction(ACTION_START_DANCE);
                                if (Creature* hamuul = me->SummonCreature(NPC_HAMUUL, HeroPos[2].GetPositionX(),
                                        HeroPos[2].GetPositionY(), HeroPos[2].GetPositionZ(),
                                        HeroPos[2].GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000))
                                    hamuul->AI()->DoAction(ACTION_START_DANCE);
                                break;

                            case EVENT_SUPERHEATED:
                                DoCast(me, SPELL_SUPERHEATED);
                                events.ScheduleEvent(EVENT_SUPERHEATED, 10000);
                                break;

                            case EVENT_EMPOWER:
                                DoCast(me, SPELL_EMPOWER);
                                events.ScheduleEvent(EVENT_EMPOWER, 10000);
                                break;

                            case EVENT_DREADFLAME:
                                for (uint32 i = 0; i < RAID_MODE<uint8>(2, 2, 2, 5); ++i)
                                    me->SummonCreature(NPC_PLATFORM_STALKER, me->GetPositionX() + urand(-20, 20),
                                            me->GetPositionY() + urand(-20, 20), me->GetPositionZ(),
                                            me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);
                                //http://www.wowhead.com/npc=53952 - Ragnaros platform stalkers... can't imagine a different use for the bitches
                                events.ScheduleEvent(EVENT_DREADFLAME, 12000);
                                break;
                        }
                    }

                    if (!me->HasAura(SPELL_SUBMERGE))
                        DoMeleeAttackIfReady();
                }
        };
};

class npc_sulfuras_smash_trigger: public CreatureScript // 53266
{
    public:
        npc_sulfuras_smash_trigger() : CreatureScript("npc_sulfuras_smash_trigger") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_sulfuras_smash_triggerAI(creature);
        }

        struct npc_sulfuras_smash_triggerAI: public ScriptedAI
        {
                npc_sulfuras_smash_triggerAI(Creature* creature) : ScriptedAI(creature)
                {
                    instance = creature->GetInstanceScript();
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    creature->AddAura(SPELL_SULFURAS_SMASH_VISUAL, creature);
                    creature->SetReactState(REACT_PASSIVE);
                    Movement::MoveSplineInit init(creature);
                    init.SetOrientationFixed(true);
                    init.Launch();
                    m_uiSmashTimer = 5000;
                    m_uiDespawnTimer = 6000;
                }

                InstanceScript* instance;
                uint32 m_uiSmashTimer;
                uint32 m_uiDespawnTimer;

                void EnterCombat(Unit* /*who*/) override
                {
                }

                void UpdateAI(uint32 diff) override
                {
                    if (m_uiSmashTimer)
                    {
                        if (m_uiSmashTimer <= diff)
                        {
                            DoCast(me, SPELL_SULFURAS_SMASH_DAMAGE, true);

                            for (uint32 spellId = SPELL_LAVA_WAVE_SUMMON_FRONT; spellId <= SPELL_LAVA_WAVE_SUMMON_LEFT; ++spellId)
                                me->CastSpell(me, spellId, true);

                            m_uiSmashTimer = 0;
                        }
                        else
                            m_uiSmashTimer -= diff;
                    }

                    if (m_uiDespawnTimer <= diff)
                    {
                        me->DespawnOrUnsummon();
                        m_uiDespawnTimer = -1;
                    }
                    else
                        m_uiDespawnTimer -= diff;
                }
        };
};

class npc_sulfuras_lava_wave: public CreatureScript // 53363
{
    public:
        npc_sulfuras_lava_wave() : CreatureScript("npc_sulfuras_lava_wave") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_sulfuras_lava_waveAI(creature);
        }

        struct npc_sulfuras_lava_waveAI: public ScriptedAI
        {
            npc_sulfuras_lava_waveAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_LAVA_WAVE, me);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);

                Position pos = me->GetPosition();
                GetPositionWithDistInOrientation(me, 200.0f, me->GetOrientation(), pos);
                me->GetMotionMaster()->MovePoint(1, pos);
            }

            void Reset() override {}
            void EnterCombat(Unit* /*who*/) override {}
            void EnterEvadeMode(EvadeReason /*why*/) override {}

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (id == 1)
                    me->DespawnOrUnsummon();
            }
        };
};

class npc_magma_trap: public CreatureScript
{
    public:
        npc_magma_trap() : CreatureScript("npc_magma_trap") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_magma_trapAI(creature);
        }

        struct npc_magma_trapAI: public ScriptedAI
        {
                npc_magma_trapAI(Creature* creature) :
                        ScriptedAI(creature)
                {
                    instance = creature->GetInstanceScript();
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                    creature->AddAura(SPELL_MAGMA_TRAP_VISUAL, creature);
                    creature->SetReactState(REACT_PASSIVE);
                    Movement::MoveSplineInit init(creature);
                    init.SetOrientationFixed(true);
                    init.Launch();
                    m_uiDespawnTimer = 70000;
                    m_uiCheckTimer = 1000;
                }

                InstanceScript* instance;
                uint32 m_uiDespawnTimer;
                uint32 m_uiCheckTimer;

                void UpdateAI(uint32 diff) override
                {
                    if (m_uiCheckTimer <= diff)
                    {

                        std::list<Player*> playerList;
                        me->GetPlayerListInGrid(playerList, 5.0f);

                        if (playerList.size() > 0)
                        {
                            DoCast(me, SPELL_MAGMA_TRAP_ERUPTION);
                            me->AddAura(SPELL_MAGMA_TRAP_VULNERABILITY, playerList.front());
                            me->DespawnOrUnsummon(900);
                        }

                        m_uiCheckTimer = 1000;
                    }
                    else
                        m_uiCheckTimer -= diff;

                    if (m_uiDespawnTimer <= diff)
                    {
                        me->DespawnOrUnsummon();
                        m_uiDespawnTimer = -1;
                    }
                    else
                        m_uiDespawnTimer -= diff;
                }
        };
};

class npc_splitting_blow: public CreatureScript
{
    public:
        npc_splitting_blow() : CreatureScript("npc_splitting_blow") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_splitting_blowAI(creature);
        }

        struct npc_splitting_blowAI: public ScriptedAI
        {
            npc_splitting_blowAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                creature->SetReactState(REACT_PASSIVE);
                Movement::MoveSplineInit init(creature);
                init.SetOrientationFixed(true);
                init.Launch();
                m_uiDespawnTimer = 8000;
                me->SummonCreature(NPC_SULFURAS, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_MANUAL_DESPAWN);
            }

            InstanceScript* instance;
            uint32 m_uiDespawnTimer;

            void UpdateAI(uint32 diff) override
            {
                if (m_uiDespawnTimer <= diff)
                {
                    me->DespawnOrUnsummon(100);
                    m_uiDespawnTimer = -1;
                }
                else
                    m_uiDespawnTimer -= diff;
            }
        };
};

class npc_sulfuras: public CreatureScript
{
    public:
        npc_sulfuras() : CreatureScript("npc_sulfuras") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_sulfurasAI(creature);
        }

        struct npc_sulfurasAI: public ScriptedAI
        {
            npc_sulfurasAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                creature->AddAura(SPELL_SULFURAS_AURA, creature);
                Talk(SAY_SONS);
                creature->SetReactState(REACT_PASSIVE);
                Movement::MoveSplineInit init(creature);
                init.SetOrientationFixed(true);
                init.Launch();
                m_uiDespawnTimer = 60000;
            }

            InstanceScript* instance;
            uint32 m_uiDespawnTimer;

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (m_uiDespawnTimer <= diff)
                {
                    me->DespawnOrUnsummon();
                    m_uiDespawnTimer = -1;
                }
                else
                    m_uiDespawnTimer -= diff;
            }
        };
};

class npc_son_of_flame_firelands: public CreatureScript
{
    public:
        npc_son_of_flame_firelands() : CreatureScript("npc_son_of_flame_firelands") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_son_of_flame_firelandsAI(creature);
        }

        struct npc_son_of_flame_firelandsAI: public ScriptedAI
        {
            npc_son_of_flame_firelandsAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                creature->SetSpeed(MOVE_RUN, 0.1f);
                creature->SetSpeed(MOVE_WALK, 0.1f);
                creature->SetWalk(true);
                creature->AddAura(SPELL_VISUAL_PRESPAWN, creature);
                m_uiEmergeTimer = 20000; // Max time just in case
                m_uiSulfurasCheckTimer = 1500;
            }

            InstanceScript* instance;
            uint32 m_uiEmergeTimer;
            uint32 m_uiSulfurasCheckTimer;

            void Reset() override
            {
                if (Aura* speedAura = me->AddAura(SPELL_BURNING_SPEED, me))
                    speedAura->SetStackAmount(10);
            }

            void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
            {
                if (spell->Id == SPELL_SOF_MISSILE_TRIGGER)
                    m_uiEmergeTimer = 100;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!HealthBelowPct(50))
                {
                    if (Aura* speedAura = me->GetAura(SPELL_BURNING_SPEED))
                        speedAura->SetStackAmount(uint32(std::ceil(float(me->GetHealthPct() - 50) / 5)));
                }
                else
                    me->RemoveAurasDueToSpell(SPELL_BURNING_SPEED);

                if (m_uiEmergeTimer)
                {
                    if (m_uiEmergeTimer <= diff)
                    {
                        me->RemoveAurasDueToSpell(SPELL_VISUAL_PRESPAWN);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                        me->AddAura(SPELL_BURNING_SPEED, me);
                        me->SetAuraStack(SPELL_BURNING_SPEED, me, 10);
                        me->AddAura(SPELL_HIT_ME, me);
                        me->SetSpeed(MOVE_RUN, 0.5f);
                        me->SetSpeed(MOVE_WALK, 0.5f);
                        if (Creature* sulfuras = me->FindNearestCreature(NPC_SULFURAS, 100.0f, true))
                            me->GetMotionMaster()->MoveChase(sulfuras);
                        me->SetReactState(REACT_PASSIVE);
                        m_uiEmergeTimer = 0;
                    }
                    else
                        m_uiEmergeTimer -= diff;
                }

                if (m_uiSulfurasCheckTimer <= diff)
                {
                    if (Creature* sulfuras = me->FindNearestCreature(NPC_SULFURAS, 2.0f, true))
                    {
                        sulfuras->CastSpell(sulfuras, SPELL_SUPERNOVA, false);
                        me->DespawnOrUnsummon(100);
                    }
                    m_uiSulfurasCheckTimer = 1500;
                }
                else
                    m_uiSulfurasCheckTimer -= diff;
            }
        };
};

class npc_molten_seed: public CreatureScript
{
    public:
        npc_molten_seed() : CreatureScript("npc_molten_seed") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_molten_seedAI(creature);
        }

        struct npc_molten_seedAI: public ScriptedAI
        {
            npc_molten_seedAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                creature->SetReactState(REACT_PASSIVE);
                Movement::MoveSplineInit init(creature);
                init.SetOrientationFixed(true);
                init.Launch();
                m_uiMoltenInfernoTimer = 10000;
                m_uiDespawnTimer = 15000;
            }

            InstanceScript* instance;

            uint32 m_uiDespawnTimer;
            uint32 m_uiMoltenInfernoTimer;

            void UpdateAI(uint32 diff) override
            {
                if (m_uiMoltenInfernoTimer <= diff)
                {
                    DoCast(me, SPELL_MOLTEN_INFERNO);
                    DoCastAOE(SPELL_MOLTEN_SEED_MISSILE);
                    me->SummonCreature(NPC_MOLTEN_ELEMENTAL, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    m_uiMoltenInfernoTimer = 10000;
                }
                else
                    m_uiMoltenInfernoTimer -= diff;

                if (m_uiDespawnTimer <= diff)
                {
                    me->DespawnOrUnsummon();
                    m_uiDespawnTimer = -1;
                }
                else
                    m_uiDespawnTimer -= diff;
            }
        };
};

class npc_lava_scion: public CreatureScript
{
    public:
        npc_lava_scion() : CreatureScript("npc_lava_scion")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_lava_scionAI(creature);
        }

        struct npc_lava_scionAI: public ScriptedAI
        {
            npc_lava_scionAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                m_uiBlazingHeatTimer = 15000;
            }

            InstanceScript* instance;
            uint32 m_uiBlazingHeatTimer;

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (m_uiBlazingHeatTimer <= diff)
                {
                    if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BLAZING_HEAT);
                    m_uiBlazingHeatTimer = urand(15000, 25000);
                }
                else
                    m_uiBlazingHeatTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };
};

class npc_molten_elemental: public CreatureScript
{
    public:
        npc_molten_elemental() : CreatureScript("npc_molten_elemental") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_molten_elementalAI(creature);
        }

        struct npc_molten_elementalAI: public ScriptedAI
        {
            npc_molten_elementalAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 m_uiMoltenPowerCheckTimer;

            void Reset() override
            {
                DoZoneInCombat();
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                {
                    me->Attack(target, true);
                    me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                    me->AddThreat(target, 1000000.0f);
                    //me->CastSpell(target, SPELL_ELEMENTAL_FIXATE, true);
                    // Not tauntable.
                    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);
                }

                m_uiMoltenPowerCheckTimer = 3000;
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (IsHeroic())
                {
                    if (m_uiMoltenPowerCheckTimer <= diff && IsHeroic())
                    {
                        if (GetClosestCreatureWithEntry(me, NPC_MOLTEN_ELEMENTAL, 6.0f))
                            DoCast(me, SPELL_MOLTEN_POWER);
                        m_uiMoltenPowerCheckTimer = 3000;
                    }
                    else
                        m_uiMoltenPowerCheckTimer -= diff;
                }

                DoMeleeAttackIfReady();
            }
        };
};

class npc_engulfing_flames: public CreatureScript
{
    public:
        npc_engulfing_flames() : CreatureScript("npc_engulfing_flames")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_engulfing_flamesAI(creature);
        }

        struct npc_engulfing_flamesAI: public ScriptedAI
        {
            npc_engulfing_flamesAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                //creature->CastSpell(creature, SPELL_ENGULFING_FLAMES_DAMAGE, false); // <= Will be set by Ragnaros from 99172
                creature->SetReactState(REACT_PASSIVE);
                Movement::MoveSplineInit init(creature);
                init.SetOrientationFixed(true);
                init.Launch();
                m_uiDespawnTimer = 4000;
            }

            InstanceScript* instance;
            uint32 m_uiDespawnTimer;

            void UpdateAI(uint32 diff) override
            {
                if (m_uiDespawnTimer <= diff)
                {
                    me->DespawnOrUnsummon();
                }
                else
                    m_uiDespawnTimer -= diff;
            }
        };
};

class npc_dreadflame: public CreatureScript
{
    public:
        npc_dreadflame() : CreatureScript("npc_dreadflame")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_dreadflameAI(creature);
        }

        struct npc_dreadflameAI: public ScriptedAI
        {
            npc_dreadflameAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                creature->SetFlag(UNIT_FIELD_FLAGS,
                        UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE);
                creature->SetReactState(REACT_PASSIVE);
                creature->DespawnOrUnsummon(60000);
                m_uiDreadTimer = 3000;
            }

            InstanceScript* instance;
            uint32 m_uiDreadTimer;
            uint32 m_uiCheckDeluge;

            void UpdateAI(uint32 diff) override
            {
                if (m_uiCheckDeluge <= diff)
                {
                    if (Player* player = me->SelectNearestPlayer(2.5f))
                        if (player->IsWithinDistInMap(me, 2.5f) && player->HasAura(SPELL_DELUGE))
                        {
                            DoCast(me, SPELL_WATER_VISUAL);
                            me->DespawnOrUnsummon();
                        }

                    m_uiCheckDeluge = 250;
                }
                else
                    m_uiCheckDeluge -= diff;

                if (m_uiDreadTimer <= diff)
                {
                    me->SummonCreature(NPC_DREADFLAME_SPAWN, me->GetPositionX() + 3, me->GetPositionY(),
                            me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    me->SummonCreature(NPC_DREADFLAME_SPAWN, me->GetPositionX() - 3, me->GetPositionY(),
                            me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    me->SummonCreature(NPC_DREADFLAME_SPAWN, me->GetPositionX(), me->GetPositionY() + 3,
                            me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    me->SummonCreature(NPC_DREADFLAME_SPAWN, me->GetPositionX(), me->GetPositionY() - 3,
                            me->GetPositionZ(), me->GetOrientation(), TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    m_uiDreadTimer = 3500;
                }
                else
                    m_uiDreadTimer -= diff;
            }
        };
};

class npc_living_meteor: public CreatureScript
{
    public:
        npc_living_meteor() : CreatureScript("npc_living_meteor") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_living_meteorAI(creature);
        }

        struct npc_living_meteorAI: public ScriptedAI
        {
            npc_living_meteorAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            EventMap events;
            uint32 m_uiLavalogedCheckTimer;
            ObjectGuid targetGuid;

            void Reset() override
            {
                events.Reset();
                targetGuid = ObjectGuid::Empty;

                events.ScheduleEvent(EVENT_NEW_FOLLOW, 2000);
                events.ScheduleEvent(EVENT_CHECK_DISTANCE, 5000);

                me->SetSpeed(MOVE_RUN, 0.75f);
                me->SetSpeed(MOVE_WALK, 0.75f);
                DoCast(me, SPELL_INCR_RUN_PERIODIC_AURA);
                me->AddAura(SPELL_COMBUSTIBLE, me);

                me->SetReactState(REACT_PASSIVE);
                m_uiLavalogedCheckTimer = 3000;
            }

            void DamageTaken(Unit* attacker, uint32& /*damage*/) override
            {
                if (!me->HasAura(SPELL_COMBUSTIBLE))
                    return;

                DoCast(attacker, SPELL_COMBUSTION); // Knock back relative to attacker

                me->GetMotionMaster()->Clear();
                me->RemoveAurasDueToSpell(SPELL_INCR_RUN_AURA);
                me->RemoveAurasDueToSpell(SPELL_COMBUSTIBLE);

                events.ScheduleEvent(EVENT_CAST_COMBUSTIBLE, 5000);
                events.ScheduleEvent(EVENT_NEW_FOLLOW, 2000);
            }

            void SelectNextFollowTarget(ObjectGuid newTargetGuid = ObjectGuid::Empty)
            {
                me->GetMotionMaster()->Clear();
                me->getThreatManager().resetAllAggro();
                me->CastStop();

                DoZoneInCombat();

                Creature* ragnaros = ObjectAccessor::GetCreature(*me, instance->GetGuidData(NPC_RAGNAROS));

                if (!ragnaros)
                    return;

                Unit* target = nullptr;

                if (!newTargetGuid.IsEmpty())
                    target = ObjectAccessor::FindPlayer(newTargetGuid);
                else
                    target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(ragnaros));

                if (!target || !target->IsAlive())
                {
                    targetGuid = ObjectGuid::Empty;
                    events.ScheduleEvent(EVENT_NEW_FOLLOW, 2000);
                    return;
                }

                me->AddThreat(target, 1000000.0f);
                me->CastSpell(target, SPELL_FLAMING_FIXATE, false);
                me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f);
                // Not tauntable.
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_TAUNT, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_ATTACK_ME, true);

                targetGuid = target->GetGUID();
            }

            void UpdateAI(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_NEW_FOLLOW:
                        {
                            SelectNextFollowTarget();
                            events.CancelEvent(EVENT_NEW_FOLLOW);
                            break;
                        }
                        case EVENT_CAST_COMBUSTIBLE:
                        {
                            me->AddAura(SPELL_COMBUSTIBLE, me);
                            events.CancelEvent(EVENT_CAST_COMBUSTIBLE);
                            break;
                        }
                        case EVENT_CHECK_DISTANCE:
                        {
                            std::list<Player*> playerList;
                            me->GetPlayerListInGrid(playerList, 5.0f);
                            if (playerList.size() > 0)
                                DoCast(SPELL_IMPACT);

                            events.ScheduleEvent(EVENT_CHECK_DISTANCE, 2000);
                            break;
                        }
                    }
                }

                if (m_uiLavalogedCheckTimer <= diff && IsHeroic())
                {
                    if (GetClosestCreatureWithEntry(me, NPC_LAVA_WAVE, 3.0f))
                        DoCast(me, SPELL_LAVALOGGED);

                    if (GetClosestCreatureWithEntry(me, NPC_BREATH_OF_FROST, 3.0f))
                    {
                        me->RemoveAllAuras();
                        me->AddAura(SPELL_METEOR_OF_FROST, me);
                    }

                    m_uiLavalogedCheckTimer = 500;
                }
                else
                    m_uiLavalogedCheckTimer -= diff;
            }
        };
};

class npc_entrapping_roots: public CreatureScript
{
    public:
        npc_entrapping_roots() : CreatureScript("npc_entrapping_roots") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_entrapping_rootsAI(creature);
        }

        struct npc_entrapping_rootsAI: public ScriptedAI
        {
            npc_entrapping_rootsAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            uint32 searchragnaros;

            void Reset() override
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->DespawnOrUnsummon(60000);
                searchragnaros = 1000;
                DoStartNoMovement(me);
                DoCast(me, SPELL_VISUAL_ROOTS);
                me->SetInCombatWithZone();
                me->SetReactState(REACT_PASSIVE);
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (searchragnaros <= uiDiff)
                {
                    if (Creature* Ragnaros = me->FindNearestCreature(NPC_RAGNAROS, 10.0f, true)) //remember NPC_RAGNAROS_FIRELANDS = 52409
                    {
                        DoCast(Ragnaros, SPELL_ENTRAPPING);
                        me->DespawnOrUnsummon(100);
                    }
                }
                else
                    searchragnaros -= uiDiff;
            }
        };
};

class npc_cloudburst: public CreatureScript
{
    public:
        npc_cloudburst() : CreatureScript("npc_cloudburst") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_cloudburstAI(creature);
        }

        struct npc_cloudburstAI: public ScriptedAI
        {
            npc_cloudburstAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                creature->SetFlag(UNIT_FIELD_FLAGS,
                    UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                creature->SetReactState(REACT_PASSIVE);
                creature->DespawnOrUnsummon(60000);
                _cloudburstCounter = 0;
            }

            InstanceScript* instance;
            uint8 _cloudburstCounter;

            void UpdateAI(uint32 /*uiDiff*/) override
            {
                _cloudburstCounter = RAID_MODE<uint8>(1, 1, 1, 3);

                if (Player* player =  me->SelectNearestPlayer(6.0f))
                    if (player->IsWithinDistInMap(me, 6.0f))
                    {
                        --_cloudburstCounter;
                        if (!player->HasAura(SPELL_DELUGE) && _cloudburstCounter == 0)
                        {
                            DoCast(player, SPELL_DELUGE);
                            me->DespawnOrUnsummon(100);
                        }
                    }
            }
        };
};

class npc_breathoffrost: public CreatureScript
{
    public:
        npc_breathoffrost() : CreatureScript("npc_breathoffrost") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_breathoffrostAI(creature);
        }

        struct npc_breathoffrostAI: public ScriptedAI
        {
            npc_breathoffrostAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
                creature->SetFlag(UNIT_FIELD_FLAGS,
                        UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
                creature->SetReactState(REACT_PASSIVE);
                creature->DespawnOrUnsummon(20000);
            }

            InstanceScript* instance;

            void UpdateAI(uint32 /*uiDiff*/) override
            {
                if (Player* player = me->SelectNearestPlayer(6.0f))
                    if (player->IsWithinDistInMap(me, 6.0f))
                    {
                        if (!player->HasAura(SPELL_PROTECT_SUPERHEAT))
                        {
                            player->RemoveAura(SPELL_SUPERHEATED);
                            player->CastSpell(player, SPELL_MOLTEN_HEART, true);
                        }
                        //else player->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SUPERHEATED, true);
                    }
            }
        };
};

class npc_malfurion: public CreatureScript
{
    public:
        npc_malfurion() : CreatureScript("npc_malfurion") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_malfurionAI(creature);
        }

        struct npc_malfurionAI: public ScriptedAI
        {
            npc_malfurionAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 m_uiCloudTimer;

            void Reset() override
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                DoStartNoMovement(me);
                me->SetInCombatWithZone();
                me->SetReactState(REACT_PASSIVE);
            }

            void EnterCombat(Unit* /*pWho*/) override
            {
                m_uiCloudTimer = 9000;
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (m_uiCloudTimer <= uiDiff)
                {
                    if (Unit* that = me->SelectNearestPlayer(60.0f))
                        me->SummonCreature(NPC_CLOUDBURST, that->GetPositionX() + urand(10, 15),
                                that->GetPositionY() + urand(10, 15), that->GetPositionZ(), that->GetOrientation(),
                                TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    DoCast(me, SPELL_CAST_CLOUDBURST);
                    m_uiCloudTimer = 22000;
                }
                else
                    m_uiCloudTimer -= uiDiff;
            }
        };
};

class npc_cenarius: public CreatureScript
{
    public:
        npc_cenarius() : CreatureScript("npc_cenarius") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_cenariusAI(creature);
        }

        struct npc_cenariusAI: public ScriptedAI
        {
            npc_cenariusAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 m_uiFrostyTimer;

            void Reset() override
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                DoStartNoMovement(me);
                me->SetInCombatWithZone();
                me->SetReactState(REACT_PASSIVE);
            }

            void EnterCombat(Unit* /*pWho*/) override
            {
                m_uiFrostyTimer = 12000;
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (m_uiFrostyTimer <= uiDiff)
                {
                    if (Unit* that = me->SelectNearestPlayer(60.0f)) //why like this? Because fuck knows how blizz did it, and it's already a 1700 word script. If you correct this shit and go "Fuck this guy for not doing it properly." suck the shit out of my ass cause you are already full of it.
                        me->SummonCreature(NPC_BREATH_OF_FROST, that->GetPositionX() + urand(5, 12),
                                that->GetPositionY() + urand(5, 12), that->GetPositionZ(), that->GetOrientation(),
                                TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    DoCast(me, SPELL_VISUAL_BREATH);
                    m_uiFrostyTimer = 30000;
                }
                else
                    m_uiFrostyTimer -= uiDiff;
            }
        };
};

class npc_heartofragnaros: public CreatureScript
{
    public:
        npc_heartofragnaros() : CreatureScript("npc_heartofragnaros")
        {
        }

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_heartofragnarosAI(creature);
        }

        struct npc_heartofragnarosAI: public ScriptedAI
        {
            npc_heartofragnarosAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 m_uiHeartBeat;

            void Reset() override
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                me->DespawnOrUnsummon(150000);
                DoStartNoMovement(me);
                me->SetReactState(REACT_PASSIVE);
                m_uiHeartBeat = 1000; //timer is here if you need it so just copy paste. To remove if script works without it.
            }

            void EnterCombat(Unit* /*pWho*/) override
            {
            }

            void UpdateAI(uint32 /*uiDiff*/) override
            {
                Player* player = me->SelectNearestPlayer(6.0f);
                if (player)
                {
                    if (player->HasAura(SPELL_RAGE_OF_RAGNAROS) && !IsHeroic())
                    {
                        player->RemoveAura(SPELL_RAGE_OF_RAGNAROS);
                        player->CastSpell(player, SPELL_MOLTEN_HEART, true);
                        me->DespawnOrUnsummon(100);
                    }
                    else if (IsHeroic()) //&& player->HasItemCount(ITEM_SMOULDERING_ESSENCE, 250))
                    {
                        me->CastSpell(player, SPELL_MOLTEN_HEART, true);
                        me->DespawnOrUnsummon(100);
                    }
                    return; //this might be very incorect and this whole thing may need a timer.
                }
            }
        };
};

class npc_hamuul: public CreatureScript
{
    public:
        npc_hamuul() : CreatureScript("npc_hamuul") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_hamuulAI(creature);
        }

        struct npc_hamuulAI: public ScriptedAI
        {
            npc_hamuulAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;

            uint32 m_uiRootTimer;

            void Reset() override
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                DoStartNoMovement(me);
                me->SetInCombatWithZone();
                me->SetReactState(REACT_PASSIVE);
            }

            void EnterCombat(Unit* /*pWho*/) override
            {
                m_uiRootTimer = 9000;
            }

            void UpdateAI(uint32 uiDiff) override
            {
                if (m_uiRootTimer <= uiDiff)
                {
                    if (Unit* that = me->SelectNearestPlayer(60.0f))
                        me->SummonCreature(NPC_ENTRAPPING_ROOTS, that->GetPositionX() + urand(10, 15),
                        that->GetPositionY() + urand(10, 15), that->GetPositionZ(), that->GetOrientation(),
                        TEMPSUMMON_CORPSE_DESPAWN, 1000);
                    DoCast(me, SPELL_NATURE);
                    m_uiRootTimer = 22000;
                }
                else
                    m_uiRootTimer -= uiDiff;
            }
        };
};

class npc_blazing_heat: public CreatureScript
{
    public:
        npc_blazing_heat() : CreatureScript("npc_blazing_heat") {}

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_blazing_heatAI(creature);
        }

        struct npc_blazing_heatAI: public ScriptedAI
        {
            npc_blazing_heatAI(Creature* creature) : ScriptedAI(creature) {}

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->AddAura(SPELL_BLAZING_HEAT_VISUAL, me);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }

            void EnterCombat(Unit* /*pWho*/)  override {}
            void UpdateAI(uint32 /*uiDiff*/) override {}
        };
};

// Molten Inferno - 98518
class spell_molten_inferno : public SpellScriptLoader
{
public:
    spell_molten_inferno() : SpellScriptLoader("spell_molten_inferno") { }

    class spell_molten_inferno_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_molten_inferno_SpellScript);

        void DealDamage()
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            float distance = caster->GetExactDist2d(target);
            const float MAX_DIST = 100;

            if (distance >= 0 && distance <= MAX_DIST)
                SetHitDamage(GetHitDamage() * (1 - (distance / MAX_DIST)));
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_molten_inferno_SpellScript::DealDamage);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_molten_inferno_SpellScript();
    }
};

void AddSC_boss_ragnaros_firelands()
{
    new boss_ragnaros_firelands();
    new npc_sulfuras_smash_trigger();
    new npc_sulfuras_lava_wave();
    new npc_magma_trap();
    new npc_splitting_blow();
    new npc_sulfuras();
    new npc_engulfing_flames();
    new npc_molten_seed();
    new npc_living_meteor();
    new npc_son_of_flame_firelands();
    new npc_lava_scion();
    new npc_molten_elemental();
    new npc_entrapping_roots();
    new npc_dreadflame();
    new npc_cloudburst();
    new npc_breathoffrost();
    new npc_hamuul();
    new npc_malfurion();
    new npc_cenarius();
    new npc_heartofragnaros();
    new npc_blazing_heat();
    new spell_molten_inferno();
}
