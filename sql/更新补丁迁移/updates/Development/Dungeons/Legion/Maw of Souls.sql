-- Cursed Falke
SET @ENTRY := 97163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,199185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ravenous Bite');

-- Diseased Pustule
SET @ENTRY := 108727;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,215950,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Diseased Pustule');

-- Enslaved Shieldmaiden
SET @ENTRY := 102104;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,199061,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hew Soul'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,17000,22000,11,198944,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Breach Armor');

-- Helarjar Champion
SET @ENTRY := 97097;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,20000,28000,11,198405,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Chilling Scream'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,194663,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ghostly Rage at 40% HP');

-- Helarjar Mistcaller
SET @ENTRY := 99033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,194610,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shroud Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,55,22000,25000,11,192016,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shroud of Concentration at 55% HP'),
(@ENTRY,0,2,0,14,0,100,0,150000,40,15000,18000,11,199589,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Whirlpool of Souls on Friendlies');

-- Night Watch Mariner
SET @ENTRY := 97182;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,195279,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bind'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,25000,11,192019,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lantern of Darkness');


-- Plaguemaw
SET @ENTRY := 103045;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,199185,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ravenous Bite'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,203666,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rip To Shreds');

-- Runecarver Slave
SET @ENTRY := 102375;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,202365,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,15000,22000,11,202408,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flare');

-- Runecarver Slave
SET @ENTRY := 114712;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,202365,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blast'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,15000,22000,11,202408,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Flare');

-- Seacursed Mistmender
SET @ENTRY := 97365;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2000,2500,11,194610,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shroud Bolt'),
(@ENTRY,0,1,0,2,0,100,0,0,55,22000,25000,11,192016,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shroud of Concentration at 55% HP'),
(@ENTRY,0,2,0,14,0,100,0,150000,40,15000,18000,11,199589,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Whirlpool of Souls on Friendlies');

-- Seacursed Slaver
SET @ENTRY := 97043;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,15000,18000,11,201567,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Swirling Muck'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,194674,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Barbed Spear on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,12000,15000,11,198752,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fracture');

-- Seacursed Soulkeeper
SET @ENTRY := 97200;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,195031,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defiant Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,22000,11,200208,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brackwater Blast');

-- Seacursed Swiftblade
SET @ENTRY := 98919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,199327,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Very Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,22000,25000,11,185325,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deceptive Strike'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,194615,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sea Legs at 40% HP');

-- Shroud Hound
SET @ENTRY := 97119;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,194506,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shroud Strike');

-- Shroudseeker
SET @ENTRY := 103605;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,194506,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shroud Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,25000,11,216106,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Convulsive Shadows');

-- Skjal <Captain of the Damned>
SET @ENTRY := 99307;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,195279,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bind'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,196885,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Give No Quarter on Aggro'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,18000,25000,11,195293,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Debilitating Shout');

-- Soulfiend Tagerma <Corruptor of the Seas>
SET @ENTRY := 108494;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,215427,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bellow of Spirits'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,215482,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,11000,10000,22000,11,215466,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expel Shadows');

-- The Grimewalker <Sludge of the Seas>
SET @ENTRY := 97185;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,194099,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bile Breath'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,194106,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poisonous Slam on Close');

-- Waterlogged Soul Guard
SET @ENTRY := 99188;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,194442,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Six Pound Barrel'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,25000,11,194640,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast xxxxx');