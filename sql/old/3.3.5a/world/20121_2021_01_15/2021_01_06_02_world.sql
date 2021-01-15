-- Sniffed
UPDATE `creature_model_info` SET `BoundingRadius` = 0.3, `CombatReach` = 1.5 WHERE `DisplayID` = 14932;
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 2.14285714286, `unit_flags` = 0, `AIName` = "SmartAI" WHERE `entry` = 15010;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 15010 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15010,0,0,0,54,0,100,0,0,0,0,0,0,11,24057,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Jungle Toad - On Just Summoned - Cast 'Confused'");

-- Guessed
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 4194304, `AIName` = "SmartAI" WHERE `entry` = 10577;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10577 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10577,0,0,0,54,0,100,0,0,0,0,0,0,11,16420,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crypt Scarab - On Just Summoned - Cast 'Crypt Scarab Confuse'"),
(10577,0,1,0,54,0,100,0,0,0,0,0,0,11,16423,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crypt Scarab - On Just Summoned - Cast 'Crypt Scarab Suicide Passive'"),
(10577,0,2,0,8,0,100,0,16424,0,0,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crypt Scarab - On Spellhit 'Crypt Scarab Suicide' - Kill Self");
