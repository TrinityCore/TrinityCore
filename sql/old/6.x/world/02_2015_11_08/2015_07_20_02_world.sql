-- Ashenvale SAI

-- 1.
-- Akkrilus SAI
SET @ENTRY := 3773;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,9000,21000,28000,11,37628,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akkrilus - In Combat - Cast 'Fel Immolate'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,24000,38000,11,35913,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akkrilus - In Combat - Cast 'Fel Fireball'");

-- 2.
-- Apothecary Falthis SAI
SET @ENTRY := 3735;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,21067,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apothecary Falthis - In Combat - Cast 'Poison Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,19000,25000,11,78705,0,0,0,0,0,2,0,0,0,0,0,0,0,"Apothecary Falthis - In Combat - Cast 'Poison Bottle'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Apothecary Falthis - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 3.
-- Artificer SAI
SET @ENTRY := 17406;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Artificer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 4.
-- Ashenvale Assassin SAI
SET @ENTRY := 34603;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Assassin - In Combat CMC - Cast 'Shoot'");

-- 5.
-- Ashenvale Bear SAI
SET @ENTRY := 3809;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5500,12000,22000,11,84867,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Bear - In Combat - Cast 'Sundering Swipe'");

-- 6.
-- Ashenvale Scout SAI
SET @ENTRY := 34177;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Scout - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Scout - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,15000,11,78754,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Scout - Within 5-30 Range - Cast 'Arcane Shot'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,35000,40000,11,78578,2,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Scout - Within 0-5 Range - Cast 'Immolation Trap'"),
(@ENTRY,0,4,0,0,0,100,1,12000,14000,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Scout - In Combat - Cast 'Leaping Cleave' (No Repeat)");

-- 7.
-- Ashenvale Sentinel SAI
SET @ENTRY := 8015;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Sentinel - In Combat - Cast 'Shoot'");

-- 8.
-- Ashenvale Skirmisher SAI
SET @ENTRY := 34101;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Skirmisher - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,17000,22000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Skirmisher - In Combat - Cast 'Whirlwind'");

-- 9.
-- Ashenvale Skirmisher SAI
SET @ENTRY := 33193;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Skirmisher - On Aggro - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,17000,22000,11,17207,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ashenvale Skirmisher - In Combat - Cast 'Whirlwind'");

-- 10.
-- Astranaar Officer SAI
SET @ENTRY := 34420;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Astranaar Officer - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,13600,14500,11,78828,2,0,0,0,0,1,0,0,0,0,0,0,0,"Astranaar Officer - Within 0-5 Range - Cast 'Bladestorm'"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,120000,120000,11,78823,2,0,0,0,0,1,0,0,0,0,0,0,0,"Astranaar Officer - In Combat - Cast 'Commanding Shout'");

-- 11.
-- Astranaar Sentinel SAI
SET @ENTRY := 6087;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Astranaar Sentinel - In Combat - Cast 'Shoot'");

-- 12.
-- Astranaar Skirmisher SAI
SET @ENTRY := 34419;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Astranaar Skirmisher - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Astranaar Skirmisher - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,15000,11,78754,2,0,0,0,0,2,0,0,0,0,0,0,0,"Astranaar Skirmisher - Within 5-30 Range - Cast 'Arcane Shot'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,35000,40000,11,78578,2,0,0,0,0,1,0,0,0,0,0,0,0,"Astranaar Skirmisher - Within 0-5 Range - Cast 'Immolation Trap'"),
(@ENTRY,0,4,0,2,0,100,0,0,50,14000,15000,11,78826,0,0,0,0,0,1,0,0,0,0,0,0,0,"Astranaar Skirmisher - Between 0-50% Health - Cast 'Evasion'");

-- 13.
-- Befouled Water Elemental SAI
SET @ENTRY := 3917;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,120000,125000,11,6873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Befouled Water Elemental - In Combat - Cast 'Foul Chill'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,20000,25000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Befouled Water Elemental - In Combat - Cast 'Splash'");

-- 14.
-- Bleakheart Satyr SAI
SET @ENTRY := 3765;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Satyr - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Satyr - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,5500,12000,16000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bleakheart Satyr - In Combat - Cast 'Swipe'");

