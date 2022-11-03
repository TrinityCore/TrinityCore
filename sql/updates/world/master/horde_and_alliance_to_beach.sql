-- *** Missing Spawns ***

SET @CGUID := 9000000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0,174971,2369,10424,13377,'0',0,0,-1,0,0,-17.644917,-6.061374,9.000128,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+1,174971,2369,10424,13377,'0',0,0,-1,0,0,-16.248755,-2.245914,8.885136,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+2,174971,2369,10424,13377,'0',0,0,-1,0,0,-4.609498,-7.722448,8.843941,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+3,174971,2369,10424,13377,'0',0,0,-1,0,0,-17.633347,5.349984,8.993013,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+4,174971,2369,10424,13377,'0',0,0,-1,0,0,-7.1927896,-1.4265188,9.105859,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+5,174971,2369,10424,13377,'0',0,0,-1,0,0,-3.5559115,-6.8839636,8.878474,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+6,174971,2369,10424,13377,'0',0,0,-1,0,0,-16.220743,-7.592815,8.926627,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+7,174971,2369,10424,13377,'0',0,0,-1,0,0,-17.212137,0.9415215,8.992922,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+8,174971,2369,10424,13377,'0',0,0,-1,0,0,-7.1881604,4.13693,8.805241,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+9,174971,2369,10424,13377,'0',0,0,-1,0,0,-3.8145015,-9.154231,8.854396,0,120,0,0,1,0,0,0,0,0,45745), -- Spar Point Advertisement
(@CGUID+10,168039,2369,10424,13377,'0',0,0,-1,0,0,-10.630922,-11.896218,8.97435,1.7062142,120,0,0,1,0,0,0,0,0,45745); -- hBoat

-- *** Creature Fixes ***

-- Phase updates
UPDATE `creature` SET `PhaseId`=13753 WHERE `id`=160737; -- Combat Dummy
UPDATE `creature` SET `PhaseId`=14349 WHERE `id`=171872; -- Apprentice Kutz
UPDATE `creature` SET `PhaseId`=14355 WHERE `id`=172033; -- Helmsman Da'vees
UPDATE `creature` SET `PhaseId`=15286 WHERE `id`=166573; -- Warlord Breka Grimaxe
UPDATE `creature` SET `PhaseId`=15286 WHERE `id`=166824; -- Warlord Breka Grimaxe
UPDATE `creature` SET `PhaseId`=15287 WHERE `id`=166827; -- Warlord Breka Grimaxe

-- Misc creature and template fixes
UPDATE `creature` SET `equipment_id`=1 WHERE `guid`=1050189;
UPDATE `creature` SET `spawntimesecs`=120 WHERE `map`=2369 AND `spawntimesecs`=7200;
UPDATE `creature` SET `curhealth`=1 WHERE `map`=2369;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=166827;
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (174971,168039);
UPDATE `creature_template` SET `faction`=35,`unit_flags`=33554432,`unit_flags2`=2048,`unit_flags3`=524320 WHERE `entry`=166814;

