-- 
-- DB/SAI: Update Mount Hyjal
-- Azralon the Gatekeeper SAI
SET @ENTRY := 40814;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4800,7900,12300,14900,11,80606,0,0,0,0,0,2,0,0,0,0,0,0,0,"Azralon the Gatekeeper - In Combat - Cast 'Evil Cleave'");
-- Ashbearer SAI
SET @ENTRY := 46925;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5100,5200,11300,12500,11,80561,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashbearer - In Combat - Cast 'Flame Edge'"),
(@ENTRY,0,1,0,0,0,100,0,9900,9900,23400,26800,11,80594,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ashbearer - In Combat - Cast 'Flame Thrower'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,17800,19200,11,18543,0,0,0,0,0,5,0,0,0,0,0,0,0,"Ashbearer - In Combat - Cast 'Flame Lash'");
-- Blazebound Elemental SAI
SET @ENTRY := 38896;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12500,15300,11,80031,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blazebound Elemental - In Combat - Cast 'Flaming Slice'");
-- Baron Geddon SAI
SET @ENTRY := 40147;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15800,18300,11,74813,0,0,0,0,0,1,0,0,0,0,0,0,0,"Baron Geddon - Within 0-8 Range - Cast 'Inferno'");
-- Charbringer SAI
SET @ENTRY := 40336;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5100,5200,11300,12500,11,80561,0,0,0,0,0,2,0,0,0,0,0,0,0,"Charbringer - In Combat - Cast 'Flame Edge'"),
(@ENTRY,0,1,0,0,0,100,0,9900,9900,23400,26800,11,80594,0,0,0,0,0,2,0,0,0,0,0,0,0,"Charbringer - In Combat - Cast 'Flame Thrower'"),
(@ENTRY,0,2,0,0,0,100,0,3000,4000,17800,19200,11,18543,0,0,0,0,0,5,0,0,0,0,0,0,0,"Charbringer - In Combat - Cast 'Flame Lash'");
-- Blaithe SAI
SET @ENTRY := 41084;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,120000,120000,11,32022,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blaithe - In Combat - Cast 'Gut Rip'"),
(@ENTRY,0,1,0,0,0,100,0,11000,11000,17800,18200,11,49865,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blaithe - In Combat - Cast 'Eye Peck'"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,14400,26700,11,78678,0,0,0,0,0,1,0,0,0,0,0,0,0,"Blaithe - In Combat - Cast 'Thunderstomp'");
-- Anren Shadowseeker SAI
SET @ENTRY := 39925;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Anren Shadowseeker - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,12300,15600,11,22127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Anren Shadowseeker - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,0,0,100,0,3000,7000,19700,21300,11,23380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Anren Shadowseeker - In Combat - Cast 'Moonfire'");
-- Blazewing SAI
SET @ENTRY := 50057;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,93515,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blazewing - On Aggro - Cast 'Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,4400,5500,22400,31500,11,93514,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blazewing - In Combat - Cast 'Melt Armor'"),
(@ENTRY,0,2,0,0,0,100,0,7700,9100,12300,13100,11,93513,0,0,0,0,0,2,0,0,0,0,0,0,0,"Blazewing - In Combat - Cast 'Flame Buffet'");
-- Cindermaul SAI
SET @ENTRY := 40844;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,15500,17800,11,76312,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cindermaul - In Combat - Cast 'Earthsmash'"),
(@ENTRY,0,1,0,0,0,100,0,3000,3500,22499,26700,11,76295,0,0,0,0,0,1,0,0,0,0,0,0,0,"Cindermaul - In Combat - Cast 'Wall of Stone'");
-- Deep Corruptor SAI
SET @ENTRY := 40561;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,15000,20000,11,51733,0,0,0,0,0,1,0,0,0,0,0,0,0,"Deep Corruptor - Out of Combat - Cast 'Shadow Channelling'");
-- Furious Hyjal Warden SAI
SET @ENTRY := 43427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Furious Hyjal Warden - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,16000,19000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furious Hyjal Warden - In Combat - Cast 'Incapacitating Shout'"),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,11000,12000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Furious Hyjal Warden - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,3,0,13,0,100,0,12000,16000,0,0,11,15618,0,0,0,0,0,6,1,0,0,0,0,0,0,"Furious Hyjal Warden - On Victim Casting - Cast 'Snap Kick'");
-- Flame Ascendant SAI
SET @ENTRY := 40709;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15800,18300,11,87481,0,0,0,0,0,1,0,0,0,0,0,0,0,"Flame Ascendant - Within 0-8 Range - Cast 'Hellfire'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,15700,18900,11,87487,0,0,0,0,0,2,0,0,0,0,0,0,0,"Flame Ascendant - In Combat - Cast 'Flame Blast'");
-- Firesworn SAI
SET @ENTRY := 50055;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7000,8000,16800,18100,11,93512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Firesworn - In Combat - Cast 'Eruption'");
-- Defender of Malorne SAI
SET @ENTRY := 40333;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,9000,11000,12000,11,12024,0,0,0,0,0,2,0,0,0,0,0,0,0,"Defender of Malorne - In Combat - Cast 'Net'");
-- Dark Iron Laborer SAI
SET @ENTRY := 40838;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4000,10500,16200,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dark Iron Laborer - In Combat - Cast 'Sunder Armor'");
-- Emissary of Flame SAI
SET @ENTRY := 40755;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7700,8900,28900,34100,11,52626,0,0,0,0,0,2,0,0,0,0,0,0,0,"Emissary of Flame - In Combat - Cast 'Melt Armor'");
-- Druid of the Talon SAI
SET @ENTRY := 41008;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,1,0,50,0,500,1000,600000,600000,11,77042,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Talon - Out of Combat - Cast 'Storm Crow Form'"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,17800,19200,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Faerie Fire'"),
(@ENTRY,0,3,0,0,0,100,0,9900,9900,11200,21300,11,77345,0,0,0,0,0,5,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Stormcall'"),
(@ENTRY,0,4,0,2,0,100,1,0,45,0,0,11,77066,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Talon - Between 0-45% Health - Cast 'Healing Touch' (No Repeat)");
-- Druid of the Talon SAI
SET @ENTRY := 50083;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,1,0,50,0,500,1000,600000,600000,11,77042,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Talon - Out of Combat - Cast 'Storm Crow Form'"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,17800,19200,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Faerie Fire'"),
(@ENTRY,0,3,0,0,0,100,0,9900,9900,11200,21300,11,77345,0,0,0,0,0,5,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Stormcall'"),
(@ENTRY,0,4,0,2,0,100,1,0,45,0,0,11,77066,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Talon - Between 0-45% Health - Cast 'Healing Touch' (No Repeat)");
-- Druid of the Talon SAI
SET @ENTRY := 41287;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,1,0,50,0,500,1000,600000,600000,11,77042,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Talon - Out of Combat - Cast 'Storm Crow Form'"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,17800,19200,11,6950,0,0,0,0,0,2,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Faerie Fire'"),
(@ENTRY,0,3,0,0,0,100,0,9900,9900,11200,21300,11,77345,0,0,0,0,0,5,0,0,0,0,0,0,0,"Druid of the Talon - In Combat - Cast 'Stormcall'"),
(@ENTRY,0,4,0,2,0,100,1,0,45,0,0,11,77066,0,0,0,0,0,1,0,0,0,0,0,0,0,"Druid of the Talon - Between 0-45% Health - Cast 'Healing Touch' (No Repeat)");
-- Arch Druid of Hyjal SAI
SET @ENTRY := 40150;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,71467,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arch Druid of Hyjal - Out of Combat - Cast 'Nature Channeling'");
-- Fiery Tormentor SAI
SET @ENTRY := 41396;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77508,64,0,0,0,0,2,0,0,0,0,0,0,0,"Fiery Tormentor - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,16000,18000,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fiery Tormentor - In Combat - Cast 'Flame Shock'");
-- Hyjal Warden SAI
SET @ENTRY := 38915;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,11000,14000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hyjal Warden - In Combat - Cast 'Mortal Strike'");
-- Hyjal Roc SAI
SET @ENTRY := 42658;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4400,10700,11300,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hyjal Roc - In Combat - Cast 'Swoop'");
-- Hyjal Owl SAI
SET @ENTRY := 42663;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4400,10700,11300,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hyjal Owl - In Combat - Cast 'Swoop'");
-- Hyjal Darkhawk SAI
SET @ENTRY := 42660;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4400,10700,11300,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hyjal Darkhawk - In Combat - Cast 'Swoop'");
-- Hovel Brute SAI
SET @ENTRY := 39642;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80512,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hovel Brute - On Aggro - Cast 'Fling Filth' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,8100,8700,13700,14600,11,80513,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hovel Brute - In Combat - Cast 'Mash'");
-- Hovel Shadowcaster SAI
SET @ENTRY := 39643;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Hovel Shadowcaster - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Hovel Shadowcaster - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,7000,8000,39000,52000,11,16231,0,0,0,0,0,5,0,0,0,0,0,0,0,"Hovel Shadowcaster - In Combat - Cast 'Curse of Recklessness'");
-- Hyjal Screecher SAI
SET @ENTRY := 42659;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4400,10700,11300,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hyjal Screecher - In Combat - Cast 'Swoop'");
-- King Moltron SAI
SET @ENTRY := 40998;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16000,18000,11,80600,0,0,0,0,0,1,0,0,0,0,0,0,0,"King Moltron - In Combat - Cast 'Flame Stomp'");
-- Lycanthoth SAI
SET @ENTRY := 39446;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,18000,21000,11,37776,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lycanthoth - In Combat - Cast 'Blood Howl'");
-- Goldrinn Defender SAI
SET @ENTRY := 39637;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Goldrinn Defender - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goldrinn Defender - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,7000,8600,10300,11200,11,12024,2,0,0,0,0,2,0,0,0,0,0,0,0,"Goldrinn Defender - In Combat - Cast 'Net'");
-- Horrorguard SAI
SET @ENTRY := 48725;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,16700,19200,11,37488,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horrorguard - In Combat - Cast 'Fel Flames'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,24000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrorguard - In Combat - Cast 'War Stomp'");
-- Howling Riftdweller SAI
SET @ENTRY := 39844;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3300,3700,12000,13400,11,32018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Howling Riftdweller - In Combat - Cast 'Call Lightning'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,16000,18000,11,80066,0,0,0,0,0,2,0,0,0,0,0,0,0,"Howling Riftdweller - In Combat - Cast 'Tornado'");
-- Horrorguard SAI
SET @ENTRY := 39724;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,9000,9000,16700,19200,11,37488,0,0,0,0,0,2,0,0,0,0,0,0,0,"Horrorguard - In Combat - Cast 'Fel Flames'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,24000,11,45,0,0,0,0,0,1,0,0,0,0,0,0,0,"Horrorguard - In Combat - Cast 'War Stomp'");
-- Grove Tender SAI
SET @ENTRY := 39931;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3300,4000,11000,12000,11,15798,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grove Tender - In Combat - Cast 'Moonfire'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,22000,27000,11,79823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grove Tender - In Combat - Cast 'Starfall'"),
(@ENTRY,0,2,0,0,0,80,0,5000,5500,13000,19000,11,78907,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grove Tender - In Combat - Cast 'Starfire'"),
(@ENTRY,0,3,0,0,0,100,1,2000,7000,33000,34000,11,79825,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grove Tender - In Combat - Cast 'Summon Unstable Mushroom' (No Repeat)");
-- Hyjal Huntress SAI
SET @ENTRY := 42664;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4400,10700,11300,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hyjal Huntress - In Combat - Cast 'Swoop'");
-- Hyjal Eagle SAI
SET @ENTRY := 42657;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,4400,10700,11300,11,55079,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hyjal Eagle - In Combat - Cast 'Swoop'");
-- Lava Surger SAI
SET @ENTRY := 46911;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,19196,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lava Surger - On Aggro - Cast 'Surge' (No Repeat)");
-- Garr SAI
SET @ENTRY := 50056;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,3000,17000,18000,11,93506,0,0,0,0,0,1,0,0,0,0,0,0,0,"Garr - In Combat - Cast 'Antimagic Pulse'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,13600,14500,11,93507,0,0,0,0,0,1,0,0,0,0,0,0,0,"Garr - Within 0-8 Range - Cast 'Magma Shackles'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,25000,26000,11,93508,0,0,0,0,0,1,0,0,0,0,0,0,0,"Garr - Within 0-8 Range - Cast 'Massive Eruption'");
-- Leyden Copperkleist SAI
SET @ENTRY := 39846;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,57780,64,0,0,0,0,2,0,0,0,0,0,0,0,"Leyden Copperkleist - In Combat - Cast 'Lightning Bolt'"),
(@ENTRY,0,1,0,0,1,100,0,4000,5000,12000,13000,11,12548,0,0,0,0,0,2,0,0,0,0,0,0,0,"Leyden Copperkleist - In Combat - Cast 'Frost Shock' (Phase 1)");
-- Lycanthoth Vandal SAI
SET @ENTRY := 39445;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,80515,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lycanthoth Vandal - On Aggro - Cast 'Undying Frenzy' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,14000,17000,11,80514,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lycanthoth Vandal - In Combat - Cast 'Undying Frenzy'");
-- Magma Giant SAI
SET @ENTRY := 40464;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8000,16000,18000,11,80600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magma Giant - In Combat - Cast 'Flame Stomp'");
-- Molten Tormentor SAI
SET @ENTRY := 41565;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,14000,18000,11,83018,0,0,0,0,0,2,0,0,0,0,0,0,0,"Molten Tormentor - In Combat - Cast 'Magma Wave'");
-- Garnoth, Fist of the Legion SAI
SET @ENTRY := 39726;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,7700,8100,13600,16800,11,35895,0,0,0,0,0,2,0,0,0,0,0,0,0,"Garnoth, Fist of the Legion - In Combat - Cast 'Fel Flamestrike'");
-- Gar'gol SAI
SET @ENTRY := 39646;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gar'gol - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Gar'gol - Between 0-30% Health - Say Line 0 (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3500,4500,11200,15900,11,80513,0,0,0,0,0,2,0,0,0,0,0,0,0,"Gar'gol - In Combat - Cast 'Mash'");
-- NPC talk text insert
SET @ENTRY := 39646;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Galrond of the Claw SAI
SET @ENTRY := 40148;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,4900,5100,11000,12000,11,74811,0,0,0,0,0,2,0,0,0,0,0,0,0,"Galrond of the Claw - In Combat - Cast 'Swipe'");
-- Nemesis SAI
SET @ENTRY := 41614;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15800,18300,11,77777,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nemesis - Within 0-8 Range - Cast 'Molten Fury'");
-- Furious Hyjal Warden SAI
SET @ENTRY := 43427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,23337,64,0,0,0,0,2,0,0,0,0,0,0,0,"Furious Hyjal Warden - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,16000,19000,11,18328,0,0,0,0,0,1,0,0,0,0,0,0,0,"Furious Hyjal Warden - In Combat - Cast 'Incapacitating Shout'"),
(@ENTRY,0,2,0,0,0,100,0,3000,3000,11000,12000,11,19643,0,0,0,0,0,2,0,0,0,0,0,0,0,"Furious Hyjal Warden - In Combat - Cast 'Mortal Strike'"),
(@ENTRY,0,3,0,13,0,100,0,12000,16000,0,0,11,15618,0,0,0,0,0,6,1,0,0,0,0,0,0,"Furious Hyjal Warden - On Victim Casting - Cast 'Snap Kick'");
-- Raging Firestorm SAI
SET @ENTRY := 39939;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,16000,21000,11,80549,0,0,0,0,0,2,0,0,0,0,0,0,0,"Raging Firestorm - In Combat - Cast 'Gout of Flame'");
-- Nordrassil Druid SAI
SET @ENTRY := 40956;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nordrassil Druid - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,18000,22000,11,22127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nordrassil Druid - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,0,0,100,0,11000,13000,15000,35000,11,23380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nordrassil Druid - In Combat - Cast 'Moonfire'");
-- Nordrassil Druid SAI
SET @ENTRY := 38952;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Nordrassil Druid - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,18000,22000,11,22127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Nordrassil Druid - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,0,0,100,0,11000,13000,15000,35000,11,23380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nordrassil Druid - In Combat - Cast 'Moonfire'");
-- Spinescale Matriarch SAI
SET @ENTRY := 40403;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,16000,18000,11,32905,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spinescale Matriarch - In Combat - Cast 'Glare'");
-- Smolderos the Carbonizer SAI
SET @ENTRY := 39348;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3300,4300,11300,12500,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Smolderos the Carbonizer - In Combat - Cast 'Rend'");
-- Tiala Whitemane SAI
SET @ENTRY := 40833;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tiala Whitemane - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,18000,22000,11,22127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tiala Whitemane - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,0,0,100,0,11000,13000,15000,35000,11,23380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tiala Whitemane - In Combat - Cast 'Moonfire'");
-- Terrorpene SAI
SET @ENTRY := 50058;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3500,3500,11300,12600,11,93521,0,0,0,0,0,2,0,0,0,0,0,0,0,"Terrorpene - In Combat - Cast 'Burning Hatred'");
-- Thol'embaar SAI
SET @ENTRY := 40107;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,8,15800,18300,11,80600,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thol'embaar - Within 0-8 Range - Cast 'Flame Stomp'"),
(@ENTRY,0,1,0,9,0,100,0,0,8,10000,30000,11,74788,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thol'embaar - Within 0-8 Range - Cast 'Ring of Fire'");
-- Twilight Guard SAI
SET @ENTRY := 39828;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Guard - On Aggro - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 39828;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, 'Stop right there!',12,0,50,0,0,0, 'combat Say',19524);
-- Spawn of Smolderos SAI
SET @ENTRY := 40427;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,16000,18000,11,74143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Spawn of Smolderos - In Combat - Cast 'Little Big Flame Breath'");
-- Shadowflame Master SAI
SET @ENTRY := 41563;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32707,64,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowflame Master - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,14000,17000,11,87420,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowflame Master - In Combat - Cast 'Shadowflame Blast'");
-- Twilight Augur SAI
SET @ENTRY := 40713;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,67,0,100,0,9000,11000,0,0,11,80607,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Augur - On Behind Target - Cast 'Flamestep'");
-- Sethria's Hatchling SAI
SET @ENTRY := 41226;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,6000,12000,15000,11,78143,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sethria's Hatchling - In Combat - Cast 'Twilight Breath'");
-- Sebelia SAI
SET @ENTRY := 40843;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Sebelia - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,18000,22000,11,22127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Sebelia - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,0,0,100,0,11000,13000,15000,35000,11,23380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Sebelia - In Combat - Cast 'Moonfire'");
-- Thartuk the Exile SAI
SET @ENTRY := 50053;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thartuk the Exile - Between 0-30% Health - Cast 'Enrage' (No Repeat)"),
(@ENTRY,0,1,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Thartuk the Exile - Between 0-30% Health - Say Line 0 (No Repeat)");
-- NPC talk text insert
SET @ENTRY := 50053;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`,`BroadcastTextId`) VALUES
(@ENTRY,0,0, '%s becomes enraged!',16,0,100,0,0,0, 'combat Enrage',10677);
-- Scalding Rock Elemental SAI
SET @ENTRY := 40229;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,14000,11,80638,0,0,0,0,0,2,0,0,0,0,0,0,0,"Scalding Rock Elemental - In Combat - Cast 'Searing Touch'");
-- Tholo Whitehoof SAI
SET @ENTRY := 40278;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Tholo Whitehoof - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,18000,22000,11,22127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Tholo Whitehoof - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,0,0,100,0,11000,13000,15000,35000,11,23380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tholo Whitehoof - In Combat - Cast 'Moonfire'");
-- Twilight Infiltrator SAI
SET @ENTRY := 40882;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Infiltrator - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Infiltrator - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,11000,12000,11,20794,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Infiltrator - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,21000,22000,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Infiltrator - In Combat - Cast 'Rain of Fire'");
-- Wormwing Screecher SAI
SET @ENTRY := 41027;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,77160,64,0,0,0,0,2,0,0,0,0,0,0,0,"Wormwing Screecher - In Combat - Cast 'Nimbus Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wormwing Screecher - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,9000,9000,35000,36000,11,76963,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wormwing Screecher - In Combat - Cast 'Wild Tornado'");
-- Wormwing Swifttalon SAI
SET @ENTRY := 41028;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,19514,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wormwing Swifttalon - Out of Combat - Cast 'Lightning Shield'");
-- Windspeaker Tamila SAI
SET @ENTRY := 39869;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9739,64,0,0,0,0,2,0,0,0,0,0,0,0,"Windspeaker Tamila - In Combat - Cast 'Wrath'"),
(@ENTRY,0,1,0,0,0,100,0,5000,6000,18000,22000,11,22127,0,0,0,0,0,5,0,0,0,0,0,0,0,"Windspeaker Tamila - In Combat - Cast 'Entangling Roots'"),
(@ENTRY,0,2,0,0,0,100,0,11000,13000,15000,35000,11,23380,0,0,0,0,0,2,0,0,0,0,0,0,0,"Windspeaker Tamila - In Combat - Cast 'Moonfire'");
-- Twilight Inferno Lord SAI
SET @ENTRY := 39974;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32707,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Inferno Lord - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Inferno Lord - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,17000,17000,11,11962,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Inferno Lord - In Combat - Cast 'Immolate'"),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,11000,13000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Inferno Lord - In Combat - Cast 'Fire Blast'");
-- Twilight Initiate SAI
SET @ENTRY := 40562;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,91997,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Initiate - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,16000,17000,11,32063,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Corruption'"),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,11000,13000,11,91998,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Throw Rock'");
-- Twilight Inciter SAI
SET @ENTRY := 39926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,3000,5000,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Inciter - Out of Combat - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Inciter - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,2,0,67,0,100,0,8000,9000,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Inciter - On Behind Target - Cast 'Shadowstep'");
-- Twilight Hunter SAI
SET @ENTRY := 39437;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2300,3900,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Hunter - In Combat - Cast 'Shoot'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Hunter - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,8000,8000,12000,19000,11,80012,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Hunter - In Combat - Cast 'Chimera Shot'"),
(@ENTRY,0,3,0,0,0,100,0,5000,5000,22000,24000,11,80009,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Hunter - In Combat - Cast 'Serpent Sting'"),
(@ENTRY,0,4,0,9,0,100,0,0,8,15800,18300,11,22910,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Hunter - Within 0-8 Range - Cast 'Immolation Trap'");
-- Twilight Enforcer SAI
SET @ENTRY := 39749;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8900,17000,21000,11,37577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Enforcer - In Combat - Cast 'Debilitating Strike'"),
(@ENTRY,0,1,0,0,0,100,0,3700,4800,12000,12500,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Enforcer - In Combat - Cast 'Sunder Armor'");
-- Twilight Enforcer SAI
SET @ENTRY := 40563;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,8000,8900,17000,21000,11,37577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Enforcer - In Combat - Cast 'Debilitating Strike'"),
(@ENTRY,0,1,0,0,0,100,0,3700,4800,12000,12500,11,11971,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Enforcer - In Combat - Cast 'Sunder Armor'");
-- Twilight Dragonkin Armorer SAI
SET @ENTRY := 41030;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,78129,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Dragonkin Armorer - In Combat - Cast 'Twilight Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,9000,9000,19000,22000,11,78128,0,0,0,0,0,2,1,0,0,0,0,0,0,"Twilight Dragonkin Armorer - In Combat - Cast 'Fuse Armor'");
-- Twilight Field Captain SAI
SET @ENTRY := 41502;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,80058,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Field Captain - In Combat - Cast 'Twilight Burst'"),
(@ENTRY,0,1,0,0,0,100,0,8000,8000,120000,120000,11,80983,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Field Captain - In Combat - Cast 'Commanding Shout'");
-- Twilight Initiate SAI
SET @ENTRY := 40185;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Initiate - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,16000,17000,11,32063,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Corruption'"),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,20000,30000,11,22678,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Fear'");
-- Twilight Juggernaut SAI
SET @ENTRY := 41031;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,600000,600000,11,77224,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Juggernaut - Out of Combat - Cast 'Armor Plating'");
-- Twilight Initiate SAI
SET @ENTRY := 40185;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Initiate - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,16000,17000,11,32063,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Corruption'"),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,20000,30000,11,22678,0,0,0,0,0,5,0,0,0,0,0,0,0,"Twilight Initiate - In Combat - Cast 'Fear'");
-- Twilight Proveditor SAI
SET @ENTRY := 39436;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5000,12000,14000,11,80182,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Proveditor - In Combat - Cast 'Uppercut'");
-- Twilight Flamecaller SAI
SET @ENTRY := 38926;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,15536,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Flamecaller - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Flamecaller - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,3000,6000,11000,12000,11,20794,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Flamecaller - In Combat - Cast 'Flamestrike'"),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,21000,22000,11,11990,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Flamecaller - In Combat - Cast 'Rain of Fire'");
-- Twilight Dragonkin SAI
SET @ENTRY := 41029;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,78114,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Dragonkin - On Aggro - Cast 'Twilight Charge' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,13000,16000,11,78121,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Dragonkin - In Combat - Cast 'Twilight Blast'");
-- Twilight Assassin SAI
SET @ENTRY := 38951;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,3000,5000,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Assassin - Out of Combat - Cast 'Stealth' (No Repeat)"),
(@ENTRY,0,1,0,67,0,100,0,3900,6900,0,0,11,37685,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Assassin - On Behind Target - Cast 'Backstab'"),
(@ENTRY,0,2,0,67,0,100,0,8000,9000,0,0,11,80576,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Assassin - On Behind Target - Cast 'Shadowstep'");
-- The Manipulator SAI
SET @ENTRY := 39756;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,32707,64,0,0,0,0,2,0,0,0,0,0,0,0,"The Manipulator - In Combat - Cast 'Incinerate'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"The Manipulator - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,4000,7000,17000,17000,11,11962,0,0,0,0,0,5,0,0,0,0,0,0,0,"The Manipulator - In Combat - Cast 'Immolate'"),
(@ENTRY,0,3,0,0,0,100,0,9000,9000,11000,13000,11,13339,0,0,0,0,0,2,0,0,0,0,0,0,0,"The Manipulator - In Combat - Cast 'Fire Blast'");
-- Twilight Retainer SAI
SET @ENTRY := 40767;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75025,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Retainer - On Aggro - Cast 'Rush of Flame' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,12000,13000,11,80561,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Retainer - In Combat - Cast 'Flame Edge'");
-- Twilight Scorchlord SAI
SET @ENTRY := 41500;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,9053,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Scorchlord - In Combat - Cast 'Fireball'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Scorchlord - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,5000,5000,55000,55000,11,77627,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Scorchlord - In Combat - Cast 'Summon Fiery Minion'");
-- Twilight Stormcaller SAI
SET @ENTRY := 39843;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,80058,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Stormcaller - In Combat - Cast 'Twilight Burst'"),
(@ENTRY,0,1,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Stormcaller - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,2,0,9,0,100,0,0,8,15800,16900,11,80068,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Stormcaller - Within 0-8 Range - Cast 'Thunderstorm'");
-- Twilight Stormwaker SAI
SET @ENTRY := 40573;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,3400,4700,11,65060,64,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Stormwaker - In Combat - Cast 'Twilight Bolt'");
-- Twilight Vanquisher SAI
SET @ENTRY := 38913;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,6000,8000,14000,18000,11,79881,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Vanquisher - In Combat - Cast 'Slam'");
-- Unbound Fire Elemental SAI
SET @ENTRY := 46991;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,75025,0,0,0,0,0,1,0,0,0,0,0,0,0,"Unbound Fire Elemental - On Aggro - Cast 'Rush of Flame' (No Repeat)"),
(@ENTRY,0,1,0,0,0,100,0,5000,5000,15000,17900,11,13729,0,0,0,0,0,2,0,0,0,0,0,0,0,"Unbound Fire Elemental - In Combat - Cast 'Flame Shock'");
-- Vengeance of the Ancient SAI
SET @ENTRY := 40857;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3300,4500,11200,13700,11,76218,0,0,0,0,0,2,0,0,0,0,0,0,0,"Vengeance of the Ancient - In Combat - Cast 'Ghostly Claw'");
-- Wailing Weed SAI
SET @ENTRY := 40066;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Weed - On Aggro - Set Event Phase 1 (No Repeat)"),
(@ENTRY,0,1,0,4,1,100,1,0,0,0,0,11,48195,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Weed - On Aggro - Cast 'Emerald Lasher Emerge' (Phase 1) (No Repeat)"),
(@ENTRY,0,2,0,4,1,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Weed - On Aggro - Remove Flag Standstate Submerged (Phase 1) (No Repeat)"),
(@ENTRY,0,3,0,0,1,100,0,4000,7000,15000,19000,11,74737,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Weed - In Combat - Cast 'Leafy Wail' (Phase 1)"),
(@ENTRY,0,4,0,7,1,100,1,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Weed - On Evade - Set Event Phase 2 (Phase 1) (No Repeat)"),
(@ENTRY,0,5,0,7,2,100,1,0,0,0,0,91,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Weed - On Evade - Remove Flag Standstate Submerged (Phase 2) (No Repeat)"),
(@ENTRY,0,6,0,21,2,100,1,0,0,0,0,90,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wailing Weed - On Reached Home - Set Flag Standstate Submerged (Phase 2) (No Repeat)"),
(@ENTRY,0,7,0,0,1,100,0,3300,4500,11300,14500,11,80546,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wailing Weed - In Combat - Cast 'Bile Blast' (Phase 1)");
-- Twilight Subjugator SAI
SET @ENTRY := 40463;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,5500,12000,12500,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Subjugator - In Combat - Cast 'Cleave'"),
(@ENTRY,0,1,0,0,0,100,0,8000,9000,15800,17900,11,57846,0,0,0,0,0,2,0,0,0,0,0,0,0,"Twilight Subjugator - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,2,0,9,0,100,0,0,8,15800,18300,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Subjugator - Within 0-8 Range - Cast 'Demoralizing Shout'");
-- Twilight Cultist SAI
SET @ENTRY := 40536;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,500,1000,45000,55000,11,74919,0,0,0,0,0,1,0,0,0,0,0,0,0,"Twilight Cultist - Out of Combat - Cast 'Shadow Channeling'");
