SET @CGUID := 7002191;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+96;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -263.748260498046875, 1288.26220703125, 2.29857492446899414, 1.055201888084411621, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+1, 130163, 1643, 8721, 0, '0', 0, 0, 0, 0, -270.236114501953125, 1318.2882080078125, 2.290036678314208984, 5.510520458221435546, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+2, 130163, 1643, 8721, 0, '0', 0, 0, 0, 0, -272.00347900390625, 1252.8177490234375, 1.737125396728515625, 0.371615409851074218, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+3, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -268.586822509765625, 1320.0035400390625, 2.138775348663330078, 5.077795028686523437, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -220.302078247070312, 1331.048583984375, -2.90368151664733886, 4.248418331146240234, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+5, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -228.1875, 1298.0103759765625, 3.331712961196899414, 2.46264052391052246, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+6, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -294.098968505859375, 1315.2691650390625, 5.205485343933105468, 1.165996670722961425, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+7, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -274.057281494140625, 1273.498291015625, 2.528095722198486328, 6.17449045181274414, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+8, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -325.458343505859375, 1344.3160400390625, 6.984639167785644531, 0.567046642303466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+9, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -286.904510498046875, 1357.6666259765625, 0.417247265577316284, 0.271109789609909057, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+10, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -232.755203247070312, 1292.0504150390625, 1.830863475799560546, 4.782318592071533203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+11, 130163, 1643, 8721, 0, '0', 0, 0, 0, 0, -269.12152099609375, 1278.5035400390625, 1.928501367568969726, 3.241037845611572265, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+12, 130163, 1643, 8721, 0, '0', 0, 0, 0, 0, -267.180572509765625, 1343.970458984375, 1.465675711631774902, 3.074371814727783203, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -263.079864501953125, 1237.9791259765625, 0.923771023750305175, 5.262291908264160156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+14, 130359, 1643, 8721, 0, '0', 0, 0, 0, 0, -287.72222900390625, 1349.4427490234375, 28.41820144653320312, 1.001869916915893554, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Coastal Osprey (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+15, 130163, 1643, 8721, 0, '0', 0, 0, 0, 0, -317.41839599609375, 1337.0972900390625, 3.751513957977294921, 0.450227856636047363, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 130163, 1643, 8721, 0, '0', 0, 0, 0, 0, -321.234375, 1334.142333984375, 4.066310882568359375, 6.040368556976318359, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+17, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -223.046875, 1246.4757080078125, -4.88500070571899414, 1.838341474533081054, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+18, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -243.520828247070312, 1386.88720703125, -3.2148745059967041, 0.87632220983505249, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+19, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -254.84722900390625, 1351.826416015625, 0.346724897623062133, 1.318518638610839843, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+20, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -293.3038330078125, 1363.013916015625, 0.645742833614349365, 1.20707404613494873, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+21, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -327.064239501953125, 1339.4478759765625, 6.573765754699707031, 5.536342144012451171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+22, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -317.15625, 1374.4149169921875, 6.684186935424804687, 3.329100608825683593, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -330.2257080078125, 1612.013916015625, 36.55460739135742187, 0.925878167152404785, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+24, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -337.9375, 1490.642333984375, 10.63002586364746093, 4.369600772857666015, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+25, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -311.642364501953125, 1452.0382080078125, 8.507113456726074218, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -340.49652099609375, 1432.0260009765625, 14.79812431335449218, 0.384996145963668823, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+27, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -304.220489501953125, 1561.03125, 9.9861907958984375, 3.588646888732910156, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+28, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -274.845489501953125, 1409.3541259765625, 0.807680249214172363, 0.888876795768737792, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -257.470489501953125, 1431.7430419921875, 0.147429153323173522, 5.428400993347167968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+30, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -307.368072509765625, 1405.8055419921875, 12.09215927124023437, 6.040369033813476562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+31, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -317.857635498046875, 1410.49658203125, 12.09215927124023437, 0.471480697393417358, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+32, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -270.2882080078125, 1461.295166015625, 1.8162689208984375, 5.260560512542724609, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+33, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -328.822906494140625, 1391.5694580078125, 12.08912563323974609, 0.350993990898132324, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+34, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -322.63714599609375, 1424.5572509765625, 12.08680534362792968, 0.334125012159347534, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+35, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -274.84722900390625, 1443.189208984375, 2.131521224975585937, 0.736458778381347656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+36, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -337.680572509765625, 1434.217041015625, 12.0420379638671875, 1.027268528938293457, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+37, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -290.451385498046875, 1421.5572509765625, 7.642371654510498046, 5.631690025329589843, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+38, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -346.3038330078125, 1417.829833984375, 12.13991069793701171, 0.717249512672424316, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+39, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -317.5538330078125, 1408.2535400390625, 12.09215927124023437, 5.43635416030883789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+40, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -291.024322509765625, 1439.0728759765625, 4.387715816497802734, 1.892069458961486816, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+41, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -338.013885498046875, 1430.84375, 12.06099128723144531, 4.206829071044921875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+42, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -317.421875, 1397.0816650390625, 12.02274608612060546, 3.812161922454833984, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+43, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -316.532989501953125, 1506.7535400390625, 7.545139312744140625, 5.61840057373046875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+44, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -328.008697509765625, 1562.0833740234375, 9.815366744995117187, 2.787972688674926757, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+45, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -374.56597900390625, 1534.1302490234375, 10.42939949035644531, 1.027268528938293457, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+46, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -356.368072509765625, 1512.09375, 10.08782100677490234, 4.069397926330566406, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+47, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -369.439239501953125, 1492.93408203125, 10.44618034362792968, 5.70033121109008789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+48, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -273.4600830078125, 1621.1666259765625, 6.99127197265625, 5.989548206329345703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+49, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -373.392364501953125, 1516.767333984375, 10.42959022521972656, 5.04296875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+50, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -295.30902099609375, 1540.7882080078125, 5.887760162353515625, 3.898755311965942382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+51, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -331.67535400390625, 1520.251708984375, 10.42932033538818359, 4.647157669067382812, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+52, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -325.442718505859375, 1560.6978759765625, 9.6556243896484375, 5.3242034912109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+53, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -297.411468505859375, 1541.26220703125, 6.498276710510253906, 4.934413909912109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+54, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -361.279510498046875, 1546.90625, 10.4293670654296875, 0.125062048435211181, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+55, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -370.10589599609375, 1495.6353759765625, 10.29861068725585937, 0.471480697393417358, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+56, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -270.126739501953125, 1537.373291015625, 2.700651168823242187, 6.039764881134033203, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+57, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -245.8125, 1532.8350830078125, 0.520528197288513183, 5.939446926116943359, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+58, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -344.348968505859375, 1541.9774169921875, 10.42931270599365234, 2.07228851318359375, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+59, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -260.998260498046875, 1499.6197509765625, 1.082616448402404785, 3.238508462905883789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+60, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -253.649307250976562, 1502.0728759765625, 0.20686998963356018, 2.402149915695190429, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+61, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -287.1475830078125, 1586.795166015625, 12.53738880157470703, 6.208652973175048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+62, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -290.0850830078125, 1491.2239990234375, 2.378141164779663085, 0.121352158486843109, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+63, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -373.055572509765625, 1535.532958984375, 10.43107318878173828, 2.858438968658447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+64, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -229.654510498046875, 1537.57470703125, -4.90268945693969726, 0.783549964427947998, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+65, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -320.189239501953125, 1536.171875, 9.922367095947265625, 1.019714117050170898, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+66, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -271.548614501953125, 1542.501708984375, 2.637594223022460937, 1.736274600028991699, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+67, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -265.795135498046875, 1617.4305419921875, 7.765465736389160156, 4.817819595336914062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+68, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -284.939239501953125, 1506.4635009765625, 2.424839019775390625, 0.384572178125381469, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+69, 130136, 1643, 8721, 9132, '0', 0, 0, 0, 0, -295.041656494140625, 1580.560791015625, 20.027740478515625, 1.833236098289489746, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+70, 125401, 1643, 8721, 9132, '0', 0, 0, 0, 0, -298.59027099609375, 1526.3385009765625, 6.125261783599853515, 5.333249568939208984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Invasive Quillrat (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+71, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -295.48785400390625, 1498.4896240234375, 4.478798389434814453, 0.384996145963668823, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+72, 125452, 1643, 8721, 9132, '0', 0, 0, 0, 0, -283.571197509765625, 1501.857666015625, 3.747579813003540039, 6.189029216766357421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+73, 130163, 1643, 8721, 9132, '0', 0, 0, 0, 0, -296.751739501953125, 1522.6771240234375, 7.47204446792602539, 5.206522941589355468, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+74, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -250.40625, 1581.3472900390625, 7.915826797485351562, 4.689915180206298828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+75, 130359, 1643, 8721, 9132, '0', 0, 0, 0, 0, -294.942718505859375, 1582.220458984375, 21.64116096496582031, 1.001869916915893554, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Coastal Osprey (Area: Hawthorne's Plot - Difficulty: 0) CreateObject2
(@CGUID+76, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -251.635421752929687, 1598.5989990234375, 12.85796737670898437, 3.463827371597290039, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+77, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -288.388885498046875, 1576.1353759765625, 12.19302940368652343, 5.216216564178466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+78, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -232.486114501953125, 1599.2864990234375, 13.67852401733398437, 6.268710136413574218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+79, 125452, 1643, 8721, 0, '0', 0, 0, 0, 0, -272.73785400390625, 1609.0694580078125, 8.446469306945800781, 5.727447986602783203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Shallows Saurolisk (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+80, 128494, 1643, 8721, 9130, '0', 0, 0, 0, 1, -348.015625, 1464.1285400390625, 11.19330406188964843, 1.344795703887939453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Adela Hawthorne (Area: Hangman's Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+81, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -496.00347900390625, 1229.015625, 0.189618051052093505, 0.797662019729614257, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+82, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -492.48089599609375, 1258.842041015625, 0.070999085903167724, 0.470041155815124511, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+83, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -392.42535400390625, 1215.10595703125, 0.949577927589416503, 5.055744647979736328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+84, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -354.6319580078125, 1212.8472900390625, -0.39824357628822326, 4.910898208618164062, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+85, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -472.8125, 1265.467041015625, 11.40636634826660156, 5.070675373077392578, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+86, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -391.35589599609375, 1216.375, 0.497235327959060668, 1.889674782752990722, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+87, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -494.248260498046875, 1232.40625, 0.126376032829284667, 3.939030408859252929, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+88, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -380.56597900390625, 1213.4427490234375, -0.02963798493146896, 0.108661346137523651, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+89, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -367.59722900390625, 1219.578125, 0.35584425926208496, 4.721321582794189453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+90, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -419.5, 1220.3941650390625, 0.27841457724571228, 4.649837017059326171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+91, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -441.557281494140625, 1235.001708984375, 0.225754708051681518, 5.272465705871582031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+92, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -406.8819580078125, 1204.265625, -2.41755366325378417, 1.224344372749328613, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+93, 130136, 1643, 8721, 9130, '0', 0, 0, 0, 0, -442.296875, 1256.3680419921875, 11.74041080474853515, 4.978581428527832031, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+94, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -450.770843505859375, 1232.59033203125, 0.076464921236038208, 5.697337150573730468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+95, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -415.414947509765625, 1207.8629150390625, -0.84746980667114257, 3.742103815078735351, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
(@CGUID+96, 130160, 1643, 8721, 9130, '0', 0, 0, 0, 0, -361.296875, 1223.1597900390625, 0.527802824974060058, 5.972630500793457031, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257); -- Saltrock Terrapin (Area: Hangman's Point - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+96;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Invasive Quillrat
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Invasive Quillrat - 145953 - Cosmetic - Sleep Zzz
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Invasive Quillrat - 145953 - Cosmetic - Sleep Zzz
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Invasive Quillrat - 145953 - Cosmetic - Sleep Zzz
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Invasive Quillrat - 145953 - Cosmetic - Sleep Zzz
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Invasive Quillrat
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Invasive Quillrat
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Invasive Quillrat - 145953 - Cosmetic - Sleep Zzz
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Invasive Quillrat
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Invasive Quillrat - 145953 - Cosmetic - Sleep Zzz
(@CGUID+70, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Invasive Quillrat
(@CGUID+80, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 3, ''); -- Adela Hawthorne

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 128494;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(128494, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 128494 (Adela Hawthorne)

-- Template
UPDATE `creature_template` SET `unit_flags`=0x0, `unit_flags3`=0x4000000 WHERE `entry`=125401; -- Invasive Quillrat

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`IN (125453,126677,126434,127714,127743,128494,145239,125401,125452) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125453 AND `DifficultyID`=0); -- 125453 (Quillrat Matriarch) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=126677 AND `DifficultyID`=0); -- 126677 (Siltfeeder Ray) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=126434 AND `DifficultyID`=0); -- 126434 (Coldscale Puffer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=127714 AND `DifficultyID`=0); -- 127714 (Bella) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=127743 AND `DifficultyID`=0); -- 127743 (Auntie Amanda Hale) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `StaticFlags3`=0x40000, `VerifiedBuild`=60257 WHERE (`Entry`=128494 AND `DifficultyID`=0); -- 128494 (Adela Hawthorne) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `VerifiedBuild`=60257 WHERE (`Entry`=145239 AND `DifficultyID`=0); -- 145239 (Inert Tide Watcher) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125401 AND `DifficultyID`=0); -- 125401 (Invasive Quillrat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=125452 AND `DifficultyID`=0); -- 125452 (Shallows Saurolisk) - CanSwim

-- Quest
UPDATE `quest_template_addon` SET `NextQuestID` = 48111, `ExclusiveGroup` = -48109 WHERE `ID` IN (48109,48110);

-- Path for Coastal Osprey
SET @MOVERGUID := @CGUID+14;
SET @ENTRY := 130359;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5453, 'Coastal Osprey - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -281.4162, 1359.3043, 28.418201, NULL, 0),
(@PATH, 1, -271.8163, 1366.0021, 28.418201, NULL, 0),
(@PATH, 2, -260.3841, 1368.5162, 28.418201, NULL, 0),
(@PATH, 3, -248.85995, 1366.464, 28.418201, NULL, 0),
(@PATH, 4, -238.99838, 1360.158, 28.418201, NULL, 0),
(@PATH, 5, -232.30067, 1350.5581, 28.418201, NULL, 0),
(@PATH, 6, -229.78653, 1339.1259, 28.418201, NULL, 0),
(@PATH, 7, -231.83867, 1327.6018, 28.418201, NULL, 0),
(@PATH, 8, -238.1447, 1317.7402, 28.418201, NULL, 0),
(@PATH, 9, -247.74458, 1311.0425, 28.418201, NULL, 0),
(@PATH, 10, -259.17682, 1308.5283, 28.418201, NULL, 0),
(@PATH, 11, -270.70093, 1310.5804, 28.418201, NULL, 0),
(@PATH, 12, -280.56253, 1316.8865, 28.418201, NULL, 0),
(@PATH, 13, -287.26022, 1326.4865, 28.418201, NULL, 0),
(@PATH, 14, -289.77438, 1337.9186, 28.418201, NULL, 0),
(@PATH, 15, -287.72223, 1349.4427, 28.418201, NULL, 0),
(@PATH, 16, -281.4162, 1359.3043, 28.418201, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Coastal Osprey
SET @MOVERGUID := @CGUID+75;
SET @ENTRY := 130359;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5454, 'Coastal Osprey - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -288.6367, 1592.082, 21.641161, NULL, 0),
(@PATH, 1, -279.0368, 1598.7798, 21.641161, NULL, 0),
(@PATH, 2, -267.60458, 1601.294, 21.641161, NULL, 0),
(@PATH, 3, -256.08044, 1599.2417, 21.641161, NULL, 0),
(@PATH, 4, -246.21887, 1592.9357, 21.641161, NULL, 0),
(@PATH, 5, -239.52116, 1583.3358, 21.641161, NULL, 0),
(@PATH, 6, -237.00702, 1571.9036, 21.641161, NULL, 0),
(@PATH, 7, -239.05916, 1560.3795, 21.641161, NULL, 0),
(@PATH, 8, -245.36519, 1550.518, 21.641161, NULL, 0),
(@PATH, 9, -254.96507, 1543.8202, 21.641161, NULL, 0),
(@PATH, 10, -266.3973, 1541.306, 21.641161, NULL, 0),
(@PATH, 11, -277.92142, 1543.3582, 21.641161, NULL, 0),
(@PATH, 12, -287.78302, 1549.6642, 21.641161, NULL, 0),
(@PATH, 13, -294.4807, 1559.2642, 21.641161, NULL, 0),
(@PATH, 14, -296.99487, 1570.6963, 21.641161, NULL, 0),
(@PATH, 15, -294.94272, 1582.2205, 21.641161, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Saltrock Terrapin
SET @MOVERGUID := @CGUID+86;
SET @ENTRY := 130160;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Saltrock Terrapin - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -395.24307, 1221.8021, 0.24742684, NULL, 0),
(@PATH, 1, -399.2639, 1223.3108, 0.28107625, NULL, 0),
(@PATH, 2, -404.9045, 1225.3611, 0.34182924, NULL, 0),
(@PATH, 3, -411.44272, 1227.6198, 0.4267452, NULL, 0),
(@PATH, 4, -419.3125, 1228.4462, 0.38369226, NULL, 0),
(@PATH, 5, -426.43576, 1228.658, 0.48360324, NULL, 0),
(@PATH, 6, -436.3941, 1228.6841, 0.24700023, NULL, 12946),
(@PATH, 7, -426.43576, 1228.658, 0.48360324, NULL, 0),
(@PATH, 8, -419.3125, 1228.4462, 0.38369226, NULL, 0),
(@PATH, 9, -411.44272, 1227.6198, 0.4267452, NULL, 0),
(@PATH, 10, -404.9045, 1225.3611, 0.34182924, NULL, 0),
(@PATH, 11, -399.2639, 1223.3108, 0.28107625, NULL, 0),
(@PATH, 12, -395.24307, 1221.8021, 0.24742684, NULL, 0),
(@PATH, 13, -392.2604, 1219.724, 0.19466807, NULL, 0),
(@PATH, 14, -391.48438, 1216.6858, 0.010944191, NULL, 13171);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