-- NPC talk text insert
SET @ENTRY := 3765;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 15.
-- Bleakheart Shadowstalker SAI
SET @ENTRY := 3770;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Shadowstalker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Shadowstalker - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,0,0,50,35000,40000,11,77471,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Shadowstalker - Between 0-50% Health - Cast 'Shadow Shield'"),
(@ENTRY,0,3,0,16,0,100,0,77471,40,35000,42000,11,77471,0,0,0,0,0,7,0,0,0,0,0,0,0,"Bleakheart Shadowstalker - On Friendly Unit Missing Buff 'Shadow Shield' - Cast 'Shadow Shield'"),
(@ENTRY,0,4,0,11,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Shadowstalker - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,5,0,7,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Shadowstalker - On Evade - Cast 'Stealth' (No Repeat)");

SET @ENTRY := 3770;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 16. 
-- Bleakheart Trickster SAI
SET @ENTRY := 3767;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Trickster - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Trickster - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,77457,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bleakheart Trickster - On Aggro - Cast 'Dazzling Lights' (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3767;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 17. 
-- Blink Dragon SAI
SET @ENTRY := 3815;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,80,0,0,30,14000,21000,11,8611,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blink Dragon - Between 0-30% Health - Cast 'Phase Shift'");

-- 18.
-- Bloodtooth Guard SAI
SET @ENTRY := 3932;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtooth Guard - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtooth Guard - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,77457,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodtooth Guard - On Aggro - Cast 'Dazzling Lights' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,4000,4500,12000,18000,11,78842,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodtooth Guard - In Combat - Cast 'Carnivorous Bite'");

-- NPC talk text insert
SET @ENTRY := 3932;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 19.
-- Branch Snapper SAI
SET @ENTRY := 10641;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,9000,11000,11,33844,0,0,0,0,0,2,0,0,0,0,0,0,0,"Branch Snapper - Within 0-30 Range - Cast 'Entangling Roots'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,15000,21000,11,78808,0,0,0,0,0,1,0,0,0,0,0,0,0,"Branch Snapper - In Combat - Cast 'Sunbeam'");

-- 20.
-- Captain Elendilad SAI
SET @ENTRY := 33302;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,13600,14500,11,78828,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elendilad - Within 0-5 Range - Cast 'Bladestorm'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,120000,120000,11,78823,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Elendilad - In Combat - Cast 'Commanding Shout'");

-- 21.
-- Cenarion Protector SAI
SET @ENTRY := 3797;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,300000,300000,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - Out of Combat - Cast 'Bear Form'"),
(@ENTRY,0,1,0,0,0,100,0,9000,20000,19000,24000,11,15727,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - In Combat - Cast 'Demoralizing Roar'"),
(@ENTRY,0,2,3,2,0,100,0,0,50,14000,21000,28,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - Between 0-50% Health - Remove Aura 'Bear Form'"),
(@ENTRY,0,3,0,61,0,100,0,0,50,14000,21000,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - Between 0-50% Health - Cast 'Rejuvenation'"),
(@ENTRY,0,4,0,3,0,100,0,60,100,100,100,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cenarion Protector - Between 60-100% Mana - Cast 'Bear Form'");

-- 22.
-- Chief Bombgineer Sploder SAI
SET @ENTRY := 34591;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,8858,64,0,0,0,0,2,0,0,0,0,0,0,0,"Chief Bombgineer Sploder - In Combat - Cast 'Bomb'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,81418,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Bombgineer Sploder - Within 0-8 Range - Cast 'Goblin Sapper Charge'");

-- 23.
-- Chief Murgut SAI
SET @ENTRY := 12918;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Murgut - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,2,6,0,100,1,0,0,0,0,11,20818,3,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Murgut - On Just Died - Cast 'Summon Foulweald Totem Basket' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,0,0,0,1,1,3,0,0,0,0,1,0,0,0,0,0,0,0,"Chief Murgut - On Just Died - Say Line 1 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 12918;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, 'You are a little gnat to the Foulweald!  Die!',12,0,100,0,0,0, 'on Aggro Text', 8350),
(@ENTRY,1,0, 'No!  You cannot be stronger than the Foulweald!  No!!',12,0,100,0,0,0, 'on Death Text', 8351);

-- 24.
-- Clattering Crawler SAI
SET @ENTRY := 3812;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,20000,11,78744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Clattering Crawler - In Combat - Cast 'Bubblebeam'");

-- 25.
-- Crazed Ancient SAI
SET @ENTRY := 3834;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,30500,80000,11,6909,32,0,0,0,0,2,0,0,0,0,0,0,0,"Crazed Ancient - Within 0-5 Range - Cast 'Curse of Thorns'");

-- 26.
-- Dal Bloodclaw SAI
SET @ENTRY := 3987;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dal Bloodclaw - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,14000,17000,11,77558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dal Bloodclaw - Within 0-5 Range - Cast 'Bloody Strike'"),
(@ENTRY,0,2,0,2,0,100,1,0,50,0,0,11,21049,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dal Bloodclaw - Between 0-50% Health - Cast 'Bloodlust' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dal Bloodclaw - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dal Bloodclaw - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3987;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 27.
-- Emerald Raptor SAI
SET @ENTRY := 6075;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,75,22000,32000,11,17173,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emerald Raptor - Between 0-75% Health - Cast 'Drain Life'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,12000,18000,11,37624,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emerald Raptor - In Combat - Cast 'Carrion Swarm'"),
(@ENTRY,0,2,3,2,0,100,1,0,50,0,0,39,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emerald Raptor - Between 0-50% Health - Call For Help (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emerald Raptor - Between 0-50% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 6075;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s calls for help!',16,0,100,0,0,0, 'emote Text', 2541);

-- 28.
-- Dreamstalker SAI
SET @ENTRY := 12498;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,27000,32000,11,20667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dreamstalker - In Combat - Cast 'Corrosive Acid Breath'");

-- 29.
-- Durak SAI
SET @ENTRY := 44414;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,79932,64,0,0,0,0,2,0,0,0,0,0,0,0,"Durak - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,1,0,100,1,3000,5000,0,0,11,30842,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durak - Out of Combat - Cast 'Summon Felhunter' (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,79934,0,0,0,0,0,1,0,0,0,0,0,0,0,"Durak - Out of Combat - Cast 'Demon Armor'"),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,22000,27000,11,79930,2,0,0,0,0,2,0,0,0,0,0,0,0,"Durak - In Combat - Cast 'Corruption'"),
(@ENTRY,0,4,0,2,0,100,0,0,40,14000,21000,11,79933,1,0,0,0,0,2,0,0,0,0,0,0,0,"Durak - Between 0-40% Health - Cast 'Drain Life'");

-- 30.
-- Duriel Moonfire SAI
SET @ENTRY := 12860;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,19000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duriel Moonfire - Within 0-5 Range - Cast 'Pierce Armor'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,17000,25000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Duriel Moonfire - In Combat - Cast 'Knockdown'");

-- 31.
-- Eck'alom SAI
SET @ENTRY := 10642;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,120000,125000,11,6873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Eck'alom - In Combat - Cast 'Foul Chill'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,20000,25000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Eck'alom - In Combat - Cast 'Splash'");

-- 32.
-- Elder Ashenvale Bear SAI
SET @ENTRY := 3810;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,84867,0,0,0,0,0,2,0,0,0,0,0,0,0,"Elder Ashenvale Bear - In Combat - Cast 'Sundering Swipe'");

-- 33.
-- Summoned Felhunter SAI
SET @ENTRY := 6268;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Felhunter - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,300000,300000,11,6922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Felhunter - In Combat - Cast 'Curse of the Shadowhorn'");

-- 34.
-- Elenna Edune SAI
SET @ENTRY := 24738;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Elenna Edune - In Combat - Cast 'Shoot'");

-- 35.
-- Emeraldon Boughguard SAI
SET @ENTRY := 12474;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emeraldon Boughguard - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,13000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emeraldon Boughguard - In Combat - Cast 'Mortal Strike'");

-- 36.
-- Emeraldon Oracle SAI
SET @ENTRY := 12476;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,9000,18000,11,9591,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emeraldon Oracle - In Combat - Cast 'Acid Spit'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,20000,21000,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Emeraldon Oracle - Between 0-50% Health - Cast 'Rejuvenation'");

-- 37.
-- Emeraldon Tree Warder SAI
SET @ENTRY := 12475;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,12000,14000,11,78921,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emeraldon Tree Warder - In Combat - Cast 'Dream Lash'");

-- 38.
-- Enraged Foulweald SAI
SET @ENTRY := 12921;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6816,0,0,0,0,0,2,0,0,0,0,0,0,0,"Enraged Foulweald - On Aggro - Cast 'Corrupted Strength' (No Repeat)");

-- 39.
-- Evenar Stillwhisper SAI
SET @ENTRY := 33204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Evenar Stillwhisper - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,22000,25000,11,11639,2,0,0,0,0,2,0,0,0,0,0,0,0,"Evenar Stillwhisper - In Combat - Cast 'Shadow Word: Pain'");

-- 40.
-- Felmusk Felsworn SAI
SET @ENTRY := 3762;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32707,64,0,0,0,0,2,0,0,0,0,0,0,0,"Felmusk Felsworn - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,0,0,100,0,7000,8000,22000,26000,11,11962,2,0,0,0,0,2,0,0,0,0,0,0,0,"Felmusk Felsworn - In Combat - Cast 'Immolate'"),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,600000,600000,11,6942,2,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Felsworn - In Combat - Cast 'Overwhelming Stench'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Felsworn - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Felsworn - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3762;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 41.
-- Felmusk Satyr SAI
SET @ENTRY := 3758;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,12000,19500,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felmusk Satyr - In Combat - Cast 'Swipe'"),
(@ENTRY,0,1,0,0,0,100,0,10000,12000,600000,600000,11,6942,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Satyr - In Combat - Cast 'Overwhelming Stench'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Satyr - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Satyr - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3758;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 42.
-- Felmusk Shadowstalker SAI
SET @ENTRY := 3763;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Felmusk Shadowstalker - In Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Shadowstalker - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,7,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Shadowstalker - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,10000,12000,600000,600000,11,6942,2,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Shadowstalker - In Combat - Cast 'Overwhelming Stench'"),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Shadowstalker - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felmusk Shadowstalker - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3763;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 43.
-- Felslayer SAI
SET @ENTRY := 3774;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,5000,12000,14000,11,13321,0,0,0,0,0,2,0,0,0,0,0,0,0,"Felslayer - In Combat - Cast 'Mana Burn'");

-- 44.
-- Forsaken Herbalist SAI
SET @ENTRY := 3733;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,40,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Forsaken Herbalist - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5500,21000,25000,11,78705,0,0,0,0,0,2,0,0,0,0,0,0,0,"Forsaken Herbalist - In Combat - Cast 'Poison Bottle'");

-- NPC talk text insert
SET @ENTRY := 3733;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Some nice contagion of rot for you, my pretty?',12,0,50,0,0,0, 'on Aggro Text', 33329),
(@ENTRY,0,1, 'You will not stop us, filthy $R!',12,0,50,0,0,0, 'on Aggro Text', 33328),
(@ENTRY,0,2, 'What are you doing here?',12,0,50,0,0,0, 'on Aggro Text', 33330);

-- 45.
-- Foulweald Pathfinder SAI
SET @ENTRY := 3745;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Foulweald Pathfinder - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,18000,21000,11,6817,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Pathfinder - Within 0-8 Range - Cast 'Corrupted Agility'");

-- 46.
-- Foulweald Totemic SAI
SET @ENTRY := 3750;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Totemic - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,8,18000,21000,11,6817,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Totemic - Within 0-8 Range - Cast 'Corrupted Agility'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,24000,26000,11,39591,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Totemic - In Combat - Cast 'Searing Totem'");

-- 47.
-- Foulweald Warrior SAI
SET @ENTRY := 3743;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Warrior - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Warrior - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,18000,21000,11,6816,0,0,0,0,0,1,0,0,0,0,0,0,0,"Foulweald Warrior - Within 0-8 Range - Cast 'Corrupted Strength'");

-- NPC talk text insert
SET @ENTRY := 3743;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 48.
-- Gaivan Shadewalker SAI
SET @ENTRY := 33777;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gaivan Shadewalker - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gaivan Shadewalker - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,4500,12000,15000,11,31289,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gaivan Shadewalker - In Combat - Cast 'Claw'");

-- 49.
-- Ghostpaw Howler SAI
SET @ENTRY := 3824;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,9000,22000,31000,11,3264,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Howler - In Combat - Cast 'Blood Howl'");

-- 50.
-- Ghostpaw Runner SAI
SET @ENTRY := 3823;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78703,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Runner - On Aggro - Cast 'Ghostform' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,15000,21000,11,78702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Runner - In Combat - Cast 'Arcane Explosion'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Runner - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Runner - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3823;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 51.
-- Ghostpaw Alpha SAI
SET @ENTRY := 3825;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78703,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Alpha - On Aggro - Cast 'Ghostform' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,15000,21000,11,78702,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Alpha - In Combat - Cast 'Arcane Explosion'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Alpha - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ghostpaw Alpha - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3825;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 52.
-- Goblin Deforester SAI
SET @ENTRY := 11684;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,12000,18000,17000,21000,11,18546,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Deforester - In Combat - Cast 'Overdrive'");

-- 53.
-- Goblin Technician SAI
SET @ENTRY := 34590;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Goblin Technician - In Combat - Cast 'Throw Dynamite'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Technician - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 54.
-- Geltharis SAI
SET @ENTRY := 4619;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,"Geltharis - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,25000,29000,11,37628,2,0,0,0,0,2,0,0,0,0,0,0,0,"Geltharis - In Combat - Cast 'Fel Immolate'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,45000,50000,11,7098,2,0,0,0,0,2,0,0,0,0,0,0,0,"Geltharis - In Combat - Cast 'Curse of Mending'"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,6925,2,0,0,0,0,1,0,0,0,0,0,0,0,"Geltharis - Between 0-30% Health - Cast 'Gift of the Xavian' (No Repeat)");

-- 55.
-- Gorgannon SAI
SET @ENTRY := 17300;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,15000,32000,11,9613,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorgannon - Within 0-40 Range - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,24000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorgannon - Within 0-5 Range - Cast 'Knockdown'"),
(@ENTRY,0,2,3,2,0,100,1,0,50,0,0,39,20,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorgannon - Between 0-50% Health - Call For Help (No Repeat)"),
(@ENTRY,0,3,0,61,0,100,1,0,50,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gorgannon - Between 0-50% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,4,0,0,0,100,0,8000,9000,24000,32000,11,37624,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gorgannon - In Combat - Cast 'Carrion Swarm'");

-- NPC talk text insert
SET @ENTRY := 17300;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s calls for help!',16,0,100,0,0,0, 'emote Text',2541);

-- 56.
-- Guardian Gurtar SAI
SET @ENTRY := 34242;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Guardian Gurtar - In Combat - Cast 'Shoot'");

-- 57.
-- Harbinger Aphotic SAI
SET @ENTRY := 33444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,24000,32000,11,75073,0,0,0,0,0,1,0,0,0,0,0,0,0,"Harbinger Aphotic - Within 0-8 Range - Cast 'Shadow Nova'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,75903,0,0,0,0,0,2,0,0,0,0,0,0,0,"Harbinger Aphotic - On Aggro - Cast 'Shadow Crash' (No Repeat)");

-- 58.
-- Hellscream Grunt SAI
SET @ENTRY := 43653;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hellscream Grunt - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,14000,17000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hellscream Grunt - Within 0-5 Range - Cast 'Cleave'");

-- 59.
-- Heretic Emissary SAI
SET @ENTRY := 25951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Heretic Emissary - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heretic Emissary - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heretic Emissary - Out of Combat - Cast 'Frost Armor'");

-- 60.
-- Ice Caller Briatha SAI
SET @ENTRY := 25949;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20792,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ice Caller Briatha - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ice Caller Briatha - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,500,1000,600000,600000,11,12544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ice Caller Briatha - Out of Combat - Cast 'Frost Armor'");

-- 61.
-- Illiyana Moonblaze SAI
SET @ENTRY := 14753;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,22907,64,0,0,0,0,2,0,0,0,0,0,0,0,"Illiyana Moonblaze - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-15% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,5,9,0,100,0,5,30,22000,27000,11,21390,2,0,0,0,0,2,0,0,0,0,0,0,0,"Illiyana Moonblaze - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,4,0,9,0,100,0,0,20,5000,9000,11,6533,2,0,0,0,0,2,0,0,0,0,0,0,0,"Illiyana Moonblaze - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,6,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Illiyana Moonblaze - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 14753;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzy', 2384);

-- 62.
-- Keeper Heartwise SAI
SET @ENTRY := 33443;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,63032,0,0,0,0,0,2,0,0,0,0,0,0,0,"Keeper Heartwise - In Combat - Cast 'Starfire'");

-- 63.
-- Keeper Ordanus SAI
SET @ENTRY := 4273;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Keeper Ordanus - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,9000,11000,11,12747,2,0,0,0,0,2,0,0,0,0,0,0,0,"Keeper Ordanus - Within 0-30 Range - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Keeper Ordanus - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 4273;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 64.
-- Kaliva SAI
SET @ENTRY := 34602;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,81651,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kaliva - In Combat - Cast 'Vile Beam'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,19000,28000,11,81650,0,0,0,0,0,4,0,0,0,0,0,0,0,"Kaliva - In Combat - Cast 'Sinful Beam'");

-- 65.
-- Kaldorei Assassin SAI
SET @ENTRY := 34206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kaldorei Assassin - On Aggro - Cast 'Sprint' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,12000,18000,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kaldorei Assassin - In Combat - Cast 'Sinister Strike'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,15000,22000,11,60850,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kaldorei Assassin - In Combat - Cast 'Mutilate'"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,33000,35000,11,3583,0,0,0,0,0,2,32,0,0,0,0,0,0,"Kaldorei Assassin - In Combat - Cast 'Deadly Poison'");

-- 66.
-- Lady Vespia SAI
SET @ENTRY := 10559;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lady Vespia - In Combat - Cast 'Water Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Vespia - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,10,15000,16000,11,78542,2,0,0,0,0,1,0,0,0,0,0,0,0,"Lady Vespia - Within 0-10 Range - Cast 'Splash'");

-- 67.
-- Lava Rager SAI
SET @ENTRY := 34314;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,9000,25000,32000,11,11829,0,0,0,0,0,4,0,0,0,0,0,0,0,"Lava Rager - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,17000,21000,11,75068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lava Rager - In Combat - Cast 'Lava Burst'");

