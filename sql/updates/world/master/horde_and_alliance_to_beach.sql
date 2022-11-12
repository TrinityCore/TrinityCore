-- *** Missing Spawns ***

SET @CGUID := 9010000;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+25;
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
(@CGUID+10,168039,2369,10424,13377,'0',0,0,-1,0,0,-10.630922,-11.896218,8.97435,1.7062142,120,0,0,1,0,0,0,0,0,45745), -- hBoat
(@CGUID+11,174971,2261,10424,10639,'0',0,0,-1,0,0,3.8316922,5.474146,5.2092524,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+12,174971,2261,10424,10639,'0',0,0,-1,0,0,2.6647408,6.4705987,5.1801515,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+13,174971,2261,10424,10639,'0',0,0,-1,0,0,9.56842,4.517551,5.1502733,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+14,174971,2261,10424,10639,'0',0,0,-1,0,0,6.701894,6.1971374,5.194476,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+15,174971,2261,10424,10639,'0',0,0,-1,0,0,7.199659,-5.407894,5.216199,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+16,174971,2261,10424,10639,'0',0,0,-1,0,0,0.4600576,-6.25066,5.2069707,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+17,174971,2261,10424,10639,'0',0,0,-1,0,0,3.8914397,-6.136929,5.1904373,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+18,174971,2261,10424,10639,'0',0,0,-1,0,0,0.9357995,5.2422814,5.221966,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+19,174971,2261,10424,10639,'0',0,0,-1,0,0,6.4270716,4.5759077,5.2394466,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+20,174971,2261,10424,10639,'0',0,0,-1,0,0,-9.461674,-4.971889,5.456243,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+21,174971,2261,10424,10639,'0',0,0,-1,0,0,-7.5362535,4.9206376,5.2989116,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+22,174971,2261,10424,10639,'0',0,0,-1,0,0,-6.4343257,-4.8330746,5.2104034,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+23,174971,2261,10424,10639,'0',0,0,-1,0,0,8.676258,-4.551461,5.2418213,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+24,174971,2261,10424,10639,'0',0,0,-1,0,0,-3.2766402,-5.403929,5.293099,0,300,0,0,1,0,0,0,0,0,0), -- Spar Point Advertisement
(@CGUID+25,156403,2261,10424,10639,'0',0,0,-1,0,0,8.402318,-0.14915128,5.2594776,3.2919948,300,0,0,1,0,0,0,0,0,0); -- aBoat

-- *** Creature Fixes ***

-- Phase updates
UPDATE `creature` SET `PhaseId`=0 WHERE `id`=171872; -- Apprentice Kutz
UPDATE `creature` SET `PhaseId`=0 WHERE `id`=172033; -- Helmsman Da'vees
UPDATE `creature` SET `PhaseId`=15286 WHERE `id`=166573; -- Warlord Breka Grimaxe
UPDATE `creature` SET `PhaseId`=15286 WHERE `id`=166824; -- Warlord Breka Grimaxe
UPDATE `creature` SET `PhaseId`=15287 WHERE `id`=166827; -- Warlord Breka Grimaxe
UPDATE `creature` SET `PhaseId`=14353 WHERE `guid` IN (1050176,1050177,1050178,1050179,1050180,1050181);
-- Misc creature and template fixes
UPDATE `creature` SET `equipment_id`=1 WHERE `guid`=1050189;
UPDATE `creature` SET `spawntimesecs`=120 WHERE `map`=2369 AND `spawntimesecs`=7200;
UPDATE `creature` SET `curhealth`=1 WHERE `map`=2369;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=166827;
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry` IN (174971,168039);
UPDATE `creature_template` SET `faction`=35,`unit_flags`=33554432,`unit_flags2`=2048,`unit_flags3`=524320 WHERE `entry`=166814;
-- Gryphons had 2 riders
UPDATE `vehicle_template_accessory` SET `minion`=1 WHERE `entry`=156345;

-- Summon data
DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN (157051,166814);
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`) VALUES
(157051,155607,NULL,NULL),
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

