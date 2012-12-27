-- Fix for Quest: 12843 "They Took Our Men!"
-- SAI for Rusty Cage
SET @ENTRY=191544;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY AND `source_type`=1);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY*100 AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,1,70,0,100,0,2,0,0,0,45,0,1,0,0,0,0,11,29466,5,0,0,0,0,0,'Rusty Cage - On activate - set data on Goblin Prisoner'),
(@ENTRY,1,1,0,61,0,100,0,0,0,0,0,33,29466,0,0,0,0,0,7,0,0,0,0,0,0,0,'Rusty Cage - On activate - quest credit');
-- SAI for Goblin Prisoner
SET @ENTRY=29466;
UPDATE `creature` SET `modelid`=0,`spawntimesecs`=120,`curhealth`=1 WHERE `id`=29466;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY*100 AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,32,0,0,0,0,0,0,15,191544,5,0,0,0,0,0,'Goblin Prisoner - On respawn - reset cage'),
(@ENTRY,0,1,0,38,0,100,0,0,1,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Prisoner - On dataset - Run Script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,45,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Prisoner - Script - set data 0'),
(@ENTRY*100,9,1,0,0,0,100,0,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Prisoner - Script - Say random text'),
(@ENTRY*100,9,2,0,0,0,100,0,2000,2000,2000,2000,46,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Prisoner - Script - move 10 yards'),
(@ENTRY*100,9,3,0,0,0,100,0,4000,4000,4000,4000,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Goblin Prisoner - Script - despawn');
-- Goblin Prisoner
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I can''t believe it! I''m free to go!',12,0,100,5,0,0, 'Goblin Prisoner'),
(@ENTRY,0,1, 'I''m free? I''m free!',12,0,100,5,0,0, 'Goblin Prisoner'),
(@ENTRY,0,2, 'Time to hightail it! Thanks, friend!',12,0,100,5,0,0, 'Goblin Prisoner');