-- 68.
-- Lesser Felguard SAI
SET @ENTRY := 3772;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,14000,19000,11,18812,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lesser Felguard - Within 0-5 Range - Cast 'Knockdown'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4500,66000,77000,11,184,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lesser Felguard - In Combat - Cast 'Fire Shield'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lesser Felguard - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lesser Felguard - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3772;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage', 10677);

-- 69.
-- Lord Magmathar SAI
SET @ENTRY := 34295;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,10000,20000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Magmathar - Out of Combat - Say Line 0"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Magmathar - On Aggro - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,2000,15000,18000,11,65214,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Magmathar - In Combat - Cast 'Lordly Immolate'"),
(@ENTRY,0,3,0,0,0,100,0,4000,5000,17000,20000,11,65215,2,0,0,0,0,4,0,0,0,0,0,0,0,"Lord Magmathar - In Combat - Cast 'Infernal Conflagration'");

-- NPC talk text insert
SET @ENTRY := 34295;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I am free of the bonds of the earth never to return again!',14,0,50,0,0,0, 'say Text',34507),
(@ENTRY,0,1, 'Like moths to the flame!',14,0,50,0,0,0, 'say Text',34509),
(@ENTRY,0,2, 'Scorch the ground, boil the water, and ignite the skies!',14,0,50,0,0,0, 'say Text', 34504),
(@ENTRY,0,3, 'There is no escape! There is only the fiery embrace of my lava!',14,0,50,0,0,0, 'say Text',34502),
(@ENTRY,0,4, 'Death rises from below and erupts from above! There is no escape!',14,0,50,0,0,0, 'say Text', 34503),
(@ENTRY,0,5, 'The Earthen Ring cannot withstand my fury!',14,0,50,0,0,0,'say Text', 34505),
(@ENTRY,0,6, 'Destroy them my minions!',14,0,50,0,0,0, 'say Text',34506),
(@ENTRY,0,7, 'ASHENVALE WILL BURN!',14,0,50,0,0,0, 'say Text',34508);

