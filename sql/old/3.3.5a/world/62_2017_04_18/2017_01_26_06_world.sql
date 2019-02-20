-- Plains Mammoth - Increase Randommove + Add script for emote
UPDATE `creature` SET `spawndist`=10 WHERE `id`=30448 AND `spawndist`=5;
UPDATE `creature` SET `spawndist`=10, `MovementType`=1 WHERE  `guid`=118583;

-- Plains Mammoth SAI
SET @ENTRY := 30448;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`>=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,1,0,100,0,4000,45000,45000,45000,80,@ENTRY*100+00,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Mammoth - Out of Combat - Run Script"),
(@ENTRY,0,2,0,4,0,100,0,0,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Mammoth - On Aggro - Set Rooted Off");

-- Actionlist SAI
SET @ENTRY := 3044800;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Mammoth - On Script - Set Active On"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Mammoth - On Script - Set Rooted On"),
(@ENTRY,9,2,0,0,0,100,0,100,100,0,0,5,377,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Mammoth - On Script - Play Emote 377"),
(@ENTRY,9,3,0,0,0,100,0,5000,5000,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Mammoth - On Script - Set Rooted Off"),
(@ENTRY,9,4,0,0,0,100,0,0,0,0,0,48,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plains Mammoth - On Script - Set Active Off");
