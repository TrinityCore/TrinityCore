UPDATE `creature_template` SET `npcflag`=`npcflag`|16777216 WHERE `entry`=40176; -- Sen'jin Frog
-- Add missing table at Steelgrill's Depot
DELETE FROM `gameobject` WHERE `guid`=151888 AND `id`=202564;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES 
(151888,202564,0,1,1,-5463.98975,-626.967041,393.528717,0,0,0,0,0,120,0,1);
-- Add non-existing equipment
DELETE FROM `creature_equip_template` WHERE `entry`=2432;
INSERT INTO `creature_equip_template` (`entry`,`equipentry1`,`equipentry2`,`equipentry3`) VALUES 
(2432,53056,0,0);
UPDATE `creature_template` SET `equipment_id`=2432 WHERE `entry`=39368; -- Set equipment to Drill Sergeant Steamcrank
UPDATE `creature_template` SET `equipment_id`=2432 WHERE `entry`=39675; -- Set equipment to Captain Tread Sparknozzle
UPDATE `creature_template` SET `equipment_id`=682 WHERE `entry`=32417; -- Set equipment to Scarlet Highlord Daion
-- Mjordin Combatant does not have EAI present
UPDATE `creature_template` SET `AIName`= '' WHERE `entry`=30037;
-- Netherwing Ledge Fixup
-- Fix and add spawns
DELETE FROM `creature` WHERE `id` IN (23289,23345,23346,23348,23291,23340,23342,23344,23370,23376,23427,23489);
DELETE FROM `creature` WHERE `guid` BETWEEN 52334 AND 52347;
INSERT INTO `creature` (guid,id,map,spawnMask,phaseMask,modelid,equipment_id,position_x,position_y,position_z,orientation,spawntimesecs,spawndist,currentwaypoint,curhealth,curmana,DeathState,MovementType) VALUES 
(52334,23289,530,1,1,0,0,-5155.48975,696.2224,42.196106,4.90454865,120,0,0,1,0,0,0), -- Mine Car
(52335,23289,530,1,1,0,0,-5195.42334,620.3688,44.1691132,6.20430231,120,0,0,1,0,0,0), -- Mine Car
(52336,23345,530,1,1,0,0,-5066.307,640.2136,86.49668,1.553343,120,0,0,1,0,0,0), -- Wing Commander Ichman
(52337,23346,530,1,1,0,0,-5060.32666,640.43634,86.66157,1.50098312,120,0,0,1,0,0,0), -- Wing Commander Mulverick
(52338,23348,530,1,1,0,0,-5074.878,625.448547,85.91173,1.57079637,120,0,0,1,0,0,0), -- Captain Skyshatter
(52339,23291,530,1,1,0,0,-5105.28,548.8744,85.7275848,0.4537856,120,0,0,1,0,0,0), -- Chief Overseer Mudlump <Beater of Peons>
(52340,23340,530,1,1,0,0,-5088.555,640.8356,86.61429,1.48352981,120,0,0,1,0,0,0), -- Murg "Oldie" Muckjaw
(52341,23342,530,1,1,0,0,-5081.61768,640.931763,86.61429,1.57079637,120,0,0,1,0,0,0), -- Trope the Filth-Belcher
(52342,23344,530,1,1,0,0,-5072.988,640.0335,86.48929,1.60313094,120,0,0,1,0,0,0), -- Corlok the Vet
(52343,23370,530,1,1,0,0,-5104.80127,683.6003,104.504616,5.56760025,120,0,0,1,0,0,0), -- Dragonmaw Tower Controller
(52344,23376,530,1,1,0,0,-5129.35352,681.3448,40.0699348,1.04193306,120,0,0,1,0,0,0), -- Dragonmaw Foreman
(52345,23376,530,1,1,0,0,-5197.53369,620.5416,44.5623055,6.202318,120,0,0,1,0,0,0), -- Dragonmaw Foreman
(52346,23427,530,1,1,0,0,-5092.035,581.6629,86.958786,1.18682384,120,0,0,1,0,0,0), -- Illidari Lord Balthas
(52347,23489,530,1,1,0,0,-5099.259,617.7783,85.9796,4.22369671,120,0,0,1,0,0,0); -- Drake Dealer Hurlunk
DELETE FROM `creature_template_addon` WHERE `entry` IN (23345,23346,23348,23291,23340,23342,23344,23370,23427,23489);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes2`) VALUES
(23345,17718,1), -- Wing Commander Ichman
(23346,17719,1), -- Wing Commander Mulverick
(23348,21425,1), -- Captain Skyshatter
(23291,0,1), -- Chief Overseer Mudlump <Beater of Peons>
(23340,17701,1), -- Murg "Oldie" Muckjaw
(23342,21155,1), -- Trope the Filth-Belcher
(23344,16314,1), -- Corlok the Vet
(23370,0,1), -- Dragonmaw Tower Controller
(23427,0,1), -- Illidari Lord Balthas
(23489,0,1); -- Drake Dealer Hurlunk
UPDATE `creature_model_info` SET `bounding_radius`=0.5,`combat_reach`=1,`gender`=2 WHERE `modelid`=11686; -- Dragonmaw Peon Work Node
UPDATE `creature_model_info` SET `bounding_radius`=0.62,`combat_reach`=2,`gender`=2 WHERE `modelid`=21412; -- Nethermine Flayer
UPDATE `creature_model_info` SET `bounding_radius`=0.3361105,`combat_reach`=1.1,`gender`=0 WHERE `modelid`=20284; -- Nethermine Ravager
UPDATE `creature_model_info` SET `bounding_radius`=0.4687497,`combat_reach`=2.025,`gender`=0 WHERE `modelid`=20893; -- Dragonmaw Skybreaker
UPDATE `creature_model_info` SET `bounding_radius`=2.5,`combat_reach`=5,`gender`=0 WHERE `modelid`=20896; -- Dragonmaw Ascendant
UPDATE `creature_model_info` SET `bounding_radius`=0.5022,`combat_reach`=2.025,`gender`=0 WHERE `modelid`=21421; -- Murg "Oldie" Muckjaw
UPDATE `creature_model_info` SET `bounding_radius`=0.520833,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=21424; -- Corlok the Vet
UPDATE `creature_model_info` SET `bounding_radius`=0.520833,`combat_reach`=2.25,`gender`=0 WHERE `modelid`=21426; -- Captain Skyshatter
UPDATE `creature_model_info` SET `bounding_radius`=1,`combat_reach`=0,`gender`=0 WHERE `modelid`=21422; -- Trope the Filth-Belcher
UPDATE `creature_template` SET `exp`=1,`minlevel`=70,`maxlevel`=70,`speed_run`=1 WHERE `entry`=23308; -- Dragonmaw Peon Work Node
UPDATE `creature_template` SET `speed_walk`=2,`speed_run`=2 WHERE `entry`=22253; -- Dragonmaw Ascendant
-- More Netherwing Eggs
SET @GUID := 151889;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @GUID AND @GUID+2;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`) VALUES
(@GUID,185915,530,1,1,-4244.827,325.0044,134.4166,0.1396245,0,0,0.06975555,0.9975641,1600),
(@GUID+1,185915,530,1,1,-4221.473,370.1472,136.2317,2.111848,0,0,0.8703556,0.4924237,1600),
(@GUID+2,185915,530,1,1,-5103.112,707.9791,85.04285,0.2792516,0,0,0.1391726,0.9902682,1600);
