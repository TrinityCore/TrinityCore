--
/*
SET @CGUID := 43502;
DELETE FROM `creature` WHERE `id`=14494;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(@CGUID, 14494, 0, 1, 1, 0, 0, 3325.180420 , -2997.122803, 164.205444, 5.663, 300, 0, 0, 3052, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`= 14494;

DELETE FROM `smart_scripts` WHERE `entryorguid`=14494;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14494, 0, 0, 0,11, 0, 100, 0, 0, 0, 0, 0, 11, 32648, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Eris Havenfire - On Spawn - Cast Ancestor Invisibility');
*/
