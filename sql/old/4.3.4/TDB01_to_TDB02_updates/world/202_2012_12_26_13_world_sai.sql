-- Syndicate Footpad SAI
SET @ENTRY := 2240;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,1800,9800,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Footpad - At 0 - 5 Range - Cast Backstab"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Footpad - At 15% HP - Flee For Assist");

-- Syndicate Thief SAI
SET @ENTRY := 2241;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,12000,36200,46300,11,6713,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Thief - In Combat - Cast Disarm"),
(@ENTRY,0,1,0,0,0,100,0,4800,16600,2000,25200,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Thief - In Combat - Cast Poison"),
(@ENTRY,0,2,0,9,0,100,0,0,5,1800,9800,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Thief - At 0 - 5 Range - Cast Backstab"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Thief - At 15% HP - Flee For Assist");

-- Syndicate Spy SAI
SET @ENTRY := 2242;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Spy - Out Of Combat - Cast Sneak"),
(@ENTRY,0,1,0,9,0,100,0,0,5,1800,9800,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Spy - At 0 - 5 Range - Cast Backstab"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Spy - At 15% HP - Flee For Assist");

-- Syndicate Sentry SAI
SET @ENTRY := 2243;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,12000,10700,28600,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Sentry - In Combat - Cast Shield Bash"),
(@ENTRY,0,1,0,0,0,100,0,35100,35100,30800,39200,11,15062,1,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Sentry - In Combat - Cast Shield Wall"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Sentry - At 15% HP - Flee For Assist");

-- Syndicate Saboteur SAI
SET @ENTRY := 2245;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Saboteur - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2500,5900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Saboteur - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,0,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,8,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,8,9,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,10,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,12,0,0,100,0,7400,10200,14500,26900,11,6980,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Saboteur - In Combat - Cast Fire Shot"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - In Combat - Display ranged weapon"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - At 15% HP - Increment Phase"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,16,2,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Saboteur - At 15% HP - Flee For Assist"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Saboteur - On Evade - Display melee weapon");

-- Syndicate Assassin SAI
SET @ENTRY := 2246;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Assassin - Out Of Combat - Cast Sneak"),
(@ENTRY,0,1,0,0,0,100,0,9200,17700,8200,30400,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Assassin - In Combat - Cast Poison"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Assassin - At 15% HP - Flee For Assist");

-- Syndicate Enforcer SAI
SET @ENTRY := 2247;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12800,18000,2300,13100,11,17207,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Enforcer - In Combat - Cast Whirlwind"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Enforcer - At 15% HP - Flee For Assist");

-- Mountain Yeti SAI
SET @ENTRY := 2250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1400,10800,10800,21800,11,3131,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mountain Yeti - In Combat - Cast Frost Breath");

-- Giant Yeti SAI
SET @ENTRY := 2251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,7800,10800,20500,11,3131,1,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Yeti - In Combat - Cast Frost Breath");

-- Crushridge Ogre SAI
SET @ENTRY := 2252;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Ogre - On Aggro - Say Line 0");

-- Texts for Crushridge Ogre
DELETE FROM `creature_text` WHERE `entry`= 2252;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2252,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Crushridge Ogre"),
(2252,0,1, "Me smash! You die!",12,0,100,0,0,0, "Crushridge Ogre"),
(2252,0,2, "I'll crush you!",12,0,100,0,0,0, "Crushridge Ogre");

-- Crushridge Brute SAI
SET @ENTRY := 2253;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Brute - On Aggro - Say Line 0");

-- Texts for Crushridge Brute
DELETE FROM `creature_text` WHERE `entry`= 2253;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2253,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Crushridge Brute"),
(2253,0,1, "Me smash! You die!",12,0,100,0,0,0, "Crushridge Brute"),
(2253,0,2, "I'll crush you!",12,0,100,0,0,0, "Crushridge Brute");

-- Crushridge Mauler SAI
SET @ENTRY := 2254;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mauler - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,4100,9300,10200,17900,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crushridge Mauler - In Combat - Cast Strike"),
(@ENTRY,0,2,0,0,0,100,0,7400,15800,7600,18700,11,6253,1,0,0,0,0,2,0,0,0,0,0,0,0,"Crushridge Mauler - In Combat - Cast Backhand");

-- Texts for Crushridge Mauler
DELETE FROM `creature_text` WHERE `entry`= 2254;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2254,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Crushridge Mauler"),
(2254,0,1, "Me smash! You die!",12,0,100,0,0,0, "Crushridge Mauler"),
(2254,0,2, "I'll crush you!",12,0,100,0,0,0, "Crushridge Mauler");

-- Crushridge Mage SAI
SET @ENTRY := 2255;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crushridge Mage - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3500,4800,11,9672,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crushridge Mage - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,0,0,5,0,0,79,10,150,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - At 0 - 5 Range - Set Ranged Movement"),
(@ENTRY,0,11,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,0,0,100,0,5300,7400,11300,21200,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Mage - In Combat - Cast Bloodlust");

-- Texts for Crushridge Mage
DELETE FROM `creature_text` WHERE `entry`= 2255;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2255,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Crushridge Mage"),
(2255,0,1, "Me smash! You die!",12,0,100,0,0,0, "Crushridge Mage"),
(2255,0,2, "I'll crush you!",12,0,100,0,0,0, "Crushridge Mage");

-- Crushridge Enforcer SAI
SET @ENTRY := 2256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9900,18000,24200,11,9791,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crushridge Enforcer - In Combat - Cast Head Crack");

-- Mug'thol SAI
SET @ENTRY := 2257;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4200,12000,3900,20300,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mug'thol - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,12000,13400,12100,39500,11,13730,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mug'thol - In Combat - Cast Demoralizing Shout");

-- Stone Fury SAI
SET @ENTRY := 2258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5200,7300,6000,25700,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stone Fury - In Combat - Cast Ground Tremor"),
(@ENTRY,0,1,0,0,0,100,0,6400,18500,5900,28500,11,5568,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stone Fury - In Combat - Cast Trample");

-- Dalaran Shield Guard SAI
SET @ENTRY := 2271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,4800,18100,0,0,11,3260,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Shield Guard - In Combat - Cast Violet Shield Effect"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dalaran Shield Guard - At 15% HP - Flee For Assist");

-- Dalaran Theurgist SAI
SET @ENTRY := 2272;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20819,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Theurgist - On Aggro - Cast Frostbolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3300,6600,11,20819,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Theurgist - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,1,4000,5300,4600,9900,11,3652,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - In Combat - Cast Summon Spirit of Old"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Theurgist - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dalaran Theurgist - At 15% HP - Flee For Assist");

-- Crushridge Warmonger SAI
SET @ENTRY := 2287;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Warmonger - On Aggro - Say Line 0"),
(@ENTRY,0,1,2,2,0,100,0,0,50,0,0,39,15,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Warmonger - At 50% HP - Call For Help"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Warmonger - At 50% HP - Say Line 1"),
(@ENTRY,0,3,4,14,0,100,0,0,15,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Warmonger - On Friendly Unit At 0 - 15% Health - Cast Frenzy"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Warmonger - On Friendly Unit At 0 - 15% Health - Say Line 2");

-- Texts for Crushridge Warmonger
DELETE FROM `creature_text` WHERE `entry`= 2287;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2287,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Crushridge Warmonger"),
(2287,0,1, "Me smash! You die!",12,0,100,0,0,0, "Crushridge Warmonger"),
(2287,0,2, "I'll crush you!",12,0,100,0,0,0, "Crushridge Warmonger"),
(2287,1,0, "%s calls for help!",16,0,100,0,0,0, "Crushridge Warmonger"),
(2287,2,0, "%s goes into a rage after seeing a friend fall in battle!",16,0,100,0,0,0, "Crushridge Warmonger");

