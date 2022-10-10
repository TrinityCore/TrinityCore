-- DB update 2021_02_01_05 -> 2021_02_01_06
DROP PROCEDURE IF EXISTS `updateDb`;
DELIMITER //
CREATE PROCEDURE updateDb ()
proc:BEGIN DECLARE OK VARCHAR(100) DEFAULT 'FALSE';
SELECT COUNT(*) INTO @COLEXISTS
FROM information_schema.COLUMNS
WHERE TABLE_SCHEMA = DATABASE() AND TABLE_NAME = 'version_db_world' AND COLUMN_NAME = '2021_02_01_05';
IF @COLEXISTS = 0 THEN LEAVE proc; END IF;
START TRANSACTION;
ALTER TABLE version_db_world CHANGE COLUMN 2021_02_01_05 2021_02_01_06 bit;
SELECT sql_rev INTO OK FROM version_db_world WHERE sql_rev = '1611254109213696316'; IF OK <> 'FALSE' THEN LEAVE proc; END IF;
--
-- START UPDATING QUERIES
--

INSERT INTO `version_db_world` (`sql_rev`) VALUES ('1611254109213696316');

-- Quest: Tomb of the Lightbringer
-- Ported over from: https://github.com/TrinityCore/TrinityCore/issues/14733

-- Old scripts cleanup
DELETE FROM `script_waypoint` WHERE `entry`=17238;

-- Creature text
DELETE FROM `creature_text` WHERE `CreatureID`=17238;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `TextRange`, `comment`, `BroadcastTextId`) VALUES
(17238, 0, 0, "Shall we begin, my friend?", 12, 7, 100, 6, 0, 0, 0, "Q Tomb of the Lighbringer", 13613),
(17238, 1, 0, "This area is known to be full of foul Scourge.  You may want to take a moment to prepare any defenses at your disposal.", 12, 7, 100, 1, 0, 0, 0, "Q Tomb of the Lighbringer", 13614),
(17238, 2, 0, "Beware!  We are attacked!", 12, 7, 100, 5, 0, 0, 0, "Q Tomb of the Lighbringer", 13616),
(17238, 3, 0, "It must be the purity of the Mark of the Lightbringer that is drawing forth the Scourge to us.  We must proceed with caution lest we be overwhelmed!", 12, 7, 100, 1, 0, 0, 0, "Q Tomb of the Lighbringer", 13617),
(17238, 4, 0, "We are beset upon again! Defend yourself!", 12, 7, 100, 5, 0, 0, 0, "Q Tomb of the Lighbringer", 13618),
(17238, 5, 0, "This land truly needs to be cleansed by the Light!  Let us continue on to the tomb.  It isn't far now.", 12, 7, 100, 1, 0, 0, 0, "Q Tomb of the Lighbringer", 13619),
(17238, 6, 0, "Very well, let us continue.", 12, 7, 100, 1, 0, 0, 0, "Q Tomb of the Lighbringer", 13615),
(17238, 7, 0, "Thank you my friend for making this possible.  This is a day that I shall never forget!  I think I will stay a while.  Please return to High Priestess MacDonnell at the camp.  I know that she'll be keenly interested to know of what has transpired here.", 12, 7, 100, 2, 0, 0, 0, "Q Tomb of the Lighbringer", 13624);

