--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (32682, 27932);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (32682, 27932) AND `source_type`=0;
UPDATE `creature_template` SET `InhabitType`=4, `speed_run`=2.5 WHERE `entry` IN (32682, 27932);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(32682, 0, 0, 0, 27, 0, 100, 1, 0, 0, 0, 0, 53, 1, 32682, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Harry''s Bomber- On passeger rided - Start wp'),
(27932, 0, 0, 0, 27, 0, 100, 1, 0, 0, 0, 0, 53, 1, 27932, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Harry''s Bomber- On passeger rided - Start wp'),
(32682, 0, 1, 0, 58, 0, 100, 1, 9, 32682, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Harry''s Bomber- On waypoint ended - Eject passengers'),
(27932, 0, 1, 0, 58, 0, 100, 1, 9, 27932, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Harry''s Bomber- On passeger ended - Eject passengers');

UPDATE `smart_scripts` SET `action_type`=85 WHERE `entryorguid`=28277 AND `source_type`=0 AND `id`=0;
DELETE FROM `waypoints` WHERE `entry` IN (32682, 27932);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(32682, 1, 61.83957, -6228.992, 19.07242, 'Harry''s Bomber'),
(32682, 2, -64.6518, -5908.95, 29.8502, 'Harry''s Bomber'),
(32682, 3, -158.0859, -5631.193, 29.8502, 'Harry''s Bomber'),
(32682, 4, -436.5865, -5223.862, 32.1002, 'Harry''s Bomber'),
(32682, 5, -412.989, -5012.779, 45.7391, 'Harry''s Bomber'),
(32682, 6, -75.09814, -4341.288, 64.29379, 'Harry''s Bomber'),
(32682, 7, -51.86116, -4023.003, 70.12712, 'Harry''s Bomber'),
(32682, 8, -136.1673, -3716.832, 59.96046, 'Harry''s Bomber'),
(32682, 9, -170.8945, -3578.378, 4.988236, 'Harry''s Bomber'),
(27932, 1, -136.1673, -3716.832, 59.96046, 'Harry''s Bomber'),
(27932, 2, -51.86116, -4023.003, 70.12712, 'Harry''s Bomber'),
(27932, 3, -75.09814, -4341.288, 64.29379, 'Harry''s Bomber'),
(27932, 4, -412.989, -5012.779, 45.7391, 'Harry''s Bomber'),
(27932, 5, -436.5865, -5223.862, 32.1002, 'Harry''s Bomber'),
(27932, 6, -158.0859, -5631.193, 29.8502, 'Harry''s Bomber'),
(27932, 7, -64.6518, -5908.95, 29.8502, 'Harry''s Bomber'),
(27932, 8, 61.83957, -6228.992, 19.07242, 'Harry''s Bomber'),
(27932, 9, 89.63259, -6287.430, -0.739605, 'Harry''s Bomber');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10218;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`Scriptname`,`Comment`) VALUES
(15,10218,0,0,0,23,0,495,0,0,0,0 ,'' , 'Harry''s Bomber - Show gossip option if the npc is in the area 495'),
(15,10218,0,0,0,9,0,11567,0,0,0,0 ,'' , 'Harry''s Bomber - Show gossip option if player has taken quest 11567'),
(15,10218,0,0,1,28,0,11567,0,0,0,0 ,'' , 'Harry''s Bomber - Show gossip option if player has quest 11567 completed');
