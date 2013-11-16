-- Forest Moss Creeper SAI
SET @ENTRY := 2350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7800,15700,48300,66300,11,3396,32,0,0,0,0,2,0,0,0,0,0,0,0,"Forest Moss Creeper - In Combat - Cast 3396");

-- Bonechewer Behemoth SAI
SET @ENTRY := 23196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,1000,25000,45000,11,41277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Behemoth - In Combat - Cast 41277 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,15000,15000,30000,40000,11,41274,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bonechewer Behemoth - In Combat - Cast 41274 (Normal Dungeon)"),
(@ENTRY,0,2,3,2,0,100,3,0,30,0,0,11,40743,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Behemoth - Between 0-30% Health - Cast 40743 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Behemoth - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,4,0,4,0,100,3,0,0,0,0,11,41272,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Behemoth - On Aggro - Cast 41272 (Normal Dungeon)");

-- Texts for Bonechewer Behemoth
SET @ENTRY := 23196;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bonechewer Behemoth");

-- Bonechewer Brawler SAI
SET @ENTRY := 23222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,0,100,2,10000,10000,35000,41500,11,41254,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Brawler - In Combat - Cast 41254 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Brawler - In Combat - Say Line 0 (Normal Dungeon)");

-- Texts for Bonechewer Brawler
SET @ENTRY := 23222;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bonechewer Brawler");

-- Bonechewer Blood Prophet SAI
SET @ENTRY := 23237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,41230,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Blood Prophet - On Aggro - Cast 41230 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7500,7500,15000,22500,11,41229,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Blood Prophet - In Combat - Cast 41229 (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,50,0,0,11,41238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer Blood Prophet - Between 0-50% Health - Cast 41238 (Normal Dungeon)"),
(@ENTRY,0,3,4,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Blood Prophet - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Blood Prophet - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Bonechewer Blood Prophet
SET @ENTRY := 23237;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bonechewer Blood Prophet");

-- Bonechewer Combatant SAI
SET @ENTRY := 23239;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,3,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Combatant - Between 0-30% Health - Cast 8269 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bonechewer Combatant - Between 0-30% Health - Say Line 0 (Normal Dungeon)");

-- Texts for Bonechewer Combatant
SET @ENTRY := 23239;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bonechewer Combatant");

-- Bash'ir Flesh Fiend SAI
SET @ENTRY := 23249;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,0,9000,15000,12000,19000,11,29939,32,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Flesh Fiend - In Combat - Cast 29939"),
(@ENTRY,0,1,0,2,0,100,0,0,20,31000,31000,11,29935,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bash'ir Flesh Fiend - Between 0-20% Health - Cast 29935");

-- Bash'ir Reckoner SAI
SET @ENTRY := 23332;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,30798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Reckoner - On Aggro - Cast 30798"),
(@ENTRY,0,1,0,0,0,90,0,30000,30000,30000,30000,11,40949,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Reckoner - In Combat - Cast 40949"),
(@ENTRY,0,2,0,0,0,100,1,0,0,1000,1000,11,35570,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bash'ir Reckoner - In Combat - Cast 35570"),
(@ENTRY,0,3,0,0,0,65,0,36000,36000,36000,36000,11,40935,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Reckoner - In Combat - Cast 40935");

-- Bash'ir Controller SAI
SET @ENTRY := 23368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,36000,36000,36000,36000,11,34944,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Controller - In Combat - Cast 34944"),
(@ENTRY,0,1,0,2,0,100,0,0,40,25000,25000,11,32130,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Controller - Between 0-40% Health - Cast 32130"),
(@ENTRY,0,2,0,0,0,75,0,42000,42000,60000,60000,11,10901,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Controller - In Combat - Cast 10901");

-- Bash'ir's Harbinger SAI
SET @ENTRY := 23390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,30798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir's Harbinger - On Aggro - Cast 30798"),
(@ENTRY,0,1,0,0,0,100,1,0,0,1000,1000,11,35570,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bash'ir's Harbinger - In Combat - Cast 35570"),
(@ENTRY,0,2,0,0,0,75,0,25000,25000,25000,25000,11,23920,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir's Harbinger - In Combat - Cast 23920"),
(@ENTRY,0,3,0,0,0,65,0,36000,36000,36000,36000,11,40935,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir's Harbinger - In Combat - Cast 40935");

-- Bash'ir SAI
SET @ENTRY := 23391;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,90,0,30000,30000,30000,30000,11,36908,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir - In Combat - Cast 36908"),
(@ENTRY,0,1,0,0,0,75,0,33000,33000,18000,18000,11,41264,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir - In Combat - Cast 41264"),
(@ENTRY,0,2,0,0,0,60,0,7000,7000,12000,12000,11,41266,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bash'ir - In Combat - Cast 41266"),
(@ENTRY,0,3,0,0,0,75,0,9000,9000,13000,13000,11,43433,0,0,0,0,0,6,0,0,0,0,0,0,0,"Bash'ir - In Combat - Cast 43433");

-- Deathshadow Agent SAI
SET @ENTRY := 23393;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,8000,14000,11,36447,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathshadow Agent - In Combat - Cast 36447");

-- Bash'ir Inquisitor SAI
SET @ENTRY := 23414;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,30798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Inquisitor - On Aggro - Cast 30798"),
(@ENTRY,0,1,0,0,0,100,1,0,0,1000,1000,11,35570,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bash'ir Inquisitor - In Combat - Cast 35570"),
(@ENTRY,0,2,0,0,0,75,0,25000,25000,25000,25000,11,23920,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bash'ir Inquisitor - In Combat - Cast 23920"),
(@ENTRY,0,3,0,0,0,65,0,36000,36000,36000,36000,11,40935,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bash'ir Inquisitor - In Combat - Cast 40935");

-- Amani'shi Scout SAI
SET @ENTRY := 23586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Scout - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,42177,0,0,0,0,0,1,0,0,0,0,0,0,0,"Amani'shi Scout - On Aggro - Cast 42177 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,2000,2000,4000,5000,11,16496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Scout - In Combat - Cast 16496 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,6000,6000,20000,24000,11,43205,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amani'shi Scout - In Combat - Cast 43205 (Normal Dungeon)");

-- Texts for Amani'shi Scout
SET @ENTRY := 23586;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Invaders! Sound the Alarm!",14,0,100,0,0,12104,"Amani\'shi Scout");

-- Ahab Wheathoof SAI
SET @ENTRY := 23618;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,10,0,100,0,1,10,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ahab Wheathoof - On LOS Out Of Combat - Say Line 0");

-- Texts for Ahab Wheathoof
SET @ENTRY := 23618;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Where is that dog?",12,0,100,0,0,11796,"Ahab Wheathoof"),
(@ENTRY,0,1,"I miss my dog so much...",12,0,100,0,0,11798,"Ahab Wheathoof"),
(@ENTRY,0,2,"Will you help me find my dog...?",12,0,100,0,0,11797,"Ahab Wheathoof");

-- Spore SAI
SET @ENTRY := 23876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,12000,23000,28000,11,42526,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spore - In Combat - Cast 42526"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spore - On Death - Set Event Phase 1"),
(@ENTRY,0,2,0,8,1,100,1,43354,0,0,0,33,24235,0,0,0,0,0,7,0,0,0,0,0,0,0,"Spore - On Spellhit By 43354 - Quest Credit (Phase 1)");

-- Ulf the Bloodletter SAI
SET @ENTRY := 24016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,12000,11,48288,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ulf the Bloodletter - Between 0-5 Range - Cast 48288"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ulf the Bloodletter - On Death - Set Event Phase 1"),
(@ENTRY,0,2,3,8,1,100,1,43178,0,0,0,33,24165,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ulf the Bloodletter - On Spellhit By 43178 - Quest Credit (Phase 1)"),
(@ENTRY,0,3,0,61,1,100,1,43178,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ulf the Bloodletter - On Spellhit By 43178 - Forced Despawn (Phase 1)");

-- Dragonflayer Metalworker SAI
SET @ENTRY := 24078;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,2000,7000,7000,11,15572,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Metalworker - In Combat - Cast 15572 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,2000,2000,7000,7000,11,59608,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Metalworker - In Combat - Cast 59608 (Heroic Dungeon)"),
(@ENTRY,0,2,3,2,0,100,7,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Metalworker - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Metalworker - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Dragonflayer Metalworker
SET @ENTRY := 24078;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Dragonflayer Metalworker");

-- North Fleet Reservist SAI
SET @ENTRY := 24120;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,43115,0,25000,25000,33,24121,0,0,0,0,0,7,0,0,0,0,0,0,0,"North Fleet Reservist - On Spellhit By 43115 - Quest Credit"),
(@ENTRY,0,1,0,61,0,80,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Reservist - On Spellhit By 43115 - Say Line 0");

-- Texts for North Fleet Reservist
SET @ENTRY := 24120;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Someone shoot that bat down!",14,0,100,0,0,0,"North Fleet Reservist"),
(@ENTRY,0,1,"That liquid... it reeks!",14,0,100,0,0,0,"North Fleet Reservist"),
(@ENTRY,0,2,"I don't feel so good...",14,0,100,0,0,0,"North Fleet Reservist"),
(@ENTRY,0,3,"It was awful.. I dreamt I was fighting against my friends",12,0,66,0,0,0,"North Fleet Reservist"),
(@ENTRY,0,4,"Help! My eyes!",14,0,33,0,0,0,"North Fleet Reservist");

-- Oric the Baleful SAI
SET @ENTRY := 24161;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,8000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oric the Baleful - Between 0-5 Range - Cast 15496"),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,9000,13000,11,32736,1,0,0,0,0,2,0,0,0,0,0,0,0,"Oric the Baleful - In Combat - Cast 32736"),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oric the Baleful - On Death - Set Event Phase 1"),
(@ENTRY,0,3,4,8,1,100,1,43178,-1,0,0,33,24166,0,0,0,0,0,7,0,0,0,0,0,0,0,"Oric the Baleful - On Spellhit By 43178 - Quest Credit (Phase 1)"),
(@ENTRY,0,4,0,61,1,100,1,43178,-1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oric the Baleful - On Spellhit By 43178 - Forced Despawn (Phase 1)");

-- Gunnar Thorvardsson SAI
SET @ENTRY := 24162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,9000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gunnar Thorvardsson - Between 0-5 Range - Cast 41056"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gunnar Thorvardsson - On Death - Set Event Phase 1"),
(@ENTRY,0,2,3,8,1,100,1,43178,-1,0,0,33,24167,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gunnar Thorvardsson - On Spellhit By 43178 - Quest Credit (Phase 1)"),
(@ENTRY,0,3,0,61,1,100,1,43178,-1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gunnar Thorvardsson - On Spellhit By 43178 - Forced Despawn (Phase 1)");

-- Bloodscalp Axe Thrower SAI
SET @ENTRY := 694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - On Aggro - Cast 10277"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,5,9,2,100,0,5,30,3500,4900,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 5-30 Range - Cast 10277 (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,14,2,0,100,1,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-30% Health - Cast 8599"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-30% Health - Say Line 0"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - On Evade - Set Sheath Melee");

-- Texts for Bloodscalp Axe Thrower
SET @ENTRY := 694;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bloodscalp Axe Thrower");

-- Dark Iron Demolitionist SAI
SET @ENTRY := 1054;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Iron Demolitionist - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,8858,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Demolitionist - On Aggro - Cast 8858"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,2,100,0,5,30,3600,3800,11,8858,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 5-30 Range - Cast 8858 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,7,8,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,9,10,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,11,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,11,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,12,13,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,13,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,14,0,0,0,100,0,1200,8300,8200,20100,11,7891,3,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Iron Demolitionist - In Combat - Cast 7891"),
(@ENTRY,0,15,16,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Demolitionist - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,18,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Demolitionist - On Evade - Set Sheath Melee");

-- Texts for Dark Iron Demolitionist
SET @ENTRY := 1054;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Never cross a Dark Iron, $c.",12,0,100,0,0,0,"Dark Iron Demolitionist"),
(@ENTRY,0,1,"Time to die, $c!",12,0,100,0,0,0,"Dark Iron Demolitionist"),
(@ENTRY,0,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,"Dark Iron Demolitionist");

-- Dark Iron Sapper SAI
SET @ENTRY := 1222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Sapper - On Aggro - Say Line 0"),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Sapper - Between 0-15% Health - Say Line 1"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Sapper - Between 0-15% Health - Say Line 2"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,3204,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Sapper - Between 0-15% Health - Cast 3204");

-- Texts for Dark Iron Sapper
SET @ENTRY := 1222;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Die in the name of Ragnaros!",12,0,100,0,0,0,"Dark Iron Sapper"),
(@ENTRY,0,1,"The Thandol Span fell to Ragnaros. So shall the Stonewrought Dam!",12,0,100,0,0,0,"Dark Iron Sapper"),
(@ENTRY,0,2,"King Magni Bronzebeard is a fool and a charlatan!",12,0,100,0,0,0,"Dark Iron Sapper"),
(@ENTRY,1,0,"Wahehe! I'm taking you down with me!",12,0,100,11,0,0,"Dark Iron Sapper"),
(@ENTRY,2,0,"%s's eyes glow red as he lights his dynamite and begins to cackle madly!",16,0,100,0,0,0,"Dark Iron Sapper");

-- Balgaras the Foul SAI
SET @ENTRY := 1364;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balgaras the Foul - Out Of Combat - Cast 12746"),
(@ENTRY,0,1,0,4,0,70,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Balgaras the Foul - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,4800,7700,21100,21100,11,9081,0,0,0,0,0,2,0,0,0,0,0,0,0,"Balgaras the Foul - In Combat - Cast 9081"),
(@ENTRY,0,3,0,0,0,100,0,6400,12500,19600,38000,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balgaras the Foul - In Combat - Cast 11831"),
(@ENTRY,0,4,0,0,0,100,0,13400,16400,182200,182400,11,3586,0,0,0,0,0,2,0,0,0,0,0,0,0,"Balgaras the Foul - In Combat - Cast 3586"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Balgaras the Foul - Between 0-15% Health - Flee For Assist");

-- Texts for Balgaras the Foul
SET @ENTRY := 1364;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"This land belongs to the Dark Iron Dwarves. Prepare to see the afterlife, $c!",12,6,100,0,0,0,"Balgaras the Foul");

-- Bloodfeather Sorceress SAI
SET @ENTRY := 2018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Out Of Combat - Cast 12544"),
(@ENTRY,0,2,3,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bloodfeather Sorceress - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfeather Sorceress - On Aggro - Cast 20793"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,2,100,0,0,40,2400,3800,11,20793,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Between 0-40 Range - Cast 20793 (Phase 2)"),
(@ENTRY,0,6,7,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,11,0,3,4,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodfeather Sorceress - Between 30-100% Mana - Decrement Event Phase (Phase 4)");

-- Texts for Bloodfeather Sorceress
SET @ENTRY := 2018;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"A fine trophy your head will make, $r.",12,0,100,0,0,0,"Bloodfeather Sorceress"),
(@ENTRY,0,1,"My talons will shred your puny body, $r.",12,0,100,0,0,0,"Bloodfeather Sorceress"),
(@ENTRY,0,2,"You will be easy prey, $c.",14,0,100,0,0,0,"Bloodfeather Sorceress");

-- Dragonmaw Scout SAI
SET @ENTRY := 2103;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dragonmaw Scout - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Scout - On Aggro - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,2,100,0,5,30,2400,3600,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,7,8,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,9,10,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,11,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,11,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,12,13,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,13,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dragonmaw Scout - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Scout - On Evade - Set Sheath Melee");

-- Texts for Dragonmaw Scout
SET @ENTRY := 2103;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Your bones will break under my boot, $r!",12,1,100,0,0,0,"Dragonmaw Scout"),
(@ENTRY,0,1,"Long live the Dragonmaw! Die you worthless $r!",12,1,100,0,0,0,"Dragonmaw Scout"),
(@ENTRY,0,2,"For the Dragonmaw!",12,1,100,0,0,0,"Dragonmaw Scout");

-- Hatefury Hellcaller SAI
SET @ENTRY := 4675;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,0,1,100,0,10000,10000,10000,10000,11,1094,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hatefury Hellcaller - In Combat - Cast 1094 (Phase 1)"),
(@ENTRY,0,1,0,0,61,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Hellcaller - In Combat - Start Auto Attack (Phase 1)"),
(@ENTRY,0,2,3,0,1,100,0,2000,2000,20000,20000,11,5740,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hatefury Hellcaller - In Combat - Cast 5740 (Phase 1)"),
(@ENTRY,0,3,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Hellcaller - In Combat - Stop Auto Attack (Phase 1)"),
(@ENTRY,0,4,5,3,1,100,1,0,5,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Hellcaller - Between 0-5% Mana - Increment Event Phase (Phase 1)"),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Hellcaller - Between 0-5% Mana - Start Auto Attack (Phase 1)"),
(@ENTRY,0,6,7,2,1,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Hellcaller - Between 0-30% Health - Cast 8599 (Phase 1)"),
(@ENTRY,0,7,0,61,1,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hatefury Hellcaller - Between 0-30% Health - Say Line 0 (Phase 1)");

-- Texts for Hatefury Hellcaller
SET @ENTRY := 4675;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Hatefury Hellcaller");

-- Lady Sarevess SAI
SET @ENTRY := 4831;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sarevess - On Aggro - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sarevess - Between 5-30 Range - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,9,0,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Between 25-80 Range - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Between 25-80 Range - Start Auto Attack (Normal Dungeon)"),
(@ENTRY,0,8,9,9,0,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Between 0-5 Range - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,9,10,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Between 0-5 Range - Set Sheath Melee (Normal Dungeon)"),
(@ENTRY,0,10,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Between 0-5 Range - Start Auto Attack (Normal Dungeon)"),
(@ENTRY,0,11,12,9,0,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,12,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - Between 5-15 Range - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,9000,12000,12000,15000,11,8435,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sarevess - In Combat - Cast 8435 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,2,6000,8500,9000,13000,11,865,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - In Combat - Cast 865 (Normal Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,7000,9000,9000,13000,11,246,33,0,0,0,0,6,0,0,0,0,0,0,0,"Lady Sarevess - In Combat - Cast 246 (Normal Dungeon)"),
(@ENTRY,0,16,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - On Evade - Set Sheath Melee (Normal Dungeon)"),
(@ENTRY,0,17,0,6,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sarevess - On Death - Say Line 1 (Normal Dungeon)");

-- Texts for Lady Sarevess
SET @ENTRY := 4831;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You should not be here! Slay them!",14,0,100,0,0,5799,"Lady Sarevess"),
(@ENTRY,1,0,"Hearty Kill!",14,0,100,0,0,5801,"Lady Sarevess");

-- Grimlok SAI
SET @ENTRY := 4854;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Out Of Combat - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimlok - On Aggro - Cast 9532 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,2,100,2,0,40,2400,3800,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimlok - Between 0-40 Range - Cast 9532 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,11,0,0,0,100,2,8000,12000,21000,31000,11,8292,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimlok - In Combat - Cast 8292 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,3,5000,7000,0,0,11,8143,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - In Combat - Cast 8143 (Normal Dungeon)"),
(@ENTRY,0,13,0,2,0,100,2,0,50,25000,35000,11,11892,33,0,0,0,0,5,0,0,0,0,0,0,0,"Grimlok - Between 0-50% Health - Cast 11892 (Normal Dungeon)"),
(@ENTRY,0,14,0,2,0,100,3,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 0-30% Health - Cast 6742 (Normal Dungeon)"),
(@ENTRY,0,15,16,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,16,17,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,17,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Grimlok - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,18,0,5,0,100,3,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimlok - On Killed Unit - Say Line 2 (Normal Dungeon)");

-- Texts for Grimlok
SET @ENTRY := 4854;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Me %s, king!",14,0,100,0,0,5853,"Grimlok"),
(@ENTRY,2,0,"Die! Die!",14,0,100,0,0,5854,"Grimlok");

-- Shade of Eranikus SAI
SET @ENTRY := 5709;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of Eranikus - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,38,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of Eranikus - On Aggro - Set In Combat With Zone (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7200,13300,16900,32100,11,12891,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shade of Eranikus - In Combat - Cast 12891 (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,2,0,5,7300,19200,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of Eranikus - Between 0-5 Range - Cast 3391 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,14300,14300,28800,39200,11,12890,1,0,0,0,0,2,0,0,0,0,0,0,0,"Shade of Eranikus - In Combat - Cast 12890 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,2,17000,20000,18000,22000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of Eranikus - In Combat - Cast 11876 (Normal Dungeon)");

-- Texts for Shade of Eranikus
SET @ENTRY := 5709;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"This evil cannot be allowed to enter this world!  Come my children!",14,0,100,0,0,0,"Shade of Eranikus");

-- Dark Iron Rifleman SAI
SET @ENTRY := 6523;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Iron Rifleman - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Rifleman - On Aggro - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,2,100,0,5,30,2300,5000,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,13,0,0,0,100,0,16100,16100,20100,32200,11,7891,3,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Iron Rifleman - In Combat - Cast 7891"),
(@ENTRY,0,14,15,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,17,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - On Evade - Set Sheath Melee");

-- Texts for Dark Iron Rifleman
SET @ENTRY := 6523;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Never cross a Dark Iron, $c.",12,0,100,0,0,0,"Dark Iron Rifleman"),
(@ENTRY,0,1,"Time to die, $c!",12,0,100,0,0,0,"Dark Iron Rifleman"),
(@ENTRY,0,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,"Dark Iron Rifleman");

-- Eversong Ranger SAI fix
UPDATE `smart_scripts` SET `event_phase_mask`=2 WHERE `entryorguid`=15938 AND `id` BETWEEN 4 AND 10;

-- Withered Spearhide SAI
SET @ENTRY := 7332;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Out Of Combat - Stop Auto Attack (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Spearhide - On Aggro - Cast 6660 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,2,100,2,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Spearhide - Between 5-30 Range - Cast 6660 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,7,9,2,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 25-80 Range - Start Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,9,9,2,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,10,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-5 Range - Set Sheath Melee (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-5 Range - Start Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,12,9,2,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,12,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 5-15 Range - Stop Auto Attack (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,13,14,0,0,100,2,8000,12000,6000,17000,11,11397,1,0,0,0,0,5,0,0,0,0,0,0,0,"Withered Spearhide - In Combat - Cast 11397 (Normal Dungeon)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - In Combat - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,15,16,2,0,100,2,0,30,120000,120000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-30% Health - Cast 8599 (Normal Dungeon)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-30% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,17,18,2,0,100,3,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-15% Health - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Withered Spearhide - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,20,0,7,0,100,3,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Withered Spearhide - On Evade - Set Sheath Melee (Normal Dungeon)");

-- Texts for Withered Spearhide
SET @ENTRY := 7332;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Withered Spearhide");

-- Mordresh Fire Eye SAI
SET @ENTRY := 7357;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mordresh Fire Eye - On Aggro - Cast 12466 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,2,100,2,0,40,2400,3800,11,12466,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mordresh Fire Eye - Between 0-40 Range - Cast 12466 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,3,4,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,11,0,0,0,100,2,8000,12000,11000,16000,11,12470,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - In Combat - Cast 12470 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,30000,40000,30000,40000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mordresh Fire Eye - In Combat - Say Line 1 (Normal Dungeon)");

-- Texts for Mordresh Fire Eye
SET @ENTRY := 7357;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Slay them, my brethren! For the Scourge!",14,0,100,0,0,5822,"Mordresh Fire Eye"),
(@ENTRY,1,0,"Soon, the Scourge will rule the world!",14,0,100,0,0,5821,"Mordresh Fire Eye"),
(@ENTRY,1,1,"We will spread across this barren land!",14,0,100,0,0,5820,"Mordresh Fire Eye"),
(@ENTRY,1,2,"We will enslave the quilboar!",14,0,100,0,0,5819,"Mordresh Fire Eye");

-- Glutton SAI
SET @ENTRY := 8567;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,12627,0,0,0,0,0,1,0,0,0,0,0,0,0,"Glutton - Out Of Combat - Cast 12627 (Normal Dungeon)"),
(@ENTRY,0,1,2,2,0,100,3,0,50,0,0,11,12795,1,0,0,0,0,1,0,0,0,0,0,0,0,"Glutton - Between 0-50% Health - Cast 12795 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Glutton - Between 0-50% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,3,4,2,0,100,3,0,15,0,0,11,12795,1,0,0,0,0,1,0,0,0,0,0,0,0,"Glutton - Between 0-15% Health - Cast 12795 (Normal Dungeon)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Glutton - Between 0-15% Health - Say Line 1 (Normal Dungeon)");

-- Texts for Glutton
SET @ENTRY := 8567;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s is getting hungry!",16,0,100,0,0,0,"Glutton"),
(@ENTRY,1,0,"%s is getting VERY hungry!",16,0,100,0,0,0,"Glutton");

-- Atal'alarion SAI
SET @ENTRY := 8580;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'alarion - On Respawn - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,100,3,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'alarion - On Aggro - Say Line 1 (Normal Dungeon)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,34,1,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'alarion - On Aggro - Set Instance Data Field To 1 To Data 1 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,10700,14900,21600,41600,11,12887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Atal'alarion - In Combat - Cast 12887 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,9700,18900,20500,32200,11,6524,1,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'alarion - In Combat - Cast 6524 (Normal Dungeon)"),
(@ENTRY,0,5,0,6,0,100,3,0,0,0,0,34,1,3,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'alarion - On Death - Set Instance Data Field To 1 To Data 3 (Normal Dungeon)"),
(@ENTRY,0,6,0,7,0,100,3,0,0,0,0,34,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Atal'alarion - On Evade - Set Instance Data Field To 1 To Data 0 (Normal Dungeon)");

-- Texts for Atal'alarion
SET @ENTRY := 8580;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"So or'manley fi siame Dim fus siame yudo",14,14,100,0,0,5859,"Atal\'alarion"),
(@ENTRY,1,0,"You will rest with the honored dead.",12,0,100,0,0,0,"Atal\'alarion");

-- Marduk Blackpool SAI
SET @ENTRY := 10433;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,50,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marduk Blackpool - On Aggro - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,3,1000,1000,0,0,11,17695,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marduk Blackpool - Out Of Combat - Cast 17695 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,5300,8400,6200,14900,11,17228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marduk Blackpool - In Combat - Cast 17228 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,15400,17800,7500,22400,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marduk Blackpool - In Combat - Cast 15284 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,14600,15900,1000,8800,11,12040,33,0,0,0,0,1,0,0,0,0,0,0,0,"Marduk Blackpool - In Combat - Cast 12040 (Normal Dungeon)");

-- Texts for Marduk Blackpool
SET @ENTRY := 10433;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"We are betrayed!",12,0,100,0,0,0,"Marduk Blackpool");

-- Summoned Blackhand Dreadweaver SAI
SET @ENTRY := 10680;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Out Of Combat - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - On Aggro - Cast 12739 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - On Aggro - Set Event Phase 6 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,2,100,2,0,0,2400,6400,11,12739,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - In Combat - Cast 12739 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,22,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 0-15% Mana - Set Event Phase 5 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,2,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 25-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,2,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,3,4,100,2,30,100,100,100,22,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 30-100% Mana - Set Event Phase 6 (Normal Dungeon) (Phase 4)"),
(@ENTRY,0,10,0,0,0,100,2,14500,19200,27600,39600,11,7068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - In Combat - Cast 7068 (Normal Dungeon)"),
(@ENTRY,0,11,12,2,0,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 0-15% Health - Set Event Phase 3 (Normal Dungeon)"),
(@ENTRY,0,12,13,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 0-15% Health - Allow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,13,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 0-15% Health - Flee For Assist (Normal Dungeon)"),
(@ENTRY,0,14,0,1,0,100,2,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Out Of Combat - Die (Normal Dungeon)");

-- Texts for Summoned Blackhand Dreadweaver
SET @ENTRY := 10680;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s summons a Blackhand Dreadweaver to his aid!",16,0,100,0,0,0,"Summoned Blackhand Dreadweaver");

-- Gordok Ogre-Mage SAI
SET @ENTRY := 11443;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,2,4,0,10,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Say Line 0"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Cast 20823"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Increment Event Phase"),
(@ENTRY,0,4,0,9,2,100,0,0,40,2400,3800,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 0-40 Range - Cast 20823 (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 0-15% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 0-15% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,3,0,100,0,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Between 30-100% Mana - Decrement Event Phase"),
(@ENTRY,0,11,0,0,0,100,0,5000,12000,35000,45000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - In Combat - Cast 6742");

-- Texts for Gordok Ogre-Mage
SET @ENTRY := 11443;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,"Gordok Ogre-Mage"),
(@ENTRY,0,1,"Me smash! You die!",12,0,100,0,0,0,"Gordok Ogre-Mage"),
(@ENTRY,0,2,"I'll crush you!",12,0,100,0,0,0,"Gordok Ogre-Mage");

-- Gordok Mage-Lord SAI
SET @ENTRY := 11444;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,2,4,0,10,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Mage-Lord - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,11,15530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mage-Lord - On Aggro - Cast 15530 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,0,9,2,100,2,0,40,2400,3800,11,15530,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-40 Range - Cast 15530 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,6,3,2,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,9,2,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,100,2,7000,14000,12000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mage-Lord - In Combat - Cast 14145 (Normal Dungeon)"),
(@ENTRY,0,12,0,0,0,100,2,12000,17000,19000,25000,11,16102,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gordok Mage-Lord - In Combat - Cast 16102 (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,7000,9000,16000,20000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Gordok Mage-Lord - In Combat - Cast 13323 (Normal Dungeon)"),
(@ENTRY,0,14,15,2,0,100,3,0,30,0,0,11,16170,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-30% Health - Cast 16170 (Normal Dungeon)"),
(@ENTRY,0,15,0,61,0,100,0,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-30% Health - Say Line 1 (Normal Dungeon)");

-- Texts for Gordok Mage-Lord
SET @ENTRY := 11444;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,"Gordok Mage-Lord"),
(@ENTRY,0,1,"Me smash! You die!",12,0,100,0,0,0,"Gordok Mage-Lord"),
(@ENTRY,0,2,"I'll crush you!",12,0,100,0,0,0,"Gordok Mage-Lord"),
(@ENTRY,1,0,"%s becomes enraged!",16,0,100,0,0,0,"Gordok Mage-Lord");

-- Gordok Warlock SAI
SET @ENTRY := 11448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Out Of Combat - Disallow Combat Movement (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,2,1000,1000,1800000,1800000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Out Of Combat - Cast 13787 (Normal Dungeon)"),
(@ENTRY,0,2,0,1,0,100,3,3000,3000,0,0,11,22865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Out Of Combat - Cast 22865 (Normal Dungeon)"),
(@ENTRY,0,3,4,4,0,10,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Warlock - On Aggro - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Warlock - On Aggro - Cast 15232 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,6,0,9,2,100,2,0,40,2400,3800,11,15232,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Warlock - Between 0-40 Range - Cast 15232 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,8,3,2,100,3,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Between 0-15% Mana - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Between 0-15% Mana - Increment Event Phase (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,3,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Between 35-80 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,3,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Between 5-15 Range - Disallow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,11,0,9,2,100,3,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Between 0-5 Range - Allow Combat Movement (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,12,0,3,0,100,2,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Between 30-100% Mana - Decrement Event Phase (Normal Dungeon)"),
(@ENTRY,0,13,0,0,0,100,2,9000,15000,26000,30000,11,17883,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Warlock - In Combat - Cast 17883 (Normal Dungeon)"),
(@ENTRY,0,14,0,0,0,100,2,5000,9000,20000,25000,11,13338,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gordok Warlock - In Combat - Cast 13338 (Normal Dungeon)"),
(@ENTRY,0,15,0,0,0,100,2,7000,15000,20000,26000,11,8994,1,0,0,0,0,6,0,0,0,0,0,0,0,"Gordok Warlock - In Combat - Cast 8994 (Normal Dungeon)");

-- Texts for Gordok Warlock
SET @ENTRY := 11448;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Raaar!!! Me smash $r!",12,0,100,0,0,0,"Gordok Warlock"),
(@ENTRY,0,1,"Me smash! You die!",12,0,100,0,0,0,"Gordok Warlock"),
(@ENTRY,0,2,"I'll crush you!",12,0,100,0,0,0,"Gordok Warlock");

-- Horde Scout SAI
SET @ENTRY := 11680;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Out Of Combat - Stop Auto Attack"),
(@ENTRY,0,2,3,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Horde Scout - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Scout - On Aggro - Cast 6660"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,6,9,2,100,0,5,30,2300,3900,11,6660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Scout - Between 5-30 Range - Cast 6660 (Phase 2)"),
(@ENTRY,0,6,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,7,8,9,2,100,0,5,30,12000,15000,11,18545,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Scout - Between 5-30 Range - Cast 18545 (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 5-30 Range - Set Sheath Ranged (Phase 2)"),
(@ENTRY,0,9,10,9,2,100,0,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 25-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 25-80 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,11,11,9,2,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,12,12,61,2,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 0-5 Range - Set Sheath Melee (Phase 2)"),
(@ENTRY,0,13,0,61,2,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 0-5 Range - Start Auto Attack (Phase 2)"),
(@ENTRY,0,14,15,9,2,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,15,0,61,2,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 5-15 Range - Stop Auto Attack (Phase 2)"),
(@ENTRY,0,16,17,2,0,100,1,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 0-15% Health - Increment Event Phase"),
(@ENTRY,0,17,18,61,0,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - Between 0-15% Health - Allow Combat Movement"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Horde Scout - Between 0-15% Health - Flee For Assist"),
(@ENTRY,0,19,0,7,0,100,1,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - On Evade - Set Sheath Melee");

-- Texts for Horde Scout
SET @ENTRY := 11680;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Never cross a Dark Iron, $c.",12,0,100,0,0,0,"Horde Scout"),
(@ENTRY,0,1,"Time to die, $c!",12,0,100,0,0,0,"Horde Scout"),
(@ENTRY,0,2,"Feel the power of the Dark Iron Dwarves!",12,0,100,0,0,0,"Horde Scout");

-- Anubisath Defender SAI
SET @ENTRY := ;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,10000,10000,11,14297,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Cast 14297 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,10000,10000,11,23931,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Cast 23931 (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,10000,10000,11,24340,0,0,0,0,0,6,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Cast 24340 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,10000,10000,20000,20000,11,22997,0,0,0,0,0,6,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Cast 22997 (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,3,0,0,500,500,11,19595,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Cast 19595 (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,3,0,0,500,500,11,13022,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Cast 13022 (Normal Dungeon)"),
(@ENTRY,0,6,7,2,0,100,3,0,10,0,0,11,14204,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anubisath Defender - Between 0-10% Health - Cast 14204 (Normal Dungeon)"),
(@ENTRY,0,7,8,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anubisath Defender - Between 0-10% Health - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,11,25699,0,0,0,0,0,1,0,0,0,0,0,0,0,"Anubisath Defender - Between 0-10% Health - Cast 25699 (Normal Dungeon)"),
(@ENTRY,0,9,0,0,0,34,2,1000,1000,12000,12000,12,15343,1,60000,0,0,0,6,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Summon Creature Qiraji Swarmguard (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,34,2,1000,1000,12000,12000,12,15317,1,60000,0,0,0,6,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Summon Creature Qiraji Scorpion (Normal Dungeon)"),
(@ENTRY,0,11,0,0,0,34,2,1000,1000,12000,12000,12,15387,1,60000,0,0,0,6,0,0,0,0,0,0,0,"Anubisath Defender - In Combat - Summon Creature Qiraji Warrior (Normal Dungeon)");

-- Texts for Anubisath Defender
SET @ENTRY := ;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Anubisath Defender");

-- Surveyor Candress SAI
SET @ENTRY := 16522;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - Out Of Combat - Disallow Combat Movement"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - Out Of Combat - Set Event Phase 0"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - On Aggro - Say Line 0"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,11,9487,0,0,0,0,0,2,0,0,0,0,0,0,0,"Surveyor Candress - On Aggro - Cast 9487"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - On Aggro - Increment Event Phase"),
(@ENTRY,0,5,0,9,2,100,0,0,40,3400,4800,11,9487,0,0,0,0,0,2,0,0,0,0,0,0,0,"Surveyor Candress - Between 0-40 Range - Cast 9487 (Phase 2)"),
(@ENTRY,0,6,7,3,2,100,1,0,7,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - Between 0-7% Mana - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - Between 0-7% Mana - Increment Event Phase (Phase 2)"),
(@ENTRY,0,8,0,9,2,100,1,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - Between 35-80 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,1,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - Between 5-15 Range - Disallow Combat Movement (Phase 2)"),
(@ENTRY,0,10,0,9,2,100,1,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - Between 0-5 Range - Allow Combat Movement (Phase 2)"),
(@ENTRY,0,11,0,3,0,100,0,15,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Surveyor Candress - Between 15-100% Mana - Decrement Event Phase");

-- Texts for Surveyor Candress
SET @ENTRY := 16522;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"You'll not take me alive, scum!",12,0,100,0,0,0,"Surveyor Candress");

-- Murkblood Spearman SAI
SET @ENTRY := 17729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Out Of Combat - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,2,3,4,0,100,3,0,0,0,0,11,22887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Spearman - On Aggro - Cast 22887 (Normal Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - On Aggro - Increment Event Phase (Normal Dungeon)"),
(@ENTRY,0,4,5,9,0,100,2,5,30,2100,3500,11,22887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Spearman - Between 5-30 Range - Cast 22887 (Normal Dungeon)"),
(@ENTRY,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 5-30 Range - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,6,7,4,0,100,5,0,0,0,0,11,40317,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Spearman - On Aggro - Cast 40317 (Heroic Dungeon)"),
(@ENTRY,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - On Aggro - Increment Event Phase (Heroic Dungeon)"),
(@ENTRY,0,8,9,9,0,100,4,5,30,2100,3500,11,40317,0,0,0,0,0,2,0,0,0,0,0,0,0,"Murkblood Spearman - Between 5-30 Range - Cast 40317 (Heroic Dungeon)"),
(@ENTRY,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 5-30 Range - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,10,11,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 25-80 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,12,13,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 0-5 Range - Set Sheath Melee (Dungeon Only)"),
(@ENTRY,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 0-5 Range - Start Auto Attack (Dungeon Only)"),
(@ENTRY,0,15,16,9,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 5-15 Range - Stop Auto Attack (Dungeon Only)"),
(@ENTRY,0,17,18,0,0,100,2,8800,13600,8200,13300,11,31407,1,0,0,0,0,5,0,0,0,0,0,0,0,"Murkblood Spearman - In Combat - Cast 31407 (Normal Dungeon)"),
(@ENTRY,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - In Combat - Set Sheath Ranged (Normal Dungeon)"),
(@ENTRY,0,19,20,0,0,100,4,8800,13600,8200,13300,11,39413,1,0,0,0,0,5,0,0,0,0,0,0,0,"Murkblood Spearman - In Combat - Cast 39413 (Heroic Dungeon)"),
(@ENTRY,0,20,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - In Combat - Set Sheath Ranged (Heroic Dungeon)"),
(@ENTRY,0,21,22,2,0,100,7,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,22,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - Between 0-30% Health - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,23,0,7,0,100,7,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Spearman - On Evade - Set Sheath Melee (Dungeon Only)");

-- Texts for Murkblood Spearman
SET @ENTRY := 17729;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Murkblood Spearman");

-- Murkblood Healer SAI
SET @ENTRY := 17730;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,14,0,100,2,7000,40,16000,20000,11,29427,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murkblood Healer - On Friendly Unit At 7000 Health Within 40 Range - Cast 29427 (Normal Dungeon)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Healer - On Friendly Unit At 7000 Health Within 40 Range - Say Line 0 (Normal Dungeon)"),
(@ENTRY,0,2,3,14,0,100,4,14000,40,16000,20000,11,37979,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murkblood Healer - On Friendly Unit At 14000 Health Within 40 Range - Cast 37979 (Heroic Dungeon)"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Healer - On Friendly Unit At 14000 Health Within 40 Range - Say Line 0 (Heroic Dungeon)"),
(@ENTRY,0,4,0,14,0,100,2,6000,40,9000,9000,11,34423,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murkblood Healer - On Friendly Unit At 6000 Health Within 40 Range - Cast 34423 (Normal Dungeon)"),
(@ENTRY,0,5,0,14,0,100,4,12000,40,9000,9000,11,37978,0,0,0,0,0,7,0,0,0,0,0,0,0,"Murkblood Healer - On Friendly Unit At 12000 Health Within 40 Range - Cast 37978 (Heroic Dungeon)"),
(@ENTRY,0,6,0,2,0,100,2,0,80,15000,20000,11,15585,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Healer - Between 0-80% Health - Cast 15585 (Normal Dungeon)"),
(@ENTRY,0,7,0,2,0,100,4,0,80,15000,20000,11,35943,1,0,0,0,0,1,0,0,0,0,0,0,0,"Murkblood Healer - Between 0-80% Health - Cast 35943 (Heroic Dungeon)");

-- Texts for Murkblood Healer
SET @ENTRY := 17730;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s begins a massive heal!",16,0,100,0,0,0,"Murkblood Healer");

-- Lykul Wasp SAI
SET @ENTRY := 17732;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Wasp - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,11,32330,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lykul Wasp - On Aggro - Cast 32330 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Wasp - On Aggro - Increment Event Phase (Dungeon Only)"),
(@ENTRY,0,3,0,9,0,100,6,0,30,2400,4900,11,32330,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lykul Wasp - Between 0-30 Range - Cast 32330 (Dungeon Only)"),
(@ENTRY,0,4,0,9,0,100,7,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Wasp - Between 25-80 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,5,0,9,0,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Wasp - Between 5-15 Range - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,6,0,9,0,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Wasp - Between 0-5 Range - Allow Combat Movement (Dungeon Only)"),
(@ENTRY,0,7,8,2,0,100,7,0,30,0,0,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Wasp - Between 0-30% Health - Cast 8599 (Dungeon Only)"),
(@ENTRY,0,8,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lykul Wasp - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Lykul Wasp
SET @ENTRY := 17732;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,"Lykul Wasp");

-- Infinite Assassin SAI
SET @ENTRY := 17835;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Assassin - Out Of Combat - Cast 31326 (Dungeon Only)"),
(@ENTRY,0,1,2,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Assassin - On Aggro - Remove Aura 31326 (Dungeon Only)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,30,1,1,2,0,0,0,1,0,0,0,0,0,0,0,"Infinite Assassin - On Aggro - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,3,0,0,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,4,0,0,2,100,2,1200,11100,4500,15300,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 14873 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,5,0,0,2,100,4,500,7300,3500,14500,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 15667 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,0,2,100,2,1900,10100,10400,21600,11,14874,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 14874 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,0,2,100,4,1000,15800,10100,20500,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 15583 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,0,2,100,4,800,7800,12200,62800,11,30981,32,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 30981 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,0,0,100,6,1200,12400,20100,24900,11,30832,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 30832 (Dungeon Only)"),
(@ENTRY,0,10,0,0,0,100,4,1000,6500,12300,24200,11,38520,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - In Combat - Cast 38520 (Heroic Dungeon)"),
(@ENTRY,0,11,0,9,0,100,2,0,5,4800,7200,11,7159,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - Between 0-5 Range - Cast 7159 (Normal Dungeon)"),
(@ENTRY,0,12,0,9,0,100,4,0,5,4800,7200,11,15657,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Assassin - Between 0-5 Range - Cast 15657 (Heroic Dungeon)"),
(@ENTRY,0,13,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Assassin - On Evade - Cast 31326 (Dungeon Only)");

-- Texts for Infinite Assassin
SET @ENTRY := 17835;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"The wizard will fall!",12,0,100,0,0,0,"Infinite Assassin"),
(@ENTRY,0,1,"We will not be stopped!",12,0,100,0,0,0,"Infinite Assassin"),
(@ENTRY,0,2,"Your efforts... are in vain.",12,0,100,0,0,0,"Infinite Assassin");

-- Rift Lord SAI
SET @ENTRY := 17839;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,30,1,1,2,0,0,0,1,0,0,0,0,0,0,0,"Rift Lord - On Aggro - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Lord - In Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,2,0,0,2,90,6,5900,12000,6000,9600,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 16145 (Dungeon Only) (Phase 2)"),
(@ENTRY,0,3,0,0,2,90,2,5100,27600,10900,26600,11,36214,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 36214 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,4,0,0,2,90,4,5100,19100,11800,16900,11,38537,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 38537 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,5,0,0,0,100,2,4800,18800,18100,38500,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 11428 (Normal Dungeon)"),
(@ENTRY,0,6,0,0,0,100,4,6200,18800,13300,19100,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 11428 (Heroic Dungeon)"),
(@ENTRY,0,7,0,0,0,100,2,6100,18000,10800,15800,11,15708,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 15708 (Normal Dungeon)"),
(@ENTRY,0,8,0,0,0,100,4,4900,17700,10300,14500,11,35054,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 35054 (Heroic Dungeon)"),
(@ENTRY,0,9,0,0,0,90,2,7200,11800,15500,26500,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 9080 (Normal Dungeon)"),
(@ENTRY,0,10,0,0,0,90,4,4600,15700,11600,18100,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rift Lord - In Combat - Cast 9080 (Heroic Dungeon)"),
(@ENTRY,0,11,0,2,0,100,7,0,30,0,0,11,8269,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rift Lord - Between 0-30% Health - Cast 8269 (Dungeon Only)");

-- Texts for Rift Lord
SET @ENTRY := 17839;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Victory or death!",12,0,100,0,0,0,"Rift Lord"),
(@ENTRY,0,1,"You are running out of time!",12,0,100,0,0,0,"Rift Lord"),
(@ENTRY,0,2,"The rift must be protected!",12,0,100,0,0,0,"Rift Lord");

-- Infinite Chronomancer SAI
SET @ENTRY := 17892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Out Of Combat - Disallow Combat Movement (Dungeon Only)"),
(@ENTRY,0,1,0,1,0,100,7,1000,1000,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Out Of Combat - Cast 31326 (Dungeon Only)"),
(@ENTRY,0,2,0,0,0,20,7,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Say Line 0 (Dungeon Only)"),
(@ENTRY,0,3,0,4,0,100,7,0,0,0,0,28,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Remove Aura 31326 (Dungeon Only)"),
(@ENTRY,0,4,0,4,0,100,7,0,0,0,0,30,1,1,3,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Set Random Phase (Dungeon Only)"),
(@ENTRY,0,5,8,4,2,100,3,0,0,0,0,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Cast 15497 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,6,0,9,2,100,2,0,40,2900,5400,11,15497,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-40 Range - Cast 15497 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,7,0,61,2,100,3,0,0,0,0,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Cast 12675 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,8,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,9,0,9,2,100,4,0,40,2900,5400,11,12675,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-40 Range - Cast 12675 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,10,11,3,2,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,11,0,61,2,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 2)"),
(@ENTRY,0,12,0,9,2,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,13,0,9,2,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,14,0,9,2,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 2)"),
(@ENTRY,0,15,0,0,2,100,2,3700,12900,33800,39800,11,15063,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 15063 (Normal Dungeon) (Phase 2)"),
(@ENTRY,0,16,0,0,2,100,4,3600,8300,22200,25700,11,15531,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 15531 (Heroic Dungeon) (Phase 2)"),
(@ENTRY,0,17,0,3,4,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 30-100% Mana - Decrement Event Phase (Dungeon Only) (Phase 4)"),
(@ENTRY,0,18,21,4,8,100,3,0,0,0,0,11,15124,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Cast 15124 (Normal Dungeon) (Phase 8)"),
(@ENTRY,0,19,0,9,8,100,2,0,40,2900,5400,11,15124,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-40 Range - Cast 15124 (Normal Dungeon) (Phase 8)"),
(@ENTRY,0,20,0,61,8,100,0,0,0,0,0,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Cast 15230 (Heroic Dungeon) (Phase 8)"),
(@ENTRY,0,21,0,61,8,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Aggro - Increment Event Phase (Heroic Dungeon) (Phase 8)"),
(@ENTRY,0,22,0,9,8,100,4,0,40,1200,3400,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-40 Range - Cast 15230 (Heroic Dungeon) (Phase 8)"),
(@ENTRY,0,23,24,3,8,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-15% Mana - Allow Combat Movement (Dungeon Only) (Phase 8)"),
(@ENTRY,0,24,0,61,8,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-15% Mana - Increment Event Phase (Dungeon Only) (Phase 8)"),
(@ENTRY,0,25,0,9,8,100,7,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 35-80 Range - Allow Combat Movement (Dungeon Only) (Phase 8)"),
(@ENTRY,0,26,0,9,8,100,7,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 5-15 Range - Disallow Combat Movement (Dungeon Only) (Phase 8)"),
(@ENTRY,0,27,0,9,8,100,7,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 0-5 Range - Allow Combat Movement (Dungeon Only) (Phase 8)"),
(@ENTRY,0,28,0,0,8,100,2,8600,18200,9500,10100,11,33860,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 33860 (Normal Dungeon) (Phase 8)"),
(@ENTRY,0,29,0,0,8,100,2,8600,18200,8000,10100,11,33623,1,0,0,0,0,2,0,0,0,0,0,0,0,"Infinite Chronomancer - In Combat - Cast 33623 (Normal Dungeon) (Phase 8)"),
(@ENTRY,0,30,0,3,0,100,6,30,100,100,100,23,0,1,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - Between 30-100% Mana - Decrement Event Phase (Dungeon Only)"),
(@ENTRY,0,31,0,7,0,100,7,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Evade - Set Event Phase 0 (Dungeon Only)"),
(@ENTRY,0,32,0,7,0,100,7,0,0,0,0,11,31326,0,0,0,0,0,1,0,0,0,0,0,0,0,"Infinite Chronomancer - On Evade - Cast 31326 (Dungeon Only)");

-- Texts for Infinite Chronomancer
SET @ENTRY := 17892;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"We are not finished!",12,0,100,0,0,0,"Infinite Chronomancer"),
(@ENTRY,0,1,"Death to the Last Guardian!",12,0,100,0,0,0,"Infinite Chronomancer"),
(@ENTRY,0,2,"We will not fail!",12,0,100,0,0,0,"Infinite Chronomancer");

-- Captain Arathyn SAI
SET @ENTRY := 19635;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1000,1000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - OOC - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,1,6000,6000,6000,6000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - OOC - Say Line 1"),
(@ENTRY,0,2,0,1,0,100,1,10000,10000,10000,10000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - OOC - Say Line 2"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,35882,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - On Aggro - Summon Azurebeak"),
(@ENTRY,0,4,0,9,0,100,0,0,5,7000,10000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Arathyn - In Combat - Cast Whirlwind");

-- Texts for Captain Arathyn
SET @ENTRY := 19635;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"I love the smell of nether in the morning.",12,0,100,1,0,0,"Captain Arathyn"),
(@ENTRY,1,0,"It smells like...",12,0,100,1,0,0,"Captain Arathyn"),
(@ENTRY,2,0,"...victory.",12,0,100,15,0,0,"Captain Arathyn");
