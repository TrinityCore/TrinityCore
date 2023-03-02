-- Alliance Hunter Infantry
SET @ENTRY := 47595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,15000,15000,11,80012,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chimera Shot'),
(@ENTRY,0,2,0,0,0,100,2,5000,5000,10000,22000,11,80009,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting'),
(@ENTRY,0,3,0,9,0,100,2,0,10,15000,25000,11,78578,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Immolation Trap on Close');

-- Alliance Mage Infantry
SET @ENTRY := 47598;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,79868,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,1,0,9,0,100,2,0,8,15000,25000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,2,0,2,0,100,2,0,40,22000,25000,11,21655,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blink at 40% HP');

-- Alliance Paladin Infantry
SET @ENTRY := 47600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,79968,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Kings on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,15000,20000,11,79965,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Avenger\'s Shield'),
(@ENTRY,0,2,0,9,0,100,2,0,8,15000,25000,11,79966,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Consecration on Close');

-- Alliance Warrior Infantry
SET @ENTRY := 47599;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,2,4,0,100,3,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,14000,15000,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sunder Armor'),
(@ENTRY,0,2,0,61,0,100,3,0,0,0,0,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Commanding Shout on Aggro'),
(@ENTRY,0,3,0,9,0,100,2,0,10,15000,25000,11,8078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap on Close');

-- Archmage Galus
SET @ENTRY := 47537;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,2,500,1000,600000,600000,11,79865,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Armor on Spawn'),
(@ENTRY,0,1,0,9,0,100,2,0,8,15000,25000,11,79850,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close'),
(@ENTRY,0,2,0,0,0,100,2,0,0,3400,4700,11,79858,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,3,0,0,0,100,2,5000,8000,12000,15000,11,79859,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ice Lance');

-- Baradin Crocolisk
SET @ENTRY := 47591;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,13445,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,1,0,0,0,100,2,4000,10000,10000,22000,11,3604,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tendon Rip');

-- Captive Spirit
SET @ENTRY := 47531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,81193,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unrelenting Anguish');

-- Cell Watcher
SET @ENTRY := 47542;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,8000,8000,15000,15000,11,36414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Focused Bursts'),
(@ENTRY,0,1,0,9,0,100,2,0,5,16000,25000,11,36398,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tongue Lash on Close');

-- Cellblock Ooze
SET @ENTRY := 47534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,9459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrosive Ooze');

-- Exiled Mage
SET @ENTRY := 47552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles'),
(@ENTRY,0,1,0,9,0,100,2,0,8,15000,25000,11,22938,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Explosion on Close'),
(@ENTRY,0,2,0,0,0,100,2,5000,8000,12000,15000,11,79880,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow');

-- Ghastly Convict
SET @ENTRY := 47590;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,67,0,100,2,3900,6900,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,1,0,2,0,100,2,0,55,22000,25000,11,80576,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 55% HP');

-- Hellscream's Sentry
SET @ENTRY := 51166;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Horde Druid Infantry
SET @ENTRY := 47607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,79823,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Starfall'),
(@ENTRY,0,1,0,0,0,100,2,0,0,3600,4700,11,78907,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Starfire'),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,18000,22000,11,79825,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Summon Unstable Mushroom');

-- Horde Mage Infantry
SET @ENTRY := 47608;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,79856,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flamestrike'),
(@ENTRY,0,1,0,0,0,100,2,0,0,3400,4700,11,79854,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,2,0,9,0,100,2,0,8,15000,25000,11,79857,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close'),
(@ENTRY,0,3,0,1,0,100,2,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');

-- Horde Rogue Infantry
SET @ENTRY := 47609;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,12000,14500,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,12000,15000,11,79852,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eviscerate'),
(@ENTRY,0,2,0,2,0,100,2,0,55,22000,25000,11,79853,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 55% HP'),
(@ENTRY,0,3,0,9,0,100,2,0,8,15000,25000,11,79851,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close');

--Horde Shaman Infantry
SET @ENTRY := 47610;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,79884,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,12000,15000,11,79890,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,2,0,0,0,100,2,10000,10000,20000,22000,11,79886,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst');

-- Imprisoned Imp
SET @ENTRY := 47549;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,36227,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Firebolt');

-- Imprisoned Worker
SET @ENTRY := 47550;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3500,4100,11,38557,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,2,0,5,15000,18000,11,6016,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pierce Armor on Close');

-- Problim
SET @ENTRY := 47593;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,80146,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bonk'),
(@ENTRY,0,1,0,9,0,100,2,0,5,15000,18000,11,88421,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Log Smash on Close');

-- Shivarra Destroyer
SET @ENTRY := 47540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,5000,12000,15000,11,36040,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fel Flamestrike'),
(@ENTRY,0,1,0,0,0,100,2,10000,10000,15000,15000,11,37629,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Melt Flesh'),
(@ENTRY,0,2,0,0,0,100,2,5000,12000,10000,25000,11,34017,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rain of Chaos');

-- Warden Guard
SET @ENTRY := 47561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,8000,12000,15000,11,85240,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sundering Cleave'),
(@ENTRY,0,1,0,2,0,100,3,0,40,0,0,11,78710,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Threatening Shout at 40% HP');

-- Warden Silva
SET @ENTRY := 48036;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,11,81219,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout on Aggro'),
(@ENTRY,0,1,0,0,0,100,2,5000,5000,12000,15000,11,11977,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend'),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,15000,19000,11,79878,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodthirst');
