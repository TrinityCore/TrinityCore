-- Emotes for Magrami Spectre
-- Actionlist SAI
SET @ENTRY := 1156000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magrami Spectre - On Script - Set Run Off"),
(@ENTRY,9,1,0,0,0,100,0,0,0,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0,"Magrami Spectre - On Script - Say Line 0"),
(@ENTRY,9,2,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,20,177746,70,0,0,0,0,0,"Magrami Spectre - On Script - Move To Closest Gameobject 'Ghost Magnet'"),
(@ENTRY,9,3,0,0,0,100,0,7000,7000,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,"Magrami Spectre - On Script - Start Attacking");

DELETE FROM `creature_text` WHERE `entry`=11560;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES 
(11560, 0, 0, '%s is drawn to the ghost magnet...', 16, 0, 100, 0, 0, 0, 7585, 'Magrami Spectre'),
(11560, 0, 1, '%s is angered!', 16, 0, 100, 0, 0, 0, 7583, 'Magrami Spectre');
