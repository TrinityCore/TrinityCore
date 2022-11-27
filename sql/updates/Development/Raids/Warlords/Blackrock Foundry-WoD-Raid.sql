-- Aknor Steelbringer
SET @ENTRY := 77337;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,156018,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Devastating Slam'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,156040,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Drop the Hammer');

-- Animated Slag
SET @ENTRY := 87520;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,160382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defense on Close');

-- Battle Medic Rogg
SET @ENTRY := 78352;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,158709,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lightning Bolt'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,158710,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Lightning'),
(@ENTRY,0,2,0,16,0,100,0,158708,40,22000,25000,11,158708,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Earthen Barrier on Friendlies Missing Buff');

-- Bellows
SET @ENTRY := 78477;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,160382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defense on Close');

-- Bellows Operator
SET @ENTRY := 76811;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,160382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defense on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,177756,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deafening Roar');

-- Bellows Operator
SET @ENTRY := 88821;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,160382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defense on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,177756,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deafening Roar');

-- Blackrock Enforcer
SET @ENTRY := 79208;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,160102,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Clobbering Strike'),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,18000,22000,11,160260,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Bomb'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,160109,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Intimidation at 40% HP');

-- Blackrock Forge Specialist
SET @ENTRY := 79200;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,160079,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shredding Spear'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,160092,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Slash on Close');

-- Cinder Wolf
SET @ENTRY := 76794;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155074,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charring Breath');

-- Cruelfang
SET @ENTRY := 76884;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155061,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Rend and Tear'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,155198,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Savage Howl at 30% HP');

-- Darkshard Acidback
SET @ENTRY := 78801;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,159118,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Acidback on Spawn');

-- Darkshard Crystalback
SET @ENTRY := 78233;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,159939,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Acidmaw'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,20000,11,159775,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shard Volley');

-- Darkshard Gnasher
SET @ENTRY := 78978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,159518,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shattering Charge'),
(@ENTRY,0,1,0,2,0,100,1,0,20,0,0,11,159700,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Insatiable Hunger at 20% HP');

-- Dreadwing
SET @ENTRY := 76874;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,154989,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Inferno Breath'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,155208,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Savage Howl at 30% HP'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,22000,11,154981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Conflagration');

-- Faultline
SET @ENTRY := 76946;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,156305,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Heavy Smash'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,155208,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Savage Howl at 30% HP');

-- Firecaller
SET @ENTRY := 76821;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155186,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cauterize Wounds'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,159408,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,155173,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reactive Earth Shield at 40% HP');

-- Forgemistress Flamehand
SET @ENTRY := 87989;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,175593,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Fists on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,175583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Living Blaze');

-- Furnace Engineer
SET @ENTRY := 88820;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155192,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Bomb'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,160382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defense on Close'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,174726,3,0,0,0,0,0,2,0,0,0,0,0,0,'Cast Drop Lit Bombs on Death'),
(@ENTRY,0,3,0,0,0,100,0,0,0,2500,3500,11,155201,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Electrocution');

-- Furnace Engineer
SET @ENTRY := 76810;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155192,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Bomb'),
(@ENTRY,0,1,0,9,0,100,0,0,8,15000,25000,11,160382,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defense on Close'),
(@ENTRY,0,2,0,6,0,100,1,0,0,0,0,11,174726,3,0,0,0,0,0,2,0,0,0,0,0,0,'Cast Drop Lit Bombs on Death'),
(@ENTRY,0,3,0,0,0,100,0,0,0,2500,3500,11,155201,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Electrocution');

-- Gorak <Deckhand of Enforcer Sorka>
SET @ENTRY := 78343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,158692,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Deadly Throw');

-- Grom'kar Firemender
SET @ENTRY := 87841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,156294,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Grenade'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,160140,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cauterizing Bolt');

-- Grom'kar Man-at-Arms
SET @ENTRY := 77687;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163750,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reckless Slash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163753,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Bellow at 40% HP');

-- Grom'kar Man-at-Arms
SET @ENTRY := 78832;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163750,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Reckless Slash'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163753,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Bellow at 40% HP');

-- Gronnling Laborer
SET @ENTRY := 81114;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,169402,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gronnling Smash'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,18501,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Iron Assembly Warden
SET @ENTRY := 80400;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162516,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Whirling Steel'),
(@ENTRY,0,1,0,13,0,100,0,5000,8000,20000,30000,11,162508,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shield Slam on Player Spell Cast'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,162523,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Bellow at 40% HP');

-- Iron Cleaver
SET @ENTRY := 84859;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,171537,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Reaping Whirl');

-- Iron Crack-Shot
SET @ENTRY := 81315;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,156294,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Grenade'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,156270,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot Rifle');

-- Iron Crack-Shot
SET @ENTRY := 77476;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,156294,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Grenade'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,156270,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot Rifle');

-- Iron Dockworker
SET @ENTRY := 84841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,171570,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Crate');

-- Iron Earthbinder
SET @ENTRY := 84860;
SET @ENTRYTOTEM := 85922;
SET @TOTEMSPELL := 171614;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
UPDATE `creature_template` SET `AIName`='0' WHERE `entry`=@ENTRYTOTEM;
UPDATE `creature_template` SET `spell1`=@TOTEMSPELL WHERE `entry`=@ENTRYTOTEM;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,25000,37000,11,171613,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Inferno Totem'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,171647,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earthen Barrier at 40% HP');