-- Summon data
DELETE FROM `creature_summoned_data` WHERE `CreatureID`=166814;
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`) VALUES
(166814,166815,NULL,NULL);

-- *** Actor Scripting ***

-- Warlord Breka Grimaxe "Quest: Warming Up"
SET @ENTRY := 166824;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Just Summoned - Load script"),
(@SCRIPT,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Say 0"),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Set Run off"),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,69,0,1,0,0,0,0,8,0,0,0,-10.602051,8.918945,8.779607,0,"Warlord Breka Grimaxe - Script - Move to position"),
(@SCRIPT,9,3,0,0,0,100,0,3000,3000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Emote Salute"),
(@SCRIPT,9,4,0,0,0,100,0,3000,3000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Load path");

DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'Throg will spar with you for now. I must speak to the crew about the rain.', 12, 0, 100, 0, 0, 156952, 199040, 0, 'Warlord Breka Grimaxe');

DELETE FROM `waypoints` WHERE `entry`=@SCRIPT;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,2.480713,9.498291,9.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,2,3.480713,9.748291,9.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,3,3.730713,9.998291,10.028435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,4,5.230713,12.248291,10.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,5,6.730713,11.748291,12.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,6,9.230713,10.748291,14.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,7,12.480713,9.498291,17.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,8,13.730713,9.498291,18.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,9,14.480713,9.248291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,10,15.480713,8.998291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,11,15.480713,6.748291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,12,15.730713,5.748291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,13,15.230713,5.498291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,14,15.230713,5.248291,18.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,15,15.980713,4.248291,19.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,16,18.480713,3.248291,22.028435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,17,23.480713,2.248291,26.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,18,24.480713,0.24829102,26.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,19,25.730713,-1.751709,27.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,20,28.730713,-6.001709,27.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,21,29.730713,-5.751709,27.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,22,32.730713,-7.501709,30.278435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,23,35.480713,-6.751709,33.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,24,35.980713,-6.501709,33.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,25,38.730713,-5.501709,34.528435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,26,39.980713,-5.001709,35.028435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,27,40.980713,-4.751709,36.028435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,28,44.480713,-4.001709,39.778435,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,29,45.563477,-3.4223633,39.777264,3.1642,0,'Warlord Breka Grimaxe'),
(@SCRIPT,30,45.563477,-3.4223633,39.777264,NULL,0,'Warlord Breka Grimaxe');

-- Sparing Partner "Quest: Stand Your Ground"
SET @ENTRY := 166814;
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'I concede! Your strength will see our mission through.', 12, 0, 100, 4, 0, 156976, 195857, 0, 'Sparing Partner');

DELETE FROM `waypoint_data` WHERE `id`=10501870;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501870,1,-10.846191,11.937012,8.9623165,NULL,0,0,0,100,0);

UPDATE `creature_template` SET `ScriptName`='npc_horde_sparring_partner' WHERE `entry`=166814;

-- hBoat "Quest: Brace for Impact"
UPDATE `creature_template` SET `ScriptName`='npc_hboat' WHERE `entry`=168039;

-- Grunt Throg "Quest: Brace for Impact"
SET @ENTRY := 166583;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,19,0,100,0,59927,0,0,0,85,325107,0,0,0,0,0,7,0,0,0,0,0,0,0,'Grunt Throg - On quest accept - Player cast \'Summon Throg\' on self'),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grunt Throg - On summon - Load script"),
(@ENTRY,0,2,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grunt Throg - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grunt Throg - Script - Say 0"),
(@SCRIPT,9,1,0,0,0,100,0,6000,6000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Grunt Throg - Script - Load path");

DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'Warlord! This storm will soon overwhelm us!', 12, 0, 100, 0, 0, 156977, 195892, 0, 'Grunt Throg');

SET @NPC := @SCRIPT;
DELETE FROM `waypoints` WHERE `entry` IN (@NPC);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@NPC,1,-3.9334717,1.109375,9.06326,3.353885,1000,'Grunt Throg'),
(@NPC,2,-3.9334717,1.109375,9.06326,NULL,0,'Grunt Throg');

-- Warlord Breka Grimaxe "Quest: Brace for Impact"
SET @ENTRY := 166827;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,54,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - On summon - Remove questgiver flag"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - On summon - Load path"),
(@ENTRY,0,2,0,58,0,100,0,0,@SCRIPT,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Path complete - Load script"),
(@ENTRY,0,3,0,58,0,100,0,0,@SCRIPT+1,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Say 0"),
(@SCRIPT,9,3,0,0,0,100,0,3000,3000,0,0,53,1,@SCRIPT+1,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Load path");

DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'Soldiers, brace yourselves!', 12, 0, 100, 0, 0, 156953, 195893, 0, 'Warlord Breka Grimaxe');

SET @NPC := @SCRIPT;
DELETE FROM `waypoints` WHERE `entry` IN (@NPC, @NPC+1);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@NPC,1,23.386414,-1.0205078,26.200092,NULL,0,'Warlord Breka Grimaxe'),
(@NPC,2,14.803528,1.5292969,18.348095,NULL,0,'Warlord Breka Grimaxe'),
(@NPC,3,15.010681,5.6401367,18.400091,NULL,0,'Warlord Breka Grimaxe'),
(@NPC,4,13.93335,10.104649,18.484093,NULL,0,'Warlord Breka Grimaxe'),
(@NPC,5,1.4016113,10.96875,9.103544,NULL,0,'Warlord Breka Grimaxe'),
(@NPC+1,1,-5.3898315,-0.84814453,9.203571,3.146518,1000,'Warlord Breka Grimaxe'),
(@NPC+1,2,-5.3898315,-0.84814453,9.203571,0,0,'Warlord Breka Grimaxe');

-- Mithdran Dawntracker "Quest: Brace for Impact"
SET @ENTRY := 166590;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mithdran Dawntracker - On summon - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mithdran Dawntracker - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,8000,8000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Mithdran Dawntracker - Script - Load path");

SET @NPC := @SCRIPT;
DELETE FROM `waypoints` WHERE `entry` IN (@NPC);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@NPC,1,-2.8079834,-3.972168,9.100056,3.1526,1000,'Mithdran Dawntracker'),
(@NPC,2,-2.8079834,-3.972168,9.100056,NULL,0,'Mithdran Dawntracker');

-- Lana Jordan "Quest: Brace for Impact"
SET @ENTRY := 166794;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,2,1,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lana Jordan - On summon - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lana Jordan - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,8000,8000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Lana Jordan - Script - Load path");

SET @NPC := @SCRIPT;
DELETE FROM `waypoints` WHERE `entry` IN (@NPC);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@NPC,1,-4.3847656,-2.7675781,9.160941,2.25859,1000,'Lana Jordan'),
(@NPC,2,-4.3847656,-2.7675781,9.160941,NULL,0,'Lana Jordan');

-- Bo "Quest: Brace for Impact"
SET @ENTRY := 166585;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT+1 AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,2,1,0,0,80,@SCRIPT+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bo - On summon - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bo - Path complete - Despawn"),
(@SCRIPT+1,9,0,0,0,0,100,0,8000,8000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Bo - Script - Load path");

SET @NPC := @SCRIPT;
DELETE FROM `waypoints` WHERE `entry` IN (@NPC);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@NPC,1,1.2434692,5.4038086,9.206478,3.52043,1000,'Bo'),
(@NPC,2,1.2434692,5.4038086,9.206478,NULL,0,'Bo');

-- Provisoner Jin'hake "Quest: Brace for Impact"
SET @ENTRY := 166799;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT+1 AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,2,1,0,0,80,@SCRIPT+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Provisoner Jin\'hake - On summon - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Provisoner Jin\'hake - Path complete - Despawn"),
(@SCRIPT+1,9,0,0,0,0,100,0,8000,8000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Provisoner Jin\'hake - Script - Load path");

SET @NPC := @SCRIPT;
DELETE FROM `waypoints` WHERE `entry` IN (@NPC);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@NPC,1,-2.8266602,3.7973633,9.252101,3.146518,1000,'Provisoner Jin\'hake'),
(@NPC,2,-2.8266602,3.7973633,9.252101,NULL,0,'Provisoner Jin\'hake');

-- *** Conditions ***

-- Spawn Conditions for Warlord Breka Grimaxe spawns Phase 1
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry` IN (166573,166824) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,166573,0,0,47,0,59926,11,0,0,0,0,'','Spawn of creature with entry 166573 requires Quest 59926 not rewarded'),
(32,5,166824,0,0,47,0,59926,64,0,0,0,0,'','Spawn of creature with entry 166824 requires Quest 59926 rewarded');

