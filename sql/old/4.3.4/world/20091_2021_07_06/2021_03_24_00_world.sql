-- Creature Naraat the Earthspeaker 45226 SAI
SET @ENTRY := 45226;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 27203, 0, 0, 0, 134, 81040, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "When player accepts quest The Maelstrom (27203) - if avaliable, last used invoker will cast spellId: Update Zone Auras and Phase Shift (81040) with castFlags on Action invoker // ");

SET @OGUID := 223199;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 205268, 1, 0, 0, 1, 169, 0, 2048.0625, -4377.163, 98.930504, 0, 0, 0, 0, 1, 120, 255, 0, 15595);

DELETE FROM `gameobject_addon` WHERE `guid` IN (@OGUID+0, 223195);
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES
(@OGUID+0, 18, 1000),
(223195, 18, 1000);

DELETE FROM `spell_area` WHERE `area` IN (5428, 5429) AND `spell`= 84481;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(84481, 5428, 27203, 27123, 0, 0, 2, 3, 74, 11), -- Stormwind
(84481, 5429, 27203, 27123, 0, 0, 2, 3, 74, 11); -- Orgrimmar

UPDATE `spell_target_position` SET `MapID`= 730, `PositionX`= 854.924, `PositionY`= 1080.96, `PositionZ`= -12.5196, `VerifiedBuild`= 15595 WHERE `ID`= 84464;
UPDATE `spell_target_position` SET `MapID`= 646, `PositionX`= 1040.91, `PositionY`= 544.689, `PositionZ`= 681.86, `VerifiedBuild`= 15595 WHERE `ID`= 84073;

-- Creature Thrall 45042 SAI
SET @ENTRY := 45042;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 28892, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Nature Channeling (28892) on Self // ");

-- Creature Farseer Nobundo 51060 SAI
SET @ENTRY := 51060;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 28892, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Nature Channeling (28892) on Self // ");

-- Muln Earthfury 51065 SAI
SET @ENTRY := 51065;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 11, 28892, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When just created - Self: Cast spell Nature Channeling (28892) on Self // ");

UPDATE `creature`SET `PhaseId`= 169 WHERE `Map`= 730;
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (45005, 43718, 45028, 45027, 45004, 45024);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(45005, 0, 0, 1, 0),
(43718, 0, 0, 1, 1),
(45028, 0, 0, 1, 1),
(45027, 0, 0, 1, 1),
(45004, 0, 1, 1, 0),
(45024, 0, 1, 1, 0);

