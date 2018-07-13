/*
 * Copyright (C) 2008-2018 TrinityCore <http://www.trinitycore.org/>
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
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "firelands.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include <G3D/Vector3.h>
#include "ObjectAccessor.h"
#include "Log.h"
#include "DynamicObject.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "TemporarySummon.h"
#include "MoveSplineInitArgs.h"
#include "MoveSplineInit.h"
#include "SpellMgr.h"

enum Texts
{
    // Ragnaros
    SAY_RAGNAROS_INTRO                      = 0,
    SAY_RAGNAROS_KILL                       = 1,
    SAY_RAGNAROS_SPLITTING_BLOW_SUBMERGE    = 2,
    SAY_RAGNAROS_WRATH_OF_RAGNAROS          = 3,
    SAY_RAGNAROS_SPLITTING_BLOW             = 4,
    SAY_RAGNAROS_SPLITTING_BLOW_EMERGE      = 5,
    SAY_RAGNAROS_NORMAL_SUBMERGE            = 6,
    SAY_RAGNAROS_HEROIC_SUBMERGE            = 7,
    SAY_RAGNAROS_HEROIC_INTRO_1             = 8,
    SAY_RAGNAROS_HEROIC_INTRO_2             = 9,
    SAY_RAGNAROS_HEROIC_DEATH               = 10,
    SAY_RAGNAROS_AGGRO                      = 11,
    SAY_RAGNAROS_RAGE_OF_RAGNAROS           = 12,
    EMOTE_ENGULFING_FLAMES                  = 13,
    EMOTE_SPLITTING_BLOW                    = 14,
    EMOTE_MAGMA_TRAP                        = 15,
    EMOTE_SULFURAS_SMASH                    = 16,
    EMOTE_WORLD_IN_FLAMES                   = 17,
    EMOTE_EMPOWER_SULFURAS                  = 18,
    EMOTE_DREADFLAME                        = 19,
    EMOTE_RAGE_OF_RAGNAROS                  = 20,
    EMOTE_SPLITTING_BLOW_EMERGE             = 21,
    EMOTE_BERSERK                           = 22,

    // Lava Scion
    EMOTE_LAVA_SCION_BLAZING_HEAT           = 0,

    // Cenarius
    SAY_CENARIUS_HEROIC_INTRO               = 0,
    SAY_CENARIUS_HEROIC_OUTRO_1             = 1,
    SAY_CENARIUS_HEROIC_OUTRO_2             = 2,
    SAY_CENARIUS_HEROIC_OUTRO_3             = 3,

    // Malfurion Stormrage
    SAY_MALFURION_HEROIC_INTRO              = 0,
    SAY_MALFURION_HEROIC_OUTRO_1            = 1,
    SAY_MALFURION_HEROIC_OUTRO_2            = 2,

    // Arch Druid Hamuul Runetotem
    SAY_HAMUUL_HEROIC_OUTRO                 = 0,
};

enum Spells
{
    // Lava Wielder
    SPELL_RAISE_LAVA                            = 99503,

    // Molten Worm
    SPELL_MOLTEN_VISUAL                         = 101032,
    SPELL_MOLTEN_BLAST                          = 99613,

    // Molten Spewer
    SPELL_LAVA_SPEWER_SUBMERGE                  = 99593,
    SPELL_MOLTEN_VOLLEY                         = 99611,

    // Molten Erupter
    SPELL_MOLTEN_ERUPTION                       = 99573,
    SPELL_MOLTEN_ERUPTION_TRIGGER_BOLT          = 99581,
    SPELL_MOLTEN_ERUPTION_BOLT                  = 99583,
    SPELL_MOLTEN_BOLT                           = 99579,

    // Ragnaros
    SPELL_BERSERK                               = 47008,
    SPELL_BASE_VISUAL                           = 98860,

    SPELL_BURNING_WOUNDS                        = 99401,
    SPELL_BURNING_WOUNDS_AURA                   = 99399,

    SPELL_MAGMA_BLAST                           = 98313,

    SPELL_RAGE_OF_RAGNAROS                      = 101107,
    SPELL_RAGE_OF_RAGNAROS_AURA                 = 101110,

    SPELL_WRATH_OF_RAGNAROS                     = 98259,
    SPELL_WRATH_OF_RAGNAROS_DAMAGE              = 98263,

    SPELL_MAGMA_TRAP                            = 98159,
    SPELL_MAGMA_TRAP_VISUAL                     = 98179,
    SPELL_MAGMA_TRAP_ERUPTION                   = 98175,
    SPELL_MAGMA_TRAP_PLAYER_TRIGGER             = 98172,
    SPELL_MAGMA_TRAP_TARGET_SEARCH              = 98171,
    SPELL_MAGMA_TRAP_VULNERABILITY              = 100238,
    SPELL_MAGMA_TRAP_MISSILE                    = 98164,

    SPELL_HAND_OF_RAGNAROS                      = 98237,

    SPELL_SULFURAS_SMASH                        = 98710,
    SPELL_SULFURAS_SMASH_DAMAGE                 = 98708,
    SPELL_SULFURAS_SMASH_SUMMON                 = 98706,
    SPELL_SULFURAS_SMASH_PLAYER_TRIGGER         = 98703,
    SPELL_SULFURAS_SMASH_LAVA_WAVE              = 98873,
    SPELL_SULFURAS_SMASH_LAVA_WAVE_N            = 98874,
    SPELL_SULFURAS_SMASH_LAVA_WAVE_W            = 98876,
    SPELL_SULFURAS_SMASH_LAVA_WAVE_E            = 98875,
    SPELL_SULFURAS_SMASH_LAVA_POOL              = 98712,
    SPELL_SCORCHED_GROUND                       = 98871,
    SPELL_LAVALOGGED                            = 101088,

    SPELL_SPLITTING_BLOW_WEST                   = 98951,
    SPELL_SPLITTING_BLOW_MIDDLE                 = 98952,
    SPELL_SPLITTING_BLOW_EAST                   = 98953,
    SPELL_SPLITTING_BLOW_TRIGGERED              = 99012,
    SPELL_INVOKE_SONS_MISSILE                   = 99050,
    SPELL_INVOKE_SONS                           = 99051,
    SPELL_SUBMERGE                              = 100051,
    SPELL_SUBMERGE_PERIODIC_AURA                = 98982,
    SPELL_SULFURAS                              = 100456,

    // Son of Flame
    SPELL_SON_OF_FLAME_HIT_ME                   = 100446,
    SPELL_SON_OF_FLAME_INVIS_PRE_VISUAL         = 98983,
    SPELL_SON_OF_FLAME_BURNING_SPEED            = 99414,
    SPELL_SON_OF_FLAME_BURNING_SPEED_CHECK      = 98473,
    SPELL_SON_OF_FLAME_SUPERNOVA                = 99112,

    SPELL_ENGULFING_FLAMES                      = 99171,
    SPELL_ENGULFING_FLAMES_PERIODIC             = 99225,
    SPELL_ENGULFING_FLAMES_NEAR                 = 99172,
    SPELL_ENGULFING_FLAMES_NEAR_VISUAL          = 99216,
    SPELL_ENGULFING_FLAMES_MIDDLE               = 99235,
    SPELL_ENGULFING_FLAMES_MIDDLE_VISUAL        = 99217,
    SPELL_ENGULFING_FLAMES_FAR                  = 99236,
    SPELL_ENGULFING_FLAMES_FAR_VISUAL           = 99218,
    SPELL_WORLD_IN_FLAMES                       = 100171,

    // Lava Scion
    SPELL_LAVA_SCION_BLAZING_HEAT               = 100460,
    SPELL_LAVA_SCION_BLAZING_HEAT_SUMMON        = 99129,
    SPELL_LAVA_SCION_BLAZING_HEAT_TARGET_SEARCH = 100459,

    // Molten Elemental
    SPELL_MOLTEN_SEED_TARGET_SEARCH             = 98333,
    SPELL_MOLTEN_SEED_MISSILE_TARGET_SEARCH     = 98497,
    SPELL_MOLTEN_SEED_MISSILE_HIT               = 98498,
    SPELL_MOLTEN_ELEMENTAL_INFERNO              = 98518,
    SPELL_MOLTEN_ELEMENTAL_COUNTDOWN            = 98520,
    SPELL_MOLTEN_ELEMENTAL_AGGRO_SUMMONER       = 100142,
    SPELL_MOLTEN_ELEMENTAL_INVIS_PRE_VISUAL     = 100153,
    SPELL_MOLTEN_ELEMENTAL_MOLTEN_POWER         = 100157,
    SPELL_MOLTEN_ELEMENTAL_DISABLE_CRIT         = 64481,

    // Living Meteor
    SPELL_LIVING_METEOR                         = 99267,
    SPELL_LIVING_METEOR_DAMAGE_REDUCTION        = 100904,
    SPELL_LIVING_METEOR_COMBUSTIBLE             = 99296,
    SPELL_LIVING_METEOR_PROXIMITY_CHECK         = 99269,
    SPELL_LIVING_METEOR_PROXIMITY_CHECK_HIT     = 99279,
    SPELL_LIVING_METEOR_SPEED_TRIGGER           = 100278,
    SPELL_LIVING_METEOR_SPEED_AURA              = 100277,
    SPELL_LIVING_METEOR_FIXATE_VISUAL           = 99849,
    SPELL_LIVING_METEOR_YOUR_FAULT_AURA         = 100910,
    SPELL_LIVING_METEOR_NOT_YOUR_FAULT_AURA     = 100911,
    SPELL_LIVING_METEOR_TRANSFORM_FROZEN        = 99301,
    SPELL_LIVING_METEOR_COMBUSTION              = 99303,
    SPELL_LIVING_METEOR_IMPACT                  = 99287,

    // Death/Defeat
    SPELL_AWARD_REPUTATION                      = 101620,
    SPELL_DEATH                                 = 99430,
    SPELL_SUMMON_CHEST                          = 101095,
    SPELL_ACHIEVEMENT_CHECK                     = 101091,
    SPELL_HEART_OF_RAGNAROS_H                   = 101252,
    SPELL_HEART_OF_RAGNAROS_A                   = 101253,
    SPELL_RAGNAROS_KILL_CREDIT                  = 102237,

    // Phase 4 - Heroic only
    SPELL_LEGS_SUBMERGE                         = 100312,
    SPELL_LEGS_HEAL                             = 100346,
    SPELL_HEROIC_TRANSFORM                      = 100420,
    SPELL_MAGMA_KNOCKUP                         = 108773,
    SPELL_MALFURION_TRANSFORM                   = 100310,
    SPELL_HAMUUL_TRANSFORM                      = 100311,
    SPELL_CENARIUS_DRAW_OUT_FIRELORD            = 100345,
    SPELL_HAMUUL_DRAW_OUT_FIRELORD              = 100344,
    SPELL_MALFURION_DRAW_OUT_FIRELORD           = 100342,

    SPELL_SUPERHEATED                           = 100593,

    SPELL_SUMMON_DREADFLAME_SPAWN               = 100675,
    SPELL_DREADFLAME_DAMAGE                     = 100941,
    SPELL_DREADFLAME                            = 100679,
    SPELL_DREADFLAME_SPAWN                      = 100692,
    SPELL_DREADFLAME_SPAWN_AURA                 = 100691,
    SPELL_DREADFLAME_SPREAD_CONTROL_AURA        = 100695,
    SPELL_DREADFLAME_DELUGE_CONTROL_AURA        = 100696,
    SPELL_DREADFLAME_SPAWN_CONTROL_AURA         = 100905,
    SPELL_DREADFLAME_DAMAGE_CONTROL_AURA        = 100965,

    SPELL_DELUGE_AURA                           = 100713,
    SPELL_DELUGE_EXTINGUISH_DREADFLAME          = 100757,
    SPELL_CLOUDBURST                            = 100751,
    SPELL_CLOUDBURST_VISUAL                     = 100758,
    SPELL_CLOUDBURST_MISSILE                    = 100714,

    SPELL_BREADTH_OF_FROST_TRIGGER              = 100472,
    SPELL_BREADTH_OF_FROST                      = 100479,
    SPELL_BREADTH_OF_FROST_PLAYER_AURA          = 100503,
    SPELL_BREADTH_OF_FROST_METEOR_AURA          = 100567,
    SPELL_BREADTH_OF_FROST_SUMMON               = 100476,
    SPELL_BREADTH_OF_FROST_TARGET_SEARCH        = 100478,

    SPELL_ENTRAPPING_ROOTS_TRIGGER              = 100645,
    SPELL_ENTRAPPING_ROOTS_SUMMON               = 100644,
    SPELL_ENTRAPPING_ROOTS_TARGET_SEARCH        = 100653,
    SPELL_ENTRAPPING_ROOTS                      = 100646,
    SPELL_ENTRAPPING_ROOTS_PERIODIC             = 100647,

    SPELL_EMPOWER_SULFURAS                      = 100604,
    SPELL_EMPOWER_SULFURAS_VISUAL_MISSILE       = 100606,
    SPELL_EMPOWER_SULFURAS_VISUAL_PERIODIC      = 100605,
    SPELL_EMPOWERED_SULFURAS                    = 100628,


    SPELL_DELUGE_AURA_CANCEL                    = 100771,

    //Misc
    SPELL_MAGMA_PERIODIC                        = 99908,
    SPELL_HEART_OF_RAGNAROS_CREATE_ITEM         = 101125,
};

enum Events
{
    EVENT_MOLTEN_VOLLEY                 = 1,
    EVENT_INTRO                         = 2,
    EVENT_WRATH_OF_RAGNAROS             = 3,
    EVENT_MAGMA_TRAP                    = 4,
    EVENT_SULFURAS_SMASH                = 5,
    EVENT_SPLITTING_BLOW_SUBMERGE       = 6,
    EVENT_SPLITTING_BLOW_EMERGE_WARNING = 7,
    EVENT_SPLITTING_BLOW_EMERGE         = 8,
    EVENT_ENGULFING_FLAMES              = 9,
    EVENT_HAND_OF_RAGNAROS              = 10,
    EVENT_MOLTEN_SEEDS                  = 11,
    EVENT_LIVING_METEOR                 = 12,
    EVENT_HEROIC_CENARIUS_1             = 13,
    EVENT_PREPARE_PHASE_FOUR            = 14,
    EVENT_PHASE_FOUR_EVENT_1            = 15,
    EVENT_PHASE_FOUR_EVENT_2            = 16,
    EVENT_PHASE_FOUR_EVENT_3            = 17,
    EVENT_SCHEDULE_PHASE_FOUR           = 18,
    EVENT_DRAW_OUT_FIRELORD             = 19,
    EVENT_HEROIC_MALFURION_1            = 20,
    EVENT_CLOUDBURST                    = 21,
    EVENT_DREADFLAME                    = 22,
    EVENT_BREADTH_OF_FROST              = 23,
    EVENT_ENTRAPPING_ROOTS              = 24,
    EVENT_EMPOWER_SULFURAS              = 25,
    EVENT_BERSERK                       = 26
};

enum Actions
{
    ACTION_NONE                         = 1,
    ACTION_INTRO                        = 2,
    ACTION_MOLTEN_ELEMENTAL_ACTIVATE    = 3,
    ACTION_RAGNAROS_HEROIC_SUBMERGE     = 4,
    ACTION_MALFURION_HEROIC_INTRO       = 5,
    ACTION_RAGNAROS_DREADFLAME          = 6,
    ACTION_LAVA_WORM_EMERGE             = 7,
    ACTION_MALFURION_OUTRO_1            = 8,
    ACTION_MALFURION_OUTRO_2            = 9,
    ACTION_CENARIUS_OUTRO_1             = 10,
    ACTION_CENARIUS_OUTRO_2             = 11,
    ACTION_CENARIUS_OUTRO_3             = 12,
    ACTION_HAMUUL_OUTRO_1               = 13,
};

enum AnimKits
{
    // Molten Spewer
    ANIM_KIT_MOLTEN_SPEWER_EMERGE   = 1254,

    // Ragnaros
    ANIM_KIT_RESURFACE              = 1465,
    ANIM_KIT_EMERGE                 = 1467,
    ANIM_KIT_TAUNT                  = 1468,
    ANIM_KIT_EMERGE_HC              = 1522,
    ANIM_KIT_STAND_UP               = 1486,

    // Malfurion & Hamuul
    ANIM_KIT_TALK                   = 1523,

    // Son of Flame
    ANIM_KIT_UNK                    = 1370,
};


enum Phases
{
    PHASE_NONE          = 0,
    PHASE_ONE           = 1,
    PHASE_INTERMISSION  = 2,
    PHASE_TWO           = 3,
    PHASE_THREE         = 4,
    PHASE_SUBMERGE      = 5,
    PHASE_FOUR          = 6,

    EVENT_GROUP_NONE    = 0,
};

enum CreatureGroups
{
    CREATURE_GROUP_MAGMA                    = 0,
    CREATURE_GROUP_SPLITTING_BLOW_WEST      = 1,
    CREATURE_GROUP_SPLITTING_BLOW_MIDDLE    = 2,
    CREATURE_GROUP_SPLITTING_BLOW_EAST      = 3,
    CREATURE_GROUP_ENGULFING_FLAMES_NEAR    = 4,
    CREATURE_GROUP_ENGULFING_FLAMES_MIDDLE  = 5,
    CREATURE_GROUP_ENGULFING_FLAMES_FAR     = 6,
    CREATURE_GROUP_LAVA_SCIONS              = 7,
    CREATURE_GROUP_PLAYER_HELPERS           = 8,
    CREATURE_GROUP_HELPER_TARGET            = 9,
    CREATURE_GROUP_CLOUDBURST_TARGETS       = 10
};

enum RagnarosData
{
    DATA_ENGULFING_FLAMES_NULL          = 0,
    DATA_ENGULFING_FLAMES_NEAR          = 1,
    DATA_ENGULFING_FLAMES_MIDDLE        = 2,
    DATA_ENGULFING_FLAMES_FAR           = 3,
    DATA_ENGULFING_FLAMES_ID            = 4,
    DATA_NEW_ENGULFING_FLAME            = 5,
    DATA_PREVIOUS_ENGULFING_FLAME       = 6,
    DATA_SPLITTING_BLOW_NONE            = 7,
    DATA_SPLITTING_BLOW_WEST            = 8,
    DATA_SPLITTING_BLOW_MIDDLE          = 9,
    DATA_SPLITTING_BLOW_EAST            = 10,
    DATA_SULFURAS_SMASH                 = 11,
    DATA_DELUGE_CHARGES                 = 12,
    DATA_IGNITED_METEORS                = 13,
    DATA_METEOR_CAST_COUNT              = 14,
};

enum RagnarosGUID : uint8
{
    GUID_SPLITTING_BLOW_WEST    = 1,
    GUID_SPLITTING_BLOW_MIDDLE  = 2,
    GUID_SPLITTING_BLOW_EAST    = 3,
    GUID_CLOUDBURST_TARGET      = 4,
    GUID_PLAYER_HELPER_TARGET   = 5,
};

enum Other
{
    EQUIP_DEFAULT               = 1,
    EQUIP_EMPOWERED_SULFURAS    = 2,

    ID_ENGULFING_FLAME_CAST     = 0,
    ID_ENGULFING_FLAME_VISUAL   = 1,


    SONS_OF_FLAME_COUNT         = 8,
    DREADFLAME_MIN_CD           = 10,
    DREADFLAME_BASE_CD          = 40,
};

struct SonOfFlameInfo
{
    Position    TargetPosition;
    uint32      ExcludeId;

    std::list<Position> GetPositionsExceptWithId(SonOfFlameInfo slotInfo[], uint32 length, uint32 id) const
    {
        std::list<Position> positions;
        for (uint32 i = 0; i < length; i++)
        {
            if (slotInfo[i].ExcludeId == id)
                continue;

            positions.push_back(slotInfo[i].TargetPosition);
        }
        return positions;
    }
};

uint32 const NormalSonsOfFlameSize = 10;
SonOfFlameInfo NormalSonsOfFlame[NormalSonsOfFlameSize] =
{
    { { 1074.852f, -12.31597f, 55.42412f,  3.700098f }, DATA_SPLITTING_BLOW_NONE },
    { { 1059.132f, -110.408f,  55.43525f,  2.408554f }, DATA_SPLITTING_BLOW_NONE },
    { { 1074.866f, -100.7882f, 55.42414f,  2.600541f }, DATA_SPLITTING_BLOW_NONE },
    { { 1058.323f, -3.836806f, 55.43348f,  3.874631f }, DATA_SPLITTING_BLOW_NONE },

    { { 1034.168f, -15.93056f, 55.60827f,  4.049164f }, DATA_SPLITTING_BLOW_WEST },
    { { 1012.12f,  -26.89063f, 55.564f,    4.39823f },  DATA_SPLITTING_BLOW_WEST },

    { { 997.1042f, -40.70486f, 55.48756f,  5.009095f }, DATA_SPLITTING_BLOW_MIDDLE },
    { { 996.7518f, -75.15278f, 55.54374f,  1.256637f }, DATA_SPLITTING_BLOW_MIDDLE },

    { { 1014.325f, -88.80209f, 55.52722f,  1.919862f }, DATA_SPLITTING_BLOW_EAST },
    { { 1035.049f, -98.75868f, 55.58205f,  2.234021f }, DATA_SPLITTING_BLOW_EAST },
};

uint32 const HeroicSonsOfFlameSize = 30;
SonOfFlameInfo HeroicSonsOfFlame[HeroicSonsOfFlameSize] =
{
    { { 1051.497f, -113.7292f, 55.44935f,  2.391101f }, DATA_SPLITTING_BLOW_NONE },
    { { 1051.76f,  0.1284722f, 55.44715f,  4.031711f }, DATA_SPLITTING_BLOW_NONE },
    { { 1055.332f, -105.0139f, 55.43525f,  2.408554f }, DATA_SPLITTING_BLOW_NONE },
    { { 1055.556f, -8.875f,    55.43348f,  3.874631f }, DATA_SPLITTING_BLOW_NONE },
    { { 1065.257f, -6.946181f, 55.56818f,  3.839724f }, DATA_SPLITTING_BLOW_NONE },
    { { 1065.372f, -108.8698f, 55.56829f,  2.373648f }, DATA_SPLITTING_BLOW_NONE },
    { { 1067.693f, -13.41146f, 55.53648f,  3.700098f }, DATA_SPLITTING_BLOW_NONE },
    { { 1068.151f, -101.3924f, 55.56828f,  2.565634f }, DATA_SPLITTING_BLOW_NONE },
    { { 1074.852f, -12.31597f, 55.42412f,  3.700098f }, DATA_SPLITTING_BLOW_NONE },
    { { 1074.866f, -100.7882f, 55.42414f,  2.600541f }, DATA_SPLITTING_BLOW_NONE },

    { { 1012.12f,  -26.89063f, 55.564f,    4.39823f },  DATA_SPLITTING_BLOW_WEST },
    { { 1025.852f, -16.11285f, 55.62734f,  4.049164f }, DATA_SPLITTING_BLOW_WEST },
    { { 1030.372f, -23.63715f, 55.44154f,  4.049164f }, DATA_SPLITTING_BLOW_WEST },
    { { 1034.168f, -15.93056f, 55.60827f,  4.049164f }, DATA_SPLITTING_BLOW_WEST },
    { { 1038.873f, -23.16319f, 55.42576f,  4.049164f }, DATA_SPLITTING_BLOW_WEST },
    { { 1043.059f, 0.3524306f, 55.44697f,  4.118977f }, DATA_SPLITTING_BLOW_WEST },

    { { 998.8941f, -69.07639f,  55.55765f, 1.256637f }, DATA_SPLITTING_BLOW_MIDDLE },
    { { 999.533f,  -45.74826f,  55.56229f, 5.009095f }, DATA_SPLITTING_BLOW_MIDDLE },
    { { 1013.458f, -68.08507f,  55.42097f, 2.513274f }, DATA_SPLITTING_BLOW_MIDDLE },
    { { 1014.134f, -43.94445f,  55.42412f, 3.979351f }, DATA_SPLITTING_BLOW_MIDDLE },
    { { 1059.384f, -0.8385417f, 55.4256f,  3.944444f }, DATA_SPLITTING_BLOW_MIDDLE },
    { { 1060.281f, -113.4549f,  55.42583f, 2.303835f }, DATA_SPLITTING_BLOW_MIDDLE },
    { { 1060.95f,  -98.13368f,  55.56828f, 2.513274f }, DATA_SPLITTING_BLOW_MIDDLE },
    { { 1061.34f,  -16.74132f,  55.56819f, 3.769911f }, DATA_SPLITTING_BLOW_MIDDLE },

    { { 1014.325f, -88.80209f, 55.52722f,  1.919862f }, DATA_SPLITTING_BLOW_EAST },
    { { 1024.845f, -97.67882f, 55.52884f,  2.234021f }, DATA_SPLITTING_BLOW_EAST },
    { { 1029.804f, -90.69097f, 55.57508f,  2.234021f }, DATA_SPLITTING_BLOW_EAST },
    { { 1035.049f, -98.75868f, 55.58205f,  2.234021f }, DATA_SPLITTING_BLOW_EAST },
    { { 1040.394f, -91.81944f, 55.42585f,  2.234021f }, DATA_SPLITTING_BLOW_EAST },
    { { 1042.033f, -114.9132f, 55.44709f,  1.919862f }, DATA_SPLITTING_BLOW_EAST }
};

uint8 const EngulfingFlamePositionsMax = 3;
uint8 const EngulfingFlamePositions[EngulfingFlamePositionsMax] =
{
    DATA_ENGULFING_FLAMES_NEAR,
    DATA_ENGULFING_FLAMES_MIDDLE,
    DATA_ENGULFING_FLAMES_FAR
};

uint32 const EngulfingFlames[4][2] =
{
    { 0, 0 },
    { SPELL_ENGULFING_FLAMES_NEAR,    SPELL_ENGULFING_FLAMES_NEAR_VISUAL },
    { SPELL_ENGULFING_FLAMES_MIDDLE,  SPELL_ENGULFING_FLAMES_MIDDLE_VISUAL },
    { SPELL_ENGULFING_FLAMES_FAR,     SPELL_ENGULFING_FLAMES_FAR_VISUAL }
};

uint32 const CenariusPathSize = 12;
G3D::Vector3 const CenariusPath[CenariusPathSize] =
{
    { 786.0003f, -59.59131f, 86.39431f },
    { 786.9566f, -59.88368f, 86.39431f },
    { 791.1458f, -60.22743f, 85.66431f },
    { 821.7049f, -59.6007f,  71.56089f },
    { 841.1945f, -58.5816f,  71.56089f },
    { 869.1875f, -59.21181f, 54.77988f },
    { 882.4983f, -58.99826f, 53.73591f },
    { 890.9254f, -58.80903f, 49.19218f },
    { 939.6042f, -59.17708f, 48.96181f },
    { 963.4393f, -58.2309f,  49.18719f },
    { 977.7205f, -57.77951f, 55.43077f },
    { 984.1371f, -57.65625f, 55.36652f }
};

uint32 const MalfurionPathSize = 5;
G3D::Vector3 const MalfurionPath[MalfurionPathSize] =
{
    { 787.3611f, -68.77084f, 93.93824f },
    { 788.3715f, -69.71528f, 98.04888f },
    { 881.5781f, -67.98959f, 79.69471f },
    { 961.5452f, -90.04861f, 72.05601f },
    { 984.2274f, -77.62153f, 61.69744f }
};

uint32 const HamuulPathSize = 6;
G3D::Vector3 const HamuulPath[HamuulPathSize] =
{
    { 788.2101f, -50.72396f, 93.77381f },
    { 789.7153f, -50.37674f, 97.14188f },
    { 842.7656f, -53.43576f, 88.88873f },
    { 884.75f,   -36.71354f, 60.77597f },
    { 951.0347f, -49.51215f, 60.77597f },
    { 982.9132f, -43.22049f, 59.49538f }
};

Position const RagnarosHeroicPosition = { 1072.38f, -57.4948f, 56.0f };

struct DreadflameInfo
{
    Position Position;
    ObjectGuid Owner;
    bool CanSpreadTo;
    std::vector<DreadflameInfo*> NearbyDreadflames;

    bool IsLit() const { return Owner != ObjectGuid::Empty; }
};

uint32 const DreadFlamesMax = 561;
Position ConstDreadflames[DreadFlamesMax] =
{
    { 1003.0f, -103.0f, 55.5f, 0.0f },
    { 1003.0f, -108.0f, 55.5f, 0.0f },
    { 1003.0f, -13.0f,  55.5f, 0.0f },
    { 1003.0f, -18.0f,  55.5f, 0.0f },
    { 1003.0f, -23.0f,  55.5f, 0.0f },
    { 1003.0f, -28.0f,  55.5f, 0.0f },
    { 1003.0f, -33.0f,  55.5f, 0.0f },
    { 1003.0f, -38.0f,  55.5f, 0.0f },
    { 1003.0f, -43.0f,  55.5f, 0.0f },
    { 1003.0f, -48.0f,  55.5f, 0.0f },
    { 1003.0f, -53.0f,  55.5f, 0.0f },
    { 1003.0f, -58.0f,  55.5f, 0.0f },
    { 1003.0f, -63.0f,  55.5f, 0.0f },
    { 1003.0f, -68.0f,  55.5f, 0.0f },
    { 1003.0f, -73.0f,  55.5f, 0.0f },
    { 1003.0f, -78.0f,  55.5f, 0.0f },
    { 1003.0f, -8.0f,   55.5f, 0.0f },
    { 1003.0f, -83.0f,  55.5f, 0.0f },
    { 1003.0f, -88.0f,  55.5f, 0.0f },
    { 1003.0f, -93.0f,  55.5f, 0.0f },
    { 1003.0f, -98.0f,  55.5f, 0.0f },
    { 1008.0f, -103.0f, 55.5f, 0.0f },
    { 1008.0f, -108.0f, 55.5f, 0.0f },
    { 1008.0f, -113.0f, 55.5f, 0.0f },
    { 1008.0f, -13.0f,  55.5f, 0.0f },
    { 1008.0f, -18.0f,  55.5f, 0.0f },
    { 1008.0f, -23.0f,  55.5f, 0.0f },
    { 1008.0f, -28.0f,  55.5f, 0.0f },
    { 1008.0f, -3.0f,   55.5f, 0.0f },
    { 1008.0f, -33.0f,  55.5f, 0.0f },
    { 1008.0f, -38.0f,  55.5f, 0.0f },
    { 1008.0f, -43.0f,  55.5f, 0.0f },
    { 1008.0f, -48.0f,  55.5f, 0.0f },
    { 1008.0f, -53.0f,  55.5f, 0.0f },
    { 1008.0f, -58.0f,  55.5f, 0.0f },
    { 1008.0f, -63.0f,  55.5f, 0.0f },
    { 1008.0f, -68.0f,  55.5f, 0.0f },
    { 1008.0f, -73.0f,  55.5f, 0.0f },
    { 1008.0f, -78.0f,  55.5f, 0.0f },
    { 1008.0f, -8.0f,   55.5f, 0.0f },
    { 1008.0f, -83.0f,  55.5f, 0.0f },
    { 1008.0f, -88.0f,  55.5f, 0.0f },
    { 1008.0f, -93.0f,  55.5f, 0.0f },
    { 1008.0f, -98.0f,  55.5f, 0.0f },
    { 1013.0f, -103.0f, 55.5f, 0.0f },
    { 1013.0f, -108.0f, 55.5f, 0.0f },
    { 1013.0f, -113.0f, 55.5f, 0.0f },
    { 1013.0f, -118.0f, 55.5f, 0.0f },
    { 1013.0f, -123.0f, 55.5f, 0.0f },
    { 1013.0f, -13.0f,  55.5f, 0.0f },
    { 1013.0f, -18.0f,  55.5f, 0.0f },
    { 1013.0f, -23.0f,  55.5f, 0.0f },
    { 1013.0f, -28.0f,  55.5f, 0.0f },
    { 1013.0f, -3.0f,   55.5f, 0.0f },
    { 1013.0f, -33.0f,  55.5f, 0.0f },
    { 1013.0f, -38.0f,  55.5f, 0.0f },
    { 1013.0f, -43.0f,  55.5f, 0.0f },
    { 1013.0f, -48.0f,  55.5f, 0.0f },
    { 1013.0f, -53.0f,  55.5f, 0.0f },
    { 1013.0f, -58.0f,  55.5f, 0.0f },
    { 1013.0f, -63.0f,  55.5f, 0.0f },
    { 1013.0f, -68.0f,  55.5f, 0.0f },
    { 1013.0f, -73.0f,  55.5f, 0.0f },
    { 1013.0f, -78.0f,  55.5f, 0.0f },
    { 1013.0f, -8.0f,   55.5f, 0.0f },
    { 1013.0f, -83.0f,  55.5f, 0.0f },
    { 1013.0f, -88.0f,  55.5f, 0.0f },
    { 1013.0f, -93.0f,  55.5f, 0.0f },
    { 1013.0f, -98.0f,  55.5f, 0.0f },
    { 1013.0f, 2.0f,    55.5f, 0.0f },
    { 1013.0f, 7.0f,    55.5f, 0.0f },
    { 1018.0f, -103.0f, 55.5f, 0.0f },
    { 1018.0f, -108.0f, 55.5f, 0.0f },
    { 1018.0f, -113.0f, 55.5f, 0.0f },
    { 1018.0f, -118.0f, 55.5f, 0.0f },
    { 1018.0f, -123.0f, 55.5f, 0.0f },
    { 1018.0f, -128.0f, 55.5f, 0.0f },
    { 1018.0f, -13.0f,  55.5f, 0.0f },
    { 1018.0f, -18.0f,  55.5f, 0.0f },
    { 1018.0f, -23.0f,  55.5f, 0.0f },
    { 1018.0f, -28.0f,  55.5f, 0.0f },
    { 1018.0f, -3.0f,   55.5f, 0.0f },
    { 1018.0f, -33.0f,  55.5f, 0.0f },
    { 1018.0f, -38.0f,  55.5f, 0.0f },
    { 1018.0f, -43.0f,  55.5f, 0.0f },
    { 1018.0f, -48.0f,  55.5f, 0.0f },
    { 1018.0f, -53.0f,  55.5f, 0.0f },
    { 1018.0f, -58.0f,  55.5f, 0.0f },
    { 1018.0f, -63.0f,  55.5f, 0.0f },
    { 1018.0f, -68.0f,  55.5f, 0.0f },
    { 1018.0f, -73.0f,  55.5f, 0.0f },
    { 1018.0f, -78.0f,  55.5f, 0.0f },
    { 1018.0f, -8.0f,   55.5f, 0.0f },
    { 1018.0f, -83.0f,  55.5f, 0.0f },
    { 1018.0f, -88.0f,  55.5f, 0.0f },
    { 1018.0f, -93.0f,  55.5f, 0.0f },
    { 1018.0f, -98.0f,  55.5f, 0.0f },
    { 1018.0f, 12.0f,   55.5f, 0.0f },
    { 1018.0f, 2.0f,    55.5f, 0.0f },
    { 1018.0f, 7.0f,    55.5f, 0.0f },
    { 1023.0f, -103.0f, 55.5f, 0.0f },
    { 1023.0f, -108.0f, 55.5f, 0.0f },
    { 1023.0f, -113.0f, 55.5f, 0.0f },
    { 1023.0f, -118.0f, 55.5f, 0.0f },
    { 1023.0f, -123.0f, 55.5f, 0.0f },
    { 1023.0f, -128.0f, 55.5f, 0.0f },
    { 1023.0f, -13.0f,  55.5f, 0.0f },
    { 1023.0f, -18.0f,  55.5f, 0.0f },
    { 1023.0f, -23.0f,  55.5f, 0.0f },
    { 1023.0f, -28.0f,  55.5f, 0.0f },
    { 1023.0f, -3.0f,   55.5f, 0.0f },
    { 1023.0f, -33.0f,  55.5f, 0.0f },
    { 1023.0f, -38.0f,  55.5f, 0.0f },
    { 1023.0f, -43.0f,  55.5f, 0.0f },
    { 1023.0f, -48.0f,  55.5f, 0.0f },
    { 1023.0f, -53.0f,  55.5f, 0.0f },
    { 1023.0f, -58.0f,  55.5f, 0.0f },
    { 1023.0f, -63.0f,  55.5f, 0.0f },
    { 1023.0f, -68.0f,  55.5f, 0.0f },
    { 1023.0f, -73.0f,  55.5f, 0.0f },
    { 1023.0f, -78.0f,  55.5f, 0.0f },
    { 1023.0f, -8.0f,   55.5f, 0.0f },
    { 1023.0f, -83.0f,  55.5f, 0.0f },
    { 1023.0f, -88.0f,  55.5f, 0.0f },
    { 1023.0f, -93.0f,  55.5f, 0.0f },
    { 1023.0f, -98.0f,  55.5f, 0.0f },
    { 1023.0f, 12.0f,   55.5f, 0.0f },
    { 1023.0f, 2.0f,    55.5f, 0.0f },
    { 1023.0f, 7.0f,    55.5f, 0.0f },
    { 1028.0f, -103.0f, 55.5f, 0.0f },
    { 1028.0f, -108.0f, 55.5f, 0.0f },
    { 1028.0f, -113.0f, 55.5f, 0.0f },
    { 1028.0f, -118.0f, 55.5f, 0.0f },
    { 1028.0f, -123.0f, 55.5f, 0.0f },
    { 1028.0f, -128.0f, 55.5f, 0.0f },
    { 1028.0f, -13.0f,  55.5f, 0.0f },
    { 1028.0f, -18.0f,  55.5f, 0.0f },
    { 1028.0f, -23.0f,  55.5f, 0.0f },
    { 1028.0f, -28.0f,  55.5f, 0.0f },
    { 1028.0f, -3.0f,   55.5f, 0.0f },
    { 1028.0f, -33.0f,  55.5f, 0.0f },
    { 1028.0f, -38.0f,  55.5f, 0.0f },
    { 1028.0f, -43.0f,  55.5f, 0.0f },
    { 1028.0f, -48.0f,  55.5f, 0.0f },
    { 1028.0f, -53.0f,  55.5f, 0.0f },
    { 1028.0f, -58.0f,  55.5f, 0.0f },
    { 1028.0f, -63.0f,  55.5f, 0.0f },
    { 1028.0f, -68.0f,  55.5f, 0.0f },
    { 1028.0f, -73.0f,  55.5f, 0.0f },
    { 1028.0f, -78.0f,  55.5f, 0.0f },
    { 1028.0f, -8.0f,   55.5f, 0.0f },
    { 1028.0f, -83.0f,  55.5f, 0.0f },
    { 1028.0f, -88.0f,  55.5f, 0.0f },
    { 1028.0f, -93.0f,  55.5f, 0.0f },
    { 1028.0f, -98.0f,  55.5f, 0.0f },
    { 1028.0f, 12.0f,   55.5f, 0.0f },
    { 1028.0f, 2.0f,    55.5f, 0.0f },
    { 1028.0f, 7.0f,    55.5f, 0.0f },
    { 1033.0f, -103.0f, 55.5f, 0.0f },
    { 1033.0f, -108.0f, 55.5f, 0.0f },
    { 1033.0f, -113.0f, 55.5f, 0.0f },
    { 1033.0f, -118.0f, 55.5f, 0.0f },
    { 1033.0f, -123.0f, 55.5f, 0.0f },
    { 1033.0f, -128.0f, 55.5f, 0.0f },
    { 1033.0f, -13.0f,  55.5f, 0.0f },
    { 1033.0f, -18.0f,  55.5f, 0.0f },
    { 1033.0f, -23.0f,  55.5f, 0.0f },
    { 1033.0f, -28.0f,  55.5f, 0.0f },
    { 1033.0f, -3.0f,   55.5f, 0.0f },
    { 1033.0f, -33.0f,  55.5f, 0.0f },
    { 1033.0f, -38.0f,  55.5f, 0.0f },
    { 1033.0f, -43.0f,  55.5f, 0.0f },
    { 1033.0f, -48.0f,  55.5f, 0.0f },
    { 1033.0f, -53.0f,  55.5f, 0.0f },
    { 1033.0f, -58.0f,  55.5f, 0.0f },
    { 1033.0f, -63.0f,  55.5f, 0.0f },
    { 1033.0f, -68.0f,  55.5f, 0.0f },
    { 1033.0f, -73.0f,  55.5f, 0.0f },
    { 1033.0f, -78.0f,  55.5f, 0.0f },
    { 1033.0f, -8.0f,   55.5f, 0.0f },
    { 1033.0f, -83.0f,  55.5f, 0.0f },
    { 1033.0f, -88.0f,  55.5f, 0.0f },
    { 1033.0f, -93.0f,  55.5f, 0.0f },
    { 1033.0f, -98.0f,  55.5f, 0.0f },
    { 1033.0f, 12.0f,   55.5f, 0.0f },
    { 1033.0f, 2.0f,    55.5f, 0.0f },
    { 1033.0f, 7.0f,    55.5f, 0.0f },
    { 1038.0f, -103.0f, 55.5f, 0.0f },
    { 1038.0f, -108.0f, 55.5f, 0.0f },
    { 1038.0f, -113.0f, 55.5f, 0.0f },
    { 1038.0f, -118.0f, 55.5f, 0.0f },
    { 1038.0f, -123.0f, 55.5f, 0.0f },
    { 1038.0f, -128.0f, 55.5f, 0.0f },
    { 1038.0f, -13.0f,  55.5f, 0.0f },
    { 1038.0f, -18.0f,  55.5f, 0.0f },
    { 1038.0f, -23.0f,  55.5f, 0.0f },
    { 1038.0f, -28.0f,  55.5f, 0.0f },
    { 1038.0f, -3.0f,   55.5f, 0.0f },
    { 1038.0f, -33.0f,  55.5f, 0.0f },
    { 1038.0f, -38.0f,  55.5f, 0.0f },
    { 1038.0f, -43.0f,  55.5f, 0.0f },
    { 1038.0f, -48.0f,  55.5f, 0.0f },
    { 1038.0f, -53.0f,  55.5f, 0.0f },
    { 1038.0f, -58.0f,  55.5f, 0.0f },
    { 1038.0f, -63.0f,  55.5f, 0.0f },
    { 1038.0f, -68.0f,  55.5f, 0.0f },
    { 1038.0f, -73.0f,  55.5f, 0.0f },
    { 1038.0f, -78.0f,  55.5f, 0.0f },
    { 1038.0f, -8.0f,   55.5f, 0.0f },
    { 1038.0f, -83.0f,  55.5f, 0.0f },
    { 1038.0f, -88.0f,  55.5f, 0.0f },
    { 1038.0f, -93.0f,  55.5f, 0.0f },
    { 1038.0f, -98.0f,  55.5f, 0.0f },
    { 1038.0f, 12.0f,   55.5f, 0.0f },
    { 1038.0f, 2.0f,    55.5f, 0.0f },
    { 1038.0f, 7.0f,    55.5f, 0.0f },
    { 1043.0f, -103.0f, 55.5f, 0.0f },
    { 1043.0f, -108.0f, 55.5f, 0.0f },
    { 1043.0f, -113.0f, 55.5f, 0.0f },
    { 1043.0f, -118.0f, 55.5f, 0.0f },
    { 1043.0f, -123.0f, 55.5f, 0.0f },
    { 1043.0f, -13.0f,  55.5f, 0.0f },
    { 1043.0f, -18.0f,  55.5f, 0.0f },
    { 1043.0f, -23.0f,  55.5f, 0.0f },
    { 1043.0f, -28.0f,  55.5f, 0.0f },
    { 1043.0f, -3.0f,   55.5f, 0.0f },
    { 1043.0f, -33.0f,  55.5f, 0.0f },
    { 1043.0f, -38.0f,  55.5f, 0.0f },
    { 1043.0f, -43.0f,  55.5f, 0.0f },
    { 1043.0f, -48.0f,  55.5f, 0.0f },
    { 1043.0f, -53.0f,  55.5f, 0.0f },
    { 1043.0f, -58.0f,  55.5f, 0.0f },
    { 1043.0f, -63.0f,  55.5f, 0.0f },
    { 1043.0f, -68.0f,  55.5f, 0.0f },
    { 1043.0f, -73.0f,  55.5f, 0.0f },
    { 1043.0f, -78.0f,  55.5f, 0.0f },
    { 1043.0f, -8.0f,   55.5f, 0.0f },
    { 1043.0f, -83.0f,  55.5f, 0.0f },
    { 1043.0f, -88.0f,  55.5f, 0.0f },
    { 1043.0f, -93.0f,  55.5f, 0.0f },
    { 1043.0f, -98.0f,  55.5f, 0.0f },
    { 1043.0f, 2.0f,    55.5f, 0.0f },
    { 1043.0f, 7.0f,    55.5f, 0.0f },
    { 1048.0f, -103.0f, 55.5f, 0.0f },
    { 1048.0f, -108.0f, 55.5f, 0.0f },
    { 1048.0f, -113.0f, 55.5f, 0.0f },
    { 1048.0f, -118.0f, 55.5f, 0.0f },
    { 1048.0f, -13.0f , 55.5f, 0.0f },
    { 1048.0f, -18.0f,  55.5f, 0.0f },
    { 1048.0f, -23.0f,  55.5f, 0.0f },
    { 1048.0f, -28.0f,  55.5f, 0.0f },
    { 1048.0f, -3.0f,   55.5f, 0.0f },
    { 1048.0f, -33.0f,  55.5f, 0.0f },
    { 1048.0f, -38.0f,  55.5f, 0.0f },
    { 1048.0f, -43.0f,  55.5f, 0.0f },
    { 1048.0f, -48.0f,  55.5f, 0.0f },
    { 1048.0f, -53.0f,  55.5f, 0.0f },
    { 1048.0f, -58.0f,  55.5f, 0.0f },
    { 1048.0f, -63.0f,  55.5f, 0.0f },
    { 1048.0f, -68.0f,  55.5f, 0.0f },
    { 1048.0f, -73.0f,  55.5f, 0.0f },
    { 1048.0f, -78.0f,  55.5f, 0.0f },
    { 1048.0f, -8.0f,   55.5f, 0.0f },
    { 1048.0f, -83.0f,  55.5f, 0.0f },
    { 1048.0f, -88.0f,  55.5f, 0.0f },
    { 1048.0f, -93.0f,  55.5f, 0.0f },
    { 1048.0f, -98.0f,  55.5f, 0.0f },
    { 1048.0f, 2.0f,    55.5f, 0.0f },
    { 1053.0f, -103.0f, 55.5f, 0.0f },
    { 1053.0f, -108.0f, 55.5f, 0.0f },
    { 1053.0f, -113.0f, 55.5f, 0.0f },
    { 1053.0f, -118.0f, 55.5f, 0.0f },
    { 1053.0f, -13.0f,  55.5f, 0.0f },
    { 1053.0f, -18.0f,  55.5f, 0.0f },
    { 1053.0f, -23.0f,  55.5f, 0.0f },
    { 1053.0f, -28.0f,  55.5f, 0.0f },
    { 1053.0f, -3.0f,   55.5f, 0.0f },
    { 1053.0f, -33.0f,  55.5f, 0.0f },
    { 1053.0f, -38.0f,  55.5f, 0.0f },
    { 1053.0f, -43.0f,  55.5f, 0.0f },
    { 1053.0f, -48.0f,  55.5f, 0.0f },
    { 1053.0f, -53.0f,  55.5f, 0.0f },
    { 1053.0f, -58.0f,  55.5f, 0.0f },
    { 1053.0f, -63.0f,  55.5f, 0.0f },
    { 1053.0f, -68.0f,  55.5f, 0.0f },
    { 1053.0f, -73.0f,  55.5f, 0.0f },
    { 1053.0f, -78.0f,  55.5f, 0.0f },
    { 1053.0f, -8.0f,   55.5f, 0.0f },
    { 1053.0f, -83.0f,  55.5f, 0.0f },
    { 1053.0f, -88.0f,  55.5f, 0.0f },
    { 1053.0f, -93.0f,  55.5f, 0.0f },
    { 1053.0f, -98.0f,  55.5f, 0.0f },
    { 1053.0f, 2.0f,    55.5f, 0.0f },
    { 1058.0f, -103.0f, 55.5f, 0.0f },
    { 1058.0f, -108.0f, 55.5f, 0.0f },
    { 1058.0f, -113.0f, 55.5f, 0.0f },
    { 1058.0f, -118.0f, 55.5f, 0.0f },
    { 1058.0f, -13.0f,  55.5f, 0.0f },
    { 1058.0f, -18.0f,  55.5f, 0.0f },
    { 1058.0f, -23.0f,  55.5f, 0.0f },
    { 1058.0f, -28.0f,  55.5f, 0.0f },
    { 1058.0f, -3.0f,   55.5f, 0.0f },
    { 1058.0f, -33.0f,  55.5f, 0.0f },
    { 1058.0f, -38.0f,  55.5f, 0.0f },
    { 1058.0f, -43.0f,  55.5f, 0.0f },
    { 1058.0f, -48.0f,  55.5f, 0.0f },
    { 1058.0f, -53.0f,  55.5f, 0.0f },
    { 1058.0f, -58.0f,  55.5f, 0.0f },
    { 1058.0f, -63.0f,  55.5f, 0.0f },
    { 1058.0f, -68.0f,  55.5f, 0.0f },
    { 1058.0f, -73.0f,  55.5f, 0.0f },
    { 1058.0f, -78.0f,  55.5f, 0.0f },
    { 1058.0f, -8.0f,   55.5f, 0.0f },
    { 1058.0f, -83.0f,  55.5f, 0.0f },
    { 1058.0f, -88.0f,  55.5f, 0.0f },
    { 1058.0f, -93.0f,  55.5f, 0.0f },
    { 1058.0f, -98.0f,  55.5f, 0.0f },
    { 1058.0f, 2.0f,    55.5f, 0.0f },
    { 1063.0f, -103.0f, 55.5f, 0.0f },
    { 1063.0f, -108.0f, 55.5f, 0.0f },
    { 1063.0f, -113.0f, 55.5f, 0.0f },
    { 1063.0f, -118.0f, 55.5f, 0.0f },
    { 1063.0f, -13.0f,  55.5f, 0.0f },
    { 1063.0f, -18.0f,  55.5f, 0.0f },
    { 1063.0f, -23.0f,  55.5f, 0.0f },
    { 1063.0f, -28.0f,  55.5f, 0.0f },
    { 1063.0f, -3.0f,   55.5f, 0.0f },
    { 1063.0f, -33.0f,  55.5f, 0.0f },
    { 1063.0f, -38.0f,  55.5f, 0.0f },
    { 1063.0f, -43.0f,  55.5f, 0.0f },
    { 1063.0f, -48.0f,  55.5f, 0.0f },
    { 1063.0f, -53.0f,  55.5f, 0.0f },
    { 1063.0f, -58.0f,  55.5f, 0.0f },
    { 1063.0f, -63.0f,  55.5f, 0.0f },
    { 1063.0f, -68.0f,  55.5f, 0.0f },
    { 1063.0f, -73.0f,  55.5f, 0.0f },
    { 1063.0f, -78.0f,  55.5f, 0.0f },
    { 1063.0f, -8.0f,   55.5f, 0.0f },
    { 1063.0f, -83.0f,  55.5f, 0.0f },
    { 1063.0f, -88.0f,  55.5f, 0.0f },
    { 1063.0f, -93.0f,  55.5f, 0.0f },
    { 1063.0f, -98.0f,  55.5f, 0.0f },
    { 1063.0f, 2.0f,    55.5f, 0.0f },
    { 1068.0f, -103.0f, 55.5f, 0.0f },
    { 1068.0f, -108.0f, 55.5f, 0.0f },
    { 1068.0f, -113.0f, 55.5f, 0.0f },
    { 1068.0f, -13.0f,  55.5f, 0.0f },
    { 1068.0f, -18.0f,  55.5f, 0.0f },
    { 1068.0f, -23.0f,  55.5f, 0.0f },
    { 1068.0f, -28.0f,  55.5f, 0.0f },
    { 1068.0f, -3.0f,   55.5f, 0.0f },
    { 1068.0f, -33.0f,  55.5f, 0.0f },
    { 1068.0f, -38.0f,  55.5f, 0.0f },
    { 1068.0f, -43.0f,  55.5f, 0.0f },
    { 1068.0f, -48.0f,  55.5f, 0.0f },
    { 1068.0f, -53.0f,  55.5f, 0.0f },
    { 1068.0f, -58.0f,  55.5f, 0.0f },
    { 1068.0f, -63.0f,  55.5f, 0.0f },
    { 1068.0f, -68.0f,  55.5f, 0.0f },
    { 1068.0f, -73.0f,  55.5f, 0.0f },
    { 1068.0f, -78.0f,  55.5f, 0.0f },
    { 1068.0f, -8.0f,   55.5f, 0.0f },
    { 1068.0f, -83.0f,  55.5f, 0.0f },
    { 1068.0f, -88.0f,  55.5f, 0.0f },
    { 1068.0f, -93.0f,  55.5f, 0.0f },
    { 1068.0f, -98.0f,  55.5f, 0.0f },
    { 1073.0f, -103.0f, 55.5f, 0.0f },
    { 1073.0f, -108.0f, 55.5f, 0.0f },
    { 1073.0f, -13.0f,  55.5f, 0.0f },
    { 1073.0f, -18.0f,  55.5f, 0.0f },
    { 1073.0f, -23.0f,  55.5f, 0.0f },
    { 1073.0f, -28.0f,  55.5f, 0.0f },
    { 1073.0f, -33.0f,  55.5f, 0.0f },
    { 1073.0f, -38.0f,  55.5f, 0.0f },
    { 1073.0f, -43.0f,  55.5f, 0.0f },
    { 1073.0f, -48.0f,  55.5f, 0.0f },
    { 1073.0f, -53.0f,  55.5f, 0.0f },
    { 1073.0f, -58.0f,  55.5f, 0.0f },
    { 1073.0f, -63.0f,  55.5f, 0.0f },
    { 1073.0f, -68.0f,  55.5f, 0.0f },
    { 1073.0f, -73.0f,  55.5f, 0.0f },
    { 1073.0f, -78.0f,  55.5f, 0.0f },
    { 1073.0f, -8.0f,   55.5f, 0.0f },
    { 1073.0f, -83.0f,  55.5f, 0.0f },
    { 1073.0f, -88.0f,  55.5f, 0.0f },
    { 1073.0f, -93.0f,  55.5f, 0.0f },
    { 1073.0f, -98.0f,  55.5f, 0.0f },
    { 1078.0f, -103.0f, 55.5f, 0.0f },
    { 1078.0f, -108.0f, 55.5f, 0.0f },
    { 1078.0f, -13.0f,  55.5f, 0.0f },
    { 1078.0f, -18.0f,  55.5f, 0.0f },
    { 1078.0f, -23.0f,  55.5f, 0.0f },
    { 1078.0f, -28.0f,  55.5f, 0.0f },
    { 1078.0f, -33.0f,  55.5f, 0.0f },
    { 1078.0f, -38.0f,  55.5f, 0.0f },
    { 1078.0f, -43.0f,  55.5f, 0.0f },
    { 1078.0f, -48.0f,  55.5f, 0.0f },
    { 1078.0f, -53.0f,  55.5f, 0.0f },
    { 1078.0f, -58.0f,  55.5f, 0.0f },
    { 1078.0f, -63.0f,  55.5f, 0.0f },
    { 1078.0f, -68.0f,  55.5f, 0.0f },
    { 1078.0f, -73.0f,  55.5f, 0.0f },
    { 1078.0f, -78.0f,  55.5f, 0.0f },
    { 1078.0f, -8.0f,   55.5f, 0.0f },
    { 1078.0f, -83.0f,  55.5f, 0.0f },
    { 1078.0f, -88.0f,  55.5f, 0.0f },
    { 1078.0f, -93.0f,  55.5f, 0.0f },
    { 1078.0f, -98.0f,  55.5f, 0.0f },
    { 1083.0f, -103.0f, 55.5f, 0.0f },
    { 1083.0f, -13.0f,  55.5f, 0.0f },
    { 1083.0f, -18.0f,  55.5f, 0.0f },
    { 1083.0f, -23.0f,  55.5f, 0.0f },
    { 1083.0f, -28.0f,  55.5f, 0.0f },
    { 1083.0f, -33.0f,  55.5f, 0.0f },
    { 1083.0f, -38.0f,  55.5f, 0.0f },
    { 1083.0f, -43.0f,  55.5f, 0.0f },
    { 1083.0f, -48.0f,  55.5f, 0.0f },
    { 1083.0f, -53.0f,  55.5f, 0.0f },
    { 1083.0f, -58.0f,  55.5f, 0.0f },
    { 1083.0f, -63.0f,  55.5f, 0.0f },
    { 1083.0f, -68.0f,  55.5f, 0.0f },
    { 1083.0f, -73.0f,  55.5f, 0.0f },
    { 1083.0f, -78.0f,  55.5f, 0.0f },
    { 1083.0f, -83.0f,  55.5f, 0.0f },
    { 1083.0f, -88.0f,  55.5f, 0.0f },
    { 1083.0f, -93.0f,  55.5f, 0.0f },
    { 1083.0f, -98.0f,  55.5f, 0.0f },
    { 1088.0f, -18.0f,  55.5f, 0.0f },
    { 1088.0f, -23.0f,  55.5f, 0.0f },
    { 1088.0f, -28.0f,  55.5f, 0.0f },
    { 1088.0f, -33.0f,  55.5f, 0.0f },
    { 1088.0f, -38.0f,  55.5f, 0.0f },
    { 1088.0f, -43.0f,  55.5f, 0.0f },
    { 1088.0f, -48.0f,  55.5f, 0.0f },
    { 1088.0f, -53.0f,  55.5f, 0.0f },
    { 1088.0f, -58.0f,  55.5f, 0.0f },
    { 1088.0f, -63.0f,  55.5f, 0.0f },
    { 1088.0f, -68.0f,  55.5f, 0.0f },
    { 1088.0f, -73.0f,  55.5f, 0.0f },
    { 1088.0f, -78.0f,  55.5f, 0.0f },
    { 1088.0f, -83.0f,  55.5f, 0.0f },
    { 1088.0f, -88.0f,  55.5f, 0.0f },
    { 1088.0f, -93.0f,  55.5f, 0.0f },
    { 1088.0f, -98.0f,  55.5f, 0.0f },
    { 1093.0f, -23.0f,  55.5f, 0.0f },
    { 1093.0f, -28.0f,  55.5f, 0.0f },
    { 1093.0f, -33.0f,  55.5f, 0.0f },
    { 1093.0f, -38.0f,  55.5f, 0.0f },
    { 1093.0f, -43.0f,  55.5f, 0.0f },
    { 1093.0f, -48.0f,  55.5f, 0.0f },
    { 1093.0f, -53.0f,  55.5f, 0.0f },
    { 1093.0f, -58.0f,  55.5f, 0.0f },
    { 1093.0f, -63.0f,  55.5f, 0.0f },
    { 1093.0f, -68.0f,  55.5f, 0.0f },
    { 1093.0f, -73.0f,  55.5f, 0.0f },
    { 1093.0f, -78.0f,  55.5f, 0.0f },
    { 1093.0f, -83.0f,  55.5f, 0.0f },
    { 1093.0f, -88.0f,  55.5f, 0.0f },
    { 1093.0f, -93.0f,  55.5f, 0.0f },
    { 1098.0f, -28.0f,  55.5f, 0.0f },
    { 1098.0f, -33.0f,  55.5f, 0.0f },
    { 1098.0f, -38.0f,  55.5f, 0.0f },
    { 1098.0f, -43.0f,  55.5f, 0.0f },
    { 1098.0f, -48.0f,  55.5f, 0.0f },
    { 1098.0f, -53.0f,  55.5f, 0.0f },
    { 1098.0f, -58.0f,  55.5f, 0.0f },
    { 1098.0f, -63.0f,  55.5f, 0.0f },
    { 1098.0f, -68.0f,  55.5f, 0.0f },
    { 1098.0f, -73.0f,  55.5f, 0.0f },
    { 1098.0f, -78.0f,  55.5f, 0.0f },
    { 1098.0f, -83.0f,  55.5f, 0.0f },
    { 1098.0f, -88.0f,  55.5f, 0.0f },
    { 1103.0f, -33.0f,  55.5f, 0.0f },
    { 1103.0f, -38.0f,  55.5f, 0.0f },
    { 1103.0f, -43.0f,  55.5f, 0.0f },
    { 1103.0f, -48.0f,  55.5f, 0.0f },
    { 1103.0f, -53.0f,  55.5f, 0.0f },
    { 1103.0f, -58.0f,  55.5f, 0.0f },
    { 1103.0f, -63.0f,  55.5f, 0.0f },
    { 1103.0f, -68.0f,  55.5f, 0.0f },
    { 1103.0f, -73.0f,  55.5f, 0.0f },
    { 1103.0f, -78.0f,  55.5f, 0.0f },
    { 1103.0f, -83.0f,  55.5f, 0.0f },
    { 1108.0f, -38.0f,  55.5f, 0.0f },
    { 1108.0f, -43.0f,  55.5f, 0.0f },
    { 1108.0f, -48.0f,  55.5f, 0.0f },
    { 1108.0f, -53.0f,  55.5f, 0.0f },
    { 1108.0f, -58.0f,  55.5f, 0.0f },
    { 1108.0f, -63.0f,  55.5f, 0.0f },
    { 1108.0f, -68.0f,  55.5f, 0.0f },
    { 1108.0f, -73.0f,  55.5f, 0.0f },
    { 1108.0f, -78.0f,  55.5f, 0.0f },
    { 1113.0f, -43.0f,  55.5f, 0.0f },
    { 1113.0f, -48.0f,  55.5f, 0.0f },
    { 1113.0f, -53.0f,  55.5f, 0.0f },
    { 1113.0f, -58.0f,  55.5f, 0.0f },
    { 1113.0f, -63.0f,  55.5f, 0.0f },
    { 1113.0f, -68.0f,  55.5f, 0.0f },
    { 1113.0f, -73.0f,  55.5f, 0.0f },
    { 983.0f,  -28.0f,  55.5f, 0.0f },
    { 983.0f,  -33.0f,  55.5f, 0.0f },
    { 983.0f,  -38.0f,  55.5f, 0.0f },
    { 983.0f,  -43.0f,  55.5f, 0.0f },
    { 983.0f,  -48.0f,  55.5f, 0.0f },
    { 983.0f,  -53.0f,  55.5f, 0.0f },
    { 983.0f,  -58.0f,  55.5f, 0.0f },
    { 983.0f,  -63.0f,  55.5f, 0.0f },
    { 983.0f,  -68.0f,  55.5f, 0.0f },
    { 983.0f,  -73.0f,  55.5f, 0.0f },
    { 983.0f,  -78.0f,  55.5f, 0.0f },
    { 983.0f,  -83.0f,  55.5f, 0.0f },
    { 983.0f,  -88.0f,  55.5f, 0.0f },
    { 988.0f,  -28.0f,  55.5f, 0.0f },
    { 988.0f,  -33.0f,  55.5f, 0.0f },
    { 988.0f,  -38.0f,  55.5f, 0.0f },
    { 988.0f,  -43.0f,  55.5f, 0.0f },
    { 988.0f,  -48.0f,  55.5f, 0.0f },
    { 988.0f,  -53.0f,  55.5f, 0.0f },
    { 988.0f,  -58.0f,  55.5f, 0.0f },
    { 988.0f,  -63.0f,  55.5f, 0.0f },
    { 988.0f,  -68.0f,  55.5f, 0.0f },
    { 988.0f,  -73.0f,  55.5f, 0.0f },
    { 988.0f,  -78.0f,  55.5f, 0.0f },
    { 988.0f,  -83.0f,  55.5f, 0.0f },
    { 988.0f,  -88.0f,  55.5f, 0.0f },
    { 993.0f,  -18.0f,  55.5f, 0.0f },
    { 993.0f,  -23.0f,  55.5f, 0.0f },
    { 993.0f,  -28.0f,  55.5f, 0.0f },
    { 993.0f,  -33.0f,  55.5f, 0.0f },
    { 993.0f,  -38.0f,  55.5f, 0.0f },
    { 993.0f,  -43.0f,  55.5f, 0.0f },
    { 993.0f,  -48.0f,  55.5f, 0.0f },
    { 993.0f,  -53.0f,  55.5f, 0.0f },
    { 993.0f,  -58.0f,  55.5f, 0.0f },
    { 993.0f,  -63.0f,  55.5f, 0.0f },
    { 993.0f,  -68.0f,  55.5f, 0.0f },
    { 993.0f,  -73.0f,  55.5f, 0.0f },
    { 993.0f,  -78.0f,  55.5f, 0.0f },
    { 993.0f,  -83.0f,  55.5f, 0.0f },
    { 993.0f,  -88.0f,  55.5f, 0.0f },
    { 993.0f,  -93.0f,  55.5f, 0.0f },
    { 993.0f,  -98.0f,  55.5f, 0.0f },
    { 998.0f,  -103.0f, 55.5f, 0.0f },
    { 998.0f,  -13.0f,  55.5f, 0.0f },
    { 998.0f,  -18.0f,  55.5f, 0.0f },
    { 998.0f,  -23.0f,  55.5f, 0.0f },
    { 998.0f,  -28.0f,  55.5f, 0.0f },
    { 998.0f,  -33.0f,  55.5f, 0.0f },
    { 998.0f,  -38.0f,  55.5f, 0.0f },
    { 998.0f,  -43.0f,  55.5f, 0.0f },
    { 998.0f,  -48.0f,  55.5f, 0.0f },
    { 998.0f,  -53.0f,  55.5f, 0.0f },
    { 998.0f,  -58.0f,  55.5f, 0.0f },
    { 998.0f,  -63.0f,  55.5f, 0.0f },
    { 998.0f,  -68.0f,  55.5f, 0.0f },
    { 998.0f,  -73.0f,  55.5f, 0.0f },
    { 998.0f,  -78.0f,  55.5f, 0.0f },
    { 998.0f,  -83.0f,  55.5f, 0.0f },
    { 998.0f,  -88.0f,  55.5f, 0.0f },
    { 998.0f,  -93.0f,  55.5f, 0.0f },
    { 998.0f,  -98.0f,  55.5f, 0.0f }
};

class HeartOfFlameCheck
{
    public:
        HeartOfFlameCheck() : _questId(0) { }
        HeartOfFlameCheck(uint32 questId) : _questId(questId) { }

        bool operator()(WorldObject* target) const
        {
            Player* player = target->ToPlayer();
            if (!player)
                return true;

            return !IsPlayerEligibleForHeartOfFlame(player);
        }

    private:
        uint32 _questId;

        uint32 GetQuestIdForPlayer(Player* player) const
        {
            if (_questId)
                return _questId;

            switch (player->GetTeam())
            {
                case HORDE:
                    return QUEST_HEART_OF_FLAME_H;
                case ALLIANCE:
                    return QUEST_HEART_OF_FLAME_A;
                default:
                    break;
            }

            return 0;
        }

        bool IsPlayerEligibleForHeartOfFlame(Player* player) const
        {
            uint32 questId = GetQuestIdForPlayer(player);
            Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
            if (!quest || player->GetQuestStatus(quest->ID) != QUEST_STATUS_INCOMPLETE)
                return false;

            for (QuestObjective const& obj : quest->GetObjectives())
            {
                switch (obj.ObjectID)
                {
                    case ITEM_HEART_OF_FLAME:
                        if (player->HasItemCount(ITEM_HEART_OF_FLAME, obj.Amount))
                            return false;
                        break;
                    case NPC_SMOULDERING_ESSENCE_CREDIT:
                    {
                        uint16 count = player->GetReqKillOrCastCurrentCount(quest->ID, NPC_SMOULDERING_ESSENCE_CREDIT);
                        if (count < obj.Amount)
                            return false;
                        break;
                    }
                    default:
                        break;
                }
            }

            return true;
        }
};

Position const LavaWielderDoorPos = { 791.5868f, -59.375f, 86.31097f, 5.742135f };
QuaternionData const LavaWielderDoorRot = { 0.0f, 0.0f, -0.2672377f, 0.9636307f };
Position const LavaWielderDoorInCombatPos = { 690.8195f, -60.05035f, 86.31098f, 2.687807f };
QuaternionData const LavaWielderDoorInCombatRot = { 0.0f, 0.0f, 0.97437f, 0.2249513f };

// http://www.wowhead.com/npc=53575/lava-wielder
struct npc_fl_ragnaros_lava_wielder : public ScriptedAI
{
    npc_fl_ragnaros_lava_wielder(Creature* creature) : ScriptedAI(creature) { }

    void InitializeAI() override
    {
        if (me->IsAlive())
            JustRespawned();
    }

    void JustRespawned() override
    {
        if (GameObject* door = me->SummonGameObject(GO_LAVA_WIELDER_DOOR, LavaWielderDoorPos, LavaWielderDoorRot, 0))
            _exitDoorGUID = door->GetGUID();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _scheduler.Schedule(Seconds(6), [this](TaskContext context)
        {
            DoCastAOE(SPELL_RAISE_LAVA);
            context.Repeat(Seconds(18));
        });
        _scheduler.Schedule(Seconds(6), [this](TaskContext)
        {
            if (GameObject* door = me->SummonGameObject(GO_LAVA_WIELDER_DOOR, LavaWielderDoorInCombatPos, LavaWielderDoorInCombatRot, 0))
                _entranceDoorGUID = door->GetGUID();
        });
    }

    void Reset() override
    {
        _scheduler.CancelAll();
        if (GameObject* door = ObjectAccessor::GetGameObject(*me, _entranceDoorGUID))
            door->RemoveFromWorld();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _scheduler.CancelAll();
        if (GameObject* door = ObjectAccessor::GetGameObject(*me, _entranceDoorGUID))
            door->RemoveFromWorld();
        if (GameObject* door = ObjectAccessor::GetGameObject(*me, _exitDoorGUID))
            door->RemoveFromWorld();
    }

    void UpdateAI(uint32 diff) override
    {
        ScriptedAI::UpdateAI(diff);
        _scheduler.Update(diff);
    }

private:
    ObjectGuid _entranceDoorGUID;
    ObjectGuid _exitDoorGUID;
    TaskScheduler _scheduler;
};

// http://www.wowhead.com/npc=53575/lava-wielder
struct npc_fl_ragnaros_lava_wielder_lava : public PassiveAI
{
    npc_fl_ragnaros_lava_wielder_lava(Creature* creature) : PassiveAI(creature) { }

    void EnterEvadeMode(EvadeReason /*reason*/) override { }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_RAISE_LAVA)
            return;

        Position homePos = me->GetHomePosition();
        Position movePos = homePos;
        movePos.RelocateOffset({ 0.0f, 0.0f, 2.0f, 0.0f });
        me->GetMotionMaster()->MovePoint(0, movePos);
        _scheduler.Schedule(Seconds(16), [this, homePos](TaskContext)
        {
            me->NearTeleportTo(homePos.GetPositionX(), homePos.GetPositionY(), homePos.GetPositionZ(), homePos.GetOrientation());
        });
    }

    void UpdateAI(uint32 diff) override
    {
        PassiveAI::UpdateAI(diff);
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

struct npc_fl_ragnaros_molten_wormAI : public ScriptedAI
{
    npc_fl_ragnaros_molten_wormAI(Creature* creature) : ScriptedAI(creature) { }

        void InitializeAI() override
        {
            if (me->IsAlive())
                JustRespawned();
        }

        void JustRespawned() override
        {
            SetCombatMovement(false);
            me->CastSpell(me, SPELL_MOLTEN_VISUAL, true);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            if (!enter_evade_mode(why))
                return;

            TC_LOG_DEBUG("entities.unit", "Creature %u enters evade mode.", me->GetEntry());

            if (!me->GetVehicle()) // otherwise me will be in evade mode forever
            {
                if (Unit* owner = me->GetCharmerOrOwner())
                {
                    me->GetMotionMaster()->Clear(false);
                    me->GetMotionMaster()->MoveFollow(owner, PET_FOLLOW_DIST, me->GetFollowAngle(), MOTION_SLOT_ACTIVE);
                }
                else
                {
                    // Required to prevent attacking creatures that are evading and cause them to reenter combat
                    // Does not apply to MoveFollow
                    Position home = me->GetHomePosition();
                    me->NearTeleportTo(home.GetPositionX(), home.GetPositionY(), home.GetPositionZ(), home.GetOrientation());
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            ScriptedAI::UpdateAI(diff);
            scheduler.Update(diff);

            _DoMeleeAttackIfReady();
        }

    private:
        bool enter_evade_mode(EvadeReason /*why*/) const
        {
            if (!me->IsAlive())
                return false;

            me->RemoveAppliedAuras([](AuraApplication const* auraApp)
            {
                switch (auraApp->GetBase()->GetId())
                {
                    case SPELL_MOLTEN_VISUAL:
                        return false;
                    default:
                        return true;
                }

                return true;
            });

            // sometimes bosses stuck in combat?
            me->DeleteThreatList();
            me->CombatStop(true);
            me->LoadCreaturesAddon();
            me->SetLootRecipient(nullptr);
            me->ResetPlayerDamageReq();
            me->SetLastDamagedTime(0);
            me->SetCannotReachTarget(false);

            return !me->IsInEvadeMode();
        }

        void _DoMeleeAttackIfReady()
        {
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            Unit* victim = me->GetVictim();
            if (!victim || !me->isAttackReady())
                return;

            if (!me->IsWithinMeleeRange(victim) || !me->IsWithinLOSInMap(victim))
                DoCastVictim(SPELL_MOLTEN_BLAST);
            else
                me->AttackerStateUpdate(victim);

            me->resetAttackTimer();
        }

    protected:
        TaskScheduler scheduler;
};

uint32 const LavaSpewerEmergePositionsCount = 3;
Position const LavaSpewerEmergePositions[LavaSpewerEmergePositionsCount] =
{
    { 945.757f, -40.2813f, 37.5921f, 0.66f },
    { 910.44f, -73.0209f, 37.6081f, 0.66f },
    { 909.955f, -44.4906f, 37.6075f, 0.66f }
};

// http://www.wowhead.com/npc=53545/molten-spewer
struct npc_fl_ragnaros_molten_spewer : public npc_fl_ragnaros_molten_wormAI
{
    npc_fl_ragnaros_molten_spewer(Creature* creature) : npc_fl_ragnaros_molten_wormAI(creature), _originalReactState(creature->GetReactState()) { }

    void Reset() override
    {
        _events.Reset();
        scheduler.CancelAll();
        me->SetReactState(_originalReactState);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        _events.Reset();
        scheduler.CancelAll();
        me->SetReactState(_originalReactState);
        npc_fl_ragnaros_molten_wormAI::EnterEvadeMode(why);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_MOLTEN_VOLLEY, Seconds(10));
        scheduler.Schedule(Seconds(15), [this](TaskContext context)
        {
            DoCastAOE(SPELL_LAVA_SPEWER_SUBMERGE);
            context.Repeat(Seconds(30));
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        _events.Reset();
        scheduler.CancelAll();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_LAVA_WORM_EMERGE:
            {
                Position pos = Trinity::Containers::SelectRandomContainerElement(LavaSpewerEmergePositions);
                me->NearTeleportTo(pos);
                me->PlayOneShotAnimKitId(ANIM_KIT_MOLTEN_SPEWER_EMERGE);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                scheduler.Schedule(Milliseconds(5500), [this](TaskContext)
                {
                    me->SetReactState(_originalReactState);
                });
                break;
            }
            default:
                break;
        }
    }

    void SpellHit(Unit* who, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_MOLTEN_ERUPTION_TRIGGER_BOLT ||
            me->HasAura(SPELL_LAVA_SPEWER_SUBMERGE) ||
            me->GetReactState() == REACT_PASSIVE)
            return;

        me->CastSpell(who, SPELL_MOLTEN_ERUPTION_BOLT, true);
    }

    void UpdateAI(uint32 diff) override
    {
        npc_fl_ragnaros_molten_wormAI::UpdateAI(diff);
        _events.Update(diff);

        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOLTEN_VOLLEY:
                    DoCastAOE(SPELL_MOLTEN_VOLLEY);
                    _events.ScheduleEvent(EVENT_MOLTEN_VOLLEY, Milliseconds(15500));
                    break;
                default:
                    break;
            }
        }
    }

private:
    ReactStates _originalReactState;
    EventMap _events;
};