-- Phase conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13753,14349,14355,15284,15286,15287,15514,15516) AND `SourceEntry`=13377;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13753,13377,0,0,6,0,67,0,0,0,0,0,'','Apply Phase 13753 if team is horde'),
(26,14349,13377,0,0,6,0,67,0,0,0,0,0,'','Apply Phase 14349 if team is horde'),
(26,14355,13377,0,0,6,0,67,0,0,0,0,0,'','Apply Phase 14355 if team is horde'),
(26,15284,13377,0,0,47,0,59927,8,0,1,0,0,'','Allow Phase 15284 if Quest 59927 is not inprogress'),
(26,15284,13377,0,0,47,0,59928,2,0,1,0,0,'','Allow Phase 15284 if Quest 59928 is not complete'),
(26,15286,13377,0,0,47,0,59928,2,0,1,0,0,'','Allow Phase 15286 if Quest 59928 is not complete'),
(26,15287,13377,0,0,47,0,59928,66,0,0,0,0,'','Allow Phase 15287 if Quest 59928 is complete or rewarded'),
(26,15514,13377,0,0,47,0,59928,2,0,1,0,0,'','Allow Phase 15514 if Quest 59928 is not Complete'),
(26,15516,13377,0,0,47,0,59928,2,0,0,0,0,'','Allow Phase 15516 if Quest 59928 is Complete');

