-- DB update 2021_02_28_00 -> 2021_02_28_01
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_28_00';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_28_00 2021_02_28_01 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1614294683092657800'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1614294683092657800');

UPDATE `creature_template` SET `faction` = 123, `AIName` = 'SmartAI' WHERE `entry` IN (2060,2061,2062,2063,2064,2065,2066,2067,2068);

UPDATE `creature_template` SET `faction` = 123 WHERE `entry` =1893;

DELETE FROM `smart_scripts` WHERE (`source_type` = 0) AND (`entryorguid` IN (2060,2061,2062,2063,2064,2065,2066,2067,2068));
INSERT INTO `smart_scripts` VALUES
(2060, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Smithers - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2060, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Smithers - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2060, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Smithers - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2060, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Smithers - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2060, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Smithers - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2060, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Smithers - On Evade - Despawn In 1500 ms (Phase 1)'),
(2060, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Smithers - On Evade - Despawn In 1500 ms'),
(2061, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Thatcher - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2061, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Thatcher - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2061, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Thatcher - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2061, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Thatcher - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2061, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Thatcher - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2061, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Thatcher - On Evade - Despawn In 1500 ms (Phase 1)'),
(2061, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Thatcher - On Evade - Despawn In 1500 ms'),
(2062, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hendricks - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2062, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hendricks - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2062, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hendricks - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2062, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hendricks - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2062, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hendricks - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2062, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hendricks - On Evade - Despawn In 1500 ms (Phase 1)'),
(2062, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hendricks - On Evade - Despawn In 1500 ms'),
(2063, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Wilhelm - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2063, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Wilhelm - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2063, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Wilhelm - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2063, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Wilhelm - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2063, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Wilhelm - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2063, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Wilhelm - On Evade - Despawn In 1500 ms (Phase 1)'),
(2063, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Wilhelm - On Evade - Despawn In 1500 ms'),
(2064, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hartin - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2064, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hartin - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2064, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hartin - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2064, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hartin - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2064, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hartin - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2064, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hartin - On Evade - Despawn In 1500 ms (Phase 1)'),
(2064, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Hartin - On Evade - Despawn In 1500 ms'),
(2065, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Cooper - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2065, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Cooper - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2065, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Cooper - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2065, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Cooper - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2065, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Cooper - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2065, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Cooper - On Evade - Despawn In 1500 ms (Phase 1)'),
(2065, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Cooper - On Evade - Despawn In 1500 ms'),
(2066, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Higarth - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2066, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Higarth - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2066, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Higarth - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2066, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Higarth - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2066, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Higarth - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2066, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Higarth - On Evade - Despawn In 1500 ms (Phase 1)'),
(2066, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Higarth - On Evade - Despawn In 1500 ms'),
(2067, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Brunswick - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2067, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Brunswick - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2067, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Brunswick - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2067, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Brunswick - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2067, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Brunswick - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2067, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Brunswick - On Evade - Despawn In 1500 ms (Phase 1)'),
(2067, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Councilman Brunswick - On Evade - Despawn In 1500 ms'),
(2068, 0, 0, 1, 2, 0, 25, 1, 70, 80, 0, 0, 0, 36, 1893, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Mayor Morrison - Between 70-80% Health - Update Template To \'Moonrage Sentry\' (No Repeat)'),
(2068, 0, 1, 2, 61, 0, 100, 0, 70, 80, 0, 0, 0, 11, 24085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Mayor Morrison - Between 70-80% Health - Cast \'Transform Visual\' (No Repeat)'),
(2068, 0, 2, 0, 61, 0, 100, 0, 70, 80, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Mayor Morrison - Between 70-80% Health - Set Event Phase 1 (No Repeat)'),
(2068, 0, 3, 0, 0, 1, 100, 0, 100, 100, 60000, 60000, 0, 11, 6507, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Mayor Morrison - In Combat - Cast \'Battle Roar\' (Phase 1)'),
(2068, 0, 4, 0, 0, 1, 100, 0, 800, 800, 60000, 60000, 0, 11, 13730, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Mayor Morrison - In Combat - Cast \'Demoralizing Shout\' (Phase 1)'),
(2068, 0, 5, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Mayor Morrison - On Evade - Despawn In 1500 ms (Phase 1)'),
(2068, 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Lord Mayor Morrison - On Evade - Despawn In 1500 ms');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
