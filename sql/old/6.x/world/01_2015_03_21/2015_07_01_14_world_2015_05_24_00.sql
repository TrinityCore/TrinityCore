-- Gnomeregan Scripts
-- Irradiated Pillager SAI
SET @ENTRY := 6329;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,75,9798,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Pillager - On Reset - Add Aura 'Radiation'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,10000,11000,11,9771,64,0,0,0,0,17,0,50,0,0,0,0,0,"Irradiated Pillager - In Combat CMC - Cast 'Radiation Bolt'"),
(@ENTRY,0,2,0,2,0,100,1,0,40,0,0,11,8269,2,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Pillager - Between 0-40% Health - Cast 'Frenzy' (No Repeat)");

-- Caverndeep Ambusher SAI
SET @ENTRY := 6207;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3700,3700,3600,12400,11,2590,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caverndeep Ambusher - In Combat - Cast 'Backstab'");

-- Caverndeep Burrower SAI
SET @ENTRY := 6206;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,9000,13000,11,1604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caverndeep Burrower - In Combat - Cast 'Dazed'"),
(@ENTRY,0,1,0,0,0,100,0,2000,4000,4000,6000,11,9770,64,0,0,0,0,2,0,0,0,0,0,0,0,"Caverndeep Burrower - In Combat CMC - Cast 'Radiation'"),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,4000,8000,11,16145,0,0,0,0,0,2,0,0,0,0,0,0,0,"Caverndeep Burrower - In Combat - Cast 'Sunder Armor'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Caverndeep Burrower - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Irradiated Slime SAI
SET @ENTRY := 6218;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,2000,0,0,75,10341,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Slime - In Combat - Add Aura 'Radiation Cloud'"),
(@ENTRY,0,1,0,0,0,100,0,2000,9000,11000,14000,11,9459,0,0,0,0,0,17,0,50,0,0,0,0,0,"Irradiated Slime - In Combat - Cast 'Corrosive Ooze'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,8000,9000,11,1604,64,0,0,0,0,2,0,0,0,0,0,0,0,"Irradiated Slime - In Combat CMC - Cast 'Dazed'");

-- Irradiated Horror SAI
SET @ENTRY := 6220;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,2000,0,0,75,10341,0,0,0,0,0,1,0,0,0,0,0,0,0,"Irradiated Horror - In Combat - Add Aura 'Radiation Cloud' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4000,5000,10000,12000,11,8211,0,0,0,0,0,2,0,0,0,0,0,0,0,"Irradiated Horror - In Combat - Cast 'Chain Burn'"),
(@ENTRY,0,2,0,0,0,100,0,2000,9000,11000,14000,11,9459,0,0,0,0,0,17,0,50,0,0,0,0,0,"Irradiated Horror - In Combat - Cast 'Corrosive Ooze'"),
(@ENTRY,0,3,0,0,0,100,0,4000,6000,8000,9000,11,1604,64,0,0,0,0,2,0,0,0,0,0,0,0,"Irradiated Horror - In Combat CMC - Cast 'Dazed'");

-- Corrosive Lurker SAI
SET @ENTRY := 6219;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,2000,0,0,75,10341,0,0,0,0,0,1,0,0,0,0,0,0,0,"Corrosive Lurker - In Combat - Add Aura 'Radiation Cloud' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,9000,11000,14000,11,9459,0,0,0,0,0,17,0,50,0,0,0,0,0,"Corrosive Lurker - In Combat - Cast 'Corrosive Ooze'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,8000,9000,11,1604,64,0,0,0,0,2,0,0,0,0,0,0,0,"Corrosive Lurker - In Combat CMC - Cast 'Dazed'");

UPDATE `creature` SET `spawndist`=20, `MovementType`=1 WHERE  `guid`=30137;

-- Viscous Fallout SAI
SET @ENTRY := 7079;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,1,1000,2000,0,0,75,10341,2,0,0,0,0,1,0,0,0,0,0,0,0,"Viscous Fallout - In Combat - Add Aura 'Radiation Cloud'"),
(@ENTRY,0,1,0,0,0,100,0,2000,9000,11000,14000,11,9459,64,0,0,0,0,17,0,50,0,0,0,0,0,"Viscous Fallout - In Combat CMC - Cast 'Corrosive Ooze'");

-- Mechanized Sentry SAI
SET @ENTRY := 6233;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,8000,9000,11,1604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanized Sentry - In Combat - Cast 'Dazed'");

