-- Rotgrip
SET @ENTRY := 13596;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,11000,15000,11,16495,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fatal Bite on Close'),
(@ENTRY,0,1,0,0,0,100,2,5000,8000,13000,18000,11,15976,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Puncture');

-- Disciple of Frost
SET @ENTRY := 28490;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,22000,26000,11,53549,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Icy Touch'),
(@ENTRY,0,1,0,9,0,100,0,0,20,16900,21200,11,53536,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Howling Blast on Close'),
(@ENTRY,0,2,0,9,0,100,0,0,10,24500,29800,11,53570,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Hungering Cold on Close'),
(@ENTRY,0,3,0,0,0,100,0,4000,6000,13400,15800,11,53550,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mind Freeze');

-- Hydromancer Velratha
SET @ENTRY := 7795;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,0,0,3400,4700,11,78801,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,1,0,2,0,100,3,0,50,0,0,11,12491,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Healing Wave at 50% HP'),
(@ENTRY,0,2,0,9,0,100,2,0,20,14000,16000,11,78802,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crashing Wave on Close');

-- Malignant Trogg
SET @ENTRY := 39984;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Puncture'),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,11,74699,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Modgud\'s Malice on Death'),
(@ENTRY,0,2,0,9,0,100,6,0,8,15000,18000,11,74837,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Modgud\'s Malady on Close');

-- Trogg Dweller
SET @ENTRY := 45467;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,2000,4500,12000,14000,11,76507,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Claw Puncture'),
(@ENTRY,0,1,0,6,0,100,7,0,0,0,0,11,74699,3,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Modgud\'s Malice on Death'),
(@ENTRY,0,2,0,9,0,100,6,0,8,15000,18000,11,74837,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Modgud\'s Malady on Close');

-- Shimmerspine Harvester
SET @ENTRY := 46474;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,0,0,70,15000,17000,11,80522,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Demoralizing Mmmrrrggglll at 70% HP'),
(@ENTRY,0,1,0,9,0,100,0,0,20,15000,25000,11,6533,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Net on Close');

-- Flamewaker Centurion
SET @ENTRY := 53222;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,30,0,5,12000,14500,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Mortal Strike on Close');

-- Enchanted Highmistress <The Queen's Royal Guard>
SET @ENTRY := 56579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,0,0,3400,4700,11,102265,64,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Fireball'),
(@ENTRY,0,1,0,9,0,100,6,0,10,14500,15500,11,102263,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Firebomb on Close');

-- Captain Flat Tusk <Captain of the Battleguard>
SET @ENTRY := 5824;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,1,0,0,0,0,11,5280,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Razor Mane on Spawn'),
(@ENTRY,0,1,0,9,0,100,0,0,5,7000,12000,11,77558,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Bloody Strike on Close'),
(@ENTRY,0,2,0,2,0,100,1,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,4,0,4,0,100,1,0,0,0,0,11,79733,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Commanding Shout on Aggro');
-- NPC talk text insert
SET @ENTRY := 5824;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',16,0,100,0,0,0, 'combat Flee');






















































