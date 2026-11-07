--
SET @CGUID := 147511; -- 5
SET @OGUID := 94151; -- 21

-- Luma Skymother
DELETE FROM `creature_text` WHERE `CreatureID` = 25697;

-- Update positions of existing creatures and add missing
UPDATE `creature` SET `position_x` = -92.4572, `position_y` = -110.664, `position_z` = -2.86676, `spawntimesecs` = 86400, `VerifiedBuild` = 12340 WHERE `guid` = 202734;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `guid` = 84148;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `guid` = 84156;
UPDATE `creature` SET `position_x` = -112.21, `position_y` = -120.209, `position_z` = -2.658, `orientation` = 5.18363, `spawntimesecs` = 300, `VerifiedBuild` = 12340 WHERE `guid` = 202736;
UPDATE `creature` SET `position_x` = -110.195, `position_y` = -116.621, `position_z` = -3.25569, `orientation` = 0.10472, `spawntimesecs` = 300, `VerifiedBuild` = 12340 WHERE `guid` = 202735;
UPDATE `creature` SET `position_x` = -93.1848, `position_y` = -115.921, `position_z` = -2.69253, `orientation` = 3.80482, `spawntimesecs` = 300, `VerifiedBuild` = 12340 WHERE `guid` = 202737;
UPDATE `creature` SET `position_x` = -97.4688, `position_y` = -231.198, `position_z` = -2.10893, `orientation` = 1.46608, `VerifiedBuild` = 12340 WHERE `guid` = 84153;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `guid` = 84154;
UPDATE `creature` SET `position_x` = -109.224, `position_y` = -120.052, `position_z` = -2.98242, `orientation` = 5.11381, `spawntimesecs` = 300, `VerifiedBuild` = 12340 WHERE `guid` = 202738;
UPDATE `creature` SET `position_x` = -92.6896, `position_y` = -119.628, `position_z` = -2.27036, `orientation` = 4.2237, `spawntimesecs` = 300, `VerifiedBuild` = 12340 WHERE `guid` = 202739;
UPDATE `creature` SET `position_y` = -224.929, `orientation` = 4.5714, `VerifiedBuild` = 12340 WHERE `guid` = 84149;
UPDATE `creature` SET `orientation` = 5.32933, `VerifiedBuild` = 12340 WHERE `guid` = 84150;
UPDATE `creature` SET `position_x` = -104.069, `position_y` = -223.537, `position_z` = -0.90263, `orientation` = 5.72273, `VerifiedBuild` = 12340 WHERE `guid` = 84151;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `guid` = 73428;
UPDATE `creature` SET `position_x` = -69.812, `VerifiedBuild` = 12340 WHERE `guid` = 73427;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `guid` = 84152;
UPDATE `creature` SET `VerifiedBuild` = 12340 WHERE `guid` = 84155;
UPDATE `creature` SET `spawntimesecs` = 5 WHERE `id` IN (25964,25965,25966);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+0,25971,547,0,0,1,1,0,0,-143.172,-147.68,-3.16113,4.85202,300,0,0,1,0,0,0,0,0,'',NULL,12340),
(@CGUID+1,25972,547,0,0,1,1,0,0,-134.304,-145.78,-1.70332,4.67748,300,0,0,1,0,0,0,0,0,'',NULL,12340),
(@CGUID+2,25973,547,0,0,1,1,0,0,-125.036,-144.207,-1.9166,4.99164,300,0,0,1,0,0,0,0,0,'',NULL,12340),
(@CGUID+3,26230,547,0,0,1,1,0,0,-98.8607,-233.753,8.37293,2.75762,300,0,0,1,0,0,0,0,0,'',NULL,12340),
(@CGUID+4,40446,547,0,0,1,1,0,1,-76.9917,-157.081,-2.10639,5.63741,86400,0,0,1,0,0,0,0,0,'',NULL,12340);

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `game_event_creature` (`eventEntry`,`guid`) VALUES
(1,@CGUID+0),
(1,@CGUID+1),
(1,@CGUID+2),
(1,@CGUID+3),
(1,@CGUID+4);

