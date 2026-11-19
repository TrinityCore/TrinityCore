SET @Ithania = 17119;

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=@Ithania);
DELETE FROM `creature_template_addon` WHERE `entry`=@Ithania;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@Ithania,0,8,257,0, NULL); -- Ithania

DELETE FROM `creature_text` WHERE `entry`=@Ithania;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@Ithania,0,0, 'I think I can make it to Brackenwall on my own. They''ve got the cargo at the top of the tower. Be careful!',12,0,0,0,0,0, 'Ithania - Escape');

-- Script
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@Ithania;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Ithania AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@Ithania*100 AND `source_type` IN (0,9));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Ithania, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 80, @Ithania*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ithania - On gossip hello run timed action list'),
(@Ithania*100, 9, 0, 0, 0, 0, 0, 0, 500, 500, 0, 0, 91, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ithania - 0 - Remove kneeling'),
(@Ithania*100, 9, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ithania - 1 - Remove gossip flag'),
(@Ithania*100, 9, 2, 0, 0, 0, 0, 0, 500, 500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Ithania - 2 - Say'),
(@Ithania*100, 9, 3, 0, 0, 0, 0, 0, 1500, 1500, 0, 0, 53, 1, @Ithania, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, 'Ithania - 3 - Start waypoint'),
(@Ithania, 0, 1, 0, 40, 0, 0, 0, 2, @Ithania, 0, 0, 33, 17119, 0, 0, 0, 0, 0, 18, 60, 0, 0, 0, 0, 0, 0, 'Ithania - 5 - Give killcredit (adjust timer)'),
(@Ithania, 0, 2, 0, 40, 0, 0, 0, 2, @Ithania, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ithania - 6 - Despawn');

DELETE FROM `waypoints` WHERE `entry`=@Ithania;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@Ithania, 1, -2873.96, -3424.76, 39.35, 'Ithania - Tower Entrance'),
(@Ithania, 2, -2833.36, -3415.22, 33.77, 'Ithania - Road');
