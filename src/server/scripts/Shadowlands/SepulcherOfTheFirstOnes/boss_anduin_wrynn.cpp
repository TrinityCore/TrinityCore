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
#include "Containers.h"
#include "Conversation.h"
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "DB2Structure.h"
#include "G3DPosition.hpp"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PathGenerator.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "sepulcher_of_the_first_ones.h"

enum AnduinWrynnSpells
{
    // Pre-Introduction
    SPELL_BROKER_SPAWN                              = 367524,

    // Generic Spells
    SPELL_ANDUIN_PLUNGE_KINGSMOURNE                 = 369125,
    SPELL_POWER_DISPLAY_WILLPOWER                   = 365177,
    SPELL_POWER_ENERGIZE_WILLPOWER_SMALL            = 365217,
    SPELL_POWER_ENERGIZE_WILLPOWER_LARGE            = 365228,
    SPELL_SOUL_DESPAWN                              = 362766,
    SPELL_SHADESTEP                                 = 363976,
    SPELL_ANDUIN_PROGRESSION_AURA                   = 369317,
    SPELL_ANDUIN_WILLPOWER_PERIODIC                 = 366848,
    SPELL_ANDUIN_SOUL_GHOST                         = 369016,

    // Dark Zeal
    SPELL_DARK_ZEAL_AURA                            = 364247,
    SPELL_DARK_ZEAL_BUFF                            = 364248,

    // Hopebreaker
    SPELL_HOPEBREAKER                               = 361815,
    SPELL_HOPEBREAKER_DAMAGE                        = 361816,
    SPELL_HOPEBREAKER_DEBUFF                        = 361817,
    SPELL_HOPEBREAKER_DEBUFF_DAMAGE                 = 361818,
    SPELL_HOPEBREAKER_CLEAR                         = 364237,

    // Domination Word: Pain
    SPELL_DOMINATION_WORD_PAIN                      = 366849,

    // Befouled Barrier
    SPELL_BEFOULED_BARRIER                          = 365295,
    SPELL_BEFOULED_BARRIER_BLACK_RING               = 365633,
    SPELL_BEFOULED_ERUPTION                         = 365853,
    SPELL_BEFOULED_BARRIER_SPHERE_AREATRIGGER       = 365173,
    SPELL_BEFOULED_BARRIER_DEBUFF                   = 365293,
    SPELL_BEFOULED_BARRIER_CLEAR                    = 369871,
    SPELL_BEFOULED_BARRIER_EXPLODE                  = 365300,

    // Blasphemy
    SPELL_BLASPHEMY                                 = 361989,
    SPELL_BLASPHEMY_PRE_HIT                         = 364239,
    SPELL_BLASPHEMY_OVERCONFIDENCE                  = 361990,
    SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER      = 361992,
    SPELL_BLASPHEMY_HOPELESSNESS                    = 361991,
    SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER        = 361993,
    SPELL_BLASPHEMY_SUCCESS                         = 362014,
    SPELL_BLASPHEMY_EXPLODE                         = 361999,
    SPELL_BLASPHEMY_EXPLODE_LFR_NORMAL              = 366933,
    SPELL_CANCEL_BLASPHEMY                          = 370161,
    SPELL_BLASPHEMY_IMMUNE                          = 370407,

    // Kingsmourne Hungers
    SPELL_KINGSMOURNE_HUNGERS                       = 362405,
    SPELL_KINGSMOURNE_HUNGERS_DAMAGE_IDK            = 362406,
    SPELL_KINGSMOURNE_HUNGERS_DAMAGE                = 362407,
    SPELL_LOST_SOUL_DIMENSION                       = 362055,
    SPELL_LOST_SOUL                                 = 362472,
    SPELL_LOST_SOUL_GRACE                           = 370068,
    SPELL_LOST_SOUL_CLEAR                           = 365641,
    SPELL_CANCEL_LOST_SOUL                          = 367774,
    SPELL_SEVERED_SOUL                              = 367769,
    SPELL_LOST_SOUL_MYTHIC                          = 367770,
    SPELL_LOST_SOUL_MIRROR_IMAGE                    = 362402,
    SPELL_SCARRED_SOUL                              = 365445,
    SPELL_MIRROR_IMAGE                              = 362474,
    SPELL_FEIGN_DEATH                               = 114371,
    SPELL_BANISH_SOUL                               = 367771,
    SPELL_MIRROR_IMAGE_IGNORE_PHASE_SHIFT           = 362473,
    SPELL_ANDUIN_LOST_SOUL_TRACKER                  = 369843,

    // Rain of Despair (Big add)
    SPELL_RAIN_OF_DESPAIR                           = 362391,
    SPELL_ANDUIN_SOUL_DESPAIR                       = 365220,
    SPELL_RAIN_OF_DESPAIR_MELEE                     = 362393,
    SPELL_RAIN_OF_DESPAIR_RANGED                    = 362396,
    SPELL_RAIN_OF_DESPAIR_EXPLOSION                 = 362392,

    // Wicked Star
    SPELL_WICKED_STAR                               = 365030,
    SPELL_WICKED_STAR_POINTER                       = 365021,
    SPELL_WICKED_STAR_AREATRIGGER                   = 365017,
    SPELL_WICKED_STAR_DAMAGE_SILENCE                = 365024,
    SPELL_WICKED_STAR_EMPOWERMENT                   = 365112,
    SPELL_WICKED_STAR_IDK                           = 365992,
    SPELL_WICKED_STAR_TARGETED                      = 366674,
    SPELL_WICKED_STAR_IDK_3                         = 369280,

    // Empowered Wicked Star
    SPELL_EMPOWERED_WICKED_STAR                     = 367631,
    SPELL_EMPOWERED_WICKED_STAR_POINTER             = 367632,
    SPELL_EMPOWERED_WICKED_STAR_AREATRIGGER         = 367621,
    SPELL_EMPOWERED_WICKED_STAR_DAMAGE_SILENCE      = 367634,

    // Force of Will
    SPELL_FORCE_OF_WILL                             = 368913,
    SPELL_CANCEL_FORCE_OF_WILL                      = 368978,

    // Fiendish Soul
    SPELL_NECROTIC_CLAWS_LEAP                       = 363019,
    SPELL_NECROTIC_CLAWS_DEBUFF                     = 363020,
    SPELL_SOUL_EXPLOSION_TARGET                     = 363029,
    SPELL_SOUL_EXPLOSION_TRIGGER_MISSILE            = 363030,
    SPELL_SOUL_EXPLOSION_DAMAGE                     = 363031,

    // Monstrous Soul
    SPELL_UNRAVELING_FRENZY_PERIODIC                = 363027,
    SPELL_UNRAVELING_FRENZY                         = 363028,
    SPELL_NECROTIC_DETONATION                       = 363024,

    // Grim Reflections
    SPELL_GRIM_REFLECTIONS                          = 365120,
    SPELL_GRIM_REFLECTIONS_SUMMON                   = 365121,
    SPELL_GRIM_REFLECTIONS_DEST_SUMMON              = 365039,
    SPELL_CALAMITY_STATE_VISUAL                     = 361685,
    SPELL_WICKED_STAR_PROTECTION                    = 370400,
    SPELL_PSYCHIC_TERROR                            = 365008,
    SPELL_GRIM_FATE                                 = 367932,

    // Beacon of Hope
    SPELL_BEACON_OF_HOPE                            = 365872,
    SPELL_BEACON_OF_HOPE_AREATRIGGER                = 362702,

    // Fragment of Hope
    SPELL_FRAGMENT_OF_HOPE_AREATRIGGER              = 365816,
    SPELL_FRAGMENT_OF_HOPE_CLEAR_DEBUFF             = 365828,
    SPELL_FRAGMENT_OF_HOPE_DAMAGE                   = 365990,

    // Purging Light
    SPELL_PURGING_LIGHT                             = 368428,

    // Hopelessness
    SPELL_HOPELESSNESS                              = 365958,
    SPELL_HOPELESSNESS_MISSILE                      = 365962,
    SPELL_HOPELESSNESS_HOPELESSNESS_AREATRIGGER     = 365966,
    SPELL_HOPELESSNESS_EXPLODE                      = 365971,

    // Empowered Hopebreaker
    SPELL_EMPOWERED_HOPEBREAKER                     = 365805,
    SPELL_EMPOWERED_HOPEBREAKER_EXPLOSION           = 365806,

    // Anduin's Soul
    SPELL_LOST_SOUL_PERIODIC                        = 365650,
    SPELL_LOST_SOUL_CONSUME                         = 365652,

    // Anduin's Hope
    SPELL_ANDUIN_SLOW                               = 365218,
    SPELL_GLOOM                                     = 364031,

    // Anduin's Doubt
    SPELL_GHOST_VISUAL_COSMETIC                     = 370833,

    // Remnant of a Fallen King
    SPELL_DOMINATION_GRASP                          = 365216,
    SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER         = 362505,
    SPELL_SHADE_VISUAL                              = 362490,
    SPELL_REMNANT_SPAWN                             = 362500,
    SPELL_DARK_PRESENCE                             = 368986,
    SPELL_WEATHER_COSMETIC                          = 362493,
    SPELL_SPAWN_REMNANT                             = 362497,
    SPELL_REMNANT_TIMER                             = 365291,
    SPELL_RETURN_TO_KINGSMOURNE                     = 363022,
    SPELL_RETURN_TO_KINGSMOURNE_VISUALS             = 363021,
    SPELL_SHADE_DESPAWN_CEREMONY                    = 363023,

    // Remorseless Winter
    SPELL_REMORSELESS_WINTER                        = 362542,
    SPELL_REMORSELESS_WINTER_PERIODIC               = 362543,
    SPELL_REMORSELESS_WINTER_DEBUFF_DAMAGE          = 362545,
    SPELL_REMORSELESS_WINTER_CLEAR                  = 370619,

    // Army of the Dead
    SPELL_ARMY_OF_THE_DEAD                          = 362862,
    SPELL_ECHOES_OF_ANDORHAL                        = 362863,
    SPELL_ECHOES_OF_ANDORHAL_FIENDISH_GHOULS        = 362864,
    SPELL_ECHOES_OF_ANDORHAL_MONSTROUS_SOUL         = 363025,

    // March of the Damned
    SPELL_MARCH_OF_THE_DAMNED                       = 363116,
    SPELL_MARCH_OF_THE_DAMNED_PERIODIC              = 363233,
    SPELL_MARCH_OF_THE_DAMNED_AREATRIGGER           = 363133,
    SPELL_MARCH_OF_THE_DAMNED_DAMAGE                = 364020,
    SPELL_DESPAWN_WALLS                             = 371694,

    // Soul Reaper
    SPELL_SOUL_REAPER                               = 362771,
    SPELL_SOUL_REAPER_PHYSICAL_DAMAGE               = 362772,
    SPELL_SOUL_REAPER_SHADOWFROST_DAMAGE            = 362773,
    SPELL_SOUL_REAPER_DEBUFF                        = 362774,
    SPELL_SOUL_REAPER_ATTACK_SPEED                  = 362775,

    // Finish Encounter
    SPELL_ANDUIN_KNEEL_POSE                         = 369367,
    SPELL_FINAL_MOVIE                               = 367306,
    SPELL_AWARD_ANDUIN_KILL                         = 359476,

    // Berserk
    SPELL_BERSERK                                   = 26662,

    // Jaina Spells
    SPELL_BLINK                                     = 362844,
    SPELL_FROSTBOLT                                 = 362843,
    SPELL_GENERIC_BLINK                             = 363984,

    // Sylvanas Spells
    SPELL_SHOOT_BOW                                 = 364068,
    SPELL_TUMBLE                                    = 364069,

    // Uther Spells
    SPELL_BLADE_OF_JUSTICE                          = 363971,
    SPELL_UTHER_CHARGE                              = 363972,

    // Translocators Teleport
    SPELL_TELEPORT_COSMIC_HUB                       = 364475,
    SPELL_TELEPORT_DOMINATIONS_GRASP                = 368563,
};

enum AnduinWrynnPhases
{
    PHASE_ONE = 1,
    PHASE_TWO,
    PHASE_THREE,
};

enum AnduinWrynnEvents
{
    // Anduin Wrynn
    EVENT_HOPEBREAKER = 1,
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
    EVENT_BANISH_SOUL,
    EVENT_BERSERK,

    // Kingsmourne Room
    EVENT_ANDUIN_SOUL,

    // Remnant of a Fallen King
    EVENT_ARMY_OF_THE_DEAD,
    EVENT_SOUL_REAPER,
    EVENT_RETURN_TO_KINGSMOURNE,

    // Fiendish Soul
    EVENT_GHOUL_LEAP,
    EVENT_NECROTIC_CLAWS,

    // Monstrous Soul
    EVENT_UNRAVELING_FRENZY,
    EVENT_NECROTIC_DETONATION,

    // Grim Reflections
    EVENT_PSYCHIC_TERROR,
    EVENT_GRIM_REFLECTION_IMMUNITY,

    // Sylvanas Windrunner
    EVENT_CANCEL_SYLVANAS_EVENTS,
    EVENT_TUMBLE,

    // Uther the Lightbringer
    EVENT_CANCEL_UTHER_EVENTS,
    EVENT_BLADE_OF_JUSTICE,

    // Jaina Proudmoore
    EVENT_CANCEL_JAINA_EVENTS,
    EVENT_BLINK,
};

