SET @CGUID := 10006970;

SET @GGUID := 100161;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+12;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 6491, 2601, 14795, 14800, '0', 0, 0, 0, 0, 3027.7666015625, -2485.7744140625, 361.95977783203125, 1.470984816551208496, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: The Earthenworks - Difficulty: 0)
(@CGUID+1, 6491, 2601, 14795, 14800, '0', 0, 0, 0, 0, 2829.65625, -3133.5244140625, 362.4063720703125, 1.459322810173034667, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: The Earthenworks - Difficulty: 0)
(@CGUID+2, 6491, 2601, 14795, 0, '0', 0, 0, 0, 0, 2439.3837890625, -2896.442626953125, 402.479949951171875, 2.818042993545532226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: The Ringing Deeps - Central - Difficulty: 0)
(@CGUID+3, 6491, 2601, 14795, 14796, '0', 0, 0, 0, 0, 2003.5816650390625, -2803.42529296875, 364.447052001953125, 2.835761547088623046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Gundargaz - Difficulty: 0)
(@CGUID+4, 6491, 2601, 14795, 14797, '0', 0, 0, 0, 0, 2370.71533203125, -2591.960205078125, 373.72955322265625, 5.12450265884399414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Ironhaul Station - Difficulty: 0)
(@CGUID+5, 6491, 2601, 14795, 14822, '0', 0, 0, 0, 0, 1753.907958984375, -3251.73095703125, 326.364044189453125, 3.968767881393432617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Pillarstone Spire - Difficulty: 0)
(@CGUID+6, 6491, 2601, 14795, 14820, '0', 0, 0, 0, 0, 1662.3507080078125, -3930.979248046875, 257.15533447265625, 2.129301786422729492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Shadowvein Point - Difficulty: 0)
(@CGUID+7, 6491, 2601, 14795, 0, '0', 0, 0, 0, 0, 2367.4375, -3727.263916015625, 402.0526123046875, 3.616298198699951171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: The Ringing Deeps - South - Difficulty: 0)
(@CGUID+8, 6491, 2601, 14795, 14816, '0', 0, 0, 0, 0, 1261.857666015625, -4177.69287109375, 224.8875579833984375, 2.932206392288208007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Obsidian Hollow - Difficulty: 0)
(@CGUID+9, 6491, 2601, 14795, 0, '0', 0, 0, 0, 0, 867.8507080078125, -3485.5400390625, 176.82415771484375, 3.787322998046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: The Ringing Deeps - West - Difficulty: 0)
(@CGUID+10, 6491, 2601, 14795, 14811, '0', 0, 0, 0, 0, 703.45660400390625, -2877.73095703125, 116.0552825927734375, 4.510862350463867187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: The Living Grotto - Difficulty: 0)
(@CGUID+11, 6491, 2601, 14795, 14812, '0', 0, 0, 0, 0, 123.0156326293945312, -3989.927001953125, 111.5989456176757812, 1.327016353607177734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186), -- Spirit Healer (Area: Opportunity Point - Difficulty: 0)
(@CGUID+12, 6491, 2601, 14795, 15528, '0', 0, 0, 0, 0, -132.05035400390625, -4863.830078125, -120.925376892089843, 2.37410593032836914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 67186); -- Spirit Healer (Area: Gutterville - Difficulty: 0)

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+12;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 14795, 'The Ringing Deeps - The Hallowfall Gate'),
(@GGUID+1, 14795, 'The Ringing Deeps - North'),
(@GGUID+2, 14795, 'The Ringing Deeps - Central'),
(@GGUID+3, 14795, 'The Ringing Deeps - Gundargaz'),
(@GGUID+4, 14795, 'The Ringing Deeps - Ironhaul Station'),
(@GGUID+5, 14795, 'The Ringing Deeps - Pillarstone Spire'),
(@GGUID+6, 14795, 'The Ringing Deeps - Shadowvein Point'),
(@GGUID+7, 14795, 'The Ringing Deeps - South'),
(@GGUID+8, 14795, 'The Ringing Deeps - Obsidian Hollow'),
(@GGUID+9, 14795, 'The Ringing Deeps - West'),
(@GGUID+10, 14795, 'The Ringing Deeps - The Living Grotto'),
(@GGUID+11, 14795, 'The Ringing Deeps - Opportunity Point'),
(@GGUID+12, 14795, 'The Ringing Deeps - Gutterville');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+12;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2601, 3028.4236, -2481.4358, 360.0422, 4.59609222412109375 / (2 * PI() / 360), 'The Ringing Deeps - The Hallowfall Gate - GY'),
(@GGUID+1, 2601, 2829.68, -3133.37, 362.26, 1.341953992843627929 / (2 * PI() / 360), 'The Ringing Deeps - North - GY'),
(@GGUID+2, 2601, 2439.77, -2896.16, 402.365, 3.500728845596313476 / (2 * PI() / 360), 'The Ringing Deeps - Central - GY'),
(@GGUID+3, 2601, 1999.7916, -2802.1597, 362.92307, 5.938390731811523437 / (2 * PI() / 360), 'The Ringing Deeps - Gundargaz - GY'),
(@GGUID+4, 2601, 2372.6301, -2597.1926, 373.80652, 1.91044628620147705 / (2 * PI() / 360), 'The Ringing Deeps - Ironhaul Station - GY'),
(@GGUID+5, 2601, 1750.6111, -3255.2708, 324.67062, 1.085670113563537597 / (2 * PI() / 360), 'The Ringing Deeps - Pillarstone Spire - GY'),
(@GGUID+6, 2601, 1658.75, -3927.6736, 255.30501, 5.403573036193847656 / (2 * PI() / 360), 'The Ringing Deeps - Shadowvein Point - GY'),
(@GGUID+7, 2601, 2362.5156, -3730.0503, 400.48096, 0.448542356491088867 / (2 * PI() / 360), 'The Ringing Deeps - South - GY'),
(@GGUID+8, 2601, 1257.6129, -4176.4897, 223.08159, 5.924509525299072265 / (2 * PI() / 360), 'The Ringing Deeps - Obsidian Hollow - GY'),
(@GGUID+9, 2601, 865.0625, -3488.2083, 174.96628, 0.60096144676208496 / (2 * PI() / 360), 'The Ringing Deeps - West - GY'),
(@GGUID+10, 2601, 702.2535, -2882.0364, 113.83126, 1.402311444282531738 / (2 * PI() / 360), 'The Ringing Deeps - The Living Grotto - GY'),
(@GGUID+11, 2601, 123.89931, -3986.2344, 109.95682, 4.44544839859008789 / (2 * PI() / 360), 'The Ringing Deeps - Opportunity Point - GY'),
(@GGUID+12, 2601, -132.083, -4863.93, -120.887, 2.254197597503662109 / (2 * PI() / 360), 'The Ringing Deeps - Gutterville - GY');
