-- Trok -- http://www.wowhead.com/npc=14872/trok#comments
-- Trok SAI
SET @ENTRY := 14872;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,20000,10000,20000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Trok - Out of Combat - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID`=14872;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `comment`) VALUES
(14872, 0, 0, 'Help! I''m being chased by a swarm of bees!', 12, 1, 100, 0, 0, 0, 10259, 'Trok'),
(14872, 0, 1, 'I''m so tired of running, but these bees won''t leave me alone!', 12, 1, 100, 0, 0, 0, 10260, 'Trok'),
(14872, 0, 2, 'I didn''t know bees didn''t like fire!', 12, 1, 100, 0, 0, 0, 10261, 'Trok'),
(14872, 0, 3, 'Karu will you please help get these bees off of me? They sting!', 12, 1, 100, 0, 0, 0, 10262, 'Trok');

DELETE FROM `creature_formations` WHERE `leaderGUID`=303759;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(303759, 303759, 0, 0, 512, 0, 0),
(303759, 303761, 3, 30, 512, 0, 0),
(303759, 303762, 3, 60, 512, 0, 0),
(303759, 303763, 3, 330, 512, 0, 0),
(303759, 303764, 3, 300, 512, 0, 0);

UPDATE `creature` SET `position_x`=180.182, `position_y`=-2862.82, `position_z`=93.2346 WHERE `guid` IN (303761, 303762, 303763, 303764);
DELETE FROM `creature_addon` WHERE  `guid` IN (303761, 303762, 303763, 303764);
DELETE FROM `waypoint_data` WHERE  `id` IN (3037610, 3037620, 3037630, 3037640);
UPDATE `creature_template` SET `speed_run`=1.257143 WHERE  `entry`=14894;
UPDATE `waypoint_data` SET `move_type`=1 WHERE  `id`=3037590;