enum AnduinWrynnActions
{
    ACTION_START_PRE_INTRODUCTION = 1,
    ACTION_START_MOVEMENT,
    ACTION_START_INTRODUCTION,
    ACTION_ARTHAS_INTERMISSION_UTHER,
    ACTION_ARTHAS_INTERMISSION_SYLVANAS,
    ACTION_EXIT_INTERMISSION,
    ACTION_ACTIVATE_REMNANT,
    ACTION_DESPAWN_REMNANT,
    ACTION_SUMMON_KINGSMOURNE_SOULS,
    ACTION_END_ENCOUNTER,
    ACTION_START_OUTRODUCTION,
    ACTION_DESPAIR_GONE,
    ACTION_DOUBT_GONE,
    ACTION_HOPE_RESTORED,

    // Monstrous Soul
    ACTION_NECROTIC_DETONATION,

    // Outroduction
    ACTION_MOVE_NPCS_ON_PLATFORM,
};

enum AnduinWrynnTexts
{
    SAY_AGGRO                           = 0,
    SAY_HOPEBREAKER                     = 1,
    SAY_BEFOULED_BARRIER                = 2,
    SAY_BLASPHEMY                       = 3,
    SAY_ANNOUNCE_BLASPHEMY              = 4,
    SAY_ANNOUNCE_KINGSMOURNE_HUNGERS    = 5,
    SAY_KINGSMOURNE_HUNGERS             = 6,
    SAY_WICKED_STAR                     = 7,
    SAY_ANNOUNCE_WICKED_STAR            = 8,
    SAY_GRIM_REFLECTIONS                = 9,
    SAY_SLAY                            = 10,
    SAY_EMPOWERED_HOPEBREAKER           = 11,
    SAY_DISENGAGE                       = 12,
    SAY_NECROTIC_DETONATION             = 13,
    SAY_ANNOUNCE_EMPOWERED_WICKED_STAR  = 14,
};

enum AnduinWrynnConversations
{
    CONVERSATION_INTRO                  = 17835,
    CONVERSATION_ARTHAS_UTHER           = 17921,
    CONVERSATION_ARTHAS_SYLVANAS        = 17923,
    CONVERSATION_ANDUIN_PHASE_THREE     = 17924,
    CONVERSATION_ANDUIN_OUTRODUCTION    = 17836,
};

enum AnduinWrynnSpawnGroups
{
    SPAWN_GROUP_INITIAL         = 0
};

enum AnduinWrynnPoints
{
    POINT_START_INTRODUCTION    = 1,
    POINT_ANDUIN_SOUL           = 2,
    POINT_ESCAPE_PLATFORM       = 3,
    POINT_MARCH_OF_THE_DAMNED   = 4,
};

enum AnduinWrynnPaths
{
    PATH_INTRODUCTION_JAINA     = 183664 * 100,
    PATH_INTRODUCTION_UTHER     = 183665 * 100,
    PATH_INTRODUCTION_SYLVANAS  = 183666 * 100,
    PATH_OUTRODUCTION_FIRIM     = 184589 * 100,
    PATH_OUTRODUCTION_THRALL    = 184599 * 100,
    PATH_OUTRODUCTION_BOLVAR    = 184601 * 100,
};

enum AnduinWrynnSpellVisuals
{
    SPELL_VISUAL_CHEST_LOOT     = 114023,
};

constexpr Position PreIntroductionAssistersPositions[3] =
{
    { -3826.9548f, -2626.2761f, 78.9296f, 4.644121f }, // Jaina
    { -3831.6807f, -2626.2761f, 78.9296f, 5.460620f }, // Uther
    { -3818.7300f, -2626.2800f, 78.9296f, 4.558697f }, // Sylvanas
};

//constexpr Position FirimOutroductionPos = { -3830.0156f, -2676.7969f, 91.56402f };
constexpr Position QuartermasterRahmPos = { -3824.9565f, -2673.0190f, 91.44697f, 4.7163963f };
constexpr Position LeftKnightPosition = { -3815.4097f, -2677.1824f, 91.44697f, 4.742376f };
constexpr Position RightKnightPosition = { -3834.6807f, -2677.42360f, 91.44697f, 4.6956997f };

constexpr Position DominationGraspCenter = { -3825.0601f, -2715.4600f, 91.3567f, 1.6260f };

constexpr Position IntermissionAssistersTeleportPosition[3] =
{
    { -3828.472f, -2688.191f, 91.2652f, 1.9153f }, // Sylvanas
    { -3819.519f, -2687.170f, 91.2652f, 2.1812f }, // Uther
    { -3824.960f, -2692.550f, 91.2652f, 1.5733f }, // Jaina
};

constexpr Position AnduinsDespairSpawnPosition = { -3828.355957f, -2704.1875f, 91.350716f, 4.982021f };

constexpr Position AnduinsSoulSpawnPosition = { -3825.060059f, -2715.459961f, 91.356697f, 1.626040f };

constexpr Position AnduinsDoubtSpawnPositions[4] =
{
    {  -3852.638916f, -2687.373291f, 91.348526f, 5.560700f }, // Right of Uther
    {  -3852.845459f, -2742.732666f, 91.348534f, 0.961583f }, // Next Right
    {  -3797.704834f, -2686.685791f, 91.348526f, 3.804689f }, // Left of Sylvanas
    {  -3799.805664f, -2740.925293f, 91.348541f, 2.247305f }, // Next Left
};

constexpr Position AnduinsHopeSpawnPosition[4] =
{
    {  -3825.149414f, -2711.508789f, 91.354919f, 1.463445f }, // In front of Anduin
    {  -3828.751709f, -2715.171875f, 91.354919f, 3.221487f }, // Left of Anduin
    {  -3821.041748f, -2715.296875f, 91.354889f, 0.046978f }, // Right of Anduin
    {  -3825.180664f, -2719.208252f, 91.354820f, 4.741285f }, // Behind Anduin
};

constexpr Position RemnantOfAFallenKingSpawnPosition = { -3825.2466f, -2700.0486f, 91.3650f, 1.3762f };

constexpr Position GrimReflectionsSpawnPositions[4] =
{
    { -3825.389f, -2739.4202f, 91.431305f, 4.8445f}, // back side of Anduin
    { -3849.8438f, -2715.0574f, 91.40953f, 2.9961f}, // left side of Anduin
    { -3825.4966f, -2692.6199f, 91.487495f, 1.4654f}, // in front of Anduin
    { -3800.6980f, -2715.4340f, 91.390780f, 6.2769f}, // right side of Anduin
};

Position const MarchOfTheDamnedSpawnPositions[8] =
{
    { -3839.8489f, -2679.7708f, 91.53031f, 5.1081f }, // First right
    { -3860.8940f, -2701.0051f, 91.53032f, 5.9010f }, // Second Right
    { -3860.5696f, -2729.7344f, 91.53032f, 0.3886f }, // Third Right
    { -3839.6390f, -2750.8890f, 91.53032f, 1.1935f }, // Fourth Right
    { -3811.0625f, -2679.6528f, 91.53031f, 4.3362f }, // First left
    { -3789.8125f, -2700.5088f, 91.53032f, 3.5383f }, // Second Left
    { -3789.2812f, -2729.3160f, 91.53032f, 2.7669f }, // Third Left
    { -3810.4290f, -2751.0903f, 91.53032f, 1.9584f } // Fourth Left
};

constexpr Position BeaconOfHopeSpawnPosition = { -3825.0417f, -2715.3923f, 91.3568f, 0.0f };

constexpr Position ChestLootSpawnPosition = { -3840.9915f, -2741.7847f, 91.26521f, 1.334929f };

class ActivateGhouls : public BasicEvent
{
public:
    ActivateGhouls(Creature* summoner, Creature* owner)
        : _summonerGuid(summoner->GetGUID()), _owner(owner) { }

    bool Execute(uint64 /*time*/, uint32 /*diff*/) override
    {
        if (Creature* _summoner = ObjectAccessor::GetCreature(*_owner, _summonerGuid))
        {
            if (Unit* target = _summoner->AI()->SelectTarget(SelectTargetMethod::Random, 0))
            {
                _owner->SetReactState(REACT_AGGRESSIVE);
                _owner->AI()->AttackStart(target);
            }
        }
        return true;
    }

private:
    ObjectGuid _summonerGuid;
    Creature* _owner;
};

// 181954 - Anduin Wrynn
struct boss_anduin_wrynn : public BossAI
{
    boss_anduin_wrynn(Creature* creature) : BossAI(creature, DATA_ANDUIN_WRYNN),
        _slayTextOnCooldown(false), _intermissionsDone(0), _encounterEnded(false) { }

    void HandleIntroduction()
    {
        if (instance->GetData(DATA_ANDUIN_WRYNN_INTRODUCTION) == DONE)
        {
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetImmuneToAll(false);
            me->SetSpeed(MOVE_RUN, 11.0f);
            me->RemoveAurasDueToSpell(SPELL_ANDUIN_PLUNGE_KINGSMOURNE);
        }
        else
        {
            DoCastSelf(SPELL_ANDUIN_PLUNGE_KINGSMOURNE);
            me->SetUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetImmuneToAll(true);
        }
    }

