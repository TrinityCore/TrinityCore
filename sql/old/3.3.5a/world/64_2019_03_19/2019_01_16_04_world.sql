-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=23946;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23946 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23946,0,0,0,0,0,100,0,1000,2000,2000,3000,0,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"North Fleet Marksman - IC - Cast Shoot"),
(23946,0,1,0,0,0,100,0,1000,2000,7000,8000,0,11,38861,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"North Fleet Marksman - IC - Cast Aimed Shot"),
(23946,0,2,0,1,0,100,0,1000,2000,2000,3000,0,11,61512,0,0,0,0,0,11,23947,100,1,0,0,0,0,0,"North Fleet Marksman - OOC - Cast Shoot");

DELETE FROM `creature` WHERE `guid` IN(96555,96557);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(96557, 23946, 571, 1, 1, 0, 0, 1606.37, -6241.61, 6.15574, 1.19442, 300, 0, 0, 6986, 0, 0),
(96555, 23946, 571, 1, 1, 0, 0, 1600.3, -6236.03, 5.81873, 0.488692, 300, 0, 0, 6986, 0, 0);