-- Baron Vardus SAI
SET @ENTRY := 2306;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Vardus - On Aggro - Cast Frostbolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3200,7500,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Vardus - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,4,5,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - At 7% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,5000,17600,12200,39800,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - In Combat - Cast Frost Nova"),
(@ENTRY,0,11,0,0,0,100,0,1000,3000,12500,29800,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Baron Vardus - In Combat - Cast Backhand"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Vardus - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Baron Vardus - At 15% HP - Flee For Assist");

-- Argus Shadow Mage SAI
SET @ENTRY := 2318;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Argus Shadow Mage - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3500,4900,11,20816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Argus Shadow Mage - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 7% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,2,0,100,1,0,30,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 30% HP - Set Phase 3"),
(@ENTRY,0,11,12,2,0,100,0,0,30,0,0,11,4063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 30% HP - Cast Argus Shadow Mage Transform"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 30% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argus Shadow Mage - At 30% HP - Say Line 0");

-- Texts for Argus Shadow Mage
DELETE FROM `creature_text` WHERE `entry`= 2318;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2318,0,0, "I tire of this nonsense! Prepare to die!",12,0,100,0,0,0, "Argus Shadow Mage");

-- Syndicate Wizard SAI
SET @ENTRY := 2319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20815,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Wizard - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3500,5400,11,20815,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Wizard - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,12,9,0,100,0,0,5,0,0,79,10,150,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Wizard - At 0 - 5 Range - Set Ranged Movement"),
(@ENTRY,0,12,0,61,0,100,0,5000,9000,25000,35000,11,12824,1,0,0,0,0,6,0,0,0,0,0,0,0,"Syndicate Wizard - In Combat - Cast Polymorph");

-- Henchman Valik SAI
SET @ENTRY := 2333;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Henchman Valik - At 15% HP - Flee For Assist");

-- Giant Moss Creeper SAI
SET @ENTRY := 2349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,16400,30200,5200,36300,11,3396,32,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Moss Creeper - In Combat - Cast Corrosive Poison");

-- Dalaran Summoner SAI
SET @ENTRY := 2358;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20815,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Summoner - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - On Aggro - Set Phase 6"),
(@ENTRY,0,3,0,0,0,100,0,0,0,6200,6400,11,20815,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - At 15% Mana - Set Phase 5"),
(@ENTRY,0,6,0,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,3,0,100,0,30,100,100,100,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - At 100% Mana - Set Phase 6"),
(@ENTRY,0,9,10,0,0,100,0,7100,13900,0,0,11,3658,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Cast Summon Theurgist"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Say Line 0"),
(@ENTRY,0,11,12,0,0,100,0,14700,16100,0,0,11,3655,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Cast Summon Shield Guard"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalaran Summoner - In Combat - Say Line 0");

-- Texts for Dalaran Summoner
DELETE FROM `creature_text` WHERE `entry`= 2358;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2358,0,0, "%s begins to summon in reinforcements!",16,0,100,0,0,0, "Dalaran Summoner");

-- Elemental Slave SAI
SET @ENTRY := 2359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,75,0,0,11,3671,1,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Slave - At 75% HP - Cast Cracking Stone"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Slave - At 75% HP - Say Line 0"),
(@ENTRY,0,2,3,2,0,100,0,0,50,0,0,11,3672,1,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Slave - At 50% HP - Cast Crumbling Stone"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Slave - At 50% HP - Say Line 1"),
(@ENTRY,0,4,5,2,0,100,0,0,25,0,0,11,3673,1,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Slave - At 25% HP - Cast Reduced to Rubble"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elemental Slave - At 25% HP - Say Line 2");

-- Texts for Elemental Slave
DELETE FROM `creature_text` WHERE `entry`= 2359;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2359,0,0, "%s begins to crack and break apart.",16,0,100,0,0,0, "Elemental Slave"),
(2359,1,0, "%s's strength dwindles as chunks of rock break off.",16,0,100,0,0,0, "Elemental Slave"),
(2359,2,0, "%s is reduced to rubble, but still continues to fight.",16,0,100,0,0,0, "Elemental Slave");

-- Ricter SAI
SET @ENTRY := 2411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ricter - At 15% HP - Flee For Assist");

-- Alina SAI
SET @ENTRY := 2412;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Alina - At 15% HP - Flee For Assist");

-- Dermot SAI
SET @ENTRY := 2413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dermot - At 15% HP - Flee For Assist");

-- Kegan Darkmar SAI
SET @ENTRY := 2414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Kegan Darkmar - At 15% HP - Flee For Assist");

-- Warden Belamoore SAI
SET @ENTRY := 2415;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warden Belamoore - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3300,4900,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warden Belamoore - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,10300,10300,14900,37400,11,20828,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - In Combat - Cast Cone of Cold"),
(@ENTRY,0,11,0,0,0,100,0,7600,12900,9800,15900,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Warden Belamoore - In Combat - Cast Polymorph"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warden Belamoore - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Warden Belamoore - At 15% HP - Flee For Assist");

-- Crushridge Plunderer SAI
SET @ENTRY := 2416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crushridge Plunderer - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,1800,3900,7900,16200,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crushridge Plunderer - In Combat - Cast Cleave");

-- Texts for Crushridge Plunderer
DELETE FROM `creature_text` WHERE `entry`= 2416;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2416,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Crushridge Plunderer"),
(2416,0,1, "Me smash! You die!",12,0,100,0,0,0, "Crushridge Plunderer"),
(2416,0,2, "I'll crush you!",12,0,100,0,0,0, "Crushridge Plunderer");