// http://www.wowhead.com/npc=53617/molten-erupter
struct npc_fl_ragnaros_molten_erupter : public npc_fl_ragnaros_molten_wormAI
{
    npc_fl_ragnaros_molten_erupter(Creature* creature) : npc_fl_ragnaros_molten_wormAI(creature) { }

    void Reset() override
    {
        scheduler.CancelAll();
    }

    void JustDied(Unit* /*killer*/) override
    {
        scheduler.CancelAll();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        scheduler.CancelAll();
        npc_fl_ragnaros_molten_wormAI::EnterEvadeMode(why);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        scheduler.Schedule(Seconds(11), [this](TaskContext context)
        {
            DoCastAOE(SPELL_MOLTEN_ERUPTION, true);
            context.Repeat(Milliseconds(25500));
        });
    }
};

// http://www.wowhead.com/npc=53621/molten-eruption
struct npc_fl_ragnaros_molten_eruption : public PassiveAI
{
    npc_fl_ragnaros_molten_eruption(Creature* creature) : PassiveAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* moltenSpewer = me->FindNearestCreature(NPC_MOLTEN_ERUPTER, 100.0f))
            moltenSpewer->CastSpell(me, SPELL_MOLTEN_BOLT, true);
    }
};

// http://www.wowhead.com/npc=54127/dreadflame
struct npc_fl_ragnaros_dreadflame : public PassiveAI
{
    npc_fl_ragnaros_dreadflame(Creature* creature) : PassiveAI(creature) { }

