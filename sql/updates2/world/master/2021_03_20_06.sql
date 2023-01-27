-- DB update 2021_03_20_05 -> 2021_03_20_06
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_03_20_05';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_03_20_05 2021_03_20_06 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616012094656299200'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616012094656299200');

DELETE FROM `event_scripts` WHERE (`id` = 10685) and (`datalong` IN (17359, 6748));
INSERT INTO `event_scripts` VALUES
(10685, 2, 10, 17359, 900000, 0, -1651.199219, -10924.120117, 58.633022, 4.135927),
(10685, 5, 10, 6748, 900000, 0, -1637.901978, -10915.750977, 58.330589, 4.159483),
(10685, 5, 10, 6748, 900000, 0, -1647.273315, -10907.033203, 58.325653, 4.565927);

DELETE FROM `creature_text` WHERE (`CreatureID` IN (17359, 6748));
INSERT INTO `creature_text` VALUES
(17359, 0, 0, 'What have you done to my life\s work?! DIE!!!', 12, 0, 100, 0, 1500, 0, 0, 0, 'Tel\athion the Impure'),
(17359, 1, 0, 'It is YOU who are wrong! I will deal with you two after I have slain this meddlesome shaman!', 12, 0, 100, 0, 1500, 0, 0, 0, 'Tel\athion the Impure'),
(6748, 0, 0, 'Wrong! It is YOU that will die, Tel\athion the Impure!', 12, 0, 100, 0, 1500, 0, 0, 0, 'Water Spirit');

