-- Prince Raze SAI
SET @ENTRY := 10647;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,4700,5800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Prince Raze - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,9,0,100,0,0,40,13000,16000,11,16570,1,0,0,0,0,5,0,0,0,0,0,0,0,"Prince Raze - 0-40 Range - Cast 'Charged Arcane Bolt'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,12000,18000,11,11969,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - 0-8 Range - Cast 'Fire Nova'"),
(@ENTRY,0,3,4,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,11,6925,1,0,0,0,0,1,0,0,0,0,0,0,0,"Prince Raze - 0-15% Health - Cast 'Gift of the Xavian' (No Repeat)");

-- Summoned Blackhand Dreadweaver SAI
SET @ENTRY := 10680;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Out of Combat - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,6400,11,12739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,14500,19200,27600,39600,11,7068,0,0,0,0,0,2,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Combat - Cast 'Veil of Shadow' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,0,1,0,100,2,10000,10000,0,0,37,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Blackhand Dreadweaver - Out of Combat - Kill Self (No Repeat) (Normal Dungeon)");

-- Duggan Wildhammer SAI
SET @ENTRY := 10817;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Duggan Wildhammer - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,6000,9000,11,15284,1,0,0,0,0,2,0,0,0,0,0,0,0,"Duggan Wildhammer - 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,0,2,0,100,0,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Duggan Wildhammer - 0-15% Health - Flee For Assist");

-- Death-Hunter Hawkspear SAI
SET @ENTRY := 10824;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,2300,3900,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,9000,11,11978,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ranger Lord Hawkspear - 0-5 Range - Cast 'Kick'");

-- Deathspeaker Selendre SAI
SET @ENTRY := 10827;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,5000,11,12471,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,18000,11,12889,1,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - Combat - Cast 'Curse of Tongues'"),
(@ENTRY,0,2,0,2,0,100,0,0,30,12000,19000,11,17238,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deathspeaker Selendre - 0-30% Health - Cast 'Drain Life'");

-- Risen Rifleman SAI
SET @ENTRY := 11054;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,17353,64,0,0,0,0,2,0,0,0,0,0,0,0,"Crimson Rifleman - Combat CMC - Cast 'Shoot' (Normal Dungeon)");

