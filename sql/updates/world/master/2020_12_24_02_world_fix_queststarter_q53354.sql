REPLACE INTO `creature_queststarter` VALUES (15192, 53354);
REPLACE INTO `quest_template_addon` VALUES (53354, 0, 0, 0, 53467, 53353, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '');

-- Echo of Gul'dan
REPLACE INTO `creature` VALUES (3530203330003062, 143505, 0, 0, 0, '0', 0, 0, 0, -1, 0, 0, -11791.7, -3177.29, -30.0176, 0.277129, 300, 0, 0, 126, 60, 0, 0, 0, 0, 0, 0, '', 0);
-- Anachronos
REPLACE INTO `creature` VALUES (3530203330003064, 143692, 0, 0, 0, '0', 0, 0, 0, -1, 0, 0, -11815.9, -3167.71, -28.0145, 5.20096, 300, 0, 0, 9477, 6000, 0, 0, 0, 0, 0, 0, '', 0);
-- npc flag = 3, faction = 35
-- bad data REPLACE INTO `creature_template` VALUES (143692, 0, 0, 0, 0, 0, 'Anachronos', '', NULL, NULL, NULL, 0, 1, 1, 5, 0, 0, 35, 3, 1, 1.14286, 1, 1, 0, 0, 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 3, 1, 600, 1, 100, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, '', 35662);
REPLACE INTO `creature_questender` VALUES (143692, 53354);
REPLACE INTO `creature_queststarter` VALUES (143692, 53353);