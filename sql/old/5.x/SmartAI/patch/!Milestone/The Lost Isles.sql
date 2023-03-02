-- Alexi Silenthowl <SI:7>
SET @ENTRY := 39143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,79863,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hemorrhage'),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,79862,0,0,0,0,0,2,0,0,0,0,0,0,0,'Casts Backstab'),
(@ENTRY,0,2,0,0,0,100,0,0,0,3500,4100,11,79866,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Throw'),
(@ENTRY,0,3,0,2,0,100,0,0,55,22000,25000,11,79864,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadowstep at 55% HP');

-- Alliance Captain
SET @ENTRY := 36153;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,18000,22000,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Shout');

-- Alliance Paratrooper <Ironforge 127th Paratroopers>
SET @ENTRY := 39042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Alliance Paratrooper <Ironforge 127th Paratroopers>
SET @ENTRY := 39069;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Alliance Sailor
SET @ENTRY := 36149;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Alliance Sailor
SET @ENTRY := 36176;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Alliance Sailor
SET @ENTRY := 36391;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,11976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike');

-- Alliance Wizard
SET @ENTRY := 36621;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball');

-- Blastshadow the Brutemaster
SET @ENTRY := 39194;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,16000,18000,11,32063,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Corruption');

-- Bomb-Throwing Monkey
SET @ENTRY := 34699;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,8858,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Bomb');

-- Brute Bodyguard
SET @ENTRY := 39589;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Acidic Sweat on Spawn'),
(@ENTRY,0,1,0,9,0,100,0,0,10,15000,25000,11,10966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Uppercut on Close');

-- Brute Overseer
SET @ENTRY := 39193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,76136,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Acidic Sweat on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,3551,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skull Crack');

-- Candy Cane
SET @ENTRY := 39426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,75924,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heartbreaker');

-- Child of Volcanoth
SET @ENTRY := 38845;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,16000,11,8873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Breath on Close');

-- Chip Endale
SET @ENTRY := 39363;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,2,15000,15000,11,75964,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Beatdown on Close'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,75968,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Full Monte');

-- Commander Arrington <SI:7>
SET @ENTRY := 39141;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,79851,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Fan of Knives on Close'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,79853,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,20000,20000,11,60842,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expose Armor'),
(@ENTRY,0,4,0,0,0,100,0,5000,5000,10000,19000,11,79852,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eviscerate');

-- Daggertooth Shark
SET @ENTRY := 34763;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,69203,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite');

-- Darkblade Cyn <SI:7>
SET @ENTRY := 39142;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,60195,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,16000,19000,11,3583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Poison'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,60850,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mutilate at 40% HP'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,66060,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Sprint on Aggro');

-- Delicia Whipsnaps
SET @ENTRY := 39195;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,75960,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whiplash'),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,1,0,3,0,0,0,0,0,1,0,0,0,0,0,0,'Say Text on Death');
-- NPC talk text insert
SET @ENTRY := 39195;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'NOOOOO!',14,0,100,0,0,0, 'on Aggro Text');

-- Faceless of the Deep
SET @ENTRY := 38448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,300000,300000,11,72055,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorption Shield on Spawn'),
(@ENTRY,0,1,0,16,0,100,0,72055,1,15000,30000,11,72055,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Absorption Shield on Repeat'),
(@ENTRY,0,2,0,9,0,100,0,10,70,10000,12000,11,75903,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Crash on Close');

-- Freezya
SET @ENTRY := 35897;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,68209,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt');

-- Gaahl
SET @ENTRY := 38808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frost Shock'),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,72935,0,0,0,0,0,10,241211,38643,0,0,0,0,0,'Cast Zombie Transformation on Spawn'); -- need check GUID

-- Goblin Survivor 
SET @ENTRY := 34748;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,60,0,100,1,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"On summoned say"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,47127,2,0,0,0,0,1,0,0,0,0,0,0,0,"on gossip set emote"),
(@ENTRY,0,2,3,61,0,100,0,0,0,0,0,29,0,0,24021,0,0,0,10,244482,24021,0,0,0,0,0,"Follow destination"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force despawn");
-- NPC talk text insert
SET @ENTRY := 34748;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Thank`s, sweeter!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,1, '$N, it`s you? Thank you!',12,0,50,1,0,0, 'say Text'),
(@ENTRY,0,2, 'Oh, at last! Light! Light! ',12,0,50,1,0,0, 'say Text');

-- Goblin Survivor 
SET @ENTRY := 38409;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,73583,0,0,0,33,38409,0,0,0,0,0,7,0,0,0,0,0,0,0,"On spellhit credit"),
(@ENTRY,0,1,0,62,0,100,0,38409,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"despawn"),
(@ENTRY,0,1,2,61,0,100,0,0,0,0,0,11,73599,4,0,0,0,0,1,0,0,0,0,0,0,0,""),
(@ENTRY,0,2,3,8,0,100,0,73599,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Say text on link"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Force Despawn");

-- Gyrochoppa Pilot
SET @ENTRY := 36129;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Aggro');
-- NPC talk text insert
SET @ENTRY := 36129;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Hey! Get away from my flying machine!',12,0,100,0,0,0, 'on Aggro Text');

-- Iceeya
SET @ENTRY := 40067;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,74724,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt');

-- Jungle Cat
SET @ENTRY := 35904;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,31289,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw');

-- Jungle Panther
SET @ENTRY := 40064;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,31289,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw');

-- KTC Oil Bot
SET @ENTRY := 39376;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,73867,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cutting Laser');

-- KTC Train-a-Tron Deluxe <Professions Trainer & Vendor>
SET @ENTRY := 45286;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Stance on Spawn');

-- Malmo
SET @ENTRY := 38809;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,57780,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,15000,18000,11,75945,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fury of the Storm'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,72935,0,0,0,0,0,10,241211,38643,0,0,0,0,0,'Cast Zombie Transformation on Spawn'); -- need check GUID

-- Mechachicken 
SET @ENTRY := 38224;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,71657,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Egg Barrage');

-- Oomlot Shaman
SET @ENTRY := 38574;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,13281,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Shock'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,12550,1,15000,30000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat');

-- Oomlot Shaman
SET @ENTRY := 38644;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,13281,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Earth Shock'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,600000,600000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Spawn'),
(@ENTRY,0,2,0,16,0,100,0,12550,1,15000,30000,11,12550,1,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Shield on Repeat'),
(@ENTRY,0,3,0,0,0,100,0,10000,10000,10000,18000,11,72518,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Enveloping Winds');

-- Oomlot Tribesman
SET @ENTRY := 38575;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,74613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Oostan Headhunter
SET @ENTRY := 38811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,84837,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Orc Scout
SET @ENTRY := 35894;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,84837,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Poison Spitter
SET @ENTRY := 35896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3800,11,68208,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot Thorns'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,68207,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Spit');

-- Pterrordax Scavenger
SET @ENTRY := 36719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,31273,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Screech on Close');

-- Pygmy Witchdoctor
SET @ENTRY := 35838;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,14,0,100,0,80,40,15000,18000,11,11986,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Wave on Friendlies'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,11986,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Wave at 40% HP');

