-- Lok Orcbane SAI
SET @ENTRY := 3435;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,15000,15000,7000,7000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lok Orcbane - In Combat - Cast Hamstring");

-- Darbel Montrose SAI
SET @ENTRY := 2598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,8722,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - Out Of Combat - Cast Summon Succubus"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darbel Montrose - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3600,6000,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darbel Montrose - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,1,4300,6800,0,0,11,12741,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,12,0,0,0,100,0,10000,15000,25000,35000,11,8994,1,0,0,0,0,6,0,0,0,0,0,0,0,"Darbel Montrose - In Combat - Cast Banish"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darbel Montrose - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Darbel Montrose - At 15% HP - Flee For Assist");

-- Geomancer Flintdagger SAI
SET @ENTRY := 2609;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Geomancer Flintdagger - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3400,8900,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,1200,3600,25900,40300,11,2601,1,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - In Combat - Cast Fire Shield III"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Geomancer Flintdagger - At 15% HP - Flee For Assist");

-- Thundering Exile SAI
SET @ENTRY := 2762;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thundering Exile - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3300,6600,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thundering Exile - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,3,0,100,0,30,100,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - At 100% Mana - Allow Combat Movement"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Thundering Exile - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,1600,15100,18900,25400,11,11824,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thundering Exile - In Combat - Cast Shock");

-- Feeboz SAI
SET @ENTRY := 4063;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,34083,0,0,0,0,0,2,0,0,0,0,0,0,0,"Feeboz - On Aggro - Cast Fireball"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,4600,8400,11,34083,0,0,0,0,0,2,0,0,0,0,0,0,0,"Feeboz - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feeboz - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Feeboz - At 15% HP - Flee For Assist");

-- Texts for Feeboz
DELETE FROM `creature_text` WHERE `entry`= 4063;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(4063,0,0, "No!  Leave us!  We must not fail our task!",12,0,100,0,0,0, "Feeboz"),
(4063,0,1, "Die!  You will not free Myzrael!",12,0,100,0,0,0, "Feeboz"),
(4063,0,2, "The Great One will smash you!",12,0,100,0,0,0, "Feeboz");

-- Dustbelcher Wyrmhunter SAI
SET @ENTRY := 2716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9483,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - On Aggro - Cast Boulder"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,5,30,2300,5900,11,9483,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - At 5 - 30 Range - Cast Boulder"),
(@ENTRY,0,5,0,9,0,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,6,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,0,0,100,0,18600,24700,21100,30400,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Wyrmhunter - In Combat - Cast Net");

-- Texts for Dustbelcher Wyrmhunter
DELETE FROM `creature_text` WHERE `entry`= 2716;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2716,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Dustbelcher Wyrmhunter"),
(2716,0,1, "Me smash! You die!",12,0,100,0,0,0, "Dustbelcher Wyrmhunter"),
(2716,0,2, "I'll crush you!",12,0,100,0,0,0, "Dustbelcher Wyrmhunter");

-- Dustbelcher Shaman SAI
SET @ENTRY := 2718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Shaman - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3600,5200,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Shaman - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Shaman - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,14,0,50,0,0,40,18300,24100,11,8005,1,0,0,0,0,7,0,0,0,0,0,0,0,"Dustbelcher Shaman - On Friendly Unit At 0 - 40% Health - Cast Healing Wave");

-- Texts for Dustbelcher Shaman
DELETE FROM `creature_text` WHERE `entry`= 2718;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2718,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Dustbelcher Shaman"),
(2718,0,1, "Me smash! You die!",12,0,100,0,0,0, "Dustbelcher Shaman"),
(2718,0,2, "I'll crush you!",12,0,100,0,0,0, "Dustbelcher Shaman");

-- Dustbelcher Ogre Mage SAI
SET @ENTRY := 2720;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,0,0,10,1,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - In Combat - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - On Aggro - Cast Frostbolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3600,5100,11,20822,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - At 0 - 40 Range - Cast Frostbolt"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,3700,7700,31500,43600,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Ogre Mage - In Combat - Cast Bloodlust");

-- Texts for Dustbelcher Ogre Mage
DELETE FROM `creature_text` WHERE `entry`= 2720;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2720,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Dustbelcher Ogre Mage"),
(2720,0,1, "Me smash! You die!",12,0,100,0,0,0, "Dustbelcher Ogre Mage"),
(2720,0,2, "I'll crush you!",12,0,100,0,0,0, "Dustbelcher Ogre Mage");

-- Scalding Whelp SAI
SET @ENTRY := 2725;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Whelp - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,34083,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Whelp - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Whelp - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3300,5000,11,34083,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Whelp - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Whelp - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Whelp - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Whelp - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Whelp - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Whelp - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scalding Whelp - At 100% Mana - Increment Phase");

-- Shadowforge Darkweaver SAI
SET @ENTRY := 2740;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Darkweaver - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3500,5300,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 7% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,14900,23100,14900,31200,11,9482,33,0,0,0,0,5,0,0,0,0,0,0,0,"Shadowforge Darkweaver - In Combat - Cast Amplify Flames"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Darkweaver - At 15% HP - Flee For Assist");

-- Shadowforge Chanter SAI
SET @ENTRY := 2742;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,8800,11900,16400,35800,11,6066,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Chanter - In Combat - Cast Power Word: Shield"),
(@ENTRY,0,1,0,14,0,100,0,0,40,18800,36600,11,6077,1,0,0,0,0,7,0,0,0,0,0,0,0,"Shadowforge Chanter - On Friendly Unit At 0 - 40% Health - Cast Renew"),
(@ENTRY,0,2,0,0,0,100,1,8000,10000,18000,24000,11,15970,1,0,0,0,0,6,0,0,0,0,0,0,0,"Shadowforge Chanter - In Combat - Cast Sleep"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Chanter - At 15% HP - Flee For Assist");

-- Enraged Rock Elemental SAI
SET @ENTRY := 2791;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,50,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Rock Elemental - At 50% HP - Cast Enrage"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Rock Elemental - At 50% HP - Say Line 0");

-- Texts for Enraged Rock Elemental
DELETE FROM `creature_text` WHERE `entry`= 2791;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2791,0,0, "%s goes into a frenzy!",16,0,100,0,0,0, "Enraged Rock Elemental");

-- Stonevault Seer SAI
SET @ENTRY := 2892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Seer - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3600,4800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Seer - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,14,0,80,1,0,40,0,0,11,11986,1,0,0,0,0,7,0,0,0,0,0,0,0,"Stonevault Seer - On Friendly Unit At 0 - 40% Health - Cast Healing Wave"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Seer - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonevault Seer - At 15% HP - Flee For Assist");

-- Dustbelcher Warrior SAI
SET @ENTRY := 2906;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Warrior - On Aggro - Say Line 0");

-- Texts for Dustbelcher Warrior
DELETE FROM `creature_text` WHERE `entry`= 2906;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2906,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Dustbelcher Warrior"),
(2906,0,1, "Me smash! You die!",12,0,100,0,0,0, "Dustbelcher Warrior"),
(2906,0,2, "I'll crush you!",12,0,100,0,0,0, "Dustbelcher Warrior");

-- Dustbelcher Mystic SAI
SET @ENTRY := 2907;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Mystic - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3700,7500,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Mystic - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dustbelcher Mystic - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,1,14800,30400,0,0,11,13281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dustbelcher Mystic - In Combat - Cast Earth Shock");

-- Servo SAI
SET @ENTRY := 2922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servo - Out Of Combat - Increment Phase"),
(@ENTRY,0,1,2,1,0,100,0,20000,40000,98000,132000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servo - Out Of Combat - Say Line 0"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servo - Out Of Combat - Increment Phase"),
(@ENTRY,0,3,4,1,0,100,0,49000,66000,98000,132000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servo - Out Of Combat - Say Line 1"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Servo - Out Of Combat - Increment Phase");

-- Texts for Servo
DELETE FROM `creature_text` WHERE `entry`= 2922;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2922,0,0, "One day I'll be a real boy.",12,0,100,0,0,0, "Servo"),
(2922,0,1, "Gizmos... check. Doothingies... check. Wizzers... check.",12,0,100,0,0,0, "Servo"),
(2922,0,2, "It can get really hot here in the Badlands. But at least it's a dry heat.",12,0,100,0,0,0, "Servo"),
(2922,1,0, "We can make it better, stronger, faster. We have the technology. We have the magic.",12,0,100,0,0,0, "Servo"),
(2922,1,1, "It is dangerous here, master. But I shall help stand guard.",12,0,100,0,0,0, "Servo"),
(2922,1,2, "Brzt... click... whir...",12,0,100,0,0,0, "Servo");

-- Zaricotl SAI
SET @ENTRY := 2931;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,5,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zaricotl - On Killed Unit - Say Line 0");

-- Texts for Zaricotl
DELETE FROM `creature_text` WHERE `entry`= 2931;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2931,0,0, "%s seems much calmer now that it has eaten the remains of $N.",16,0,100,0,0,0, "Zaricotl");

-- Shadowforge Surveyor SAI
SET @ENTRY := 4844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Surveyor - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,5000,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,10700,20100,20300,22600,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - In Combat - Cast Frost Nova"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowforge Surveyor - At 15% HP - Flee For Assist");

-- Stonevault Cave Hunter SAI
SET @ENTRY := 4856;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Cave Hunter - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2800,4700,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,0,5900,13200,20300,26700,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonevault Cave Hunter - In Combat - Cast Net"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stonevault Cave Hunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonevault Cave Hunter - On Evade - Display melee weapon");

-- 7:XT SAI
SET @ENTRY := 14224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,10000,60000,120000,240000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"7:XT - Out Of Combat - Say Line 0");

-- Texts for 7:XT
DELETE FROM `creature_text` WHERE `entry`= 14224;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(14224,0,0, "Unknown life forms detected....assessing...",12,0,100,0,0,0, "7:XT"),
(14224,0,1, "Target lost....resuming search patterns Delta",12,0,100,0,0,0, "7:XT"),
(14224,0,2, "Scanning life forms....target not found",12,0,100,0,0,0, "7:XT");

-- Dreadmaul Ogre Mage SAI
SET @ENTRY := 5975;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,0,0,30,34000,38000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - At 30% HP - Cast Bloodlust");

-- Dreadmaul Warlock SAI
SET @ENTRY := 5978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Warlock - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,5000,7000,15000,25000,11,8282,33,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - In Combat - Cast Curse of Blood");

-- Nethergarde Engineer SAI
SET @ENTRY := 5997;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Engineer - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Engineer - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,0,8000,11000,12000,16000,11,8858,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Engineer - In Combat - Cast Bomb"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Nethergarde Engineer - At 15% HP - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - On Evade - Display melee weapon");

-- Nethergarde Riftwatcher SAI
SET @ENTRY := 6002;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,9000,14000,14000,18000,11,11975,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - In Combat - Cast Arcane Explosion"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - At 15% HP - Flee For Assist");

-- Shadowsworn Cultist SAI
SET @ENTRY := 6004;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Cultist - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 15% HP - Increment Phase"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowsworn Cultist - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - On Evade - Display melee weapon");

-- Shadowsworn Warlock SAI
SET @ENTRY := 6008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,1,1000,1000,0,0,11,5108,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - Out Of Combat - Cast Voidwalker"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Warlock - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,1,5000,8000,30000,45000,11,11980,33,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Warlock - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowsworn Warlock - At 15% HP - Flee For Assist");