    void EnterEvadeMode(EvadeReason /*reason*/) override { }

    void Reset() override
    {
        Dreadflames.clear();
        for (const auto& ConstDreadflame : ConstDreadflames)
        {
            DreadflameInfo* dreadflame = new DreadflameInfo();
            dreadflame->Position = ConstDreadflame;
            dreadflame->Owner = ObjectGuid::Empty;
            Dreadflames.push_back(dreadflame);
        }

        for (auto sourceDreadflame : Dreadflames)
            for (auto targetDreadflame : Dreadflames)
                if (sourceDreadflame != targetDreadflame && sourceDreadflame->Position.IsInDist2d(targetDreadflame->Position.GetPositionX(), targetDreadflame->Position.GetPositionY(), 5.1f))
                    sourceDreadflame->NearbyDreadflames.push_back(targetDreadflame);

        me->CastSpell(me, SPELL_DREADFLAME_SPREAD_CONTROL_AURA, true);
        me->CastSpell(me, SPELL_DREADFLAME_DELUGE_CONTROL_AURA, true);
        me->CastSpell(me, SPELL_DREADFLAME_SPAWN_CONTROL_AURA, true);
        me->CastSpell(me, SPELL_DREADFLAME_DAMAGE_CONTROL_AURA, true);
    }

