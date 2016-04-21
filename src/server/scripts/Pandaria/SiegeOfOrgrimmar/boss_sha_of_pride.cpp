
#include "GameObjectAI.h"
#include "siege_of_orgrimmar.h"

/*
#include "siege_of_orgrimmar.h"
#include "MoveSplineInit.h"
/*
General Information: (Icy-veins.com):

1.1. Health Values

Difficulty	Sha of Pride	Manifestations of Pride	Reflections	Corrupted Fragment
10-man	425M	1.7M	2.4M	Heroic-only
10-man Heroic	660M	4.40M	2.75M	4.73
25-man	1.2B	4M	5.6M	Heroic-only
25-man Heroic	1.85B	5.6M	7.7M	4.7M
LFR	???M	???

1.2. Enrage Timer
We do not know if this fight has a hard enrage timer. When the Sha of Pride reaches 30% health, the raid will constantly gain 5 Pride every 10 seconds, meaning that you will have about 200 seconds to kill the boss from that moment.
*/

/*
SQL:

INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529749, 213251, 1136, 6738, 6738, 8, 65535, 1459.18, 861.013, 248.993, 4.69923, 0, 0, 0.711744, -0.702439, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529834, 213251, 1136, 6738, 6738, 8, 65535, 1459.18, 861.013, 248.993, 4.69923, 0, 0, 0.711744, -0.702439, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529748, 210171, 1136, 6738, 6738, 32, 1, 1281.03, 1041.68, 434.87, 3.09378, 0, 0, 0.999714, 0.0239024, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529788, 221446, 1136, 0, 0, 8, 65535, 762.313, 1046.56, 357.151, 1.75204, 0, 0, 0.768196, 0.640214, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529755, 188488, 1136, 6738, 6738, 8, 65535, 1283.8, 1043.54, 436.246, 0.0379198, 0, 0, 0.0189588, 0.99982, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529747, 210171, 1136, 6738, 6738, 32, 1, 1281.36, 1036.23, 434.868, 0.0460982, 0, 0, 0.0230471, 0.999734, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529833, 221611, 1136, 0, 0, 8, 65535, 1214.21, 984.966, 417.877, 1.61004, 0, 0, 0.720846, 0.693096, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529835, 221446, 1136, 0, 0, 8, 65535, 762.313, 1046.56, 357.151, 1.75204, 0, 0, 0.768196, 0.640214, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529836, 188488, 1136, 6738, 6738, 8, 65535, 1283.8, 1043.54, 436.246, 0.0379198, 0, 0, 0.0189588, 0.99982, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529837, 221760, 1136, 0, 0, 8, 65535, 723.039, 1129.09, 354.612, 0.15709, 0, 0, 0.0784644, 0.996917, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529838, 222681, 1136, 6738, 6738, 8, 65535, 687.826, 1100.18, 356.072, 3.32319, 0, 0, 0.995881, -0.0906735, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529839, 222681, 1136, 6738, 6738, 8, 65535, 723.069, 1128.54, 356.073, 0.622188, 0, 0, 0.3061, 0.951999, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529840, 221751, 1136, 0, 0, 8, 65535, 731.979, 1088.21, 354.612, 1.697, 0, 0, 0.750289, 0.66111, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529841, 221758, 1136, 0, 0, 8, 65535, 764.376, 1137.69, 354.613, 4.84044, 0, 0, 0.660417, -0.750899, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529842, 222681, 1136, 6738, 6738, 8, 65535, 772.502, 1096.17, 356.072, 0.41078, 0, 0, 0.203949, 0.978982, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529843, 221677, 1136, 0, 0, 8, 65535, 772.832, 1096.46, 353.718, 4.0541, 0, 0, 0.89771, -0.440586, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529844, 221678, 1136, 0, 0, 8, 65535, 722.446, 1128.39, 353.325, 1.19935, 0, 0, 0.564374, 0.825519, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529845, 183957, 1136, 6738, 6738, 8, 65535, 723.545, 1126.77, 356.992, 1.41031, 0, 0, 0.648152, 0.761511, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529846, 222681, 1136, 6738, 6738, 8, 65535, 695.358, 1144.19, 356.072, 2.65858, 0, 0, 0.970978, 0.239168, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529847, 221750, 1136, 0, 0, 8, 65535, 772.917, 1096.36, 354.613, 3.15393, 0, 0, 0.999981, -0.00616861, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529848, 221676, 1136, 0, 0, 8, 65535, 764.071, 1137.55, 353.717, 1.22768, 0, 0, 0.576011, 0.817442, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529849, 221678, 1136, 0, 0, 8, 65535, 731.574, 1087.69, 353.343, 0.824668, 0, 0, 0.400749, 0.916188, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529850, 222681, 1136, 6738, 6738, 8, 65535, 809.212, 1125.97, 356.072, 0.304753, 0, 0, 0.151787, 0.988413, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529851, 222681, 1136, 6738, 6738, 8, 65535, 731.317, 1087.67, 356.073, 1.31006, 0, 0, 0.609183, 0.793029, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529852, 221757, 1136, 0, 0, 8, 65535, 764.376, 1137.69, 354.613, 0.574437, 0, 0, 0.283286, 0.959036, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529853, 221759, 1136, 0, 0, 8, 65535, 764.376, 1137.69, 354.613, 2.80644, 0, 0, 0.985992, 0.166794, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529854, 221752, 1136, 0, 0, 8, 65535, 731.979, 1088.21, 354.612, 3.64956, 0, 0, 0.967919, -0.251262, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529855, 221761, 1136, 0, 0, 8, 65535, 723.039, 1129.09, 354.612, 2.18659, 0, 0, 0.888146, 0.459561, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529856, 222681, 1136, 6738, 6738, 8, 65535, 735.192, 1173.21, 356.072, 1.7335, 0, 0, 0.76223, 0.647306, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529857, 221756, 1136, 0, 0, 8, 65535, 723.039, 1129.09, 354.612, 4.36578, 0, 0, 0.818448, -0.57458, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529858, 221753, 1136, 0, 0, 8, 65535, 731.979, 1088.21, 354.612, 5.97543, 0, 0, 0.153272, -0.988184, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529859, 222681, 1136, 6738, 6738, 8, 65535, 763.404, 1137.97, 356.073, 5.75988, 0, 0, 0.258677, -0.965964, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529860, 221754, 1136, 0, 0, 8, 65535, 772.917, 1096.36, 354.613, 5.19693, 0, 0, 0.516816, -0.856096, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529861, 221755, 1136, 0, 0, 8, 65535, 772.917, 1096.36, 354.613, 1.02543, 0, 0, 0.490545, 0.871416, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529862, 211363, 1136, 6738, 6738, 8, 65535, 723.545, 1126.77, 356.992, 1.41031, 0, 0, 0.648152, 0.761511, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529863, 188488, 1136, 6738, 6738, 32, 65535, 1281.3, 1046.46, 434.874, 3.14016, 0, 0, 1, 0.000718669, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529864, 164839, 1136, 6738, 6738, 8, 65535, 723.545, 1126.77, 356.992, 0.829809, 0, 0, 0.403103, 0.915155, 300, 0, 1, 0, NULL, 0);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`, `protect_anti_doublet`, `scale`) VALUES (529865, 183957, 1136, 6738, 6738, 8, 65535, 724.366, 1131.84, 356.072, 6.04649, 0, 0, 0.118069, -0.993005, 300, 0, 1, 0, NULL, 0);
*/

