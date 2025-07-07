SET @CGUID := 7002767;
SET @OGUID := 7000583;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 127088, 1643, 8721, 9222, '0', 0, 0, 0, 0, 430.31597900390625, 1894.2379150390625, 2.692708253860473632, 1.854488372802734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Ethel Rose (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+1, 128798, 1643, 8721, 9222, '0', 0, 0, 0, 0, 376.51202392578125, 1874.466796875, 7.067935466766357421, 2.917942762374877929, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bramble Hare (Area: Autumnvale - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+2, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 418.75347900390625, 1891.234375, 2.760067939758300781, 1.200674414634704589, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1 (Auras: 251603 - Worship)
(@CGUID+3, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 391.734375, 1882.21533203125, 5.429356098175048828, 2.373861312866210937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+4, 126965, 1643, 8721, 9222, '0', 0, 0, 0, 0, 421.78472900390625, 1894.8836669921875, 2.74259352684020996, 1.118398785591125488, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Soloman Howe (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+5, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 390.001739501953125, 1884.5399169921875, 5.590527057647705078, 5.501505374908447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+6, 127080, 1643, 8721, 9222, '0', 0, 0, 0, 0, 426.446197509765625, 1893.3472900390625, 2.669977664947509765, 1.56410384178161621, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Lord Autumnvale (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+7, 127292, 1643, 8721, 9222, '0', 0, 0, 0, 0, 424.993072509765625, 1905.298583984375, 2.711433887481689453, 4.875752449035644531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wicker Man (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+8, 127396, 1643, 8721, 9222, '0', 0, 0, 0, 0, 425.967010498046875, 1867.689208984375, 1.868055582046508789, 5.925806999206542968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Initiate Peony (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+9, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 411.696197509765625, 1900.517333984375, 2.990068912506103515, 0.408385097980499267, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1 (Auras: 251603 - Worship)
(@CGUID+10, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 426.0069580078125, 1889.3489990234375, 2.531386137008666992, 1.673281669616699218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1 (Auras: 251603 - Worship)
(@CGUID+11, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 431.453125, 1891.560791015625, 2.831655025482177734, 1.946269035339355468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1 (Auras: 251603 - Worship)
(@CGUID+12, 128798, 1643, 8721, 9222, '0', 0, 0, 0, 0, 407.00274658203125, 1871.1103515625, 3.963227033615112304, 1.953116178512573242, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bramble Hare (Area: Autumnvale - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+13, 127089, 1643, 8721, 9222, '0', 0, 0, 0, 0, 419.005218505859375, 1897.46533203125, 2.74889540672302246, 0.763827621936798095, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Nora Willow (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+14, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 438.954864501953125, 1897.795166015625, 3.382175445556640625, 2.433756351470947265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1 (Auras: 251603 - Worship)
(@CGUID+15, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 439.40625, 1903.0660400390625, 3.733983278274536132, 2.859854698181152343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1 (Auras: 251603 - Worship)
(@CGUID+16, 128798, 1643, 8721, 9222, '0', 0, 0, 0, 0, 358.333984375, 1937.602783203125, 15.39729976654052734, 4.712388992309570312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bramble Hare (Area: Autumnvale - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 127393, 1643, 8721, 9222, '0', 0, 0, 0, 0, 426.9913330078125, 1866.8021240234375, 1.773882389068603515, 2.493089914321899414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Wickerite Initiate (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+18, 127087, 1643, 8721, 9222, '0', 0, 0, 0, 0, 433.7100830078125, 1896.4010009765625, 2.833009719848632812, 2.224264144897460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Daniel Rowan (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+19, 128798, 1643, 8721, 9222, '0', 0, 0, 0, 0, 375, 1910.416015625, 7.355776786804199218, 0.146381333470344543, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bramble Hare (Area: Autumnvale - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 128798, 1643, 8721, 9222, '0', 0, 0, 0, 0, 358.12249755859375, 1808.803955078125, 8.568509101867675781, 4.337918281555175781, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bramble Hare (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+21, 128798, 1643, 8721, 9222, '0', 0, 0, 0, 0, 354.895233154296875, 1727.6512451171875, 9.724596023559570312, 2.653474330902099609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bramble Hare (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+22, 128798, 1643, 8721, 9222, '0', 0, 0, 0, 0, 415.6953125, 1728.095703125, 7.145865440368652343, 2.28069925308227539, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568), -- Bramble Hare (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+23, 127297, 1643, 8721, 9222, '0', 0, 0, 0, 0, 349.564239501953125, 1717.498291015625, 9.759129524230957031, 5.628334522247314453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Lydia Maldus (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+24, 127296, 1643, 8721, 9222, '0', 0, 0, 0, 0, 348.817718505859375, 1715.8489990234375, 9.7722625732421875, 0.26449558138847351, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- David Maldus (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+25, 129984, 1643, 8721, 9222, '0', 0, 0, 0, 0, 346.98089599609375, 1711.6805419921875, 10.00902271270751953, 0.70981764793395996, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60568), -- Anna Ridgeley (Area: Autumnvale - Difficulty: 0) CreateObject1
(@CGUID+26, 128798, 1643, 8721, 9222, '0', 0, 0, 0, 0, 342.060546875, 1704.4912109375, 11.57847213745117187, 4.110302925109863281, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60568); -- Bramble Hare (Area: Autumnvale - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '251603'), -- Wickerite Initiate - 251603 - Worship
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 13946, 0, 0, 0, ''), -- Wicker Man
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '251603'), -- Wickerite Initiate - 251603 - Worship
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '251603'), -- Wickerite Initiate - 251603 - Worship
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '251603'), -- Wickerite Initiate - 251603 - Worship
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '251603'), -- Wickerite Initiate - 251603 - Worship
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '251603'), -- Wickerite Initiate - 251603 - Worship
(@CGUID+23, 0, 0, 0, 0, 0, 1, 1, 605, 0, 0, 0, 0, ''), -- Lydia Maldus
(@CGUID+25, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Anna Ridgeley

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+22;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 276203, 1643, 8721, 9222, '0', 0, 0, 423.838531494140625, 1866.5572509765625, 2.885762453079223632, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Herbs (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+1, 276202, 1643, 8721, 9222, '0', 0, 0, 422.817718505859375, 1867.592041015625, 2.04754185676574707, 0.564048051834106445, 0, 0, 0.278300285339355468, 0.960494101047515869, 120, 255, 1, 60568), -- Grain (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+2, 276201, 1643, 8721, 9222, '0', 0, 0, 423.618072509765625, 1867.5833740234375, 1.958167672157287597, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Scrolls (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+3, 276200, 1643, 8721, 9222, '0', 0, 0, 423.9444580078125, 1869.4305419921875, 1.983998417854309082, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Entrails (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+4, 276206, 1643, 8721, 9222, '0', 0, 0, 423.274322509765625, 1868.4166259765625, 1.98486495018005371, 4.668522834777832031, 0, 0, -0.72244453430175781, 0.691428899765014648, 120, 255, 1, 60568), -- Bundle of Wicker (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+5, 276205, 1643, 8721, 9222, '0', 0, 0, 424.852447509765625, 1868.2864990234375, 1.88775801658630371, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Bones (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+6, 276204, 1643, 8721, 9222, '0', 0, 0, 422.302093505859375, 1869.35595703125, 2.069600105285644531, 0, 0, 0, 0, 1, 120, 255, 1, 60568), -- Fruit (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+7, 290145, 1643, 8721, 9222, '0', 0, 0, 451.2413330078125, 1850.53125, 1.137630581855773925, 5.65312957763671875, 0, 0, -0.30984306335449218, 0.950787723064422607, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+8, 290145, 1643, 8721, 9222, '0', 0, 0, 444.328125, 1904.1510009765625, 3.999552011489868164, 3.163166284561157226, 0, 0, -0.99994182586669921, 0.01078648492693901, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+9, 290145, 1643, 8721, 9222, '0', 0, 0, 493.036468505859375, 1911.3819580078125, 3.478535175323486328, 5.25316619873046875, 0, 0, -0.49254322052001953, 0.870287954807281494, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+10, 290146, 1643, 8721, 9222, '0', 0, 0, 490.114593505859375, 1812.701416015625, 16.24561882019042968, 5.453990459442138671, 0, 0, -0.40282154083251953, 0.915278553962707519, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+11, 290145, 1643, 8721, 9222, '0', 0, 0, 410.352447509765625, 1960.68408203125, 2.157674789428710937, 5.46425485610961914, 0, 0, -0.39811897277832031, 0.917333781719207763, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+12, 290146, 1643, 8721, 9222, '0', 0, 0, 476.953125, 1841.296875, 1.222588658332824707, 2.033373832702636718, 0, 0, 0.850369453430175781, 0.526186108589172363, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+13, 290145, 1643, 8721, 9222, '0', 0, 0, 439.904510498046875, 1891.7916259765625, 3.867586851119995117, 2.384779930114746093, 0, 0, 0.929254531860351562, 0.36944010853767395, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+14, 278528, 1643, 8721, 9222, '0', 0, 0, 351.125, 1715.7708740234375, 9.722564697265625, 0.095993652939796447, 0, 0, 0.047978401184082031, 0.998848378658294677, 120, 255, 1, 60568), -- Campfire (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+15, 290146, 1643, 8721, 9222, '0', 0, 0, 526.69097900390625, 1958.53125, 2.11001133918762207, 3.56854248046875, 0, 0, -0.97730064392089843, 0.21185709536075592, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+16, 290145, 1643, 8721, 9222, '0', 0, 0, 489.114593505859375, 1807.6458740234375, 16.38996505737304687, 0.02008853293955326, 0, 0, 0.010044097900390625, 0.999949514865875244, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+17, 290145, 1643, 8721, 9222, '0', 0, 0, 493.3975830078125, 1775.5035400390625, 20.11948394775390625, 0.6604844331741333, 0, 0, 0.32427215576171875, 0.945963859558105468, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+18, 276403, 1643, 8721, 9222, '0', 0, 0, 344.692718505859375, 2068.522705078125, 8.822121620178222656, 4.843312263488769531, 0, 0, -0.65933704376220703, 0.751847505569458007, 120, 255, 1, 60568), -- Cage (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+19, 290145, 1643, 8721, 9222, '0', 0, 0, 559.703125, 1930.923583984375, 9.499957084655761718, 3.764120817184448242, 0, 0, -0.95194721221923828, 0.306262135505676269, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+20, 290145, 1643, 8721, 9222, '0', 0, 0, 495.217010498046875, 1814.423583984375, 16.21969413757324218, 5.121554374694824218, 0, 0, -0.5487060546875, 0.83601534366607666, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+21, 290145, 1643, 8721, 9222, '0', 0, 0, 556.234375, 1831.8836669921875, 23.48208045959472656, 4.055953502655029296, 0, 0, -0.89730072021484375, 0.441419750452041625, 120, 255, 1, 60568), -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1
(@OGUID+22, 290145, 1643, 8721, 9222, '0', 0, 0, 563.57464599609375, 1921.217041015625, 9.597222328186035156, 2.372748374938964843, 0, 0, 0.927015304565429687, 0.375023514032363891, 120, 255, 1, 60568); -- Abandoned Effigy (Area: Autumnvale - Difficulty: 0) CreateObject1

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry`IN (129984,127296,127297,127087,127038,126974,127089,126973,127104,127396,127292,127080,126965,127393,128798,127088) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=129984 AND `DifficultyID`=0); -- 129984 (Anna Ridgeley) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127296 AND `DifficultyID`=0); -- 127296 (David Maldus) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127297 AND `DifficultyID`=0); -- 127297 (Lydia Maldus) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127087 AND `DifficultyID`=0); -- 127087 (Daniel Rowan) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60568 WHERE (`Entry`=127038 AND `DifficultyID`=0); -- 127038 (Barbthorn Hive) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60568 WHERE (`Entry`=126974 AND `DifficultyID`=0); -- 126974 (Barbthorn Worker) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127089 AND `DifficultyID`=0); -- 127089 (Nora Willow) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60568 WHERE (`Entry`=126973 AND `DifficultyID`=0); -- 126973 (Barbthorn Drone) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60568 WHERE (`Entry`=127104 AND `DifficultyID`=0); -- 127104 (Credit - Offering Given) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127396 AND `DifficultyID`=0); -- 127396 (Initiate Peony) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60568 WHERE (`Entry`=127292 AND `DifficultyID`=0); -- 127292 (Wicker Man) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127080 AND `DifficultyID`=0); -- 127080 (Lord Autumnvale) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=126965 AND `DifficultyID`=0); -- 126965 (Soloman Howe) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127393 AND `DifficultyID`=0); -- 127393 (Wickerite Initiate) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=128798 AND `DifficultyID`=0); -- 128798 (Bramble Hare) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60568 WHERE (`Entry`=127088 AND `DifficultyID`=0); -- 127088 (Ethel Rose) - CanSwim

-- Quest
DELETE FROM `quest_details` WHERE `ID` IN (48677,48678);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48677, 5, 1, 6, 0, 0, 0, 0, 0, 60568), -- Wicker Worship
(48678, 6, 1, 25, 0, 0, 0, 0, 0, 60568); -- Questionable Offerings

DELETE FROM `creature_queststarter` WHERE (`id`=127296 AND `quest`=48677) OR (`id`=127080 AND `quest`=48678);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(127296, 48677, 60568), -- Wicker Worship offered by David Maldus
(127080, 48678, 60568); -- Questionable Offerings offered by Lord Autumnvale

DELETE FROM `creature_questender` WHERE (`id`=127080 AND `quest`=48677);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(127080, 48677, 60568); -- Wicker Worship ended by Lord Autumnvale

DELETE FROM `quest_template_addon` WHERE `ID` = 48678;
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(48678, 0, 0, 0, 48677, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Questionable Offerings
