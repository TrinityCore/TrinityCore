--
SET @GUID := 111185;

DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1, @GUID+2);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID  , 15655, 530, 0, 0, 1, 1, 0, 0, 8607.49, -6788.45, 101.839, 0.00836706, 60, 0, 0, 120, 0, 0, 0, 0, 0, "", 0),
(@GUID+1, 15654, 530, 0, 0, 1, 1, 0, 1, 8605.56, -6790.09, 102.006, 0.00836706, 60, 0, 0, 120, 0, 0, 0, 0, 0, "", 0),
(@GUID+2, 15654, 530, 0, 0, 1, 1, 0, 1, 8605.38, -6786.45, 102.481, 0.00836706, 60, 0, 0, 120, 0, 0, 0, 0, 0, "", 0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (15942, 15655);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15942, -@GUID, -(@GUID+1), -(@GUID+2)) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(15942, 0, 0, 0, 1, 0, 100, 0, 10000, 30000, 300000, 540000, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID, 15655, 0, 0, 0, 0, 0, 0, "Ranger Sareyn - OOC - Set Data 1 1 (Rotlimb Cannibal)"),
(-@GUID, 0, 0, 1, 11, 0, 100, 0, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set Invisible"),
(-@GUID, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Spawn - Set ReactState Passive"),
(-@GUID, 0, 2, 3, 38, 0, 100, 0, 1, 1, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Visible"),
(-@GUID, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 1565501, 0, 0, 120000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Start Waypoint"),
(-@GUID, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+1, 15654, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Data 1 1 (Plaguebone Villager)"),
(-@GUID, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID+2, 15654, 0, 0, 0, 0, 0, 0, "Rotlimb Cannibal - On Data 1 1 Set - Set Data 1 1 (Plaguebone Villager)"),
(-(@GUID+1), 0, 0, 0, 0, 0, 100, 0, 5900, 12200, 11900, 22100, 0, 11, 11976, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - In Combat - Cast 'Strike'"),
(-(@GUID+1), 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Spawn - Set Invisible"),
(-(@GUID+1), 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Spawn - Set ReactState Passive"),
(-(@GUID+1), 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Data 1 1 Set - Set Visible"),
(-(@GUID+1), 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 1565501, 0, 0, 120000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Data 1 1 Set - Start Waypoint"),
(-(@GUID+1), 0, 5, 0, 40, 0, 100, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 15942, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Waypoint 1 Reached - Say Line 0 (Ranger Sareyn)"),
(-(@GUID+2), 0, 0, 0, 0, 0, 100, 0, 5900, 12200, 11900, 22100, 0, 11, 11976, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - In Combat - Cast 'Strike'"),
(-(@GUID+2), 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 0, 47, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Spawn - Set Invisible"),
(-(@GUID+2), 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Spawn - Set ReactState Passive"),
(-(@GUID+2), 0, 3, 4, 38, 0, 100, 0, 1, 1, 0, 0, 0, 47, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Data 1 1 Set - Set Visible"),
(-(@GUID+2), 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 1565501, 0, 0, 120000, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Plaguebone Pillager - On Data 1 1 Set - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry`=1565501;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(1565501, 1, 8648.8262, -6790.4302, 96.2708, "Rotlimb Cannibal/Plaguebone Villager");

DELETE FROM `creature_text` WHERE `CreatureID`=15942;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(15942, 0, 0, "Open fire!", 14, 0, 100, 0, 0, 0, 12417, 0, "Ranger Sareyn"),
(15942, 0, 1, "Enemy sighted!  Ready your weapons!", 14, 0, 100, 0, 0, 0, 12418, 0, "Ranger Sareyn"),
(15942, 0, 2, "Hold your positions!", 14, 0, 100, 0, 0, 0, 12419, 0, "Ranger Sareyn");
