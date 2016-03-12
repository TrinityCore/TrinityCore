-- AQ20 Summon Enabler Stalkers **** 434 & 6XX only ****
SET @CGUID := 250142;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 53488, 509, 1, 1, -8427.401, 1543.568, 32.65972, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+1, 53488, 509, 1, 1, -8443.738, 1521.17, 31.99033, 0.3316126, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+2, 53488, 509, 1, 1, -8453.188, 1496.908, 32.49519, 0.5759587, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+3, 53488, 509, 1, 1, -8457.667, 1552.467, 31.99035, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+4, 53488, 509, 1, 1, -8477.679, 1523.717, 31.99035, 0, 7200, 0, 0); -- Summon Enabler Stalker
DELETE FROM `creature_template_addon` WHERE `entry` IN (53488);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (53488,0,1,0, '99201');

-- AQ40 Summon Enabler Stalkers **** 434 & 6XX only ****
SET @CGUID := 250147;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 53488, 531, 1, 1, -8206.741, 2011.095, 129.985, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+1, 53488, 531, 1, 1, -8216.75, 2055.684, 130.3047, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+2, 53488, 531, 1, 1, -8191.83, 2039.389, 131.013, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+3, 53488, 531, 1, 1, -8228.645, 2026.089, 129.8517, 0, 7200, 0, 0); -- Summon Enabler Stalker

-- Fixing position of some AQ40 spawns
DELETE FROM `creature` WHERE `guid` IN (87561,87562,87563,4458,87559,87560,88073,88076,88077,88072);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(87561, 15378, 531, 1, 1, 169, -8652.15, 2020.907, 108.6608, 4.014257, 7200, 0, 0), -- Merithra of the Dream
(87562, 15379, 531, 1, 1, 169, -8660.591, 2022.339, 108.6608, 4.031711, 7200, 0, 0), -- Caelestrasz
(87563, 15380, 531, 1, 1, 169, -8663.463, 2029.885, 108.6608, 4.310963, 7200, 0, 0), -- Arygos
(4458, 15896, 531, 1, 1, 169, -8578.104, 1986.944, 100.3037, 2.303835, 7200, 0, 0), -- C'Thun Portal
(87559, 15727, 531, 1, 1, 169, -8578.648, 1985.847, 100.3037, 3.490659, 7200, 0, 0), -- C'Thun
(87560, 15589, 531, 1, 1, 169, -8578.792, 1986.183, 100.3037, 3.508112, 7200, 0, 0), -- Eye of C'Thun
(88073, 15957, 531, 1, 1, 169, -9173.091, 2107.334, -65.08635 ,1.430085, 7200, 5, 1), -- Ouro should be Ouro Spawner
(88076, 15275, 531, 1, 1, 169, -9023.666, 1176.24, -104.226, 0.7679449, 7200, 0, 0), -- Emperor Vek'nilash
(88077, 15276, 531, 1, 1, 169, -8868.309, 1205.966, -104.2311, 2.70526, 7200, 0, 0), -- Emperor Vek'lor
(88072, 15963, 531, 1, 1, 169, -8953.297, 1233.641, -99.71796, 5.305801, 7200, 0, 0); -- The Master's Eye
-- Ouro Spawner should spawn Ouro "BOSS" on aggro and despawn self.

DELETE FROM `creature_template_addon` WHERE `entry` IN (15589,15957,15963);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(15589,0,1,0, '18950'),(15957,0,1,0, '26092'),(15963,0,1,0, '18430');

UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry` IN (15963);
