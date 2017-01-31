-- Update Azshara

-- 1.
-- Antilos SAI
SET @ENTRY := 6648;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Antilos - In Combat - Cast 'Rend'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,13600,14500,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Antilos - Within 0-5 Range - Cast 'Cleave'");

-- 2.
-- Apprentice Illuminator SAI
SET @ENTRY := 36593;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Apprentice Illuminator - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Illuminator - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,5000,12000,17000,11,13339,1,0,0,0,0,2,0,0,0,0,0,0,0,"Apprentice Illuminator - In Combat - Cast 'Fire Blast'");

-- 3.
-- Apprentice Investigator SAI
SET @ENTRY := 36592;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Apprentice Investigator - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apprentice Investigator - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 4.
-- Balboa SAI
SET @ENTRY := 35759;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,15000,18000,11,80835,0,0,0,0,0,1,0,0,0,0,0,0,0,"Balboa - In Combat - Cast 'Thundering Stomp'");

-- 5.
-- Bilgewater Foreman SAI
SET @ENTRY := 42777;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,17000,22000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bilgewater Foreman - In Combat - Cast 'Strike'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,19000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bilgewater Foreman - Within 0-5 Range - Cast 'Cleave'");

-- 6.
-- Bilgewater Seal SAI
SET @ENTRY := 37741;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,14000,21500,11,50169,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bilgewater Seal - In Combat - Cast 'Flipper Thwack'");

-- 7.
-- Bilgewater Soldier SAI
SET @ENTRY := 36925;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,69591,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bilgewater Soldier - In Combat - Cast 'Shoot'");

-- 8.
-- Bingham Gadgetspring SAI
SET @ENTRY := 36407;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,28000,37000,11,8209,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bingham Gadgetspring - In Combat - Cast 'Explosive Sheep'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bingham Gadgetspring - On Aggro - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 36407;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, 'My house!',12,0,100,0,0,0, 'on Aggro Text', 36373);

-- 9.
-- Blackmaw Pathfinder SAI
SET @ENTRY := 36015;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,74613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Blackmaw Pathfinder - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackmaw Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 10.
-- Blackmaw Shaman SAI
SET @ENTRY := 36012;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,15000,16000,11,15039,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blackmaw Shaman - In Combat - Cast 'Flame Shock'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,14000,21000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackmaw Shaman - Between 0-40% Health - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,14,0,100,0,100,40,15000,18000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,"Blackmaw Shaman - Friendly At 100 Health - Cast 'Healing Wave'");

-- 11.
-- Blackmaw Warrior SAI
SET @ENTRY := 36013;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,17000,24000,11,41056,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackmaw Warrior - In Combat - Cast 'Whirlwind'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackmaw Warrior - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blackmaw Warrior - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 36013;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 12.
-- Captain Grunwald SAI
SET @ENTRY := 36680;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Grunwald - On Aggro - Cast 'Battle Shout' (No Repeat)");

-- 13.
-- Cliff Crasher SAI
SET @ENTRY := 37002;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,15000,18000,11,80835,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cliff Crasher - In Combat - Cast 'Thundering Stomp'");

-- 14.
-- Commander Jarrodenus SAI
SET @ENTRY := 36884;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Jarrodenus - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Commander Jarrodenus - On Aggro - Say Line 1 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,40,25000,26000,11,81005,0,0,0,0,0,2,0,0,0,0,0,0,0,"Commander Jarrodenus - Within 0-40 Range - Cast 'Hadouken'"),
(@ENTRY,0,3,0,0,0,100,0,6000,7000,14000,21000,11,81014,0,0,0,0,0,2,0,0,0,0,0,0,0,"Commander Jarrodenus - In Combat - Cast 'Flaming Dragon Kick'");

-- NPC talk text insert
SET @ENTRY := 36884;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Haaadoouuuu....',12,0,100,0,0,0, 'on Aggro Text',43407),
(@ENTRY,1,0, '... KEN!!',14,0,100,0,0,0, 'on Aggro Text',43408);

