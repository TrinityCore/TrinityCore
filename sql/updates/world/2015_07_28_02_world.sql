-- 
-- DB/SAI: Update Uldum
-- Cavorting Pygmy SAI
SET @ENTRY := 51217;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12000,12500,11,86695,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cavorting Pygmy - Within 0-8 Range - Cast 'Whirlwind'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,14500,16900,11,86699,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cavorting Pygmy - In Combat - Cast 'Shockwave'");
-- Colossus of the Moon SAI
SET @ENTRY := 46042;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,17000,11,85840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Colossus of the Moon - Within 0-8 Range - Cast 'Thunderclap'");
-- Colossus of the Sun SAI
SET @ENTRY := 46041;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,17000,11,85840,0,0,0,0,0,1,0,0,0,0,0,0,0,"Colossus of the Sun - Within 0-8 Range - Cast 'Thunderclap'");
-- Carrion Bird SAI
SET @ENTRY := 51760;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4100,11500,13500,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Carrion Bird - In Combat - Cast 'Swoop'");
-- Captain Kronkh SAI
SET @ENTRY := 47978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,120000,120000,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Kronkh - Within 0-8 Range - Cast 'Commanding Shout'");
-- Ancestral Guardian SAI
SET @ENTRY := 48518;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13500,14200,11,86085,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancestral Guardian - In Combat - Cast 'Mutilate'");
-- Amethyst Scarab SAI
SET @ENTRY := 46129;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Amethyst Scarab - In Combat - Cast 'Serrated Slash'");
-- Crazed Digger SAI
SET @ENTRY := 46590;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Crazed Digger - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Diseased Vulture SAI
SET @ENTRY := 47202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,13000,16000,11,81236,0,0,0,0,0,2,32,0,0,0,0,0,0,"Diseased Vulture - In Combat - Cast 'Diseased Spit'");
-- Dreadstalker SAI
SET @ENTRY := 47749;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13300,17500,11,88876,0,0,0,0,0,2,32,0,0,0,0,0,0,"Dreadstalker - In Combat - Cast 'Paralytic Venom'");
-- Dark Pharaoh Tekahn SAI
SET @ENTRY := 47753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,88886,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Pharaoh Tekahn - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,11000,13000,11,88883,0,0,0,0,0,5,1,0,0,0,0,0,0,"Dark Pharaoh Tekahn - In Combat - Cast 'Pact of Darkness'"),
(@ENTRY,0,2,0,9,0,100,0,5,25,15800,18300,11,88887,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Pharaoh Tekahn - Within 5-25 Range - Cast 'Dark Rune'");
-- Dark Ritualist Zakahn SAI
SET @ENTRY := 49148;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12400,13500,11,9081,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - Within 0-8 Range - Cast 'Shadow Bolt Volley'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,91614,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - On Aggro - Cast 'Zakahn's Serpents' (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,1000,1000,11,68797,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - Out of Combat - Cast 'Soulguard Channel' (No Repeat)");
-- Decrepit Watcher SAI
SET @ENTRY := 47385;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16000,19000,11,87753,0,0,0,0,0,1,0,0,0,0,0,0,0,"Decrepit Watcher - In Combat - Cast 'Blazing Eruption'");
-- Emerald Scarab SAI
SET @ENTRY := 46128;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emerald Scarab - In Combat - Cast 'Serrated Slash'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,14500,15500,11,87393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emerald Scarab - Within 0-8 Range - Cast 'Corrosive Spray'");
-- Eternal Protector SAI
SET @ENTRY := 47227;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,17800,21300,11,14868,0,0,0,0,0,5,0,0,0,0,0,0,0,"Eternal Protector - In Combat - Cast 'Curse of Agony'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,8000,11000,11,85424,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eternal Protector - Within 0-5 Range - Cast 'Spirit Burst'");
-- Cyrus the Black SAI
SET @ENTRY := 50064;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,13600,15800,11,93589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cyrus the Black - In Combat - Cast 'Disease Breath'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,17800,21300,11,93587,0,0,0,0,0,2,1,0,0,0,0,0,0,"Cyrus the Black - In Combat - Cast 'Ritual of Bloodletting'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,93585,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cyrus the Black - Between 0-50% Health - Cast 'Serum of Torment' (No Repeat)");
-- Crown Technician SAI
SET @ENTRY := 51613;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,70074,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crown Technician - In Combat - Cast 'Spray Chemical'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,8000,10000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Crown Technician - Within 0-5 Range - Cast 'Kick'");
-- Captain Margun SAI
SET @ENTRY := 47981;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,14500,15300,11,6253,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Margun - In Combat - Cast 'Backhand'"),
(@ENTRY,0,1,0,9,0,100,0,0,10,12000,12300,11,84309,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Margun - Within 0-10 Range - Cast 'Coin Toss'");
-- Captain Cork SAI
SET @ENTRY := 47980;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11300,13500,11,86738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Captain Cork - In Combat - Cast 'Deep Bruise'"),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,16000,11,93456,0,0,0,0,0,5,0,0,0,0,0,0,0,"Captain Cork - Within 0-10 Range - Cast 'Smoke Bomb'");
-- Antechamber Guardian SAI
SET @ENTRY := 39077;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,15000,11,80380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Antechamber Guardian - Within 0-5 Range - Cast 'Sand Breath'"),
(@ENTRY,0,1,0,9,0,100,0,0,25,22000,23000,11,73864,0,0,0,0,0,2,0,0,0,0,0,0,0,"Antechamber Guardian - Within 0-25 Range - Cast 'Sand Trap'"),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,18000,18000,11,83567,0,0,0,0,0,1,0,0,0,0,0,0,0,"Antechamber Guardian - In Combat - Cast 'Sparkling Sands'");
-- Akma'hat SAI
SET @ENTRY := 50063;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,22000,22000,11,94946,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - In Combat - Cast 'Fury of the Sands'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,19500,27300,11,93578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - In Combat - Cast 'Sands of Time'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,15800,18300,11,94968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akma'hat - Within 0-8 Range - Cast 'Shockwave'"),
(@ENTRY,0,3,0,2,0,100,1,0,40,0,0,11,93561,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - Between 0-40% Health - Cast 'Stone Mantle' (No Repeat)");
-- Cursed Engineer SAI
SET @ENTRY := 46617;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,25,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cursed Engineer - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 46617;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Hubba-hubba!',12,0,50,0,0,0, 'combat Say',46807),
(@ENTRY,0,1, 'You could bounce a washer off those legs!',12,0,50,0,0,0, 'combat Say',46809),
(@ENTRY,0,2, 'Weaponized sharks? Why didn\'t I think of that!',12,0,50,0,0,0, 'combat Say',46817),
(@ENTRY,0,3, 'ROCK ON!',12,0,50,0,0,0, 'combat Say',46818),
(@ENTRY,0,4, 'So... EPIC!',12,0,50,0,0,0, 'combat Say',46816),
(@ENTRY,0,5, '200 horsepower, dual combustion engine with modified flux capacitors! ZOING!',12,0,50,0,0,0, 'combat Say',46812),
(@ENTRY,0,6, 'Shake it like a sine wave, baby!',12,0,50,0,0,0, 'combat Say',46810);
-- Mangy Hyena SAI
SET @ENTRY := 45202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,12000,11,85415,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mangy Hyena - In Combat - Cast 'Mangle'");
-- Madexx SAI
SET @ENTRY := 51402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Victim Casting - Cast 'Harden'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - Between 0-30% Health - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");
-- Madexx SAI
SET @ENTRY := 50154;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Victim Casting - Cast 'Harden'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - Between 0-30% Health - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");
-- Madexx SAI
SET @ENTRY := 51403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Victim Casting - Cast 'Harden'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - Between 0-30% Health - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");
-- Madexx SAI
SET @ENTRY := 51404;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Victim Casting - Cast 'Harden'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - Between 0-30% Health - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");
-- Madexx SAI
SET @ENTRY := 51401;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,12000,18000,0,0,11,79840,0,0,0,0,0,6,1,0,0,0,0,0,0,"Madexx - On Victim Casting - Cast 'Harden'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - Between 0-30% Health - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,79443,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - On Aggro - Cast 'Sand Step' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,14000,16000,11,79607,0,0,0,0,0,1,0,0,0,0,0,0,0,"Madexx - In Combat - Cast 'Venom Splash'");
-- Longstrider Gazelle SAI
SET @ENTRY := 51713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Longstrider Gazelle - In Combat - Cast 'Gore'");
-- Kavem the Callous SAI
SET @ENTRY := 47567;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kavem the Callous - Within 0-8 Range - Cast 'Battle Shout'"),
(@ENTRY,0,1,0,2,0,100,1,0,50,0,0,11,79878,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kavem the Callous - Between 0-50% Health - Cast 'Bloodthirst' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,11000,13000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kavem the Callous - In Combat - Cast 'Rend'"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,79883,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kavem the Callous - On Aggro - Cast 'Shattering Throw' (No Repeat)"),
(@ENTRY,0,4,0,0,0,100,0,8000,8000,17800,19600,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kavem the Callous - In Combat - Cast 'Slam'");
-- Mysterious Camel Figurine SAI
SET @ENTRY := 50409;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3500,11000,11500,11,93473,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mysterious Camel Figurine - In Combat - Cast 'Sandstorm'");
-- Mar'at Guardian SAI
SET @ENTRY := 48874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mar'at Guardian - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mar'at Guardian - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3400,5500,10800,15400,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mar'at Guardian - In Combat - Cast 'Cleave'");
-- Indentured Protector SAI
SET @ENTRY := 45949;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,91856,64,0,0,0,0,2,0,0,0,0,0,0,0,"Indentured Protector - In Combat - Cast 'Scythe of Disruption'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,13500,14200,11,86085,0,0,0,0,0,2,0,0,0,0,0,0,0,"Indentured Protector - In Combat - Cast 'Mutilate'");
-- Immortal Colossus SAI
SET @ENTRY := 48548;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,90422,0,0,0,0,0,2,0,0,0,0,0,0,0,"Immortal Colossus - In Combat - Cast 'Colossal Cleave'");
-- High Priest Sekhemet SAI
SET @ENTRY := 47730;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,"High Priest Sekhemet - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Priest Sekhemet - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8200,8500,18500,22300,11,86845,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Priest Sekhemet - In Combat - Cast 'Shadow Eruption'");
-- General Ammantep SAI
SET @ENTRY := 45772;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"General Ammantep - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Ammantep - Between 0-15% Health - Flee For Assist (No Repeat)");
-- High Commander Kamses SAI
SET @ENTRY := 46134;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"High Commander Kamses - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Commander Kamses - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Ferndweller Wasp SAI
SET @ENTRY := 51712;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,34392,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferndweller Wasp - Between 0-30% Health - Cast 'Stinger Rage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferndweller Wasp - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 51712;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes rage!',16,0,100,0,0,0, 'combat Rage',10677);
-- Furious Specter SAI
SET @ENTRY := 47220;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,17200,18900,11,69633,0,0,0,0,0,5,0,0,0,0,0,0,0,"Furious Specter - In Combat - Cast 'Veil of Shadow'"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,9000,14000,11,92919,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furious Specter - In Combat - Cast 'Wail of Souls'");
-- Oasis Crocolisk SAI
SET @ENTRY := 51675;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,12900,14700,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oasis Crocolisk - In Combat - Cast 'Powerful Bite'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,87228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oasis Crocolisk - Between 0-30% Health - Cast 'Thick Hide' (No Repeat)");
-- Obsidian Colossus SAI
SET @ENTRY := 46646;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,17900,18500,11,87988,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Colossus - In Combat - Cast 'Force Punch'"),
(@ENTRY,0,1,0,9,0,100,0,8,20,15800,18300,11,87990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Obsidian Colossus - Within 8-20 Range - Cast 'Shadow Storm'"),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,12000,13000,11,87680,0,0,0,0,0,2,0,0,0,0,0,0,0,"Obsidian Colossus - In Combat - Cast 'Sweeping Attack'");
-- Neferset Blade Twister SAI
SET @ENTRY := 47727;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13400,11,88844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Blade Twister - In Combat - Cast 'Cauterizing Strike'");
-- Neferset Armorer SAI
SET @ENTRY := 47722;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,4500,15800,18900,11,86070,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Armorer - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,21200,22000,11,21118,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Armorer - In Combat - Cast 'Spell Reflection'");
-- Neferset Ritualist SAI
SET @ENTRY := 47762;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,88886,64,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Ritualist - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Ritualist - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,3000,22000,25000,11,69391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Ritualist - In Combat - Cast 'Dark Blessing'"),
(@ENTRY,0,3,0,9,0,100,0,0,20,15800,19900,11,88902,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Ritualist - Within 0-20 Range - Cast 'Meteor'");
-- Neferset Savage SAI
SET @ENTRY := 47729;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,14800,15600,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Savage - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9200,22400,22700,11,88846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Savage - In Combat - Cast 'Shockwave'");
-- Neferset Raider SAI
SET @ENTRY := 48626;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,12300,11,13608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Raider - In Combat - Cast 'Hooked Net'");
-- Neferset Scryer SAI
SET @ENTRY := 48625;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,88886,64,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Scryer - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Scryer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,18500,19100,11,90607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Scryer - In Combat - Cast 'Curse of Impotence'"),
(@ENTRY,0,3,0,0,0,100,0,1000,1000,34500,35600,11,31976,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Scryer - In Combat - Cast 'Shadow Shield'");
-- Prince Nadun SAI
SET @ENTRY := 45799;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Nadun - In Combat - Cast 'Shoot'");
-- Rabid Hyena SAI
SET @ENTRY := 51671;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4500,4500,11000,12500,11,85415,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rabid Hyena - In Combat - Cast 'Mangle'");
-- Ramkahen Citizen SAI
SET @ENTRY := 46402;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Citizen - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Citizen - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Ramkahen Field Worker SAI
SET @ENTRY := 47699;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Field Worker - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Field Worker - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Pyramid Watcher SAI
SET @ENTRY := 47810;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16000,19000,11,87753,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pyramid Watcher - In Combat - Cast 'Blazing Eruption'");
-- Ramkahen Prisoner SAI
SET @ENTRY := 46425;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,22000,25000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Prisoner - Within 0-8 Range - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,13500,15700,11,74720,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Prisoner - In Combat - Cast 'Pound'");
-- Ramkahen Ranger SAI
SET @ENTRY := 49255;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Ranger - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Ranger - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Ramkahen Ranger Captain SAI
SET @ENTRY := 49253;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Ranger Captain - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Ranger Captain - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Ramkahen Marksman SAI
SET @ENTRY := 48514;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,85232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Marksman - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Marksman - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Ramkahen Guardian SAI
SET @ENTRY := 51776;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,8000,12000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - Within 0-8 Range - Cast 'Cleave'");
-- Neferset Cursebringer SAI
SET @ENTRY := 47760;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,17000,19200,11,88901,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Cursebringer - In Combat - Cast 'Curse of Blood'"),
(@ENTRY,0,1,0,0,0,100,0,3000,9000,11000,14500,11,15968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Cursebringer - In Combat - Cast 'Lash of Pain'");
-- Neferset Looter SAI
SET @ENTRY := 48627;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5500,12000,13000,11,6595,0,0,0,0,0,2,0,0,0,0,0,0,0,"Neferset Looter - In Combat - Cast 'Exploit Weakness'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,21000,22000,11,36250,0,0,0,0,0,2,1,0,0,0,0,0,0,"Neferset Looter - In Combat - Cast 'Steal Armor'");
-- Neferset Snake Charmer SAI
SET @ENTRY := 47738;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,11900,13500,11,88863,0,0,0,0,0,2,32,0,0,0,0,0,0,"Neferset Snake Charmer - In Combat - Cast 'Instant Poison'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,25000,25000,11,88862,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Snake Charmer - In Combat - Cast 'Viper's Call'");
-- Neferset Venom Keeper SAI
SET @ENTRY := 47741;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,17000,18000,11,85713,0,0,0,0,0,2,32,0,0,0,0,0,0,"Neferset Venom Keeper - In Combat - Cast 'Intoxicating Venom'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,12000,13000,11,88867,0,0,0,0,0,1,0,0,0,0,0,0,0,"Neferset Venom Keeper - In Combat - Cast 'Anesthetics'");
-- Oathsworn Skinner SAI
SET @ENTRY := 51759;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16000,16000,11,96098,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oathsworn Skinner - In Combat - Cast 'Fan of Knives'"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,11000,11500,11,84031,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oathsworn Skinner - In Combat - Cast 'Spinal Pierce'");
-- Pygmy Oaf SAI
SET @ENTRY := 48040;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,18000,11,86695,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Oaf - Within 0-8 Range - Cast 'Whirlwind'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12500,13600,11,86699,0,0,0,0,0,2,0,0,0,0,0,0,0,"Pygmy Oaf - In Combat - Cast 'Shockwave'");
-- Pygmy Scout SAI
SET @ENTRY := 48041;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,79444,64,0,0,0,0,2,0,0,0,0,0,0,0,"Pygmy Scout - In Combat - Cast 'Impale'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Scout - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,15000,11,73864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Scout - Within 0-8 Range - Cast 'Sand Trap'");
-- Pygmy Thief SAI
SET @ENTRY := 48043;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,87341,64,0,0,0,0,2,0,0,0,0,0,0,0,"Pygmy Thief - In Combat - Cast 'Blow Dart'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pygmy Thief - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Ramkahen Guardian SAI
SET @ENTRY := 48883;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,15000,16000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - Within 0-20 Range - Cast 'Net'");
-- Ramkahen Guardian SAI
SET @ENTRY := 51776;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ramkahen Guardian - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,8000,12000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ramkahen Guardian - Within 0-8 Range - Cast 'Cleave'");
-- Riverbed Crocolisk SAI
SET @ENTRY := 45321;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,12900,14700,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Riverbed Crocolisk - In Combat - Cast 'Powerful Bite'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,87228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverbed Crocolisk - Between 0-30% Health - Cast 'Thick Hide' (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,17900,18500,11,63900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Riverbed Crocolisk - Within 0-8 Range - Cast 'Thunderstomp'");
-- Myzerian SAI
SET @ENTRY := 48444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,12000,14000,11,90075,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Black Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,15000,17500,11,90076,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Fire Spit'"),
(@ENTRY,0,2,0,0,0,100,0,12000,12000,25000,27000,11,90078,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Rupture Line'"),
(@ENTRY,0,3,0,0,0,100,0,5000,14000,17500,21500,11,90074,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Tail Sweep'");
-- Myzerian SAI
SET @ENTRY := 48428;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,12000,14000,11,90075,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Black Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,15000,17500,11,90076,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Fire Spit'"),
(@ENTRY,0,2,0,0,0,100,0,12000,12000,25000,27000,11,90078,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Rupture Line'"),
(@ENTRY,0,3,0,0,0,100,0,5000,14000,17500,21500,11,90074,0,0,0,0,0,2,0,0,0,0,0,0,0,"Myzerian - In Combat - Cast 'Tail Sweep'");
-- Schnottz Sea Trooper SAI
SET @ENTRY := 47982;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,11000,12000,11,38029,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Sea Trooper - In Combat - Cast 'Stab'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,7000,15000,11,13608,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Sea Trooper - In Combat - Cast 'Hooked Net'");
-- Schnottz Overseer SAI
SET @ENTRY := 48205;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13500,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Overseer - In Combat - Cast 'Slam'"),
(@ENTRY,0,1,0,0,0,100,0,3000,8000,16800,19900,11,32191,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Overseer - In Combat - Cast 'Heavy Dynamite'");
-- Schnottz Excavator SAI
SET @ENTRY := 48204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,12000,18000,0,0,11,11978,0,0,0,0,0,6,1,0,0,0,0,0,0,"Schnottz Excavator - On Victim Casting - Cast 'Kick'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,15800,16400,11,7978,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Excavator - Within 0-8 Range - Cast 'Throw Dynamite'");
-- Schnottz Overseer SAI
SET @ENTRY := 51753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13500,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Overseer - In Combat - Cast 'Slam'"),
(@ENTRY,0,1,0,0,0,100,0,3000,8000,16800,19900,11,32191,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Overseer - In Combat - Cast 'Heavy Dynamite'");
-- Schnottz Rifleman SAI
SET @ENTRY := 47067;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,84837,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Rifleman - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Rifleman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,14500,16800,11,8858,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Rifleman - In Combat - Cast 'Bomb'"),
(@ENTRY,0,3,0,0,0,100,0,11000,11000,19000,19000,11,31358,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Rifleman - In Combat - Cast 'Fear'");
-- Schnottz Elite Trooper SAI
SET @ENTRY := 48443;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Elite Trooper - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Trooper - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,14500,16800,11,93449,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Elite Trooper - In Combat - Cast 'Bomb'");
-- Schnottz Elite Infantryman SAI
SET @ENTRY := 48631;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Elite Infantryman - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Infantryman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,14500,16800,11,93449,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Elite Infantryman - In Combat - Cast 'Bomb'");
-- Schnottz Air Officer SAI
SET @ENTRY := 46993;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Air Officer - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Air Officer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,14500,16800,11,93449,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Air Officer - In Combat - Cast 'Bomb'");
-- Schnottz Air Trooper SAI
SET @ENTRY := 46979;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Air Trooper - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Air Trooper - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,14500,16800,11,93449,0,0,0,0,0,5,0,0,0,0,0,0,0,"Schnottz Air Trooper - In Combat - Cast 'Bomb'");
-- Schnottz's Landing Laborer SAI
SET @ENTRY := 47974;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,89205,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Schnottz's Landing Laborer SAI
SET @ENTRY := 47291;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - Within 0-8 Range - Cast 'Battle Shout'");
-- Schnottz's Landing Laborer SAI
SET @ENTRY := 47690;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz's Landing Laborer - Within 0-8 Range - Cast 'Battle Shout'");
-- Warlord Ihsenn SAI
SET @ENTRY := 47755;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,6434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Ihsenn - Between 0-30% Health - Cast 'Slice and Dice' (No Repeat)");
-- Vizier Tanotep SAI
SET @ENTRY := 46136;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,14000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vizier Tanotep - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,17800,19600,11,88846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vizier Tanotep - In Combat - Cast 'Shockwave'");
-- Venomscale Spitter SAI
SET @ENTRY := 51673;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13300,17500,11,88876,0,0,0,0,0,2,32,0,0,0,0,0,0,"Venomscale Spitter - In Combat - Cast 'Paralytic Venom'");
-- Venomblood Scorpid SAI
SET @ENTRY := 45859;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,15000,11,63900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venomblood Scorpid - Within 0-5 Range - Cast 'Thunderstomp'");
-- Turquoise Scarab SAI
SET @ENTRY := 46126;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4000,15600,16400,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Turquoise Scarab - In Combat - Cast 'Serrated Slash'"),
(@ENTRY,0,1,0,0,0,100,0,16800,17900,16800,17900,11,88023,0,0,0,0,0,1,0,0,0,0,0,0,0,"Turquoise Scarab - In Combat - Cast 'Shroud of Gold'"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,88023,0,0,0,0,0,1,0,0,0,0,0,0,0,"Turquoise Scarab - On Aggro - Cast 'Shroud of Gold' (No Repeat)");
-- Tormented Tomb-Robber SAI
SET @ENTRY := 45765;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,35,0,0,11,87354,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tormented Tomb-Robber - Between 0-35% Health - Cast 'Ethereal Form' (No Repeat)");
-- Temple Scarab SAI
SET @ENTRY := 47801;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Temple Scarab - In Combat - Cast 'Serrated Slash'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,14500,15500,11,87393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Temple Scarab - Within 0-8 Range - Cast 'Corrosive Spray'");
-- Sweeping Winds SAI
SET @ENTRY := 51672;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,18500,18900,11,77500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sweeping Winds - Within 0-8 Range - Cast 'Wind Blast'");
-- Skarf SAI
SET @ENTRY := 45204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13500,11,85835,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skarf - In Combat - Cast 'Maul'"),
(@ENTRY,0,1,0,9,0,100,0,5,15,15800,18300,11,44531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skarf - Within 5-15 Range - Cast 'Dash'");
-- Shaggy Desert Coyote SAI
SET @ENTRY := 47190;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13500,11,85835,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shaggy Desert Coyote - In Combat - Cast 'Maul'"),
(@ENTRY,0,1,0,0,0,100,0,9900,9900,16400,17400,11,85691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shaggy Desert Coyote - In Combat - Cast 'Piercing Howl'");
-- Slacking Laborer SAI
SET @ENTRY := 47292;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,14890,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slacking Laborer - On Aggro - Cast 'Dismounting Blow' (No Repeat)");
-- Sergeant Mehat SAI
SET @ENTRY := 48012;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,87215,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sergeant Mehat - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sergeant Mehat - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Schnottz Elite Trooper SAI
SET @ENTRY := 48668;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Elite Trooper - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Schnottz Elite Trooper - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,12000,13000,11,88844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Schnottz Elite Trooper - In Combat - Cast 'Cauterizing Strike'");
-- Sapphire Scarab SAI
SET @ENTRY := 46127;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,9000,7000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sapphire Scarab - In Combat - Cast 'Serrated Slash'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,16800,17900,11,87396,0,0,0,0,0,2,1,0,0,0,0,0,0,"Sapphire Scarab - In Combat - Cast 'Sapphire Gaze'");
-- Sand Serpent SAI
SET @ENTRY := 47283;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,89905,0,0,0,0,0,2,32,0,0,0,0,0,0,"Sand Serpent - In Combat - Cast 'Venomous Bite'");
-- Sand Scorpid SAI
SET @ENTRY := 47803;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,3500,10800,11200,11,31289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand Scorpid - In Combat - Cast 'Claw'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,16800,17300,11,32093,0,0,0,0,0,2,32,0,0,0,0,0,0,"Sand Scorpid - In Combat - Cast 'Poison Spit'");
-- Sand Pygmy SAI
SET @ENTRY := 45190;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12000,12500,11,86695,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand Pygmy - Within 0-8 Range - Cast 'Whirlwind'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,14500,16900,11,86699,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand Pygmy - In Combat - Cast 'Shockwave'");
-- Tiger SAI
SET @ENTRY := 47726;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13500,11,85835,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tiger - In Combat - Cast 'Maul'"),
(@ENTRY,0,1,0,9,0,100,0,5,15,15800,18300,11,44531,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tiger - Within 5-15 Range - Cast 'Dash'");
-- Sultan Oogah SAI
SET @ENTRY := 45205;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,87341,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sultan Oogah - In Combat - Cast 'Blow Dart'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sultan Oogah - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,22500,23800,11,87322,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sultan Oogah - In Combat - Cast 'Veil of Shimmering Sand'");
-- Sand-Husk Scarab SAI
SET @ENTRY := 51674;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,9000,10000,13600,11,87395,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sand-Husk Scarab - In Combat - Cast 'Serrated Slash'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,14500,15500,11,87393,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sand-Husk Scarab - Within 0-8 Range - Cast 'Corrosive Spray'");
-- Scorpion-Lord Namkhare SAI
SET @ENTRY := 47742;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,89424,0,0,0,0,0,1,0,0,0,0,0,0,0,"Scorpion-Lord Namkhare - On Aggro - Cast 'Call Scorpid' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,13000,11,88863,0,0,0,0,0,2,32,0,0,0,0,0,0,"Scorpion-Lord Namkhare - In Combat - Cast 'Instant Poison'"),
(@ENTRY,0,2,0,0,0,100,0,2000,8000,7000,16000,11,38338,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scorpion-Lord Namkhare - In Combat - Cast 'Net'");
-- Titanic Guardian SAI
SET @ENTRY := 47032;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16000,19000,11,87753,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanic Guardian - In Combat - Cast 'Blazing Eruption'"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,13000,13000,11,87656,0,0,0,0,0,1,0,0,0,0,0,0,0,"Titanic Guardian - In Combat - Cast 'Decrepit Ruin'"),
(@ENTRY,0,2,0,0,0,100,0,12000,12000,29000,35000,11,87698,0,0,0,0,0,1,1,0,0,0,0,0,0,"Titanic Guardian - In Combat - Cast 'Summon Meteor'");
