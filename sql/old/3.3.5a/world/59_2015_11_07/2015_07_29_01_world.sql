--
SET @ENTRY := 8075;
UPDATE `creature_template` SET `InhabitType`=4, `AIName`="SmartAI" WHERE `entry` IN (@ENTRY);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY, -312720) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,46,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Edana Hatetalon - on Just summoned - move forward"),
(@ENTRY,0,1,0,9,0,100,0,0,20,5000,5000,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Edana Hatetalon - In range  - Lightning Bolt"),
(@ENTRY,0,2,0,0,0,100,0,4000,5000,20000,22000,11,8293,2,0,0,0,0,2,0,0,0,0,0,0,0,"Edana Hatetalon - IC - Cast Lightning Cloud"),
(@ENTRY,0,3,0,0,0,100,0,9000,10000,7000,9000,11,12058,2,0,0,0,0,2,0,0,0,0,0,0,0,"Edana Hatetalon - IC - Cast Chain Lightning");
