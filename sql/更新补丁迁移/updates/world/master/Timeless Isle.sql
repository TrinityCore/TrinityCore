-- Ancient Spineclaw
SET @ENTRY := 72766;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147557,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Claw Fury');

-- Archiereus of Flame
SET @ENTRY := 73666;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,148003,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Blow'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,12000,19000,11,147998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Storm'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147997,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,148004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Eternal Kiln at 30% HP');

-- Archiereus of Flame
SET @ENTRY := 73174;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,148003,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Blow'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,12000,19000,11,147998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Storm'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147997,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,148004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Eternal Kiln at 30% HP');

-- Ashleaf Sprite
SET @ENTRY := 72877;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147562,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Great Wrath'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147563,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,15000,11,147565,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sun Worship');

-- Blazebound Chanter
SET @ENTRY := 72897;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147562,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Great Wrath'),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147563,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 40% HP'),
(@ENTRY,0,3,0,0,0,100,0,5000,8000,12000,15000,11,147565,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sun Worship');

-- Brilliant Windfeather
SET @ENTRY := 72762;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147310,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gust of Wind'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,147306,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Windfeather at 40% HP');

-- Bufo
SET @ENTRY := 72775;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147655,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gulp Frog Toxin'),
(@ENTRY,0,1,0,2,0,100,0,0,40,15000,15000,11,147654,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Toxic Skin at 40% HP');

-- Burning Berserker
SET @ENTRY := 72895;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,147704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fiery Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147702,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Cleave'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147703,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Fury at 40% HP');

-- Captain Huan <Celestial Guard>
SET @ENTRY := 73347;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,81210,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,12000,15000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick');

-- Celestial Guard
SET @ENTRY := 73343;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,81210,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,12000,15000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick');

-- Champion of the Black Flame
SET @ENTRY := 73171;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,147704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fiery Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147702,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Cleave'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147703,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Fury at 40% HP');

-- Chelon
SET @ENTRY := 72045;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Geyser'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,10000,11,147571,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shell Spin'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147569,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snapping Bite at 40% HP');

-- Cinderfall
SET @ENTRY := 73175;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147878,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Inferno');

-- Cove Shark
SET @ENTRY := 71986;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,126062,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Savage Bite'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,126063,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Scent of Blood at 40% HP');

-- Crag Stalker
SET @ENTRY := 72807;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,147649,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pounce on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147646,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rending Swipe');

-- Cranegnasher
SET @ENTRY := 72049;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,128933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Spawn'),
(@ENTRY,0,1,0,7,0,100,1,0,0,0,0,11,128933,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Evade'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,147400,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bite Morsel'),
(@ENTRY,0,3,0,4,0,100,1,0,0,0,0,11,147394,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pounce on Aggro');

-- Crimsonscale Firestorm
SET @ENTRY := 72876;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147818,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Blossom'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,22000,25000,11,147817,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flame Breath');

-- Cursed Hozen Swabby
SET @ENTRY := 71920;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147529,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Depth Charge'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,147612,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Makeshift Harpoon Gun'),
(@ENTRY,0,2,0,9,0,100,0,0,5,15000,25000,11,147694,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rusty Shank on Close');

-- Damp Shambler
SET @ENTRY := 72771;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,147805,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Murky Cloud on Spawn'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,147769,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renewing Mists at 40% HP');

-- Death Adder
SET @ENTRY := 72841;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147289,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Huge Fang');

-- Elder Great Turtle
SET @ENTRY := 72765;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147573,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Geyser'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,10000,10000,11,147571,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shell Spin'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147569,2,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snapping Bite at 40% HP');

