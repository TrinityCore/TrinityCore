UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` IN (14884);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (14884);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(14884,0,0,0,25,0,100,0,0,3,0,0,75,23867,0,0,0,0,0,1,0,0,0,0,0,0,0,'Parasitic Serpent - Cast Parasitic Serpent aura on spawn'),
(14884,0,1,2,31,0,100,0,23865,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Parasitic Serpent - stop combat movement, linking to 2'),
(14884,0,2,0,61,0,100,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Parasitic Serpent - evade, linking to 3'),
(14884,0,3,0,7,0,100,0,0,0,0,0,41,10,0,0,0,0,0,1,0,0,0,0,0,0,0,'Parasitic Serpent - on evade despawn');