-- Captain Garrick  "Quest: Warming Up & Brace for Impact"
SET @ENTRY := 156280;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@SCRIPT,@SCRIPT+1) AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,38,0,100,0,1,1,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - On dataset - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Path complete - Despawn"),
(@ENTRY,0,2,3,38,0,100,0,1,2,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - On dataset - Remove questgiver flag"),
(@ENTRY,0,3,0,61,0,100,0,0,0,0,0,53,1,@SCRIPT+1,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - On dataset - Load path"),
(@ENTRY,0,4,0,58,0,100,0,0,@SCRIPT+1,0,0,80,@SCRIPT+1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Path complete - Load script"),
(@ENTRY,0,5,0,58,0,100,0,0,@SCRIPT+2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Script - Say 0"),
(@SCRIPT,9,1,0,0,0,100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Script - Set Run off"),
(@SCRIPT,9,2,0,0,0,100,0,0,0,0,0,69,0,1,0,0,0,0,8,0,0,0,-11.810547,0.9602051,5.5279408,0,"Captain Garrick - Script - Move to position"),
(@SCRIPT,9,3,0,0,0,100,0,3000,3000,0,0,5,66,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Script - Emote Salute"),
(@SCRIPT,9,4,0,0,0,100,0,4000,4000,0,0,53,0,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Script - Load path"),
(@SCRIPT+1,9,0,0,0,0,100,0,1000,1000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Script - Say 1"),
(@SCRIPT+1,9,1,0,0,0,100,0,3000,3000,0,0,53,1,@SCRIPT+2,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garrick - Script - Load path");
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'Private Cole will run you through the rest of the drills. I need to discuss this storm with the helmsman.', 12, 0, 100, 0, 0, 152734, 184106, 0, 'Captain Garrick'),
(@ENTRY, 1, 0, 'Everyone below decks! Now!', 12, 0, 100, 0, 0, 152735, 177674, 0, 'Captain Garrick');
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT,@SCRIPT+1,@SCRIPT+2);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,-0.3022461,-1.409729,5.774313,NULL,0,'Captain Garrick'),
(@SCRIPT,2,4.697754,-2.659729,5.524313,NULL,0,'Captain Garrick'),
(@SCRIPT,3,8.697754,-4.159729,5.524313,NULL,0,'Captain Garrick'),
(@SCRIPT,4,12.447754,-5.159729,5.524313,NULL,0,'Captain Garrick'),
(@SCRIPT,5,15.947754,-5.409729,6.274313,NULL,0,'Captain Garrick'),
(@SCRIPT,6,18.947754,-5.409729,9.274313,NULL,0,'Captain Garrick'),
(@SCRIPT,7,21.197754,-4.659729,9.774313,NULL,0,'Captain Garrick'),
(@SCRIPT,8,30.197754,-3.659729,11.024313,NULL,0,'Captain Garrick'),
(@SCRIPT,9,37.706055,-3.779663,12.020686,NULL,0,'Captain Garrick'),
(@SCRIPT,10,37.83252,-1.4055176,12.501659,3.31911778,0,'Captain Garrick'),
(@SCRIPT,11,37.83252,-1.4055176,12.501659,NULL,0,'Captain Garrick'),
(@SCRIPT+1,1,38.556152,-0.6357422,13.232409,NULL,0,'Captain Garrick'),
(@SCRIPT+1,2,35.56421,-1.1977539,12.1479,NULL,0,'Captain Garrick'),
(@SCRIPT+1,3,32.572266,-1.7597656,11.063391,NULL,0,'Captain Garrick'),
(@SCRIPT+1,4,28.660645,-2.8950195,10.562886,NULL,0,'Captain Garrick'),
(@SCRIPT+1,5,22.253174,-4.680664,9.82038,NULL,0,'Captain Garrick'),
(@SCRIPT+1,6,18.129395,-4.897949,8.297633,NULL,0,'Captain Garrick'),
(@SCRIPT+1,7,13.874268,-5.3256836,5.080761,NULL,0,'Captain Garrick'),
(@SCRIPT+1,8,10.271484,-5.2910156,5.001395,NULL,0,'Captain Garrick'),
(@SCRIPT+1,9,4.762451,-3.1137695,5.1861935,NULL,0,'Captain Garrick'),
(@SCRIPT+2,1,11.084107,3.9018552,5.28156,NULL,0,'Captain Garrick'),
(@SCRIPT+2,2,17.084106,4.9018555,5.53156,NULL,0,'Captain Garrick'),
(@SCRIPT+2,3,26.905762,5.4174805,4.876927,3.0892324,1000,'Captain Garrick'),
(@SCRIPT+2,4,26.905762,5.4174805,4.876927,NULL,0,'Captain Garrick');

-- Sparing Partner "Quest: Stand Your Ground"
DELETE FROM `creature_text` WHERE `CreatureID` IN (157051,166814);
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(157051, 0, 0, 'I yield! Well, I\'d say you\'re more than ready for whatever we find on that island.', 12, 0, 100, 4, 0, 152848, 177677, 0, 'Alliance Sparing Partner'),
(166814, 0, 0, 'I concede! Your strength will see our mission through.', 12, 0, 100, 4, 0, 156976, 195857, 0, 'Horde Sparing Partner');
DELETE FROM `waypoint_data` WHERE `id` IN (10501460,10501870);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(10501460,1,-13.461914,0.69628906,5.677742,NULL,0,0,0,100,0),
(10501460,2,-13.461914,0.69628906,5.677742,6.143559,1000,0,0,100,0),
(10501460,3,-13.461914,0.69628906,5.677742,NULL,0,0,0,100,0),
(10501870,1,-10.846191,11.937012,8.9623165,NULL,0,0,0,100,0),
(10501870,2,-10.846191,11.937012,8.9623165,4.677482,1000,0,0,100,0),
(10501870,3,-10.846191,11.937012,8.9623165,NULL,0,0,0,100,0);
UPDATE `creature_template` SET `ScriptName`='npc_sparring_partner' WHERE `entry` IN (157051,166814);

-- Private Cole "Quest: Stand Your Ground & Brace for Impact"
SET @ENTRY := 160664;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,19,0,100,0,58209,0,0,0,85,303064,0,0,0,0,0,7,0,0,0,0,0,0,0,'Private Cole - On quest accept - Player cast \'Summon Cole\' on self'),
(@ENTRY,0,1,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Cole - On summon - Load script"),
(@ENTRY,0,2,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Cole - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,3000,3000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Cole - Script - Say 0"),
(@SCRIPT,9,1,0,0,0,100,0,6000,6000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Private Cole - Script - Load path");
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'Captain! We can\'t weather this storm for long!', 12, 0, 100, 0, 0, 152849, 177675, 0, 'Private Cole');
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,30.931396,6.4296875,4.817522,4.1208,1000,'Private Cole'),
(@SCRIPT,2,30.931396,6.4296875,4.817522,NULL,0,'Private Cole');

-- Grunt Throg "Quest: Stand Your Ground & Brace for Impact"
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
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,-3.9334717,1.109375,9.06326,3.353885,1000,'Grunt Throg'),
(@SCRIPT,2,-3.9334717,1.109375,9.06326,NULL,0,'Grunt Throg');

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
(@SCRIPT,9,1,0,0,0,100,0,3000,3000,0,0,53,1,@SCRIPT+1,0,0,0,0,1,0,0,0,0,0,0,0,"Warlord Breka Grimaxe - Script - Load path");
DELETE FROM `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ENTRY, 0, 0, 'Soldiers, brace yourselves!', 12, 0, 100, 0, 0, 156953, 195893, 0, 'Warlord Breka Grimaxe');
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT, @SCRIPT+1);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,23.386414,-1.0205078,26.200092,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,2,14.803528,1.5292969,18.348095,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,3,15.010681,5.6401367,18.400091,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,4,13.93335,10.104649,18.484093,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT,5,1.4016113,10.96875,9.103544,NULL,0,'Warlord Breka Grimaxe'),
(@SCRIPT+1,1,-5.3898315,-0.84814453,9.203571,3.146518,1000,'Warlord Breka Grimaxe'),
(@SCRIPT+1,2,-5.3898315,-0.84814453,9.203571,0,0,'Warlord Breka Grimaxe');

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
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,-2.8079834,-3.972168,9.100056,3.1526,1000,'Mithdran Dawntracker'),
(@SCRIPT,2,-2.8079834,-3.972168,9.100056,NULL,0,'Mithdran Dawntracker');

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
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,-4.3847656,-2.7675781,9.160941,2.25859,1000,'Lana Jordan'),
(@SCRIPT,2,-4.3847656,-2.7675781,9.160941,NULL,0,'Lana Jordan');

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
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,1.2434692,5.4038086,9.206478,3.52043,1000,'Bo'),
(@SCRIPT,2,1.2434692,5.4038086,9.206478,NULL,0,'Bo');

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
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,-2.8266602,3.7973633,9.252101,3.146518,1000,'Provisoner Jin\'hake'),
(@SCRIPT,2,-2.8266602,3.7973633,9.252101,NULL,0,'Provisoner Jin\'hake');

-- Quartermaster Richter "Quest: Brace for Impact"
SET @ENTRY := 157042;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quartermaster Richter - On summon - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Quartermaster Richter - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,8000,8000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Quartermaster Richter - Script - Load path");
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,-0.9053688,-5.5730305,5.2387342,NULL,0,'Quartermaster Richter'),
(@SCRIPT,2,0.5946312,-1.3230305,5.4887342,NULL,0,'Quartermaster Richter'),
(@SCRIPT,3,3.5946312,2.4269695,5.4887342,NULL,0,'Quartermaster Richter'),
(@SCRIPT,4,9.844631,4.9269695,5.2387342,NULL,0,'Quartermaster Richter'),
(@SCRIPT,5,17.344631,5.6769695,5.4887342,NULL,0,'Quartermaster Richter'),
(@SCRIPT,6,24.344631,5.1769695,4.9887342,NULL,0,'Quartermaster Richter'),
(@SCRIPT,7,26.844631,4.1769695,4.9887342,NULL,0,'Quartermaster Richter'),
(@SCRIPT,8,30.037842,0.7416992,4.877288,1.413716,1000,'Quartermaster Richter'),
(@SCRIPT,9,30.037842,0.7416992,4.877288,NULL,0,'Quartermaster Richter');

-- Kee-la "Quest: Brace for Impact"
SET @ENTRY := 157043;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kee-la - On summon - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kee-lar - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,8000,8000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Kee-la - Script - Load path");
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,-9.640718,3.819191,5.6868877,NULL,0,'Kee-la'),
(@SCRIPT,2,-3.890718,3.319191,5.4368877,NULL,0,'Kee-la'),
(@SCRIPT,3,1.609282,3.819191,5.4368877,NULL,0,'Kee-la'),
(@SCRIPT,4,10.359282,4.819191,5.1868877,NULL,0,'Kee-la'),
(@SCRIPT,5,16.609282,5.569191,5.1868877,NULL,0,'Kee-la'),
(@SCRIPT,6,23.859282,5.069191,5.1868877,NULL,0,'Kee-la'),
(@SCRIPT,7,27.859282,4.069191,5.1868877,NULL,0,'Kee-la'),
(@SCRIPT,8,29.109282,-0.43080902,5.1868877,NULL,0,'Kee-la'),
(@SCRIPT,9,27.582764,-0.94091797,4.871175,NULL,0,'Kee-la');

-- Austin Huxworth "Quest: Brace for Impact"
SET @ENTRY := 157046;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Austin Huxworth - On summon - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Austin Huxworth - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,8000,8000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Austin Huxworth - Script - Load path");
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,-1.4587336,8.48258,5.233676,NULL,0,'Austin Huxworth'),
(@SCRIPT,2,7.2912664,6.2325807,5.233676,NULL,0,'Austin Huxworth'),
(@SCRIPT,3,19.541267,5.4825807,5.233676,NULL,0,'Austin Huxworth'),
(@SCRIPT,4,27.791267,4.7325807,4.983676,NULL,0,'Austin Huxworth'),
(@SCRIPT,5,30.068604,2.567871,4.8888426,NULL,0,'Austin Huxworth');

-- Bjorn Stouthands "Quest: Brace for Impact"
SET @ENTRY := 157044;
SET @SCRIPT := @ENTRY * 100;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@SCRIPT AND `source_type`=9;
UPDATE creature_template SET AIName="SmartAI" WHERE entry=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,0,54,0,100,0,0,0,0,0,80,@SCRIPT,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Stouthands - On summon - Load script"),
(@ENTRY,0,1,0,58,0,100,0,0,@SCRIPT,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Stouthands - Path complete - Despawn"),
(@SCRIPT,9,0,0,0,0,100,0,8000,8000,0,0,53,1,@SCRIPT,0,0,0,0,1,0,0,0,0,0,0,0,"Bjorn Stouthands - Script - Load path");
DELETE FROM `waypoints` WHERE `entry` IN (@SCRIPT);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(@SCRIPT,1,7.726696,-7.4220815,5.1850023,NULL,0,'Bjorn Stouthands'),
(@SCRIPT,2,7.976696,-2.4220815,5.4350023,NULL,0,'Bjorn Stouthands'),
(@SCRIPT,3,11.726696,3.5779185,5.1850023,NULL,0,'Bjorn Stouthands'),
(@SCRIPT,4,16.976696,5.5779185,5.1850023,NULL,0,'Bjorn Stouthands'),
(@SCRIPT,5,21.726696,5.8279185,4.9350023,NULL,0,'Bjorn Stouthands'),
(@SCRIPT,6,25.476696,5.5779185,4.9350023,NULL,0,'Bjorn Stouthands'),
(@SCRIPT,7,29.112793,4.151367,4.889695,3.124139,1000,'Bjorn Stouthands'),
(@SCRIPT,8,29.112793,4.151367,4.889695,NULL,0,'Bjorn Stouthands');

-- *** Conditions ***

-- Spawn Conditions for Warlord Breka Grimaxe spawns Phase 1
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry` IN (166573,166824) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,166573,0,0,47,0,59926,11,0,0,0,0,'','Spawn of creature with entry 166573 requires Quest 59926 not rewarded'),
(32,5,166824,0,0,47,0,59926,64,0,0,0,0,'','Spawn of creature with entry 166824 requires Quest 59926 rewarded');

-- Phase conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15284,15286,15287,15514,15516) AND `SourceEntry`=13377;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15284,13377,0,0,47,0,59927,8,0,1,0,0,'','Allow Phase 15284 if Quest 59927 is not inprogress'),
(26,15284,13377,0,0,47,0,59928,2,0,1,0,0,'','Allow Phase 15284 if Quest 59928 is not complete'),
(26,15286,13377,0,0,47,0,59928,2,0,1,0,0,'','Allow Phase 15286 if Quest 59928 is not complete'),
(26,15287,13377,0,0,47,0,59928,66,0,0,0,0,'','Allow Phase 15287 if Quest 59928 is complete or rewarded'),
(26,15514,13377,0,0,47,0,59928,2,0,1,0,0,'','Allow Phase 15514 if Quest 59928 is not Complete'),
(26,15516,13377,0,0,47,0,59928,2,0,0,0,0,'','Allow Phase 15516 if Quest 59928 is Complete');

-- Fix condition showing Alliance quest phase on horde on ship
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13861,14350,14353) AND `SourceEntry`=10639;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13861,10639,0,0,47,0,54933,2,0,0,0,0,'','Apply Phase 13861 if Quest 54933 is complete'),
(26,14350,10639,0,0,47,0,56775,64,0,0,0,0,'','Apply Phase 14350 if Quest 56775 is rewarded'),
(26,14350,10639,0,0,47,0,58208,2,0,1,0,0,'','Apply Phase 14350 if Quest 58208 is not complete'),
(26,14353,10639,0,0,47,0,58208,2,0,0,0,0,'','Allow Phase 14353 if Quest 58208 is complete');