enum Spells
{
    SPELL_AURA_OF_PRIDE_AURA = 146817,
    SPELL_PRIDE_METER = 144343,
    SPELL_GIFT_OF_TITAN = 144359,
    SPELL_POWER_OF_THE_TITANS = 144364,
    SPELL_SWELLING_PRIDE = 144400,
    SPELL_BANISHMENT = 145215,
    SPELL_BURSTING_PRIDE = 144910,
    SPELL_PROJECTION_PROJECTILE = 145066,
    SPELL_PROJECTION_DUMMY = 144952,
    SPELL_PROJECTION_DAMAGE = 145320,
    SPELL_PROJECTION_BLUE = 145526,
    SPELL_PROJECTION_WARNING = 146822,
    SPELL_CHARMED_OVERCOME = 144863,
    SPELL_OVERCOME_DAMAGE = 144843,
    SPELL_MARK_OF_ARROGANCE = 144351,
    SPELL_WOUNDED_PRIDE = 144358,
    SPELL_MANIFESTATION_VISUAL = 144778,
    SPELL_MOCKINGB_LAST = 144379,
    SPELL_LAST_WORD = 144370,
    SPELL_SPELL_REFLECTION_VISUAL_POOL = 144784,
    SPELL_SPELL_REFLECTION_VISUAL_SQUIRT = 144788,
    SPELL_CORRUPTED_PRISON_DOT = 144574,
    SPELL_CORRUPTED_PRISON_EXPLOSION = 144615,
    SPELL_REACHING_ATTACK = 144774,
    SPELL_UNLEASHED_01 = 146173,
    SPELL_UNLEASHED_02 = 146174,
    SPELL_FINAL_GIFT = 144854,

    /// Heroic
    SPELL_SHA_OF_PRIDE_DAMAGE = 147183,
    SPELL_SHA_OF_PRIDE_BOLT = 147391,

    SPELL_BANISHMENT_DEBUFF = 145215,
    SPELL_BANISHMENT_DOT_ENRAGE = 145684,
    SPELL_BANISHMENT_RED_VISUAL = 148705,

    SPELL_ORB_OF_LIGHT_VISUAL = 145299,
    SPELL_ORB_OF_LIGHT_HEAL = 145345,
};

enum Events
{
    EVENT_GIFT_OF_THE_TITANS = 1,
    EVENT_POWER_OF_TITANS,
    EVENT_SWELLING_PRIDE,
    EVENT_BURSTING_PRIDE,
    EVENT_AURA_OF_PRIDE,
    EVENT_OVERCOME,
    EVENT_MARKOF_ARROGANCE,
    EVENT_WOUNDED_PRIDE,
    EVENT_MANIFESTATION_OF_PRIDE,
    EVENT_MOCKING_BLAST,
    EVENT_LAST_WORD,
    EVENT_SELF_REFLECTION,
    EVENT_CORRUPTION_PRISON,
    EVENT_REACHING_ATTACK,
    EVENT_UNLEASHED,
    EVENT_CHECK_ENERGY,

    EVENT_NORUSHEN_GIFT_OF_THE_TITANS,
    EVENT_FINAL_GIFT,
    EVENT_ENRAGE,

    // RP
    EVENT_01,
    EVENT_02,
    EVENT_03,
    EVENT_04,
    EVENT_05,
    EVENT_06,
};

enum Actions
{
    ACTION_UNLEAHSED = 1,
    ACTION_RELEASE = 2,
    ACTION_SWITCH01 = 3,
    ACTION_SWITCH02 = 4,
    ACTION_SWITCH03 = 5,
    ACTION_RESET = 6,
    ACTION_COMBAT = 7,
    ACTION_FINISH = 8,
};

enum Creatures
{
    CREATURE_MANIFESTATION_OF_PRIDE = 71946,
    CREATURE_PRISON_TRIGGER = 324245, // CUSTOM
    CREATURE_REFLECTION = 72172,
    CREATURE_PROJECTION = 432425,
    CREATURE_ETHEREAL_CORRUPTION = 73972,
};

enum Talks
{
    TALK_AGGRO = 1,          // Haha.. so.. Foolish.
    TAL_DEATH,               // Arghhh...
    TALK_INTRO,              // Come face me, give in to your pride.. show me your greatness!
    TALK_SAY01,              // You're weak..
    TALK_SAY02,              // That one is unworthy of your group.
    TALK_SAY03,              // Blame your companions.
    TALK_SPELL01,            // You're better then your companions
    TALK_SPELL02,            // Your arrogance compels you!
    TALK_SPELL03,            // Succumb.. to your PRIDE!
    TALK_SPELL04,            // Your arrogance.. feeds me!
    TALK_SPELL05,            // You should bow to no King.. or Warchief..

    TALK_EVENT01,            // You've let your pride clowd your version, titan.. puppet. YOU CAN NEVER CONTAIN ME!
    TALK_NORUSHEN_EVENT01,   // The corruption is amplifying, the fragments must be purged before it becomes to great!
    TALK_NORUSHEN_EVENT02,   // It did not matter.. it comes.. steal your hearts and prepare your souls.
    TALK_NORUSHEN_ABILITY01, // Be humble!
    TALK_NORUSHEN_ABILITY02, // Free yourself of arrogance!
    TALK_NORUSHEN_DEATH      // You.. must.. contain.. it.
};

enum eShaOfPrideSwellingCases
{
    LOW = 1,
    MEDIUM,
    HARD,
    FATAL,
    CHAOS,
};

void ModifyPride(Unit* me,uint32 p_BaseValue, ObjectGuid playerGuid)
{
    if (playerGuid.IsEmpty())
        return;

    if (Player* l_Object = ObjectAccessor::GetPlayer(*me, playerGuid))
    {
        if (l_Object->HasAura(Spells::SPELL_GIFT_OF_TITAN))
            return;

        uint32 power = l_Object->GetPower(Powers(POWER_ALTERNATE_POWER));

        l_Object->SetPower(Powers(POWER_ALTERNATE_POWER), power + p_BaseValue);
    }
}

int32 CheckForPrideValue(Player* player)
{
    uint32 auraBasePoint = player->GetPower(POWER_ALTERNATE_POWER);

    if (auraBasePoint > 0 && auraBasePoint < 24)
        return eShaOfPrideSwellingCases::LOW;

    else if (auraBasePoint > 25 && auraBasePoint < 49)
        return eShaOfPrideSwellingCases::MEDIUM;

    else if (auraBasePoint > 50 && auraBasePoint < 74)
        return eShaOfPrideSwellingCases::HARD;

    else if (auraBasePoint > 75 && auraBasePoint < 98)
        return eShaOfPrideSwellingCases::FATAL;

    else if (auraBasePoint > 99)
        return eShaOfPrideSwellingCases::CHAOS;

    return 0;
}

static void DespawnCreaturesInArea(uint32 entry, WorldObject* object)
{
    std::list<Creature*> creatures;
    GetCreatureListWithEntryInGrid(creatures, object, entry, 300.0f);
    if (creatures.empty())
        return;

    for (std::list<Creature*>::iterator iter = creatures.begin(); iter != creatures.end(); ++iter)
        (*iter)->DespawnOrUnsummon();
}

Position l_PositionManifestationOfPride[2] =
{
    { 734.903f, 1175.487f, 356.078f, 4.878463f },
    { 684.109f, 1099.600f, 356.093f, 0.108021f },
};

Position l_PositionCircleA = { 731.222f, 1087.770f, 356.072f, 0.838f };
Position l_PositionCircleB = { 773.229f, 1095.722f, 356.072f, 1.843f };
Position l_PositionCircleC = { 765.093f, 1137.772f, 356.072f, 3.380f };
Position l_PositionCircleD = { 723.024f, 1129.941f, 356.072f, 4.732f };

#define HostileFaction 16
#define FriendlyFaction 35
#define DISPLAY_NONE 11686
#define PRIDE_DISPLAY 49098