-- 70.
-- Mannoroc Lasher SAI
SET @ENTRY := 11697;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mannoroc Lasher - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,18000,24000,11,18543,2,0,0,0,0,2,0,0,0,0,0,0,0,"Mannoroc Lasher - In Combat - Cast 'Flame Lash'");

-- 71.
-- Mavoris Cloudsbreak SAI
SET @ENTRY := 3942;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,12058,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mavoris Cloudsbreak - In Combat - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,7000,8000,25000,29000,11,6535,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mavoris Cloudsbreak - In Combat - Cast 'Lightning Cloud'");

-- 72.
-- Mist Howler SAI
SET @ENTRY := 10644;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,10000,18000,21000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mist Howler - In Combat - Cast 'Tendon Rip'"),
(@ENTRY,0,1,0,0,0,100,0,16000,20000,30000,35000,11,8715,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mist Howler - In Combat - Cast 'Terrifying Howl'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,20000,25000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mist Howler - Within 0-5 Range - Cast 'Rend'");

-- 73.
-- Moon Priestess Maestra SAI
SET @ENTRY := 33276;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,"Moon Priestess Maestra - In Combat - Cast 'Holy Smite'"),
(@ENTRY,0,1,0,0,0,100,0,15000,18000,25000,30000,11,17140,2,0,0,0,0,2,0,0,0,0,0,0,0,"Moon Priestess Maestra - In Combat - Cast 'Holy Fire'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,11642,2,0,0,0,0,1,0,0,0,0,0,0,0,"Moon Priestess Maestra - Between 0-40% Health - Cast 'Heal'");

-- 74.
-- Mystlash Hydra SAI
SET @ENTRY := 3721;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,4000,8000,11,6917,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mystlash Hydra - In Combat - Cast 'Venom Spit'");

-- 75.
-- Oakpaw SAI
SET @ENTRY := 10640;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,11000,12000,11,6819,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oakpaw - In Combat - Cast 'Corrupted Stamina'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,19000,25000,11,12160,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oakpaw - Between 0-50% Health - Cast 'Rejuvenation'");

-- 76.
-- Orc Overseer SAI
SET @ENTRY := 3734;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,34000,35000,11,78710,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orc Overseer - In Combat - Cast 'Threatening Shout'"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,43,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orc Overseer - On Aggro - Dismount (No Repeat)"),
(@ENTRY,0,2,0,1,0,30,0,1000,1000,25000,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orc Overseer - Out of Combat - Say Line 0"),
(@ENTRY,0,3,0,4,0,30,1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orc Overseer - On Aggro - Say Line 1 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3734;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'They say there\'s no rest for the wicked. That means you!',12,0,50,0,0,0, 'say Text', 33316),
(@ENTRY,0,1, 'How special... you\'re good at picking flowers. Are you going to send me a bouquet? Hahahaha!',12,0,50,0,0,0, 'say Text',33322),
(@ENTRY,0,2, 'This is coward''s work. We should be crushing the Alliance now!',12,0,50,0,0,0, 'say Text',33317),
(@ENTRY,0,3, 'Work faster for the glory of the Horde!',12,0,50,0,0,0, 'say Text',33320),
(@ENTRY,0,4, 'Warchief Hellscream will have your head if you don\'t pick up the pace,Forsaken!',12,0,50,0,0,0, 'say Text',33321),
(@ENTRY,1,0, 'I\'ll crush you, puny $R!',12,0,100,0,0,0, 'say Text',33332);

-- 77.
-- Orendil Broadleaf SAI
SET @ENTRY := 3847;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,14000,21000,11,62804,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orendil Broadleaf - Between 0-40% Health - Cast 'Rejuvenation'");

-- 78.
-- Orux Thrice-Damned SAI
SET @ENTRY := 33356;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32707,64,0,0,0,0,2,0,0,0,0,0,0,0,"Orux Thrice-Damned - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,1,0,100,1,3000,5000,0,0,11,11939,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orux Thrice-Damned - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,1,7000,9000,0,0,11,62856,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orux Thrice-Damned - Out of Combat - Cast 'Detect Invisibility' (No Repeat)"),
(@ENTRY,0,3,0,0,0,100,0,7000,8000,17000,22000,11,11962,2,0,0,0,0,2,0,0,0,0,0,0,0,"Orux Thrice-Damned - In Combat - Cast 'Immolate'"),
(@ENTRY,0,4,5,1,0,100,0,500,500,20000,35000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orux Thrice-Damned - Out of Combat - Say Line 0"),
(@ENTRY,0,5,0,61,0,100,1,500,500,20000,35000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Orux Thrice-Damned - Out of Combat - Say Line 1");

-- NPC talk text insert
SET @ENTRY := 33356;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'I want that one killed! The one right there that doesn\'t look like the others!',14,0,50,0,0,0, 'say Text',33481),
(@ENTRY,0,1, 'Smash them! Destroy them! Lok\'tar ogar!',14,0,50,0,0,0, 'say Text',33479),
(@ENTRY,0,2, 'There is no blood easier spilt than that of a puny night elf!',14,0,50,0,0,0, 'say Text',33483),
(@ENTRY,1,0, 'Pathetic weakling. You will die quickly!',12,0,100,0,0,0, 'say Text',33475);

-- 79.
-- Oso Bramblescar SAI
SET @ENTRY := 34499;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oso Bramblescar - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,29000,35000,11,87185,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oso Bramblescar - In Combat - Cast 'Demoralizing Roar'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oso Bramblescar - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oso Bramblescar - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 34499;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 80.
-- Overseer Gorthak SAI
SET @ENTRY := 17304;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Gorthak - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,13,0,100,0,5000,8000,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Overseer Gorthak - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");

-- 81.
-- Painmaster Thundrak SAI
SET @ENTRY := 39096;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,19000,22000,11,81419,0,0,0,0,0,1,0,0,0,0,0,0,0,"Painmaster Thundrak - In Combat - Cast 'The Painhammer'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,33958,0,0,0,0,0,1,0,0,0,0,0,0,0,"Painmaster Thundrak - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Painmaster Thundrak - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 39096;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 82.
-- Phantim SAI
SET @ENTRY := 5314;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,12000,19000,11,20667,0,0,0,0,0,2,0,0,0,0,0,0,0,"Phantim - In Combat - Cast 'Corrosive Acid Breath'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,24000,32000,11,20671,0,0,0,0,0,1,0,0,0,0,0,0,0,"Phantim - Between 0-50% Health - Cast 'Summon Phantim Illusion'");

-- 83.
-- Prince Raze SAI
SET @ENTRY := 10647;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Raze - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,11969,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - Within 0-8 Range - Cast 'Fire Nova'"),
(@ENTRY,0,2,0,1,0,100,0,8000,9000,25000,32000,11,16570,1,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Raze - Out of Combat - Cast 'Charged Arcane Bolt'");

-- 84.
-- Protector Arminon SAI
SET @ENTRY := 34204;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Arminon - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Arminon - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,15000,11,22822,2,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Arminon - Within 5-30 Range - Cast 'Starshards'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,25000,28000,11,78828,2,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Arminon - Within 0-5 Range - Cast 'Bladestorm'"),
(@ENTRY,0,4,0,0,0,100,1,12000,14000,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Arminon - In Combat - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,5,0,0,0,100,0,8000,9000,300000,300000,11,78823,2,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Arminon - In Combat - Cast 'Commanding Shout'");

-- 85.
-- Protector Dorinar SAI
SET @ENTRY := 34294;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78823,0,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Dorinar - On Aggro - Cast 'Commanding Shout' (No Repeat)"),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,19000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Dorinar - Within 0-5 Range - Cast 'Expose Armor'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,11000,14000,11,78826,0,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Dorinar - Between 0-40% Health - Cast 'Evasion'");

-- 86.
-- Protector Endolar SAI
SET @ENTRY := 34208;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Endolar - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Endolar - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,15000,11,22822,2,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Endolar - Within 5-30 Range - Cast 'Starshards'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,25000,28000,11,78828,2,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Endolar - Within 0-5 Range - Cast 'Bladestorm'"),
(@ENTRY,0,4,0,0,0,100,1,12000,14000,0,0,11,78894,0,0,0,0,0,2,0,0,0,0,0,0,0,"Protector Endolar - In Combat - Cast 'Leaping Cleave' (No Repeat)"),
(@ENTRY,0,5,0,0,0,100,0,8000,9000,300000,300000,11,78823,2,0,0,0,0,1,0,0,0,0,0,0,0,"Protector Endolar - In Combat - Cast 'Commanding Shout'");

-- 87.
-- Raene Wolfrunner SAI
SET @ENTRY := 3691;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Raene Wolfrunner - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,20,8000,9000,11,6533,2,0,0,0,0,2,0,0,0,0,0,0,0,"Raene Wolfrunner - Within 0-20 Range - Cast 'Net'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,19000,11,15495,2,0,0,0,0,2,0,0,0,0,0,0,0,"Raene Wolfrunner - Within 5-30 Range - Cast 'Explosive Shot'"),
(@ENTRY,0,3,0,9,0,100,0,5,30,22000,27000,11,22908,2,0,0,0,0,4,0,0,0,0,0,0,0,"Raene Wolfrunner - Within 5-30 Range - Cast 'Volley'");

-- 88.
-- Raging Ancient SAI
SET @ENTRY := 33688;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,13600,14500,11,11922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Ancient - Within 0-30 Range - Cast 'Entangling Roots'"),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,17000,25000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Raging Ancient - In Combat - Cast 'War Stomp'");

-- 89.
-- Ran Bloodtooth SAI
SET @ENTRY := 3696;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ran Bloodtooth - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,2,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-15% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,9,0,100,0,0,5,15000,25000,11,78842,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ran Bloodtooth - Within 0-5 Range - Cast 'Carnivorous Bite'"),
(@ENTRY,0,4,5,9,0,100,0,5,30,9000,22000,11,78841,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ran Bloodtooth - Within 5-30 Range - Cast 'Aimed Shot'"),
(@ENTRY,0,5,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,6,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ran Bloodtooth - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3696;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 90.
-- Reef Shark SAI
SET @ENTRY := 12123;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,15000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Reef Shark - In Combat - Cast 'Thrash'");

-- 91.
-- Roaming Felguard SAI
SET @ENTRY := 6115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,12000,19000,11,22859,0,0,0,0,0,2,0,0,0,0,0,0,0,"Roaming Felguard - In Combat - Cast 'Mortal Cleave'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Roaming Felguard - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Roaming Felguard - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 6115;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 92.
-- Rorgish Jowl SAI
SET @ENTRY := 10639;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rorgish Jowl - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,19000,27000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rorgish Jowl - In Combat - Cast 'Thunderclap'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,3490,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rorgish Jowl - Between 0-30% Health - Cast 'Frenzied Rage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rorgish Jowl - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 10639;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzied Rage',10677);

-- 93.
-- Rotting Slime SAI
SET @ENTRY := 3928;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,34000,39000,11,6907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rotting Slime - In Combat - Cast 'Diseased Slime'"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,6464,3,0,0,0,0,1,0,0,0,0,0,0,0,"Rotting Slime - On Just Died - Cast 'Summon Rusty Chest' (No Repeat)");

-- 94.
-- Ruuzel SAI
SET @ENTRY := 3943;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,20000,11,77522,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ruuzel - Within 0-5 Range - Cast 'Swoop'"),
(@ENTRY,0,1,0,9,0,100,0,0,30,28000,32000,11,78747,0,0,0,0,0,2,1,0,0,0,0,0,0,"Ruuzel - Within 0-30 Range - Cast 'Hand of Azshara'");

-- 95.
-- Searing Infernal SAI
SET @ENTRY := 6073;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,18000,22000,11,36247,0,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Infernal - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,15000,15000,11,32749,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Infernal - In Combat - Cast 'Fire Shield'");

-- 96.
-- Sentinel Farsong SAI
SET @ENTRY := 14733;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Farsong - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,12000,17000,11,15496,2,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Farsong - Within 0-5 Range - Cast 'Cleave'");

-- 97.
-- Sentinel Shyela SAI
SET @ENTRY := 33187;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,13600,14500,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Shyela - Within 0-5 Range - Cast 'Heroic Strike'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,25000,32000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sentinel Shyela - In Combat - Cast 'Demoralizing Shout'"),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,12000,17000,11,32736,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sentinel Shyela - In Combat - Cast 'Mortal Strike'");

-- 98.
-- Severed Druid SAI
SET @ENTRY := 3799;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Severed Druid - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,0,0,55,20000,34000,11,12160,2,0,0,0,0,1,0,0,0,0,0,0,0,"Severed Druid - Between 0-55% Health - Cast 'Rejuvenation'");

