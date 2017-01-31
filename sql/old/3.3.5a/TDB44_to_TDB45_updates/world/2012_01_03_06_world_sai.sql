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

-- SmartAI for Wildspawn Hellcaller
SET @ENTRY := @NPC_WILDSPAWN_HELLCALLER;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=3 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,1,2,4,0,100,0,0,0,0,0,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Hellcaller - On Aggro - Cast Fireball '),
(@ENTRY,0,2,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - On Aggro - Set Phase 1'),
(@ENTRY,0,3,0,9,1,100,0,0,40,2400,3800,11,15228,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Phase 1 - Cast Fireball'),
(@ENTRY,0,4,5,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller -In Phase 1 - Start Combat Movement'),
(@ENTRY,0,5,0,61,1,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Mana at 15% (Phase 1) - Set Phase 2'),
(@ENTRY,0,6,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Hellcaller - At 35 Yards  (Phase 1) - Start Combat Movement'),
(@ENTRY,0,7,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - at 15 Yards (Phase 1) - Prevent Combat Movement '),
(@ENTRY,0,8,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Below 5 Yards (Phase 1) - Start Combat Movement'),
(@ENTRY,0,9,0,3,2,100,0,0,30,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Mana is above 30% (Phase 2) - Set Phase 1'),
(@ENTRY,0,10,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Hellcaller - Set Phase 1 when Mana is above 30% (Phase 2)'),
(@ENTRY,0,11,0,0,0,100,0,8000,14000,18000,25000,11,20754,3,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Hellcaller - In Combat - Cast Rain of Fire'),
(@ENTRY,0,12,0,2,0,100,1,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Hellcaller - At 15% HP - Start Combat Movement'),
(@ENTRY,0,13,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Betrayer - At 15% HP - Flee'),
(@ENTRY,0,14,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Evade - Set Phase to 0');

-- SmartAI for Wildspawn Felsworn
SET @ENTRY := @NPC_WILDSPAWN_FELSWORN;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=3 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,1,1000,1000,1800000,1800000,11,12542,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - Cast Chaotic Focus'),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Aggro - Prevent Combat Movement'),
(@ENTRY,0,2,3,4,0,100,0,0,0,0,0,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Aggro - Cast Shadow Bolt'),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Aggro - Set Phase 1'),
(@ENTRY,0,4,0,9,1,100,0,0,40,2400,3800,11,15537,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Felsworn - Phase 1 - Cast Shadow Bolt'),
(@ENTRY,0,5,6,3,1,100,0,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn -In Phase 1 - Start Combat Movement'),
(@ENTRY,0,6,0,61,1,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - Mana at 15% (Phase 1) - Set Phase 2'),
(@ENTRY,0,7,0,9,1,100,0,35,80,0,0,21,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Felsworn - At 35 Yards  (Phase 1) - Start Combat Movement'),
(@ENTRY,0,8,0,9,1,100,0,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - at 15 Yards (Phase 1) - Prevent Combat Movement '),
(@ENTRY,0,9,0,9,1,100,0,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - Below 5 Yards (Phase 1) - Start Combat Movement'),
(@ENTRY,0,10,0,3,2,100,0,0,30,100,100,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - Mana is above 30% (Phase 2) - Set Phase 1'),
(@ENTRY,0,11,0,0,0,100,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'Wildspawn Felsworn - Set Phase 1 when Mana is above 30% (Phase 2)'),
(@ENTRY,0,12,0,0,0,100,0,7000,12000,38000,45000,11,22417,1,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - In Phase 1 - Cast Shadow Shield'),
(@ENTRY,0,13,0,0,1,100,0,11000,17000,23000,30000,11,15654,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Felsworn - In Phase 1 - Cast Shadow Word: Pain'),
(@ENTRY,0,14,0,0,0,100,0,6000,10000,10000,15000,11,12542,1,0,0,0,0,5,0,0,0,0,0,0,0,'Wildspawn Felsworn - In Combat - Cast Fear (on random target)'),
(@ENTRY,0,15,0,7,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Felsworn - On Evade - Set Phase to 0');

-- add movement
SET @ENTRY  := 56992; -- single Wildspawn Felsworn instance
UPDATE creature SET `MovementType`=2 WHERE `guid`=@ENTRY;
DELETE FROM `creature_addon` WHERE `guid`=@ENTRY;
INSERT INTO `creature_addon`(`guid`,`path_id`) VALUES
(@ENTRY,@ENTRY*10);

-- Add waypoints to Wildspawn Felsworn instance
DELETE FROM `waypoint_data` WHERE `id`=@ENTRY*10;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@ENTRY*10,1,57.4000,-737.329,-25.1524,0,0,0,100,0),
(@ENTRY*10,2,26.45,-682.69,-24.98,0,0,0,100,0);

-- Smart AI for Wildspawn Shadowstalker
SET @ENTRY := @NPC_WILDSPAWN_SHADOWSTALKER;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
UPDATE creature SET `MovementType`=1,`spawndist`=3 WHERE `id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,22766,0,0,0,0,0,1,0,0,0,0,0,0,0,'Wildspawn Shadowstalker - On Spawn - cast Sneak on self'),
(@ENTRY,0,1,0,0,0,100,0,4000,8000,5000,8000,11,22416,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Shadowstalker - In Combat - Cast Backstab'),
(@ENTRY,0,2,0,0,0,100,0,6000,7000,8000,9000,11,7992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Wildspawn Shadowstalker - In Combat - Cast Slowing Posion');
