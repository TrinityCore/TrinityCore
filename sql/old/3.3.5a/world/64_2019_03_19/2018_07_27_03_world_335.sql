-- 
-- Tidelord Rrurgaz
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=16072;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16072 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(16072,0,0,0,0,0,100,0,2000,4000,14000,21000,0,11,16244,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidelord Rrurgaz - In Combat - Cast 'Demoralizing Shout'"),
(16072,0,1,0,0,0,100,0,5000,7000,19000,22000,0,11,16509,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tidelord Rrurgaz - In Combat - Cast 'Rend'"),
(16072,0,2,0,0,0,100,0,7000,9000,8000,12000,0,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidelord Rrurgaz - In Combat - Cast 'Whirlwind'"),
(16072,0,3,0,0,0,100,0,9000,12000,14000,17000,0,11,15588,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tidelord Rrurgaz - In Combat - Cast 'Thunderclap'");

-- Strashaz Warrior
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4364;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4364 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4364,0,0,0,0,0,100,0,5000,7000,12000,15000,0,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Warrior - In Combat - Cast 'Hamstring'"),
(4364,0,1,0,0,0,100,0,4000,9000,8000,12000,0,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Warrior - In Combat - Cast 'Mortal Strike'"),
(4364,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Strashaz Warrior - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Strashaz Sorceress
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4370;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4370 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4370,0,0,0,0,0,100,0,0,0,3000,5000,0,11,12737,64,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Sorceress - In Combat - Cast 'Frostbolt'"),
(4370,0,1,0,0,0,100,0,12000,16000,16000,21000,0,11,15499,0,0,0,0,0,5,0,0,0,0,0,0,0,"Strashaz Sorceress - In Combat - Cast 'Frost Shock'"),
(4370,0,2,0,9,0,100,0,0,8,12000,15000,0,11,15532,0,0,0,0,0,1,0,0,0,0,0,0,0,"Strashaz Sorceress - Within 0-8 Range - Cast 'Frost Nova'"),
(4370,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Strashaz Sorceress - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Strashaz Siren
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4371;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4371 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4371,0,0,0,0,0,100,0,0,0,3000,5000,0,11,15587,64,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Siren - In Combat - Cast 'Mind Blast'"),
(4371,0,1,0,0,0,100,0,11000,15000,21000,26000,0,11,15654,0,0,0,0,0,5,0,0,0,0,0,0,0,"Strashaz Siren - In Combat - Cast 'Shadow Word: Pain'"),
(4371,0,2,0,0,0,100,0,8000,12000,16000,22000,0,11,7645,0,0,0,0,0,6,0,0,0,0,0,0,0,"Strashaz Siren - In Combat - Cast 'Dominate Mind'"),
(4371,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Strashaz Siren - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Strashaz Myrmidon
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4368;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4368 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4368,0,0,0,0,0,100,0,5000,7000,11000,14000,0,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Myrmidon - In Combat - Cast 'Cleave'"),
(4368,0,1,0,0,0,100,0,7000,11000,9000,13000,0,11,18812,0,0,0,0,0,5,0,0,0,0,0,0,0,"Strashaz Myrmidon - In Combat - Cast 'Knockdown'"),
(4368,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Strashaz Myrmidon - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Strashaz Serpent Guard
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4366;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4366 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4366,0,0,0,0,0,100,0,5000,7000,7000,11000,0,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Serpent Guard - In Combat - Cast 'Strike'"),
(4366,0,1,0,0,0,100,0,4000,9000,18000,24000,0,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Strashaz Serpent Guard - In Combat - Cast 'Disarm'"),
(4366,0,2,0,0,0,100,0,7000,12000,21000,25000,0,11,16509,0,0,0,0,0,5,0,0,0,0,0,0,0,"Strashaz Serpent Guard - In Combat - Cast 'Rend'"),
(4366,0,3,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Strashaz Serpent Guard - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Strashaz Hydra
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=4374;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4374 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4374,0,0,0,25,0,100,0,0,0,0,0,0,11,8876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Strashaz Hydra - On Reset - Cast 'Thrash'"),
(4374,0,1,0,0,0,100,0,5000,9000,12000,21000,0,11,16128,0,0,0,0,0,5,0,0,0,0,0,0,0,"Strashaz Hydra - In Combat - Cast 'Infected Bite'");

-- Doctor Weavil
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=15552;
DELETE FROM `smart_scripts` WHERE `entryorguid`=15552 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15552,0,0,0,0,0,100,0,8000,14000,8000,14000,0,11,25774,0,0,0,0,0,1,0,0,0,0,0,0,0,"Doctor Weavil - In Combat - Cast 'Mind Shatter'"),
(15552,0,1,0,0,0,100,0,15000,15000,120000,120000,0,11,25772,0,0,0,0,0,2,0,0,0,0,0,0,0,"Doctor Weavil - In Combat - Cast 'Mental Domination'");
