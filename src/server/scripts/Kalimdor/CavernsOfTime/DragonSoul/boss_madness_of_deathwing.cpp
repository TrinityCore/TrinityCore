/*
 * Copyright (C) 2022 BfaCore Reforged
 * Copyright (C) 2014-2018 RoG_WoW Source <http://wow.rog.snet>
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
#include "Group.h"
#include "dragon_soul.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "ScriptedGossip.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"

enum DeathwingScriptedTexts
{
    SAY_DEATHWING_AGGRO     = 0,
    SAY_DEATHWING_BOLT      = 2,
    SAY_DEATHWING_PHASE     = 1,
    SAY_IMPALE_ASPECT       = 3,
    SAY_ATTACK_ALEXSTRASZA  = 4,
    SAY_ATTACK_NOZDORMU     = 5,
    SAY_ATTACK_YSERA        = 6,
    SAY_ATTACK_KALECGOS     = 7,
};

enum AlexstraszaScriptedTexts
{
    SAY_ALEXTRASZA_END          = 0,
    SAY_ALEXSTRASZA_PLATFORM    = 1,
    SAY_ALEXSTRASZA_PHASE_2     = 2,
    SAY_ALEXSTRASZA_CATACLYSM   = 3,
};

enum NozdormuScriptedTexts
{
    SAY_NOZDORMU_PLATFORM       = 1,
    SAY_NOZDORMU_PHASE_2        = 2,
    SAY_NOZDORMU_CATACLYSM      = 3,
};

enum YseraScriptedTexts
{
    SAY_YSERA_PLATFORM          = 1,
    SAY_YSERA_PHASE_2           = 2,
    SAY_YSERA_CATACLYSM         = 3,
};

enum KalecgosScriptedTexts
{
    SAY_KALECGOS_PLATFORM       = 1,
    SAY_KALECGOS_PHASE_2        = 2,
    SAY_KALECGOS_CATACLYSM      = 3,
};

enum ThrallScriptedTexts
{
    SAY_THRALL_PHASE_2          = 0,
};

enum Spells
{

    // Thrall
    SPELL_ASTRAL_RECALL_1               = 108537,
    SPELL_ASTRAL_RECALL_2               = 101063,
    SPELL_TRIGGER_ASPECT_YELL_1         = 109708,
    SPELL_TRIGGER_ASPECT_YELL_2         = 109727,
    SPELL_FIRE_DRAGON_SOUL_ASPECTS      = 110067,
    SPELL_FIRE_DRAGON_SOUL              = 109971,
    SPELL_FIRE_DRAGON_SOUL_SCRIPT       = 110065,

    SPELL_IDLE                          = 106187, // tail tentacle has it

    SPELL_TRIGGER_ASPECT_BUFFS          = 106943, // casted by deathwing 56173
    SPELL_SHARE_HEALTH_1                = 109547, // casted by deathwing 56173 on self ?
    SPELL_SHARE_HEALTH_2                = 109548, // casted by deathwing 56173 on 57962
    SPELL_ASSAULT_ASPECTS               = 107018, // casted by deathwing 56173
    SPELL_ELEMENTIUM_BOLT               = 105651,
    SPELL_ELEMENTIUM_METEOR_SCRIPT      = 105599,
    SPELL_ELEMENTIUM_METEOR_SUMMON      = 105658,
    SPELL_ELEMENTIUM_BLAST              = 105723,
    SPELL_ELEMENTIUM_METEOR_TARGET      = 106242, // target mark
    SPELL_ELEMENTIUM_METEOR_TRANSFORM_1 = 106991, // summon from sniffs ?
    SPELL_ELEMENTIUM_METEOR_TRANSFORM_2 = 110663,
    SPELL_ELEMENTIUM_METEOR_AURA        = 110628,
    SPELL_ELEMENTIUM_METEOR_AURA_DMG    = 110632,
    SPELL_CATACLYSM                     = 106523,
    SPELL_SLUMP_1                       = 106708, // phase 2
    SPELL_SLUMP_2                       = 110062, // on death ?
    SPELL_CORRUPTED_BLOOD               = 106834,
    SPELL_CORRUPTED_BLOOD_DPS           = 106835,
    SPELL_CORRUPTED_BLOOD_STACKER       = 106843,
    SPELL_CORRUPTING_PARASITE_AOE       = 108597,
    SPELL_CORRUPTING_PARASITE_DMG       = 108601,
    SPELL_CORRUPTING_PARASITE_AURA      = 108649,
    SPELL_PARASITIC_BACKSLASH           = 108787,
    SPELL_UNSTABLE_CORRUPTION           = 108813,
    SPELL_DEATH                         = 110101,
    SPELL_BERSERK                       = 64238,
    SPELL_SCREEN_CALM_MAELSTROM         = 109480,

    SPELL_ACHIEVEMENT                   = 111533,

    // Limb Tentacle
    SPELL_LIMB_EMERGE_VISUAL            = 107991,
    SPELL_SUMMON_BLISTERING_TENTACLE    = 105549,
    SPELL_BURNING_BLOOD                 = 105401,
    SPELL_TRIGGER_CONCENTRATION         = 106940,
    SPELL_AGONIZING_PAIN                = 106548,

    // Mutated Corruption
    SPELL_SUMMON_TAIL_FORCE             = 106239,
    SPELL_SUMMON_TAIL                   = 106240,
    SPELL_CRUSH_FORCE                   = 106382,
    SPELL_CRUSH_SUMMON                  = 106384,
    SPELL_CRUSH                         = 106385,
    SPELL_IMPALE                        = 106400,
    SPELL_IMPALE_DMG                    = 106444,
    SPELL_IMPALE_ASPECT_AOE             = 107026,
    SPELL_IMPALE_ASPECT                 = 107029,

    // Blistering Tentacle
    SPELL_BLISTERING_TENTACLE_VEHICLE   = 105550,
    SPELL_BLISTERING_HEAT               = 105444,
    SPELL_BLISTERING_HEAT_DMG           = 105445,

    // Hemorrhage
    SPELL_HEMORRHAGE_SUMMON_AOE         = 105853,
    SPELL_HEMORRHAGE_AURA               = 105861,
    SPELL_HEMORRHAGE_SCRIPT             = 105862,
    SPELL_HEMORRHAGE_MISSILE            = 105863,
    SPELL_HEMORRHAGE_SUMMON             = 105875,
    SPELL_REGENERATIVE_BLOOD_PERIODIC   = 105932,
    SPELL_REGENERATIVE_BLOOD_SCRIPT     = 105934,
    SPELL_REGENERATIVE_BLOOD_HEAL       = 105937,
    SPELL_REGENERATIVE_BLOOD_AURA       = 105969, // scale aura
    SPELL_DEGENERATIVE_BITE_AURA        = 105842,
    SPELL_DEGENERATIVE_BITE_DPS         = 105841,

    // Congealing Blood
    SPELL_CONGEALING_BLOOD_AOE          = 109082,
    SPELL_CONGEALING_BLOOD_SCRIPT       = 109087,
    SPELL_CONGEALING_BLOOD_MISSILE      = 109089,
    SPELL_CONGEALING_BLOOD_SUMMON       = 109091,
    SPELL_CONGEALING_BLOOD_HEAL         = 109102,

    // Elementium Terror
    SPELL_ELEMENTIUM_TERROR_SCRIPT      = 106765,
    SPELL_ELEMENTIUM_TERROR_MISSILE     = 106766,
    SPELL_ELEMENTIUM_TERROR_SUMMON      = 106767, // original name is hemorrhage
    SPELL_ELEMENTIUM_TERROR_TETANUS_AUR = 106728,
    SPELL_ELEMENTIUM_TERROR_TETANUS_DPS = 106730,

    // Impaling Tentacle
    SPELL_IMPALING_TENTACLE_SCRIPT      = 106775,
    SPELL_IMPALING_TENTACLE_MISSILE     = 106776,
    SPELL_IMPALING_TENTACLE_SUMMON      = 106777,
    SPELL_SHRAPNEL_AURA                 = 106818,
    SPELL_SHRAPNEL_AOE                  = 106789,
    SPELL_SHRAPNEL_TARGET               = 106794,
    SPELL_SHRAPNEL_DMG                  = 106791,

    // Aspects
    SPELL_ALEXSTRASZA_PRESENCE          = 105825,
    SPELL_ALEXSTRASZA_PRESENCE_AURA     = 106028,
    SPELL_CAUTERIZE_1                   = 105565, // blistering tentacle
    SPELL_CAUTERIZE_1_DMG               = 105569,
    SPELL_CAUTERIZE_2_1                 = 106860, // deathwing phase 2 5 sec
    SPELL_CAUTERIZE_2_2                 = 106888, // deathwing phase 2 10 sec
    SPELL_CAUTERIZE_2_3                 = 106889, // deathwing phase 2 15 sec
    SPELL_CAUTERIZE_2_DMG               = 106886,
    SPELL_CAUTERIZE_3                   = 108840, // parasite
    SPELL_CAUTERIZE_3_DMG               = 109045,

    SPELL_NOZDORMU_PRESENCE             = 105823,
    SPELL_NOZDORMU_PRESENCE_AURA        = 106027,
    SPELL_TIME_ZONE_FORCE               = 106919, // first spell, there are npcs 'platform'
    SPELL_TIME_ZONE_SUMMON_TARGET       = 105793, // summon target
    SPELL_TIME_ZONE_MISSILE_1           = 105799,
    SPELL_TIME_ZONE_SUMMON_1            = 105802, // summon time zone
    SPELL_TIME_ZONE                     = 105831, // main aura on trigger
    SPELL_TIME_ZONE_AURA_1              = 105830, // aura (debuff)
    SPELL_TIME_ZONE_MISSILE_2           = 107055, // ? maybe heroic
    SPELL_TIME_ZONE_SUMMON_2            = 107057, // ? maybe heroic
    SPELL_TIME_ZONE_AURA_2              = 108646, // for parasite

    SPELL_YSERA_PRESENCE                = 106456,
    SPELL_YSERA_PRESENCE_AURA           = 106457,
    SPELL_THE_DREAMER                   = 106463,
    SPELL_ENTER_THE_DREAM               = 106464,
    SPELL_DREAM                         = 106466,

    SPELL_KALECGOS_PRESENCE             = 106026,
    SPELL_KALECGOS_PRESENCE_AURA        = 106029,
    SPELL_SPELLWEAVER                   = 106039,
    SPELL_SPELLWEAVING                  = 106040,
    SPELL_SPELLWEAVING_DPS              = 106043,

    SPELL_EXPOSE_WEAKNESS_1             = 106588,
    SPELL_EXPOSE_WEAKNESS_2             = 106600,
    SPELL_EXPOSE_WEAKNESS_3             = 106613,
    SPELL_EXPOSE_WEAKNESS_4             = 106624,

    SPELL_CONCENTRATION_1               = 106641,
    SPELL_CONCENTRATION_2               = 106642,
    SPELL_CONCENTRATION_3               = 106643,
    SPELL_CONCENTRATION_4               = 106644,
    SPELL_CONCENTRATION_5               = 110071,
    SPELL_CONCENTRATION_6               = 110072,
    SPELL_CONCENTRATION_7               = 110076,
    SPELL_CONCENTRATION_8               = 110077,

    // Jump Pad
    SPELL_CARRYING_WINDS_1              = 106663, // casted by player, from 1 to 2
    SPELL_CARRYING_WINDS_SCRIPT_1       = 106666, // casted by pad on player
    SPELL_CARRYING_WINDS_2              = 106668, // from 2 to 1
    SPELL_CARRYING_WINDS_SCRIPT_2       = 106669,
    SPELL_CARRYING_WINDS_3              = 106670, // from 2 to 3
    SPELL_CARRYING_WINDS_SCRIPT_3       = 106671,
    SPELL_CARRYING_WINDS_4              = 106672, // from 3 to 2
    SPELL_CARRYING_WINDS_SCRIPT_4       = 106673,
    SPELL_CARRYING_WINDS_5              = 106674, // from 3 to 4
    SPELL_CARRYING_WINDS_SCRIPT_5       = 106675,
    SPELL_CARRYING_WINDS_6              = 106676, // from 4 to 3
    SPELL_CARRYING_WINDS_SCRIPT_6       = 106677,
    SPELL_CARRYING_WINDS_DUMMY          = 106678, // visual ?
    SPELL_CARRYING_WINDS_SPEED_10       = 106664,
};

enum Adds
{
    NPC_WING_TENTACLE       = 56168, // 1 & 4
    NPC_ARM_TENTACLE_1      = 56846, // 2
    NPC_ARM_TENTACLE_2      = 56167, // 3

    NPC_MUTATED_CORRUPTION  = 56471,
    NPC_CRUSH_TARGET        = 56581,
    NPC_BLISTERING_TENTACLE = 56188,
    NPC_REGENERATIVE_BLOOD  = 56263,
    NPC_HEMORRHAGE_TARGET   = 56359,
    NPC_ELEMENTIUM_BOLT     = 56262,
    NPC_CLAWK_MARK          = 56545,
    NPC_CORRUPTING_PARASITE = 57479,
    NPC_TIME_ZONE_TARGET    = 56332,
    NPC_TIME_ZONE           = 56311,
    NPC_IMPALING_TENTACLE   = 56724,
    NPC_ELEMENTIUM_TERROR   = 56710,
    NPC_CONGEALING_BLOOD    = 57798,
    NPC_CONGEALING_HEAL     = 53488,
    NPC_DEATHWING_1         = 57962, // invisible ?

    NPC_COSMETIC_TENTACLE   = 57693,
    NPC_TAIL_TENTACLE       = 56844,

    NPC_JUMP_PAD            = 56699,
    NPC_PLATFORM            = 56307,
};

enum Events
{
    EVENT_SPAWN_LIMBS_1         = 1,
    EVENT_SPAWN_LIMBS_2         = 2,
    EVENT_SPAWN_LIMBS_3         = 3,
    EVENT_CHECK_PLAYERS         = 4,
    EVENT_ASSAULT_ASPECTS       = 5,
    EVENT_CRUSH                 = 6,
    EVENT_IMPALE                = 7,
    EVENT_CRUSH_1               = 8,
    EVENT_ASSAULT_ASPECTS_1     = 9,
    EVENT_HEMORRHAGE            = 10,
    EVENT_UPDATE_HEALTH         = 11,
    EVENT_START_MOVE            = 12,
    EVENT_ELEMENTIUM_BOLT       = 13,
    EVENT_CATACLYSM             = 14,
    EVENT_CORRUPTING_PARASITE   = 15,
    EVENT_UNSTABLE_CORRUPTION   = 16,
    EVENT_TIME_ZONE             = 17,
    EVENT_CAUTERIZE             = 18,
    EVENT_SELECT_VICTIM         = 19,
    EVENT_BLISTERING_TENTACLE   = 20,
    EVENT_SLUMP                 = 21,
    EVENT_ASPECT_TALK_2         = 22, // talk at the beginning of second phase
    EVENT_THRALL_TALK_2         = 23, // talk at the beginning of second phase (after aspect)
    EVENT_ELEMENTIUM_FRAGMENT   = 24,
    EVENT_ELEMENTIUM_TERROR     = 25,
    EVENT_CONGEALING_BLOOD      = 26,
    EVENT_SHRAPNEL              = 27,
    EVENT_CAUTERIZE_PARASITE    = 28,
    EVENT_CONGEALING_BLOOD_HEAL = 29,
    EVENT_DRAGON_SOUL           = 30,
    EVENT_END_BATTLE            = 31,
    EVENT_TIME_ZONE_2           = 32,
    EVENT_BERSERK               = 33,
    EVENT_FINISH                = 34,
};

enum Actions
{
    ACTION_CHECK_PLAYERS            = 1,
    ACTION_CRUSH                    = 2,
    ACTION_ASSAULT_ASPECTS          = 3,
    ACTION_ASSAULT_ASPECTS_FIRST    = 4,
    ACTION_PARASITIC_BACKSLASH      = 5,
    ACTION_TIME_ZONE                = 6,
    ACTION_CAUTERIZE                = 7,
    ACTION_CAUTERIZE_PARASITE       = 8,
    ACTION_END_BATTLE               = 9,
    ACTION_TIME_ZONE_2              = 10,
    ACTION_HP_UPDATE                = 11,
};

enum Other
{
    DATA_ASSAULT_PLATFORM       = 1,
    DATA_DESTROY_PLATFORM       = 2,
    DATA_CURRENT_PLATFORM       = 3,
    DATA_METEOR_POINT           = 4,
    DATA_SHRAPNEL               = 5,
    DATA_BLOOD_POINT            = 6,
    DATA_LAST_ASSAULT_PLATFORM  = 7,
};

uint8 GetGround(const WorldObject* who)
{
    if (who->GetPositionX() > -11979.311523f && who->GetPositionX() < -11938.857422f &&
        who->GetPositionY() > 12236.340820f && who->GetPositionY() < 12299.116211f)
        return 1;
    else if (who->GetPositionX() > -12074.251953f && who->GetPositionX() < -12002.294922f &&
        who->GetPositionY() > 12184.281250f && who->GetPositionY() < 12256.737305f)
        return 2;
    else if (who->GetPositionX() > -12135.291992f && who->GetPositionX() < -12054.627930f &&
        who->GetPositionY() > 12129.464844f && who->GetPositionY() < 12190.023438f)
        return 3;
    else if (who->GetPositionX() > -12164.257813f && who->GetPositionX() < -12075.483398f &&
        who->GetPositionY() > 12051.344727f && who->GetPositionY() < 12107.757813f)
        return 4;

    return 0;
}

const Position mutatedcorruptionPos[4] =
{
    {-11993.3f, 12286.3f, -2.58115f, 5.91667f}, // 1
    {-12028.8f, 12265.6f, -6.27147f, 4.13643f}, // 2
    {-12107.4f, 12201.9f, -5.32397f, 5.16617f}, // 3
    {-12160.9f, 12057.0f, 2.47362f, 0.733038f}  // 4
};

const Position limbsPos[5] =
{
    {-11941.2f, 12248.9f, 12.1499f, 1.98968f},
    {-12015.8f, 12195.3f, -4.79399f, 2.1293f},
    {-12005.8f, 12190.3f, -6.59399f, 2.1293f},
    {-12065.0f, 12140.2f, -1.0946f, 2.338740f},
    {-12097.8f, 12067.4f, 13.4888f, 2.21657f}
};

const Position hemorrhagePos[4] =
{
    {-11955.948242f, 12281.756836f, 1.30f, 0.0f},
    {-12048.077148f, 12237.601563f, -6.14f, 0.0f},
    {-12113.989258f, 12166.718750f, -2.72f, 0.0f},
    {-12146.370117f, 12093.588867f, 2.31f, 0.0f}
};

const Position boltPos[5] =
{
    {-11929.83f, 12035.63f, 35.45797f, 0.0f},
    {-11961.268555f, 12286.041992f, 1.30f, 0.0f},   // 1
    {-12055.000977f, 12239.061523f, -6.14f, 0.0f},  // 2
    {-12112.834961f, 12170.205078f, -2.72f, 0.0f},  // 3
    {-12149.885742f, 12081.416992f, 2.31f, 0.0f}    // 4
};

const Position timezonePos[5] =
{
    {-11962.668945f, 12262.736328f, 1.30f, 0.0f},
    {-12045.594727f, 12216.872070f, -6.02f, 0.0f},
    {-12098.596680f, 12156.881836f, -2.72f, 0.0f},
    {-12113.083008f, 12081.437500f, 2.31f, 0.0f},
    {-12102.192383f, 12156.113281f, -2.72f, 0.0f}
};

const Position blisteringPos[4] =
{
    {-11942.116211f, 12249.538086f, 1.37f, 0.0f},
    {-12025.414063f, 12213.312500f, -6.14f, 0.0f},
    {-12084.824219f, 12146.507813f, -2.72f, 0.0f},
    {-12102.188477f, 12067.497070f, 2.31f, 0.0f},
};

const Position impalingPos[8] =
{
    {-12117.319336f, 12185.737305f, -2.72f, 0.0f},
    {-12115.992188f, 12177.088867f, -2.72f, 0.0f},
    {-12122.911133f, 12176.027344f, -2.72f, 0.0f},
    {-12120.683594f, 12170.037109f, -2.72f, 0.0f},
    {-12115.131836f, 12168.325195f, -2.72f, 0.0f},
    {-12120.296875f, 12165.841797f, -2.72f, 0.0f},
    {-12113.935547f, 12165.100586f, -2.72f, 0.0f},
    {-12112.777344f, 12172.588867f, -2.72f, 0.0f}
};

const Position terrorPos[2] =
{
    {-12121.259766f, 12162.742188f, -2.74f, 0.0f},
    {-12117.771484f, 12168.811523f, -2.72f, 0.0f}
};

const Position congealingPos[2] =
{
    {-12119.488281f, 12162.667969f, -2.72f, 0.0f},
    {-12079.577148f, 12169.696289f, -2.72f, 0.0f} // healing pos
};

const Position thrallPos[2] =
{
    {-12128.3f, 12253.8f, 0.0451f, 0.0f}, // Thrall teleports here
    {-12061.8f, 12188.f, 10.2966f, 5.57f}
};
const Position deathwingPos = {-11903.9f, 11989.1f, -113.204f, 2.16421f};
const Position deathwing2Pos = {-12063.5f, 12198.9f, -13.04f, 2.16421f};

const Position alexstraszaPos = {-11957.3f, 12338.3f, 38.9364f, 5.06145f};
const Position nozdormuPos = {-12093.8f, 12312.0f, 43.228f, 5.42797f};
const Position yseraPos = {-12157.4f, 12212.5f, 36.0152f, 5.75959f};
const Position kalecgosPos = {-12224.8f, 12128.5f, 68.96f, 5.84685f};


const Position alexstraszaendPos = {-12077.3f, 12152.3f, -2.64092f, 6.00393f};
const Position nozdormuendPos = {-12078.4f, 12147.5f, -2.64092f, 0.174533f};
const Position yseraendPos = {-12073.8f, 12156.6f, -2.64091f, 5.55015f};
const Position kalecgosendPos = {-12069.2f, 12159.9f, -2.64091f, 5.23599f};
const Position aggraendPos = {-12066.1f, 12150.4f, -2.64091f, 3.05433f};
const Position thrallendPos = {-12067.7f, 12146.4f, -2.64091f, 3.05433f};

const Position jumpPos[6] =
{
    {-11972.8f, 12272.8f, 1.38396f, 0.0f},  // from 1 to 2
    {-12023.f, 12228.5f, -6.0689f, 0.0f},   // from 2 to 1
    {-12047.9f, 12213.9f, -5.94278f, 0.0f}, // from 2 to 3
    {-12087.5f, 12165.7f, -2.65091f, 0.0f}, // from 3 to 2
    {-12099.6f, 12152.8f, -2.65092f, 0.0f}, // from 3 to 4
    {-12118.2f, 12084.9f, 2.39029f, 0.0f}   // from 4 to 3
};

#define GOSSIP_OPTION_1 "Is this end?"

uint32 healthValueNew;
uint32 healthValue;

class boss_madness_of_deathwing : public CreatureScript
{
    public:
        boss_madness_of_deathwing() : CreatureScript("boss_madness_of_deathwing") { }

        CreatureAI* GetAI(Creature* pCreature) const
        {
            return new boss_madness_of_deathwingAI(pCreature);
        }

        struct boss_madness_of_deathwingAI : public BossAI
        {
            boss_madness_of_deathwingAI(Creature* pCreature) : BossAI(pCreature, DATA_MADNESS)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                m_current_platform = 0;
                m_destroyed_platform = 0;
                healthValueNew = 0;
                healthValue = 0;
                m_isFirst = true;
                m_isBerserk = false;
            }

            void AttackStart(Unit* target) override
            {
                if (!target)
                    return;

                if (me->Attack(target, true))
                    DoStartNoMovement(target);
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                instance->SetBossState(DATA_MADNESS, IN_PROGRESS);
                events.ScheduleEvent(EVENT_SPAWN_LIMBS_1, 1);
                events.ScheduleEvent(EVENT_BERSERK, 900000);
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_ASSAULT_PLATFORM)
                {
                    m_current_platform = (uint8)data;

                    events.ScheduleEvent(EVENT_ASSAULT_ASPECTS_1, 500);
                }
                else if (type == DATA_DESTROY_PLATFORM)
                    m_destroyed_platform |= (1 << data);
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_DESTROY_PLATFORM)
                    return m_destroyed_platform;
                else if (type == DATA_CURRENT_PLATFORM)
                    return m_current_platform;

                return 0;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                if (spellInfo->Id == SPELL_AGONIZING_PAIN)
                {
                    events.CancelEvent(EVENT_CATACLYSM);
                    events.CancelEvent(EVENT_ELEMENTIUM_BOLT);
                    events.CancelEvent(EVENT_ASSAULT_ASPECTS);
                    events.CancelEvent(EVENT_ASSAULT_ASPECTS_1);

                    if (Spell* spell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL))
                        if (spell->GetSpellInfo()->Id == SPELL_CATACLYSM)
                            me->InterruptSpell(CURRENT_GENERIC_SPELL);

                    if ((m_destroyed_platform & (1 << 1)) > 0 &&
                        (m_destroyed_platform & (1 << 2)) > 0 &&
                        (m_destroyed_platform & (1 << 3)) > 0 &&
                        (m_destroyed_platform & (1 << 4)) > 0)
                    {
                        DoCastAOE(SPELL_TRIGGER_ASPECT_BUFFS, true);
                        events.ScheduleEvent(EVENT_SLUMP, 7000);
                        Talk(SAY_DEATHWING_PHASE);
                    }
                    else
                        events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 7000);
                }
                else if (spellInfo->Id == SPELL_FIRE_DRAGON_SOUL_SCRIPT)
                {
                    instance->DoCastSpellOnPlayers(SPELL_SCREEN_CALM_MAELSTROM);
                    me->RemoveAura(SPELL_SLUMP_2);
                    DoCast(me, SPELL_DEATH);
                    events.ScheduleEvent(EVENT_FINISH, 6000);
                }
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_BERSERK:
                            if (Creature* pDeathwing = me->FindNearestCreature(NPC_DEATHWING_1, 600.0f, true))
                                pDeathwing->CastSpell(pDeathwing, SPELL_BERSERK, true);
                            m_isBerserk = true;
                            break;
                        case EVENT_SPAWN_LIMBS_1:

                            if (Creature* pAspect = instance->GetCreature(DATA_ALEXSTRASZA_DRAGON))
                            {
                                if (Creature* pLimb = pAspect->FindNearestCreature(NPC_WING_TENTACLE, 500.0f, true))
                                {
                                    pLimb->SetVisible(true);
                                    pLimb->AI()->DoZoneInCombat(pLimb, 500.0f);
                                    pLimb->SendPlaySpellVisualKit(22445, 0, 1000);
                                    limbsGuids[0] = pLimb->GetGUID();
                                    pLimb->AI()->SetData(DATA_CURRENT_PLATFORM, 1);
                                }
                            }

                            if (Creature* pAspect = instance->GetCreature(DATA_ALEXSTRASZA_DRAGON))
                            {
                                if (Creature* pLimb = pAspect->FindNearestCreature(NPC_ARM_TENTACLE_1, 500.0f, true))
                                {
                                    pLimb->SetVisible(true);
                                    pLimb->AI()->DoZoneInCombat(pLimb, 500.0f);
                                    pLimb->SendPlaySpellVisualKit(22445, 0, 1000);
                                    limbsGuids[1] = pLimb->GetGUID();
                                    pLimb->AI()->SetData(DATA_CURRENT_PLATFORM, 2);
                                }
                            }

                            if (Creature* pAspect = instance->GetCreature(DATA_KALECGOS_DRAGON))
                            {
                                if (Creature* pLimb = pAspect->FindNearestCreature(NPC_ARM_TENTACLE_2, 500.0f, true))
                                {
                                    pLimb->SetVisible(true);
                                    pLimb->AI()->DoZoneInCombat(pLimb, 500.0f);
                                    pLimb->SendPlaySpellVisualKit(22445, 0, 1000);
                                    limbsGuids[2] = pLimb->GetGUID();
                                    pLimb->AI()->SetData(DATA_CURRENT_PLATFORM, 3);
                                }
                            }

                            if (Creature* pAspect = instance->GetCreature(DATA_KALECGOS_DRAGON))
                            {
                                if (Creature* pLimb = pAspect->FindNearestCreature(NPC_WING_TENTACLE, 500.0f, true))
                                {
                                    pLimb->SetVisible(true);
                                    pLimb->AI()->DoZoneInCombat(pLimb, 500.0f);
                                    pLimb->SendPlaySpellVisualKit(22445, 0, 1000);
                                    limbsGuids[3] = pLimb->GetGUID();
                                    pLimb->AI()->SetData(DATA_CURRENT_PLATFORM, 4);
                                }
                            }

                            events.ScheduleEvent(EVENT_SPAWN_LIMBS_2, 100);
                            break;
                        case EVENT_SPAWN_LIMBS_2:
                            for (uint8 i = 0; i < 4; ++i)
                                if (Creature* pLimb = ObjectAccessor::GetCreature(*me, limbsGuids[i]))
                                    pLimb->CastSpell(pLimb, SPELL_LIMB_EMERGE_VISUAL, true);

                            events.ScheduleEvent(EVENT_SPAWN_LIMBS_3, 500);
                            break;
                        case EVENT_SPAWN_LIMBS_3:
                            for (uint8 i = 0; i < 4; ++i)
                                if (Creature* pLimb = ObjectAccessor::GetCreature(*me, limbsGuids[i]))
                                    pLimb->SendPlaySpellVisualKit(22446, 0, 500);

                            events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 2000);
                            break;
                        case EVENT_ASSAULT_ASPECTS:
                            DoCastAOE(SPELL_ASSAULT_ASPECTS);
                            break;
                        case EVENT_ASSAULT_ASPECTS_1:
                        {
                            switch (m_current_platform)
                            {
                                case 1:
                                    if (Creature* pAspect = instance->GetCreature(DATA_ALEXSTRASZA_DRAGON))
                                    {
                                        pAspect->AI()->Talk(SAY_ALEXSTRASZA_PLATFORM);
                                        if (Creature* pTentacle = pAspect->FindNearestCreature(NPC_MUTATED_CORRUPTION, 100.0f, true))
                                        {
                                            pTentacle->SetVisible(true);
                                            pTentacle->SetReactState(REACT_AGGRESSIVE);
                                            DoZoneInCombat(pTentacle, 200.0f);
                                        }
                                    }
                                    Talk(SAY_ATTACK_ALEXSTRASZA);
                                    break;
                                case 2:
                                    if (Creature* pAspect = instance->GetCreature(DATA_NOZDORMU_DRAGON))
                                    {
                                        pAspect->AI()->Talk(SAY_NOZDORMU_PLATFORM);
                                        if (Creature* pTentacle = pAspect->FindNearestCreature(NPC_MUTATED_CORRUPTION, 100.0f, true))
                                        {
                                            pTentacle->SetVisible(true);
                                            pTentacle->SetReactState(REACT_AGGRESSIVE);
                                            DoZoneInCombat(pTentacle, 200.0f);
                                        }
                                    }

                                    Talk(SAY_ATTACK_NOZDORMU);
                                    break;
                                case 3:
                                    if (Creature* pAspect = instance->GetCreature(DATA_YSERA_DRAGON))
                                    {
                                        pAspect->AI()->Talk(SAY_YSERA_PLATFORM);
                                        if (Creature* pTentacle = pAspect->FindNearestCreature(NPC_MUTATED_CORRUPTION, 100.0f, true))
                                        {
                                            pTentacle->SetVisible(true);
                                            pTentacle->SetReactState(REACT_AGGRESSIVE);
                                            DoZoneInCombat(pTentacle, 200.0f);
                                        }
                                    }

                                     Talk(SAY_ATTACK_YSERA);
                                    break;
                                case 4:
                                    if (Creature* pAspect = instance->GetCreature(DATA_KALECGOS_DRAGON))
                                    {
                                        pAspect->AI()->Talk(SAY_KALECGOS_PLATFORM);
                                        if (Creature* pTentacle = pAspect->FindNearestCreature(NPC_MUTATED_CORRUPTION, 100.0f, true))
                                        {
                                            pTentacle->SetVisible(true);
                                            pTentacle->SetReactState(REACT_AGGRESSIVE);
                                            DoZoneInCombat(pTentacle, 200.0f);
                                        }
                                    }

                                    Talk(SAY_ATTACK_KALECGOS);
                                    break;
                            }

                            if (Creature* pLimb = this->GetLimbTentacleAtPlatform(m_current_platform))
                                pLimb->AI()->DoAction(m_isFirst ? ACTION_ASSAULT_ASPECTS_FIRST : ACTION_ASSAULT_ASPECTS);

                            if (Creature* pAspect = instance->GetCreature(DATA_NOZDORMU_DRAGON))
                                pAspect->AI()->DoAction(ACTION_TIME_ZONE);

                            events.ScheduleEvent(EVENT_ELEMENTIUM_BOLT, m_isFirst ? (40500 - 10000) : (55500 - 10000));
                            events.ScheduleEvent(EVENT_CATACLYSM, m_isFirst ? (115500 - 10000) : (130500 - 10000));

                            m_isFirst = false;
                            break;
                        }
                        case EVENT_ELEMENTIUM_BOLT:
                            DoCast(me, SPELL_ELEMENTIUM_BOLT);
                            Talk(SAY_DEATHWING_BOLT);
                            break;
                        case EVENT_CATACLYSM:
                        {
                            DoCast(me, SPELL_CATACLYSM);

                            Creature* pLimb = GetLimbTentacleAtPlatform(m_current_platform);

                            switch (m_current_platform)
                            {
                                case 1:
                                    if (Creature* pAspect = instance->GetCreature(DATA_ALEXSTRASZA_DRAGON))
                                    {
                                        pAspect->AI()->Talk(SAY_ALEXSTRASZA_CATACLYSM);
                                        if (pLimb)
                                            pAspect->CastSpell(pLimb, SPELL_EXPOSE_WEAKNESS_1);
                                    }
                                    break;
                                case 2:
                                    if (Creature* pAspect = instance->GetCreature(DATA_NOZDORMU_DRAGON))
                                    {
                                        pAspect->AI()->Talk(SAY_NOZDORMU_CATACLYSM);
                                        if (pLimb)
                                            pAspect->CastSpell(pLimb, SPELL_EXPOSE_WEAKNESS_2);
                                    }
                                    break;
                                case 3:
                                    if (Creature* pAspect = instance->GetCreature(DATA_YSERA_DRAGON))
                                    {
                                        pAspect->AI()->Talk(SAY_YSERA_CATACLYSM);
                                        if (pLimb)
                                            pAspect->CastSpell(pLimb, SPELL_EXPOSE_WEAKNESS_3);
                                    }
                                    break;
                                case 4:
                                    if (Creature* pAspect = instance->GetCreature(DATA_KALECGOS_DRAGON))
                                    {
                                        pAspect->AI()->Talk(SAY_KALECGOS_CATACLYSM);
                                        if (pLimb)
                                            pAspect->CastSpell(pLimb, SPELL_EXPOSE_WEAKNESS_4);
                                    }
                                    break;
                            }
                            break;
                        }
                        case EVENT_SLUMP:
                            DoCast(SPELL_SLUMP_1);
                            if (Creature* pDeathwing = me->FindNearestCreature(NPC_DEATHWING_1, 500.0f, true))
                            {
                                pDeathwing->SetVisible(true);
                                DoZoneInCombat(pDeathwing, 200.0f);
                                pDeathwing->SetMaxHealth(me->GetMaxHealth());
                                pDeathwing->SetHealth(me->GetHealth());
                                healthValue = me->GetHealth();
                                pDeathwing->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE));
                                pDeathwing->CastSpell(pDeathwing, SPELL_CORRUPTED_BLOOD_STACKER, true);
                                pDeathwing->CastSpell(pDeathwing, SPELL_SHRAPNEL_AURA, true);
                                pDeathwing->AI()->DoAction(ACTION_HP_UPDATE);
                                pDeathwing->SetInCombatWithZone();
                                if (m_isBerserk)
                                    pDeathwing->CastSpell(pDeathwing, SPELL_BERSERK, true);
                            }
                            if (m_isBerserk)
                                me->CastSpell(me, SPELL_BERSERK, true);

                            events.ScheduleEvent(EVENT_ASPECT_TALK_2, 10000);
                            events.ScheduleEvent(EVENT_TIME_ZONE_2, 1000);
                            break;
                        case EVENT_TIME_ZONE_2:
                            if (Creature* pAspect = instance->GetCreature(DATA_NOZDORMU_DRAGON))
                                pAspect->AI()->DoAction(ACTION_TIME_ZONE_2);
                            break;
                        case EVENT_ASPECT_TALK_2:
                        {
                            switch (urand(0, 3))
                            {
                                case 0:
                                    if (Creature* pAspect = instance->GetCreature(DATA_ALEXSTRASZA_DRAGON))
                                        pAspect->AI()->Talk(SAY_ALEXSTRASZA_PHASE_2);
                                    break;
                                case 1:
                                    if (Creature* pAspect = instance->GetCreature(DATA_NOZDORMU_DRAGON))
                                        pAspect->AI()->Talk(SAY_NOZDORMU_PHASE_2);
                                    break;
                                case 2:
                                    if (Creature* pAspect = instance->GetCreature(DATA_YSERA_DRAGON))
                                        pAspect->AI()->Talk(SAY_YSERA_PHASE_2);
                                    break;
                                case 3:
                                    if (Creature* pAspect = instance->GetCreature(DATA_KALECGOS_DRAGON))
                                        pAspect->AI()->Talk(SAY_KALECGOS_PHASE_2);
                                    break;
                            }

                            events.ScheduleEvent(EVENT_THRALL_TALK_2, 6000);
                            break;
                        }
                        case EVENT_THRALL_TALK_2:

                            if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                                pThrall->AI()->Talk(SAY_THRALL_PHASE_2);

                            break;
                        case EVENT_FINISH:
                        {
                            instance->DoStartMovie(76);
                            instance->DoCompleteAchievement(6107); //Achievement Fall of Deathwing

                            //75 Justices Points for players level 85
                            instance->DoModifyPlayerCurrencies(395, 7500);
                            if (!IsHeroic())
                            {
                                instance->DoModifyPlayerCurrencies(614, 1);
                                instance->DoModifyPlayerCurrencies(615, 1);
                            }
                            else
                            {
                                instance->DoModifyPlayerCurrencies(614, 2);
                                instance->DoModifyPlayerCurrencies(615, 2);
                                /* RoG_WoW Custom Content to allow Gaining Title that is no longer available*/
                                //instance->DoAddTitleIfLevel(158 /* Death's Demise, 85 */, 85 /* Lv 85 to Obtain it */);
                            }

                            DespawnCreatures(NPC_ALEXSTRASZA_DRAGON);
                            DespawnCreatures(NPC_KALECGOS_DRAGON);
                            DespawnCreatures(NPC_YSERA_DRAGON);
                            DespawnCreatures(NPC_NOZDORMU_DRAGON);
                            DespawnCreatures(NPC_THRALL_2);

                            me->SummonCreature(NPC_ALEXSTRASZA_2, alexstraszaendPos);
                            me->SummonCreature(NPC_NOZDORMU_2, nozdormuendPos);
                            me->SummonCreature(NPC_YSERA_2, yseraendPos);
                            me->SummonCreature(NPC_KALECGOS_2, kalecgosendPos);
                            me->SummonCreature(NPC_AGGRA, thrallendPos);
                            me->SummonCreature(NPC_THRALL_3, aggraendPos);

                            switch (GetDifficulty())
                            {
                            case DIFFICULTY_10_N:
                                if (Creature* trall = me->FindNearestCreature(NPC_THRALL_3, 500.0f, true))
                                if (!trall->FindNearestGameObject(GO_ELEMENTIUM_FRAGMENT_10N, 500.0f))
                                    trall->SummonGameObject(GO_ELEMENTIUM_FRAGMENT_10N, -12100.5f, 12173.6f, -2.73425f, 5.09636f, QuaternionData(), 7 * DAY);
                                break;
                            case DIFFICULTY_25_N:
                                if (Creature* trall = me->FindNearestCreature(NPC_THRALL_3, 500.0f, true))
                                if (!trall->FindNearestGameObject(GO_ELEMENTIUM_FRAGMENT_25N, 500.0f))
                                    trall->SummonGameObject(GO_ELEMENTIUM_FRAGMENT_25N, -12100.5f, 12173.6f, -2.73425f, 5.09636f, QuaternionData(), 7 * DAY);
                                break;
                            case DIFFICULTY_10_HC:
                                if (Creature* trall = me->FindNearestCreature(NPC_THRALL_3, 500.0f, true))
                                if (!trall->FindNearestGameObject(GO_ELEMENTIUM_FRAGMENT_10H, 500.0f))
                                    trall->SummonGameObject(GO_ELEMENTIUM_FRAGMENT_10H, -12100.5f, 12173.6f, -2.73425f, 5.09636f, QuaternionData(), 7 * DAY);
                                break;
                            case DIFFICULTY_25_HC:
                                if (Creature* trall = me->FindNearestCreature(NPC_THRALL_3, 500.0f, true))
                                if (!trall->FindNearestGameObject(GO_ELEMENTIUM_FRAGMENT_25H, 500.0f))
                                    trall->SummonGameObject(GO_ELEMENTIUM_FRAGMENT_25H, -12100.5f, 12173.6f, -2.73425f, 5.09636f, QuaternionData(), 7 * DAY);
                                break;

                            default: break;
                            }

                            me->DespawnOrUnsummon(5000);
                        }
                        default:
                            break;
                    }
                }
            }

        private:
            ObjectGuid limbsGuids[4] = {};
            uint8 m_current_platform;
            uint8 m_destroyed_platform;
            bool m_isFirst;
            bool m_isBerserk;

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                   return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                     (*iter)->DespawnOrUnsummon(2000);
            }

            Creature* GetLimbTentacleAtPlatform(uint8 platform)
            {
                if (platform)
                {
                    if (Creature* pLimb = ObjectAccessor::GetCreature(*me, limbsGuids[platform - 1]))
                        if (pLimb->IsAlive())
                            return pLimb;
                }

                return NULL;
            }
        };
};