-- Respawn gameobjects
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` IN (187882,188067,188072,188073,188142) AND `map` = 547);
DELETE FROM `game_event_gameobject` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id` IN (187882,188067,188072,188073,188142) AND `map` = 547);
DELETE FROM `gameobject` WHERE `id` IN (187882,188067,188072,188073,188142) AND `map` = 547;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+00 AND @OGUID+20;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+00, 188067, 547, 0, 0, 1, 1, -75.2318267822265625, -217.329315185546875, -3.0727999210357666, -0.48869124054908752, 0, 0, -0.24192142486572265, 0.970295846462249755, 300, 255, 1, 12340), -- 188067 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+01, 188067, 547, 0, 0, 1, 1, -49.2725067138671875, -168.985946655273437, -1.89881098270416259, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 300, 255, 1, 12340), -- 188067 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+02, 188067, 547, 0, 0, 1, 1, -71.8962478637695312, -145.49737548828125, -1.55181300640106201, -1.9547656774520874, 0, 0, -0.82903671264648437, 0.559194147586822509, 300, 255, 1, 12340), -- 188067 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+03, 188067, 547, 0, 0, 1, 1, -79.397003173828125, -219.702499389648437, -4.04289197921752929, -2.19911456108093261, 0, 0, -0.8910064697265625, 0.453990638256072998, 300, 255, 1, 12340), -- 188067 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+04, 188067, 547, 0, 0, 1, 1, -83.5252761840820312, -172.18060302734375, -3.81652188301086425, 0.017452461645007133, 0, 0, 0.008726119995117187, 0.999961912631988525, 300, 255, 1, 12340), -- 188067 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+05, 188067, 547, 0, 0, 1, 1, -115.598533630371093, -162.772384643554687, -1.92402505874633789, -0.55850392580032348, 0, 0, -0.27563667297363281, 0.961261868476867675, 300, 255, 1, 12340), -- 188067 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+06, 188067, 547, 0, 0, 1, 1, -75.9513931274414062, -182.77099609375, -4.88201713562011718, -1.15191638469696044, 0, 0, -0.54463863372802734, 0.838670849800109863, 300, 255, 1, 12340), -- 188067 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+07, 188072, 547, 0, 0, 1, 1, -69.2177276611328125, -163.490951538085937, -2.04477310180664062, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 300, 255, 1, 12340), -- 188072 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+08, 188072, 547, 0, 0, 1, 1, -71.824859619140625, -164.474990844726562, -3.96298193931579589, -0.92502385377883911, 0, 0, -0.446197509765625, 0.894934535026550292, 300, 255, 1, 12340), -- 188072 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+09, 188072, 547, 0, 0, 1, 1, -71.4891510009765625, -160.731643676757812, -4.18568992614746093, -0.41887861490249633, 0, 0, -0.20791149139404296, 0.978147625923156738, 300, 255, 1, 12340), -- 188072 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+10, 188072, 547, 0, 0, 1, 1, -69.2083663940429687, -160.345046997070312, -4.25643014907836914, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 300, 255, 1, 12340), -- 188072 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+11, 188073, 547, 0, 0, 1, 1, -89.7520523071289062, -113.500236511230468, -2.70944190025329589, 0.453785032033920288, 0, 0, 0.224950790405273437, 0.974370121955871582, 300, 255, 1, 12340), -- 188073 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+12, 188073, 547, 0, 0, 1, 1, -114.957443237304687, -117.301666259765625, -2.71000003814697265, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 300, 255, 1, 12340), -- 188073 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+13, 188142, 547, 0, 0, 1, 1, -75.4278411865234375, -221.159988403320312, -2.88294100761413574, 0.488691240549087524, 0, 0, 0.241921424865722656, 0.970295846462249755, 300, 255, 1, 12340), -- 188142 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+14, 188142, 547, 0, 0, 1, 1, -117.385650634765625, -165.964920043945312, -2.01864600181579589, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 300, 255, 1, 12340), -- 188142 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+15, 188142, 547, 0, 0, 1, 1, -74.6595916748046875, -243.812469482421875, -2.73599910736083984, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 300, 255, 1, 12340), -- 188142 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+16, 188142, 547, 0, 0, 1, 1, -103.713432312011718, -245.504074096679687, -1.37788105010986328, -1.29154169559478759, 0, 0, -0.60181427001953125, 0.798636078834533691, 300, 255, 1, 12340), -- 188142 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+17, 188142, 547, 0, 0, 1, 1, -118.919563293457031, -204.802276611328125, -1.50416100025177001, 1.919861555099487304, 0, 0, 0.819151878356933593, 0.573576688766479492, 300, 255, 1, 12340), -- 188142 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+18, 188142, 547, 0, 0, 1, 1, -72.753143310546875, -185.154693603515625, -4.93059301376342773, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 300, 255, 1, 12340), -- 188142 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+19, 187882, 547, 0, 0, 1, 1, -69.9045486450195312, -162.244949340820312, -2.366563081741333, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 86400, 255, 1, 12340), -- 187882 (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+20, 195000, 547, 0, 0, 1, 1, -98.0260238647460937, -230.428787231445312, -7.61181306838989257, 0, 0, 0, 0, 1, 300, 255, 1, 12340); -- 195000 (Area: 0 - Difficulty: 0) CreateObject1

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+00 AND @OGUID+20;
INSERT INTO `game_event_gameobject` (`eventEntry`,`guid`) VALUES
(1,@OGUID+00),
(1,@OGUID+01),
(1,@OGUID+02),
(1,@OGUID+03),
(1,@OGUID+04),
(1,@OGUID+05),
(1,@OGUID+06),
(1,@OGUID+07),
(1,@OGUID+08),
(1,@OGUID+09),
(1,@OGUID+10),
(1,@OGUID+11),
(1,@OGUID+12),
(1,@OGUID+13),
(1,@OGUID+14),
(1,@OGUID+15),
(1,@OGUID+16),
(1,@OGUID+17),
(1,@OGUID+18),
(1,@OGUID+19),
(1,@OGUID+20);