UPDATE `creature_template` SET `ArmorModifier` = 3, `AIName` = 'SmartAI', `resistance1` = 90, `resistance2` = 90, `resistance3` = 90, `resistance4` = 90, `resistance5` = 90, `resistance6` = 90 WHERE (`entry` = 17359);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 17359);
INSERT INTO `smart_scripts` VALUES
(17359, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - On Just Summoned - Set Run On'),
(17359, 0, 1, 0, 0, 0, 100, 1, 100, 100, 0, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1646.4, -10918.7, 58.9241, 4.78159, 'Tel\'athion the Impure - In Combat - Move To Position (No Repeat)'),
(17359, 0, 2, 0, 60, 0, 100, 1, 3000, 3000, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - On Update - Set Event Phase 1 (No Repeat)'),
(17359, 0, 3, 0, 60, 1, 100, 1, 1000, 1000, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 30, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - On Update - Start Attacking (Phase 1) (No Repeat)'),
(17359, 0, 4, 0, 0, 1, 100, 1, 1000, 1000, 0, 0, 0, 1, 0, 1000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - In Combat - Say Line 0 (Phase 1) (No Repeat)'),
(17359, 0, 5, 0, 0, 1, 100, 0, 5000, 5000, 5000, 5000, 0, 11, 9672, 66, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - In Combat - Cast \'Frostbolt\' (Phase 1)'),
(17359, 0, 6, 0, 0, 1, 100, 1, 6200, 6200, 0, 0, 0, 1, 1, 1500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - In Combat - Say Line 1 (Phase 1) (No Repeat)'),
(17359, 0, 7, 0, 0, 1, 100, 0, 6200, 6200, 5000, 5000, 0, 11, 13339, 66, 0, 0, 0, 0, 5, 6748, 30, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - In Combat - Cast \'Fire Blast\' (Phase 1)'),
(17359, 0, 8, 0, 9, 1, 100, 0, 0, 10, 13000, 13000, 0, 11, 11831, 66, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - Within 0-10 Range - Cast \'Frost Nova\' (Phase 1)'),
(17359, 0, 9, 0, 0, 1, 100, 0, 8000, 8000, 10000, 10000, 0, 11, 15735, 66, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - In Combat - Cast \'Arcane Missiles\' (Phase 1)'),
(17359, 0, 10, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - On Evade - Despawn In 1000 ms (Phase 1)'),
(17359, 0, 11, 0, 6, 1, 100, 0, 0, 0, 0, 0, 0, 41, 60000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Tel\'athion the Impure - On Just Died - Despawn In 60000 ms (Phase 1)');

UPDATE `creature_template` SET `faction` = 1655, `AIName` = 'SmartAI', `type_flags` = 0, `resistance1` = 10, `resistance2` = 60, `resistance3` = 50, `resistance4` = 60, `resistance5` = 10, `resistance6` = 10 WHERE (`entry` = 6748);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 6748);
INSERT INTO `smart_scripts` VALUES
(6748, 0, 0, 0, 60, 0, 100, 1, 5000, 5000, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Water Spirit - On Update - Set Event Phase 1 (No Repeat)'),
(6748, 0, 1, 0, 75, 1, 100, 1, 0, 17359, 13, 500, 0, 1, 0, 1500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Water Spirit - On Distance To Creature - Say Line 0 (Phase 1) (No Repeat)'),
(6748, 0, 2, 0, 52, 1, 100, 1, 0, 6748, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 11, 17359, 30, 0, 0, 0, 0, 0, 0, 'Water Spirit - On Text 0 Over - Start Attacking (Phase 1) (No Repeat)'),
(6748, 0, 3, 0, 7, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Water Spirit - On Evade - Despawn In 1000 ms (Phase 1)'),
(6748, 0, 4, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Water Spirit - On Evade - Despawn In 1000 ms'),
(6748, 0, 5, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Water Spirit - On Just Died - Despawn In 1000 ms'),
(6748, 0, 6, 0, 6, 1, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Water Spirit - On Just Died - Despawn In 1000 ms (Phase 1)');

DELETE FROM `gameobject` WHERE (`id` = 181699);
INSERT INTO `gameobject` VALUES
(28522, 181699, 530, 0, 0, 1, 1, -1647.35, -10922.1, 58.8833, 4.53641, 0, 0, -0.76651, 0.642232, 300, 0, 1, '', 0);

UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 181699;

DELETE FROM `smart_scripts` WHERE (`source_type` = 1 AND `entryorguid` = 181699);
INSERT INTO `smart_scripts` VALUES
(181699, 1, 0, 2, 70, 0, 100, 0, 1, 0, 0, 0, 0, 202, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel of Filth - On Gameobject State Changed - Set GO state to 0'),
(181699, 1, 1, 0, 60, 0, 100, 0, 500, 500, 240000, 240000, 0, 202, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel of Filth - On Update - Set GO state to 1'),
(181699, 1, 2, 21, 61, 0, 100, 0, 1, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel of Filth - On Gameobject State Changed - Set Event Phase 1'),
(181699, 1, 3, 0, 60, 1, 100, 0, 100, 100, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1646.49, -10923, 58.9432, 4.45983, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 4, 0, 60, 1, 100, 0, 200, 200, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1645.43, -10923.1, 58.9586, 4.55997, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 5, 0, 60, 1, 100, 0, 300, 300, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1644.23, -10923.2, 58.8715, 4.76613, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 6, 0, 60, 1, 100, 0, 400, 400, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1643.32, -10924.3, 58.7962, 4.55997, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 7, 0, 60, 1, 100, 0, 500, 500, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1644.36, -10924, 58.9024, 4.70723, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 8, 0, 60, 1, 100, 0, 600, 600, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1644.88, -10925.2, 58.9533, 4.6012, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 9, 0, 60, 1, 100, 0, 700, 700, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1642.46, -10925.3, 58.7492, 4.75435, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 10, 0, 60, 1, 100, 0, 800, 800, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1643.59, -10925.4, 58.8521, 4.64244, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 11, 0, 60, 1, 100, 0, 900, 900, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1644.88, -10925.2, 58.9533, 4.65422, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 12, 0, 60, 1, 100, 0, 1000, 1000, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1646.05, -10925, 59.0046, 4.55997, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 13, 0, 60, 1, 100, 0, 1100, 1100, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1643.49, -10926.5, 58.9367, 1.38105, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 14, 0, 60, 1, 100, 0, 1200, 1200, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1644.75, -10926.2, 59.0393, 1.45763, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 15, 0, 60, 1, 100, 0, 1300, 1300, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1645.85, -10926.2, 59.1919, 1.44585, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 16, 0, 60, 1, 100, 0, 1400, 1400, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1644.88, -10927.3, 59.214, 1.40462, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 17, 0, 60, 1, 100, 0, 1500, 1500, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1646.07, -10927.1, 59.3079, 1.36338, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 18, 0, 60, 1, 100, 0, 1600, 1600, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1647.04, -10926.6, 59.1369, 1.169, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 19, 0, 60, 1, 100, 0, 1700, 1700, 1000, 1000, 0, 50, 181699, 4, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1648.4, -10926.7, 59.0437, 1.35749, 'Barrel of Filth - On Update - Summon Gameobject \'Barrel of Filth\' (Phase 1)'),
(181699, 1, 20, 0, 60, 1, 100, 0, 2500, 2500, 4500, 4500, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel of Filth - On Update - Set Event Phase 0 (Phase 1)'),
(181699, 1, 21, 0, 61, 1, 100, 0, 1, 0, 0, 0, 0, 11, 69657, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel of Filth - On Gameobject State Changed - Cast \'Water Splash (Self)\''),
(181699, 1, 22, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, 11, 69657, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel of Filth - On Just Created - Cast \'Water Splash (Self)\'');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
