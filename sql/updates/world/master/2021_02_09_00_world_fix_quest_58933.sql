UPDATE `creature_template` SET `ScriptName`='npc_gutgruck_the_tough' WHERE `entry`=163031;
UPDATE `creature_template` SET `faction`='190' WHERE `entry`=163031;
REPLACE INTO `areatrigger_involvedrelation` VALUES (130001, 58933);
REPLACE INTO `areatrigger` VALUES (113, 130001, 2175, 1, 257.067596, -2174.937988, 97.172401, '');
REPLACE INTO `areatrigger_scripts` VALUES (130001, 'at_for_gutgruck_the_tough');
REPLACE INTO `areatrigger_template` VALUES (130001, 0, 1, 35, 35, 0, 0, 0, 0, 'at_for_gutgruck_the_tough', 0);

/* DELETE */
DELETE FROM `creature_addon` WHERE  `guid`=4000000000046946;
DELETE FROM `creature` WHERE  `guid`=4000000000046946;
DELETE FROM `creature_addon` WHERE  `guid`=4000000000046950;
DELETE FROM `creature` WHERE  `guid`=4000000000046950;
DELETE FROM `creature_addon` WHERE  `guid`=4000000000046954;
DELETE FROM `creature` WHERE  `guid`=4000000000046954;
DELETE FROM `creature_addon` WHERE  `guid`=4000000000046955;
DELETE FROM `creature` WHERE  `guid`=4000000000046955;
DELETE FROM `creature_addon` WHERE  `guid`=4000000000046960;
DELETE FROM `creature` WHERE  `guid`=4000000000046960;
DELETE FROM `creature_addon` WHERE  `guid`=4000000000046959;
DELETE FROM `creature` WHERE  `guid`=4000000000046959;
/* END DELETE */

/* spirit Coulston Nereus */
REPLACE INTO `creature_addon` VALUES (4000000000046964, 0, 0, 8, 0, 0, 0, 0, 0, 0, NULL);
REPLACE INTO `creature` VALUES (4000000000046964, 162972, 2175, 0, 0, '0', 0, 0, 0, -1, 0, 0, 171.848, -2061.6, 77.7334, 2.17111, 300, 0, 0, 68, 0, 0, 0, 0, 0, 0, 0, '', 0);
/* corpse Coulston Nereus */
REPLACE INTO `creature_addon` VALUES (4000000000046963, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '145363');
REPLACE INTO `creature` VALUES (4000000000046963, 162970, 2175, 0, 0, '0', 0, 0, 0, -1, 0, 0, 170.91, -2059.94, 77.7056, 3.67122, 300, 0, 0, 123, 0, 0, 0, 0, 0, 0, 0, '', 0);

REPLACE INTO `creature_template_addon` VALUES (162970, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '145363');
REPLACE INTO `creature_template` VALUES (162970, 0, 0, 0, 0, 0, 'Coulston Nereus', '', NULL, NULL, NULL, 0, 1, 10, 0, 0, 0, 2057, 0, 1, 1.14286, 1, 0, 0, 0, 0, 1, 1, 1, 537166592, 2049, 8192, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 1.2, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, '', 36949);

REPLACE INTO `quest_template_addon` VALUES (58917, 0, 0, 0, 58933, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `quest_template_addon` VALUES (58933, 0, 0, 58917, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');
REPLACE INTO `creature_queststarter` VALUES (162972, 58933);