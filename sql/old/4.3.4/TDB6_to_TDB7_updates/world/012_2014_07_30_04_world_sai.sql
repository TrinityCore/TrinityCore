-- Warmaul Warlock SAI
SET @ENTRY := 18037;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,50,1,1000,1000,0,0,11,11939,1,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Warlock - Out of Combat - Cast 'Summon Imp' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Warlock - In Combat CMC - Cast 'Shadow Bolt'");

-- Rajis Fyashe SAI
SET @ENTRY := 18044;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,15043,64,0,0,0,0,2,0,0,0,0,0,0,0,"Rajis Fyashe - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,1,6000,9000,0,0,11,35594,1,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - In Combat - Cast 'Mass Elementals' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,9000,8000,12000,11,35499,0,0,0,0,0,2,0,0,0,0,0,0,0,"Rajis Fyashe - In Combat - Cast 'Water Spout'"),
(@ENTRY,0,3,0,0,0,100,0,18000,24000,18000,24000,11,34787,1,0,0,0,0,2,0,0,0,0,0,0,0,"Rajis Fyashe - In Combat - Cast 'Freezing Circle'"),
(@ENTRY,0,4,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rajis Fyashe - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Enraged Crusher SAI
SET @ENTRY := 18062;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,65,0,30000,30000,8000,8000,11,32015,0,0,0,0,0,2,0,0,0,0,0,0,0,"Enraged Crusher - In Combat - Cast 'Knockdown'"),
(@ENTRY,0,1,2,2,0,100,1,0,30,0,0,11,3019,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Crusher - Between 0-30% Health - Cast 'Frenzy' (No Repeat)"),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Enraged Crusher - Between 0-30% Health - Say Line 0 (No Repeat)");

-- Warmaul Shaman SAI
SET @ENTRY := 18064;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,60,0,2000,2000,4000,4000,11,15038,0,0,0,0,0,2,0,0,0,0,0,0,0,"Warmaul Shaman - In Combat - Cast 'Scorching Totem'"),
(@ENTRY,0,1,0,2,0,100,1,0,49,22000,22000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warmaul Shaman - Between 0-49% Health - Cast 'Healing Wave'");

-- Umbrafen Oracle SAI
SET @ENTRY := 18077;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Oracle - On Aggro - Cast 'Lightning Shield'"),
(@ENTRY,0,1,0,2,0,100,1,0,49,22000,22000,11,11986,0,0,0,0,0,1,0,0,0,0,0,0,0,"Umbrafen Oracle - Between 0-49% Health - Cast 'Healing Wave'");

-- Darkcrest Siren SAI
SET @ENTRY := 18087;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9672,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Siren - In Combat CMC - Cast 'Frostbolt'"),
(@ENTRY,0,1,0,0,0,100,0,7000,10000,14000,18000,11,11831,1,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - In Combat - Cast 'Frost Nova'"),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,12000,17000,11,6726,1,0,0,0,0,5,0,0,0,0,0,0,0,"Darkcrest Siren - In Combat - Cast 'Silence'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Siren - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Bloodscale Enchantress SAI
SET @ENTRY := 18088;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,34447,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscale Enchantress - In Combat CMC - Cast 'Arcane Missiles'"),
(@ENTRY,0,1,0,0,0,100,0,6000,8000,16000,22000,11,34787,1,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Enchantress - In Combat - Cast 'Freezing Circle'");

-- Bloodscale Slavedriver SAI
SET @ENTRY := 18089;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,32064,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Slavedriver - On Aggro - Cast 'Battle Shout' (No Repeat)");

-- Bloodscale Wavecaller SAI
SET @ENTRY := 20089;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,600000,600000,11,34827,33,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodscale Wavecaller - Out of Combat - Cast 'Water Shield' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,"Bloodscale Wavecaller - In Combat CMC - Cast 'Water Bolt'");

-- Darkcrest Sorceress SAI
SET @ENTRY := 19947;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,1800000,1800000,11,12544,33,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Out of Combat - Cast 'Frost Armor' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,0,0,2400,3800,11,13901,64,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Sorceress - In Combat CMC - Cast 'Arcane Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,10000,15000,20000,25000,11,34787,1,0,0,0,0,2,0,0,0,0,0,0,0,"Darkcrest Sorceress - In Combat - Cast 'Freezing Circle'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Darkcrest Sorceress - Between 0-15% Health - Flee For Assist (No Repeat)");
