-- Stranglethorn - Missing Scripts
-- Gorlash SAI
SET @ENTRY := 1492;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,5000,6000,11,5568,2,0,0,0,0,2,0,0,0,0,0,0,0,"Gorlash - In Combat - Cast 'Trample'");

-- Silverback Patriarch SAI
SET @ENTRY := 1558;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,6000,7000,8000,11,6253,2,0,0,0,0,2,0,0,0,0,0,0,0,"Silverback Patriarch - In Combat - Cast 'Backhand'");

-- Zanzil Witch Doctor SAI
SET @ENTRY := 1490;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,5000,6000,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Zanzil Witch Doctor - In Combat CMC - Cast 'Shadow Bolt'");

-- Zanzil Zombie SAI
SET @ENTRY := 1488;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,2000,3000,0,0,11,7102,2,0,0,0,0,2,0,0,0,0,0,0,0,"Zanzil Zombie - In Combat - Cast 'Contagion of Rot' (No Repeat)");

-- Zanzil the Outcast SAI
SET @ENTRY := 2534;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,0,0,0,0,11,8832,2,0,0,0,0,1,0,0,0,0,0,0,0,"Zanzil the Outcast - In Combat - Cast 'Ward of Zanzil' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,5000,6000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Zanzil the Outcast - In Combat CMC - Cast 'Lightning Bolt'");

-- Bloodscalp Axe Thrower SAI
SET @ENTRY := 694;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5,30,3500,4900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Axe Thrower - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Texts for Bloodscalp Axe Thrower
SET @ENTRY := 694;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bloodscalp Axe Thrower",10677);

-- Zanzil Hunter SAI
SET @ENTRY := 1489;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Zanzil Hunter - On Aggro - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Zanzil Hunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Zanzil Naga SAI
SET @ENTRY := 1491;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,7000,8000,11,9080,2,0,0,0,0,2,0,0,0,0,0,0,0,"Zanzil Naga - In Combat - Cast 'Hamstring'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,10000,11000,11,12555,2,0,0,0,0,2,0,0,0,0,0,0,0,"Zanzil Naga - In Combat - Cast 'Pummel'");

-- Venture Co. Tinkerer SAI
SET @ENTRY := 677;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,0,1000,2000,0,0,11,12544,2,0,0,0,0,1,0,0,0,0,0,0,0,"Venture Co. Tinkerer - On Just Summoned - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,5000,6000,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Tinkerer - In Combat CMC - Cast 'Fireball'");

-- Venture Co. Strip Miner SAI
SET @ENTRY := 674;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,12000,15000,11,7978,64,0,0,0,0,2,0,0,0,0,0,0,0,"Venture Co. Strip Miner - In Combat CMC - Cast 'Throw Dynamite'");

-- Skullsplitter Warrior SAI
SET @ENTRY := 667;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,15000,20000,11,3148,2,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Warrior - In Combat - Cast 'Head Crack'"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,11000,12000,11,11972,2,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Warrior - In Combat - Cast 'Shield Bash'");

-- Skullsplitter Witch Doctor SAI
SET @ENTRY := 670;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,2000,10000,11000,11,8376,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Witch Doctor - In Combat - Cast 'Earthgrab Totem'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,20000,30000,11,5605,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Witch Doctor - In Combat - Cast 'Healing Ward'");

-- Skullsplitter Scout SAI
SET @ENTRY := 782;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,18000,20000,11,3148,2,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Scout - In Combat - Cast 'Head Crack'");

-- Skullsplitter Spiritchaser SAI
SET @ENTRY := 672;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,10000,11000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skullsplitter Spiritchaser - Between 0-40% Health - Cast 'Healing Wave'"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,5000,6000,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Spiritchaser - In Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,0,0,100,1,6000,7000,0,0,11,11981,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skullsplitter Spiritchaser - In Combat - Cast 'Mana Burn' (No Repeat)");

-- Ana'thek the Cruel SAI
SET @ENTRY := 1059;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,6000,18000,20000,11,9791,2,0,0,0,0,2,0,0,0,0,0,0,0,"Ana'thek the Cruel - In Combat - Cast 'Head Crack'");

-- Mosh'Ogg Spellcrafter SAI
SET @ENTRY := 710;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,54,0,100,1,0,0,0,0,11,12544,64,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Spellcrafter - On Just Summoned - Cast 'Frost Armor' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,3000,4000,5000,6000,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mosh'Ogg Spellcrafter - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,6000,7000,11,11829,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mosh'Ogg Spellcrafter - In Combat - Cast 'Flamestrike'");

-- Mosh'Ogg Warmonger SAI
SET @ENTRY := 709;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,75,0,2000,3000,10000,11000,11,8147,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Warmonger - In Combat - Cast 'Thunderclap'");