-- Flamecallers
DELETE FROM `waypoint_data` WHERE `id` IN (2027370,2027360,2027350);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(2027370,1,-100.88306,-124.1661,-1.8983139,NULL,0,0,0,100,0),
(2027370,2,-111.86027,-131.01558,-1.8261951,NULL,0,0,0,100,0),
(2027370,3,-133.16624,-129.1665,-1.8110363,NULL,0,0,0,100,0),
(2027370,4,-137.43831,-136.40495,-1.7238404,NULL,0,0,0,100,0),

(2027360,1,-130.73262,-127.74429,-1.8071115,NULL,0,0,0,100,0),
(2027360,2,-129.0413,-132.14944,-2.092847,NULL,0,0,0,100,0),

(2027350,1,-111.93455,-129.72392,-2.0384862,NULL,0,0,0,100,0),
(2027350,2,-127.86124,-131.64095,-2.1006312,NULL,0,0,0,100,0),
(2027350,3,-145.22327,-137.55428,-1.5905597,NULL,0,0,0,100,0);

UPDATE `creature` SET `StringId` = 'EarthenRingFlamecaller1' WHERE `guid` = 202737 AND `id` = 25754;
UPDATE `creature` SET `StringId` = 'EarthenRingFlamecaller2' WHERE `guid` = 202736 AND `id` = 25754;
UPDATE `creature` SET `StringId` = 'EarthenRingFlamecaller3' WHERE `guid` = 202735 AND `id` = 25754;

UPDATE `creature_template_movement` SET `InteractionPauseTimer` = 0 WHERE `CreatureId` = 25754;

-- Shaman Bonfire Bunny
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_shaman_bonfire_bunny' WHERE `entry` IN (25971,25972,25973);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25971,25972,25973) AND `source_type` = 0;

-- Ahune
UPDATE `creature_template_movement` SET `Rooted` = 1 WHERE `CreatureId` = 25740;

DELETE FROM `creature_text` WHERE `CreatureID` = 25740;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(25740,0,0,"The Frost Lord has won.",41,0,100,0,0,0,25153,1,"Ahune EMOTE_WON");

UPDATE `creature_template_addon` SET `StandState` = 0, `auras` = '' WHERE `entry` = 25740;

-- Frozen Core
DELETE FROM `creature_template_addon` WHERE `entry` = 25865;

-- Wisp Source Bunny
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26121 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 26121;

-- Wisp Dest Bunny
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26120 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 26120;

-- [PH] Ahune Loot Loc Bunny
UPDATE `smart_scripts` SET `action_param1` = 45939, `comment` = "[PH] Ahune Loot Loc Bunny - On Spellhit 'Summon Ahune's Loot Missile' - Cast 'Summon Ahune's Loot'" WHERE `entryorguid` = 25746 AND `source_type` = 0;

-- [PH] Spank Target Bunny
DELETE FROM `smart_scripts` WHERE `entryorguid` = 26190 AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = '' WHERE `entry` = 26190;