class npc_dragon_soul_thrall_1 : public CreatureScript
{
    public:
        npc_dragon_soul_thrall_1() : CreatureScript("npc_dragon_soul_thrall_1") { }

        bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
        {
            /*if (pPlayer->IsInCombat())
                return true;*/

            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {
                /*if (pInstance->IsEncounterInProgress())
                    return true;*/

                /*if (pInstance->GetBossState(DATA_SPINE) != DONE ||
                    pInstance->GetBossState(DATA_MADNESS) != NOT_STARTED)
                    return true;*/

                if (pInstance->GetBossState(DATA_MADNESS) == DONE)
                    return true;

                if (pInstance->instance->IsHeroic() && !pInstance->GetData(DATA_ALL_HEROIC))
                {
                    //pPlayer->GetSession()->SendNotification(LANG_DS_HEROIC_MODE);
                    return true;
                }

                AddGossipItemFor(pPlayer, 0, GOSSIP_OPTION_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                SendGossipMenuFor(pPlayer, 1, pCreature->GetGUID());
                return true;
            }

            return false;
        }

        bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*sender*/, uint32 action) override
        {
            pPlayer->PlayerTalkClass->SendCloseGossip();

            /*if (pPlayer->IsInCombat())
                return true;*/

            if (InstanceScript* pInstance = pCreature->GetInstanceScript())
            {

                /*if (pInstance->IsEncounterInProgress())
                    return true;*/

               /* if (pInstance->GetBossState(DATA_SPINE) != DONE ||
                    pInstance->GetBossState(DATA_MADNESS) != NOT_STARTED)
                    return true;*/

                 if (pInstance->GetBossState(DATA_MADNESS) == DONE)
                return true;

                if (pInstance->instance->IsHeroic() && !pInstance->GetData(DATA_ALL_HEROIC))
                {
                    //pPlayer->GetSession()->SendNotification(LANG_DS_HEROIC_MODE);
                    return true;
                }

                if (action == GOSSIP_ACTION_INFO_DEF + 1)
                {
                    pInstance->SetBossState(DATA_MADNESS, IN_PROGRESS);
                    if (Creature* pDeathwing = pCreature->SummonCreature(NPC_DEATHWING, deathwingPos))
                    {
                        pDeathwing->AI()->DoZoneInCombat(pDeathwing, 500.0f);
                        pDeathwing->AI()->Talk(SAY_DEATHWING_AGGRO);
                    }

                    if (Creature* pAlextrasza = pCreature->SummonCreature(NPC_ALEXSTRASZA_DRAGON, alexstraszaPos))
                        pAlextrasza->SetInCombatWithZone();
                    if (Creature* pNozdormu = pCreature->SummonCreature(NPC_NOZDORMU_DRAGON, nozdormuPos))
                        pNozdormu->SetInCombatWithZone();
                    if (Creature* pYsera = pCreature->SummonCreature(NPC_YSERA_DRAGON, yseraPos))
                        pYsera->SetInCombatWithZone();
                    if (Creature* pKalecgos = pCreature->SummonCreature(NPC_KALECGOS_DRAGON, kalecgosPos))
                        pKalecgos->SetInCombatWithZone();

                    pCreature->AI()->DoAction(ACTION_CHECK_PLAYERS);
                    pCreature->AI()->DoCastAOE(SPELL_TRIGGER_ASPECT_BUFFS, true);
                    pCreature->CastSpell(pCreature, SPELL_ASTRAL_RECALL_1);
                }
            }
            return true;
        }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_thrall_1AI(pCreature);
        }

        struct npc_dragon_soul_thrall_1AI : public ScriptedAI
        {
            npc_dragon_soul_thrall_1AI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                pInstance = me->GetInstanceScript();
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_CHECK_PLAYERS)
                    events.ScheduleEvent(EVENT_CHECK_PLAYERS, 5000);
                else if (action == ACTION_RESET_BATTLE)
                    ResetBattle();
                else if (action == ACTION_END_BATTLE)
                {
                    DoCast(me, SPELL_ASTRAL_RECALL_2, true);
                    me->NearTeleportTo(thrallPos[1].GetPositionX(), thrallPos[1].GetPositionY(), thrallPos[1].GetPositionZ(), thrallPos[1].GetOrientation());
                    events.ScheduleEvent(EVENT_END_BATTLE, 2000);

                    if (pInstance)
                    {
                        pInstance->DoUpdateAchievementCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_ACHIEVEMENT, 0, me);
                        if (Creature* pDeathwing = pInstance->GetCreature(DATA_DEATHWING))
                        {
                            pDeathwing->RemoveAura(SPELL_SLUMP_1);
                            pDeathwing->CastSpell(pDeathwing, SPELL_SLUMP_2, true);
                        }
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_CHECK_PLAYERS)
                    {
                        if (pInstance)
                        {
                            if ((pInstance->GetBossState(DATA_MADNESS) != IN_PROGRESS) || !CheckPlayers())
                            {
                                ResetBattle();
                            }
                            else
                                events.ScheduleEvent(EVENT_CHECK_PLAYERS, 1000);
                        }
                    }
                    else if (eventId == EVENT_END_BATTLE)
                    {
                        me->UpdateObjectVisibility(true);
                        events.CancelEvent(EVENT_CHECK_PLAYERS);
                        ResetBattle(true);
                        DoCastAOE(SPELL_TRIGGER_ASPECT_YELL_1, true);
                        DoCastAOE(SPELL_FIRE_DRAGON_SOUL_ASPECTS, true);
                        events.ScheduleEvent(EVENT_DRAGON_SOUL, 1000);
                    }
                    else if (eventId == EVENT_DRAGON_SOUL)
                    {
                        DoCast(me, SPELL_FIRE_DRAGON_SOUL);
                    }
                }
            }

            void ResetBattle(bool done = false)
            {
                if (!done)
                {
                    me->AddNpcFlag(UNIT_NPC_FLAG_GOSSIP);

                    if (pInstance)
                    {
                        pInstance->SetBossState(DATA_MADNESS, NOT_STARTED);
                        RemoveEncounterAuras();
                        RemoveSpellDream();
                    }

                    healthValueNew = 0;
                    healthValue = 0;

                    ForceReset(NPC_MUTATED_CORRUPTION);
                    ForceReset(NPC_ARM_TENTACLE_1);
                    ForceReset(NPC_ARM_TENTACLE_2);
                    ForceReset(NPC_WING_TENTACLE);
                    ForceReset(NPC_BLISTERING_TENTACLE);
                    ForceReset(NPC_DEATHWING_1);

                    DespawnCreatures(NPC_DEATHWING);
                    DespawnCreatures(NPC_CLAWK_MARK);

                    DespawnCreatures(NPC_REGENERATIVE_BLOOD);
                    DespawnCreatures(NPC_ELEMENTIUM_BOLT);
                    DespawnCreatures(NPC_TIME_ZONE);
                    DespawnCreatures(NPC_IMPALING_TENTACLE);
                    DespawnCreatures(NPC_ELEMENTIUM_TERROR);
                    DespawnCreatures(NPC_CONGEALING_BLOOD);
                    DespawnCreatures(NPC_CORRUPTING_PARASITE);

                    DespawnCreatures(NPC_ALEXSTRASZA_DRAGON);
                    DespawnCreatures(NPC_KALECGOS_DRAGON);
                    DespawnCreatures(NPC_YSERA_DRAGON);
                    DespawnCreatures(NPC_NOZDORMU_DRAGON);

                    me->NearTeleportTo(me->GetHomePosition().GetPositionX(), me->GetHomePosition().GetPositionY(), me->GetHomePosition().GetPositionZ(), me->GetHomePosition().GetOrientation());
                    me->UpdateObjectVisibility(true);
                }
                else
                {
                    if (pInstance)
                    {
                        pInstance->SetBossState(DATA_MADNESS, DONE);
                        RemoveEncounterAuras();
                        RemoveSpellDream();
                    }

                    ForceReset(NPC_MUTATED_CORRUPTION);
                    ForceReset(NPC_BLISTERING_TENTACLE);
                    ForceReset(NPC_DEATHWING_1);

                    DespawnCreatures(NPC_WING_TENTACLE);
                    DespawnCreatures(NPC_ARM_TENTACLE_1);
                    DespawnCreatures(NPC_ARM_TENTACLE_2);
                    DespawnCreatures(NPC_REGENERATIVE_BLOOD);
                    DespawnCreatures(NPC_ELEMENTIUM_BOLT);
                    DespawnCreatures(NPC_TIME_ZONE);
                    DespawnCreatures(NPC_IMPALING_TENTACLE);
                    DespawnCreatures(NPC_ELEMENTIUM_TERROR);
                    DespawnCreatures(NPC_CONGEALING_BLOOD);
                    DespawnCreatures(NPC_CLAWK_MARK);
                }
            }

        private:

            EventMap events;
            InstanceScript* pInstance;

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                   return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                     (*iter)->DespawnOrUnsummon(2000);
            }

            void ForceReset(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                    return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    (*iter)->AI()->Reset();
            }

            void RemoveEncounterAuras()
            {
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ALEXSTRASZA_PRESENCE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NOZDORMU_PRESENCE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_YSERA_PRESENCE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_THE_DREAMER);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_KALECGOS_PRESENCE);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_SPELLWEAVER);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_YSERA_PRESENCE_AURA);
                pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ENTER_THE_DREAM);

            }

            void RemoveSpellDream()
            {
                Map::PlayerList const &PlayerList = me->GetMap()->GetPlayers();
                if (!PlayerList.isEmpty())
                {
                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        if(Player *player = i->GetSource())
                        if (player->HasSpell(SPELL_DREAM))
                            player->RemoveSpell(SPELL_DREAM, false, false);
                    }
                }
            }

            bool CheckPlayers()
            {
                Player* player = NULL;
                AnyLivePlayerNoGmCheck check(me, 500.0f);
                Trinity::PlayerSearcher<AnyLivePlayerNoGmCheck> searcher(me, player, check);
                Cell::VisitWorldObjects(me, searcher, 500.0f);
                return (player ? true : false);
            }

            class AnyLivePlayerNoGmCheck
            {
                public:
                    AnyLivePlayerNoGmCheck(WorldObject const* obj, float range) : _obj(obj), _range(range) {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (!_obj->IsWithinDistInMap(u, _range))
                            return false;

                        /*if (u->IsGameMaster())
                            return false;*/

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    float _range;
            };
        };
};