    void JustRegisteredDynObject(DynamicObject* dynObj) override
    {
        RegisterDreadflame(dynObj);
    }

    void JustUnregisteredDynObject(DynamicObject* dynObj) override
    {
        UnregisterDreadflame(dynObj);
    }

    void RegisterDreadflame(DynamicObject* dynObj)
    {
        for (uint32 i = 0; i < DreadFlamesMax; i++)
        {
            DreadflameInfo* dfi = Dreadflames[i];
            if (std::sqrt(dynObj->GetExactDist2dSq(dfi->Position.GetPositionX(), dfi->Position.GetPositionY()) < 3.0f))
            {
                dfi->Owner = dynObj->GetGUID();
                dfi->CanSpreadTo = false;
                for (DreadflameInfo* neighbor : dfi->NearbyDreadflames)
                {
                    if (neighbor->CanSpreadTo || neighbor->IsLit())
                        continue;

                    neighbor->CanSpreadTo = true;
                }
            }
        }
    }

    void UnregisterDreadflame(DynamicObject* dynObj)
    {
        for (uint32 i = 0; i < DreadFlamesMax; i++)
        {
            DreadflameInfo* dfi = Dreadflames[i];
            if (dfi->Owner != dynObj->GetGUID())
                continue;

            dfi->Owner = ObjectGuid::Empty;
            dfi->CanSpreadTo = false;
            for (DreadflameInfo* neighbor : dfi->NearbyDreadflames)
            {
                if (!neighbor->IsLit())
                    continue;

                dfi->CanSpreadTo = true;
                break;
            }
            break;
        }
    }

    std::vector<Position> GetDreadflameSpreadPositions() const
    {
        std::list<DreadflameInfo*> spreadDreadflames;
        std::copy(Dreadflames.begin(), Dreadflames.end(), std::back_inserter(spreadDreadflames));
        spreadDreadflames.remove_if([](DreadflameInfo* dfi)
        {
            return !dfi->CanSpreadTo;
        });

        uint32 size = me->GetMap()->Is25ManRaid() ? 6 : 2;
        if (spreadDreadflames.size() > size)
            Trinity::Containers::RandomResize(spreadDreadflames, std::max<uint32>(size, ceil(spreadDreadflames.size() * 0.6))); // 0.75 TODO: Magic number

        std::vector<Position> spreadPositions;
        for (DreadflameInfo* dfi : spreadDreadflames)
        {
            spreadPositions.push_back(dfi->Position);
        }

        return spreadPositions;
    }

    std::list<Position> GetVacantDreadflamePositions()
    {
        std::list<Position> positions;
        for (auto dreadflame : Dreadflames)
            if (dreadflame->Owner.IsEmpty())
                positions.push_back(dreadflame->Position);

        return positions;
    }

    std::list<Position> GetRandomVacantDreadflamePositions(uint32 size)
    {
        std::list<Position> positions = GetVacantDreadflamePositions();
        Trinity::Containers::RandomResize(positions, size);

        return positions;
    }

    bool IsNearbyDreadflame(WorldObject* source, float distance) const
    {
        std::vector<DynamicObject*> dreadflames = me->GetDynObjects(SPELL_DREADFLAME_SPAWN);
        for (auto dreadflame : dreadflames)
            if (source->IsInDist2d(dreadflame, distance))
                return true;

        return false;
    }

    DynamicObject* GetNearestLitDreadflameDynamicObject(WorldObject* source, float distance) const
    {
        std::vector<DynamicObject*> dreadflamesVector = me->GetDynObjects(SPELL_DREADFLAME_SPAWN);
        if (dreadflamesVector.empty())
            return nullptr;

        std::list<DynamicObject*> dreadflames(dreadflamesVector.begin(), dreadflamesVector.end());
        dreadflames.remove_if([source, distance](DynamicObject* dynObject)
        {
            return source->GetDistance2d(dynObject) > distance;
        });
        if (dreadflames.empty())
            return nullptr;

        dreadflames.sort(Trinity::ObjectDistanceOrderPred(source));
        return dreadflames.front();
    }

private:
    std::vector<DreadflameInfo*> Dreadflames;
};

typedef npc_fl_ragnaros_dreadflame DreadflameAI;

// http://www.wowhead.com/npc=52409/ragnaros
struct boss_fl_ragnaros : public BossAI
{
    boss_fl_ragnaros(Creature* creature) : BossAI(creature, DATA_RAGNAROS),
        _canDie(false), _canYell(false), _inSulfurasSmash(false), _newPhase(PHASE_NONE), _previousPhase(PHASE_NONE),
        _previousEngulfingFlamePos(0), _meteorCastCount(0), _dreadflameCnt(0), _dreadflameCountdown(0)
    {
        me->setActive(true);
    }

    void DamageTaken(Unit* /*who*/, uint32& damage) override
    {
        if (damage >= me->GetHealth() && !_canDie)
            damage = me->GetHealth() - 1;

        if (me->HealthBelowPctDamaged(11, damage) && events.IsInPhase(PHASE_THREE))
        {
            _newPhase = PHASE_SUBMERGE;
        }
        else if (((me->HealthBelowPctDamaged(71, damage) && events.IsInPhase(PHASE_ONE))
            || (me->HealthBelowPctDamaged(41, damage) && events.IsInPhase(PHASE_TWO)))
            && _newPhase != PHASE_INTERMISSION)
        {
            _newPhase = PHASE_INTERMISSION;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RAGNAROS_HEROIC_SUBMERGE:
                Talk(SAY_RAGNAROS_HEROIC_SUBMERGE);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->CastSpell(me, SPELL_LEGS_SUBMERGE, true);
                me->RemoveAurasDueToSpell(SPELL_BASE_VISUAL);
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                events.ScheduleEvent(EVENT_HEROIC_CENARIUS_1, Milliseconds(3200));
                events.ScheduleEvent(EVENT_PREPARE_PHASE_FOUR, Milliseconds(5200));
                break;
            case ACTION_RAGNAROS_DREADFLAME:
                _dreadflameCountdown -= uint32(DREADFLAME_MIN_CD);
                if (_dreadflameCountdown != 0 && _dreadflameCnt > 0)
                    break;

                _dreadflameCountdown = std::max(uint8(DREADFLAME_MIN_CD), uint8(DREADFLAME_BASE_CD - (_dreadflameCnt * 5)));
                ++_dreadflameCnt;
                if (Creature* dreadflame = instance->GetCreature(DATA_DREADFLAME))
                {
                    DreadflameAI* ai = CAST_AI(DreadflameAI, dreadflame->GetAI());
                    if (ai)
                    {
                        std::list<Position> positions = ai->GetRandomVacantDreadflamePositions(me->GetMap()->Is25ManRaid() ? 6 : 2);
                        if (!positions.empty())
                        {
                            Talk(EMOTE_DREADFLAME);
                            for (const auto& position : positions)
                                me->CastSpell(position.GetPositionX(), position.GetPositionY(), position.GetPositionZ(), SPELL_SUMMON_DREADFLAME_SPAWN, true);
                        }
                    }
                }
                break;
            default:
                break;
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        _EnterCombat();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_RAGNAROS_AGGRO);

        events.CancelEvent(EVENT_INTRO);
        scheduler.Schedule(Milliseconds(1200), [this](TaskContext context)
        {
            _CheckForNewPhase(_newPhase);
            context.Repeat();
        });
        PreparePhase(PHASE_ONE);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (!_EnterEvadeModeRagnaros(why))
            return;

        scheduler.CancelAll();
        events.Reset();
        _CombatCleanup();
        PreparePhase(PHASE_NONE);
        instance->SetBossState(DATA_RAGNAROS, FAIL);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        if (GameObject* platform = instance->GetGameObject(DATA_RAGNAROS_PLATFORM))
            platform->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);

