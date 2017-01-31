UPDATE `creature_template` SET `InhabitType`=`InhabitType`|4 WHERE `entry`=38004;
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry` IN(38232,37665);

-- Spire Gargoyle SAI
SET @ENTRY := 37544;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,3000,2000,4000,11,70189,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spire Gargoyle - In Combat - Cast 'Poison Spit'");

-- Frenzied Abomination SAI
SET @ENTRY := 37546;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,6000,6000,6000,11,70191,0,0,0,0,0,0,0,0,0,0,0,0,0,"Frenzied Abomination - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,30000,30000,60000,60000,11,70371,0,0,0,0,0,1,0,0,0,0,0,0,0,"Frenzied Abomination - In Combat - Cast 'Enrage'");

-- Skybreaker Summoner SAI
SET @ENTRY := 37148;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,2000,6000,11,69969,0,0,0,0,0,5,0,0,0,0,0,0,0,"Skybreaker Summoner - In Combat - Cast 'Curse of Doom'"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,6000,10000,11,69972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skybreaker Summoner - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,15000,11,69973,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skybreaker Summoner - In Combat - Cast 'Incinerate'");

-- Kor'kron Necrolyte SAI
SET @ENTRY := 37149;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,2000,6000,11,69969,0,0,0,0,0,5,0,0,0,0,0,0,0,"Kor'kron Necrolyte - In Combat - Cast 'Curse of Doom'"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,6000,10000,11,69972,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Necrolyte - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,15000,11,69973,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Necrolyte - In Combat - Cast 'Incinerate'");

-- Skybreaker Luminary SAI
SET @ENTRY := 37016;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1500,20000,25000,11,69926,0,0,0,0,0,26,40,0,0,0,0,0,0,"Skybreaker Luminary - In Combat - Cast 'Earth Shield'"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,6000,7000,11,69958,0,0,0,0,0,26,40,0,0,0,0,0,0,"Skybreaker Luminary - In Combat - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,6000,7000,11,69923,0,0,0,0,0,26,40,0,0,0,0,0,0,"Skybreaker Luminary - In Combat - Cast 'Chain Heal'"),
(@ENTRY,0,3,0,0,0,100,0,7000,8000,7000,8000,11,69970,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skybreaker Luminary - In Combat - Cast 'Lightning Bolt'");

-- Kor'kron Oracle SAI
SET @ENTRY := 37031;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,1500,20000,25000,11,69926,0,0,0,0,0,26,40,0,0,0,0,0,0,"Kor'kron Oracle - In Combat - Cast 'Earth Shield'"),
(@ENTRY,0,1,0,0,0,100,0,3000,3000,6000,7000,11,69958,0,0,0,0,0,26,40,0,0,0,0,0,0,"Kor'kron Oracle - In Combat - Cast 'Healing Wave'"),
(@ENTRY,0,2,0,0,0,100,0,4000,6000,6000,7000,11,69923,0,0,0,0,0,26,40,0,0,0,0,0,0,"Kor'kron Oracle - In Combat - Cast 'Chain Heal'"),
(@ENTRY,0,3,0,0,0,100,0,7000,8000,7000,8000,11,69970,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Oracle - In Combat - Cast 'Lightning Bolt'");

-- Skybreaker Vindicator SAI
SET @ENTRY := 37003;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,0,12000,12000,16000,20000,11,69927,0,0,0,0,0,2,0,0,0,0,0,0,0,"Skybreaker Vindicator - In Combat - Cast 'Avenger's Shield'"),
(@ENTRY,0,2,0,0,0,100,0,6000,6000,16000,18000,11,69930,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Vindicator - In Combat - Cast 'Consecration'"),
(@ENTRY,0,3,0,0,0,100,0,4000,4000,16000,20000,11,69934,0,0,0,0,0,1,0,0,0,0,0,0,0,"Skybreaker Vindicator - In Combat - Cast 'Holy Wrath'");

-- Kor'kron Vanquisher SAI
SET @ENTRY := 37035;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,1,0,0,0,100,0,12000,12000,16000,20000,11,69927,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kor'kron Vanquisher - In Combat - Cast 'Avenger's Shield'"),
(@ENTRY,0,2,0,0,0,100,0,6000,6000,16000,18000,11,69930,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Vanquisher - In Combat - Cast 'Consecration'"),
(@ENTRY,0,3,0,0,0,100,0,4000,4000,16000,20000,11,69934,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kor'kron Vanquisher - In Combat - Cast 'Holy Wrath'");
