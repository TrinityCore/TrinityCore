-- 
-- Quest Tomb of the Lighbringer - 9446
-- Old scripts cleanup
DELETE FROM `script_waypoint` WHERE `entry`=17238;
-- Creature text
DELETE FROM `creature_text` WHERE `entry`=17238;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `TEXT`, `TYPE`, `LANGUAGE`, `probability`, `emote`, `duration`, `sound`, `TextRange`, `COMMENT`, `BroadcastTextId`) VALUES
(17238, 0, 0, "Shall we begin, my friend?", 12, 7, 100, 6, 0, 0, 0, "Q Tomb of the Lighbringer", 13613),
(17238, 1, 0, "This area is known to be full of foul Scourge.  You may want to take a moment to prepare any defenses at your disposal.", 12, 7, 100, 1, 0, 0, 0, "Q Tomb of the Lighbringer", 13614),
(17238, 2, 0, "Beware!  We are attacked!", 12, 7, 100, 5, 0, 0, 0, "Q Tomb of the Lighbringer", 13616),
(17238, 3, 0, "It must be the purity of the Mark of the Lightbringer that is drawing forth the Scourge to us.  We must proceed with caution lest we be overwhelmed!", 12, 7, 100, 1, 0, 0, 0, "Q Tomb of the Lighbringer", 13617),
(17238, 4, 0, "We are beset upon again! Defend yourself!", 12, 7, 100, 5, 0, 0, 0, "Q Tomb of the Lighbringer", 13618),
(17238, 5, 0, "This land truly needs to be cleansed by the Light!  Let us continue on to the tomb.  It isn't far now.", 12, 7, 100, 1, 0, 0, 0, "Q Tomb of the Lighbringer", 13619),
(17238, 6, 0, "Very well, let us continue.", 12, 7, 100, 1, 0, 0, 0, "Q Tomb of the Lighbringer", 13615),
(17238, 7, 0, "Thank you my friend for making this possible.  This is a day that I shall never forget!  I think I will stay a while.  Please return to High Priestess MacDonnell at the camp.  I know that she'll be keenly interested to know of what has transpired here.", 12, 7, 100, 2, 0, 0, 0, "Q Tomb of the Lighbringer", 13624);

-- Anchorite Truuen AI
UPDATE `creature_template` SET `scriptname`="", `AIName`="SmartAI" WHERE `entry` IN (17238, 17233);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (17238, 17233);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryorguid` IN (1723800, 1723801, 1723300);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(17238, 0, 0, 1, 19, 0, 100, 0, 9446, 0, 0, 0, 1, 0, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Quest Taken - Say text'),
(17238, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 53, 0, 17238, 0, 9446, 45000, 1, 17, 0, 30, 0, 0, 0, 0, 0, 'Anchorite Truuen - Quest Taken - Start WP'),
(17238, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Quest Taken - Pause before movements'),
(17238, 0, 3, 18, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - Quest Taken - Remove npc flag'),
(17238, 0, 4, 5, 40, 0, 100, 0, 3, 0, 0, 0, 54, 15000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Pause at WP 3'),
(17238, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 6000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Speak'),
(17238, 0, 6, 7, 40, 0, 100, 0, 5, 0, 0, 0, 12, 4472, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1039.984, -1577.659, 61.437, 1.753951, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 12, 1802, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1031.033, -1576.279, 62.436, 0.265621, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Say text'),
(17238, 0, 9, 0, 40, 0, 100, 0, 7, 0, 0, 0, 1, 3, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Say text'),
(17238, 0, 10, 11, 40, 0, 100, 0, 11, 0, 0, 0, 1, 4, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Say text'),
(17238, 0, 11, 12, 61, 0, 100, 0, 0, 0, 0, 0, 12, 4475, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1110.658, -1742.137, 61.019, 2.413687, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 12, 13, 61, 0, 100, 0, 0, 0, 0, 0, 12, 4475, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1106.837, -1750.592, 61.174, 2.409762, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 13, 14, 61, 0, 100, 0, 0, 0, 0, 0, 12, 4475, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1111.725, -1753.404, 61.459, 2.755339, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 14, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 4475, 3, 60000, 1, 0, 0, 8, 0, 0, 0, 1117.459, -1743.327, 61.000, 2.853514, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 15, 0, 40, 0, 100, 0, 12, 0, 0, 0, 1, 5, 2000, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - say text'),
(17238, 0, 16, 17, 40, 0, 100, 0, 17, 0, 0, 0, 12, 17233, 3, 60000, 0, 0, 0, 8, 0, 0, 0, 971.86, -1825.42, 84, 0, 'Anchorite Truuen - On wp reached - Summon creature'),
(17238, 0, 17, 0, 61, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Kneels'),
(17238, 0, 18, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On quest taken - Set Faction'),
(17238, 0, 19, 0, 40, 0, 100, 0, 3, 0, 0, 0, 80, 1723800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Anchorite Truuen - On wp reached - Action list'),
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
(17238, 1, 946, -1430, 64, "anchorite_truuen_Q9446"),
(17238, 2, 974, -1439, 66, "anchorite_truuen_Q9446"),
(17238, 3,  1031, -1474, 64, "anchorite_truuen_Q9446"),
(17238, 4,  1039, -1503, 66, "anchorite_truuen_Q9446"),
(17238, 5,  1036, -1566, 62, "anchorite_truuen_Q9446"),
(17238, 6,  1036, -1568, 62, "anchorite_truuen_Q9446"),
(17238, 7,  1038, -1662, 61, "anchorite_truuen_Q9446"),
(17238, 8,  1047, -1683, 61, "anchorite_truuen_Q9446"),
(17238, 9,  1064, -1710, 61, "anchorite_truuen_Q9446"),
(17238, 10,  1099, -1738, 61, "anchorite_truuen_Q9446"),
(17238, 11,  1113, -1746, 61, "anchorite_truuen_Q9446"),
(17238, 12,  1118, -1750, 61, "anchorite_truuen_Q9446"),
(17238, 13,  1156, -1761, 61, "anchorite_truuen_Q9446"),
(17238, 14,  1152, -1773, 61, "anchorite_truuen_Q9446"),
(17238, 15,  1080, -1802, 65, "anchorite_truuen_Q9446"),
(17238, 16,  1019, -1810, 78, "anchorite_truuen_Q9446"),
(17238, 17,  976, -1823, 81, "anchorite_truuen_Q9446");

UPDATE `creature_text` SET `text`="%s's will falters.", `BroadcastTextId`=5594 WHERE `entry`=10321 AND `groupid`=0 AND `id`=0; -- Fix text for a previous commit