-- Ravenous Lurker
SET @ENTRY := 36681;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,69203,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite');

-- SI:7 Assassin
SET @ENTRY := 36092;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike');

-- SI:7 Infiltrator
SET @ENTRY := 35891;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,15691,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eviscerate');

-- Smart Mining Monkey
SET @ENTRY := 35812;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,38560,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw');

-- Southsea Mercenary
SET @ENTRY := 39449;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,75361,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Swashbuckling Slice');

-- Steamwheedle Shark
SET @ENTRY := 39354;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32735,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Saw Blade on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,75962,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shred Armor');

-- Strange Tentacle
SET @ENTRY := 33420;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,5000,5000,11,71812,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt');

-- Strangle Vine
SET @ENTRY := 35995;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro');

-- Teloch
SET @ENTRY := 38810;
SET @ENTRYTOTEM := 22895;
SET @TOTEMSPELL := 39592;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,37000,11,39591,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Searing Totem'),
(@ENTRY,0,1,0,0,0,100,0,4000,4000,12000,15000,11,75946,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire and the Flames'),
(@ENTRY,0,2,0,11,0,100,1,0,0,0,0,11,72935,0,0,0,0,0,10,241211,38643,0,0,0,0,0,'Cast Zombie Transformation on Spawn'); -- need check GUID

-- Teraptor Hatchling
SET @ENTRY := 36740;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,6268,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rushing Charge on Aggro');

-- Teraptor Matriarch
SET @ENTRY := 36735;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,35321,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gushing Wound'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,36629,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Terrifying Roar');