    void PrepareAssistersForIntermission() const
    {
        if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER_ANDUIN))
        {
            sylvanas->CastSpell(IntermissionAssistersTeleportPosition[0], SPELL_GENERIC_BLINK);
            sylvanas->AttackStop();
            sylvanas->SetSheath(SHEATH_STATE_RANGED);
            sylvanas->SetEmoteState(EMOTE_STATE_READY_BOW);
        }

        if (Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN))
        {
            uther->CastSpell(IntermissionAssistersTeleportPosition[1], SPELL_GENERIC_BLINK);
            uther->AttackStop();
            uther->SetSheath(SHEATH_STATE_MELEE);
            uther->SetEmoteState(EMOTE_STATE_READY2H);
        }

        if (Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_ANDUIN))
        {
            jaina->CastSpell(IntermissionAssistersTeleportPosition[2], SPELL_GENERIC_BLINK);
            jaina->AttackStop();
            jaina->SetSheath(SHEATH_STATE_RANGED);
            jaina->SetEmoteState(EMOTE_STATE_READY2H);
        }
    }

    void ForceAssistersToAttackRemnant() const
    {
        Unit* remnant = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING);
        if (!remnant)
            return;

        auto forceAttack = [this, remnant](uint32 data)
        {
            Creature* creature = instance->GetCreature(data);
            if (!creature)
                return;

            creature->AI()->AttackStart(remnant);
            creature->SetReactState(REACT_AGGRESSIVE);
        };

        forceAttack(DATA_SYLVANAS_WINDRUNNER_ANDUIN);
        forceAttack(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN);
        forceAttack(DATA_JAINA_PROUDMOORE_ANDUIN);
    }

    void MoveKnightsOnPlatform() const
    {
        if (Creature* rahm = instance->GetCreature(DATA_QUARTERMASTER_RAHM_ANDUIN))
            rahm->NearTeleportTo(QuartermasterRahmPos);

        std::list<Creature*> knights;
        me->GetCreatureListWithOptionsInGrid(knights, 150.0f, { .CreatureId = NPC_KNIGHT_OF_EBON_BLADE_ANDUIN });

        for (Creature* knight : knights)
        {
            if (knight->HasStringId("left_knight"))
                knight->NearTeleportTo(LeftKnightPosition);
            else
                knight->NearTeleportTo(RightKnightPosition);
        }
    }

    void ClearDebuffs() const
    {
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPEBREAKER_DEBUFF);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLASPHEMY_OVERCONFIDENCE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLASPHEMY_HOPELESSNESS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_DOMINATION_WORD_PAIN);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BEFOULED_BARRIER_DEBUFF);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BEFOULED_BARRIER_EXPLODE);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LOST_SOUL_DIMENSION);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FORCE_OF_WILL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SCARRED_SOUL);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WEATHER_COSMETIC);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_REMORSELESS_WINTER_PERIODIC);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPELESSNESS_HOPELESSNESS_AREATRIGGER);
    }

    void JustAppeared() override
    {
        scheduler.ClearValidator();
        HandleIntroduction();
        me->SetEmoteState(EMOTE_STATE_READY2H);
        me->ModifyPower(me->GetPowerType(), 0);
        DoCastSelf(SPELL_ANDUIN_PROGRESSION_AURA);
        DoCastSelf(SPELL_POWER_DISPLAY_WILLPOWER, true);
        DoCastSelf(SPELL_DARK_ZEAL_AURA, true);
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 0);
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_INTERMISSION, 0);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        ClearDebuffs();
        Talk(SAY_DISENGAGE);
        if (_encounterEnded == true)
            return;

        _DespawnAtEvade();
        summons.DespawnAll();
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 0);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void Reset() override
    {
        _Reset();
        me->SummonCreatureGroup(SPAWN_GROUP_INITIAL);
        me->SetPower(POWER_ENERGY, 0);

        _slayTextOnCooldown = false;
        _intermissionsDone = 0;
        _encounterEnded = false;
    }

    void KilledUnit(Unit* victim) override
    {
        if (_slayTextOnCooldown == false && !victim->IsPlayer())
        {
            Talk(SAY_SLAY);
            _slayTextOnCooldown = true;
            scheduler.Schedule(3s, [this](TaskContext /*task*/)
            {
                _slayTextOnCooldown = false;
            });
        }
    }

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
                summon->SetReactState(REACT_PASSIVE);
                summon->SetUninteractible(true);
                summon->CastSpell(summon, SPELL_REMNANT_SPAWN);
                break;
            }

            case NPC_MARCH_OF_THE_DAMNED:
            {
                float marchSpeed = 0.0f;
                switch (me->GetMap()->GetDifficultyID())
                {
                    case DIFFICULTY_LFR_NEW:
                    case DIFFICULTY_NORMAL_RAID:
                    case DIFFICULTY_HEROIC_RAID:
                        marchSpeed = 0.40f;
                        break;
                    case DIFFICULTY_MYTHIC_RAID:
                        marchSpeed = 0.60f;
                        break;
                    default:
                        marchSpeed = 0.40f;
                        break;
                }

                summon->SetSpeedRate(MOVE_RUN, marchSpeed);
                summon->SetReactState(REACT_PASSIVE);
                summon->CastSpell(summon, SPELL_MARCH_OF_THE_DAMNED_AREATRIGGER, true);
                scheduler.Schedule(1s, [summon](TaskContext /*task*/)
                {
                    Position exitPlatform = summon->GetFirstCollisionPosition(100.0f, summon->GetAbsoluteAngle(summon));
                    summon->GetMotionMaster()->MovePoint(POINT_MARCH_OF_THE_DAMNED, exitPlatform, false, summon->GetOrientation());
                });
                break;
            }

            case NPC_BEACON_OF_HOPE:
            {
                summon->SetReactState(REACT_PASSIVE);
                summon->CastSpell(summon, SPELL_BEACON_OF_HOPE_AREATRIGGER);
                break;
            }

            default:
                break;
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_GRIM_REFLECTION)
            summon->DespawnOrUnsummon(3s);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        PhaseEvents(PHASE_ONE);
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, PHASE_ONE);
        Talk(SAY_AGGRO);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_START_PRE_INTRODUCTION:
            {
                auto teleportNamed = [this](uint32 data, Position const& position)
                {
                    Creature* creature = instance->GetCreature(data);
                    if (!creature)
                        return;

                    creature->NearTeleportTo(position);
                    creature->CastSpell(creature, SPELL_BROKER_SPAWN, true);
                };

                teleportNamed(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN, PreIntroductionAssistersPositions[0]);
                teleportNamed(DATA_SYLVANAS_WINDRUNNER_ANDUIN, PreIntroductionAssistersPositions[1]);
                teleportNamed(DATA_JAINA_PROUDMOORE_ANDUIN, PreIntroductionAssistersPositions[2]);
                break;
            }
            case ACTION_START_MOVEMENT:
            {
                auto castBrokerSpawn = [this](uint32 data)
                {
                    Creature* creature = instance->GetCreature(data);
                    if (!creature)
                        return;

                    creature->CastSpell(creature, SPELL_BROKER_SPAWN, true);
                };

                castBrokerSpawn(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN);
                castBrokerSpawn(DATA_SYLVANAS_WINDRUNNER_ANDUIN);
                castBrokerSpawn(DATA_JAINA_PROUDMOORE_ANDUIN);
                break;
            }
            case ACTION_START_INTRODUCTION:
            {
                instance->SetData(DATA_ANDUIN_WRYNN_INTRODUCTION, IN_PROGRESS);
                scheduler.Schedule(1ms, [this](TaskContext /*task*/)
                {
                    Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN);
                    if (!uther)
                        return;

                    Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER_ANDUIN);
                    if (!sylvanas)
                        return;

                    Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_ANDUIN);
                    if (!jaina)
                        return;

                    Conversation* convo = Conversation::CreateConversation(CONVERSATION_INTRO, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false);
                    if (!convo)
                        return;

                    convo->AddActor(NPC_UTHER_THE_LIGHTBRINGER_ANDUIN, 1, uther->GetGUID());
                    convo->AddActor(NPC_SYLVANAS_WINDRUNNER_ANDUIN, 2, sylvanas->GetGUID());
                    convo->AddActor(NPC_LADY_JAINA_PROUDMOORE_ANDUIN, 3, jaina->GetGUID());
                    convo->Start();
                });

                scheduler.Schedule(35s, [this](TaskContext /*task*/)
                {
                    instance->SetData(DATA_ANDUIN_WRYNN_INTRODUCTION, DONE);
                    HandleIntroduction();
                });
                break;
            }
            case ACTION_MOVE_NPCS_ON_PLATFORM:
            {
                if (Creature* bolvar = me->GetInstanceScript()->GetCreature(DATA_BOLVAR_FORDRAGON_ANDUIN))
                    bolvar->GetMotionMaster()->MovePath(PATH_OUTRODUCTION_BOLVAR, false);

                if (Creature* thrall = me->GetInstanceScript()->GetCreature(DATA_THRALL_ANDUIN))
                    thrall->GetMotionMaster()->MovePath(PATH_OUTRODUCTION_THRALL, false);

                scheduler.Schedule(10s, [this](TaskContext /*task*/)
                {
                    MoveKnightsOnPlatform();
                });
                break;
            }
            case ACTION_START_OUTRODUCTION:
            {
                Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN);
                if (!uther)
                    break;

                Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER_ANDUIN);
                if (!sylvanas)
                    break;

                Creature* jaina = instance->GetCreature(DATA_JAINA_PROUDMOORE_ANDUIN);
                if (!jaina)
                    break;

                Creature* firim = instance->GetCreature(DATA_FIRIM_ANDUIN);
                if (!firim)
                    break;

                firim->GetMotionMaster()->MovePath(PATH_OUTRODUCTION_FIRIM, false);

                Conversation* convo = Conversation::CreateConversation(CONVERSATION_ANDUIN_OUTRODUCTION, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false);
                if (!convo)
                    break;

                convo->AddActor(NPC_LADY_JAINA_PROUDMOORE_ANDUIN, 1, jaina->GetGUID());
                convo->AddActor(NPC_SYLVANAS_WINDRUNNER_ANDUIN, 2, sylvanas->GetGUID());
                convo->AddActor(NPC_UTHER_THE_LIGHTBRINGER_ANDUIN, 3, uther->GetGUID());
                convo->AddActor(NPC_FIRIM_ANDUIN, 4, firim->GetGUID());
                convo->Start();
                break;
            }
            case ACTION_ARTHAS_INTERMISSION_UTHER:
            {
                instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_INTERMISSION, 1);
                if (Creature* uther = instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN))
                {
                    if (Conversation* convo = Conversation::CreateConversation(CONVERSATION_ARTHAS_UTHER, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false))
                    {
                        convo->AddActor(NPC_UTHER_THE_LIGHTBRINGER_ANDUIN, 1, uther->GetGUID());
                        convo->Start();
                    }
                }
                break;
            }
            case ACTION_ARTHAS_INTERMISSION_SYLVANAS:
            {
                instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_INTERMISSION, 2);
                if (Creature* sylvanas = instance->GetCreature(DATA_SYLVANAS_WINDRUNNER_ANDUIN))
                {
                    if (Conversation* convo = Conversation::CreateConversation(CONVERSATION_ARTHAS_SYLVANAS, me, me->GetPosition(), ObjectGuid::Empty, nullptr, false))
                    {
                        convo->AddActor(NPC_SYLVANAS_WINDRUNNER_ANDUIN, 1, sylvanas->GetGUID());
                        convo->Start();
                    }
                }
                break;
            }
            case ACTION_EXIT_INTERMISSION:
            {
                if (_intermissionsDone == 0)
                {
                    PhaseEvents(PHASE_TWO);
                    scheduler.Schedule(3s, [this](TaskContext /*task*/)
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                    });
                }
                else if (_intermissionsDone == 1)
                {
                    PhaseEvents(PHASE_THREE);
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

        Unit* victim = me->GetVictim();
        if (victim && !victim->IsPlayer())
        {
            EnterEvadeMode(EvadeReason::NoHostiles);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HOPEBREAKER:
                {
                    DoCastSelf(SPELL_HOPEBREAKER);
                    Talk(SAY_HOPEBREAKER);
                    break;
                }
                case EVENT_EMPOWERED_HOPEBREAKER:
                {
                    DoCastSelf(SPELL_EMPOWERED_HOPEBREAKER);
                    Talk(SAY_EMPOWERED_HOPEBREAKER);
                    if (IsMythic())
                        events.Repeat(65500ms);
                    else
                        events.Repeat(58400ms);
                    break;
                }
                case EVENT_DOMINATION_WORD_PAIN:
                {
                    DoCastSelf(SPELL_DOMINATION_WORD_PAIN);
                    break;
                }
                case EVENT_BEFOULED_BARRIER:
                {
                    DoCastSelf(SPELL_BEFOULED_BARRIER);
                    Talk(SAY_BEFOULED_BARRIER);
                    break;
                }
                case EVENT_BLASPHEMY:
                {
                    DoCastSelf(SPELL_BLASPHEMY);
                    Talk(SAY_ANNOUNCE_BLASPHEMY);
                    Talk(SAY_BLASPHEMY);
                    break;
                }
                case EVENT_HOPELESSNESS:
                {
                    DoCastAOE(SPELL_HOPELESSNESS);
                    Talk(SAY_BLASPHEMY);
                    if (IsMythic())
                        events.Repeat(65500ms);
                    else
                        events.Repeat(58500ms);
                    break;
                }
                case EVENT_WICKED_STAR:
                {
                    DoCastSelf(SPELL_WICKED_STAR);
                    Talk(SAY_WICKED_STAR);
                    if (events.IsInPhase(PHASE_THREE))
                        events.Repeat(58500ms);
                    break;
                }
                case EVENT_EMPOWERED_WICKED_STAR:
                {
                    DoCastSelf(SPELL_EMPOWERED_WICKED_STAR, true);
                    Talk(SAY_WICKED_STAR);
                    if (IsMythic())
                        events.Repeat(65500ms);
                    else
                        events.Repeat(58500ms);
                    break;
                }
                case EVENT_KINGSMOURNE_HUNGERS:
                {
                    DoCastSelf(SPELL_KINGSMOURNE_HUNGERS);
                    Talk(SAY_ANNOUNCE_KINGSMOURNE_HUNGERS);
                    Talk(SAY_KINGSMOURNE_HUNGERS);
                    break;
                }
                case EVENT_GRIM_REFLECTIONS:
                {
                    Talk(SAY_GRIM_REFLECTIONS);
                    DoCastSelf(SPELL_GRIM_REFLECTIONS);
                    break;
                }
                case EVENT_BEACON_OF_HOPE:
                {
                    DoCastSelf(SPELL_BEACON_OF_HOPE);
                    break;
                }
                case EVENT_INTERMISSION_ONE:
                {
                    StartIntermission(0);
                    break;
                }
                case EVENT_INTERMISSION_TWO:
                {
                    StartIntermission(1);
                    break;
                }
                case EVENT_BERSERK:
                {
                    DoCastSelf(SPELL_BERSERK);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

    void StartIntermission(uint8 intermissionNum)
    {
        auto SpawnRemnant = [this](TaskContext /*task*/)
        {
            if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                me->CastSpell(arthas, SPELL_SPAWN_REMNANT);
        };

        Seconds timeOffset = intermissionNum * 1s;

        scheduler.Schedule(1ms, [this](TaskContext /*task*/)
        {
            me->SetReactState(REACT_PASSIVE);
            me->CastSpell(DominationGraspCenter, SPELL_SHADESTEP);
            PrepareAssistersForIntermission();
        });

        scheduler.Schedule(1204ms + timeOffset, [this, intermissionNum](TaskContext /*task*/)
        {
            DoAction(intermissionNum == 0 ? ACTION_ARTHAS_INTERMISSION_UTHER : ACTION_ARTHAS_INTERMISSION_SYLVANAS);
        });

        scheduler.Schedule(2204ms + timeOffset, [this](TaskContext /*task*/)
        {
            me->SetFacingTo(1.626040f);
        });

        scheduler.Schedule(4s + timeOffset, [this](TaskContext /*task*/)
        {
            DoCastSelf(SPELL_FORCE_OF_WILL);
            DoCastSelf(SPELL_HOPEBREAKER_CLEAR);
            DoCastSelf(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);

            if (Creature* arthas = me->SummonCreature(BOSS_REMNANT_OF_A_FALLEN_KING, RemnantOfAFallenKingSpawnPosition, TEMPSUMMON_MANUAL_DESPAWN))
            {
                me->CastSpell(arthas, SPELL_DOMINATION_GRASP);
                me->CastSpell(arthas, SPELL_SPAWN_REMNANT);
            }
        });

        scheduler.Schedule(5s + timeOffset, SpawnRemnant);

        scheduler.Schedule(6s + timeOffset, SpawnRemnant);

        scheduler.Schedule(7s + timeOffset, SpawnRemnant);

        scheduler.Schedule(8s + timeOffset, [this, intermissionNum](TaskContext /*task*/)
        {
            if (intermissionNum == 1 || IsMythic())
                DoCastSelf(SPELL_MARCH_OF_THE_DAMNED_PERIODIC);

            if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
            {
                me->CastSpell(arthas, SPELL_SPAWN_REMNANT);
                arthas->SetImmuneToAll(false);
                ForceAssistersToAttackRemnant();
            }
        });
    }

    void PhaseEvents(uint8 phase)
    {
        events.Reset();

        switch (phase)
        {
            case PHASE_ONE:
            {
                events.SetPhase(PHASE_ONE);
                events.ScheduleEventSeries(EVENT_HOPEBREAKER, { 5s, 31900ms, 28s, 29900ms, 29900ms });
                events.ScheduleEventSeries(EVENT_BEFOULED_BARRIER, { 17s, 51900ms, 48s });
                events.ScheduleEventSeries(EVENT_BLASPHEMY, { 30s, 49900ms, 54900ms });
                events.ScheduleEventSeries(EVENT_WICKED_STAR, { 55s, 35s, 30s });
                events.ScheduleEventSeries(EVENT_DOMINATION_WORD_PAIN, { 7s, 13s, 13s, 10s, 15s, 13100ms, 12900ms, 13s, 13900ms, 12200ms, 14800ms });
                events.ScheduleEvent(EVENT_INTERMISSION_ONE, 150s);
                events.ScheduleEvent(EVENT_BERSERK, 15min);

                if (IsLFR())
                    DoCastSelf(SPELL_ANDUIN_WILLPOWER_PERIODIC, true);
                else
                    events.ScheduleEventSeries(EVENT_KINGSMOURNE_HUNGERS, { 45s, 1min });
                break;
            }

            case PHASE_TWO:
            {
                _intermissionsDone = 1;
                me->ModifyPower(me->GetPowerType(), 0);
                events.SetPhase(PHASE_TWO);
                events.ScheduleEventSeries(EVENT_GRIM_REFLECTIONS, { 8700ms, 87s });
                events.ScheduleEventSeries(EVENT_BEFOULED_BARRIER, { 80600ms, 47s });
                events.ScheduleEvent(EVENT_INTERMISSION_TWO, 169s);

                if (!IsMythic())
                {
                    events.ScheduleEventSeries(EVENT_DOMINATION_WORD_PAIN, { 11500ms, 13s, 13s, 17700ms, 8100ms, 13s, 13s, 14400ms, 11200ms, 12200ms });
                    events.ScheduleEventSeries(EVENT_HOPEBREAKER, { 13600ms, 22s, 33300ms, 29s, 29s });
                    events.ScheduleEventSeries(EVENT_WICKED_STAR, { 18500ms, 39s, 26s, 30500ms, 19s });
                }
                else
                {
                    events.ScheduleEventSeries(EVENT_DOMINATION_WORD_PAIN, { 10700ms, 13s, 13s, 17700ms, 8100ms, 13s, 13s, 14400ms, 11200ms, 12200ms });
                    events.ScheduleEventSeries(EVENT_HOPEBREAKER, { 13600ms, 25s, 33s, 29s, 29100ms });
                    events.ScheduleEventSeries(EVENT_WICKED_STAR, { 18500ms, 39s, 26s, 30900ms, 19100ms });
                }

                if (IsLFR())
                    DoCastSelf(SPELL_ANDUIN_WILLPOWER_PERIODIC, true);
                else
                    events.ScheduleEventSeries(EVENT_KINGSMOURNE_HUNGERS, { 48600ms, 1min });
                break;
            }

            case PHASE_THREE:
            {
                _intermissionsDone = 2;
                me->ModifyPower(me->GetPowerType(), 0);
                Conversation::CreateConversation(CONVERSATION_ANDUIN_PHASE_THREE, me, me->GetPosition(), ObjectGuid::Empty, nullptr, true);
                events.SetPhase(PHASE_THREE);
                events.ScheduleEvent(EVENT_BEACON_OF_HOPE, 1ms);
                events.ScheduleEvent(EVENT_EMPOWERED_HOPEBREAKER, 11500ms);
                events.ScheduleEvent(EVENT_HOPELESSNESS, 21700ms);

                if (!IsMythic())
                    events.ScheduleEvent(EVENT_WICKED_STAR, 41s);
                else
                    events.ScheduleEvent(EVENT_EMPOWERED_WICKED_STAR, 41s);
                break;
            }
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (_intermissionsDone < 2 && me->HealthBelowPctDamaged(10, damage))
        {
            me->RemoveAurasDueToSpell(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
            me->RemoveAurasDueToSpell(SPELL_MARCH_OF_THE_DAMNED_PERIODIC);
            scheduler.Schedule(6s, [this](TaskContext /*task*/)
            {
                me->SetReactState(REACT_AGGRESSIVE);
            });

            scheduler.CancelAll();
            me->SetReactState(REACT_AGGRESSIVE);
            PhaseEvents(PHASE_THREE);

            std::list<Creature*> fiendishSouls;
            GetCreatureListWithEntryInGrid(fiendishSouls, me, NPC_FIENDISH_SOUL, 50.0f);

            for (Creature* fiends : fiendishSouls)
            {
                fiends->CastSpell(fiends, SPELL_SOUL_DESPAWN);
                fiends->DespawnOrUnsummon(500ms);
            }

            std::list<Creature*> marches;
            GetCreatureListWithEntryInGrid(marches, me, NPC_MARCH_OF_THE_DAMNED, 50.0f);

            for (Creature* march : marches)
                march->DespawnOrUnsummon();

            if (Creature* remnant = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
                remnant->GetAI()->DoAction(ACTION_DESPAWN_REMNANT);
        }
    }

    void EndEncounter()
    {
        ClearDebuffs();
        events.Reset();
        scheduler.CancelAll();
        _encounterEnded = true;
        instance->SetBossState(DATA_ANDUIN_WRYNN, DONE);
        _EnterEvadeMode();
        DoCastSelf(SPELL_ANDUIN_KNEEL_POSE);

        if (Creature* beacon = instance->GetCreature(DATA_BEACON_OF_HOPE))
            beacon->DespawnOrUnsummon();

        me->SetReactState(REACT_PASSIVE);
        me->SetFaction(FACTION_FRIENDLY);
        instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_COMPLETED, 1);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DoAction(ACTION_MOVE_NPCS_ON_PLATFORM);

        if (GameObject* chest = me->SummonGameObject(GAMEOBJECT_ANDUIN_CHEST_LOOT, ChestLootSpawnPosition, QuaternionData::fromEulerAnglesZYX(-225.0f, 0.0f, 0.0f), 7_days))
        {
            chest->SetGoState(GO_STATE_ACTIVE);
            chest->SetSpellVisualId(SPELL_VISUAL_CHEST_LOOT, ObjectGuid::Empty);
        }

        scheduler.Schedule(5s, [this](TaskContext /*task*/)
        {
            instance->DoCastSpellOnPlayers(SPELL_FINAL_MOVIE);
        });
    }

private:
    bool _slayTextOnCooldown;
    uint8 _intermissionsDone;
    bool _encounterEnded;
};

// 184830 - Beacon of Hope
struct npc_anduin_wrynn_beacon_of_hope : public ScriptedAI
{
    npc_anduin_wrynn_beacon_of_hope(Creature* creature) : ScriptedAI(creature) { }

    void JustUnregisteredAreaTrigger(AreaTrigger* areaTrigger) override
    {
        switch (areaTrigger->GetSpellId())
        {
            case SPELL_FRAGMENT_OF_HOPE_AREATRIGGER:
            {
                if (!areaTrigger->GetInsideUnits().empty())
                    break;

                InstanceScript* instance = me->GetInstanceScript();
                if (!instance)
                    break;

                if (Creature* beacon = instance->GetCreature(DATA_BEACON_OF_HOPE))
                    beacon->CastSpell(beacon, SPELL_FRAGMENT_OF_HOPE_DAMAGE, true);
                break;
            }
            default:
                break;
        }
    }
};

// 183452 - Empty Vessel
struct npc_anduin_wrynn_empty_vessel : public ScriptedAI
{
    npc_anduin_wrynn_empty_vessel(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (!summoner->IsPlayer())
            return;

        summoner->CastSpell(me, SPELL_MIRROR_IMAGE);
        DoCast(me, SPELL_FEIGN_DEATH);
    }
};

// 185607 - Lost Soul
struct npc_anduin_wrynn_lost_soul : public ScriptedAI
{
    npc_anduin_wrynn_lost_soul(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_PASSIVE);
        _events.ScheduleEvent(EVENT_BANISH_SOUL, 1ms);
    }

    void IsSummonedBy(WorldObject* summoner) override
    {
        if (!summoner->IsPlayer())
            return;

        summoner->CastSpell(me, SPELL_LOST_SOUL_MIRROR_IMAGE);
    }

    void JustDied(Unit* /*killer*/) override
    {
        TempSummon* summon = me->ToTempSummon();
        if (!summon)
            return;

        if (Unit* summoner = summon->GetSummonerUnit())
        {
            summoner->RemoveAurasDueToSpell(SPELL_SEVERED_SOUL);
            summoner->NearTeleportTo(me->GetPosition());
        }
        me->DespawnOrUnsummon(2s);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BANISH_SOUL:
                {
                    DoCastSelf(SPELL_BANISH_SOUL);
                    _events.Repeat(1ms);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 184519 - Anduin's Soul
struct npc_anduin_wrynn_anduin_soul : public ScriptedAI
{
    npc_anduin_wrynn_anduin_soul(Creature* creature) : ScriptedAI(creature),
        _hopeRestored(0), _doubtGone(0), _despairGone(0), _summons(me) { }

    void CheckForReleaseFromKingsmourne()
    {
        if (_hopeRestored == 4 && _doubtGone == 4 && _despairGone == 1)
        {
            DoCastAOE(SPELL_LOST_SOUL_CLEAR, true);
            _hopeRestored = 0;
            _doubtGone = 0;
            _despairGone = 0;
        }
    }

    void JustAppeared() override
    {
        me->SetDisableGravity(true, true);
        me->SetHoverHeight(1.0);
        DoCastSelf(SPELL_LOST_SOUL_PERIODIC);
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
        InstanceScript* instance = me->GetInstanceScript();
        if (!instance)
            return;

        Creature* anduin = instance->GetCreature(DATA_ANDUIN_SOUL);
        if (!anduin)
            return;

        switch (action)
        {
            case ACTION_SUMMON_KINGSMOURNE_SOULS:
            {
                me->SummonCreature(NPC_ANDUIN_DESPAIR, AnduinsDespairSpawnPosition, TEMPSUMMON_TIMED_DESPAWN, 40s);
                for (uint8 i = 0; i < 4; i++)
                {
                    me->SummonCreature(NPC_ANDUIN_DOUBT, AnduinsDoubtSpawnPositions[i], TEMPSUMMON_TIMED_DESPAWN, 40s);
                    me->SummonCreature(NPC_ANDUIN_HOPE, AnduinsHopeSpawnPosition[i], TEMPSUMMON_TIMED_DESPAWN, 40s);
                }
                break;
            }
            case ACTION_DESPAIR_GONE:
                _despairGone++;
                CheckForReleaseFromKingsmourne();
                break;

            case ACTION_DOUBT_GONE:
                _doubtGone++;
                CheckForReleaseFromKingsmourne();
                break;

            case ACTION_HOPE_RESTORED:
                _hopeRestored++;
                CheckForReleaseFromKingsmourne();
                break;

            default:
                break;
        }
    }

public:
    uint8 _hopeRestored;
    uint8 _doubtGone;
    uint8 _despairGone;
    SummonList _summons;
};

// 184520 - Anduin's Despair
struct npc_anduin_wrynn_anduin_despair : public ScriptedAI
{
    npc_anduin_wrynn_anduin_despair(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void JustAppeared() override
    {
        DoCastSelf(SPELL_RAIN_OF_DESPAIR);
        DoCastSelf(SPELL_ANDUIN_SOUL_DESPAIR);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_POWER_ENERGIZE_WILLPOWER_LARGE);

        if (Creature* soul = _instance->GetCreature(DATA_ANDUIN_SOUL))
            soul->GetAI()->DoAction(ACTION_DESPAIR_GONE);
    }

private:
    InstanceScript* _instance;
};

// 184494 - Anduin's Doubt
struct npc_anduin_wrynn_anduin_doubt : public ScriptedAI
{
    npc_anduin_wrynn_anduin_doubt(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetWalk(true);
        DoCastSelf(SPELL_GHOST_VISUAL_COSMETIC, true);
        DoZoneInCombat();
        me->GetMotionMaster()->MovePoint(POINT_ANDUIN_SOUL, AnduinsSoulSpawnPosition);
    }

    void JustDied(Unit* /*killer*/) override
    {
        DoCastSelf(SPELL_POWER_ENERGIZE_WILLPOWER_SMALL);
        DoCastSelf(SPELL_SOUL_DESPAWN);

        if (Creature* soul = me->GetInstanceScript()->GetCreature(DATA_ANDUIN_SOUL))
            soul->GetAI()->DoAction(ACTION_DOUBT_GONE);
    }

    void UpdateAI(uint32 /*diff*/) override
    {
        UpdateVictim();
    }
};

// 184493 - Anduin's Hope
struct npc_anduin_wrynn_anduin_hope : public ScriptedAI
{
    npc_anduin_wrynn_anduin_hope(Creature* creature) : ScriptedAI(creature),
        _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        me->SetRegenerateHealth(false);
        me->SetHealth(1);
        me->SetReactState(REACT_PASSIVE);
    }

    void JustAppeared() override
    {
        _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 255);
        me->SetWalk(true);
        DoCastSelf(SPELL_ANDUIN_SLOW);
        if (IsHeroic() || IsMythic())
            DoCastSelf(SPELL_GLOOM);

        _scheduler.Schedule(2s, [this](TaskContext /*task*/)
        {
            Position exitPlatform = me->GetFirstCollisionPosition(100.0f, 0);
            me->GetMotionMaster()->MovePoint(POINT_ESCAPE_PLATFORM, exitPlatform, false, me->GetOrientation());
        });
        me->SetHealth(1);

        _scheduler.Schedule(40s, [this](TaskContext /*task*/)
        {
            me->DespawnOrUnsummon();
        });
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        _scheduler.Update(diff);
    }

    void HealReceived(Unit* /*healer*/, uint32& heal) override
    {
        if (me->HealthAbovePctHealed(100, heal))
        {
            _instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            DoCastSelf(SPELL_POWER_ENERGIZE_WILLPOWER_SMALL);
            DoCastSelf(SPELL_SOUL_DESPAWN);

            if (Creature* soul = _instance->GetCreature(DATA_ANDUIN_SOUL))
                soul->GetAI()->DoAction(ACTION_HOPE_RESTORED);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_ESCAPE_PLATFORM:
            {
                DoCastSelf(SPELL_SOUL_DESPAWN);
                break;
            }
            default:
                break;
        }
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
};

// 183669 - Fiendish Soul
struct npc_anduin_wrynn_fiendish_soul : public ScriptedAI
{
    npc_anduin_wrynn_fiendish_soul(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_GHOUL_LEAP, 1s);
        _events.ScheduleEvent(EVENT_NECROTIC_CLAWS, 10s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (IsHeroic() || IsMythic())
            DoCastSelf(SPELL_SOUL_EXPLOSION_TARGET);

        DoCastSelf(SPELL_SOUL_DESPAWN);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->DespawnOrUnsummon();
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
                case EVENT_GHOUL_LEAP:
                {
                    std::list<Player*> targetList;
                    GetPlayerListInGrid(targetList, me, 50.0f);
                    if (!targetList.empty())
                        me->CastSpell(Trinity::Containers::SelectRandomContainerElement(targetList), SPELL_NECROTIC_CLAWS_LEAP);
                    _events.Repeat(10s);
                    break;
                }
                case EVENT_NECROTIC_CLAWS:
                {
                    DoCastVictim(SPELL_NECROTIC_CLAWS_DEBUFF);
                    _events.Repeat(5s, 10s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 183671 - Monstrous Soul
struct npc_anduin_wrynn_monstrous_soul : public ScriptedAI
{
    npc_anduin_wrynn_monstrous_soul(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* /*who*/) override
    {
        me->GetInstanceScript()->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 255);
        DoCastSelf(SPELL_UNRAVELING_FRENZY_PERIODIC, true);
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (me->HealthBelowPctDamaged(35, damage))
            _events.ScheduleEvent(EVENT_NECROTIC_DETONATION, 1ms);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_NECROTIC_DETONATION:
            {
                Talk(SAY_NECROTIC_DETONATION);
                DoCastSelf(SPELL_NECROTIC_DETONATION);
                break;
            }
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        me->GetInstanceScript()->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        me->GetInstanceScript()->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        me->DespawnOrUnsummon();
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
                case EVENT_NECROTIC_DETONATION:
                {
                    Talk(SAY_NECROTIC_DETONATION);
                    DoCastSelf(SPELL_NECROTIC_DETONATION);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

// 183463 - Remnant of a Fallen King
struct boss_remnant_of_a_fallen_king : public ScriptedAI
{
    boss_remnant_of_a_fallen_king(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()), _summons(creature) { }

    void JustAppeared() override
    {
        _scheduler.ClearValidator();
        DoCastSelf(SPELL_SHADE_VISUAL);
        me->ModifyPower(me->GetPowerType(), 0);
        me->SetPower(me->GetPowerType(), 0);
        for (MapReference const& players : me->GetMap()->GetPlayers())
        {
            if (Player* player = players.GetSource())
                me->CastSpell(player, SPELL_WEATHER_COSMETIC, true);
        }
        _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_HOPEBREAKER);
        me->SetReactState(REACT_PASSIVE);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _summons.DespawnAll();
        me->DespawnOrUnsummon();

        if (Creature* anduin = _instance->GetCreature(DATA_ANDUIN_WRYNN))
            anduin->AI()->EnterEvadeMode(EvadeReason::NoHostiles);

        _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_WEATHER_COSMETIC);
        _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_REMORSELESS_WINTER_PERIODIC);
        _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NECROTIC_CLAWS_DEBUFF);
        _instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_FORCE_OF_WILL);
    }

    void ContinueAttacking() const
    {
        if (Creature* sylvanas = _instance->GetCreature(DATA_SYLVANAS_WINDRUNNER_ANDUIN))
            sylvanas->GetAI()->AttackStartCaster(me, 25.0f);

        if (Creature* uther = _instance->GetCreature(DATA_UTHER_THE_LIGHTBRINGER_ANDUIN))
            uther->GetAI()->AttackStart(me);

        if (Creature* jaina = _instance->GetCreature(DATA_JAINA_PROUDMOORE_ANDUIN))
            jaina->GetAI()->AttackStartCaster(me, 25.0f);
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);

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
                DoCastAOE(SPELL_DARK_PRESENCE);
                DoZoneInCombat();

                _scheduler.Schedule(1500ms, [this](TaskContext /*task*/)
                {
                    _instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 2);
                    me->SetUninteractible(false);
                });

                _scheduler.Schedule(2s, [this](TaskContext /*task*/)
                {
                    DoCastSelf(SPELL_REMNANT_TIMER);
                    _events.ScheduleEvent(EVENT_ARMY_OF_THE_DEAD, 1ms);
                    _events.ScheduleEvent(EVENT_SOUL_REAPER, 8000ms);
                    _events.ScheduleEvent(EVENT_RETURN_TO_KINGSMOURNE, 67500ms);
                    me->SetReactState(REACT_AGGRESSIVE);
                    ContinueAttacking();
                });
                break;
            }
            case ACTION_DESPAWN_REMNANT:
            {
                DoCastSelf(SPELL_SOUL_DESPAWN);
                _scheduler.Schedule(500ms, [this](TaskContext /*task*/)
                {
                    EnterEvadeMode(EvadeReason::Other);
                });
                break;
            }
            default:
                break;
        }
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
                case EVENT_RETURN_TO_KINGSMOURNE:
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->InterruptNonMeleeSpells(true);
                    DoCastSelf(SPELL_RETURN_TO_KINGSMOURNE);
                    break;
                }
                case EVENT_ARMY_OF_THE_DEAD:
                {
                    DoCastSelf(SPELL_ARMY_OF_THE_DEAD);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (!IsLFR())
                        _events.Repeat(36900ms);
                    break;
                }
                case EVENT_SOUL_REAPER:
                {
                    DoCastVictim(SPELL_SOUL_REAPER);
                    _events.Repeat(12s);
                    break;
                }
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
    SummonList _summons;
};

// 183033 - Grim Reflection
struct npc_anduin_wrynn_grim_reflection : public ScriptedAI
{
    npc_anduin_wrynn_grim_reflection(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustAppeared() override
    {
        SetCombatMovement(false);
        DoCastSelf(SPELL_CALAMITY_STATE_VISUAL);
        DoZoneInCombat();
        me->SetReactState(REACT_AGGRESSIVE);
        _events.ScheduleEvent(EVENT_PSYCHIC_TERROR, 1ms);

        if (IsLFR() || IsNormal())
            _events.ScheduleEvent(EVENT_GRIM_REFLECTION_IMMUNITY, 1ms);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (IsMythic())
            DoCastAOE(SPELL_GRIM_FATE);
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
                {
                    DoCastSelf(SPELL_PSYCHIC_TERROR);
                    _events.Repeat(2s);
                    break;
                }
                case EVENT_GRIM_REFLECTION_IMMUNITY:
                {
                    DoCastSelf(SPELL_WICKED_STAR_PROTECTION);
                    _events.Repeat(1s);
                    break;
                }
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap _events;
};

// 183666 - Sylvanas Windrunner
struct npc_anduin_wrynn_sylvanas : public ScriptedAI
{
    npc_anduin_wrynn_sylvanas(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetCanMelee(false); // DoSpellAttackIfReady
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_TUMBLE, 10s);
    }

    bool CanAIAttack(Unit const* target) const override
    {
        return !target->HasAura(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
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
    EventMap _events;
};

// 183664 - Jaina Proudmoore
struct npc_anduin_wrynn_jaina : public ScriptedAI
{
    npc_anduin_wrynn_jaina(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
        me->SetCanMelee(false); // DoSpellAttackIfReady
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_BLINK, 10s);
    }

    bool CanAIAttack(Unit const* target) const override
    {
        return !target->HasAura(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
    }

    void WaypointPathEnded(uint32 /*nodeId*/, uint32 pathId) override
    {
        if (pathId != PATH_INTRODUCTION_JAINA)
            return;

        if (Creature* anduin = me->GetInstanceScript()->GetCreature(DATA_ANDUIN_WRYNN))
            anduin->GetAI()->DoAction(ACTION_START_INTRODUCTION);
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
                case EVENT_CANCEL_JAINA_EVENTS:
                {
                    _events.CancelEvent(EVENT_BLINK);
                    break;
                }
                case EVENT_BLINK:
                {
                    DoCastSelf(SPELL_BLINK);
                    _events.Repeat(60s);
                    break;
                }
                default:
                    break;
            }
        }

        DoSpellAttackIfReady(SPELL_FROSTBOLT);
    }

private:
    EventMap _events;
};

// 183665 - Uther the Lightbringer
struct npc_anduin_wrynn_uther : public ScriptedAI
{
    npc_anduin_wrynn_uther(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        me->SetReactState(REACT_AGGRESSIVE);
    }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        DoCast(who, SPELL_UTHER_CHARGE);
        _events.ScheduleEvent(EVENT_BLADE_OF_JUSTICE, 3s);
    }

    bool CanAIAttack(Unit const* target) const override
    {
        return !target->HasAura(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
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
                case EVENT_CANCEL_UTHER_EVENTS:
                {
                    _events.CancelEvent(EVENT_BLADE_OF_JUSTICE);
                    break;
                }
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
    }

private:
    EventMap _events;
};

// 367524 - Spawn Pre-Introduction
class spell_anduin_wrynn_pre_introduction : public AuraScript
{
    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        switch (caster->GetEntry())
        {
            case NPC_LADY_JAINA_PROUDMOORE_ANDUIN:
                caster->NearTeleportTo(PreIntroductionAssistersPositions[0]);
                break;
            case NPC_UTHER_THE_LIGHTBRINGER_ANDUIN:
                caster->NearTeleportTo(PreIntroductionAssistersPositions[1]);
                break;
            case NPC_SYLVANAS_WINDRUNNER_ANDUIN:
                caster->NearTeleportTo(PreIntroductionAssistersPositions[2]);
                break;
            default:
                break;
        }
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        uint32 pathId = 0;
        switch (caster->GetEntry())
        {
            case NPC_LADY_JAINA_PROUDMOORE_ANDUIN:
                pathId = PATH_INTRODUCTION_JAINA;
                break;
            case NPC_UTHER_THE_LIGHTBRINGER_ANDUIN:
                pathId = PATH_INTRODUCTION_UTHER;
                break;
            case NPC_SYLVANAS_WINDRUNNER_ANDUIN:
                pathId = PATH_INTRODUCTION_SYLVANAS;
                break;
            default:
                break;
        }
        caster->GetMotionMaster()->MovePath(pathId, false);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_pre_introduction::OnApply, EFFECT_1, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_pre_introduction::OnRemove, EFFECT_2, SPELL_AURA_MOD_ROOT, AURA_EFFECT_HANDLE_REAL);
    }
};

// 369317 - Anduin Progression Aura (Can't be reduced < 1 hp)
class spell_anduin_wrynn_progression_aura : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_ANDUIN_PROGRESSION_AURA, SPELL_ANDUIN_KNEEL_POSE });
    }

    void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
    {
        amount = -1;
        canBeRecalculated = true;
    }

    void Trigger(AuraEffect* /*aurEff*/, DamageInfo const& dmgInfo, uint32& absorbAmount)
    {
        if (!GetTarget()->GetAura(SPELL_ANDUIN_PROGRESSION_AURA))
            return;

        if (dmgInfo.GetDamage() <= GetTarget()->GetHealth())
            return;

        if (dmgInfo.GetDamage() >= GetTarget()->GetHealth())
        {
            absorbAmount = dmgInfo.GetDamage();
            if (_triggered)
                return;

            GetTarget()->SetHealth(1);
            GetTarget()->CastSpell(GetTarget(), SPELL_ANDUIN_KNEEL_POSE);
            GetTarget()->GetAI()->DoAction(ACTION_END_ENCOUNTER);
            _triggered = true;
        }
    }

    void Register() override
    {
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_progression_aura::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_anduin_wrynn_progression_aura::Trigger, EFFECT_0);
    }

