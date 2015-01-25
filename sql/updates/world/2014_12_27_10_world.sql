-- The Brewmaiden SAI
SET @ENTRY := 36021;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,100,0,101,0,0,0,11,48249,1,0,0,0,0,7,0,0,0,0,0,0,0,"The Brewmaiden - Received Emote 101 - Cast 'Brewfest Brew Toss'"),
(@ENTRY,0,1,2,54,0,100,0,0,0,0,0,75,68269,0,0,0,0,0,23,0,0,0,0,0,0,0,"The Brewmaiden - On Just Summoned - Add Aura 'The Brewmaiden's Blessing'"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,80,@ENTRY*100+00,2,0,0,0,0,1,0,0,0,0,0,0,0,"The Brewmaiden - On Just Summoned - Run Script");
