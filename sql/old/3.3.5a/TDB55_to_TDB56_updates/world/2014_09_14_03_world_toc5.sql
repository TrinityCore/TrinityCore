SET @CGUID := 143275;
SET @OGUID := 77245;

DELETE FROM `creature` WHERE `map`=650;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+  0, 35644, 650, 3, 1, 702.967, 587.6493, 412.4754, 0.6108652, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+  1, 35644, 650, 3, 1, 774.8976, 573.7361, 412.4752, 2.146755, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+  2, 35644, 650, 3, 1, 787.4393, 584.9688, 412.4759, 2.478368, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+  3, 35644, 650, 3, 1, 712.5938, 576.2604, 412.4758, 0.8901179, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+  4, 35644, 650, 3, 1, 720.5695, 571.2847, 412.4749, 1.064651, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+  5, 36558, 650, 3, 1, 790.1771, 589.059, 412.4753, 2.565634, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+  6, 36558, 650, 3, 1, 716.6649, 573.4948, 412.4753, 0.9773844, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+  7, 36558, 650, 3, 1, 770.4861, 571.5521, 412.4746, 2.059489, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+  8, 36558, 650, 3, 1, 700.5313, 591.9271, 412.4749, 0.5235988, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+  9, 36558, 650, 3, 1, 778.7413, 576.0486, 412.4756, 2.234021, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+ 10, 36558, 650, 3, 1, 705.4965, 583.9445, 412.4759, 0.6981317, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+ 11, 35644, 650, 3, 1, 699.9427, 643.3698, 412.4744, 5.77704, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+ 12, 35644, 650, 3, 1, 790.4896, 646.533, 412.4745, 3.717551, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+ 13, 35644, 650, 3, 1, 777.5643, 660.3004, 412.4669, 4.34587, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+ 14, 35644, 650, 3, 1, 704.9427, 651.3299, 412.4751, 5.602507, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+ 15, 35644, 650, 3, 1, 793.0087, 592.6667, 412.4749, 2.6529, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+ 16, 35644, 650, 3, 1, 768.2552, 661.6059, 412.4703, 4.555309, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+ 17, 35644, 650, 3, 1, 722.3629, 660.7448, 412.4681, 4.834562, 7200, 0, 0), -- Argent Warhorse (Area: Trial of the Champion) (Auras: 67870 - Trample)
(@CGUID+ 18, 35016, 650, 3, 1, 748.8837, 616.4618, 411.1738, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 19, 35016, 650, 3, 1, 782.1198, 583.2101, 412.4743, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 20, 35016, 650, 3, 1, 746.5243, 615.868, 411.1725, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 21, 35016, 650, 3, 1, 747.375, 619.1094, 411.9709, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 22, 35016, 650, 3, 1, 746.9774, 618.7934, 411.9709, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 23, 35016, 650, 3, 1, 697.2847, 618.2535, 412.4758, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 24, 35016, 650, 3, 1, 792.2587, 598.2239, 412.4696, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 25, 35016, 650, 3, 1, 703.8837, 596.6007, 412.4742, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 26, 35016, 650, 3, 1, 714.4861, 581.7222, 412.476, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 27, 22515, 650, 3, 1, 746.9045, 618.2813, 411.1724, 0, 7200, 0, 0), -- World Trigger (Area: Trial of the Champion)
(@CGUID+ 28, 35004, 650, 3, 1, 748.309, 619.4879, 411.1724, 4.712389, 7200, 0, 0), -- Jaeren Sunsworn (Area: Trial of the Champion)
(@CGUID+ 29, 36558, 650, 3, 1, 717.4427, 660.6458, 412.4669, 4.921828, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+ 30, 36558, 650, 3, 1, 702.1649, 647.2674, 412.4749, 5.689773, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+ 31, 36558, 650, 3, 1, 726.8264, 661.2014, 412.4716, 4.660029, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+ 32, 34977, 650, 3, 1, 726.3802, 557.1511, 436.9785, 1.256637, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 33, 35016, 650, 3, 1, 712.4132, 653.9305, 412.4742, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 34, 34970, 650, 3, 1, 757.9983, 559.7309, 435.5007, 1.466077, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 35, 34979, 650, 3, 1, 712.8733, 563.1719, 436.9667, 1.029744, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 36, 34979, 650, 3, 1, 709.5764, 570.1059, 435.5041, 0.9424778, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 37, 35016, 650, 3, 1, 702.2743, 638.7604, 412.4703, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 38, 35016, 650, 3, 1, 795.5486, 618.25, 412.4769, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 39, 35016, 650, 3, 1, 780.4358, 654.4063, 412.4742, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 40, 34975, 650, 3, 1, 767.5816, 560.5399, 435.5033, 1.832596, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 41, 34996, 650, 3, 1, 746.5833, 559.0191, 435.4921, 1.570796, 7200, 0, 0), -- Highlord Tirion Fordring (Area: Trial of the Champion)
(@CGUID+ 42, 35016, 650, 3, 1, 791.9722, 638.0104, 412.4699, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - Generic Bunny (Area: Trial of the Champion)
(@CGUID+ 43, 34859, 650, 3, 1, 688.7309, 604.6893, 435.5013, 0.2094395, 7200, 0, 0), -- Orcish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 44, 34887, 650, 3, 1, 797.1476, 617.7083, 435.4885, 3.106686, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Alliance (Area: Trial of the Champion)
(@CGUID+ 45, 34903, 650, 3, 1, 697.1163, 583.0521, 435.5041, 0.6283185, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Tauren (Area: Trial of the Champion)
(@CGUID+ 46, 34857, 650, 3, 1, 692.8542, 590.632, 435.5041, 0.4712389, 7200, 0, 0), -- Troll Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 47, 34858, 650, 3, 1, 697.2413, 583.8577, 435.5041, 0.6283185, 7200, 0, 0), -- Tauren Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 48, 34857, 650, 3, 1, 689.6233, 598.0452, 435.5031, 0.3316126, 7200, 0, 0), -- Troll Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66371 - Sen'jin Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 49, 34966, 650, 3, 1, 718.9167, 564.0781, 435.5041, 1.117011, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 50, 34975, 650, 3, 1, 775.7483, 564.5851, 435.5041, 2.164208, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 51, 34966, 650, 3, 1, 725.6614, 560.8351, 435.5034, 1.239184, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 52, 34977, 650, 3, 1, 734.4114, 560.158, 435.501, 1.37881, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 53, 36558, 650, 3, 1, 788.0156, 650.7882, 412.4749, 3.804818, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+ 54, 36558, 650, 3, 1, 773.0972, 660.7327, 412.4673, 4.45059, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+ 55, 36558, 650, 3, 1, 793.0521, 642.8507, 412.4742, 3.630285, 7200, 0, 0), -- Argent Battleworg (Area: Trial of the Champion) (Auras: 67865 - Trample)
(@CGUID+ 56, 34994, 650, 3, 1, 686.6632, 614.5608, 435.4849, 6.230825, 7200, 0, 0), -- Thrall (Area: Trial of the Champion)
(@CGUID+ 57, 34977, 650, 3, 1, 730.9983, 552.7188, 438.8121, 1.343904, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 58, 34974, 650, 3, 1, 787.5018, 568.9618, 436.9922, 2.286381, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 59, 34974, 650, 3, 1, 781.3715, 567.4167, 435.5041, 2.408554, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 60, 34995, 650, 3, 1, 686.9358, 622.0295, 435.4867, 6.230825, 7200, 0, 0), -- Garrosh Hellscream (Area: Trial of the Champion)
(@CGUID+ 61, 34856, 650, 3, 1, 801.5677, 591.3837, 435.5041, 2.670354, 7200, 0, 0), -- Dwarven Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66363 - Ironforge Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 62, 34883, 650, 3, 1, 687.8299, 617.6493, 435.4933, 1.58825, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Horde (Area: Trial of the Champion)
(@CGUID+ 63, 34856, 650, 3, 1, 804.0261, 598.4358, 435.503, 2.86234, 7200, 0, 0), -- Dwarven Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 64, 34902, 650, 3, 1, 689.1962, 597, 435.5034, 0.3490658, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Troll (Area: Trial of the Champion)
(@CGUID+ 65, 34901, 650, 3, 1, 687.1597, 618.132, 435.4888, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Orc (Area: Trial of the Champion)
(@CGUID+ 66, 34859, 650, 3, 1, 687.9653, 629.6111, 435.4982, 6.195919, 7200, 0, 0), -- Orcish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66369 - Orgrimmar Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 67, 34906, 650, 3, 1, 803.6215, 594.6302, 435.5041, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Dwarf (Area: Trial of the Champion)
(@CGUID+ 68, 34859, 650, 3, 1, 685.1129, 600.4305, 436.9705, 0.2792527, 7200, 0, 0), -- Orcish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 69, 34868, 650, 3, 1, 798.6945, 587.3577, 435.5041, 2.687807, 7200, 0, 0), -- Draenei Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 70, 34870, 650, 3, 1, 804.4705, 604.8055, 435.5013, 2.844887, 7200, 0, 0), -- Human Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 71, 34858, 650, 3, 1, 696.2604, 577.507, 436.9658, 0.6981317, 7200, 0, 0), -- Tauren Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66370 - Thunder Bluff Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 72, 34868, 650, 3, 1, 793.882, 580.6788, 435.5041, 2.391101, 7200, 0, 0), -- Draenei Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66362 - Exodar Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 73, 34858, 650, 3, 1, 689.6354, 582.8229, 438.8188, 0.5585054, 7200, 0, 0), -- Tauren Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 74, 34970, 650, 3, 1, 764.0799, 553.434, 438.8278, 1.867502, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 75, 34966, 650, 3, 1, 718.4045, 555.9202, 438.8031, 1.151917, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 76, 34979, 650, 3, 1, 714.3403, 553.7083, 440.2231, 1.117011, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 77, 34970, 650, 3, 1, 761.217, 549.1424, 440.2457, 1.58825, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 78, 34977, 650, 3, 1, 733.809, 545.2153, 442.0747, 1.413717, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 79, 34990, 650, 3, 1, 806.3246, 617.9948, 435.4912, 3.124139, 7200, 0, 0), -- King Varian Wrynn (Area: Trial of the Champion)
(@CGUID+ 80, 34992, 650, 3, 1, 806.2239, 614.9393, 435.4874, 3.001966, 7200, 0, 0), -- Lady Jaina Proudmoore (Area: Trial of the Champion)
(@CGUID+ 81, 34975, 650, 3, 1, 773.5018, 555.5156, 438.8247, 1.954769, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 82, 34860, 650, 3, 1, 699.0052, 654.8941, 435.5041, 5.532694, 7200, 0, 0), -- Forsaken Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 83, 34870, 650, 3, 1, 805.0313, 629.7674, 435.5009, 3.385939, 7200, 0, 0), -- Human Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 84, 34905, 650, 3, 1, 696.3594, 653.5868, 435.5041, 5.602507, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Undead (Area: Trial of the Champion)
(@CGUID+ 85, 34904, 650, 3, 1, 690.5955, 642, 435.5041, 5.88176, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Blood Elf (Area: Trial of the Champion)
(@CGUID+ 86, 34869, 650, 3, 1, 806.5208, 644.8802, 436.9614, 3.543018, 7200, 0, 0), -- Gnomish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 87, 34909, 650, 3, 1, 800.1441, 651.7257, 437.002, 3.630285, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Night Elf (Area: Trial of the Champion)
(@CGUID+ 88, 34908, 650, 3, 1, 799.4948, 582.9219, 436.9941, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Draenei (Area: Trial of the Champion)
(@CGUID+ 89, 34900, 650, 3, 1, 813.5729, 618.1268, 438.8528, 3.159046, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Human (Area: Trial of the Champion)
(@CGUID+ 90, 34910, 650, 3, 1, 805.7778, 640.0972, 435.6143, 0, 7200, 0, 0), -- [ph] Argent Raid Spectator - FX - Gnome (Area: Trial of the Champion)
(@CGUID+ 91, 34868, 650, 3, 1, 799.1945, 575.25, 438.801, 2.373648, 7200, 0, 0), -- Draenei Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66362 - Exodar Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 92, 34861, 650, 3, 1, 686.3924, 643.3507, 436.9734, 5.88176, 7200, 0, 0), -- Blood Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 93, 34859, 650, 3, 1, 680.5989, 603.9861, 438.7939, 0.1919862, 7200, 0, 0), -- Orcish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 94, 34860, 650, 3, 1, 693.6354, 654.8924, 436.9629, 5.602507, 7200, 0, 0), -- Forsaken Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 95, 34856, 650, 3, 1, 808.9236, 586.0347, 440.2946, 2.635447, 7200, 0, 0), -- Dwarven Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+ 96, 34856, 650, 3, 1, 814.3316, 597.7813, 440.2612, 2.897247, 7200, 0, 0), -- Dwarven Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66363 - Ironforge Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 97, 34857, 650, 3, 1, 684.9636, 591.0174, 438.8482, 0.418879, 7200, 0, 0), -- Troll Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66371 - Sen'jin Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 98, 34870, 650, 3, 1, 809.1111, 633.1337, 436.9589, 3.420845, 7200, 0, 0), -- Human Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+ 99, 34856, 650, 3, 1, 807.6233, 595.1649, 436.9687, 2.80998, 7200, 0, 0), -- Dwarven Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66363 - Ironforge Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+100, 34868, 650, 3, 1, 800.2813, 582.7483, 436.9739, 2.583087, 7200, 0, 0), -- Draenei Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66362 - Exodar Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+101, 34856, 650, 3, 1, 813.6354, 587.592, 442.0691, 2.70526, 7200, 0, 0), -- Dwarven Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66363 - Ironforge Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+102, 34860, 650, 3, 1, 686.8663, 650.8368, 438.7787, 5.759586, 7200, 0, 0), -- Forsaken Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66365 - Undercity Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+103, 34871, 650, 3, 1, 799.3472, 648.0243, 435.5041, 3.560472, 7200, 0, 0), -- Night Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+104, 34857, 650, 3, 1, 675.2813, 589.9879, 442.0812, 0.3839724, 7200, 0, 0), -- Troll Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+105, 34870, 650, 3, 1, 808.1927, 601.9358, 436.9788, 2.80998, 7200, 0, 0), -- Human Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+106, 34871, 650, 3, 1, 805.4722, 648.7205, 436.9274, 3.508112, 7200, 0, 0), -- Night Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+107, 34868, 650, 3, 1, 806.4879, 574.6146, 442.076, 2.495821, 7200, 0, 0), -- Draenei Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66362 - Exodar Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+108, 34857, 650, 3, 1, 675.1146, 597.7188, 442.0728, 0.2792527, 7200, 0, 0), -- Troll Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+109, 34859, 650, 3, 1, 685.118, 634.4045, 436.9757, 6.091199, 7200, 0, 0), -- Orcish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66369 - Orgrimmar Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+110, 34858, 650, 3, 1, 688.0121, 573.8524, 442.0741, 0.6632251, 7200, 0, 0), -- Tauren Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66370 - Thunder Bluff Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+111, 34861, 650, 3, 1, 692.4063, 644.8698, 435.5041, 5.8294, 7200, 0, 0), -- Blood Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66360 - Silvermoon Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+112, 34859, 650, 3, 1, 677.9861, 634.1024, 440.2452, 6.126106, 7200, 0, 0), -- Orcish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+113, 34869, 650, 3, 1, 803.8958, 639.0643, 435.5034, 3.455752, 7200, 0, 0), -- Gnomish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+114, 34861, 650, 3, 1, 689.4358, 639.2587, 435.5034, 5.951573, 7200, 0, 0), -- Blood Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66360 - Silvermoon Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+115, 34858, 650, 3, 1, 682.8559, 586.1996, 440.2427, 0.4712389, 7200, 0, 0), -- Tauren Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66370 - Thunder Bluff Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+116, 34869, 650, 3, 1, 807.9583, 636.7726, 436.9755, 3.368485, 7200, 0, 0), -- Gnomish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+117, 34871, 650, 3, 1, 795.6719, 653.7396, 435.5041, 3.752458, 7200, 0, 0), -- Night Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66368 - Darnassus Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+118, 34975, 650, 3, 1, 779.9965, 550.6945, 442.0774, 2.059489, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+119, 34974, 650, 3, 1, 783.0695, 561.1771, 438.7979, 2.303835, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+120, 34966, 650, 3, 1, 721.9705, 548.191, 442.0721, 1.239184, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+121, 34970, 650, 3, 1, 769.9514, 547.875, 442.0723, 1.797689, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+122, 34974, 650, 3, 1, 790.6077, 559.2691, 442.0727, 2.408554, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+123, 34979, 650, 3, 1, 700.2726, 559.2239, 442.0803, 0.9250245, 7200, 0, 0), -- Argent Crusade Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+124, 34869, 650, 3, 1, 818.5121, 640.5989, 442.0783, 3.385939, 7200, 0, 0), -- Gnomish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+125, 34870, 650, 3, 1, 818.1632, 607.1302, 440.209, 2.949606, 7200, 0, 0), -- Human Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+126, 34869, 650, 3, 1, 813.5018, 644.8768, 440.2538, 3.490659, 7200, 0, 0), -- Gnomish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+127, 34860, 650, 3, 1, 690.4861, 661.6614, 440.2092, 5.550147, 7200, 0, 0), -- Forsaken Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66365 - Undercity Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+128, 34861, 650, 3, 1, 677.1702, 640.7396, 442.0688, 6.003932, 7200, 0, 0), -- Blood Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura)
(@CGUID+129, 34871, 650, 3, 1, 800.1945, 660.7292, 438.7687, 3.822271, 7200, 0, 0), -- Night Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66368 - Darnassus Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+130, 34870, 650, 3, 1, 818.1337, 626.9636, 440.2178, 3.281219, 7200, 0, 0), -- Human Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+131, 34869, 650, 3, 1, 813.3004, 650.717, 442.0732, 3.490659, 7200, 0, 0), -- Gnomish Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66366 - Gnomeregan Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+132, 34861, 650, 3, 1, 679.9809, 648.8785, 440.1984, 5.864306, 7200, 0, 0), -- Blood Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66360 - Silvermoon Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+133, 34860, 650, 3, 1, 684.0695, 656.6805, 442.074, 5.689773, 7200, 0, 0), -- Forsaken Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow, 66365 - Undercity Pennant, 55944 - Spectator - Cheer Aura)
(@CGUID+134, 34871, 650, 3, 1, 810.6077, 659.8299, 442.0864, 3.682645, 7200, 0, 0); -- Night Elf Coliseum Spectator (Area: Trial of the Champion) (Auras: 66321 - [DND] Spawn Grow; 55944 - Spectator - Cheer Aura)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+134;
INSERT INTO `creature_addon` (`guid`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(@CGUID+18, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+19, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+20, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+21, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+22, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+23, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+24, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+25, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+26, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+32, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+33, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+34, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+35, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+36, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+37, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+38, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+39, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+40, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+42, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - Generic Bunny
(@CGUID+43, 0, 0x0, 0x1, '66321 55944'), -- Orcish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+44, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - FX - Alliance
(@CGUID+45, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - FX - Tauren
(@CGUID+46, 0, 0x0, 0x1, '66321 55944'), -- Troll Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+47, 0, 0x0, 0x1, '66321 55944'), -- Tauren Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+48, 0, 0x0, 0x1, '66321 66371 55944'), -- Troll Coliseum Spectator - 66321 - [DND] Spawn Grow, 66371 - Sen'jin Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+49, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+50, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+51, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+52, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+57, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+58, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+59, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+61, 0, 0x0, 0x1, '66321 66363 55944'), -- Dwarven Coliseum Spectator - 66321 - [DND] Spawn Grow, 66363 - Ironforge Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+62, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - FX - Horde
(@CGUID+63, 0, 0x0, 0x1, '66321 55944'), -- Dwarven Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+64, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - FX - Troll
(@CGUID+65, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - FX - Orc
(@CGUID+66, 0, 0x0, 0x1, '66321 66369 55944'), -- Orcish Coliseum Spectator - 66321 - [DND] Spawn Grow, 66369 - Orgrimmar Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+67, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - FX - Dwarf
(@CGUID+68, 0, 0x0, 0x1, '66321 55944'), -- Orcish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+69, 0, 0x0, 0x1, '66321 55944'), -- Draenei Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+70, 0, 0x0, 0x1, '66321 66367 55944'), -- Human Coliseum Spectator - 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+71, 0, 0x0, 0x1, '66321 66370 55944'), -- Tauren Coliseum Spectator - 66321 - [DND] Spawn Grow, 66370 - Thunder Bluff Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+72, 0, 0x0, 0x1, '66321 66362 55944'), -- Draenei Coliseum Spectator - 66321 - [DND] Spawn Grow, 66362 - Exodar Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+73, 0, 0x0, 0x1, '66321 55944'), -- Tauren Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+74, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+75, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+76, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+77, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+78, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+81, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+82, 0, 0x0, 0x1, '66321 55944'), -- Forsaken Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+83, 0, 0x0, 0x1, '66321 66367 55944'), -- Human Coliseum Spectator - 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+84, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - FX - Undead
(@CGUID+85, 0, 0x0, 0x1, ''), -- [ph] Argent Raid Spectator - FX - Blood Elf
(@CGUID+86, 0, 0x0, 0x1, '66321 55944'), -- Gnomish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+91, 0, 0x0, 0x1, '66321 66362 55944'), -- Draenei Coliseum Spectator - 66321 - [DND] Spawn Grow, 66362 - Exodar Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+92, 0, 0x0, 0x1, '66321 55944'), -- Blood Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+93, 0, 0x0, 0x1, '66321 55944'), -- Orcish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+94, 0, 0x0, 0x1, '66321 55944'), -- Forsaken Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+95, 0, 0x0, 0x1, '66321 55944'), -- Dwarven Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+96, 0, 0x0, 0x1, '66321 66363 55944'), -- Dwarven Coliseum Spectator - 66321 - [DND] Spawn Grow, 66363 - Ironforge Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+97, 0, 0x0, 0x1, '66321 66371 55944'), -- Troll Coliseum Spectator - 66321 - [DND] Spawn Grow, 66371 - Sen'jin Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+98, 0, 0x0, 0x1, '66321 66367 55944'), -- Human Coliseum Spectator - 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+99, 0, 0x0, 0x1, '66321 66363 55944'), -- Dwarven Coliseum Spectator - 66321 - [DND] Spawn Grow, 66363 - Ironforge Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+100, 0, 0x0, 0x1, '66321 66362 55944'), -- Draenei Coliseum Spectator - 66321 - [DND] Spawn Grow, 66362 - Exodar Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+101, 0, 0x0, 0x1, '66321 66363 55944'), -- Dwarven Coliseum Spectator - 66321 - [DND] Spawn Grow, 66363 - Ironforge Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+102, 0, 0x0, 0x1, '66321 66365 55944'), -- Forsaken Coliseum Spectator - 66321 - [DND] Spawn Grow, 66365 - Undercity Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+103, 0, 0x0, 0x1, '66321 55944'), -- Night Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+104, 0, 0x0, 0x1, '66321 55944'), -- Troll Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+105, 0, 0x0, 0x1, '66321 66367 55944'), -- Human Coliseum Spectator - 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+106, 0, 0x0, 0x1, '66321 55944'), -- Night Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+107, 0, 0x0, 0x1, '66321 66362 55944'), -- Draenei Coliseum Spectator - 66321 - [DND] Spawn Grow, 66362 - Exodar Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+108, 0, 0x0, 0x1, '66321 55944'), -- Troll Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+109, 0, 0x0, 0x1, '66321 66369 55944'), -- Orcish Coliseum Spectator - 66321 - [DND] Spawn Grow, 66369 - Orgrimmar Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+110, 0, 0x0, 0x1, '66321 66370 55944'), -- Tauren Coliseum Spectator - 66321 - [DND] Spawn Grow, 66370 - Thunder Bluff Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+111, 0, 0x0, 0x1, '66321 66360 55944'), -- Blood Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 66360 - Silvermoon Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+112, 0, 0x0, 0x1, '66321 55944'), -- Orcish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+113, 0, 0x0, 0x1, '66321 55944'), -- Gnomish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+114, 0, 0x0, 0x1, '66321 66360 55944'), -- Blood Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 66360 - Silvermoon Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+115, 0, 0x0, 0x1, '66321 66370 55944'), -- Tauren Coliseum Spectator - 66321 - [DND] Spawn Grow, 66370 - Thunder Bluff Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+116, 0, 0x0, 0x1, '66321 55944'), -- Gnomish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+117, 0, 0x0, 0x1, '66321 66368 55944'), -- Night Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 66368 - Darnassus Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+118, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+119, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+120, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+121, 0, 0x0, 0x1, '66321 66361 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 66361 - Argent Crusade Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+122, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+123, 0, 0x0, 0x1, '66321 55944'), -- Argent Crusade Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+124, 0, 0x0, 0x1, '66321 55944'), -- Gnomish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+125, 0, 0x0, 0x1, '66321 66367 55944'), -- Human Coliseum Spectator - 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+126, 0, 0x0, 0x1, '66321 55944'), -- Gnomish Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+127, 0, 0x0, 0x1, '66321 66365 55944'), -- Forsaken Coliseum Spectator - 66321 - [DND] Spawn Grow, 66365 - Undercity Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+128, 0, 0x0, 0x1, '66321 55944'), -- Blood Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 55944 - Spectator - Cheer Aura
(@CGUID+129, 0, 0x0, 0x1, '66321 66368 55944'), -- Night Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 66368 - Darnassus Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+130, 0, 0x0, 0x1, '66321 66367 55944'), -- Human Coliseum Spectator - 66321 - [DND] Spawn Grow, 66367 - Stormwind Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+131, 0, 0x0, 0x1, '66321 66366 55944'), -- Gnomish Coliseum Spectator - 66321 - [DND] Spawn Grow, 66366 - Gnomeregan Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+132, 0, 0x0, 0x1, '66321 66360 55944'), -- Blood Elf Coliseum Spectator - 66321 - [DND] Spawn Grow, 66360 - Silvermoon Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+133, 0, 0x0, 0x1, '66321 66365 55944'), -- Forsaken Coliseum Spectator - 66321 - [DND] Spawn Grow, 66365 - Undercity Pennant, 55944 - Spectator - Cheer Aura
(@CGUID+134, 0, 0x0, 0x1, '66321 55944'); -- Night Elf Coliseum Spectator - 66321 - [DND] Spawn Grow; 55944 - Spectator - Cheer Aura