-- Anchorite Truuen AI
UPDATE `creature_template` SET `ScriptName`="", `AIName`="SmartAI" WHERE `entry` IN (17238, 17233);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (17238, 17233);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryorguid` IN (1723800, 1723801, 1723300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17238, 0, 0, 1, 19, 0, 100, 0, 9446, 0, 0, 0, 1, 0, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Quest Taken - Say text'),
(17238, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 17238, 0, 9446, 45000, 1, 17, 0, 30, 0, 0, 0, 0, 0, 'Anchorite Truuen - Quest Taken - Start WP'),
(17238, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Quest Taken - Pause before movements'),
(17238, 0, 3, 18, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Quest Taken - Remove npc flag'),
(17238, 0, 4, 5, 40, 0, 100, 0, 4, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Pause at WP 3'),
(17238, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Speak'),
(17238, 0, 6, 7, 40, 0, 100, 0, 9, 0, 0, 0, 12, 4472, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1039.984, -1577.659, 61.437, 1.753951, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 12, 1802, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1031.033, -1576.279, 62.436, 0.265621, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Say text'),
(17238, 0, 9, 0, 40, 0, 100, 0, 11, 0, 0, 0, 1, 3, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Say text'),
(17238, 0, 10, 11, 40, 0, 100, 0, 16, 0, 0, 0, 1, 4, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Say text'),
(17238, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 12, 4475, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1110.658, -1742.137, 61.019, 2.413687, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 12, 4475, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1106.837, -1750.592, 61.174, 2.409762, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 12, 4475, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1111.725, -1753.404, 61.459, 2.755339, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 4475, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1117.459, -1743.327, 61.000, 2.853514, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 15, 0, 40, 0, 100, 0, 19, 0, 0, 0, 1, 5, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - say text'),
(17238, 0, 16, 17, 40, 0, 100, 0, 31, 0, 0, 0, 12, 17233, 3, 60000, 0, 0, 0, 8, 0, 0, 0, 971.801, -1825.102, 84, 0.29408, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 17, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Kneels'),
(17238, 0, 18, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On quest taken - Set Faction'),
(17238, 0, 19, 0, 40, 0, 100, 0, 4, 0, 0, 0, 80, 1723800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Action list'),
(1723800, 9, 0, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Action list - Say text'),
(17238, 0, 20, 0, 38, 0, 100, 0, 0, 1, 0, 0, 80, 1723801, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On data set - Action list'),
(1723801, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Action list - remove kneel'),
(1723801, 9, 1, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Action list - Say text'),
(1723801, 9, 2, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Action list - Despawns'),
(17233, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, 1723300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghost of Uther - Just summoned - Action list'),
(1723300, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghost of Uther - Action list - Say text'),
(1723300, 9, 1, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghost of Uther - Action list - Say text'),
(1723300, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 45, 0, 1, 0, 0, 0, 0, 19, 17238, 20, 0, 0, 0, 0, 0, 'Ghost of Uther - Action list - Set data'),
(1723300, 9, 3, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghost of Uther - Action list - Despawn');

-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=17238;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(17238, 1,   954.51, -1433.0245, 63.16, "anchorite_truuen_Q9446"),
(17238, 2,   961.526, -1453.96, 63.32, "anchorite_truuen_Q9446"),
(17238, 3,   970.394, -1466.55, 61.16, "anchorite_truuen_Q9446"),
(17238, 4,   1012.357, -1461.835, 61.66, "anchorite_truuen_Q9446"),
(17238, 5,   1031.535, -1473.047, 63.67, "anchorite_truuen_Q9446"),
(17238, 6,   1038.94, -1494.244, 65.18, "anchorite_truuen_Q9446"),
(17238, 7,   1038.747, -1516.181, 65.08, "anchorite_truuen_Q9446"),
(17238, 8,   1036.895, -1547.898, 62.11, "anchorite_truuen_Q9446"),
(17238, 9,   1035.789, -1574.936, 61.63, "anchorite_truuen_Q9446"),
(17238, 10,  1035.309, -1622.293, 61.67, "anchorite_truuen_Q9446"),
(17238, 11,  1036.177, -1633.579, 61.63, "anchorite_truuen_Q9446"),
(17238, 12,  1038.244, -1653.66, 60.31, "anchorite_truuen_Q9446"),
(17238, 13,  1041.586, -1665.22, 60.97, "anchorite_truuen_Q9446"),
(17238, 14,  1059.76, -1702.15, 60.61, "anchorite_truuen_Q9446"),
(17238, 15,  1078.538, -1721.825, 60.91, "anchorite_truuen_Q9446"),
(17238, 16,  1104.235, -1741.978, 60.78, "anchorite_truuen_Q9446"),
(17238, 17,  1150.263, -1758.498, 60.72, "anchorite_truuen_Q9446"),
(17238, 18,  1154.893, -1765.053, 60.64, "anchorite_truuen_Q9446"),
(17238, 19,  1151.319, -1771.608, 60.78, "anchorite_truuen_Q9446"),
(17238, 20,  1133.801, -1779.852, 61.43, "anchorite_truuen_Q9446"),
(17238, 21,  1121.943, -1785.256, 60.99, "anchorite_truuen_Q9446"),
(17238, 22,  1101.865, -1795.598, 60.86, "anchorite_truuen_Q9446"),
(17238, 23,  1090.508, -1799.026, 61.72, "anchorite_truuen_Q9446"),
(17238, 24,  1048.401, -1804.304, 73.75, "anchorite_truuen_Q9446"),
(17238, 25,  1028.65, -1807.525, 76.67, "anchorite_truuen_Q9446"),
(17238, 26,  1013.413, -1812.5, 77.33, "anchorite_truuen_Q9446"),
(17238, 27,  1007.335, -1814.347, 80.49, "anchorite_truuen_Q9446"),
(17238, 28,  981.7519, -1822.1616, 80.49, "anchorite_truuen_Q9446"),
(17238, 29,  979.1897, -1820.734, 80.49, "anchorite_truuen_Q9446"),
(17238, 30,  977.8632, -1823.1943, 80.49, "anchorite_truuen_Q9446"),
(17238, 31,  976.0802, -1823.7548, 81.03, "anchorite_truuen_Q9446");

--
-- END UPDATING QUERIES
--
COMMIT;
END //
DELIMITER ;
CALL updateDb();
DROP PROCEDURE IF EXISTS `updateDb`;