class npc_madness_of_deathwing_mutated_corruption : public CreatureScript
{
    public:
        npc_madness_of_deathwing_mutated_corruption() : CreatureScript("npc_madness_of_deathwing_mutated_corruption") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_mutated_corruptionAI(pCreature);
        }

        struct npc_madness_of_deathwing_mutated_corruptionAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_mutated_corruptionAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                pInstance = me->GetInstanceScript();
            }

            void Reset() override
            {
                me->SetVisible(false);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->setActive(true);
                me->SetReactState(REACT_PASSIVE);
                events.Reset();
                if (me->isDead())
                    me->Respawn();
            }

            void EnterCombat(Unit* /*who*/) override
            {
                if (me->IsVisible())
                {
                    events.ScheduleEvent(EVENT_CRUSH, urand(10000, 15000));
                    events.ScheduleEvent(EVENT_IMPALE, 12000);
                    events.ScheduleEvent(EVENT_SELECT_VICTIM, 5000);
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->Respawn();
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_CRUSH:
                            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            {
                                me->SetFacingToObject(pTarget);
                                DoCast(pTarget, SPELL_CRUSH);
                            }
                            events.ScheduleEvent(EVENT_CRUSH, 8000);
                            break;
                        case EVENT_IMPALE:
                        {
                            Unit* pTarget = me->GetVictim();

                            if (!me->IsWithinMeleeRange(pTarget))
                            {
                                Unit* pNearest = SelectTarget(SELECT_TARGET_NEAREST, 0, 0.0f, true);
                                if (pNearest)
                                    pTarget = pNearest;
                            }

                            DoCast(pTarget, SPELL_IMPALE);
                            events.ScheduleEvent(EVENT_IMPALE, 35000);
                            break;
                        }
                        case EVENT_SELECT_VICTIM:
                        {
                            Unit* pNearest = NULL;
                            if (!me->GetVictim() || !me->IsWithinMeleeRange(me->GetVictim()))
                            {
                                pNearest = SelectTarget(SELECT_TARGET_NEAREST, 0, 0.0f, true);

                                // Cast Impale Aspect
                                if (!pNearest || !me->IsWithinMeleeRange(pNearest))
                                {
                                    if (pInstance)
                                    {
                                        if (Creature* pDeathwing = pInstance->GetCreature(DATA_DEATHWING))
                                        {
                                            Unit* pAspect = NULL;
                                            uint8 platform = pDeathwing->AI()->GetData(DATA_CURRENT_PLATFORM);

                                            switch (platform)
                                            {
                                                case 1:
                                                    pAspect = pInstance->GetCreature(DATA_ALEXSTRASZA_DRAGON);
                                                    break;
                                                case 2:
                                                    pAspect = pInstance->GetCreature(DATA_NOZDORMU_DRAGON);
                                                    break;
                                                case 3:
                                                    pAspect = pInstance->GetCreature(DATA_YSERA_DRAGON);
                                                    break;
                                                case 4:
                                                    pAspect = pInstance->GetCreature(DATA_KALECGOS_DRAGON);
                                                    break;
                                            }

                                            if (pAspect)
                                            {
                                                pDeathwing->AI()->Talk(SAY_IMPALE_ASPECT);
                                                DoCast(pAspect, SPELL_IMPALE_ASPECT);
                                            }
                                        }
                                    }
                                }
                                else
                                    me->Attack(pNearest, true);
                            }

                            events.ScheduleEvent(EVENT_SELECT_VICTIM, 2000);
                            break;
                        }
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
        };
};

