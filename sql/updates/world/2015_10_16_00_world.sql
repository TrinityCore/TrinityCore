--
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (87678,87679,87680,87681,87682,87683,87684,87690,87698,87702,87704,87705,87707,87710,87712,87714,87715,87716,87719,87721,87725,87728,87730,87731,87732,87733,87734,87738,87739,87740,87747,87749,87750,87751,87756,87762,87764,87765,87767,87769,87772,87774,87777,87778,87779,87791,87793,87794,87795,87797,87799,87800,87801,87802,87803,87807,87816,87818,87820,87822,87824,87826,87828,87829);
INSERT INTO `creature_addon` (`guid`,`emote`) (SELECT `guid`, 28 FROM `creature` WHERE `id`=15300 AND `MovementType`=0);

-- Fixing position of some AQ40 spawns
DELETE FROM `creature` WHERE `guid` IN (87561,87562,87563,4458,87559,87560,88073,88076,88077,88072);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(87561, 15378, 531, 1, 1, -8652.15, 2020.907, 108.6608, 4.014257, 7200, 0, 0), -- Merithra of the Dream
(87562, 15379, 531, 1, 1, -8660.591, 2022.339, 108.6608, 4.031711, 7200, 0, 0), -- Caelestrasz
(87563, 15380, 531, 1, 1, -8663.463, 2029.885, 108.6608, 4.310963, 7200, 0, 0), -- Arygos
(4458, 15896, 531, 1, 1, -8578.104, 1986.944, 100.3037, 2.303835, 7200, 0, 0), -- C'Thun Portal
(87559, 15727, 531, 1, 1, -8578.648, 1985.847, 100.3037, 3.490659, 7200, 0, 0), -- C'Thun
(87560, 15589, 531, 1, 1, -8578.792, 1986.183, 100.3037, 3.508112, 7200, 0, 0), -- Eye of C'Thun
(88073, 15957, 531, 1, 1, -9173.091, 2107.334, -65.08635 ,1.430085, 7200, 5, 1), -- Ouro should be Ouro Spawner
(88076, 15275, 531, 1, 1, -9023.666, 1176.24, -104.226, 0.7679449, 7200, 0, 0), -- Emperor Vek'nilash
(88077, 15276, 531, 1, 1, -8868.309, 1205.966, -104.2311, 2.70526, 7200, 0, 0), -- Emperor Vek'lor
(88072, 15963, 531, 1, 1, -8953.297, 1233.641, -99.71796, 5.305801, 7200, 0, 0); -- The Master's Eye
-- Ouro Spawner should spawn Ouro "BOSS" on aggro and despawn self.
 
DELETE FROM `creature_template_addon` WHERE `entry` IN (15589,15957,15963);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(15589,0,1,0, '18950'),(15957,0,1,0, '26092'),(15963,0,1,0, '18430');
 
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry` IN (15963);
