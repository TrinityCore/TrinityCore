-- Chief Hawkwind SAI For Quest 24861 "Last Rites, First Rites" 4XX
SET @ENTRY   := 2981; -- NPC entry
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@ENTRY*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,19,0,100,0,24861,0,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - On Quest 24861 Accept - Run Script'),
(@ENTRY*100,0,0,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - Script - say 0'),
(@ENTRY*100,0,1,0,0,0,100,0,6000,6000,6000,6000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - Script - say 1'),
(@ENTRY*100,0,2,0,0,0,100,0,8000,8000,8000,8000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - Script - say 2'),
(@ENTRY*100,0,3,0,0,0,100,0,7000,7000,7000,7000,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Chief Hawkwind - Script - say 3');
-- NPC talk text insert from sniff
DELETE FROM `creature_text` WHERE `entry`=2981;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2981,0,0, 'Earth Mother, into your arms we give one of our own. She is Unaya Hawkwind, my mother, and Greatmother to us all; the wisest of our tribe.',12,0,100,1,0,0, 'Chief Hawkwind'), -- 18/11/2011 10:17:56 PM
(2981,1,0, 'May her spirit fly to you swiftly; may the winds carry her gently, and the grass whisper her name.',12,0,100,1,0,0, 'Chief Hawkwind'), -- 18/11/2011 10:18:03 PM
(2981,2,0, 'Watch over her as she has watched over us; let her look down on us with joy, through the eternal gaze of An''she and Mu''sha, until we too join her in death.',12,0,100,1,0,0, 'Chief Hawkwind'), -- 18/11/2011 10:18:11 PM
(2981,3,0, 'For we are all born of you, and shall all return to you.',12,0,100,1,0,0, 'Chief Hawkwind'); -- 18/11/2011 10:18:18 PM
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=11006 AND `text_id`=15309;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (11006,15309);