class npc_madness_of_deathwing_crush_target : public CreatureScript
{
    public:
        npc_madness_of_deathwing_crush_target() : CreatureScript("npc_madness_of_deathwing_crush_target") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_crush_targetAI(pCreature);
        }

        struct npc_madness_of_deathwing_crush_targetAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_crush_targetAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                if (Creature* pCorruption = me->FindNearestCreature(NPC_MUTATED_CORRUPTION, 80.0f))
                {
                    pCorruption->SetFacingToObject(me);
                    pCorruption->CastSpell(me, SPELL_CRUSH);
               }
            }
        };
};

class npc_madness_of_deathwing_limb_tentacle : public CreatureScript
{
    public:
        npc_madness_of_deathwing_limb_tentacle() : CreatureScript("npc_madness_of_deathwing_limb_tentacle") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_limb_tentacleAI(pCreature);
        }

        struct npc_madness_of_deathwing_limb_tentacleAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_limb_tentacleAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->SetReactState(REACT_PASSIVE);
                me->SetVisible(false);
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                phase = 0;
                tentacles = 0;
                m_current_platform = 0;

                pInstance = me->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                phase = 0;
                tentacles = 0;
                m_current_platform = 0;
                facing = false;
                me->SetVisible(false);
                if (me->isDead())
                    me->Respawn();
                if (me->HasAura(SPELL_BLISTERING_TENTACLE_VEHICLE))
                    me->RemoveAura(SPELL_BLISTERING_TENTACLE_VEHICLE);
                ForceReset(NPC_BLISTERING_TENTACLE);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                phase = 0;
                tentacles = 0;
                m_current_platform = 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_CURRENT_PLATFORM)
                    m_current_platform = data;
            }

            void JustSummoned(Creature* summon) override
            {
                if (summon->GetEntry() == NPC_BLISTERING_TENTACLE)
                    tentacles++;
                else if (summon->GetEntry() == NPC_HEMORRHAGE_TARGET)
                    summon->CastSpell(summon, SPELL_HEMORRHAGE_AURA, true);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_ASSAULT_ASPECTS_FIRST)
                {
                    events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 100);
                    events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                    events.ScheduleEvent(EVENT_HEMORRHAGE, IsHeroic() ? (55500 - 10000) : (85500 - 10000));
                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 12000 - 10000);
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 72000 - 10000);
                    }
                }
                else if (action == ACTION_ASSAULT_ASPECTS)
                {
                    events.ScheduleEvent(EVENT_ASSAULT_ASPECTS, 100);
                    events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                    events.ScheduleEvent(EVENT_HEMORRHAGE, IsHeroic() ? (70500 - 10000) : (100500 - 10000));
                    if (IsHeroic())
                    {
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 22000 - 10000);
                        events.ScheduleEvent(EVENT_CORRUPTING_PARASITE, 82000 - 10000);
                    }
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                events.Reset();

                if (pInstance && m_current_platform)
                {
                    if (Creature* pDeathwing = pInstance->GetCreature(DATA_DEATHWING))
                        pDeathwing->AI()->SetData(DATA_DESTROY_PLATFORM, m_current_platform);
                    if (Creature* pAspect = pInstance->GetCreature(DATA_NOZDORMU_DRAGON))
                        pAspect->AI()->SetData(DATA_LAST_ASSAULT_PLATFORM, m_current_platform);

                    switch (m_current_platform)
                    {
                        case 1:
                            if (Creature* pAspect = pInstance->GetCreature(DATA_ALEXSTRASZA_DRAGON))
                                DoCast(pAspect, SPELL_TRIGGER_CONCENTRATION, true);
                            break;
                        case 2:
                            if (Creature* pAspect = pInstance->GetCreature(DATA_NOZDORMU_DRAGON))
                                DoCast(pAspect, SPELL_TRIGGER_CONCENTRATION, true);
                            break;
                        case 3:
                            if (Creature* pAspect = pInstance->GetCreature(DATA_YSERA_DRAGON))
                                DoCast(pAspect, SPELL_TRIGGER_CONCENTRATION, true);
                            break;
                        case 4:
                            if (Creature* pAspect = pInstance->GetCreature(DATA_KALECGOS_DRAGON))
                                DoCast(pAspect, SPELL_TRIGGER_CONCENTRATION, true);
                            break;
                    }
                }

                ForceReset(NPC_BLISTERING_TENTACLE);
                DoCastAOE(SPELL_AGONIZING_PAIN, true);

                me->Respawn();
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if (!facing)
                {
                    facing = true;
                    if (Creature* ysera = me->FindNearestCreature(NPC_YSERA_DRAGON, 110.0f))
                        me->SetFacingToObject(ysera);
                    if (Creature* alextraza = me->FindNearestCreature(NPC_ALEXSTRASZA_DRAGON, 80.0f))
                        me->SetFacingToObject(alextraza);
                    if (Creature* kalecgos = me->FindNearestCreature(NPC_KALECGOS_DRAGON, 120.0f))
                        me->SetFacingToObject(kalecgos);
                    if (Creature* nozdormu = me->FindNearestCreature(NPC_NOZDORMU_DRAGON, 110.0f))
                        me->SetFacingToObject(nozdormu);
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if ((me->GetHealthPct() <= 75 && phase == 0) ||
                    (me->GetHealthPct() <= 50 && phase == 1) ||
                    (me->GetHealthPct() <= 25 && phase == 2))
                {
                    phase++;

                    ForceReset(NPC_BLISTERING_TENTACLE);
                    SitBlistering();

                    if (pInstance)
                    if (Creature* pAspect = pInstance->GetCreature(DATA_ALEXSTRASZA_DRAGON))
                    pAspect->AI()->DoAction(ACTION_CAUTERIZE);

                    return;
                }

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_ASSAULT_ASPECTS:
                            DoCast(me, SPELL_BURNING_BLOOD, true);
                            break;
                        case EVENT_HEMORRHAGE:
                            if (m_current_platform > 0)
                                me->SummonCreature(NPC_HEMORRHAGE_TARGET, hemorrhagePos[m_current_platform - 1], TEMPSUMMON_TIMED_DESPAWN, 10000);

                            break;
                        case EVENT_UPDATE_HEALTH:
                            if (Aura* aur = me->GetAura(SPELL_BURNING_BLOOD))
                            {
                                uint8 newstack = 100 - me->GetHealthPct();
                                if (newstack > 100) newstack = 100;
                                if (newstack < 1) newstack = 1;
                                if (aur->GetStackAmount() != newstack)
                                    aur->SetStackAmount(newstack);
                            }
                            events.ScheduleEvent(EVENT_UPDATE_HEALTH, 3000);
                            break;
                        case EVENT_CORRUPTING_PARASITE:
                            me->CastCustomSpell(SPELL_CORRUPTING_PARASITE_AOE, SPELLVALUE_MAX_TARGETS, 1, NULL, true);
                            break;
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            uint8 phase;
            uint8 tentacles;
            uint8 m_current_platform;
            bool facing;

            void ForceReset(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                    return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    (*iter)->AI()->Reset();
            }

            void SitBlistering()
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, NPC_BLISTERING_TENTACLE, 1000.0f);

                if (creatures.empty())
                    return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                {
                    (*iter)->CastSpell(me, SPELL_BLISTERING_TENTACLE_VEHICLE, true);
                    me->AddAura(SPELL_BLISTERING_HEAT, (*iter));
                    (*iter)->SetVisible(true);
                    (*iter)->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                    (*iter)->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    //(*iter)->ClearUnitState(UNIT_STATE_ONVEHICLE);
                    DoZoneInCombat((*iter), 200.0f);
                }
            }
        };
};