-- Ghost of Ahune
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 2 WHERE `entry` = 26239;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 26239 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2623900 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26239,0,0,0,11,0,100,0,0,0,0,0,0,11,24235,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ghost of Ahune - On Spawn - Cast 'Super Invis'"),
(26239,0,1,0,11,0,100,0,0,0,0,0,0,11,46786,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ghost of Ahune - On Spawn - Cast 'Ahune's Ghost Disguise'"),
(26239,0,2,0,38,0,100,0,0,0,0,0,0,80,2623900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ghost of Ahune - On Data Set 0 0 - Run Script"),

(2623900,9,0,0,0,0,100,0,1200,1200,0,0,0,28,24235,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ghost of Ahune - On Script - Remove Aura 'Super Invis'"),
(2623900,9,1,0,0,0,100,0,1200,1200,0,0,0,11,24235,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ghost of Ahune - On Script - Cast 'Super Invis'");

UPDATE `spell_dbc` SET `DurationIndex` = 21 WHERE `Id` = 24235; -- Infinite duration in sniffs

-- Skar'this the Summoner
UPDATE `creature_text` SET `Type` = 12 WHERE `CreatureID` = 40446;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 40446 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(40446,0,0,0,1,0,100,0,0,0,1200,1200,0,11,75427,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Skar'this the Summoner - Out Of Combat - Cast 'Frost Channelling'"),
(40446,0,1,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Skar'this the Summoner - On Aggro - Say Line 0"),
(40446,0,2,0,0,0,100,0,3000,5000,3000,5000,0,11,15043,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Skar'this the Summoner - In Combat - Cast 'Frostbolt'"),
(40446,0,3,0,0,0,100,0,10000,15000,15000,25000,0,11,11831,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Skar'this the Summoner - In Combat - Cast 'Frost Nova'"),
(40446,0,4,0,0,0,100,0,15000,20000,15000,25000,0,11,55909,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Skar'this the Summoner - In Combat - Cast 'Crashing Wave'");

-- Ahunite Hailstone
-- Ahunite Coldwave
-- Ahunite Frostwind
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25755,25756,25757) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25755,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ahunite Hailstone - On AI Initialize - Set Corpse Delay"),
(25755,0,1,0,0,0,100,0,5000,10000,15000,25000,0,11,2676,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ahunite Hailstone - In Combat - Cast 'Pulverize'"),

(25756,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ahunite Coldwave - On AI Initialize - Set Corpse Delay"),
(25756,0,1,0,11,0,100,0,0,0,0,0,0,11,45955,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ahunite Coldwave - On Spawn - Cast 'Minion Despawn Control Aura'"),
(25756,0,2,0,0,0,100,0,0,0,4000,5000,0,11,46406,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ahunite Coldwave - In Combat - Cast 'Bitter Blast'"),

(25757,0,0,0,37,0,100,0,0,0,0,0,0,116,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ahunite Frostwind - On AI Initialize - Set Corpse Delay"),
(25757,0,1,0,11,0,100,0,0,0,0,0,0,11,45955,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ahunite Frostwind - On Spawn - Cast 'Minion Despawn Control Aura'"),
(25757,0,2,0,60,0,100,0,0,10000,10000,15000,0,11,12550,34,0,0,0,0,1,0,0,0,0,0,0,0,0,"Ahunite Frostwind - On Update - Cast 'Lightning Shield'"),
(25757,0,3,0,0,0,100,0,5000,10000,10000,20000,0,11,46568,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Ahunite Frostwind - In Combat - Cast 'Wind Buffet'");

-- Ice Chest
UPDATE `gameobject_template_addon` SET `flags` = 0 WHERE `entry` = 187892;

-- Spells
UPDATE `conditions` SET `ConditionValue2` = 25971 WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (46398,46396);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (46236,46143,46176,46382);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,46236,0,0,31,0,3,25754,0,0,0,0,"","Group 0: Spell 'Close Opening Visual' (Effect 0) targets creature 'Earthen Ring Flamecaller'"),
(13,1,46143,0,0,31,0,3,25746,0,0,0,0,"","Group 0: Spell 'Summon Minion Missile, Minion 2' (Effect 0) targets creature '[PH] Ahune Loot Loc Bunny'"),
(13,1,46176,0,0,31,0,3,25746,0,0,0,0,"","Group 0: Spell 'Summon Minion Missile, Higher' (Effect 0) targets creature '[PH] Ahune Loot Loc Bunny'"),
(13,1,46382,0,0,31,0,3,25746,0,0,0,0,"","Group 0: Spell 'Summon Minion Missile, Minion 3' (Effect 0) targets creature '[PH] Ahune Loot Loc Bunny'");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_ahune_find_opening_visual',
'spell_ahune_find_opening_beam_end',
'spell_ahune_spank_force_bunny_to_knock_you_to',
'spell_ahune_make_ahunes_ghost_burst',
'spell_ahune_ahunes_shield');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45964, 'spell_ahune_find_opening_visual'),
(46333, 'spell_ahune_find_opening_beam_end'),
(46735, 'spell_ahune_spank_force_bunny_to_knock_you_to'),
(46809, 'spell_ahune_make_ahunes_ghost_burst'),
(45954, 'spell_ahune_ahunes_shield');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-45964,45964);

DELETE FROM `spell_script_names` WHERE `spell_id` = 45955 AND `ScriptName` = 'spell_gen_despawn_aura';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(45955,'spell_gen_despawn_aura');

DELETE FROM `disables` WHERE `sourceType` = 0 AND `entry` = 46320; 
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(0,46320,64,'','',"Disable LOS for spell 'Slippery Floor Ambient Periodic'");
