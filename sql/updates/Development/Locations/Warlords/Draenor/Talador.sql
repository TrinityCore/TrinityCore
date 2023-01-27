-- Aarko
SET @ENTRY := 77664;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,80009,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Serpent Sting'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,80012,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chimera Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,30,15000,25000,11,36207,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steal Weapon on Close');

-- Abyssal Invader
SET @ENTRY := 78433;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,171071,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation Aura on Spawn');

-- Abyssal Invader
SET @ENTRY := 78458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,171071,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation Aura on Spawn');

-- Adept Vatrusta <Disciple of Velhari>
SET @ENTRY := 91740;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,185494,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrupted Touch'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,185500,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fiery Onslaught');

-- Adherent Squallbringer
SET @ENTRY := 75290;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158480,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Localized Windstorm'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,158459,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burst of Air');

-- Adherent Sun-Caller
SET @ENTRY := 85434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,158429,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Solar Wrath');

-- Adherent Wing-Guard
SET @ENTRY := 75283;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165328,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Rush'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,158083,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slash on Close'),
(@ENTRY,0,2,0,0,0,100,0,0,0,2000,2200,11,158143,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chakram');

-- Agitated Duskwing
SET @ENTRY := 76668;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173573,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Moth Balls');

-- Albino Cave Ambusher
SET @ENTRY := 80081;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,165687,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,29920,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Phasing Invisibility on Spawn');

-- Ambassador Hellmaw
SET @ENTRY := 87576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,25000,11,31598,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,170794,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp on Close');

-- Amethon
SET @ENTRY := 89823;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,179373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystalline Cage');

-- An'dure the Awakened
SET @ENTRY := 78372;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173215,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Affinity');

-- Ango'rosh Crusher
SET @ENTRY := 77352;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162127,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Backhand'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,157241,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wail of the Restless on Close');

-- Ango'rosh Hunter
SET @ENTRY := 77402;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend');

-- Ango'rosh Spellweaver
SET @ENTRY := 77351;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,167012,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incorporeal at 40% HP');

-- Ango'rosh Spellweaver
SET @ENTRY := 77362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,167012,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incorporeal at 40% HP');

-- Arakkoa Raider
SET @ENTRY := 77749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165328,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Rush'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,158083,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slash on Close'),
(@ENTRY,0,2,0,0,0,100,0,0,0,2000,2200,11,158143,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chakram');

-- Arakkoa Stinger
SET @ENTRY := 77753;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165328,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Rush'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,158083,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slash on Close');

-- Arakkoa Suntalon
SET @ENTRY := 77754;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,158429,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Solar Wrath'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,158433,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Solar Radiance at 40% HP');

-- Arcane Guardian
SET @ENTRY := 85384;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,135503,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,1,0,9,0,100,0,0,30,15000,25000,11,18972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow on Close');

-- Arcane Guardian
SET @ENTRY := 85416;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,135503,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,1,0,9,0,100,0,0,30,15000,25000,11,18972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slow on Close');

-- Arcane Wraith
SET @ENTRY := 78451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172060,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles');

-- Archmagus Tekar <Sargerei War Council>
SET @ENTRY := 88072;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172060,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,10000,11,170365,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Barrage'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,174756,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Spheres at 40% HP');

-- Artificer Romuul
SET @ENTRY := 85880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,79976,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retribution Aura on Spawn'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,79970,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Divine Storm on Close'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,79971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Wrath'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,60000,60000,11,79977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Might on Spawn');

-- Aruumel
SET @ENTRY := 76824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,174957,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Blast'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,174988,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fragmented Thoughts');

-- Auchenai Defender
SET @ENTRY := 79419;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,32416,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,20000,11,162221,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Final Verdict');

-- Auchenai Defender
SET @ENTRY := 79430;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,161919,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vindicator\'s Fury on Close');

-- Auchenai Defender
SET @ENTRY := 81401;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,13,0,100,0,5000,8000,20000,30000,11,82800,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Bash on Player Spell Cast'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');

-- Auchenai Guardian
SET @ENTRY := 91749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,161919,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vindicator\'s Fury on Close');

-- Auchenai Soulpriest
SET @ENTRY := 76695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,154835,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Split'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Auchenai Soulpriest
SET @ENTRY := 78453;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,154835,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Split'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Auchenai Soulpriest
SET @ENTRY := 79431;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,154835,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Split'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Avatar of Socrethar <Shadow Council>
SET @ENTRY := 88043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,75964,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Beatdown'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,175679,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowbolt Volley'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,175685,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power of the Legion at 40% HP');

-- Azuka Bladefury <Warlord of the Burning Blade>
SET @ENTRY := 85046;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Coil'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,173822,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fury of Sanketsu at 40% HP');

-- Battle-Mage Maraa
SET @ENTRY := 83503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');

-- Blackhand
SET @ENTRY := 77256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168766,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shattering Smash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,18000,11,168261,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Marked for Death');

-- Blademaster Bralok
SET @ENTRY := 76981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166902,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,162078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Coil');

-- Burning Blade Initiate
SET @ENTRY := 87267;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,174604,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Soul of Flame at 40% HP');

-- Burning Blademaster
SET @ENTRY := 75794;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166782,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Burning Blademaster
SET @ENTRY := 77205;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166782,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Burning Blademaster
SET @ENTRY := 83807;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166782,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind');

-- Burning Fiend
SET @ENTRY := 86530;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,169033,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flames');

-- Burning Hound
SET @ENTRY := 91707;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Bite');

-- Cave Hunter
SET @ENTRY := 80082;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,165687,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP');

-- Chrysalis
SET @ENTRY := 86744;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,1,0,0,0,0,11,173700,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Maturing on Aggro'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,41,500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Despawn ');

