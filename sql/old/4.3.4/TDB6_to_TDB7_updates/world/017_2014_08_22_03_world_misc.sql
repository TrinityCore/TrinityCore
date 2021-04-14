SET @CGUID :=    29974;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
DELETE FROM `creature_addon` WHERE `guid` IN (118456,118301,118183,117164);
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+0, 0, 0x10000, 0x1, '49415'), -- 27102 - 49415
(@CGUID+1, 0, 0x10000, 0x101, '49415'), -- 26839 - 49415
(@CGUID+2, 0, 0x10000, 0x101, '49415'), -- 26839 - 49415

(118456, 0, 0x10000, 0x1, '49414'), -- 26863 - 49414
(118301, 0, 0x10000, 0x101, '49414'), -- 26862 - 49414
(118183, 0, 0x10000, 0x1, '49414'), -- 26860 - 49414
(117164, 0, 0x10000, 0x1, '49414'); -- 27102 - 49414

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 27102, 571, 1, 1, 3270.905, -2197.24, 117.4559, 4.101524, 120, 0, 0), -- 27102 (Area: 394)
(@CGUID+1, 26839, 571, 1, 1, 3268.641, -2195.643, 117.4559, 4.34587, 120, 0, 0), -- 26839 (Area: 394)
(@CGUID+2, 26839, 571, 1, 1, 3273.251, -2197.424, 117.4559, 4.066617, 120, 0, 0); -- 26839 (Area: 394)

DELETE FROM `spell_area` WHERE `spell` IN(49417,49416) AND `area`=4206;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES 
(49417,4206, 12431, 0, 0, 0, 2, 1, 64, 11),
(49416,4206, 0, 12431, 0, 0, 2, 1, 64, 11);