-- Shadowsworn Dreadweaver SAI
SET @ENTRY := 6009;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,8000,11000,19000,24000,11,8994,1,0,0,0,0,6,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - In Combat - Cast Banish"),
(@ENTRY,0,12,0,0,0,100,0,12000,16000,30000,45000,11,7098,33,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - In Combat - Cast Curse of Mending");

-- Razelikh the Defiler SAI
SET @ENTRY := 7664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,16000,22000,11,8255,0,0,0,0,0,2,0,0,0,0,0,0,0,"Razelikh the Defiler - In Combat - Cast Strong Cleave"),
(@ENTRY,0,1,0,0,0,100,0,11000,15000,12000,17000,11,12745,1,0,0,0,0,5,0,0,0,0,0,0,0,"Razelikh the Defiler - In Combat - Cast Mana Burn"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,13000,24000,11,13459,33,0,0,0,0,2,0,0,0,0,0,0,0,"Razelikh the Defiler - In Combat - Cast Decimate"),
(@ENTRY,0,3,4,2,0,100,0,0,75,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - At 75% HP - Say Line 0"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,10864,1,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - At 75% HP - Cast Razelikh's Tear I"),
(@ENTRY,0,5,6,2,0,100,0,0,50,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - At 50% HP - Say Line 1"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,11,10854,1,0,0,0,0,2,0,0,0,0,0,0,0,"Razelikh the Defiler - At 50% HP - Cast Flames of Chaos"),
(@ENTRY,0,7,8,2,0,100,0,0,25,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - At 25% HP - Say Line 2"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,11,10866,1,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - At 25% HP - Cast Razelikh's Tear II"),
(@ENTRY,0,9,0,2,0,100,1,0,15,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - At 15% HP - Cast Frenzy"),
(@ENTRY,0,10,0,6,0,100,1,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razelikh the Defiler - On Death - Say Line 3");

-- Texts for Razelikh the Defiler
DELETE FROM `creature_text` WHERE `entry`= 7664;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(7664,0,0, "Ilifar, your master calls!",14,0,100,0,0,0, "Razelikh the Defiler"),
(7664,1,0, "Let the flames of chaos engulf you!",14,0,100,0,0,0, "Razelikh the Defiler"),
(7664,2,0, "Face my champion, mortals!",14,0,100,0,0,0, "Razelikh the Defiler"),
(7664,3,0, "Prepare yourselves for an eternity of anguish and torture - vengeance shall be mine...",14,0,100,0,0,0, "Razelikh the Defiler");

-- Archmage Allistarj SAI
SET @ENTRY := 7666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Allistarj - On Aggro - Cast Fireball"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,3400,4800,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Allistarj - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,6,0,0,0,100,0,9000,12000,11000,14000,11,12737,1,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat - Cast Frostbolt"),
(@ENTRY,0,7,0,0,0,100,0,13000,16000,13000,16000,11,14145,1,0,0,0,0,5,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat - Cast Fire Blast"),
(@ENTRY,0,8,0,0,0,100,0,5000,7000,16000,20000,11,12738,1,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat - Cast Amplify Damage"),
(@ENTRY,0,9,0,0,0,100,0,7000,12000,20000,24000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Archmage Allistarj - In Combat - Cast Polymorph"),
(@ENTRY,0,10,11,3,0,100,0,0,8,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - At 8% Mana - Allow Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - At 8% Mana - Increment Phase"),
(@ENTRY,0,12,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,13,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,14,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,15,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Allistarj - At 100% Mana - Increment Phase");

-- Lady Sevine SAI
SET @ENTRY := 7667;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sevine - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,3400,4800,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sevine - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,6,7,3,0,100,0,0,8,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - At 8% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - At 8% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,0,0,100,0,9000,12000,24000,27000,11,12742,1,0,0,0,0,5,0,0,0,0,0,0,0,"Lady Sevine - In Combat - Cast Immolate"),
(@ENTRY,0,13,0,0,0,100,0,2000,5000,30000,45000,11,12741,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - In Combat - Cast Curse of Weakness"),
(@ENTRY,0,14,0,0,0,100,0,7000,9000,15000,25000,11,12740,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sevine - In Combat - Cast Summon Infernal Servant");

-- Mojo the Twisted SAI
SET @ENTRY := 8296;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mojo the Twisted - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mojo the Twisted - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mojo the Twisted - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,30,9000,14000,11,17228,1,0,0,0,0,5,0,0,0,0,0,0,0,"Mojo the Twisted - At 0 - 30 Range - Cast Shadow Bolt Volley");

-- Magronos the Unyielding SAI
SET @ENTRY := 8297;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,8000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magronos the Unyielding - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,0,1000,3000,12000,14000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Magronos the Unyielding - In Combat - Cast Hamstring"),
(@ENTRY,0,2,3,2,0,100,0,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magronos the Unyielding - At 30% HP - Cast Enrage"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magronos the Unyielding - At 30% HP - Say Line 0");

-- Texts for Magronos the Unyielding
DELETE FROM `creature_text` WHERE `entry`= 8297;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(8297,0,0, "%s goes into a frenzy!",16,0,100,0,0,0, "Magronos the Unyielding");

-- Akubar the Seer SAI
SET @ENTRY := 8298;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akubar the Seer - On Aggro - Cast Lightning Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20824,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akubar the Seer - At 0 - 40 Range - Cast Lightning Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Akubar the Seer - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,9,0,100,0,0,30,13800,13800,11,20831,1,0,0,0,0,5,0,0,0,0,0,0,0,"Akubar the Seer - At 0 - 30 Range - Cast Chain Lightning"),
(@ENTRY,0,12,0,0,0,100,0,3000,5000,25700,31300,11,11436,1,0,0,0,0,5,0,0,0,0,0,0,0,"Akubar the Seer - In Combat - Cast Slow");

-- Blackrock Sorcerer SAI
SET @ENTRY := 7026;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sorcerer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Sorcerer - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sorcerer - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3400,4500,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Sorcerer - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sorcerer - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sorcerer - At 7% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sorcerer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sorcerer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sorcerer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Sorcerer - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,8500,19300,14700,19400,11,20827,1,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Sorcerer - In Combat - Cast Flamestrike");

-- Blackrock Warlock SAI
SET @ENTRY := 7028;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Warlock - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Warlock - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Warlock - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3300,5200,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Warlock - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Warlock - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Warlock - At 7% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Warlock - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Warlock - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Warlock - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blackrock Warlock - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,2600,7300,29100,31300,11,13338,33,0,0,0,0,5,0,0,0,0,0,0,0,"Blackrock Warlock - In Combat - Cast Curse of Tongues"),
(@ENTRY,0,11,0,0,0,100,0,6200,8700,5100,11000,11,20826,33,0,0,0,0,2,0,0,0,0,0,0,0,"Blackrock Warlock - In Combat - Cast Immolate");

-- Thaurissan Agent SAI
SET @ENTRY := 7038;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Agent - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2200,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Agent - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,5,30,36300,50000,11,6685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Agent - At 5 - 30 Range - Cast Piercing Shot"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,15,0,9,0,100,0,0,5,13300,24100,11,12540,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thaurissan Agent - At 0 - 5 Range - Cast Gouge"),
(@ENTRY,0,16,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - On Evade - Display melee weapon"),
(@ENTRY,0,17,19,6,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thaurissan Agent - On Death - Display melee weapon");

-- Thauris Balgarr SAI
SET @ENTRY := 8978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thauris Balgarr - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,21700,35200,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thauris Balgarr - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,0,7000,11000,21700,35200,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thauris Balgarr - In Combat - Cast Net"),
(@ENTRY,0,14,0,0,0,100,0,1000,3000,19200,32700,11,11802,1,0,0,0,0,2,0,0,0,0,0,0,0,"Thauris Balgarr - In Combat - Cast Dark Iron Land Mine"),
(@ENTRY,0,15,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thauris Balgarr - On Evade - Display melee weapon");

-- Lord Ello Ebonlocke SAI
SET @ENTRY := 263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,20000,30000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Ello Ebonlocke - Out Of Combat - Say Line 0");

-- Role Dreuger SAI
SET @ENTRY := 269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,80000,90000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Role Dreuger - Out Of Combat - Say Line 0");

-- Councilman Millstipe SAI
SET @ENTRY := 270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,40000,50000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Councilman Millstipe - Out Of Combat - Say Line 0");

-- Ambassador Berrybuck SAI
SET @ENTRY := 271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,70000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ambassador Berrybuck - Out Of Combat - Say Line 0");

-- Texts for Lord Ello Ebonlocke
DELETE FROM `creature_text` WHERE `entry`= 263;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(263,0,0, "Undead are crawling all over the land.  Where is the Stormwind Army?",12,0,100,0,0,0, "Lord Ello Ebonlocke");

-- Texts for Role Dreuger
DELETE FROM `creature_text` WHERE `entry`= 269;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(269,0,0, "The Council of Duskwood must take action.  Evil lingers in the air.",12,0,100,0,0,0, "Role Dreuger"),
(269,0,1, "The people of Darkshire expect more from the Council.  We cannot let them suffer from this unholy wrath which plagues us.",12,0,100,0,0,0, "Role Dreuger"),
(269,0,2, "Constant bickering will get us nowhere.  We need to take action.",12,0,100,0,0,0, "Role Dreuger");

-- Texts for Councilman Millstipe
DELETE FROM `creature_text` WHERE `entry`= 270;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(270,0,0, "We need better representation from Stormwind. Our homes are falling to the undead.",12,0,100,0,0,0, "Councilman Millstipe");

-- Texts for Ambassador Berrybuck
DELETE FROM `creature_text` WHERE `entry`= 271;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(271,0,0, "Our cause falls on deaf ears beyond the thick, stone walls of Stormwind.",12,0,100,0,0,0, "Ambassador Berrybuck"),
(271,0,1, "The news from Stormwind does not bode well. . . .",12,0,100,0,0,0, "Ambassador Berrybuck");

-- Stalvan Mistmantle SAI
SET @ENTRY := 315;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stalvan Mistmantle - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,7800,9000,8000,16000,11,3105,32,0,0,0,0,2,0,0,0,0,0,0,0,"Stalvan Mistmantle - In Combat - Cast Curse of Stalvan"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Stalvan Mistmantle - At 15% HP - Flee For Assist");

-- Hogan Ference SAI
SET @ENTRY := 325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,0,10000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hogan Ference - Out Of Combat - Say Line 0");

-- Texts for Stalvan Mistmantle
DELETE FROM `creature_text` WHERE `entry`= 315;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(315,0,0, "I shall spill your blood, $C!",12,0,100,0,0,0, "Stalvan Mistmantle"),
(315,0,1, "Who dares disturb me?  Die $N!",12,0,100,0,0,0, "Stalvan Mistmantle");

-- Texts for Hogan Ference
DELETE FROM `creature_text` WHERE `entry`= 325;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(325,0,0, "I fear something dark is coming.",12,0,100,0,0,0, "Hogan Ference"),
(325,0,1, "The light appears to have forsaken us.",12,0,100,0,0,0, "Hogan Ference"),
(325,0,2, "Why haven't the Stormwind guards come?",12,0,100,0,0,0, "Hogan Ference");

-- Nightbane Shadow Weaver SAI
SET @ENTRY := 533;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,2800,3800,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,21700,114300,76500,91800,11,992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Shadow Weaver - In Combat - Cast Shadow Word: Pain");

-- Skeletal Healer SAI
SET @ENTRY := 787;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Healer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Healer - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Healer - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3500,3700,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Healer - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Healer - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Healer - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Healer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Healer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Healer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Skeletal Healer - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,14,0,100,1,0,40,0,0,11,2054,1,0,0,0,0,7,0,0,0,0,0,0,0,"Skeletal Healer - On Friendly Unit At 0 - 40% Health - Cast Heal");

-- Splinter Fist Ogre SAI
SET @ENTRY := 889;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Ogre - On Aggro - Say Line 0");

-- Texts for Splinter Fist Warrior
DELETE FROM `creature_text` WHERE `entry`= 212;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(212,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Splinter Fist Warrior"),
(212,0,1, "Me smash! You die!",12,0,100,0,0,0, "Splinter Fist Warrior"),
(212,0,2, "I'll crush you!",12,0,100,0,0,0, "Splinter Fist Warrior");

-- Texts for Splinter Fist Ogre
DELETE FROM `creature_text` WHERE `entry`= 889;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(889,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Splinter Fist Ogre"),
(889,0,1, "Me smash! You die!",12,0,100,0,0,0, "Splinter Fist Ogre"),
(889,0,2, "I'll crush you!",12,0,100,0,0,0, "Splinter Fist Ogre");

-- Splinter Fist Fire Weaver SAI
SET @ENTRY := 891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,19816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3300,7400,11,19816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,1600,4700,18400,19100,11,20296,1,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Fire Weaver - In Combat - Cast Flamestrike");

-- Texts for Splinter Fist Fire Weaver
DELETE FROM `creature_text` WHERE `entry`= 891;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(891,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Splinter Fist Fire Weaver"),
(891,0,1, "Me smash! You die!",12,0,100,0,0,0, "Splinter Fist Fire Weaver"),
(891,0,2, "I'll crush you!",12,0,100,0,0,0, "Splinter Fist Fire Weaver");

-- Splinter Fist Taskmaster SAI
SET @ENTRY := 892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Taskmaster - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,800,3100,1500,5000,11,3631,32,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Taskmaster - In Combat - Cast Battle Fury");

-- Texts for Splinter Fist Taskmaster
DELETE FROM `creature_text` WHERE `entry`= 892;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(892,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Splinter Fist Taskmaster"),
(892,0,1, "Me smash! You die!",12,0,100,0,0,0, "Splinter Fist Taskmaster"),
(892,0,2, "I'll crush you!",12,0,100,0,0,0, "Splinter Fist Taskmaster");

-- Defias Night Blade SAI
SET @ENTRY := 909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,18500,2000,18500,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Night Blade - In Combat - Cast Poison"),
(@ENTRY,0,1,0,0,0,100,0,3200,15100,11700,44100,11,7992,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Night Blade - In Combat - Cast Slowing Poison"),
(@ENTRY,0,2,0,0,0,70,0,3900,12700,3900,12700,11,2589,0,0,0,0,0,5,0,0,0,0,0,0,0,"Defias Night Blade - In Combat - Cast Backstab"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Night Blade - At 15% HP - Flee For Assist");

-- Defias Enchanter SAI
SET @ENTRY := 910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Enchanter - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3900,7600,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Enchanter - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - At 15% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,5000,14100,18000,36500,11,3443,1,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - In Combat - Cast Enchanted Quickness"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defias Enchanter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Defias Enchanter - At 15% HP - Flee For Assist");

-- Nightbane Tainted One SAI
SET @ENTRY := 920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,13500,19800,24100,38300,11,3424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nightbane Tainted One - In Combat - Cast Tainted Howl"),
(@ENTRY,0,1,0,0,0,100,0,19000,27300,2300,5700,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Nightbane Tainted One - In Combat - Cast Poison");

-- Black Widow Hatchling SAI
SET @ENTRY := 930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3200,13400,8300,14100,11,7367,32,0,0,0,0,2,0,0,0,0,0,0,0,"Black Widow Hatchling - In Combat - Cast Infected Bite"),
(@ENTRY,0,1,0,0,0,100,0,9800,19900,6500,26000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Black Widow Hatchling - In Combat - Cast Poison");

-- Rotted One SAI
SET @ENTRY := 948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rotted One - Out Of Combat - Cast Birth"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,3428,3,0,0,0,0,1,0,0,0,0,0,0,0,"Rotted One - On Death - Cast Summon Flesh Eating Worms");

-- Carrion Recluse SAI
SET @ENTRY := 949;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9800,26600,13000,48400,11,3609,32,0,0,0,0,2,0,0,0,0,0,0,0,"Carrion Recluse - In Combat - Cast Paralyzing Poison");

-- Skeletal Raider SAI
SET @ENTRY := 1110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,4700,19100,34700,11,7992,32,0,0,0,0,2,0,0,0,0,0,0,0,"Skeletal Raider - In Combat - Cast Slowing Poison");

-- Splinter Fist Firemonger SAI
SET @ENTRY := 1251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Firemonger - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,1300,5300,61600,71200,11,184,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Firemonger - In Combat - Cast Fire Shield II");

-- Texts for Splinter Fist Firemonger
DELETE FROM `creature_text` WHERE `entry`= 1251;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(1251,0,0, "Raaar!!! Me smash $R!",12,0,100,0,0,0, "Splinter Fist Firemonger"),
(1251,0,1, "Me smash! You die!",12,0,100,0,0,0, "Splinter Fist Firemonger"),
(1251,0,2, "I'll crush you!",12,0,100,0,0,0, "Splinter Fist Firemonger");

-- Black Ravager Mastiff SAI
SET @ENTRY := 1258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6300,8900,30200,47300,11,3149,1,0,0,0,0,1,0,0,0,0,0,0,0,"Black Ravager Mastiff - In Combat - Cast Furious Howl"),
(@ENTRY,0,1,0,0,0,100,0,9000,12800,15900,25400,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Ravager Mastiff - In Combat - Cast Rend");

-- Fetid Corpse SAI
SET @ENTRY := 1270;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fetid Corpse - Out Of Combat - Cast Birth"),
(@ENTRY,0,1,0,0,0,100,0,2200,18500,120200,125700,11,7102,0,0,0,0,0,5,0,0,0,0,0,0,0,"Fetid Corpse - In Combat - Cast Contagion of Rot");

-- Splinter Fist Enslaver SAI
SET @ENTRY := 1487;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Enslaver - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,3400,5100,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,0,0,100,0,0,3200,21100,42100,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Splinter Fist Enslaver - In Combat - Cast Net"),
(@ENTRY,0,14,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splinter Fist Enslaver - On Evade - Display melee weapon");

-- Sloth SAI
SET @ENTRY := 2475;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,1200,4000,10000,11,3510,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sloth - In Combat - Cast Sloth Effect");

-- Sludge SAI
SET @ENTRY := 2479;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,3100,3700,9900,11,3514,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sludge - In Combat - Cast Sludge");

-- Gutspill SAI
SET @ENTRY := 6170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,17000,20400,21700,37500,11,3424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gutspill - In Combat - Cast Tainted Howl"),
(@ENTRY,0,1,0,0,0,100,0,9800,19900,6500,26000,11,744,32,0,0,0,0,2,0,0,0,0,0,0,0,"Gutspill - In Combat - Cast Poison");

-- Blighted Surge SAI
SET @ENTRY := 8519;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Surge - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,16554,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blighted Surge - On Aggro - Cast Toxic Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Surge - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,2800,3800,11,16554,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blighted Surge - At 0 - 40 Range - Cast Toxic Bolt"),
(@ENTRY,0,4,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Surge - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,5,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Surge - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,6,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Surge - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,8,0,100,0,21332,0,0,0,36,13279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Surge - On Spellhit Aspect of Neptulon - Update Template");

-- Plague Ravager SAI
SET @ENTRY := 8520;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,21332,0,0,0,36,13279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Ravager - On Spellhit Aspect of Neptulon - Update Template");

-- Blighted Horror SAI
SET @ENTRY := 8521;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,15000,25000,11,16555,33,0,0,0,0,5,0,0,0,0,0,0,0,"Blighted Horror - In Combat - Cast Drowning Death"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,23000,35000,11,12542,0,0,0,0,0,5,0,0,0,0,0,0,0,"Blighted Horror - In Combat - Cast Fear"),
(@ENTRY,0,2,0,8,0,100,0,21332,0,0,0,36,13279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blighted Horror - On Spellhit Aspect of Neptulon - Update Template");

-- Plague Monstrosity SAI
SET @ENTRY := 8522;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,8000,13000,11,14099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plague Monstrosity - In Combat - Cast Mighty Blow"),
(@ENTRY,0,1,0,8,0,100,0,21332,0,0,0,36,13279,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague Monstrosity - On Spellhit Aspect of Neptulon - Update Template");

-- Scourge Soldier SAI
SET @ENTRY := 8523;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,5000,9000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Soldier - In Combat - Cast Strike");

-- Cursed Mage SAI
SET @ENTRY := 8524;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Mage - On Aggro - Cast Arcane Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Mage - At 0 - 40 Range - Cast Arcane Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Mage - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,6,0,100,1,0,0,0,0,11,16567,7,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Mage - On Death - Cast Tainted Mind");

-- Scourge Warder SAI
SET @ENTRY := 8525;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,8000,11000,11,12169,32,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Warder - In Combat - Cast Shield Block"),
(@ENTRY,0,1,0,0,0,100,0,11000,17000,45000,60000,11,12040,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Warder - In Combat - Cast Shadow Shield");

-- Dark Caster SAI
SET @ENTRY := 8526;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Caster - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Caster - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Caster - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,11000,14000,22000,25000,11,20825,32,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Caster - In Combat - Cast Shadow Bolt");

-- Scourge Guard SAI
SET @ENTRY := 8527;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,8000,11000,11,8242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Guard - In Combat - Cast Shield Slam"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,13000,17000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Guard - In Combat - Cast Disarm");

-- Dread Weaver SAI
SET @ENTRY := 8528;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,9000,12000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dread Weaver - In Combat - Cast Mind Flay"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,12000,15000,11,12542,1,0,0,0,0,6,0,0,0,0,0,0,0,"Dread Weaver - In Combat - Cast Fear");

-- Scourge Champion SAI
SET @ENTRY := 8529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,9000,13000,11,13737,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Champion - In Combat - Cast Mortal Strike");

-- Putrid Gargoyle SAI
SET @ENTRY := 8534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,45000,50000,11,16573,0,0,0,0,0,1,0,0,0,0,0,0,0,"Putrid Gargoyle - In Combat - Cast Putrid Bile");

-- Putrid Shrieker SAI
SET @ENTRY := 8535;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,16000,24000,11,8281,0,0,0,0,0,1,0,0,0,0,0,0,0,"Putrid Shrieker - In Combat - Cast Sonic Burst");

-- Torn Screamer SAI
SET @ENTRY := 8540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,12000,15000,11,5884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Torn Screamer - In Combat - Cast Banshee Curse");

-- Hate Shrieker SAI
SET @ENTRY := 8541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,12000,15000,11,5884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hate Shrieker - In Combat - Cast Banshee Curse"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,12000,15000,11,3589,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hate Shrieker - In Combat - Cast Deafening Screech");

-- Death Singer SAI
SET @ENTRY := 8542;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,12000,15000,11,5884,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Singer - In Combat - Cast Banshee Curse"),
(@ENTRY,0,1,0,0,0,100,0,12000,16000,20000,25000,11,6605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Death Singer - In Combat - Cast Terrifying Screech");

-- Stitched Horror SAI
SET @ENTRY := 8543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,9000,15000,11,14099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stitched Horror - In Combat - Cast Mighty Blow");

-- Gangled Golem SAI
SET @ENTRY := 8544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,9000,13000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gangled Golem - In Combat - Cast Knockdown");

-- Stitched Golem SAI
SET @ENTRY := 8545;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,16577,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stitched Golem - On Respawn - Cast Disease Cloud");

-- Dark Adept SAI
SET @ENTRY := 8546;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,9000,14000,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Adept - In Combat - Cast Snap Kick");

-- Death Cultist SAI
SET @ENTRY := 8547;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,5000,7000,11,16583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Death Cultist - In Combat - Cast Shadow Shock");

-- Vile Tutor SAI
SET @ENTRY := 8548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,11000,17000,45000,60000,11,12040,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vile Tutor - In Combat - Cast Shadow Shield");

-- Shadowmage SAI
SET @ENTRY := 8550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,0,0,11,16592,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - Out Of Combat - Cast Shadowform"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmage - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,3400,4800,11,20825,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowmage - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,6,7,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - At 7% Mana - Increment Phase"),
(@ENTRY,0,8,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowmage - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Shadowmage - At 15% HP - Flee For Assist");

-- Dark Summoner SAI
SET @ENTRY := 8551;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Summoner - On Aggro - Cast Arcane Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Summoner - At 0 - 40 Range - Cast Arcane Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,4000,6000,15000,20000,11,16590,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - In Combat - Cast Summon Zombie"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Summoner - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Summoner - At 15% HP - Flee For Assist");

-- Necromancer SAI
SET @ENTRY := 8553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,16592,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necromancer - Out Of Combat - Cast Shadowform"),
(@ENTRY,0,1,0,1,0,100,1,3000,3000,0,0,11,12420,0,0,0,0,0,1,0,0,0,0,0,0,0,"Necromancer - Out Of Combat - Cast Summon Skeletal Servant"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,20000,24000,11,11443,1,0,0,0,0,5,0,0,0,0,0,0,0,"Necromancer - In Combat - Cast Cripple");

-- Crypt Stalker SAI
SET @ENTRY := 8555;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,10000,15000,11,31600,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Stalker - In Combat - Cast Crypt Scarabs");

-- Crypt Walker SAI
SET @ENTRY := 8556;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,10000,15000,11,745,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crypt Walker - In Combat - Cast Web");

-- Crypt Horror SAI
SET @ENTRY := 8557;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,20000,30000,11,17169,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crypt Horror - In Combat - Cast Summon Carrion Scarab");

-- Crypt Slayer SAI
SET @ENTRY := 8558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,11,17170,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crypt Slayer - At 15% HP - Cast Fatal Sting");

-- Mossflayer Scout SAI
SET @ENTRY := 8560;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,18000,22000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mossflayer Scout - In Combat - Cast Hamstring"),
(@ENTRY,0,1,0,0,0,100,1,4000,4000,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mossflayer Scout - In Combat - Flee For Assist");

-- Mossflayer Shadowhunter SAI
SET @ENTRY := 8561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,5,30,6000,9000,11,17171,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 5 - 30 Range - Cast Shadow Shot"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,8,9,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,10,11,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,11,12,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,13,14,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,15,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 15% HP - Increment Phase"),
(@ENTRY,0,16,17,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - At 15% HP - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossflayer Shadowhunter - On Evade - Display melee weapon");

-- Mossflayer Cannibal SAI
SET @ENTRY := 8562;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,22000,25000,11,17172,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mossflayer Cannibal - In Combat - Cast Hex"),
(@ENTRY,0,1,0,0,0,100,0,7000,10000,22000,25000,11,17173,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mossflayer Cannibal - In Combat - Cast Drain Life");

-- Woodsman SAI
SET @ENTRY := 8563;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,12000,7000,14000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Woodsman - In Combat - Cast Sunder Armor");

-- Ranger SAI
SET @ENTRY := 8564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,5,30,7000,9000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger - At 5 - 30 Range - Cast Multi-Shot"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,8,9,9,0,100,0,5,30,9000,11000,11,17174,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger - At 5 - 30 Range - Cast Concussive Shot"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,10,11,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,14,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,15,16,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,17,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 15% HP - Increment Phase"),
(@ENTRY,0,18,19,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ranger - At 15% HP - Flee For Assist"),
(@ENTRY,0,20,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger - On Evade - Display melee weapon");

-- Pathstrider SAI
SET @ENTRY := 8565;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,9000,14000,11,16498,32,0,0,0,0,5,0,0,0,0,0,0,0,"Pathstrider - In Combat - Cast Faerie Fire");

-- Plaguehound SAI
SET @ENTRY := 8597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,9000,14000,11,3427,32,0,0,0,0,2,0,0,0,0,0,0,0,"Plaguehound - In Combat - Cast Infected Wound");

-- Frenzied Plaguehound SAI
SET @ENTRY := 8598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzied Plaguehound - At 30% HP - Cast Enrage"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzied Plaguehound - At 30% HP - Say Line 0");

-- Texts for Frenzied Plaguehound
DELETE FROM `creature_text` WHERE `entry`= 8598;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(8598,0,0, "%s goes into a frenzy!",16,0,100,0,0,0, "Frenzied Plaguehound");

-- Plaguebat SAI
SET @ENTRY := 8600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,10000,14000,16000,11,6605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plaguebat - In Combat - Cast Terrifying Screech");

-- Noxious Plaguebat SAI
SET @ENTRY := 8601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,9000,12000,11,7992,32,0,0,0,0,2,0,0,0,0,0,0,0,"Noxious Plaguebat - In Combat - Cast Slowing Poison");

-- Monstrous Plaguebat SAI
SET @ENTRY := 8602;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,16000,19000,11,64140,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monstrous Plaguebat - In Combat - Cast Sonic Burst");

-- Carrion Grub SAI
SET @ENTRY := 8603;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,8000,12000,11,16449,32,0,0,0,0,5,0,0,0,0,0,0,0,"Carrion Grub - In Combat - Cast Maggot Slime");

-- Carrion Devourer SAI
SET @ENTRY := 8605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,8000,12000,11,16449,32,0,0,0,0,5,0,0,0,0,0,0,0,"Carrion Devourer - In Combat - Cast Maggot Slime"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,17197,7,0,0,0,0,1,0,0,0,0,0,0,0,"Carrion Devourer - On Death - Cast Maggot Goo");

-- Rotting Sludge SAI
SET @ENTRY := 8607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,8000,12000,11,7279,32,0,0,0,0,5,0,0,0,0,0,0,0,"Rotting Sludge - In Combat - Cast Black Sludge");

-- Scarlet Warder SAI
SET @ENTRY := 9447;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,7000,11000,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Warder - In Combat - Cast Crusader Strike"),
(@ENTRY,0,1,0,2,0,100,0,0,50,15000,22000,11,15493,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Warder - At 50% HP - Cast Holy Light");

-- Scarlet Praetorian SAI
SET @ENTRY := 9448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,13000,18000,11,17143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Praetorian - In Combat - Cast Holy Strike"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,9000,11000,11,17149,0,0,0,0,0,5,0,0,0,0,0,0,0,"Scarlet Praetorian - In Combat - Cast Exorcism");

-- Scarlet Cleric SAI
SET @ENTRY := 9449;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Cleric - On Aggro - Cast Mind Blast"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,30,3400,4800,11,15587,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Cleric - At 0 - 30 Range - Cast Mind Blast"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,14,0,100,0,0,40,25000,35000,11,15587,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Cleric - On Friendly Unit At 0 - 40% Health - Cast Mind Blast"),
(@ENTRY,0,11,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - At 100% Mana - Increment Phase"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Cleric - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Cleric - At 15% HP - Flee For Assist");

-- Scarlet Curate SAI
SET @ENTRY := 9450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Curate - On Aggro - Cast Holy Smite"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,25054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Curate - At 0 - 40 Range - Cast Holy Smite"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,15,0,100,1,0,30,0,0,11,17201,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Curate - On Friendly Unit In CC - Cast Dispel Magic"),
(@ENTRY,0,12,0,14,0,100,0,0,40,25000,35000,11,17201,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Curate - On Friendly Unit At 0 - 40% Health - Cast Dispel Magic"),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - At 15% HP - Set Phase 3"),
(@ENTRY,0,14,15,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Curate - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,15,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Curate - At 15% HP - Flee For Assist");

-- Scarlet Archmage SAI
SET @ENTRY := 9451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,0,1,0,100,0,1000,1000,1800000,1800000,11,18100,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - Out Of Combat - Cast Frost Armor"),
(@ENTRY,0,3,4,4,0,100,0,0,0,0,0,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Archmage - On Aggro - Cast Fireball"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - On Aggro - Increment Phase"),
(@ENTRY,0,5,0,9,0,100,0,0,40,3400,4800,11,15242,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Archmage - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,6,0,0,0,100,0,8000,11000,16000,21000,11,15244,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - In Combat - Cast Cone of Cold"),
(@ENTRY,0,7,8,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - At 7% Mana - Increment Phase"),
(@ENTRY,0,9,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - At 100% Mana - Increment Phase"),
(@ENTRY,0,13,0,13,0,100,1,0,0,0,0,11,15122,1,0,0,0,0,7,0,0,0,0,0,0,0,"Scarlet Archmage - On Target Casting - Cast Counterspell"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - At 15% HP - Set Phase 3"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Archmage - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scarlet Archmage - At 15% HP - Flee For Assist");

-- Scarlet Enchanter SAI
SET @ENTRY := 9452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,25055,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Enchanter - On Aggro - Cast Arcane Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,25055,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Enchanter - At 0 - 40 Range - Cast Arcane Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Enchanter - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,7000,10000,18000,22000,11,15970,1,0,0,0,0,6,0,0,0,0,0,0,0,"Scarlet Enchanter - In Combat - Cast Sleep");

-- Duggan Wildhammer SAI
SET @ENTRY := 10817;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duggan Wildhammer - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duggan Wildhammer - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,9,0,100,0,0,5,6000,9000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Duggan Wildhammer - At 0 - 5 Range - Cast Cleave"),
(@ENTRY,0,14,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 15% HP - Increment Phase"),
(@ENTRY,0,15,16,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Duggan Wildhammer - At 15% HP - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - On Evade - Display melee weapon");

-- Hed'mush the Rotting SAI
SET @ENTRY := 10821;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,13000,18000,11,14099,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hed'mush the Rotting - In Combat - Cast Mighty Blow");

-- Warlord Thresh'jin SAI
SET @ENTRY := 10822;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,14000,17000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Thresh'jin - At 0 - 5 Range - Cast Hamstring"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,10000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Thresh'jin - At 0 - 5 Range - Cast Sunder Armor"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,8000,10000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Thresh'jin - In Combat - Cast Whirlwind");

-- Zul'Brin Warpbranch SAI
SET @ENTRY := 10823;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,8000,11000,11,20831,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zul'Brin Warpbranch - At 0 - 30 Range - Cast Chain Lightning"),
(@ENTRY,0,1,0,9,0,100,0,0,20,12000,15000,11,15039,0,0,0,0,0,5,0,0,0,0,0,0,0,"Zul'Brin Warpbranch - At 0 - 20 Range - Cast Flame Shock"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,11000,14000,11,17172,1,0,0,0,0,6,0,0,0,0,0,0,0,"Zul'Brin Warpbranch - In Combat - Cast Hex"),
(@ENTRY,0,3,0,14,0,100,0,0,40,10000,15000,11,12491,1,0,0,0,0,7,0,0,0,0,0,0,0,"Zul'Brin Warpbranch - On Friendly Unit At 0 - 40% Health - Cast Healing Wave");

-- Ranger Lord Hawkspear SAI
SET @ENTRY := 10824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,9,0,100,0,0,5,7000,9000,11,11978,1,0,0,0,0,7,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 0 - 5 Range - Cast Kick"),
(@ENTRY,0,14,0,9,0,100,0,0,5,4000,7000,11,11978,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 0 - 5 Range - Cast Kick"),
(@ENTRY,0,15,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 15% HP - Increment Phase"),
(@ENTRY,0,16,17,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - At 15% HP - Flee For Assist"),
(@ENTRY,0,18,0,0,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - On Evade - Display melee weapon");

-- Gish the Unmoving SAI
SET @ENTRY := 10825;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,16564,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gish the Unmoving - In Combat - Cast Gargoyle Strike"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,18000,21000,11,13445,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gish the Unmoving - In Combat - Cast Rend");

-- Lord Darkscythe SAI
SET @ENTRY := 10826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,6000,8000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Darkscythe - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,10000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Darkscythe - At 0 - 5 Range - Cast Sunder Armor");

-- Deathspeaker Selendre SAI
SET @ENTRY := 10827;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathspeaker Selendre - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathspeaker Selendre - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,3000,5000,11,12471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,4,5,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathspeaker Selendre - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathspeaker Selendre - At 7% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathspeaker Selendre - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathspeaker Selendre - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deathspeaker Selendre - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deathspeaker Selendre - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,0,0,100,0,3000,5000,15000,18000,11,12889,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - In Combat - Cast Curse of Tongues"),
(@ENTRY,0,11,0,2,0,100,0,0,30,12000,19000,11,17238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - At 30% HP - Cast Drain Life");

-- High General Abbendis SAI
SET @ENTRY := 10828;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,39,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"High General Abbendis - On Aggro - Call For Help"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High General Abbendis - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,15000,20000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"High General Abbendis - In Combat - Cast Battle Shout"),
(@ENTRY,0,3,0,0,0,100,0,10000,13000,20000,30000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"High General Abbendis - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,4,0,0,0,100,0,5000,7000,6000,9000,11,17143,1,0,0,0,0,2,0,0,0,0,0,0,0,"High General Abbendis - In Combat - Cast Holy Strike");

-- Texts for High General Abbendis
DELETE FROM `creature_text` WHERE `entry`= 10828;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(10828,0,0, "%s calls for help!",16,0,100,0,0,0, "High General Abbendis");

-- Captain Redpath SAI
SET @ENTRY := 10937;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,8000,10000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Redpath - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,14000,18000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Redpath - In Combat - Cast Backhand"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,15000,20000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Redpath - In Combat - Cast Battle Shout");

-- Redpath the Corrupted SAI
SET @ENTRY := 10938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redpath the Corrupted - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,14000,18000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redpath the Corrupted - In Combat - Cast Backhand"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,15000,20000,11,16244,0,0,0,0,0,1,0,0,0,0,0,0,0,"Redpath the Corrupted - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,3,0,0,0,100,0,5000,7000,9000,14000,11,12542,1,0,0,0,0,6,0,0,0,0,0,0,0,"Redpath the Corrupted - In Combat - Cast Fear");

-- Ghost of the Past SAI
SET @ENTRY := 10940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghost of the Past - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,12000,15000,11,15089,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ghost of the Past - In Combat - Cast Frost Shock");

-- Texts for Ghost of the Past
DELETE FROM `creature_text` WHERE `entry`= 10940;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(10940,0,0, "Leave this place!",12,0,100,0,0,0, "Ghost of the Past");

-- Davil Lightfire SAI
SET @ENTRY := 10944;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,17232,0,0,0,0,0,1,0,0,0,0,0,0,0,"Davil Lightfire - On Aggro - Cast Devotion Aura"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,8000,10000,11,17284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Davil Lightfire - In Combat - Cast Holy Strike"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,15000,20000,11,13005,0,0,0,0,0,5,0,0,0,0,0,0,0,"Davil Lightfire - In Combat - Cast Hammer of Justice");

-- Horgus the Ravager SAI
SET @ENTRY := 10946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,17467,1,0,0,0,0,1,0,0,0,0,0,0,0,"Horgus the Ravager - Out Of Combat - Cast Unholy Aura"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,6000,8000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horgus the Ravager - In Combat - Cast Thrash"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,9000,12000,11,15608,1,0,0,0,0,2,0,0,0,0,0,0,0,"Horgus the Ravager - In Combat - Cast Ravenous Claw");

-- Darrowshire Betrayer SAI
SET @ENTRY := 10947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,7000,10000,11,5337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darrowshire Betrayer - In Combat - Cast Wither Strike");

-- Darrowshire Defender SAI
SET @ENTRY := 10948;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,8000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darrowshire Defender - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,7000,10000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darrowshire Defender - In Combat - Cast Shield Block");

-- Silver Hand Disciple SAI
SET @ENTRY := 10949;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,6000,9000,11,14518,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silver Hand Disciple - In Combat - Cast Crusader Strike"),
(@ENTRY,0,1,0,14,0,100,0,0,40,15000,20000,11,15493,1,0,0,0,0,7,0,0,0,0,0,0,0,"Silver Hand Disciple - On Friendly Unit At 0 - 40% Health - Cast Holy Light");

-- Redpath Militia SAI
SET @ENTRY := 10950;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,8000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Redpath Militia - In Combat - Cast Strike");

-- Marauding Corpse SAI
SET @ENTRY := 10951;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,8000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marauding Corpse - In Combat - Cast Strike");

-- Marauding Skeleton SAI
SET @ENTRY := 10952;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,12000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marauding Skeleton - In Combat - Cast Hamstring"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,15000,18000,11,11972,1,0,0,0,0,2,0,0,0,0,0,0,0,"Marauding Skeleton - In Combat - Cast Shield Bash");

-- Servant of Horgus SAI
SET @ENTRY := 10953;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,11000,9000,12000,11,15608,1,0,0,0,0,2,0,0,0,0,0,0,0,"Servant of Horgus - In Combat - Cast Ravenous Claw");

-- Bloodletter SAI
SET @ENTRY := 10954;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,8000,12000,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodletter - In Combat - Cast Rupture"),
(@ENTRY,0,1,0,0,0,100,0,14000,18000,20000,25000,11,15667,1,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodletter - In Combat - Cast Sinister Strike");

-- Fallen Hero SAI
SET @ENTRY := 10996;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,18396,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fallen Hero - On Aggro - Cast Dismounting Blast"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,7000,9000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fallen Hero - In Combat - Cast Mortal Strike"),
(@ENTRY,0,2,0,0,0,100,0,1000,3000,9000,12000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fallen Hero - In Combat - Cast Incapacitating Shout"),
(@ENTRY,0,3,0,9,0,100,0,0,5,8000,14000,11,15618,1,0,0,0,0,2,0,0,0,0,0,0,0,"Fallen Hero - At 0 - 5 Range - Cast Snap Kick");

-- Spectral Betrayer SAI
SET @ENTRY := 11288;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,7000,10000,11,5337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Betrayer - In Combat - Cast Wither Strike");

-- Spectral Defender SAI
SET @ENTRY := 11289;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,8000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spectral Defender - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,7000,10000,11,12169,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spectral Defender - In Combat - Cast Shield Block");

-- Unliving Mossflayer SAI
SET @ENTRY := 11291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,9000,12000,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Mossflayer - In Combat - Cast Wither Touch"),
(@ENTRY,0,1,0,9,0,100,0,0,5,8000,14000,11,11428,1,0,0,0,0,2,0,0,0,0,0,0,0,"Unliving Mossflayer - At 0 - 5 Range - Cast Knockdown");

-- Nathanos Blightcaller SAI
SET @ENTRY := 11878;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nathanos Blightcaller - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,0,0,100,0,4000,6000,8000,11000,11,18651,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nathanos Blightcaller - In Combat - Cast Multi-Shot"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - In Combat - Display ranged weapon"),
(@ENTRY,0,8,9,0,0,100,0,7000,9000,10000,12000,11,6660,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nathanos Blightcaller - In Combat - Cast Shoot"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - In Combat - Display ranged weapon"),
(@ENTRY,0,10,11,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,12,13,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,13,14,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,15,16,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,17,0,9,0,100,0,0,5,7000,9000,11,6253,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nathanos Blightcaller - At 0 - 5 Range - Cast Backhand"),
(@ENTRY,0,18,0,15,0,100,1,0,10,0,0,11,13704,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - On Friendly Unit In CC - Cast Psychic Scream"),
(@ENTRY,0,19,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - On Evade - Display melee weapon");

-- Blighthound SAI
SET @ENTRY := 11885;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,16577,1,0,0,0,0,1,0,0,0,0,0,0,0,"Blighthound - On Respawn - Cast Disease Cloud"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,17000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blighthound - At 0 - 5 Range - Cast Rend");

-- Mercutio Filthgorger SAI
SET @ENTRY := 11886;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,6000,8000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mercutio Filthgorger - In Combat - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,8000,11000,11,12540,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mercutio Filthgorger - In Combat - Cast Gouge"),
(@ENTRY,0,2,0,9,0,100,0,0,5,6000,10000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mercutio Filthgorger - At 0 - 5 Range - Cast Sunder Armor");

-- Borelgore SAI
SET @ENTRY := 11896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,3000,4000,11,14516,0,0,0,0,0,5,0,0,0,0,0,0,0,"Borelgore - At 0 - 30 Range - Cast Strike"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,8000,11000,11,5568,1,0,0,0,0,1,0,0,0,0,0,0,0,"Borelgore - In Combat - Cast Trample");

-- Duskwing SAI
SET @ENTRY := 11897;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,8000,11000,11,14516,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duskwing - In Combat - Cast Strike");

-- Crusader Lord Valdelmar SAI
SET @ENTRY := 11898;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,17232,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Lord Valdelmar - On Aggro - Cast Devotion Aura"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,7000,9000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crusader Lord Valdelmar - In Combat - Cast Cleave"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,15000,20000,11,13005,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crusader Lord Valdelmar - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,3,0,2,0,100,1,0,20,0,0,11,17233,1,0,0,0,0,1,0,0,0,0,0,0,0,"Crusader Lord Valdelmar - At 20% HP - Cast Lay on Hands");

-- Conquered Soul of the Blightcaller SAI
SET @ENTRY := 12208;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,9000,12000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Conquered Soul of the Blightcaller - In Combat - Cast Incapacitating Shout");

-- Infiltrator Hameya SAI
SET @ENTRY := 12248;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,5000,9000,11,18270,32,0,0,0,0,5,0,0,0,0,0,0,0,"Infiltrator Hameya - At 0 - 30 Range - Cast Dark Plague"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,15000,17000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infiltrator Hameya - In Combat - Cast Rend");

-- Zaeldarr the Outcast SAI
SET @ENTRY := 12250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,6000,8000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zaeldarr the Outcast - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,9,0,100,0,0,5,8000,14000,11,19128,1,0,0,0,0,2,0,0,0,0,0,0,0,"Zaeldarr the Outcast - At 0 - 5 Range - Cast Knockdown");

-- Infected Mossflayer SAI
SET @ENTRY := 12261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,9000,12000,11,4974,32,0,0,0,0,2,0,0,0,0,0,0,0,"Infected Mossflayer - In Combat - Cast Wither Touch"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,9000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infected Mossflayer - At 0 - 5 Range - Cast Knockdown");

-- Ziggurat Protector SAI
SET @ENTRY := 12262;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,9000,12000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ziggurat Protector - In Combat - Cast Incapacitating Shout");

-- Slaughterhouse Protector SAI
SET @ENTRY := 12263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,9000,12000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slaughterhouse Protector - In Combat - Cast Incapacitating Shout");

-- Quel'Lithien Protector SAI
SET @ENTRY := 12322;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,15547,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,9,0,100,0,0,5,5000,7000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 0 - 5 Range - Cast Strike"),
(@ENTRY,0,14,0,9,0,100,0,0,5,8000,13000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 0 - 5 Range - Cast Kick"),
(@ENTRY,0,15,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 15% HP - Increment Phase"),
(@ENTRY,0,16,17,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Quel'Lithien Protector - At 15% HP - Flee For Assist"),
(@ENTRY,0,18,0,0,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - On Evade - Display melee weapon");

-- Crimson Courier SAI
SET @ENTRY := 12337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,60000,120000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Courier - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,39,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Courier - On Aggro - Call For Help"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,11,19726,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crimson Courier - On Aggro - Cast Resistance Aura"),
(@ENTRY,0,3,0,0,0,100,0,5000,7000,6000,8000,11,17143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Courier - In Combat - Cast Holy Strike"),
(@ENTRY,0,4,0,0,0,100,0,8000,11000,15000,20000,11,13005,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crimson Courier - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,5,0,0,0,100,0,9000,13000,10000,14000,11,17149,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crimson Courier - In Combat - Cast Exorcism"),
(@ENTRY,0,6,0,0,0,100,0,2000,4000,20000,26000,11,19725,1,0,0,0,0,6,0,0,0,0,0,0,0,"Crimson Courier - In Combat - Cast Turn Undead"),
(@ENTRY,0,7,0,14,0,100,0,0,40,14000,18000,11,15493,1,0,0,0,0,7,0,0,0,0,0,0,0,"Crimson Courier - On Friendly Unit At 0 - 40% Health - Cast Holy Light");

-- Texts for Crimson Courier
DELETE FROM `creature_text` WHERE `entry`= 12337;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(12337,0,0, "I sense danger up ahead.",12,0,100,0,0,0, "Crimson Courier"),
(12337,0,1, "If I should fall, take my pouch. Make certain that it gets to the High General.",12,0,100,0,0,0, "Crimson Courier"),
(12337,0,2, "My back is killing me.",12,0,100,0,0,0, "Crimson Courier");

-- Demetria SAI
SET @ENTRY := 12339;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,4000,5000,11,17194,0,0,0,0,0,2,0,0,0,0,0,0,0,"Demetria - In Combat - Cast Mind Blast"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,20000,25000,11,14515,1,0,0,0,0,6,0,0,0,0,0,0,0,"Demetria - In Combat - Cast Dominate Mind"),
(@ENTRY,0,2,0,0,0,100,0,9000,13000,18000,24000,11,17146,0,0,0,0,0,5,0,0,0,0,0,0,0,"Demetria - In Combat - Cast Shadow Word: Pain"),
(@ENTRY,0,3,0,0,0,100,0,15000,18000,15000,18000,11,17165,1,0,0,0,0,5,0,0,0,0,0,0,0,"Demetria - In Combat - Cast Mind Flay"),
(@ENTRY,0,4,0,15,0,100,1,0,15,0,0,11,17201,0,0,0,0,0,7,0,0,0,0,0,0,0,"Demetria - On Friendly Unit In CC - Cast Dispel Magic"),
(@ENTRY,0,5,0,2,0,100,0,0,30,20000,25000,11,13704,1,0,0,0,0,1,0,0,0,0,0,0,0,"Demetria - At 30% HP - Cast Psychic Scream");

-- Scarlet Trooper SAI
SET @ENTRY := 12352;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Trooper - On Aggro - Cast Devotion Aura"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,7000,9000,11,17149,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scarlet Trooper - In Combat - Cast Exorcism"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,15000,19000,11,13005,0,0,0,0,0,5,0,0,0,0,0,0,0,"Scarlet Trooper - In Combat - Cast Hammer of Justice"),
(@ENTRY,0,3,0,14,0,100,0,0,40,15000,20000,11,17233,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scarlet Trooper - On Friendly Unit At 0 - 40% Health - Cast Lay on Hands");

-- Crimson Bodyguard SAI
SET @ENTRY := 13118;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,25,15000,25000,11,15749,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crimson Bodyguard - At 8 - 25 Range - Cast Shield Charge"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,17000,20000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Bodyguard - In Combat - Cast Shield Bash"),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,11000,14000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Bodyguard - In Combat - Cast Disarm"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Crimson Bodyguard - At 15% HP - Flee For Assist");

-- Injured Peasant SAI
SET @ENTRY := 14484;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,23127,0,0,0,0,0,1,0,0,0,0,0,0,0,"Injured Peasant - On Respawn - Cast Death's Door");

-- Plagued Peasant SAI
SET @ENTRY := 14485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,23127,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plagued Peasant - On Respawn - Cast Death's Door");

-- Terrordale Spirit SAI
SET @ENTRY := 14564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,8000,11000,11,7713,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terrordale Spirit - In Combat - Cast Wailing Dead");

-- Plagued Swine SAI
SET @ENTRY := 16117;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,10000,15000,11,3385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plagued Swine - In Combat - Cast Boar Charge");

-- Nerubian Overseer SAI
SET @ENTRY := 16184;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,10000,13000,11,15471,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nerubian Overseer - At 0 - 20 Range - Cast Enveloping Web"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,7000,9000,11,31601,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nerubian Overseer - In Combat - Cast Crypt Scarabs");

-- Guard Didier SAI
SET @ENTRY := 16226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,28114,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guard Didier - On Respawn - Cast Mark of Didier"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guard Didier - On Aggro - Cast Charge");

-- Caravan Mule SAI
SET @ENTRY := 16232;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,28114,0,0,0,0,0,1,0,0,0,0,0,0,0,"Caravan Mule - On Respawn - Cast Mark of Didier");

-- Argent Medic SAI
SET @ENTRY := 16284;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Argent Medic - At 15% HP - Flee For Assist");

-- Argent Sentry SAI
SET @ENTRY := 16378;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,25821,0,0,0,0,0,2,0,0,0,0,0,0,0,"Argent Sentry - On Aggro - Cast Charge"),
(@ENTRY,0,1,2,0,0,100,0,4000,6000,7000,9000,11,19643,1,0,0,0,0,2,0,0,0,0,0,0,0,"Argent Sentry - In Combat - Cast Mortal Strike"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Sentry - In Combat - Display melee weapon"),
(@ENTRY,0,3,0,0,0,100,0,1000,3000,9000,12000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Sentry - In Combat - Cast Incapacitating Shout"),
(@ENTRY,0,4,0,9,0,100,0,0,5,8000,14000,11,15618,1,0,0,0,0,2,0,0,0,0,0,0,0,"Argent Sentry - At 0 - 5 Range - Cast Snap Kick"),
(@ENTRY,0,5,6,9,0,100,0,20,45,2300,3900,11,23337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Argent Sentry - At 20 - 45 Range - Cast Shoot"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Argent Sentry - At 20 - 45 Range - Display ranged weapon");

-- Siouxsie the Banshee SAI
SET @ENTRY := 27928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,36000,36000,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Siouxsie the Banshee - Out Of Combat - Say Line 0");

-- Texts for Siouxsie the Banshee
DELETE FROM `creature_text` WHERE `entry`= 27928;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(27928,0,0, "You can leave my sight, squire, before I slay you. Again.",12,0,100,0,0,0, "Siouxsie the Banshee"),
(27928,0,1, "No. Away with you, worm.",12,0,100,0,0,0, "Siouxsie the Banshee"),
(27928,0,2, "Get away from me, Edwards, lest I behead you.",12,0,100,0,0,0, "Siouxsie the Banshee");

-- Val'kyr Battle-maiden SAI
SET @ENTRY := 31095;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,7000,9000,11,57547,0,0,0,0,0,5,0,0,0,0,0,0,0,"Val'kyr Battle-maiden - In Combat - Cast Touch of the Val'kyr");

-- Scourge Necromancer SAI
SET @ENTRY := 31096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Necromancer - On Aggro - Cast Shadow Bolt"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20298,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scourge Necromancer - At 0 - 40 Range - Cast Shadow Bolt"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,0,0,100,0,12000,15000,16000,19000,11,51337,1,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - In Combat - Cast Shadowflame"),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 15% HP - Set Phase 3"),
(@ENTRY,0,13,14,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scourge Necromancer - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Scourge Necromancer - At 15% HP - Flee For Assist");

-- Terrifying Abomination SAI
SET @ENTRY := 31098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,8,40,0,0,11,50335,1,0,0,0,0,7,0,0,0,0,0,0,0,"Terrifying Abomination - At 8 - 40 Range - Cast Scourge Hook"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,9000,11,15496,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terrifying Abomination - At 0 - 5 Range - Cast Cleave");

-- Forest Spider SAI
SET @ENTRY := 30;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,80,0,11000,11000,15000,20000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Forest Spider - In Combat - Cast Poison");

-- Mine Spider SAI
SET @ENTRY := 43;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,4500,18000,28000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mine Spider - In Combat - Cast Poison");

-- Murloc Forager SAI
SET @ENTRY := 46;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,3368,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murloc Forager - At 40% HP - Cast Drink Minor Potion");

-- Ruklar the Trapper SAI
SET @ENTRY := 60;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,19600,19600,21000,31000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruklar the Trapper - In Combat - Cast Net"),
(@ENTRY,0,1,0,0,0,100,0,8200,8200,45000,50000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruklar the Trapper - In Combat - Cast Pierce Armor");

-- Diseased Timber Wolf SAI
SET @ENTRY := 69;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,71764,2,0,0,0,0,1,0,0,0,0,0,0,0,"Diseased Timber Wolf - On Respawn - Cast Diseased");

-- Narg the Taskmaster SAI
SET @ENTRY := 79;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,18000,18000,11,9128,0,0,0,0,0,1,0,0,0,0,0,0,0,"Narg the Taskmaster - In Combat - Cast Battle Shout");

-- Defias Cutpurse SAI
SET @ENTRY := 94;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1100,1100,2400,7900,11,53,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defias Cutpurse - In Combat - Cast Backstab");

-- Morgaine the Sly SAI
SET @ENTRY := 99;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1800,1800,16300,16300,11,1776,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morgaine the Sly - In Combat - Cast Gouge"),
(@ENTRY,0,1,0,0,0,100,0,8900,8900,30000,40000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Morgaine the Sly - In Combat - Cast Poison"),
(@ENTRY,0,2,0,0,0,100,0,5500,5500,3400,5400,11,53,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morgaine the Sly - In Combat - Cast Backstab");

-- Gruff Swiftbite SAI
SET @ENTRY := 100;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,16000,18000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gruff Swiftbite - In Combat - Cast Thrash");

-- Stonetusk Boar SAI
SET @ENTRY := 113;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetusk Boar - On Aggro - Cast Rushing Charge");

-- Longsnout SAI
SET @ENTRY := 119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Longsnout - On Aggro - Cast Rushing Charge");

-- Diseased Young Wolf SAI
SET @ENTRY := 299;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,71764,2,0,0,0,0,1,0,0,0,0,0,0,0,"Diseased Young Wolf - On Respawn - Cast Diseased");

-- Princess SAI
SET @ENTRY := 330;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Princess - On Aggro - Cast Rushing Charge");

-- Porcine Entourage SAI
SET @ENTRY := 390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Porcine Entourage - On Aggro - Cast Rushing Charge");

-- Mother Fang SAI
SET @ENTRY := 471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1500,1500,17000,19000,11,11918,32,0,0,0,0,2,0,0,0,0,0,0,0,"Mother Fang - In Combat - Cast Poison"),
(@ENTRY,0,1,0,0,0,100,0,6700,6700,22900,30900,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mother Fang - In Combat - Cast Web");

-- Fedfennel SAI
SET @ENTRY := 472;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,5000,12000,16000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Fedfennel - In Combat - Cast Demoralizing Shout"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,45000,50000,11,3238,1,0,0,0,0,1,0,0,0,0,0,0,0,"Fedfennel - In Combat - Cast Nimble Reflexes");

-- Morgan the Collector SAI
SET @ENTRY := 473;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1900,1900,11900,13900,11,1776,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morgan the Collector - In Combat - Cast Gouge");

-- Rockhide Boar SAI
SET @ENTRY := 524;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rockhide Boar - On Aggro - Cast Rushing Charge");

-- Gray Forest Wolf SAI
SET @ENTRY := 1922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,120000,600000,120000,600000,4,1018,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gray Forest Wolf - Out Of Combat - Play Sound 1018"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,5,393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gray Forest Wolf - Out Of Combat - Play Emote 393");

-- Forlorn Spirit SAI
SET @ENTRY := 2044;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forlorn Spirit - On Respawn - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,2000,2000,2000,2000,11,3105,32,0,0,0,0,2,0,0,0,0,0,0,0,"Forlorn Spirit - In Combat - Cast Curse of Stalvan"),
(@ENTRY,0,2,0,8,0,100,0,0,0,45000,45000,11,118,0,0,0,0,0,7,0,0,0,0,0,0,0,"Forlorn Spirit - On Spellhit - Cast Polymorph");

-- Texts for Forlorn Spirit
DELETE FROM `creature_text` WHERE `entry`= 2044;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(2044,0,0, "Toil not in matters of the past, $N!",12,0,100,0,0,0, "Forlorn Spirit"),
(2044,0,1, "Who is this mere $R that meddles with that which is past?  May the legend of Stalvan die along with you!",12,0,100,0,0,0, "Forlorn Spirit");

-- Cylina Darkheart SAI
SET @ENTRY := 6374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cylina Darkheart - On Respawn - Cast Summon Imp");

-- Crimson Cannon SAI
SET @ENTRY := 11199;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,4000,5000,11,17501,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Cannon - At 0 - 40 Range - Cast Cannon Fire");

-- Arcane Wraith SAI
SET @ENTRY := 15273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,16,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Arcane Wraith - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,16,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Arcane Wraith - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,2,0,0,0,100,0,10100,16500,12700,24800,11,37361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arcane Wraith - In Combat - Cast Arcane Bolt");

-- Mana Wyrm SAI
SET @ENTRY := 15274;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,16,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,16,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Mana Wyrm - On Spellhit Arcane Torrent - Quest Credit");

-- Lanthan Perilon SAI
SET @ENTRY := 15281;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lanthan Perilon - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lanthan Perilon - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lanthan Perilon - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Lanthan Perilon - At 15% HP - Flee For Assist");

-- Feral Tender SAI
SET @ENTRY := 15294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,16,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Feral Tender - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,16,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Feral Tender - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,2,0,2,0,100,0,0,50,15300,22900,11,31325,0,0,0,0,0,1,0,0,0,0,0,0,0,"Feral Tender - At 50% HP - Cast Renew");

-- Tainted Arcane Wraith SAI
SET @ENTRY := 15298;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,28730,0,0,0,16,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Tainted Arcane Wraith - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,1,0,8,0,100,1,25046,0,0,0,16,15468,28730,0,0,0,0,7,0,0,0,0,0,0,0,"Tainted Arcane Wraith - On Spellhit Arcane Torrent - Quest Credit"),
(@ENTRY,0,2,0,0,0,100,0,9000,18800,21100,32200,11,25603,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tainted Arcane Wraith - In Combat - Cast Slow");

-- Felendren the Banished SAI
SET @ENTRY := 15367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felendren the Banished - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,9100,10600,20500,28600,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felendren the Banished - In Combat - Cast Mind Flay");

-- Texts for Felendren the Banished
DELETE FROM `creature_text` WHERE `entry`= 15367;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15367,0,0, "Take heart! Your friends will not long mourn your passing!",12,0,100,0,0,0, "Felendren the Banished");

-- Sunstrider Guardian SAI
SET @ENTRY := 15371;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,22,0,30,0,78,1000,1000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunstrider Guardian - Received Emote - Say Line 0"),
(@ENTRY,0,1,0,22,0,30,0,77,1000,1000,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sunstrider Guardian - Received Emote - Say Line 1");

-- Texts for Sunstrider Guardian
DELETE FROM `creature_text` WHERE `entry`= 15371;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15371,0,0, "Move along, $C.",12,0,100,66,0,0, "Sunstrider Guardian"),
(15371,0,1, "Off with you, $N.",12,0,100,66,0,0, "Sunstrider Guardian"),
(15371,1,0, "Do not push it citizen!",12,0,100,1,0,0, "Sunstrider Guardian");

-- Ley-Keeper Velania SAI
SET @ENTRY := 15401;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ley-Keeper Velania - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ley-Keeper Velania - At 15% HP - Flee For Assist");

-- Ley-Keeper Caidanis SAI
SET @ENTRY := 15405;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ley-Keeper Caidanis - At 15% HP - Flee For Assist");

-- Chieftain Zul'Marosh SAI
SET @ENTRY := 15407;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,10600,26200,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Chieftain Zul'Marosh - In Combat - Cast Cleave"),
(@ENTRY,0,1,0,0,0,100,0,15600,15600,12500,23200,11,11971,1,0,0,0,0,2,0,0,0,0,0,0,0,"Chieftain Zul'Marosh - In Combat - Cast Sunder Armor");

-- Spearcrafter Otembe SAI
SET @ENTRY := 15408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6700,6700,21800,32300,11,3148,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spearcrafter Otembe - In Combat - Cast Head Crack");

-- Old Whitebark SAI
SET @ENTRY := 15409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12800,17400,36200,48800,11,11442,32,0,0,0,0,2,0,0,0,0,0,0,0,"Old Whitebark - In Combat - Cast Withered Touch");

-- Ranger Jaela SAI
SET @ENTRY := 15416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Jaela - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Jaela - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Jaela - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,1500,3000,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Jaela - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Jaela - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Jaela - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Jaela - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Jaela - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Jaela - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ranger Jaela - At 100% Mana - Increment Phase");

-- Velan Brightoak SAI
SET @ENTRY := 15417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Velan Brightoak - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Velan Brightoak - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velan Brightoak - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Velan Brightoak - At 15% HP - Flee For Assist");

-- Magister Jaronis SAI
SET @ENTRY := 15418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Jaronis - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magister Jaronis - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magister Jaronis - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Magister Jaronis - At 15% HP - Flee For Assist");

-- Withered Green Keeper SAI
SET @ENTRY := 15637;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10200,11900,14100,25800,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Green Keeper - In Combat - Cast Strike");

-- Arcane Patroller SAI
SET @ENTRY := 15638;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arcane Patroller - On Aggro - Say Line 0");

-- Texts for Arcane Patroller
DELETE FROM `creature_text` WHERE `entry`= 15638;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15638,0,0, "Uphold the Law!",12,0,100,0,0,0, "Arcane Patroller"),
(15638,0,1, "Serve the Public Trust!",12,0,100,0,0,0, "Arcane Patroller"),
(15638,0,2, "Protect the innocent!",12,0,100,0,0,0, "Arcane Patroller");

-- Amani Axe Thrower SAI
SET @ENTRY := 15641;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Axe Thrower - On Aggro - Cast Throw"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,2300,3900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Axe Thrower - At 5 - 30 Range - Cast Throw"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,7,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - At 25 - 80 Range - Start Auto Attack"),
(@ENTRY,0,8,9,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,10,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,11,12,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - At 5 - 15 Range - Start Auto Attack"),
(@ENTRY,0,13,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Axe Thrower - On Evade - Display melee weapon");

-- Amani Shadowpriest SAI
SET @ENTRY := 15642;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4200,7700,7100,16200,11,11639,32,0,0,0,0,2,0,0,0,0,0,0,0,"Amani Shadowpriest - In Combat - Cast Shadow Word: Pain");

-- Amani Berserker SAI
SET @ENTRY := 15643;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Berserker - At 30% HP - Cast Frenzy"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani Berserker - At 30% HP - Say Line 0");

-- Texts for Amani Berserker
DELETE FROM `creature_text` WHERE `entry`= 15643;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15643,0,0, "%s becomes enraged!",16,0,100,0,0,0, "Amani Berserker");

-- Texts for Wretched Urchin
DELETE FROM `creature_text` WHERE `entry`= 15644;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15644,0,0, "The pain...the need...I hunger for more...",12,10,100,0,0,0, "Wretched Urchin"),
(15644,0,1, "I cannot stand the pain.  I must find a new source.",12,10,100,0,0,0, "Wretched Urchin"),
(15644,0,2, "More, more, more!  I must feed soon.",12,10,100,0,0,0, "Wretched Urchin");

-- Texts for Wretched Thug
DELETE FROM `creature_text` WHERE `entry`= 15645;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15645,0,0, "The pain...the need...I hunger for more...",12,10,100,0,0,0, "Wretched Thug"),
(15645,0,1, "I cannot stand the pain.  I must find a new source.",12,10,100,0,0,0, "Wretched Thug"),
(15645,0,2, "More, more, more!  I must feed soon.",12,10,100,0,0,0, "Wretched Thug");

-- Texts for Manawraith
DELETE FROM `creature_text` WHERE `entry`= 15648;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15648,0,0, "%s bursts, showering the area with arcane residue!",16,0,100,0,0,0, "Manawraith");

-- Wretched Urchin SAI
SET @ENTRY := 15644;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Urchin - On Aggro - Say Line 0");

-- Wretched Thug SAI
SET @ENTRY := 15645;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Thug - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,0,0,100,0,1500,7900,5700,16100,11,29098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Thug - In Combat - Cast Bitter Withdrawal");

-- Mana Stalker SAI
SET @ENTRY := 15647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,600,7900,17900,24900,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Stalker - In Combat - Cast Moonfire");

-- Manawraith SAI
SET @ENTRY := 15648;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5600,9400,11100,24100,11,25602,0,0,0,0,0,2,0,0,0,0,0,0,0,"Manawraith - In Combat - Cast Faerie Fire"),
(@ENTRY,0,1,2,6,0,100,0,0,0,0,0,11,29109,3,0,0,0,0,1,0,0,0,0,0,0,0,"Manawraith - On Death - Cast Arcane Residue"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Manawraith - On Death - Say Line 0");

-- Springpaw Stalker SAI
SET @ENTRY := 15651;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,24450,0,0,0,0,0,1,0,0,0,0,0,0,0,"Springpaw Stalker - On Respawn - Cast Prowl"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,24450,0,0,0,0,0,1,0,0,0,0,0,0,0,"Springpaw Stalker - On Evade - Cast Prowl");

-- Elder Springpaw SAI
SET @ENTRY := 15652;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,24450,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Springpaw - On Respawn - Cast Prowl"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,24450,0,0,0,0,0,1,0,0,0,0,0,0,0,"Elder Springpaw - On Evade - Cast Prowl");

-- Plaguebone Pillager SAI
SET @ENTRY := 15654;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5900,12200,11900,22100,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plaguebone Pillager - In Combat - Cast Strike");

-- Angershade SAI
SET @ENTRY := 15656;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angershade - At 30% HP - Cast Enrage"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Angershade - At 30% HP - Say Line 0");