        _DespawnAtEvade(30);
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_NEW_ENGULFING_FLAME:
            {
                std::list<uint8> engulfingFlames;
                for (uint8 pos : EngulfingFlamePositions)
                    if (pos != _previousEngulfingFlamePos)
                        engulfingFlames.push_back(pos);

                return Trinity::Containers::SelectRandomContainerElement(engulfingFlames);
            }
            case DATA_IGNITED_METEORS:
            {
                uint32 count = 0;
                for (auto guid : summons)
                    if (Creature* summon = ObjectAccessor::GetCreature(*me, guid))
                        if (summon->GetEntry() == NPC_RAGNAROS_LIVING_METEOR && summon->HasAura(SPELL_LAVALOGGED))
                            count++;

                return count;
            }
            case DATA_METEOR_CAST_COUNT:
                return _meteorCastCount;
            default:
                break;
        }

        return 0;
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case GUID_SPLITTING_BLOW_WEST:
                return _splittingBlowWest;
            case GUID_SPLITTING_BLOW_MIDDLE:
                return _splittingBlowMiddle;
            case GUID_SPLITTING_BLOW_EAST:
                return _splittingBlowEast;
            case GUID_CLOUDBURST_TARGET:
                return Trinity::Containers::SelectRandomContainerElement(_cloudBurstTargets);
            case GUID_PLAYER_HELPER_TARGET:
                return _playerHelperTarget;
            default:
                break;
        }

        return ObjectGuid::Empty;
    }

    void Reset() override
    {
        instance->SetBossState(DATA_RAGNAROS, NOT_STARTED);
        _ResetVariables();
        SetCombatMovement(false);
        _PrepareEncounterArea();
        me->LoadEquipment();
        me->SetReactState(REACT_DEFENSIVE);
        _Emerge();
    }

    void JustReachedHome() override { }

    void JustRespawned() override
    {
        Reset();
        BossAI::JustRespawned();
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() != TYPEID_PLAYER || !_canYell)
            return;

        _canYell = false;
        Talk(SAY_RAGNAROS_KILL);
        scheduler.Schedule(Seconds(8), [this](TaskContext)
        {
            _canYell = true;
        });
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

        Talk(SAY_RAGNAROS_HEROIC_DEATH);
        if (Creature* malfurion = instance->GetCreature(DATA_MALFURION_STORMRAGE))
            if (malfurion->IsAIEnabled)
                malfurion->AI()->DoAction(ACTION_MALFURION_OUTRO_1);

        _CombatCleanup(false);
        DoCastAOE(SPELL_ACHIEVEMENT_CHECK, true);
        DoCastAOE(SPELL_HEART_OF_RAGNAROS_A, true);
        DoCastAOE(SPELL_HEART_OF_RAGNAROS_H, true);
        DoCastAOE(SPELL_AWARD_REPUTATION, true);
    }

    void JustSummoned(Creature* summon) override
    {
        if (me->IsInCombat() && summon->IsHostileToPlayers())
            DoZoneInCombat(summon, summon->GetVisibilityRange());

        switch (summon->GetEntry())
        {
            case NPC_SULFURAS:
                summon->CastSpell(summon, SPELL_SULFURAS, true);
                break;
            case NPC_SULFURAS_SMASH_TRIGGER:
                _inSulfurasSmash = true;
                me->CastStop();
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->SetFacingToObject(summon);
                me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetAngle(summon));
                DoCastAOE(SPELL_SULFURAS_SMASH);
                DoCastAOE(SPELL_SULFURAS_SMASH_SUMMON, true);
                Talk(EMOTE_SULFURAS_SMASH);
                scheduler.Schedule(Milliseconds(5600), [this](TaskContext)
                {
                    _ResumeAttack();
                });
                break;
            case NPC_LAVA_SCION:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, summon);
                break;
            case NPC_CENARIUS:
            case NPC_HAMUUL_RUNETOTEM:
            case NPC_MALFURION_STORMRAGE:
                summon->setActive(true);
                instance->instance->LoadGrid(summon->GetPositionX(), summon->GetPositionY());
            case NPC_HEART_OF_RAGNAROS:
                return;
            default:
                break;
        }

        summons.Summon(summon);
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        summons.Despawn(summon);

        switch (summon->GetEntry())
        {
            case NPC_SON_OF_FLAME:
                if (events.IsInPhase(PHASE_INTERMISSION) && !summons.HasEntry(NPC_SON_OF_FLAME))
                {
                    events.CancelEvent(EVENT_SPLITTING_BLOW_EMERGE);
                    events.CancelEvent(EVENT_SPLITTING_BLOW_EMERGE_WARNING);
                    events.ScheduleEvent(EVENT_SPLITTING_BLOW_EMERGE, Milliseconds(500), EVENT_GROUP_NONE, PHASE_INTERMISSION);
                }
                break;
            case NPC_LAVA_SCION:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
                break;
            default:
                break;
        }


        summon->DespawnOrUnsummon(Seconds(3));
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_LAVA_SCION:
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, summon);
                break;
            default:
                break;
        }

        BossAI::SummonedCreatureDespawn(summon);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_SUBMERGE_PERIODIC_AURA)
            return;

        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_RAGE_OF_RAGNAROS_AURA:
                Talk(SAY_RAGNAROS_RAGE_OF_RAGNAROS, target);
                break;
            case SPELL_MAGMA_TRAP:
                Talk(EMOTE_MAGMA_TRAP);
                break;
            default:
                break;
        }
    }

    void SetData(uint32 id, uint32 entry) override
    {
        switch (id)
        {
            case DATA_PREVIOUS_ENGULFING_FLAME:
                _previousEngulfingFlamePos = entry;
                break;
            case DATA_METEOR_CAST_COUNT:
                _meteorCastCount = entry;
                break;
            default:
                break;
        }

    }

    void PreparePhase(Phases phase, Phases previousPhase = PHASE_NONE)
    {
        events.SetPhase(phase);

        if (previousPhase != PHASE_NONE)
            _previousPhase = previousPhase;

        switch (phase)
        {
            case PHASE_ONE:
                me->CastSpell(me, SPELL_BURNING_WOUNDS);
                if (!me->GetMap()->IsHeroic())
                    scheduler.Schedule(Seconds(5), [this](TaskContext)
                {
                    DoCastAOE(SPELL_RAGE_OF_RAGNAROS, true);
                });

                events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, Seconds(6), EVENT_GROUP_NONE, PHASE_ONE);
                events.ScheduleEvent(EVENT_MAGMA_TRAP, Seconds(16), EVENT_GROUP_NONE, PHASE_ONE);
                events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, Seconds(26), EVENT_GROUP_NONE, PHASE_ONE);
                events.ScheduleEvent(EVENT_SULFURAS_SMASH, Seconds(31), EVENT_GROUP_NONE, PHASE_ONE);
                events.ScheduleEvent(EVENT_BERSERK, Minutes(18));
                break;
            case PHASE_INTERMISSION:
            {
                uint32 splittingBlow = RAND(SPELL_SPLITTING_BLOW_WEST, SPELL_SPLITTING_BLOW_MIDDLE, SPELL_SPLITTING_BLOW_EAST);
                Creature* target = nullptr;
                switch (splittingBlow)
                {
                    case SPELL_SPLITTING_BLOW_WEST:
                        _SummonSonsOfFlame(DATA_SPLITTING_BLOW_WEST);
                        target = ObjectAccessor::GetCreature(*me, _splittingBlowWest);
                        break;
                    case SPELL_SPLITTING_BLOW_MIDDLE:
                        _SummonSonsOfFlame(DATA_SPLITTING_BLOW_MIDDLE);
                        target = ObjectAccessor::GetCreature(*me, _splittingBlowMiddle);
                        break;
                    case SPELL_SPLITTING_BLOW_EAST:
                        _SummonSonsOfFlame(DATA_SPLITTING_BLOW_EAST);
                        target = ObjectAccessor::GetCreature(*me, _splittingBlowEast);
                        break;
                    default:
                        break;
                }

                if (!target)
                    break;

                _newPhase = PHASE_NONE;
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                me->SetFacingToObject(target);
                me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetAngle(target));
                me->CastSpell(me, SPELL_SUBMERGE, true);
                me->CastSpell(target, splittingBlow);
                Talk(SAY_RAGNAROS_SPLITTING_BLOW);
                Talk(EMOTE_SPLITTING_BLOW);
                events.ScheduleEvent(EVENT_SPLITTING_BLOW_SUBMERGE, Milliseconds(9500), EVENT_GROUP_NONE, PHASE_INTERMISSION);
                break;
            }
            case PHASE_TWO:
                events.CancelEvent(EVENT_SPLITTING_BLOW_EMERGE);
                events.CancelEvent(EVENT_SPLITTING_BLOW_EMERGE_WARNING);

                Talk(SAY_RAGNAROS_SPLITTING_BLOW_EMERGE);
                me->CastSpell(me, SPELL_BASE_VISUAL, true);
                me->PlayOneShotAnimKitId(ANIM_KIT_RESURFACE);
                me->RemoveAurasDueToSpell(SPELL_SUBMERGE_PERIODIC_AURA);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                scheduler.Schedule(Seconds(4), [this](TaskContext)
                {
                    _ResumeAttack();
                });
                events.ScheduleEvent(EVENT_SULFURAS_SMASH, Seconds(me->GetMap()->IsHeroic() ? 6 : 16), EVENT_GROUP_NONE, PHASE_TWO);
                events.ScheduleEvent(EVENT_MOLTEN_SEEDS, Seconds(me->GetMap()->IsHeroic() ? 16 : 22), EVENT_GROUP_NONE, PHASE_TWO);
                events.ScheduleEvent(EVENT_ENGULFING_FLAMES, Seconds(40), EVENT_GROUP_NONE, PHASE_TWO);
                break;
            case PHASE_THREE:
                events.CancelEvent(EVENT_SPLITTING_BLOW_EMERGE);
                events.CancelEvent(EVENT_SPLITTING_BLOW_EMERGE_WARNING);

                Talk(SAY_RAGNAROS_SPLITTING_BLOW_EMERGE);
                me->CastSpell(me, SPELL_BASE_VISUAL, true);
                me->PlayOneShotAnimKitId(ANIM_KIT_RESURFACE);
                me->RemoveAurasDueToSpell(SPELL_SUBMERGE_PERIODIC_AURA);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                scheduler.Schedule(Seconds(4), [this](TaskContext)
                {
                    _ResumeAttack();
                });
                events.ScheduleEvent(EVENT_SULFURAS_SMASH, Seconds(15), EVENT_GROUP_NONE, PHASE_THREE);
                events.ScheduleEvent(EVENT_ENGULFING_FLAMES, Seconds(31), EVENT_GROUP_NONE, PHASE_THREE);
                events.ScheduleEvent(EVENT_LIVING_METEOR, Seconds(45), EVENT_GROUP_NONE, PHASE_THREE);
                break;
            case PHASE_SUBMERGE:
                _newPhase = PHASE_NONE;
                if (me->GetMap()->IsHeroic())
                    me->SummonCreatureGroup(CREATURE_GROUP_PLAYER_HELPERS);
                else
                {
                    Talk(SAY_RAGNAROS_NORMAL_SUBMERGE);
                    me->RemoveAllAurasOnDeath();
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    me->DeleteThreatList();
                    me->CombatStop();
                    me->SetFacingTo(me->GetHomePosition().GetOrientation());
                    me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetHomePosition().GetOrientation());
                    instance->DoUpdateCriteria(CRITERIA_TYPE_BE_SPELL_TARGET, SPELL_RAGNAROS_KILL_CREDIT, 0, me);
                    DoCastAOE(SPELL_AWARD_REPUTATION, true);
                    me->CastSpell(me, SPELL_DEATH, true);
                    DoCastAOE(SPELL_SUMMON_CHEST, true);
                    DoCastAOE(SPELL_ACHIEVEMENT_CHECK, true);
                    DoCastAOE(SPELL_HEART_OF_RAGNAROS_H, true);
                    DoCastAOE(SPELL_HEART_OF_RAGNAROS_A, true);
                    _CombatCleanup();
                    _JustDied();
                    me->DespawnOrUnsummon(Milliseconds(3600));
                }
                break;
            case PHASE_FOUR:
            {
                _canDie = true;
                me->SetReactState(REACT_AGGRESSIVE);

                DoCastAOE(SPELL_DREADFLAME_SPAWN_AURA, true);
                DoCastAOE(SPELL_BREADTH_OF_FROST_TRIGGER, true);

                std::chrono::seconds empowerSulfurasTimer = Seconds(urand(49, 63));
                events.ScheduleEvent(EVENT_EMPOWER_SULFURAS, empowerSulfurasTimer, EVENT_GROUP_NONE, PHASE_FOUR);
                events.ScheduleEvent(EVENT_ENTRAPPING_ROOTS, empowerSulfurasTimer - Seconds(14), EVENT_GROUP_NONE, PHASE_FOUR);
                events.ScheduleEvent(EVENT_BREADTH_OF_FROST, Seconds(45), EVENT_GROUP_NONE, PHASE_FOUR);
                break;
            }
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();

        events.Update(diff);
        scheduler.Update(diff);

        if (!_CanExecuteEvent())
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_INTRO:
                    me->PlayOneShotAnimKitId(ANIM_KIT_TAUNT);
                    Talk(SAY_RAGNAROS_INTRO);
                    break;
                case EVENT_WRATH_OF_RAGNAROS:
                    if (urand(1, 3) == 1)
                        Talk(SAY_RAGNAROS_WRATH_OF_RAGNAROS);
                    DoCastAOE(SPELL_WRATH_OF_RAGNAROS);
                    break;
                case EVENT_MAGMA_TRAP:
                    DoCastAOE(SPELL_MAGMA_TRAP);
                    events.ScheduleEvent(EVENT_MAGMA_TRAP, Seconds(25), EVENT_GROUP_NONE, PHASE_ONE);
                    break;
                case EVENT_HAND_OF_RAGNAROS:
                    DoCastAOE(SPELL_HAND_OF_RAGNAROS);
                    events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, Seconds(25), EVENT_GROUP_NONE, PHASE_ONE);
                    break;
                case EVENT_SULFURAS_SMASH:
                    DoCastAOE(SPELL_SULFURAS_SMASH_PLAYER_TRIGGER);
                    events.ScheduleEvent(EVENT_WRATH_OF_RAGNAROS, Seconds(12), EVENT_GROUP_NONE, PHASE_ONE);
                    events.ScheduleEvent(EVENT_SULFURAS_SMASH, Seconds(30), EVENT_GROUP_NONE, events.IsInPhase(PHASE_THREE) ? PHASE_THREE : events.IsInPhase(PHASE_TWO) ? PHASE_TWO : PHASE_ONE);
                    break;
                case EVENT_SPLITTING_BLOW_SUBMERGE:
                    Talk(SAY_RAGNAROS_SPLITTING_BLOW_SUBMERGE);
                    events.ScheduleEvent(EVENT_SPLITTING_BLOW_EMERGE_WARNING, Seconds(40), EVENT_GROUP_NONE, PHASE_INTERMISSION);
                    me->RemoveAurasDueToSpell(SPELL_BASE_VISUAL);
                    if (_previousPhase == PHASE_TWO)
                        me->SummonCreatureGroup(CREATURE_GROUP_LAVA_SCIONS);
                    break;
                case EVENT_SPLITTING_BLOW_EMERGE_WARNING:
                    Talk(EMOTE_SPLITTING_BLOW_EMERGE);
                    events.ScheduleEvent(EVENT_SPLITTING_BLOW_EMERGE, Milliseconds(4500), EVENT_GROUP_NONE, PHASE_INTERMISSION);
                    break;
                case EVENT_SPLITTING_BLOW_EMERGE:
                    if (events.IsInPhase(PHASE_INTERMISSION))
                        PreparePhase(_previousPhase == PHASE_ONE ? PHASE_TWO : PHASE_THREE);
                    break;
                case EVENT_MOLTEN_SEEDS:
                    DoCastAOE(SPELL_MOLTEN_SEED_TARGET_SEARCH);
                    events.ScheduleEvent(EVENT_MOLTEN_SEEDS, Minutes(1), EVENT_GROUP_NONE, PHASE_TWO);
                    break;
                case EVENT_ENGULFING_FLAMES:
                    if (me->GetMap()->IsHeroic())
                    {
                        Talk(EMOTE_WORLD_IN_FLAMES);
                        me->AddAura(SPELL_WORLD_IN_FLAMES, me); // Hack, it is actually a channeled spell that triggers other spells with cast time, that TrinityCore does not currently support.
                    }
                    else
                    {
                        Talk(EMOTE_ENGULFING_FLAMES);
                        DoCastAOE(SPELL_ENGULFING_FLAMES);
                    }
                    if (events.IsInPhase(PHASE_TWO))
                        events.ScheduleEvent(EVENT_ENGULFING_FLAMES, me->GetMap()->IsHeroic() ? Minutes(1) : Seconds(40), EVENT_GROUP_NONE, PHASE_TWO);
                    else if (events.IsInPhase(PHASE_THREE))
                        events.ScheduleEvent(EVENT_ENGULFING_FLAMES, Seconds(30), EVENT_GROUP_NONE, PHASE_THREE);
                    break;
                case EVENT_LIVING_METEOR:
                    DoCastAOE(SPELL_LIVING_METEOR);
                    events.ScheduleEvent(EVENT_LIVING_METEOR, Seconds(45), EVENT_GROUP_NONE, PHASE_THREE);
                    break;
                case EVENT_PREPARE_PHASE_FOUR:
                    me->CastSpell(me, SPELL_LEGS_HEAL, true);
                    me->CastSpell(me, SPELL_HEROIC_TRANSFORM, true);
                    me->NearTeleportTo(RagnarosHeroicPosition.GetPositionX(), RagnarosHeroicPosition.GetPositionY(), RagnarosHeroicPosition.GetPositionZ(), me->GetOrientation());
                    events.ScheduleEvent(EVENT_PHASE_FOUR_EVENT_1, Milliseconds(8500), EVENT_GROUP_NONE, PHASE_SUBMERGE);
                    break;
                case EVENT_PHASE_FOUR_EVENT_1:
                    if (GameObject* platform = instance->GetGameObject(DATA_RAGNAROS_PLATFORM))
                        platform->SetDestructibleState(GO_DESTRUCTIBLE_DAMAGED);
                    if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                    {
                        me->SetFacingToObject(target);
                        me->UpdatePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetAngle(target));
                    }
                    if (Creature* magma = me->FindNearestCreature(NPC_RAGNAROS_MAGMA, 25.0f))
                        magma->CastSpell(magma, SPELL_MAGMA_KNOCKUP, true);
                    SetCombatMovement(true);
                    me->PlayOneShotAnimKitId(ANIM_KIT_EMERGE_HC);
                    me->RemoveAurasDueToSpell(SPELL_LEGS_SUBMERGE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    events.ScheduleEvent(EVENT_PHASE_FOUR_EVENT_2, Milliseconds(3600));
                    break;
                case EVENT_PHASE_FOUR_EVENT_2:
                    Talk(SAY_RAGNAROS_HEROIC_INTRO_1);
                    me->PlayOneShotAnimKitId(ANIM_KIT_TAUNT);
                    me->RemoveAurasDueToSpell(SPELL_CENARIUS_DRAW_OUT_FIRELORD);
                    me->RemoveAurasDueToSpell(SPELL_HAMUUL_DRAW_OUT_FIRELORD);
                    me->RemoveAurasDueToSpell(SPELL_MALFURION_DRAW_OUT_FIRELORD);
                    if (Creature* malfurion = instance->GetCreature(DATA_MALFURION_STORMRAGE))
                        if (malfurion->IsAIEnabled)
                            malfurion->AI()->DoAction(ACTION_MALFURION_HEROIC_INTRO);

                    events.ScheduleEvent(EVENT_PHASE_FOUR_EVENT_3, Milliseconds(9700), EVENT_GROUP_NONE, PHASE_SUBMERGE);
                    break;
                case EVENT_PHASE_FOUR_EVENT_3:
                    Talk(SAY_RAGNAROS_HEROIC_INTRO_2);
                    me->PlayOneShotAnimKitId(ANIM_KIT_STAND_UP);
                    me->SetDisableGravity(false);
                    me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                    me->CastSpell(me, SPELL_DREADFLAME, true);
                    if (GameObject* platform = instance->GetGameObject(DATA_RAGNAROS_PLATFORM))
                        platform->SetDestructibleState(GO_DESTRUCTIBLE_DESTROYED);

                    scheduler.Schedule(Milliseconds(1200), [this](TaskContext)
                    {
                        DoCast(SPELL_SUPERHEATED);
                    });

                    events.ScheduleEvent(EVENT_SCHEDULE_PHASE_FOUR, Seconds(6), EVENT_GROUP_NONE, PHASE_SUBMERGE);
                    break;
                case EVENT_SCHEDULE_PHASE_FOUR:
                    PreparePhase(PHASE_FOUR);
                    break;
                case EVENT_BREADTH_OF_FROST:
                    DoCastAOE(SPELL_BREADTH_OF_FROST_TRIGGER, true);
                    events.ScheduleEvent(EVENT_BREADTH_OF_FROST, Seconds(46), EVENT_GROUP_NONE, PHASE_FOUR);
                    break;
                case EVENT_ENTRAPPING_ROOTS:
                    DoCastAOE(SPELL_ENTRAPPING_ROOTS_TRIGGER, true);
                    events.ScheduleEvent(EVENT_ENTRAPPING_ROOTS, Seconds(56), EVENT_GROUP_NONE, PHASE_FOUR);
                    break;
                case EVENT_EMPOWER_SULFURAS:
                    me->StopMoving();
                    SetCombatMovement(false);
                    Talk(EMOTE_EMPOWER_SULFURAS);
                    DoCastAOE(SPELL_EMPOWER_SULFURAS);
                    events.ScheduleEvent(EVENT_EMPOWER_SULFURAS, Seconds(56), EVENT_GROUP_NONE, PHASE_FOUR);
                    break;
                default:
                    break;
            }
        }

        _DoMeleeAttackIfReady();
    }

