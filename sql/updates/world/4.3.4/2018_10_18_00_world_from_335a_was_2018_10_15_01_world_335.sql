/*
-- 
DELETE FROM `creature` WHERE `guid` IN (90891,90893,90909,90923,90924);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`,`spawndist`, `MovementType`) VALUES
(90891, 7135, 1, 1, 1, 0, 0, 5708, -751.906, 377.419, 0.73825, 300, 5, 1),
(90893, 7135, 1, 1, 1, 0, 0, 5603.79, -985.106, 375.881, 2.88632, 300, 5, 1),
(90909, 7135, 1, 1, 1, 0, 0, 5462.9, -781.349, 351.154, 4.08013, 300, 5, 1),
(90923, 7135, 1, 1, 1, 0, 0, 5575.97, -709.797, 340.8, 5.81586, 300, 5, 1),
(90924, 7135, 1, 1, 1, 0, 0, 5551.63, -772.707, 344.833, 0.360496, 300, 5, 1);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=7135;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7135 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7135,0,0,0,0,0,100,0,1000,3000,14000,16000,0,11,2602,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infernal Bodyguard - IC - Fire Shield IV"),
(7135,0,1,0,0,0,100,0,4000,7000,10000,15000,0,11,22916,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infernal Bodyguard - IC - Uppercut");
*/
