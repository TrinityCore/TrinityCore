SET @CGUID := 7000364;
SET @OGUID := 7000168;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 295051, 1643, 9042, 9579, '0', 0, 0, 3441.21875, -421.598876953125, 7.794084072113037109, 1.125736594200134277, 0, 0, 0.533614158630371093, 0.845728039741516113, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+1, 295050, 1643, 9042, 9579, '0', 0, 0, 3443.36328125, -421.15594482421875, 7.794084072113037109, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+2, 295049, 1643, 9042, 9579, '0', 0, 0, 3445.842041015625, -414.021148681640625, 7.794084072113037109, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+3, 294711, 1643, 9042, 9579, '0', 0, 0, 3349.053955078125, -344.736114501953125, 15.80430126190185546, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+4, 295048, 1643, 9042, 9579, '0', 0, 0, 3444.24169921875, -416.453125, 7.794084072113037109, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+5, 295055, 1643, 9042, 9579, '0', 0, 0, 3443.762939453125, -425.733795166015625, 7.823177337646484375, 4.302238941192626953, 0, 0, -0.83628559112548828, 0.5482940673828125, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+6, 295054, 1643, 9042, 9579, '0', 0, 0, 3441.719970703125, -424.44921875, 7.823177337646484375, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+7, 295053, 1643, 9042, 9579, '0', 0, 0, 3440.671875, -423.75396728515625, 7.823177337646484375, 4.00553131103515625, 0, 0, -0.9081430435180664, 0.418660014867782592, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+8, 295052, 1643, 9042, 9579, '0', 0, 0, 3442.56787109375, -419.377471923828125, 7.794084072113037109, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+9, 294713, 1643, 9042, 9579, '0', 0, 0, 3342.913330078125, -338.9132080078125, 15.80521011352539062, 2.12057352066040039, 0, 0, 0.872495651245117187, 0.488621890544891357, 120, 255, 1, 54762), -- Chair (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+10, 294712, 1643, 9042, 9579, '0', 0, 0, 3347.741455078125, -340.125, 15.80521011352539062, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 120, 255, 1, 54762), -- Stove (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+11, 295057, 1643, 9042, 9579, '0', 0, 0, 3451.556396484375, -410.005523681640625, 7.698925018310546875, 5.866266250610351562, 0, 0, -0.20695304870605468, 0.97835087776184082, 120, 255, 1, 54762), -- Fire (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+12, 295056, 1643, 9042, 9579, '0', 0, 0, 3442.771728515625, -425.065277099609375, 7.823177337646484375, 4.127707481384277343, 0, 0, -0.880889892578125, 0.473321229219436645, 120, 255, 1, 54762), -- Stool (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+13, 296877, 1643, 9042, 9579, '0', 0, 0, 3317.94970703125, -328.380218505859375, 13.34244823455810546, 3.970627307891845703, 0, 0, -0.91531085968017578, 0.402748137712478637, 120, 255, 1, 54762), -- Mailbox (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+14, 291132, 1643, 9042, 9579, '0', 0, 0, 3426.7509765625, -448.95660400390625, 10.82904052734375, 5.013007164001464843, 0, 0, -0.59324932098388671, 0.805018782615661621, 120, 255, 1, 54762), -- Bone (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+15, 292545, 1643, 9042, 9579, '0', 0, 0, 3243.585205078125, -521.7569580078125, 1.267088532447814941, 4.341106414794921875, 0, 0, -0.82547283172607421, 0.564441800117492675, 120, 255, 1, 54762), -- Weapon Rack (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+16, 291132, 1643, 9042, 9579, '0', 0, 0, 3405.470458984375, -440.880218505859375, 13.84467887878417968, 1.691165447235107421, 0, 0, 0.748357772827148437, 0.663295328617095947, 120, 255, 1, 54762), -- Bone (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+17, 291132, 1643, 9042, 9579, '0', 0, 0, 3426.98779296875, -447.786468505859375, 10.87959575653076171, 4.05368661880493164, 0, 0, -0.89780044555664062, 0.440402477979660034, 120, 255, 1, 54762), -- Bone (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+18, 291132, 1643, 9042, 9579, '0', 0, 0, 3406.9140625, -443.064239501953125, 13.85734844207763671, 1.691165447235107421, 0, 0, 0.748357772827148437, 0.663295328617095947, 120, 255, 1, 54762), -- Bone (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+19, 291132, 1643, 9042, 9579, '0', 0, 0, 3405.163330078125, -442.229156494140625, 13.86177253723144531, 0.333484798669815063, 0, 0, 0.165970802307128906, 0.98613065481185913, 120, 255, 1, 54762), -- Bone (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+20, 291132, 1643, 9042, 9579, '0', 0, 0, 3407.224853515625, -440.857635498046875, 13.83086967468261718, 2.694235801696777343, 0, 0, 0.975088119506835937, 0.221817851066589355, 120, 255, 1, 54762), -- Bone (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+21, 277419, 1643, 9042, 9579, '0', 0, 0, 2949.50439453125, -99.939239501953125, -0.15199999511241912, 4.412836074829101562, 0, 0, -0.8047027587890625, 0.593677937984466552, 120, 255, 1, 54762), -- Cylinder Collision (2.5 Scale) (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+22, 298912, 1643, 9042, 9579, '0', 0, 0, 3440.279541015625, -424.914947509765625, 9.003243446350097656, 0.65004122257232666, 0, 0, 0.31932830810546875, 0.947644174098968505, 120, 255, 1, 54762), -- Spring-Loaded Spikes (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+23, 291132, 1643, 9042, 9579, '0', 0, 0, 3425.233642578125, -447.80902099609375, 10.89545059204101562, 0.114566504955291748, 0, 0, 0.057251930236816406, 0.998359739780426025, 120, 255, 1, 54762), -- Bone (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+24, 291132, 1643, 9042, 9579, '0', 0, 0, 3424.92626953125, -449.157989501953125, 10.89236164093017578, 1.745003461837768554, 0, 0, 0.765939712524414062, 0.64291238784790039, 120, 255, 1, 54762), -- Bone (Area: Tidecross - Difficulty: 0) CreateObject1
(@OGUID+25, 292545, 1643, 9042, 9579, '0', 0, 0, 3248.560791015625, -569.76910400390625, 15.49766731262207031, 5.017819404602050781, 0, 0, -0.59131050109863281, 0.806443989276885986, 120, 255, 1, 54762); -- Weapon Rack (Area: Tidecross - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+1, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+2, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+4, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+5, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+6, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+7, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+8, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+11, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Fire
(@OGUID+12, 0, 0, 0.488621234893798828, 0.872496008872985839, 0, 0), -- Stool
(@OGUID+22, 0, 0, 0, 1, 10427, 0); -- Spring-Loaded Spikes

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+47;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 134721, 1643, 9042, 9579, '0', 0, 0, 0, 1, 3385.50439453125, -426.213531494140625, 13.984375, 5.759586334228515625, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Stalwart Revolutionary (Area: Tidecross - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 126642, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3301.605712890625, -407.547332763671875, -0.92706239223480224, 3.90489506721496582, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crab (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+2, 138280, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3297.99755859375, -410.6275634765625, -1.85077071189880371, 2.114041328430175781, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crawler (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+3, 130077, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3221.817626953125, -357.66375732421875, -2.22753810882568359, 0.924048066139221191, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Hermit Crab (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 143036, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3282.886474609375, -374.376708984375, 1.735674500465393066, 0.61657869815826416, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crawler (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+5, 131376, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3293.455078125, -335.76104736328125, 16.61583137512207031, 2.62044072151184082, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Honey Bee (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+6, 54638, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3373.75439453125, -412.697906494140625, 11.97694587707519531, 2.518779993057250976, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Generic Bunny (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+7, 142609, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3345.7041015625, -340.84027099609375, 15.88854312896728515, 0.272221922874450683, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Handyman Gareth (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+8, 126642, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3274.7255859375, -381.170379638671875, -0.22728478908538818, 3.094667911529541015, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crab (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+9, 126642, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3313.872314453125, -421.67401123046875, 0.253625929355621337, 2.498286962509155273, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crab (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+10, 134696, 1643, 9042, 9579, '0', 0, 0, 0, 1, 3346.368896484375, -378.435760498046875, 18.62731361389160156, 1.479342818260192871, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Marla Featherfoot (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+11, 130077, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3275.889404296875, -375.01885986328125, 0.913532853126525878, 3.640160799026489257, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Hermit Crab (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+12, 143036, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3328.483642578125, -433.258209228515625, -0.67110049724578857, 6.25389719009399414, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crawler (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+13, 126642, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3210.4443359375, -359.988189697265625, -3.14969778060913085, 5.316576957702636718, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crab (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 136422, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3289.74609375, -327.729034423828125, 13.91765403747558593, 3.27478957176208496, 120, 10, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Valley Cottontail (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+15, 136422, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3361.510986328125, -429.319305419921875, 12.359130859375, 6.030802726745605468, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Cottontail (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 134623, 1643, 9042, 9579, '0', 0, 0, 0, 1, 3380.854248046875, -420.930572509765625, 12.76978397369384765, 5.354724407196044921, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Taelia (Area: Tidecross - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+17, 126642, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3237.994140625, -353.96844482421875, -0.35828664898872375, 3.603056907653808593, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crab (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 142194, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3250.69873046875, -411.104156494140625, 12.97412776947021484, 2.146619081497192382, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Skittish Seagull (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+19, 134377, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3272.033447265625, -338.469207763671875, 30.24342536926269531, 0.020568065345287323, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Slickbeak Osprey (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+20, 142168, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3247.850341796875, -326.96929931640625, 11.3204050064086914, 3.202183961868286132, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Squirrel (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 138280, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3230.534912109375, -352.71588134765625, -0.10200726985931396, 3.726888179779052734, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crawler (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+22, 142634, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3335.232666015625, -372.78125, 13.08397769927978515, 1.577361583709716796, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Sister Alison (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+23, 143036, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3311.38525390625, -409.27252197265625, 1.420114517211914062, 3.4574737548828125, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crawler (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+24, 134723, 1643, 9042, 9579, '0', 0, 0, 0, 1, 3378.085205078125, -421.619781494140625, 12.48090267181396484, 5.637413501739501953, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Trueheart Marksman (Area: Tidecross - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+25, 130077, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3220.886962890625, -418.09332275390625, -29.7011795043945312, 4.630242824554443359, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Hermit Crab (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+26, 138280, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3263.96240234375, -360.572967529296875, -0.95921695232391357, 1.309251070022583007, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crawler (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+27, 143038, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3303.398193359375, -362.05145263671875, 13.24366474151611328, 1.140060782432556152, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Honey Bee (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+28, 136422, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3299.60400390625, -366.361572265625, 9.207753181457519531, 0.163060203194618225, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Cottontail (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+29, 138280, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3210.666748046875, -334.50482177734375, 1.714617490768432617, 0.824052929878234863, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Sandyback Crawler (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+30, 142194, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3289.361083984375, -323.368072509765625, 16.2221221923828125, 4.085919857025146484, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Skittish Seagull (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+31, 142199, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3370.92919921875, -285.589752197265625, 67.8933258056640625, 4.735934257507324218, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Alpine Hawk (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 134377, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3209.2216796875, -509.387786865234375, 34.58963775634765625, 2.333814382553100585, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Slickbeak Osprey (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+33, 134377, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3419.518310546875, -452.075897216796875, 24.73954010009765625, 2.244010210037231445, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Slickbeak Osprey (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 134721, 1643, 9042, 9579, '0', 0, 0, 0, 1, 3393.317626953125, -424.90972900390625, 13.94179153442382812, 5.567600250244140625, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Stalwart Revolutionary (Area: Tidecross - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+35, 142168, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3398.8349609375, -383.160980224609375, 15.22425365447998046, 3.427221536636352539, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Squirrel (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 142194, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3289.229248046875, -400.2413330078125, 12.06528377532958984, 4.666686534881591796, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Skittish Seagull (Area: Tidecross - Difficulty: 0) CreateObject2
(@CGUID+37, 142168, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3285.26611328125, -287.03338623046875, 24.55756187438964843, 0.348952054977416992, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Squirrel (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+38, 142168, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3389.5830078125, -336.458984375, 27.79191970825195312, 4.149394989013671875, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Squirrel (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+39, 136422, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3314.965087890625, -286.88104248046875, 26.78862953186035156, 2.047563552856445312, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Cottontail (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+40, 141064, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3344.130859375, -286.04913330078125, 32.71361160278320312, 4.950742244720458984, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Highland Hare (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+41, 136422, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3375.09521484375, -291.60174560546875, 35.71710586547851562, 1.278772473335266113, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Cottontail (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+42, 54638, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3406.584228515625, -442.161468505859375, 13.93338203430175781, 2.441189289093017578, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54762), -- Generic Bunny (Area: Tidecross - Difficulty: 0) CreateObject1 (Auras: 264700 - Bonestorm)
(@CGUID+43, 141064, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3416.94189453125, -305.246490478515625, 39.27288436889648437, 1.849901080131530761, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Highland Hare (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+44, 136422, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3396.633056640625, -268.82843017578125, 39.65697479248046875, 2.348807334899902343, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Cottontail (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+45, 142168, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3354.30908203125, -254.696182250976562, 39.20532608032226562, 5.19281768798828125, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Valley Squirrel (Area: Tidecross - Difficulty: 0) CreateObject1
(@CGUID+46, 141064, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3381.385498046875, -254.387832641601562, 41.39926528930664062, 5.033213615417480468, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762), -- Highland Hare (Area: Tidecross - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 141064, 1643, 9042, 9579, '0', 0, 0, 0, 0, 3306.25, -250, 33.9922637939453125, 5.399059295654296875, 120, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 54762); -- Highland Hare (Area: Tidecross - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+47;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Stalwart Revolutionary
(@CGUID+5, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Honey Bee
(@CGUID+7, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Handyman Gareth
(@CGUID+10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Marla Featherfoot
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Taelia
(@CGUID+18, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skittish Seagull
(@CGUID+19, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Slickbeak Osprey
(@CGUID+22, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sister Alison
(@CGUID+24, 0, 0, 0, 0, 0, 2, 0, 214, 0, 0, 0, 0, ''), -- Trueheart Marksman
(@CGUID+27, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Honey Bee
(@CGUID+30, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Skittish Seagull
(@CGUID+32, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Slickbeak Osprey
(@CGUID+33, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Slickbeak Osprey
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Stalwart Revolutionary
(@CGUID+36, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Skittish Seagull

DELETE FROM `creature_template_addon` WHERE `entry` IN (142199 /*142199 (Alpine Hawk)*/, 143038 /*143038 (Honey Bee)*/, 134723 /*134723 (Trueheart Marksman)*/, 142634 /*142634 (Sister Alison)*/, 134377 /*134377 (Slickbeak Osprey)*/, 134696 /*134696 (Marla Featherfoot)*/, 142609 /*142609 (Handyman Gareth)*/, 131376 /*131376 (Honey Bee)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(142199, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 142199 (Alpine Hawk)
(143038, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 143038 (Honey Bee)
(134723, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, ''), -- 134723 (Trueheart Marksman)
(142634, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 142634 (Sister Alison)
(134377, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 134377 (Slickbeak Osprey)
(134696, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 134696 (Marla Featherfoot)
(142609, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 142609 (Handyman Gareth)
(131376, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 131376 (Honey Bee)

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=134696 AND `MenuID`=6944) OR (`CreatureID`=142609 AND `MenuID`=23171) OR (`CreatureID`=142634 AND `MenuID`=23172);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(134696, 6944, 54762), -- Marla Featherfoot
(142609, 23171, 54762), -- Handyman Gareth
(142634, 23172, 54762); -- Sister Alison

DELETE FROM `npc_vendor` WHERE (`entry`=142609 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=142609 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=183952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142609 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142634 AND `item`=159875 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142634 AND `item`=160554 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142634 AND `item`=159871 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142634 AND `item`=163075 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142634 AND `item`=159869 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142634 AND `item`=159898 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142634 AND `item`=159868 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=142634 AND `item`=159867 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(142609, 13, 163203, 0, 6426, 1, 0, 0, 54762), -- Hypersensitive Azeritometer Sensor
(142609, 12, 3857, 0, 0, 1, 0, 0, 54762), -- Coal
(142609, 11, 18567, 0, 0, 1, 0, 0, 54762), -- Elemental Flux
(142609, 10, 160298, 0, 0, 1, 0, 0, 54762), -- Durable Flux
(142609, 9, 3466, 0, 0, 1, 0, 0, 54762), -- Strong Flux
(142609, 8, 2880, 0, 0, 1, 0, 0, 54762), -- Weak Flux
(142609, 7, 5956, 0, 0, 1, 0, 0, 54762), -- Blacksmith Hammer
(142609, 6, 2901, 0, 0, 1, 0, 0, 54762), -- Mining Pick
(142609, 5, 6219, 0, 0, 1, 0, 0, 54762), -- Arclight Spanner
(142609, 4, 160502, 0, 0, 1, 0, 0, 54762), -- Chemical Blasting Cap
(142609, 3, 163569, 0, 0, 1, 0, 0, 54762), -- Insulated Wiring
(142609, 2, 183952, 0, 0, 1, 0, 0, 54762), -- Machinist's Oil
(142609, 1, 180733, 0, 0, 1, 0, 0, 54762), -- Luminous Flux
(142634, 8, 159875, 0, 0, 1, 0, 0, 54762), -- Sour Vanilla Skyr
(142634, 7, 160554, 0, 0, 1, 0, 0, 54762), -- Stormsong Sourdough
(142634, 6, 159871, 0, 0, 1, 0, 0, 54762), -- Buttered Turnip Porridge
(142634, 5, 163075, 0, 0, 1, 0, 0, 54762), -- Stormshore Haddock
(142634, 4, 159869, 0, 0, 1, 0, 0, 54762), -- Goldfield Sweet Yams
(142634, 3, 159898, 0, 0, 1, 0, 0, 54762), -- Sour Stormberries
(142634, 2, 159868, 0, 0, 1, 0, 0, 54762), -- Free-Range Goat's Milk
(142634, 1, 159867, 0, 0, 1, 0, 0, 54762); -- Rockskip Mineral Water

DELETE FROM `gossip_menu` WHERE (`MenuID`=23171 AND `TextID`=160710) OR (`MenuID`=23172 AND `TextID`=160740);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(23171, 160710, 54762), -- 142609 (Handyman Gareth)
(23172, 160740, 54762); -- 142634 (Sister Alison)

UPDATE `gossip_menu` SET `VerifiedBuild`=54762 WHERE (`MenuID`=6944 AND `TextID`=7778);

UPDATE `gossip_menu_option` SET `GossipOptionID`=34833, `VerifiedBuild`=54762 WHERE (`MenuID`=6944 AND `OptionID`=0); -- OptionBroadcastTextID: 12271 - 140511 - 158191
UPDATE `gossip_menu_option` SET `GossipOptionID`=49432, `OptionBroadcastTextID`=45533, `VerifiedBuild`=54762 WHERE (`MenuID`=23171 AND `OptionID`=0); -- OptionBroadcastTextID: 45533 - 143334
UPDATE `gossip_menu_option` SET `GossipOptionID`=49434, `OptionBroadcastTextID`=2822, `VerifiedBuild`=54762 WHERE (`MenuID`=23172 AND `OptionID`=0); -- OptionBroadcastTextID: 2822 - 162070
UPDATE `gossip_menu_option` SET `GossipOptionID`=49433, `OptionBroadcastTextID`=2823, `VerifiedBuild`=54762 WHERE (`MenuID`=23172 AND `OptionID`=1); -- OptionBroadcastTextID: 2823 - 7509 - 8097

-- 
UPDATE `creature_model_info` SET `VerifiedBuild`=54762 WHERE `DisplayID` IN (68093, 10612, 68092, 83920, 52520, 6302, 79406, 75344, 75343, 68090, 30257, 81202, 32187, 81283, 81084, 81198, 32789, 52599, 1072, 81291, 85042, 52601, 86312, 86176, 86309, 32790, 80264, 83815, 982, 87006, 342, 86311, 88681, 88625, 79014, 85797, 85041, 86175, 81201);
UPDATE `creature_model_info` SET `BoundingRadius`=0.264983922243118286, `CombatReach`=1.5, `VerifiedBuild`=54762 WHERE `DisplayID`=79404;
UPDATE `creature_model_info` SET `BoundingRadius`=3.662486076354980468, `VerifiedBuild`=54762 WHERE `DisplayID`=87014;
UPDATE `creature_model_info` SET `BoundingRadius`=0.208000004291534423, `CombatReach`=1.5, `VerifiedBuild`=54762 WHERE `DisplayID`=83273;
UPDATE `creature_model_info` SET `BoundingRadius`=0.199136361479759216, `CombatReach`=1.399999976158142089, `VerifiedBuild`=54762 WHERE `DisplayID`=81663;
UPDATE `creature_model_info` SET `BoundingRadius`=0.289333313703536987, `CombatReach`=1.399999976158142089, `VerifiedBuild`=54762 WHERE `DisplayID`=71828;

UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=123226 AND `DifficultyID`=0); -- Harbor Thresher
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=126642 AND `DifficultyID`=0); -- Sandyback Crab
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=130094 AND `DifficultyID`=0); -- Tidesage Seacaller
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=130116 AND `DifficultyID`=0); -- Frothing Tideblood
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=130531 AND `DifficultyID`=0); -- Shipwright Turncoat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`DifficultyID`=0 AND `Entry` IN (131376,143038)); -- Honey Bee
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=131387 AND `DifficultyID`=0); -- Coppertail Fox
UPDATE `creature_template_difficulty` SET `StaticFlags1`=805306368 WHERE (`Entry`=134377 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `StaticFlags3`=262144, `VerifiedBuild`=54762 WHERE (`Entry`=134623 AND `DifficultyID`=0); -- Taelia
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=134631 AND `DifficultyID`=0); -- Brittle Sailor
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=134696 AND `DifficultyID`=0); -- Marla Featherfoot
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=134721 AND `DifficultyID`=0); -- Stalwart Revolutionary
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435712, `VerifiedBuild`=54762 WHERE (`Entry`=134723 AND `DifficultyID`=0); -- Trueheart Marksman
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=134747 AND `DifficultyID`=0); -- Tidesage Defector
UPDATE `creature_template_difficulty` SET `ContentTuningID`=188, `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=134861 AND `DifficultyID`=0); -- Inert Grasp
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=136204 AND `DifficultyID`=0); -- Coldtooth Alpha
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=136205 AND `DifficultyID`=0); -- Coldtooth Howler
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=136422 AND `DifficultyID`=0); -- Valley Cottontail
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=136591 AND `DifficultyID`=0); -- Highland Grizzly
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`DifficultyID`=0 AND `Entry` IN (138134,143037)); -- River Otter
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`DifficultyID`=0 AND `Entry` IN (138280,143036)); -- Sandyback Crawler
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435712, `VerifiedBuild`=54762 WHERE (`Entry`=139177 AND `DifficultyID`=0); -- Brittle Sailor
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=139968 AND `DifficultyID`=0); -- Corrupted Tideskipper
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=139973 AND `DifficultyID`=0); -- Juvenile Tideskipper
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54762 WHERE (`Entry`=141008 AND `DifficultyID`=0); -- Reanimated Kraken Tentacle
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=141064 AND `DifficultyID`=0); -- Highland Hare
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`DifficultyID`=0 AND `Entry` IN (142196,143032)); -- River Frog
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=54762 WHERE (`Entry`=142199 AND `DifficultyID`=0); -- Alpine Hawk
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=142609 AND `DifficultyID`=0); -- Handyman Gareth
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=54762 WHERE (`Entry`=142634 AND `DifficultyID`=0); -- Sister Alison
