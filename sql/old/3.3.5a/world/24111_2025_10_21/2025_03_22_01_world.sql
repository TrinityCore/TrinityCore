-- Mathrengyl Bearwalker missing outro emotes.

-- Add SmartAI to creature template
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4217;

-- Scripts
DELETE FROM `smart_scripts` WHERE `entryorguid`=4217 AND `source_type`=0 AND `id`IN (0,1,2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (421700,421701,421702,421703) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4217,0,1,0,20,0,100,0,6001,0,0,0,0,80,421701,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Quest 'Body and Heart' Rewarded - Run Script"),
(4217,0,2,0,20,0,100,0,5061,0,0,0,0,80,421702,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Quest 'Aquatic Form' Rewarded - Run Script"),
(4217,0,3,0,20,0,100,0,6125,0,0,0,0,80,421703,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Quest 'Power over Poison' Rewarded - Run Script"),

-- "Body and Heart"
(421701,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Set Orientation Invoker"),
(421701,9,1,0,0,0,100,0,0,0,0,0,0,5,469,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Play Emote"),
(421701,9,2,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Set Orientation Home Position"),

-- "Aquatic Form"
(421702,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Set Orientation Invoker"),
(421702,9,1,0,0,0,100,0,0,0,0,0,0,5,469,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Play Emote"),
(421702,9,2,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Set Orientation Home Position"),

-- "Power over Poison"
(421703,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Set Orientation Invoker"),
(421703,9,1,0,0,0,100,0,0,0,0,0,0,5,469,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Play Emote"),
(421703,9,2,0,0,0,100,0,2000,2000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mathrengyl Bearwalker - On Script - Set Orientation Home Position");