class npc_madness_of_deathwing_blistering_tentacle : public CreatureScript
{
    public:
        npc_madness_of_deathwing_blistering_tentacle() : CreatureScript("npc_madness_of_deathwing_blistering_tentacle") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_blistering_tentacleAI(pCreature);
        }

        struct npc_madness_of_deathwing_blistering_tentacleAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_blistering_tentacleAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_PERSISTENT_AREA_AURA, true);
                me->SetVisible(false);
                me->SetReactState(REACT_PASSIVE);

                me->SetCanFly(true);
                me->SetDisableGravity(true);
            }

            void Reset() override
            {
                me->SetReactState(REACT_PASSIVE);
                me->SetVisible(false);
                if (!me->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE))
                    me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                if (!me->HasUnitFlag(UNIT_FLAG_NON_ATTACKABLE))
                    me->AddUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                me->SetCombatReach(16.0f);
                if (me->HasAura(SPELL_BLISTERING_HEAT))
                    me->RemoveAura(SPELL_BLISTERING_HEAT);
                if (me->isDead())
                    me->Respawn();
                if (me->IsMounted())
                    me->ExitVehicle();
            }

            void DamageTaken(Unit* /*attacker*/, uint32 &damage) override
            {
                if (damage >= me->GetHealth())
                {
                    damage = 0;
                    me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                    me->SetVisible(false);
                    me->RemoveAllAuras();
                    //me->AddUnitState(UNIT_STATE_ONVEHICLE);
                }
            }
        };
};

class npc_madness_of_deathwing_regenerative_blood : public CreatureScript
{
    public:
        npc_madness_of_deathwing_regenerative_blood() : CreatureScript("npc_madness_of_deathwing_regenerative_blood") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_regenerative_bloodAI(pCreature);
        }

        struct npc_madness_of_deathwing_regenerative_bloodAI : public ScriptedAI
        {
            npc_madness_of_deathwing_regenerative_bloodAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->setActive(true);
                pInstance = me->GetInstanceScript();
                platform = GetGround(me);
            }

            void Reset() override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetPowerType(POWER_ENERGY);
                events.Reset();
                me->SetMaxPower(POWER_ENERGY, 90);
                me->SetMaxPower(POWER_RAGE, 90);
                me->SetPower(POWER_ENERGY, 0);
                me->SetPower(POWER_RAGE, 0);
                me->AddAura(SPELL_DEGENERATIVE_BITE_AURA, me);
                platform = GetGround(me);
            }


            void IsSummonedBy(Unit* /*summoner*/) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                DoZoneInCombat(me, 200.0f);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 150.0f, true))
                    AttackStart(target);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
            }

            void AttackStart(Unit* who) override
            {
                if (!who)
                    return;

                if (platform && platform != GetGround(who))
                {
                    me->Attack(who, false);
                }
                else
                {
                    if (me->Attack(who, true))
                        me->GetMotionMaster()->MoveChase(who);
                }
            }

            void JustDied(Unit* /*who*/) override
            {
                me->DespawnOrUnsummon(2000);
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_UPDATE_HEALTH:
                            //TODO : Figure out which power is it
                            if (me->GetPower(POWER_RAGE) < 90)
                            {
                                int32 power = me->GetPower(POWER_RAGE);
                                power = power + 10;
                                me->SetPower(POWER_ENERGY, power);
                                me->SetPower(POWER_RAGE, power);
                            }
                            else if (me->GetPower(POWER_RAGE) >= 90)
                            {
                                me->SetPower(POWER_ENERGY, 0);
                                me->SetPower(POWER_RAGE, 0);
                                DoCast(me, SPELL_REGENERATIVE_BLOOD_HEAL, true);
                                me->AddAura(SPELL_REGENERATIVE_BLOOD_AURA, me);
                            }
                            events.ScheduleEvent(EVENT_UPDATE_HEALTH, 1000);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            uint8 platform;
        };
};

class npc_madness_of_deathwing_elementium_bolt : public CreatureScript
{
    public:
        npc_madness_of_deathwing_elementium_bolt() : CreatureScript("npc_madness_of_deathwing_elementium_bolt") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_elementium_boltAI(pCreature);
        }

        struct npc_madness_of_deathwing_elementium_boltAI : public ScriptedAI
        {
            npc_madness_of_deathwing_elementium_boltAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->setActive(true);
                me->SetSpeed(MOVE_FLIGHT, 4.5f);
                me->SetSpeed(MOVE_WALK, 4.5f);
                me->SetSpeed(MOVE_RUN, 4.5f);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
                platform = 0;
                isSlow = false;
            }

            void IsSummonedBy(Unit* owner) override
            {
                if (!owner || !owner->ToCreature())
                    return;

                platform = owner->ToCreature()->AI()->GetData(DATA_CURRENT_PLATFORM);
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                if (!platform)
                    return;

                if (spellInfo->Id == SPELL_ELEMENTIUM_METEOR_SCRIPT)
                {
                    if (Creature* pTrigger = me->SummonCreature(NPC_CLAWK_MARK, boltPos[platform], TEMPSUMMON_MANUAL_DESPAWN))
                        pTrigger->AddAura(SPELL_ELEMENTIUM_METEOR_TARGET, pTrigger);
                    if (Creature* pTrigger = me->SummonCreature(NPC_PLATFORM, boltPos[platform], TEMPSUMMON_MANUAL_DESPAWN))
                        pTrigger->AddAura(SPELL_ELEMENTIUM_METEOR_TARGET, pTrigger);

                    me->GetMotionMaster()->MovePoint(DATA_METEOR_POINT, boltPos[platform]);
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == POINT_MOTION_TYPE)
                    if (id == DATA_METEOR_POINT)
                    {
                        if (Creature* pTrigger = me->FindNearestCreature(NPC_CLAWK_MARK, 100.0f, true))
                            pTrigger->DespawnOrUnsummon(1000);
                        if (Creature* pTrigger = me->FindNearestCreature(NPC_PLATFORM, 100.0f, true))
                            pTrigger->DespawnOrUnsummon(1000);
                        DoCast(me, SPELL_ELEMENTIUM_METEOR_AURA, true);
                        DoCast(me, SPELL_ELEMENTIUM_BLAST, true);
                        me->SetBoundingRadius(0.39f);
                        me->SetCombatReach(1.0f);
                    }
            }

            void JustDied(Unit* /*who*/) override
            {
                me->DespawnOrUnsummon(1000);
            }

            void UpdateAI(const uint32 /*diff*/) override
            {
                if (!isSlow && me->FindNearestCreature(NPC_TIME_ZONE, 15.0f, true))
                {
                    isSlow = true;
                    me->SetSpeed(MOVE_FLIGHT, 0.6f);
                    me->SetSpeed(MOVE_WALK, 0.6f);
                    me->SetSpeed(MOVE_RUN, 0.6f);
                }
                else if (isSlow && !me->FindNearestCreature(NPC_TIME_ZONE, 15.0f, true))
                {
                    me->SetSpeed(MOVE_FLIGHT, 4.5f);
                    me->SetSpeed(MOVE_WALK, 4.5f);
                    me->SetSpeed(MOVE_RUN, 4.5f);
                }
            }

        private:
            InstanceScript* pInstance;
            uint8 platform;
            bool isSlow;
        };
};

class npc_madness_of_deathwing_corrupting_parasite : public CreatureScript
{
    public:
        npc_madness_of_deathwing_corrupting_parasite() : CreatureScript("npc_madness_of_deathwing_corrupting_parasite") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_corrupting_parasiteAI(pCreature);
        }

        struct npc_madness_of_deathwing_corrupting_parasiteAI : public ScriptedAI
        {
            npc_madness_of_deathwing_corrupting_parasiteAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();

                m_unstable = false;
            }

            void Reset() override
            {
                events.Reset();
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_PARASITIC_BACKSLASH && !m_unstable)
                {
                    m_unstable = true;
                    me->SetObjectScale(me->GetObjectScale() * 3.3f);
                    events.ScheduleEvent(EVENT_UNSTABLE_CORRUPTION, 1000);

                    if (pInstance)
                        if (Creature* pAspect = pInstance->GetCreature(DATA_ALEXSTRASZA_DRAGON))
                            pAspect->AI()->DoAction(ACTION_CAUTERIZE_PARASITE);
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    if (eventId == EVENT_UNSTABLE_CORRUPTION)
                    {
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE));
                        DoCastAOE(SPELL_UNSTABLE_CORRUPTION);
                    }
                }
            }

            void JustDied(Unit* /*who*/) override
            {
                me->DespawnOrUnsummon(1000);
            }

        private:
            EventMap events;
            InstanceScript* pInstance;
            bool m_unstable;
        };
};

