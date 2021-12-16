-- Respawn Gauntlet area
SET @CGUID := 147107; -- 46

DELETE FROM `linked_respawn` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (25373,25483,25484,25486,25506,25837,25848));
DELETE FROM `creature` WHERE `id` IN (25373,25483,25484,25486,25506,25837,25848);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+00 AND @CGUID+45;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID+00,25373,580,0,0,1,1,0,1,1560.38,561.653,50.6551,4.99164,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+01,25373,580,0,0,1,1,0,1,1602.27,576.492,83.0067,5.14161,604800,0,0,140728,0,2,0,0,0,"",15354),
(@CGUID+02,25373,580,0,0,1,1,0,1,1659.8,505.172,50.5755,4.28742,604800,0,0,140728,0,2,0,0,0,"",15354),
(@CGUID+03,25373,580,0,0,1,1,0,1,1681.45,513.118,85.3565,4.97419,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+04,25373,580,0,0,1,1,0,1,1688.99,510.253,85.3565,3.735,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+05,25373,580,0,0,1,1,0,1,1705.7,509.507,85.3565,5.88176,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+06,25373,580,0,0,1,1,0,1,1712.09,513.983,85.3565,5.16617,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+07,25483,580,0,0,1,1,0,1,1573.49,532.99,36.5959,5.63741,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+08,25483,580,0,0,1,1,0,1,1595.91,580.53,85.021,5.35816,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+09,25483,580,0,0,1,1,0,1,1652.19,508.852,50.6588,2.79253,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+10,25483,580,0,0,1,1,0,1,1673.78,546.548,85.2338,2.16421,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+11,25483,580,0,0,1,1,0,1,1770.92,574.367,85.2662,2.9147,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+12,25483,580,0,0,1,1,0,1,1785.86,560.699,56.9858,3.98604,604800,0,0,140728,0,2,0,0,0,"",15354),
(@CGUID+13,25483,580,0,0,1,1,0,1,1817.55,593.429,50.8023,4.04916,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+14,25484,580,0,0,1,1,0,1,1598.08,572.836,50.6588,4.49742,604800,5,0,175934,0,1,0,0,0,"",15354), -- default
(@CGUID+15,25484,580,0,0,1,1,0,1,1609.73,598.006,84.9956,0.123412,604800,0,0,175934,0,0,0,0,0,"",15354), -- aggro pos
(@CGUID+16,25484,580,0,0,1,1,0,1,1613.45,590.271,84.9329,4.89668,604800,0,0,175934,0,0,0,0,0,"",15354), -- aggro pos
(@CGUID+17,25484,580,0,0,1,1,0,1,1767.51,567.411,85.2846,2.530727,604800,0,0,175934,0,0,0,0,0,"",15354), -- default
(@CGUID+18,25484,580,0,0,1,1,0,1,1792.09,568.5,53.796,4.26668,604800,0,0,175934,0,0,0,0,0,"",15354), -- aggro pos
(@CGUID+19,25486,580,0,0,1,1,0,1,1575.04,526.229,33.0523,5.53269,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+20,25486,580,0,0,1,1,0,1,1586.09,532.133,32.5025,5.06145,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+21,25486,580,0,0,1,1,0,1,1595.83,574.954,83.8008,4.97419,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+22,25486,580,0,0,1,1,0,1,1605.55,577.98,83.056,4.69494,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+23,25486,580,0,0,1,1,0,1,1642.62,500.648,50.6588,2.58309,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+24,25486,580,0,0,1,1,0,1,1646.26,512.54,50.6588,2.98451,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+25,25486,580,0,0,1,1,0,1,1668.67,547.475,85.2455,2.40855,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+26,25486,580,0,0,1,1,0,1,1685.17,555.067,85.1755,2.21657,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+27,25486,580,0,0,1,1,0,1,1752.69,574.163,85.1591,5.67232,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+28,25486,580,0,0,1,1,0,1,1762.07,562.63,85.2814,2.33874,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+29,25486,580,0,0,1,1,0,1,1793.91,593.621,50.7982,5.51524,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+30,25486,580,0,0,1,1,0,1,1812.62,586.042,50.7989,3.71755,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+31,25506,580,0,0,1,1,0,1,1578.72,536.317,36.5785,5.46288,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+32,25506,580,0,0,1,1,0,1,1602.72,582.55,85.0094,5.14872,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+33,25506,580,0,0,1,1,0,1,1648.74,501.291,50.6588,2.51327,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+34,25506,580,0,0,1,1,0,1,1684.76,548.52,85.2384,2.19911,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+35,25506,580,0,0,1,1,0,1,1759.42,579.986,85.1691,5.68977,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+36,25506,580,0,0,1,1,0,1,1782.86,563.353,56.9448,3.98603,604800,0,0,140728,0,0,0,0,0,"",15354),
(@CGUID+37,25837,580,0,0,1,1,0,1,1682.33,537.624,85.3339,2.07694,604800,0,0,175934,0,0,0,0,0,"",15354),
(@CGUID+38,25837,580,0,0,1,1,0,1,1754.95,567.301,85.1341,0.759888,604800,0,0,175934,0,2,0,0,0,"",15354),
(@CGUID+39,25848,580,0,0,1,1,0,0,1589.51,514.924,33.225,2.16421,604800,0,0,3827,0,0,0,0,0,"",15354),
(@CGUID+40,25848,580,0,0,1,1,0,0,1680.38,542.687,85.2705,2.00713,604800,0,0,3827,0,0,0,0,0,"",15354),
(@CGUID+41,25848,580,0,0,1,1,0,0,1684.98,507.977,88.1204,1.15192,604800,0,0,3827,0,0,0,0,0,"",15354),
(@CGUID+42,25848,580,0,0,1,1,0,0,1697.92,502.315,86.4882,1.65806,604800,0,0,3827,0,0,0,0,0,"",15354),
(@CGUID+43,25848,580,0,0,1,1,0,0,1698.09,502.24,86.492,1.5708,604800,0,0,3827,0,0,0,0,0,"",15354),
(@CGUID+44,25848,580,0,0,1,1,0,0,1698.2,501.53,95.8557,1.78024,604800,0,0,3827,0,0,0,0,0,"",15354),
(@CGUID+45,25848,580,0,0,1,1,0,0,1709.35,510.243,90.9538,2.93215,604800,0,0,3827,0,0,0,0,0,"",15354);

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+11,@CGUID+35,@CGUID+01,@CGUID+02,@CGUID+38,@CGUID+12);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+11,0,0,1,1,0,0,"45769 46744"),
(@CGUID+35,0,0,1,1,0,0,"45769"),
(@CGUID+01,(@CGUID+01)*10,0,0,1,0,0,"45769"),
(@CGUID+02,(@CGUID+02)*10,0,0,1,0,0,"45769"),
(@CGUID+38,(@CGUID+38)*10,0,0,1,0,0,"45769"),
(@CGUID+12,(@CGUID+12)*10,0,0,1,0,0,"45769 46744");

