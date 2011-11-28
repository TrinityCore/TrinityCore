 
   /* Dungeon Normal-Heroic for 5 people */
    /* Trash Mobs */
	
-- Drakkari Battle Rider
SET @ENTRY := 29836;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,4,1,100,3,0,0,0,0,11,55348,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw on Aggro'),
(@ENTRY,0,3,0,9,1,100,2,5,30,3500,4100,11,55348,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,4,0,9,1,100,2,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@ENTRY,0,5,0,9,1,100,2,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,6,0,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@ENTRY,0,7,0,9,1,100,2,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in Throw Range'),
(@ENTRY,0,8,0,2,1,100,3,0,15,0,0,22,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'At 15% HP - Set Phase 2'),
(@ENTRY,0,9,0,2,2,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,10,0,7,2,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,11,0,2,2,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,12,0,0,1,100,2,12000,15000,16000,22000,11,55521,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Poisoned Spear'),
(@ENTRY,0,13,0,4,0,100,5,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,14,0,4,1,100,5,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,15,0,4,1,100,5,0,0,0,0,11,58966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw on Aggro'),
(@ENTRY,0,16,0,9,1,100,4,5,30,3500,4100,11,58966,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Throw'),
(@ENTRY,0,17,0,9,1,100,4,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@ENTRY,0,18,0,9,1,100,4,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,19,0,9,1,100,4,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Throw Range'),
(@ENTRY,0,20,0,9,1,100,4,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in Throw Range'),
(@ENTRY,0,21,0,2,1,100,5,0,15,0,0,22,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'At 15% HP - Set Phase 2'),
(@ENTRY,0,22,0,2,2,100,5,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,23,0,7,2,100,5,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,24,0,2,2,100,5,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,25,0,0,1,100,4,12000,15000,16000,22000,11,58967,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Poisoned Spear');
-- NPC talk text insert
SET @ENTRY := 29836;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',2,0,100,0,0,0, 'combat Flee');

-- Drakkari Earthshaker
SET @ENTRY := 29829;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,9000,14000,11,16172,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,5,9000,14000,11,58969,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Head Crack on Close'),
(@ENTRY,0,2,0,0,0,100,6,12000,15000,12000,18000,11,55563,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Slam Ground'),
(@ENTRY,0,3,0,0,0,100,6,5000,8000,5000,7000,11,55567,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Powerful Blow');

-- Drakkari Raider
SET @ENTRY := 29982;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,6,0,5,5000,7000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cleaveon Close');

-- Drakkari Rhino
SET @ENTRY := 29931;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,11000,14000,20000,11,55663,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deafening Roar'),
(@ENTRY,0,1,0,0,0,100,4,5000,11000,14000,20000,11,58992,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deafening Roar'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,55530,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,3,0,4,0,100,5,0,0,0,0,11,58991,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Drakkari Rhino
SET @ENTRY := 29838;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,11000,14000,20000,11,55663,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deafening Roar'),
(@ENTRY,0,1,0,0,0,100,4,5000,11000,14000,20000,11,58992,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deafening Roar'),
(@ENTRY,0,2,0,4,0,100,3,0,0,0,0,11,55530,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro'),
(@ENTRY,0,3,0,4,0,100,5,0,0,0,0,11,58991,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Charge on Aggro');

-- Spitting Cobra
SET @ENTRY := 29774;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,5000,6000,12000,13000,11,55703,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cobra Strike'),
(@ENTRY,0,1,0,0,0,100,4,5000,6000,12000,13000,11,59020,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cobra Strike'),
(@ENTRY,0,2,0,0,0,100,2,9000,11000,16000,18000,11,55700,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Spit'),
(@ENTRY,0,3,0,0,0,100,4,9000,11000,16000,18000,11,59019,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Venom Spit');

-- Unyielding Constrictor
SET @ENTRY := 29768;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,4000,9000,9000,12000,11,55602,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite'),
(@ENTRY,0,1,0,0,0,100,4,4000,9000,9000,12000,11,59021,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Vicious Bite');

-- Drakkari Medicine Man
SET @ENTRY := 29826;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,3,0,100,6,0,30,22000,29000,11,55582,0,0,0,0,0,5,1,0,0,0,0,0,0,'Cast Mana Link at 30% MP'),
(@ENTRY,0,1,0,2,0,100,3,0,50,0,0,11,55599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield at 50% HP'),
(@ENTRY,0,2,0,2,0,100,5,0,50,0,0,11,58981,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Earth Shield at 50% HP'),
(@ENTRY,0,3,0,14,0,100,2,30000,40,14000,21000,11,55597,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Wave on Friendlies'),
(@ENTRY,0,4,0,14,0,100,4,30000,40,14000,21000,11,58980,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Healing Wave on Friendlies'),
(@ENTRY,0,5,0,14,0,100,6,10000,30,12000,15000,11,55598,0,0,0,0,0,7,0,0,0,0,0,0,0,'Cast Cleanse Magic on Friendlies');

-- Drakkari Inciter
SET @ENTRY := 29874;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,2,0,5,5000,7000,11,12057,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close'),
(@ENTRY,0,1,0,9,0,100,4,0,5,5000,7000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Strike on Close');

-- Drakkari Golem
SET @ENTRY := 29832;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,7,0,30,0,0,11,55633,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Body of Stone at 30% HP'),
(@ENTRY,0,1,0,0,0,100,2,2000,5000,14000,17000,11,55635,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap'),
(@ENTRY,0,2,0,0,0,100,4,2000,5000,14000,17000,11,58975,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Thunderclap'),
(@ENTRY,0,3,0,0,0,100,2,5000,9000,20000,25000,11,55636,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave'),
(@ENTRY,0,4,0,0,0,100,4,5000,9000,20000,25000,11,58977,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shockwave');

-- Drakkari Lancer
SET @ENTRY := 29819;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,6,10000,15000,17000,20000,11,40546,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Retaliation'),
(@ENTRY,0,1,0,0,0,100,6,9000,12000,15000,18000,11,6713,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Disarm'),
(@ENTRY,0,2,0,0,0,100,2,4000,7000,12000,15000,11,55622,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale'),
(@ENTRY,0,3,0,0,0,100,2,4000,7000,12000,15000,11,58978,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Impale');

-- Drakkari God Hunter
SET @ENTRY := 29820;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,4,1,100,3,0,0,0,0,11,35946,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro'),
(@ENTRY,0,3,0,9,1,100,2,5,30,3500,4100,11,35946,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,4,0,9,1,100,2,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Shoot Range'),
(@ENTRY,0,5,0,9,1,100,2,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,6,0,9,1,100,2,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Shoot Range'),
(@ENTRY,0,7,0,9,1,100,2,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in Shoot Range'),
(@ENTRY,0,8,0,2,1,100,3,0,15,0,0,22,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'At 15% HP - Set Phase 2'),
(@ENTRY,0,9,0,2,2,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,10,0,7,2,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,11,0,2,2,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,12,0,2,1,100,3,0,30,0,0,11,31567,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deterrence at 30% HP'),
(@ENTRY,0,13,0,0,1,100,2,7000,10000,12000,15000,11,55624,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Arcane Shot'),
(@ENTRY,0,14,0,4,0,100,5,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,15,0,4,1,100,5,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,16,0,4,1,100,5,0,0,0,0,11,59146,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot on Aggro'),
(@ENTRY,0,17,0,9,1,100,4,5,30,3500,4100,11,59146,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Shoot'),
(@ENTRY,0,18,0,9,1,100,4,30,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Shoot Range'),
(@ENTRY,0,19,0,9,1,100,4,9,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,20,0,9,1,100,4,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in Shoot Range'),
(@ENTRY,0,21,0,9,1,100,4,5,30,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in Shoot Range'),
(@ENTRY,0,22,0,2,1,100,5,0,15,0,0,22,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'At 15% HP - Set Phase 2'),
(@ENTRY,0,23,0,2,2,100,5,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,24,0,7,2,100,5,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,25,0,2,2,100,5,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,26,0,2,1,100,5,0,30,0,0,11,31567,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Deterrence at 30% HP'),
(@ENTRY,0,27,0,0,1,100,4,7000,10000,12000,15000,11,58973,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Arcane Shot'),
(@ENTRY,0,28,0,0,1,100,6,3000,5000,33000,37000,11,55798,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Flare'),
(@ENTRY,0,29,0,0,1,100,6,18000,21000,19000,23000,11,55625,0,0,0,0,0,5,0,0,0,0,0,0,0,'Cast Tranquilizing Shot');
-- NPC talk text insert
SET @ENTRY := 29820;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',2,0,100,0,0,0, 'combat Flee');

-- Drakkari Fire Weaver
SET @ENTRY := 29822;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,3,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,1,0,4,1,100,3,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,2,0,4,1,100,3,0,0,0,0,11,55659,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@ENTRY,0,3,0,9,1,100,2,0,40,3400,4700,11,55659,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,4,0,9,1,100,2,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@ENTRY,0,5,0,9,1,100,2,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,6,0,9,1,100,2,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@ENTRY,0,7,0,3,1,100,2,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@ENTRY,0,8,0,3,2,100,2,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@ENTRY,0,9,0,3,2,100,2,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@ENTRY,0,10,0,2,2,100,3,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 3 at 15% HP'),
(@ENTRY,0,11,0,2,3,100,3,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,12,0,7,3,100,3,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,13,0,2,3,100,3,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,14,0,0,1,100,2,4000,7000,12000,15000,11,55613,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,15,0,4,0,100,5,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 on Aggro'),
(@ENTRY,0,16,0,4,1,100,5,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving on Aggro'),
(@ENTRY,0,17,0,4,1,100,5,0,0,0,0,11,58972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt on Aggro'),
(@ENTRY,0,18,0,9,1,100,4,0,40,3400,4700,11,58972,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast bolt'),
(@ENTRY,0,19,0,9,1,100,4,40,100,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving when not in bolt Range'),
(@ENTRY,0,20,0,9,1,100,4,10,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving at 15 Yards'),
(@ENTRY,0,21,0,9,1,100,4,0,40,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Stop Moving when in bolt Range'),
(@ENTRY,0,22,0,3,1,100,4,0,15,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 2 at 15% Mana'),
(@ENTRY,0,23,0,3,2,100,4,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Start Moving at 15% Mana'),
(@ENTRY,0,24,0,3,2,100,4,30,100,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 1 When Mana is above 30%'),
(@ENTRY,0,25,0,2,2,100,5,0,15,0,0,22,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'Set Phase 3 at 15% HP'),
(@ENTRY,0,26,0,2,3,100,5,0,15,0,0,25,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Flee at 15% HP'),
(@ENTRY,0,27,0,7,3,100,5,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Reset on Evade'),
(@ENTRY,0,28,0,2,3,100,5,0,15,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Say Text at 15% HP'),
(@ENTRY,0,29,0,0,1,100,4,4000,7000,12000,15000,11,58971,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Flame Shock'),
(@ENTRY,0,30,0,9,1,100,6,0,5,10000,16000,11,61362,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Blast Wave on Close');
-- NPC talk text insert
SET @ENTRY := 29822;
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0, '%s attempts to run away in fear!',2,0,100,0,0,0, 'combat Flee');

-- Snake Wrap
SET @ENTRY := 29742;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,7,1000,1000,1000,1000,11,55128,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Aura on Spawn');