-- Grel'borg the Miser SAI
SET @ENTRY := 2417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grel'borg the Miser - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,3400,6500,29900,38100,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grel'borg the Miser - In Combat - Cast Bloodlust"),
(@ENTRY,0,2,0,0,0,100,0,2000,2000,36000,36000,11,4979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grel'borg the Miser - In Combat - Cast Quick Flame Ward"),
(@ENTRY,0,3,0,0,0,100,0,10500,19400,10800,23500,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grel'borg the Miser - In Combat - Cast Rain of Fire");

-- Texts for Grel'borg the Miser
DELETE FROM `creature_text` WHERE `entry`= 2417;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2417,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Grel\'borg the Miser"),
(2417,0,1, "Me smash! You die!",12,0,100,0,0,0, "Grel\'borg the Miser"),
(2417,0,2, "I'll crush you!",12,0,100,0,0,0, "Grel\'borg the Miser");

-- Targ SAI
SET @ENTRY := 2420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,7366,0,0,0,0,0,1,0,0,0,0,0,0,0,"Targ - Out Of Combat - Cast Berserker Stance"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Targ - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,4000,16500,6000,19600,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Targ - In Combat - Cast Cleave"),
(@ENTRY,0,3,0,0,0,100,0,13200,16700,11500,24100,11,8147,1,0,0,0,0,2,0,0,0,0,0,0,0,"Targ - In Combat - Cast Thunderclap");

-- Texts for Targ
DELETE FROM `creature_text` WHERE `entry`= 2420;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2420,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Targ"),
(2420,0,1, "Me smash! You die!",12,0,100,0,0,0, "Targ"),
(2420,0,2, "I'll crush you!",12,0,100,0,0,0, "Targ");

-- Muckrake SAI
SET @ENTRY := 2421;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7900,13900,11800,26000,11,8379,0,0,0,0,0,2,0,0,0,0,0,0,0,"Muckrake - In Combat - Cast Disarm"),
(@ENTRY,0,1,0,0,0,100,0,13200,16200,6400,15700,11,12555,1,0,0,0,0,2,0,0,0,0,0,0,0,"Muckrake - In Combat - Cast Pummel");

-- Glommus SAI
SET @ENTRY := 2422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Glommus - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,500,1500,1100,9800,11,9128,1,0,0,0,0,1,0,0,0,0,0,0,0,"Glommus - In Combat - Cast Battle Shout"),
(@ENTRY,0,2,0,0,0,100,0,5800,11800,14500,35600,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Glommus - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,3,0,0,0,100,0,6800,8800,9600,32800,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Glommus - In Combat - Cast Knockdown");

-- Texts for Glommus
DELETE FROM `creature_text` WHERE `entry`= 2422;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2422,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Glommus"),
(2422,0,1, "Me smash! You die!",12,0,100,0,0,0, "Glommus"),
(2422,0,2, "I'll crush you!",12,0,100,0,0,0, "Glommus");

-- Lord Aliden Perenolde SAI
SET @ENTRY := 2423;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,13300,38300,11,11974,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Aliden Perenolde - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,1,0,2,0,100,0,0,50,36100,103800,11,8362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Aliden Perenolde - At 50% HP - Cast Renew"),
(@ENTRY,0,2,0,0,0,100,0,7000,12000,16000,22000,11,8399,1,0,0,0,0,6,0,0,0,0,0,0,0,"Lord Aliden Perenolde - In Combat - Cast Sleep"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lord Aliden Perenolde - At 15% HP - Flee For Assist");

-- Jailor Borhuin SAI
SET @ENTRY := 2431;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,7500,20100,33400,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Jailor Borhuin - In Combat - Cast Net"),
(@ENTRY,0,1,0,0,0,100,0,5900,10500,14000,32100,11,8379,1,0,0,0,0,2,0,0,0,0,0,0,0,"Jailor Borhuin - In Combat - Cast Disarm"),
(@ENTRY,0,2,0,0,0,100,0,11200,18300,11400,24800,11,12555,1,0,0,0,0,2,0,0,0,0,0,0,0,"Jailor Borhuin - In Combat - Cast Pummel"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Jailor Borhuin - At 15% HP - Flee For Assist");

-- Drunken Footpad SAI
SET @ENTRY := 2440;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,240000,500000,240000,500000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drunken Footpad - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,8900,177000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drunken Footpad - In Combat - Cast Strike");

-- Texts for Drunken Footpad
DELETE FROM `creature_text` WHERE `entry`= 2440;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2440,0,0, "Mmm... I love my delicious Southshore stout.",12,0,100,0,0,0, "Drunken Footpad");

-- Narillasanz SAI
SET @ENTRY := 2447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,4000,8000,11,9573,0,0,0,0,0,2,0,0,0,0,0,0,0,"Narillasanz - In Combat - Cast Flame Breath"),
(@ENTRY,0,1,0,2,0,100,0,0,50,20000,25000,11,8362,1,0,0,0,0,1,0,0,0,0,0,0,0,"Narillasanz - At 50% HP - Cast Renew");

-- Skhowl SAI
SET @ENTRY := 2452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,32000,38000,11,15971,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skhowl - In Combat - Cast Demoralizing Roar"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,9000,12000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skhowl - In Combat - Cast Backhand"),
(@ENTRY,0,2,0,2,0,100,0,0,50,19000,23000,11,16508,1,0,0,0,0,2,0,0,0,0,0,0,0,"Skhowl - At 50% HP - Cast Intimidating Roar");

-- Lo'Grosh SAI
SET @ENTRY := 2453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lo'Grosh - In Combat - Cast Bloodlust"),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,35000,38000,11,2601,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lo'Grosh - In Combat - Cast Fire Shield III"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,18000,22000,11,8814,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lo'Grosh - In Combat - Cast Flame Spike");

-- Archmage Ansirem Runeweaver SAI
SET @ENTRY := 2543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - On Aggro - Cast Frostbolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3500,6300,11,20792,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,4,5,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 7% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,5100,7400,3700,17600,11,512,33,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - In Combat - Cast Chains of Ice"),
(@ENTRY,0,11,0,0,0,100,0,7600,12500,26000,30000,11,118,32,0,0,0,0,6,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - In Combat - Cast Polymorph"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Archmage Ansirem Runeweaver - At 15% HP - Flee For Assist");

-- Dalaran Worker SAI
SET @ENTRY := 2628;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dalaran Worker - At 15% HP - Flee For Assist");

-- Nancy Vishas SAI
SET @ENTRY := 3984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Nancy Vishas - At 15% HP - Flee For Assist");

-- Grandpa Vishas SAI
SET @ENTRY := 3985;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Grandpa Vishas - At 15% HP - Flee For Assist");

-- Cyclonian SAI
SET @ENTRY := 6239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,10000,8000,11000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclonian - In Combat - Cast Whirlwind"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,33000,33000,11,6982,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cyclonian - In Combat - Cast Gust of Wind"),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,12000,15000,11,18670,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cyclonian - In Combat - Cast Knock Away");

-- Thanthaldis Snowgleam SAI
SET @ENTRY := 13217;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,8000,11000,11,19642,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thanthaldis Snowgleam - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,5000,7000,11,19644,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thanthaldis Snowgleam - In Combat - Cast Strike");

-- Jekyll Flandring SAI
SET @ENTRY := 13219;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,1000,1000,7000,7000,11,11567,1,0,0,0,0,2,0,0,0,0,0,0,0,"Jekyll Flandring - In Combat - Cast Heroic Strike");

-- The Abominable Greench SAI
SET @ENTRY := 13602;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Abominable Greench - On Respawn - Say Line 0");

-- Texts for The Abominable Greench
DELETE FROM `creature_text` WHERE `entry`= 13602;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(13602,0,0, "ARRRRRRR!",14,0,100,0,0,0, "The Abominable Greench");

-- Warmaster Laggrond SAI
SET @ENTRY := 13840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,8000,11000,11,19642,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaster Laggrond - In Combat - Cast Cleave");

-- Lieutenant Haggerdin SAI
SET @ENTRY := 13841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,8000,11000,11,19130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Haggerdin - In Combat - Cast Revenge"),
(@ENTRY,0,1,0,0,0,100,0,1000,4000,9000,14000,11,12169,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Haggerdin - In Combat - Cast Shield Block");

-- Gravis Slipknot SAI
SET @ENTRY := 14221;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gravis Slipknot - At 15% HP - Flee For Assist");

-- Jimmy the Bleeder SAI
SET @ENTRY := 14281;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Jimmy the Bleeder - At 15% HP - Flee For Assist");

-- Witherbark Troll SAI
SET @ENTRY := 2552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12800,22200,2100,32400,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Troll - In Combat - Cast Wither Touch"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Witherbark Troll - At 15% HP - Flee For Assist");

-- Witherbark Shadowcaster SAI
SET @ENTRY := 2553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,50,1,1000,1000,0,0,11,11939,1,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - Out Of Combat - Cast Summon Imp"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Shadowcaster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3600,6300,11,20816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Witherbark Shadowcaster - At 15% HP - Flee For Assist");

-- Witherbark Axe Thrower SAI
SET @ENTRY := 2554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Axe Thrower - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2100,4800,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,0,10200,26000,2500,6700,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Axe Thrower - In Combat - Cast Wither Touch"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Witherbark Axe Thrower - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Axe Thrower - On Evade - Display melee weapon");