-- Mosh'Ogg Lord SAI
SET @ENTRY := 680;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,30000,40000,11,9128,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Lord - In Combat - Cast 'Battle Shout'");

-- Mosh'Ogg Mauler SAI
SET @ENTRY := 678;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,50,0,4000,6000,11000,12000,11,5164,2,0,0,0,0,2,0,0,0,0,0,0,0,"Mosh'Ogg Mauler - In Combat - Cast 'Knockdown'");

-- Mai'Zoth SAI
SET @ENTRY := 818;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,5000,6000,11,8398,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mai'Zoth - In Combat CMC - Cast 'Frostbolt Volley'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,8000,9000,11,8814,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mai'Zoth - In Combat - Cast 'Flame Spike'");

-- Young Panther SAI
SET @ENTRY := 683;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,5000,6000,11,16830,2,0,0,0,0,2,0,0,0,0,0,0,0,"Young Panther - In Combat - Cast 'Claw'");

-- Bloodscalp Witch Doctor SAI
SET @ENTRY := 660;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,2000,3000,0,0,11,8376,64,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Witch Doctor - In Combat - Cast 'Earthgrab Totem' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Witch Doctor - Between 0-30% Health - Cast 'Enrage' (No Repeat)");

-- Bloodscalp Beastmaster SAI
SET @ENTRY := 699;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Beastmaster - On Aggro - Cast 'Throw'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Beastmaster - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Beastmaster - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Beastmaster - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Texts for Bloodscalp Axe Thrower
SET @ENTRY := 699;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bloodscalp Beastmaster",10677);

-- Bloodscalp Headhunter SAI
SET @ENTRY := 671;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,10277,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Headhunter - On Aggro - Cast 'Throw'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Headhunter - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Headhunter - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Headhunter - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Texts for Bloodscalp Headhunter
SET @ENTRY := 671;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(@ENTRY,0,0,"%s becomes enraged!",16,0,100,0,0,0,"Bloodscalp Headhunter",10677);

-- Bloodscalp Tiger SAI
SET @ENTRY := 698;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,50,1,0,30,0,0,11,8599,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Tiger - Between 0-30% Health - Cast 'Enrage' (No Repeat)");

-- Nezzliok the Dire SAI
SET @ENTRY := 1062;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,5000,6000,11,421,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nezzliok the Dire - In Combat CMC - Cast 'Chain Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,6000,7000,6000,7000,11,2610,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nezzliok the Dire - In Combat - Cast 'Shock'");

-- Gan'zulah SAI
SET @ENTRY := 1061;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,2,0,0,0,0,1,0,0,0,0,0,0,0,"Gan'zulah - Between 0-30% Health - Cast 'Enrage' (No Repeat)");

-- Bloodscalp Scout SAI
SET @ENTRY := 588;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,50,1,0,30,0,0,11,8599,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Scout - Between 0-30% Health - Cast 'Enrage' (No Repeat)");

-- Panther SAI
SET @ENTRY := 736;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,4000,5000,11,16831,2,0,0,0,0,2,0,0,0,0,0,0,0,"Panther - In Combat - Cast 'Claw'");

-- Mosh'Ogg Witch Doctor SAI
SET @ENTRY := 1144;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,4000,20000,30000,11,11980,2,0,0,0,0,2,0,0,0,0,0,0,0,"Mosh'Ogg Witch Doctor - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,1,0,0,0,100,1,4000,6000,0,0,11,3827,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mosh'Ogg Witch Doctor - In Combat - Cast 'Ward of Laze' (No Repeat)");

-- Roloch SAI
SET @ENTRY := 14488;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,5000,6000,11,15496,2,0,0,0,0,2,0,0,0,0,0,0,0,"Roloch - In Combat - Cast 'Cleave'");

-- Bloodscalp Scavenger SAI
SET @ENTRY := 702;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,6000,7000,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Scavenger - In Combat - Cast 'Backstab'"),
(@ENTRY,0,1,0,0,0,50,0,1000,2000,20000,30000,11,744,2,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscalp Scavenger - In Combat - Cast 'Poison'"),
(@ENTRY,0,2,0,2,0,100,0,0,30,0,0,11,8599,2,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscalp Scavenger - Between 0-30% Health - Cast 'Enrage'");

-- Tethis SAI
SET @ENTRY := 730;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,10000,10000,11,3604,2,0,0,0,0,2,0,0,0,0,0,0,0,"Tethis - In Combat - Cast 'Tendon Rip'");

-- Sin'Dall SAI
SET @ENTRY := 729;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,10000,10000,11,5164,2,0,0,0,0,2,0,0,0,0,0,0,0,"Sin'Dall - In Combat - Cast 'Knockdown'");