-- Trade Prince Gallywix <Leader of the Bilgewater Cartel>
SET @ENTRY := 39582;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,74003,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Downsizing'),
(@ENTRY,0,1,2,0,0,100,0,10000,10000,15000,22000,11,74005,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Revenue Stream'),
(@ENTRY,0,2,0,0,0,61,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Text on Revenue Stream'),
(@ENTRY,0,3,4,0,0,100,0,4000,9000,10000,19000,11,74000,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unload Toxic Assets'),
(@ENTRY,0,4,0,0,0,61,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Text on Unload Toxic Assets'),
(@ENTRY,0,5,6,0,0,100,0,15000,15000,25000,27000,11,74004,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast You\'re Fired'),
(@ENTRY,0,6,0,0,0,61,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Text on  You\'re Fired'),
(@ENTRY,0,7,0,0,0,100,0,10000,10000,10000,10000,11,81000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Call A Meeting');
-- NPC talk text insert
SET @ENTRY := 39582;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'You are FIRED!',14,0,100,0,0,0, 'Text'),
(@ENTRY,1,0, 'I am so money!',14,0,100,0,0,0, 'Text'),
(@ENTRY,2,0, 'Here, I need Unload Some Toxic Assets',14,0,100,0,0,0, 'Text');

-- Vashj'elan Siren
SET @ENTRY := 38360;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frostbolt'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frost Nova on Close');

-- Vashj'elan Warrior
SET @ENTRY := 38359;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heroic Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Venom Spitter
SET @ENTRY := 40068;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,74726,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot Thorns'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,74725,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Spit');

-- Volcanoth
SET @ENTRY := 38855;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,9,0,100,0,0,100,12000,15000,11,73097,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Volcanic Breath on Close');

-- Volcanoth Champion
SET @ENTRY := 38850;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Volcanoth Priest
SET @ENTRY := 38851;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,72991,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Voodoo Illusion
SET @ENTRY := 40722;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,37075,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Damage Amplification: All on Spawn');

-- Yngwie
SET @ENTRY := 38696;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,75,15000,18000,11,75942,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Voodoo Illusion at 75% HP'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,60000,125000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Random Text on Spawn');
-- NPC talk text insert
SET @ENTRY := 36600;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Tak`en goblins! ',14,0,50,1,0,0, 'say Text'),
(@ENTRY,0,1, 'Get em all!',14,0,50,1,0,0, 'say Text'),
(@ENTRY,0,2, 'Measa wa tun na tonga!',14,0,50,1,0,0, 'say Text');

-- Geargrinder Gizmo
SET @ENTRY := 36600;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14001,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add'),
(@ENTRY,0,2,0,19,0,100,0,14474,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add');
-- NPC talk text insert
SET @ENTRY := 36600;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Yeah, there`s tons of people still trapped in the escape pods, boss. Oh, wait! I guess you`re not the boss anymore. Anyways, they`re all probably going to drown if you don`t get them out. ',12,0,100,1,0,0, 'say Text');

-- Sassy Hardwrench <Your Former Executive Assistant>
SET @ENTRY := 35650;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14014,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add'),
(@ENTRY,0,2,0,19,0,100,0,14248,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add'),
(@ENTRY,0,3,0,19,0,100,0,14234,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add');
-- NPC talk text insert
SET @ENTRY := 35650;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'We need all of our bombs and tools to survive on this deserted Island, $N!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,1,0, 'Dampwick`s at the cave entrance just to the southeast!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,2,0, 'We need some new friends if we`re going to survive all of these. Hopefully, the orcs won`t just kill you on sight.',12,0,100,1,0,0, 'say Text');