-- Clearwater Mistweaver
SET @ENTRY := 87261;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,11431,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 40% HP'),
(@ENTRY,0,1,0,14,0,100,0,3000,40,15000,18000,11,12160,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Rejuvenation on Friendlies');

-- Clearwater Protector
SET @ENTRY := 87258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79892,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,79892,1,15000,30000,11,79892,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Water Shield on Repeat');

-- Clearwater Tempest
SET @ENTRY := 87282;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,37054,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Concubine of Lust
SET @ENTRY := 82940;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash of Pain');

-- Concubine of Sin
SET @ENTRY := 82934;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash of Pain');

-- Conniving Deathblade <Shadow Council>
SET @ENTRY := 82981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169059,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Noxious Bomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,169061,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smoke Bomb');

-- Conniving Deathblade <Shadow Council>
SET @ENTRY := 82960;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169059,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Noxious Bomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,169061,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smoke Bomb');

-- Council Felcaller <Shadow Council>
SET @ENTRY := 86553;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,20000,22000,11,174845,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Foul Totem'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,174843,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Lavabolt Volley');

-- Council Soulspeaker <Shadow Council>
SET @ENTRY := 83023;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176756,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,176725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hand of Gul\'dan'),
(@ENTRY,0,3,0,2,0,100,1,0,40,0,0,11,168039,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonic Gateway at 40% HP');

-- Cro Fleshrender
SET @ENTRY := 77620;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173124,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rend Flesh'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,157858,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Exhausted at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,8000,10000,18000,22000,11,158189,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidate');

-- Crusader Vel'anaar
SET @ENTRY := 83420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,79976,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retribution Aura on Spawn'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,79977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Might on Aggro');

-- Crystal Rager
SET @ENTRY := 78327;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172108,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystalline Burst');

-- Crystal Rager
SET @ENTRY := 78452;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172108,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crystalline Burst');

-- Daggerjaw Hoarder
SET @ENTRY := 79930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163414,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hack and Slash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,60000,60000,11,164561,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,164543,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro');

-- Daggerjaw Pridelord
SET @ENTRY := 79961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,177065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,177066,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rend');

-- Daggerjaw Raider
SET @ENTRY := 79929;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,177065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,177066,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rend');

-- Daleera Moonfang
SET @ENTRY := 85878;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,20000,25000,11,17140,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Fire'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,165738,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,165739,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn');

-- Darkwoods Stalker
SET @ENTRY := 77443;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,165687,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP');

-- Deathweb Crawler
SET @ENTRY := 75273;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165669,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Acid'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,134729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro');

-- Deathweb Crawler
SET @ENTRY := 78291;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165779,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Bite'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,134729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,18000,22000,11,165776,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom-Laced Web');

-- Deathweb Egg Tender
SET @ENTRY := 76947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165669,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Burning Acid'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,165776,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom-Laced Web');

-- Deathweb Hatchling
SET @ENTRY := 75258;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,134729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro');

-- Deathweb Hatchling
SET @ENTRY := 77957;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,134729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro');

-- Deathweb Hatchling
SET @ENTRY := 78864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,134729,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro');

-- Defender Spirit
SET @ENTRY := 81986;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut');

-- Demon Conjurer <Shadow Council>
SET @ENTRY := 77901;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170608,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,171354,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Enflame'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,18000,22000,11,170619,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Malefic Grasp'),
(@ENTRY,0,3,0,1,0,100,1,3000,5000,0,0,11,168139,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Voidwalker on Spawn');

-- Demon Guard
SET @ENTRY := 82921;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,176852,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Malefic Slam on Close'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,176859,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Essence');

-- Demon Raider
SET @ENTRY := 86807;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174872,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Lash'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,174876,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Charge on Aggro');

-- Displaced Bloodpetal
SET @ENTRY := 80722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,8,40,15000,25000,11,152265,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Needle Punch on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,149499,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Big Bop');

-- Displaced Razorleaf
SET @ENTRY := 80103;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,141427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Squirt');

-- Disturbed Podling
SET @ENTRY := 85410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,166605,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl of Thorns on Close');

-- Doombringer
SET @ENTRY := 79503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,170794,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp on Close');

-- Doomcrusher
SET @ENTRY := 82928;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176859,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Essence'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,176852,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Malefic Slam on Close');

-- Dr. Gloom
SET @ENTRY := 77561;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169059,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Noxious Bomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,169061,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smoke Bomb');

-- Draka
SET @ENTRY := 77194;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,54609,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbrand Attack');

-- Dreadpiston
SET @ENTRY := 80576;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,162711,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Clusterpult Shot');

-- Dur'gol the Ruthless
SET @ENTRY := 77349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,164300,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,164311,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,167012,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incorporeal at 40% HP');

-- Dusky Teromoth
SET @ENTRY := 77441;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shimmer Shot'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,171189,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wind Burst');

-- Echo of Murmur
SET @ENTRY := 77795;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175781,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sonic Blast'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,175815,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sonic Boom on Close');

-- Elder Duskwing
SET @ENTRY := 77328;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173573,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Moth Balls'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,173593,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Decaying Dust on Close');

-- Elder Ridge Prowler
SET @ENTRY := 79909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,161229,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pounce'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,162248,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swipe');

-- Encroaching Giant
SET @ENTRY := 79333;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,32065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fungal Decay'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,15550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close');

-- Engineer Draxen
SET @ENTRY := 76791;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2200,11,163501,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Explosive Bomb');

-- Engineer Trak
SET @ENTRY := 77387;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2200,11,163501,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Explosive Bomb');

-- Fel Cannoneer <Shadow Council>
SET @ENTRY := 84880;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,169846,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Lava Burst'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,170426,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Foul Totem');

-- Fel Legionnaire
SET @ENTRY := 84367;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169918,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,169354,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Spike');

-- Fel Seer <Shadow Council>
SET @ENTRY := 84873;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,169846,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Lava Burst'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,170426,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Foul Totem');

-- Fel Vanguard
SET @ENTRY := 86745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169918,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,169354,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Spike');

