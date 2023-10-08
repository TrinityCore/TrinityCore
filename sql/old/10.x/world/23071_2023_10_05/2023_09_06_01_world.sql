SET @CGUID := 5000028;
SET @OGUID := 5000046;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+47;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 78883, 1265, 7025, 7037, '0', 3568, 0, 0, 1, 4056.423583984375, -2430.15283203125, 94.68719482421875, 0.640638291835784912, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+1, 78883, 1265, 7025, 7037, '0', 3568, 0, 0, 1, 4043.63623046875, -2426.147705078125, 94.6871795654296875, 6.144875526428222656, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+2, 78883, 1265, 7025, 7037, '0', 3568, 0, 0, 1, 4042.549560546875, -2411.295166015625, 94.51904296875, 4.681329250335693359, 120, 0, 0, 5000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+3, 78883, 1265, 7025, 7037, '0', 3568, 0, 0, 1, 4049.55908203125, -2380.5625, 94.68717193603515625, 1.393499612808227539, 120, 0, 0, 4800, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+4, 78883, 1265, 7025, 7037, '0', 3568, 0, 0, 1, 4041.78466796875, -2381.078125, 94.68637847900390625, 0.57881784439086914, 120, 0, 0, 4600, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+5, 78883, 1265, 7025, 7037, '0', 3568, 0, 0, 1, 4075.078125, -2374.467041015625, 94.68717193603515625, 4.80870819091796875, 120, 0, 0, 5000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+6, 78883, 1265, 7025, 7037, '0', 3568, 0, 0, 1, 4094.564208984375, -2396.507080078125, 94.68621826171875, 0.700788438320159912, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+7, 78883, 1265, 7025, 7037, '0', 3568, 0, 0, 1, 4090.84033203125, -2423.638916015625, 94.6871795654296875, 5.443758010864257812, 120, 0, 0, 5000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+8, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4056.423583984375, -2430.15283203125, 94.68719482421875, 0.640638291835784912, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+9, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4043.63623046875, -2426.147705078125, 94.6871795654296875, 6.144875526428222656, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+10, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4042.549560546875, -2411.295166015625, 94.51904296875, 4.681329250335693359, 120, 0, 0, 5000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+11, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4049.55908203125, -2380.5625, 94.68717193603515625, 1.393499612808227539, 120, 0, 0, 4800, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+12, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4041.78466796875, -2381.078125, 94.68637847900390625, 0.57881784439086914, 120, 0, 0, 4600, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+13, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4075.078125, -2374.467041015625, 94.68717193603515625, 4.80870819091796875, 120, 0, 0, 5000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+14, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4094.564208984375, -2396.507080078125, 94.68621826171875, 0.700788438320159912, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+15, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4090.84033203125, -2423.638916015625, 94.6871795654296875, 5.443758010864257812, 120, 0, 0, 5000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+16, 83538, 1265, 7025, 7037, '0', 3568, 0, 0, 2, 4118.88525390625, -2279.21533203125, 69.410858154296875, 3.83407902717590332, 120, 0, 0, 4800, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Warsong Commander (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166740 - Howling Blade)
(@CGUID+17, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4105.8212890625, -2423.553955078125, 91.76662445068359375, 3.145416975021362304, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+18, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4116.0546875, -2389.932373046875, 81.26428985595703125, 4.808262825012207031, 120, 0, 0, 5200, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+19, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4015.723876953125, -2384.765625, 78.9198455810546875, 3.759487867355346679, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+20, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4112.080078125, -2406.14404296875, 88.9763946533203125, 3.701324701309204101, 120, 0, 0, 4800, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+21, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4115.1025390625, -2375.447998046875, 78.91943359375, 0.47011345624923706, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+22, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4022.983642578125, -2406.17529296875, 88.97638702392578125, 1.020450830459594726, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+23, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4014.65625, -2376.109375, 78.919464111328125, 2.352326393127441406, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+24, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4020.861083984375, -2417.00341796875, 88.97637939453125, 4.395724773406982421, 120, 0, 0, 4600, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+25, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4026.96435546875, -2423.869873046875, 90.89703369140625, 0.150151148438453674, 120, 0, 0, 5200, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned, 158082 - Battle Hardened)
(@CGUID+26, 78883, 1265, 7025, 7037, '0', 0, 0, 0, 1, 4016.608642578125, -2394.3125, 84.04718017578125, 4.512995719909667968, 120, 0, 0, 4000, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Iron Grunt (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 80636 - Feigned)
(@CGUID+27, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4037.260498046875, -2413.96484375, 85.7198944091796875, 0.678200364112854003, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+28, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4089.069580078125, -2399.15576171875, 70.7515411376953125, 5.644424915313720703, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+29, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4054.649658203125, -2432.82275390625, 84.93317413330078125, 4.566654682159423828, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+30, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4091.6796875, -2407.835205078125, 70.6233978271484375, 0.84901583194732666, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+31, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4043.348876953125, -2417.90771484375, 70.53369903564453125, 3.286806106567382812, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+32, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4046.8857421875, -2405.9013671875, 86.45153045654296875, 0.405240744352340698, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+33, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4049.745849609375, -2416.4541015625, 70.5209197998046875, 5.388498783111572265, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+34, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4080.155517578125, -2431.82177734375, 86.7387847900390625, 5.875795364379882812, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+35, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4087.44189453125, -2402.660400390625, 85.69635009765625, 0.888596236705780029, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+36, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4052.260986328125, -2422.30419921875, 72.18666839599609375, 5.811341762542724609, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+37, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4158.8193359375, -2269.24560546875, 69.52416229248046875, 0.921878516674041748, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+38, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4058.5029296875, -2423.203857421875, 70.532012939453125, 2.122214317321777343, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+39, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 3950.831787109375, -2282.37255859375, 64.49739837646484375, 6.118890285491943359, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+40, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4078.165283203125, -2428.41064453125, 70.5323944091796875, 3.732020854949951171, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+41, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4173.18115234375, -2287.706298828125, 63.47681427001953125, 2.568333625793457031, 120, 0, 0, 600, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul)
(@CGUID+42, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4181.1318359375, -2274.548583984375, 67.08599853515625, 3.699581384658813476, 120, 0, 0, 600, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul)
(@CGUID+43, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 3970.126953125, -2276.245361328125, 67.79856109619140625, 1.127520442008972167, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+44, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 3961.25927734375, -2293.349853515625, 64.53330230712890625, 4.006815433502197265, 120, 10, 0, 600, 0, 1, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul) (possible waypoints or random movement)
(@CGUID+45, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4074.0634765625, -2426.32080078125, 72.169342041015625, 6.268630504608154296, 120, 0, 0, 600, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul)
(@CGUID+46, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4090.79345703125, -2406.069091796875, 70.842132568359375, 1.574909210205078125, 120, 0, 0, 600, 0, 0, NULL, NULL, NULL, NULL, 50791), -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul)
(@CGUID+47, 82647, 1265, 7025, 7037, '0', 3568, 0, 0, 0, 4037.8671875, -2416.130126953125, 70.0666656494140625, 0.013610582798719406, 120, 0, 0, 600, 0, 0, NULL, NULL, NULL, NULL, 50791); -- Tormented Soul (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166452 - Tormented Soul)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+47;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '166740 167640'), -- Warsong Commander - 166740 - Howling Blade, 167640 - HOTDP - Iron Horde Banner
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'), -- Iron Grunt - 80636 - Feigned
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80636'); -- Iron Grunt - 80636 - Feigned

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 232505, 1265, 7025, 7037, '0', 0, 856, 4076.62060546875, -2377.567626953125, 94.96607208251953125, 3.692596197128295898, 0, 0, -0.96228885650634765, 0.272029727697372436, 120, 255, 1, 50791), -- Spiked Ball (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+1, 232505, 1265, 7025, 7037, '0', 0, 856, 4042.0244140625, -2413.625, 94.60385894775390625, 5.882395744323730468, -0.14478778839111328, -0.19889068603515625, -0.21602916717529296, 0.944886445999145507, 120, 255, 1, 50791); -- Spiked Ball (Area: The Dark Portal - Difficulty: 0) CreateObject1

