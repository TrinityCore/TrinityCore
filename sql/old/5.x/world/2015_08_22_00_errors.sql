-- Defias Shadowguard
SET @ENTRY := 48505;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,2,0,50,15000,18000,11,90958,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 50% HP'),
(@ENTRY,0,1,0,0,0,100,2,8000,8000,14000,15000,11,90956,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadowstep'),
(@ENTRY,0,2,0,0,0,100,2,2000,3000,9000,11000,11,90951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,3,0,0,0,100,2,12000,14000,24000,28000,11,90960,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirling Blades'),
(@ENTRY,0,4,0,11,0,100,3,0,0,0,0,11,90954,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Camouflage on Spawn');
-- Defias Enforcer
SET @ENTRY := 48502;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,90928,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,17000,19000,11,90929,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Recklessness'),
(@ENTRY,0,2,0,2,0,100,6,0,40,8000,11000,11,90925,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbath at 40% HP');
-- Ol' Beaky
SET @ENTRY := 48451;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4900,9000,12000,11,90913,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eye Gouge'),
(@ENTRY,0,1,0,0,0,100,6,7000,9000,16000,19000,11,90920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eye Peck');
-- Defias Enforcer
SET @ENTRY := 49850;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,7,0,0,0,0,11,90928,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,1,0,2,0,100,6,0,40,8000,11000,11,90925,1,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloodbath at 40% HP');
-- Defias Shadowguard
SET @ENTRY := 49852;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,6,0,50,15000,18000,11,90958,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Evasion at 50% HP'),
(@ENTRY,0,1,0,0,0,100,6,8000,8000,14000,15000,11,90956,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Shadowstep'),
(@ENTRY,0,2,0,0,0,100,6,2000,3000,9000,11000,11,90951,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Sinister Strike'),
(@ENTRY,0,3,0,0,0,100,6,12000,14000,24000,28000,11,90960,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Whirling Blades');
-- Sunwing Squawker
SET @ENTRY := 48450;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,4000,4900,9000,12000,11,90913,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eye Gouge'),
(@ENTRY,0,1,0,0,0,100,6,7000,9000,16000,19000,11,90920,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Eye Peck');
-- Defias Blood Wizard
SET @ENTRY := 49854;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,90938,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,2,2,0,100,7,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,2,0,61,0,100,7,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,3,0,16,0,100,6,90947,30,12000,14000,11,90946,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Bloodwash on Friendlies'),
(@ENTRY,0,4,0,0,0,100,6,5000,5000,35000,35000,11,90932,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Ragezone');
-- NPC talk text insert
SET @ENTRY := 49854;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');
-- Bound Rumbler
SET @ENTRY := 49826;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,10,11300,12600,38900,41200,11,93327,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Entomb'),
(@ENTRY,0,1,0,0,0,100,10,5500,5500,15600,17900,11,93325,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave');