class npc_madness_of_deathwing_deathwing : public CreatureScript
{
    public:
        npc_madness_of_deathwing_deathwing() : CreatureScript("npc_madness_of_deathwing_deathwing") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_deathwingAI(pCreature);
        }

        struct npc_madness_of_deathwing_deathwingAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_deathwingAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);


                pInstance = me->GetInstanceScript();
            }

            void Reset() override
            {
                events.Reset();
                me->SetVisible(false);
                me->SetHealth(me->GetMaxHealth());
                isDead = false;
                phase = 0;
                healthValue = 0;
                healthValueNew = 0;
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetReactState(REACT_PASSIVE);
                if (me->HasAura(SPELL_CORRUPTED_BLOOD_STACKER))
                me->RemoveAura(SPELL_CORRUPTED_BLOOD_STACKER);
                if (me->HasAura(SPELL_SHRAPNEL_AURA))
                me->RemoveAura(SPELL_SHRAPNEL_AURA);
                if (me->HasAura(SPELL_CORRUPTED_BLOOD))
                    me->RemoveAura(SPELL_CORRUPTED_BLOOD);

                DespawnCreatures(NPC_IMPALING_TENTACLE);
                DespawnCreatures(NPC_ELEMENTIUM_TERROR);
                DespawnCreatures(NPC_CONGEALING_BLOOD);
            }

            void DoAction(const int32 action) override
            {
                if (action == ACTION_HP_UPDATE)
                {
                    phase = 0;
                    events.ScheduleEvent(EVENT_UPDATE_HEALTH, 500);
                    events.ScheduleEvent(EVENT_ELEMENTIUM_FRAGMENT, 10500);
                    events.ScheduleEvent(EVENT_ELEMENTIUM_TERROR, 35500);
                }

            }

            void DamageTaken(Unit* /*who*/, uint32& damage) override
            {
                if ((me->GetHealthPct() <= 15.0f && phase == 0) || (me->GetHealthPct() <= 10.0f && phase == 1) || (me->GetHealthPct() <= 5.0f && phase == 2))
                {
                    phase++;
                    if (IsHeroic())
                        for (uint8 i = 0; i < 8; ++i)
                            me->CastSpell(congealingPos[0].GetPositionX(), congealingPos[0].GetPositionY(), congealingPos[0].GetPositionZ(), SPELL_CONGEALING_BLOOD_MISSILE, true);
                }


                if (!isDead)
                    if (me->GetHealth() <= damage)
                    {
                        isDead = true;
                        if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                            pThrall->AI()->DoAction(ACTION_END_BATTLE);
                        me->SetVisible(false);
                    }
            }

            void HealReceived(Unit* /*who*/, uint32& /*heal*/) override
            {
                if (me->GetHealthPct() >= 15.0f && phase > 0)
                    phase = 0;
                else if (me->GetHealthPct() >= 10.0f && phase > 1)
                    phase = 1;
                else if (me->GetHealthPct() >= 5.0f && phase > 2)
                    phase = 2;
            }

            void JustSummoned(Creature* summon) override
            {
                DoZoneInCombat(summon);
            }

            void UpdateAI(const uint32 diff) override
            {

                if (healthValueNew > healthValue)
                {
                    healthValue = healthValueNew;
                    return;
                }

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPDATE_HEALTH:
                        {
                            healthValueNew = me->GetHealth();
                            if (AuraEffect* aurEff = me->GetAuraEffect(SPELL_CORRUPTED_BLOOD, EFFECT_1))
                            {
                                int32 newamount = 100 * (phase + 1);
                                aurEff->SetAmount(newamount);
                            }
                            uint32 newamount = (float(healthValue - healthValueNew) / float(healthValue)) * 100.0f;
                            me->SetPower(POWER_ALTERNATE_POWER, newamount);
                            events.ScheduleEvent(EVENT_UPDATE_HEALTH, 500);
                            break;
                        }
                        case EVENT_ELEMENTIUM_FRAGMENT:
                        {
                            DoCast(me, SPELL_IMPALING_TENTACLE_SCRIPT, true);
                            uint8 num = RAID_MODE(3, 8);
                            for (uint8 i = 0; i < num; ++i)
                            {
                                uint8 pos = urand(0, 7);
                                me->CastSpell(impalingPos[pos].GetPositionX(), impalingPos[pos].GetPositionY(), impalingPos[pos].GetPositionZ(), SPELL_IMPALING_TENTACLE_MISSILE, true);
                            }

                            events.ScheduleEvent(EVENT_ELEMENTIUM_FRAGMENT, 90000);
                            break;
                        }
                        case EVENT_ELEMENTIUM_TERROR:
                        {
                            DoCast(me, SPELL_ELEMENTIUM_TERROR_SCRIPT, true);
                            for (uint8 i = 0; i < 2; ++i)
                            {
                                uint8 pos = urand(0, 1);
                                me->CastSpell(terrorPos[pos].GetPositionX(), terrorPos[pos].GetPositionY(), terrorPos[pos].GetPositionZ(), SPELL_ELEMENTIUM_TERROR_MISSILE, true);
                            }

                            events.ScheduleEvent(EVENT_ELEMENTIUM_TERROR, 90000);
                            break;
                        }
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            bool isDead;
            uint8 phase;

            void DespawnCreatures(uint32 entry)
            {
                std::list<Creature*> creatures;
                GetCreatureListWithEntryInGrid(creatures, me, entry, 1000.0f);

                if (creatures.empty())
                    return;

                for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
                    (*iter)->DespawnOrUnsummon(2000);
            }
        };
};

class npc_madness_of_deathwing_impaling_tentacle : public CreatureScript
{
    public:
        npc_madness_of_deathwing_impaling_tentacle() : CreatureScript("npc_madness_of_deathwing_impaling_tentacle") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_impaling_tentacleAI(pCreature);
        }

        struct npc_madness_of_deathwing_impaling_tentacleAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_impaling_tentacleAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                events.Reset();
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(2000);
            }

            void SetGUID(ObjectGuid guid, int32 type) override
            {
                if (type == DATA_SHRAPNEL)
                {
                    if (!guid.IsEmpty())
                    {
                        targetGuid = guid;
                        events.ScheduleEvent(EVENT_SHRAPNEL, 200);
                    }
                }
            }
            void UpdateAI(const uint32 diff) override
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
                        case EVENT_SHRAPNEL:
                            if (Unit* pTarget = ObjectAccessor::GetUnit(*me, targetGuid))
                            {
                                DoCast(pTarget, SPELL_SHRAPNEL_TARGET, true);
                                DoCast(pTarget, SPELL_SHRAPNEL_DMG);
                            }
                            break;
                    }
                }
            }

        private:
            EventMap events;
            ObjectGuid targetGuid;
        };
};

class npc_madness_of_deathwing_elementium_terror : public CreatureScript
{
    public:
        npc_madness_of_deathwing_elementium_terror() : CreatureScript("npc_madness_of_deathwing_elementium_terror") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_elementium_terrorAI(pCreature);
        }

        struct npc_madness_of_deathwing_elementium_terrorAI : public ScriptedAI
        {
            npc_madness_of_deathwing_elementium_terrorAI(Creature* pCreature) : ScriptedAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_STUN, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_ROOT, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FREEZE, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);

                me->SetReactState(REACT_PASSIVE);
            }

            void Reset() override
            {
                events.Reset();
                me->AddAura(SPELL_ELEMENTIUM_TERROR_TETANUS_AUR, me);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(2000);
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                events.ScheduleEvent(EVENT_START_MOVE, 1000);
            }

            void UpdateAI(const uint32 diff) override
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
                        case EVENT_START_MOVE:
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap events;
        };
};

class npc_madness_of_deathwing_congealing_blood : public CreatureScript
{
    public:
        npc_madness_of_deathwing_congealing_blood() : CreatureScript("npc_madness_of_deathwing_congealing_blood") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_congealing_bloodAI(pCreature);
        }

        struct npc_madness_of_deathwing_congealing_bloodAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_congealing_bloodAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
                me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
                me->SetReactState(REACT_PASSIVE);
                me->SetSpeed(MOVE_RUN, 1.0f);
                pInstance = me->GetInstanceScript();
            }

            void IsSummonedBy(Unit* /*owner*/) override
            {
                isMove = true;
                bNear = false;
                events.ScheduleEvent(EVENT_START_MOVE, 1000);
            }

            void JustDied(Unit* /*killer*/) override
            {
                me->DespawnOrUnsummon(1000);
            }

            void MovementInform(uint32 type, uint32 data) override
            {
                if (type == POINT_MOTION_TYPE)
                    if (data == DATA_BLOOD_POINT)
                        events.ScheduleEvent(EVENT_CONGEALING_BLOOD_HEAL, 1);
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                if ((me->HasAuraType(SPELL_AURA_MOD_STUN) || me->HasAuraType(SPELL_AURA_MOD_ROOT) || me->isFrozen()) && (isMove))
                {
                    me->GetMotionMaster()->Clear();
                    isMove = false;
                    events.ScheduleEvent(EVENT_START_MOVE, 1000);
                    return;
                }

                if (Creature* trigger = me->FindNearestCreature(NPC_CONGEALING_HEAL, 500.0f, true))
                {
                    if (me->GetDistance(trigger) < 5.0f && !bNear)
                        {
                        if (Creature* deathwing = me->FindNearestCreature(NPC_DEATHWING_1, 500.0f, true))
                            {
                                bNear = true;
                                me->GetMotionMaster()->Clear();
                                me->CastSpell(deathwing, SPELL_CONGEALING_BLOOD_HEAL, true);
                                me->DespawnOrUnsummon();
                                return;
                            }
                        }
                }

                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_MOVE:
                            if (!isMove)
                                isMove = true;
                            if (Creature* deathwing = me->FindNearestCreature(NPC_CONGEALING_HEAL, 500.0f, true))
                               me->GetMotionMaster()->MoveFollow(deathwing, 1.0f, 0.0f);
                            break;
                        case EVENT_CONGEALING_BLOOD_HEAL:
                        {
                            if (Creature* deathwing = me->FindNearestCreature(NPC_DEATHWING_1, 500.0f, true))
                            {
                                me->CastSpell(deathwing, SPELL_CONGEALING_BLOOD_HEAL, true);
                                me->DespawnOrUnsummon();
                            }
                        }
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            bool isMove;
            bool bNear;
        };
};

class npc_dragon_soul_alexstrasza_dragon : public CreatureScript
{
    public:
        npc_dragon_soul_alexstrasza_dragon() : CreatureScript("npc_dragon_soul_alexstrasza_dragon") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_alexstrasza_dragonAI(pCreature);
        }

        struct npc_dragon_soul_alexstrasza_dragonAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_alexstrasza_dragonAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();

                isActive = true;
                me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                return;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                switch (spellInfo->Id)
                {
                    case SPELL_TRIGGER_CONCENTRATION:
                        isActive = false;
                        events.Reset();
                        me->RemoveAura(SPELL_ALEXSTRASZA_PRESENCE);
                        me->InterruptNonMeleeSpells(true);
                        DoCast(SPELL_CONCENTRATION_1);
                        break;
                    case SPELL_TRIGGER_ASPECT_BUFFS:
                        isActive = true;
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_ALEXSTRASZA_PRESENCE, true);
                        break;
                    case SPELL_TRIGGER_ASPECT_YELL_1:
                        Talk(SAY_ALEXTRASZA_END);
                        break;
                    case SPELL_FIRE_DRAGON_SOUL_ASPECTS:
                        isActive = false;
                        events.Reset();
                        me->RemoveAura(SPELL_ALEXSTRASZA_PRESENCE);
                        if (Creature* trall = me->FindNearestCreature(NPC_THRALL_2, 500.0f, true))
                            me->CastSpell(trall, SPELL_CONCENTRATION_5, true);
                        break;
                }
            }

            void DoAction(const int32 action) override
            {
                if (isActive && action == ACTION_CAUTERIZE)
                    events.ScheduleEvent(EVENT_CAUTERIZE, 2000);
                else if (isActive && action == ACTION_CAUTERIZE_PARASITE)
                    events.ScheduleEvent(EVENT_CAUTERIZE_PARASITE, 1000);

            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                    pThrall->AI()->DoAction(ACTION_RESET_BATTLE);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAUTERIZE:
                            DoCast(me, SPELL_CAUTERIZE_1, true);
                            break;
                        case EVENT_CAUTERIZE_PARASITE:
                            DoCast(me, SPELL_CAUTERIZE_3, true);
                            break;
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            bool isActive;
        };
};

class npc_dragon_soul_nozdormu_dragon : public CreatureScript
{
    public:
        npc_dragon_soul_nozdormu_dragon() : CreatureScript("npc_dragon_soul_nozdormu_dragon") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_nozdormu_dragonAI(pCreature);
        }

        struct npc_dragon_soul_nozdormu_dragonAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_nozdormu_dragonAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature), summons(me)
            {
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();

                isActive = true;
                me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                return;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_LAST_ASSAULT_PLATFORM)
                {
                    m_current_platform = (uint8)data;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                if (type == DATA_LAST_ASSAULT_PLATFORM)
                    return m_current_platform;
                return 0;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                switch (spellInfo->Id)
                {
                    case SPELL_TRIGGER_CONCENTRATION:
                        isActive = false;
                        events.Reset();
                        me->RemoveAura(SPELL_NOZDORMU_PRESENCE);
                        summons.DespawnEntry(NPC_TIME_ZONE);
                        me->InterruptNonMeleeSpells(true);
                        DoCast(SPELL_CONCENTRATION_2);
                        break;
                    case SPELL_TRIGGER_ASPECT_BUFFS:
                        isActive = true;
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_NOZDORMU_PRESENCE, true);
                        break;
                    case SPELL_FIRE_DRAGON_SOUL_ASPECTS:
                        isActive = false;
                        events.Reset();
                        me->InterruptNonMeleeSpells(true);
                        summons.DespawnEntry(NPC_TIME_ZONE);
                        me->RemoveAura(SPELL_NOZDORMU_PRESENCE);
                        if (Creature* trall = me->FindNearestCreature(NPC_THRALL_2, 500.0f, true))
                            me->CastSpell(trall, SPELL_CONCENTRATION_6, true);
                        break;
                }
            }

            void DoAction(const int32 action) override
            {
                if (isActive && action == ACTION_TIME_ZONE)
                {
                    summons.DespawnEntry(NPC_TIME_ZONE);
                    events.ScheduleEvent(EVENT_TIME_ZONE, urand(2000, 6000));
                }
                else if (action == ACTION_TIME_ZONE_2)
                {
                    summons.DespawnEntry(NPC_TIME_ZONE);
                    events.ScheduleEvent(EVENT_TIME_ZONE_2, urand(5000, 6000));
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                    pThrall->AI()->DoAction(ACTION_RESET_BATTLE);
            }

            void JustSummoned(Creature* summon) override
            {
                summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) override
            {
                summons.Despawn(summon);
            }

            void UpdateAI(const uint32 diff) override
            {
                events.Update(diff);

                if (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_TIME_ZONE:
                            if (pInstance)
                            {
                                if (Creature* pDeathwing = pInstance->GetCreature(DATA_DEATHWING))
                                {
                                    uint8 platform = pDeathwing->AI()->GetData(DATA_CURRENT_PLATFORM);
                                    if (platform < 1)
                                        break;

                                    me->CastSpell(timezonePos[platform - 1].GetPositionX(), timezonePos[platform - 1].GetPositionY(), timezonePos[platform - 1].GetPositionZ(), SPELL_TIME_ZONE_MISSILE_1, true);
                                }
                            }
                            break;
                        case EVENT_TIME_ZONE_2:
                            if (pInstance)
                            {
                                if (m_current_platform < 1)
                                        break;
                                else
                                        me->CastSpell(timezonePos[4].GetPositionX(), timezonePos[4].GetPositionY(), timezonePos[4].GetPositionZ(), SPELL_TIME_ZONE_MISSILE_2, true);
                            }
                            events.ScheduleEvent(EVENT_TIME_ZONE_2, 30000);
                            break;
                    }
                }
            }

        private:
            InstanceScript* pInstance;
            EventMap events;
            SummonList summons;
            bool isActive;
            uint8 m_current_platform;
        };
};