UPDATE `conditions` SET `ConditionValue1`=58208, `Comment`='Apply Phase 13861 if Quest 58208 is complete' WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=13861 AND `SourceEntry`=10639;

-- *** Phasing ***

DELETE FROM `phase_area` WHERE `AreaId`=13377 AND `PhaseId` IN (13753,14349,14350,14355,15284,15286,15287,15514,15516);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(13377,13753, 'NPE both ships all stages Unknown'),
(13377,14349, 'NPE Alliance Ship - Captain Garrick Stage 1'),
(13377,14350, 'NPE Alliance Ship - Captain Garrick Stage 1'),
(13377,14355, 'NPE Alliance Ship - Decoration NPC´s Stage 1'),
(13377,15284, 'NPE Horde Ship - Grunt Throg Stage 1'),
(13377,15286, 'NPE Horde Ship - Warlord Breka Grimaxe both Stage 1 (Quest 59927 incomplete'),
(13377,15287, 'NPE Horde Ship - Grunt Throg & Warlord Breka Grimaxe Stage 2 (Quest 59928 complete'),
(13377,15514, 'NPE Horde Ship - Decoration NPC´s Stage 1 (Quest 59927 incomplete'),
(13377,15516, 'NPE Horde Ship - Decoration NPC´s Stage 2 (Quest 59928 complete');