DELETE FROM `waypoint_data` WHERE `id` IN ((@CGUID+01)*10,(@CGUID+02)*10,(@CGUID+38)*10,(@CGUID+12)*10);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
((@CGUID+01)*10,1,1614.62,557.94464,72.18295,0,0,0,0,0,0),
((@CGUID+01)*10,2,1630.1543,541.5376,62.27385,0,0,0,0,0,0),
((@CGUID+01)*10,3,1648.82,527.84894,52.866714,0,0,0,0,0,0),
((@CGUID+01)*10,4,1630.1543,541.5376,62.27385,0,0,0,0,0,0),
((@CGUID+01)*10,5,1614.62,557.94464,72.18295,0,0,0,0,0,0),
((@CGUID+01)*10,6,1604.4705,571.67554,80.42003,0,0,0,0,0,0),
((@CGUID+01)*10,7,1598.7472,584.1803,84.96414,0,0,0,0,0,0),
((@CGUID+01)*10,8,1594.0377,597.88556,85.12552,0,0,0,0,0,0),
((@CGUID+01)*10,9,1598.7472,584.1803,84.96414,0,0,0,0,0,0),
((@CGUID+01)*10,10,1604.4705,571.67554,80.42003,0,0,0,0,0,0),
((@CGUID+02)*10,1,1660.8033,507.39877,50.57551,0,0,0,0,0,0),
((@CGUID+02)*10,2,1662.8678,524.444,50.5755,0,0,0,0,0,0),
((@CGUID+02)*10,3,1660.8033,507.39877,50.57551,0,0,0,0,0,0),
((@CGUID+02)*10,4,1655.2913,495.21875,50.575504,0,0,0,0,0,0),
((@CGUID+38)*10,1,1764.0201,578.5973,85.12091,0,0,0,0,0,0),
((@CGUID+38)*10,2,1758.3895,570.56714,85.129524,0,0,0,0,0,0),
((@CGUID+38)*10,3,1752.3616,564.8392,85.134415,0,0,0,0,0,0),
((@CGUID+38)*10,4,1758.3895,570.56714,85.129524,0,0,0,0,0,0),
((@CGUID+12)*10,20,1781.791,556.1232,59.4439,0,0,0,0,0,0),
((@CGUID+12)*10,19,1792.061,567.6834,53.97069,0,0,0,0,0,0),
((@CGUID+12)*10,18,1781.791,556.1232,59.4439,0,0,0,0,0,0),
((@CGUID+12)*10,17,1772.609,545.9611,62.09303,0,0,0,0,0,0),
((@CGUID+12)*10,16,1774.792,537.0277,62.09303,0,0,0,0,0,0),
((@CGUID+12)*10,15,1783.75,522.1627,69.59276,0,0,0,0,0,0),
((@CGUID+12)*10,14,1790.207,509.9032,74.16136,0,0,0,0,0,0),
((@CGUID+12)*10,13,1782.676,498.8569,74.14127,0,0,0,0,0,0),
((@CGUID+12)*10,12,1770.5,498.5753,74.15498,0,0,0,0,0,0),
((@CGUID+12)*10,11,1761.895,511.8103,80.35925,0,0,0,0,0,0),
((@CGUID+12)*10,10,1756.622,520.4323,85.27325,0,0,0,0,0,0),
((@CGUID+12)*10,9,1747.67,535.4413,85.28307,0,0,0,0,0,0),
((@CGUID+12)*10,8,1756.622,520.4323,85.27325,0,0,0,0,0,0),
((@CGUID+12)*10,7,1761.89,511.810,80.35925,0,0,0,0,0,0),
((@CGUID+12)*10,6,1770.5,498.5753,74.15498,0,0,0,0,0,0),
((@CGUID+12)*10,5,1782.676,498.8569,74.14127,0,0,0,0,0,0),
((@CGUID+12)*10,4,1790.207,509.9032,74.16136,0,0,0,0,0,0),
((@CGUID+12)*10,3,1783.75,522.1627,69.59276,0,0,0,0,0,0),
((@CGUID+12)*10,2,1774.792,537.0277,62.09303,0,0,0,0,0,0),
((@CGUID+12)*10,1,1772.609,545.9611,62.09303,0,0,0,0,0,0);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@CGUID+12);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+12,@CGUID+12,0,0,515,0,0),
(@CGUID+12,@CGUID+36,4,90,515,0,0);