DELETE FROM `gameobject` WHERE `map`=650;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+ 0, 195479, 650, 3, 1, 746.1556, 549.4642, 412.8809, 4.71239, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- Doodad_InstancePortal_Green_10Man01 (Area: 0)
(@OGUID+ 1, 195480, 650, 3, 1, 746.1556, 549.4642, 412.8809, 1.570796, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- Doodad_InstancePortal_Green_25Man01 (Area: 0)
(@OGUID+ 2, 195478, 650, 3, 1, 746.1556, 549.4642, 412.8809, 1.570796, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- Doodad_InstancePortal_Green_10Man_Heroic01 (Area: 0)
(@OGUID+ 3, 195481, 650, 3, 1, 746.1556, 549.4642, 412.8809, 1.570796, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- Doodad_InstancePortal_Green_25Man_Heroic01 (Area: 0)
(@OGUID+ 4, 195486, 650, 3, 1, 813.1198, 617.5898, 413.0305, 0, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- Doodad_InstanceNewPortal_Purple_Skull01 (Area: 0)
(@OGUID+ 5, 195477, 650, 3, 1, 813.1296, 617.6323, 413.0386, 0, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- Doodad_InstanceNewPortal_Purple07 (Area: 0)
(@OGUID+ 6, 195650, 650, 3, 1, 804.6328, 618.0554, 412.6763, 3.141593, 0, 0, 0.7071069, 0.7071066, 86400, 255, 0), -- North Portcullis (Area: Trial of the Champion)
(@OGUID+ 7, 195649, 650, 3, 1, 688.7698, 618.0554, 412.704, 3.141593, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- South Portcullis (Area: Trial of the Champion)
(@OGUID+ 8, 195648, 650, 3, 1, 746.6458, 560.1208, 412.704, 1.570796, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- East Portcullis (Area: Trial of the Champion)
(@OGUID+ 9, 195647, 650, 3, 1, 746.6976, 677.4688, 412.3391, 1.570796, 0, 0, 0.7071069, 0.7071066, 86400, 255, 1), -- Main Gate (Area: Trial of the Champion)
(@OGUID+10, 196398, 650, 3, 1, 784.533, 660.2379, 412.3891, 5.567601, 0, 0, 0, 1, 86400, 255, 1), -- Lance Rack (Area: Trial of the Champion)
(@OGUID+11, 196398, 650, 3, 1, 801.6632, 624.8055, 412.3444, 4.939284, 0, 0, 0, 1, 86400, 255, 1), -- Lance Rack (Area: Trial of the Champion)
(@OGUID+12, 195485, 650, 3, 1, 844.6845, 623.4078, 159.1088, 0, 0, 0, 0.7071069, 0.7071066, 86400, 255, 0), -- Web Door (Area: Trial of the Champion)
(@OGUID+13, 196398, 650, 3, 1, 692.1268, 610.5746, 412.3466, 1.850049, 0, 0, 0, 1, 86400, 255, 1), -- Lance Rack (Area: Trial of the Champion)
(@OGUID+14, 196398, 650, 3, 1, 710.3246, 660.7083, 412.3868, 0.6981314, 0, 0, 0, 1, 86400, 255, 1), -- Lance Rack (Area: Trial of the Champion)
(@OGUID+15, 195709, 650, 1, 1, 744.7205, 618.3073, 411.0891, 1.53589, 0, 0, 0, 1, -86400, 255, 1), -- Champion's Cache (Area: Trial of the Champion)
(@OGUID+16, 195374, 650, 1, 1, 748.7604, 618.309, 411.0891, 1.588249, 0, 0, 0, 1, -86400, 255, 1), -- Eadric's Cache (Area: Trial of the Champion)
(@OGUID+17, 195323, 650, 1, 1, 748.7778, 618.3524, 411.0891, 1.570796, 0, 0, 0, 1, -86400, 255, 1), -- Confessor's Cache (Area: 0)
(@OGUID+18, 195710, 650, 2, 1, 744.7205, 618.3073, 411.0891, 1.53589, 0, 0, 0, 1, -86400, 255, 1), -- Champion's Cache (Area: Trial of the Champion)
(@OGUID+19, 195375, 650, 2, 1, 748.7604, 618.309, 411.0891, 1.588249, 0, 0, 0, 1, -86400, 255, 1), -- Eadric's Cache (Area: Trial of the Champion)
(@OGUID+20, 195324, 650, 2, 1, 748.7778, 618.3524, 411.0891, 1.570796, 0, 0, 0, 1, -86400, 255, 1); -- Confessor's Cache (Area: 0)

UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=29639; -- 29639
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=29640; -- 29640
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725 WHERE `modelid`=29643; -- 29643
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=29644; -- 29644
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05 WHERE `modelid`=29645; -- 29645
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05 WHERE `modelid`=29646; -- 29646
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=29648; -- 29648
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=29650; -- 29650
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5 WHERE `modelid`=29651; -- 29651
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5 WHERE `modelid`=29652; -- 29652
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5 WHERE `modelid`=29654; -- 29654
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5 WHERE `modelid`=29655; -- 29655
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5 WHERE `modelid`=29659; -- 29659
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5 WHERE `modelid`=29660; -- 29660
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=29570; -- 29570
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=29571; -- 29571
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5 WHERE `modelid`=29572; -- 29572
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5 WHERE `modelid`=29574; -- 29574
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5 WHERE `modelid`=29575; -- 29575
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=29576; -- 29576
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=29577; -- 29577
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5 WHERE `modelid`=29578; -- 29578
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5 WHERE `modelid`=29579; -- 29579
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5 WHERE `modelid`=29580; -- 29580
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5 WHERE `modelid`=29581; -- 29581
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05 WHERE `modelid`=29582; -- 29582
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05 WHERE `modelid`=29583; -- 29583
UPDATE `creature_model_info` SET `bounding_radius`=0.4596, `combat_reach`=1.8 WHERE `modelid`=29894; -- 29894
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5 WHERE `modelid`=29634; -- 29634
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5 WHERE `modelid`=29635; -- 29635
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5 WHERE `modelid`=29636; -- 29636
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5 WHERE `modelid`=29638; -- 29638

UPDATE `creature_template` SET `scale`=1 WHERE `entry` IN (34871, 34869, 34856, 34975, 34970, 34868, 34870, 34977, 34974, 34966, 34979, 34860, 34859, 34861, 34857, 34858);

UPDATE `creature_template` SET `spell1`=68505, `spell2`=62575,`spell3`=68282,`spell4`=62552 WHERE `entry` IN (36558,33322);
