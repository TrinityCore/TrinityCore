SET @CGUID := 5000334;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 75422, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1199.3941650390625, 40.19097137451171875, 25.9039459228515625, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+1, 75422, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1164.533447265625, -45.340087890625, 41.14262771606445312, 3.882111549377441406, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%)
(@CGUID+2, 75422, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1208.979248046875, -92.8111953735351562, 50.83480072021484375, 3.538788557052612304, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+3, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1239.635986328125, -132.80596923828125, 57.30201339721679687, 2.888794183731079101, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+4, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1166.0848388671875, -109.616493225097656, 44.49292373657226562, 3.600873708724975585, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+5, 88975, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1226.1302490234375, -96.9427108764648437, 52.04950714111328125, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Royal Moth (Area: Moonflower Valley - Difficulty: 0) CreateObject1
(@CGUID+6, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1212.6781005859375, -151.413406372070312, 47.4642333984375, 3.961555242538452148, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+7, 75422, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1247.3251953125, -148.022506713867187, 59.43047332763671875, 0.679618239402770996, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+8, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1151.720458984375, -130.227432250976562, 39.26608657836914062, 0.103404685854911804, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+9, 75486, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1198.6754150390625, -164.357330322265625, 42.71991348266601562, 2.231496810913085937, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Prairie Dog (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1268.8951416015625, -155.251373291015625, 60.84051132202148437, 5.754829883575439453, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+11, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1145.6197509765625, -128.965286254882812, 37.0440826416015625, 2.020424127578735351, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%, 109525 - Sleeping Sleep)
(@CGUID+12, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1200.7227783203125, -173.048843383789062, 42.7629241943359375, 0.932375311851501464, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1
(@CGUID+13, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1195.622802734375, -173.14544677734375, 41.440460205078125, 0.881561458110809326, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1
(@CGUID+14, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1202.0068359375, -175.335098266601562, 43.16703033447265625, 0.863547742366790771, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1
(@CGUID+15, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1198.698974609375, -172.817733764648437, 42.17542648315429687, 0.842774569988250732, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1
(@CGUID+16, 75486, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1169.1962890625, -214.01947021484375, 30.58735466003417968, 0.783324897289276123, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Prairie Dog (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 75486, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1086.245361328125, -196.109542846679687, 2.349494218826293945, 4.107585906982421875, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Prairie Dog (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1177.9718017578125, -227.819610595703125, 30.71281242370605468, 2.898982524871826171, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+19, 75486, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1084.2860107421875, -180.881057739257812, 1.290332198143005371, 3.631895065307617187, 120, 8, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Prairie Dog (Area: Moonflower Valley - Difficulty: 0) CreateObject1
(@CGUID+20, 88975, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1255.0260009765625, -226.574661254882812, 44.79790878295898437, 0, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Royal Moth (Area: Moonflower Valley - Difficulty: 0) CreateObject1
(@CGUID+21, 75422, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1195.223876953125, -272.384033203125, 25.62535667419433593, 2.716824054718017578, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+22, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1242.76220703125, -227.944442749023437, 46.64191436767578125, 5.233479022979736328, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+23, 75422, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1263.84521484375, -211.53448486328125, 46.52070999145507812, 4.455562591552734375, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+24, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1237.951416015625, -221.520828247070312, 51.36392974853515625, 0.30944332480430603, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%, 109525 - Sleeping Sleep)
(@CGUID+25, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1180.11474609375, -268.940399169921875, 22.77799797058105468, 5.627965927124023437, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+26, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1198.5758056640625, -281.270721435546875, 23.95895004272460937, 1.117637872695922851, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+27, 75422, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1288.201416015625, -273.7562255859375, 22.92155265808105468, 3.380176544189453125, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+28, 82308, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1206.4617919921875, -302.321197509765625, 17.69097328186035156, 4.958888530731201171, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+29, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1205.171875, -306.477447509765625, 16.64410400390625, 0.61881422996520996, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+30, 78276, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1206.65283203125, -304.80035400390625, 17.13541793823242187, 5.83009958267211914, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Silverpelt Charger (Area: Moonflower Valley - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+31, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1247.8177490234375, -330.276031494140625, 9.4432220458984375, 2.151513338088989257, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+32, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1320.5408935546875, -298.996917724609375, 12.49213123321533203, 3.110872507095336914, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+33, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1272.6805419921875, -339.885406494140625, 7.41773223876953125, 5.279338836669921875, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+34, 75422, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1255.3004150390625, -334.497344970703125, 8.327250480651855468, 5.684625148773193359, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+35, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1310.3470458984375, -317.347015380859375, 14.63452339172363281, 5.967304706573486328, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+36, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1273.7603759765625, -345.642364501953125, 7.330327510833740234, 0.93396848440170288, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+37, 78276, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1275.2916259765625, -343.17535400390625, 7.108081817626953125, 5.91694498062133789, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Silverpelt Charger (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+38, 78276, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1282.515625, -344.98089599609375, 5.726770877838134765, 3.747088193893432617, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Silverpelt Charger (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+39, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1294.376708984375, -354.354156494140625, 4.175259590148925781, 5.279338836669921875, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%, 109525 - Sleeping Sleep)
(@CGUID+40, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1339.653564453125, -322.39654541015625, 8.754564285278320312, 1.017993092536926269, 120, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%) (possible waypoints or random movement)
(@CGUID+41, 82308, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1285.2413330078125, -366.00347900390625, 5.114583492279052734, 1.632222652435302734, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Shadowmoon Stalker (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+42, 78276, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1284.7742919921875, -362.611114501953125, 5.451389312744140625, 5.483483791351318359, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Silverpelt Charger (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%, 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+43, 75422, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1273.5308837890625, -399.669342041015625, 3.420484542846679687, 2.196721076965332031, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Wisptail Hare (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123978 - Mod Scale 95-120%) (possible waypoints or random movement)
(@CGUID+44, 82452, 1116, 6719, 6921, '0', 0, 0, 0, 0, 1400.8316650390625, -320.625, 18.26710319519042968, 4.791634559631347656, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 53989), -- Ancient Pearltusk (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk)
(@CGUID+45, 74146, 1116, 6719, 6921, '0', 0, 0, 0, 1, 1390.126708984375, -375.88714599609375, 5.445678234100341796, 3.746661663055419921, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Podling Nibbler (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+46, 74148, 1116, 6719, 6921, '0', 0, 0, 0, 1, 1403.625, -368.739593505859375, 7.855213642120361328, 0.396663457155227661, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Podling Squirt (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+47, 74148, 1116, 6719, 6921, '0', 0, 0, 0, 1, 1395.5867919921875, -360.4288330078125, 8.378731727600097656, 0.274863243103027343, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Podling Squirt (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+48, 74146, 1116, 6719, 6921, '0', 0, 0, 0, 1, 1390.920166015625, -363.625, 7.852959632873535156, 1.254290223121643066, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Podling Nibbler (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+49, 74148, 1116, 6719, 6921, '0', 0, 0, 0, 1, 1385.9583740234375, -368.470489501953125, 6.788760662078857421, 3.546651363372802734, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Podling Squirt (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+50, 74146, 1116, 6719, 6921, '0', 0, 0, 0, 1, 1391.1458740234375, -370.4132080078125, 6.854771614074707031, 4.820009231567382812, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Podling Nibbler (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+51, 74148, 1116, 6719, 6921, '0', 0, 0, 0, 1, 1397.0972900390625, -375.583343505859375, 5.790297508239746093, 2.131632328033447265, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Podling Squirt (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+52, 74146, 1116, 6719, 6921, '0', 0, 0, 0, 1, 1402.3316650390625, -375.1475830078125, 6.35229349136352539, 5.754480838775634765, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989); -- Podling Nibbler (Area: Plains of Serenity - Difficulty: 0) CreateObject1 (Auras: 123167 - Mod Scale 95-100%)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+52;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123167 109525'), -- Shadowmoon Stalker - 123167 - Mod Scale 95-100%, 109525 - Sleeping Sleep
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123167 109525'), -- Shadowmoon Stalker - 123167 - Mod Scale 95-100%, 109525 - Sleeping Sleep
(@CGUID+30, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '123978 145363'), -- Silverpelt Charger - 123978 - Mod Scale 95-120%, 145363 - Permanent Feign Death (Stun, Untrackable, Immune)
(@CGUID+33, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123167'), -- Shadowmoon Stalker - 123167 - Mod Scale 95-100%
(@CGUID+37, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '123978 145363'), -- Silverpelt Charger - 123978 - Mod Scale 95-120%, 145363 - Permanent Feign Death (Stun, Untrackable, Immune)
(@CGUID+38, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '123978 145363'), -- Silverpelt Charger - 123978 - Mod Scale 95-120%, 145363 - Permanent Feign Death (Stun, Untrackable, Immune)
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123167 109525'), -- Shadowmoon Stalker - 123167 - Mod Scale 95-100%, 109525 - Sleeping Sleep
(@CGUID+42, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '123978 145363'); -- Silverpelt Charger - 123978 - Mod Scale 95-120%, 145363 - Permanent Feign Death (Stun, Untrackable, Immune)

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (88975, 75422, 74148);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(88975, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 88975 (Royal Moth)
(75422, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123978'), -- 75422 (Wisptail Hare) - Mod Scale 95-120%
(74148, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123167'); -- 74148 (Podling Squirt) - Mod Scale 95-100%

-- Difficulty & Model
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=53989 WHERE (`Entry`=88975 AND `DifficultyID`=0); -- Royal Moth
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53989 WHERE (`Entry`=82308 AND `DifficultyID`=0); -- Shadowmoon Stalker
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=53989 WHERE (`Entry`=75422 AND `DifficultyID`=0); -- Wisptail Hare

-- Path for CGUID+12
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+12;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+12, @CGUID+12, 0, 0, 515, 0, 0),
(@CGUID+12, @CGUID+14, 3, 70, 515, 0, 0),
(@CGUID+12, @CGUID+15, 3, 290, 515, 0, 0),
(@CGUID+12, @CGUID+13, 6, 310, 515, 0, 0);

SET @ENTRY := 82308;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Shadowmoon Stalker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1227.844, -154.4931, 54.01735, NULL, 0),
(@PATH, 1, 1253.741, -165.6875, 56.93204, NULL, 0),
(@PATH, 2, 1259.101, -190.4774, 50.3604, NULL, 0),
(@PATH, 3, 1264.745, -213.3767, 46.22044, NULL, 0),
(@PATH, 4, 1272.313, -237.2051, 36.3636, NULL, 0),
(@PATH, 5, 1281.948, -262.757, 29.51261, NULL, 0),
(@PATH, 6, 1289.614, -286.5371, 18.28436, NULL, 0),
(@PATH, 7, 1269.726, -310.2778, 10.89239, NULL, 0),
(@PATH, 8, 1251.866, -313.776, 13.35365, NULL, 0),
(@PATH, 9, 1242.771, -309.2413, 14.63742, NULL, 0),
(@PATH, 10, 1225.333, -292.7422, 19.10599, NULL, 0),
(@PATH, 11, 1210.085, -276.0938, 25.59332, NULL, 0),
(@PATH, 12, 1196.264, -255.8767, 29.21887, NULL, 0),
(@PATH, 13, 1185.927, -232.4618, 31.31764, NULL, 0),
(@PATH, 14, 1181.835, -206.7014, 32.16679, NULL, 0),
(@PATH, 15, 1191.476, -185.5104, 39.98606, NULL, 0),
(@PATH, 16, 1208.751, -162.2305, 45.83586, NULL, 0);

UPDATE `creature` SET `position_x`= 1227.844, `position_y`= -154.4931, `position_z`= 54.01735, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+12, @PATH, 1);

-- Path for CGUID+31
SET @ENTRY := 82308;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Shadowmoon Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1307.01, -378.3559, 8.115505, NULL, 4401),
(@PATH, 1, 1293.613, -379.0121, 6.669366, NULL, 0),
(@PATH, 2, 1277.786, -371.7639, 4.647415, NULL, 5777),
(@PATH, 3, 1268.691, -363.3733, 6.102775, NULL, 3218),
(@PATH, 4, 1256.111, -344.191, 7.834034, NULL, 0),
(@PATH, 5, 1247.818, -330.276, 9.443222, NULL, 16535),
(@PATH, 6, 1256.111, -344.191, 7.834034, NULL, 0),
(@PATH, 7, 1268.691, -363.3733, 6.102775, NULL, 0),
(@PATH, 8, 1277.786, -371.7639, 4.647415, NULL, 4743),
(@PATH, 9, 1293.613, -379.0121, 6.669366, NULL, 0);

UPDATE `creature` SET `position_x`= 1307.01, `position_y`= -378.3559, `position_z`= 8.115505, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+31;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+31;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+31, @PATH, 1);