-- 99.
-- Severed Keeper SAI
SET @ENTRY := 3803;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,78907,64,0,0,0,0,2,0,0,0,0,0,0,0,"Severed Keeper - In Combat - Cast 'Starfire'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,24000,28000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Severed Keeper - In Combat - Cast 'Moonfire'");

-- 100.
-- Shadethicket Bark Ripper SAI
SET @ENTRY := 3784;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,24000,31000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadethicket Bark Ripper - In Combat - Cast 'Tendon Rip'");

-- 101.
-- Shadethicket Raincaller SAI
SET @ENTRY := 3783;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,12000,17000,11,9532,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadethicket Raincaller - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,24000,35000,11,32193,0,0,0,0,0,4,0,0,0,0,0,0,0,"Shadethicket Raincaller - In Combat - Cast 'Lightning Cloud'");

-- 102.
-- Shadethicket Stone Mover SAI
SET @ENTRY := 3782;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,16000,32000,11,6864,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadethicket Stone Mover - In Combat - Cast 'Strength of Stone'");

-- 103.
-- Shadethicket Wood Shaper SAI
SET @ENTRY := 3781;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,17000,32000,11,12747,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadethicket Wood Shaper - Within 0-30 Range - Cast 'Entangling Roots'");

-- 104.
-- Shadowhorn Stag SAI
SET @ENTRY := 3817;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6921,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowhorn Stag - On Aggro - Cast 'Shadowhorn Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,300000,300000,11,6922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowhorn Stag - In Combat - Cast 'Curse of the Shadowhorn'");

