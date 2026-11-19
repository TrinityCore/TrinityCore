-- 
-- AQ20 Summon Enabler Stalkers **** 434 & 6XX only ****
SET @CGUID := 250142;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 53488, 509, 1, 169, -8427.401, 1543.568, 32.65972, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+1, 53488, 509, 1, 169, -8443.738, 1521.17, 31.99033, 0.3316126, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+2, 53488, 509, 1, 169, -8453.188, 1496.908, 32.49519, 0.5759587, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+3, 53488, 509, 1, 169, -8457.667, 1552.467, 31.99035, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+4, 53488, 509, 1, 169, -8477.679, 1523.717, 31.99035, 0, 7200, 0, 0); -- Summon Enabler Stalker
DELETE FROM `creature_template_addon` WHERE `entry` IN (53488);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (53488,0,1,0, '99201');

-- AQ40 Summon Enabler Stalkers **** 434 & 6XX only ****
SET @CGUID := 250147;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `PhaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 53488, 531, 1, 169, -8206.741, 2011.095, 129.985, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+1, 53488, 531, 1, 169, -8216.75, 2055.684, 130.3047, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+2, 53488, 531, 1, 169, -8191.83, 2039.389, 131.013, 0, 7200, 0, 0), -- Summon Enabler Stalker
(@CGUID+3, 53488, 531, 1, 169, -8228.645, 2026.089, 129.8517, 0, 7200, 0, 0); -- Summon Enabler Stalker
