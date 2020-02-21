DELETE FROM `spawn_group_template` WHERE `groupId` IN (431, 432);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(431, 'Shadowfang Keep - Lord Godfrey - Packleader Ivar Bloodfang', 4),
(432, 'Shadowfang Keep - Lord Godfrey - Deathstalker Commander Belmont', 4);

SET @CGUID := 395387;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 47006, 33, 209, 209, 3, 169, 0, 0, 0, -160.621, 2178.69, 152.376, 5.883088, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Packleader Ivar Bloodfang (Area: Shadowfang Keep - Difficulty: 2)
(@CGUID+1, 47293, 33, 209, 209, 3, 169, 0, 0, 0, -168.978, 2185.792, 151.9715, 4.799315, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Deathstalker Commander Belmont (Area: 0 - Difficulty: 0) (possible waypoints or random movement)

DELETE FROM `spawn_group` WHERE `groupId` IN (431, 432);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(431, 0, @CGUID+0),
(432, 0, @CGUID+1);

-- Ivar
SET @GUID := -(@CGUID+0);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -129.387, 2166.32, 155.678, 0, "When just created - Self: Move to position (-129.387, 2166.32, 155.678, 0) (point id 1) // "),
(@GUID, 0, 1, 2, 34, 0, 100, 0, 8, 1, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -120.818, 2162.85, 155.678, 0, "On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Move to position (-120.818, 2162.85, 155.678, 0) (point id 0) // "),
(@GUID, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4700602, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4700602 // ");

SET @ENTRY := 4700602;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 6100, 6100, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.745929, "When in combat and timer at the begining between 6100 and 6100 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 2.745929) // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 200, 200, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 200 and 200 ms (and later repeats every 0 and 0 ms) - Self: Talk 11 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 0 and 0 ms) - Self: Talk 12 // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 2200, 2200, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.88752, "When in combat and timer at the begining between 2200 and 2200 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 5.88752) // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 100, 100, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 224840, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 100 and 100 ms (and later repeats every 0 and 0 ms) - Gameobject Arugal's Lair 18971 (224840): Activate (only gameobject) // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 4800, 4800, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.745929, "When in combat and timer at the begining between 4800 and 4800 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 2.745929) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Talk 13 // ");

-- Belmont
SET @GUID := -(@CGUID+1);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@GUID, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, -131.832, 2166.28, 155.678, 0, "When just created - Self: Move to position (point id 1) // "),
(@GUID, 0, 1, 2, 34, 0, 100, 0, 8, 1, 0, 0, 69, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, -119.658, 2162.35, 155.678, 0, "On movement of type POINT_MOTION_TYPE inform, point 1 - Self: Move to position (point id 0) // "),
(@GUID, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 4729303, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Start timed action list id #4729303 // ");

-- TimedActionList  4729303 SAI
SET @ENTRY := 4729303;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 0 and 0 ms) - Self: Talk 10 // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 6600, 6600, 0, 0, 1, 11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6600 and 6600 ms (and later repeats every 0 and 0 ms) - Self: Talk 11 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 14, 224840, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Gameobject Arugal's Lair 18971 (224840): Activate (only gameobject) // "),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 6400, 6400, 0, 0, 84, 3, 0, 0, 0, 0, 0, 10, 395328, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6400 and 6400 ms (and later repeats every 0 and 0 ms) - Creature High Warlord Cromush 47294 (395328): Talk 3 // "),
(@ENTRY, 9, 4, 0, 0, 0, 100, 0, 5700, 5700, 0, 0, 1, 12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 5700 and 5700 ms (and later repeats every 0 and 0 ms) - Self: Talk 12 // "),
(@ENTRY, 9, 5, 0, 0, 0, 100, 0, 4600, 4600, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.79164, "When in combat and timer at the begining between 4600 and 4600 ms (and later repeats every 0 and 0 ms) - Self: Look at (0, 0, 0, 2.79164) // "),
(@ENTRY, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Play emote ONESHOT_EXCLAMATION(DNR) (5) // "),
(@ENTRY, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 333, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 0 and 0 ms (and later repeats every 0 and 0 ms) - Self: Set emote state (UNIT_NPC_EMOTESTATE) to STATE_READY1H (333) // ");