-- Felbark
SET @ENTRY := 80204;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161784,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bathe in Flame'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,161794,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Flames');

-- Felchained Elemental
SET @ENTRY := 84266;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,170376,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Shatter on Death');

-- Felfire Batrider <Shadow Council>
SET @ENTRY := 84112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170091,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Firebomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,170099,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Haymaker');

-- Felfire Consort
SET @ENTRY := 82992;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175751,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2500,11,175769,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Felfire Blast');

-- Felfire Elemental
SET @ENTRY := 84278;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,170376,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Shatter on Death');

-- Felfire Fiend
SET @ENTRY := 86531;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,222571,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireblast');

-- Felguard Protector
SET @ENTRY := 78639;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171056,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Crash');

-- Felwrought Annihilator
SET @ENTRY := 77528;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,20000,22000,11,171430,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Enflame'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,171433,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Immolation Aura on Spawn');

-- Fervid Adherent <Shadow Council
SET @ENTRY := 77022;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169059,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Noxious Bomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,169061,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smoke Bomb'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,169064,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Strikes at 40% HP');

-- Field Medic Mahoaan
SET @ENTRY := 83513;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,15493,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 40% HP'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,79962,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Righteousness on Aggro');

-- Field Medic Nesrerah
SET @ENTRY := 83736;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,15493,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 40% HP'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,79962,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Righteousness on Aggro');

-- Fireblade Invoker
SET @ENTRY := 77047;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,162074,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,166727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cauterizing Flame');

-- Fireblade Invoker
SET @ENTRY := 77066;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,162074,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,166727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cauterizing Flame');

-- Fireblade Invoker
SET @ENTRY := 77201;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,162074,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,166727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cauterizing Flame');

-- Fireblade Invoker
SET @ENTRY := 83811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,162074,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,166727,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cauterizing Flame');

-- Fluttering Teromoth
SET @ENTRY := 79595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173573,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Moth Balls');

-- Forest Stalker
SET @ENTRY := 79745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,165687,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP');

-- Fort Wrynn Footman
SET @ENTRY := 81428;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,12169,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 40% HP');

-- Fort Wrynn Footman
SET @ENTRY := 81468;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,12169,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 40% HP');

-- Fort Wrynn Footman
SET @ENTRY := 81470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,12169,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 40% HP');

-- Fort Wrynn Footman
SET @ENTRY := 81471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,12169,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 40% HP');

-- Fort Wrynn Magus
SET @ENTRY := 81430;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

-- Fort Wrynn Magus
SET @ENTRY := 81437;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,125160,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard');

-- Fort Wrynn Magus
SET @ENTRY := 81438;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,125160,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Blizzard');

-- Frenzied Ancient
SET @ENTRY := 79409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175302,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Breath of Cinders');

-- Frenzied Golem <Vortex, Arcane Enchanted, Dampening>
SET @ENTRY := 77614;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161025,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Sentry'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,161035,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vortex'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,160990,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Sentries at 40% HP');

-- Frenzied Manafeeder
SET @ENTRY := 78390;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172112,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mana Volley');

-- Furious Glowgullet
SET @ENTRY := 80345;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158982,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrosive Bite'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,159015,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Charge on Close');

-- Galzomar
SET @ENTRY := 78713;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,25000,11,31598,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rain of Fire'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,170794,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp on Close');

-- Garrison Priest
SET @ENTRY := 85723;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9734,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,20000,25000,11,17140,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Fire'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,165738,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close'),
(@ENTRY,0,3,0,1,0,100,0,500,1000,600000,600000,11,165739,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Word: Fortitude on Spawn');

-- Garrison Soldier
SET @ENTRY := 85778;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,12169,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shield Block at 40% HP');

-- Gennadian
SET @ENTRY := 80471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161577,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bite'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,17000,20000,11,164764,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ball of Fire'),
(@ENTRY,0,2,0,0,0,100,0,12000,12000,10000,25000,11,164758,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fiery Breath'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,162073,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tail at 40% HP');

-- Gezz'ran
SET @ENTRY := 87086;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,165687,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP');

-- Glimmerwing
SET @ENTRY := 77719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173608,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glimmer Shot'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,173684,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chrysalis at 40% HP');

-- Glowgullet Devourer
SET @ENTRY := 79190;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158982,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corrosive Bite'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,159015,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Charge on Close');

-- Glowing Draenite Crystal
SET @ENTRY := 79926;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162992,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crystalize');

-- Gordunni Basher
SET @ENTRY := 79231;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,164251,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Big Foot Kick'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,164257,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,164247,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ground Stomp on Close'),
(@ENTRY,0,3,0,11,0,100,1,0,0,0,0,11,147085,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Massive Weapon on Spawn');

-- Gordunni Cleaver
SET @ENTRY := 79234;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,164251,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Big Foot Kick'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,164257,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,164247,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ground Stomp on Close');

-- Gordunni Warcrier
SET @ENTRY := 81764;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,20,15000,25000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring on Close'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,164324,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Determination at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,164323,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Precise Strike');

-- Gorebound Beast-Tamer
SET @ENTRY := 77574;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,20000,11,36208,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steal Weapon'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,171331,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pillaging Flames');

-- Gorebound Beast-Tamer
SET @ENTRY := 88961;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,20000,11,36208,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steal Weapon'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,171331,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pillaging Flames');

-- Gorebound Demonguard
SET @ENTRY := 77541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171056,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Crash');

-- Gorebound Insurgent <Shadow Council>
SET @ENTRY := 85490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,170367,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw');

-- Gorebound Insurgent <Shadow Council>
SET @ENTRY := 85966;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,170367,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw');

-- Gorebound Insurgent <Shadow Council>
SET @ENTRY := 87337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,170367,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw');