UPDATE `creature_template` SET `npcflag`= 16777216 WHERE `entry` IN (45005, 45004, 45024);
UPDATE `creature_template` SET `VehicleId`= 1071, `ScriptName`= 'npc_deepholm_wyvern' WHERE `entry`= 45004;
UPDATE `creature_template` SET `VehicleId`= 1073, `ScriptName`= 'npc_deepholm_wyvern' WHERE `entry`= 45024;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 18 AND `SourceGroup`= 45005;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`, `Comment`) VALUES
(18, 45005, 84071, 28, 27123, '', 'Required quest active for spellclick');

UPDATE `npc_spellclick_spells` SET `cast_flags`= 1, `user_type`= 0 WHERE `npc_entry`= 45005;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (45004, 45024);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(45004, 46598, 1, 0),
(45024, 46598, 1, 0);

UPDATE `creature`SET `spawntimesecs`= 3 WHERE `guid`= 383652;

-- Creature Wyvern 45005 SAI
SET @ENTRY := 45005;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 8, 0, 100, 0, 84071, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Stormbeak (84071) hit  - Self: Despawn instantly // ");

-- Conditions
DELETE FROM `conditions` WHERE `SourceEntry` IN (84071, 84364) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 84071 , 0, 0, 31, 0, 3, 45005, 0, 0, 0, '', 'Stormbeak - Target Wyvern'),
(13, 1, 84364 , 0, 0, 31, 0, 3, 43718, 0, 0, 0, '', 'Camera 1 - Target Generic Trigger LAB (Gigantic AOI)');

DELETE FROM `creature_template_addon` WHERE `entry` IN (45004, 45024);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`) VALUES
(45004, 50331648, 1),
(45024, 50331648, 1);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (45004, 45024);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summonType`, `summonTimer`) VALUES
(45004, 45028, 0, 1, 'Wyvern - Aggra', 8, 0),
(45024, 45027, 0, 1, 'Wyvern - Aggra', 8, 0);

SET @PATH := 45004 * 100;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `move_type`, `velocity`) VALUES
(@PATH, 0, 893.021, 788.55, -245.521, 0, 32),
(@PATH, 1, 869.17, 497.146, -22.7786, 0, 32);

DELETE FROM `waypoint_data_addon` WHERE `PathID`= @PATH;
INSERT INTO `waypoint_data_addon` (`PathID`, `PointID`, `SplinePointIndex`, `PositionX`, `PositionY`, `PositionZ`) VALUES
-- 0
(@PATH, 0, 0, 770.34, 949.726, 34.8637),
(@PATH, 0, 1, 792.222, 737.495, 34.8637),
(@PATH, 0, 2, 920.221, 698.87, 3.86366),
(@PATH, 0, 3, 985.457, 788.34, -31.0252),
(@PATH, 0, 4, 937.471, 883.339, -39.7197),
(@PATH, 0, 5, 835.682, 853.524, -54.1363),
(@PATH, 0, 6, 842.057, 757.833, -80.2752),
(@PATH, 0, 7, 948.002, 751.8, -107.581),
(@PATH, 0, 8, 947.352, 798.976, -147.995),
-- 1
(@PATH, 1, 0, 907.95, 502.139, -44.4632),
(@PATH, 1, 1, 882.642, 499.205, -28.8255);

SET @PATH := 45024 * 100;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `move_type`, `velocity`) VALUES
(@PATH, 0, 935.057, 506.95, -48.1708, 0, 16),
(@PATH, 1, 909.137, 502.672, -17.6993, 0, 16);

DELETE FROM `waypoint_data_addon` WHERE `PathID`= @PATH;
INSERT INTO `waypoint_data_addon` (`PathID`, `PointID`, `SplinePointIndex`, `PositionX`, `PositionY`, `PositionZ`) VALUES
-- 0
(@PATH, 0, 0, 1109.14, 649.396, 413.65),
(@PATH, 0, 0, 954.589, 657.99, 289.706),
(@PATH, 0, 0, 875.491, 621.337, 191.761),
(@PATH, 0, 0, 837.281, 565.34, 122.955),
(@PATH, 0, 0, 820.571, 487.705, 39.7609),
(@PATH, 0, 0, 903.094, 501.446, -36.7289),
(@PATH, 0, 0, 935.057, 506.95, -48.1708);


DELETE FROM `creature_text` WHERE `CreatureID` IN (45028, 45027);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(45028, 0, 0, 'I hope you have a strong stomach.  Travelling through the breach is not for the weak.', 12, 0, 100, 0, 0, 22606, 45169, 'Aggra to Player'),
(45028, 1, 0, 'We\'re at the center of the Maelstrom, the rift between Deepholm and Azeroth.  Watch as it threatens to tear your world apart!', 12, 0, 100, 0, 0, 22607, 45170, 'Aggra to Player'),
(45028, 2, 0, 'Let us hope Thrall and the others can contain it while you\'re inside.', 12, 0, 100, 0, 0, 22608, 45171, 'Aggra to Player'),
(45028, 3, 0, 'This is it!  Brace yourself!', 14, 0, 100, 0, 0, 22609, 45172, 'Aggra to Player'),
(45027, 0, 0, 'You made it!  Good!', 12, 0, 100, 4, 0, 22610, 45175, 'Aggra to Player'),
(45027, 1, 0, 'This is the Temple of Earth.  It\'s the most important structure in Deepholm.', 12, 0, 100, 0, 0, 22611, 45176, 'Aggra to Player'),
(45027, 2, 0, 'There was once a Titan-made stone inside.  It was known as the World Pillar.  The name was literal.  It bore the weight of all the elemental and magnetic forces in Deepholm.', 12, 0, 100, 0, 0, 22612, 45180, 'Aggra to Player'),
(45027, 3, 0, 'It was shattered when Deathwing broke through the dome above and created the rift between the two worlds.  All of Deepholm is going to collapse into Azeroth if we do not put the World Pillar back together.', 12, 0, 100, 0, 0, 22613, 45182, 'Aggra to Player'),
(45027, 4, 0, 'The first fragment was going to be delivered to us by a Horde gunship known as the Storm\'s Fury.  It never made it here.', 12, 0, 100, 0, 0, 22614, 45186, 'Aggra to Player'),
(45027, 5, 0, 'We\'ve taken control of the temple and we\'re containing as much of the damage as we can.  Go inside and speak to Maruut; he\'s in charge.', 12, 0, 100, 0, 0, 22615, 45187, 'Aggra to Player'),
(45027, 6, 0, 'We are all counting on you.', 12, 0, 100, 0, 0, 22616, 45191, 'Aggra to Player');

-- Creature Aggra 45028 SAI
SET @ENTRY := 45028;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 5000, 5000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 5000 and 5000 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 14400, 14400, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 14400 and 14400 ms) - Self: Talk 1 // "),
(@ENTRY, 0, 2, 0, 60, 0, 100, 1, 25400, 25400, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 25400 and 25400 ms) - Self: Talk 2 // "),
(@ENTRY, 0, 3, 4, 60, 0, 100, 1, 33400, 33400, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 33400 and 33400 ms) - Self: Talk 3 // "),
(@ENTRY, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 86971, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Self: Cast spell Pre-Forcecast Switch to Seat 3 (86971) on Self // ");

-- Creature Aggra 45028 SAI
SET @ENTRY := 45027;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 4700, 4700, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 4700 and 4700 ms) - Self: Talk 0 // "),
(@ENTRY, 0, 1, 0, 60, 0, 100, 1, 9700, 9700, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 9700 and 9700 ms) - Self: Talk 1 // "),
(@ENTRY, 0, 2, 0, 60, 0, 100, 1, 16500, 16500, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 16500 and 16500 ms) - Self: Talk 2 // "),
(@ENTRY, 0, 3, 0, 60, 0, 100, 1, 29700, 29700, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 29700 and 29700 ms) - Self: Talk 3 // "),
(@ENTRY, 0, 4, 0, 60, 0, 100, 1, 44100, 44100, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 44100 and 44100 ms) - Self: Talk 4 // "),
(@ENTRY, 0, 5, 0, 60, 0, 100, 1, 53700, 53700, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 53700 and 53700 ms) - Self: Talk 5 // "),
(@ENTRY, 0, 6, 0, 60, 0, 100, 1, 63200, 63200, 0, 0, 1, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 63200 and 63200 ms) - Self: Talk 6 // ");

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_deepholm_intro_teleport';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(84073, 'spell_deepholm_intro_teleport');
