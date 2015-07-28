-- 
-- DB/SAI: Update Stonetalon Mountains
-- Allendril Fallcreek SAI
SET @ENTRY := 34941;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Allendril Fallcreek - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Allendril Fallcreek - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,20000,25000,11,81428,0,0,0,0,0,4,0,0,0,0,0,0,0,"Allendril Fallcreek - In Combat - Cast 'Song of Persuasion'");
-- NPC talk text insert
SET @ENTRY := 34941;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Black Dragon Whelp SAI
SET @ENTRY := 34898;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,81521,64,0,0,0,0,2,0,0,0,0,0,0,0,"Black Dragon Whelp - In Combat - Cast 'Fireball'");
-- Black Drake SAI
SET @ENTRY := 34897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,12000,35000,38000,11,8873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Black Drake - In Combat - Cast 'Flame Breath'");
-- Boulderslide Geomancer SAI
SET @ENTRY := 11917;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20793,64,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderslide Geomancer - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Boulderslide Geomancer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,25000,27000,11,81309,2,0,0,0,0,4,0,0,0,0,0,0,0,"Boulderslide Geomancer - In Combat - Cast 'Cave-in'");
-- Boulderslide Rock Keeper SAI
SET @ENTRY := 11915;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,13600,14500,11,81305,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderslide Rock Keeper - Within 0-30 Range - Cast 'Rock Barrage'");
-- Boulderslide Stonepounder SAI
SET @ENTRY := 11918;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,12000,19000,11,81361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Boulderslide Stonepounder - Within 0-20 Range - Cast 'Ground Spike'");
-- Brother Ravenoak SAI
SET @ENTRY := 5915;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brother Ravenoak - On Aggro - Cast 'Bear Form' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,15000,11,12161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brother Ravenoak - Within 0-5 Range - Cast 'Maul'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,17000,22000,11,8716,0,0,0,0,0,2,0,0,0,0,0,0,0,"Brother Ravenoak - In Combat - Cast 'Low Swipe'");
-- Cenarion Botanist SAI
SET @ENTRY := 4051;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cenarion Botanist - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Botanist - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Cenarion Caretaker SAI
SET @ENTRY := 4050;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Caretaker - On Aggro - Cast 'Bear Form' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,15000,11,12161,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cenarion Caretaker - Within 0-5 Range - Cast 'Maul'");
-- Cenarion Druid SAI
SET @ENTRY := 4052;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cenarion Druid - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,5759,1,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Druid - Between 0-30% Health - Cast 'Cat Form' (No Repeat)");
-- Cliff Stormer SAI
SET @ENTRY := 4008;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,11000,11,5401,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cliff Stormer - Within 0-30 Range - Cast 'Lizard Bolt'");
-- Cliffwalker Brave SAI
SET @ENTRY := 42040;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Cliffwalker Brave - In Combat - Cast 'Shoot'");
-- Cloaked Alliance Spy SAI
SET @ENTRY := 42035;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloaked Alliance Spy - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cloaked Alliance Spy - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,8000,15000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cloaked Alliance Spy - Within 0-5 Range - Cast 'Sinister Strike'"),
(@ENTRY,0,3,0,0,0,100,0,7000,9000,19000,21000,11,15691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Cloaked Alliance Spy - In Combat - Cast 'Eviscerate'");
-- Corrupted Sap Beast SAI
SET @ENTRY := 4021;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,30000,35000,11,3396,0,0,0,0,0,2,32,0,0,0,0,0,0,"Corrupted Sap Beast - In Combat - Cast 'Corrosive Poison'");
-- Corrupted Sentinel SAI
SET @ENTRY := 34969;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,36500,64,0,0,0,0,2,0,0,0,0,0,0,0,"Corrupted Sentinel - In Combat - Cast 'Glaive'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrupted Sentinel - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Councilman Stark I'ylar SAI
SET @ENTRY := 34937;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Councilman Stark I'ylar - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Councilman Stark I'ylar - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,25000,28000,11,79823,2,0,0,0,0,4,0,0,0,0,0,0,0,"Councilman Stark I'ylar - In Combat - Cast 'Starfall'"),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,81427,0,0,0,0,0,1,0,0,0,0,0,0,0,"Councilman Stark I'ylar - On Aggro - Cast 'Rhetoric' (No Repeat)"),
(@ENTRY,0,4,0,0,0,100,0,5000,5000,12000,15000,11,22823,2,0,0,0,0,2,0,0,0,0,0,0,0,"Councilman Stark I'ylar - In Combat - Cast 'Starshards'");
-- NPC talk text insert
SET @ENTRY := 34937;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Darnassian Scout SAI
SET @ENTRY := 41865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darnassian Scout - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Scout - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darnassian Scout - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,3,0,9,0,100,0,0,5,13600,14500,11,40652,0,0,0,0,0,2,0,0,0,0,0,0,0,"Darnassian Scout - Within 0-5 Range - Cast 'Wing Clip'");
-- Daughter of Cenarius SAI
SET @ENTRY := 4053;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Daughter of Cenarius - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,12000,14000,11,527,2,0,0,0,0,2,0,0,0,0,0,0,0,"Daughter of Cenarius - In Combat - Cast 'Dispel Magic'"),
(@ENTRY,0,3,0,0,0,100,0,2000,3000,9000,12000,11,527,2,0,0,0,0,1,0,0,0,0,0,0,0,"Daughter of Cenarius - In Combat - Cast 'Dispel Magic'");
-- Deepmoss Venomspitter SAI
SET @ENTRY := 4007;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,2000,15000,17000,11,7951,0,0,0,0,0,2,32,0,0,0,0,0,0,"Deepmoss Venomspitter - In Combat - Cast 'Toxic Spit'");
-- Deepmoss Webspinner SAI
SET @ENTRY := 4006;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,13000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deepmoss Webspinner - Within 0-30 Range - Cast 'Web'");
-- Emerald Spirit SAI
SET @ENTRY := 34982;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,13000,11,32909,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emerald Spirit - Within 0-5 Range - Cast 'Talon Strike'");
-- Enraged Highborne Spirit SAI
SET @ENTRY := 41231;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,11000,17800,11,43512,0,0,0,0,0,2,1,0,0,0,0,0,0,"Enraged Highborne Spirit - In Combat - Cast 'Mind Flay'");
-- Farwatcher Guardian SAI
SET @ENTRY := 41627;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Farwatcher Guardian - In Combat - Cast 'Shoot'");
-- Fey Dragon SAI
SET @ENTRY := 4016;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3500,25000,27000,11,25602,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fey Dragon - In Combat - Cast 'Faerie Fire'");
-- Fissure-born Fire Elemental SAI
SET @ENTRY := 34911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,19000,11,80549,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fissure-born Fire Elemental - In Combat - Cast 'Gout of Flame'");
-- Gatekeeper Kordurus SAI
SET @ENTRY := 4409;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Kordurus - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Gnome Engineer SAI
SET @ENTRY := 35334;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,15000,16000,11,81420,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gnome Engineer - Within 0-30 Range - Cast 'Super Shrink Ray'");
-- Goblin Harvester SAI
SET @ENTRY := 35204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32735,0,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Harvester - On Aggro - Cast 'Saw Blade' (No Repeat)");
-- Goblin Pump Controller SAI
SET @ENTRY := 41437;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,81505,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pump Controller - On Aggro - Cast 'Rocket Launched Support Shredder' (No Repeat)");
-- Grimtotem Sorcerer SAI
SET @ENTRY := 11913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20802,64,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Sorcerer - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Sorcerer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,50,18000,21000,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Sorcerer - Between 0-50% Health - Cast 'Rejuvenation'");
-- Grimtotem Ruffian SAI
SET @ENTRY := 11910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Ruffian - Out of Combat - Cast 'Lightning Shield'"),
(@ENTRY,0,1,0,16,0,100,0,19514,1,15000,30000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Ruffian - On Friendly Unit Missing Buff 'Lightning Shield' - Cast 'Lightning Shield'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,79914,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Ruffian - Between 0-50% Health - Cast 'Feral Spirit' (No Repeat)"),
(@ENTRY,0,3,0,9,0,100,0,0,30,9000,12000,11,79913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Ruffian - Within 0-30 Range - Cast 'Chain Lightning'"),
(@ENTRY,0,4,0,0,0,100,0,5000,6000,29000,35000,11,78770,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Ruffian - In Combat - Cast 'Magma Totem'");
-- Grimtotem Mercenary SAI
SET @ENTRY := 11911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,20000,25000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Mercenary - Within 0-5 Range - Cast 'Expose Armor'"),
(@ENTRY,0,1,0,2,0,100,0,0,30,15000,18000,11,79853,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Mercenary - Between 0-30% Health - Cast 'Evasion'"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,15000,19000,11,79852,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Mercenary - In Combat - Cast 'Eviscerate'"),
(@ENTRY,0,3,0,0,0,100,0,10000,12000,29000,33000,11,79851,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Mercenary - In Combat - Cast 'Fan of Knives'"),
(@ENTRY,0,4,0,0,0,100,0,2000,3000,14000,22000,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Mercenary - In Combat - Cast 'Sinister Strike'");
-- Goblin Stripminer SAI
SET @ENTRY := 41408;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,38557,64,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Stripminer - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Stripminer - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,17000,19000,11,7978,2,0,0,0,0,4,0,0,0,0,0,0,0,"Goblin Stripminer - In Combat - Cast 'Throw Dynamite'");
-- Goblin Technician SAI
SET @ENTRY := 35333;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Technician - In Combat - Cast 'Throw Dynamite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Technician - Between 0-15% Health - Flee For Assist (No Repeat)");
-- General Vaurajo SAI
SET @ENTRY := 41368;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79884,64,0,0,0,0,2,0,0,0,0,0,0,0,"General Vaurajo - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Vaurajo - Out of Combat - Cast 'Water Shield'"),
(@ENTRY,0,2,0,16,0,100,0,79892,1,15000,30000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Vaurajo - On Friendly Unit Missing Buff 'Water Shield' - Cast 'Water Shield'"),
(@ENTRY,0,3,0,9,0,100,0,0,25,15000,17000,11,79890,2,0,0,0,0,2,0,0,0,0,0,0,0,"General Vaurajo - Within 0-25 Range - Cast 'Flame Shock'"),
(@ENTRY,0,4,0,0,0,100,0,5000,9000,35000,38000,11,39591,2,0,0,0,0,1,0,0,0,0,0,0,0,"General Vaurajo - In Combat - Cast 'Searing Totem'"),
(@ENTRY,0,5,0,0,0,100,0,10000,12000,10000,13000,11,79886,2,0,0,0,0,2,0,0,0,0,0,0,0,"General Vaurajo - In Combat - Cast 'Lava Burst'");
-- General Vol'tar SAI
SET @ENTRY := 41370;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"General Vol'tar - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,15000,19000,11,80009,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Vol'tar - In Combat - Cast 'Serpent Sting'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,20000,22000,11,22910,2,0,0,0,0,1,0,0,0,0,0,0,0,"General Vol'tar - Within 0-5 Range - Cast 'Immolation Trap'");
-- Gerenzo Wrenchwhistle SAI
SET @ENTRY := 4202;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,38558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gerenzo Wrenchwhistle - On Aggro - Cast 'Throw' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,20000,11,54962,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gerenzo Wrenchwhistle - In Combat - Cast 'Ticking Bomb'");
-- Ticking Bomb SAI
SET @ENTRY := 29684;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,11,0,100,1,0,0,0,0,11,54954,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Bomb - On Respawn - Cast 'Explosion' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,41,2000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ticking Bomb - On Respawn - Despawn In 2000 ms (No Repeat)");
-- General Salaman SAI
SET @ENTRY := 41369;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,20000,25000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Salaman - Within 0-5 Range - Cast 'Expose Armor'"),
(@ENTRY,0,1,0,2,0,100,0,0,30,15000,18000,11,79853,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Salaman - Between 0-30% Health - Cast 'Evasion'"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,15000,19000,11,79852,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Salaman - In Combat - Cast 'Eviscerate'"),
(@ENTRY,0,3,0,0,0,100,0,10000,12000,29000,33000,11,79851,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Salaman - In Combat - Cast 'Fan of Knives'"),
(@ENTRY,0,4,0,0,0,100,0,2000,3000,14000,22000,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Salaman - In Combat - Cast 'Sinister Strike'");
-- Gorehoof the Black SAI
SET @ENTRY := 11914;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,15000,19000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorehoof the Black - In Combat - Cast 'War Stomp'");
-- General Grebo SAI
SET @ENTRY := 42050;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,12000,14000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Grebo - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,19000,20000,11,81378,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Grebo - In Combat - Cast 'Jump Strike'"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,15000,25000,11,78828,2,0,0,0,0,1,0,0,0,0,0,0,0,"General Grebo - In Combat - Cast 'Bladestorm'");
-- General Glubgok SAI
SET @ENTRY := 41367;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,25000,29000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Glubgok - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,0,0,100,0,12000,13000,17000,19000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Glubgok - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,2,0,0,0,100,0,2000,2000,11000,23000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"General Glubgok - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,79871,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Glubgok - Between 0-30% Health - Cast 'Recklessness' (No Repeat)"),
(@ENTRY,0,4,0,9,0,100,0,0,5,13600,14500,11,57846,0,0,0,0,0,1,0,0,0,0,0,0,0,"General Glubgok - Within 0-5 Range - Cast 'Heroic Strike'");
-- Grimtotem Brute SAI
SET @ENTRY := 11912;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,25000,29000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Brute - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,1,0,0,0,100,0,12000,13000,17000,19000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Brute - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,2,0,0,0,100,0,2000,2000,11000,23000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grimtotem Brute - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,79871,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Brute - Between 0-30% Health - Cast 'Recklessness' (No Repeat)"),
(@ENTRY,0,4,0,9,0,100,0,0,5,13600,14500,11,57846,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grimtotem Brute - Within 0-5 Range - Cast 'Heroic Strike'");
-- Guardsman Belothiel SAI
SET @ENTRY := 34939;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardsman Belothiel - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Guardsman Belothiel - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardsman Belothiel - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,2000,4500,12000,20000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Guardsman Belothiel - In Combat - Cast 'Heroic Strike'");
-- NPC talk text insert
SET @ENTRY := 34939;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);
-- Alliance Gunship Cannon SAI
SET @ENTRY := 34929;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,22000,11,43512,2,0,0,0,0,2,1,0,0,0,0,0,0,"Alliance Gunship Cannon - In Combat - Cast 'Mind Flay'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,14000,19000,11,75903,0,0,0,0,0,4,0,0,0,0,0,0,0,"Alliance Gunship Cannon - Within 0-30 Range - Cast 'Shadow Crash'");
-- High Chieftain Cliffwalker SAI
SET @ENTRY := 42039;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,21807,64,0,0,0,0,2,0,0,0,0,0,0,0,"High Chieftain Cliffwalker - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,0,0,40,14000,21000,11,32131,2,0,0,0,0,1,0,0,0,0,0,0,0,"High Chieftain Cliffwalker - Between 0-40% Health - Cast 'Rejuvenation'"),
(@ENTRY,0,2,0,0,0,100,0,5000,9000,17000,22000,11,15798,2,0,0,0,0,4,0,0,0,0,0,0,0,"High Chieftain Cliffwalker - In Combat - Cast 'Moonfire'");
-- Highborne Charlatan SAI
SET @ENTRY := 34931;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Charlatan - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Charlatan - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,30,14000,15000,11,6434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Charlatan - Between 0-30% Health - Cast 'Slice and Dice'"),
(@ENTRY,0,3,0,0,0,100,0,2000,4500,12000,20000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Highborne Charlatan - In Combat - Cast 'Heroic Strike'");
-- NPC talk text insert
SET @ENTRY := 34931;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);#
-- Highborne Sorcerer SAI
SET @ENTRY := 34932;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,51797,64,0,0,0,0,2,0,0,0,0,0,0,0,"Highborne Sorcerer - In Combat - Cast 'Arcane Blast'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,79857,2,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Sorcerer - Within 0-8 Range - Cast 'Blast Wave'");
-- Huntress Davinia SAI
SET @ENTRY := 41864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Huntress Davinia - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,1,0,100,1,3000,5000,0,0,11,81293,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huntress Davinia - Out of Combat - Cast 'Call Moonshadow' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,4500,12000,15000,11,78841,2,0,0,0,0,2,0,0,0,0,0,0,0,"Huntress Davinia - In Combat - Cast 'Aimed Shot'");
-- Huntress Illiona SAI
SET @ENTRY := 41071;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huntress Illiona - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Huntress Illiona - On Evade - Cast 'Stealth' (No Repeat)");
-- Illyanna Stonewood SAI
SET @ENTRY := 34940;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,12000,14500,11,81430,0,0,0,0,0,2,0,0,0,0,0,0,0,"Illyanna Stonewood - Within 0-30 Range - Cast 'Cold Hearted'");
-- Invading Crusher SAI
SET @ENTRY := 34961;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invading Crusher - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invading Crusher - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,62975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Invading Crusher - On Aggro - Cast 'Shadow Bolt' (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,5,30,3500,4100,11,62975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Invading Crusher - Within 5-30 Range - Cast 'Shadow Bolt' (Phase 1)");
-- Invading Tendril SAI
SET @ENTRY := 34917;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invading Tendril - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Invading Tendril - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,62975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Invading Tendril - On Aggro - Cast 'Shadow Bolt' (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,5,30,3500,4100,11,62975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Invading Tendril - Within 5-30 Range - Cast 'Shadow Bolt' (Phase 1)");
-- Kalimdor Eagle SAI
SET @ENTRY := 34886;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,11000,15000,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kalimdor Eagle - Within 0-5 Range - Cast 'Swoop'");
-- Krom'gar Assassin SAI
SET @ENTRY := 41291;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,16000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Assassin - Within 0-5 Range - Cast 'Sinister Strike'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krom'gar Assassin - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krom'gar Assassin - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,19000,11,15691,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Assassin - In Combat - Cast 'Eviscerate'");
-- Krom'gar Berserker SAI
SET @ENTRY := 35158;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,17000,21000,11,37704,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krom'gar Berserker - In Combat - Cast 'Whirlwind'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,22000,25000,11,79878,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Berserker - Within 0-5 Range - Cast 'Bloodthirst'");
-- Krom'gar Blood Guard SAI
SET @ENTRY := 41407;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Blood Guard - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krom'gar Blood Guard - In Combat - Cast 'Battle Shout'"),
(@ENTRY,0,2,0,13,0,100,0,5000,8000,20000,30000,11,34783,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krom'gar Blood Guard - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Spell Reflection'");
-- Krom'gar Enforcer SAI
SET @ENTRY := 41870;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Enforcer - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,14000,11,40505,2,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Enforcer - Within 0-5 Range - Cast 'Cleave'");
-- Krom'gar Enforcer SAI
SET @ENTRY := 42125;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Enforcer - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,14000,11,40505,2,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Enforcer - Within 0-5 Range - Cast 'Cleave'");
-- Krom'gar Enforcer SAI
SET @ENTRY := 41673;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Enforcer - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,14000,11,40505,2,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Enforcer - Within 0-5 Range - Cast 'Cleave'");
-- Krom'gar Infantry SAI
SET @ENTRY := 41062;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Infantry - On Aggro - Cast 'Throw' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,17000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Infantry - Within 0-5 Range - Cast 'Chop'");
-- Krom'gar Logger SAI
SET @ENTRY := 35160;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Logger - On Aggro - Cast 'Throw' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,9000,17000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Logger - Within 0-5 Range - Cast 'Chop'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,17000,21000,11,7978,0,0,0,0,0,4,0,0,0,0,0,0,0,"Krom'gar Logger - In Combat - Cast 'Throw Dynamite'");
-- Krom'gar Peon SAI
SET @ENTRY := 40904;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,11,76565,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Peon - On Aggro - Cast 'Throw Iron Ore' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,11,76576,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krom'gar Peon - On Aggro - Cast 'Clear Summoned Ore' (No Repeat)");
-- Krom'gar Peon SAI
SET @ENTRY := 35174;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,11,76565,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Peon - On Aggro - Cast 'Throw Iron Ore' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,1,0,0,0,0,11,76576,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krom'gar Peon - On Aggro - Cast 'Clear Summoned Ore' (No Repeat)");
-- Krom'gar Rifleman SAI
SET @ENTRY := 41230;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,77302,64,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Rifleman - In Combat - Cast 'Shoot'");
-- Krom'gar Warrior SAI
SET @ENTRY := 35161;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Krom'gar Warrior - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,15000,22000,11,81500,0,0,0,0,0,1,0,0,0,0,0,0,0,"Krom'gar Warrior - In Combat - Cast 'War Stomp'");
-- Lady Benel'derath SAI
SET @ENTRY := 34933;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Benel'derath - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,38033,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Benel'derath - Within 0-8 Range - Cast 'Frost Nova'");
-- Merchant Kendra SAI
SET @ENTRY := 34946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,74613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Merchant Kendra - In Combat - Cast 'Shoot'");
-- Lord Ro'minate SAI
SET @ENTRY := 34934;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Ro'minate - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Ro'minate - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,32319,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Ro'minate - On Respawn - Cast 'Mutilate' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,40,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Ro'minate - Between 0-40% Health - Cast 'Shadowstep' (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 34934;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy',2384);#
-- Lumbering Oaf SAI
SET @ENTRY := 40906;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,35491,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lumbering Oaf - Between 0-30% Health - Cast 'Furious Rage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lumbering Oaf - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lumbering Oaf - On Respawn - Cast 'Acidic Sweat' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,15000,21000,11,35492,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lumbering Oaf - In Combat - Cast 'Exhaustion'");
-- NPC talk text insert
SET @ENTRY := 40906;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Furious Rage',10677);
-- Malaka'jin Witch Doctor SAI
SET @ENTRY := 34807;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,3000,5000,0,0,11,66254,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malaka'jin Witch Doctor - Out of Combat - Cast 'Summon Fire Cyclone' (No Repeat)");
-- Mirkfallon Dryad SAI
SET @ENTRY := 4061;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mirkfallon Dryad - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirkfallon Dryad - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,15000,20000,11,7992,2,0,0,0,0,2,32,0,0,0,0,0,0,"Mirkfallon Dryad - In Combat - Cast 'Slowing Poison'");
-- Mirkfallon Keeper SAI
SET @ENTRY := 4056;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mirkfallon Keeper - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Mirkfallon Post Scout SAI
SET @ENTRY := 41432;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mirkfallon Post Scout - In Combat - Cast 'Shoot'");
-- Masha Cliffwalker SAI
SET @ENTRY := 42047;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,10000,13000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Masha Cliffwalker - Within 0-5 Range - Cast 'Heroic Strike'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,15000,19000,11,15576,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masha Cliffwalker - In Combat - Cast 'Whirlwind'"),
(@ENTRY,0,2,0,0,0,100,0,2000,9000,14000,25000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Masha Cliffwalker - In Combat - Cast 'Thunderclap'");
-- Marshal Paltrow SAI
SET @ENTRY := 41937;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,9000,15000,11,14517,0,0,0,0,0,2,0,0,0,0,0,0,0,"Marshal Paltrow - Within 0-5 Range - Cast 'Crusader Strike'"),
(@ENTRY,0,1,0,0,0,100,0,12000,12000,25000,29000,11,58127,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal Paltrow - In Combat - Cast 'Divine Storm'"),
(@ENTRY,0,2,0,2,0,100,0,0,30,24000,32000,11,13952,0,0,0,0,0,1,0,0,0,0,0,0,0,"Marshal Paltrow - Between 0-30% Health - Cast 'Holy Light'");
-- Master Assassin Kel'istra SAI
SET @ENTRY := 41311;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,67,0,100,0,9000,12000,0,0,11,79862,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Assassin Kel'istra - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,1,0,13,0,100,0,2000,4500,20000,30000,11,79866,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Assassin Kel'istra - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Deadly Throw'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,11000,17000,11,79863,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Assassin Kel'istra - Within 0-5 Range - Cast 'Hemorrhage'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,79864,0,0,0,0,0,2,0,0,0,0,0,0,0,"Master Assassin Kel'istra - Between 0-30% Health - Cast 'Shadowstep' (No Repeat)");
-- Nal'taszar SAI
SET @ENTRY := 4066;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,15305,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nal'taszar - In Combat - Cast 'Chain Lightning'");
-- Night Elf Mage SAI
SET @ENTRY := 35154;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,33417,64,0,0,0,0,2,0,0,0,0,0,0,0,"Night Elf Mage - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Night Elf Mage - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,6000,9000,13000,11,33462,2,0,0,0,0,2,0,0,0,0,0,0,0,"Night Elf Mage - In Combat - Cast 'Arcane Missiles'"),
(@ENTRY,0,3,0,0,0,100,0,9000,11000,27000,29000,11,33624,2,0,0,0,0,4,0,0,0,0,0,0,0,"Night Elf Mage - In Combat - Cast 'Blizzard'");
-- Northwatch Encroacher SAI
SET @ENTRY := 41935;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,11000,13000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Encroacher - Within 0-5 Range - Cast 'Heroic Strike'"),
(@ENTRY,0,1,0,13,0,100,0,2000,4500,20000,30000,11,38233,0,0,0,0,0,2,0,0,0,0,0,0,0,"Northwatch Encroacher - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");
-- Pridewing Wyvern SAI
SET @ENTRY := 4012;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,17000,21000,11,81376,0,0,0,0,0,2,32,0,0,0,0,0,0,"Pridewing Wyvern - In Combat - Cast 'Pridewing Poison'");
-- Queen Silith SAI
SET @ENTRY := 41185;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,19000,11,744,0,0,0,0,0,2,32,0,0,0,0,0,0,"Queen Silith - In Combat - Cast 'Poison'"),
(@ENTRY,0,1,0,0,0,100,0,5500,7500,25000,25000,11,81302,0,0,0,0,0,2,0,0,0,0,0,0,0,"Queen Silith - In Combat - Cast 'Spider Swarm'");
-- Raging Earth Elemental SAI
SET @ENTRY := 41993;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,36645,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Earth Elemental - On Aggro - Cast 'Throw Rock' (No Repeat)");
-- Sap Beast SAI
SET @ENTRY := 4020;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,7000,12000,11,7997,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sap Beast - Within 0-5 Range - Cast 'Sap Might'");
-- Seldarria SAI
SET @ENTRY := 34896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,11000,14000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seldarria - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,12000,12000,31000,32000,11,17294,0,0,0,0,0,2,0,0,0,0,0,0,0,"Seldarria - In Combat - Cast 'Flame Breath'"),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,29000,37000,11,15847,0,0,0,0,0,4,0,0,0,0,0,0,0,"Seldarria - In Combat - Cast 'Tail Sweep'"),
(@ENTRY,0,3,0,0,0,100,0,15000,15000,45000,55000,11,14100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Seldarria - In Combat - Cast 'Terrifying Roar'");
-- Sentinel Ambusher SAI
SET @ENTRY := 41854;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Ambusher - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Ambusher - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,15000,20000,11,24337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Ambusher - In Combat - Cast 'Ambush'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,12000,14000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Ambusher - Within 0-5 Range - Cast 'Sinister Strike'");
-- Son of Cenarius SAI
SET @ENTRY := 4057;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,3000,5000,0,0,11,7993,0,0,0,0,0,1,0,0,0,0,0,0,0,"Son of Cenarius - Out of Combat - Cast 'Summon Treant Ally' (No Repeat)");
-- Sorrow Wing SAI
SET @ENTRY := 5928;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,17000,21000,11,81376,0,0,0,0,0,2,32,0,0,0,0,0,0,"Sorrow Wing - In Combat - Cast 'Pridewing Poison'");
-- Spirit Wolf SAI
SET @ENTRY := 42855;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,5,30,11000,12000,11,58867,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spirit Wolf - Within 5-30 Range - Cast 'Spirit Wolf Leap'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,58875,0,0,0,0,0,1,0,0,0,0,0,0,0,"Spirit Wolf - On Aggro - Cast 'Spirit Walk' (No Repeat)");
-- Sister Riven SAI
SET @ENTRY := 5930;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,184,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sister Riven - On Aggro - Cast 'Fire Shield' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,20,25000,28000,11,3356,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sister Riven - Within 0-20 Range - Cast 'Flame Lash'"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,17000,19000,11,6725,0,0,0,0,0,4,0,0,0,0,0,0,0,"Sister Riven - In Combat - Cast 'Flame Spike'");
-- Subdued Kobold SAI
SET @ENTRY := 42026;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,81361,0,0,0,0,0,2,0,0,0,0,0,0,0,"Subdued Kobold - In Combat - Cast 'Ground Spike'");
-- Stonetalon Warder SAI
SET @ENTRY := 35151;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetalon Warder - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetalon Warder - On Aggro - Disable Combat Movement (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,11,36500,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonetalon Warder - On Aggro - Cast 'Glaive' (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,9,1,100,0,10,25,3500,4100,11,36500,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonetalon Warder - Within 10-25 Range - Cast 'Glaive' (Phase 1)"),
(@ENTRY,0,4,0,9,1,100,0,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetalon Warder - Within 30-100 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,5,0,9,1,100,0,9,24,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetalon Warder - Within 9-24 Range - Disable Combat Movement (Phase 1)"),
(@ENTRY,0,6,0,9,1,100,0,0,9,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetalon Warder - Within 0-9 Range - Enable Combat Movement (Phase 1)"),
(@ENTRY,0,7,0,9,1,100,0,9,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetalon Warder - Within 9-30 Range - Disable Combat Movement (Phase 1)");
-- Stonetalon Ram SAI
SET @ENTRY := 34894;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,19000,22000,11,81363,0,0,0,0,0,2,0,0,0,0,0,0,0,"Stonetalon Ram - In Combat - Cast 'Headbutt'");
-- Stonetalon Grunt SAI
SET @ENTRY := 7730;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stonetalon Grunt - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,13600,14500,11,40505,2,0,0,0,0,2,0,0,0,0,0,0,0,"Stonetalon Grunt - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetalon Grunt - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stonetalon Grunt - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 7730;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Furious Rage',10677);
-- Taskmaster Whipfang SAI
SET @ENTRY := 5932;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,13600,14500,11,16508,0,0,0,0,0,2,0,0,0,0,0,0,0,"Taskmaster Whipfang - Within 0-20 Range - Cast 'Intimidating Roar'");
-- Venture Co. Builder SAI
SET @ENTRY := 4070;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Builder - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Builder - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,16000,11,81296,2,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Builder - Within 0-5 Range - Cast 'Hammer Time'");
-- Venture Co. Holdout SAI
SET @ENTRY := 3992;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Holdout - In Combat - Cast 'Throw Dynamite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Holdout - Between 0-15% Health - Flee For Assist (No Repeat)");
-- Venture Co. Machine Smith SAI
SET @ENTRY := 3993;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7979,0,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Machine Smith - On Aggro - Cast 'Compact Harvest Reaper' (No Repeat)");
-- Wily Fey Dragon SAI
SET @ENTRY := 4017;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4500,22000,27000,11,17630,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wily Fey Dragon - In Combat - Cast 'Mana Burn'");
-- Warlord Roktrog SAI
SET @ENTRY := 41063;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warlord Roktrog - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Roktrog - In Combat - Cast 'Battle Shout'"),
(@ENTRY,0,2,0,0,0,100,0,4000,8000,15000,19000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Roktrog - In Combat - Cast 'Whirlwind'");
-- Windshear Hold Guardian SAI
SET @ENTRY := 41039;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Windshear Hold Guardian - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,14500,11,40505,2,0,0,0,0,2,0,0,0,0,0,0,0,"Windshear Hold Guardian - Within 0-5 Range - Cast 'Cleave'");
-- Windshear Overseer SAI
SET @ENTRY := 40905;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windshear Overseer - On Aggro - Cast 'Commanding Shout' (No Repeat)");