class npc_dragon_soul_ysera_dragon : public CreatureScript
{
    public:
        npc_dragon_soul_ysera_dragon() : CreatureScript("npc_dragon_soul_ysera_dragon") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_ysera_dragonAI(pCreature);
        }

        struct npc_dragon_soul_ysera_dragonAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_ysera_dragonAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
                me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                return;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                switch (spellInfo->Id)
                {
                    case SPELL_TRIGGER_CONCENTRATION:
                        me->RemoveAura(SPELL_YSERA_PRESENCE);
                        me->RemoveAura(SPELL_THE_DREAMER);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_YSERA_PRESENCE);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_YSERA_PRESENCE_AURA);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_THE_DREAMER);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ENTER_THE_DREAM);
                        me->InterruptNonMeleeSpells(true);
                        DoCast(SPELL_CONCENTRATION_3);
                        break;
                    case SPELL_TRIGGER_ASPECT_BUFFS:
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_YSERA_PRESENCE, true);
                        DoCast(me, SPELL_THE_DREAMER, true);
                        break;
                    case SPELL_FIRE_DRAGON_SOUL_ASPECTS:
                        me->RemoveAura(SPELL_YSERA_PRESENCE);
                        me->RemoveAura(SPELL_THE_DREAMER);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_YSERA_PRESENCE);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_YSERA_PRESENCE_AURA);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_THE_DREAMER);
                        pInstance->DoRemoveAurasDueToSpellOnPlayers(SPELL_ENTER_THE_DREAM);
                        if (Creature* trall = me->FindNearestCreature(NPC_THRALL_2, 500.0f, true))
                            me->CastSpell(trall, SPELL_CONCENTRATION_7, true);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                    pThrall->AI()->DoAction(ACTION_RESET_BATTLE);
            }

        private:
            InstanceScript* pInstance;
        };
};

class npc_dragon_soul_kalecgos_dragon : public CreatureScript
{
    public:
        npc_dragon_soul_kalecgos_dragon() : CreatureScript("npc_dragon_soul_kalecgos_dragon") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_dragon_soul_kalecgos_dragonAI(pCreature);
        }

        struct npc_dragon_soul_kalecgos_dragonAI : public Scripted_NoMovementAI
        {
            npc_dragon_soul_kalecgos_dragonAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);

                me->SetReactState(REACT_PASSIVE);

                pInstance = me->GetInstanceScript();
                me->SetAnimTier(UNIT_BYTE1_FLAG_HOVER, true);
                me->AddUnitMovementFlag(MOVEMENTFLAG_CAN_FLY | MOVEMENTFLAG_FLYING);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                return;
            }

            void SpellHit(Unit* /*who*/, const SpellInfo* spellInfo) override
            {
                switch (spellInfo->Id)
                {
                    case SPELL_TRIGGER_CONCENTRATION:
                        me->RemoveAura(SPELL_KALECGOS_PRESENCE);
                        me->RemoveAura(SPELL_SPELLWEAVER);
                        me->InterruptNonMeleeSpells(true);
                        DoCast(SPELL_CONCENTRATION_4);
                        break;
                    case SPELL_TRIGGER_ASPECT_BUFFS:
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_KALECGOS_PRESENCE, true);
                        DoCast(me, SPELL_SPELLWEAVER, true);
                        break;
                    case SPELL_FIRE_DRAGON_SOUL_ASPECTS:
                        me->RemoveAura(SPELL_KALECGOS_PRESENCE);
                        me->RemoveAura(SPELL_SPELLWEAVER);
                        if (Creature* trall = me->FindNearestCreature(NPC_THRALL_2, 500.0f, true))
                            me->CastSpell(trall, SPELL_CONCENTRATION_8, true);
                        break;
                }
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (Creature* pThrall = me->FindNearestCreature(NPC_THRALL_2, 500.0f))
                    pThrall->AI()->DoAction(ACTION_RESET_BATTLE);
            }

        private:
            InstanceScript* pInstance;
        };
};

class npc_madness_of_deathwing_jump_pad : public CreatureScript
{
    public:
        npc_madness_of_deathwing_jump_pad() : CreatureScript("npc_madness_of_deathwing_jump_pad") { }

        CreatureAI* GetAI(Creature* pCreature) const override
        {
            return new npc_madness_of_deathwing_jump_padAI(pCreature);
        }

        struct npc_madness_of_deathwing_jump_padAI : public Scripted_NoMovementAI
        {
            npc_madness_of_deathwing_jump_padAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
            {
                me->SetReactState(REACT_PASSIVE);
                checkTimer = 500;
                pos = 0;
                spellId = 0;
                spellIdEx1 = 0;
                spellIdEx2 = 0;
            }

            void Reset() override
            {
                for (uint8 i = 0; i < 6; ++i)
                {
                    if (me->GetExactDist(&jumpPos[i]) < 5.0f)
                    {
                        pos = i + 1;
                        switch (pos)
                        {
                            case 1:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_1;
                                spellIdEx1 = SPELL_CARRYING_WINDS_1;
                                spellIdEx2 = SPELL_CARRYING_WINDS_2;
                                break;
                            case 2:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_2;
                                spellIdEx1 = SPELL_CARRYING_WINDS_2;
                                spellIdEx2 = SPELL_CARRYING_WINDS_1;
                                break;
                            case 3:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_3;
                                spellIdEx1 = SPELL_CARRYING_WINDS_3;
                                spellIdEx2 = SPELL_CARRYING_WINDS_4;
                                break;
                            case 4:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_4;
                                spellIdEx1 = SPELL_CARRYING_WINDS_4;
                                spellIdEx2 = SPELL_CARRYING_WINDS_3;
                                break;
                            case 5:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_5;
                                spellIdEx1 = SPELL_CARRYING_WINDS_5;
                                spellIdEx2 = SPELL_CARRYING_WINDS_6;
                                break;
                            case 6:
                                spellId = SPELL_CARRYING_WINDS_SCRIPT_6;
                                spellIdEx1 = SPELL_CARRYING_WINDS_6;
                                spellIdEx2 = SPELL_CARRYING_WINDS_5;
                                break;
                        }
                        break;
                    }
                }
            }

            void UpdateAI(const uint32 diff) override
            {
                if (!spellId)
                    return;

                if (checkTimer <= diff)
                {
                    std::list<Player*> players;
                    PlayerCheck check(me/*, spellIdEx1, spellIdEx2*/);
                    Trinity::PlayerListSearcher<PlayerCheck> searcher(me, players, check);
                    Cell::VisitWorldObjects(me, searcher, 45.0f);
                    if (!players.empty())
                        for (std::list<Player*>::const_iterator itr = players.begin(); itr != players.end(); ++ itr)
                            DoCast((*itr), spellId, true);

                    checkTimer = 300;
                }
                else
                    checkTimer -= diff;
            }

        private:
            uint32 checkTimer;
            uint8 pos;
            uint32 spellId;
            uint32 spellIdEx1;
            uint32 spellIdEx2;

            class PlayerCheck
            {
                public:
                    PlayerCheck(WorldObject const* obj/*, uint32 spellEx1, uint32 spellEx2*/) : _obj(obj)/*, _spellEx1(spellEx1), _spellEx2(spellEx2)*/ {}
                    bool operator()(Player* u)
                    {
                        if (!u->IsAlive())
                            return false;

                        if (!u->IsFalling() || _obj->GetPositionZ() < (u->GetPositionZ() + 3.0f))
                            return false;

                        if (!_obj->IsWithinDistInMap(u, 45.0f))
                            return false;

                        /*if (u->HasAura(_spellEx1) || u->HasAura(_spellEx2))
                            return false;*/

                        if (Creature* pPad = u->FindNearestCreature(NPC_JUMP_PAD, 45.0f, true))
                            if (pPad->GetGUID() != _obj->GetGUID())
                                return false;

                        return true;
                    }

                private:
                    WorldObject const* _obj;
                    //uint32 _spellEx1, _spellEx2;
            };
        };
};

class spell_madness_of_deathwing_assault_aspects : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_assault_aspects() : SpellScriptLoader("spell_madness_of_deathwing_assault_aspects") { }

        class spell_madness_of_deathwing_assault_aspects_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_assault_aspects_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                uint8 players[4];
                memset(players, 0, sizeof(players));

                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if (WorldObject* object = (*itr))
                    {
                        uint8 ground =  GetGround(object);
                        if (ground > 0)
                            players[ground - 1]++;
                    }

                uint8 found = 0;
                uint8 max_val = 0;

                uint8 destroyed = 0;
                if (Creature* pDeathwing = GetCaster()->ToCreature())
                {
                    destroyed = pDeathwing->AI()->GetData(DATA_DESTROY_PLATFORM);

                    if (destroyed == 30)
                        return;

                    for (uint8 i = 0; i < 4; ++i)
                        if (players[i] > max_val && (destroyed & (1 << (i + 1))) == 0)
                        {
                            max_val = players[i];
                            found = i + 1;
                        }

                    if (found == 0)
                        for (uint8 i = 0; i < 4; ++i)
                            if ((destroyed & (1 << (i + 1))) == 0)
                            {
                                found = i + 1;
                                break;
                            }

                    if (found > 0)
                        pDeathwing->AI()->SetData(DATA_ASSAULT_PLATFORM, found);
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_madness_of_deathwing_assault_aspects_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_assault_aspects_SpellScript();
        }
};

class spell_madness_of_deathwing_crush_force : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_crush_force() : SpellScriptLoader("spell_madness_of_deathwing_crush_force") { }

        class spell_madness_of_deathwing_crush_force_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_crush_force_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                Trinity::Containers::RandomResize(targets, 1);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_madness_of_deathwing_crush_force_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_crush_force_SpellScript();
        }
};

class spell_madness_of_deathwing_hemorrhage_script : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_hemorrhage_script() : SpellScriptLoader("spell_madness_of_deathwing_hemorrhage_script") { }

        class spell_madness_of_deathwing_hemorrhage_script_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_hemorrhage_script_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                GetHitUnit()->CastSpell(GetCaster(), SPELL_HEMORRHAGE_MISSILE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_madness_of_deathwing_hemorrhage_script_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_hemorrhage_script_SpellScript();
        }
};

class spell_madness_of_deathwing_elementium_meteor_summon : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_elementium_meteor_summon() : SpellScriptLoader("spell_madness_of_deathwing_elementium_meteor_summon") { }

        class spell_madness_of_deathwing_elementium_meteor_summon_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_elementium_meteor_summon_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                WorldLocation summonPos = *GetExplTargetDest();
                summonPos.Relocate(boltPos[0]);
                SetExplTargetDest(summonPos);
                GetHitDest()->Relocate(boltPos[0]);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_madness_of_deathwing_elementium_meteor_summon_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SUMMON);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_elementium_meteor_summon_SpellScript();
        }
};

class spell_madness_of_deathwing_elementium_blast : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_elementium_blast() : SpellScriptLoader("spell_madness_of_deathwing_elementium_blast") { }

        class spell_madness_of_deathwing_elementium_blast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_elementium_blast_SpellScript);

            void HandleDamage()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                float distance = GetCaster()->GetExactDist2d(GetHitUnit());
                if (distance < 5.0f)
                    SetHitDamage(GetHitDamage() * 1.33f);
                else
                    SetHitDamage(int32(GetHitDamage() * 1.33f / (distance / 5.0f)));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_madness_of_deathwing_elementium_blast_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_elementium_blast_SpellScript();
        }
};

class spell_madness_of_deathwing_corrupting_parasite_aoe : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_corrupting_parasite_aoe() : SpellScriptLoader("spell_madness_of_deathwing_corrupting_parasite_aoe") { }

        class spell_madness_of_deathwing_corrupting_parasite_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_corrupting_parasite_aoe_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                Unit* pTarget = GetHitUnit();

                GetCaster()->CastSpell(GetHitUnit(), SPELL_CORRUPTING_PARASITE_AURA, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_CORRUPTING_PARASITE_DMG, true);
                if (Creature* pParasite = GetCaster()->SummonCreature(NPC_CORRUPTING_PARASITE, *pTarget))
                {
                    pParasite->AI()->DoZoneInCombat();
                    pParasite->EnterVehicle(GetHitUnit(), -1);
                    pParasite->SetObjectScale(pParasite->GetObjectScale() * 0.3f);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_madness_of_deathwing_corrupting_parasite_aoe_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_corrupting_parasite_aoe_SpellScript();
        }
};

class spell_madness_of_deathwing_corrupting_parasite_aura : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_corrupting_parasite_aura() : SpellScriptLoader("spell_madness_of_deathwing_corrupting_parasite_aura") { }

        class spell_madness_of_deathwing_corrupting_parasite_aura_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_madness_of_deathwing_corrupting_parasite_aura_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* owner = GetUnitOwner())
                {
                    owner->CastSpell((Unit*)NULL, SPELL_PARASITIC_BACKSLASH, true);
                    if (Creature* pParasite = owner->FindNearestCreature(NPC_CORRUPTING_PARASITE, 10.0f))
                        pParasite->AI()->DoAction(ACTION_PARASITIC_BACKSLASH);
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_madness_of_deathwing_corrupting_parasite_aura_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_madness_of_deathwing_corrupting_parasite_aura_AuraScript();
        }
};

class spell_madness_of_deathwing_agonizing_pain : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_agonizing_pain() : SpellScriptLoader("spell_madness_of_deathwing_agonizing_pain") { }

        class spell_madness_of_deathwing_agonizing_pain_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_agonizing_pain_SpellScript);

            void HandleDamage()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                int32 damage = GetHitUnit()->CountPctFromMaxHealth(20);

                SetHitDamage(damage);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_madness_of_deathwing_agonizing_pain_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_agonizing_pain_SpellScript();
        }
};