-- Witherbark Witch Doctor SAI
SET @ENTRY := 2555;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6500,15300,80900,93900,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Witch Doctor - In Combat - Cast Healing Ward"),
(@ENTRY,0,1,0,0,0,100,0,0,16000,11100,23400,11,8190,0,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Witch Doctor - In Combat - Cast Magma Totem"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Witherbark Witch Doctor - At 15% HP - Flee For Assist");

-- Witherbark Headhunter SAI
SET @ENTRY := 2556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9500,24100,18500,39800,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Headhunter - In Combat - Cast Net"),
(@ENTRY,0,1,0,0,0,100,0,20200,31400,38500,47500,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Headhunter - In Combat - Cast Wither Touch"),
(@ENTRY,0,2,0,12,0,100,1,0,20,0,0,11,7160,1,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Headhunter - On Target At 0 - 20% HP - Cast Execute"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Witherbark Headhunter - At 15% HP - Flee For Assist");

-- Witherbark Shadow Hunter SAI
SET @ENTRY := 2557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,8600,15100,39900,11,992,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Shadow Hunter - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,0,0,100,0,1000,11700,48000,60000,11,7646,32,0,0,0,0,5,0,0,0,0,0,0,0,"Witherbark Shadow Hunter - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,2,0,0,0,100,0,11300,11300,30000,36600,11,6726,1,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Shadow Hunter - In Combat - Cast Silence"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Witherbark Shadow Hunter - At 15% HP - Flee For Assist");

-- Witherbark Berserker SAI
SET @ENTRY := 2558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,25600,23000,38300,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Witherbark Berserker - In Combat - Cast Wither Touch"),
(@ENTRY,0,1,0,0,0,100,0,0,15200,15100,28800,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Witherbark Berserker - In Combat - Cast Frenzy"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Witherbark Berserker - At 15% HP - Flee For Assist");

-- Highland Thrasher SAI
SET @ENTRY := 2560;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6100,13700,11200,18500,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highland Thrasher - In Combat - Cast Thrash");

-- Highland Fleshstalker SAI
SET @ENTRY := 2561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7300,9800,12200,24000,11,3393,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highland Fleshstalker - In Combat - Cast Consume Flesh");

-- Boulderfist Ogre SAI
SET @ENTRY := 2562;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Ogre - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,2,0,100,0,0,30,15300,42700,11,4955,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Ogre - At 30% HP - Cast Fist of Stone");

-- Texts for Boulderfist Ogre
DELETE FROM `creature_text` WHERE `entry`= 2562;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2562,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Boulderfist Ogre"),
(2562,0,1, "Me smash! You die!",12,0,100,0,0,0, "Boulderfist Ogre"),
(2562,0,2, "I'll crush you!",12,0,100,0,0,0, "Boulderfist Ogre");

-- Plains Creeper SAI
SET @ENTRY := 2563;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7200,22300,16000,39700,11,4962,32,0,0,0,0,2,0,0,0,0,0,0,0,"Plains Creeper - In Combat - Cast Encasing Webs"),
(@ENTRY,0,1,0,0,0,100,0,11000,22000,12600,22500,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Plains Creeper - In Combat - Cast Poison");

-- Boulderfist Enforcer SAI
SET @ENTRY := 2564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Enforcer - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,4800,13100,30500,40900,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Enforcer - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,2,0,2,0,100,0,0,30,27200,46600,11,4955,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Enforcer - At 30% HP - Cast Fist of Stone");

-- Texts for Boulderfist Enforcer
DELETE FROM `creature_text` WHERE `entry`= 2564;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2564,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Boulderfist Enforcer"),
(2564,0,1, "Me smash! You die!",12,0,100,0,0,0, "Boulderfist Enforcer"),
(2564,0,2, "I'll crush you!",12,0,100,0,0,0, "Boulderfist Enforcer");

-- Giant Plains Creeper SAI
SET @ENTRY := 2565;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6700,24600,15400,46200,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Plains Creeper - In Combat - Cast Poison"),
(@ENTRY,0,1,0,0,0,100,0,9800,34200,19000,38400,11,4962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Plains Creeper - In Combat - Cast Encasing Webs");

-- Boulderfist Brute SAI
SET @ENTRY := 2566;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Brute - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,5000,11500,12000,17500,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Brute - In Combat - Cast Knockdown"),
(@ENTRY,0,2,0,2,0,100,0,0,30,29200,29300,11,4955,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Brute - At 30% HP - Cast Fist of Stone");

-- Texts for Boulderfist Brute
DELETE FROM `creature_text` WHERE `entry`= 2566;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2566,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Boulderfist Brute"),
(2566,0,1, "Me smash! You die!",12,0,100,0,0,0, "Boulderfist Brute"),
(2566,0,2, "I'll crush you!",12,0,100,0,0,0, "Boulderfist Brute");

-- Boulderfist Magus SAI
SET @ENTRY := 2567;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,0,0,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - In Combat - Say Line 0"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Magus - On Aggro - Cast Frostbolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,3500,6400,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Magus - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,6,7,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - At 15% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,0,0,100,0,6000,9800,15400,23500,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - In Combat - Cast Frost Nova"),
(@ENTRY,0,13,14,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Magus - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Boulderfist Magus - At 15% HP - Flee For Assist");

-- Texts for Boulderfist Magus
DELETE FROM `creature_text` WHERE `entry`= 2567;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2567,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Boulderfist Magus"),
(2567,0,1, "Me smash! You die!",12,0,100,0,0,0, "Boulderfist Magus"),
(2567,0,2, "I'll crush you!",12,0,100,0,0,0, "Boulderfist Magus");

-- Boulderfist Mauler SAI
SET @ENTRY := 2569;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,5,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Mauler - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,11600,20300,15900,45500,11,4955,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Mauler - In Combat - Cast Fist of Stone");

-- Texts for Boulderfist Mauler
DELETE FROM `creature_text` WHERE `entry`= 2569;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2569,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Boulderfist Mauler"),
(2569,0,1, "Me smash! You die!",12,0,100,0,0,0, "Boulderfist Mauler"),
(2569,0,2, "I'll crush you!",12,0,100,0,0,0, "Boulderfist Mauler");

-- Boulderfist Shaman SAI
SET @ENTRY := 2570;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Shaman - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3500,6400,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderfist Shaman - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,12,2,0,100,1,0,45,0,0,11,6364,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - At 45% HP - Cast Searing Totem"),
(@ENTRY,0,12,0,61,0,100,1,0,40,0,0,11,11986,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Shaman - At 40% HP - Cast Healing Wave");

-- Texts for Boulderfist Shaman
DELETE FROM `creature_text` WHERE `entry`= 2570;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2570,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Boulderfist Shaman"),
(2570,0,1, "Me smash! You die!",12,0,100,0,0,0, "Boulderfist Shaman"),
(2570,0,2, "I'll crush you!",12,0,100,0,0,0, "Boulderfist Shaman");

-- Boulderfist Lord SAI
SET @ENTRY := 2571;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,2500,242400,250000,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Lord - In Combat - Cast Devotion Aura"),
(@ENTRY,0,1,0,0,0,100,0,11200,17300,21000,37500,11,4955,1,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderfist Lord - In Combat - Cast Fist of Stone");

-- Drywhisker Kobold SAI
SET @ENTRY := 2572;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Drywhisker Kobold - At 30% HP - Flee For Assist");

-- Drywhisker Surveyor SAI
SET @ENTRY := 2573;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drywhisker Surveyor - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3500,6400,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,5100,15000,215000,225000,11,865,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - In Combat - Cast Frost Nova"),
(@ENTRY,0,12,13,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Drywhisker Surveyor - At 15% HP - Flee For Assist");

-- Drywhisker Digger SAI
SET @ENTRY := 2574;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2500,6100,179800,180400,11,7164,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drywhisker Digger - Out Of Combat - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,0,1700,10300,6000,15400,11,8380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drywhisker Digger - In Combat - Cast Sunder Armor"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Drywhisker Digger - At 15% HP - Flee For Assist");

-- Dark Iron Supplier SAI
SET @ENTRY := 2575;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,2300,1300,3800,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Supplier - In Combat - Cast Poison"),
(@ENTRY,0,1,0,14,0,100,1,0,35,0,0,11,4961,1,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Iron Supplier - On Friendly Unit At 0 - 35% Health - Cast Resupply"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Supplier - At 15% HP - Flee For Assist");

-- Dark Iron Shadowcaster SAI
SET @ENTRY := 2577;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3500,8600,11,20816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,5500,12400,18200,30700,11,2941,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - In Combat - Cast Immolate"),
(@ENTRY,0,11,12,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,61,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Shadowcaster - At 15% HP - Flee For Assist");

-- Coyote SAI
SET @ENTRY := 834;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coyote - Out Of Combat - Play Sound 1018"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Coyote - Out Of Combat - Play Emote 393");

-- Rotten Ghoul SAI
SET @ENTRY := 846;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4400,5900,8200,17800,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rotten Ghoul - In Combat - Cast Poison");

-- Fleshripper SAI
SET @ENTRY := 1109;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,4000,13600,20300,24000,11,12166,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fleshripper - In Combat - Cast Muscle Tear");

-- Highland Lashtail SAI
SET @ENTRY := 1016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10500,18200,11200,33800,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highland Lashtail - In Combat - Cast Lash");

-- Highland Scytheclaw SAI
SET @ENTRY := 1017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,12000,25100,14000,20200,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highland Scytheclaw - In Combat - Cast Rend Flesh");

-- Highland Razormaw SAI
SET @ENTRY := 1018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,13900,21500,14100,36000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Highland Razormaw - In Combat - Cast Infected Wound");

-- Elder Razormaw SAI
SET @ENTRY := 1019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,0,6200,12200,20200,28100,11,3604,32,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Razormaw - In Combat - Cast Tendon Rip");

-- Mottled Scytheclaw SAI
SET @ENTRY := 1022;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8100,18100,16000,33800,11,3147,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mottled Scytheclaw - In Combat - Cast Rend Flesh");

-- Mottled Razormaw SAI
SET @ENTRY := 1023;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,24200,14000,28200,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mottled Razormaw - In Combat - Cast Infected Wound");

-- Bluegill Murloc SAI
SET @ENTRY := 1024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bluegill Murloc - At 15% HP - Flee For Assist");

-- Bluegill Puddlejumper SAI
SET @ENTRY := 1025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bluegill Puddlejumper - At 15% HP - Flee For Assist");

-- Bluegill Forager SAI
SET @ENTRY := 1026;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1200,4900,8500,25400,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Forager - In Combat - Cast Poison"),
(@ENTRY,0,1,0,0,0,100,0,9700,18200,7800,19400,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Forager - In Combat - Cast Sinister Strike"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bluegill Forager - At 15% HP - Flee For Assist");

-- Bluegill Warrior SAI
SET @ENTRY := 1027;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Warrior - Out Of Combat - Cast Battle Stance"),
(@ENTRY,0,1,0,0,0,100,0,3600,6800,3600,6800,11,9080,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Warrior - In Combat - Cast Hamstring"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bluegill Warrior - At 15% HP - Flee For Assist");

-- Bluegill Muckdweller SAI
SET @ENTRY := 1028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,0,1100,6300,11100,14500,11,1777,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bluegill Muckdweller - In Combat - Cast Gouge"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bluegill Muckdweller - At 15% HP - Flee For Assist");

-- Bluegill Oracle SAI
SET @ENTRY := 1029;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,60,0,0,11,6274,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Oracle - At 60% HP - Cast Healing Ward"),
(@ENTRY,0,1,0,14,0,100,0,0,30,11500,24600,11,939,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bluegill Oracle - On Friendly Unit At 0 - 30% Health - Cast Healing Wave"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bluegill Oracle - At 15% HP - Flee For Assist");

-- Black Slime SAI
SET @ENTRY := 1030;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1800,2400,186700,195200,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Slime - In Combat - Cast Dark Sludge");

-- Crimson Ooze SAI
SET @ENTRY := 1031;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,0,1200,2000,4800,14400,11,3322,32,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Ooze - In Combat - Cast Rancid Blood");

-- Black Ooze SAI
SET @ENTRY := 1032;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,0,1900,12500,7900,18900,11,3322,32,0,0,0,0,2,0,0,0,0,0,0,0,"Black Ooze - In Combat - Cast Rancid Blood");

-- Monstrous Ooze SAI
SET @ENTRY := 1033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,0,2800,4500,4500,13200,11,3322,32,0,0,0,0,2,0,0,0,0,0,0,0,"Monstrous Ooze - In Combat - Cast Rancid Blood");

-- Dragonmaw Raider SAI
SET @ENTRY := 1034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Raider - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,1200,12900,24800,27900,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Raider - In Combat - Cast Net"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Raider - At 15% HP - Flee For Assist");

-- Dragonmaw Battlemaster SAI
SET @ENTRY := 1037;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9100,14700,19000,38900,11,11839,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Battlemaster - In Combat - Cast Fireball"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Battlemaster - At 15% HP - Flee For Assist");

