-- Bleakheart Hellcaller SAI
SET @ENTRY := 3771;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0, 1,0,100,1,0,   0,0,0,31,    1,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - Out of Combat - Set Phase Random Between 1-2 (No Repeat)"),
(@ENTRY,0,1,2, 1,1,100,0,0,1000,0,0,11,12746,3,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - Out of Combat - Cast 'Summon Voidwalker' (Phase 1)"),
(@ENTRY,0,2,0,61,1,100,0,0,1000,0,0,22,    0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - Out of Combat - Set Event Phase 0 (Phase 1)"),
(@ENTRY,0,3,4, 1,2,100,0,0,1000,0,0,11,11939,3,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - Out of Combat - Cast 'Summon Imp' (Phase 2)"),
(@ENTRY,0,4,0,61,2,100,0,0,1000,0,0,22,    0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - Out of Combat - Set Event Phase 0 (Phase 2)"),
(@ENTRY,0,5,0, 2,0,100,1,0,  15,0,0,11,    8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Hellcaller - Between 0-15% Health - cast enrage (No Repeat)");
