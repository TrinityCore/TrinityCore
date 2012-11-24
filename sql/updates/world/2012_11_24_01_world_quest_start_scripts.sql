-- fix possible chaining issue, remove quest_start_script
UPDATE `quest_template` SET `NextQuestId`=4024,`StartScript`=0 WHERE `Id`=4023;
DELETE FROM `quest_start_scripts` WHERE `id`=4023;
-- Already done in cpp, can be removed
UPDATE `quest_template` SET `StartScript`=0 WHERE `Id` IN (6482,9686,11300); 
DELETE FROM `quest_start_scripts` WHERE `id` IN (6482,9686,11300); 
-- there is no need for external requirement in this case
UPDATE `quest_template` SET `StartScript`=0 WHERE `Id`=10162;
DELETE FROM `quest_start_scripts` WHERE `id`=10162;
-- Change cast spell after 0s to cast on accept (same thing, different table)
UPDATE `quest_template` SET `SourceSpellId`=25201,`StartScript`=0 WHERE `Id`=8305;
DELETE FROM `quest_start_scripts` WHERE `id`=8305;
-- convert quest_start_scripts into SAI;
DELETE FROM `quest_start_scripts` WHERE `id`=2701;
UPDATE `quest_template` SET `StartScript`=0 WHERE `Id`=2701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=7750;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7750 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7750,0,0,0,19,0,100,0,2701,0,0,0,70,0,0,0,0,0,0,14,44732,141981,0,0,0,0,0, 'Corporal Thund Splithoof - On Quest Accept - Respawn Spectral Lockbox Particles (GO)'),
(7750,0,1,0,19,0,100,0,2701,0,0,0,70,0,0,0,0,0,0,14,44733,141980,0,0,0,0,0, 'Corporal Thund Splithoof - On Quest Accept - Respawn Spectral Lockbox (GO)');
-- BEWARE: THIS (TEMP) REMOVES SUPPORT FOR QUESTS 434,10985,11108,11198!
DELETE FROM `quest_start_scripts` WHERE `id` IN (434,10985,11108,11198);
UPDATE `quest_template` SET `StartScript`=0 WHERE `Id` IN (434,10985,11108,11198);
DELETE FROM `db_script_string` WHERE `entry` IN (2000000033,2000000034,2000000035,2000000036,2000000037,2000000038,2000000039,2000000040,2000000041);