-- Fen Creeper SAI
SET @ENTRY := 1040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fen Creeper - Out Of Combat - Cast Sneak"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,28,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fen Creeper - On Aggro - Remove Aura Sneak");

-- Fen Lord SAI
SET @ENTRY := 1041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,8857,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fen Lord - Out Of Combat - Cast Summon Fen Dweller"),
(@ENTRY,0,1,0,0,0,100,0,3500,8900,11300,38900,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Fen Lord - In Combat - Cast Poison");

-- Red Whelp SAI
SET @ENTRY := 1042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,11800,15000,26400,11,3356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Whelp - In Combat - Cast Flame Lash");

-- Red Dragonspawn SAI
SET @ENTRY := 1045;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6500,9700,7700,9700,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Dragonspawn - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,8900,10400,6800,17000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Dragonspawn - In Combat - Cast Hamstring");

-- Red Wyrmkin SAI
SET @ENTRY := 1046;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1200,3900,22900,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Wyrmkin - In Combat - Cast Fireball"),
(@ENTRY,0,1,0,0,0,100,0,3200,24500,21100,26900,11,18399,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Wyrmkin - In Combat - Cast Flamestrike"),
(@ENTRY,0,2,0,0,0,100,0,3800,19700,13800,32800,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Wyrmkin - In Combat - Cast Fire Blast"),
(@ENTRY,0,3,0,0,0,100,0,7400,12500,8500,23300,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Wyrmkin - In Combat - Cast Arcane Bolt");

-- Red Scalebane SAI
SET @ENTRY := 1047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,18000,5800,16400,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Red Scalebane - In Combat - Cast Cleave");

-- Scalebane Lieutenant SAI
SET @ENTRY := 1048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3400,7600,9800,26800,11,16509,32,0,0,0,0,2,0,0,0,0,0,0,0,"Scalebane Lieutenant - In Combat - Cast Rend"),
(@ENTRY,0,1,0,0,0,100,0,4000,15100,6900,23100,11,12169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalebane Lieutenant - In Combat - Cast Shield Block"),
(@ENTRY,0,2,0,0,0,100,0,6000,12400,5400,20600,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalebane Lieutenant - In Combat - Cast Sunder Armor");

-- Wyrmkin Firebrand SAI
SET @ENTRY := 1049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11700,22700,12700,13500,11,17203,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmkin Firebrand - In Combat - Cast Fireball Volley"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,18700,11,17195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmkin Firebrand - In Combat - Cast Scorch"),
(@ENTRY,0,2,0,0,0,100,0,7500,19200,6600,22800,11,20754,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmkin Firebrand - In Combat - Cast Rain of Fire"),
(@ENTRY,0,3,0,0,0,100,0,3300,18500,9400,20800,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wyrmkin Firebrand - In Combat - Cast Shadow Bolt");

-- Scalebane Royal Guard SAI
SET @ENTRY := 1050;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5900,17300,5900,21000,11,16635,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalebane Royal Guard - In Combat - Cast Fire Nova"),
(@ENTRY,0,1,0,0,0,100,0,7100,15200,7400,29300,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalebane Royal Guard - In Combat - Cast Mortal Strike");

-- Dragonmaw Bonewarder SAI
SET @ENTRY := 1057;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,7900,21900,41500,61200,11,10651,32,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Bonewarder - In Combat - Cast Curse of the Eye"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,3360,32,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Bonewarder - In Combat - Cast Curse of the Eye");

-- Crimson Whelp SAI
SET @ENTRY := 1069;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1200,7800,60800,63500,11,184,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Whelp - In Combat - Cast Fire Shield II");

-- Leech Stalker SAI
SET @ENTRY := 1111;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2500,17100,32300,52800,11,3358,32,0,0,0,0,2,0,0,0,0,0,0,0,"Leech Stalker - In Combat - Cast Leech Poison");

-- Leech Widow SAI
SET @ENTRY := 1112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7600,9200,38200,61600,11,3388,32,0,0,0,0,2,0,0,0,0,0,0,0,"Leech Widow - In Combat - Cast Deadly Leech Poison");

-- First Mate Snellig SAI
SET @ENTRY := 1159;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,0,13000,14800,18200,35700,11,10651,32,0,0,0,0,2,0,0,0,0,0,0,0,"First Mate Snellig - In Combat - Cast Curse of the Eye"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,3360,32,0,0,0,0,2,0,0,0,0,0,0,0,"First Mate Snellig - In Combat - Cast Curse of the Eye"),
(@ENTRY,0,2,0,0,0,100,0,4100,19400,8100,19000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"First Mate Snellig - In Combat - Cast Disarm");

-- Gobbler SAI
SET @ENTRY := 1259;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7300,22600,32600,37800,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gobbler - In Combat - Cast Pierce Armor"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Gobbler - At 15% HP - Flee For Assist");

-- Sarltooth SAI
SET @ENTRY := 1353;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6700,8800,11100,28000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Sarltooth - In Combat - Cast Infected Wound"),
(@ENTRY,0,1,0,0,0,100,0,200,4700,4200,19900,11,3391,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sarltooth - In Combat - Cast Thrash");

-- Giant Wetlands Crocolisk SAI
SET @ENTRY := 2089;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,0,6400,8000,20200,30200,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Wetlands Crocolisk - In Combat - Cast Tendon Rip");

-- Ma'ruk Wyrmscale SAI
SET @ENTRY := 2090;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,300,900,10200,15900,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ma'ruk Wyrmscale - In Combat - Cast Battle Shout"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ma'ruk Wyrmscale - At 15% HP - Flee For Assist");

-- Mesa Buzzard SAI
SET @ENTRY := 2579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11400,18600,30500,60700,11,8139,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mesa Buzzard - In Combat - Cast Fevered Fatigue");

-- Elder Mesa Buzzard SAI
SET @ENTRY := 2580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9600,15400,39100,65100,11,8139,32,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Mesa Buzzard - In Combat - Cast Fevered Fatigue");

-- Stromgarde Troll Hunter SAI
SET @ENTRY := 2583;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,5000,19000,23000,11,2767,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stromgarde Troll Hunter - Out Of Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,1,0,2,0,100,0,0,50,12000,18000,11,17137,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stromgarde Troll Hunter - At 50% HP - Cast Flash Heal");

-- Stromgarde Defender SAI
SET @ENTRY := 2584;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,2000,6000,180000,180000,11,7164,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stromgarde Defender - Out Of Combat - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,0,7000,10000,9000,13000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stromgarde Defender - In Combat - Cast Shield Bash");

-- Stromgarde Vindicator SAI
SET @ENTRY := 2585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,14,0,100,1,0,20,0,0,11,8602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stromgarde Vindicator - On Friendly Unit At 0 - 20% Health - Cast Vengeance");

-- Syndicate Highwayman SAI
SET @ENTRY := 2586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Highwayman - Out Of Combat - Cast Sneak"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,28,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Highwayman - On Aggro - Remove Aura Sneak"),
(@ENTRY,0,2,0,0,0,100,0,1200,3400,2200,4200,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Highwayman - In Combat - Cast Backstab"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Highwayman - At 15% HP - Flee For Assist");

-- Syndicate Prowler SAI
SET @ENTRY := 2588;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Prowler - Out Of Combat - Cast Sneak"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,28,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Syndicate Prowler - On Aggro - Remove Aura Sneak"),
(@ENTRY,0,2,0,0,0,100,0,4900,14400,22500,41700,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Prowler - In Combat - Cast Sinister Strike"),
(@ENTRY,0,3,0,0,0,100,0,8000,15800,20200,36000,11,6713,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syndicate Prowler - In Combat - Cast Disarm"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Prowler - At 15% HP - Flee For Assist");

-- Syndicate Mercenary SAI
SET @ENTRY := 2589;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Syndicate Mercenary - At 15% HP - Flee For Assist");

-- Rumbling Exile SAI
SET @ENTRY := 2592;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3300,11600,11100,30700,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rumbling Exile - In Combat - Cast Ground Tremor");

-- Daggerspine Raider SAI
SET @ENTRY := 2595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12200,15700,17000,34200,11,6533,1,0,0,0,0,5,0,0,0,0,0,0,0,"Daggerspine Raider - In Combat - Cast Net"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Daggerspine Raider - At 15% HP - Flee For Assist");

-- Singer SAI
SET @ENTRY := 2600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4800,13100,30500,40900,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singer - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,1,0,0,0,70,0,9100,12100,26100,34300,11,14515,0,0,0,0,0,6,0,0,0,0,0,0,0,"Singer - In Combat - Cast Dominate Mind");

-- Foulbelly SAI
SET @ENTRY := 2601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,3106,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulbelly - Out Of Combat - Cast Aura of Rot"),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,12000,18000,11,7992,32,0,0,0,0,5,0,0,0,0,0,0,0,"Foulbelly - In Combat - Cast Slowing Poison"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,120000,130000,11,3583,32,0,0,0,0,2,0,0,0,0,0,0,0,"Foulbelly - In Combat - Cast Deadly Poison"),
(@ENTRY,0,3,0,0,0,100,1,9000,17000,0,0,11,3256,0,0,0,0,0,2,0,0,0,0,0,0,0,"Foulbelly - In Combat - Cast Plague Cloud");

-- Kovork SAI
SET @ENTRY := 2603;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,50,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Kovork - At 50% HP - Cast Frenzy");

-- Molok the Crusher SAI
SET @ENTRY := 2604;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,9700,13300,6100,16600,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Molok the Crusher - In Combat - Cast Backhand");

-- Zalas Witherbark SAI
SET @ENTRY := 2605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,5000,5000,27000,27000,11,512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zalas Witherbark - In Combat - Cast Chains of Ice"),
(@ENTRY,0,1,0,0,0,60,0,3000,3000,15000,15000,11,851,1,0,0,0,0,6,0,0,0,0,0,0,0,"Zalas Witherbark - In Combat - Cast Polymorph: Sheep");

-- Nimar the Slayer SAI
SET @ENTRY := 2606;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7800,10000,11100,24200,11,17207,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nimar the Slayer - In Combat - Cast Whirlwind"),
(@ENTRY,0,1,0,12,0,100,1,0,30,0,0,11,7160,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nimar the Slayer - On Target At 0 - 30% HP - Cast Execute"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Nimar the Slayer - At 15% HP - Flee For Assist");

-- Prince Galen Trollbane SAI
SET @ENTRY := 2607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,13730,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Galen Trollbane - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,6000,12000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Galen Trollbane - In Combat - Cast Sunder Armor");

-- Commander Amaren SAI
SET @ENTRY := 2608;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,20000,35000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Amaren - In Combat - Cast Battle Shout");

-- Fozruk SAI
SET @ENTRY := 2611;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12400,16200,23500,31400,11,6524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fozruk - In Combat - Cast Ground Tremor"),
(@ENTRY,0,1,0,0,0,100,0,5400,8600,10700,20900,11,5568,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fozruk - In Combat - Cast Trample");

-- Lieutenant Valorcall SAI
SET @ENTRY := 2612;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,7000,9000,11,13953,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Valorcall - In Combat - Cast Holy Strike"),
(@ENTRY,0,1,0,2,0,100,0,0,50,30000,36000,11,642,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Valorcall - At 50% HP - Cast Divine Shield"),
(@ENTRY,0,2,0,2,0,100,0,0,20,20000,25000,11,3472,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lieutenant Valorcall - At 20% HP - Cast Holy Light");

-- Kinelory SAI
SET @ENTRY := 2713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,30000,38000,11,4948,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - In Combat - Cast Kinelory's Bear Form"),
(@ENTRY,0,1,0,14,0,100,1,0,40,0,0,11,3627,1,0,0,0,0,7,0,0,0,0,0,0,0,"Kinelory - On Friendly Unit At 0 - 40% Health - Cast Rejuvenation");

-- Stromgarde Cavalryman SAI
SET @ENTRY := 2738;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stromgarde Cavalryman - On Aggro - Cast Rushing Charge");

-- Myzrael SAI
SET @ENTRY := 2755;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,1000,1000,5000,5000,11,4938,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzrael - In Combat - Cast Myzrael Earthquake");

-- Cresting Exile SAI
SET @ENTRY := 2761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1800000,1800000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cresting Exile - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,1,0,0,0,100,0,1400,7300,25600,32300,11,865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cresting Exile - In Combat - Cast Frost Nova");

-- Vengeful Surge SAI
SET @ENTRY := 2776;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1400,7300,25600,32300,11,14907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vengeful Surge - In Combat - Cast Frost Nova");

-- Marez Cowl SAI
SET @ENTRY := 2783;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,12380,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marez Cowl - Out Of Combat - Cast Shadow Channeling"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Marez Cowl - At 15% HP - Flee For Assist");

-- Gor'mul SAI
SET @ENTRY := 2792;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,4900,39000,46000,11,4153,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gor'mul - In Combat - Cast Guile of the Raptor");

-- Prismatic Exile SAI
SET @ENTRY := 2887;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,85,0,100,100,6000,6000,11,34083,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prismatic Exile - In Combat - Cast Fireball"),
(@ENTRY,0,1,0,0,0,75,1,0,0,2000,2000,11,12550,1,0,0,0,0,2,0,0,0,0,0,0,0,"Prismatic Exile - In Combat - Cast Lightning Shield");

-- Dark Iron Bombardier SAI
SET @ENTRY := 4062;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,30,6000,9000,11,8858,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Bombardier - At 5 - 30 Range - Cast Bomb");

-- Fardel Dabyrie SAI
SET @ENTRY := 4479;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,14000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fardel Dabyrie - In Combat - Cast Thrash"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,120000,130000,11,3583,1,0,0,0,0,2,0,0,0,0,0,0,0,"Fardel Dabyrie - In Combat - Cast Deadly Poison");

-- Kenata Dabyrie SAI
SET @ENTRY := 4480;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,6000,12000,11,8379,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kenata Dabyrie - In Combat - Cast Disarm");

-- Marcel Dabyrie SAI
SET @ENTRY := 4481;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marcel Dabyrie - On Aggro - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,19000,25000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Marcel Dabyrie - In Combat - Cast Shield Bash"),
(@ENTRY,0,2,0,0,0,100,0,15000,20000,20000,30000,11,15062,1,0,0,0,0,1,0,0,0,0,0,0,0,"Marcel Dabyrie - In Combat - Cast Shield Wall");

-- Refuge Pointe Defender SAI
SET @ENTRY := 10696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Refuge Pointe Defender - On Aggro - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,19000,25000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Refuge Pointe Defender - In Combat - Cast Shield Bash");

-- Rutherford Twing SAI
SET @ENTRY := 15126;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22911,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rutherford Twing - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,14000,18000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rutherford Twing - In Combat - Cast Backhand"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,7000,9000,11,17207,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rutherford Twing - In Combat - Cast Whirlwind");

-- Samuel Hawke SAI
SET @ENTRY := 15127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22911,1,0,0,0,0,1,0,0,0,0,0,0,0,"Samuel Hawke - On Aggro - Cast Charge"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,14000,18000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Samuel Hawke - In Combat - Cast Backhand"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,7000,9000,11,17207,0,0,0,0,0,2,0,0,0,0,0,0,0,"Samuel Hawke - In Combat - Cast Whirlwind"),
(@ENTRY,0,3,0,0,0,100,0,7000,11000,9000,11000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Samuel Hawke - In Combat - Cast Cleave"),
(@ENTRY,0,4,0,0,0,100,0,8000,10000,12000,15000,11,15708,1,0,0,0,0,2,0,0,0,0,0,0,0,"Samuel Hawke - In Combat - Cast Mortal Strike");

-- Defiler Elite SAI
SET @ENTRY := 15128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defiler Elite - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,19000,25000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Defiler Elite - In Combat - Cast Shield Bash");

-- League of Arathor Elite SAI
SET @ENTRY := 15130;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"League of Arathor Elite - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,0,6000,11000,19000,25000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"League of Arathor Elite - In Combat - Cast Shield Bash");

-- Scorched Guardian SAI
SET @ENTRY := 2726;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,700,6000,2200,15500,11,8873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorched Guardian - In Combat - Cast Flame Breath");

-- Feral Crag Coyote SAI
SET @ENTRY := 2728;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6100,16200,18300,27300,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feral Crag Coyote - In Combat - Cast Thrash");

-- Elder Crag Coyote SAI
SET @ENTRY := 2729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,30000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Crag Coyote - Out Of Combat - Play Sound 1018"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Crag Coyote - Out Of Combat - Play Emote 393");

-- Rabid Crag Coyote SAI
SET @ENTRY := 2730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10200,13900,18000,32300,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Crag Coyote - In Combat - Cast Infected Wound"),
(@ENTRY,0,1,0,0,0,100,1,5900,19400,34200,62000,11,3150,32,0,0,0,0,5,0,0,0,0,0,0,0,"Rabid Crag Coyote - In Combat - Cast Rabies");

-- Ridge Stalker SAI
SET @ENTRY := 2731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ridge Stalker - Out Of Combat - Cast Sneak"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,28,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ridge Stalker - On Aggro - Remove Aura Sneak");

-- Shadowforge Tunneler SAI
SET @ENTRY := 2739;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Tunneler - On Aggro - Cast Defensive Stance"),
(@ENTRY,0,1,0,0,0,100,0,7200,11900,7600,13700,11,8380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Tunneler - In Combat - Cast Sunder Armor"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Tunneler - At 15% HP - Flee For Assist");

-- Shadowforge Warrior SAI
SET @ENTRY := 2743;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7600,18600,22500,33100,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Warrior - In Combat - Cast Whirlwind"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Warrior - At 15% HP - Flee For Assist");

