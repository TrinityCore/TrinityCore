-- Summoned Voidwalker SAI
SET @ENTRY := 5676;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,7741,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Voidwalker - On Respawn - Cast 'Summoned Demon'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,7750,1,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Voidwalker - Between 0-30% Health - Cast 'Consuming Rage'");

-- Dalin Forgewright SAI
SET @ENTRY := 5682;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,80,20000,20000,11,6075,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dalin Forgewright - Between 0-80% Health - Cast 'Renew'"),
(@ENTRY,0,1,0,2,0,100,0,0,30,10000,10000,11,2054,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dalin Forgewright - Between 0-30% Health - Cast 'Heal'");

-- Spawn of Hakkar SAI
SET @ENTRY := 5708;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,1000,3500,1200,6200,11,12280,32,0,0,0,0,2,0,0,0,0,0,0,0,"Spawn of Hakkar - In Combat - Cast 'Acid of Hakkar' (Normal Dungeon)");

-- Felweaver Scornn SAI
SET @ENTRY := 5822;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4600,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Felweaver Scornn - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Felweaver Scornn - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Azzere the Skyblade SAI
SET @ENTRY := 5834;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,13375,64,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,80,0,4000,9000,22000,29000,11,6725,1,0,0,0,0,2,0,0,0,0,0,0,0,"Azzere the Skyblade - In Combat - Cast 'Flame Spike'");

-- Brokespear SAI
SET @ENTRY := 5838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Brokespear - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,0,0,100,0,6000,12000,9000,15000,11,7992,32,0,0,0,0,5,0,0,0,0,0,0,0,"Brokespear - In Combat - Cast 'Slowing Poison'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Brokespear - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dark Iron Geologist SAI
SET @ENTRY := 5839;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2800,3600,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Geologist - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Geologist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Heggin Stonewhisker SAI
SET @ENTRY := 5847;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Heggin Stonewhisker - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,6000,12000,9000,14000,11,6979,0,0,0,0,0,2,0,0,0,0,0,0,0,"Heggin Stonewhisker - In Combat - Cast 'Fire Shot'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Heggin Stonewhisker - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dreadmaul Ogre Mage SAI
SET @ENTRY := 5975;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,0,0,30,34000,38000,11,6742,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dreadmaul Ogre Mage - Between 0-30% Health - Cast 'Bloodlust'");

-- Dreadmaul Warlock SAI
SET @ENTRY := 5978;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20298,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,5000,7000,15000,25000,11,8282,33,0,0,0,0,2,0,0,0,0,0,0,0,"Dreadmaul Warlock - In Combat - Cast 'Curse of Blood'");

-- Nethergarde Engineer SAI
SET @ENTRY := 5997;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Engineer - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,12000,16000,11,8858,1,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Engineer - In Combat - Cast 'Bomb'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Engineer - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Nethergarde Riftwatcher SAI
SET @ENTRY := 6002;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20823,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,9000,14000,14000,18000,11,11975,1,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - In Combat - Cast 'Arcane Explosion'"),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nethergarde Riftwatcher - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Shadowsworn Cultist SAI
SET @ENTRY := 6004;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,10277,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Cultist - In Combat CMC - Cast 'Throw'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Cultist - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Shadowsworn Warlock SAI
SET @ENTRY := 6008;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,5108,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - Out of Combat - Cast 'Voidwalker' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Warlock - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,30000,45000,11,11980,33,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Warlock - In Combat - Cast 'Curse of Weakness'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shadowsworn Warlock - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Shadowsworn Dreadweaver SAI
SET @ENTRY := 6009;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,20825,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,8000,11000,19000,24000,11,8994,1,0,0,0,0,6,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - In Combat - Cast 'Banish'"),
(@ENTRY,0,2,0,0,0,100,0,12000,16000,30000,45000,11,7098,33,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowsworn Dreadweaver - In Combat - Cast 'Curse of Mending'");

-- Addled Leper SAI
SET @ENTRY := 6221;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,7165,1,0,0,0,0,1,0,0,0,0,0,0,0,"Addled Leper - Out of Combat - Cast 'Battle Stance'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Addled Leper - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,9,0,100,0,0,5,17000,23000,11,9080,1,0,0,0,0,2,0,0,0,0,0,0,0,"Addled Leper - Within 0-5 Range - Cast 'Hamstring'"),
(@ENTRY,0,3,0,0,0,100,0,7000,9000,13000,16000,11,25712,1,0,0,0,0,2,0,0,0,0,0,0,0,"Addled Leper - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,4,0,2,0,100,0,0,30,30000,45000,11,2055,1,0,0,0,0,1,0,0,0,0,0,0,0,"Addled Leper - Between 0-30% Health - Cast 'Heal'"),
(@ENTRY,0,5,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Addled Leper - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Dark Iron Ambassador SAI
SET @ENTRY := 6228;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,1000,1000,1800000,1800000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,2,0,0,2400,3800,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,2,1000,1000,60000,65000,11,184,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat - Cast 'Fire Shield II'"),
(@ENTRY,0,3,0,0,0,100,3,2000,2000,0,0,11,10870,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat - Cast 'Summon Burning Servant' (No Repeat)"),
(@ENTRY,0,4,0,0,0,100,3,3000,3000,0,0,11,10870,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat - Cast 'Summon Burning Servant' (No Repeat)"),
(@ENTRY,0,5,0,0,0,100,3,4000,4000,0,0,11,10869,1,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Ambassador - In Combat - Cast 'Summon Embers' (No Repeat)");

-- Dark Iron Rifleman SAI
SET @ENTRY := 6523;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,15,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Dark Iron Rifleman - On Aggro - Say Line 0 (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,5000,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Rifleman - In Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,0,0,100,0,16100,16100,20100,32200,11,7891,3,0,0,0,0,5,0,0,0,0,0,0,0,"Dark Iron Rifleman - In Combat - Cast 'Gift of Ragnaros'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Iron Rifleman - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Baelog SAI
SET @ENTRY := 6906;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,15620,64,0,0,0,0,2,0,0,0,0,0,0,0,"Baelog - In Combat CMC - Cast 'Shoot' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,4000,7000,9000,13000,11,14516,1,0,0,0,0,2,0,0,0,0,0,0,0,"Baelog - In Combat - Cast 'Strike' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baelog - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");

-- Revelosh SAI
SET @ENTRY := 6910;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2400,3800,11,15801,64,0,0,0,0,2,0,0,0,0,0,0,0,"Revelosh - In Combat CMC - Cast 'Lightning Bolt' (Normal Dungeon)"),
(@ENTRY,0,1,0,0,0,100,2,8000,13000,18000,25000,11,16006,1,0,0,0,0,2,0,0,0,0,0,0,0,"Revelosh - In Combat - Cast 'Chain Lightning' (Normal Dungeon)"),
(@ENTRY,0,2,0,2,0,100,3,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Revelosh - Between 0-15% Health - Flee For Assist (No Repeat) (Normal Dungeon)");
