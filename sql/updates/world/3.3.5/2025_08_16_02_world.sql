--
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (22035,22036);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22035,22036) AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2203500) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22035,0,0,0,37,0,100,0,0,0,0,0,0,116,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pure Spawn of Hydross - On AI Initialize - Set Corpse Delay"),
(22035,0,1,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pure Spawn of Hydross - On AI Initialize - Set Reactstate Passive"),
(22035,0,2,0,11,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pure Spawn of Hydross - On Spawn - Cast 'Elemental Spawn-in'"),
(22035,0,3,0,11,0,100,0,0,0,0,0,0,80,2203500,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pure Spawn of Hydross - On Spawn - Run Script"),

(22036,0,0,0,37,0,100,0,0,0,0,0,0,116,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tainted Spawn of Hydross - On AI Initialize - Set Corpse Delay"),
(22036,0,1,0,37,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tainted Spawn of Hydross - On AI Initialize - Set Reactstate Passive"),
(22036,0,2,0,11,0,100,0,0,0,0,0,0,11,25035,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tainted Spawn of Hydross - On Spawn - Cast 'Elemental Spawn-in'"),
(22036,0,3,0,11,0,100,0,0,0,0,0,0,80,2203500,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tainted Spawn of Hydross - On Spawn - Run Script"),

(2203500,9,0,0,0,0,100,0,3000,3000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pure Spawn of Hydross - On Script - Set Reactstate Aggressive");
