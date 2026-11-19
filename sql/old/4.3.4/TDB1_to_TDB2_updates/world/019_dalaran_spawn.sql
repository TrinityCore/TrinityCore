DELETE FROM `gameobject` WHERE `guid` IN (56658, 56733, 56600, 56586, 56552, 56465, 56485, 56712);

SET @CGUID := 269;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+19;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 50148, 571, 1, 1, 5916.846, 579.3958, 639.6555, 0.122173, 120, 0, 0), -- Matron Ossela (Area: Sunreaver's Sanctuary)
(@CGUID+1, 50142, 571, 1, 1, 5920.592, 580.3368, 639.6818, 3.316126, 120, 0, 0), -- Summoner Calwen (Area: Sunreaver's Sanctuary)
(@CGUID+2, 50147, 571, 1, 1, 5917.088, 571.8577, 639.699, 6.161012, 120, 0, 0), -- Pathstalker Rislar (Area: Sunreaver's Sanctuary)
(@CGUID+3, 49750, 571, 1, 1, 5910.911, 565.941, 639.6708, 3.612832, 120, 0, 0), -- Warchief's Herald (Area: Sunreaver's Sanctuary)
(@CGUID+4, 50152, 571, 1, 1, 5931.917, 576.9219, 639.6932, 5.270895, 120, 0, 0), -- Hahna Moonscrest (Area: Sunreaver's Sanctuary)
(@CGUID+5, 50153, 571, 1, 1, 5934.002, 573.7483, 639.692, 2.146755, 120, 0, 0), -- Murgha the Tempered (Area: Sunreaver's Sanctuary)
(@CGUID+6, 50144, 571, 1, 1, 5927.223, 561.1163, 639.7015, 6.108652, 120, 0, 0), -- Ranger Eoss (Area: Sunreaver's Sanctuary)
(@CGUID+7, 50149, 571, 1, 1, 5931.623, 562.1285, 639.687, 3.752458, 120, 0, 0), -- Vinsun (Area: Sunreaver's Sanctuary)
(@CGUID+8, 50150, 571, 1, 1, 5930.111, 558.8976, 639.6744, 1.832596, 120, 0, 0), -- Nelur Lightsown (Area: Sunreaver's Sanctuary)
(@CGUID+9, 50174, 571, 1, 1, 5704.895, 738.618, 641.918, 0.5235988, 120, 0, 0), -- Farseer Lopaa (Area: Dalaran City)
(@CGUID+10, 50171, 571, 1, 1, 5707.502, 742.0452, 641.8522, 4.45059, 120, 0, 0), -- Muran Fairden (Area: Dalaran City)
(@CGUID+11, 54653, 571, 1, 1, 5753.739, 585.4135, 615.0519, 0, 120, 0, 0), -- Nargle Lashcord (Area: Dalaran City)
(@CGUID+12, 50158, 571, 1, 1, 5706.293, 733.3177, 641.8743, 5.654867, 120, 0, 0), -- Pathstalker Ralsir (Area: Dalaran City)
(@CGUID+13, 50163, 571, 1, 1, 5708.2, 738.8195, 641.8839, 2.478368, 120, 0, 0), -- Matron Alesso (Area: Dalaran City)
(@CGUID+14, 50156, 571, 1, 1, 5708.964, 731.1302, 641.8698, 2.373648, 120, 0, 0), -- Summoner Nolric (Area: Dalaran City)
(@CGUID+15, 49748, 571, 1, 1, 5719.837, 742.6077, 641.8522, 5.532694, 120, 0, 0), -- Hero's Herald (Area: Dalaran City)
(@CGUID+16, 50157, 571, 1, 1, 5712.683, 728.2379, 641.8168, 6.161012, 120, 0, 0), -- Ranger Selone (Area: Dalaran City)
(@CGUID+17, 50160, 571, 1, 1, 5715.683, 725.7379, 641.7135, 1.884956, 120, 0, 0), -- Rulen Lightsreap (Area: Dalaran City)
(@CGUID+18, 50155, 571, 1, 1, 5716.308, 729.7795, 641.775, 4.066617, 120, 0, 0), -- Naseev (Area: Dalaran City)
(@CGUID+19, 47579, 571, 1, 1, 5855.3, 651.028, 647.5953, 0, 120, 0, 0); -- Dariness the Learned (Area: Dalaran Island)

SET @OGUID := 80;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 202443, 571, 1, 1, 5804.526, 638.5417, 647.6481, 2.460913, 0, 0, 0, 1, 120, 255, 1), -- Dedication of Honor (Area: Forlorn Woods)
(@OGUID+1, 208316, 571, 1, 1, 5717.018, 742.0972, 641.7689, 5.602507, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+2, 208317, 571, 1, 1, 5914.641, 564.4184, 639.2689, 3.665196, 0, 0, 0, 1, 120, 255, 1); -- -Unknown- (Area: 0)
