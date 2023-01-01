-- 
DELETE FROM `areatrigger_scripts` WHERE `entry` = 822;
DELETE FROM `areatrigger_involvedrelation` WHERE `id` = 822;
INSERT INTO `areatrigger_involvedrelation` (`id`,`quest`) VALUES
(822,2240);

UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = 4863;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4863 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4863,0,0,0,0,0,100,0,8000,12000,30000,40000,0,11,3636,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Jadespine Basilisk - In Combat - Cast 'Crystalline Slumber'");
