-- Stormforged Soldier SAI
SET @ENTRY := 30136;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,9000,12000,11,56621,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Soldier - In Combat - Cast 56621"),
(@ENTRY,0,1,0,0,0,100,0,3000,8000,9000,12000,11,56622,2,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Soldier - In Combat - Cast 56622");

-- The Iron Watcher SAI
SET @ENTRY := 30142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,11000,17000,11,60925,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Iron Watcher - In Combat - Cast 60925");

-- Garhal SAI
SET @ENTRY := 30147;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,5000,9000,11,50306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Garhal - Between 0-5 Range - Cast 50306");

-- Stormforged Warmonger SAI
SET @ENTRY := 30060;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,32000,36000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Warmonger - In Combat - Cast 52701"),
(@ENTRY,0,1,0,9,0,100,0,0,5,14000,18000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Warmonger - Between 0-5 Range - Cast 51876");

-- Stormforged Decimator SAI
SET @ENTRY := 30063;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,15000,19000,11,56352,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Decimator - In Combat - Cast 56352"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,18000,22000,11,35238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Decimator - In Combat - Cast 35238");

-- Iron Behemoth SAI
SET @ENTRY := 30064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,15000,20000,26000,11,56062,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Behemoth - In Combat - Cast 56062"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,11,56062,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Behemoth - Between 0-15% Health - Cast 56062"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,11,56061,0,0,0,0,0,1,0,0,0,0,0,0,0,"Iron Behemoth - Between 0-15% Health - Cast 56061");

-- Icebound Revenant SAI
SET @ENTRY := 30053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,15000,14000,20000,11,55216,0,0,0,0,0,5,0,0,0,0,0,0,0,"Icebound Revenant - In Combat - Cast 55216");

-- Warsmith Sigfinna SAI
SET @ENTRY := 30006;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,35,25000,28000,11,35570,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsmith Sigfinna - Between 5-35 Range - Cast 35570");

-- Earthen Elite SAI
SET @ENTRY := 29980;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,11000,17000,11,55715,0,0,0,0,0,5,0,0,0,0,0,0,0,"Earthen Elite - In Combat - Cast 55715");

-- Earthen Warder SAI
SET @ENTRY := 29981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,12000,11,55704,0,0,0,0,0,2,0,0,0,0,0,0,0,"Earthen Warder - Between 0-30 Range - Cast 55704");

-- Iron Sentinel SAI
SET @ENTRY := 29984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,5000,12000,18000,11,5568,0,0,0,0,0,5,0,0,0,0,0,0,0,"Iron Sentinel - In Combat - Cast 5568"),
(@ENTRY,0,1,0,0,0,100,0,7000,12000,12000,15000,11,56490,0,0,0,0,0,2,0,0,0,0,0,0,0,"Iron Sentinel - In Combat - Cast 56490");

-- Snorts SAI
SET @ENTRY := 29996;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,3385,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snorts - On Aggro - Cast 3385");

-- Tunka'lo Brave SAI
SET @ENTRY := 29973;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,15000,11,52058,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tunka'lo Brave - In Combat - Cast 52058");

-- Warsong Hold Grunt SAI
SET @ENTRY := 29942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,5000,8000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Hold Grunt - In Combat - Cast 19643"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,9000,11,15618,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Hold Grunt - Between 0-5 Range - Cast 15618");

-- Stormcrest Eagle SAI
SET @ENTRY := 29854;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,4000,7000,11,43517,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormcrest Eagle - In Combat - Cast 43517");

-- Stormforged Monitor SAI
SET @ENTRY := 29862;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,30000,40000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Monitor - In Combat - Cast 52701"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,15000,18000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Monitor - In Combat - Cast 57580");

-- Icemane Yeti SAI
SET @ENTRY := 29875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,9000,15000,11,56402,0,0,0,0,0,2,0,0,0,0,0,0,0,"Icemane Yeti - In Combat - Cast 56402");

-- Stormforged Loreseeker SAI
SET @ENTRY := 29843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,20000,40000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Loreseeker - In Combat - Cast 12550"),
(@ENTRY,0,1,0,0,0,100,0,4000,7000,6000,12000,11,61561,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Loreseeker - In Combat - Cast 61561");

-- Icebound Revenant SAI
SET @ENTRY := 29844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,9000,15000,11,55216,0,0,0,0,0,5,0,0,0,0,0,0,0,"Icebound Revenant - In Combat - Cast 55216");

