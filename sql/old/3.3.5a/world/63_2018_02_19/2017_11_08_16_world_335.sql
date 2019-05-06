-- 
SET @GUID := 81148; -- Needs 2
DELETE FROM `creature` WHERE `guid` IN (@GUID, @GUID+1);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID  , 4062, 0, 0, 0, 1, 2, 0, 1, -2366.4019, -2513.9302, 75.3443, 1.6262, 2, 0, 0, 1050, 0, 0, 0, 0, 0, "", 0),
(@GUID+1, 4062, 0, 0, 0, 1, 2, 0, 1, -2374.0273, -2496.1335, 75.3440, 5.3474, 2, 0, 0, 1050, 0, 0, 0, 0, 0, "", 0);

UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`=2652;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2652 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@GUID), -(@GUID+1)) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=406200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2652, 1, 0, 1, 19, 0, 100, 0, 632, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID, 4062, 0, 0, 0, 0, 0, "Ebenezer Rustlocke's Corpse - On Quest 'The Thandol Span' Accepted - Set Data 1 1 (Dark Iron Bombardier)"),
(2652, 1, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 10, @GUID+1, 4062, 0, 0, 0, 0, 0, "Ebenezer Rustlocke's Corpse - On Quest 'The Thandol Span' Accepted - Set Data 2 2 (Dark Iron Bombardier)"),
(-(@GUID), 0, 0, 0, 9, 0, 100, 0, 5, 30, 6000, 9000, 11, 8858, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - Within 5-30 Range - Cast 'Bomb' (No Repeat)"),
(-(@GUID), 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - Between 0-15% Health - Flee For Assist (No Repeat)"),
(-(@GUID), 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On reset - Set Event Phase 1"),
(-(@GUID), 0, 3, 4, 38, 1, 100, 0, 1, 1, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On Data 1 1 Set - Set Event Phase 2"),
(-(@GUID), 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On Data 1 1 Set - Set PhaseMask 1 (Phase 2)"),
(-(@GUID), 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On Data 1 1 Set - Say Line 0 (Phase 2)"),
(-(@GUID), 0, 6, 0, 7, 0, 100, 0, 0, 0, 0, 0, 44, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On evade - Set Phase 1"),
(-(@GUID+1), 0, 0, 0, 9, 0, 100, 0, 5, 30, 6000, 9000, 11, 8858, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - Within 5-30 Range - Cast 'Bomb' (No Repeat)"),
(-(@GUID+1), 0, 1, 0, 2, 0, 100, 1, 0, 15, 0, 0, 25, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - Between 0-15% Health - Flee For Assist (No Repeat)"),
(-(@GUID+1), 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On reset - Set Event Phase 1"),
(-(@GUID+1), 0, 3, 4, 38, 1, 100, 0, 2, 2, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On Data 1 1 Set - Set Event Phase 2"),
(-(@GUID+1), 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 406200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On Data 1 1 Set - Run Script"),
(-(@GUID+1), 0, 5, 0, 7, 0, 100, 0, 0, 0, 0, 0, 44, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On evade - Set Phase 1"),
(406200, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 44, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On Script - Set PhaseMask 1"),
(406200, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Dark Iron Bombardier - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=4062;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4062, 0, 0, "Still no sign of the final shipment of explosives.", 12, 7, 100, 0, 0, 0, 782, 0, "Dark Iron Bombardier"),
(4062, 1, 0, "No sign of the final explosives shipment to the west either.  Where are those lollygaggers?", 12, 7, 100, 0, 0, 0, 783, 0, "Dark Iron Bombardier");
