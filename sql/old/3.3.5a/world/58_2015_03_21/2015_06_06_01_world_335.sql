--
DELETE FROM `creature_formations` WHERE `leaderGUID`=79720;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(79720,79720,4,0,2),
(79720,79721,4,0,2);

DELETE FROM `waypoint_data` WHERE `id`=797210;
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 229 AND 270;
UPDATE `waypoint_data` SET `action`=0 WHERE `id`=797200;
UPDATE `creature_template` SET `MovementType` = 0 WHERE `entry` = 2532;
UPDATE `creature_addon` SET `path_id` = 0 WHERE `guid` = 79721;
UPDATE `waypoint_data` SET  `move_type`=1 WHERE `id`=797200;
UPDATE `creature` SET `movementtype`=0 WHERE `guid`=79721;

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=2533;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2533 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=253300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2533,0,0,0,1,0,100,0,10000,10000,30000,30000,80,253300,0,0,0,0,0,1,0,0,0,0,0,0,0,'William - ooc - action list'),
(253300,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'William - action list - talk1'),
(253300,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,19,2532,50,0,0,0,0,0,'William - action list - talk1 for Donna');

DELETE FROM `creature_text` WHERE `entry` IN (2533, 2532);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(2533,0,0,'Ha ha! I have Betsy!',12,7,100,0,0,0,'William', 693),
(2533,0,1,'I wonder if your dolly can swim!',12,7,100,0,0,0,'William', 705),
(2533,0,2,'I have your dolly! Nyah nyah!',12,7,100,0,0,0,'William', 706),
(2533,0,3,'What happens when I do this?!',12,7,100,0,0,0,'William', 707),
(2533,0,4,'If you want her back you''re gonna have to beg!',12,7,100,0,0,0,'William', 708),
(2533,0,5,'Crybaby! Crybaby!',12,7,100,0,0,0,'William', 709),
(2533,0,6,'Baby wants her dolly!',12,7,100,0,0,0,'William', 710),
(2533,0,7,'Oops!',12,7,100,0,0,0,'William', 711),
(2532,0,0,'Gimme my dolly!!',12,7,100,0,0,0,'Donna', 694),
(2532,0,1,'Betsy! Give me Betsy back!',12,7,100,0,0,0,'Donna', 695),
(2532,0,2,'Don''t hurt Betsy, you meanie!',12,7,100,0,0,0,'Donna', 696),
(2532,0,3,'WAAAHHH!!!',12,7,100,0,0,0,'Donna', 697),
(2532,0,4,'I''m telling Mommy!',12,7,100,0,0,0,'Donna', 698),
(2532,0,5,'Stop pulling her hair out!',12,7,100,0,0,0,'Donna', 699),
(2532,0,6,'You''re hurting her!',12,7,100,0,0,0,'Donna', 700),
(2532,0,7,'Stop! You''ll pull her head off!',12,7,100,0,0,0,'Donna', 701);