INSERT INTO `linked_respawn` (`linkedGuid`,`linkType`,`guid`) SELECT 53668, 0, `guid` FROM `creature` WHERE `id` IN (25373,25483,25484,25486,25506,25837,25848);

UPDATE `creature_template_addon` SET `auras` = "45769 46744" WHERE `entry` = 25483;
UPDATE `creature_template_addon` SET `auras` = "45769 16380" WHERE `entry` = 25484;
UPDATE `creature_template_addon` SET `auras` = "45769 18950" WHERE `entry` = 25486;

-- Volatile Fiend
UPDATE `creature` SET `wander_distance` = 10, `MovementType` = 1 WHERE `id` = 25851;
UPDATE `creature` SET `wander_distance` = 5, `MovementType` = 1 WHERE `guid` IN (47607,47313,47471,47768,47608,47769) AND `id` = 25851;
UPDATE `creature` SET `wander_distance` = 3, `MovementType` = 1 WHERE `guid` IN (47470,47475,47578,47875,47884,47897) AND `id` = 25851;

-- Stats, auras, models
UPDATE `creature_template_addon` SET `bytes1` = 0 WHERE `entry` = 24895; -- Madrigosa
UPDATE `creature_template_addon` SET `auras` = "45455" WHERE `entry` = 25165; -- Lady Sacrolash
UPDATE `creature_template_addon` SET `auras` = "45457" WHERE `entry` = 25166; -- Grand Warlock Alythess
UPDATE `creature_template_addon` SET `auras` = "45263" WHERE `entry` = 25214; -- Shadow Image
UPDATE `creature_template_addon` SET `auras` = "45769 46267" WHERE `entry` = 25509; -- Priestess of Torment
DELETE FROM `creature_template_addon` WHERE `entry` = 25591;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES
(25591,"45769 46277"); -- Painbringer
UPDATE `creature_template_addon` SET `auras` = "45769 31722" WHERE `entry` = 25592; -- Doomfire Destroyer
UPDATE `creature_template_addon` SET `auras` = "46367" WHERE `entry` = 26046; -- Anveena

