-- Trok -- http://www.wowhead.com/npc=14872/trok#comments
-- Trok SAI
SET @ENTRY := 14872;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,20000,10000,20000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trok - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `entry`=14872;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextID`, `comment`) VALUES
(14872, 0, 0, 'Help! I''m being chased by a swarm of bees!', 12, 1, 100, 0, 0, 0, 10259, 'Trok'),
(14872, 0, 1, 'I''m so tired of running, but these bees won''t leave me alone!', 12, 1, 100, 0, 0, 0, 10260, 'Trok'),
(14872, 0, 2, 'I didn''t know bees didn''t like fire!', 12, 1, 100, 0, 0, 0, 10261, 'Trok'),
(14872, 0, 3, 'Karu will you please help get these bees off of me? They sting!', 12, 1, 100, 0, 0, 0, 10262, 'Trok');

DELETE FROM `creature_formations` WHERE `leaderGUID`=13178;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(13178, 13178, 0, 0, 0, 0, 0),
(13178, 13589, 3, 30, 0, 0, 0),
(13178, 13588, 3, 60, 0, 0, 0),
(13178, 13587, 3, 330, 0, 0, 0),
(13178, 13586, 3, 300, 0, 0, 0);

UPDATE `creature` SET `position_x`=180.182, `position_y`=-2862.82, `position_z`=93.2346 WHERE `guid` IN (13589, 13588, 13587, 13586);
DELETE FROM `creature_addon` WHERE  `guid` IN (13589, 13588, 13587, 13586);
DELETE FROM `waypoint_data` WHERE  `id` IN (135890, 135880, 135870, 135860);
UPDATE `creature_template` SET `speed_run`=1.257143 WHERE  `entry`=14894;
UPDATE `waypoint_data` SET `move_type`=1 WHERE  `id`=131780;
