-- 
SET @GUID := 27588;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26117 AND `source_type`=0 AND `id` IN (3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(26117, 0, 3, 4, 20, 0, 100, 0, 11967, 0, 0, 0, 44, 1, 0, 0, 0, 0, 0, 10, @GUID, 26206, 0, 0, 0, 0, 0, "Raelorasz - On Quest 'Mustering the Reds' Rewarded - Set Phase 1 (Keristrasza)"),
(26117, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, @GUID, 26206, 0, 0, 0, 0, 0, "Raelorasz - On Quest 'Mustering the Reds' Rewarded - Set Data 1 1 (Keristrasza)");

DELETE FROM `creature` WHERE `guid`=@GUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@GUID, 26206, 571, 0, 0, 1, 2, 0, 0, 3579.6333, 6653.4771, 195.5151, 3.4422, 1, 0, 0, 151200, 31952, 0, 0, 0, 0, "", 0);
