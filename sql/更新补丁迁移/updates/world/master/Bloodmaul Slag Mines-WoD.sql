-- Bloodmaul Enforcer
SET @ENTRY := 84978;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,151415,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Beatdown'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,25000,11,151446,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crush'),
(@ENTRY,0,2,0,4,0,100,1,0,0,0,0,11,151542,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lumbering Leap on Aggro');

-- Bloodmaul Flamespeaker
SET @ENTRY := 81767;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,164617,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Exploding Flames'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,164615,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Channel Flames');

-- Bloodmaul Geomancer
SET @ENTRY := 75198;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,164592,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Stone Bolt'),
(@ENTRY,0,1,0,16,0,100,0,164597,40,22000,25000,11,164597,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Stone Bulwark on Friendlies Missing Buff'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,164597,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stone Bulwark at 40% HP');

-- Bloodmaul Magma Binder
SET @ENTRY := 74349;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,151558,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,151566,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Molten Binding');

-- Bloodmaul Ogre Mage
SET @ENTRY := 75272;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,151558,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Burst'),
(@ENTRY,0,1,0,16,0,100,0,151548,40,22000,25000,11,151548,2,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Blood Rage on Friendlies Missing Buff'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,151548,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stone Bulwark at 40% HP');

-- Bloodmaul Ogron
SET @ENTRY := 81750;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15000,25000,11,164587,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Massive Stomp on Close'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,164582,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Colossal Roar on Aggro');

-- Bloodmaul Overseer
SET @ENTRY := 75193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,151581,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Suppression Field on Close'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,151697,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Subjugate');

-- Bloodmaul Overseer
SET @ENTRY := 75426;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,5,15000,25000,11,151581,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Suppression Field on Close'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,151697,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Subjugate');

-- Bloodmaul Slaver
SET @ENTRY := 75191;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,15000,25000,11,151990,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Chain Grip on Close'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,152073,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Shock Bola'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,151965,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slaver\'s Rage at 30% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,15000,11,152043,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Slash');

-- Bloodmaul Warder
SET @ENTRY := 75210;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,40505,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleave'),
(@ENTRY,0,1,0,2,0,100,1,0,60,0,0,11,151545,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Frightening Roar at 60% HP');

-- Calamity <Servant of the Flame>
SET @ENTRY := 74571;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,15000,11,150290,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Scorch'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,18000,22000,11,149975,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Dancing Flames'),
(@ENTRY,0,2,0,9,0,100,0,0,8,15000,25000,11,149997,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Firestorm on Close');

-- Captured Miner
SET @ENTRY := 74357;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,150807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Traumatic Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,150811,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Weakened Will at 30% HP');

-- Captured Miner
SET @ENTRY := 74356;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,150807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Traumatic Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,150811,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Weakened Will at 30% HP');

-- Captured Miner
SET @ENTRY := 74355;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,150807,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Traumatic Strike'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,150811,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Weakened Will at 30% HP');

-- Fleeing Miner
SET @ENTRY := 75646;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Fleeing Miner
SET @ENTRY := 75647;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP');

-- Gnasher
SET @ENTRY := 75194;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,164641,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Rending Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,164624,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Furious Swipes');

-- Magma Lord
SET @ENTRY := 75211;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,152427,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,151623,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Pillar of Flames at 40% HP');

-- Molten Earth Elemental
SET @ENTRY := 75209;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,151720,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Arc');

-- Slagna
SET @ENTRY := 75406;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,152183,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Lava Spit');

-- Vengeful Magma Elemental
SET @ENTRY := 75820;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77508,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,18000,25000,11,152298,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cinder Splash'),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,12000,15000,11,151685,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Armor Dent');