-- Iron Eviscerator
SET @ENTRY := 78347;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158686,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Expose Armor'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,20000,22000,11,158702,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Fixate');

-- Iron Flame Binder
SET @ENTRY := 87515;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,40,22000,25000,11,175620,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4700,11,175621,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lavaburst'),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,175609,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Unbind Flame at 40% HP');

-- Iron Flametwister
SET @ENTRY := 80676;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,178177,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Blast'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163192,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lava Shield at 40% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,10,0,0,11,163194,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Final Flame at 10% HP');

-- Iron Gunnery Sergeant
SET @ENTRY := 78981;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,159481,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Delayed Siege Bomb');

-- Iron Journeyman
SET @ENTRY := 80677;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,164102,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Haymaker');

-- Iron Marksman
SET @ENTRY := 80411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,162777,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162748,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scatter Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,162757,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Trap on Close'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,162902,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Morale at 30% HP');

-- Iron Marksman
SET @ENTRY := 80422;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,162777,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,162748,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scatter Shot'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,162757,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ice Trap on Close'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,162902,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Battle Morale at 30% HP');

-- Iron Mauler
SET @ENTRY := 85748;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,171193,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Crate'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,171580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Massive Ammo Cache');

-- Iron Raider
SET @ENTRY := 81197;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3500,4100,11,156294,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Grenade');

-- Iron Slag-Shaper
SET @ENTRY := 87521;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,20000,25000,11,175941,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Animate Slag'),
(@ENTRY,0,1,0,0,0,100,0,0,0,5000,8000,11,175603,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gripping Slag'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,175981,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rain of Slag on Close');

-- Iron Smith
SET @ENTRY := 80719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163182,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crushing Slam');

-- Iron Soldier
SET @ENTRY := 77665;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,156728,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Explosive Round');

-- Iron Taskmaster
SET @ENTRY := 80708;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,163126,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bonk'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,163121,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Held to Task at 40% HP');

-- Ironcrusher
SET @ENTRY := 76945;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,155236,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush Armor'),
(@ENTRY,0,1,0,9,0,100,0,0,15,15000,25000,11,155247,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stampede on Close');

-- Ironworker
SET @ENTRY := 87448;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,175670,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Packing Explosive Ore on Spawn'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,175672,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw Explosive Ore'),
(@ENTRY,0,2,0,0,0,100,0,3000,5000,12000,15000,11,175668,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Hammer Throw');

-- Karnor the Cruel
SET @ENTRY := 81117;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,188189,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fel Poison'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,170687,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Killing Spree at 40% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,170679,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chain Volley on Close');

-- Markog Aba'dir <The Iron Enforcer>
SET @ENTRY := 80409;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175291,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slam'),
(@ENTRY,0,1,0,2,0,100,1,0,40,0,0,11,162772,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Colossal Roar at 40% HP');

-- Mol'dana Two-Blade
SET @ENTRY := 88902;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,177891,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rising Flame Kick'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,177856,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ember in the Wind at 40% HP');

-- Ogron Hauler
SET @ENTRY := 87719;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,175762,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ground Stomp on Close'),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,12000,15000,11,175752,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Slag Breath'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,175765,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Overhead Smash at 40% HP');

-- Ornery Ironhoof
SET @ENTRY := 80534;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Goring Swipe'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,162675,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ground Slam on Close'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,173790,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Bond at 40% HP');

-- Pack Beast
SET @ENTRY := 77128;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,20000,25000,11,155208,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Savage Howl');

-- Primal Elementalist
SET @ENTRY := 76815;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,158345,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shields Down');

-- Security Guard
SET @ENTRY := 88818;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,155256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elemental Slayer on Spawn'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,160382,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defense at 40% HP');

-- Security Guard
SET @ENTRY := 76812;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,155256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Elemental Slayer on Spawn'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,160382,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Defense at 40% HP');

-- Slag Behemoth
SET @ENTRY := 77504;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,156446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blast Wave'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,19000,22000,11,156345,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Ignite'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,156413,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Volcanic Bomb at 40% HP');

-- Slagshop Brute
SET @ENTRY := 87780;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Death Howl'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,175993,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lumbering Strength at 40% HP');

-- Slagshop Worker
SET @ENTRY := 87771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175987,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture Wound');

-- Stubborn Ironhoof
SET @ENTRY := 80526;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162672,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Goring Swipe'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,8269,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,162675,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ground Slam on Close'),
(@ENTRY,0,3,0,2,0,100,0,0,40,22000,25000,11,173790,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Bond at 40% HP');

-- Thunderlord Beast-Tender
SET @ENTRY := 80423;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,162653,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Electrical Storm'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2800,11,162633,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Call Lightning'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,162602,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Bestial Wrath at 40% HP');

-- Workshop Guardian
SET @ENTRY := 87411;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,12000,15000,11,175624,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Grievous Mortal Wounds'),
(@ENTRY,0,1,0,0,0,100,0,8000,10000,18000,22000,11,175627,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spinning Blade');