-- Gorebound Legionnaire
SET @ENTRY := 77490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw'),
(@ENTRY,0,1,0,9,0,100,0,5,25,15000,25000,11,171459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Close');

-- Gorebound Legionnaire
SET @ENTRY := 79127;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw'),
(@ENTRY,0,1,0,9,0,100,0,5,25,15000,25000,11,171459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Close');

-- Gorebound Vessel
SET @ENTRY := 79125;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,159969,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Firebomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,170099,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Haymaker');

-- Gorgorek
SET @ENTRY := 85042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176229,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ancient Rune'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,176237,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aftershocks');

-- Grom'kar Blademaster
SET @ENTRY := 85456;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,4,15000,25000,11,162078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Coil on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,166722,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Weapon');

-- Grom'kar Blademaster
SET @ENTRY := 85457;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,4,15000,25000,11,162078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Coil on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,166722,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Weapon');

-- Grom'kar Bulwark
SET @ENTRY := 85454;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158158,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidate'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,158198,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark at 40% HP');

-- Grom'kar Bulwark
SET @ENTRY := 85459;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158158,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidate'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,158198,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark at 40% HP');

-- Grom'kar Deadeye
SET @ENTRY := 75749;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,162668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kickback on Close');

-- Grom'kar Deadeye
SET @ENTRY := 75943;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,162668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kickback on Close');

-- Grom'kar Deadeye
SET @ENTRY := 77023;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,162668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kickback on Close');

-- Grom'kar Deadeye
SET @ENTRY := 77207;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,162668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kickback on Close');

-- Grom'kar Deadeye
SET @ENTRY := 85450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,162668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kickback on Close');

-- Grom'kar Deadeye
SET @ENTRY := 85460;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,162668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Kickback on Close');

-- Grom'kar Grenadier
SET @ENTRY := 84630;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,159085,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rifle Shot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162666,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rapid Shot');

-- Grom'kar Grimshot
SET @ENTRY := 75752;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,126346,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,157013,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hide-Piercing Shot'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,157387,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hunter\'s Signal at 40% HP');

-- Grom'kar Grimshot
SET @ENTRY := 75947;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,126346,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,157013,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hide-Piercing Shot'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,157387,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hunter\'s Signal at 40% HP');

-- Grom'kar Grimshot
SET @ENTRY := 77203;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,126346,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,157013,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hide-Piercing Shot'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,157387,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hunter\'s Signal at 40% HP');

-- Grom'kar Grimshot
SET @ENTRY := 83805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,126346,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,157013,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hide-Piercing Shot'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,157387,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hunter\'s Signal at 40% HP');

-- Grom'kar Lieutenant
SET @ENTRY := 81704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158158,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidate'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,158198,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bulwark at 40% HP');

-- Grom'kar Punisher
SET @ENTRY := 85455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Aggro');

-- Grom'kar Punisher
SET @ENTRY := 85458;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Aggro');

-- Grom'kar Shadowblade
SET @ENTRY := 75753;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174433,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Slash'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,174436,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Vial on Close');

-- Grom'kar Shadowblade
SET @ENTRY := 75946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174433,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Slash'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,174436,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitating Vial on Close');

-- Grom'kar Shadowblade
SET @ENTRY := 84359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stormstrike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,157388,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slayer\'s Signal at 40% HP');

-- Grom'kar Siegesmith
SET @ENTRY := 80552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150705,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Wrench'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Grom'kar Siegesmith
SET @ENTRY := 85978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150705,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Wrench'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,22120,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Grom'kar Skirmisher
SET @ENTRY := 90305;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,166740,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Blade');

-- Grom'kar Vanguard
SET @ENTRY := 75747;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,149212,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grievous Shield Bash');

-- Grom'kar Vanguard
SET @ENTRY := 77024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,149212,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grievous Shield Bash');

-- Grom'kar Vanguard
SET @ENTRY := 77202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Aggro');

-- Grom'kar Vanguard
SET @ENTRY := 83637;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Aggro');

-- Grom'kar Vanguard
SET @ENTRY := 83806;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Aggro');

-- Gronnling Mount
SET @ENTRY := 87601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175703,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Siege Blast'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,175119,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cannon Barrage');

-- Grrbrrgle
SET @ENTRY := 85572;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175747,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Big Sharp Nasty Claws');

-- Gug'tol <Shadow Council>
SET @ENTRY := 83019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169030,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Doom'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,175714,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Madness at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,169028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Chaos');

-- Haakun the All-Consuming
SET @ENTRY := 83008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168532,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Expel Souls'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,175691,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Funnel'),
(@ENTRY,0,2,0,13,0,100,0,5000,8000,20000,30000,11,170402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Shackle on Player Spell Cast'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,10000,10000,11,175695,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Void');

-- Hammertooth
SET @ENTRY := 77715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,154224,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whip Splash'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Hen Chick
SET @ENTRY := 77627;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162921,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peck'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,161182,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Protective Frenzy at 40% HP');

-- Hen-Mother Hami
SET @ENTRY := 77626;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,161191,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Zephyr Rush on Aggro');

-- Hilaani
SET @ENTRY := 77431;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,176065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Headbutt');

-- Imp Charmer <Shadow Council>
SET @ENTRY := 83017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,169028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Chaos');

-- Imp Seer <Shadow Council>
SET @ENTRY := 83018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,169028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Chaos');

