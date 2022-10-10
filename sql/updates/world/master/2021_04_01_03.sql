-- DB update 2021_04_01_02 -> 2021_04_01_03
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_04_01_02';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_04_01_02 2021_04_01_03 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1616686614747472700'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1616686614747472700');

UPDATE `creature_template` SET `faction` = 1647, `DamageModifier` = 1.7, `unit_flags2` = 18432, `type_flags` = 4096, `AIName` = 'SmartAI', `HealthModifier` = 3, `ManaModifier` = 6, `ArmorModifier` = 3 WHERE (`entry` = 17982);

UPDATE `creature` SET `spawntimesecs` = 1 WHERE (`guid` = 63688);

DELETE FROM `creature_addon` WHERE (`guid` IN (63688));

DELETE FROM `creature_template_addon` WHERE (`entry` = 17982);

DELETE FROM `smart_scripts` WHERE (`source_type` = 9 AND `entryorguid` IN (1798200, 1798201, 1798202, 1798203, 1798204));

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 17982);
INSERT INTO `smart_scripts` VALUES
(17982, 0, 0, 0, 19, 0, 100, 0, 9759, 0, 0, 0, 0, 53, 1, 17982, 0, 0, 0, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Quest \'Ending Their World\' Taken - Start Waypoint'),
(17982, 0, 1, 0, 19, 0, 100, 0, 9759, 0, 0, 0, 0, 1, 0, 1500, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Quest \'Ending Their World\' Taken - Say Line 0'),
(17982, 0, 2, 0, 40, 0, 100, 0, 16, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 17678, 200, 0, 0, 0, 0, 0, 1.32052, 'Demolitionist Legoso - On Waypoint 16 Reached - Set Orientation 1.32052'),
(17982, 0, 3, 0, 40, 0, 100, 0, 16, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 16 Reached - Say Line 1'),
(17982, 0, 4, 0, 40, 0, 100, 0, 16, 0, 0, 0, 0, 54, 6000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 16 Reached - Pause Waypoint'),
(17982, 0, 5, 0, 40, 0, 100, 0, 17, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 17 Reached - Say Line 2'),
(17982, 0, 6, 0, 40, 0, 100, 0, 17, 0, 0, 0, 0, 54, 2000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 17 Reached - Pause Waypoint'),
(17982, 0, 7, 0, 40, 0, 100, 0, 18, 0, 0, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 18 Reached - Say Line 3'),
(17982, 0, 8, 9, 40, 0, 100, 0, 18, 0, 0, 0, 0, 54, 7000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 18 Reached - Pause Waypoint'),
(17982, 0, 9, 10, 61, 0, 100, 0, 18, 0, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1953.6, -10653.4, 110.176, 1.54305, 'Demolitionist Legoso - On Waypoint 18 Reached - Summon Gameobject \'Barrel\''),
(17982, 0, 10, 11, 61, 0, 100, 0, 18, 0, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1954.87, -10653.6, 110.363, 1.64319, 'Demolitionist Legoso - On Waypoint 18 Reached - Summon Gameobject \'Barrel\''),
(17982, 0, 11, 12, 61, 0, 100, 0, 18, 0, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1955.95, -10654, 110.731, 1.55483, 'Demolitionist Legoso - On Waypoint 18 Reached - Summon Gameobject \'Barrel\''),
(17982, 0, 12, 13, 61, 0, 100, 0, 18, 0, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1955.17, -10654.7, 110.515, 1.85525, 'Demolitionist Legoso - On Waypoint 18 Reached - Summon Gameobject \'Barrel\''),
(17982, 0, 13, 0, 61, 0, 100, 0, 18, 0, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1954.14, -10654.4, 110.204, 1.74922, 'Demolitionist Legoso - On Waypoint 18 Reached - Summon Gameobject \'Barrel\''),
(17982, 0, 14, 0, 40, 0, 100, 0, 19, 0, 0, 0, 0, 66, 4, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.832369, 'Demolitionist Legoso - On Waypoint 19 Reached - Set Orientation 0.832369'),
(17982, 0, 15, 0, 40, 0, 100, 0, 19, 0, 0, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 19 Reached - Say Line 4'),
(17982, 0, 16, 0, 40, 0, 100, 0, 19, 0, 0, 0, 0, 54, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 19 Reached - Pause Waypoint'),
(17982, 0, 17, 0, 40, 0, 100, 0, 19, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 19 Reached - Set Event Phase 1'),
(17982, 0, 18, 0, 60, 1, 100, 0, 1000, 1000, 20000, 20000, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Say Line 5 (Phase 1)'),
(17982, 0, 19, 0, 60, 1, 100, 0, 2100, 2100, 20000, 20000, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Say Line 6 (Phase 1)'),
(17982, 0, 20, 0, 60, 1, 100, 0, 3100, 3100, 20000, 20000, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Say Line 7 (Phase 1)'),
(17982, 0, 21, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1962.53, -10656.9, 124.125, 0.322799, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 22, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1941.75, -10663.7, 126.462, 0.0636172, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 23, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1954.96, -10660.4, 130.794, 1.08856, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 24, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1928.92, -10673.9, 124.273, 0.0636172, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 25, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1927.21, -10675.4, 134.452, 0.558418, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 26, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1941.15, -10664.8, 141.266, 0.558418, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 27, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1946.89, -10660.3, 139.935, 0.558418, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 28, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1951.09, -10655, 139.902, 0.558418, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 29, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1963.7, -10653.2, 142.875, 6.01694, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 30, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1960.48, -10663.6, 142.474, 1.06893, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 31, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1937.21, -10667.4, 131.39, 0.94719, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 32, 0, 60, 1, 100, 1, 8000, 8000, 0, 0, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1946.76, -10653.3, 119.19, 1.24564, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 1) (No Repeat)'),
(17982, 0, 33, 0, 60, 1, 100, 1, 9000, 9000, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Set Event Phase 0 (Phase 1) (No Repeat)'),
(17982, 0, 34, 0, 40, 0, 100, 0, 20, 0, 0, 0, 0, 1, 8, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 20 Reached - Say Line 8'),
(17982, 0, 35, 0, 40, 0, 100, 0, 20, 0, 0, 0, 0, 54, 3500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 20 Reached - Pause Waypoint'),
(17982, 0, 36, 0, 40, 0, 100, 0, 30, 0, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 30 Reached - Say Line 9'),
(17982, 0, 37, 0, 40, 0, 100, 0, 30, 0, 0, 0, 0, 54, 3500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 30 Reached - Pause Waypoint'),
(17982, 0, 38, 0, 40, 0, 100, 0, 31, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 31 Reached - Set Orientation Closest Player'),
(17982, 0, 39, 0, 40, 0, 100, 0, 31, 0, 0, 0, 0, 1, 10, 0, 0, 0, 0, 0, 21, 20, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 31 Reached - Say Line 10'),
(17982, 0, 40, 0, 40, 0, 100, 0, 31, 0, 0, 0, 0, 54, 4000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 31 Reached - Pause Waypoint'),
(17982, 0, 41, 0, 40, 0, 100, 0, 32, 0, 0, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 32 Reached - Say Line 11'),
(17982, 0, 42, 0, 40, 0, 100, 0, 32, 0, 0, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 32 Reached - Pause Waypoint'),
(17982, 0, 43, 0, 40, 0, 100, 0, 33, 0, 0, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 33 Reached - Say Line 12'),
(17982, 0, 44, 0, 40, 0, 100, 0, 33, 0, 0, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 33 Reached - Pause Waypoint'),
(17982, 0, 45, 0, 40, 0, 100, 0, 34, 0, 0, 0, 0, 54, 6000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 34 Reached - Pause Waypoint'),
(17982, 0, 46, 0, 40, 0, 100, 0, 34, 0, 0, 0, 0, 1, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 34 Reached - Say Line 13'),
(17982, 0, 47, 0, 40, 0, 100, 0, 34, 0, 0, 0, 0, 12, 179820, 7, 5000, 0, 0, 0, 8, 0, 0, 0, 0, -1913.07, -10581.9, 178.527, 6.02656, 'Demolitionist Legoso - On Waypoint 34 Reached - Summon Creature \'Q-9759 Trigger Barrel Bomb\''),
(17982, 0, 48, 0, 40, 0, 100, 0, 35, 0, 0, 0, 0, 1, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 35 Reached - Say Line 14'),
(17982, 0, 49, 0, 40, 0, 100, 0, 35, 0, 0, 0, 0, 54, 2500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 35 Reached - Pause Waypoint'),
(17982, 0, 50, 0, 40, 0, 100, 0, 38, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Waypoint 38 Reached - Set Event Phase 2'),
(17982, 0, 51, 0, 60, 2, 100, 0, 1000, 1000, 20000, 20000, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Say Line 5 (Phase 2)'),
(17982, 0, 52, 0, 60, 2, 100, 0, 2100, 2100, 20000, 20000, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Say Line 6 (Phase 2)'),
(17982, 0, 53, 0, 60, 2, 100, 0, 3100, 3100, 20000, 20000, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Say Line 7 (Phase 2)'),
(17982, 0, 54, 0, 60, 2, 100, 0, 8000, 8000, 40000, 40000, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1906.47, -10583.7, 186.822, 5.31794, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 2)'),
(17982, 0, 55, 0, 60, 2, 100, 0, 8000, 8000, 40000, 40000, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1917.51, -10585.8, 189.25, 4.62287, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 2)'),
(17982, 0, 56, 0, 60, 2, 100, 0, 8000, 8000, 40000, 40000, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1911.4, -10586.1, 195.387, 4.62287, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 2)'),
(17982, 0, 57, 0, 60, 2, 100, 0, 8000, 8000, 40000, 40000, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1919.15, -10587.1, 194.39, 4.62287, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 2)'),
(17982, 0, 58, 0, 60, 2, 100, 0, 8000, 8000, 40000, 40000, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1920.97, -10588.7, 202.086, 4.62287, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 2)'),
(17982, 0, 59, 0, 60, 2, 100, 0, 8000, 8000, 40000, 40000, 0, 50, 182090, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1925.14, -10589.4, 184.482, 5.40826, 'Demolitionist Legoso - On Update - Summon Gameobject \'Vector Coil Fire (L)\' (Phase 2)'),
(17982, 0, 60, 61, 60, 2, 100, 0, 9000, 9000, 40000, 40000, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Set Event Phase 0 (Phase 2)'),
(17982, 0, 61, 62, 61, 0, 100, 0, 9000, 9000, 40000, 40000, 0, 45, 1, 1, 0, 0, 0, 0, 11, 17678, 45, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Set Data 1 1 (Phase 2)'),
(17982, 0, 62, 0, 61, 0, 100, 0, 9000, 9000, 40000, 40000, 0, 1, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Update - Say Line 18 (Phase 2)'),
(17982, 0, 63, 0, 5, 0, 100, 0, 0, 8000, 0, 17678, 0, 45, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Killed Unit - Set Data 1 1'),
(17982, 0, 64, 0, 38, 0, 100, 0, 1, 1, 0, 8000, 0, 1, 19, 2500, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Data Set 1 1 - Say Line 19'),
(17982, 0, 65, 66, 52, 0, 100, 0, 19, 17982, 0, 0, 0, 1, 20, 1700, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Text 19 Over - Say Line 20'),
(17982, 0, 66, 0, 61, 0, 100, 0, 19, 17982, 0, 0, 0, 26, 9759, 0, 0, 0, 0, 0, 18, 45, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Text 19 Over - Quest Credit \'Ending Their World\''),
(17982, 0, 67, 0, 52, 0, 100, 0, 20, 17982, 0, 0, 0, 41, 4500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - On Text 20 Over - Despawn In 4500 ms'),
(17982, 0, 100, 0, 0, 0, 100, 0, 5000, 5000, 12000, 12000, 0, 11, 8056, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - In Combat - Cast \'Frost Shock\''),
(17982, 0, 101, 0, 2, 0, 100, 0, 1, 45, 9000, 9000, 0, 11, 913, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - Between 1-45% Health - Cast \'Healing Wave\''),
(17982, 0, 102, 0, 0, 0, 100, 0, 500, 500, 30000, 30000, 0, 11, 325, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Demolitionist Legoso - In Combat - Cast \'Lightning Shield\'');

DELETE FROM `waypoints` WHERE (`entry` = 17982);
INSERT INTO `waypoints` VALUES 
(17982, 1, -1772.70, -11074.70, 78.9523, 'Demonitiolist Lagoso'),
(17982, 2, -1790.27, -11053.81, 78.9543, 'Demonitiolist Lagoso'),
(17982, 3, -1798.05, -11032.88, 73.2248, 'Demonitiolist Lagoso'),
(17982, 4, -1827.51, -11017.92, 67.2534, 'Demonitiolist Lagoso'),
(17982, 5, -1879.67, -10988.88, 60.7772, 'Demonitiolist Lagoso'),
(17982, 6, -1929.85, -10909.55, 62.5501, 'Demonitiolist Lagoso'),
(17982, 7, -1940.70, -10846.87, 71.2584, 'Demonitiolist Lagoso'),
(17982, 8, -1931.54, -10837.23, 74.8954, 'Demonitiolist Lagoso'),
(17982, 9, -1937.94, -10808.30, 84.5661, 'Demonitiolist Lagoso'),
(17982, 10, -1944.59, -10798.88, 87.3097, 'Demonitiolist Lagoso'),
(17982, 11, -1895.12, -10770.07, 101.9580, 'Demonitiolist Lagoso'),
(17982, 12, -1887.79, -10754.76, 106.6948, 'Demonitiolist Lagoso'),
(17982, 13, -1883.62, -10728.73, 111.6938, 'Demonitiolist Lagoso'),
(17982, 14, -1944.28, -10706.12, 111.6414, 'Demonitiolist Lagoso'),
(17982, 15, -1960.67, -10688.54, 111.2230, 'Demonitiolist Lagoso'),
(17982, 16, -1960.28, -10687.04, 111.0856, 'Demonitiolist Lagoso'),
(17982, 17, -1957.16, -10679.88, 110.5308, 'Demonitiolist Lagoso'),
(17982, 18, -1956.81, -10654.30, 111.0142, 'Demonitiolist Lagoso'),
(17982, 19, -1977.02, -10705.33, 114.4567, 'Demonitiolist Lagoso'),
(17982, 20, -1980.37, -10701.60, 114.4284, 'Demonitiolist Lagoso'),
(17982, 21, -1997.29, -10680.81, 118.0604, 'Demonitiolist Lagoso'),
(17982, 22, -2021.17, -10654.56, 127.8307, 'Demonitiolist Lagoso'),
(17982, 23, -2035.65, -10637.71, 140.1543, 'Demonitiolist Lagoso'),
(17982, 24, -2043.83, -10622.95, 145.5923, 'Demonitiolist Lagoso'),
(17982, 25, -2043.83, -10622.95, 145.5923, 'Demonitiolist Lagoso'),
(17982, 26, -2043.83, -10622.95, 145.5923, 'Demonitiolist Lagoso'),
(17982, 27, -2043.83, -10622.95, 145.5923, 'Demonitiolist Lagoso'),
(17982, 28, -2043.83, -10622.95, 145.5923, 'Demonitiolist Lagoso'),
(17982, 29, -2018.91, -10603.98, 152.7457, 'Demonitiolist Lagoso'),
(17982, 30, -1985.64, -10611.87, 163.4069, 'Demonitiolist Lagoso'),
(17982, 31, -1963.00, -10607.08, 165.5145, 'Demonitiolist Lagoso'),
(17982, 32, -1944.21, -10575.63, 175.3522, 'Demonitiolist Lagoso'),
(17982, 33, -1939.01, -10577.16, 175.9011, 'Demonitiolist Lagoso'),
(17982, 34, -1914.03, -10582.93, 178.4607, 'Demonitiolist Lagoso'),
(17982, 35, -1923.24, -10572.15, 177.1505, 'Demonitiolist Lagoso'),
(17982, 36, -1948.92, -10557.29, 177.5732, 'Demonitiolist Lagoso'),
(17982, 37, -1955.57, -10564.50, 177.6642, 'Demonitiolist Lagoso'),
(17982, 38, -1951.06, -10560.76, 177.7242, 'Demonitiolist Lagoso');

DELETE FROM `creature_template` WHERE (`entry` = 179820);
INSERT INTO `creature_template` VALUES
(179820, 0, 0, 0, 0, 0, 24860, 0, 0, 0, 'Q-9759 Trigger Barrel Bomb', '', '', 0, 1, 1, 0, 35, 0, 1, 1.14286, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'SmartAI', 0, 3, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, '', 0);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 179820);
INSERT INTO `smart_scripts` VALUES
(179820, 0, 0, 0, 60, 0, 100, 0, 3000, 3000, 20000, 20000, 0, 45, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel Bomb - On Update - Set Data 1 1'),
(179820, 0, 1, 2, 38, 0, 100, 1, 1, 1, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel Bomb - On Data Set 1 1 - Set Event Phase 0 (No Repeat)'),
(179820, 0, 2, 3, 61, 0, 100, 0, 1, 1, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1913.07, -10581.9, 178.527, 6.02656, 'Barrel Bomb - On Data Set 1 1 - Summon Gameobject \'Barrel\' (No Repeat)'),
(179820, 0, 3, 4, 61, 0, 100, 0, 1, 1, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1912.73, -10581, 178.461, 6.02656, 'Barrel Bomb - On Data Set 1 1 - Summon Gameobject \'Barrel\' (No Repeat)'),
(179820, 0, 4, 5, 61, 0, 100, 0, 1, 1, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1911.79, -10580.7, 178.813, 5.86163, 'Barrel Bomb - On Data Set 1 1 - Summon Gameobject \'Barrel\' (No Repeat)'),
(179820, 0, 5, 6, 61, 0, 100, 0, 1, 1, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1912.02, -10581.7, 178.84, 5.86163, 'Barrel Bomb - On Data Set 1 1 - Summon Gameobject \'Barrel\' (No Repeat)'),
(179820, 0, 6, 7, 61, 0, 100, 0, 1, 1, 0, 0, 0, 50, 180779, 120, 0, 0, 0, 0, 8, 0, 0, 0, 0, -1912.52, -10582.6, 178.727, 5.89108, 'Barrel Bomb - On Data Set 1 1 - Summon Gameobject \'Barrel\' (No Repeat)'),
(179820, 0, 7, 0, 61, 0, 100, 0, 1, 1, 0, 0, 0, 41, 22000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel Bomb - On Data Set 1 1 - Despawn In 22000 ms (No Repeat)');

UPDATE `gameobject_template` SET `AIName` = 'SmartGameObjectAI' WHERE (`entry` = 180779);

DELETE FROM `smart_scripts` WHERE (`source_type` = 1 AND `entryorguid` = 180779);
INSERT INTO `smart_scripts` VALUES
(180779, 1, 0, 0, 63, 0, 100, 1, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel - On Just Created - Set Event Phase 1 (No Repeat)'),
(180779, 1, 1, 2, 60, 1, 100, 1, 20000, 20000, 0, 0, 0, 11, 71495, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel - On Update - Cast \'Explosion Visual\' (Phase 1) (No Repeat)'),
(180779, 1, 2, 0, 61, 0, 100, 0, 20000, 20000, 0, 0, 0, 41, 1100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Barrel - On Update - Despawn In 1100 ms (Phase 1) (No Repeat)');

UPDATE `creature_template` SET `DamageModifier` = 1.1, `AIName` = 'SmartAI' WHERE (`entry` = 17678);

UPDATE `creature` SET `spawntimesecs` = 1 WHERE (`guid` = 63402);

DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryorguid` = 17678);
INSERT INTO `smart_scripts` VALUES
(17678, 0, 0, 2, 1, 0, 100, 0, 1000, 1000, 10000, 10000, 0, 11, 31612, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - Out of Combat - Cast \'Sironas Channeling\''),
(17678, 0, 1, 2, 21, 0, 100, 0, 0, 0, 0, 0, 0, 11, 31612, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - On Reached Home - Cast \'Sironas Channeling\''),
(17678, 0, 2, 0, 61, 0, 100, 0, 1000, 1000, 10000, 10000, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - Out of Combat - Set Flags Immune To Players & Immune To NPC\'s'),
(17678, 0, 3, 0, 0, 0, 100, 0, 7000, 9000, 11000, 11000, 0, 11, 12742, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - In Combat - Cast \'Immolate\''),
(17678, 0, 4, 0, 0, 0, 100, 0, 6000, 7000, 25000, 25000, 0, 11, 8282, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - In Combat - Cast \'Curse of Blood\''),
(17678, 0, 5, 0, 0, 0, 100, 0, 4000, 4000, 15000, 15000, 0, 11, 10966, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - In Combat - Cast \'Uppercut\''),
(17678, 0, 6, 7, 38, 0, 100, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - On Data Set 1 1 - Say Line 0'),
(17678, 0, 7, 8, 61, 0, 100, 0, 1, 1, 0, 0, 0, 51, 0, 0, 0, 0, 0, 0, 11, 17979, 100, 0, 0, 0, 0, 0, 0, 'Sironas - On Data Set 1 1 - Kill Target'),
(17678, 0, 8, 9, 61, 0, 100, 0, 1, 1, 0, 0, 0, 28, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - On Data Set 1 1 - Remove Aura \'null\''),
(17678, 0, 9, 10, 61, 0, 100, 0, 1, 1, 0, 0, 0, 75, 47114, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - On Data Set 1 1 - Add Aura \'Scorchling Grow\''),
(17678, 0, 10, 11, 61, 0, 100, 0, 1, 1, 0, 0, 0, 75, 47114, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - On Data Set 1 1 - Add Aura \'Scorchling Grow\''),
(17678, 0, 11, 12, 61, 0, 100, 0, 1, 1, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - On Data Set 1 1 - Remove Flags Immune To Players & Immune To NPC\'s'),
(17678, 0, 12, 0, 61, 0, 100, 0, 1, 1, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 19, 17982, 100, 0, 0, 0, 0, 0, 0, 'Sironas - On Data Set 1 1 - Start Attacking'),
(17678, 0, 13, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 17982, 45, 0, 0, 0, 0, 0, 0, 'Sironas - On Just Died - Set Data 1 1'),
(17678, 0, 14, 0, 6, 0, 100, 0, 0, 0, 0, 0, 0, 41, 7000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Sironas - On Just Died - Despawn In 7000 ms');

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