private:
    bool _triggered = false;
};

// 366848 - Anduin Willpower Periodic (Only LFR)
class spell_anduin_wrynn_energize_willpower_lfr : public AuraScript
{
    static constexpr std::array<int32, 22> AnduinRegenCycle =
    { 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1 }; // 0.681 willpower per second on Retail

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        _powerGained = AnduinRegenCycle[_powerRegenCycle++];

        if (_powerRegenCycle >= 22)
           _powerRegenCycle = 0;

        target->ModifyPower(target->GetPowerType(), _powerGained);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anduin_wrynn_energize_willpower_lfr::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

    uint8 _powerRegenCycle = 0;
    uint32 _powerGained = 0;
};

// 364247 - Dark Zeal
class spell_anduin_wrynn_dark_zeal : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DARK_ZEAL_BUFF });
    }

    void OnProc(AuraEffect* /*aurEff*/, ProcEventInfo const& eventInfo)
    {
        Unit* actionTarget = eventInfo.GetActionTarget();
        if (!actionTarget)
            return;

        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_DARK_ZEAL_BUFF, true);

        if (actionTarget->GetGUID() == _currentTank)
            return;

        target->RemoveAura(SPELL_DARK_ZEAL_BUFF);
        _currentTank = actionTarget->GetGUID();
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_anduin_wrynn_dark_zeal::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }

private:
    ObjectGuid _currentTank;
};

// 361815 - Hopebreaker
// 365806 - Empowered Hopebreaker
class spell_anduin_wrynn_hopebreaker : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HOPEBREAKER_DAMAGE, SPELL_HOPEBREAKER_DEBUFF });
    }

    void HandleHit(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HOPEBREAKER_DAMAGE, true);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HOPEBREAKER_DEBUFF, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_hopebreaker::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 361817 - Hopebreaker Periodic
class spell_anduin_wrynn_hopebreaker_periodic : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HOPEBREAKER_DEBUFF_DAMAGE });
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/) const
    {
        if (!GetCaster())
            return;

        GetCaster()->CastSpell(GetTarget(), SPELL_HOPEBREAKER_DEBUFF_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anduin_wrynn_hopebreaker_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 361818 - Hopebreaker Damage
class spell_anduin_wrynn_hopebreaker_damage : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HOPEBREAKER_DEBUFF });
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();

        Aura* hopebreaker = target->GetAura(SPELL_HOPEBREAKER_DEBUFF);
        if (!hopebreaker)
            return;

        uint8 hopebreakerStacks = hopebreaker->GetStackAmount();
        SetHitDamage(GetHitDamage() * hopebreakerStacks);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_hopebreaker_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 363133 - March of the Damned, CreatePropertiesId - 24093