private:
    bool _canDie;
    bool _canYell;
    bool _inSulfurasSmash;
    Phases _newPhase;
    Phases _previousPhase;
    uint32 _previousEngulfingFlamePos;
    uint32 _meteorCastCount;
    uint32 _dreadflameCnt;
    uint32 _dreadflameCountdown;
    ObjectGuid _splittingBlowWest, _splittingBlowMiddle, _splittingBlowEast;
    ObjectGuid _playerHelperTarget;
    GuidVector _cloudBurstTargets;

    bool _CanExecuteEvent() const
    {
        return !(me->HasUnitState(UNIT_STATE_STUNNED) || me->HasUnitState(UNIT_STATE_CASTING) || me->HasAura(SPELL_WORLD_IN_FLAMES) || _inSulfurasSmash);
    }

    void _CheckForNewPhase(Phases newPhase)
    {
        if (!me->IsInCombat() || me->HasUnitState(UNIT_STATE_CASTING) || me->HasReactState(REACT_PASSIVE) || me->HasAura(SPELL_WORLD_IN_FLAMES) || _inSulfurasSmash)
            return;

        switch (newPhase)
        {
            case PHASE_INTERMISSION:
                if (events.IsInPhase(PHASE_ONE))
                    PreparePhase(PHASE_INTERMISSION, PHASE_ONE);
                else if (events.IsInPhase(PHASE_TWO))
                    PreparePhase(PHASE_INTERMISSION, PHASE_TWO);
                break;
            case PHASE_SUBMERGE:
                PreparePhase(PHASE_SUBMERGE);
                break;
            default:
                break;
        }
    }

    void _CombatCleanup(bool wipe = true)
    {
        if (me->GetMap()->IsHeroic() && wipe)
        {
            if (Creature* cenarius = instance->GetCreature(DATA_CENARIUS))
                if (cenarius->IsAIEnabled)
                    cenarius->AI()->EnterEvadeMode();
            if (Creature* malfurion = instance->GetCreature(DATA_MALFURION_STORMRAGE))
                if (malfurion->IsAIEnabled)
                    malfurion->AI()->EnterEvadeMode();
            if (Creature* hamuul = instance->GetCreature(DATA_HAMUUL_RUNETOTEM))
                if (hamuul->IsAIEnabled)
                    hamuul->AI()->EnterEvadeMode();
        }

        summons.DespawnAll();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_LAVA_SCION_BLAZING_HEAT); // Blizzard does not remove this aura

        if (me->GetMap()->IsHeroic())
            DoCastAOE(SPELL_DELUGE_AURA_CANCEL, true);
    }

    void _DoMeleeAttackIfReady()
    {
        Unit* victim = me->GetVictim();
        if (!victim || !me->isAttackReady())
            return;

        if (!me->IsWithinMeleeRange(victim))
        {
            if (events.IsInPhase(PHASE_FOUR))
                return;

            DoCastVictim(SPELL_MAGMA_BLAST);
        }
        else
            me->AttackerStateUpdate(victim);

        me->resetAttackTimer();
    }

    void _Emerge()
    {
        me->PlayOneShotAnimKitId(ANIM_KIT_EMERGE);
        scheduler.Schedule(Milliseconds(1200), [this](TaskContext)
        {
            me->CastSpell(me, SPELL_BASE_VISUAL, true);
        });
        if (instance->GetData(DATA_RAGNAROS_FIRST_EMERGE) == 1)
        {
            instance->SetData(DATA_RAGNAROS_FIRST_EMERGE, 0);
            events.ScheduleEvent(EVENT_INTRO, Seconds(6));
        }
    }



    bool _EnterEvadeModeRagnaros(EvadeReason why)
    {
        if (!me->IsAlive())
            return false;

        if (why == EVADE_REASON_NO_HOSTILES
            && events.IsInPhase(PHASE_SUBMERGE)
            && !me->GetMap()->IsHeroic())
            return false;

        me->RemoveAppliedAuras([](AuraApplication const* auraApp)
        {
            if (Aura* aura = auraApp->GetBase())
            {
                if (SpellInfo const* auraInfo = aura->GetSpellInfo())
                {
                    switch (auraInfo->Id)
                    {
                        case SPELL_BASE_VISUAL:
                        case SPELL_BURNING_WOUNDS:
                            return false;
                        default:
                            return true;
                    }
                }
            }

            return true;
        });

        // sometimes bosses stuck in combat?
        me->DeleteThreatList();
        me->CombatStop(true);
        me->LoadCreaturesAddon();
        me->SetLootRecipient(nullptr);
        me->ResetPlayerDamageReq();
        me->SetLastDamagedTime(0);

        return !me->IsInEvadeMode();
    }

    void _PrepareEncounterArea()
    {
        me->SummonCreatureGroup(CREATURE_GROUP_MAGMA);

        std::list<TempSummon*> summonGroup;
        me->SummonCreatureGroup(CREATURE_GROUP_SPLITTING_BLOW_WEST, &summonGroup);
        if (TempSummon* temp = summonGroup.front())
            _splittingBlowWest = temp->GetGUID();

        summonGroup.clear();
        me->SummonCreatureGroup(CREATURE_GROUP_SPLITTING_BLOW_MIDDLE, &summonGroup);
        if (TempSummon* temp = summonGroup.front())
            _splittingBlowMiddle = temp->GetGUID();

        summonGroup.clear();
        me->SummonCreatureGroup(CREATURE_GROUP_SPLITTING_BLOW_EAST, &summonGroup);
        if (TempSummon* temp = summonGroup.front())
            _splittingBlowEast = temp->GetGUID();

        summonGroup.clear();
        me->SummonCreatureGroup(CREATURE_GROUP_ENGULFING_FLAMES_NEAR, &summonGroup);
        for (auto flame : summonGroup)
            if (flame->IsAIEnabled)
                flame->AI()->SetData(DATA_ENGULFING_FLAMES_ID, DATA_ENGULFING_FLAMES_NEAR);

        summonGroup.clear();
        me->SummonCreatureGroup(CREATURE_GROUP_ENGULFING_FLAMES_MIDDLE, &summonGroup);
        for (auto flame : summonGroup)
            if (flame->IsAIEnabled)
                flame->AI()->SetData(DATA_ENGULFING_FLAMES_ID, DATA_ENGULFING_FLAMES_MIDDLE);

        summonGroup.clear();
        me->SummonCreatureGroup(CREATURE_GROUP_ENGULFING_FLAMES_FAR, &summonGroup);
        for (auto flame : summonGroup)
            if (flame->IsAIEnabled)
                flame->AI()->SetData(DATA_ENGULFING_FLAMES_ID, DATA_ENGULFING_FLAMES_FAR);

        summonGroup.clear();
        _playerHelperTarget.Clear();
        me->SummonCreatureGroup(CREATURE_GROUP_HELPER_TARGET, &summonGroup);
        if (TempSummon* temp = summonGroup.front())
            _playerHelperTarget = temp->GetGUID();

        summonGroup.clear();
        _cloudBurstTargets.clear();
        me->SummonCreatureGroup(CREATURE_GROUP_CLOUDBURST_TARGETS, &summonGroup);
        for (auto helper : summonGroup)
            _cloudBurstTargets.push_back(helper->GetGUID());
    }

    void _ResetVariables()
    {
        _meteorCastCount = 0;
        _inSulfurasSmash = false;
        _canDie = false;
        _newPhase = PHASE_NONE;
        _canYell = true;
        _dreadflameCnt = 0;
        _dreadflameCountdown = DREADFLAME_BASE_CD;
        _previousEngulfingFlamePos = 0;
        _splittingBlowWest.Clear();
        _splittingBlowMiddle.Clear();
        _splittingBlowEast.Clear();
        _playerHelperTarget.Clear();
        _cloudBurstTargets.clear();
    }

    void _ResumeAttack()
    {
        _inSulfurasSmash = false;
        me->resetAttackTimer();
        me->SetReactState(REACT_AGGRESSIVE);
        summons.DespawnEntry(NPC_SULFURAS);
        if (me->HealthBelowPct(11) && events.IsInPhase(PHASE_THREE))
            _newPhase = PHASE_SUBMERGE;
        else if (me->HealthBelowPct(41) && events.IsInPhase(PHASE_TWO))
            _newPhase = PHASE_INTERMISSION;
    }

    void _SummonSonsOfFlame(uint32 excludeSideId) const
    {
        std::list<Position> spawnPoints;
        if (me->GetMap()->IsHeroic())
            spawnPoints = HeroicSonsOfFlame->GetPositionsExceptWithId(HeroicSonsOfFlame, HeroicSonsOfFlameSize, excludeSideId);
        else
            spawnPoints = NormalSonsOfFlame->GetPositionsExceptWithId(NormalSonsOfFlame, NormalSonsOfFlameSize, excludeSideId);

        if (spawnPoints.empty())
            return;

        Trinity::Containers::RandomResize(spawnPoints, SONS_OF_FLAME_COUNT);
        for (const auto& pos : spawnPoints)
            me->SummonCreature(NPC_SON_OF_FLAME, pos);
    }
};

// http://www.wowhead.com/npc=53086/magma-trap
struct npc_fl_ragnaros_magma_trap : public PassiveAI
{
    npc_fl_ragnaros_magma_trap(Creature* creature) : PassiveAI(creature) { }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_MAGMA_TRAP_TARGET_SEARCH)
            return;

        DoCastAOE(SPELL_MAGMA_TRAP_ERUPTION, true);
        me->RemoveAurasDueToSpell(SPELL_MAGMA_TRAP_VISUAL);
        me->RemoveAurasDueToSpell(SPELL_MAGMA_TRAP_PLAYER_TRIGGER);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        me->CastSpell(me, SPELL_MAGMA_TRAP_VISUAL, true);
        scheduler.Schedule(Milliseconds(1200), [this](TaskContext)
        {
            me->CastSpell(me, SPELL_MAGMA_TRAP_PLAYER_TRIGGER, true);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

// http://www.wowhead.com/npc=53268/sulfuras-smash
struct npc_fl_ragnaros_sulfuras_smash : public NullCreatureAI
{
    npc_fl_ragnaros_sulfuras_smash(Creature* creature) : NullCreatureAI(creature) { }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_SULFURAS_SMASH_DAMAGE)
            return;

        me->RemoveAurasDueToSpell(SPELL_SULFURAS_SMASH_LAVA_POOL);
        me->CastSpell(me, SPELL_SCORCHED_GROUND, true);

        _scheduler.Schedule(Milliseconds(7500), [this](TaskContext)
        {
            me->Kill(me);
        });
    }

    void JustSummoned(Creature* summon) override
    {
        if (Creature* ragnaros = me->GetInstanceScript()->GetCreature(DATA_RAGNAROS))
            if (ragnaros->IsAIEnabled)
                ragnaros->AI()->JustSummoned(summon);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _scheduler.Schedule(Milliseconds(400), [this](TaskContext)
        {
            me->CastSpell(me, SPELL_SULFURAS_SMASH_LAVA_WAVE_N, true);
            me->CastSpell(me, SPELL_SULFURAS_SMASH_LAVA_WAVE_W, true);
            me->CastSpell(me, SPELL_SULFURAS_SMASH_LAVA_WAVE_E, true);
            me->CastSpell(me, SPELL_SULFURAS_SMASH_LAVA_POOL, true);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        NullCreatureAI::UpdateAI(diff);
    }

private:
    TaskScheduler _scheduler;
};

// http://www.wowhead.com/npc=53363/lava-wave
struct npc_fl_ragnaros_lava_wave : public NullCreatureAI
{
    npc_fl_ragnaros_lava_wave(Creature* creature) : NullCreatureAI(creature) { }

    void IsSummonedBy(Unit* summoner) override
    {
        float x, y;
        me->GetNearPoint2D(x, y, 80.0f, summoner->GetAngle(me));
        movePos = { x, y, me->GetPositionZ() };
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_SULFURAS_SMASH_DAMAGE)
            return;

        me->CastSpell(me, SPELL_SULFURAS_SMASH_LAVA_WAVE, true);
        _scheduler.Schedule(Milliseconds(200), [this](TaskContext)
        {
            me->GetMotionMaster()->MovePoint(0, movePos);
        });
    }

    void MovementInform(uint32 type, uint32 /*id*/) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
        NullCreatureAI::UpdateAI(diff);
    }

private:
    TaskScheduler _scheduler;
    Position movePos;
};

// http://www.wowhead.com/npc=53140/son-of-flame
struct npc_fl_ragnaros_son_of_flame : public PassiveAI
{
    npc_fl_ragnaros_son_of_flame(Creature* creature) : PassiveAI(creature) { }

    // Cannot deal damage, but if it had the ability, it could cause unwanted behavior if default EnterEvadeMode is in place
    void EnterEvadeMode(EvadeReason /*reason*/) override { }

    void InitializeAI() override
    {
        if (!me->IsAlive())
            return;

        JustRespawned();
    }

    void JustRespawned() override
    {
        me->CastSpell(me, SPELL_SON_OF_FLAME_HIT_ME, true);
        me->CastSpell(me, SPELL_SON_OF_FLAME_INVIS_PRE_VISUAL, true);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_INVOKE_SONS)
            return;

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->PlayOneShotAnimKitId(ANIM_KIT_UNK);
        me->RemoveAurasDueToSpell(SPELL_SON_OF_FLAME_INVIS_PRE_VISUAL);
        me->CastSpell(me, SPELL_SON_OF_FLAME_BURNING_SPEED_CHECK, true);
        if (Creature* sulfuras = me->GetInstanceScript()->GetCreature(DATA_SULFURAS))
            _sulfurasGuid = sulfuras->GetGUID();

        _scheduler.Schedule(Milliseconds(2600), [this](TaskContext context)
        {
            if (me->isDead())
                return;

            if (Creature* sulfuras = ObjectAccessor::GetCreature(*me, _sulfurasGuid))
            {
                if (me->IsWithinMeleeRange(sulfuras))
                {
                    Detonate();
                    return;
                }
                else if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE && me->CanFreeMove())
                    me->GetMotionMaster()->MovePoint(0, sulfuras->GetPosition());
            }
            else
            {
                if (me->isMoving())
                {
                    me->GetMotionMaster()->Clear(false);
                    me->StopMoving();
                }

                context.Schedule(Milliseconds(2600), [this](TaskContext)
                {
                    Detonate();
                });
                return;
            }

            context.Repeat(Milliseconds(400));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        UpdateVictim();
        _scheduler.Update(diff);
    }

    void Detonate()
    {
        DoCastAOE(SPELL_SON_OF_FLAME_SUPERNOVA, true);
        me->Kill(me);
    }

private:
    TaskScheduler _scheduler;
    ObjectGuid _chaseGuid;
    ObjectGuid _sulfurasGuid;
};

// http://www.wowhead.com/npc=53189/molten-elemental
struct npc_fl_ragnaros_molten_elemental : public ScriptedAI
{
    npc_fl_ragnaros_molten_elemental(Creature* creature) : ScriptedAI(creature) { me->SetReactState(REACT_PASSIVE); }

    void EnterCombat(Unit* /*who*/) override
    {
        DoCast(SPELL_MOLTEN_ELEMENTAL_DISABLE_CRIT);
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_MOLTEN_ELEMENTAL_ACTIVATE)
            return;

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        DoCastAOE(SPELL_MOLTEN_ELEMENTAL_INFERNO);
        scheduler.Schedule(Milliseconds(600), [this](TaskContext)
        {
            me->SetReactState(REACT_AGGRESSIVE);
            DoCastAOE(SPELL_MOLTEN_ELEMENTAL_AGGRO_SUMMONER);
        });
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* ragnaros = me->GetInstanceScript()->GetCreature(DATA_RAGNAROS))
            if (ragnaros->IsAIEnabled)
                ragnaros->AI()->JustSummoned(me);

        DoCastAOE(SPELL_MOLTEN_SEED_MISSILE_TARGET_SEARCH);
        me->AddAura(SPELL_MOLTEN_ELEMENTAL_INVIS_PRE_VISUAL, me);
    }

    void SpellHit(Unit* caster, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_MOLTEN_SEED_MISSILE_HIT || caster->GetGUID() != SeedCasterGUID
            || !me->HasAura(SPELL_MOLTEN_ELEMENTAL_INVIS_PRE_VISUAL))
            return;

        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
        me->RemoveAurasDueToSpell(SPELL_MOLTEN_ELEMENTAL_INVIS_PRE_VISUAL);
        DoCast(SPELL_MOLTEN_ELEMENTAL_COUNTDOWN);

        if (!me->GetMap()->IsHeroic())
            return;

        scheduler.Schedule(Milliseconds(8200), [this](TaskContext)
        {
            DoCast(SPELL_MOLTEN_ELEMENTAL_MOLTEN_POWER);
        });
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_MOLTEN_SEED_MISSILE_TARGET_SEARCH)
            return;

        SeedCasterGUID = target->GetGUID();
    }

    void UpdateAI(uint32 diff) override
    {
        ScriptedAI::UpdateAI(diff);
        scheduler.Update(diff);
    }

private:
    ObjectGuid SeedCasterGUID;
    TaskScheduler scheduler;
};

// http://www.wowhead.com/npc=53485/engulfing-flames
struct npc_fl_ragnaros_engulfing_flames : public PassiveAI
{
    npc_fl_ragnaros_engulfing_flames(Creature* creature) : PassiveAI(creature), _engulfingId(DATA_ENGULFING_FLAMES_NULL) { }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_ENGULFING_FLAMES_PERIODIC || !me->GetMap()->IsHeroic())
            return;

        // Hack
        if (Aura* aura = me->GetAura(SPELL_ENGULFING_FLAMES_PERIODIC, me->GetGUID()))
            aura->SetDuration(1000);
    }

    void SetData(uint32 type, uint32 data) override
    {
        if (type != DATA_ENGULFING_FLAMES_ID)
            return;

        _engulfingId = data;
    }

    uint32 GetData(uint32 type) const override
    {
        if (type == DATA_ENGULFING_FLAMES_ID)
            return _engulfingId;

        return 0;
    }

private:
    uint32 _engulfingId;
};

// http://www.wowhead.com/npc=53231/lava-scion
struct npc_fl_ragnaros_lava_scion : public CreatureAI
{
    npc_fl_ragnaros_lava_scion(Creature* creature) : CreatureAI(creature)
    {
        me->SetWalk(true);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_LAVA_SCION_BLAZING_HEAT)
            return;

        Talk(EMOTE_LAVA_SCION_BLAZING_HEAT, target);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        scheduler.Schedule(Seconds(12), Seconds(15), [this](TaskContext context)
        {
            DoCastAOE(SPELL_LAVA_SCION_BLAZING_HEAT_TARGET_SEARCH);
            context.Repeat(Seconds(20), Seconds(23));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        DoMeleeAttackIfReady();
    }

private:
    TaskScheduler scheduler;
};

// http://www.wowhead.com/npc=53500/living-meteor
struct npc_fl_ragnaros_living_meteor : public NullCreatureAI
{
    npc_fl_ragnaros_living_meteor(Creature* creature) : NullCreatureAI(creature), _knockedBack(false) { }

    void Reset() override
    {
        me->CastSpell(me, SPELL_LIVING_METEOR_DAMAGE_REDUCTION, true);
        ScheduleChase(Milliseconds(1200));
    }

    void ScheduleChase(std::chrono::microseconds time)
    {
        _scheduler.Schedule(time, [this](TaskContext targetSearchLoop)
        {
            Unit* target = GetRandomFocusTarget(200.0f);
            if (!target || me->Attack(target, true))
            {
                targetSearchLoop.Repeat(Seconds(1));
                return;
            }

            me->GetMotionMaster()->MoveChase(target);

            targetSearchLoop.Schedule(Milliseconds(3600), [this, target](TaskContext context)
            {
                DoCast(SPELL_LIVING_METEOR_COMBUSTIBLE);
                DoCast(SPELL_LIVING_METEOR_PROXIMITY_CHECK);
                me->AddAura(SPELL_LIVING_METEOR_SPEED_TRIGGER, me);
                context.Schedule(Milliseconds(1200), [this, target](TaskContext)
                {
                    DoCast(target, SPELL_LIVING_METEOR_FIXATE_VISUAL, true);
                });
            });
        });
    }

    void ResetAuras(bool keepProximityChecker = false) const
    {
        me->RemoveAppliedAuras([keepProximityChecker](AuraApplication const* auraApp)
        {
            if (Aura* aura = auraApp->GetBase())
            {
                if (SpellInfo const* auraInfo = aura->GetSpellInfo())
                {
                    switch (auraInfo->Id)
                    {
                        case SPELL_LIVING_METEOR_PROXIMITY_CHECK:
                            if (keepProximityChecker)
                                return false;
                        case SPELL_LIVING_METEOR_COMBUSTIBLE:
                        case SPELL_LIVING_METEOR_SPEED_TRIGGER:
                        case SPELL_LIVING_METEOR_SPEED_AURA:
                            return true;
                        default:
                            return false;
                    }
                }
            }

            return false;
        });
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_LIVING_METEOR_COMBUSTION:
                me->AttackStop();
                _scheduler.CancelAll();
                ResetAuras(true);
                _knockedBack = true;
                _scheduler.Schedule(Milliseconds(1200), [this](TaskContext)
                {
                    _knockedBack = false;
                });
                ScheduleChase(Milliseconds(2500));
                break;
            case SPELL_BREADTH_OF_FROST_METEOR_AURA:
                _scheduler.CancelAll();
                ResetAuras();
                ScheduleChase(Seconds(12));
                break;
            default:
                break;
        }

    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_LIVING_METEOR_PROXIMITY_CHECK_HIT:
                me->AddAura(_knockedBack ? SPELL_LIVING_METEOR_NOT_YOUR_FAULT_AURA : SPELL_LIVING_METEOR_YOUR_FAULT_AURA, target);
                DoCastAOE(SPELL_LIVING_METEOR_IMPACT, true);
                me->AttackStop();
                _scheduler.CancelAll();
                ResetAuras();
                ScheduleChase(Seconds(3));
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        NullCreatureAI::UpdateAI(diff);
        _scheduler.Update(diff);
    }

private:
    bool _knockedBack;
    ObjectGuid _currentTarget;
    TaskScheduler _scheduler;
    Unit* GetRandomFocusTarget(float distance) const
    {
        std::list<Player*> players;
        Trinity::AnyPlayerInObjectRangeCheck checker(me, distance);
        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
        Cell::VisitWorldObjects(me, searcher, distance);

        players.remove_if([](Player* player)
        {
            return player->IsGameMaster();
        });

        if (players.size() > 1)
            if (Player* player = ObjectAccessor::GetPlayer(*me, _currentTarget))
                players.remove(player);

        return Trinity::Containers::SelectRandomContainerElement(players);
    }
};

// http://www.wowhead.com/npc=53872/cenarius
struct npc_fl_ragnaros_cenarius : public PassiveAI
{
    npc_fl_ragnaros_cenarius(Creature* creature) : PassiveAI(creature), _instance(me->GetInstanceScript()), _summons(creature) { }

    void InitializeAI() override
    {
        if (!me->IsAlive())
            return;

        JustRespawned();
    }

    void JustRespawned() override
    {
        Movement::PointsArray path(CenariusPath, CenariusPath + CenariusPathSize);
        me->GetMotionMaster()->MovePoint(1, CenariusPath[CenariusPathSize - 1].x, CenariusPath[CenariusPathSize - 1].y, CenariusPath[CenariusPathSize - 1].z);

        Movement::MoveSplineInit init(me);
        init.DisableTransportPathTransformations();
        init.MovebyPath(path);
        init.SetVelocity(24.0f);
        init.SetWalk(true);
        init.SetSmooth();
        init.SetFacing(me->GetOrientation());
        init.Launch();
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        _summons.Despawn(summon);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 /*id*/) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (Creature* ragnaros = _instance->GetCreature(DATA_RAGNAROS))
            if (ragnaros->IsAIEnabled)
                ragnaros->AI()->DoAction(ACTION_RAGNAROS_HEROIC_SUBMERGE);
        if (Creature* hamuul = _instance->GetCreature(DATA_HAMUUL_RUNETOTEM))
            if (hamuul->IsAIEnabled)
                hamuul->AI()->DoAction(ACTION_RAGNAROS_HEROIC_SUBMERGE);
        if (Creature* malfurion = _instance->GetCreature(DATA_MALFURION_STORMRAGE))
            if (malfurion->IsAIEnabled)
                malfurion->AI()->DoAction(ACTION_RAGNAROS_HEROIC_SUBMERGE);

