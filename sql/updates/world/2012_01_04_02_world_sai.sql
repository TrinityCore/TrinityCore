-- spawns for the first part of DM East, along Pusillins path (will make things a bit more fun ;-) )

SET @NPC_WILDSPAWN_SATYR = 11451;
SET @NPC_WILDSPAWN_ROGUE := 11452;
SET @NPC_WILDSPAWN_BETRAYER := 11454;
SET @NPC_WILDSPAWN_FELSWORN := 11455;
SET @NPC_WILDSPAWN_SHADOWSTALKER := 11456;
SET @NPC_WILDSPAWN_HELLCALLER := 11457;
SET @NPC_WARPWOOD_TREANT = 11462;
SET @NPC_WARPWOOD_CRUSHER := 13021;
SET @NPC_WHIP_LASHER := 13022;
SET @NPC_PHASE_LASHER := 13196;
SET @NPC_FEL_LASH := 13197;

-- SmartAI for Warpwood Treant
SET @ENTRY := @NPC_WARPWOOD_TREANT;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,5000,5000,7000,11,18368,0,0,0,0,0,2,0,0,0,0,0,0,0,'Warpwood Treant - In Combat - Cast Strike'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,18000,22000,11,14331,0,0,0,0,0,2,0,0,0,0,0,0,0,'Warpwood Treant - In Combat - Cast Vicious Rend'),
(@ENTRY,0,2,0,0,0,100,0,10000,12000,9000,14000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Warpwood Treant - In Combat - Cast Knockdown');

-- SmartAI for Warpwood Crusher
SET @ENTRY := @NPC_WARPWOOD_CRUSHER;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,3000,7000,8000,12000,11,22426,0,0,0,0,0,2,0,0,0,0,0,0,0,'Warpwood Crusher - In Combat - Cast Crush Armor');

-- SmartAI for Whip Lasher
SET @ENTRY := @NPC_WHIP_LASHER;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=15 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,5000,7000,9000,11,21987,0,0,0,0,0,2,0,0,0,0,0,0,0,'Whip Lasher - In Combat - Cast Lash of Pain');