struct at_anduin_wrynn_march_of_the_damned : AreaTriggerAI
{
    at_anduin_wrynn_march_of_the_damned(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_MARCH_OF_THE_DAMNED_DAMAGE, true);
    }
};

float constexpr BEFOULED_BARRIER_MAX_RADIUS = 12.0f;
float constexpr BEFOULED_BARRIER_MIN_RADIUS = 4.0f;

// 365173 - Befouled Barrier - CreatePropertiesId: 24332
struct at_anduin_wrynn_befouled_barrier : AreaTriggerAI
{
    at_anduin_wrynn_befouled_barrier(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnInitialize() override
    {
        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_BEFOULED_BARRIER_DEBUFF, at->GetMap()->GetDifficultyID()))
            _absorbRequired = spellInfo->GetEffect(EFFECT_0).CalcValue(at->GetCaster());

        at->SetTimeToTargetScale(30000);

        // The aura is handling it automatically
        at->SetDuration(-1);
    }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(500ms, [this](TaskContext task)
        {
            float startRadius = 1.0f;

            UpdateSize(startRadius, BEFOULED_BARRIER_MAX_RADIUS);
            at->SetTimeToTargetScale(500);

            task.Schedule(Milliseconds(at->GetTimeToTargetScale()), [this](TaskContext task)
            {
                UpdateSizeBasedOnAbsorb();
                task.Repeat();
            });
        });
    }

    void UpdateSize(float radius, float targetRadius) const
    {
        std::array<DBCPosition2D, 2> points =
        { {
            { 0.0f, radius },
            { 1.0f, targetRadius }
        } };

        at->SetOverrideScaleCurve(points);
    }

    void UpdateSizeBasedOnAbsorb() const
    {
        Unit* target = at->GetTarget();
        if (!target)
            return;

        float radiusMod = 1.0f - (_absorbDone / (float)_absorbRequired);
        float targetRadius = BEFOULED_BARRIER_MAX_RADIUS * radiusMod;
        float currentRadius = at->GetMaxSearchRadius();

        if (G3D::fuzzyEq(currentRadius, targetRadius))
            return;

        // Players need to be able to actually enter the AT to heal it no sniff has a value lower than 4.0f
        if (targetRadius <= BEFOULED_BARRIER_MIN_RADIUS)
            return;

        UpdateSize(currentRadius, targetRadius);
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        caster->CastSpell(unit, SPELL_BEFOULED_BARRIER_DEBUFF, true);
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAura(SPELL_BEFOULED_BARRIER_DEBUFF);
    }

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
        {
            creature->CastSpell(creature, SPELL_BEFOULED_BARRIER_CLEAR, true);
            creature->DespawnOrUnsummon(1s);
        }
    }

    uint32 GetRemainingAbsorb() const
    {
        return _absorbRequired - _absorbDone;
    }

private:
    uint32 _absorbDone = 0;
    uint32 _absorbRequired = 0;
    TaskScheduler _scheduler;
};

float constexpr BEACON_OF_HOPE_MAX_RADIUS = 12.0f;
float constexpr BEACON_OF_HOPE_MIN_RADIUS = 4.0f;

// 362702 - Beacon of Hope - CreatePropertiesId: 25025 / 24247
struct at_anduin_wrynn_beacon_of_hope : AreaTriggerAI
{
    at_anduin_wrynn_beacon_of_hope(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger),
        _instance(at->GetInstanceScript()), _entries(0), _chargesRemaining(40) { }

    void OnInitialize() override
    {
        _entries = 0;
        _chargesRemaining = 40;
    }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(500ms, [this](TaskContext task)
        {
            float startRadius = 1.0f;
            float targetRadius = BEACON_OF_HOPE_MAX_RADIUS;

            UpdateSize(startRadius, targetRadius);
            at->SetTimeToTargetScale(500);

            task.Schedule(Milliseconds(at->GetTimeToTargetScale()), [this](TaskContext task)
            {
                UpdateSizeBasedOnCharges();
                task.Repeat();
            });
        });
    }

    void UpdateSize(float radius, float targetRadius) const
    {
        std::array<DBCPosition2D, 2> points =
        { {
            { 0.0f, radius },
            { 1.0f, targetRadius }
        } };

        at->SetOverrideScaleCurve(points);
    }

    void UpdateSizeBasedOnCharges() const
    {
        float radiusMod = 0.205129f * _entries;
        float targetRadius = BEACON_OF_HOPE_MAX_RADIUS - radiusMod;

        if (targetRadius <= BEACON_OF_HOPE_MIN_RADIUS || _chargesRemaining <= 0)
            at->Remove();

        float currentRadius = at->GetMaxSearchRadius();
        if (G3D::fuzzyEq(currentRadius, targetRadius))
            return;

        UpdateSize(currentRadius, targetRadius);
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        if (!at->GetCaster())
            return;

        Creature* beacon = _instance->GetCreature(DATA_BEACON_OF_HOPE);
        if (!beacon)
            return;

        beacon->CastSpell(beacon, SPELL_PURGING_LIGHT, true);
        unit->RemoveAurasDueToSpell(SPELL_HOPELESSNESS_HOPELESSNESS_AREATRIGGER);

        if (at->GetMap()->IsMythic())
        {
            _entries++;
            _chargesRemaining--;
            beacon->CastSpell(unit, SPELL_FRAGMENT_OF_HOPE_AREATRIGGER, true);
        }
    }

private:
    InstanceScript* _instance;
    uint8 _entries;
    uint8 _chargesRemaining;
    TaskScheduler _scheduler;
};

// 365816 - Fragment of Hope
class spell_anduin_wrynn_fragment_of_hope : public SpellScript
{
    void SetDest(SpellDestination& destination) const
    {
        Unit* caster = GetCaster();
        Position dest = caster->GetPosition();

        if (Creature* beacon = caster->GetInstanceScript()->GetCreature(DATA_BEACON_OF_HOPE))
            beacon->MovePositionToFirstCollision(dest, 30.0f, beacon->GetAbsoluteAngle(GetExplTargetWorldObject()) - beacon->GetOrientation());

        destination.Relocate(dest);
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_anduin_wrynn_fragment_of_hope::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 365293 - Befouled Barrier
class spell_anduin_wrynn_befouled_barrier_absorb : public AuraScript
{
    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ SPELL_BEFOULED_BARRIER_SPHERE_AREATRIGGER })
            && ValidateSpellEffect({ { spellInfo->Id, EFFECT_2 } });
    }

    void OnHealAbsorb(AuraEffect* /*aurEff*/, HealInfo const& healInfo, uint32& absorbAmount) const
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
        OnEffectAbsorbHeal += AuraEffectAbsorbHealFn(spell_anduin_wrynn_befouled_barrier_absorb::OnHealAbsorb, EFFECT_0);
    }
};

// 365173 - Befouled Barrier Expire
class spell_anduin_wrynn_befouled_barrier_expire : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BEFOULED_BARRIER_SPHERE_AREATRIGGER, SPELL_BEFOULED_BARRIER_EXPLODE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
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

// 361989 - Blasphemy
class spell_anduin_wrynn_blasphemy : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLASPHEMY_PRE_HIT, SPELL_BLASPHEMY_OVERCONFIDENCE, SPELL_BLASPHEMY_HOPELESSNESS });
    }

    void OnPrecast() override
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_BLASPHEMY_PRE_HIT, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        int64 hopelessnessAffected = targets.size() / 2;
        int64 maxAffected = hopelessnessAffected * 2;
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
        }
    }

    void HandleDebuff(SpellEffIndex /*effIndex*/)
    {
        uint32* spellId = Trinity::Containers::MapGetValuePtr(_spellAssignments, GetHitUnit()->GetGUID());
        if (!spellId)
            return;

        GetCaster()->CastSpell(GetHitUnit(), *spellId, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_blasphemy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_blasphemy::HandleDebuff, EFFECT_0, SPELL_EFFECT_DUMMY);
    }

private:
    std::unordered_map<ObjectGuid /*player*/, uint32 /*spell*/> _spellAssignments;
};

// 361992 - Overconfidence CreatePropertiesId: 24616
// 361993 - Hopelessness CreatePropertiesId: 24616
struct at_anduin_wrynn_blasphemy : AreaTriggerAI
{
    at_anduin_wrynn_blasphemy(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)  { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer() || unit->HasAura(SPELL_BLASPHEMY_PRE_HIT))
            return;

        if (!unit->IsAlive())
            at->Remove();

        if (unit->HasAura(at->GetSpellId()))
        {
            uint32 explodeSpellId = SPELL_BLASPHEMY_EXPLODE;
            if (at->GetMap()->IsLFR() || at->GetMap()->IsNormal())
                explodeSpellId = SPELL_BLASPHEMY_EXPLODE_LFR_NORMAL;

            unit->CastSpell(unit, explodeSpellId, true);
            unit->RemoveAurasDueToSpell(at->GetSpellId());
            if (Unit* target = at->GetTarget())
            {
                target->CastSpell(target, explodeSpellId, true);
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
            // On Mythic players walking in with no debuff also trigger explosion
            if (!at->GetMap()->IsMythic())
                return;

            if (!unit->HasAura(SPELL_BLASPHEMY_HOPELESSNESS_AREATRIGGER) || !unit->HasAura(SPELL_BLASPHEMY_OVERCONFIDENCE_AREATRIGGER))
            {
                if (Unit* target = at->GetTarget())
                    target->CastSpell(target, SPELL_BLASPHEMY_EXPLODE, true);
            }
        }
    }
};

// 361992 - Overconfidence
// 361993 - Hopelessness
class spell_anduin_wrynn_hopelessness_overconfidence : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BLASPHEMY_EXPLODE,
            SPELL_BLASPHEMY_EXPLODE_LFR_NORMAL
        });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
        {
            Unit* target = GetTarget();
            uint32 explodeSpellId = SPELL_BLASPHEMY_EXPLODE;
            if (target->GetMap()->IsLFR() || target->GetMap()->IsNormal())
                explodeSpellId = SPELL_BLASPHEMY_EXPLODE_LFR_NORMAL;

            target->CastSpell(target, explodeSpellId, true);
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_hopelessness_overconfidence::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 365021 - Wicked Star
class spell_anduin_wrynn_wicked_star_selector : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 rangedDpsCount = 0;
        for (WorldObject* target : targets)
        {
            Player* targetPlayer = target->ToPlayer();
            if (!targetPlayer)
                continue;

            ChrSpecializationEntry const* spec = targetPlayer->GetPrimarySpecializationEntry();
            if (!spec)
                continue;

            if (!targetPlayer->IsAlive())
                continue;

            if ((spec->GetRole() == ChrSpecializationRole::Dps && spec->GetFlags().HasFlag(ChrSpecializationFlag::Caster)) ||
                (spec->GetRole() == ChrSpecializationRole::Dps && spec->GetFlags().HasFlag(ChrSpecializationFlag::Ranged)))
                rangedDpsCount++;
        }

        targets.remove_if([rangedDpsCount](WorldObject* target) -> bool
        {
            Player* player = target->ToPlayer();
            if (!player || player->HasAura(SPELL_WICKED_STAR_TARGETED))
                return true;

            if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Tank)
                return true;

            if (rangedDpsCount >= 3)
            {
                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Dps && player->GetPrimarySpecializationEntry()->GetFlags().HasFlag(ChrSpecializationFlag::Melee))
                    return true;

                if (player->GetPrimarySpecializationEntry()->GetRole() == ChrSpecializationRole::Healer)
                    return true;
            }
            return false;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_wrynn_wicked_star_selector::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 365021 - Wicked Star
class spell_anduin_wrynn_wicked_star_selector_AuraScript : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WICKED_STAR_TARGETED, GetAreaTriggerSpellID() });
    }

    virtual uint8 GetAnnounceGroupID() const
    {
        return SAY_ANNOUNCE_WICKED_STAR;
    }

    virtual uint32 GetAreaTriggerSpellID() const
    {
        return SPELL_WICKED_STAR_AREATRIGGER;
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        if (!caster)
            return;

        caster->CastSpell(target, SPELL_WICKED_STAR_TARGETED, true);

        if (Creature* creature = caster->ToCreature())
            if (CreatureAI* anduinAI = creature->AI())
                anduinAI->Talk(GetAnnounceGroupID(), target);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        float angle = caster->GetAbsoluteAngle(GetTarget());
        Position spellDest(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), angle);

        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            if (Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN))
                anduin->CastSpell(spellDest, GetAreaTriggerSpellID(), true);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_wicked_star_selector_AuraScript::OnApply, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_wicked_star_selector_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 365017 - Wicked Star CreatePropertiesId: 24741
