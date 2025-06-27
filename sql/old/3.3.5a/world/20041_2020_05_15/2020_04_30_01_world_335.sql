-- 
UPDATE `item_template` SET `ScriptName` = "" WHERE `entry` = 31742;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 22408;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22408 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22408,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Furious Nether-wraith - On Just Summoned - Start Attacking"),
(22408,0,1,0,0,0,100,0,0,0,3000,5000,0,11,39337,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Furious Nether-wraith - In Combat - Cast 'Arcane Bolt'"),
(22408,0,2,0,0,0,100,0,10000,15000,22000,28000,0,11,38205,1,0,0,0,0,2,0,0,0,0,0,0,0,0,"Furious Nether-wraith - In Combat - Cast 'Shadow Blast'");