-- 105.
-- Shadumbra SAI
SET @ENTRY := 12677;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,15000,22000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadumbra - In Combat - Cast 'Rend'");

-- 106.
-- Shady Nook Guardian SAI
SET @ENTRY := 34500;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shady Nook Guardian - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,29000,38000,11,87185,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shady Nook Guardian - In Combat - Cast 'Demoralizing Roar'");

-- 107.
-- Sharptalon SAI
SET @ENTRY := 12676;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,9000,21000,28000,11,12097,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sharptalon - In Combat - Cast 'Pierce Armor'");

-- 108.
-- Shindrell Swiftfire SAI
SET @ENTRY := 3845;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shindrell Swiftfire - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,5,22000,25000,11,32908,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shindrell Swiftfire - Within 0-5 Range - Cast 'Wing Clip'"),
(@ENTRY,0,2,5,9,0,100,0,5,15,15000,22000,11,23601,2,0,0,0,0,2,0,0,0,0,0,0,0,"Shindrell Swiftfire - Within 5-15 Range - Cast 'Scatter Shot'");

-- 109.
-- Silverwind Conqueror SAI
SET @ENTRY := 34592;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwind Conqueror - In Combat - Cast 'Battle Shout'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwind Conqueror - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwind Conqueror - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 34592;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 110.
-- Silverwind Vanquisher SAI
SET @ENTRY := 43657;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,120000,120000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwind Vanquisher - In Combat - Cast 'Battle Shout'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwind Vanquisher - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwind Vanquisher - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 43657;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 111.
-- Silverwing Elite SAI
SET @ENTRY := 14715;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Elite - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,0,5,12000,22000,11,15496,2,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Elite - Within 0-5 Range - Cast 'Cleave'");