-- Shadowforge Commander SAI
SET @ENTRY := 2744;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,1032,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Commander - On Aggro - Cast Devotion Aura");

-- Ambassador Infernus SAI
SET @ENTRY := 2745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,300,300,12200,29500,11,9552,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ambassador Infernus - In Combat - Cast Searing Flames"),
(@ENTRY,0,1,0,0,0,100,0,4200,5200,14200,28300,11,11970,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Infernus - In Combat - Cast Fire Nova"),
(@ENTRY,0,2,0,0,0,100,0,7900,16700,24300,36400,11,2602,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Infernus - In Combat - Cast Fire Shield IV");

-- Rumbler SAI
SET @ENTRY := 2752;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7700,14500,11000,26300,11,6524,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rumbler - In Combat - Cast Ground Tremor"),
(@ENTRY,0,1,0,0,0,100,0,8400,16900,14700,37700,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rumbler - In Combat - Cast Trample");

-- Blacklash SAI
SET @ENTRY := 2757;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1000,19500,23500,11,9573,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blacklash - In Combat - Cast Flame Breath");

-- Hematus SAI
SET @ENTRY := 2759;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1400,1400,17300,30300,11,9574,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hematus - In Combat - Cast Flame Buffet");

-- Buzzard SAI
SET @ENTRY := 2830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,13900,22200,18100,38500,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Buzzard - In Combat - Cast Infected Wound");

-- Giant Buzzard SAI
SET @ENTRY := 2831;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6100,16000,18100,30200,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Giant Buzzard - In Combat - Cast Infected Wound");

-- Stonevault Bonesnapper SAI
SET @ENTRY := 2893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,15900,15700,26100,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Bonesnapper - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,9700,19800,15300,24800,11,12555,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Bonesnapper - In Combat - Cast Pummel"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonevault Bonesnapper - At 15% HP - Flee For Assist");

-- Stonevault Shaman SAI
SET @ENTRY := 2894;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,60,1,0,80,0,0,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Shaman - At 80% HP - Cast Healing Ward");

-- Magregan Deepshadow SAI
SET @ENTRY := 2932;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7600,18600,22500,31800,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magregan Deepshadow - In Combat - Cast Whirlwind");

-- Murdaloc SAI
SET @ENTRY := 2945;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Murdaloc - At 15% HP - Flee For Assist");

-- Shadowforge Ruffian SAI
SET @ENTRY := 4845;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5800,10100,5200,16100,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Ruffian - In Combat - Cast Kick"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Ruffian - At 15% HP - Flee For Assist");

-- Shadowforge Digger SAI
SET @ENTRY := 4846;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6500,10900,5900,11200,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Digger - In Combat - Cast Sunder Armor"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Digger - At 15% HP - Flee For Assist");