-- Leprous Defender SAI
SET @ENTRY := 6223;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1500,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Leprous Defender - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,7000,9000,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Leprous Defender - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,9000,11000,11,5116,0,0,0,0,0,2,0,0,0,0,0,0,0,"Leprous Defender - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Defender - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Leprous Technician SAI
SET @ENTRY := 6222;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,11,12024,64,0,0,0,0,2,0,0,0,0,0,0,0,"Leprous Technician - On Aggro CMC - Cast 'Net'"),
(@ENTRY,0,1,0,0,0,100,0,2000,6000,8000,9000,11,1604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Leprous Technician - In Combat - Cast 'Dazed'"),
(@ENTRY,0,2,0,0,0,100,0,2000,5000,6000,8000,11,13398,64,0,0,0,0,21,30,0,0,0,0,0,0,"Leprous Technician - In Combat CMC - Cast 'Throw Wrench'");

-- Mechano-Tank SAI
SET @ENTRY := 6225;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5,30,2300,3900,11,1604,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mechano-Tank - Combat CMC - Cast 'Dazed'"),
(@ENTRY,0,1,0,9,0,100,0,5,30,7000,9000,11,10346,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechano-Tank - Within 5-30 Range - Cast 'Multi-Shot'"),
(@ENTRY,0,2,0,9,0,100,0,5,30,9000,11000,11,5116,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechano-Tank - Within 5-30 Range - Cast 'Concussive Shot'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mechano-Tank - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Peacekeeper Security Suit SAI
SET @ENTRY := 6230;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,6000,8000,11,6533,64,0,0,0,0,2,0,0,0,0,0,0,0,"Peacekeeper Security Suit - In Combat CMC - Cast 'Net'"),
(@ENTRY,0,1,0,0,0,50,0,5000,6000,14000,16000,11,10730,0,0,0,0,0,2,0,0,0,0,0,0,0,"Peacekeeper Security Suit - In Combat - Cast 'Pacify'");

-- Mechanized Guardian SAI
SET @ENTRY := 6234;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,6000,7000,11,1604,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechanized Guardian - In Combat - Cast 'Dazed'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,6000,7000,11,11820,0,0,0,0,0,21,40,0,0,0,0,0,0,"Mechanized Guardian - In Combat - Cast 'Field'");

-- Mechano-Flamewalker SAI
SET @ENTRY := 6226;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,6000,6000,10000,11,11306,64,0,0,0,0,1,0,0,0,0,0,0,0,"Mechano-Flamewalker - In Combat CMC - Cast 'Fire Nova'"),
(@ENTRY,0,1,0,0,0,100,0,3000,6000,10000,12000,11,10733,0,0,0,0,0,2,0,0,0,0,0,0,0,"Mechano-Flamewalker - In Combat - Cast 'Flame Spray'");

-- Mechano-Frostwalker SAI
SET @ENTRY := 6227;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,40,0,0,11,22519,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mechano-Frostwalker - Between 0-40% Health - Cast 'Ice Nova' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,6000,8000,9000,11,11264,64,0,0,0,0,1,0,0,0,0,0,0,0,"Mechano-Frostwalker - In Combat CMC - Cast 'Ice Blast'");

-- Caverndeep Reaver SAI
SET @ENTRY := 6211;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,7366,2,0,0,0,0,1,0,0,0,0,0,0,0,"Caverndeep Reaver - On Aggro - Cast 'Berserker Stance' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2000,6000,5000,8000,11,8374,2,0,0,0,0,2,0,0,0,0,0,0,0,"Caverndeep Reaver - In Combat - Cast 'Arcing Smash'"),
(@ENTRY,0,2,0,0,0,100,0,4000,4000,4000,4000,11,845,2,0,0,0,0,2,0,0,0,0,0,0,0,"Caverndeep Reaver - In Combat - Cast 'Cleave'");

-- Holdout Medic SAI
SET @ENTRY := 6392;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,60,0,0,11,22167,0,0,0,0,0,1,0,0,0,0,0,0,0,"Holdout Medic - Between 0-60% Health - Cast 'Heal' (No Repeat)"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,22168,64,0,0,0,0,1,0,0,0,0,0,0,0,"Holdout Medic - On Aggro CMC - Cast 'Renew' (No Repeat)"),
(@ENTRY,0,2,0,1,0,100,0,5000,5000,8000,10000,11,22167,0,0,0,0,0,1,0,0,0,0,0,0,0,"Holdout Medic - Out of Combat - Cast 'Heal'"),
(@ENTRY,0,3,0,1,0,100,0,4000,10000,15000,20000,11,22168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Holdout Medic - Out of Combat - Cast 'Renew'");

-- Walking Bomb SAI
SET @ENTRY := 7915;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,3,0,0,15000,15000,11,11504,0,0,0,0,0,1,0,0,0,0,0,0,0,"Walking Bomb - In Combat - Cast 'Walking Bomb Effect' (No Repeat) (Normal Dungeon)");

UPDATE `creature` SET `spawndist`=20, `MovementType`=1 WHERE  `guid`=30133;

-- Leprous Machinesmith SAI
SET @ENTRY := 6224;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4000,5000,20000,25000,11,10732,0,0,0,0,0,19,6224,50,0,0,0,0,0,"Leprous Machinesmith - In Combat - Cast 'Supercharge'"),
(@ENTRY,0,1,0,0,0,100,0,2000,5000,4000,6000,11,13398,64,0,0,0,0,21,30,0,0,0,0,0,0,"Leprous Machinesmith - In Combat CMC - Cast 'Throw Wrench'"),
(@ENTRY,0,2,0,2,0,100,1,0,90,0,0,11,10348,0,0,0,0,0,1,0,0,0,0,0,0,0,"Leprous Machinesmith - Between 0-90% Health - Cast 'Tune Up' (No Repeat)");