-- Frostfeather Screecher SAI
SET @ENTRY := 29792;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,4000,7000,11,57815,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frostfeather Screecher - In Combat - Cast 57815");

-- Frostfeather Witch SAI
SET @ENTRY := 29793;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,5000,7000,11,51877,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frostfeather Witch - In Combat - Cast 51877");

-- Sirana Iceshriek SAI
SET @ENTRY := 29794;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,61223,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sirana Iceshriek - In Combat - Cast 61223"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,9000,13000,11,61211,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sirana Iceshriek - In Combat - Cast 61211");

-- Stormcrest Hatchling SAI
SET @ENTRY := 29808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,4000,6000,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormcrest Hatchling - In Combat - Cast 55079");

-- Hyldsmeet Drakerider SAI
SET @ENTRY := 29694;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,5000,9000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hyldsmeet Drakerider - In Combat - Cast 32736");

-- Stormforged Pursuer SAI
SET @ENTRY := 29696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,30,7000,11000,11,55007,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Pursuer - Between 5-30 Range - Cast 55007");

-- Drakuru Prophet SAI
SET @ENTRY := 29697;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,6000,120000,120000,11,50366,32,0,0,0,0,1,0,0,0,0,0,0,0,"Drakuru Prophet - In Combat - Cast 50366");

-- Stormpeak Hatchling SAI
SET @ENTRY := 29755;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,61554,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormpeak Hatchling - In Combat - Cast 61554");

-- Drakuru Blood Drinker SAI
SET @ENTRY := 29654;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,10000,20000,30000,11,37838,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakuru Blood Drinker - In Combat - Cast 37838");

-- Drakuru Berserker SAI
SET @ENTRY := 29656;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,20000,30000,11,54959,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakuru Berserker - In Combat - Cast 54959");

-- Ragemane SAI
SET @ENTRY := 29664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,51492,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragemane - On Aggro - Cast 51492"),
(@ENTRY,0,1,0,0,0,100,0,7000,15000,15000,21000,11,50169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ragemane - In Combat - Cast 50169"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,50420,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ragemane - Between 0-30% Health - Cast 50420");

-- Serpent Defender SAI
SET @ENTRY := 29693;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,10000,11,34811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Serpent Defender - Between 0-5 Range - Cast 34811");

-- Savage Hill Brute SAI
SET @ENTRY := 29623;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,20000,26000,11,54678,0,0,0,0,0,1,0,0,0,0,0,0,0,"Savage Hill Brute - In Combat - Cast 54678");

-- Stormrider SAI
SET @ENTRY := 29624;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,9000,12000,11,12549,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormrider - In Combat - Cast 12549"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,18000,11,51876,1,0,0,0,0,2,0,0,0,0,0,0,0,"Stormrider - In Combat - Cast 51876");

-- Tormar Frostgut SAI
SET @ENTRY := 29626;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,12000,15000,11,50410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tormar Frostgut - In Combat - Cast 50410"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,15000,18000,11,11876,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormar Frostgut - In Combat - Cast 11876");

-- Banshee Soulclaimer SAI
SET @ENTRY := 29646;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,5000,15000,11,28993,0,0,0,0,0,2,0,0,0,0,0,0,0,"Banshee Soulclaimer - In Combat - Cast 28993");

-- Snowblind Devotee SAI
SET @ENTRY := 29554;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 56410");

-- Valkyrion Aspirant SAI
SET @ENTRY := 29569;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,140000,11,57524,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valkyrion Aspirant - Between 0-30% Health - Cast 57524");

-- Nascent Val'kyr SAI
SET @ENTRY := 29570;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,12000,12000,15000,11,57547,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nascent Val'kyr - In Combat - Cast 57547"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,4000,6000,11,60991,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nascent Val'kyr - In Combat - Cast 60991");

-- Stormforged Pillager SAI
SET @ENTRY := 29586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,35000,42000,11,52701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Pillager - In Combat - Cast 52701");

-- Yorg Stormheart SAI
SET @ENTRY := 29593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,18000,23000,11,19135,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yorg Stormheart - In Combat - Cast 19135");