-- Texts for Angershade
DELETE FROM `creature_text` WHERE `entry`= 15656;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15656,0,0, "%s goes into a frenzy!",16,0,100,0,0,0, "Angershade");

-- Texts for Darkwraith
DELETE FROM `creature_text` WHERE `entry`= 15657;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(15657,0,0, "%s goes into a frenzy!",16,0,100,0,0,0, "Darkwraith");

-- Darkwraith SAI
SET @ENTRY := 15657;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkwraith - At 30% HP - Cast Enrage"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkwraith - At 30% HP - Say Line 0");

-- Rotlimb Marauder SAI
SET @ENTRY := 15658;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1700,4700,10300,23600,11,3234,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rotlimb Marauder - In Combat - Cast Disease Touch");

-- Grimscale Oracle SAI
SET @ENTRY := 15669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,70,53400,55800,11,17137,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimscale Oracle - At 70% HP - Cast Flash Heal");

-- Grimscale Forager SAI
SET @ENTRY := 15670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,17400,12300,27900,11,7365,32,0,0,0,0,2,0,0,0,0,0,0,0,"Grimscale Forager - In Combat - Cast Bottle of Poison");

-- Mmmrrrggglll SAI
SET @ENTRY := 15937;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2500,8500,21700,123400,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mmmrrrggglll - In Combat - Cast Chain Lightning"),
(@ENTRY,0,1,0,0,0,100,0,7800,14700,11200,22500,11,21030,1,0,0,0,0,2,0,0,0,0,0,0,0,"Mmmrrrggglll - In Combat - Cast Frost Shock"),
(@ENTRY,0,2,0,2,0,100,0,0,70,82400,174000,11,12491,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mmmrrrggglll - At 70% HP - Cast Healing Wave");

-- Eversong Ranger SAI
SET @ENTRY := 15938;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - Out Of Combat - Start Auto Attack"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eversong Ranger - On Aggro - Cast Shoot"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - On Aggro - Increment Phase"),
(@ENTRY,0,4,5,9,0,100,0,5,30,3400,3700,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eversong Ranger - At 5 - 30 Range - Cast Shoot"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - At 5 - 30 Range - Display ranged weapon"),
(@ENTRY,0,6,0,9,0,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - At 25 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,8,9,0,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,8,9,9,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - At 0 - 5 Range - Display melee weapon"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - At 0 - 5 Range - Start Auto Attack"),
(@ENTRY,0,10,0,9,0,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - At 15% HP - Increment Phase"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Eversong Ranger - At 15% HP - Flee For Assist"),
(@ENTRY,0,14,0,7,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Ranger - On Evade - Display melee weapon");

-- Apprentice Meledor SAI
SET @ENTRY := 15945;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apprentice Meledor - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apprentice Meledor - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Meledor - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Apprentice Meledor - At 15% HP - Flee For Assist");

-- Grimscale Seer SAI
SET @ENTRY := 15950;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6800,8500,14000,26000,11,20802,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimscale Seer - In Combat - Cast Lightning Bolt");

-- Duskwither Apprentice SAI
SET @ENTRY := 15965;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,16900,25200,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duskwither Apprentice - In Combat - Cast Mind Blast");

-- Mana Serpent SAI
SET @ENTRY := 15966;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5400,11300,11200,38300,11,25602,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mana Serpent - In Combat - Cast Faerie Fire");

-- Instructor Antheol SAI
SET @ENTRY := 15970;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Instructor Antheol - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Instructor Antheol - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Instructor Antheol - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Instructor Antheol - At 15% HP - Flee For Assist");

-- Silvermoon Apprentice SAI
SET @ENTRY := 15971;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermoon Apprentice - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Silvermoon Apprentice - At 15% HP - Flee For Assist");

-- Wretched Hooligan SAI
SET @ENTRY := 16162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8800,13700,9900,19500,11,29098,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Hooligan - In Combat - Cast Bitter Withdrawal"),
(@ENTRY,0,1,0,0,0,100,0,9900,12900,11900,17500,11,14873,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wretched Hooligan - In Combat - Cast Sinister Strike");

-- Paelarin SAI
SET @ENTRY := 16263;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,50,0,30000,90000,240000,480000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Paelarin - Out Of Combat - Say Line 0");

-- Texts for Paelarin
DELETE FROM `creature_text` WHERE `entry`= 16263;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16263,0,0, "I don't see why we ally with filthy stinking trolls? The only good troll is a dead troll.",12,0,100,1,0,0, "Paelarin"),
(16263,0,1, "Does anyone need any supplies to down the trolls? Any troll will do.",12,0,100,1,0,0, "Paelarin");

-- Aldaron the Reckless SAI
SET @ENTRY := 16294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aldaron the Reckless - On Aggro - Cast Fireball"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - On Aggro - Increment Phase"),
(@ENTRY,0,3,0,9,0,100,0,0,40,4700,5200,11,9053,0,0,0,0,0,2,0,0,0,0,0,0,0,"Aldaron the Reckless - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,4,5,3,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - At 15% Mana - Allow Combat Movement"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - At 15% Mana - Increment Phase"),
(@ENTRY,0,6,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,7,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - At 100% Mana - Increment Phase"),
(@ENTRY,0,10,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - At 15% HP - Set Phase 3"),
(@ENTRY,0,11,12,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Aldaron the Reckless - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Aldaron the Reckless - At 15% HP - Flee For Assist");

-- Runewarden Deryan SAI
SET @ENTRY := 16362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Runewarden Deryan - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Runewarden Deryan - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runewarden Deryan - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Runewarden Deryan - At 15% HP - Flee For Assist");

-- Ardeyn Riverwind SAI
SET @ENTRY := 16397;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - Out Of Combat - Allow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - Out Of Combat - Set Phase 0"),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ardeyn Riverwind - On Aggro - Cast Fireball"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - On Aggro - Increment Phase"),
(@ENTRY,0,4,0,9,0,100,0,0,40,3400,4800,11,20811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 0 - 40 Range - Cast Fireball"),
(@ENTRY,0,5,6,3,0,100,0,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 7% Mana - Allow Combat Movement"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 7% Mana - Increment Phase"),
(@ENTRY,0,7,0,9,0,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 35 - 80 Range - Allow Combat Movement"),
(@ENTRY,0,8,0,9,0,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 5 - 15 Range - Allow Combat Movement"),
(@ENTRY,0,9,0,9,0,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 0 - 5 Range - Allow Combat Movement"),
(@ENTRY,0,10,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 100% Mana - Increment Phase"),
(@ENTRY,0,11,0,2,0,100,1,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 15% HP - Set Phase 3"),
(@ENTRY,0,12,13,2,0,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 15% HP - Allow Combat Movement"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Ardeyn Riverwind - At 15% HP - Flee For Assist");

-- Wretched Captive SAI
SET @ENTRY := 16916;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,14000,14000,14000,14000,5,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Captive - Out Of Combat - Play Emote 20"),
(@ENTRY,0,1,2,1,0,100,0,242000,242000,242000,242000,5,18,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Captive - Out Of Combat - Play Emote 18"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wretched Captive - Out Of Combat - Say Line 0");

-- Texts for Wretched Captive
DELETE FROM `creature_text` WHERE `entry`= 16916;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16916,0,0, "Please!  I must feed on something soon... A mana crystal.... a shard... anything!  The pain is unbearable!",12,0,100,0,0,0, "Wretched Captive");

-- Sergeant Kan'ren SAI
SET @ENTRY := 16924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,240000,240000,240000,240000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Kan'ren - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,244000,244000,244000,244000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Kan'ren - Out Of Combat - Say Line 1");

-- Texts for Sergeant Kan'ren
DELETE FROM `creature_text` WHERE `entry`= 16924;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(16924,0,0, "Tell us!  Where does your leader hide?",12,0,100,1,0,0, "Sergeant Kan''ren"),
(16924,1,0, "You're not getting anything until you speak, scum!",12,0,100,1,0,0, "Sergeant Kan''ren");

-- Texts for Enraged Wraith
DELETE FROM `creature_text` WHERE `entry`= 17086;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(17086,0,0, "%s goes into a frenzy!",16,0,100,0,0,0, "Enraged Wraith");

-- Texts for Kyrenna
DELETE FROM `creature_text` WHERE `entry`= 18929;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(18929,0,0, "Ooh what a dreadful job! All day, surrounded by the stench of bad feet.",12,0,100,1,0,0, "Kyrenna"),
(18929,0,1, "Why couldn't mother have chosen something else to dedicate herself to? Cakes, pastries, even bread - anything but cheese!",12,0,100,1,0,0, "Kyrenna"),
(18929,0,2, "If only I had some wine to go with my cheese...",12,0,100,18,0,0, "Kyrenna");

-- Texts for Jane
DELETE FROM `creature_text` WHERE `entry`= 20098;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(20098,0,0, "I'm right here, daddy. You've been asleep all day long. You sure must be tired!",12,0,100,1,0,0, "Jane");

-- Texts for Jessel
DELETE FROM `creature_text` WHERE `entry`= 20100;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(20100,0,0, "Was... Was it all a dream? Azuremyst, Bloodymyst, Zangarmarsh, Shadowmoon... even Zul'Aman... Jane! Jane where are you!",12,0,100,1,0,0, "Jessel"),
(20100,1,0, "Ah, wonderful. It was all just a dream...",12,0,100,1,0,0, "Jessel");

-- Eversong Partygoer SAI
SET @ENTRY := 17056;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,5,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eversong Partygoer - On Respawn - Play Emote 10");

-- Enraged Wraith SAI
SET @ENTRY := 17086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,0,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Wraith - At 30% HP - Cast Enrage"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Wraith - At 30% HP - Say Line 0");

-- Kyrenna SAI
SET @ENTRY := 18929;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,120000,240000,300000,420000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kyrenna - Out Of Combat - Say Line 0");

-- Jane SAI
SET @ENTRY := 20098;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,132000,132000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jane - Out Of Combat - Say Line 0");

-- Jessel SAI
SET @ENTRY := 20100;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,5,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessel - On Respawn - Play Emote 12"),
(@ENTRY,0,1,0,1,0,100,0,120000,120000,300000,300000,5,13,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessel - Out Of Combat - Play Emote 13"),
(@ENTRY,0,2,0,1,0,100,0,125000,125000,300000,300000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessel - Out Of Combat - Say Line 0"),
(@ENTRY,0,3,0,1,0,100,0,139000,139000,300000,300000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessel - Out Of Combat - Say Line 1"),
(@ENTRY,0,4,0,1,0,100,0,145000,145000,300000,300000,5,12,0,0,0,0,0,1,0,0,0,0,0,0,0,"Jessel - Out Of Combat - Play Emote 12");

-- Traveling Orphan SAI
SET @ENTRY := 23971;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,60000,240000,180000,300000,5,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Traveling Orphan - Out Of Combat - Play Emote 11");

-- Silvermoon Dragonhawk SAI
SET @ENTRY := 27946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,6000,9000,11,37985,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silvermoon Dragonhawk - In Combat - Cast Fire Breath");

-- Summoned Voidwalker SAI
SET @ENTRY := 5676;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,7741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Voidwalker - On Respawn - Cast Summoned Demon"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,7750,1,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Voidwalker - At 30% HP - Cast Consuming Rage");
