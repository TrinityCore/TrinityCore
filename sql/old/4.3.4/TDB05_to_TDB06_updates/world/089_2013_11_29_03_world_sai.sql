-- Scarshield Grunt SAI
SET @ENTRY := 9043;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,0,0,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarshield Grunt - Between 0-5 Range - Cast 11976 (Dungeon)"),
(@ENTRY,0,1,0,9,0,100,0,0,0,0,0,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarshield Grunt - Between 0-5 Range - Cast 11976");
-- Fix Burning Blade Summoner SAI
UPDATE `smart_scripts` SET `link`=0, `event_type`=61 WHERE `entryorguid`=4668 AND `id`=1;
