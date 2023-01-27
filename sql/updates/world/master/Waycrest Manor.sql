-- Banquet Steward
SET @ENTRY := 131586;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,265391,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Meaty Rampage'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,265407,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Dinner Bell on Close');

-- Bewitched Captain
SET @ENTRY := 131587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,265371,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Captain\'s Strike'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,265368,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirited Defense at 40% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,20,0,0,11,264027,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Warding Candles at 20% HP');

-- Bile Oozeling
SET @ENTRY := 136541;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,6,0,100,1,0,0,0,0,11,268234,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Bile Explosion on Death');

-- Blight Toad
SET @ENTRY := 135052;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,265364,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blighted Lick'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,265352,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Toad Blight on Death'),
(@ENTRY,0,2,0,2,0,100,1,0,20,0,0,11,264027,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Warding Candles at 20% HP');

-- Corvus
SET @ENTRY := 136945;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,278667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gust'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,278672,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Feathery Onslaught'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,278665,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul-Piercing Gaze at 40% HP');

-- Coven Diviner
SET @ENTRY := 131819;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,260699,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,264378,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fragment Soul'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,264384,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Consume Fragments at 40% HP');

-- Coven Thornshaper
SET @ENTRY := 131666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,264038,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uproot'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2500,11,264050,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Infected Thorn'),
(@ENTRY,0,2,0,2,0,100,1,0,20,0,0,11,264027,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Warding Candles at 20% HP');

-- Crazed Marksman
SET @ENTRY := 131849;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2500,3000,11,264510,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,264456,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tracking Explosive'),
(@ENTRY,0,3,0,2,0,100,1,0,20,0,0,11,264027,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Warding Candles at 20% HP');

-- Deathtouched Slaver
SET @ENTRY := 135552;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,266460,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dread Bolt'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,15000,15000,11,273657,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Dark Leap');

-- Devouring Maggot
SET @ENTRY := 134024;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,278431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Parasitic on Spawn');

-- Devouring Maggot
SET @ENTRY := 142587;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,278431,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Parasitic on Spawn');

-- Diseased Mastiff
SET @ENTRY := 135234;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,265642,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Diseased Crunch');

-- Dreadwing Raven
SET @ENTRY := 135049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,265347,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Peck'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,265346,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Pallid Glare');

-- Enthralled Guard
SET @ENTRY := 131585;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,265372,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Cleave');

-- Executive Chef Daniel
SET @ENTRY := 131601;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,259938,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Inspire at 40% HP');

-- Faceless Maiden
SET @ENTRY := 131821;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,264407,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Horrific Visage');

-- Gloom Horror
SET @ENTRY := 139269;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,273653,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Claw'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,273657,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dark Leap on Aggro');

-- Gorak Tul <Lord of the Blighted Lands>
SET @ENTRY := 131864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,266225,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Darkened Lightning'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,266266,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Summon Deathtouched Slaver at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,266181,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dread Essence');

-- Gorestained Piglet
SET @ENTRY := 135048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,265337,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snout Smack');

-- Governess Tabitha
SET @ENTRY := 131595;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,259990,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Insightful Strike'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,260004,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Book Binding');

-- Groundskeeper Lilith
SET @ENTRY := 131617;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,259848,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reap'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,259857,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sow on Aggro');

-- Head Vintner Justin
SET @ENTRY := 131615;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,260431,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Doppel Strike'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2500,3000,11,260428,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vinegared Batch');

-- Heartsbane Runeweaver
SET @ENTRY := 131677;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,263905,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Marking Cleave'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,263943,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Etch'),
(@ENTRY,0,2,0,2,0,100,1,0,20,0,0,11,264027,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Warding Candles at 20% HP');

-- Heartsbane Soulcharmer
SET @ENTRY := 131812;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,264024,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,263959,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Volley');

-- Heartsbane Vinetwister
SET @ENTRY := 131670;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,263899,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jagged Scratch'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2000,11,263891,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grasping Thorns');

-- Huntmaster Grath
SET @ENTRY := 131853;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,269072,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Inferno Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,269048,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blazing Toss');

-- Infected Peasant
SET @ENTRY := 134041;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,266008,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Infected on Spawn');

-- Jagged Hound
SET @ENTRY := 131669;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,264140,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thorned Claw');

-- Maddened Survivalist
SET @ENTRY := 131850;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,264520,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Severing Serpent'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,264525,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shrapnel Trap');

-- Marked Sister
SET @ENTRY := 131818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,264110,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Darkened Blade on Spawn');

-- Matron Alma
SET @ENTRY := 135365;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,265881,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Decaying Touch'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,265880,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dread Mark'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3000,3500,11,265876,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ruinous Volley');

-- Matron Bryndle
SET @ENTRY := 135329;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,10000,10000,18000,22000,11,265759,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Splinter Spike'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,265741,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drain Soul Essence'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3000,3500,11,265760,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Thorned Barrage');

-- Matron Christiane
SET @ENTRY := 134112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,265877,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ruinous Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,265876,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ruinous Volley'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,263455,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sacrifice at 40% HP'),
(@ENTRY,0,3,0,2,0,100,0,0,55,10000,18000,11,265878,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Weeping Soul at 55% HP');

-- Pallid Gorger
SET @ENTRY := 137830;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,271175,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Ravaging Leap'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,271174,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retch');

-- Roast Chef Rhonda
SET @ENTRY := 131611;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,259866,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Raw Chicken'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3000,3500,11,259894,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Roasting Fire');

-- Runic Disciple
SET @ENTRY := 131685;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,264390,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spellbind'),
(@ENTRY,0,1,0,16,0,100,0,264396,40,22000,25000,11,264396,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Spectral Talisman on Friendlies Missing Buff');

-- Sacrificial Acolyte
SET @ENTRY := 134115;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3000,3500,11,264158,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Soul Blast'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,80,15000,15000,11,263469,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sacrificed Soul at 80% HP');

-- Sauciere Samuel
SET @ENTRY := 131607;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,259903,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gravy Spray');

-- Seamstress Johanna
SET @ENTRY := 131619;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,260293,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Needles'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,260300,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Soul Weave');

-- Soul Essence
SET @ENTRY := 135240;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,267824,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scar Soul');

-- Sown Lasher
SET @ENTRY := 131731;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,272566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Razor Petal');

-- Thistle Acolyte
SET @ENTRY := 135474;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,266035,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bone Splinter'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,266036,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drain Essence');

-- Thornguard
SET @ENTRY := 131858;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,264556,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Tearing Strike'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,11,264150,3,0,0,0,0,0,1,0,0,0,0,0,0,'Cast Shatter on Death'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,257260,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Waycrest Reveler
SET @ENTRY := 131847;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,278567,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Soul Fetish on Spawn');