-- 112.
-- Silverwing Sentinel SAI
SET @ENTRY := 12896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Sentinel - In Combat - Cast 'Shoot'");

-- 113.
-- Silverwing Warrior SAI
SET @ENTRY := 12897;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,20000,29500,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Warrior - Within 0-5 Range - Cast 'Rend'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Warrior - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 114.
-- Singed Shambler SAI
SET @ENTRY := 3780;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,120000,125000,11,78810,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singed Shambler - In Combat - Cast 'Smouldering'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,15000,21000,11,78808,0,0,0,0,0,1,0,0,0,0,0,0,0,"Singed Shambler - In Combat - Cast 'Sunbeam'");

-- 115.
-- Splintertree Guard SAI
SET @ENTRY := 34052;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Splintertree Guard - In Combat - Cast 'Shoot'");

-- 116.
-- Splintertree Guard SAI
SET @ENTRY := 12903;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Splintertree Guard - In Combat - Cast 'Shoot'");

-- 117.
-- Splintertree Raider SAI
SET @ENTRY := 12859;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Splintertree Raider - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 12859;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);

-- 118.
-- Stardust Sentinel SAI
SET @ENTRY := 39254;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Stardust Sentinel - In Combat - Cast 'Shoot'");

-- 119.
-- Talen SAI
SET @ENTRY := 3846;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,20000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talen - In Combat - Cast 'Strike'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,25000,29000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Talen - In Combat - Cast 'Rend'");

-- 120.
-- Velinde Starsong SAI
SET @ENTRY := 3946;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,25000,32000,11,13860,0,0,0,0,0,2,0,0,0,0,0,0,0,"Velinde Starsong - In Combat - Cast 'Mind Blast'"),
(@ENTRY,0,1,0,0,0,100,0,5000,12000,15000,27000,11,16568,0,0,0,0,0,2,0,0,0,0,0,0,0,"Velinde Starsong - In Combat - Cast 'Mind Flay'"),
(@ENTRY,0,2,0,2,0,100,0,0,50,17000,21000,11,11640,0,0,0,0,0,1,0,0,0,0,0,0,0,"Velinde Starsong - Between 0-50% Health - Cast 'Renew'");

-- 121.
-- Tendril from Below SAI
SET @ENTRY := 33419;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tendril from Below - On Aggro - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,3000,12000,19000,11,62975,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tendril from Below - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,7000,8000,28000,35000,11,78751,2,0,0,0,0,2,0,0,0,0,0,0,0,"Tendril from Below - In Combat - Cast 'Mind Flay'");

-- 122.
-- Terrowulf Packlord SAI
SET @ENTRY := 3792;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Terrowulf Packlord - On Aggro - Cast 'Battle Roar' (No Repeat)");

-- 123.
-- Thistlefur Avenger SAI
SET @ENTRY := 3925;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Avenger - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,8602,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Avenger - Between 0-30% Health - Cast 'Vengeance' (No Repeat)");

-- 124.
-- Thistlefur Pathfinder SAI
SET @ENTRY := 3926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Pathfinder - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Pathfinder - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,3,0,9,0,100,0,5,30,14000,19000,11,78754,2,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Pathfinder - Within 5-30 Range - Cast 'Arcane Shot'");

-- 125.
-- Thistlefur Shaman SAI
SET @ENTRY := 3924;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Shaman - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,0,0,40,34000,36000,11,6742,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Shaman - Between 0-40% Health - Cast 'Bloodlust'"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,25000,29000,11,39591,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Shaman - In Combat - Cast 'Searing Totem'");

-- 126.
-- Thistlefur Totemic SAI
SET @ENTRY := 3922;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Totemic - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,21000,35000,11,78770,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Totemic - In Combat - Cast 'Magma Totem'");

-- 127.
-- Thistlefur Ursa SAI
SET @ENTRY := 3921;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Ursa - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,24000,32000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Ursa - In Combat - Cast 'Thunderclap'"),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,3490,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Ursa - Between 0-30% Health - Cast 'Frenzied Rage' (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Ursa - Between 0-30% Health - Say Line 0 (No Repeat)");

-- NPC talk text insert
SET @ENTRY := 3921;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s goes into a frenzy!',16,0,100,0,0,0, 'combat Frenzied Rage',2384);

-- 128.
-- Thistlefur Warrior SAI
SET @ENTRY := 33390;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Warrior - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,18000,25000,11,77558,0,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Warrior - In Combat - Cast 'Bloody Strike'");

-- 129.
-- Thistlefur Wise One SAI
SET @ENTRY := 33389;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Wise One - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Wise One - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,6813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thistlefur Wise One - On Respawn - Cast 'Coat of Thistlefur' (No Repeat)"),
(@ENTRY,0,3,0,9,0,100,0,0,30,9000,12000,11,33844,2,0,0,0,0,2,0,0,0,0,0,0,0,"Thistlefur Wise One - Within 0-30 Range - Cast 'Entangling Roots'");

-- 130.
-- Tideress SAI
SET @ENTRY := 12759;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,120000,125000,11,6873,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tideress - In Combat - Cast 'Foul Chill'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,20000,25000,11,78542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tideress - In Combat - Cast 'Splash'");

