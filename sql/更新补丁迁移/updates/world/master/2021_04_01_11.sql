-- DB update 2021_04_01_10 -> 2021_04_01_11
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_10';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_10 2021_04_01_11 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617105845198069500'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617105845198069500');

UPDATE `creature_template` SET `DamageModifier` = 1.7, `unit_flags2` = 2080, `HealthModifier` = 4, `ArmorModifier` = 3, `AIName` = 'SmartAI', `speed_walk` = 1.1, `speed_run` = 1.3 WHERE (`entry` = 17664);

DELETE FROM `creature` WHERE (`id` = 17664);
INSERT INTO `creature` VALUES
(63387, 17664, 530, 0, 0, 1, 1, 0, 1, -1936.22, -10803.3, 86.3798, 5.1831, 1, 0, 0, 1131, 408, 0, 0, 0, 0, '', 0);

DELETE FROM `creature_addon` WHERE (`guid` IN (63387));
INSERT INTO `creature_addon` VALUES
(63387, 0, 2346, 0, 1, 0, 0, NULL);

DELETE FROM `creature_template_addon` WHERE (`entry` = 17664);
INSERT INTO `creature_template_addon` VALUES
(17664, 0, 2346, 0, 1, 0, 0, NULL);

DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` = 1785300);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 17664);
INSERT INTO `smart_scripts` VALUES
(17664, 0, 0, 0, 11, 0, 100, 1, 0, 0, 0, 0, 0, 53, 0, 17664, 1, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Respawn - Start Waypoint (No Repeat)'),
(17664, 0, 1, 2, 75, 0, 100, 0, 0, 17853, 30, 900, 0, 66, 0, 0, 0, 0, 0, 0, 19, 17853, 30, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Distance To Creature - Set Orientation Closest Creature \'Tracker of the Hand\''),
(17664, 0, 2, 0, 61, 0, 100, 1, 0, 17853, 30, 900, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Distance To Creature - Set Event Phase 1'),
(17664, 0, 3, 4, 60, 1, 100, 0, 500, 500, 20000, 20000, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Update - Set Reactstate Aggressive (Phase 1)'),
(17664, 0, 4, 0, 61, 1, 100, 1, 500, 500, 20000, 20000, 0, 49, 0, 0, 0, 0, 0, 0, 11, 17853, 30, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Update - Start Attacking (Phase 1)'),
(17664, 0, 5, 0, 75, 1, 100, 1, 0, 17853, 30, 500, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Distance To Creature - Say Line 0 (Phase 1) (No Repeat)'),
(17664, 0, 6, 0, 2, 1, 100, 1, 22, 51, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Set Flag Standstate Dead (Phase 1) (No Repeat)'),
(17664, 0, 7, 0, 2, 1, 100, 1, 22, 51, 0, 0, 0, 90, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Set Flag Standstate Sleep (Phase 1) (No Repeat)'),
(17664, 0, 8, 0, 2, 1, 100, 1, 22, 51, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Stop Attacking (Phase 1) (No Repeat)'),
(17664, 0, 9, 0, 2, 1, 100, 1, 22, 51, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Disable Combat Movement (Phase 1) (No Repeat)'),
(17664, 0, 10, 11, 2, 1, 100, 1, 22, 51, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Say Line 1 (Phase 1) (No Repeat)'),
(17664, 0, 11, 12, 61, 1, 100, 1, 22, 51, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Set Data 1 1 (Phase 1) (No Repeat)'),
(17664, 0, 12, 13, 61, 1, 100, 1, 22, 51, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 17853, 30, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Set Data 1 1 (Phase 1) (No Repeat)'),
(17664, 0, 13, 14, 61, 1, 100, 1, 22, 51, 0, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Remove FlagStandstate Dead (Phase 1) (No Repeat)'),
(17664, 0, 14, 15, 61, 1, 100, 1, 22, 51, 0, 0, 0, 91, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Remove FlagStandstate Sleep (Phase 1) (No Repeat)'),
(17664, 0, 15, 16, 61, 1, 100, 1, 22, 51, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Set Event Phase 2 (Phase 1) (No Repeat)'),
(17664, 0, 16, 17, 61, 2, 100, 1, 22, 51, 0, 0, 0, 18, 772, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Set Flags Disable Movement & Immune To Players & Immune To NPC\'s (Phase 1) (No Repeat)'),
(17664, 0, 17, 0, 61, 2, 100, 1, 22, 51, 0, 0, 0, 41, 8000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - Between 22-51% Health - Despawn In 8000 ms (Phase 1) (No Repeat)'),
(17664, 0, 18, 0, 11, 0, 100, 1, 0, 0, 0, 0, 0, 19, 772, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Respawn - Remove Flags Disable Movement & Immune To Players & Immune To NPC\'s (No Repeat)'),
(17664, 0, 19, 20, 0, 0, 100, 1, 500, 500, 0, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - In Combat - Enable Combat Movement (No Repeat)'),
(17664, 0, 20, 21, 61, 0, 100, 1, 500, 500, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - In Combat - Start Attacking (No Repeat)'),
(17664, 0, 21, 0, 61, 0, 100, 0, 500, 500, 0, 0, 0, 20, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - In Combat - Start Attacking (No Repeat)'),
(17664, 0, 22, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 43, 0, 2346, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Matis the Cruel - On Respawn - Mount To Model 2346');

DELETE FROM `waypoint_data` WHERE (`id` IN (633870));

DELETE FROM `waypoints` WHERE (`entry` IN (17664));
INSERT INTO `waypoints` VALUES
(17664, 1, -1936.21, -10803.29, 86.3797, 'Matis the Cruel'),
(17664, 2, -1935.68, -10822.00, 79.8942, 'Matis the Cruel'),
(17664, 3, -1934.65, -10841.29, 73.5764, 'Matis the Cruel'),
(17664, 4, -1941.42, -10849.59, 70.3264, 'Matis the Cruel'),
(17664, 5, -1938.68, -10864.20, 67.2014, 'Matis the Cruel'),
(17664, 6, -1934.35, -10883.70, 64.2909, 'Matis the Cruel'),
(17664, 7, -1921.16, -10884.20, 64.6192, 'Matis the Cruel'),
(17664, 8, -1912.77, -10884.79, 62.6705, 'Matis the Cruel'),
(17664, 9, -1899.84, -10885.50, 66.1876, 'Matis the Cruel'),
(17664, 10, -1890.56, -10888.20, 66.9680, 'Matis the Cruel'),
(17664, 11, -1881.69, -10886.79, 66.8430, 'Matis the Cruel'),
(17664, 12, -1890.56, -10888.20, 66.9680, 'Matis the Cruel'),
(17664, 13, -1899.84, -10885.50, 66.1876, 'Matis the Cruel'),
(17664, 14, -1912.77, -10884.79, 62.6705, 'Matis the Cruel'),
(17664, 15, -1921.16, -10884.20, 64.6192, 'Matis the Cruel'),
(17664, 16, -1929.88, -10899.00, 63.1309, 'Matis the Cruel'),
(17664, 17, -1928.43, -10915.90, 62.2858, 'Matis the Cruel'),
(17664, 18, -1903.14, -10949.90, 61.3821, 'Matis the Cruel'),
(17664, 19, -1881.34, -10984.59, 60.8757, 'Matis the Cruel'),
(17664, 20, -1884.31, -11018.90, 60.1304, 'Matis the Cruel'),
(17664, 21, -1884.70, -11057.70, 59.6088, 'Matis the Cruel'),
(17664, 22, -1862.59, -11079.79, 61.1763, 'Matis the Cruel'),
(17664, 23, -1831.73, -11092.59, 63.6176, 'Matis the Cruel'),
(17664, 24, -1810.02, -11123.59, 64.2914, 'Matis the Cruel'),
(17664, 25, -1790.78, -11161.40, 64.3323, 'Matis the Cruel'),
(17664, 26, -1775.80, -11189.20, 63.9911, 'Matis the Cruel'),
(17664, 27, -1779.31, -11226.90, 61.8886, 'Matis the Cruel'),
(17664, 28, -1786.23, -11251.90, 59.9644, 'Matis the Cruel'),
(17664, 29, -1783.09, -11285.29, 58.1493, 'Matis the Cruel'),
(17664, 30, -1772.23, -11312.29, 56.9459, 'Matis the Cruel'),
(17664, 31, -1757.14, -11339.59, 55.9275, 'Matis the Cruel'),
(17664, 32, -1744.31, -11367.40, 54.3308, 'Matis the Cruel'),
(17664, 33, -1738.46, -11406.00, 48.9322, 'Matis the Cruel'),
(17664, 34, -1744.31, -11367.40, 54.3308, 'Matis the Cruel'),
(17664, 35, -1757.14, -11339.59, 55.9275, 'Matis the Cruel'),
(17664, 36, -1772.23, -11312.29, 56.9459, 'Matis the Cruel'),
(17664, 37, -1783.09, -11285.29, 58.1493, 'Matis the Cruel'),
(17664, 38, -1786.23, -11251.90, 59.9644, 'Matis the Cruel'),
(17664, 39, -1779.31, -11226.90, 61.8886, 'Matis the Cruel'),
(17664, 40, -1775.80, -11189.20, 63.9911, 'Matis the Cruel'),
(17664, 41, -1790.78, -11161.40, 64.3323, 'Matis the Cruel'),
(17664, 42, -1810.02, -11123.59, 64.2914, 'Matis the Cruel'),
(17664, 43, -1831.73, -11092.59, 63.6176, 'Matis the Cruel'),
(17664, 44, -1862.59, -11079.79, 61.1763, 'Matis the Cruel'),
(17664, 45, -1884.70, -11057.70, 59.6088, 'Matis the Cruel'),
(17664, 46, -1884.31, -11018.90, 60.1304, 'Matis the Cruel'),
(17664, 47, -1881.34, -10984.59, 60.8757, 'Matis the Cruel'),
(17664, 48, -1903.14, -10949.90, 61.3821, 'Matis the Cruel'),
(17664, 49, -1928.43, -10915.90, 62.2858, 'Matis the Cruel'),
(17664, 50, -1929.88, -10899.00, 63.1309, 'Matis the Cruel'),
(17664, 51, -1921.16, -10884.20, 64.6192, 'Matis the Cruel'),
(17664, 52, -1912.77, -10884.79, 62.6705, 'Matis the Cruel'),
(17664, 53, -1899.84, -10885.50, 66.1876, 'Matis the Cruel'),
(17664, 54, -1890.56, -10888.20, 66.9680, 'Matis the Cruel'),
(17664, 55, -1881.69, -10886.79, 66.8430, 'Matis the Cruel'),
(17664, 56, -1890.56, -10888.20, 66.9680, 'Matis the Cruel'),
(17664, 57, -1899.84, -10885.50, 66.1876, 'Matis the Cruel'),
(17664, 58, -1912.77, -10884.79, 62.6705, 'Matis the Cruel'),
(17664, 59, -1921.16, -10884.20, 64.6192, 'Matis the Cruel'),
(17664, 60, -1934.35, -10883.70, 64.2909, 'Matis the Cruel'),
(17664, 61, -1938.68, -10864.20, 67.2014, 'Matis the Cruel'),
(17664, 62, -1941.42, -10849.59, 70.3264, 'Matis the Cruel'),
(17664, 63, -1934.65, -10841.29, 73.5764, 'Matis the Cruel'),
(17664, 64, -1935.68, -10822.00, 79.8942, 'Matis the Cruel');

UPDATE `creature_template` SET `DamageModifier` = 3.5, `AIName` = 'SmartAI', `HealthModifier` = 4 WHERE (`entry` = 17853);

DELETE FROM `creature_template_addon` WHERE (`entry` = 17853);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 17853);
INSERT INTO `smart_scripts` VALUES
(17853, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 17664, 30, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Just Summoned - Set Orientation Closest Creature \'Matis the Cruel\''),
(17853, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Just Summoned - Say Line 0'),
(17853, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Just Summoned - Set Event Phase 1'),
(17853, 0, 3, 0, 60, 1, 100, 1, 500, 500, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Update - Set Reactstate Aggressive (Phase 1) (No Repeat)'),
(17853, 0, 4, 0, 38, 1, 100, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Data Set 1 1 - Say Line 1 (Phase 1)'),
(17853, 0, 5, 0, 38, 1, 100, 1, 1, 1, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Data Set 1 1 - Set Reactstate Passive (Phase 1) (No Repeat)'),
(17853, 0, 6, 0, 38, 1, 100, 0, 1, 1, 0, 0, 0, 20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Data Set 1 1 - Stop Attacking (Phase 1)'),
(17853, 0, 7, 0, 38, 1, 100, 0, 1, 1, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Data Set 1 1 - Disable Combat Movement (Phase 1)'),
(17853, 0, 8, 0, 38, 1, 100, 0, 1, 1, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Data Set 1 1 - Despawn In 5000 ms (Phase 1)'),
(17853, 0, 9, 0, 38, 1, 100, 0, 1, 1, 0, 0, 0, 15, 9711, 0, 0, 0, 0, 0, 7, 1, 0, 0, 0, 0, 0, 0, 0, 'Tracker of the Hand - On Data Set 1 1 - Quest Credit \'Matis the Cruel\' (Phase 1)');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
