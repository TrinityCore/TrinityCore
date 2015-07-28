-- Ancestral Guardian SAI
SET @ENTRY := 48518;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,13500,14200,11,86085,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ancestral Guardian - Combat - Cast Mutilate");

-- Dark Ritualist Zakahn SAI
SET @ENTRY := 49148;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,12400,13500,11,9081,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - Range 0 to 8 - Cast Shadow Bolt Volley"),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,91614,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - Aggro - Cast Zakahn's Serpents"),
(@ENTRY,0,2,0,1,0,100,1,1000,1000,1000,1000,11,68797,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dark Ritualist Zakahn - OOC - Cast Aura (No Repeat)");

-- Akma'hat SAI
SET @ENTRY := 50063;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,22000,22000,11,94946,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - Combat - Cast 'Fury of the Sands'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,19500,27300,11,93578,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - Combat - Cast 'Sands of Time'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,15800,18300,11,94968,0,0,0,0,0,2,0,0,0,0,0,0,0,"Akma'hat - Range 0 to 8 - Cast 'Shockwave'"),
(@ENTRY,0,3,0,2,0,100,1,0,40,0,0,11,93561,0,0,0,0,0,1,0,0,0,0,0,0,0,"Akma'hat - @40%HP - Cast 'Stone Mantle'");

-- Armagedillo SAI
SET @ENTRY := 50065;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,500,1000,5000,15000,11,93598,1,0,0,0,0,5,0,0,0,0,0,0,0,"Armagedillo - Combat - Cast 'Spiked Charge'"),
(@ENTRY,0,1,0,0,0,100,0,8000,12000,9000,15000,11,93592,1,0,0,0,0,2,0,0,0,0,0,0,0,"Armagedillo - Combat - Cast 'Dillogeddon'"),
(@ENTRY,0,2,0,0,0,100,0,6000,8000,6000,10000,11,93590,1,0,0,0,0,2,0,0,0,0,0,0,0,"Armagedillo - Combat - Cast 'Flame Breath'");

-- Oasis Crocolisk SAI
SET @ENTRY := 51675;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,4000,12900,14700,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Oasis Crocolisk - Combat - Cast 'Powerful Bite'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,87228,0,0,0,0,0,1,0,0,0,0,0,0,0,"Oasis Crocolisk - @30%HP - Cast 'Thick Hide'");

-- Ferndweller Wasp SAI
SET @ENTRY := 51712;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,34392,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferndweller Wasp - @30%HP - Cast 'Stinger Rage'"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ferndweller Wasp - @30%HP - Say Text 0");

-- Longstrider Gazelle SAI
SET @ENTRY := 51713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,13000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Longstrider Gazelle - Combat - Cast Gore");