-- Brunnhildar Warmaiden SAI
SET @ENTRY := 29498;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,7000,10000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brunnhildar Warmaiden - In Combat - Cast 15496");

-- Fjorn SAI
SET @ENTRY := 29503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,11000,9000,23000,11,57801,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fjorn - In Combat - Cast 57801"),
(@ENTRY,0,1,0,0,0,100,0,12000,15000,30000,35000,11,55512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fjorn - In Combat - Cast 55512");

-- Seething Revenant SAI
SET @ENTRY := 29504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,9000,12000,11,56620,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seething Revenant - In Combat - Cast 56620");

-- Overseer Syra SAI
SET @ENTRY := 29518;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,12000,15000,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Syra - In Combat - Cast 6253"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,9000,12000,11,49807,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Syra - In Combat - Cast 49807");

-- Garm Watcher SAI
SET @ENTRY := 29553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,35,25000,28000,11,50413,0,0,0,0,0,1,0,0,0,0,0,0,0,"Garm Watcher - Between 5-35 Range - Cast 50413");

-- Crystalweb Spitter SAI
SET @ENTRY := 29412;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,57616,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crystalweb Spitter - In Combat - Cast 57616"),
(@ENTRY,0,1,0,9,0,100,0,0,30,12000,17000,11,12023,1,0,0,0,0,5,0,0,0,0,0,0,0,"Crystalweb Spitter - Between 0-30 Range - Cast 12023");

-- Snowblind Digger SAI
SET @ENTRY := 29413;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,7000,11000,11,50370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Digger - In Combat - Cast 50370"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,7000,12000,11,48374,1,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Digger - In Combat - Cast 48374");

-- Hyldnir Overseer SAI
SET @ENTRY := 29426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,11000,16000,11,30931,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hyldnir Overseer - In Combat - Cast 30931"),
(@ENTRY,0,1,0,8,0,100,0,0,5,6000,9000,11,46182,1,0,0,0,0,2,0,0,0,0,0,0,0,"Hyldnir Overseer - On Spellhit By School 5 - Cast 46182");

-- Icetip Crawler SAI
SET @ENTRY := 29461;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,7000,10000,11,57617,0,0,0,0,0,5,0,0,0,0,0,0,0,"Icetip Crawler - In Combat - Cast 57617");

-- Ice Steppe Rhino SAI
SET @ENTRY := 29469;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,35,25000,30000,11,55193,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ice Steppe Rhino - Between 5-35 Range - Cast 55193");

-- Snowblind Devotee SAI
SET @ENTRY := 29407;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,120000,130000,11,56410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Snowblind Devotee - Between 0-30% Health - Cast 56410");

-- Garm Watcher SAI
SET @ENTRY := 29409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,50413,0,0,0,0,0,1,0,0,0,0,0,0,0,"Garm Watcher - On Aggro - Cast 50413");

-- Crystalweb Weaver SAI
SET @ENTRY := 29411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,15000,11,47698,0,0,0,0,0,5,0,0,0,0,0,0,0,"Crystalweb Weaver - Between 0-30 Range - Cast 47698");

-- Stormforged Magus SAI
SET @ENTRY := 29374;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,605000,610000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - Out Of Combat - Cast 12550"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,35000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast 12550"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,16000,19000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast 32193");

-- Stormforged Artificer SAI
SET @ENTRY := 29376;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast 57580");

-- Stormforged War Golem SAI
SET @ENTRY := 29380;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,15000,19000,11,56352,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged War Golem - In Combat - Cast 56352");

-- Stormforged Reaver SAI
SET @ENTRY := 29382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,10,7000,15000,11,55825,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Reaver - Between 0-10 Range - Cast 55825");