-- Ragefire Shaman SAI
SET @ENTRY := 11319;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ragefire Shaman - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,74,0,100,3,0,40,30000,35000,11,11986,1,0,0,0,0,9,0,0,0,0,0,0,0,"Ragefire Shaman - On Friendly Between 0-40% Health - Cast 'Healing Wave' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ragefire Shaman - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Searing Blade Warlock SAI
SET @ENTRY := 11324;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,3,1000,1000,0,0,11,12746,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - Out of Combat - Cast 'Summon Voidwalker' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,3400,6500,11,20791,64,0,0,0,0,2,0,0,0,0,0,0,0,"Searing Blade Warlock - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Searing Blade Warlock - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Gordok Ogre-Mage SAI
SET @ENTRY := 11443;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,5000,12000,35000,45000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Combat - Cast 'Bloodlust'"),
(@ENTRY,0,3,0,4,0,20,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Ogre-Mage - On Aggro - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,0,0,2400,3800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,2,5000,12000,35000,45000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Ogre-Mage - Combat - Cast 'Bloodlust' (Normal Dungeon)");

-- Gordok Mage-Lord SAI
SET @ENTRY := 11444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,20,3,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Gordok Mage-Lord - On Aggro - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,15530,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mage-Lord - Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,14000,12000,15000,11,14145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Mage-Lord - Combat - Cast 'Fire Blast' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,12000,17000,19000,25000,11,16102,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gordok Mage-Lord - Combat - Cast 'Flamestrike' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,7000,9000,16000,20000,11,13323,1,0,0,0,0,6,0,0,0,0,0,0,0,"Gordok Mage-Lord - Combat - Cast 'Polymorph' (Normal Dungeon)"),
(@ENTRY,0,5,6,2,0,100,3,0,30,0,0,11,16170,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-30% Health - Cast 'Bloodlust' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,6,0,61,0,100,3,0,30,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Mage-Lord - Between 0-30% Health - Say Line 1 (No Repeat) (Normal Dungeon)");

-- Gordok Warlock SAI
SET @ENTRY := 11448;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,13787,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Out of Combat - Cast 'Demon Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,1,0,100,3,3000,3000,0,0,11,22865,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - Out of Combat - Cast 'Summon Doomguard' (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,2,0,4,0,20,3,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gordok Warlock - On Aggro - Say Line 0 (No Repeat) (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,0,0,2400,3800,11,15232,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Warlock - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,9000,15000,26000,30000,11,17883,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gordok Warlock - Combat - Cast 'Immolate' (Normal Dungeon)"),
(@ENTRY,0,5,0,0,0,100,2,5000,9000,20000,25000,11,13338,0,0,0,0,0,5,0,0,0,0,0,0,0,"Gordok Warlock - Combat - Cast 'Curse of Tongues' (Normal Dungeon)"),
(@ENTRY,0,6,0,0,0,100,2,7000,15000,20000,26000,11,8994,1,0,0,0,0,6,0,0,0,0,0,0,0,"Gordok Warlock - Combat - Cast 'Banish' (Normal Dungeon)");

-- Wildspawn Betrayer SAI
SET @ENTRY := 11454;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Betrayer - Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,9,0,100,2,5,30,7800,11400,11,18649,40,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Betrayer - 5-30 Range - Cast 'Shadow Shot' (Normal Dungeon)"),
(@ENTRY,0,2,0,9,0,100,2,5,30,9900,13600,11,7896,40,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Betrayer - 5-30 Range - Cast 'Exploding Shot' (Normal Dungeon)"),
(@ENTRY,0,3,0,9,0,100,2,0,5,6000,11000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Betrayer - 0-5 Range - Cast 'Knockdown' (Normal Dungeon)"),
(@ENTRY,0,4,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildspawn Betrayer - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Wildspawn Felsworn SAI
SET @ENTRY := 11455;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12542,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildspawn Felsworn - Out of Combat - Cast 'Fear' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Felsworn - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,12000,38000,45000,11,22417,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildspawn Felsworn - Combat - Cast 'Shadow Shield' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,1,100,2,11000,17000,23000,30000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Felsworn - Combat - Cast 'Shadow Word: Pain' (Normal Dungeon)"),
(@ENTRY,0,4,0,0,0,100,2,6000,10000,10000,15000,11,12542,1,0,0,0,0,5,0,0,0,0,0,0,0,"Wildspawn Felsworn - Combat - Cast 'Fear' (Normal Dungeon)");

-- Wildspawn Hellcaller SAI
SET @ENTRY := 11457;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Hellcaller - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,14000,18000,25000,11,20754,3,0,0,0,0,2,0,0,0,0,0,0,0,"Wildspawn Hellcaller - Combat - Cast 'Rain of Fire' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wildspawn Hellcaller - 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Highborne Summoner SAI
SET @ENTRY := 11466;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,12466,64,0,0,0,0,2,0,0,0,0,0,0,0,"Highborne Summoner - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,11000,9000,12000,11,13341,0,0,0,0,0,5,0,0,0,0,0,0,0,"Highborne Summoner - Combat - Cast 'Fire Blast' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,12000,16000,18000,22000,11,15063,1,0,0,0,0,1,0,0,0,0,0,0,0,"Highborne Summoner - Combat - Cast 'Frost Nova' (Normal Dungeon)");

-- Eldreth Apparition SAI
SET @ENTRY := 11471;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,18100,1,0,0,0,0,1,0,0,0,0,0,0,0,"Eldreth Apparition - Out of Combat - Cast 'Frost Armor' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,16799,64,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Apparition - Combat CMC - Cast 'Frostbolt' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,7000,12000,20000,27500,11,22744,1,0,0,0,0,6,0,0,0,0,0,0,0,"Eldreth Apparition - Combat - Cast 'Chains of Ice' (Normal Dungeon)"),
(@ENTRY,0,3,0,0,0,100,2,11000,14000,20000,30000,11,15244,1,0,0,0,0,2,0,0,0,0,0,0,0,"Eldreth Apparition - Combat - Cast 'Cone of Cold' (Normal Dungeon)");

-- Irondeep Shaman SAI
SET @ENTRY := 11600;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Irondeep Shaman - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,7000,9000,55000,65000,11,15786,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - Combat - Cast 'Earthbind Totem' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,50,15000,20000,11,12492,1,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - 0-50% Health - Cast 'Healing Wave' (Normal Dungeon)"),
(@ENTRY,0,3,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irondeep Shaman - 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Whitewhisker Geomancer SAI
SET @ENTRY := 11604;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,15228,64,0,0,0,0,2,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Combat CMC - Cast 'Fireball' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,500,1000,600000,600000,11,18968,1,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - Combat - Cast 'Fire Shield' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Whitewhisker Geomancer - 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Morloch SAI
SET @ENTRY := 11657;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,15537,64,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - Combat CMC - Cast 'Shadow Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,120000,130000,11,12741,1,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - Combat - Cast 'Curse of Weakness' (Normal Dungeon)"),
(@ENTRY,0,2,0,0,0,100,2,11000,14000,9000,15000,11,17228,0,0,0,0,0,2,0,0,0,0,0,0,0,"Morloch - Combat - Cast 'Shadow Bolt Volley' (Normal Dungeon)");

-- Snowblind Windcaller SAI
SET @ENTRY := 11675;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Snowblind Windcaller - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,12000,16000,11,9532,1,0,0,0,0,6,0,0,0,0,0,0,0,"Snowblind Windcaller - Combat - Cast 'Lightning Bolt' (Normal Dungeon)");

-- Horde Scout SAI
SET @ENTRY := 11680;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Horde Scout - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Scout - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,12000,15000,11,18545,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horde Scout - Within 5-30 Range - Cast 'Scorpid Sting'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horde Scout - 0-15% Health - Flee For Assist (No Repeat)");

-- Warsong Shaman SAI
SET @ENTRY := 11683;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20805,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Shaman - Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,2,0,100,0,0,30,30000,35000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - 0-30% Health - Cast 'Bloodlust'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Shaman - 0-15% Health - Flee For Assist (No Repeat)");

-- Wildpaw Mystic SAI
SET @ENTRY := 11838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4800,11,37361,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Mystic - Combat CMC - Cast 'Arcane Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,6000,9000,16000,19000,11,12058,1,0,0,0,0,2,0,0,0,0,0,0,0,"Wildpaw Mystic - Combat - Cast 'Chain Lightning' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,2,0,50,12000,16000,11,11986,1,0,0,0,0,1,0,0,0,0,0,0,0,"Wildpaw Mystic - 0-50% Health - Cast 'Healing Wave' (Normal Dungeon)");

-- Nathanos Blightcaller SAI
SET @ENTRY := 11878;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nathanos Blightcaller - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,4000,6000,8000,11000,11,18651,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nathanos Blightcaller - Combat - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,7000,9000,11,6253,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nathanos Blightcaller - 0-5 Range - Cast 'Backhand'"),
(@ENTRY,0,3,0,15,0,100,1,0,0,10,0,11,13704,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nathanos Blightcaller - Friendly Crowd Controlled - Cast 'Psychic Scream'");

-- Lord Vyletongue SAI
SET @ENTRY := 12236;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,16100,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Vyletongue - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,2,5,30,7000,9500,11,21390,1,0,0,0,0,2,0,0,0,0,0,0,0,"Lord Vyletongue - 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,0,0,100,2,20000,30000,20000,30000,11,21655,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - Combat - Cast 'Blink'"),
(@ENTRY,0,3,0,0,0,100,2,8000,12000,14000,18000,11,7964,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lord Vyletongue - Combat - Cast 'Smoke Bomb'");

-- Quel'Lithien Protector SAI
SET @ENTRY := 12322;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15547,64,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - 0-5 Range - Cast 'Strike'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,8000,13000,11,11978,0,0,0,0,0,2,0,0,0,0,0,0,0,"Quel'Lithien Protector - 0-5 Range - Cast 'Kick'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quel'Lithien Protector - 0-15% Health - Flee For Assist (No Repeat)");

-- Damned Soul SAI
SET @ENTRY := 12378;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Damned Soul - Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,7000,9000,11,13748,0,0,0,0,0,2,0,0,0,0,0,0,0,"Damned Soul - Combat - Cast 'Arcane Bolt'");

-- Mastok Wrilehiss SAI
SET @ENTRY := 12737;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mastok Wrilehiss - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,15284,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mastok Wrilehiss - 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,2,0,0,0,100,0,9000,15000,14000,18000,11,23600,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - Combat - Cast 'Piercing Howl'"),
(@ENTRY,0,3,4,2,0,100,0,0,30,120000,130000,11,8599,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - 0-30% Health - Cast 'Enrage'"),
(@ENTRY,0,4,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mastok Wrilehiss - 0-30% Health - Say 0");

DELETE FROM `creature_text` WHERE `entry` IN (12737);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`BroadcastTextId`,`comment`) VALUES
(12737,0,0,'$s becomes enraged!',16,0,100,0,0,0,24144,'Mastok Wrilehiss enrage at 30%');

-- Ashenvale Outrunner SAI
SET @ENTRY := 12856;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,35900,52300,11,18545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Within 5-30 Range - Cast 'Scorpid Sting'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,7100,15300,11,8646,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashenvale Outrunner - Within 0-5 Range - Cast 'Snap Kick'");

-- Warsong Scout SAI
SET @ENTRY := 12862;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Scout - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Scout - 0-15% Health - Flee For Assist (No Repeat)");

-- Warsong Runner SAI
SET @ENTRY := 12863;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Runner - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warsong Runner - 0-15% Health - Flee For Assist (No Repeat)");

-- Warsong Outrider SAI
SET @ENTRY := 12864;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,35900,52300,11,18545,1,0,0,0,0,2,0,0,0,0,0,0,0,"Warsong Outrider - Within 5-30 Range - Cast 'Scorpid Sting'");

-- Ambassador Malcin SAI
SET @ENTRY := 12865;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Malcin - Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,9000,15000,25000,11,8282,32,0,0,0,0,2,0,0,0,0,0,0,0,"Ambassador Malcin - Combat - Cast 'Curse of Blood'");

-- Silverwing Sentinel SAI
SET @ENTRY := 12896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Silverwing Sentinel - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Silverwing Sentinel - 0-15% Health - Flee For Assist (No Repeat)");

-- Lorgus Jett SAI
SET @ENTRY := 12902;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,600000,600000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,"Lorgus Jett - Out of Combat - Cast 'Lightning Shield' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,12167,64,0,0,0,0,2,0,0,0,0,0,0,0,"Lorgus Jett - Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)");

-- Mounted Ironforge Mountaineer SAI
SET @ENTRY := 12996;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mounted Ironforge Mountaineer - 0-15% Health - Flee For Assist (No Repeat)");