-- Insidious Defiler <Shadow Council>
SET @ENTRY := 76969;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,50,1,3000,5000,0,0,11,169027,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Burning Familiar on Spawn'),
(@ENTRY,0,1,0,1,0,50,1,3000,5000,0,0,11,169021,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Felfire Familiar on Spawn'),
(@ENTRY,0,2,0,1,0,50,1,3000,5000,0,0,11,169026,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Shadowflame Familiar on Spawn'),
(@ENTRY,0,3,0,0,0,100,0,3000,5000,12000,15000,11,157326,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption Ritual'),
(@ENTRY,0,4,0,0,0,100,0,0,0,3400,4700,11,169028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Chaos');

-- Invasive Shambler
SET @ENTRY := 79335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173285,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spore Burst');

-- Iridium Geode
SET @ENTRY := 80072;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162992,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Crystalize');

-- Iron Boltblaster
SET @ENTRY := 74892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,149308,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shotgun');

-- Iron Brute
SET @ENTRY := 75944;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,161601,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enraged at 30% HP');

-- Iron Explosive
SET @ENTRY := 78479;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170517,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Activating'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,170518,3,0,0,0,0,0,2,0,0,0,0,0,0,'Cast Explosive on Death');

-- Iron Shredder
SET @ENTRY := 75815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,152769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shred');

-- Iron Shredder Prototype
SET @ENTRY := 79256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160156,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death from Above'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,160152,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Elecrostatic Distortion');

-- Kaavu the Crimson Claw
SET @ENTRY := 77750;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165373,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Whirl'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,158099,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Electrified Chakram');

-- Kaelynara Sunchaser
SET @ENTRY := 78501;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170365,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Barrage'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,170666,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,174756,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Spheres at 40% HP');

-- Kana
SET @ENTRY := 77669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,131944,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ferocious Bite');

-- Ketya Shrediron <Principal Engineer>
SET @ENTRY := 75986;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160189,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Manual Override'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2300,3900,11,160184,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Zot!'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,160188,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Power Armor at 40% HP');

-- Kharazos the Triumphant
SET @ENTRY := 78710;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171239,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Spike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,171236,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Slam');

-- Kil'uun
SET @ENTRY := 77430;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162921,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peck'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,22000,25000,11,162947,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plume Typhoon');

-- Klikixx
SET @ENTRY := 78872;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172873,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poison Spray'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,172850,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Web Blast');

-- Kurlosh Doomfang <Shadow Council>
SET @ENTRY := 82988;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,169060,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smoke Bomb');

-- Lady Demlash <Shadow Council>
SET @ENTRY := 82942;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176339,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonic Breath'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,176350,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Incinerate'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,176340,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Leap at 40% HP');

-- Lakebottom Zapper
SET @ENTRY := 79636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,167594,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jolt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,161629,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Discharge on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,161673,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Charging Up at 40% HP');

-- Legion Assailant
SET @ENTRY := 76883;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171056,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Crash');

-- Legion Assailant
SET @ENTRY := 78455;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171084,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamelash');

-- Legion Vanguard
SET @ENTRY := 88494;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamelash');

-- Light's Rest Defender
SET @ENTRY := 81992;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Light's Rest Defender
SET @ENTRY := 82019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Living Apexis Shard
SET @ENTRY := 79924;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163696,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Resonant Shards');

-- Lo'marg Jawcrusher
SET @ENTRY := 77784;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169797,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fissure'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,169805,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fel Flames on Close'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,169804,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flaming Fists on Spawn'),
(@ENTRY,0,3,0,2,0,100,1,0,10,0,0,11,169801,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Waning Control at 10% HP');

-- Lord Korinak
SET @ENTRY := 82920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174855,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eruption');

-- Lost Soul
SET @ENTRY := 77408;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,175175,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Void Shards');

-- Machinist B'randt
SET @ENTRY := 80962;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2200,11,168102,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blackrock Bomb');

-- Marauding Destroyer
SET @ENTRY := 84181;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamelash'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,170067,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Charge on Aggro');

-- Marauding Warder
SET @ENTRY := 84180;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flamelash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,168350,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Crash');

-- Massive Riverwallow
SET @ENTRY := 79587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,5568,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Trample on Close');

-- Matron of Sin
SET @ENTRY := 82998;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175892,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Blast'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,175881,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonic Nova on Close'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,175871,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fatal Attraction');

-- Mok'war the Terrible
SET @ENTRY := 77350;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,164304,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Missiles'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,167012,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Incorporeal at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,157241,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wail of the Restless on Close');

-- Nathrezim Helot
SET @ENTRY := 78271;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,170794,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast War Stomp on Close');

-- Nefarious Consort
SET @ENTRY := 82990;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168985,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Burst'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,168948,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Beguile'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,168982,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl of Blades at 40% HP');

-- Nefarious Madame
SET @ENTRY := 82996;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168985,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Burst'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,168948,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Beguile'),
(@ENTRY,0,2,0,0,0,100,0,0,0,2000,2500,11,168986,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Blast'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,168982,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl of Blades at 40% HP');

-- Nightslash Owl
SET @ENTRY := 77442;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171186,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peck'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,171180,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gust');

-- No'losh
SET @ENTRY := 79334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162726,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Overload');

-- Noxious Riverhopper
SET @ENTRY := 78673;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158537,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Pool'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,158532,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Trounce at 40% HP'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,158806,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poisonous Skin on Spawn');

-- O'mogg Blackheart <Shadow Council>
SET @ENTRY := 76876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Call Abyssal'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2500,11,169849,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolation');

-- Olin Umberhide
SET @ENTRY := 85903;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Shout');

-- Orumo the Observer
SET @ENTRY := 87668;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175188,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Glare'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,175196,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sear');

-- Palebelly Croaker
SET @ENTRY := 78671;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158537,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Pool'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,158532,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Toxic Trounce at 40% HP'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,158806,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Poisonous Skin on Spawn');

-- Peon
SET @ENTRY := 80313;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,31553,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hamstring');

-- Pesky Imp
SET @ENTRY := 80213;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,35913,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball');

-- Protective Shimmerwing Moth
SET @ENTRY := 86810;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,163710,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shimmer Shot');

-- Ra'kahn
SET @ENTRY := 77741;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162227,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bounding Swipe'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,161222,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pounce'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,162246,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Tooth and Claw at 40% HP');

-- Ra'tok the Hammer
SET @ENTRY := 77684;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,158240,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cluster Bombs on Spawn'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,161601,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enraged at 30% HP'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,157843,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoulder Charge on Aggro');

-- Ravenous Mongrel
SET @ENTRY := 79110;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Bite');

-- Refuge Watcher
SET @ENTRY := 86021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave');