-- Stonevault Basher SAI
SET @ENTRY := 6733;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonevault Basher - At 15% HP - Flee For Assist");

-- Dreadmaul Mauler SAI
SET @ENTRY := 5977;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,8000,11000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Mauler - In Combat - Cast Thrash");

-- Wretched Lost One SAI
SET @ENTRY := 5979;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5300,10800,10100,24400,11,11962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Lost One - In Combat - Cast Immolate"),
(@ENTRY,0,1,0,0,0,100,0,17200,39600,29600,39600,11,11963,32,0,0,0,0,5,0,0,0,0,0,0,0,"Wretched Lost One - In Combat - Cast Enfeeble");

-- Black Slayer SAI
SET @ENTRY := 5982;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,12,0,100,0,0,20,30000,35000,11,7160,0,0,0,0,0,7,0,0,0,0,0,0,0,"Black Slayer - On Target At 0 - 20% HP - Cast Execute");

-- Bonepicker SAI
SET @ENTRY := 5983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,12,0,100,0,0,20,6000,12000,11,8139,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bonepicker - On Target At 0 - 20% HP - Cast Fevered Fatigue");

-- Scorpok Stinger SAI
SET @ENTRY := 5988;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7300,18800,7300,17600,11,5416,32,0,0,0,0,5,0,0,0,0,0,0,0,"Scorpok Stinger - In Combat - Cast Venom Sting");

