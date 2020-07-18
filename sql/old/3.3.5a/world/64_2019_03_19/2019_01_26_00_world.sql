-- Scholomance Occultist (10472)
DELETE FROM `smart_scripts` WHERE `entryorguid`=10472 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10472, 0, 0, 0, 0, 0, 100, 0, 1000, 7000, 60000, 60000, 11, 16431, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scholomance Occultist - In Combat - Cast Bone Armor"),
(10472, 0, 1, 0, 13, 0, 100, 0, 10000, 20000, 0, 0, 11, 15122, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Scholomance Occultist - Victim Casting - Cast Counterspell"),
(10472, 0, 2, 0, 0, 0, 100, 0, 2000, 10000, 11000, 17000, 11, 17228, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scholomance Occultist - In Combat - Cast Shadow Bolt Volley"),
(10472, 0, 3, 0, 0, 0, 100, 0, 6000, 15000, 13000, 21000, 11, 17243, 64, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Scholomance Occultist - In Combat - Cast Drain Mana"),
(10472, 0, 4, 0, 0, 0, 50, 1, 5000, 5000, 0, 0, 36, 11284, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Scholomance Occultist - In Combat - update template");

UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=11284;
DELETE FROM `smart_scripts` WHERE `entryorguid`=11284 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(11284, 0, 0, 0, 0, 0, 100, 0, 6000, 15000, 13000, 21000, 11, 17228, 64, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Dark Shade - In Combat - Cast Shadow Bolt Volley');

DELETE FROM `creature_template_addon` WHERE `entry`=11284;
INSERT INTO `creature_template_addon` (`entry`, `auras`, `visibilityDistanceType`) VALUES (11284,"34311",0);