-- *** Phasing ***

DELETE FROM `phase_area` WHERE `AreaId`=13377 AND `PhaseId` IN (13753,14349,14355,15284,15286,15287,15514,15516);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(13377,13753, 'NPE Horde Ship - Combat dummys'),
(13377,14349, 'NPE Horde Ship - Apprentice Kutz'),
(13377,14355, 'NPE Horde Ship - Helmsman De\'vees'),
(13377,15284, 'NPE Horde Ship - Grunt Throg Stage 1'),
(13377,15286, 'NPE Horde Ship - Warlord Breka Grimaxe both Stage 1 (Quest 59927 incomplete'),
(13377,15287, 'NPE Horde Ship - Grunt Throg & Warlord Breka Grimaxe Stage 2 (Quest 59928 complete'),
(13377,15514, 'NPE Horde Ship - Decoration NPC´s Stage 1 (Quest 59927 incomplete'),
(13377,15516, 'NPE Horde Ship - Decoration NPC´s Stage 2 (Quest 59928 complete');

DELETE FROM `phase_name` WHERE `ID` IN (13753,14349,14355,15284,15286,15287,15514,15516);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(13753,'Cosmetic - NPE Horde Ship - Combat dummys'),
(14349,'Cosmetic - NPE Horde Ship - Apprentice Kutz'),
(14355,'Cosmetic - NPE Horde Ship - Helmsman De\'vees'),
(15284,'Cosmetic - NPE Horde Ship - Grunt Throg Stage 1'),
(15286,'Cosmetic - NPE Horde Ship - Warlord Breka Grimaxe both Stage 1'),
(15287,'Cosmetic - NPE Horde Ship - Grunt Throg & Warlord Breka Grimaxe Stage 2'),
(15514,'Cosmetic - NPE Horde Ship - Decoration NPC´s Stage 1'),
(15516,'Cosmetic - NPE Horde Ship - Decoration NPC´s Stage 2');

-- Fix condition showing Alliance quest phase on horde on ship
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13878) AND `SourceEntry`=10424;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13878,10424,0,0,47,0,54933,64,0,1,0,0,'','Apply Phase 13878 if Quest 54933 is not rewarded'),
(26,13878,10424,0,0,6,0,469,0,0,0,0,0,'','Apply PHASE 13878 if team is alliance');

-- *** Spells ***

-- Needs work to relocate target position for "Stand your Ground" Quest "Horde only tested atm"
DELETE FROM `spell_script_names` WHERE `spell_id`=325108;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(325108,'spell_summon_throg_combat_training');

-- Needed to remove player from transport before teleporting
DELETE FROM `spell_script_names` WHERE `spell_id` IN (305425,325131);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305425,'spell_alliance_spell_ship_crash_teleport'),
(325131,'spell_horde_spell_ship_crash_teleport');

