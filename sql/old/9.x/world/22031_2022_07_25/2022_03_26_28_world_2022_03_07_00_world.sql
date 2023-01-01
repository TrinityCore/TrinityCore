--
UPDATE `creature_template` SET `unit_flags` = 32768, `AIName` = 'SmartAI' WHERE `entry` IN (35060,35061,35071,35072);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (35060,35061,35071,35072) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(35060,0,0,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"North Sea Thresher - On Spawn - Start Attack Summoner"),
(35061,0,0,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"North Sea Blue Shark - On Spawn - Start Attack Summoner"),
(35071,0,0,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"North Sea Mako - On Spawn - Start Attack Summoner"),

(35072,0,0,0,11,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Angry Kvaldir - On Spawn - Start Attack Summoner"),
(35072,0,1,0,0,0,100,0,0,0,15000,15000,0,11,49922,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Angry Kvaldir - In Combat - Cast 'Wave Crash'");