-- Fel Lash
SET @ENTRY := @NPC_FEL_LASH;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=15 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fel Lash - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,'Fel Lash - On Aggro - Cast Arcane Bolt'),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Fel Lash - On Aggro - Set Phase 1'),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,15230,0,0,0,0,0,2,0,0,0,0,0,0,0,'Fel Lash - In Phase 1 - Cast Arcane Bolt '),
(@ENTRY,0,4,5,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fel Lash - In Phase 1 and Mana at 15% - Start Combat Movement'),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,2,0,0,0,0,0,0,0,0,0,0,0,0,0,'Fel Lash - In Phase 1 and  Mana is at 15% - set Phase 2'),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fel Lash - In Phase 1 - Start Combat Movement at 35 Yards'),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fel Lash - In Phase 1 - Prevent Combat Movement at 15 Yards'),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Fel Lash - In Phase 1 - Start Combat Movement Below 5 Yards'),
(@ENTRY,0,9,0,3,2,100,0,30,100,100,100,22,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Fel Lash - Phase 2 - Set Phase 1 when Mana is above 30%'),
(@ENTRY,0,10,0,0,0,100,0,9000,15000,11000,16000,11,22271,1,0,0,0,0,1,0,0,0,0,0,0,0,'Fel Lash - In Combat - Cast Arcane Explosion'),
(@ENTRY,0,11,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Fel Lash - On Evade - Set Phase to 0');

-- Phase Lasher
SET @ENTRY := @NPC_PHASE_LASHER;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=15 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - On Aggro - Set Phase 1'),
(@ENTRY,0,2,0,9,1,100,0,0,30,3400,4800,11,17228,2,0,0,0,0,2,0,0,0,0,0,0,0,'Phase Lasher - On Range - Cast Shadow Bolt Volley (Phase 1)'),
(@ENTRY,0,3,0,0,1,100,0,5000,5000,6000,6000,31,2,4,8,16,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - In Phase 1 - Random Select Phase'),
(@ENTRY,0,4,5,9,2,100,0,0,40,3400,4800,11,15285,2,0,0,0,0,2,0,0,0,0,0,0,0,'Phase Lasher - In Phase 2 - Cast Fireball Volley'),
(@ENTRY,0,5,0,61,2,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - In Phase 2 - Set Phase 1'),
(@ENTRY,0,6,7,0,4,100,0,4000,8000,8000,10000,11,22519,2,0,0,0,0,2,0,0,0,0,0,0,0,'Phase Lasher - In Phase 3 - Cast Ice Nova'),
(@ENTRY,0,7,0,61,4,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - In Phase 3 - Set Phase 1'),
(@ENTRY,0,8,0,0,8,100,0,4000,8000,10000,13000,11,22356,2,0,0,0,0,2,0,0,0,0,0,0,0,'Phase Lasher - In Phase 4 - Cast Slow'),
(@ENTRY,0,9,0,61,8,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - In Phase 4 - Set Phase 1'),
(@ENTRY,0,10,11,0,16,100,0,4000,8000,6000,8000,11,21749,2,0,0,0,0,2,0,0,0,0,0,0,0,'Phase Lasher - In Phase 5 - Cast Thorn Volley'),
(@ENTRY,0,11,0,61,16,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - In Phase 5  - Set Phase 1'),
(@ENTRY,0,12,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - On Evade - Set Phase to 0'),
(@ENTRY,0,13,0,6,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Phase Lasher - On Death - Set Phase to 0');

-- SmartAI for Wildspawn Satyr
SET @ENTRY := @NPC_WILDSPAWN_SATYR;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=3 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,4000,6000,11,15580,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Satyr - In Combat - Cast Strike'),
(@ENTRY,0,1,0,0,0,100,0,7000,9000,14000,18000,11,9080,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Satyr - In Combat - Cast Hamstring'),
(@ENTRY,0,2,0,0,0,100,0,5000,7000,15000,25000,11,9128,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Satyr - In Combat - Cast Battle Shout'),
(@ENTRY,0,3,0,2,0,100,1,0,30,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Satyr - At 30% HP - Cast Enrage'),
(@ENTRY,0,4,0,2,0,100,1,0,30,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Satyr - At 30% HP - Say Line 0');

-- Text for Wildspawn Satyr
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,'%s becomes enraged!',16,0,100,0,0,0,'Wildspawn Satyr - At 30% HP - Enraged Text');

-- SmartAI for Wildspawn Rogue
SET @ENTRY := @NPC_WILDSPAWN_ROGUE;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=3 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,7000,12000,16000,11,15583,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Rogue - In Combat - Cast Rupture'),
(@ENTRY,0,1,0,0,0,100,0,11000,15000,10000,13000,11,15667,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Rogue - In Combat - Cast Sinister Strike');

-- SmartAI for Wildspawn Betrayer
SET @ENTRY := @NPC_WILDSPAWN_BETRAYER;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=3 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - On Spawn - Prevent Combat Movement'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Betrayer - On Spawn - Prevent Melee'),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Betrayer - On Aggro - Cast Shoot'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - On Aggro - Set Phase 1'),
(@ENTRY,0,4,5,9,1,100,0,5,30,2300,3900,11,16100,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Betrayer - In Combat (Phase 1) - Cast Shoot'),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - In Combat (Phase 1) - Set Ranged Weapon Model'),
(@ENTRY,0,6,7,9,1,100,1,25,80,0,0,21,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Betrayer - At 25 Yards (Phase 1) - Start Combat Movement'),
(@ENTRY,0,7,0,61,1,100,1,0,0,0,0,20,1,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Betrayer - At 25 Yards (Phase 1) - Start Melee'),
(@ENTRY,0,8,9,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - Below 5 Yards (Phase 1) - Start Combat Movement'),
(@ENTRY,0,9,10,61,1,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - Below 5 Yards (Phase 1) - Set Melee Weapon'),
(@ENTRY,0,10,0,61,1,100,0,0,0,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - Below 5 Yards (Phase 1) - Start Melee'),
(@ENTRY,0,11,12,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - At 15 Yards (Phase 1) - Prevent Combat Movement'),
(@ENTRY,0,12,0,61,1,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - At 15 Yards (Phase 1) - Prevent Melee'),
(@ENTRY,0,13,0,9,1,100,0,5,30,7800,11400,11,18649,40,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Betrayer - In Combat (Phase 1) - Cast Shadow Shot'),
(@ENTRY,0,14,0,9,1,100,0,5,30,9900,13600,11,7896,40,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Betrayer - In Combat (Phase 1) - Cast Exploding Shot'),
(@ENTRY,0,15,0,0,1,100,0,5000,8000,8000,11000,11,11428,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Betrayer - In Combat (Phase 1) - Cast Knockdown'),
(@ENTRY,0,16,0,2,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - At 15% HP - Start Combat Movement'),
(@ENTRY,0,17,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - At 15% HP - Flee'),
(@ENTRY,0,18,19,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - On Evade - Set Phase to 0'),
(@ENTRY,0,19,0,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - On Evade -  Set Melee Weapon Model');

-- SmartAI for Wildspawn Hellcaller
SET @ENTRY := @NPC_WILDSPAWN_HELLCALLER;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=3 WHERE `id`=@ENTRY
;DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Hellcaller - On Aggro - Cast Fireball '),(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - On Aggro - Set Phase 1'),(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Phase 1 - Cast Fireball'),
(@ENTRY,0,4,5,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller -In Phase 1 - Start Combat Movement'),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Mana at 15% (Phase 1) - Set Phase 2'),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Hellcaller - At 35 Yards  (Phase 1) - Start Combat Movement'),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - at 15 Yards (Phase 1) - Prevent Combat Movement '),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Below 5 Yards (Phase 1) - Start Combat Movement'),
(@ENTRY,0,9,0,3,2,100,0,0,30,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Mana is above 30% (Phase 2) - Set Phase 1'),
(@ENTRY,0,10,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Set Phase 1 when Mana is above 30% (Phase 2)'),
(@ENTRY,0,11,0,0,0,100,0,8000,14000,18000,25000,11,20754,3,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Hellcaller - In Combat - Cast Rain of Fire'),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - At 15% HP - Start Combat Movement'),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - At 15% HP - Flee'),(@ENTRY,0,14,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Evade - Set Phase to 0');

-- SmartAI for Wildspawn Felsworn
SET @ENTRY := @NPC_WILDSPAWN_FELSWORN;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=3 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES(@ENTRY,0,0,0,1,0,100,1,1000,1000,1800000,1800000,11,12542,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - Cast Chaotic Focus'),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Aggro - Cast Shadow Bolt'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Aggro - Set Phase 1'),(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Felsworn - Phase 1 - Cast Shadow Bolt'),
(@ENTRY,0,5,6,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn -In Phase 1 - Start Combat Movement'),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - Mana at 15% (Phase 1) - Set Phase 2'),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Felsworn - At 35 Yards  (Phase 1) - Start Combat Movement'),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - at 15 Yards (Phase 1) - Prevent Combat Movement '),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - Below 5 Yards (Phase 1) - Start Combat Movement'),
(@ENTRY,0,10,0,3,2,100,0,0,30,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - Mana is above 30% (Phase 2) - Set Phase 1'),
(@ENTRY,0,11,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Felsworn - Set Phase 1 when Mana is above 30% (Phase 2)'),
(@ENTRY,0,12,0,0,0,100,0,7000,12000,38000,45000,11,22417,1,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - In Phase 1 - Cast Shadow Shield'),(@ENTRY,0,13,0,0,1,100,0,11000,17000,23000,30000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Felsworn - In Phase 1 - Cast Shadow Word: Pain'),(@ENTRY,0,14,0,0,0,100,0,6000,10000,10000,15000,11,12542,1,0,0,0,0,5,0,0,0,0,0,0,0,'Wildspawn Felsworn - In Combat - Cast Fear (on random target)'),
(@ENTRY,0,15,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Evade - Set Phase to 0');