-- Emerald Gander
SET @ENTRY := 73158;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147310,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gust of Wind'),
(@ENTRY,0,1,0,2,0,100,0,0,60,15000,17000,11,147306,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Windfeather at 60% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147309,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Song at 40% HP');

-- Eroded Cliffdwelle
SET @ENTRY := 72809;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,147516,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boulder'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,147510,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Eternal Kilnmaster
SET @ENTRY := 72896;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,148003,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Blow'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,12000,19000,11,147998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Storm'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147997,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,148004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Eternal Kiln at 30% HP');

-- Evermaw <Gnawing Hunger of the Deep>
SET @ENTRY := 73279;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Enrage at 30% HP');

-- Fishgorged Crane
SET @ENTRY := 72095;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147310,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gust of Wind'),
(@ENTRY,0,1,0,2,0,100,0,0,60,15000,17000,11,147306,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Windfeather at 60% HP');

-- Flintlord Gairan
SET @ENTRY := 73172;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,147704,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fiery Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147702,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Cleave'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147703,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Fury at 40% HP');

-- Foreboding Flame
SET @ENTRY := 73162;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147446,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spiritfire Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147448,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Spiritflame Strike');

-- Garnia
SET @ENTRY := 73282;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147896,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Ruby Bolt');

-- Golganarr
SET @ENTRY := 72970;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147500,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stomp'),
(@ENTRY,0,1,0,0,0,100,0,0,0,3500,4100,11,147516,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Boulder'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,147510,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Frenzy at 30% HP');

-- Great Turtle
SET @ENTRY := 72764;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147568,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snapping Bite'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,147571,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shell Spin on Close');

-- Great Turtle Furyshell
SET @ENTRY := 72764;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147568,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snapping Bite'),
(@ENTRY,0,1,0,9,0,100,0,0,5,15000,25000,11,147571,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shell Spin on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,22000,11,147572,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Geyser');

-- Great Turtle Hatchling
SET @ENTRY := 72763;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147568,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snapping Bite');

-- Gu'chi the Swarmbringe
SET @ENTRY := 72909;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147535,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Spit');

-- Gulp Frog
SET @ENTRY := 72777;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147655,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gulp Frog Toxin'),
(@ENTRY,0,1,0,2,0,100,0,0,40,15000,15000,11,147654,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Toxic Skin at 40% HP');

-- High Priest of Ordos
SET @ENTRY := 72898;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,148003,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Blow'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,12000,19000,11,147998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Storm'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147997,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,148004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Eternal Kiln at 30% HP');

-- Huojin Sentry
SET @ENTRY := 73362;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,81210,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,12000,15000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick');

-- Huolon <The Black Wind>
SET @ENTRY := 73167;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147826,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Lightning Breath'),
(@ENTRY,0,1,0,0,0,100,0,0,0,2000,2500,11,147828,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Storm Blossom');

-- Imperial Python
SET @ENTRY := 73163;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147290,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Huge Fang');

-- Ironfur Grazer
SET @ENTRY := 72843;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147382,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Headbutt'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,147368,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Fur at 30% HP');

-- Ironfur Great Bull
SET @ENTRY := 72844;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,147386,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ox Charge on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,147368,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Fur at 30% HP');

-- Ironfur Herdling
SET @ENTRY := 72842;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147382,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Headbutt');

-- Ironfur Steelhorn
SET @ENTRY := 73160;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,147386,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ox Charge on Aggro'),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,11,147368,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Iron Fur at 30% HP');

-- Jademist Dancer
SET @ENTRY := 72767;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147863,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Steam Blast');

-- Jakur of Ordon
SET @ENTRY := 73169;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147674,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cracking Blow'),
(@ENTRY,0,1,0,2,0,100,0,0,60,22000,25000,11,147689,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Defensive Shield at 60% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,147682,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Oath of Guardianship at 30% HP');

-- Karkanos <The Gushing Maw>
SET @ENTRY := 72193;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147843,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Gushing Maw');

-- Leafmender
SET @ENTRY := 73277;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147562,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Great Wrath'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,147563,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Touch at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,147565,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sun Worship');

-- Molten Guardian
SET @ENTRY := 72888;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147878,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Molten Inferno');

-- Monstrous Spineclaw
SET @ENTRY := 73166;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147560,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Claw Flurry');

-- Nice Sprite
SET @ENTRY := 71823;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,114997,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Nature\'s Wrath');

-- Ordon Candlekeeper
SET @ENTRY := 72875;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147416,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Breath of Fire'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,147422,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Burning Sacrifice');

-- Ordon Fire-Watcher
SET @ENTRY := 72894;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147720,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pyroblast'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147723,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Falling Flames');

-- Ordon Oathguard
SET @ENTRY := 72892;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147674,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cracking Blow'),
(@ENTRY,0,1,0,2,0,100,0,0,60,22000,25000,11,147689,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Defensive Shield at 60% HP'),
(@ENTRY,0,2,0,2,0,100,1,0,30,0,0,11,147682,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Oath of Guardianship at 30% HP');

-- Playful Water Spirit
SET @ENTRY := 71883;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32011,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,39207,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Spout');

-- Primal Stalker
SET @ENTRY := 72805;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147652,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Swipe');

-- Rattleskew
SET @ENTRY := 72048;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,43330,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shadow Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,38048,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of Pain'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,20000,20000,11,16555,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Drowning Death');

-- Rattling Mariner
SET @ENTRY := 72033;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,149406,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Curse of the Sea');

-- Rock Moss
SET @ENTRY := 73157;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,147805,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Murky Cloud on Spawn'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,147769,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renewing Mists at 40% HP');