-- Ridge Prowler
SET @ENTRY := 79703;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162248,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swipe'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,162244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,3,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade');

-- Ripgut
SET @ENTRY := 80058;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,177065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,22000,22000,11,177066,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rend');

-- Riverwallow Calfling
SET @ENTRY := 79662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Riverwallower
SET @ENTRY := 79577;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,176048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Rune Ritualist <Shadow Council>
SET @ENTRY := 86591;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176756,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,176725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hand of Gul\'dan');

-- Sandreaver
SET @ENTRY := 87251;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163035,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scuttling Strike');

-- Sandreaver Matriarch
SET @ENTRY := 87250;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163035,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scuttling Strike');

-- Sargerei Destructor
SET @ENTRY := 84337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169185,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonic Breath'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2500,11,169849,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolation'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,169183,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Leap on Aggro');

-- Sargerei Discordant
SET @ENTRY := 86190;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,171459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw');

-- Sargerei Felbringer
SET @ENTRY := 84334;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169159,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonic Breath'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2500,11,169156,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolation'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,169157,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Leap on Aggro');

-- Sargerei Fiendmaster
SET @ENTRY := 83021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,173051,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Charm at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,174754,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Chaos');

-- Sargerei Fiendspeaker
SET @ENTRY := 83020;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,174754,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Chaos');

-- Sargerei Huntsman
SET @ENTRY := 84026;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,176790,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Sargerei Huntsman
SET @ENTRY := 84055;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,176790,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Sargerei Punisher
SET @ENTRY := 91685;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,183209,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Harmful Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,183214,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Felfire Slam');

-- Sargerei Ritualist
SET @ENTRY := 87341;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,176756,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,176725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hand of Gul\'dan');

-- Sargerei Soul-Twister
SET @ENTRY := 83004;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170396,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Funnel'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,168493,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Draw Souls at 40% HP'),
(@ENTRY,0,2,0,13,0,100,0,5000,8000,20000,30000,11,170402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Shackle on Player Spell Cast');

-- Sargerei Souldrainer
SET @ENTRY := 91686;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170396,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Funnel'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,168493,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Draw Souls at 40% HP'),
(@ENTRY,0,2,0,13,0,100,0,5000,8000,20000,30000,11,170402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Shackle on Player Spell Cast');

-- Sargerei Soulspewer
SET @ENTRY := 83011;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170396,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Funnel'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,168493,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Draw Souls at 40% HP'),
(@ENTRY,0,2,0,13,0,100,0,5000,8000,20000,30000,11,170402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Shackle on Player Spell Cast');

-- Sargerei Summoner
SET @ENTRY := 84094;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,50,1,3000,5000,0,0,11,168137,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Felhunter on Spawn'),
(@ENTRY,0,1,0,1,0,50,1,3000,5000,0,0,11,168138,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Observer on Spawn'),
(@ENTRY,0,2,0,1,0,50,1,3000,5000,0,0,11,168139,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Voidwalker on Spawn'),
(@ENTRY,0,3,0,0,0,100,0,3000,5000,12000,15000,11,170608,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption'),
(@ENTRY,0,4,0,0,0,100,0,0,0,3400,4700,11,174947,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Empowerment'),
(@ENTRY,0,5,0,0,0,100,0,10000,10000,20000,22000,11,170619,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Malefic Grasp');

-- Sha'tari Battle-Mage
SET @ENTRY := 83493;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,79849,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Armor on Spawn');

-- Sha'tari Crusader
SET @ENTRY := 83417;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,79977,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blessing of Might on Aggro'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,79976,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retribution Aura on Spawn');

-- Sha'tari Field Medic
SET @ENTRY := 83511;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,168067,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Light at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,79962,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Seal of Righteousness');

-- Shadow Council Pyromancer
SET @ENTRY := 78202;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169159,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonic Breath'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,169156,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Immolation');

-- Shadow Council Summoner
SET @ENTRY := 77794;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,170828,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,170825,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony');

-- Shadow Guardian <Shadow Council>
SET @ENTRY := 77973;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw');

-- Shadow Infiltrator <Shadow Council>
SET @ENTRY := 76663;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169064,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Strikes');

-- Shadow Militant <Shadow Council>
SET @ENTRY := 78319;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,171459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Aggro');

-- Shadow Pillager <Shadow Council>
SET @ENTRY := 76686;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,36208,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steal Weapon'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2200,11,171331,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pillaging Flames');

-- Shadow Pillager <Shadow Council>
SET @ENTRY := 78729;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,36208,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steal Weapon'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2200,11,171331,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pillaging Flames');

-- Shadow Pillager <Shadow Council>
SET @ENTRY := 88039;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,36208,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steal Weapon'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2200,11,171331,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pillaging Flames');

-- Shadow Raider
SET @ENTRY := 77673;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,171459,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Aggro');

-- Shadowborne Dementor <Shadow Council>
SET @ENTRY := 77548;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,170828,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,170825,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony');

-- Shadowborne Dementor <Shadow Council>
SET @ENTRY := 79187;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,170828,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,170825,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony');

-- Shadowborne Felcaster
SET @ENTRY := 88040;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Bomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,174730,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball Barrage');

-- Shadowborne Reverend <Shadow Council>
SET @ENTRY := 77426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,170828,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,170825,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony');

-- Shadowbourne Felcaster <Shadow Council>
SET @ENTRY := 84871;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Bomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,174730,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball Barrage');

-- Shadowbourne Felcaster <Shadow Council>
SET @ENTRY := 85498;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174721,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Bomb'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,174730,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Fireball Barrage');

-- Shadowflame Familiar
SET @ENTRY := 84445;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,169020,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame Blast');

-- Shadowflame Fiend
SET @ENTRY := 86529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169036,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame Nova');

-- Shadowflame Terrorwalker
SET @ENTRY := 82930;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176440,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowflame Pyre'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,176396,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowflame Axes at 40% HP'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,176359,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Charge on Aggro');