struct at_anduin_wrynn_wicked_star : AreaTriggerAI
{
    at_anduin_wrynn_wicked_star(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    static constexpr float GetWickedStarSpeed(Difficulty difficulty)
    {
        // in yards per second
        switch (difficulty)
        {
            case DIFFICULTY_HEROIC_RAID:
            case DIFFICULTY_MYTHIC_RAID:
                return 18.0f;
            default: // LFR + Normal
                return 15.0f;
        }
    }

    void OnInitialize() override
    {
        if (Unit* caster = at->GetCaster())
        {
            at->SetOrientation(caster->GetOrientation());

            Position destPos = caster->GetPosition();
            at->MovePositionToFirstCollision(destPos, 100.0f, 0.0f);

            std::vector<G3D::Vector3> splinePoints;
            splinePoints.push_back(PositionToVector3(at->GetPosition()));
            splinePoints.push_back(PositionToVector3(at->GetPosition()));
            splinePoints.push_back(PositionToVector3(destPos));
            splinePoints.push_back(PositionToVector3(at->GetPosition()));
            splinePoints.push_back(PositionToVector3(at->GetPosition()));

            float timeToTarget = at->GetDistance(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ()) * 2 / GetWickedStarSpeed(at->GetMap()->GetDifficultyID()) * 1000;
            at->InitSplines(std::move(splinePoints), timeToTarget);
        }
    }

    void OnUnitEnter(Unit* unit) override
    {
        if (unit->GetEntry() == NPC_SYLVANAS_WINDRUNNER_ANDUIN || unit->GetEntry() == NPC_UTHER_THE_LIGHTBRINGER_ANDUIN ||
            unit->GetEntry() == NPC_LADY_JAINA_PROUDMOORE_ANDUIN || unit->GetEntry() == BOSS_ANDUIN_WRYNN)
            return;

        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        if (caster->IsValidAttackTarget(unit))
            caster->CastSpell(unit, SPELL_WICKED_STAR_DAMAGE_SILENCE, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)));
        else if (caster->IsValidAssistTarget(unit))
            caster->CastSpell(unit, SPELL_WICKED_STAR_EMPOWERMENT, CastSpellExtraArgs(TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS)));
    }

    void OnDestinationReached() override
    {
        at->Remove();
    }
};

// 367632 - Empowered Wicked Star
class spell_anduin_wrynn_empowered_wicked_star_selector_AuraScript : public spell_anduin_wrynn_wicked_star_selector_AuraScript
{
    uint8 GetAnnounceGroupID() const override
    {
        return SAY_ANNOUNCE_EMPOWERED_WICKED_STAR;
    }

    uint32 GetAreaTriggerSpellID() const override
    {
        return SPELL_EMPOWERED_WICKED_STAR_AREATRIGGER;
    }
};

// 367621 - Empowered Wicked Star CreatePropertiesId: 24599
struct at_anduin_wrynn_empowered_wicked_star : public at_anduin_wrynn_wicked_star
{
    at_anduin_wrynn_empowered_wicked_star(AreaTrigger* areatrigger) : at_anduin_wrynn_wicked_star(areatrigger) { }

    static float constexpr EMPOWERED_WICKED_STAR_SPEED = 14.0f; // in yards per second

    void HandleMovement(float angle) const
    {
        Unit* caster = at->GetCaster();
        if (!caster)
            return;

        // hack: when reflection is implemented use at position instead of center; due to mmaps we are causing infinite loop if using at position after dest reach
        Position destPos = DominationGraspCenter;
        at->MovePositionToFirstCollision(destPos, 100.0f, angle);

        std::vector<G3D::Vector3> splinePoints;
        splinePoints.push_back(PositionToVector3(at));
        splinePoints.push_back(PositionToVector3(at));
        splinePoints.push_back(PositionToVector3(destPos));
        splinePoints.push_back(PositionToVector3(destPos));

        float timeToTarget = at->GetDistance(destPos.GetPositionX(), destPos.GetPositionY(), destPos.GetPositionZ()) / EMPOWERED_WICKED_STAR_SPEED * 1000;
        at->InitSplines(std::move(splinePoints), timeToTarget);
    }

    void OnInitialize() override
    {
        HandleMovement(0);
    }

    void OnDestinationReached() override
    {
        // hack: angle should use physical laws for reflection
        HandleMovement(frand(0, 2.0f * float(M_PI)));
    }
};

// 362405 - Kingsmourne Hungers
class spell_anduin_wrynn_kingsmourne_hungers : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_KINGSMOURNE_HUNGERS_DAMAGE,
            SPELL_LOST_SOUL_DIMENSION,
            SPELL_LOST_SOUL,
            SPELL_SEVERED_SOUL
        });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Unit* hitUnit = GetHitUnit();
        caster->CastSpell(hitUnit, SPELL_KINGSMOURNE_HUNGERS_DAMAGE, true);
        if (caster->GetMap()->IsMythic())
            hitUnit->CastSpell(hitUnit, SPELL_SEVERED_SOUL, true);
        caster->CastSpell(hitUnit, SPELL_LOST_SOUL_DIMENSION);
        hitUnit->CastSpell(hitUnit, SPELL_LOST_SOUL, true);
    }

    void OnCast() const
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* anduinSoul = instance->GetCreature(DATA_ANDUIN_SOUL))
            anduinSoul->GetAI()->DoAction(ACTION_SUMMON_KINGSMOURNE_SOULS);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_kingsmourne_hungers::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        AfterCast += SpellCastFn(spell_anduin_wrynn_kingsmourne_hungers::OnCast);
    }
};

// 362055 - Lost Soul
class spell_anduin_wrynn_lost_soul : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_LOST_SOUL_GRACE,
            SPELL_SCARRED_SOUL
        });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        _lostSoulPosition = target->GetPosition();
        target->CastSpell(target, SPELL_LOST_SOUL_GRACE, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* target = GetTarget();
        switch (GetTargetApplication()->GetRemoveMode())
        {
            case AURA_REMOVE_BY_DEFAULT:
            case AURA_REMOVE_BY_ENEMY_SPELL:
                target->CastSpell(target, SPELL_SCARRED_SOUL, true);
                break;
            case AURA_REMOVE_BY_EXPIRE:
            {
                if (target->GetMap()->IsMythic())
                {
                    target->KillSelf();
                    target->NearTeleportTo(_lostSoulPosition);
                }
                break;
            }
            case AURA_REMOVE_BY_DEATH:
            {
                target->CastSpell(target, SPELL_SCARRED_SOUL, true);
                if (target->GetMap()->IsMythic())
                    target->NearTeleportTo(_lostSoulPosition);
                break;
            }
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_lost_soul::OnApply, EFFECT_0, SPELL_AURA_PHASE, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_lost_soul::OnRemove, EFFECT_1, SPELL_AURA_SCREEN_EFFECT, AURA_EFFECT_HANDLE_REAL);
    }

    Position _lostSoulPosition;
};

// 362392 - Rain of Despair
class spell_anduin_rain_of_despair_player_selector : public SpellScript
{
    void HandleDespair(SpellEffIndex effIndex) const
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo(effIndex).TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectLaunchTarget += SpellEffectFn(spell_anduin_rain_of_despair_player_selector::HandleDespair, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 362766 - Soul Despawn
class spell_anduin_wrynn_soul_despawn : public SpellScript
{
    void OnCast() const
    {
        if (Creature* creature = GetCaster()->ToCreature())
            if (creature->GetEntry() == NPC_ANDUIN_HOPE || creature->GetEntry() == NPC_ANDUIN_DOUBT)
                creature->DespawnOrUnsummon(3s);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_anduin_wrynn_soul_despawn::OnCast);
    }
};

// 368913 - Force of Will
class spell_anduin_wrynn_force_of_will : public AuraScript
{
    void RecalculateHook(AuraEffect const* /*aurEffect*/, int32& amount, bool& canBeRecalculated) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // at 100 will power = 200% Damage Done increase
        int32 powerValue = caster->GetPower(caster->GetPowerType());
        amount = 2 * powerValue;
        canBeRecalculated = false;
    }

    void RecalculateHookDamageTaken(AuraEffect const* /*aurEffect*/, int32& amount, bool& canBeRecalculated) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        // Damage Taken reduction can only be capped to 90%
        int32 powerValue = caster->GetPower(caster->GetPowerType());
        amount = -std::min(powerValue, 90);
        canBeRecalculated = false;
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->SetPower(caster->GetPowerType(), 0);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_force_of_will::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE, AURA_EFFECT_HANDLE_REAL);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_force_of_will::RecalculateHook, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_force_of_will::RecalculateHook, EFFECT_1, SPELL_AURA_MOD_SUMMON_DAMAGE);
        DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_anduin_wrynn_force_of_will::RecalculateHookDamageTaken, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
    }
};

// 363233 - March of the Damned
class spell_anduin_wrynn_march_of_the_damned : public AuraScript
{
    void OnPeriodic(AuraEffect const* aurEff)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Seconds raidDifficulty = 0s;

        switch (GetCaster()->GetMap()->GetDifficultyID())
        {
            case DIFFICULTY_LFR_NEW:
            case DIFFICULTY_NORMAL_RAID:
            case DIFFICULTY_HEROIC_RAID:
                raidDifficulty = 28s;
                break;
            case DIFFICULTY_MYTHIC_RAID:
                raidDifficulty = 21s;
                break;
            default:
                raidDifficulty = 28s;
                break;
        }

        // Don't summon the wall on aura granted
        if (aurEff->GetTickNumber() == 1)
            return;

        if (_availableSpawnPositions.empty())
            return;

        Position chosenPosition = Trinity::Containers::SelectRandomContainerElement(_availableSpawnPositions);
        auto it = std::find(_availableSpawnPositions.begin(), _availableSpawnPositions.end(), chosenPosition);
        _availableSpawnPositions.erase(it);

        GetCaster()->SummonCreature(NPC_MARCH_OF_THE_DAMNED, chosenPosition, TEMPSUMMON_TIMED_DESPAWN, raidDifficulty);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_anduin_wrynn_march_of_the_damned::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

    std::vector<Position> _availableSpawnPositions = { std::begin(MarchOfTheDamnedSpawnPositions), std::end(MarchOfTheDamnedSpawnPositions) };
};

// 362500 - Shade Spawn Ceremony
class spell_remnant_of_a_fallen_king_spawn : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            GetTarget()->GetAI()->DoAction(ACTION_ACTIVATE_REMNANT);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_remnant_of_a_fallen_king_spawn::OnRemove, EFFECT_2, SPELL_AURA_TRIGGER_SPELL_ON_EXPIRE, AURA_EFFECT_HANDLE_REAL);
    }
};

// 365652 - Lost Soul
class spell_anduin_soul_lost_soul : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& unitList) const
    {
        unitList.remove_if([this](WorldObject const* target)
        {
            if (target->GetEntry() == NPC_ANDUIN_DOUBT && target->IsWithinDistInMap(GetCaster(), 0.2f))
                return false;
            return true;
        });
    }

    void HandleDummy(SpellEffIndex /*effIndex*/) const
    {
        if (Creature* creature = GetHitUnit()->ToCreature())
            creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_anduin_soul_lost_soul::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_anduin_soul_lost_soul::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 367769 - Severed Soul
class spell_anduin_wrynn_severed_soul : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CANCEL_LOST_SOUL });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            _soulPosition = caster->GetPosition();
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_CANCEL_LOST_SOUL, true);

        if (TempSummon* summon = GetTarget()->ToTempSummon())
            if (summon->GetSummonerUnit() == caster)
                caster->NearTeleportTo(_soulPosition);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_anduin_wrynn_severed_soul::OnApply, EFFECT_0, SPELL_AURA_LINKED_SUMMON, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_severed_soul::OnRemove, EFFECT_1, SPELL_AURA_TRIGGER_SPELL_ON_EXPIRE, AURA_EFFECT_HANDLE_REAL);
    }

    Position _soulPosition;
};

