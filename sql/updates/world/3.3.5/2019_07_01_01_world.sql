--
SET @GUID := 111225;

DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1, @GUID+2, @GUID+3);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID  , 15655, 530, 0, 0, 1, 1, 0, 0, 9301.48, -6958.67, 8.01523, 6.19155, 60, 0, 0, 120, 0, 0, 0, 0, 0, "", 0),
(@GUID+1, 15655, 530, 0, 0, 1, 1, 0, 0, 9298.69, -6960.92, 7.68314, 6.19155, 60, 0, 0, 120, 0, 0, 0, 0, 0, "", 0),
(@GUID+2, 15655, 530, 0, 0, 1, 1, 0, 0, 9296.88, -6958.01, 7.37056, 6.19155, 60, 0, 0, 120, 0, 0, 0, 0, 0, "", 0),
(@GUID+3, 15655, 530, 0, 0, 1, 1, 0, 0, 9300.1, -6955.84, 7.74662, 6.19155, 60, 0, 0, 120, 0, 0, 0, 0, 0, "", 0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15655;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15416, -@GUID, -(@GUID+1), -(@GUID+2), -(@GUID+3)) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15416, 0, 0, 0, 0, 0, 100, 0, 0, 0, 3100, 3700, 0, 11, 20811, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Ranger Jaela - Combat CMC - Cast 'Fireball'"),
(15416, 0, 1, 0, 1, 0, 100, 0, 10000, 30000, 300000, 540000, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID, 15655, 0, 0, 0, 0, 0, 0, "Ranger Jaela - OOC - Set Data 1 1 (Rotlimb Cannibal)"),
(-@GUID, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set Invisible"),
(-@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set ReactState Passive"),
(-@GUID, 0, 2, 3, 38, 0, 100, 0, 1, 1, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Visible"),
(-@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 1565500, 0, 0, 120000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Start Waypoint"),
(-@GUID, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+1, 15655, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Data 1 1 (Rotlimb Cannibal)"),
(-@GUID, 0, 5, 6, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+2, 15655, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Data 1 1 (Rotlimb Cannibal)"),
(-@GUID, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+3, 15655, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Data 1 1 (Rotlimb Cannibal)"),
(-@GUID, 0, 7, 0, 40, 0, 100, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 15416, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Waypoint 1 Reached - Say Line 0 (Ranger Jaela)"),
(-(@GUID+1), 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set Invisible"),
(-(@GUID+1), 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set ReactState Passive"),
(-(@GUID+1), 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Visible"),
(-(@GUID+1), 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 1565500, 0, 0, 120000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Start Waypoint"),
(-(@GUID+2), 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set Invisible"),
(-(@GUID+2), 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set ReactState Passive"),
(-(@GUID+2), 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Visible"),
(-(@GUID+2), 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 1565500, 0, 0, 120000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Start Waypoint"),
(-(@GUID+3), 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set Invisible"),
(-(@GUID+3), 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set ReactState Passive"),
(-(@GUID+3), 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Visible"),
(-(@GUID+3), 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 1, 1565500, 0, 0, 120000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Start Waypoint");

DELETE FROM `creature_text` WHERE `CreatureID`=15416;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15416, 0, 0, "Slay them!  Don't let the Scourge scum defile our city!", 14, 0, 100, 0, 0, 0, 12861, 0, "Ranger Jaela"),
(15416, 0, 1, "The enemy approaches from the south.  Ready your weapons!", 14, 0, 100, 0, 0, 0, 12862, 0, "Ranger Jaela"),
(15416, 0, 2, "The undead are approaching.  Attack!", 14, 0, 100, 0, 0, 0, 12863, 0, "Ranger Jaela");

DELETE FROM `waypoints` WHERE `entry`=1565500;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(1565500, 1, 9347.2148, -6964.3096, 15.5277, "Rotlimb Cannibal");
