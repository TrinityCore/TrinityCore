--
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 28653;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 28653 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(28653,0,0,0,19,0,100,0,12687,0,0,0,0,11,52359,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Salanar the Horseman - On Quest 'Into the Realm of Shadows' Taken - Cast 'Realm of Shadows'"),
(28653,0,1,2,62,0,100,0,9739,0,0,0,0,11,52359,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Salanar the Horseman - On Gossip Option 0 Selected - Cast 'Realm of Shadows'"),
(28653,0,2,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Salanar the Horseman - On Gossip Option 0 Selected - Close Gossip");

DELETE FROM `spell_area` WHERE `spell` = 52693;
