SET @CGUID := 11000001;

SET @NPCTEXTID := 610000;

SET @POOLID := 1100000;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+98;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8706.138671875, 421.68402099609375, 99.2193145751953125, 3.769489288330078125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+1, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8707.3125, 418.868072509765625, 99.166351318359375, 1.298754453659057617, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+2, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8708.701171875, 420.166656494140625, 98.98682403564453125, 0.660206139087677001, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+3, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8708.5556640625, 422.135406494140625, 98.97164154052734375, 6.099417686462402343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+4, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8704.826171875, 421.03125, 99.46875, 3.861049890518188476, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+5, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8733.9775390625, 398.015625, 98.06345367431640625, 4.755939483642578125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+6, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8725.1162109375, 458.267364501953125, 98.2146148681640625, 3.68799757957458496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+7, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8729.30078125, 396.9375, 98.0351409912109375, 4.234243392944335937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+8, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.1025390625, 393.69964599609375, 98.290496826171875, 1.383632540702819824, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+9, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8730.7861328125, 395.951385498046875, 98.0367889404296875, 4.365546226501464843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+10, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8727.0849609375, 457.0625, 98.44086456298828125, 0.49616822600364685, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+11, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8734.7236328125, 396.369781494140625, 98.290496826171875, 5.020342826843261718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+12, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.267578125, 397.796875, 98.04198455810546875, 4.564572811126708984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+13, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.138671875, 390.947906494140625, 98.290496826171875, 1.475192070007324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+14, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.5830078125, 396.748260498046875, 98.047882080078125, 4.808267593383789062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+15, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8733.607421875, 392.916656494140625, 98.290496826171875, 1.475192070007324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+16, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8728.9150390625, 395.01910400390625, 98.290496826171875, 3.808313846588134765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+17, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8701.357421875, 460.29339599609375, 96.6452178955078125, 4.635957717895507812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+18, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8728.2900390625, 434.00347900390625, 98.45070648193359375, 3.09932708740234375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+19, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.5576171875, 433.13714599609375, 98.990234375, 0.354807615280151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+20, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8702.5595703125, 456.34375, 96.9482421875, 2.311017751693725585, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+21, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.3662109375, 436.48089599609375, 99.1847076416015625, 0.354807615280151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+22, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8727.4912109375, 432.421875, 98.39881134033203125, 3.258150577545166015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+23, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8728.935546875, 436.064239501953125, 98.60760498046875, 3.642995834350585937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+24, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8704.5869140625, 458.539947509765625, 96.72534942626953125, 5.85458230972290039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+25, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8729.169921875, 432.359375, 98.54477691650390625, 3.09932708740234375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+26, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8703.2099609375, 460.0538330078125, 96.57634735107421875, 5.124796390533447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+27, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8701.9287109375, 457.6475830078125, 96.85198974609375, 2.219457626342773437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+28, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.2763671875, 434.828125, 99.09869384765625, 0.263248145580291748, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+29, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8730.0517578125, 439.17535400390625, 98.6682586669921875, 4.292134761810302734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+30, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8711.171875, 447.369781494140625, 97.25511932373046875, 4.629204273223876953, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+31, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8730.12890625, 437.623260498046875, 98.7930450439453125, 4.278536796569824218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+32, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8672.234375, 409.133697509765625, 103.7615585327148437, 1.756839275360107421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+33, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8670.46875, 410.005218505859375, 103.6328125, 2.270540714263916015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+34, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8660.1337890625, 499.782989501953125, 101.5218276977539062, 0.942570984363555908, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+35, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8678.908203125, 481.548614501953125, 97.16225433349609375, 5.323331832885742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+36, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8657.484375, 502.211822509765625, 101.7852783203125, 3.836822509765625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+37, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8672.75390625, 411.470489501953125, 104.1501235961914062, 5.113438129425048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+38, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8658.97265625, 503.2100830078125, 102.05401611328125, 3.905642986297607421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+39, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8677.7236328125, 479.203125, 97.2174530029296875, 1.931082606315612792, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+40, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8662.2294921875, 502.505218505859375, 102.05401611328125, 0.066855460405349731, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+41, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8661.50390625, 500.703125, 101.5715179443359375, 0.581144869327545166, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+42, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8671.2392578125, 412.689239501953125, 103.9925765991210937, 5.027472972869873046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+43, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8696.6298828125, 391.001739501953125, 102.516326904296875, 5.568322658538818359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+44, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8629.935546875, 441.1319580078125, 102.9605331420898437, 5.398550033569335937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+45, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8691.3505859375, 391.4913330078125, 102.4295196533203125, 4.6082611083984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+46, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8693.7255859375, 388.447906494140625, 102.6494827270507812, 2.02476668357849121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+47, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8628.6630859375, 438.751739501953125, 103.2975692749023437, 2.327332258224487304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+48, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8628.6005859375, 442.3975830078125, 103.3246536254882812, 5.323331832885742187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+49, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8711.373046875, 444.755218505859375, 97.34857177734375, 1.649069786071777343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+50, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8629.91015625, 442.883697509765625, 102.928955078125, 5.398550033569335937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+51, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8693.9443359375, 392.31597900390625, 102.3186569213867187, 4.946494102478027343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+52, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8691.3037109375, 386.8194580078125, 102.9618377685546875, 2.116326332092285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+53, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8630.9150390625, 439.10589599609375, 102.9737548828125, 6.007556438446044921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+54, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8696.4736328125, 389.5382080078125, 102.6932754516601562, 5.395518302917480468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+55, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8694.45703125, 386.930572509765625, 102.9618377685546875, 2.116326332092285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+56, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8627.0537109375, 440.26910400390625, 103.3104934692382812, 2.563581705093383789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+57, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8694.6337890625, 390.59027099609375, 102.4197921752929687, 5.139936447143554687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+58, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8692.5849609375, 390.5694580078125, 102.4608230590820312, 4.6082611083984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+59, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8672.75390625, 411.470489501953125, 104.1501235961914062, 5.113438129425048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+60, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8643.4423828125, 454.994781494140625, 102.58160400390625, 0.744741797447204589, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+61, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8677.7236328125, 479.203125, 97.2174530029296875, 1.931082606315612792, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+62, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8641.404296875, 456.701385498046875, 102.4747238159179687, 3.672198772430419921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+63, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8671.2392578125, 412.689239501953125, 103.9925765991210937, 5.027472972869873046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+64, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8676.888671875, 389.734375, 103.4172286987304687, 5.674918174743652343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+65, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8627.0537109375, 440.26910400390625, 103.3104934692382812, 2.563581705093383789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+66, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8628.6630859375, 438.751739501953125, 103.2975692749023437, 2.327332258224487304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+67, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8691.3037109375, 386.8194580078125, 102.9618377685546875, 2.116326332092285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+68, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8694.45703125, 386.930572509765625, 102.9618377685546875, 2.116326332092285156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+69, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8693.7255859375, 388.447906494140625, 102.6494827270507812, 2.02476668357849121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+70, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8675.0224609375, 388.2569580078125, 103.5077590942382812, 2.638671636581420898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+71, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8648.2294921875, 409.76910400390625, 102.71514892578125, 2.250457286834716796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+72, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8649.794921875, 411.760406494140625, 102.730712890625, 5.3607940673828125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+73, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8705.5380859375, 456.96527099609375, 96.8568878173828125, 0.0028458540327847, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+74, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.3662109375, 436.48089599609375, 99.1847076416015625, 0.354807615280151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+75, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8733.607421875, 392.916656494140625, 98.290496826171875, 1.475192070007324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+76, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.2763671875, 434.828125, 99.09869384765625, 0.263248145580291748, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+77, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8732.1025390625, 393.69964599609375, 98.290496826171875, 1.383632540702819824, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+78, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.5576171875, 433.13714599609375, 98.990234375, 0.354807615280151367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+79, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8731.138671875, 390.947906494140625, 98.290496826171875, 1.475192070007324218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+80, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8684.671875, 441.361114501953125, 99.6461639404296875, 4.193150997161865234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+81, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8687.767578125, 438.008697509765625, 99.445098876953125, 1.054665088653564453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+82, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8682.7236328125, 439.13714599609375, 99.59661865234375, 3.662360668182373046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+83, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8682.576171875, 441.729156494140625, 99.7542266845703125, 4.158257484436035156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+84, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8686.3330078125, 437.81597900390625, 99.44927978515625, 0.963104486465454101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+85, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8687.1630859375, 441.614593505859375, 99.5476226806640625, 4.526597023010253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+86, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8658.97265625, 503.2100830078125, 102.05401611328125, 3.905642986297607421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+87, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8657.484375, 502.211822509765625, 101.7852783203125, 3.836822509765625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+88, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8706.138671875, 421.68402099609375, 99.2193145751953125, 3.769489288330078125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+89, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8704.826171875, 421.03125, 99.46875, 3.861049890518188476, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+90, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8658.232421875, 437.513885498046875, 101.367095947265625, 2.250457286834716796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+91, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8660.0673828125, 439.701385498046875, 101.081573486328125, 5.461605548858642578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+92, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8675.0224609375, 388.2569580078125, 103.5077590942382812, 2.638671636581420898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+93, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8648.2294921875, 409.76910400390625, 102.71514892578125, 2.250457286834716796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+94, 246154, 0, 1519, 5149, '0', 0, 0, 0, 0, -8643.4423828125, 454.994781494140625, 102.58160400390625, 0.744741797447204589, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+95, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8742.671875, 415.802093505859375, 98.290496826171875, 3.555392026901245117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+96, 246155, 0, 1519, 5149, '0', 0, 0, 0, 0, -8745.9658203125, 414.34027099609375, 98.290496826171875, 0.251413047313690185, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Suspicious Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+97, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8741.5595703125, 414.333343505859375, 98.0711822509765625, 3.011341571807861328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727), -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2
(@CGUID+98, 251797, 0, 1519, 5149, '0', 0, 0, 0, 0, -8742.9970703125, 413.3819580078125, 98.290496826171875, 3.011341571807861328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 65727); -- Interested Citizen (Area: Old Town - Difficulty: 0) CreateObject2

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (246155 /*246155 (Suspicious Citizen)*/, 246154 /*246154 (Suspicious Citizen)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(246155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 246155 (Suspicious Citizen)
(246154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 246154 (Suspicious Citizen)

-- Template
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry` IN (246155, 246154); -- Suspicious Citizen
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=251797; -- Interested Citizen

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=246154 AND `DifficultyID`=0); -- 246154 (Suspicious Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=246155 AND `DifficultyID`=0); -- 246155 (Suspicious Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3098, `StaticFlags1`=0x10000000, `VerifiedBuild`=65727 WHERE (`Entry`=251797 AND `DifficultyID`=0); -- 251797 (Interested Citizen) - CanSwim

-- Quest
DELETE FROM `quest_details` WHERE `ID`=90760;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(90760, 1, 0, 0, 0, 0, 0, 0, 0, 65727); -- Avoiding Blame

DELETE FROM `quest_request_items` WHERE `ID`=90760;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(90760, 0, 1, 0, 0, 'I understand the comfort the void can provide. But surrendering to it completely is not the peace many are led to believe.', 65727); -- Avoiding Blame

DELETE FROM `creature_queststarter` WHERE (`id`=246156 AND `quest`=90760);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(246156, 90760, 65727); -- Avoiding Blame offered by Magister Umbric

DELETE FROM `creature_questender` WHERE (`id`=246156 AND `quest`=90760);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(246156, 90760, 65727); -- Avoiding Blame ended by Magister Umbric

DELETE FROM `quest_template_addon` WHERE `ID` = 90760;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(90760, 0, 0, 0, 90759, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '');

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=246155 AND `MenuID`=39854) OR (`CreatureID`=246154 AND `MenuID`=39850);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(246155, 39854, 65727), -- Suspicious Citizen
(246154, 39850, 65727); -- Suspicious Citizen

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 1, 1, 1, 1, 0, 0, 0, 293453, 293451, 293454, 293452, 293455, 0, 0, 0, 65727), -- 246154 (Suspicious Citizen)
(@NPCTEXTID+1, 1, 1, 1, 1, 0, 0, 0, 0, 293457, 293466, 293460, 293459, 0, 0, 0, 0, 65727); -- 246155 (Suspicious Citizen)

DELETE FROM `gossip_menu` WHERE (`MenuID`=39850 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=39854 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(39850, @NPCTEXTID+0, 65727), -- 246154 (Suspicious Citizen)
(39854, @NPCTEXTID+1, 65727); -- 246155 (Suspicious Citizen)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=39854 AND `OptionID` IN (0,1)) OR (`MenuID`=39850 AND `OptionID` IN (1,0));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(39854, 134634, 0, 0, 'Are you talking about the Twilight\'s Blade?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727),
(39850, 134643, 1, 0, 'You\'re not who I am looking for. Please move along.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727),
(39850, 134631, 0, 0, 'Are you talking about the Twilight\'s Blade?', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727),
(39854, 134642, 1, 0, 'You\'re not who I am looking for. Please move along.', 0, 0, 1, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 65727);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 14) AND (`SourceGroup` IN (39854,39850));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(14, 39854, @NPCTEXTID+1, 0, 0, 47, 0, 90760, 8, 0, '', 0, 'Player for which gossip text is shown has Avoiding Blame (90760) in state incomplete'),
(14, 39850, @NPCTEXTID+0, 0, 0, 47, 0, 90760, 8, 0, '', 0, 'Player for which gossip text is shown has Avoiding Blame (90760) in state incomplete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (39850));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 39850, 0, 0, 0, 47, 0, 90760, 8, 0, '', 0, 'Player for which gossip text is shown has Avoiding Blame (90760) in state incomplete'),
(15, 39850, 1, 0, 0, 47, 0, 90760, 8, 0, '', 0, 'Player for which gossip text is shown has Avoiding Blame (90760) in state incomplete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 15) AND (`SourceGroup` IN (39854));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(15, 39854, 0, 0, 0, 47, 0, 90760, 8, 0, '', 0, 'Player for which gossip text is shown has Avoiding Blame (90760) in state incomplete'),
(15, 39854, 1, 0, 0, 47, 0, 90760, 8, 0, '', 0, 'Player for which gossip text is shown has Avoiding Blame (90760) in state incomplete');

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (246155,246154));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(246155, 1, 235248, 0, 0, 0, 0, 0, 0, 0, 0, 65727), -- Suspicious Citizen
(246154, 1, 235248, 0, 0, 0, 0, 0, 0, 0, 0, 65727); -- Suspicious Citizen

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (246154,246155);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(246154, 0, 0, 'Xal\'atath has a dark and glorious purpose for you, $c!', 12, 0, 100, 0, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246154, 0, 1, 'The Twilight\'s Blade embraces the end. Join us!', 12, 0, 100, 0, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246154, 0, 2, 'Bah. Your investigation ends here!', 12, 0, 100, 0, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246154, 0, 3, 'This is the last you\'ll speak of it!', 12, 0, 100, 0, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246154, 0, 4, 'We are Xal\'atath\'s finest weapon!', 12, 0, 100, 0, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246154, 0, 5, 'The apocalypse beckons. We answer her call.', 12, 0, 100, 0, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246155, 0, 0, 'I have no interest in doomsday events, $c.', 12, 0, 100, 1, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246155, 0, 1, 'Do you have ambitions? Desires? I might know the way to achieving them...', 12, 0, 100, 1, 0, 0, 0, 0, 'Suspicious Citizen'),
(246155, 0, 2, 'Do I give the impression I\'m part of that cult? I need to rethink my wardrobe...', 12, 0, 100, 1, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246155, 0, 3, 'The Twilight\'s Blade? That sounds dreadful. I\'ll keep an eye out.', 12, 0, 100, 1, 0, 0, 0, 0, 'Suspicious Citizen to Player'),
(246155, 0, 4, 'Are there cultists in the city? I had better hurry home...', 12, 0, 100, 1, 0, 0, 0, 0, 'Suspicious Citizen to Player');

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=140375;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(140375, 1, 1.5, 0, 65727);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (141424, 138274, 75694, 140375);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(141424, 0.305999994277954101, 1.5, 0, 65727),
(138274, 1, 1.5, 0, 65727),
(75694, 1.082463026046752929, 0, 0, 65727),
(140375, 1, 1.5, 0, 65727);

-- Pools
DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID+0 AND @POOLID+20;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+0, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+1, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+2, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+3, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+4, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+5, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+6, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+7, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+8, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+9, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+10, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+11, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+12, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+13, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+14, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+15, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+16, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+17, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+18, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+19, 1, 'Stormwind - Suspicious Citizen'),
(@POOLID+20, 1, 'Stormwind - Suspicious Citizen');

DELETE FROM `pool_members` WHERE `type` = 0 AND `poolSpawnId` BETWEEN @POOLID+0 AND @POOLID+20;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, @CGUID+74, @POOLID+0, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+21, @POOLID+0, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+76, @POOLID+1, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+28, @POOLID+1, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+78, @POOLID+2, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+19, @POOLID+2, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+88, @POOLID+3, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+0, @POOLID+3, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+89, @POOLID+4, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+4, @POOLID+4, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+15, @POOLID+5, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+75, @POOLID+5, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+77, @POOLID+6, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+8, @POOLID+6, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+13, @POOLID+7, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+79, @POOLID+7, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+68, @POOLID+8, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+55, @POOLID+8, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+46, @POOLID+9, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+69, @POOLID+9, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+52, @POOLID+10, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+67, @POOLID+10, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+70, @POOLID+11, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+92, @POOLID+11, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+37, @POOLID+12, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+59, @POOLID+12, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+63, @POOLID+13, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+42, @POOLID+13, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+71, @POOLID+14, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+93, @POOLID+14, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+47, @POOLID+15, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+66, @POOLID+15, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+56, @POOLID+16, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+65, @POOLID+16, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+60, @POOLID+17, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+94, @POOLID+17, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+36, @POOLID+18, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+87, @POOLID+18, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+38, @POOLID+19, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+86, @POOLID+19, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+39, @POOLID+20, 0, 'Stormwind - Suspicious Citizen'),
(0, @CGUID+61, @POOLID+20, 0, 'Stormwind - Suspicious Citizen');