class sha_of_pride_summon_reflection : public BasicEvent
{
public:
    explicit sha_of_pride_summon_reflection(Unit* unit, int value, Position position) : obj(unit), modifier(value), pos(position)
    {
    }

    bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
    {
        if (obj)
        {
            if (InstanceScript* l_Instance = obj->GetInstanceScript())
            {
                switch (modifier)
                {
                case 0:
                    l_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_SPELL_REFLECTION_VISUAL_POOL);

                    if (Creature* l_Reflection = obj->SummonCreature(Creatures::CREATURE_REFLECTION, pos, TEMPSUMMON_MANUAL_DESPAWN))
                        l_Reflection->CastSpell(l_Reflection, Spells::SPELL_SPELL_REFLECTION_VISUAL_SQUIRT);
                    break;
                }
            }
        }
        return true;
    }
private:
    Creature* storm;
    Unit* obj;
    int modifier;
    Position pos;
    int Event;
};

class sha_of_pride_register_guid_prisons : public BasicEvent
{
public:
    explicit sha_of_pride_register_guid_prisons(Unit* unit, int value) : obj(unit), modifier(value)
    {
    }

    bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
    {
        if (obj && obj->IsInWorld())
        {
            if (InstanceScript* l_Instance = obj->GetInstanceScript())
            {
                switch (modifier)
                {
                case 0:
                    // Handle Prison in delay so player won't get stuck in port
                    obj->CastSpell(obj, Spells::SPELL_CORRUPTED_PRISON_DOT);

                    // Guid passing
                    if (Creature * l_NearestController = obj->FindNearestCreature(CREATURE_PRISON_TRIGGER, 6.0f, true))
                    {
                        if (l_NearestController->GetAI())
                            l_NearestController->GetAI()->SetGUID(obj->GetGUID());
                    }

                    break;
                }
            }
        }
        return true;
    }
private:
    Creature* storm;
    Unit* obj;
    int modifier;
    int Event;
};

class sha_of_pride_emerge : public BasicEvent
{
public:
    explicit sha_of_pride_emerge(Unit* unit, int value) : obj(unit), modifier(value)
    {
    }

    bool Execute(uint64 /*currTime*/, uint32 /*diff*/)
    {
        if (obj)
        {
            if (InstanceScript* l_Instance = obj->GetInstanceScript())
            {
                switch (modifier)
                {
                case 0:
                    // Guid passing
                    if (Creature * l_Pride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                    {
                        l_Pride->SetDisplayId(PRIDE_DISPLAY);
                        l_Pride->RemoveFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_PC);
                    }

                    break;
                }
            }
        }
        return true;
    }
private:
    Creature* storm;
    Unit* obj;
    int modifier;
    int Event;
};

class CheckForPrisoner
{
public:
    CheckForPrisoner() {}

    bool operator()(WorldObject* object)
    {
        if (object->ToPlayer()->HasAura(SPELL_CORRUPTED_PRISON_DOT))
            return true;
        else
            return false;
    }
};

class boss_sha_of_pride : public CreatureScript
{
public:
    boss_sha_of_pride() : CreatureScript("boss_sha_of_pride") { }

    struct boss_sha_of_prideAI : public BossAI
    {
        boss_sha_of_prideAI(Creature* p_Creature) : BossAI(p_Creature, eData::DATA_SHA_OF_PRIDE)
        {
            m_Instance = p_Creature->GetInstanceScript();
            m_Intro = false;

            me->SetDisplayId(DISPLAY_NONE);
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_IMMUNE_TO_PC);
        }

        InstanceScript* m_Instance;
        bool m_Intro;
        bool m_ReachAttack;
        bool m_Unleashed;
        uint32 m_ReflectionCounter;
        uint32 m_PrisonCounter;