UPDATE `creature_model_info` SET `BoundingRadius` = 0.8, `CombatReach` = 1.6 WHERE `DisplayID` = 23830;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.30236202, `CombatReach` = 0.85 WHERE `DisplayID` = 23178;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.6, `CombatReach` = 3 WHERE `DisplayID` = 23475;
UPDATE `creature_model_info` SET `BoundingRadius` = 1, `CombatReach` = 1 WHERE `DisplayID` = 18996;
UPDATE `creature_model_info` SET `BoundingRadius` = 2, `CombatReach` = 2 WHERE `DisplayID` = 23422;
UPDATE `creature_model_info` SET `BoundingRadius` = 1.275, `CombatReach` = 2.55 WHERE `DisplayID` = 13971;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.459, `CombatReach` = 2.25 WHERE `DisplayID` = 18069;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.435, `CombatReach` = 2.175 WHERE `DisplayID` = 23225;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.435, `CombatReach` = 2.175 WHERE `DisplayID` = 23226;
UPDATE `creature_model_info` SET `BoundingRadius` = 1, `CombatReach` = 2 WHERE `DisplayID` = 23749;
UPDATE `creature_model_info` SET `BoundingRadius` = 0.57449996, `CombatReach` = 2.25 WHERE `DisplayID` = 23750;
UPDATE `creature_model_info` SET `BoundingRadius` = 2, `CombatReach` = 4 WHERE `DisplayID` = 23748;

-- Brutallus & Kil'jaeden flags cannot be applied without intro events
-- 25319 gossip flag only in outro
-- 25744 non-selectable only after spell casts, removed
-- 25357, 25948 still requires checks, no sniffs