-- Sharpfang Stalker
SET @ENTRY := 76685;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,162244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162248,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swipe');

-- Shattered Hand Captain
SET @ENTRY := 79558;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175105,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gore Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,175098,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Defiled Blood at 40% HP');

-- Shattered Hand Grunt
SET @ENTRY := 79544;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174438,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Break Legs'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,174439,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fierce Bludgeoning');

-- Shattrath Anchorite
SET @ENTRY := 77746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,162220,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Smite'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,162219,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Holy Nova on Close');

-- Sher'khaan <Sharpfang Patriarch>
SET @ENTRY := 76687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,58506,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,161229,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pounce'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,22000,11,162248,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swipe');

-- Shimmerwing Moth
SET @ENTRY := 79910;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shimmer Shot');

-- Shimmerwing Moth
SET @ENTRY := 79923;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shimmer Shot');

-- Shirzir
SET @ENTRY := 79543;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170918,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Optic Blast'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,169902,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast All-Seeing Eye on Spawn'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,170907,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Eye Beam');

-- Sikthiss, Maiden of Slaughter
SET @ENTRY := 78715;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168995,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Field'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,168986,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Blast'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,169001,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Torrent of Blades on Close');

-- Silthide
SET @ENTRY := 51015;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,167439,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whip Splash');

-- Socrethar
SET @ENTRY := 82662;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175272,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball Barrage'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,174956,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Nether Protection at 40% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,20,22000,25000,11,174978,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wrath of Socrethar at 20% HP');

--Soul Guardian <Shadow Council> 
SET @ENTRY := 86600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173548,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grim Toil');

-- Soulbinder Halaari
SET @ENTRY := 79977;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175801,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2200,2500,11,175812,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Spike'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,175809,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Void Mend at 40% HP');

-- Soulbinder Naylana <Sargerei War Council>
SET @ENTRY := 88083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175801,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Word: Pain'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2200,2500,11,175812,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Spike'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,175809,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Void Mend at 40% HP');

-- Steeltusk
SET @ENTRY := 86549;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175626,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fiery Headbutt'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,158207,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Smash on Close');

-- Strategist Ankor <Sargerei War Council>
SET @ENTRY := 88071;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw'),
(@ENTRY,0,1,0,9,0,100,0,5,25,15000,25000,11,171466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Close');

-- Sultry Desecrator
SET @ENTRY := 76968;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168985,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Burst'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,168982,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl of Blades at 40% HP');

-- Sun-Sage Kairyx
SET @ENTRY := 75302;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158441,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Solar Zone'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,158429,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Solar Wrath'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,158433,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Solar Radiance at 40% HP');

-- Sunsworn Defender
SET @ENTRY := 77615;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,171943,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Shot'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Sunsworn Knight
SET @ENTRY := 79418;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,32416,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice');

-- Surok Darkstorm
SET @ENTRY := 77677;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170367,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Throw'),
(@ENTRY,0,1,0,9,0,100,0,5,25,15000,25000,11,171466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Charge on Close');

-- Tagar Spinebreaker <Shadow Council>
SET @ENTRY := 76745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155513,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Mauler'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,22000,24000,11,155517,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rush');

-- Taladorantula
SET @ENTRY := 77634;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172913,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arachnid Infestation'),
(@ENTRY,0,1,0,2,0,100,0,0,55,22000,25000,11,172902,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spiderling Swarm at 55% HP');

-- Talonpriest Zorkra
SET @ENTRY := 79485;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158830,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Darkness Within'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,158823,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Phantasm at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3400,4700,11,158809,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Phantasm Bolt'),
(@ENTRY,0,3,0,2,0,100,0,0,60,20000,20000,11,158854,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Summon Shadow Figurines at 60% HP');

-- Teroclaw
SET @ENTRY := 79746;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162921,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peck'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,22000,25000,11,162947,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Plume Typhoon');

-- Teroclaw Chick
SET @ENTRY := 79752;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162921,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peck');

-- Terrorwing Commander <Shadow Council>
SET @ENTRY := 86838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170099,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Haymaker');

-- Terrorwing Rider <Shadow Council>
SET @ENTRY := 86515;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170099,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Haymaker'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,174880,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Firebomb');

-- Tol'ressa
SET @ENTRY := 77902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168985,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Burst'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,168948,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Beguile'),
(@ENTRY,0,2,0,0,0,100,0,0,0,2000,2500,11,168986,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Blast'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,168982,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirl of Blades at 40% HP');

-- Tormenting Concubine
SET @ENTRY := 79540;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170851,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lash of Pain'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,170852,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jealous Kiss');

-- Twisted Memory
SET @ENTRY := 77407;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,157176,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grip of the Void');

-- Underseer Bloodmane
SET @ENTRY := 80524;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,40504,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,163483,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,33500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirlwind on Close'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,142499,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Rip on Aggro'),
(@ENTRY,0,4,0,2,0,100,0,0,55,22000,25000,11,79878,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodthirst at 55% HP');

-- Vicegnaw
SET @ENTRY := 80053;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,177065,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,177066,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flesh Rend');

-- Vicious Felhound
SET @ENTRY := 84027;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171444,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Bite');

-- Vigilant Paarthos <Protector of Shattrath>
SET @ENTRY := 88436;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,176676,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Holy Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,10000,11,176671,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Judgment'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,176636,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Sanctified Nova on Death'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,176637,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sanctified Charge on Aggro');

-- Vindicator Dalu
SET @ENTRY := 79970;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161919,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vindicator\'s Fury'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,32416,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice'),
(@ENTRY,0,2,0,2,0,100,0,0,60,22000,25000,11,162221,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Final Verdict at 60% HP');

-- Vindicator Maraad
SET @ENTRY := 77196;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,150628,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of the Righteous'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,169368,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Righteous Fury on Spawn'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,13005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice on Close');

-- Viperlash
SET @ENTRY := 77564;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,174820,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Claws'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,174824,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadowstep at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,10000,11,174135,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unnerving Hiss');

-- Vizier Cromaug <Gordali Council>
SET @ENTRY := 80295;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,167616,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Resonant Strike'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,164307,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164298,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP'),
(@ENTRY,0,3,0,16,0,100,0,164298,30,22000,25000,11,164298,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodlust on Friendlies Missing Buff'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,60000,60000,11,164309,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mage Armor on Spawn');

