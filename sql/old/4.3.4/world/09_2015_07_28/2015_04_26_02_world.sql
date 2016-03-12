--
SET @ENTRY := 18225;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,85,31961,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fire Bomb Target - On Just Summoned - InvokerCast 'Fire Bomb'"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,31963,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fire Bomb Target - On Just Summoned - Cast to Summon Fire Bomb");
