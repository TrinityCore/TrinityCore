-- remove unused waypoint_scripts
DELETE FROM `waypoint_scripts` WHERE `id` IN (380,381,382,383,384);
DELETE FROM `db_script_string` WHERE `entry` IN (2000005237,2000005238,2000005239,2000005240,2000005241);

-- fix incorrect event 15 parameters for SAI:
UPDATE `smart_scripts` SET `event_param2`=0,`event_param3`=30 WHERE `entryorguid`=9450 AND `source_type`=0 AND `id`=11;
UPDATE `smart_scripts` SET `event_param2`=0,`event_param3`=10 WHERE `entryorguid`=11878 AND `source_type`=0 AND `id`=18;
UPDATE `smart_scripts` SET `event_param2`=0,`event_param3`=15 WHERE `entryorguid`=12339 AND `source_type`=0 AND `id`=4;

-- update horribad entries for Crimson Hand Blood Knight:
DELETE FROM `smart_scripts` WHERE `entryorguid`=20049;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20049,0,0,0, 0,0,100,2,5000,5000,25000,50000,11,39077,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Crimson Hand Blood Knight - In Combat - Cast Hammer of Justice'),
(20049,0,1,0,12,0,100,2,20,20,15000,15000,11,37259,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Crimson Hand Blood Knight - On Target below 20% HP - Cast Hammer of Wrath'),
(20049,0,2,0,14,0,100,2,0,100,35000,35000,11,37257,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crimson Hand Blood Knight - On Friendly Unit At 0 - 100% Health - Cast Flash of Light'),
(20049,0,3,0, 0,0,100,2,60000,60000,120000,160000,11,37257,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Crimson Hand Blood Knight - In Combat - Cast Flash of Light'),
(20049,0,4,0,14,0,100,2,50,20,40000,40000,11,37260,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crimson Hand Blood Knight - On Friendly Unit below 50% HP - Cast Renew'),
(20049,0,5,0,15,0,100,2,0,0,15,0,11,39078,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Crimson Hand Blood Knight - On Friendly Unit in CC - Cast Cleanse');
