--
SET @CGUID := 147197; -- 21

-- Sir Wendell Balfour
-- Lorien Sunblaze
-- Conall Irongrip
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `unit_flags2` = `unit_flags2` &~ 1, `dynamicflags` = 0 WHERE `entry` IN (33439,33455,33457);
DELETE FROM `creature_template_addon` WHERE `entry` IN (33439,33455,33457);
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (33439,33455,33457);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (33439,33455,33457) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(33439,0,0,0,63,0,100,0,0,0,0,0,0,11,51195,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sir Wendell Balfour - On Just Created - Cast 'Cosmetic - Low Poly Fire'"),
(33439,0,1,0,63,0,100,0,0,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sir Wendell Balfour - On Just Created - Cast 'Permanent Feign Death'"),
(33439,0,2,0,63,0,100,0,0,0,0,0,0,11,10389,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sir Wendell Balfour - On Just Created - Cast 'Spawn Smoke'"),
(33455,0,0,0,63,0,100,0,0,0,0,0,0,11,61894,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lorien Sunblaze - On Just Created - Cast 'Spirit Particles (green - Base)'"),
(33455,0,1,0,63,0,100,0,0,0,0,0,0,11,41290,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lorien Sunblaze - On Just Created - Cast 'Disease Cloud'"),
(33455,0,2,0,63,0,100,0,0,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lorien Sunblaze - On Just Created - Cast 'Permanent Feign Death'"),
(33457,0,0,0,63,0,100,0,0,0,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Conall Irongrip - On Just Created - Cast 'Permanent Feign Death'");

UPDATE `event_scripts` SET `x` = 8461.7265625, `y` = 468.7471923828125, `z` = 596.2335205078125, `o` = 4.729842185974121093, `Comment` = "Event (Object 'Sir Wendell's Grave' (194537)) - On Event - Summon Creature 'Sir Wendell Balfour'" WHERE `id` = 21077 AND `command` = 10;
UPDATE `event_scripts` SET `x` = 8441.8642578125, `y` = 452.8818359375, `z` = 596.16571044921875, `o` = 1.850049018859863281, `Comment` = "Event (Object 'Lorien's Grave' (194539)) - On Event - Summon Creature 'Lorien Sunblaze'" WHERE `id` = 21075 AND `command` = 10;
UPDATE `event_scripts` SET `x` = 8471.435546875, `y` = 452.217437744140625, `z` = 596.15509033203125, `o` = 4.78220224380493164, `Comment` = "Event (Object 'Connall's Grave' (194538)) - On Event - Summon Creature 'Conall Irongrip'" WHERE `id` = 21076 AND `command` = 10;

-- Slain Iron Vrykul
-- Slain Iron Dwarf
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 33774;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 33775;

-- Sacrificed Aspirant
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ (536870912|262144), `dynamicflags` = 0 WHERE `entry` = 35097;

-- Slain Alliance Soldier
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912, `dynamicflags` = 0 WHERE `entry` = 31177;
-- Currently there is another pile of Dead Alliance Soldier spawned at the same spot
-- So far I found only one spawn in sniff and one spawn carried by vehicle
-- No idea if that pile should be removed or not but now there will be another pile of Slain Alliance Soldier
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+20 AND `id` = 31177;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(@CGUID+00,31177,571,1,1,0,1,6593.4,1110.48,273.085,4.88692,300,0,0,14545),
(@CGUID+01,31177,571,1,1,0,1,6772.86,1438.78,390.796,2.82743,300,0,0,14545),
(@CGUID+02,31177,571,1,1,0,1,6775.79,1441.89,390.796,4.03171,300,0,0,14545),
(@CGUID+03,31177,571,1,1,0,1,6776.28,1439.3,390.796,6.05629,300,0,0,14545),
(@CGUID+04,31177,571,1,1,0,1,6776.12,1440.33,390.796,4.27606,300,0,0,14545),
(@CGUID+05,31177,571,1,1,0,1,6774.88,1440.39,391.303,4.27606,300,0,0,14545),
(@CGUID+06,31177,571,1,1,0,1,6774.45,1441.18,390.796,2.86234,300,0,0,14545),
(@CGUID+07,31177,571,1,1,0,1,6773.87,1442.68,390.796,2.98451,300,0,0,14545),
(@CGUID+08,31177,571,1,1,0,1,6774.66,1438.52,390.796,2.04204,300,0,0,14545),
(@CGUID+09,31177,571,1,1,0,1,6776.75,1441.69,390.796,0,300,0,0,14545),
(@CGUID+10,31177,571,1,1,0,1,6772.37,1437.48,390.796,1.46608,300,0,0,14545),
(@CGUID+11,31177,571,1,1,0,1,6774.28,1439.56,390.796,4.34587,300,0,0,14545),
(@CGUID+12,31177,571,1,1,0,1,6773.09,1440.07,390.796,3.42085,300,0,0,14545),
(@CGUID+13,31177,571,1,1,0,1,6556.9,996.463,280.699,6.19592,300,0,0,14545),
(@CGUID+14,31177,571,1,1,0,1,6751.21,1191.47,275.671,3.24631,300,0,0,14545),
(@CGUID+15,31177,571,1,1,0,1,6578.72,1218.41,281.011,5.044,300,0,0,14545),
(@CGUID+16,31177,571,1,1,0,1,6507.78,1206.2,282.821,3.97935,300,0,0,14545),
(@CGUID+17,31177,571,1,1,0,1,6818.68,1181.63,278.63,5.21853,300,0,0,14545),
(@CGUID+18,31177,571,1,1,0,1,6779.05,1078.05,286.088,1.78024,300,0,0,14545),
(@CGUID+19,31177,571,1,1,0,1,6837.51,1034.99,300.817,1.8326,300,0,0,14545),
(@CGUID+20,31177,571,1,1,0,1,6790.64,1042.12,293.713,0.959931,300,0,0,14545);
-- For some reason they used models from 31304
UPDATE `creature` SET `modelid` = 0 WHERE `id` = 31177;
UPDATE `creature` SET `VerifiedBuild` = 14545 WHERE `guid` NOT IN (124174,124171) AND `id` = 31177;

DELETE FROM `creature_addon` WHERE `guid` IN (124173,124153,124164,124175,124172,124155,124159,124183,124181,124167,124179,124178,124163,124185,124152,124176);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(124173,0,0,50331648,1,0,0,"58768"),
(124153,0,0,50331648,1,0,0,"58768"),
(124164,0,0,50331648,1,0,0,"58806"),
(124175,0,0,50331648,1,0,0,"58806"),
(124172,0,0,50331648,1,0,0,"58768"),
(124155,0,0,50331648,1,0,0,"58768"),
(124159,0,0,50331648,1,0,0,"58768"),
(124183,0,0,50331648,1,0,0,"58806"),
(124181,0,0,50331648,1,0,0,"58806"),
(124167,0,0,50331648,1,0,0,"58768"),
(124179,0,0,50331648,1,0,0,"58768"),
(124178,0,0,50331648,1,0,0,"58768"),
(124163,0,0,50331648,1,0,0,"58768"),
(124185,0,0,50331648,1,0,0,"58768"),
(124152,0,0,50331648,1,0,0,"58806"),
(124176,0,0,50331648,1,0,0,"58806");
