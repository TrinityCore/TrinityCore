/*
* Copyright 2023 AzgathCore
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

#ifndef ISLE_OF_THUNDER_H
#define ISLE_OF_THUNDER_H

const Position arcanitalLeave          = { 6440.34f, 5382.37f, 12.19f, 4.18f };
const Position vereesaAmbushPoint      = { 6500.79f, 5440.40f, 6.68f,  3.53f };
const Position arcanitalBarricadePoint = { 6326.90f, 5250.99f, 27.70f, 0.79f };
const Position arcanitalAnkiPoint      = { 6258.17f, 5179.19f, 31.09f, 0.77f };
const Position ankiSpawnPoint          = { 6249.20f, 5170.29f, 31.09f, 0.74f };
const Position jainaSummPoint          = { 6135.69f, 5057.55f, 36.89f, 4.72f };
const Position tulachekLeave           = { 6816.41f, 5912.60f, 7.49f, 3.51f  };
const Position arcanitalkreshPoint     = { 7086.95f, 6052.60f, 19.02f, 3.38f };
const Position krashSpawnPoint         = { 7117.00f, 6037.77f, 35.48f, 2.50f };
const Position lortemarSummPoint       = { 7191.20f, 6318.35f, 12.99f, 4.26f };
const Position tearDownPastIntro       = { 6515.08f, 5765.94f, 28.52f, 5.46f };
const Position tearDownElsiaIntro      = { 6534.05f, 5745.85f, 28.46f, 2.38f };
const Position elsiaExplosivePoint     = { 6598.48f, 5326.71f, 15.17f, 0.17f };
const Position elsiaSummPos            = { 6564.44f, 5346.64f, 16.65f, 6.03f };
const Position assaultBreakPos         = { 6640.50f, 5313.94f, 23.77f, 2.34f };
const Position taoshiSummPos           = { 7414.77f, 5589.00f, 81.95f, 1.97f };
const Position taoshiExplosionPos      = { 7444.32f, 5601.91f, 51.17f, 4.49f };
const Position forgeAssaultEntrancePos = { 7305.79f, 5623.65f, 31.88f, 0.06f };
const Position shanbuLeavePos          = { 7120.10f, 5158.45f, 66.12f, 2.31f };
const Position taranZhuFollowPos       = { 7046.07f, 5233.27f, 84.25f, 5.45f };
const Position taranZhuJumpPos         = { 7087.02f, 5191.83f, 66.03f, 5.46f };
const Position nalakLeavePos           = { 7111.07f, 5205.05f, 124.77f, 2.39f };
const Position taranZhuBreakPos        = { 7005.32f, 5273.96f, 84.44f, 2.31f };
const Position wrathionSummPos         = { 7216.58f, 5295.97f, 65.98f, 0.81f };
const Position forgeMasterSummonPos    = { 7212.39f, 5266.80f, 65.98f, 3.90f };
const Position almagmationSummPos      = { 7353.69f, 5176.16f, 49.58f, 0.0f };

const Position jainaPath[2] =
{
    { 5681.08f, 6221.33f, 13.13f, 3.91f },
    { 5687.19f, 6215.00f, 12.92f, 5.48f },
};

const Position flyPath[9] =
{
    { 5839.47f, 6091.02f, 52.83f, 5.91f  },
    { 5982.24f, 6061.97f, 99.76f, 6.07f  },
    { 6128.09f, 6015.83f, 113.44f, 5.98f },
    { 6359.34f, 5976.41f, 119.59f, 6.21f },
    { 6560.83f, 5955.52f, 116.90f, 5.40f },
    { 6739.16f, 5737.58f, 106.40f, 5.26f },
    { 6765.48f, 5612.03f, 106.40f, 4.82f },
    { 6642.79f, 5507.99f, 106.40f, 3.61f },
    { 6509.01f, 5494.57f, 106.40f, 3.30f },
};

const Position ambusherSpawnPos[2] =
{
    { 6461.40f, 5427.07f, 9.87f, 0.13f },
    { 6511.51f, 5408.32f, 7.82f, 1.88f },
};

const Position vereesaBarricadePath[4] =
{
    { 6455.54f, 5421.95f, 10.06f, 3.73f },
    { 6434.53f, 5373.39f, 13.06f, 4.17f },
    { 6392.78f, 5346.33f, 20.75f, 3.72f },
    { 6349.37f, 5277.57f, 24.78f, 4.11f },
};

const Position vereesaAnkiPath[4] =
{
    { 6330.36f, 5254.97f, 27.87f, 3.93f },
    { 6297.20f, 5219.48f, 25.53f, 3.95f },
    { 6290.84f, 5207.04f, 33.57f, 4.27f },
    { 6277.31f, 5194.40f, 31.00f, 3.86f },
};

const Position vereesaArcanitalPath[8] =
{
    { 6237.38f, 5190.80f, 31.08f, 2.83f },
    { 6203.68f, 5203.63f, 20.01f, 2.77f },
    { 6161.55f, 5189.22f, 3.72f,  3.47f },
    { 6134.99f, 5134.16f, -0.06f, 4.70f },
    { 6135.41f, 5109.38f, 18.76f, 4.73f },
    { 6135.39f, 5086.56f, 18.94f, 4.71f },
    { 6135.90f, 5064.05f, 37.25f, 4.71f },
    { 6135.85f, 5011.91f, 36.90f, 4.71f },
};

const Position hordeFlyPath[9] =
{
    { 6658.81f, 6345.94f, 43.87f, 4.25f },
    { 6612.40f, 6244.53f, 65.68f, 4.25f },
    { 6552.13f, 6109.93f, 91.51f, 4.21f },
    { 6440.87f, 5954.21f, 96.49f, 4.09f },
    { 6402.22f, 5770.39f, 96.49f, 4.53f },
    { 6417.33f, 5574.40f, 96.49f, 5.62f },
    { 6660.21f, 5509.23f, 96.49f, 6.27f },
    { 6818.59f, 5710.12f, 96.49f, 1.33f },
    { 6743.31f, 5825.31f, 96.49f, 2.26f },
};

const Position hordeAmbusherSpawnPos[2] =
{
    { 6798.31f, 5957.65f, 8.37f, 4.12f },
    { 6736.72f, 5949.31f, 9.95f, 4.98f },
};

const Position lorthemarPath[2] =
{
    { 6728.18f, 6476.15f, 5.77f, 4.57f },
    { 6709.01f, 6473.28f, 4.73f, 3.21f },
};

const Position elsiaBarricadePath[4] =
{
    { 6807.78f, 5996.62f, 7.46f,  1.18f },
    { 6845.03f, 6018.83f, 13.04f, 0.49f },
    { 6898.97f, 6018.94f, 8.65f,  0.20f },
    { 6935.89f, 6041.04f, 7.99f,  0.35f },
};

const Position elsiaKreshPath[4] =
{
    { 6952.61f, 6045.81f, 11.38f, 0.35f },
    { 7008.45f, 6064.46f, 12.75f, 0.25f },
    { 7027.77f, 6061.07f, 19.50f, 6.05f },
    { 7067.67f, 6043.40f, 17.61f, 5.85f },
};

const Position elsiaArcanitalPath[9] =
{
    { 7068.01f, 6064.32f, 18.94f, 1.59f },
    { 7075.44f, 6103.33f, 10.85f, 1.37f },
    { 7081.47f, 6133.32f, 7.40f,  1.42f },
    { 7085.11f, 6157.74f, 14.73f, 1.44f },
    { 7091.95f, 6192.08f, 5.57f,  1.33f },
    { 7094.65f, 6201.72f, 9.19f,  1.31f },
    { 7112.30f, 6228.39f, 12.35f, 0.97f },
    { 7137.79f, 6252.30f, 23.39f, 0.77f },
    { 7175.44f, 6288.44f, 12.47f, 0.78f },
};

const Position elsiaAlchuklaPath[7] =
{
    { 6635.47f, 5325.61f, 21.70f, 6.05f },
    { 6698.93f, 5324.37f, 27.36f, 0.19f },
    { 6785.40f, 5346.32f, 29.57f, 0.66f },
    { 6810.97f, 5375.90f, 30.98f, 1.31f },
    { 6796.05f, 5420.72f, 29.57f, 1.48f },

    { 6843.74f, 5432.98f, 30.02f, 5.86f },
    { 6860.33f, 5417.25f, 48.10f, 5.50f },
};

const Position toSkiesHordeSummPos[3] =
{
    { 7197.09f, 6300.74f, 12.42f, 3.77f }, // Lorthemar
    { 7201.90f, 6326.79f, 13.58f, 0.80f },
    { 7209.46f, 6321.62f, 12.46f, 3.94f },
};

const Position toSkiesAllianceSummPos[3] =
{
    { 6116.33f, 5033.27f, 36.89f, 6.27f }, // Jaina
    { 6110.17f, 5041.20f, 36.89f, 6.27f },
    { 6099.61f, 5037.49f, 36.89f, 2.05f },
};

const Position cycleFlyPath[10] =
{
    { 7517.01f, 5620.42f, 125.65f, 5.50f },
    { 7589.93f, 5524.07f, 130.00f, 5.36f },
    { 7600.99f, 5357.13f, 168.83f, 4.76f },
    { 7567.94f, 5272.17f, 160.57f, 3.02f },
    { 7452.15f, 5298.54f, 131.43f, 2.65f },
    { 7298.80f, 5399.39f, 104.81f, 2.55f },
    { 7200.96f, 5327.43f, 113.60f, 2.17f },
    { 7018.19f, 5436.38f, 109.70f, 2.60f },
    { 7210.52f, 5621.53f, 120.94f, 0.38f },
    { 7376.07f, 5632.81f, 111.45f, 6.23f },
};

const Position toSkiesHordePath[6] =
{
    { 7258.80f, 6368.49f, 43.81f, 0.54f },
    { 7312.50f, 6335.58f, 43.81f, 4.93f },
    { 7289.68f, 6226.59f, 46.61f, 4.49f },
    { 7274.39f, 6070.09f, 57.46f, 4.63f },
    { 7353.93f, 5882.53f, 78.40f, 5.16f },
    { 7472.40f, 5686.13f, 95.29f, 5.23f },
};

const Position toSkiesAlliancePath[8] =
{
    { 6096.95f, 5039.59f, 85.93f,  0.47f },
    { 6281.25f, 5119.90f, 97.75f,  0.40f },
    { 6460.54f, 5236.24f, 97.75f,  0.57f },
    { 6672.31f, 5357.95f, 99.88f,  0.53f },
    { 6845.09f, 5507.26f, 99.88f,  0.71f },
    { 7037.59f, 5613.48f, 99.88f,  0.48f },
    { 7319.14f, 5716.64f, 122.05f, 0.24f },
    { 7421.11f, 5678.71f, 100.76f, 5.76f },
};

const Position thunderwingBackPath[2] =
{
    { 7449.52f, 5454.58f, 220.93f, 1.00f },
    { 7445.55f, 5623.36f,  75.98f, 1.64f },
};

const Position taoshiJump[2] =
{
    { 7399.17f, 5630.15f, 73.51f, 1.55f },
    { 7427.45f, 5622.95f, 49.80f, 0.11f },
};

const Position taoshiOpenDoorPath[3] =
{
    { 7343.25f, 5621.01f, 33.18f, 2.82f },
    { 7322.62f, 5627.34f, 32.73f, 2.97f },
    { 7263.43f, 5620.60f, 35.36f, 3.14f },
};

const Position taoshiStormseaFlypath[2] =
{
    { 6816.81f, 4830.83f, 93.13f, 5.29f },
    { 6892.20f, 4879.27f, 87.70f, 0.81f },
};

const Position StormseaFlypath[4] =
{
    { 7031.16f, 5035.38f, 87.70f, 0.83f  },
    { 6890.70f, 5173.07f, 118.13f, 4.28f },
    { 6832.63f, 5049.62f, 92.93f, 4.30f  },
    { 6892.20f, 4879.27f, 87.70f, 0.81f  },
};

const Position StormseaShipFlypath[3] =
{
    { 6908.72f, 5060.09f, 140.24f, 4.62f },
    { 6862.77f, 4756.39f, 79.85f, 5.21f  },
    { 6904.03f, 4799.64f, 28.76f, 1.47f  },
};

const Position TaoshiShipPath[4] =
{
    { 6905.47f, 4821.62f, 22.23f, 2.23f },
    { 6910.01f, 4841.14f, 21.90f, 0.71f },
    { 6900.15f, 4849.55f, 21.97f, 2.40f },
    { 6887.94f, 4864.75f, 22.14f, 1.26f }, // after this - path
};

const Position TaoshiShipParabolic[3] =
{
    { 6860.39f, 4872.91f, 22.29f, 5.50f },
    { 6858.70f, 4853.37f, 22.23f, 4.79f },
    { 6868.02f, 4835.61f, 22.05f, 5.52f },
};

const Position TaoshiHoldPath[4] =
{
    { 6891.92f, 4809.56f, 22.06f, 5.48f },
    { 6894.06f, 4813.29f, 22.29f, 2.17f },
    { 6879.62f, 4827.90f,  7.41f, 2.36f },
    { 6843.39f, 4872.17f,  7.41f, 2.23f },
};

const Position TaoshiLeaveShipPath[4] =
{
    { 6878.70f, 4870.84f, 7.41f, 6.24f },
    { 6889.00f, 4866.72f, 7.41f, 0.35f },
    { 6917.83f, 4894.25f, 6.93f, 0.75f },
    { 6943.31f, 4897.56f, 7.75f, 1.57f },
};

const Position TaoshiReachGatePath_1[4] =
{
    { 6891.31f, 4948.33f, 7.68f, 2.30f  },
    { 6897.85f, 4956.81f, 11.34f, 0.91f },
    { 6903.03f, 4966.13f, 11.40f, 1.14f },
    { 6941.73f, 5024.13f, 11.39f, 0.85f },
};

const Position TaoshiReachGatePath_2[5] =
{
    { 6961.97f, 5045.78f, 17.24f, 2.02f },
    { 6950.16f, 5069.50f, 26.89f, 2.06f },
    { 6934.54f, 5119.78f, 53.18f, 1.86f },
    { 6929.31f, 5168.76f, 59.74f, 1.58f },
    { 6932.07f, 5194.49f, 66.03f, 1.46f },
};

const Position husengIntroPath[2] =
{
    { 6921.67f, 5190.71f, 66.03f, 2.35f },
    { 6942.67f, 5213.81f, 66.03f, 0.76f },
};

const Position AllianceShanbuIntro[2]
{
    { 6940.65f, 5218.09f, 66.03f, 3.97f },
    { 6945.18f, 5213.17f, 66.03f, 3.97f },
};

const Position HordeShanbuIntro[2]
{
    { 7059.84f, 5338.99f, 65.98f, 0.87f },
    { 7063.78f, 5335.42f, 65.99f, 0.76f },
};

const Position HordeShanbuPath[2] =
{
    { 7047.56f, 5318.69f, 84.51f, 0.0f },
    { 7016.78f, 5287.56f, 84.38f, 0.0f },
};

const Position AllianceShanbuPath[2] =
{
    { 6961.64f, 5232.72f, 84.62f, 0.0f },
    { 6991.15f, 5262.04f, 84.25f, 0.0f },
};

const Position TaoshiToTaranPath[4] =
{
    { 7042.27f, 5226.06f, 84.25f, 5.56f },
    { 7047.80f, 5220.34f, 82.27f, 5.51f },
    { 7063.84f, 5206.00f, 66.34f, 5.56f },
    { 7082.96f, 5192.56f, 66.03f, 5.90f },
};

const Position TaranHomePath[4] =
{
    { 7068.44f, 5210.67f, 66.44f, 2.33f },
    { 7053.58f, 5224.48f, 81.53f, 2.33f },
    { 7047.73f, 5230.67f, 84.10f, 2.33f },
    { 7015.89f, 5263.24f, 84.73f, 2.31f },
};

const Position WrathionCruciblePath[2] =
{
    { 7217.08f, 5285.11f, 65.98f, 4.51f },
    { 7204.15f, 5266.79f, 65.98f, 3.96f },
};

const Position ShadoPanForgeAssault[3] =
{
    { 7188.57f, 5242.81f, 87.39f, 0.79f }, // Defender
    { 7194.92f, 5236.73f, 85.52f, 0.76f },
    { 7182.62f, 5249.09f, 85.52f, 0.75f },
};

const Position InnerForgePath[5] =
{
    { 7253.96f, 5274.97f, 65.98f, 6.07f },
    { 7305.28f, 5223.46f, 65.32f, 5.47f },
    { 7318.33f, 5210.35f, 65.34f, 5.47f },
    { 7340.74f, 5188.51f, 49.94f, 5.47f },
    { 7359.88f, 5168.16f, 49.58f, 5.57f },
};

const Position moguAssaultSide[3] =
{
    { 7258.20f, 5270.76f, 65.98f, 2.33f },
    { 7266.54f, 5320.92f, 65.98f, 3.94f },
    { 7216.49f, 5312.57f, 65.64f, 5.46f },
};

const Position celesialsSpawnPos[2] =
{
    { 7333.14f, 5124.65f, 55.10f, 0.75f }, // blacksmith
    { 7404.89f, 5197.14f, 55.28f, 3.92f },
};

const Position anvilsPathPos[7] =
{
    { 7341.08f, 5160.44f, 49.58f, 6.22f },
    { 7348.74f, 5140.66f, 49.58f, 0.74f },
    { 7368.49f, 5132.40f, 49.58f, 1.55f },
    { 7387.89f, 5140.87f, 49.58f, 2.37f },
    { 7396.17f, 5160.38f, 49.58f, 3.06f },
    { 7388.18f, 5179.80f, 49.58f, 3.90f },
    { 7368.31f, 5187.95f, 49.58f, 4.71f },
};

enum Steps
{
    STEP_MEET_WITH_RANGER,
    STEP_SURVIVE_THE_AMBUSH,
    STEP_DESTROY_THE_BARRICADES,
    STEP_ANKI_AND_PAKUTESH,
    STEP_KILL_ARCANITAL,

    STEP_FIND_MISSED_EXPLOSIVE,
    STEP_SEND_EXPLOSIVE,
    STEP_EXPLOSIVE,
    STEP_KILL_WARGOD_ALCHUKLA,

    STEP_IN_SKY,
    STEP_INTERCEPTION,
    STEP_CURB_BEASTMASTER,
    STEP_IN_THE_MINE,
    STEP_WAS_YOURS_BECOME_MINE,
    STEP_COVER_ME,

    STEP_BLENDING_IN,
    STEP_PATH_OF_SMOKE,
    STEP_SHADOWS_IN_THE_STORM,
    STEP_WETWORK,
    STEP_KEEP_QUIET,
    STEP_LIGHT_UP_THE_NIGHT,

    STEP_BLOODY_CROSSROAD,
    STEP_KILL_THE_GUARDS,
    STEP_TO_LEI_SHEN_PALACE,
    STEP_DEFEAT_SHAN_BU,

    // Legendary
    STEP_TALK_WITH_WRATHION,
    STEP_FORGED_FROM_TRILLIUM,
    STEP_CHARGING,
    STEP_IN_FORGE,
    STEP_FILTH_FOUND,
    STEP_MANIFESTATION_OF_FILTH,

    // misc
    PLAYER_DATA,
    FACTION_DATA,
    TAOSHI_DATA,
    PHASE_DATA,
    ROLE_DATA,
};

enum Quests
{
    QUEST_THE_ASSAULT_ON_SHAOLMARA = 32644,
    QUEST_THE_ASSAULT_ON_ZEB_TULA  = 32212,
    QUEST_TEAR_DOWN_THIS_WALL_A    = 32654,
    QUEST_TEAR_DOWN_THIS_WALL_H    = 32276,
    QUEST_TO_THE_SKIES_A           = 32652,
    QUEST_TO_THE_SKIES_H           = 32277,
    QUEST_A_BOLT_IDEA_A            = 32655,
    QUEST_DECISIVE_ACTION_H        = 32278, // same like up
    QUEST_FALL_OF_SHANBU_H         = 32279,
    QUEST_FALL_OF_SHANBU_A         = 32656,
    QUEST_THE_THUNDER_FORGE        = 32593,
    QUEST_SPIRIT_OF_THE_STORM_LORD = 32594,
};

enum Actions
{
    ACTION_START_INTRO,
    ACTION_FLY_FALL,
    ACTION_SURPRISED,
    ACTION_AMBUSH_PREVENTED,
    ACTION_BARRICADE_ASSAULT,
    ACTION_ANKI_DEFEAT,
    ACTION_BEHIND_ANKI,
    ACTION_MARAKAH_DEFEATED,
    ACTION_BREAK_THE_WALL,
    ACTION_ALCHUKLA_FIND,
    ACTION_FLY_ASSAULT,
    ACTION_AMBUSH_HIM,
    ACTION_MOVE_TO,
    ACTION_LEAVE_SHIP,
    ACTION_HUSENG_COMBAT,
    ACTION_MARKED,
    ACTION_START_ASSAULT,
    ACTION_MOVE_TO_BLODY_CROSS,
    ACTION_KEEP_TO_SHANBU,
    ACTION_ATTACK_SHANBU,
    ACTION_SHANBU_DEFEATED,
    ACTION_TARAN_BLEEDED,
    ACTION_BREAK_THIS_CONFLICT,
    ACTION_FORGE_INFLUSION,
    ACTION_FORGE_FIRST_WAVE_DONE,
    ACTION_MOVE_INNER_FORGE,
    ACTION_INNER_FORGE,
    ACTION_LAUNCH_FORGE,
    ACTION_SHA_DEFEATED,
    ACTION_ALMAGMATION_INCOMING,
};

enum Creatures
{
    // Alliance
    NPC_LADY_JAINA_GUNSHIP             = 70131,
    NPC_SILVER_COVENANT_HYPPOGRYPH     = 70233,
    NPC_SILVER_COVENANT_RANGER         = 70237,
    NPC_VEERISA_HIPPOGRYPH             = 70231,
    NPC_PLAYER_HIPPOGRYPH              = 70234,
    NPC_VEREESA_WINDRUNNER             = 70041,
    NPC_ARCANITAL_MARAKAH              = 69538,
    NPC_SPIRIT_MASK                    = 69476,
    NPC_SHAOL_MARA_BEASTCALLER         = 70286,
    NPC_SHAOL_MARA_RAPTOR              = 70288,
    NPC_ZEBTULA_STONESHIELD            = 69517,
    NPC_ZANDALARI_BARRICADE_A          = 69516,
    NPC_ZEBTULA_SPEARANGER             = 69518,
    NPC_ANKI                           = 69531,
    NPC_BEASTCALLER_PAKUTESH           = 69532,
    NPC_TEARDOWN_VEREESA_WINDRUNNER    = 69949,
    NPC_TEARDOWN_JAINA_PROUDMOORE      = 70092,
    NPC_SILVER_COVENANT_ASSASSIN       = 70395,
    NPC_SILVER_COVENANT_SPELLBLADE     = 70396,
    NPC_SILVER_COVENANT_CAPTAIN        = 70397,
    NPC_SILVER_COVENANT_ARCHER         = 70213,
    NPC_LADY_JAINA_IN_SKY              = 69741,
    NPC_VEREESA_WINDRUNNED_IN_SKY      = 69744,
    NPC_KIRIN_TOR_MAGE                 = 70574,
    NPC_SILVER_COVENANT_SPELLBLADE_ST  = 67970,
    NPC_LADY_JAINA_STORMSEA            = 69616,
    NPC_SILVER_COVENANT_SPELLBLOW      = 69624,
    NPC_SHANBU_VEREESA                 = 69615,
    NPC_SHANBU_JAINA                   = 69616,
                                       
    // Horde                           
    NPC_SUNREAVER_CAPTAIN              = 70352,
    NPC_SUNREAVER_PYROMANCER           = 70351,
    NPC_LORTHEMAR_THERON               = 67990,
    NPC_SUNREAVER_BLOODHAWK_PLAYER     = 69487,
    NPC_SUNREAVER_LIEUTENANT           = 69488,
    NPC_SCOUT_CAPTAIN_ELSIA            = 69485,
    NPC_ELSIA_BLOODHAWK                = 69486,
    NPC_SUNREAVER_BLOODHAWK            = 69489,
    NPC_ARCANITAL_TULACHEK             = 69475,
    NPC_KRESH_THE_REAPER               = 69474,
    NPC_ZANDALARI_BARRICADE_H          = 69515,
    NPC_LORTEMAR_THERON_UNK            = 69478,
    NPC_DARKSEEKER_GUARDIAN            = 70253,
    NPC_SUNREAVER_MAGUS                = 67661,
    NPC_ELINA_ZARALAE                  = 69418,
    NPC_KETHIEL_SUNLANCE               = 67984,
    NPC_HALDURON_BRIGHTWING            = 70520,
    NPC_HIGH_MAGISTER_ROMMAT           = 67989,
    NPC_HIGH_MAGE_ETHAS                = 67660,
    NPC_LANESH_THE_STEALWEAVER         = 69259,
    NPC_AMALIA_PENSHIR                 = 69371,
    NPC_DEZKO                          = 69425,
    NPC_MAGISTRIX_SAIA                 = 69433,
    NPC_RANGER_SHALAN                  = 69252,
    NPC_RISHEL                         = 69389,
    NPC_CAPTAIN_AERTHAS                = 67983,
    NPC_AMARIEL_SUNSWORN               = 67674,
    NPC_GIRANA_THE_BLOODED             = 67673,
    NPC_MAGISTER_HATHOREL              = 67663,
    NPC_HIGH_ARCANIST_SAVOR            = 67662,
    NPC_SUNREAVER_GOLEM                = 67930,
    NPC_CARGO_HAULER                   = 69659,
    NPC_ELYNARA                        = 67586,
    NPC_SILVERMOON_RUNESEEKER          = 67604,
    NPC_HARLAN_WHITEDAWN               = 69447,
    NPC_TEARDOWN_SUNREAVER_CAPTAIN     = 70046,
    NPC_TEARDOWN_SUNREAVER_PYRO        = 70044,
    NPC_TEARDOWN_SUNREAVER_SPELLBLADE  = 69994,
    NPC_TEARDOWN_SUNREAVER_ASSASSIN    = 70350,
    NPC_TEARDOWN_SUNREAVER_ASSASSIN_2  = 70045,
    NPC_TEARDOWN_LORTHEMAR_THERONE     = 70055,
    NPC_TEARDOWN_SCOUT_CAPTAIN_ELSIA   = 69565,
    NPC_TEARDOWN_ZANDALARI_STONESHIELD = 69865,
    NPC_WARGOD_ALCHUKLA                = 69755,
    NPC_LORTHEMAR_THRON_IN_SKY         = 69481,
    NPC_SCOUT_CAPTAIN_ELSIA_IN_SKY     = 69745,
    NPC_SUNREAVER_RANGER_FORGE         = 70122,
    NPC_SUNREAVER_MAGISTER_FORGE       = 70573,
    NPC_LORTHEMAR_STORMSEA             = 69617,
    NPC_SUNREAVER_RANGER               = 69625,
    NPC_SHANBU_ELSIA                   = 69620,
    NPC_SHANBU_LORTHEMAR               = 69617,
    NPC_SHANBU_AETHAS                  = 69619,

    // Misc
    NPC_ZEBTULA_GENERIC_BUNNY      = 69508,
    NPC_ARCANITAL_TULACHEK_BUNNY   = 69475,
    NPC_ZEBTULA_BARRIER_BUNNY      = 69571,
    NPC_BUNNY_ZTO                  = 55370,
    NPC_PURPLE_HAWKSTRIDER         = 20217,
    NPC_HEAVY_EXPLOSIVES           = 69606,
    NPC_SCENARIO_TEAR_DOWN_BUNNY   = 69623,
    NPC_TOTALY_GENERIC_BUNNY       = 28960,
    NPC_SLAVEMASTER_SHIAXU         = 69923,
    NPC_SHANZE_ELECTROCUTIONER     = 69216,
    NPC_MANFRED                    = 69217,
    NPC_LIGHTNING_STRIKE_DUMMY     = 69192,
    NPC_BEASTMASTER_HORAKI         = 69559,
    NPC_SHANZE_SLAVER              = 67466,
    NPC_THUNDERWING                = 69509,
    NPC_ZANDALARI_BEASTCALLER      = 69521,
    NPC_ZANDALARI_PTERRORWING      = 69511,
    NPC_TAOSHI                     = 69810,
    NPC_TAOSHI_CAVE                = 69917,
    NPC_SENTRY_LASER_BUNNY         = 70078,
    NPC_ZANDALARI_STONE_SHIELD_3   = 69527,
    NPC_SENTRY_TOTEM               = 69505,
    NPC_TAOSHI_STORMSEA            = 69457,
    NPC_TAOSHI_STORMSEA_SHIP       = 69544,
    NPC_SHAN_BU_STORMSEA           = 69743,
    NPC_HUSENG_THE_GATEKEEPER      = 69483,
    NPC_CAPTAIN_HALUKAL            = 69482,
    NPC_ZANDALARI_WINGRIDER        = 69463,
    NPC_ZANDALARI_CONSCRIPT        = 70118,
    NPC_ZANDALARI_SPIRIT_TWISTER   = 70121,
    NPC_ZANDALARI_BEAST_HANDLER    = 70119,
    NPC_VETERAN_WINGRIDER          = 69552,
    NPC_DRUNKEN_WINGRIDER          = 70566,
    NPC_THUNDERWING_STORMSEA       = 69458,
    NPC_CHAINS                     = 70581,
    NPC_ZANDALARI_GOLEM            = 70511,
    NPC_DEACTIVATED_ACCESS_GEN     = 70615,
    NPC_GATE_BUNNY_CREDIT          = 70211,
    NPC_SHANBU_TARAN_ZHU           = 69501,
    NPC_YALIAS_TIGER               = 69811,
    NPC_YALIAS_SAGEWHISPER         = 69618,
    NPC_SHANBU_TAOSHI              = 69621,
    NPC_SHAN_BU                    = 69530,
    NPC_PALACE_GATEKEEPER          = 69510,
    NPC_QUILEN_GUARDIAN            = 69506,
    NPC_SHANZE_ELECTROCUTIONER_2   = 69525,
    NPC_NALAK                      = 69562,
    NPC_SHANBU_CREDIT              = 69534,
    NPC_WRATHION                   = 70100,
    NPC_SHADO_PAN_DEFENDER         = 70099,
    NPC_SHADO_PAN_WARRIOR          = 70106,
    NPC_SHANZE_WARRIOR             = 69833,
    NPC_SHANZE_PYROMANCER          = 69824,
    NPC_FORGEMASTER_VULKON         = 70074,
    NPC_THUNDER_FORGE              = 70061,
    NPC_THUNDER_FORGE_2            = 70283,
    NPC_CELESTIAL_DEFENDER         = 69837,
    NPC_CELESTIAL_BLACKSMITH       = 69828,
    NPC_SHA_ALMAGAMATION           = 70228,
    NPC_SHA_FIEND                  = 70039,
    NPC_SHA_BEAST                  = 68030,
    NPC_COMPLETE_SCENARIO_CREDIT   = 70094, // thunder forge
    NPC_UNLOCK_FORGE_CREDIT        = 70093,
    NPC_UNLOCK_COURTYARD_CREDIT    = 70456,
};

enum Scenes
{
    SCENE_ALCHUKLA_WALL_DESTROY     = 167,
    SCENE_TEAR_DOWN_THIS_WALL_INTRO = 169,
};

enum ScenarioTypes
{
    SCENARIO_ATTACK_ON_CAMP, // zebtula | shaolmara
    SCENARIO_TEAR_DOWN_THIS_WALL, // both, 2td stage
    SCENARIO_IN_SKY, // both, 3td stage
    SCENARIO_STORMSEA_LANDING, // both 4td stage
    SCENARIO_FALL_OF_SHANBU, // both, 5td stage
    SCENARIO_THUNDER_FORGE, // Legendary Quest
};

enum Gameobjects
{
    GO_SUNREAVER_PORTAL            = 218460,
    GO_SUNREAVER_LOW_PORTAL        = 218486,
    GO_TEAR_DOWN_DESTRUCT_WALL     = 218538,
    GO_HEAVE_EXPLOSIVES            = 218196,
    GO_HEAVY_EXPLOSIVES_EXPLOSIVE  = 218377,
    GO_PORTAL_TO_ISLE_OF_THUNDER   = 218462,
    GO_CAVEIN                      = 218544,
    GO_MOGU_DOOR                   = 218198,
    GO_HUSENG_COLLISION            = 210097,
    GO_MOGU_GATES_STORMSEA         = 218697, // also right door for alliance
    GO_MOGU_GATES_HORDE            = 218698,
    GO_MOGU_GATES_CENTER           = 218728,
    GO_ACCESS_GENERATOR            = 219094,
    GO_SPIRIT_WALL                 = 218626,
    GO_MOGU_CRUCIBLE               = 218910,
    GO_THUNDER_FORGE_DOOR          = 218727,
    GO_THUNDER_ANVIL               = 218701,
};

enum IsleOfThunderLFGDungeons
{
    // Alliance
    LADY_JAINA_GOSSIP_MENU = 15516,

    LFG_DUNGEON_ASSAULT_ON_SHAOLMARA = 617,
    LFG_DUNGEON_BREAK_THIS_WALL_A = 602,
    LFG_DUNGEON_TO_SKIES_A = 618,
    LFG_DUNGEON_STORMSEA_LANDING = 603,
    LFG_DUNGEON_FALL_OF_SHANBU_A = 621,

    // Horde
    LOR_TEMAR_GOSSIP_MENU = 15406,

    LFG_DUNGEON_ASSAULT_ON_ZEB_TULA = 604,
    LFG_DUNGEON_BREAK_THIS_WALL_H = 608,
    LFG_DUNGEON_TO_SKIES_H = 606,
    LFG_DUNGEON_FALL_OF_SHANBU_H = 607,
    LFG_THUNDER_FORGE = 615,
};

enum Scenarios
{
    SCENARIO_ID_SHAOLMARA          = 212,
    SCENARIO_ID_ZEBTULA            = 206,
    SCENARIO_ID_IN_THE_SKY         = 207,
    SCENARIO_ID_STORMSEA_LANDING   = 205,
    SCENARIO_ID_FALL_OF_SHANBU     = 208,
    SCENARIO_ID_TEAR_DOWN_ALLIANCE = 204,
    SCENARIO_ID_TEAR_DOWN_HORDE    = 209,
    SCENARIO_ID_THUNDER_FORGE      = 211,
};

enum Criteries
{
    CRITERIA_TREE_ID_SHAOLMARA_1        = 31925,
    CRITERIA_TREE_ID_SHAOLMARA_2        = 31928,
    CRITERIA_TREE_ID_SHAOLMARA_3        = 31930,
    CRITERIA_TREE_ID_SHAOLMARA_4        = 31932,
    CRITERIA_TREE_ID_SHAOLMARA_5        = 31934,
    CRITERIA_TREE_ID_ZEBTULA_1          = 31670,
    CRITERIA_TREE_ID_ZEBTULA_2          = 31672,
    CRITERIA_TREE_ID_ZEBTULA_3          = 31674,
    CRITERIA_TREE_ID_ZEBTULA_4          = 31676,
    CRITERIA_TREE_ID_ZEBTULA_5          = 31679,
    CRITERIA_TREE_ID_TEAR_DOWN_A_1      = 31833,
    CRITERIA_TREE_ID_TEAR_DOWN_A_2      = 31835,
    CRITERIA_TREE_ID_TEAR_DOWN_A_3      = 31839,
    CRITERIA_TREE_ID_TEAR_DOWN_A_4      = 31837,
    CRITERIA_TREE_ID_TEAR_DOWN_H_1      = 31746,
    CRITERIA_TREE_ID_TEAR_DOWN_H_2      = 31765,
    CRITERIA_TREE_ID_TEAR_DOWN_H_3      = 31768,
    CRITERIA_TREE_ID_TEAR_DOWN_H_4      = 31804,
    CRITERIA_TREE_ID_iN_THE_SKY_1       = 31693,
    CRITERIA_TREE_ID_iN_THE_SKY_2       = 31695,
    CRITERIA_TREE_ID_iN_THE_SKY_3       = 31697,
    CRITERIA_TREE_ID_iN_THE_SKY_4       = 31830,
    CRITERIA_TREE_ID_iN_THE_SKY_5       = 31841,
    CRITERIA_TREE_ID_iN_THE_SKY_6       = 31703,
    CRITERIA_TREE_ID_STORMSEA_LANDING_1 = 31682,
    CRITERIA_TREE_ID_STORMSEA_LANDING_2 = 31684,
    CRITERIA_TREE_ID_STORMSEA_LANDING_3 = 31686,
    CRITERIA_TREE_ID_STORMSEA_LANDING_4 = 31806,
    CRITERIA_TREE_ID_STORMSEA_LANDING_5 = 31689,
    CRITERIA_TREE_ID_STORMSEA_LANDING_6 = 31691,
    CRITERIA_TREE_ID_STORMSEA_LANDING_7 = 31937,
    CRITERIA_TREE_ID_FALL_OF_SHANBU_1   = 31844,
    CRITERIA_TREE_ID_FALL_OF_SHANBU_2   = 31710,
    CRITERIA_TREE_ID_FALL_OF_SHANBU_3   = 31718,
    CRITERIA_TREE_ID_FALL_OF_SHANBU_4   = 31723,
    CRITERIA_TREE_ID_THUNDER_FORGE_1    = 31856,
    CRITERIA_TREE_ID_THUNDER_FORGE_2    = 31923,
    CRITERIA_TREE_ID_THUNDER_FORGE_3    = 31810,
    CRITERIA_TREE_ID_THUNDER_FORGE_4    = 32142,
    CRITERIA_TREE_ID_THUNDER_FORGE_5    = 31812,
    CRITERIA_TREE_ID_THUNDER_FORGE_6    = 31814,
};

const std::map<uint32, uint32> invAssaulterType =
{
    { NPC_TEARDOWN_SUNREAVER_CAPTAIN,    NPC_SILVER_COVENANT_CAPTAIN    },
    { NPC_TEARDOWN_SUNREAVER_PYRO,       NPC_SILVER_COVENANT_ARCHER     },
    { NPC_TEARDOWN_SUNREAVER_SPELLBLADE, NPC_SILVER_COVENANT_SPELLBLADE },
    { NPC_TEARDOWN_SUNREAVER_ASSASSIN,   NPC_SILVER_COVENANT_ASSASSIN   },
    { NPC_TEARDOWN_SUNREAVER_ASSASSIN_2, NPC_SILVER_COVENANT_ASSASSIN   },
};

const std::map<uint32, uint32> invForgeType =
{
    { NPC_LORTHEMAR_THRON_IN_SKY,   NPC_LADY_JAINA_IN_SKY },
    { NPC_SUNREAVER_RANGER_FORGE,   NPC_SILVER_COVENANT_RANGER },
    { NPC_SUNREAVER_MAGISTER_FORGE, NPC_KIRIN_TOR_MAGE },
};

const std::vector<uint32> tempShanbuCreatures =
{
    NPC_SHANBU_ELSIA,
    NPC_SHANBU_LORTHEMAR,
    NPC_SHANBU_JAINA,
    NPC_SHANBU_VEREESA,
};

#endif