        _events.ScheduleEvent(EVENT_HEROIC_CENARIUS_1, Milliseconds(3250));
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_CENARIUS_OUTRO_1:
                _scheduler.Schedule(Milliseconds(3600), [this](TaskContext)
                {
                    me->PlayOneShotAnimKitId(ANIM_KIT_TALK);
                    Talk(SAY_CENARIUS_HEROIC_OUTRO_1);
                    if (Creature* malfurion = _instance->GetCreature(DATA_MALFURION_STORMRAGE))
                        if (malfurion->IsAIEnabled)
                            malfurion->AI()->DoAction(ACTION_MALFURION_OUTRO_2);
                });
                break;
            case ACTION_CENARIUS_OUTRO_2:
                _scheduler.Schedule(Milliseconds(5800), [this](TaskContext)
                {
                    me->PlayOneShotAnimKitId(ANIM_KIT_TALK);
                    Talk(SAY_CENARIUS_HEROIC_OUTRO_2);
                    if (Creature* hamuul = _instance->GetCreature(DATA_HAMUUL_RUNETOTEM))
                        if (hamuul->IsAIEnabled)
                            hamuul->AI()->DoAction(ACTION_HAMUUL_OUTRO_1);
                });
                break;
            case ACTION_CENARIUS_OUTRO_3:
                _scheduler.Schedule(Milliseconds(13200), [this](TaskContext)
                {
                    me->PlayOneShotAnimKitId(ANIM_KIT_TALK);
                    Talk(SAY_CENARIUS_HEROIC_OUTRO_3);
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        _scheduler.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_HEROIC_CENARIUS_1:
                    Talk(SAY_CENARIUS_HEROIC_INTRO);
                    _events.ScheduleEvent(EVENT_DRAW_OUT_FIRELORD, Seconds(6));
                    break;
                case EVENT_DRAW_OUT_FIRELORD:
                    DoCastAOE(SPELL_CENARIUS_DRAW_OUT_FIRELORD, true);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    TaskScheduler _scheduler;
    SummonList _summons;
};

// http://www.wowhead.com/npc=53875/malfurion-stormrage
struct npc_fl_ragnaros_malfurion_stormrage : public PassiveAI
{
    npc_fl_ragnaros_malfurion_stormrage(Creature* creature) : PassiveAI(creature), _instance(me->GetInstanceScript()), _summons(creature) { }

    void InitializeAI() override
    {
        if (!me->IsAlive())
            return;

        JustRespawned();
    }

    void JustRespawned() override
    {
        Movement::PointsArray path(MalfurionPath, MalfurionPath + MalfurionPathSize);
        me->GetMotionMaster()->MovePoint(1, MalfurionPath[MalfurionPathSize - 1].x, MalfurionPath[MalfurionPathSize - 1].y, MalfurionPath[MalfurionPathSize - 1].z);

        Movement::MoveSplineInit init(me);
        init.DisableTransportPathTransformations();
        init.MovebyPath(path);
        init.SetVelocity(24.0f);
        init.SetFly();
        init.SetSmooth();
        init.SetFacing(0.0f);
        init.Launch();
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        _summons.Despawn(summon);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == 1)
        {
            me->SetFloatValue(UNIT_FIELD_HOVERHEIGHT, 0.0f); // Hack to prevent creature from hovering 1 yard above the ground after landing
            me->SetDisableGravity(false);
            me->RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            me->GetMotionMaster()->MoveFall();
        }
        else if (type == EFFECT_MOTION_TYPE)
            me->CastSpell(me, SPELL_MALFURION_TRANSFORM, true);
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RAGNAROS_HEROIC_SUBMERGE:
                _events.ScheduleEvent(EVENT_DRAW_OUT_FIRELORD, Seconds(8));
                break;
            case ACTION_MALFURION_HEROIC_INTRO:
                _events.ScheduleEvent(EVENT_HEROIC_MALFURION_1, Milliseconds(5200));
                break;
            case ACTION_MALFURION_OUTRO_1:
                _scheduler.Schedule(Milliseconds(6800), [this](TaskContext)
                {
                    me->PlayOneShotAnimKitId(ANIM_KIT_TALK);
                    Talk(SAY_MALFURION_HEROIC_OUTRO_1);
                    if (Creature* cenarius = _instance->GetCreature(DATA_CENARIUS))
                        if (cenarius->IsAIEnabled)
                            cenarius->AI()->DoAction(ACTION_CENARIUS_OUTRO_1);
                });
                break;
            case ACTION_MALFURION_OUTRO_2:
                _scheduler.Schedule(Seconds(4), [this](TaskContext)
                {
                    me->PlayOneShotAnimKitId(ANIM_KIT_TALK);
                    Talk(SAY_MALFURION_HEROIC_OUTRO_2);
                    if (Creature* cenarius = _instance->GetCreature(DATA_CENARIUS))
                        if (cenarius->IsAIEnabled)
                            cenarius->AI()->DoAction(ACTION_CENARIUS_OUTRO_2);
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        _scheduler.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DRAW_OUT_FIRELORD:
                    DoCastAOE(SPELL_MALFURION_DRAW_OUT_FIRELORD, true);
                    break;
                case EVENT_HEROIC_MALFURION_1:
                    Talk(SAY_MALFURION_HEROIC_INTRO);
                    me->PlayOneShotAnimKitId(ANIM_KIT_TALK);
                    _events.ScheduleEvent(EVENT_CLOUDBURST, Seconds(18));
                    break;
                case EVENT_CLOUDBURST:
                    DoCastAOE(SPELL_CLOUDBURST, true);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    TaskScheduler _scheduler;
    EventMap _events;
    SummonList _summons;
};

// http://www.wowhead.com/npc=53876/arch-druid-hamuul-runetotem
struct npc_fl_ragnaros_hamuul_runetotem : public PassiveAI
{
    npc_fl_ragnaros_hamuul_runetotem(Creature* creature) : PassiveAI(creature), _summons(creature) { }

    void InitializeAI() override
    {
        if (!me->IsAlive())
            return;

        JustRespawned();
    }

    void JustRespawned() override
    {
        Movement::PointsArray path(HamuulPath, HamuulPath + HamuulPathSize);
        me->GetMotionMaster()->MovePoint(1, HamuulPath[HamuulPathSize - 1].x, HamuulPath[HamuulPathSize - 1].y, HamuulPath[HamuulPathSize - 1].z);

        Movement::MoveSplineInit init(me);
        init.DisableTransportPathTransformations();
        init.MovebyPath(path);
        init.SetVelocity(24.0f);
        init.SetFly();
        init.SetSmooth();
        init.SetFacing(0.0f);
        init.Launch();
    }

    void JustSummoned(Creature* summon) override
    {
        _summons.Summon(summon);
    }

    void SummonedCreatureDespawn(Creature* summon) override
    {
        _summons.Despawn(summon);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == 1)
        {
            me->SetFloatValue(UNIT_FIELD_HOVERHEIGHT, 0.0f); // Hack to prevent creature from hovering 1 yard above the ground after landing
            me->SetDisableGravity(false);
            me->RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
            me->GetMotionMaster()->MoveFall();
        }
        else if (type == EFFECT_MOTION_TYPE)
            me->CastSpell(me, SPELL_HAMUUL_TRANSFORM, true);
    }

    void SpellHit(Unit* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_HAMUUL_TRANSFORM)
            return;
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_RAGNAROS_HEROIC_SUBMERGE:
                _events.ScheduleEvent(EVENT_DRAW_OUT_FIRELORD, Seconds(7));
                break;
            case ACTION_HAMUUL_OUTRO_1:
                _scheduler.Schedule(Milliseconds(13200), [this](TaskContext)
                {
                    me->PlayOneShotAnimKitId(ANIM_KIT_TALK);
                    Talk(SAY_HAMUUL_HEROIC_OUTRO);
                    if (Creature* cenarius = me->GetInstanceScript()->GetCreature(DATA_CENARIUS))
                        if (cenarius->IsAIEnabled)
                            cenarius->AI()->DoAction(ACTION_CENARIUS_OUTRO_3);
                });
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);
        _scheduler.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DRAW_OUT_FIRELORD:
                    DoCastAOE(SPELL_HAMUUL_DRAW_OUT_FIRELORD, true);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    TaskScheduler _scheduler;
    SummonList _summons;
};

// http://www.wowhead.com/npc=53952/platform-stalker
    struct npc_fl_ragnaros_platform_stalker : public PassiveAI
    {
        npc_fl_ragnaros_platform_stalker(Creature* creature) : PassiveAI(creature) { }

        void JustSummoned(Creature* summon) override
        {
            if (Creature* ragnaros = me->GetInstanceScript()->GetCreature(DATA_RAGNAROS))
                if (ragnaros->IsAIEnabled)
                    ragnaros->AI()->JustSummoned(summon);
        }

        void SummonedCreatureDespawn(Creature* summon) override
        {
            if (Creature* ragnaros = me->GetInstanceScript()->GetCreature(DATA_RAGNAROS))
                if (ragnaros->IsAIEnabled)
                    ragnaros->AI()->SummonedCreatureDespawn(summon);
        }
    };

// http://www.wowhead.com/npc=54147/cloudburstnpc_ragnaros_cloudburst
struct npc_fl_ragnaros_cloudburst : public PassiveAI
{
    npc_fl_ragnaros_cloudburst(Creature* creature) : PassiveAI(creature), _charges(0) { }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        _charges = me->GetMap()->Is25ManRaid() ? 3 : 1;
        me->CastSpell(me, SPELL_CLOUDBURST_VISUAL, true);
    }

    void OnSpellClick(Unit* /*clicker*/, bool& result) override
    {
        if (!result || _charges == 0)
            return;

        if (--_charges == 0)
            me->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 /*diff*/) override { }

private:
    uint32 _charges;
};

// http://www.wowhead.com/npc=54074/entrapping-roots
struct npc_fl_ragnaros_entrapping_roots : public PassiveAI
{
    npc_fl_ragnaros_entrapping_roots(Creature* creature) : PassiveAI(creature) { }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_ENTRAPPING_ROOTS_TARGET_SEARCH)
            return;

        me->RemoveAurasDueToSpell(SPELL_ENTRAPPING_ROOTS_PERIODIC);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* hamuul = me->GetInstanceScript()->GetCreature(DATA_HAMUUL_RUNETOTEM))
            hamuul->CastSpell(me, SPELL_ENTRAPPING_ROOTS);
    }
};

// http://www.wowhead.com/npc=53953/breadth-of-frost
struct npc_fl_ragnaros_breadth_of_frost : public PassiveAI
{
    npc_fl_ragnaros_breadth_of_frost(Creature* creature) : PassiveAI(creature) { }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_BREADTH_OF_FROST_METEOR_AURA)
            return;

        me->RemoveAurasDueToSpell(SPELL_BREADTH_OF_FROST_TARGET_SEARCH);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        if (Creature* cenarius = me->GetInstanceScript()->GetCreature(DATA_CENARIUS))
            cenarius->CastSpell(me, SPELL_BREADTH_OF_FROST);
    }
};

// http://www.wowhead.com/npc=54293/heart-of-ragnaros
struct npc_fl_ragnaros_heart_of_ragnaros : public PassiveAI
{
    npc_fl_ragnaros_heart_of_ragnaros(Creature* creature) : PassiveAI(creature), _looted(false) { }

    void EnterEvadeMode(EvadeReason /*why*/) override { }

    void OnSpellClick(Unit* clicker, bool& result) override
    {
        if (!result)
            return;

        if (_looted)
        {
            result = false;
            return;
        }

        Player* player = clicker->ToPlayer();
        if (!player)
            return;

        _looted = true;
        me->DespawnOrUnsummon(3);
    }

private:
    bool _looted;
};

// http://www.wowhead.com/spell=99503/raise-lava
class spell_fl_ragnaros_lava_wielder_raise_lava : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_lava_wielder_raise_lava);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 4);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_lava_wielder_raise_lava::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// http://www.wowhead.com/spell=99593/submerge
class spell_fl_ragnaros_lava_spewer_submerge : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_lava_spewer_submerge);

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        if (Creature* lavaSpewer = GetTarget()->ToCreature())
            if (lavaSpewer->IsAIEnabled)
                lavaSpewer->AI()->DoAction(ACTION_LAVA_WORM_EMERGE);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_fl_ragnaros_lava_spewer_submerge::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// http://www.wowhead.com/spell=99907/magma
class spell_fl_ragnaros_magma : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_magma);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* target)
        {
            return target->GetPositionZ() > 54.0f;
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_magma::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_magma::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=99400/burning-blast
class spell_fl_ragnaros_burning_blast : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_burning_blast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BURNING_WOUNDS_AURA });
    }

    void ChangeDamage()
    {
        if (Aura* burningWounds = GetCaster()->GetAura(SPELL_BURNING_WOUNDS_AURA))
            SetHitDamage(GetHitDamage()*burningWounds->GetStackAmount());
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_fl_ragnaros_burning_blast::ChangeDamage);
    }
};

// http://www.wowhead.com/spell=101110/rage-of-ragnaros
class spell_fl_ragnaros_rage_of_ragnaros : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_rage_of_ragnaros);

    void OnProc(AuraEffect const* /*aurEff*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        Creature* creature = caster->ToCreature();
        if (!creature || !creature->IsAIEnabled)
            return;

        creature->AI()->Talk(EMOTE_RAGE_OF_RAGNAROS, GetTarget());
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_fl_ragnaros_rage_of_ragnaros::OnProc, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

// http://www.wowhead.com/spell=101107/rage-of-ragnaros
class spell_fl_ragnaros_rage_of_ragnaros_dummy : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_rage_of_ragnaros_dummy);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo()->BasePoints, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(HeartOfFlameCheck());
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_rage_of_ragnaros_dummy::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_rage_of_ragnaros_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=98159/magma-trap
class spell_fl_ragnaros_magma_trap : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_magma_trap);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void HitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo()->BasePoints, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_magma_trap::HitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_magma_trap::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=98171/magma-trap
class spell_fl_ragnaros_magma_trap_dummy : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_magma_trap_dummy);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.size() <= 1)
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
        targets.resize(1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_magma_trap_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=98259/wrath-of-ragnaros
class spell_fl_ragnaros_wrath_of_ragnaros : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_wrath_of_ragnaros);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void HitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo()->BasePoints, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 3 : 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_wrath_of_ragnaros::HitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_wrath_of_ragnaros::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=98710/sulfuras-smash
class spell_fl_ragnaros_sulfuras_smash : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_sulfuras_smash);

    void SelectTarget(WorldObject*& target)
    {
        target = nullptr;
        if (Creature* sulfurasSmash = GetCaster()->FindNearestCreature(NPC_SULFURAS_SMASH, 50.0f))
            target = sulfurasSmash;
        else
            FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_fl_ragnaros_sulfuras_smash::SelectTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

// http://www.wowhead.com/spell=98706/sulfuras-smash
class spell_fl_ragnaros_sulfuras_smash_summon : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_sulfuras_smash_summon);

    void ModDestHeight(SpellEffIndex /*effIndex*/)
    {
        // Height is set to summoners height, which is not what we want. We want ground + 1.0f
        float height = GetCaster()->GetMap()->GetHeight(GetCaster()->GetPhaseShift(), GetHitDest()->GetPositionX(), GetHitDest()->GetPositionY(), GetHitDest()->GetPositionZ());
        GetHitDest()->Relocate(GetHitDest()->GetPositionX(), GetHitDest()->GetPositionY(), height + 1.0f);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_fl_ragnaros_sulfuras_smash_summon::ModDestHeight, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// http://www.wowhead.com/spell=98703/sulfuras-smash
class spell_fl_ragnaros_sulfuras_smash_player_trigger : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_sulfuras_smash_player_trigger);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_sulfuras_smash_player_trigger::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=99054/invoke-sons
class spell_fl_ragnaros_invoke_sons : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_invoke_sons);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INVOKE_SONS_MISSILE });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_INVOKE_SONS_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_invoke_sons::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// http://www.wowhead.com/spell=98473/burning-speed
class spell_fl_ragnaros_burning_speed : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_burning_speed);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SON_OF_FLAME_BURNING_SPEED });
    }

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        int32 stacks = GetTarget()->GetHealthPct() - 50;
        stacks /= 5;

        if (stacks > 0)
        {
            if (GetTarget()->GetAuraCount(SPELL_SON_OF_FLAME_BURNING_SPEED) != static_cast<uint32>(stacks))
                GetTarget()->SetAuraStack(SPELL_SON_OF_FLAME_BURNING_SPEED, GetTarget(), stacks);
        }
        else if (GetTarget()->HasAura(SPELL_SON_OF_FLAME_BURNING_SPEED))
            GetTarget()->RemoveAura(SPELL_SON_OF_FLAME_BURNING_SPEED);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_fl_ragnaros_burning_speed::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// http://www.wowhead.com/spell=98951/splitting-blow
// http://www.wowhead.com/spell=98952/splitting-blow
// http://www.wowhead.com/spell=98953/splitting-blow
class spell_fl_ragnaros_splitting_blow : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_splitting_blow);

    void SelectTarget(WorldObject*& target)
    {
        target = nullptr;
        Creature* ragnaros = GetCaster()->ToCreature();
        if (!ragnaros || !ragnaros->IsAIEnabled)
            return;

        RagnarosGUID id = RagnarosGUID(NULL);
        switch (GetSpellInfo()->Id)
        {
            case SPELL_SPLITTING_BLOW_WEST:
                id = GUID_SPLITTING_BLOW_WEST;
                break;
            case SPELL_SPLITTING_BLOW_MIDDLE:
                id = GUID_SPLITTING_BLOW_MIDDLE;
                break;
            case SPELL_SPLITTING_BLOW_EAST:
                id = GUID_SPLITTING_BLOW_EAST;
                break;
            default:
                break;
        }

        target = ObjectAccessor::GetCreature(*ragnaros, ragnaros->AI()->GetGUID(id));
    }
    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_fl_ragnaros_splitting_blow::SelectTarget, EFFECT_0, TARGET_DEST_NEARBY_ENTRY);
    }
};

// http://www.wowhead.com/spell=99012/splitting-blow
class spell_fl_ragnaros_splitting_blow_dummy : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_splitting_blow_dummy);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_1);
        return spellEffectInfo && ValidateSpellInfo({ SPELL_SPLITTING_BLOW_TRIGGERED, uint32(spellEffectInfo->BasePoints) });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* target = GetHitCreature();
        if (!target)
            return;

        target->CastSpell(target, uint32(GetEffectValue()), true);
        target->CastSpell(target, GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_splitting_blow_dummy::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// http://www.wowhead.com/spell=98520/molten-seed
class spell_fl_ragnaros_molten_seed_grow : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_molten_seed_grow);

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            if (creature->IsAIEnabled)
                creature->AI()->DoAction(ACTION_MOLTEN_ELEMENTAL_ACTIVATE);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_fl_ragnaros_molten_seed_grow::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// http://www.wowhead.com/spell=98333/molten-seed
class spell_fl_ragnaros_molten_seed_target_search : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_molten_seed_target_search);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, GetCaster()->GetMap()->Is25ManRaid() ? 20 : 10);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_molten_seed_target_search::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=98497/molten-seed
class spell_fl_ragnaros_molten_seed_missile_target_search : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_molten_seed_missile_target_search);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetCaster(), GetEffectInfo()->BasePoints, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_molten_seed_missile_target_search::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_molten_seed_missile_target_search::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// http://www.wowhead.com/spell=98518/molten-inferno
class spell_fl_ragnaros_molten_inferno : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_molten_inferno);

    void ChangeDamage()
    {
        float maxRange = GetSpellInfo()->GetEffect(EFFECT_0)->CalcRadius();
        float actualRange = GetCaster()->GetDistance2d(GetHitUnit());
        SetHitDamage(GetHitDamage()*pow(0.8, uint32(actualRange / maxRange * 100)));
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_fl_ragnaros_molten_inferno::ChangeDamage);
    }
};

// http://www.wowhead.com/spell=99172/engulfing-flames
// http://www.wowhead.com/spell=99216/engulfing-flames-near-visual
// http://www.wowhead.com/spell=99235/engulfing-flames
// http://www.wowhead.com/spell=99217/engulfing-flames-middle-visual
// http://www.wowhead.com/spell=99236/engulfing-flames
// http://www.wowhead.com/spell=99218/engulfing-flames-far-visual
class spell_fl_ragnaros_engulfing_flames : public SpellScriptLoader
{
    public:
        spell_fl_ragnaros_engulfing_flames(char const* scriptName, uint32 dataId) : SpellScriptLoader(scriptName), _dataId(dataId) { }

        class spell_fl_ragnaros_engulfing_flames_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_fl_ragnaros_engulfing_flames_SpellScript);

        public:
            spell_fl_ragnaros_engulfing_flames_SpellScript(uint32 dataId) : SpellScript(), _dataId(dataId) { }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if([this](WorldObject* target)
                {
                    Creature* creature = target->ToCreature();
                    if (!creature || creature->GetEntry() != NPC_ENGULFING_FLAMES || !creature->IsAIEnabled)
                        return true;

                    return _dataId != creature->AI()->GetData(DATA_ENGULFING_FLAMES_ID);
                });
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_engulfing_flames_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }

        private:
            uint32 _dataId;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_fl_ragnaros_engulfing_flames_SpellScript(_dataId);
        }

    private:
        uint32 _dataId;
};