-- 15.
-- Coralshell Lurker SAI
SET @ENTRY := 6352;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,12000,13500,11,80604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Coralshell Lurker - In Combat - Cast 'Crushing Bite'");

-- 16.
-- Ectoplasmic Exhaust SAI
SET @ENTRY := 35558;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,24000,26000,11,3335,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ectoplasmic Exhaust - In Combat - Cast 'Dark Sludge'");

-- 17.
-- Enslaved Son of Arkkoroc SAI
SET @ENTRY := 36868;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,16000,18000,11,81026,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enslaved Son of Arkkoroc - Within 0-8 Range - Cast 'Sea Splash'");

-- 18.
-- Explosives Stockpile SAI
SET @ENTRY := 35296;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,67294,3,0,0,0,0,1,0,0,0,0,0,0,0,"Explosives Stockpile - On Just Died - Cast 'Shoot Me Cue' (No Repeat)");

-- 19.
-- Gatekeeper Rageroar SAI
SET @ENTRY := 6651;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,12000,14500,11,12747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Rageroar - Within 0-30 Range - Cast 'Entangling Roots'"),
(@ENTRY,0,1,0,0,0,100,0,3500,5000,12000,14000,11,13584,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Rageroar - In Combat - Cast 'Strike'");

-- 20.
-- General Fangferror SAI
SET @ENTRY := 6650;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,12500,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Fangferror - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,4500,5000,15000,18000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Fangferror - In Combat - Cast 'Strike'"),
(@ENTRY,0,2,0,0,0,100,0,2000,9000,17000,26000,11,18812,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Fangferror - In Combat - Cast 'Knockdown'");

-- 21.
-- Greystone Basilisk SAI
SET @ENTRY := 35245;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,17000,21500,11,3636,0,0,0,0,0,2,0,0,0,0,0,0,0,"Greystone Basilisk - In Combat - Cast 'Crystalline Slumber'");

-- 22.
-- Grit SAI
SET @ENTRY := 36972;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,4000,6000,11,69375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grit - Within 8-40 Range - Cast 'Lob Fire'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,15000,22000,11,69359,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grit - In Combat - Cast 'Flamethrower'");

-- 23.
-- Grit SAI
SET @ENTRY := 36930;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,4000,6000,11,69375,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grit - Within 8-40 Range - Cast 'Lob Fire'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,15000,22000,11,69359,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grit - In Combat - Cast 'Flamethrower'");

-- 24.
-- High Priestess Silthera SAI
SET @ENTRY := 36873;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"High Priestess Silthera - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Priestess Silthera - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,25000,28000,11,11639,1,0,0,0,0,2,0,0,0,0,0,0,0,"High Priestess Silthera - In Combat - Cast 'Shadow Word: Pain'");

-- 25.
-- Imp Desecrator SAI
SET @ENTRY := 35584;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Imp Desecrator - In Combat - Cast 'Firebolt'");

-- 26.
-- Lady Sesspira SAI
SET @ENTRY := 6649;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sesspira - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Sesspira - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,18000,11,15495,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sesspira - Within 5-30 Range - Cast 'Explosive Shot'"),
(@ENTRY,0,3,0,0,0,100,0,4000,7000,15000,22000,11,20299,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Sesspira - In Combat - Cast 'Forked Lightning'");

-- 27.
-- Lady Silisthra SAI
SET @ENTRY := 35880;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Silisthra - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Silisthra - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,18000,11,15495,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Silisthra - Within 5-30 Range - Cast 'Explosive Shot'"),
(@ENTRY,0,3,0,0,0,100,0,4000,7000,15000,22000,11,20299,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Silisthra - In Combat - Cast 'Forked Lightning'"),
(@ENTRY,0,4,0,9,0,100,0,5,30,9000,26000,11,12551,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Silisthra - Within 5-30 Range - Cast 'Frost Shot'"),
(@ENTRY,0,5,0,1,0,100,0,500,1000,600000,600000,11,15507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Silisthra - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,6,0,16,0,100,0,15507,1,15000,30000,11,15507,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Silisthra - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'");

-- 28.
-- Lady Vesthra SAI
SET @ENTRY := 35881;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vesthra - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Vesthra - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,13600,14500,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Vesthra - Within 0-8 Range - Cast 'Frost Nova'"),
(@ENTRY,0,3,0,9,0,100,0,0,25,15000,18000,11,21067,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vesthra - Within 0-25 Range - Cast 'Poison Bolt'"),
(@ENTRY,0,4,0,0,0,100,0,4000,5000,14500,15800,11,38663,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vesthra - In Combat - Cast 'Slow'"),
(@ENTRY,0,5,0,9,0,100,0,0,15,25000,28000,11,81039,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Vesthra - Within 0-15 Range - Cast 'Toxic Nova'");

-- 29.
-- Legashi Hellcaller SAI
SET @ENTRY := 6202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Legashi Hellcaller - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,18500,21500,11,77428,1,0,0,0,0,1,0,0,0,0,0,0,0,"Legashi Hellcaller - Within 0-5 Range - Cast 'Hellfire'");

-- 30.
-- Legashi Rogue SAI
SET @ENTRY := 6201;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32720,0,0,0,0,0,1,0,0,0,0,0,0,0,"Legashi Rogue - On Aggro - Cast 'Sprint' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3500,12000,14500,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legashi Rogue - In Combat - Cast 'Sinister Strike'");

-- 31.
-- Legashi Satyr SAI
SET @ENTRY := 6200;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2500,50000,55000,11,80966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Legashi Satyr - In Combat - Cast 'Curse of the Legashi'");

-- 32.
-- Lord Kassarus SAI
SET @ENTRY := 36822;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,13000,11,69463,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Kassarus - In Combat - Cast 'Impaling Spine'"),
(@ENTRY,0,1,0,0,0,100,0,2000,8000,10000,18000,11,69461,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Kassarus - In Combat - Cast 'Wide Swipe'");

-- 33.
-- Lorekeeper Amberwind SAI
SET @ENTRY := 36594;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lorekeeper Amberwind - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,9000,12000,11,38663,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lorekeeper Amberwind - Within 0-20 Range - Cast 'Slow'"),
(@ENTRY,0,2,0,1,0,100,1,3000,5000,0,0,11,68990,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lorekeeper Amberwind - Out of Combat - Cast 'Summon Arcane Construct' (No Repeat)");

-- 34.
-- Makrinni Razorclaw SAI
SET @ENTRY := 6350;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,14500,17800,11,81043,0,0,0,0,0,2,0,0,0,0,0,0,0,"Makrinni Razorclaw - In Combat - Cast 'Razor Slice'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Makrinni Razorclaw - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 35.
-- Makrinni Scrabbler SAI
SET @ENTRY := 6370;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Makrinni Scrabbler - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 36.
-- Makrinni Snapclaw SAI
SET @ENTRY := 6372;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,12000,13000,11,81046,0,0,0,0,0,2,0,0,0,0,0,0,0,"Makrinni Snapclaw - In Combat - Cast 'Quick Snap'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Makrinni Snapclaw - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 37.
-- Marius Tanolaar SAI
SET @ENTRY := 35371;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marius Tanolaar - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marius Tanolaar - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,12000,15000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marius Tanolaar - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,3,0,0,0,100,0,5000,7000,9000,17000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marius Tanolaar - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,4,0,0,0,100,0,1000,3000,35000,38000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marius Tanolaar - In Combat - Cast 'Demoralizing Shout'");

-- 38.
-- Mistwing Cliffdweller SAI
SET @ENTRY := 36304;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,14000,17000,11,15797,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistwing Cliffdweller - In Combat - Cast 'Lightning Breath'");

-- 39.
-- Mistwing Ravager SAI
SET @ENTRY := 8764;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,12000,16500,11,36590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mistwing Ravager - In Combat - Cast 'Rip'");

-- 40.
-- Mosshoof Courser SAI
SET @ENTRY := 8761;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshoof Courser - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mosshoof Courser - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshoof Courser - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,4000,7000,15000,18000,11,31274,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosshoof Courser - In Combat - Cast 'Knockdown'");

-- NPC talk text insert
SET @ENTRY := 8761;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 41.
-- Mountainfoot Grunt SAI
SET @ENTRY := 36936;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mountainfoot Grunt - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mountainfoot Grunt - Between 0-30% Health - Say Line 0 (No Repeat)");

SET @ENTRY := 36936;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 42.
-- Mutant Goblin SAI
SET @ENTRY := 36156;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,6,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mutant Goblin - On Just Died - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,61,0,100,1,0,0,0,0,12,36157,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mutant Goblin - On Just Died - Summon Creature 'Mutant Tentacle' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,12,36157,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mutant Goblin - On Just Died - Summon Creature 'Mutant Tentacle' (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 36156;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'The mutant goblin\'s tentacles break free and sither across the ground!',16,0,100,0,0,0, 'combat Text',44536);

-- 43.
-- Netgun Gnome SAI
SET @ENTRY := 36385;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,9,0,100,0,0,30,15000,18000,11,68658,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netgun Gnome - Within 0-30 Range - Cast 'Netgun Blast'"),
(@ENTRY,0,1,0,61,0,100,0,0,30,15000,18000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netgun Gnome - Within 0-30 Range - Say Line 0");

-- NPC talk text insert
SET @ENTRY := 36385;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Got one!',12,0,50,0,0,0, 'combat Text',60200),
(@ENTRY,0,1, 'Snagged one!',12,0,50,0,0,0, 'combat Text',36367),
(@ENTRY,0,2, 'Zap\'em!',12,0,50,0,0,0, 'combat Text',36368);

-- 44.
-- Northwatch Bodyguard SAI
SET @ENTRY := 36688;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7164,0,0,0,0,0,1,0,0,0,0,0,0,0,"Northwatch Bodyguard - On Aggro - Cast 'Defensive Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,12500,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Bodyguard - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,13,0,100,0,5000,6000,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Bodyguard - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");

-- 45.
-- Orgrimmar Gatekeeper SAI
SET @ENTRY := 35190;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Gatekeeper - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Gatekeeper - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orgrimmar Gatekeeper - Between 0-30% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,3,0,9,0,100,0,0,5,11000,12000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Orgrimmar Gatekeeper - Within 0-5 Range - Cast 'Cleave'");

-- NPC talk text insert
SET @ENTRY := 35190;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Defend the gates!',12,0,50,0,0,0, 'on Aggro Text',35437),
(@ENTRY,0,1, 'For the Horde!',12,0,50,0,0,0, 'on Aggro Text',4921),
(@ENTRY,0,2, 'For the Warchief!',12,0,50,0,0,0, 'on Aggro Text',2104),
(@ENTRY,1,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);


-- 46.
-- Private Worcester SAI
SET @ENTRY := 36752;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,69591,64,0,0,0,0,2,0,0,0,0,0,0,0,"Private Worcester - In Combat - Cast 'Shoot'");

-- 47.
-- Restless Spirit SAI
SET @ENTRY := 35466;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,60000,65000,11,31376,0,0,0,0,0,2,0,0,0,0,0,0,0,"Restless Spirit - In Combat - Cast 'Ghostly Touch'");

-- 48.
-- Runaway Shredder SAI
SET @ENTRY := 35111;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32735,0,0,0,0,0,2,0,0,0,0,0,0,0,"Runaway Shredder - On Aggro - Cast 'Saw Blade' (No Repeat)"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Runaway Shredder - On Just Died - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 35111;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Syntax Error Line 14,Sequence:Flee for Life. Entering Passive Mode.*Click!*',12,0,100,0,0,0, 'on Death Text',35339);

-- 49.
-- Shade of Hate SAI
SET @ENTRY := 35503;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,80819,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shade of Hate - In Combat - Cast 'Burning Hatred'"),
(@ENTRY,0,1,0,4,0,30,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shade of Hate - On Aggro - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 35503;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'These grounds ... are not ... yours ...',12,0,100,0,0,0, 'on Aggro Text',35859);

-- 50.
-- Spitelash Battlemaster SAI
SET @ENTRY := 7885;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Battlemaster - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,5,35,12000,13000,11,38556,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Battlemaster - Within 5-35 Range - Cast 'Throw'");

-- 51.
-- Spitelash Enchantress SAI
SET @ENTRY := 7886;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Enchantress - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Enchantress - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,0,20,9000,13000,11,38663,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Enchantress - Within 0-20 Range - Cast 'Slow' (Phase 1)");

-- 52.
-- Spitelash Enchantress SAI
SET @ENTRY := 7886;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Enchantress - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Enchantress - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,1,100,0,0,20,9000,13000,11,38663,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Enchantress - Within 0-20 Range - Cast 'Slow' (Phase 1)");

-- 53.
-- Spitelash Invader SAI
SET @ENTRY := 36989;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Invader - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,8000,9000,11,31290,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Invader - Within 0-20 Range - Cast 'Net'");

-- 54.
-- Spitelash Myrmidon SAI
SET @ENTRY := 6196;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,17000,20000,11,81020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Myrmidon - In Combat - Cast 'Heave'");

-- 55.
-- Spitelash Priestess SAI
SET @ENTRY := 35833;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Priestess - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Priestess - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,24000,28000,11,11639,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Priestess - In Combat - Cast 'Shadow Word: Pain'");

-- 56.
-- Spitelash Screamer SAI
SET @ENTRY := 6193;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Screamer - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Screamer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,18900,22000,11,80967,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Screamer - Within 0-20 Range - Cast 'Silence'");

-- 57.
-- Spitelash Seacaller SAI
SET @ENTRY := 35832;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Seacaller - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Seacaller - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,13600,14500,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Seacaller - Within 0-8 Range - Cast 'Frost Nova'"),
(@ENTRY,0,3,0,1,0,100,0,3000,5000,180000,185000,11,68129,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Seacaller - Out of Combat - Cast 'Summon Shipwrecker'");

-- 58.
-- Spitelash Serpent Guard SAI
SET @ENTRY := 6194;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,12000,14000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Serpent Guard - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,1,0,13,0,100,0,2000,4500,20000,30000,11,34783,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Serpent Guard - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Spell Reflection'");

-- 59.
-- Spitelash Siren SAI
SET @ENTRY := 6195;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Siren - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Siren - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,20,18900,22000,11,80967,1,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Siren - Within 0-20 Range - Cast 'Silence'");

-- 60.
-- Spitelash Stormfury SAI
SET @ENTRY := 35831;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,81038,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Stormfury - In Combat - Cast 'Forked Lightning'");

-- 61.
-- Spitelash Warrior SAI
SET @ENTRY := 6190;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,69592,64,0,0,0,0,2,0,0,0,0,0,0,0,"Spitelash Warrior - In Combat - Cast 'Hurl Spear'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,63227,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Warrior - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spitelash Warrior - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 6190;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 62.
-- Static-Charged Hippogryph SAI
SET @ENTRY := 36147;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Static-Charged Hippogryph - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,1,0,16,0,100,0,19514,1,15000,30000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Static-Charged Hippogryph - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,12000,13000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Static-Charged Hippogryph - In Combat - Cast 'Shock'"),
(@ENTRY,0,3,4,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Static-Charged Hippogryph - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Static-Charged Hippogryph - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 36147;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 63.
-- Talrendis Ambassador SAI
SET @ENTRY := 36614;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Ambassador - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Ambassador - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,22000,26000,11,50273,1,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Ambassador - In Combat - Cast 'Arcane Barrage'"),
(@ENTRY,0,3,0,0,0,100,0,4000,6000,15000,17000,11,13339,1,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Ambassador - In Combat - Cast 'Fire Blast'");

-- 64.
-- Talrendis Ancient SAI
SET @ENTRY := 35198;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Ancient - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,5,30,14000,16000,11,66968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Ancient - Within 5-30 Range - Cast 'Boulder'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,12000,22000,11,66967,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Ancient - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,3,0,0,0,100,0,8000,11000,25000,29000,11,66966,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Ancient - In Combat - Cast 'Smash'"),
(@ENTRY,0,4,0,2,0,100,1,0,70,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Ancient - Between 0-70% Health - Say Line 1 (No Repeat)"),
(@ENTRY,0,5,0,2,0,100,1,0,40,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Ancient - Between 0-40% Health - Say Line 1 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 35198;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Why, what brings you all the way over here, young $r? Please be cautious. Our foes stream from a hole in the mountains to the east - they have done irreparable harm to this land.',14,0,100,0,0,0, 'on Aggro Text',35480),
(@ENTRY,1,0, 'The Talrendis Ancient howls out in pain!',41,0,100,0,0,0, 'in Battle Text',35470);

-- 65.
-- Talrendis Biologist SAI
SET @ENTRY := 36611;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,18000,21000,11,80917,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Biologist - In Combat - Cast 'Snail Slime'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Biologist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 66.
-- Talrendis Defender SAI
SET @ENTRY := 36816;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Defender - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Defender - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,2,0,13,0,100,0,2000,4500,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Defender - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");

-- 67.
-- Talrendis Glaive Thrower SAI
SET @ENTRY := 36890;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Glaive Thrower - On Aggro - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,5000,5000,11,69517,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Glaive Thrower - In Combat - Cast 'Throw Glaive'");

-- 68.
-- Talrendis Lorekeeper SAI
SET @ENTRY := 36849;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Lorekeeper - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Lorekeeper - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,15000,19000,11,15798,1,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Lorekeeper - In Combat - Cast 'Moonfire'");

-- 69.
-- Talrendis Marksman SAI
SET @ENTRY := 36660;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Marksman - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Marksman - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,5,9,0,100,0,0,5,8000,12000,11,81001,1,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Marksman - Within 0-5 Range - Cast 'Side Kick'");

-- 70.
-- Talrendis Raider SAI
SET @ENTRY := 35177;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,30493,64,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Raider - In Combat - Cast 'Shoot Bow'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Raider - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 71.
-- Talrendis Saboteur SAI
SET @ENTRY := 35312;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Saboteur - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Saboteur - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,12000,15000,11,11971,1,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Saboteur - Within 0-5 Range - Cast 'Sunder Armor'"),
(@ENTRY,0,3,0,9,0,100,0,5,30,17000,24000,11,67301,1,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Saboteur - Within 5-30 Range - Cast 'Fire Shot'");

-- 72.
-- Talrendis Scout SAI
SET @ENTRY := 35095;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,80266,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Scout - On Respawn - Cast 'Talrendis Camo' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,80266,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Scout - On Evade - Cast 'Talrendis Camo' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,50,14000,21000,11,80820,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Scout - Between 0-50% Health - Cast 'Forest Step'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Scout - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 73.
-- Talrendis Sentinel SAI
SET @ENTRY := 36914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,36500,64,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Sentinel - In Combat - Cast 'Glaive'");

-- 74.
-- Talrendis Sniper SAI
SET @ENTRY := 35149;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Talrendis Sniper - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Talrendis Sniper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 75.
-- The Evalcharr SAI
SET @ENTRY := 8660;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,15797,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Evalcharr - In Combat - Cast 'Lightning Breath'");

-- 76.
-- Thunderhead Hippogryph SAI
SET @ENTRY := 6375;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80957,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thunderhead Hippogryph - On Aggro - Cast 'Thundering Rush' (No Repeat)");

-- 77.
-- Thunderhead Stagwing SAI
SET @ENTRY := 6377;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,12000,13000,11,12553,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead Stagwing - In Combat - Cast 'Shock'"),
(@ENTRY,0,1,0,0,0,100,0,6000,9000,19000,25000,11,11019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thunderhead Stagwing - In Combat - Cast 'Wing Flap'");

-- 78.
-- Ticker SAI
SET @ENTRY := 36976;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,69373,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ticker - In Combat - Cast 'Shoot'");

-- 79.
-- Twilight Desecrator SAI
SET @ENTRY := 36637;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Desecrator - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,22000,24000,11,80999,1,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Desecrator - In Combat - Cast 'Shadow Void'");

-- 80.
-- Twilight Dragon Hunter SAI
SET @ENTRY := 36636;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Dragon Hunter - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,5,42000,45000,11,78578,1,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Dragon Hunter - Within 0-5 Range - Cast 'Immolation Trap'");

-- 81.
-- Twilight Lord Katrana SAI
SET @ENTRY := 36638;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Lord Katrana - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,60,28000,32000,11,69135,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Lord Katrana - Between 0-60% Health - Cast 'Twilight Barrier'");

-- NPC talk text insert
SET @ENTRY := 36638;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You''ve come seeking your death? Happy to oblige.',14,0,100,0,0,0, 'on Aggro Text',36908);

-- 82.
-- Valormok Grunt SAI
SET @ENTRY := 36815;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Valormok Grunt - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,5,9000,11000,11,40505,1,0,0,0,0,2,0,0,0,0,0,0,0,"Valormok Grunt - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,3,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valormok Grunt - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valormok Grunt - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 36815;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 83.
-- Varo'then's Ghost SAI
SET @ENTRY := 6118;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,22000,25000,11,21007,0,0,0,0,0,2,0,0,0,0,0,0,0,"Varo'then's Ghost - In Combat - Cast 'Curse of Weakness'");

-- 84.
-- Vile Splash SAI
SET @ENTRY := 36131;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,9000,12000,11,32011,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vile Splash - In Combat - Cast 'Water Bolt'");

-- 85.
-- Volt SAI
SET @ENTRY := 36975;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,69374,64,0,0,0,0,2,0,0,0,0,0,0,0,"Volt - In Combat - Cast 'Shoot'");

-- 86.
-- Warlord Krellian SAI
SET @ENTRY := 8408;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Krellian - On Aggro - Cast 'Battle Shout' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,13000,11,15496,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Krellian - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,16000,19000,11,81020,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Krellian - In Combat - Cast 'Heave'");

-- 87.
-- Weakened Mosshoof Stag SAI
SET @ENTRY := 35096;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weakened Mosshoof Stag - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,4500,15000,18500,11,31274,0,0,0,0,0,2,0,0,0,0,0,0,0,"Weakened Mosshoof Stag - In Combat - Cast 'Knockdown'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Weakened Mosshoof Stag - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 88.
-- Yellowfin Shark SAI
SET @ENTRY := 37740;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,16000,21000,11,69203,0,0,0,0,0,2,0,0,0,0,0,0,0,"Yellowfin Shark - In Combat - Cast 'Vicious Bite'");

-- 89.
-- Zapper Gnome SAI
SET @ENTRY := 36384;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,9,0,100,0,5,30,15000,18000,11,68664,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zapper Gnome - Within 5-30 Range - Cast 'Zapper Gun'"),
(@ENTRY,0,1,0,61,0,100,0,5,30,15000,18000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zapper Gnome - Within 5-30 Range - Say Line 0");

-- NPC talk text insert
SET @ENTRY := 36384;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Got one!',12,0,50,0,0,0, 'combat Text',60200),
(@ENTRY,0,1, 'Snagged one!',12,0,50,0,0,0, 'combat Text',36367),
(@ENTRY,0,2, 'Zap\'em!',12,0,50,0,0,0, 'combat Text',36368);