DELETE FROM `phase_area` WHERE `AreaId`=10639 AND `PhaseId` IN (13753,13861,14349,14350,14353,14355);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10639,13753, 'NPE both ships all stages Unknown'),
(10639,13861, 'NPE Alliance Ship - Lightning Stage 2'),
(10639,14349, 'NPE Alliance Ship - Captain Garrick Stage 1'),
(10639,14350, 'NPE Alliance Ship - Captain Garrick Stage 1'),
(10639,14353, 'NPE Alliance Ship - Decoration NPC´s Stage 2'),
(10639,14355, 'NPE Alliance Ship - Decoration NPC´s Stage 1');

DELETE FROM `phase_name` WHERE `ID` IN (13753,13861,14349,14350,14353,14355,15284,15286,15287,15514,15516);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(13753,'Cosmetic - NPE both ships all stages Unknown'),
(13861,'Cosmetic - NPE Alliance Ship - Lightning Stage 2'),
(14349,'Cosmetic - NPE Alliance Ship - Captain Garrick before quest 56775 complete'),
(14350,'Cosmetic - NPE Alliance Ship - Captain Garrick after quest 56775 complete'),
(14353,'Cosmetic - NPE Alliance Ship - Decoration NPC´s Stage 2'),
(14355,'Cosmetic - NPE Alliance Ship - Decoration NPC´s Stage 1'),
(15284,'Cosmetic - NPE Horde Ship - Grunt Throg Stage 1'),
(15286,'Cosmetic - NPE Horde Ship - Warlord Breka Grimaxe both Stage 1'),
(15287,'Cosmetic - NPE Horde Ship - Grunt Throg & Warlord Breka Grimaxe Stage 2'),
(15514,'Cosmetic - NPE Horde Ship - Decoration NPC´s Stage 1'),
(15516,'Cosmetic - NPE Horde Ship - Decoration NPC´s Stage 2');