-- Maxx Avalanche <Shaman Trainer>
SET @ENTRY := 35786;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14473,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add'),
(@ENTRY,0,2,0,20,0,100,0,14473,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest End');
-- NPC talk text insert
SET @ENTRY := 35786;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '&N, you gotta get those teraptor hatching before they gey us!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,1,0, 'Did you here the matriarch growling up on the cliff? Steer clear of her!',12,0,100,1,0,0, 'say Text');

-- Bamm Megabomb <Hunter Trainer>
SET @ENTRY := 35758;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14019,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add'),
(@ENTRY,0,2,0,20,0,100,0,14019,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest End');
-- NPC talk text insert
SET @ENTRY := 35758;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The monkeys are going to get a kick out of those bananas!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,1,0, 'That was the most beautiful thing that I`ve ever seen!',12,0,100,1,0,0, 'say Text');

-- Foreman Dampwick
SET @ENTRY := 35769;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14021,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add'),
(@ENTRY,0,2,0,20,0,100,0,14021,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest End');
-- NPC talk text insert
SET @ENTRY := 35769;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'The kaja`mite has gone and made these monkeys smart! keep that miner safe, $N!',12,0,100,1,0,0, 'say Text'),
(@ENTRY,1,0, 'Oh behalf of the Bi;gewater Cartel! i lay claim to this mine.',12,0,100,1,0,0, 'say Text');

-- Trade Prince Gallywix <Leader of the Bilgewater Cartel>
SET @ENTRY := 36403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,1,0,100,0,30000,125000,30000,125000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Say Test OOC"),
(@ENTRY,0,2,0,19,0,100,0,14120,0,0,0,28,59074,0,0,0,0,0,7,0,0,0,0,0,0,0,"Remove aura 59074 when quest add 14120"),
(@ENTRY,0,4,0,20,0,100,0,14126,0,0,0,75,69010,0,0,0,0,0,7,0,0,0,0,0,0,0,"Put aura on quest end"),
(@ENTRY,0,5,0,20,0,100,0,14126,0,0,0,62,648,0,0,0,0,0,7,0,0,0,533.77,3274.62,0.198,4.9,"Teleport to Lost Isle");
-- NPC talk text insert
SET @ENTRY := 35769;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'I can not me prevent me say that without the fricotage of someone on Kezan, we would be all in security in Azshara to which it is.',14,0,50,5,0,19590, 'say Text'),
(@ENTRY,0,1, 'No Paniquea! I`ll make sure one way this island the lamentable. You will see!',14,0,50,274,0,19588, 'say Text'),
(@ENTRY,0,2, 'Oh, I think that have know all property that is really responsible for this bazard. Do not worry I will ensure that they have what it deserve!',14,0,50,5,0,19587, 'say Text'),
(@ENTRY,0,3, 'Do not be afraid! Trade prince Gallywix is la! Have reaches Azshara before that a stick of dynamite is time to boom and ca despite the evil spirit of who you know!',14,0,50,5,0,19589, 'say Text'),
(@ENTRY,0,4, 'Oh, I`ve had the eye! Let`s just say that there is a goblin who leave here alive and that his name starts with Merchant Prince!',14,0,50,5,0,19591, 'say Text'),
(@ENTRY,0,5, 'Listen to me well all! All those who are not my Boat, can go point to the Island!',14,0,50,5,0,19593, 'say Text');

-- Aggra
SET @ENTRY := 35875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14235,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add'),
(@ENTRY,0,2,0,19,0,100,0,14237,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add');
-- NPC talk text insert
SET @ENTRY := 35875;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Kilag Gorefang should be dawn the path to the west, goblin.',12,0,100,1,0,0, 'say Text'),
(@ENTRY,1,0, 'Head back through the vale and meetup with Kilag at the Wild Overlook.',12,0,100,1,0,0, 'say Text');

-- Kilag Gorefang
SET @ENTRY := 35893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14236,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add'),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,3,0,0,0,100,0,2500,3800,2500,3800,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,4,0,19,0,100,0,14303,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add');
-- NPC talk text insert
SET @ENTRY := 35893;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Use your weed wracker to mow down these plants, little goblin.',12,0,100,1,0,0, 'say Text'),
(@ENTRY,1,0, 'Go back to Aggra and tell her that we`re moving northwest!',12,0,100,1,0,0, 'say Text');

-- Orc Scout
SET @ENTRY := 35893;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,2500,3800,2500,3800,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Orc Scout
SET @ENTRY := 36042;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,2500,3800,2500,3800,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Orc Scout
SET @ENTRY := 35918;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,2500,3800,2500,3800,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Orc Scout
SET @ENTRY := 35894;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,1,100,1,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,2500,3800,2500,3800,11,15620,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot');

-- Scout Brax
SET @ENTRY := 36112;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14241,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add');
-- NPC talk text insert
SET @ENTRY := 36112;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Get to the gyrochoppa! Do it NOW!',14,0,100,1,0,0, 'say Text');

-- Foreman Dampwick
SET @ENTRY := 36470;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,14245,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add');
-- NPC talk text insert
SET @ENTRY := 36470;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Hurry, $N, deploy the Town In A Box! Our people are trapped inside. Oh, I almost forgot your parachute.',12,0,100,1,0,0, 'say Text');

-- Foreman Dampwick
SET @ENTRY := 36471;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,27139,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add');
-- NPC talk text insert
SET @ENTRY := 36471;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Hobart`s fight behind you!',12,0,100,1,0,0, 'say Text');

-- Bamm Megabomb <Hunter Trainer>
SET @ENTRY := 24741;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,64,0,100,0,0,0,0,0,10,1,3,5,6,0,0,1,0,0,0,0,0,0,0,'Play Emote on Gossip'),
(@ENTRY,0,1,0,19,0,100,0,27139,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text on Quest Add');
-- NPC talk text insert
SET @ENTRY := 24741;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, 'Now get us some real eggs!',12,0,100,1,0,0, 'say Text');