// http://www.wowhead.com/spell=99171/engulfing-flames
class spell_fl_ragnaros_world_in_flames : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_world_in_flames);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        for (uint8 pos : EngulfingFlamePositions)
            if (!sSpellMgr->GetSpellInfo(EngulfingFlames[pos][ID_ENGULFING_FLAME_VISUAL]) ||
                !sSpellMgr->GetSpellInfo(EngulfingFlames[pos][ID_ENGULFING_FLAME_CAST]))
                return false;
        return true;
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Creature* ragnaros = GetCaster()->ToCreature();
        if (!ragnaros->IsAIEnabled)
            return;

        uint32 pos = ragnaros->AI()->GetData(DATA_NEW_ENGULFING_FLAME);
        ragnaros->AI()->SetData(DATA_PREVIOUS_ENGULFING_FLAME, pos);

        uint32 visual = EngulfingFlames[pos][ID_ENGULFING_FLAME_VISUAL];
        uint32 cast = EngulfingFlames[pos][ID_ENGULFING_FLAME_CAST];
        ragnaros->CastSpell(ragnaros, visual, true);
        ragnaros->CastSpell(ragnaros, cast);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_world_in_flames::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// http://www.wowhead.com/spell=99125/blazing-heat
class spell_fl_ragnaros_blazing_heat_spawn : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_blazing_heat_spawn);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_LAVA_SCION_BLAZING_HEAT_SUMMON });
    }

    void CastSpell()
    {
        GetCaster()->CastSpell(GetCaster(), SPELL_LAVA_SCION_BLAZING_HEAT_SUMMON, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (!targets.empty())
            FinishCast(SPELL_FAILED_DONT_REPORT);
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_fl_ragnaros_blazing_heat_spawn::CastSpell);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_blazing_heat_spawn::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// http://www.wowhead.com/spell=100459/blazing-heat
class spell_fl_ragnaros_blazing_heat_target_search : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_blazing_heat_target_search);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo()->BasePoints, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_blazing_heat_target_search::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/spell=99267/living-meteor
class spell_fl_ragnaros_living_meteor_target_search : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_living_meteor_target_search);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT && GetCaster()->IsAIEnabled;
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo()->BasePoints, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 castCount = GetCaster()->GetAI()->GetData(DATA_METEOR_CAST_COUNT);
        Trinity::Containers::RandomResize(targets, castCount > 1 ? castCount * 2 : castCount);
        GetCaster()->GetAI()->SetData(DATA_METEOR_CAST_COUNT, castCount + 1);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_living_meteor_target_search::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_living_meteor_target_search::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=99296/combustible
class spell_fl_ragnaros_living_meteor_combustible : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_living_meteor_combustible);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LIVING_METEOR_COMBUSTION });
    }

    void OnProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(eventInfo.GetDamageInfo()->GetAttacker(), SPELL_LIVING_METEOR_COMBUSTION, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_fl_ragnaros_living_meteor_combustible::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};

// http://www.wowhead.com/spell=108773/magma
class spell_fl_ragnaros_magma_knockup : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_magma_knockup);

    void FilterShortKnockup(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* target)
        {
            return GetCaster()->IsWithinLOSInMap(target);
        });
    }

    void FilterHighKnockup(std::list<WorldObject*>& targets)
    {
        targets.remove_if([this](WorldObject* target)
        {
            return !GetCaster()->IsWithinLOSInMap(target);
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_magma_knockup::FilterShortKnockup, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_magma_knockup::FilterHighKnockup, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// http://www.wowhead.com/spell=100691/dreadflame
class spell_fl_ragnaros_dreadflame_dummy : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_dreadflame_dummy);

    void HandleDummyTick(AuraEffect const* /*aurEff*/)
    {
        Creature* ragnaros = GetCaster()->ToCreature();
        if (!ragnaros || !ragnaros->IsAIEnabled)
            return;

        ragnaros->AI()->DoAction(ACTION_RAGNAROS_DREADFLAME);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_fl_ragnaros_dreadflame_dummy::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// http://www.wowhead.com/spell=100906/dreadflame-control-aura
class spell_fl_ragnaros_dreadflame_spawn_control_aura : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_dreadflame_spawn_control_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_DELUGE_AURA,
            SPELL_DREADFLAME_SPAWN
        });
    }

    void OnSpellHit(SpellEffIndex /*effIndex*/)
    {
        DreadflameAI* ai = CAST_AI(DreadflameAI, GetCaster()->GetAI());
        if (!ai)
            return;

        Creature* creature = GetHitCreature();
        if (!creature)
            return;

        if (!ai->IsNearbyDreadflame(creature, 1.5f))
        {
            std::list<Player*> players;
            Trinity::AnyPlayerInObjectRangeCheck checker(creature, 1.5f);
            Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(creature, players, checker);
            Cell::VisitWorldObjects(creature, searcher, 1.5f);
            players.remove_if(Trinity::UnitAuraCheck(false, SPELL_DELUGE_AURA));
            if (players.empty())
                GetCaster()->CastSpell(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), SPELL_DREADFLAME_SPAWN, true);
        }

        creature->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_dreadflame_spawn_control_aura::OnSpellHit, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/spell=100695/dreadflame-control-aura
class spell_fl_ragnaros_dreadflame_spread_control_aura : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_dreadflame_spread_control_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DREADFLAME_SPAWN });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        PreventDefaultAction();
        DreadflameAI* ai = CAST_AI(DreadflameAI, GetCaster()->GetAI());
        if (!ai)
            return;

        std::vector<Position> dreadflames = ai->GetDreadflameSpreadPositions();
        for (auto dreadFlame : dreadflames)
            GetCaster()->CastSpell(dreadFlame.GetPositionX(), dreadFlame.GetPositionY(), dreadFlame.GetPositionZ(), SPELL_DREADFLAME_SPAWN, true);
    }


    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_fl_ragnaros_dreadflame_spread_control_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// http://www.wowhead.com/spell=100966/dreadflame-control-aura
class spell_fl_ragnaros_dreadflame_damage_control_aura : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_dreadflame_damage_control_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DREADFLAME_DAMAGE });
    }

    void OnSpellHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_DREADFLAME_DAMAGE, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        DreadflameAI* ai = CAST_AI(DreadflameAI, GetCaster()->GetAI());
        if (!ai)
        {
            targets.clear();
            return;
        }

        targets.remove_if([ai](WorldObject* target)
        {
            return !ai->IsNearbyDreadflame(target, 4.0f);
        });
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_dreadflame_damage_control_aura::OnSpellHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_dreadflame_damage_control_aura::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// http://www.wowhead.com/spell=100823/dreadflame-control-aura
class spell_fl_ragnaros_dreadflame_deluge_control_aura : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_dreadflame_deluge_control_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DELUGE_EXTINGUISH_DREADFLAME });
    }

    void HitTarget(SpellEffIndex /*effIndex*/)
    {
        DreadflameAI* ai = CAST_AI(DreadflameAI, GetCaster()->GetAI());
        if (!ai)
            return;

        if (DynamicObject* dreadflame = ai->GetNearestLitDreadflameDynamicObject(GetHitUnit(), 1.5f))
        {
            GetCaster()->CastSpell(dreadflame->GetPositionX(), dreadflame->GetPositionY(), dreadflame->GetPositionZ(), SPELL_DELUGE_EXTINGUISH_DREADFLAME, true);
            // Hack, this should be handled by unimplemented SPELL_DELUGE_EXTINGUISH_DREADFLAME effect
            dreadflame->Remove();
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_dreadflame_deluge_control_aura::HitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/spell=100644/entrapping-roots-summon
// http://www.wowhead.com/spell=100476/breadth-of-frost-summon
class spell_fl_ragnaros_npc_helper_summon : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_npc_helper_summon);

    void RelocateHeight(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();

        // The default "random" pattern sucks, so we recalculate it here.
        float distance = sqrt(rand_norm()) * (GetSpellInfo()->GetEffect(effIndex)->CalcRadius(GetCaster()) + caster->GetObjectSize());
        float theta = float(rand_norm()) * static_cast<float>(2 * M_PI);
        float x = distance * cos(theta) + GetCaster()->GetPositionX();
        float y = distance * sin(theta) + GetCaster()->GetPositionY();
        float z = GetCaster()->GetPositionZ();

        const_cast<WorldLocation*>(GetExplTargetDest())->Relocate(x, y, z);
        GetHitDest()->Relocate(x, y, z);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_fl_ragnaros_npc_helper_summon::RelocateHeight, EFFECT_0, SPELL_EFFECT_SUMMON);
    }
};

// http://www.wowhead.com/spell=100751/cloudburst
class spell_fl_ragnaros_cloudburst : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_cloudburst);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void OnSpellHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), GetEffectInfo()->BasePoints);
    }

    void TargetStalker(std::list<WorldObject*>& targets)
    {
        targets.clear();
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* ragnaros = instance->GetCreature(DATA_RAGNAROS))
                if (ragnaros->IsAIEnabled)
                    if (Creature* target = ObjectAccessor::GetCreature(*GetCaster(), ragnaros->GetAI()->GetGUID(GUID_CLOUDBURST_TARGET)))
                        targets.push_back(target);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_cloudburst::OnSpellHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_cloudburst::TargetStalker, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// http://www.wowhead.com/spell=100653/entrapping-roots
class spell_fl_ragnaros_entrapping_roots : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_entrapping_roots);

    void TargetRagnaros(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            FinishCast(SPELL_FAILED_DONT_REPORT);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_entrapping_roots::TargetRagnaros, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_entrapping_roots::TargetRagnaros, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// http://www.wowhead.com/spell=100645/enrapping-roots
class spell_fl_ragnaros_entrapping_roots_trigger : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_entrapping_roots_trigger);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void OnSpellHit(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetEffectInfo()->BasePoints, true);
    }

    void TargetStalker(WorldObject*& target)
    {
        target = nullptr;
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* ragnaros = instance->GetCreature(DATA_RAGNAROS))
                if (ragnaros->IsAIEnabled)
                    if (Creature* helperTarget = ObjectAccessor::GetCreature(*GetCaster(), ragnaros->GetAI()->GetGUID(GUID_PLAYER_HELPER_TARGET)))
                        target = helperTarget;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_entrapping_roots_trigger::OnSpellHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_fl_ragnaros_entrapping_roots_trigger::TargetStalker, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

// http://www.wowhead.com/spell=100472/breadth-of-frost-trigger
class spell_fl_ragnaros_breadth_of_frost_trigger : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_breadth_of_frost_trigger);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void OnSpellHit(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), GetEffectInfo()->BasePoints, true);
    }

    void TargetStalker(WorldObject*& target)
    {
        target = nullptr;
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* ragnaros = instance->GetCreature(DATA_RAGNAROS))
                if (ragnaros->IsAIEnabled)
                    if (Creature* helperTarget = ObjectAccessor::GetCreature(*GetCaster(), ragnaros->GetAI()->GetGUID(GUID_PLAYER_HELPER_TARGET)))
                        target = helperTarget;
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_breadth_of_frost_trigger::OnSpellHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_fl_ragnaros_breadth_of_frost_trigger::TargetStalker, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

// http://www.wowhead.com/spell=100503/breadth-of-frost
class spell_fl_ragnaros_breadth_of_frost_player_aura : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_breadth_of_frost_player_aura);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_1);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void OnSpellHit(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(GetEffectInfo()->BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_breadth_of_frost_player_aura::OnSpellHit, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// http://www.wowhead.com/spell=100567/breadth-of-frost
class spell_fl_ragnaros_breadth_of_frost_meteor_aura : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_breadth_of_frost_meteor_aura);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_LIVING_METEOR_TRANSFORM_FROZEN });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_LIVING_METEOR_TRANSFORM_FROZEN, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_LIVING_METEOR_TRANSFORM_FROZEN);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_fl_ragnaros_breadth_of_frost_meteor_aura::OnApply, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_fl_ragnaros_breadth_of_frost_meteor_aura::OnRemove, EFFECT_0, SPELL_AURA_MOD_STUN, AURA_EFFECT_HANDLE_REAL);
    }
};

// http://www.wowhead.com/spell=100604/empower-sulfuras
class spell_fl_ragnaros_empower_sulfuras : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_empower_sulfuras);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_1);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void OnSpellHit(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->AddAura(GetEffectInfo()->BasePoints, GetHitUnit());
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_empower_sulfuras::OnSpellHit, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// http://www.wowhead.com/spell=100628/empowered-sulfuras
class spell_fl_ragnaros_empower_sulfuras_aura : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_empower_sulfuras_aura);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* ragnaros = GetTarget()->ToCreature();
        if (!ragnaros)
            return;

        ragnaros->LoadEquipment(EQUIP_EMPOWERED_SULFURAS);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Creature* ragnaros = GetTarget()->ToCreature();
        if (!ragnaros)
            return;

        ragnaros->LoadEquipment(); // Load default equipment
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_fl_ragnaros_empower_sulfuras_aura::OnApply, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_fl_ragnaros_empower_sulfuras_aura::OnRemove, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// http://www.wowhead.com/spell=100605/empower-sulfuras
class spell_fl_ragnaros_empower_sulfuras_aura_dummy : public AuraScript
{
    PrepareAuraScript(spell_fl_ragnaros_empower_sulfuras_aura_dummy);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->TriggerSpell) });
    }

    void HandleDummyTick(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        if (urand(0, 2) == 0)
        {
            uint32 triggerSpell = GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->TriggerSpell;
            GetTarget()->CastSpell(GetTarget(), triggerSpell, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_fl_ragnaros_empower_sulfuras_aura_dummy::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// http://www.wowhead.com/spell=100771/deluge-aura-cancel
class spell_fl_ragnaros_deluge_aura_cancel : public SpellScript
{
    PrepareSpellScript(spell_fl_ragnaros_deluge_aura_cancel);

    bool Validate(SpellInfo const* spellInfo) override
    {
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_0);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAura(GetEffectInfo()->BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_fl_ragnaros_deluge_aura_cancel::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_fl_ragnaros_heart_of_ragnaros : public SpellScriptLoader
{
    public:
        spell_fl_ragnaros_heart_of_ragnaros(char const* scriptName, uint32 questId) : SpellScriptLoader(scriptName), _questId(questId) { }

        class spell_fl_ragnaros_heart_of_ragnaros_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_fl_ragnaros_heart_of_ragnaros_SpellScript);

        public:
            spell_fl_ragnaros_heart_of_ragnaros_SpellScript(uint32 questId) : SpellScript(), _questId(questId) { }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return sObjectMgr->GetQuestTemplate(_questId) != nullptr;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(HeartOfFlameCheck(_questId));
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fl_ragnaros_heart_of_ragnaros_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            }

        private:
            uint32 _questId;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_fl_ragnaros_heart_of_ragnaros_SpellScript(_questId);
        }

    private:
        uint32 _questId;
};

// 6845
class at_sulfuron_keep : public AreaTriggerScript
{
    public:
        at_sulfuron_keep() : AreaTriggerScript("at_sulfuron_keep") { }

        bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/, bool entered) override
        {
            if (!entered)
                return true;

            if (InstanceScript* instance = player->GetInstanceScript())
                instance->SetData(DATA_RAGNAROS_EMERGE, 0);

            return true;
        }
};

// http://www.wowhead.com/achievement=5855/ragnar-os
class achievement_ragnar_os : public AchievementCriteriaScript
{
    public:
        achievement_ragnar_os() : AchievementCriteriaScript("achievement_ragnar_os") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target || !target->IsAIEnabled)
                return false;

            return target->GetAI()->GetData(DATA_IGNITED_METEORS) >= 3;
        }
};

void AddSC_boss_ragnaros_firelands()
{
    RegisterFirelandsAI(npc_fl_ragnaros_lava_wielder);
    RegisterFirelandsAI(npc_fl_ragnaros_lava_wielder_lava);
    RegisterFirelandsAI(npc_fl_ragnaros_molten_spewer);
    RegisterFirelandsAI(npc_fl_ragnaros_molten_erupter);
    RegisterFirelandsAI(npc_fl_ragnaros_molten_eruption);
    RegisterFirelandsAI(npc_fl_ragnaros_dreadflame);
    RegisterFirelandsAI(boss_fl_ragnaros);
    RegisterFirelandsAI(npc_fl_ragnaros_magma_trap);
    RegisterFirelandsAI(npc_fl_ragnaros_sulfuras_smash);
    RegisterFirelandsAI(npc_fl_ragnaros_lava_wave);
    RegisterFirelandsAI(npc_fl_ragnaros_son_of_flame);
    RegisterFirelandsAI(npc_fl_ragnaros_molten_elemental);
    RegisterFirelandsAI(npc_fl_ragnaros_engulfing_flames);
    RegisterFirelandsAI(npc_fl_ragnaros_lava_scion);
    RegisterFirelandsAI(npc_fl_ragnaros_living_meteor);
    RegisterFirelandsAI(npc_fl_ragnaros_cenarius);
    RegisterFirelandsAI(npc_fl_ragnaros_malfurion_stormrage);
    RegisterFirelandsAI(npc_fl_ragnaros_hamuul_runetotem);
    RegisterFirelandsAI(npc_fl_ragnaros_platform_stalker);
    RegisterFirelandsAI(npc_fl_ragnaros_cloudburst);
    RegisterFirelandsAI(npc_fl_ragnaros_entrapping_roots);
    RegisterFirelandsAI(npc_fl_ragnaros_breadth_of_frost);
    RegisterFirelandsAI(npc_fl_ragnaros_heart_of_ragnaros);

    RegisterSpellScript(spell_fl_ragnaros_lava_wielder_raise_lava);
    RegisterAuraScript(spell_fl_ragnaros_lava_spewer_submerge);
    RegisterSpellScript(spell_fl_ragnaros_magma);
    RegisterSpellScript(spell_fl_ragnaros_burning_blast);
    RegisterAuraScript(spell_fl_ragnaros_rage_of_ragnaros);
    RegisterSpellScript(spell_fl_ragnaros_rage_of_ragnaros_dummy);
    RegisterSpellScript(spell_fl_ragnaros_magma_trap);
    RegisterSpellScript(spell_fl_ragnaros_magma_trap_dummy);
    RegisterSpellScript(spell_fl_ragnaros_wrath_of_ragnaros);
    RegisterSpellScript(spell_fl_ragnaros_sulfuras_smash);
    RegisterSpellScript(spell_fl_ragnaros_sulfuras_smash_summon);
    RegisterSpellScript(spell_fl_ragnaros_sulfuras_smash_player_trigger);
    RegisterSpellScript(spell_fl_ragnaros_invoke_sons);
    RegisterAuraScript(spell_fl_ragnaros_burning_speed);
    RegisterSpellScript(spell_fl_ragnaros_splitting_blow);
    RegisterSpellScript(spell_fl_ragnaros_splitting_blow_dummy);
    RegisterAuraScript(spell_fl_ragnaros_molten_seed_grow);
    RegisterSpellScript(spell_fl_ragnaros_molten_seed_target_search);
    RegisterSpellScript(spell_fl_ragnaros_molten_seed_missile_target_search);
    RegisterSpellScript(spell_fl_ragnaros_molten_inferno);
    new spell_fl_ragnaros_engulfing_flames("spell_fl_ragnaros_engulfing_flames_near", DATA_ENGULFING_FLAMES_NEAR);
    new spell_fl_ragnaros_engulfing_flames("spell_fl_ragnaros_engulfing_flames_near_visual", DATA_ENGULFING_FLAMES_NEAR);
    new spell_fl_ragnaros_engulfing_flames("spell_fl_ragnaros_engulfing_flames_middle", DATA_ENGULFING_FLAMES_MIDDLE);
    new spell_fl_ragnaros_engulfing_flames("spell_fl_ragnaros_engulfing_flames_middle_visual", DATA_ENGULFING_FLAMES_MIDDLE);
    new spell_fl_ragnaros_engulfing_flames("spell_fl_ragnaros_engulfing_flames_far", DATA_ENGULFING_FLAMES_FAR);
    new spell_fl_ragnaros_engulfing_flames("spell_fl_ragnaros_engulfing_flames_far_visual", DATA_ENGULFING_FLAMES_FAR);
    RegisterSpellScript(spell_fl_ragnaros_world_in_flames);
    RegisterSpellScript(spell_fl_ragnaros_blazing_heat_spawn);
    RegisterSpellScript(spell_fl_ragnaros_blazing_heat_target_search);
    RegisterSpellScript(spell_fl_ragnaros_living_meteor_target_search);
    RegisterAuraScript(spell_fl_ragnaros_living_meteor_combustible);
    RegisterSpellScript(spell_fl_ragnaros_magma_knockup);
    RegisterAuraScript(spell_fl_ragnaros_dreadflame_dummy);
    RegisterSpellScript(spell_fl_ragnaros_dreadflame_spawn_control_aura);
    RegisterAuraScript(spell_fl_ragnaros_dreadflame_spread_control_aura);
    RegisterSpellScript(spell_fl_ragnaros_dreadflame_damage_control_aura);
    RegisterSpellScript(spell_fl_ragnaros_dreadflame_deluge_control_aura);
    RegisterSpellScript(spell_fl_ragnaros_npc_helper_summon);
    RegisterSpellScript(spell_fl_ragnaros_cloudburst);
    RegisterSpellScript(spell_fl_ragnaros_entrapping_roots);
    RegisterSpellScript(spell_fl_ragnaros_entrapping_roots_trigger);
    RegisterSpellScript(spell_fl_ragnaros_breadth_of_frost_trigger);
    RegisterSpellScript(spell_fl_ragnaros_breadth_of_frost_player_aura);
    RegisterAuraScript(spell_fl_ragnaros_breadth_of_frost_meteor_aura);
    RegisterSpellScript(spell_fl_ragnaros_empower_sulfuras);
    RegisterAuraScript(spell_fl_ragnaros_empower_sulfuras_aura);
    RegisterAuraScript(spell_fl_ragnaros_empower_sulfuras_aura_dummy);
    RegisterSpellScript(spell_fl_ragnaros_deluge_aura_cancel);
    new spell_fl_ragnaros_heart_of_ragnaros("spell_fl_ragnaros_heart_of_ragnaros_h", QUEST_HEART_OF_FLAME_H);
    new spell_fl_ragnaros_heart_of_ragnaros("spell_fl_ragnaros_heart_of_ragnaros_a", QUEST_HEART_OF_FLAME_A);

    new at_sulfuron_keep();

    new achievement_ragnar_os();
};