-- Levels of some cosmetic & trigger creatures are different from sniffs (434), after checking CreatureDifficuly
-- turned out MinLevel is new level and MaxLevel is old level (instance was partially sniffed in TBC)
-- Quite possible new levels are valid for 335, hard to be sure
UPDATE `creature_template` SET `speed_walk` = 1, `speed_run` = 1.14286 WHERE `entry` = 19871; -- World Trigger (Not Immune NPC)
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 24844; -- Kalecgos
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.71429 WHERE `entry` = 24850; -- Kalecgos
UPDATE `creature_template` SET `speed_walk` = 2.8, `speed_run` = 2.85714 WHERE `entry` = 24882; -- Brutallus
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.71429 WHERE `entry` = 24891; -- Kalecgos
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.71429 WHERE `entry` = 24892; -- Sathrovarr the Corruptor
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 2.85714, `unit_flags` = 33600 WHERE `entry` = 24895; -- Madrigosa
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 2.85714, `unit_flags` = 32832 WHERE `entry` = 25038; -- Felmyst
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.71429, `unit_flags` = 32832 WHERE `entry` = 25165; -- Lady Sacrolash
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.71429, `unit_flags` = 32832 WHERE `entry` = 25166; -- Grand Warlock Alythess
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `unit_flags` = 33587200 WHERE `entry` = 25214; -- Shadow Image
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.71429, `BaseAttackTime` = 3000 WHERE `entry` = 25315; -- Kil'jaeden
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.71429, `unit_flags` = 32832 WHERE `entry` = 25319; -- Kalecgos
UPDATE `creature_template` SET `speed_run` = 0.992063 WHERE `entry` = 25358; -- Felmyst Flight Target - Right
UPDATE `creature_template` SET `speed_run` = 1.42857 WHERE `entry` = 25363; -- Sunblade Cabalist
UPDATE `creature_template` SET `speed_run` = 1.42857 WHERE `entry` = 25367; -- Sunblade Arch Mage
UPDATE `creature_template` SET `speed_run` = 1.42857 WHERE `entry` = 25368; -- Sunblade Slayer
UPDATE `creature_template` SET `speed_run` = 1.42857 WHERE `entry` = 25369; -- Sunblade Vindicator
UPDATE `creature_template` SET `speed_run` = 1.42857 WHERE `entry` = 25370; -- Sunblade Dusk Priest
UPDATE `creature_template` SET `speed_run` = 1.42857 WHERE `entry` = 25371; -- Sunblade Dawn Priest
UPDATE `creature_template` SET `speed_run` = 1.42857 WHERE `entry` = 25372; -- Sunblade Scout
UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 2.85714, `unit_flags` = 32832 WHERE `entry` = 25373; -- Shadowsword Soulbinder
UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 2.71429, `unit_flags` = 32832 WHERE `entry` = 25483; -- Shadowsword Manafiend
UPDATE `creature_template` SET `speed_walk` = 3.2, `speed_run` = 2.71429, `unit_flags` = 32832 WHERE `entry` = 25484; -- Shadowsword Assassin
UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 2.28571, `unit_flags` = 32832 WHERE `entry` = 25485; -- Shadowsword Deathbringer
UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 2.85714, `unit_flags` = 32832 WHERE `entry` = 25486; -- Shadowsword Vanquisher
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 0.571429, `unit_flags2` = 0 WHERE `entry` = 25502; -- Shield Orb
UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 2.71429, `unit_flags` = 32832 WHERE `entry` = 25506; -- Shadowsword Lifeshaper
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857 WHERE `entry` = 25507; -- Sunblade Protector
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857 WHERE `entry` = 25508; -- Shadowsword Guardian
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.71429 WHERE `entry` = 25509; -- Priestess of Torment
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `unit_flags` = 32832 WHERE `entry` = 25588; -- Hand of the Deceiver
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857 WHERE `entry` = 25591; -- Painbringer
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857 WHERE `entry` = 25592; -- Doomfire Destroyer
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857 WHERE `entry` = 25593; -- Apocalypse Guard
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857 WHERE `entry` = 25595; -- Chaos Gazer
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857 WHERE `entry` = 25597; -- Oblivion Mage
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857, `unit_flags` = 32768 WHERE `entry` = 25598; -- Volatile Felfire Fiend
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857 WHERE `entry` = 25599; -- Cataclysm Hound
UPDATE `creature_template` SET `speed_run` = 1, `unit_flags` = 33555200 WHERE `entry` = 25603; -- Felfire Portal
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 25632; -- Vindicator Moorba
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 25638; -- Captain Selana
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 25639; -- Anchorite Elbadon
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` = 25640; -- Orb Target
UPDATE `creature_template` SET `speed_run` = 1, `BaseAttackTime` = 4000, `RangeAttackTime` = 4000, `unit_flags` = 33587200, `unit_flags2` = 0 WHERE `entry` = 25653; -- Power of the Blue Flight
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` = 25703; -- Brutallus Death Cloud
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `unit_flags` = 32832 WHERE `entry` = 25708; -- Sinister Reflection
UPDATE `creature_template` SET `speed_run` = 1 WHERE `entry` = 25741; -- M'uru
UPDATE `creature_template` SET `speed_walk` = 1.2, `speed_run` = 1.42857, `unit_flags` = 0, `unit_flags2` = 0 WHERE `entry` = 25744; -- Dark Fiend
UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 1.42857, `BaseAttackTime` = 1500, `unit_flags` = 32832 WHERE `entry` = 25798; -- Shadowsword Berserker
UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 1.42857, `unit_flags` = 32832 WHERE `entry` = 25799; -- Shadowsword Fury Mage
UPDATE `creature_template` SET `speed_walk` = 0.88888, `speed_run` = 1.42857, `unit_flags` = 32832 WHERE `entry` = 25837; -- Shadowsword Commander
UPDATE `creature_template` SET `speed_run` = 1.42857, `BaseAttackTime` = 1500 WHERE `entry` = 25840; -- Entropius
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` = 25848; -- Gauntlet Imp Trigger
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857 WHERE `entry` = 25851; -- Volatile Fiend
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 0.714286 WHERE `entry` = 25855; -- Singularity
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.42857 WHERE `entry` = 25867; -- Sunblade Dragonhawk
UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` = 25879; -- Darkness
UPDATE `creature_template` SET `speed_walk` = 1.6, `speed_run` = 1.71429, `unit_flags` = 33554432 WHERE `entry` = 26046; -- Anveena
UPDATE `creature_template` SET `speed_walk` = 2.4, `speed_run` = 1.42857 WHERE `entry` = 26101; -- Fire Fiend
UPDATE `creature_template` SET `unit_flags` = 33600 WHERE `entry` = 26246; -- Prophet Velen
UPDATE `creature_template` SET `speed_run` = 2.28571, `unit_flags` = 832 WHERE `entry` = 26247; -- Lady Liadrin
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` = 26251; -- Shattrath Portal Dummy
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` = 26254; -- Inert Portal
UPDATE `creature_template` SET `unit_flags` = 33536 WHERE `entry` = 26259; -- Shattered Sun Soldier
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE `entry` = 26262; -- The Core of Entropius
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = 26289; -- Shattered Sun Riftwaker