-- Sentry Jienfo
SET @ENTRY := 73386;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,81210,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net');

-- Sentry Laofung
SET @ENTRY := 73385;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,81210,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,12000,15000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick');

-- Skunky Brew Alemental
SET @ENTRY := 71908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147345,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brew Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,148584,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Skunky Suds');

-- Southsea Lookout
SET @ENTRY := 73718;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,141528,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spyglass on Spawn');

-- Spectral Brewmaster
SET @ENTRY := 73018;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,148730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spinning Crane Kick'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,30000,40000,11,146948,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drunken Stupor on Spawn');

-- Spectral Mistweaver
SET @ENTRY := 73025;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,148730,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spinning Crane Kick'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,148728,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Mists at 40% HP');

-- Spectral Pirate
SET @ENTRY := 71987;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,129040,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,20000,22000,11,128049,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Black Fog');

-- Spectral Windwalker
SET @ENTRY := 73021;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,148729,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Chi Burst'),
(@ENTRY,0,1,0,1,0,100,0,500,1000,30000,40000,11,146948,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Drunken Stupor on Spawn');

-- Spelurk
SET @ENTRY := 71864;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,147805,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Murky Cloud on Spawn'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,147769,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Renewing Mists at 40% HP'),
(@ENTRY,0,2,0,0,0,100,0,5000,8000,12000,15000,11,144892,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Breath');

-- Spirit of Jadefire
SET @ENTRY := 72769;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147454,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jadefire Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147456,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Jadeflame Strike');

-- Spotted Swarmer
SET @ENTRY := 72908;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Poison Spit');

-- Stinkbraid <Southsea Captain>
SET @ENTRY := 73704;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,85253,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rotten Stench'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,83622,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Leaping Cleave on Aggro');

-- Timeless Spirit
SET @ENTRY := 71868;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,144059,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Strangle'),
(@ENTRY,0,1,0,4,0,100,1,0,0,0,0,11,144455,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Spirit Winds on Aggro');

-- Tsavo'ka <Ghost in the Darkness>
SET @ENTRY := 72808;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147653,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Greater Swipe');

-- Tushui Sentry
SET @ENTRY := 73361;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,81210,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,12000,15000,11,15618,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Snap Kick');

-- Urdur the Cauterizer
SET @ENTRY := 73173;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,148003,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Blazing Blow'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,12000,19000,11,147998,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fire Storm'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147997,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Cauterize at 40% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,148004,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Conjure Eternal Kiln at 30% HP');

-- Watcher Osu
SET @ENTRY := 73170;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147720,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Pyroblast'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147723,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Falling Flames');

-- Windfeather Chick
SET @ENTRY := 71143;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147310,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gust of Wind'),
(@ENTRY,0,1,0,2,0,100,0,0,60,15000,17000,11,147306,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Windfeather at 60% HP');

-- Windfeather Nestkeeper
SET @ENTRY := 72761;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147310,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Gust of Wind'),
(@ENTRY,0,1,0,2,0,100,0,0,60,15000,17000,11,147306,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Windfeather at 60% HP'),
(@ENTRY,0,2,0,2,0,100,0,0,40,22000,25000,11,147309,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Song at 40% HP');

-- Zesqua
SET @ENTRY := 72245;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,147335,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Furious Splash'),
(@ENTRY,0,1,0,0,0,100,0,10000,10000,12000,20000,11,147439,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Blossom'),
(@ENTRY,0,2,0,9,0,100,0,0,55,15000,25000,11,147344,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Water Bolt Volley on Close');

-- Zhu-Gon the Sour
SET @ENTRY := 71919;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,147345,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Brew Bolt'),
(@ENTRY,0,1,0,0,0,100,0,5000,8000,12000,15000,11,147347,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Rain of Skunky Ale'),
(@ENTRY,0,2,0,0,0,100,0,10000,10000,10000,20000,11,144882,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Skunky Ale Crash');