// 362402 - Lost Soul Mirror Image
class spell_anduin_wrynn_lost_soul_mirror_image : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        ObjectGuid casterGuid = caster->GetGUID();

        targets.remove_if([casterGuid](WorldObject const* target) -> bool
        {
            Unit const* unit = target->ToUnit();
            if (!unit)
                return true;

            TempSummon const* summon = unit->ToTempSummon();
            if (!summon)
                return true;

            if (summon->GetSummonerGUID() != casterGuid)
                return true;

            return false;
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

// 363029 - Soul Explosion
class spell_friendish_soul_explosion : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOUL_EXPLOSION_TRIGGER_MISSILE });
    }

    void FilterTargets(std::list<WorldObject*>& targets) const
    {
        if (targets.empty())
            return;

        targets.remove_if(Trinity::ObjectTypeIdCheck(TYPEID_PLAYER, false));

        std::vector<WorldObject*> rangedTargets;
        for (WorldObject* target : targets)
        {
            if (target->GetDistance(GetCaster()) >= 5.0f)
            {
                rangedTargets.push_back(target);
                break;
            }
        }

        if (!rangedTargets.empty())
        {
            targets.clear();
            targets.push_back(Trinity::Containers::SelectRandomContainerElement(rangedTargets));
        }
    }

    void HandleMissile(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SOUL_EXPLOSION_TRIGGER_MISSILE, true);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_friendish_soul_explosion::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_friendish_soul_explosion::HandleMissile, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 363022 - Return to Kingsmourne
class spell_remnant_of_a_fallen_king_return_to_kingsmourne_applied : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_RETURN_TO_KINGSMOURNE_VISUALS });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_RETURN_TO_KINGSMOURNE_VISUALS);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_remnant_of_a_fallen_king_return_to_kingsmourne_applied::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// 363021 - Return to Kingsmourne
class spell_remnant_of_a_fallen_king_return_to_kingsmourne : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER,
            SPELL_CANCEL_FORCE_OF_WILL
        });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        InstanceScript* instance = caster->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* arthas = instance->GetCreature(DATA_REMNANT_OF_A_FALLEN_KING))
            arthas->AI()->EnterEvadeMode(EvadeReason::Other);

        if (Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN))
        {
            anduin->RemoveAurasDueToSpell(SPELL_DOMINATION_GRASP_ROOT_AREATRIGGER);
            instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_INTERMISSION, 0);
            instance->DoUpdateWorldState(WORLD_STATE_ANDUIN_ENCOUNTER_STARTED, 1);
            if (anduin->IsAIEnabled())
            {
                anduin->AI()->DoAction(ACTION_EXIT_INTERMISSION);
                anduin->AI()->DoCastSelf(SPELL_CANCEL_FORCE_OF_WILL);
            }
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_remnant_of_a_fallen_king_return_to_kingsmourne::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 365120 - Grim Reflections
class spell_anduin_wrynn_grim_reflections : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GRIM_REFLECTIONS_SUMMON });
    }

    void HandleCast() const
    {
        uint8 reflectionsNumber = GetCaster()->GetMap()->IsMythic() ? 4 : 3;
        std::vector<Position> grimReflectionPositions(std::begin(GrimReflectionsSpawnPositions), std::end(GrimReflectionsSpawnPositions));
        Trinity::Containers::RandomResize(grimReflectionPositions, reflectionsNumber);

        for (uint8 i = 0; i < reflectionsNumber; i++)
            GetCaster()->CastSpell(grimReflectionPositions[i], SPELL_GRIM_REFLECTIONS_SUMMON, true);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_anduin_wrynn_grim_reflections::HandleCast);
    }
};

// 365872 - Beacon of Hope
class spell_anduin_wrynn_beacon_of_hope : public SpellScript
{
    void OnCast() const
    {
        GetCaster()->SummonCreature(NPC_BEACON_OF_HOPE, BeaconOfHopeSpawnPosition, TEMPSUMMON_MANUAL_DESPAWN);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_anduin_wrynn_beacon_of_hope::OnCast);
    }
};

// 365958 - Hopelessness
class spell_anduin_wrynn_hopelessness : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BLASPHEMY_PRE_HIT,
            SPELL_HOPELESSNESS_MISSILE
        });
    }

    void OnPrecast() override
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_BLASPHEMY_PRE_HIT, true);
    }

    void HandleDebuff(SpellEffIndex /*effIndex*/) const
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_HOPELESSNESS_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_anduin_wrynn_hopelessness::HandleDebuff, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 365966 - Hopelessness CreatePropertiesId 24443
struct at_anduin_wrynn_hopelessness : AreaTriggerAI
{
    at_anduin_wrynn_hopelessness(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)  { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer() || unit->HasAura(SPELL_BLASPHEMY_PRE_HIT))
            return;

        if (!unit->IsAlive())
        {
            at->Remove();
            return;
        }

        if (unit->HasAura(at->GetSpellId()))
        {
            unit->CastSpell(unit, SPELL_BLASPHEMY_EXPLODE, true);
            if (Unit* target = at->GetTarget())
                target->CastSpell(target, SPELL_BLASPHEMY_EXPLODE, true);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        if (!unit->IsAlive() && unit->HasAura(at->GetSpellId()))
            unit->RemoveAurasDueToSpell(at->GetSpellId());
    }
};

// 365966 - Hopelessness
class spell_anduin_wrynn_hopelessness_expire : public AuraScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_HOPELESSNESS_EXPLODE });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        switch (GetTargetApplication()->GetRemoveMode())
        {
            case AURA_REMOVE_BY_ENEMY_SPELL:
            case AURA_REMOVE_BY_EXPIRE:
            case AURA_REMOVE_BY_DEATH:
                GetTarget()->CastSpell(GetTarget(), SPELL_HOPELESSNESS_EXPLODE, true);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_anduin_wrynn_hopelessness_expire::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 365291 - Remnant Timer
class spell_remnant_of_a_fallen_king_energize_runic_power : public AuraScript
{
    static constexpr std::array<int32, 3> RemnantRegenCycle = { 1, 1, 2 };

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        int32 powerGained = RemnantRegenCycle[_powerRegenCycle++];

        if (_powerRegenCycle > 2)
            _powerRegenCycle = 1;

        target->ModifyPower(target->GetPowerType(), powerGained);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_remnant_of_a_fallen_king_energize_runic_power::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }

    uint8 _powerRegenCycle = 0;
};

// 362862 - Army of the Dead
class spell_remnant_of_a_fallen_king_army_of_the_dead : public SpellScript
{
    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_ECHOES_OF_ANDORHAL_MONSTROUS_SOUL });
    }

    void HandleAfterCast() const
    {
        if (GetCaster()->GetMap()->IsLFR())
            return;

        Position monstrousSoulSpawnPosition = GetCaster()->GetNearPosition(frand(30.0f, 50.0f), frand(0.0f, 3.5f));
        GetCaster()->CastSpell(monstrousSoulSpawnPosition, SPELL_ECHOES_OF_ANDORHAL_MONSTROUS_SOUL, true);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_remnant_of_a_fallen_king_army_of_the_dead::HandleAfterCast);
    }
};

// 362543 - Remorseless Winter
class spell_remnant_of_a_fallen_king_remorseless_winter_periodic : public AuraScript
{
    void OnPeriodic(AuraEffect const* /*aurEff*/) const
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(GetTarget(), SPELL_REMORSELESS_WINTER_DEBUFF_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_remnant_of_a_fallen_king_remorseless_winter_periodic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 362545 - Remorseless Winter
class spell_remnant_of_a_fallen_king_remorseless_winter_damage : public SpellScript
{
    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Aura* remorselessWinter = GetHitUnit()->GetAura(SPELL_REMORSELESS_WINTER_PERIODIC);
        if (!remorselessWinter)
            return;

        SetHitDamage(int32(GetHitDamage() * remorselessWinter->GetStackAmount()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_remnant_of_a_fallen_king_remorseless_winter_damage::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 362771 - Soul Reaper
class spell_remnant_of_a_fallen_king_soul_reaper : public SpellScript
{
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

    void HandleDummyEffect(SpellEffIndex /*effIndex*/) const
    {
        Unit* caster = GetCaster();
        Unit* hitUnit = GetHitUnit();
        caster->CastSpell(hitUnit, SPELL_SOUL_REAPER_PHYSICAL_DAMAGE, true);
        caster->CastSpell(hitUnit, SPELL_SOUL_REAPER_SHADOWFROST_DAMAGE, true);
        caster->CastSpell(hitUnit, SPELL_SOUL_REAPER_DEBUFF, true);
        caster->CastSpell(caster, SPELL_SOUL_REAPER_ATTACK_SPEED, true);
        caster->resetAttackTimer(BASE_ATTACK);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_remnant_of_a_fallen_king_soul_reaper::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Anduin Wrynn Introduction Custom AT
struct at_anduin_wrynn_pre_introduction : AreaTriggerAI
{
    at_anduin_wrynn_pre_introduction(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Player* player = unit->ToPlayer();
        if (!player || player->IsGameMaster())
            return;

        InstanceScript* instance = at->GetInstanceScript();
        if (!instance)
            return;

        if (Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN))
            anduin->GetAI()->DoAction(ACTION_START_PRE_INTRODUCTION);

        at->Remove();
    }
};

// 956 - Anduin End Movie
class movie_anduin_final : public PlayerScript
{
public:
    movie_anduin_final() : PlayerScript("movie_anduin_final") { }

    void MarkPlayerAsSkipped(uint32 playerId)
    {
        _skippedPlayers.insert(playerId);
    }

    void OnMovieComplete(Player* player, uint32 /*movieId*/) override
    {
        InstanceScript* instance = player->GetInstanceScript();
        if (!instance)
            return;

        Creature* anduin = instance->GetCreature(DATA_ANDUIN_WRYNN);
        if (!anduin)
            return;

        MarkPlayerAsSkipped(static_cast<uint32>(player->GetGUID().GetCounter()));
        player->RemoveAurasDueToSpell(SPELL_FINAL_MOVIE);

        // Outroduction must start once every player skips or completes the movie
        if (_skippedPlayers.size() == player->GetMap()->GetPlayersCountExceptGMs())
            anduin->GetAI()->DoAction(ACTION_START_OUTRODUCTION);
    }

private:
    std::unordered_set<uint32> _skippedPlayers;
};

void AddSC_boss_anduin_wrynn()
{
    RegisterSepulcherOfTheFirstOnesCreatureAI(boss_anduin_wrynn);
    RegisterSepulcherOfTheFirstOnesCreatureAI(boss_remnant_of_a_fallen_king);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_sylvanas);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_jaina);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_uther);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_empty_vessel);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_lost_soul);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_anduin_soul);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_anduin_despair);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_anduin_doubt);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_anduin_hope);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_monstrous_soul);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_fiendish_soul);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_grim_reflection);
    RegisterSepulcherOfTheFirstOnesCreatureAI(npc_anduin_wrynn_beacon_of_hope);

    RegisterAreaTriggerAI(at_anduin_wrynn_pre_introduction);
    RegisterSpellScript(spell_anduin_wrynn_pre_introduction);
    RegisterSpellScript(spell_anduin_wrynn_progression_aura);
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
    RegisterAreaTriggerAI(at_anduin_wrynn_empowered_wicked_star);
    RegisterSpellAndAuraScriptPair(spell_anduin_wrynn_wicked_star_selector, spell_anduin_wrynn_wicked_star_selector_AuraScript);
    RegisterSpellAndAuraScriptPairWithArgs(spell_anduin_wrynn_wicked_star_selector, spell_anduin_wrynn_empowered_wicked_star_selector_AuraScript, "spell_anduin_wrynn_empowered_wicked_star_selector");
    RegisterSpellScript(spell_anduin_wrynn_kingsmourne_hungers);
    RegisterSpellScript(spell_anduin_soul_lost_soul);
    RegisterSpellScript(spell_anduin_wrynn_lost_soul);
    RegisterSpellScript(spell_anduin_wrynn_lost_soul_mirror_image);
    RegisterSpellScript(spell_anduin_wrynn_severed_soul);
    RegisterSpellScript(spell_anduin_wrynn_soul_despawn);
    RegisterSpellScript(spell_anduin_rain_of_despair_player_selector);
    RegisterSpellScript(spell_anduin_wrynn_force_of_will);
    RegisterAreaTriggerAI(at_anduin_wrynn_march_of_the_damned);
    RegisterSpellScript(spell_anduin_wrynn_march_of_the_damned);
    RegisterSpellScript(spell_friendish_soul_explosion);
    RegisterSpellScript(spell_anduin_wrynn_grim_reflections);
    RegisterAreaTriggerAI(at_anduin_wrynn_beacon_of_hope);
    RegisterSpellScript(spell_anduin_wrynn_beacon_of_hope);
    RegisterAreaTriggerAI(at_anduin_wrynn_hopelessness);
    RegisterSpellScript(spell_anduin_wrynn_hopelessness);
    RegisterSpellScript(spell_anduin_wrynn_hopelessness_expire);
    RegisterSpellScript(spell_anduin_wrynn_fragment_of_hope);

    RegisterSpellScript(spell_remnant_of_a_fallen_king_spawn);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_energize_runic_power);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_army_of_the_dead);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_soul_reaper);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_remorseless_winter_periodic);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_remorseless_winter_damage);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_return_to_kingsmourne);
    RegisterSpellScript(spell_remnant_of_a_fallen_king_return_to_kingsmourne_applied);

    new movie_anduin_final();
}
