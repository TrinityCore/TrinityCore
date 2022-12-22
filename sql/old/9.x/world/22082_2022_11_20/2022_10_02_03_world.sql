-- Delete doubled Trainings Dummy
DELETE FROM `creature` WHERE `guid` = 251604;
DELETE FROM `creature_addon` WHERE `guid` = 251604;

-- add new Stablemaster
SET @CGUID := 251604; -- re-use the GUID
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 68989, 648, 4737, 4765, '0', 0, 558, 0, 0, -8385.01953125, 1363.217041015625, 102.1136093139648437, 3.004709243774414062, 120, 0, 0, 622, 0, 0, 0, 0, 0, 45338); -- Beastblast Babblesnaff (Area: KTC Headquarters - Difficulty: 0) (Auras: )

DELETE FROM `creature_addon` WHERE `guid` = @CGUID+0;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 69, 0, 0, 0, 0, ''); -- Beastblast Babblesnaff

-- remove wander distance for GUID: 251603 251602 251611
UPDATE `creature` SET `wander_distance`= 0, `MovementType`= 0 WHERE `guid` IN (251603, 251602, 251611);

-- Update Visibility
UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=49132; -- 49132 (Goblin Trike)

-- Template
UPDATE `creature_template` SET `gossip_menu_id`=9821, `minlevel`=20, `maxlevel`=20 WHERE `entry`=68989; -- Beastblast Babblesnaff

-- Update Quest Chain
UPDATE `quest_template_addon` SET `PrevQuestID` = 14138, `ExclusiveGroup` = -14069 WHERE `ID` = 14075; -- Trouble in the Mines
UPDATE `quest_template_addon` SET `PrevQuestID` = 14138, `ExclusiveGroup` = -14069 WHERE `ID` = 14069; -- Good Help is Hard to Find

-- Quest Details/Offer Reward
DELETE FROM `quest_details` WHERE `ID` IN (14070 /*Do it Yourself*/, 24567 /*Report for Tryouts*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14070, 1, 0, 0, 0, 0, 0, 0, 0, 45338), -- Do it Yourself
(24567, 1, 0, 0, 0, 0, 0, 0, 0, 45338); -- Report for Tryouts

DELETE FROM `quest_offer_reward` WHERE `ID`=28607;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(28607, 6, 0, 0, 0, 0, 0, 0, 0, 'You lost your Keys to the Hot Rod somewhere?$B$BNo problem, boss. I always like to keep a spare set handy just in case.', 45338); -- The Keys to the Hot Rod

 -- Sally "Salvager" Sandscrew smart ai
SET @ENTRY := 37761;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 4000, 7000, 4000, 7000, 10, 1, 5, 6, 25, 273, 274, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 7 seconds (OOC) - Self: Play random emote: 1, 5, 6, 25, 273, 274');

 -- Brett "Coins" McQuid smart ai
SET @ENTRY := 37762;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 4000, 7000, 4000, 7000, 10, 274, 25, 1, 6, 5, 273, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 4 - 7 seconds (OOC) - Self: Play random emote: 274, 25, 1, 6, 5, 273');

-- Waypoints for GUID: 251717
SET @CGUID := 251717;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8424.518, 1329.443, 102.0956, NULL, 0),
(@PATH, 1, -8416.872, 1332.5, 102.375, NULL, 0),
(@PATH, 2, -8408.069, 1333.384, 102.1484, NULL, 0),
(@PATH, 3, -8398.679, 1334.172, 102.1039, NULL, 0),
(@PATH, 4, -8387.957, 1341.425, 102.1039, NULL, 0),
(@PATH, 5, -8398.679, 1334.172, 102.1039, NULL, 0),
(@PATH, 6, -8408.069, 1333.384, 102.1484, NULL, 0),
(@PATH, 7, -8416.872, 1332.5, 102.375, NULL, 0),
(@PATH, 8, -8424.518, 1329.443, 102.0956, NULL, 0),
(@PATH, 9, -8431.024, 1324.602, 101.875, NULL, 0);

UPDATE `creature` SET `position_x`= -8424.518, `position_y`= 1329.443, `position_z`= 102.0956, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID, @PATH, 1, 80264);