class spell_madness_of_deathwing_impale_aspect : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_impale_aspect() : SpellScriptLoader("spell_madness_of_deathwing_impale_aspect") { }

        class spell_madness_of_deathwing_impale_aspect_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_impale_aspect_SpellScript);

            void HandleDamage()
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                int32 damage = GetHitUnit()->CountPctFromMaxHealth(25);

                SetHitDamage(damage);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_madness_of_deathwing_impale_aspect_SpellScript::HandleDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_impale_aspect_SpellScript();
        }
};

class spell_madness_of_deathwing_shrapnel_aoe : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_shrapnel_aoe() : SpellScriptLoader("spell_madness_of_deathwing_shrapnel_aoe") { }

        class spell_madness_of_deathwing_shrapnel_aoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_shrapnel_aoe_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                if (targets.empty())
                    return;

                fragments.clear();

                for (std::list<WorldObject*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr)
                    if ((*itr)->GetEntry() == NPC_IMPALING_TENTACLE)
                        fragments.push_back((*itr)->GetGUID());
            }

            void FilterPlayers(std::list<WorldObject*>& targets)
            {
                if (!GetCaster())
                    return;

                Unit* pCaster = GetCaster();

                if (fragments.empty())
                    return;

                if (targets.empty())
                    return;

                targets.remove_if(PlayersCheck());

                Trinity::Containers::RandomResize(targets, fragments.size());

                for (std::list<ObjectGuid>::const_iterator itr = fragments.begin(); itr != fragments.end(); ++itr)
                {
                    if (targets.empty())
                        break;

                    if (Creature* pFragment = ObjectAccessor::GetCreature(*pCaster, (*itr)))
                    {
                        std::list<WorldObject*>::iterator itr_player = targets.begin();
                        pFragment->AI()->SetGUID((*itr_player)->GetGUID(), DATA_SHRAPNEL);
                        targets.erase(itr_player);
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_madness_of_deathwing_shrapnel_aoe_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_madness_of_deathwing_shrapnel_aoe_SpellScript::FilterPlayers, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
            }

        private:
            std::list<ObjectGuid> fragments;

            class PlayersCheck
            {
                public:
                    PlayersCheck() {}
                    bool operator()(WorldObject* unit)
                    {
                        if (unit->GetTypeId() != TYPEID_PLAYER)
                            return true;
                        return false;
                    }
            };
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_shrapnel_aoe_SpellScript();
        }
};

class spell_madness_of_deathwing_unstable_corruption : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_unstable_corruption() : SpellScriptLoader("spell_madness_of_deathwing_unstable_corruption") { }

        class spell_madness_of_deathwing_unstable_corruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_unstable_corruption_SpellScript);

            void HandleDamage()
            {
                if (!GetCaster())
                    return;

                int32 damage = 0.1f * GetCaster()->GetHealth();

                SetHitDamage(damage);
            }

            void HandleCast()
            {
                if (!GetCaster())
                    return;

                if (Creature* pParasite = GetCaster()->ToCreature())
                    pParasite->DespawnOrUnsummon(2000);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_madness_of_deathwing_unstable_corruption_SpellScript::HandleDamage);
                AfterCast += SpellCastFn(spell_madness_of_deathwing_unstable_corruption_SpellScript::HandleCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_unstable_corruption_SpellScript();
        }
};

class spell_madness_of_deathwing_carrying_winds_script : public SpellScriptLoader
{
    public:
        spell_madness_of_deathwing_carrying_winds_script(const char* name, uint8 pos) : SpellScriptLoader(name), _pos(pos) { }

        class spell_madness_of_deathwing_carrying_winds_script_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_madness_of_deathwing_carrying_winds_script_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (!GetCaster() || !GetHitUnit())
                    return;

                uint32 spellId = SPELL_CARRYING_WINDS_1;
                switch (_pos)
                {
                    case 1: spellId = SPELL_CARRYING_WINDS_1; break;
                    case 2: spellId = SPELL_CARRYING_WINDS_2; break;
                    case 3: spellId = SPELL_CARRYING_WINDS_3; break;
                    case 4: spellId = SPELL_CARRYING_WINDS_4; break;
                    case 5: spellId = SPELL_CARRYING_WINDS_5; break;
                    case 6: spellId = SPELL_CARRYING_WINDS_6; break;
                    default: break;
                }

                uint8 otherPos = (_pos % 2) == 1 ? _pos : _pos - 2;
                GetHitUnit()->CastSpell(jumpPos[otherPos].GetPositionX(), jumpPos[otherPos].GetPositionY(), jumpPos[otherPos].GetPositionZ(), spellId, true);
                GetHitUnit()->CastSpell(GetHitUnit(), SPELL_CARRYING_WINDS_SPEED_10, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_madness_of_deathwing_carrying_winds_script_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

        public:
            spell_madness_of_deathwing_carrying_winds_script_SpellScript(uint8 pos) : SpellScript(), _pos(pos) {}

        private:
            uint8 _pos;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_madness_of_deathwing_carrying_winds_script_SpellScript(_pos);
        }

    private:
        uint8 _pos;
};

class spell_madness_of_deathwing_burning_blood : public SpellScriptLoader
{
public:
    spell_madness_of_deathwing_burning_blood() : SpellScriptLoader("spell_madness_of_deathwing_burning_blood") { }

    class spell_madness_of_deathwing_burning_blood_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_madness_of_deathwing_burning_blood_SpellScript);

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster())
                return;

            if (Aura* aur = GetCaster()->GetAura(SPELL_BURNING_BLOOD))
            {
                uint32 ticks = aur->GetStackAmount();
                int32 dmg = GetHitDamage();
                SetHitDamage(dmg * ticks);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_madness_of_deathwing_burning_blood_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_madness_of_deathwing_burning_blood_SpellScript();
    }
};

// Degenerative Bite Proc 105842
class spell_madness_of_deathwing_degenerative_bite : public SpellScriptLoader
{
public:
    spell_madness_of_deathwing_degenerative_bite() : SpellScriptLoader("spell_madness_of_deathwing_degenerative_bite") { }

    class spell_madness_of_deathwing_degenerative_bite_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_madness_of_deathwing_degenerative_bite_AuraScript);

        bool OnCheckProc(ProcEventInfo& eventInfo)
        {
            if (Unit* target = eventInfo.GetActionTarget())
            {
               if(Aura* aur = target->GetAura(SPELL_DEGENERATIVE_BITE_DPS))
               {
                  aur->ModStackAmount(1);
                  return false;
               }
               return true;
            }
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_madness_of_deathwing_degenerative_bite_AuraScript::OnCheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_madness_of_deathwing_degenerative_bite_AuraScript();
    }
};

//Elementium Meteor Aura Dps 110632
class spell_madness_of_deathwing_elementium_meteor_aura_dps : public SpellScriptLoader
{
public:
    spell_madness_of_deathwing_elementium_meteor_aura_dps() : SpellScriptLoader("spell_madness_of_deathwing_elementium_meteor_aura_dps") { }

    class spell_madness_of_deathwing_elementium_meteor_aura_dps_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_madness_of_deathwing_elementium_meteor_aura_dps_SpellScript);

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster())
                return;
            if (!GetCaster()->GetMap()->IsHeroic())
                SetHitDamage(GetHitDamage() * 28.7f);
            else
                SetHitDamage(GetHitDamage() * 14.3f);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_madness_of_deathwing_elementium_meteor_aura_dps_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_madness_of_deathwing_elementium_meteor_aura_dps_SpellScript();
    }
};

class spell_madness_of_deathwing_spellweaving : public SpellScriptLoader
{
public:
    spell_madness_of_deathwing_spellweaving() : SpellScriptLoader("spell_madness_of_deathwing_spellweaving") { }

    class spell_madness_of_deathwing_spellweaving_AuraScript : public AuraScript

    {
        PrepareAuraScript(spell_madness_of_deathwing_spellweaving_AuraScript);


        void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();
            if (Unit* target = GetTarget())
                target->CastSpell(target, SPELL_SPELLWEAVING_DPS, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_madness_of_deathwing_spellweaving_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_madness_of_deathwing_spellweaving_AuraScript();
    }
};

// Tetanus Proc 106728
class spell_madness_of_deathwing_tetanus : public SpellScriptLoader
{
public:
    spell_madness_of_deathwing_tetanus() : SpellScriptLoader("spell_madness_of_deathwing_tetanus") { }

    class spell_madness_of_deathwing_tetanus_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_madness_of_deathwing_tetanus_AuraScript);

        bool OnCheckProc(ProcEventInfo& eventInfo)
        {
            if (Unit* target = eventInfo.GetActionTarget())
            {
                if (Aura* aur = target->GetAura(SPELL_ELEMENTIUM_TERROR_TETANUS_DPS))
                {
                    aur->ModStackAmount(1);
                    return false;
                }
                return true;
            }
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_madness_of_deathwing_tetanus_AuraScript::OnCheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_madness_of_deathwing_tetanus_AuraScript();
    }
};

//Corrupted Blood Dps 106835
class spell_madness_of_deathwing_corrupted_blood_dps : public SpellScriptLoader
{
public:
    spell_madness_of_deathwing_corrupted_blood_dps() : SpellScriptLoader("spell_madness_of_deathwing_corrupted_blood_dps") { }

    class spell_madness_of_deathwing_corrupted_blood_dps_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_madness_of_deathwing_corrupted_blood_dps_SpellScript);

        void HandleDamage()
        {

            if (!GetCaster())
                return;

            Unit* caster = GetCaster();
            uint32 HealthMaxValue = caster->GetMaxHealth();
            float damage = float(healthValueNew) / float(HealthMaxValue) * 5.0f; //That is the 100% of health, just when the dps start
            if (!damage)
                return;

            if (!caster->GetMap()->IsHeroic())
            {
                if (damage < 0.17f)
                    SetHitDamage(urand(21000, 34000));
                else
                    SetHitDamage(GetHitDamage() / damage);
            }
            else
            {
                if (damage < 0.22f)
                    SetHitDamage(urand(25000, 44000));
                else
                    SetHitDamage(GetHitDamage() / damage);
            }

        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_madness_of_deathwing_corrupted_blood_dps_SpellScript::HandleDamage);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_madness_of_deathwing_corrupted_blood_dps_SpellScript();
    }
};

//Fire Dragon Soul 109971
class spell_madness_of_deathwing_fire_dragon_soul : public SpellScriptLoader
{
public:
    spell_madness_of_deathwing_fire_dragon_soul() : SpellScriptLoader("spell_madness_of_deathwing_fire_dragon_soul") { }

    class spell_madness_of_deathwing_fire_dragon_soul_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_madness_of_deathwing_fire_dragon_soul_AuraScript);

        void OnPeriodic(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                if (Creature* deathwing = caster->FindNearestCreature(NPC_DEATHWING, 500.0f, true))
                    caster->CastSpell(deathwing, SPELL_FIRE_DRAGON_SOUL_SCRIPT, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_madness_of_deathwing_fire_dragon_soul_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_madness_of_deathwing_fire_dragon_soul_AuraScript();
    }
};

// Corrupting Parasite Dmg 108601
class spell_madness_of_deathwing_corrupting_parasite_dmg : public SpellScriptLoader
{
public:
    spell_madness_of_deathwing_corrupting_parasite_dmg() : SpellScriptLoader("spell_madness_of_deathwing_corrupting_parasite_dmg") { }

    AuraScript* GetAuraScript() const override
    {
        return new spell_madness_of_deathwing_corrupting_parasite_dmg_AuraScript();
    }

    class spell_madness_of_deathwing_corrupting_parasite_dmg_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_madness_of_deathwing_corrupting_parasite_dmg_AuraScript);

        void OnUpdate(AuraEffect* aurEff)
        {
            uint32 dmg = urand(145000, 150000);
            aurEff->SetAmount(dmg / (11 - (aurEff->GetTickNumber() / 2)));
        }

        void Register() override
        {
            OnEffectUpdatePeriodic += AuraEffectUpdatePeriodicFn(spell_madness_of_deathwing_corrupting_parasite_dmg_AuraScript::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };
};

class achievement_chromatic_champion : public AchievementCriteriaScript
{
public:
    achievement_chromatic_champion() : AchievementCriteriaScript("achievement_chromatic_champion") { }

    bool OnCheck(Player* /*source*/, Unit* /*target*/) override
    {
        return false;
    }
};

void AddSC_madness_of_deathwing()
{
    new boss_madness_of_deathwing();
    new npc_dragon_soul_thrall_1();
    new npc_madness_of_deathwing_mutated_corruption();
    new npc_madness_of_deathwing_crush_target();
    new npc_madness_of_deathwing_limb_tentacle();
    new npc_madness_of_deathwing_blistering_tentacle();
    new npc_madness_of_deathwing_regenerative_blood();
    new npc_madness_of_deathwing_elementium_bolt();
    new npc_madness_of_deathwing_corrupting_parasite();
    new npc_madness_of_deathwing_deathwing();
    new npc_madness_of_deathwing_impaling_tentacle();
    new npc_madness_of_deathwing_elementium_terror();
    new npc_madness_of_deathwing_congealing_blood();
    new npc_dragon_soul_alexstrasza_dragon();
    new npc_dragon_soul_nozdormu_dragon();
    new npc_dragon_soul_ysera_dragon();
    new npc_dragon_soul_kalecgos_dragon();
    new npc_madness_of_deathwing_jump_pad();
    new spell_madness_of_deathwing_assault_aspects();
    new spell_madness_of_deathwing_crush_force();
    new spell_madness_of_deathwing_hemorrhage_script();
    new spell_madness_of_deathwing_elementium_meteor_summon();
    new spell_madness_of_deathwing_elementium_blast();
    new spell_madness_of_deathwing_corrupting_parasite_aoe();
    new spell_madness_of_deathwing_corrupting_parasite_aura();
    new spell_madness_of_deathwing_agonizing_pain();
    new spell_madness_of_deathwing_impale_aspect();
    new spell_madness_of_deathwing_shrapnel_aoe();
    new spell_madness_of_deathwing_unstable_corruption();
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_1", 1);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_2", 2);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_3", 3);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_4", 4);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_5", 5);
    new spell_madness_of_deathwing_carrying_winds_script("spell_madness_of_deathwing_carrying_winds_script_6", 6);
    new spell_madness_of_deathwing_burning_blood();
    new spell_madness_of_deathwing_degenerative_bite();
    new spell_madness_of_deathwing_elementium_meteor_aura_dps;
    new spell_madness_of_deathwing_spellweaving();
    new spell_madness_of_deathwing_tetanus();
    new spell_madness_of_deathwing_corrupted_blood_dps();
    new spell_madness_of_deathwing_fire_dragon_soul();
    //new spell_madness_of_deathwing_corrupting_parasite_dmg(); Fix this when the hook work again
    new achievement_chromatic_champion();
}