-- 131.
-- Ursangous SAI
SET @ENTRY := 12678;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,9000,12000,22000,11,10101,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ursangous - In Combat - Cast 'Knock Away'"),
(@ENTRY,0,1,0,0,0,100,0,10000,13000,15000,24000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ursangous - In Combat - Cast 'Rend'");

-- 132.
-- Ursol'lok SAI
SET @ENTRY := 12037;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ursol'lok - On Aggro - Cast 'Leaping Rush' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,24000,32000,11,84867,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ursol'lok - In Combat - Cast 'Sundering Swipe'");

-- 133.
-- Uthil Mooncall SAI
SET @ENTRY := 3941;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uthil Mooncall - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,11,7090,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uthil Mooncall - On Aggro - Cast 'Bear Form' (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,0,1,100,0,2000,4500,12000,15000,11,12161,0,0,0,0,0,1,0,0,0,0,0,0,0,"Uthil Mooncall - In Combat - Cast 'Maul' (Phase 1)");

-- 134.
-- Vorsha the Lasher SAI
SET @ENTRY := 12940;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,9000,12000,11,3391,0,0,0,0,0,1,0,0,0,0,0,0,0,"Vorsha the Lasher - In Combat - Cast 'Thrash'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,24000,32000,11,6607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vorsha the Lasher - In Combat - Cast 'Lash'"),
(@ENTRY,0,2,0,0,0,100,0,2000,4000,18000,28000,11,33126,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vorsha the Lasher - In Combat - Cast 'Dropped Weapon'");

-- 135.
-- Wandering Protector SAI
SET @ENTRY := 12836;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,13000,15000,11,11922,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wandering Protector - Within 0-30 Range - Cast 'Entangling Roots'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,27000,35000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wandering Protector - In Combat - Cast 'War Stomp'");

-- 136.
-- Warsong Demolisher SAI
SET @ENTRY := 32850;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Demolisher - On Aggro - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,50,10000,14000,11,61865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Demolisher - Within 0-50 Range - Cast 'Flaming Ball'"),
(@ENTRY,0,3,0,9,0,100,0,0,20,14000,19000,11,65388,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Demolisher - Within 0-20 Range - Cast 'Flamethrower'"),
(@ENTRY,0,4,0,6,0,100,1,0,0,0,0,11,65417,3,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Demolisher - On Just Died - Cast 'Warsong Demolisher Explodes' (No Repeat)");

-- 137.
-- Warsong Grunt SAI
SET @ENTRY := 11682;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,19000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Grunt - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,13,0,100,0,2000,4500,20000,30000,11,11972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Grunt - On Victim Casting 'Alexander's Test Periodic Aura' - Cast 'Shield Bash'");

-- 138.
-- Warsong Guardian SAI
SET @ENTRY := 34241;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,95826,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Guardian - In Combat - Cast 'Shoot'");

-- 139.
-- Warsong Logger SAI
SET @ENTRY := 11681;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4500,12000,22000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Logger - In Combat - Cast 'Sunder Armor'");

-- 140.
-- Warsong Outrider SAI
SET @ENTRY := 12864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,5,9,0,100,0,5,30,24000,35000,11,18545,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - Within 5-30 Range - Cast 'Scorpid Sting'");

-- 141.
-- Warsong Shaman SAI
SET @ENTRY := 11683;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,20805,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Shaman - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,16,0,100,0,6742,40,22000,25000,11,6742,2,0,0,0,0,7,0,0,0,0,0,0,0,"Warsong Shaman - On Friendly Unit Missing Buff 'Bloodlust' - Cast 'Bloodlust'"),
(@ENTRY,0,2,0,2,0,100,0,0,40,25000,28000,11,6742,2,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - Between 0-40% Health - Cast 'Bloodlust'");

-- 142.
-- Warsong Vanguard SAI
SET @ENTRY := 34366;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Vanguard - On Aggro - Cast 'Rushing Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,22000,34000,11,17963,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Vanguard - In Combat - Cast 'Sundering Cleave'");

-- 143.
-- Wild Buck SAI
SET @ENTRY := 3816;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wild Buck - On Aggro - Cast 'Rushing Charge' (No Repeat)");

-- 144.
-- Wildthorn Lurker SAI
SET @ENTRY := 3821;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildthorn Lurker - On Respawn - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,77806,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildthorn Lurker - On Evade - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,4000,17000,26000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildthorn Lurker - In Combat - Cast 'Poison'");

-- 145.
-- Wildthorn Stalker SAI
SET @ENTRY := 3819;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,12000,15000,11,12023,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildthorn Stalker - Within 0-30 Range - Cast 'Web'");

-- 146.
-- Wildthorn Venomspitter SAI
SET @ENTRY := 3820;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,30,17000,24000,11,6917,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildthorn Venomspitter - Within 0-30 Range - Cast 'Venom Spit'");

-- 147.
-- Withered Ancient SAI
SET @ENTRY := 3919;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,24000,32000,11,6909,0,0,0,0,0,2,0,0,0,0,0,0,0,"Withered Ancient - Within 0-5 Range - Cast 'Curse of Thorns'");

-- 148.
-- Wrathtail Myrmidon SAI
SET @ENTRY := 3711;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,25000,31000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Myrmidon - In Combat - Cast 'Rend'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,19000,26500,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Myrmidon - Within 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Myrmidon - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 149.
-- Wrathtail Priestess SAI
SET @ENTRY := 3944;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,7000,17000,28000,11,17140,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Priestess - In Combat - Cast 'Holy Fire'"),
(@ENTRY,0,1,0,2,0,100,0,0,50,45000,57000,11,11835,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Priestess - Between 0-50% Health - Cast 'Power Word: Shield'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Priestess - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 150.
-- Wrathtail Razortail SAI
SET @ENTRY := 3712;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,27000,32000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Razortail - In Combat - Cast 'Pierce Armor'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Razortail - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 151.
-- Wrathtail Sea Witch SAI
SET @ENTRY := 3715;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,8598,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sea Witch - In Combat - Cast 'Lightning Blast'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,30,17000,22000,11,11981,2,0,0,0,0,4,0,0,0,0,0,0,0,"Wrathtail Sea Witch - Within 0-30 Range - Cast 'Mana Burn'");

-- 152.
-- Wrathtail Sorceress SAI
SET @ENTRY := 3717;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wrathtail Sorceress - In Combat - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,12000,13000,11,11831,2,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Within 0-8 Range - Cast 'Frost Nova'"),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,34827,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Sorceress - Out of Combat - Cast 'Water Shield'");

-- 153.
-- Wrathtail Wave Rider SAI
SET @ENTRY := 3713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,18000,24500,11,78732,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Wave Rider - In Combat - Cast 'Whirlpool'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wrathtail Wave Rider - Between 0-15% Health - Flee For Assist (No Repeat)");

-- 154.
-- Xavian Betrayer SAI
SET @ENTRY := 3754;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,4500,12000,18000,11,77522,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Betrayer - In Combat - Cast 'Swoop'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,11,6925,2,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Betrayer - Between 0-15% Health - Cast 'Gift of the Xavian' (No Repeat)");

-- 155.
-- Xavian Felsworn SAI
SET @ENTRY := 3755;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Felsworn - In Combat - Cast 'Fel Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Felsworn - Between 0-15% Health - Cast 'Gift of the Xavian' (No Repeat)");

-- 156.
-- Xavian Hellcaller SAI
SET @ENTRY := 3757;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Hellcaller - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Hellcaller - Between 0-15% Health - Cast 'Gift of the Xavian' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,21000,32000,11,39273,1,0,0,0,0,4,0,0,0,0,0,0,0,"Xavian Hellcaller - In Combat - Cast 'Rain of Fire'");

-- 157.
-- Xavian Rogue SAI
SET @ENTRY := 3752;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,22000,29000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,"Xavian Rogue - In Combat - Cast 'Expose Armor'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,11,6925,2,0,0,0,0,1,0,0,0,0,0,0,0,"Xavian Rogue - Between 0-15% Health - Cast 'Gift of the Xavian' (No Repeat)");