-- Stormforged Taskmaster SAI
SET @ENTRY := 29369;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,35000,50000,11,52701,1,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 52701"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,15000,18000,11,51876,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stormforged Taskmaster - In Combat - Cast 51876"),
(@ENTRY,0,2,0,5,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Taskmaster - On Killed Unit - Say Line 0");

-- Texts for Stormforged Taskmaster
SET @ENTRY := 29369;
DELETE FROM creature_ai_texts WHERE entry IN (-739);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Your mother was a wench and your father smelt of seaforium!",12,0,100,0,0,0,"Stormforged Taskmaster");

-- Stormforged Champion SAI
SET @ENTRY := 29370;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,35000,50000,11,52701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Champion - In Combat - Cast 52701");

-- Gundrak Bat Rider SAI
SET @ENTRY := 29332;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gundrak Bat Rider - On Aggro - Dismount"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,43,0,9074,0,0,0,0,1,0,0,0,0,0,0,0,"Gundrak Bat Rider - On Evade - Mount Up Model 9074"),
(@ENTRY,0,2,0,0,0,100,0,3000,7000,14000,26000,11,54684,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gundrak Bat Rider - In Combat - Cast 54684");

-- Gundrak Raptor SAI
SET @ENTRY := 29334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,8000,18000,11,54487,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gundrak Raptor - In Combat - Cast 54487");

-- Anub'ar Webspinner SAI
SET @ENTRY := 29335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,54290,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Webspinner - In Combat - Cast 54290 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59362,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Webspinner - In Combat - Cast 59362 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,6,10000,13000,19000,22000,11,52086,1,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Webspinner - In Combat - Cast 52086 (Dungeon Only)");

-- Torseg the Exiled SAI
SET @ENTRY := 29350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,12000,16000,11,33707,0,0,0,0,0,2,0,0,0,0,0,0,0,"Torseg the Exiled - In Combat - Cast 33707"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,16000,20000,11,53437,1,0,0,0,0,1,0,0,0,0,0,0,0,"Torseg the Exiled - In Combat - Cast 53437");

-- Gundrak Savage SAI
SET @ENTRY := 29235;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,8000,20000,30000,11,5515,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gundrak Savage - In Combat - Cast 5515");

-- Gundrak Brute SAI
SET @ENTRY := 29236;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,20000,30000,11,54678,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gundrak Brute - In Combat - Cast 54678");

-- Gundrak Fire-eater SAI
SET @ENTRY := 29237;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,14000,28000,11,54682,9,0,0,0,0,2,0,0,0,0,0,0,0,"Gundrak Fire-eater - In Combat - Cast 54682");

-- Sifreldar Storm Maiden SAI
SET @ENTRY := 29323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,16000,21000,11,57408,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sifreldar Storm Maiden - On Aggro - Cast 57408");

-- Disturbed Soul SAI
SET @ENTRY := 29133;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,8000,8000,12000,11,51818,0,0,0,0,0,2,0,0,0,0,0,0,0,"Disturbed Soul - In Combat - Cast 51818");

-- Vekgar SAI
SET @ENTRY := 29146;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,1,5,30,9000,12000,11,54487,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vekgar - Between 5-30 Range - Cast 54487"),
(@ENTRY,0,1,0,2,0,100,0,0,30,10000,13000,11,52071,1,0,0,0,0,1,0,0,0,0,0,0,0,"Vekgar - Between 0-30% Health - Cast 52071");

-- Anub'ar Champion SAI
SET @ENTRY := 29117;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,9000,17000,32000,11,53317,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Champion - In Combat - Cast 53317 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,15000,18000,11,59343,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Champion - In Combat - Cast 59343 (Heroic Dungeon)"),
(@ENTRY,0,2,0,13,0,100,2,14000,17000,0,0,11,53394,1,0,0,0,0,7,0,0,0,0,0,0,0,"Anub'ar Champion - On Target Casting - Cast 53394 (Normal Dungeon)"),
(@ENTRY,0,3,0,13,0,100,4,9000,12000,0,0,11,59344,1,0,0,0,0,7,0,0,0,0,0,0,0,"Anub'ar Champion - On Target Casting - Cast 59344 (Heroic Dungeon)");

-- Anub'ar Crypt Fiend SAI
SET @ENTRY := 29118;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,53330,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 53330 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59348,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 59348 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,13000,17000,11,53322,1,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 53322 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,10000,13000,11,59347,1,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 59347 (Heroic Dungeon)");

-- Monstrous Wight SAI
SET @ENTRY := 29123;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,9000,12000,11,51334,0,0,0,0,0,2,0,0,0,0,0,0,0,"Monstrous Wight - In Combat - Cast 51334");

-- Lifeblood Elemental SAI
SET @ENTRY := 29124;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,12000,18000,11,54790,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lifeblood Elemental - In Combat - Cast 54790");