-- *** Spells ***

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

DELETE FROM `spell_script_names` WHERE `spell_id` IN (305464,325136);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305464,'spell_crash_landed_alliance'),
(325136,'spell_crash_landed_horde');

-- *** Scenes ***

-- Add scene scripts
UPDATE `scene_template` SET `ScriptName`='scene_alliance_and_horde_ship' WHERE `SceneId` IN (2236,2486);
DELETE FROM `scene_template` WHERE `SceneId` IN (2334,2487);
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2334,16,2708,0,'scene_alliance_and_horde_crash'), -- Alliance
(2487,16,2708,0,'scene_alliance_and_horde_crash'); -- Horde

-- *** Conversations ***

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (10768,12818,12798,14422,14423,14424);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(10768,73720,1050145,0,156280,92690,0,0,45745), -- Alliance
(10768,75916,1050189,1,166573,91669,0,0,45745), -- Horde
(12818,73720,1050145,0,156280,92690,0,0,45745), -- Alliance
(12818,75916,1050189,1,166573,91669,0,0,45745), -- Horde
(12798,73720,1050145,0,156280,92690,0,0,45745), -- Alliance
(12798,75916,1050189,1,166573,91669,0,0,45745), -- Horde
(14422,68598,0,0,160664,81534,0,0,45745), -- Alliance
(14422,75920,0,1,166583,91670,0,0,45745), -- Horde
(14423,68598,0,0,160664,81534,0,0,45745), -- Alliance
(14423,75920,0,1,166583,91670,0,0,45745), -- Horde
(14424,68598,0,0,160664,81534,0,0,45745), -- Alliance
(14424,75920,0,1,166583,91670,0,0,45745); -- Horde