-- Redstone Basilisk SAI
SET @ENTRY := 5990;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8500,28700,48900,48900,11,3635,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redstone Basilisk - In Combat - Cast Crystal Gaze");

-- Redstone Crystalhide SAI
SET @ENTRY := 5991;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7300,27400,48200,60200,11,5106,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redstone Crystalhide - In Combat - Cast Crystal Flash");

-- Ashmane Boar SAI
SET @ENTRY := 5992;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,11351,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - Out Of Combat - Cast Fire Shield"),
(@ENTRY,0,1,0,9,0,50,1,5,20,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashmane Boar - At 5 - 20 Range - Cast Rushing Charge");

-- Helboar SAI
SET @ENTRY := 5993;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Helboar - On Aggro - Cast Rushing Charge"),
(@ENTRY,0,1,0,0,0,100,0,13800,14900,20800,29700,11,11970,1,0,0,0,0,1,0,0,0,0,0,0,0,"Helboar - In Combat - Cast Fire Nova");

-- Nethergarde Miner SAI
SET @ENTRY := 5996;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,7000,11000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Miner - In Combat - Cast Sunder Armor"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Nethergarde Miner - At 15% HP - Flee For Assist");

-- Nethergarde Foreman SAI
SET @ENTRY := 5998;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,12000,16000,11,5115,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Foreman - In Combat - Cast Battle Command"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Nethergarde Foreman - At 15% HP - Flee For Assist");

-- Nethergarde Soldier SAI
SET @ENTRY := 5999;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,12000,15000,11,3248,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Soldier - In Combat - Cast Improved Blocking"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,13000,16000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Soldier - In Combat - Cast Shield Bash");

-- Nethergarde Cleric SAI
SET @ENTRY := 6000;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,6000,9000,11,9734,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Cleric - In Combat - Cast Holy Smite"),
(@ENTRY,0,1,0,2,0,100,0,0,50,45000,60000,11,11974,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Cleric - At 50% HP - Cast Power Word: Shield"),
(@ENTRY,0,2,0,14,0,100,0,0,40,16000,21000,11,2054,1,0,0,0,0,7,0,0,0,0,0,0,0,"Nethergarde Cleric - On Friendly Unit At 0 - 40% Health - Cast Heal"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Nethergarde Cleric - At 15% HP - Flee For Assist");

-- Nethergarde Analyst SAI
SET @ENTRY := 6001;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,25000,28000,11,7140,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Analyst - In Combat - Cast Expose Weakness");
