-- DB update 2021_04_01_11 -> 2021_04_01_12
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_11';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_11 2021_04_01_12 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1617153703041946200'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1617153703041946200');

UPDATE `creature_template` SET `speed_walk` = 1, `HealthModifier` = 3, `ManaModifier` = 3, `ArmorModifier` = 3, `AIName` = 'SmartAI' WHERE (`entry` = 2433);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 2433);
INSERT INTO `smart_scripts` VALUES
(2433, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 2433, 0, 0, 10000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Respawn - Start Waypoint'),
(2433, 0, 1, 0, 1, 0, 1, 1, 1500, 1500, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - Out of Combat - Say Line 0 (No Repeat)'),
(2433, 0, 2, 0, 1, 0, 1, 1, 1500, 1500, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - Out of Combat - Say Line 1 (No Repeat)'),
(2433, 0, 3, 0, 1, 0, 1, 1, 1500, 1500, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - Out of Combat - Say Line 2 (No Repeat)'),
(2433, 0, 4, 0, 1, 0, 1, 1, 1500, 1500, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - Out of Combat - Say Line 3 (No Repeat)'),
(2433, 0, 5, 0, 4, 0, 70, 0, 0, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Aggro - Say Line 4'),
(2433, 0, 6, 0, 4, 0, 100, 0, 0, 0, 0, 0, 0, 11, 4950, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Aggro - Cast \'Summon Helcular`s Puppets\''),
(2433, 0, 7, 11, 5, 0, 100, 0, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Killed Unit - Say Line 5'),
(2433, 0, 8, 0, 60, 0, 100, 1, 500, 500, 0, 0, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Update - Enable Combat Movement (No Repeat)'),
(2433, 0, 9, 0, 75, 0, 100, 0, 0, 2386, 25, 4500, 0, 49, 0, 0, 0, 0, 0, 0, 11, 2386, 25, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Distance To Creature - Start Attacking'),
(2433, 0, 10, 0, 11, 0, 100, 0, 0, 0, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Respawn - Set Reactstate Defensive'),
(2433, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 11, 4950, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Helcular\'s Remains - On Killed Unit - Cast \'Summon Helcular`s Puppets\'');

DELETE FROM `waypoints` WHERE (`entry` IN (2433));
INSERT INTO `waypoints` VALUES
(2433, 1, -749.03, -598.01, 18.4133, 'Helcular Remains'),
(2433, 2, -773.83, -587.81, 15.9183, 'Helcular Remains'),
(2433, 3, -747.35, -586.21, 19.8563, 'Helcular Remains'),
(2433, 4, -755.06, -570.77, 19.3430, 'Helcular Remains'),
(2433, 5, -773.37, -546.27, 17.8202, 'Helcular Remains'),
(2433, 6, -820.27, -533.12, 15.0504, 'Helcular Remains'),
(2433, 7, -842.47, -540.02, 12.7530, 'Helcular Remains'),
(2433, 8, -864.46, -521.96, 10.8711, 'Helcular Remains'),
(2433, 9, -878.53, -532.17, 10.0846, 'Helcular Remains'),
(2433, 10, -921.94, -524.36, 6.8796, 'Helcular Remains'),
(2433, 11, -904.65, -545.08, 6.8796, 'Helcular Remains'),
(2433, 12, -900.60, -577.46, 6.8796, 'Helcular Remains');

UPDATE `creature_template` SET `rank` = 1, `DamageModifier` = 5, `AIName` = 'SmartAI', `HealthModifier` = 3, `ArmorModifier` = 3 WHERE (`entry` = 2946);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 2946);
INSERT INTO `smart_scripts` VALUES
(2946, 0, 1, 0, 75, 0, 100, 0, 0, 2386, 30, 4500, 0, 21, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Puppet of Helcular - On Distance To Creature - Enable Combat Movement'),
(2946, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Puppet of Helcular - On Just Summoned - Set Reactstate Aggressive');

DELETE FROM `factiontemplate_dbc` WHERE (`ID` IN (83, 96));
INSERT INTO `factiontemplate_dbc` VALUES
(83, 66, 0, 4, 4, 10, 79, 0, 0, 0, 66, 0, 0, 0),
(96, 79, 0, 2, 2, 0, 66, 0, 0, 0, 79, 0, 0, 0);

DELETE FROM `broadcast_text` WHERE (`ID` IN (599, 600, 601, 602, 603, 604));
INSERT INTO `broadcast_text` VALUES
(599, 0, 'Revenge shall be mine at last!','', 0, 0, 0, 0, 0, 0, 0, 0, 6, 18019),
(600, 0, 'I have risen!','', 0, 0, 0, 0, 0, 0, 0, 0, 6, 18019),
(601, 0, 'Southshore shall pay in blood!','', 0, 0, 0, 0, 0, 0, 0, 0, 6, 18019),
(602, 0, 'I returned from the grave to take my revenge!','', 0, 0, 0, 0, 0, 0, 0, 0, 6, 18019),
(603, 0, 'The undead shall feast on your soul, $n.','', 0, 0, 0, 0, 0, 0, 0, 0, 6, 18019),
(604, 0, 'Die in the name of the Dark Lady, $n.','', 0, 0, 0, 0, 0, 0, 0, 0, 6, 18019);

DELETE FROM `creature_text` WHERE (`CreatureID` IN (2433));
INSERT INTO `creature_text` VALUES
(2433, 0, 0, 'Revenge shall be mine at last!', 14, 0, 100, 15, 1500, 0, 0, 1, 'Helcular\'s Remains'),
(2433, 1, 1, 'I have risen!', 14, 0, 100, 15, 1500, 0, 0, 1, 'Helcular\'s Remains'),
(2433, 2, 2, 'Southshore shall pay in blood!', 14, 0, 100, 15, 1500, 0, 0, 1, 'Helcular\'s Remains'),
(2433, 3, 3, 'I returned from the grave to take my revenge!', 14, 0, 100, 15, 1500, 0, 0, 1, 'Helcular\'s Remains'),
(2433, 4, 0, 'The undead shall feast on your soul, $n.', 14, 0, 100, 0, 1500, 0, 0, 1, 'Helcular\'s Remains'),
(2433, 5, 0, 'Die in the name of the Dark Lady, $n.', 14, 0, 100, 0, 1500, 0, 0, 1, 'Helcular\'s Remains');

UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE `entry` = 1767;

DELETE FROM `smart_scripts` WHERE (`source_type` = 1 AND `entryorguid` = 1767);
INSERT INTO `smart_scripts` VALUES
(1767, 1, 0, 0, 20, 0, 100, 0, 553, 0, 0, 0, 0, 12, 2433, 7, 60000, 0, 0, 0, 8, 0, 0, 0, 0, -740.43, -621.57, 18.6447, 3.2299, 'Helcular\'s Grave - On Quest \'Helcular\'s Revenge\' Finished - Summon Creature \'Helcular\'s Remains\'');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
