/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#ifndef DEF_THUNDER_FORGE
#define DEF_THUNDER_FORGE

enum Data
{
    DATA_NONE,

    DATA_PLAYER_ROLE,
    DATA_MOGU_CRUCIBLE,
    DATA_ALLOWED_STAGE,
    DATA_WAVE_COUNTER,
    DATA_WARRIOR_1,
    DATA_WARRIOR_2,
    DATA_DEFENDER,
    DATA_STAGE1_P2,
    DATA_TRUNDER_FORGE_DOOR,
    DATA_WRATHION,
    DATA_CELESTIAL_BLACKSMITH,
    DATA_CELESTIAL_DEFENDER,
    DATA_SECOND_STAGE_FIRST_STEP,
    DATA_COMPLETE_SECOND_STAGE_SECOND_STEP,
};

enum Actions
{
    ACTION_WRATHION_START = 20,
    ACTION_INISIBLE_HUNTER_AURA,
    ACTION_CHARGING_1,
    ACTION_CHARGING_2,
    ACTION_CHARGING_3,
    ACTION_CHARGING_4,
    ACTION_LR_P1,
    ACTION_CB_START_MOVING,
    ACTION_FORGE_CAST,
    ACTION_CANCEL_FORGE_EVENTS,
    ACTION_M_ENERGY,
    ACTION_SHA_FIXATE,
    ACTION_FIRST_WAVE,

    ACTION_SCENARIO_COMPLETED
};

enum eCreatures
{
    NPC_WRATHION                        = 70100,
    NPC_SHADO_PAN_WARRIOR               = 70106, //< x2
    NPC_SHADO_PAN_DEFENDER              = 70099,

    NPC_THUNDER_FORGE                   = 70577,
    NPC_THUNDER_FORGE_2                 = 70283,
    NPC_THUNDER_FORGE_3                 = 70292,
    NPC_THUNDER_FORGE_CRUCIBLE          = 70556,
    NPC_LIGHTING_PILAR_BEAM_STALKER     = 69798,
    NPC_LIGHTING_PILAR_SPARK_STALKER    = 69813,
    NPC_INVISIBLE_STALKER               = 62142,

    NPC_FORGEMASTER_VULKON              = 70074,

    NPC_SHANZE_SHADOWCASTER             = 69827,
    NPC_SHANZE_WARRIOR                  = 69833,
    NPC_SHANZE_BATTLEMASTER             = 69835,
    NPC_SHANZE_ELECTRO_CUTIONER         = 70070,
    NPC_SHANZE_ELECTRO_CUTIONER2        = 69216,
    NPC_SHANZE_PYROMANCER               = 69824,

    NPC_SPIRIT_HEALER                   = 65183,
    NPC_JUVENILE_SKYSCREAMER            = 69162,
    NPC_ZANALARI_COMMONER               = 69170,
    NPC_DRAKKARI_GOD_HULK               = 69200,
    NPC_MANFRED                         = 69217,
    NPC_ZANALARI_STONE_SHIELD           = 69223,
    NPC_FIERCE_ANKLEBITER               = 69244,
    NPC_ZANDALARI_PROSPECT              = 69269,
    NPC_ZANDALARI_BEASTCALLER           = 69379,
    NPC_ZANDALARI_BEASTCALLER2          = 69397,
    NPC_JUVENILE_SKYSCREAMER2           = 69404,
    NPC_ZANDALARI_BEASTCALLER3          = 69412,
    NPC_LORTHEMAR_THERON                = 69481,
    NPC_SLAVEMASTER_SHIAXU              = 69923,
    NPC_SCOUT_CAPTAIN_ELSIA             = 70042,
    NPC_NALAK                           = 69099,

    //< VEH
    NPC_ZANDALARI_SKYSCREAMER           = 69156,
    NPC_ZANDALARI_SKYSCREAMER2          = 69411,
    NPC_THUNDERWING                     = 69509,

    //< second room
    NPC_CELESTIAL_BLACKSMITH            = 69828,
    NPC_CELESTIAL_DEFENDER              = 69837,

    NPC_PHASE3_ROOM_CENTER_STALKER      = 70481,
    NPC_ANVIL_STALKER                   = 70079,
    NPC_THUNDER_FORGE_4                 = 70061,
    NPC_LIGHTING_SPEAR_FLOAT_STALKER    = 70500,
    NPC_LIGHTING_LANCE                  = 70460,

