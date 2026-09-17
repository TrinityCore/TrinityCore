--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26321 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2632100 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26321,0,0,0,8,0,100,0,47530,0,0,0,0,80,2632100,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lothalor Ancient - On Spellhit 'Bark of the Walkers' - Run Script"),

(2632100,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lothalor Ancient - On Script - Say Line 0"),
(2632100,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lothalor Ancient - On Script - Set Orientation Invoker"),
(2632100,9,2,0,0,0,100,0,0,0,0,0,0,33,26321,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lothalor Ancient - On Script - Quest Credit 'Strengthen the Ancients'"),
(2632100,9,3,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lothalor Ancient - On Script - Despawn");

UPDATE `creature_template` SET `npcflag` = 16777216 WHERE `entry` = 26421;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26421 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2642100,2642101) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26421,0,0,0,0,0,100,0,3000,6000,8000,12000,0,11,50994,32,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodlands Walker - In Combat - Cast 'Toughen Hide'"),
(26421,0,1,0,8,0,100,0,47575,0,0,0,0,88,2642100,2642101,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodlands Walker - On Spellhit 'Strengthen the Ancients: On Interact Dummy to Woodlands Walker' - Run Random Script"),

(2642100,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Woodlands Walker - On Script - Say Line 0"),
(2642100,9,1,0,0,0,100,0,0,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodlands Walker - On Script - Set Faction 14"),
(2642100,9,2,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Woodlands Walker - On Script - Start Attack"),

(2642101,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Woodlands Walker - On Script - Say Line 1"),
(2642101,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Woodlands Walker - On Script - Set Orientation Invoker"),
(2642101,9,2,0,0,0,100,0,0,0,0,0,0,11,47550,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Woodlands Walker - On Script - Cast 'Create Bark of the Walkers'"),
(2642101,9,3,0,0,0,100,0,7000,7000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodlands Walker - On Script - Despawn");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_q12096_q12092_dummy','spell_q12096_q12092_bark');