-- Creature/GameObject Template
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=78883; -- Iron Grunt
UPDATE `creature_template` SET `speed_run`=1.142857193946838378, `AIName`='SmartAI' WHERE `entry`=83538; -- Warsong Commander

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 82647 /*82647 (Tormented Soul) - Tormented Soul*/;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(82647, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '166452'); -- 82647 (Tormented Soul) - Tormented Soul

UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=232505; -- Spiked Ball

-- Creature Movement data
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 82647;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(82647, 0, 0, 1, 0, 0, 0, NULL);

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` = 83538;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(83538, 0, 0, 'Come at me, bro!', 14, 0, 100, 0, 0, 0, 85250, 0, 'Warsong Commander to Player');

-- ScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` = 80636;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(80636, 'spell_gen_feign_death_all_flags_uninteractible');

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 7037 AND `PhaseId` = 3568;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7037, 3568, 'See the Battle for the Dark Portal (Assault on the Dark Portal)');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3568 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3568, 0, 0, 0, 47, 0, 34393, 2 | 64, 0, 1, 'Apply Phase 3568 if Quest 34393 is not complete | rewarded');

-- Clientside area trigger 10125 smart ai
SET @ENTRY := 10125;
DELETE FROM `smart_scripts` WHERE `source_type` = 2 AND `entryOrGuid` = @ENTRY;
DELETE FROM `areatrigger_scripts` WHERE `entry` = @ENTRY;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES (@ENTRY, 'SmartTrigger');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 2, 0, 0, 46, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, (@CGUID+16), 83538, 0, 0, 0, 0, 0, 'On trigger - Creature Warsong Commander (83538) with guid (fetching): Set creature data #1 to 1');

-- Warsong Commander smart ai
DELETE FROM `smart_scripts` WHERE (`entryorguid`= -(@CGUID+16) AND `source_type`= 0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+16), 0, 0, 1, 0, 0, 100, 1, 0, 0, 0, 0, 28, 167640, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Once (IC) - Self: Remove aura due to spell  167640'),
(-(@CGUID+16), 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 97, 16, 0, 22, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Once (IC) - Victim: Jump to pos (0, 0, 0, 0) with speed XY 16 and speed Z 0'),
(-(@CGUID+16), 0, 2, 0, 38, 0, 100, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[1] set to 1 - Self: Talk Come at me, bro! (0) to invoker');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = -(@CGUID+16) AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES 
(22, 3, -(@CGUID+16), 0, 0, 1, 1, 167640, 0, 0, 0, 'Action invoker has aura of spell 167640, effect EFFECT_0');
