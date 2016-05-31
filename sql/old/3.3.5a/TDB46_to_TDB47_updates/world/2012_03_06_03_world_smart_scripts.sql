-- SAI for Elrodan
SET @ENTRY=18743;
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=@ENTRY*100 AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,8000,15000,25000,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,'Elrodan - OOC - run script'),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,11,18744,20,0,0,0,0,0,'Elrodan - Script - Aurosalia say random'),
(@ENTRY*100,9,1,0,0,0,100,0,3000,3000,3000,3000,11,32826,0,0,0,0,0,1,0,0,0,0,0,0,0,'Elrodan - Script - cast Polymorph Cast Visual');
-- Aurosalia fix model
UPDATE `creature_model_info` SET `modelid_other_gender`=0 WHERE `modelid`=18145;
-- Aurosalia text
DELETE FROM `creature_text` WHERE `entry`=18744;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(18744,0,0, 'Stop!',1,0,100,5,0,0, 'Aurosalia'),
(18744,0,1, 'Will you stop--',1,0,100,274,0,0, 'Aurosalia'),
(18744,0,2, '',1,0,100,6,0,0, 'Aurosalia');
