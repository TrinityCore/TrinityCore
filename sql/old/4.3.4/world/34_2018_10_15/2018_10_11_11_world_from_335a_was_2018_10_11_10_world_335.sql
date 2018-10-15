/*
-- 
DELETE FROM `creature` WHERE `guid` IN (87910,87928,87929,87930);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(87910, 4293, 189, 1, 1, 0, 1, 1805.176, 1167.855, 6.820, 0.162434, 7200, 0,  0),    
(87928, 4293, 189, 1, 1, 0, 1, 1782.416, 1118.755, 7.490, 5.97183, 7200, 0, 0),  
(87929, 4293, 189, 1, 1, 0, 1, 1759.67, 1146.85, 7.49036, 3.19674, 7200, 0, 0),
(87930, 4293, 189, 1, 1, 0, 1, 1788.68, 1145.46, 7.49084, 6.10664, 7200, 0, 0);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4293;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4293 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4293,0,0,0,0,0,100,0,1000,2000,3000,3500,0,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Scryer - IC - Cast Shadow Bolt"),
(4293,0,1,0,0,0,100,0,5000,7000,12000,17000,0,11,1090,1,0,0,0,0,5,0,0,0,0,0,0,0,"Scarlet Scryer - IC - Cast Shadow Sleep");
*/