-- Bloodmoon Servant SAI
SET @ENTRY := 29082;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,30,12000,16000,11,32714,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodmoon Servant - Between 0-30% Health - Cast 32714");

-- Anub'ar Champion SAI
SET @ENTRY := 29096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,9000,17000,32000,11,53317,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Champion - In Combat - Cast 53317 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,15000,18000,11,59343,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Champion - In Combat - Cast 59343 (Heroic Dungeon)"),
(@ENTRY,0,2,0,13,0,100,2,14000,17000,0,0,11,53394,1,0,0,0,0,7,0,0,0,0,0,0,0,"Anub'ar Champion - On Target Casting - Cast 53394 (Normal Dungeon)"),
(@ENTRY,0,3,0,13,0,100,4,9000,12000,0,0,11,59344,1,0,0,0,0,7,0,0,0,0,0,0,0,"Anub'ar Champion - On Target Casting - Cast 59344 (Heroic Dungeon)");

-- Anub'ar Crypt Fiend SAI
SET @ENTRY := 29097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,53330,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 53330 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59348,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 59348 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,13000,17000,11,53322,1,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 53322 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,10000,13000,11,59347,1,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 59347 (Heroic Dungeon)");

-- Perch Guardian SAI
SET @ENTRY := 29013;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,9000,15000,11,52702,0,0,0,0,0,2,0,0,0,0,0,0,0,"Perch Guardian - In Combat - Cast 52702");

-- Servant of Freya SAI
SET @ENTRY := 29036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,35000,48000,11,55067,0,0,0,0,0,1,0,0,0,0,0,0,0,"Servant of Freya - In Combat - Cast 55067");

-- Goretalon Matriarch SAI
SET @ENTRY := 29044;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,5000,7000,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goretalon Matriarch - In Combat - Cast 55079"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,10000,13000,11,49865,1,0,0,0,0,2,0,0,0,0,0,0,0,"Goretalon Matriarch - In Combat - Cast 49865"),
(@ENTRY,0,2,0,0,0,100,0,9000,12000,15000,20000,11,51946,1,0,0,0,0,1,0,0,0,0,0,0,0,"Goretalon Matriarch - In Combat - Cast 51946");

-- Anub'ar Champion SAI
SET @ENTRY := 29062;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,6000,9000,17000,32000,11,53317,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Champion - In Combat - Cast 53317 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,15000,18000,11,59343,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Champion - In Combat - Cast 59343 (Heroic Dungeon)"),
(@ENTRY,0,2,0,13,0,100,2,14000,17000,0,0,11,53394,1,0,0,0,0,7,0,0,0,0,0,0,0,"Anub'ar Champion - On Target Casting - Cast 53394 (Normal Dungeon)"),
(@ENTRY,0,3,0,13,0,100,4,9000,12000,0,0,11,59344,1,0,0,0,0,7,0,0,0,0,0,0,0,"Anub'ar Champion - On Target Casting - Cast 59344 (Heroic Dungeon)");

-- Anub'ar Crypt Fiend SAI
SET @ENTRY := 29063;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,7000,9000,12000,11,53330,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 53330 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59348,32,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 59348 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,13000,17000,11,53322,1,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 53322 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,10000,13000,11,59347,1,0,0,0,0,5,0,0,0,0,0,0,0,"Anub'ar Crypt Fiend - In Combat - Cast 59347 (Heroic Dungeon)");

-- Overlook Sentry SAI
SET @ENTRY := 28840;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,10000,12000,16000,11,55030,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlook Sentry - In Combat - Cast 55030");

-- Prophet of Har'koa SAI
SET @ENTRY := 28848;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,15000,15000,11,52719,0,0,0,0,0,2,0,0,0,0,0,0,0,"Prophet of Har'koa - In Combat - Cast 52719");