        void Reset() override
        {
            _Reset();
            events.Reset();

            m_ReachAttack = true;
            m_Unleashed = false;

            m_ReflectionCounter = 0;
            m_PrisonCounter = 0;

            me->SetPower(POWER_ENERGY, 0);
            me->SetInt32Value(UNIT_FIELD_POWER, 0);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetInt32Value(UNIT_FIELD_MAXPOWER, 100);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->setFaction(HostileFaction);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who && who->IsInWorld() && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 60.0f) && !m_Intro)
            {
                m_Intro = true;
                Talk(Talks::TALK_INTRO);

                me->CastSpell(me, 145144);
                me->m_Events.AddEvent(new sha_of_pride_emerge(me, 0), me->m_Events.CalculateTime(10000));
            }
        }

        void JustReachedHome() override
        {
            _JustReachedHome();
            summons.DespawnAll();

            if (m_Instance != nullptr)
            {
                if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN)))
                {
                    if (l_Norushen->GetAI())
                        l_Norushen->GetAI()->DoAction(Actions::ACTION_RELEASE);
                }

                DespawnCreaturesInArea(72172, me); // REFLECTION
                m_Instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);;
                m_Instance->SetBossState(eData::DATA_SHA_OF_PRIDE, FAIL);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_PRIDE_METER);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_AURA_OF_PRIDE_AURA);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_OVERCOME_DAMAGE);
                m_Instance->DoRemoveAurasDueToSpellOnPlayers(Spells::SPELL_CORRUPTED_PRISON_DOT);
            }


            std::list<Player*> l_Playerlists;
            me->GetPlayerListInGrid(l_Playerlists, 300.0f);

            if (l_Playerlists.empty())
                return;

            for (auto itr : l_Playerlists)
            {
                itr->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

                itr->RemoveCharmedBy(me);
            }

            // Handle Switcher Reset
            std::list<Creature*> listLockTriggers;
            me->GetCreatureListWithEntryInGrid(listLockTriggers, CREATURE_PRISON_TRIGGER_SWITCHERS, 200.0f);

            if (listLockTriggers.empty())
                return;

            for (auto itr : listLockTriggers)
            {
                if (itr->GetAI())
                    itr->GetAI()->DoAction(ACTION_FINISH);
            }
        }

        void KilledUnit(Unit* who) override
        {
            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                switch (urand(0, 2))
                {
                    case 0:
                        Talk(Talks::TALK_SAY01);
                        break;
                    case 1:
                        Talk(Talks::TALK_SAY02);
                        break;
                    case 2:
                        Talk(Talks::TALK_SAY03);
                        break;
                }
            }
        }

        void EnterCombat(Unit* attacker) override
        {
            Talk(Talks::TALK_AGGRO);

            events.ScheduleEvent(Events::EVENT_CHECK_ENERGY, 1 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_WOUNDED_PRIDE, 30 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_SELF_REFLECTION, 45 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_MARKOF_ARROGANCE, 25 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_CORRUPTION_PRISON, 45 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_MANIFESTATION_OF_PRIDE, 60 * TimeConstants::IN_MILLISECONDS);

            if (m_Instance != nullptr)
            {
                if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN)))
                {
                    if (l_Norushen->GetAI())
                        l_Norushen->GetAI()->DoAction(Actions::ACTION_COMBAT);
                }
            }

            std::list<Player*> l_Playerlists;
            me->GetPlayerListInGrid(l_Playerlists, 300.0f);

            if (l_Playerlists.empty())
                return;

            for (auto itr : l_Playerlists)
            {
                itr->CastSpell(itr, Spells::SPELL_PRIDE_METER);
            }

            me->SetPower(POWER_ENERGY, 0);
            me->SetInt32Value(UNIT_FIELD_POWER, 0);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetInt32Value(UNIT_FIELD_MAXPOWER, 100);
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case Actions::ACTION_UNLEAHSED:
                // Handle Unleahsed

                if (m_Instance != nullptr)
                {
                    if (Creature * l_Norushen = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_NORUSHEN)))
                    {
                        if (l_Norushen->GetAI())
                            l_Norushen->GetAI()->DoAction(Actions::ACTION_UNLEAHSED);
                    }
                }
                break;
            }
        }

        void RegeneratePower(Powers power, int32& value)
        {
            if (power != POWER_ENERGY)
                return;

            if (!me->IsInCombat())
                return;

            // Sha of Fear regenerates 6 energy every 2s (15 energy for 5s)
            value = 5;

            int32 val = me->GetPower(POWER_ENERGY);
            if (val + value > 100)
                val = 100;
            else
                val += value;

            if (value >= 100)
            {
                me->SetPower(POWER_ENERGY, 0);
                me->SetInt32Value(UNIT_FIELD_POWER, 0);
                events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
            }

            me->SetInt32Value(UNIT_FIELD_POWER, val);
        }

        void DamageTaken(Unit* attacker, uint32& damage) override
        {
            if (!me->IsInCombat())
                return;

            // Unleashed
            if (!m_Unleashed && me->GetHealthPct() <= 30)
            {
                m_Unleashed = true;
                DoAction(Actions::ACTION_UNLEAHSED);
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (Unit* l_Target = me->GetVictim())
                if (!me->IsWithinMeleeRange(l_Target))
                {
                    if (!m_ReachAttack)
                    {
                        m_ReachAttack = true;
                        events.ScheduleEvent(Events::EVENT_REACHING_ATTACK, 5 * TimeConstants::IN_MILLISECONDS);
                    }
                }
                else
                {
                    m_ReachAttack = false;
                    events.CancelEvent(Events::EVENT_REACHING_ATTACK);
                }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
                case Events::EVENT_ENRAGE:
                {
                    // hardcode 5 pride every 10 seconds.
                    break;
                }
                case Events::EVENT_CHECK_ENERGY:
                {
                    if (me->GetUInt32Value(UNIT_FIELD_POWER) == 100)
                    {
                        me->CastSpell(me->GetVictim(), Spells::SPELL_SWELLING_PRIDE, true);

                        me->SetPower(POWER_ENERGY, 0);
                        me->SetInt32Value(UNIT_FIELD_POWER, 0);
                        Talk(Talks::TALK_SPELL03);
                    }
                    events.ScheduleEvent(EVENT_CHECK_ENERGY, 1000);
                    break;
                }
                case Events::EVENT_CORRUPTION_PRISON:
                {
                    Talk(Talks::TALK_SPELL05);

                    // Handle Switcher Reset
                    std::list<Creature*> listLockTriggers;
                    me->GetCreatureListWithEntryInGrid(listLockTriggers, 324245, 200.0f);

                    if (listLockTriggers.empty())
                        return;

                    for (auto itr : listLockTriggers)
                    {
                        if (itr->GetAI())
                            itr->GetAI()->DoAction(ACTION_FINISH);
                    }

                    if (m_PrisonCounter >= 3)
                        m_PrisonCounter = 0;

                    std::list<Player*> l_Playerlists;
                    me->GetPlayerListInGrid(l_Playerlists, 300.0f);

                    if (l_Playerlists.empty())
                        return;

                    if (l_Playerlists.size() < 1)
                        return;

                    Position l_Position;

                    std::list<Player*>::const_iterator it = l_Playerlists.begin();
                    std::advance(it, urand(0, l_Playerlists.size() - 1));

                    if ((*it))
                    {
                        m_PrisonCounter++;

                        if (InstanceScript* m_Instance = me->GetInstanceScript())
                        {
                            if (Creature * l_ShaOfPride = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                            {
                                if (boss_sha_of_pride::boss_sha_of_prideAI* linkAI = CAST_AI(boss_sha_of_pride::boss_sha_of_prideAI, l_ShaOfPride->GetAI()))
                                {
                                    switch (linkAI->m_PrisonCounter)
                                    {
                                    case 0:
                                        l_Position.m_positionX = l_PositionCircleA.GetPositionX();
                                        l_Position.m_positionY = l_PositionCircleA.GetPositionY();
                                        l_Position.m_positionZ = l_PositionCircleA.GetPositionZ();
                                        break;
                                    case 1:
                                        l_Position.m_positionX = l_PositionCircleB.GetPositionX();
                                        l_Position.m_positionY = l_PositionCircleB.GetPositionY();
                                        l_Position.m_positionZ = l_PositionCircleB.GetPositionZ();
                                        break;
                                    case 2:
                                        l_Position.m_positionX = l_PositionCircleC.GetPositionX();
                                        l_Position.m_positionY = l_PositionCircleC.GetPositionY();
                                        l_Position.m_positionZ = l_PositionCircleC.GetPositionZ();
                                        break;
                                    case 3:
                                        l_Position.m_positionX = l_PositionCircleD.GetPositionX();
                                        l_Position.m_positionY = l_PositionCircleD.GetPositionY();
                                        l_Position.m_positionZ = l_PositionCircleD.GetPositionZ();
                                        break;
                                    }

                                    (*it)->StopMoving();

                                    (*it)->NearTeleportTo(l_Position.GetPositionX(), l_Position.GetPositionY(), l_Position.GetPositionZ(), (*it)->GetOrientation());
                                    (*it)->m_Events.AddEvent(new sha_of_pride_register_guid_prisons((*it), 0), (*it)->m_Events.CalculateTime(1000));
                                }
                            }
                        }
                    }

                    events.ScheduleEvent(Events::EVENT_CORRUPTION_PRISON, 75 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case Events::EVENT_WOUNDED_PRIDE:
                    if (Unit* l_Target = me->GetVictim())
                        me->CastSpell(l_Target, Spells::SPELL_WOUNDED_PRIDE);

                    events.ScheduleEvent(Events::EVENT_WOUNDED_PRIDE, 20 * TimeConstants::IN_MILLISECONDS);
                    break;
                case Events::EVENT_REACHING_ATTACK:
                    DoCastAOE(Spells::SPELL_REACHING_ATTACK);

                    events.ScheduleEvent(Events::EVENT_REACHING_ATTACK, 5 * TimeConstants::IN_MILLISECONDS);
                    break;
                case Events::EVENT_MANIFESTATION_OF_PRIDE:
                {
                    if (me->GetMap()->Is25ManRaid())
                    {
                        for (int i = 0; i <= 2; i++)
                        {
                            Creature* l_manifestedPride = me->SummonCreature(Creatures::CREATURE_MANIFESTATION_OF_PRIDE, l_PositionManifestationOfPride[i], TEMPSUMMON_MANUAL_DESPAWN);
                            l_manifestedPride->CastSpell(me, Spells::SPELL_MANIFESTATION_VISUAL, true);

                        }
                    }
                    else
                    {
                        Creature* l_manifestedPride = me->SummonCreature(Creatures::CREATURE_MANIFESTATION_OF_PRIDE, l_PositionManifestationOfPride[1], TEMPSUMMON_MANUAL_DESPAWN);
                        l_manifestedPride->CastSpell(me, Spells::SPELL_MANIFESTATION_VISUAL, true);
                    }

                    events.ScheduleEvent(Events::EVENT_MANIFESTATION_OF_PRIDE, 60 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case Events::EVENT_MARKOF_ARROGANCE:
                {
                    std::list<Player*> l_Playerlists;
                    me->GetPlayerListInGrid(l_Playerlists, 300.0f);

                    if (l_Playerlists.empty())
                        return;

                    if (l_Playerlists.size() < 1)
                        return;

                    std::list<Player*>::const_iterator it = l_Playerlists.begin();
                    std::advance(it, urand(0, l_Playerlists.size() - 2));

                    me->CastSpell((*it), Spells::SPELL_MARK_OF_ARROGANCE, true);

                    events.ScheduleEvent(Events::EVENT_MARKOF_ARROGANCE, 20 * TimeConstants::IN_MILLISECONDS);
                    break;
                }
                case Events::EVENT_SELF_REFLECTION:
                {
                    Talk(Talks::TALK_SPELL01);
                    std::list<Player*> l_Playerlists;
                    me->GetPlayerListInGrid(l_Playerlists, 600.0f);

                    if (l_Playerlists.empty())
                        return;

                    m_ReflectionCounter++;

                    ///< 25 man / 10 man
                    if (l_Playerlists.size() < 4)
                        return;

                    std::list<Player*>::const_iterator it = l_Playerlists.begin();
                    std::advance(it, urand(0, l_Playerlists.size() - 5));

                    Position l_Position;
                    l_Position.m_positionX = (*it)->GetPositionX();
                    l_Position.m_positionY = (*it)->GetPositionY();
                    l_Position.m_positionZ = (*it)->GetPositionZ();

                    // Handle Prison
                    (*it)->CastSpell((*it), Spells::SPELL_SPELL_REFLECTION_VISUAL_POOL);
                    (*it)->m_Events.AddEvent(new sha_of_pride_summon_reflection((*it), 0, l_Position), (*it)->m_Events.CalculateTime(2 * TimeConstants::IN_MILLISECONDS));
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_sha_of_prideAI(creature);
    }
};

// Norushen -
class npc_norushen : public CreatureScript
{
public:
    npc_norushen() : CreatureScript("npc_norushen") { }

    struct npc_norushenAI : public BossAI
    {
        npc_norushenAI(Creature* creature) : BossAI(creature, eData::DATA_NORUSHEN)
        {
            m_Instance = creature->GetInstanceScript();

            m_Intro = true;
        }

        InstanceScript* m_Instance;
        bool m_Intro;

        void Reset() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who && who->IsInWorld() && who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 10.0f) && m_Intro)
            {
                m_Intro = false;
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case Actions::ACTION_UNLEAHSED:
                events.ScheduleEvent(Events::EVENT_01, 2 * TimeConstants::IN_MILLISECONDS);
                break;
            case Actions::ACTION_COMBAT:
                events.ScheduleEvent(Events::EVENT_GIFT_OF_THE_TITANS, 35 * TimeConstants::IN_MILLISECONDS);
                break;
            case Actions::ACTION_RELEASE:
                events.Reset();
                me->Respawn(true);
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            // Starts at 30% UNLESHED EVENT
            if (Creature * l_ShaOfPride = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
            {
                if (l_ShaOfPride->GetAI())
                {
                    switch (events.ExecuteEvent())
                    {
                        // RP
                    case Events::EVENT_01:
                        l_ShaOfPride->AI()->Talk(Talks::TALK_EVENT01);
                        events.ScheduleEvent(Events::EVENT_02, 6 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case Events::EVENT_02:
                        Talk(Talks::TALK_NORUSHEN_EVENT01);
                        events.ScheduleEvent(Events::EVENT_03, 6 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case Events::EVENT_03:
                        Talk(Talks::TALK_NORUSHEN_EVENT02);
                        events.ScheduleEvent(Events::EVENT_04, 6 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case Events::EVENT_04:
                        l_ShaOfPride->CastSpell(l_ShaOfPride, 144832);
                        events.ScheduleEvent(Events::EVENT_05, 10 * TimeConstants::IN_MILLISECONDS);
                        break;
                    case Events::EVENT_05:
                    {
                        std::list<Player*> l_PlayerList;
                        me->GetPlayerListInGrid(l_PlayerList, 300.0f);

                        if (l_PlayerList.empty())
                            return;

                        for (auto itr : l_PlayerList)
                        {
                            me->CastSpell(itr, Spells::SPELL_FINAL_GIFT);
                        }
                        break;
                    }
                    case Events::EVENT_06:
                        l_ShaOfPride->Kill(me);
                        Talk(Talks::TALK_NORUSHEN_DEATH);
                        break;
                    case Events::EVENT_GIFT_OF_THE_TITANS:
                    {
                        std::list<Player*> l_PlayerList;
                        me->GetPlayerListInGrid(l_PlayerList, 300.0f);

                        if (l_PlayerList.empty())
                            return;

                        for (auto itr : l_PlayerList)
                        {
                            me->CastSpell(itr, Spells::SPELL_GIFT_OF_TITAN);
                        }

                        events.ScheduleEvent(Events::EVENT_GIFT_OF_THE_TITANS, 68 * TimeConstants::IN_MILLISECONDS);
                        break;
                    }
                    default:
                        break;
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_norushenAI(creature);
    }
};

// Manifestation Of Pride -
class npc_manifestation_of_pride : public CreatureScript
{
public:
    npc_manifestation_of_pride() : CreatureScript("npc_manifestation_of_pride") { }

    struct npc_manifestation_of_prideAI : public BossAI
    {
        npc_manifestation_of_prideAI(Creature* creature) : BossAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
            me->Respawn();
        }

        InstanceScript* m_Instance;

        void Reset()
        {
            me->setFaction(FriendlyFaction);

            events.Reset();
            events.ScheduleEvent(Events::EVENT_MANIFESTATION_OF_PRIDE, 4 * TimeConstants::IN_MILLISECONDS);
        }

        void EnterCombat(Unit* attacker) override
        {
            // Schedule Combat event here
            events.Reset();

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);

            events.ScheduleEvent(Events::EVENT_MOCKING_BLAST, 8 * TimeConstants::IN_MILLISECONDS);
            events.ScheduleEvent(Events::EVENT_LAST_WORD, 15 * TimeConstants::IN_MILLISECONDS);
        }

        void JustDied(Unit* killer) override
        {
            std::list<Player*> l_ListCloserPlayers;
            me->GetPlayerListInGrid(l_ListCloserPlayers, 20.0f);

            if (l_ListCloserPlayers.empty())
                return;

            for (auto itr : l_ListCloserPlayers)
            {
                me->CastSpell(itr, Spells::SPELL_LAST_WORD);
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            switch (events.ExecuteEvent())
            {
            case Events::EVENT_MOCKING_BLAST:
            {
                if (!UpdateVictim())
                    return;

                if (Unit* random = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    me->CastSpell(random, Spells::SPELL_MOCKINGB_LAST);

                events.ScheduleEvent(Events::EVENT_MOCKING_BLAST, 8 * TimeConstants::IN_MILLISECONDS);
                break;
            }
            case Events::EVENT_MANIFESTATION_OF_PRIDE:
            {
                me->RemoveAllAuras();
                me->setFaction(HostileFaction);
                me->SetInCombatWithZone();
                break;
            }
            default:
                break;
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_manifestation_of_prideAI(creature);
    }
};

// Projectile -
class npc_projection : public CreatureScript
{
public:
    npc_projection() : CreatureScript("npc_projection") { }

    struct npc_projectionAI : public BossAI
    {
        npc_projectionAI(Creature* creature) : ScriptedAI(creature)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        uint32 m_Explosion;

        void Reset()
        {
            m_Explosion = 6000;

            if (TempSummon* tempo = me->ToTempSummon())
                if (Unit* summoner = tempo->GetSummoner())
                    if (summoner->IsInWorld() && summoner->IsAlive())
                    {
                        me->CastSpell(summoner, Spells::SPELL_PROJECTION_WARNING);
                    }
        }

        bool TargetCheck()
        {
            if (Player* nearest = me->GetVictim())
            {
                if (nearest->GetAura(Spells::SPELL_PROJECTION_WARNING, me->GetGUID()))
                {
                    return true;
                }
            }
            return false;
        }

        void UpdateAI(const uint32 diff)
        {
            events.Update(diff);

            // Projectile
            if (TempSummon* tempo = me->ToTempSummon())
                if (Unit* summoner = tempo->GetSummoner())
                    if (summoner->IsInWorld() && summoner->IsAlive())
                    {
                        summoner->CastSpell(me, Spells::SPELL_PROJECTION_PROJECTILE);
                    }

            // Explosion
            if (m_Explosion <= diff)
            {
                if (TargetCheck())
                {
                    me->CastSpell(me, Spells::SPELL_PROJECTION_BLUE);
                    m_Explosion = 10000;
                }
                else
                {
                    me->CastSpell(me, Spells::SPELL_PROJECTION_DAMAGE);
                    me->DespawnOrUnsummon();

                    std::list<Player*> l_ListPlayers;
                    me->GetPlayerListInGrid(l_ListPlayers, 300.0f);

                    if (l_ListPlayers.empty())
                        return;

                    for (auto itr : l_ListPlayers)
                    {
                        if (InstanceScript* l_Instance = me->GetInstanceScript())
                        {
                            if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                            {
                                ModifyPride(l_ShaOfPride, 5, itr->GetGUID());
                            }
                        }
                    }

                    m_Explosion = 10000;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_projectionAI(creature);
    }
};

// Corrupted Prison Controller
class mob_corrupted_prison : public CreatureScript
{
public:
    mob_corrupted_prison() : CreatureScript("mob_corrupted_prison") { }

    struct sha_of_pride_creatures : public NullCreatureAI
    {
        sha_of_pride_creatures(Creature* p_Creature) : NullCreatureAI(p_Creature), victimGUID(0)
        {
            m_ListPrisonsTriggers.clear();
            m_Instance = me->GetInstanceScript();
        }

        std::list<uint64> m_ListPrisonsTriggers;
        std::list<GameObject*> m_listPrisonersGobjects;
        InstanceScript* m_Instance;
        uint64 victimGUID;
        bool switch01;
        bool switch02;
        bool switch03;

        void Reset() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UnitFlags::UNIT_FLAG_NON_ATTACKABLE | UnitFlags::UNIT_FLAG_DISABLE_MOVE);
            me->setFaction(FriendlyFaction);

            switch01 = false;
            switch02 = false;
            switch03 = false;

            me->SetDisplayId(11686);

            std::list<Creature*> listLockTriggers;
            me->GetCreatureListWithEntryInGrid(listLockTriggers, CREATURE_PRISON_TRIGGER_SWITCHERS, 5.0f);

            if (listLockTriggers.empty())
                return;

            for (auto itr : listLockTriggers)
            {
                if (itr->GetAI())
                    itr->GetAI()->Reset();
            }
        }

        void SetGUID(uint64 guid, int32 /*param*/) override
        {
            switch01 = false;
            switch02 = false;
            switch03 = false;
            victimGUID = guid;
            std::list<Creature*> listLockTriggers;
            me->GetCreatureListWithEntryInGrid(listLockTriggers, CREATURE_PRISON_TRIGGER_SWITCHERS, 6.8f);

            if (listLockTriggers.empty())
                return;

            for (auto itr : listLockTriggers)
            {
                if (itr->GetAI())
                    itr->GetAI()->DoAction(ACTION_COMBAT);
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
            case Actions::ACTION_RELEASE:
            {
                if (victimGUID)
                {
                    if (Unit* victim = ObjectAccessor::GetUnit(*me, GetGUID(victimGUID)))
                    {
                        victim->RemoveAura(Spells::SPELL_CORRUPTED_PRISON_DOT);
                    }
                }

                switch01 = false;
                switch02 = false;
                switch03 = false;

                victimGUID = NULL;

                std::list<Creature*> listLockTriggers;
                me->GetCreatureListWithEntryInGrid(listLockTriggers, CREATURE_PRISON_TRIGGER_SWITCHERS, 3.0f);

                if (listLockTriggers.empty())
                    return;

                for (auto itr : listLockTriggers)
                {
                    if (itr->GetAI())
                        itr->GetAI()->DoAction(ACTION_FINISH);
                }
                break;
            }
            case Actions::ACTION_SWITCH01:
                switch01 = true;
                break;
            case Actions::ACTION_SWITCH02:
                switch02 = true;
                break;
            case Actions::ACTION_SWITCH03:
                switch03 = true;
                break;
            }
        }

        void UpdateAI(const uint32 diff) override
        {
            if (!me->GetMap()->Is25ManRaid())
            {
                if (switch01 && switch02)
                {
                    DoAction(Actions::ACTION_RELEASE);
                }
            }
            else
            {
                if (switch01 && switch02 && switch03)
                {
                    DoAction(Actions::ACTION_RELEASE);
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new sha_of_pride_creatures(p_Creature);
    }
};

// Corrupted Prison
class creature_corrupted_prison_pride_switch : public CreatureScript
{
public:
    creature_corrupted_prison_pride_switch() : CreatureScript("creature_corrupted_prison_pride_switch") { }

    struct creature_corrupted_prison_pride_switchAI : public ScriptedAI
    {
        creature_corrupted_prison_pride_switchAI(Creature* creature) : ScriptedAI(creature), Guido(0)
        {
            m_Instance = creature->GetInstanceScript();
        }

        InstanceScript* m_Instance;
        std::list<GameObject*> listGameObjects;
        bool hasClicked;
        bool Triggered;
        uint32 ValueToReset;
        uint64 Guido;

        void Reset() override
        {
            Guido = 0;
            ValueToReset = 0;
            hasClicked = true;
            Triggered = false;

            me->SetDisplayId(11686);
        }

        void SetGUID(uint64 guid, int32 param) override
        {
            uint32 entries[12] =
            {
                GAMEOBJECT_PRISON_NORTH_01, GAMEOBJECT_PRISON_NORTH_02, GAMEOBJECT_PRISON_NORTH_03, GAMEOBJECT_PRISON_SOUTH_01, GAMEOBJECT_PRISON_SOUTH_02,
                GAMEOBJECT_PRISON_SOUTH_03, GAMEOBJECT_PRISON_WEST_01, GAMEOBJECT_PRISON_WEST_02, GAMEOBJECT_PRISON_WEST_03, GAMEOBJECT_PRISON_EAST_01,
                GAMEOBJECT_PRISON_EAST_02, GAMEOBJECT_PRISON_EAST_03
            };

            me->GetGameObjectListWithEntryInGrid(listGameObjects, entries[param], 600.0f);

            if (listGameObjects.empty())
                return;

            for (auto itr : listGameObjects)
            {
                Guido = itr->GetGUID();

                itr->SetLootState(GO_READY);
                itr->UseDoorOrButton(10000, false, me);
            }
        }

        void DoAction(const int32 action) override
        {
            switch (action)
            {
                case Actions::ACTION_RESET:
                {
                    if (m_Instance == nullptr)
                        return;

                    hasClicked = false;

                    break;
                }
                case Actions::ACTION_COMBAT:
                {
                    if (GameObject * gob = ObjectAccessor::GetGameObject(*me, GetGUID(Guido)))
                    {
                        gob->SetLootState(GO_READY);
                        gob->UseDoorOrButton(10000, false, me);
                    }

                    hasClicked = false;
                    Triggered = true;
                    break;
                }
                case Actions::ACTION_FINISH:
                {
                    Triggered = false;
                    hasClicked = false;
                    if (GameObject * gob = ObjectAccessor::GetGameObject(*me, GetGUID(Guido)))
                    {
                        gob->SetLootState(GO_READY);
                        gob->UseDoorOrButton(10000, false, me);
                    }
                    break;
                }
            }
        }

        void UpdateAI(uint32 const diff)
        {
            // Only if Prison is triggered (has a victim GUID)
            if (Triggered)
            {
                if (GameObject * gob = ObjectAccessor::GetGameObject(*me, GetGUID(Guido)))
                {
                        if (me->GetVictim())
                        {
                            if (!hasClicked)
                            {
                                hasClicked = true;

                                gob->SetLootState(GO_READY);
                                gob->UseDoorOrButton(10000, false, me);
                            }


                            uint32 l_GameObjectsEntries[16] =
                            {
                                eGameObjectsLocal::GAMEOBJECT_PRISON_NORTH_01, eGameObjectsLocal::GAMEOBJECT_PRISON_NORTH_02, eGameObjectsLocal::GAMEOBJECT_PRISON_NORTH_03,
                                eGameObjectsLocal::GAMEOBJECT_PRISON_SOUTH_01, eGameObjectsLocal::GAMEOBJECT_PRISON_SOUTH_02, eGameObjectsLocal::GAMEOBJECT_PRISON_SOUTH_03,
                                eGameObjectsLocal::GAMEOBJECT_PRISON_EAST_01, eGameObjectsLocal::GAMEOBJECT_PRISON_EAST_02, eGameObjectsLocal::GAMEOBJECT_PRISON_EAST_03,
                                eGameObjectsLocal::GAMEOBJECT_PRISON_WEST_01, eGameObjectsLocal::GAMEOBJECT_PRISON_WEST_02, eGameObjectsLocal::GAMEOBJECT_PRISON_WEST_03,
                            };

                            switch (gob->GetEntry())
                            {
                            case GAMEOBJECT_PRISON_NORTH_01:
                            case GAMEOBJECT_PRISON_SOUTH_01:
                            case GAMEOBJECT_PRISON_EAST_01:
                            case GAMEOBJECT_PRISON_WEST_01:
                                if (Creature* PrisonController = gob->FindNearestCreature(CREATURE_PRISON_TRIGGER, 5.0f))
                                    if (PrisonController->GetAI())
                                        PrisonController->GetAI()->DoAction(ACTION_SWITCH01);

                                ValueToReset = 1;
                                break;
                            case GAMEOBJECT_PRISON_NORTH_02:
                            case GAMEOBJECT_PRISON_SOUTH_02:
                            case GAMEOBJECT_PRISON_EAST_02:
                            case GAMEOBJECT_PRISON_WEST_02:
                                if (Creature* PrisonController = gob->FindNearestCreature(CREATURE_PRISON_TRIGGER, 5.0f))
                                    if (PrisonController->GetAI())
                                        PrisonController->GetAI()->DoAction(ACTION_SWITCH02);

                                ValueToReset = 2;
                                break;
                            case GAMEOBJECT_PRISON_NORTH_03:
                            case GAMEOBJECT_PRISON_SOUTH_03:
                            case GAMEOBJECT_PRISON_EAST_03:
                            case GAMEOBJECT_PRISON_WEST_03:
                                if (Creature* PrisonController = gob->FindNearestCreature(CREATURE_PRISON_TRIGGER, 5.0f))
                                    if (PrisonController->GetAI())
                                        PrisonController->GetAI()->DoAction(ACTION_SWITCH03);

                                ValueToReset = 3;
                                break;
                            }
                        }
                        else
                        {
                            if (hasClicked)
                            {
                                hasClicked = false;

                                gob->SetLootState(GO_READY);
                                gob->UseDoorOrButton(10000, false, me);

                                if (Creature* PrisonController = gob->FindNearestCreature(CREATURE_PRISON_TRIGGER, 8.0f))
                                {
                                    if (mob_corrupted_prison::sha_of_pride_creatures* linkAI = CAST_AI(mob_corrupted_prison::sha_of_pride_creatures, PrisonController->GetAI()))
                                    {
                                        switch (ValueToReset)
                                        {
                                        case 1:
                                            if (linkAI->switch01)
                                            {
                                                linkAI->switch01 = false;
                                                DoAction(ACTION_RESET);
                                            }
                                            break;
                                        case 2:
                                            if (linkAI->switch02)
                                            {
                                                linkAI->switch02 = false;
                                                DoAction(ACTION_RESET);
                                            }
                                            break;
                                        case 3:
                                            if (linkAI->switch03)
                                            {
                                                linkAI->switch03 = false;
                                                DoAction(ACTION_RESET);
                                            }
                                            break;
                                        }
                                    }
                                }

                            }
                        }
                    }
            }

        }
    };

    CreatureAI* GetAI(Creature* creature) const
    {
        return new creature_corrupted_prison_pride_switchAI(creature);
    }
};

// Corrupted Prison - 144574
class spell_corrupted_prison : public SpellScriptLoader
{
public:
    spell_corrupted_prison() : SpellScriptLoader("spell_corrupted_prison") { }

    class spell_corrupted_prisonSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_corrupted_prisonSpellScript);

        void HandleCorruptedPrison()
        {
            if (!GetHitUnit() && GetHitUnit()->GetTypeId() != TYPEID_PLAYER && !GetHitUnit()->IsAlive())
                return;

            if (!GetCaster())
                return;

            if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
            {
                if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                {
                    // 5 Pride upon each attack.
                    ModifyPride(l_ShaOfPride, 5, GetHitUnit()->ToPlayer()->GetGUID());
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_corrupted_prisonSpellScript::HandleCorruptedPrison);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_corrupted_prisonSpellScript();
    }

    class spell_corrupted_prisonAuraScript : public AuraScript
    {
        PrepareAuraScript(spell_corrupted_prisonAuraScript);

        void OnRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* l_Target = GetTarget())
            {
                l_Target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            }
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_corrupted_prisonAuraScript::OnRemove, EFFECT_1, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_corrupted_prisonAuraScript();
    }
};

// Projection - 144952
class spell_projection_spawn : public SpellScriptLoader
{
public:
    spell_projection_spawn() : SpellScriptLoader("spell_projection_spawn") { }

    class spell_projection_spawn_spell_script : public SpellScript
    {
        PrepareSpellScript(spell_projection_spawn_spell_script);

        void HandleCast()
        {
            if (!GetCaster())
                return;

            Player* l_Player = GetCaster()->ToPlayer();

            Position l_Position;
            l_Position = l_Player->GetPosition();

            if (l_Player)
            {
                l_Player->SummonCreature(CREATURE_PROJECTION, l_Position, TempSummonType::TEMPSUMMON_MANUAL_DESPAWN);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_projection_spawn_spell_script::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_projection_spawn_spell_script();
    }
};

// Power of The Titans:: 144363
class spell_power_of_the_titans : public SpellScriptLoader
{
public:
    spell_power_of_the_titans() : SpellScriptLoader("spell_power_of_the_titans") { }

    class spell_power_of_the_titans_spell_Script : public SpellScript
    {
        PrepareSpellScript(spell_power_of_the_titans_spell_Script);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (!GetCaster())
                return;

            uint32 l_Counter = 0;

            if (Player* l_NearestPlayer = GetCaster()->GetVictim())
            {
                std::list<Player*> l_ListPlayers;
                //JadeCore::AnyPlayerInObjectRangeCheck checker(l_NearestPlayer, 10.0f);
                //JadeCore::PlayerListSearcher<JadeCore::AnyPlayerInObjectRangeCheck> searcherBigList(l_NearestPlayer, l_ListPlayers, checker);
                //GetCaster()->VisitNearbyWorldObject(10.0f, searcherBigList);

                if (l_Counter >= 8)
                {
                    std::list<Player*> l_TempPlayers;

                    if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
                    {
                        if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                        {
                            l_ShaOfPride->GetPlayerListInGrid(l_TempPlayers, 300.0f);

                            if (l_TempPlayers.empty())
                                return;

                            for (auto itr : l_TempPlayers)
                            {
                                itr->AddAura(Spells::SPELL_POWER_OF_THE_TITANS, itr);
                            }
                        }
                    }
                }
            }
        }

        void Register()
        {
            OnEffectHitTarget += SpellEffectFn(spell_power_of_the_titans_spell_Script::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_power_of_the_titans_spell_Script();
    }
};

// Wounded Pride - 144358
class spell_wounded_pride : public SpellScriptLoader
{
public:
    spell_wounded_pride() : SpellScriptLoader("spell_wounded_pride") { }

    class spell_wounded_pride_aura_script : public AuraScript
    {
        PrepareAuraScript(spell_wounded_pride_aura_script);

        void OnProc(const AuraEffect* aurEff, ProcEventInfo& eventInfo)
        {
            if (!GetTarget())
                return;

            if (!GetCaster())
                return;

            if (Player* player = GetTarget()->ToPlayer())
            {
                if (InstanceScript* m_Instance = GetCaster()->GetInstanceScript())
                {
                    if (Creature * l_ShaOfPride = m_Instance->instance->GetCreature(m_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                    {
                        // Only Sha Of Pride can cause the Pride modification.
                        if (l_ShaOfPride->GetVictim() == player)
                            ModifyPride(l_ShaOfPride, 5, player->GetGUID());
                    }
                }
            }
        }

        void Register()
        {
            OnEffectProc += AuraEffectProcFn(spell_wounded_pride_aura_script::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_wounded_pride_aura_script();
    }
};

// Self-Reflection::SQUIRT 144788  || Last Word 144370 || Mocking blast 144379  || Projection 145320 || Unleahsed 144836
class spell_self_reflection : public SpellScriptLoader
{
public:
    spell_self_reflection() : SpellScriptLoader("spell_self_reflection") { }

    class spell_self_reflectionSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_self_reflectionSpellScript);

        void HandleSwellingCorruption()
        {
            if (!GetHitUnit() && GetHitUnit()->GetTypeId() != TYPEID_PLAYER)
                return;

            if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
            {
                if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                {
                    ModifyPride(l_ShaOfPride, 5, GetHitUnit()->ToPlayer()->GetGUID());
                }
            }
        }

        void Register()
        {
            OnHit += SpellHitFn(spell_self_reflectionSpellScript::HandleSwellingCorruption);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_self_reflectionSpellScript();
    }
};

// Swelling Pride - 144400
class spell_swelling_pride : public SpellScriptLoader
{
public:
    spell_swelling_pride() : SpellScriptLoader("spell_swelling_pride") { }

    class spell_swelling_prideSpellScript : public SpellScript
    {
        PrepareSpellScript(spell_swelling_prideSpellScript);

        void HandleSwellingCorruption()
        {
            int32 m_SpellId = NULL;

            if (!GetCaster())
                return;

            std::list<Player*> listPlayers;
            GetCaster()->GetPlayerListInGrid(listPlayers, 300.0f);

            if (listPlayers.empty())
                return;

            for (auto itr : listPlayers)
            {
                switch (CheckForPrideValue(itr))
                {
                case LOW:
                    return;
                    break;
                case MEDIUM:
                    m_SpellId = Spells::SPELL_BURSTING_PRIDE;
                    break;
                case HARD:
                    m_SpellId = Spells::SPELL_PROJECTION_DUMMY;
                    break;
                case CHAOS:
                    m_SpellId = Spells::SPELL_AURA_OF_PRIDE_AURA;
                    break;
                case FATAL:
                    m_SpellId = Spells::SPELL_OVERCOME_DAMAGE;
                    break;
                }

                if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
                {
                    if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                    {
                        ModifyPride(l_ShaOfPride, 5, itr->GetGUID());
                    }
                }

                if (m_SpellId != Spells::SPELL_BURSTING_PRIDE)
                    itr->CastSpell(itr, m_SpellId, true);
                else
                    GetCaster()->CastSpell(itr, Spells::SPELL_BURSTING_PRIDE);
            }
        }

        void Register()
        {
            AfterCast += SpellCastFn(spell_swelling_prideSpellScript::HandleSwellingCorruption);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_swelling_prideSpellScript();
    }
};

// Overcome - 144843
class spell_overcome : public SpellScriptLoader
{
public:
    spell_overcome() : SpellScriptLoader("spell_overcome") { }

    class spell_overcome_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_overcome_AuraScript);

        void OnApply(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (Unit* l_Target = GetTarget())
                {
                    if (InstanceScript* l_Instance = l_Caster->GetInstanceScript())
                    {
                        if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                        {
                            l_Target->SetCharmedBy(l_ShaOfPride, CHARM_TYPE_CONVERT);
                        }
                    }
                }
            }
        }

        void OnRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* l_Target = GetTarget())
            {
                if (InstanceScript* l_Instance = l_Target->GetInstanceScript())
                {
                    if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                    {
                        l_Target->RemoveCharmedBy(l_ShaOfPride);
                    }
                }
            }
        }

        void Register()
        {
            AfterEffectApply += AuraEffectApplyFn(spell_overcome_AuraScript::OnApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_overcome_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_overcome_AuraScript();
    }
};

// Corrupted Prison        - 144574
// spell_mark_of_arrogance - 144351
class spell_mark_of_arrogance : public SpellScriptLoader
{
public:
    spell_mark_of_arrogance() : SpellScriptLoader("spell_mark_of_arrogance") { }

    class spell_champion_of_light_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_champion_of_light_AuraScript);

        void OnRemove(const AuraEffect* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* l_Caster = GetCaster())
            {
                if (GetTarget() && GetTarget()->GetTypeId() == TYPEID_PLAYER)
                {
                    if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
                    {
                        if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                        {
                            ModifyPride(l_ShaOfPride, 5, GetTarget()->ToPlayer()->GetGUID());
                        }
                    }
                }
            }
        }

        void Register()
        {
            AfterEffectRemove += AuraEffectRemoveFn(spell_champion_of_light_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_champion_of_light_AuraScript();
    }
};

// Corrupted Prison        - 144574
class spell_corrupted_prison_dot_damage : public SpellScriptLoader
{
public:
    spell_corrupted_prison_dot_damage() : SpellScriptLoader("spell_corrupted_prison_dot_damage") { }

    class spell_corrupted_prison_dot_damageAI : public AuraScript {
        PrepareAuraScript(spell_corrupted_prison_dot_damageAI);

        int32 cooldownPer;

        void OnUpdate(const AuraEffect* aurEff)
        {
            if (!GetTarget())
                return;

            if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
                return;

            if (InstanceScript* l_Instance = GetCaster()->GetInstanceScript())
            {
                if (Creature * l_ShaOfPride = l_Instance->instance->GetCreature(l_Instance->GetObjectGuid(eData::DATA_SHA_OF_PRIDE)))
                {
                    ModifyPride(l_ShaOfPride, 5, GetTarget()->ToPlayer()->GetGUID());
                }
            }
        }
        void Register()
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_corrupted_prison_dot_damageAI::OnUpdate, EFFECT_2, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_corrupted_prison_dot_damageAI();
    }
};

void AddSC_sha_of_pride()
{
    new boss_sha_of_pride();
    new npc_norushen();

    new npc_projection();
    new npc_manifestation_of_pride();
    new mob_corrupted_prison();
    new creature_corrupted_prison_pride_switch();

    new spell_overcome();
    new spell_corrupted_prison_dot_damage();
    new spell_corrupted_prison();
    new spell_self_reflection();
    new spell_mark_of_arrogance();
    new spell_swelling_pride();
    new spell_wounded_pride();
    new spell_power_of_the_titans();
    new spell_projection_spawn();
}