    NPC_CONSTELLATION                   = 70058,
    NPC_COSMETIC_SHA_BOSS               = 70449,
    NPC_METEOR_SUMMONER_STALKER         = 70299,
    NPC_DEBILITATING_SHA                = 70462,
    NPC_SHA_AMALGAMATION                = 70228,
    NPC_MEDIUM_SHA_SPAWNER_STALKER      = 70148,
    NPC_SHA_FIEND                       = 70039,
    NPC_SMALL_SHA_SPAWNER_STALKER       = 70148,
    NPC_SHA_BEAST                       = 70048,
};

enum eGameObects
{
    GO_MOGU_CRICUBLE                = 218910,

    GO_THUNDER_FORGE_DOOR           = 218832,
    GO_INVISIBLE_WALL               = 213251,

    GO_THUNDER_FORGE_AVNIL          = 218741,
    GO_THUNDER_FORGE_AVNIL_2        = 218704,
    GO_THUNDER_FORGE_AVNIL_3        = 218701,
    GO_THUNDER_FORGE_AVNIL_4        = 218705,
    GO_THUNDER_FORGE_AVNIL_5        = 218702,
    GO_THUNDER_FORGE_AVNIL_6        = 218706,
    GO_THUNDER_FORGE_AVNIL_7        = 218703,

    GO_SMELTING_ROD_02              = 218916,
    GO_SMELTING_ROD_01              = 218909,
    GO_SMELTING_POT_01              = 218908,
    GO_SMELTING_POT_02              = 218917,


    GO_PORTAL_TO_THUNDER_ISLAND     = 218462,
    //GameObjectEntry: 218538 Low: 18551
    //GameObjectEntry: 218628 Low: 18621
    //GameObjectEntry: 218696 Low: 18619
    //GameObjectEntry: 218697 Low: 18618
    //GameObjectEntry: 218698 Low: 18617
    //GameObjectEntry: 218707 Low: 18603
    //GameObjectEntry: 218708 Low: 18604
    //GameObjectEntry: 218709 Low: 18605
    //GameObjectEntry: 218710 Low: 18606
    //GameObjectEntry: 218717 Low: 18622
    //GameObjectEntry: 218726 Low: 18614
    //GameObjectEntry: 218728 Low: 18596
    //GameObjectEntry: 218729 Low: 18616
    //GameObjectEntry: 218730 Low: 18620
    //GameObjectEntry: 218744 Low: 18609
    //GameObjectEntry: 218751 Low: 18610
    //GameObjectEntry: 218752 Low: 18611
    //GameObjectEntry: 218753 Low: 18612
    //GameObjectEntry: 218754 Low: 18613


    // seems like just cosmetic
    GO_IOTTK_PROGRESSION_S_D_TOWER  = 218976,
    GO_IOTTK_PROGRESSION_SUNWELL    = 218975,
    GO_DOODAD_ITK_FORGE_FX_WRAPPP1  = 218740,
};

Position const WrathionWP[]
{
    {7214.340f, 5285.522f, 66.05622f},
    {7207.432f, 5270.125f, 66.05622f},
    {7204.241f, 5266.851f, 66.05622f},
    {7200.241f, 5255.292f, 65.98731f}
};

Position const helpersLastJumpPos[]
{
    {7196.58f, 5233.76f, 85.5807f},
    {7175.76f, 5255.42f, 85.5464f},
    {7166.76f, 5264.76f, 85.5331f}
};

Position const cosmeticPilarPos[]
{
    {7195.710f, 5249.874f, 67.64626f},
    {7195.721f, 5250.080f, 69.25357f},
    {7195.720f, 5250.080f, 73.64575f},
    {7195.721f, 5250.080f, 80.91364f}
};

int32 const phasingTargets[]
{
    70100, 70106, 70106, 70099, 70577, 62142, 65183, 69162, 69170, 69200, 69217,
    69223, 69244, 69269, 69379, 69397, 69404, 69412, 69481, 69798, 69813, 69827,
    69833, 69835, 69923, 70042, 70070, 70074, 70283, 70556, 69156, 69411, 69509
};

enum Stages
{
    STAGE_NONE,

    STAGE_1,
    STAGE_2,
    STAGE_3,
    STAGE_4,
    STAGE_5,
    STAGE_6,
    STAGE_7,
    STAGE_8,
    STAGE_LAST
};

namespace Helper
{
    bool IsNextStageAllowed(InstanceScript* instance, uint8 stage);
}

#endif