-- Enchanted Tiki Warrior SAI
SET @ENTRY := 28882;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,54647,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enchanted Tiki Warrior - On Respawn - Cast 54647"),
(@ENTRY,0,1,0,0,0,100,0,9000,21000,12000,24000,11,54657,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enchanted Tiki Warrior - In Combat - Cast 54657");

-- Yara SAI
SET @ENTRY := 28917;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,48594,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yara - On Aggro - Cast 48594"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Yara - On Aggro - Say Line 0"),
(@ENTRY,0,2,0,0,0,100,0,6000,8000,10000,20000,11,14516,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yara - In Combat - Cast 14516"),
(@ENTRY,0,3,0,0,0,100,0,8000,16000,16000,24000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yara - In Combat - Cast 15618");

-- Texts for Yara
SET @ENTRY := 28917;
DELETE FROM creature_ai_texts WHERE entry IN (-476);
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Daddy!",12,0,100,0,0,0,"Yara");

-- Anub'ar Crusher SAI
SET @ENTRY := 28922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,9000,12000,18000,11,53318,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Crusher - In Combat - Cast 53318 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,7000,9000,12000,11,59346,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anub'ar Crusher - In Combat - Cast 59346 (Heroic Dungeon)"),
(@ENTRY,0,2,0,2,0,100,6,0,30,600000,600000,11,53801,1,0,0,0,0,1,0,0,0,0,0,0,0,"Anub'ar Crusher - Between 0-30% Health - Cast 53801 (Dungeon Only)");

-- Blood of Mam'toth SAI
SET @ENTRY := 28779;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,54582,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blood of Mam'toth - On Respawn - Cast 54582");

-- Guardian of Zim'Rhuk SAI
SET @ENTRY := 28597;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,10000,15000,15000,11,54565,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian of Zim'Rhuk - In Combat - Cast 54565");

-- Hardened Steel Berserker SAI
SET @ENTRY := 28579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,9000,14000,21000,11,52740,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Berserker - In Combat - Cast 52740 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,4000,9000,14000,18000,11,59259,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hardened Steel Berserker - In Combat - Cast 59259 (Heroic Dungeon)"),
(@ENTRY,0,2,0,2,0,100,7,0,30,0,0,11,61369,7,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Berserker - Between 0-30% Health - Cast 61369 (Dungeon Only)"),
(@ENTRY,0,3,0,2,0,100,7,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hardened Steel Berserker - Between 0-30% Health - Say Line 0 (Dungeon Only)");

-- Texts for Hardened Steel Berserker
SET @ENTRY := 28579;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Hardened Steel Berserker");

-- Cultist Saboteur SAI
SET @ENTRY := 28538;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,10000,15000,11,40062,0,0,0,0,0,5,0,0,0,0,0,0,0,"Cultist Saboteur - In Combat - Cast 40062");

-- Heb'Drakkar Striker SAI
SET @ENTRY := 28465;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heb'Drakkar Striker - On Aggro - Dismount"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,43,0,9074,0,0,0,0,1,0,0,0,0,0,0,0,"Heb'Drakkar Striker - On Evade - Mount Up Model 9074"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,16000,16000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Heb'Drakkar Striker - In Combat - Cast 11976"),
(@ENTRY,0,3,0,0,0,100,0,4000,14000,50000,60000,11,51951,32,0,0,0,0,2,0,0,0,0,0,0,0,"Heb'Drakkar Striker - In Combat - Cast 51951");

-- Broodmother Slivina SAI
SET @ENTRY := 28467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,5000,7000,11,51772,0,0,0,0,0,2,0,0,0,0,0,0,0,"Broodmother Slivina - In Combat - Cast 51772"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,12000,17000,11,51768,1,0,0,0,0,2,0,0,0,0,0,0,0,"Broodmother Slivina - In Combat - Cast 51768");

-- Squire Edwards SAI
SET @ENTRY := 28486;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,30000,30000,180000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Squire Edwards - Out Of Combat - Say Line 0"),
(@ENTRY,0,1,0,1,0,100,0,42000,42000,180000,180000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Squire Edwards - Out Of Combat - Say Line 1");

-- Texts for Squire Edwards
SET @ENTRY := 28486;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -726 AND -723;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"M-mistress... Might I brush your mighty steed?",12,0,100,0,0,0,"Squire Edwards"),
(@ENTRY,0,1,"M-mistress... may I p-polish your armor ...?",12,0,100,0,0,0,"Squire Edwards"),
(@ENTRY,0,2,"M-mistress... did you n-need more corpse dust, p-perhaps... ?",12,0,100,0,0,0,"Squire Edwards"),
(@ENTRY,1,0,"Yes, M-mistress...",12,0,100,0,0,0,"Squire Edwards");

-- Captive Footman SAI
SET @ENTRY := 28415;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captive Footman - On Respawn - Say Line 0");

-- Texts for Captive Footman
SET @ENTRY := 28415;
DELETE FROM creature_ai_texts WHERE entry BETWEEN -800 AND -798;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Ugh...",12,0,100,0,0,0,"Captive Footman"),
(@ENTRY,0,1,"I am in your debt, friend.",12,0,100,0,0,0,"Captive Footman"),
(@ENTRY,0,2,"I thought I was done for!",12,0,100,0,0,0,"Captive Footman");

-- Drakkari Bear Trapper SAI
SET @ENTRY := 28418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,61227,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Bear Trapper - On Aggro - Cast 61227"),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,10000,14000,11,38556,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drakkari Bear Trapper - In Combat - Cast 38556"),
(@ENTRY,0,2,0,0,0,100,0,4000,10000,20000,22000,11,53432,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drakkari Bear Trapper - In Combat - Cast 53432");

-- Thalgran Blightbringer SAI
SET @ENTRY := 28443;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,26047,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thalgran Blightbringer - Out Of Combat - Cast 26047"),
(@ENTRY,0,1,0,0,0,100,0,13000,19000,15000,25000,11,51854,0,0,0,0,0,5,0,0,0,0,0,0,0,"Thalgran Blightbringer - In Combat - Cast 51854"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,9000,17000,11,54210,1,0,0,0,0,5,0,0,0,0,0,0,0,"Thalgran Blightbringer - In Combat - Cast 54210");

-- Stratholme Resident SAI
SET @ENTRY := 28341;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,9000,12000,17000,11,52660,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stratholme Resident - In Combat - Cast 52660 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,5000,9000,12000,17000,11,58817,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stratholme Resident - In Combat - Cast 58817 (Heroic Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,9000,12000,15000,21000,11,52657,1,0,0,0,0,5,0,0,0,0,0,0,0,"Stratholme Resident - In Combat - Cast 52657 (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,4,9000,12000,15000,21000,11,58816,1,0,0,0,0,5,0,0,0,0,0,0,0,"Stratholme Resident - In Combat - Cast 58816 (Heroic Dungeon)");

-- Cultist Infiltrator SAI
SET @ENTRY := 28373;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,22000,30000,11,54962,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cultist Infiltrator - In Combat - Cast 54962");

-- Primordial Drake SAI
SET @ENTRY := 28378;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,52791,1,0,0,0,0,1,0,0,0,0,0,0,0,"Primordial Drake - Out Of Combat - Cast 52791"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,9000,12000,11,55071,0,0,0,0,0,2,0,0,0,0,0,0,0,"Primordial Drake - In Combat - Cast 55071");

-- Cursed Offspring of Har'koa SAI
SET @ENTRY := 28404;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,12000,8000,12000,11,54604,32,0,0,0,0,2,0,0,0,0,0,0,0,"Cursed Offspring of Har'koa - In Combat - Cast 54604"),
(@ENTRY,0,1,0,8,0,100,1,51895,-1,0,0,11,51891,7,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Offspring of Har'koa - On Spellhit By 51895 - Cast 51891"),
(@ENTRY,0,2,0,8,0,100,1,51895,-1,0,0,33,28526,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cursed Offspring of Har'koa - On Spellhit By 51895 - Quest Credit"),
(@ENTRY,0,3,0,8,0,100,1,51895,-1,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Offspring of Har'koa - On Spellhit By 51895 - Forced Despawn In 1000 Ms");

-- Mossy Rampager SAI
SET @ENTRY := 28323;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,8000,18000,18000,11,54475,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mossy Rampager - In Combat - Cast 54475");

-- Ravenous Mangal Crocolisk SAI
SET @ENTRY := 28325;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,9000,14000,11,34370,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ravenous Mangal Crocolisk - In Combat - Cast 34370");

-- Bile Golem SAI
SET @ENTRY := 28201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,12000,21000,27000,11,52527,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bile Golem - In Combat - Cast 52527 (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,4,5000,12000,21000,27000,11,58810,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bile Golem - In Combat - Cast 58810 (Heroic Dungeon)");

-- Hailscorn SAI
SET @ENTRY := 28208;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,5000,7000,11,3130,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hailscorn - In Combat - Cast 3130"),
(@ENTRY,0,1,0,0,0,100,0,9000,16000,18000,23000,11,51144,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hailscorn - In Combat - Cast 51144"),
(@ENTRY,0,2,0,0,0,100,0,14000,20000,75000,90000,11,51061,1,0,0,0,0,1,0,0,0,0,0,0,0,"Hailscorn - In Combat - Cast 51061");

-- Bythius the Flesh-Shaper SAI
SET @ENTRY := 28212;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,3000,0,0,12,28207,1,600000,0,0,0,2,0,0,0,0,0,0,0,"Bythius the Flesh-Shaper - In Combat - Summon Creature Cerberon"),
(@ENTRY,0,1,0,0,0,100,1,1000,3000,0,0,12,28211,1,600000,0,0,0,2,0,0,0,0,0,0,0,"Bythius the Flesh-Shaper - In Combat - Summon Creature Glonn"),
(@ENTRY,0,2,0,0,0,100,0,7000,10000,12000,17000,11,30043,0,0,0,0,0,5,0,0,0,0,0,0,0,"Bythius the Flesh-Shaper - In Combat - Cast 30043");

-- Zul'Drak Bat SAI
SET @ENTRY := 28233;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,10000,18000,11,54663,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zul'Drak Bat - In Combat - Cast 54663");

-- Devouring Ghoul SAI
SET @ENTRY := 28249;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,50,20000,25000,11,52352,0,0,0,0,0,2,0,0,0,0,0,0,0,"Devouring Ghoul - Between 0-50% Health - Cast 52352 (Normal Dungeon)"),
(@ENTRY,0,1,0,2,0,100,4,0,50,20000,25000,11,58758,0,0,0,0,0,2,0,0,0,0,0,0,0,"Devouring Ghoul - Between 0-50% Health - Cast 58758 (Heroic Dungeon)");

-- Guerrero SAI
SET @ENTRY := 28163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,5000,7000,17000,20000,11,13738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guerrero - In Combat - Cast 13738 (Dungeon Only)"),
(@ENTRY,0,1,0,0,0,100,6,1000,2000,9000,13000,11,50739,32,0,0,0,0,2,0,0,0,0,0,0,0,"Guerrero - In Combat - Cast 50739 (Dungeon Only)");

-- Meatpie SAI
SET @ENTRY := 28188;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,10000,8000,11000,11,49807,0,0,0,0,0,1,0,0,0,0,0,0,0,"Meatpie - In Combat - Cast 49807"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,9000,12000,11,32588,1,0,0,0,0,5,0,0,0,0,0,0,0,"Meatpie - In Combat - Cast 32588");

-- Venture Co. Excavator SAI
SET @ENTRY := 28123;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,4000,7000,11,49749,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Excavator - In Combat - Cast 49749");

-- Venture Co. Ruffian SAI
SET @ENTRY := 28124;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,11000,15000,11,52908,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Ruffian - In Combat - Cast 52908"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,9000,13000,11,51601,0,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Ruffian - In Combat - Cast 51601");

-- Longneck Grazer SAI
SET @ENTRY := 28129;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,9000,8000,12000,11,29577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Longneck Grazer - In Combat - Cast 29577");

-- Blighted Corpse SAI
SET @ENTRY := 28101;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,7000,12000,11,50306,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blighted Corpse - In Combat - Cast 50306");

-- Urgreth of the Thousand Tombs SAI
SET @ENTRY := 28103;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,9000,12000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Urgreth of the Thousand Tombs - In Combat - Cast 16856"),
(@ENTRY,0,1,0,0,0,100,0,11000,16000,18000,24000,11,51074,1,0,0,0,0,2,0,0,0,0,0,0,0,"Urgreth of the Thousand Tombs - In Combat - Cast 51074"),
(@ENTRY,0,2,0,0,0,100,0,11000,16000,18000,24000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Urgreth of the Thousand Tombs - In Combat - Say Line 0");

-- Bonescythe Ravager SAI
SET @ENTRY := 28108;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,9000,12000,11,54770,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonescythe Ravager - In Combat - Cast 54770");

-- Frenzyheart Spearbearer SAI
SET @ENTRY := 28080;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,15000,18000,11,54951,0,0,0,0,0,2,0,0,0,0,0,0,0,"Frenzyheart Spearbearer - In Combat - Cast 54951");
