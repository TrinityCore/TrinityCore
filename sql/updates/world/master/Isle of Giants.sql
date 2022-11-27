-- Agrant Sharpshot <Jurassic Expedition>
SET @ENTRY := 70030;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Arnold Raygun <Jurassic Expedition>
SET @ENTRY := 70034;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,215377,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast The Maw Must Feed');

-- Primal Devilsaur
SET @ENTRY := 69991;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,25000,11,138766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Piercing Roar'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- Primal Devilsaur
SET @ENTRY := 70008;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,25000,11,138766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Piercing Roar'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- Primal Devilsaur
SET @ENTRY := 70009;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,25000,11,138766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Piercing Roar'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- Primal Devilsaur
SET @ENTRY := 70010;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,25000,11,138766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Piercing Roar'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- Primal Devilsaur
SET @ENTRY := 70011;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15000,25000,11,138766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Piercing Roar'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- Primal Direhorn
SET @ENTRY := 69983;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138772,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Double Swipe'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn
SET @ENTRY := 70019;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138772,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Double Swipe'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn
SET @ENTRY := 70016;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138772,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Double Swipe'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn
SET @ENTRY := 70017;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138772,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Double Swipe'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn
SET @ENTRY := 70018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138772,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Double Swipe'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn Hatchling
SET @ENTRY := 70014;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,1,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn Hatchling
SET @ENTRY := 70015;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,1,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn Hatchling
SET @ENTRY := 70012;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,1,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn Hatchling
SET @ENTRY := 69992;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,1,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Primal Direhorn Hatchling
SET @ENTRY := 70013;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP'),
(@ENTRY,0,1,0,9,0,100,0,15,50,15000,25000,11,138769,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Trihorn Charge on Close');

-- Pterrorwing Skyscreamer
SET @ENTRY := 70020;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138817,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skycall'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- Pterrorwing Skyscreamer
SET @ENTRY := 70021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138817,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skycall'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- War-God Dokah <Ward of Beasts>
SET @ENTRY := 70096;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,138044,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thunder Crush'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,138042,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Meteor Shower'),
(@ENTRY,0,2,0,0,0,100,0,15000,15000,20000,35000,11,138040,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Horrific Visage'),
(@ENTRY,0,3,0,2,0,50,0,0,55,30000,30000,11,138043,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Vengeful Spirit at 55% HP'),
(@ENTRY,0,4,0,2,0,50,0,0,55,30000,30000,11,138036,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Scarab Swarm at 55% HP');

-- Young Primal Devilsaur
SET @ENTRY := 70007;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- Young Primal Devilsaur
SET @ENTRY := 70006;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,223971,2,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Hunter\'s Rush at 40% HP');

-- Zandalari Dinomancer
SET @ENTRY := 69925;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,60,0,0,11,138771,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dino Form at 60% HP'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,138770,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dino-Mending at 40% HP');

