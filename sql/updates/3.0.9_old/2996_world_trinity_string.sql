DELETE FROM `trinity_string` WHERE `entry` IN (750,751);
INSERT INTO `trinity_string` VALUES
(750,'Not enough players. This game will close in %u mins.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL),
(751,'Not enough players. This game will close in %u seconds.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL);

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1200 AND 1232;
INSERT INTO `trinity_string` VALUES
(1200, 'You try to view cinemitic %u but it doesn''t exist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1201, 'You try to view movie %u but it doesn''t exist.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `trinity_string` WHERE `entry` BETWEEN 1300 AND 1332;
INSERT INTO `trinity_string` VALUES
(1300, 'Alliance', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1301, 'Horde', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1302, '%s was destroyed by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1303, 'The %s is under attack! If left unchecked, the %s will destroy it!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1304, 'The %s was taken by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1305, 'The %s was taken by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1306, 'The %s was taken by the %s!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1307, 'The %s is under attack! If left unchecked, the %s will capture it!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1308, 'The %s has taken the %s! Its supplies will now be used for reinforcements!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1309, 'Irondeep Mine', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1310, 'Coldtooth Mine', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1311, 'Stormpike Aid Station', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1312, 'Dun Baldar South Bunker', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1313, 'Dun Baldar North Bunker', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1314, 'Stormpike Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1315, 'Icewing Bunker', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1316, 'Stonehearth Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1317, 'Stonehearth Bunker', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1318, 'Snowfall Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1319, 'Iceblood Tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1320, 'Iceblood Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1321, 'Tower Point', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1322, 'Frostwolf Graveyard', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1323, 'East Frostwolf Tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1324, 'West Frostwolf Tower', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1325, 'Frostwolf Relief Hut', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1326, 'The Battle for Alterac Valley begins in 1 minute.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1327, 'The Battle for Alterac Valley begins in 30 seconds. Prepare yourselves!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1328, 'The Battle for Alterac Valley has begun!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1329, 'The Alliance Team is running out of reinforcements!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1330, 'The Horde Team is running out of reinforcements!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1331, 'The Frostwolf General is Dead!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(1332, 'The Stormpike General is Dead!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);