-- Crash movie spell cast on player for "Brace for Impact" quest rewarded Alliance and Horde
DELETE FROM `spell_area` WHERE `spell` IN (346797,346799);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(346797,10453,58208,0,305425,0,2,1,64,0),
(346799,10453,59928,0,325131,0,2,1,64,0);

-- Wrong storm spell in db
UPDATE `spell_area` SET `spell`=305421 WHERE `spell`=305422;

-- Teleport spell locations for "Brace for Impact" quest rewarded Alliance and Horde
DELETE FROM `spell_target_position` WHERE `ID` IN (305425,325131);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(305425,4,2175,-462.4,-2619.8,0.4,45745),
(325131,3,2175,-462.4,-2619.8,0.4,45745);

-- Spell linking for enter ship and arrive at beach "Horde only tested atm"
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-290901,-305445);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-290901,290903,0,'Removing aura Attention! cast DEBUG - Look Right'),
(-305445,344889,0,'Knocked Down (DNT) removal triggers Knocked Down (DNT)');

-- *** Scenes ***

-- Add scene scripts
UPDATE `scene_template` SET `ScriptName`='scene_alliance_and_horde_ship' WHERE `SceneId`=2486;
DELETE FROM `scene_template` WHERE `SceneId` IN (2334,2487);
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2334,16,2708,0,'scene_alliance_and_horde_crash'),
(2487,16,2708,0,'scene_alliance_and_horde_crash');

-- *** Conversations ***

-- *** Mostly Horde only atm will cleanup when I get alliance data

UPDATE `conversation_template` SET `ScriptName`='conversation_horde_sparing_partner' WHERE `Id` IN (14422,14423,14424);

DELETE FROM `conversation_actors` WHERE `ConversationId`=10768;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(10768,73720,1050145,0,156280,92690,0,0,45745),
(10768,75916,1050189,1,166573,91669,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=35650;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(35650,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=10768 AND `FirstLineId`=35650;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(10768,35650,0,'',45745);

DELETE FROM `conversation_actors` WHERE `ConversationId`=12818;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12818,73720,1050145,0,156280,92690,0,0,45745),
(12818,75916,1050189,1,166573,91669,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36093;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36093,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=12818;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12818,36093,0,'',45745);

DELETE FROM `conversation_actors` WHERE `ConversationId`=12798;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12798,73720,1050145,0,156280,92690,0,0,45745),
(12798,75916,1050189,1,166573,91669,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36096;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36096,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=12798;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12798,36096,0,'',45745);


DELETE FROM `conversation_actors` WHERE `ConversationId`=14422 AND `ConversationActorId`=75920;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14422,75920,0,1,166815,91670,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36100;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36100,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=14422 AND `FirstLineId`=36099;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14422,36099,0,'',45745);


DELETE FROM `conversation_actors` WHERE `ConversationId`=14423 AND `ConversationActorId`=75920;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14423,75920,0,1,166815,91670,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36102;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36102,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=14423 AND `FirstLineId`=36101;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14423,36101,0,'',45745);


DELETE FROM `conversation_actors` WHERE `ConversationId`=14424 AND `ConversationActorId`=75920;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14424,75920,0,1,166815,91670,0,0,45745);

DELETE FROM `conversation_line_template` WHERE `Id`=36104;
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(36104,0,1,0,45745);

DELETE FROM `conversation_template` WHERE `Id`=14424 AND `FirstLineId`=36103;
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14424,36103,0,'',45745);

-- *** Quest ***

-- Add quest scripts
DELETE FROM `quest_template_addon` WHERE `ID`=59926;
INSERT INTO `quest_template_addon` (`ID`,`ScriptName`) VALUES
(59926,'quest_warming_up');
UPDATE `quest_template_addon` SET `ScriptName`='quest_stand_your_ground' WHERE `ID`=59927;
UPDATE `quest_template_addon` SET `ScriptName`='quest_brace_for_impact' WHERE `ID`=59928;

















