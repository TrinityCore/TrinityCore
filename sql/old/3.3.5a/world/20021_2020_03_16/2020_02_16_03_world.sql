-- 
DELETE FROM `creature` WHERE `guid` IN (125917, 125918, 125920, 125921);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `npcflag`, `MovementType`) VALUES
(125917, 18766, 558, 3, 1, 0, 0, 113.589, -132.944, -139.589, 2.72271, 7200, 0, 0, 1, 0, 0, 0),
(125918, 18766, 558, 3, 1, 0, 0, 40.7895, -191.962, -139.589, 3.89208, 7200, 0, 0, 1, 0, 0, 0),
(125920, 18766, 558, 3, 1, 0, 0, 113.81, -191.401, -139.589, 2.9147, 7200, 0, 0, 1, 0, 0, 0),
(125921, 18766, 558, 3, 1, 0, 0, 40.4961, -134.312, -139.589, 5.74213, 7200, 0, 0, 1, 0, 0, 0);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`IN (18766);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(18766) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(18766, 0, 0, 0, 10, 0, 100, 0, 0, 60, 1000, 1000, 0, 11, 32889, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Pool of Souls - Ooc los - Cast Grasp of Death');

UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (18766,20314); 
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (18766,20314);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(18766, 0, 0, 1, 0),
(20314, 0, 0, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry`= 20316;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(20316, "35841 35850");