DELETE FROM `conversation_line_template` WHERE `Id` IN (32717,35650,31445,36093,31382,36096,36099,36100,36101,36102,36103,36104);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES 
(32717,0,0,0,45745), -- Alliance
(35650,0,1,0,45745), -- Horde
(31445,0,0,0,45745), -- Alliance
(36093,0,1,0,45745), -- Horde
(31382,0,0,0,45745), -- Alliance
(36096,0,1,0,45745), -- Horde
(36099,0,0,0,45745), -- Alliance
(36100,0,1,0,45745), -- Horde
(36101,0,0,0,45745), -- Alliance
(36102,0,1,0,45745), -- Horde
(36103,0,0,0,45745), -- Alliance
(36104,0,1,0,45745); -- Horde

DELETE FROM `conversation_template` WHERE `Id` IN (10768,12818,12798,14422,14423,14424);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(10768,32717,0,'',45745),
(12818,31445,0,'',45745),
(12798,31382,0,'',45745),
(14422,36099,0,'',45745),
(14423,36101,0,'',45745),
(14424,36103,0,'',45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (32717,35650,31445,36093,31382,36096,36099,36100,36101,36102,36103,36104);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,32717,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 32717 if team is Alliance'),
(29,0,35650,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 35650 if team is horde'),
(29,0,31445,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 31445 if team is Alliance'),
(29,0,36093,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36093 if team is horde'),
(29,0,31382,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 31382 if team is Alliance'),
(29,0,36096,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36096 if team is horde'),
(29,0,36099,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36099 if team is Alliance'),
(29,0,36100,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36100 if team is horde'),
(29,0,36101,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36101 if team is Alliance'),
(29,0,36102,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36102 if team is horde'),
(29,0,36103,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36103 if team is Alliance'),
(29,0,36104,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36104 if team is horde');

-- *** Quest ***

-- Add quest scripts
DELETE FROM `quest_template_addon` WHERE `ID` IN (56775,59926); 
INSERT INTO `quest_template_addon` (`ID`,`ScriptName`) VALUES
(56775,'quest_warming_up'),(59926,'quest_warming_up');

UPDATE `quest_template_addon` SET `ScriptName`='quest_stand_your_ground' WHERE `ID` IN (58209,59927);
UPDATE `quest_template_addon` SET `ScriptName`='quest_brace_for_impact' WHERE `ID` IN (58208,59928);