-- Vizier Vorgorsh <Gordali Council>
SET @ENTRY := 80294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168636,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Eruption'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,164307,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164298,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP'),
(@ENTRY,0,3,0,16,0,100,0,164298,30,22000,25000,11,164298,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodlust on Friendlies Missing Buff'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,60000,60000,11,164309,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mage Armor on Spawn');

-- Vizier Zulmork <Gordali Council>
SET @ENTRY := 80292;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,164304,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Missiles'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,164307,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164298,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP'),
(@ENTRY,0,3,0,16,0,100,0,164298,30,22000,25000,11,164298,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodlust on Friendlies Missing Buff'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,60000,60000,11,164309,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mage Armor on Spawn');

-- Vol'jin's Pride Grunt
SET @ENTRY := 81505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Vol'jin's Pride Grunt
SET @ENTRY := 81507;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Vol'jin's Pride Grunt
SET @ENTRY := 81508;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Vol'jin's Pride Grunt
SET @ENTRY := 81509;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158600,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike');

-- Vol'jin's Pride Headhunter
SET @ENTRY := 79688;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');

-- Vol'jin's Pride Headhunter
SET @ENTRY := 79701;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');

-- Vol'jin's Pride Headhunter
SET @ENTRY := 81511;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');

-- Vol'jin's Pride Headhunter
SET @ENTRY := 81512;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,38556,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');

-- Vol'jin's Pride Magus
SET @ENTRY := 81500;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

-- Vol'jin's Pride Magus
SET @ENTRY := 81503;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

-- Vol'jin's Pride Magus
SET @ENTRY := 81504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

-- Vorpil Ribcleaver <Shadow Council>
SET @ENTRY := 77051;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,173208,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demonic Breath'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,173212,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Firebomb'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,173207,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Demonic Leap at 40% HP');

-- Wandering Eye
SET @ENTRY := 86192;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,169902,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast All-Seeing Eye on Spawn');

-- Wandering Vindicator
SET @ENTRY := 77776;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161479,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blind Recompense'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,161513,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Light of Truth at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,157241,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wail of the Restless');

-- Warlock Ritualist <Shadow Council>
SET @ENTRY := 78321;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,50,1,3000,5000,0,0,11,169027,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Burning Familiar on Spawn'),
(@ENTRY,0,1,0,1,0,50,1,3000,5000,0,0,11,169021,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Felfire Familiar on Spawn'),
(@ENTRY,0,2,0,1,0,50,1,3000,5000,0,0,11,169026,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Shadowflame Familiar on Spawn'),
(@ENTRY,0,3,0,0,0,100,0,3000,5000,12000,15000,11,157326,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption Ritual'),
(@ENTRY,0,4,0,0,0,100,0,0,0,3400,4700,11,169028,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Touch of Chaos');

-- Warlock Ritualist <Shadow Council>
SET @ENTRY := 78629;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170825,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,170828,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');

-- Warlock Soulstealer <Shadow Council>
SET @ENTRY := 79482;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170825,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Agony'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,170828,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');

-- Warsong Overseer
SET @ENTRY := 75745;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2000,11,80149,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Axe'),
(@ENTRY,0,1,0,9,0,100,0,0,30,15000,25000,11,166815,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hooked Net on Close'),
(@ENTRY,0,2,0,9,0,100,0,0,15,15000,25000,11,166762,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Howling Blade on Close');

-- Watchful Eye
SET @ENTRY := 86140;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,1000,1000,11,172140,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Debilitation'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,172139,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lacerating Bite on Close');

-- Wing-Guard Kuuan
SET @ENTRY := 75353;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,165328,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Piercing Rush'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,165358,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whirl on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,158087,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whirling Winds');

-- Witch Lord Morkurk
SET @ENTRY := 80335;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,168636,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Arcane Eruption'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,164307,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Arcane Blast'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164298,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bloodlust at 40% HP'),
(@ENTRY,0,3,0,16,0,100,0,164298,30,22000,25000,11,164298,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodlust on Friendlies Missing Buff'),
(@ENTRY,0,4,0,1,0,100,0,500,1000,60000,60000,11,164309,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Mage Armor on Spawn');

-- Wrathguard Destroyer
SET @ENTRY := 75382;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171236,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,22000,22000,11,171239,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Spike');

-- Xanatos the Defiler
SET @ENTRY := 75294;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,170802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cripple'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,22000,22000,11,175402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Carrion Swarm'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,173365,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cold as Stone on Aggro');

-- Xothear, the Destroyer
SET @ENTRY := 82922;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171236,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,22000,22000,11,171239,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Spike'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,177120,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Lash at 40% HP');

-- Yazheera the Incinerator
SET @ENTRY := 77529;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,162074,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,162078,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Coil on Close'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,162082,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deep Impact');

-- Young Ridge Prowler
SET @ENTRY := 79705;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,162244,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leap on Aggro');

-- Yrel
SET @ENTRY := 77197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,161919,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vindicator\'s Fury'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,32416,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer of Justice'),
(@ENTRY,0,2,0,2,0,100,0,0,60,22000,25000,11,162221,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Final Verdict at 60% HP');

-- Zangarra Sporebat
SET @ENTRY := 79332;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,172652,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peculiar Spores');

-- Zealous Fanatic <Shadow Council>
SET @ENTRY := 77434;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,15000,20000,11,36208,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steal Weapon'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,171331,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pillaging Flames');