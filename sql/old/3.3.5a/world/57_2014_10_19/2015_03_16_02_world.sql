-- Azure Spellweaver SAI
SET @ENTRY := 31403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Azure Spellweaver - Combat CMC - Cast 'Arcane Missiles'");

-- Gatekeeper Melindra SAI
SET @ENTRY := 32373;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,1,0,0,0,0,1,0,0,0,0,0,0,0,"Gatekeeper Melindra - Out of Combat - Cast 'Frost Armor'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,17290,64,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Melindra - Combat CMC - Cast 'Fireball'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,19000,25000,11,12738,1,0,0,0,0,2,0,0,0,0,0,0,0,"Gatekeeper Melindra - In Combat - Cast 'Amplify Damage'");

-- Syreian the Bonecarver SAI
SET @ENTRY := 32438;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,3,4,0,100,1,0,0,0,0,11,38952,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - On Aggro CMC - Cast 'Frost Arrow' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,2300,3900,2300,3900,11,50092,64,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - Combat CMC - Cast 'Shoot'"),
(@ENTRY,0,2,0,0,0,100,0,12000,15000,11000,14000,11,38952,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - In Combat - Cast 'Frost Arrow'"),
(@ENTRY,0,3,0,9,0,100,0,0,5,12000,16000,11,47168,1,0,0,0,0,2,0,0,0,0,0,0,0,"Syreian the Bonecarver - Within 0-5 Range - Cast 'Improved Wing Clip'");

-- Unbound Seer SAI
SET @ENTRY := 33422;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4800,11,38204,64,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Seer - Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,9000,12000,12000,15000,11,58667,33,0,0,0,0,5,0,0,0,0,0,0,0,"Unbound Seer - In Combat - Cast 'Ley Curse'");

-- Mistcaller Yngvar SAI
SET @ENTRY := 34965;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,0,0,11,45658,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - Out of Combat - Cast 'Call of the Mist'"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,9532,64,0,0,0,0,2,0,0,0,0,0,0,0,"Mistcaller Yngvar - Combat CMC - Cast 'Lightning Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,6000,9000,12000,17000,11,49816,0,0,0,0,0,5,0,0,0,0,0,0,0,"Mistcaller Yngvar - Combat - Cast 'Mist of Strangulation'"),
(@ENTRY,0,3,0,2,0,100,0,0,30,120000,120000,11,49871,1,0,0,0,0,1,0,0,0,0,0,0,0,"Mistcaller Yngvar - 0-30% Health - Cast 'Rune of Retribution'");

-- Drottinn Hrothgar SAI
SET @ENTRY := 34980;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,0,0,0,0,11,66625,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - Out of Combat - Cast 'Cloud Aura' (No Repeat)"),
(@ENTRY,0,1,0,1,0,100,1,1500,1500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - Out of Combat - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,5,5000,7000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Drottinn Hrothgar - Within 0-5 Range - Cast 'Cleave'"),
(@ENTRY,0,3,0,0,0,100,0,12000,16000,15000,21000,11,67038,1,0,0,0,0,1,0,0,0,0,0,0,0,"Drottinn Hrothgar - In Combat - Cast 'Smash'");

-- Ornolf the Scarred SAI
SET @ENTRY := 35012;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1000,8000,11000,11,38557,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ornolf the Scarred - Combat - Cast 'Throw'"),
(@ENTRY,0,1,0,9,0,100,0,0,5,5000,7000,11,43410,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ornolf the Scarred - Within 0-5 Range - Cast 'Chop'"),
(@ENTRY,0,2,0,0,0,100,0,8000,11000,8000,11000,11,67037,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ornolf the Scarred - Combat - Cast 'Whirlwind'"),
(@ENTRY,0,3,0,2,0,100,0,0,30,40000,40000,11,3019,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ornolf the Scarred - 0-30% Health - Cast 'Frenzy'");

-- Kul the Reckless SAI
SET @ENTRY := 34956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,0,66531,0,0,0,80,3495600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kul the Reckless - On Spellhit 'Open Black Cage' - Run Script");

-- Kvaldir Harpooner SAI
SET @ENTRY := 34907;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,66489,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kvaldir Harpooner - Combat CMC - Cast 'Spear Throw'");

-- Deep Jormungar SAI
SET @ENTRY := 34920;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,1,0,100,1,0,0,500,500,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Out of Combat - Cast 'Submerge' (No Repeat)"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Out of Combat - Set Flags Not Attackable & Not Selectable (No Repeat)"),
(@ENTRY,0,2,3,4,0,100,1,0,0,0,0,28,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Aura 'Submerge' (No Repeat)"),
(@ENTRY,0,3,4,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Aura 'Tunnel Bore Passive' (No Repeat)"),
(@ENTRY,0,4,5,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Cast 'Stand' (No Repeat)"),
(@ENTRY,0,5,6,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,6,0,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Aggro - Remove Flags Not Attackable & Not Selectable (No Repeat)"),
(@ENTRY,0,7,0,0,0,100,0,1000,1000,3000,5000,11,61597,64,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Jormungar - In Combat CMC - Cast 'Acid Spit'"),
(@ENTRY,0,8,0,0,0,100,0,11000,16000,15000,20000,11,61598,1,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - In Combat - Cast 'Sweep'"),
(@ENTRY,0,9,0,0,0,100,0,10000,20000,45000,50000,11,32738,0,0,0,0,0,2,0,0,0,0,0,0,0,"Deep Jormungar - In Combat - Cast 'Bore'"),
(@ENTRY,0,10,11,9,0,100,1,30,60,0,0,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 30-60 Range - Cast 'Submerge' (No Repeat)"),
(@ENTRY,0,11,0,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 30-60 Range - Cast 'Tunnel Bore Passive' (No Repeat)"),
(@ENTRY,0,12,13,9,0,100,1,0,8,0,0,28,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Remove Aura 'Submerge' (No Repeat)"),
(@ENTRY,0,13,14,61,0,100,0,0,0,0,0,28,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Remove Aura 'Tunnel Bore Passive' (No Repeat)"),
(@ENTRY,0,14,15,61,0,100,0,0,0,0,0,11,37752,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Cast 'Stand' (No Repeat)"),
(@ENTRY,0,15,16,61,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Disable Combat Movement (No Repeat)"),
(@ENTRY,0,16,0,61,0,100,0,0,0,0,0,19,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - Within 0-8 Range - Remove Flags Not Attackable & Not Selectable (No Repeat)"),
(@ENTRY,0,17,18,7,0,100,1,0,0,0,0,11,56503,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Cast 'Submerge' (No Repeat)"),
(@ENTRY,0,18,19,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,19,20,61,0,100,0,0,0,0,0,11,29147,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Cast 'Tunnel Bore Passive' (No Repeat)"),
(@ENTRY,0,20,21,61,0,100,0,0,0,0,0,14,0,100,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Set All Threat 0-100 (No Repeat)"),
(@ENTRY,0,21,0,61,0,100,0,0,0,0,0,18,33554434,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Jormungar - On Evade - Set Flags Not Attackable & Not Selectable (No Repeat)");
