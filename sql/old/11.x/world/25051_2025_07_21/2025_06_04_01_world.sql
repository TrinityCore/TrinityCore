SET @CGUID := 6001929;
SET @OGUID := 6001396;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+371;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1012.88409423828125, 3698.513427734375, -41.7211418151855468, 4.830121994018554687, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1, 105729, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1014.973876953125, 3782.85498046875, 2.937943696975708007, 4.570400714874267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Signal Lantern (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 209519 - Lantern)
(@CGUID+2, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 972.97991943359375, 3716.269775390625, -38.8142662048339843, 2.560314178466796875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+3, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 961.249267578125, 3708.56689453125, -14.3317461013793945, 5.365382671356201171, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+4, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 963.9678955078125, 3787.814697265625, -35.8917884826660156, 0.846930086612701416, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+5, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 964.06500244140625, 3779.8740234375, -23.5939884185791015, 0.890450954437255859, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+6, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 985.3369140625, 3773.23876953125, -38.2069358825683593, 3.021608352661132812, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+7, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1034.816650390625, 3777.93798828125, -7.17219352722167968, 2.073499679565429687, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+8, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1001.39630126953125, 3743.221923828125, -48.1309432983398437, 2.534811973571777343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+9, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 933.28302001953125, 3815.150146484375, -40.4883537292480468, 2.986541509628295898, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+10, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 990.745361328125, 3744.727783203125, -24.8567867279052734, 5.436133384704589843, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+11, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1035.2830810546875, 3739.613525390625, -20.4682941436767578, 2.127483844757080078, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+12, 111367, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1052.4739990234375, 3665.40966796875, 2.69928741455078125, 3.931749343872070312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+13, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1082.73681640625, 3612.8369140625, 35.60659027099609375, 4.075578689575195312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 111367, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1150.9254150390625, 3696.962646484375, 2.487020015716552734, 0.373336821794509887, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+15, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1080.9254150390625, 3614.77783203125, 35.56509017944335937, 0.297112911939620971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1085.9619140625, 3617.326904296875, 35.60659027099609375, 2.822934627532958984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+17, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1083.56201171875, 3614.421875, 35.60659027099609375, 2.288319110870361328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 111372, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1159.3245849609375, 3696.927490234375, 2.79409027099609375, 1.413800597190856933, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+19, 111372, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1153.076416015625, 3701.829833984375, 2.704654455184936523, 4.916741371154785156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+20, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1006.398193359375, 3659.9501953125, -34.5289688110351562, 2.410708904266357421, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%) (possible waypoints or random movement)
(@CGUID+21, 111367, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1155.185791015625, 3695.82470703125, 2.699282646179199218, 2.069846630096435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+22, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1087.4010009765625, 3615.691650390625, 35.60659027099609375, 1.023730039596557617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1083.313232421875, 3614.91064453125, 35.60659027099609375, 4.248108386993408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+24, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 915.16107177734375, 3817.480224609375, -26.8347377777099609, 3.98323678970336914, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+25, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1012.32305908203125, 3642.9677734375, -14.4372034072875976, 5.428040981292724609, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%) (possible waypoints or random movement)
(@CGUID+26, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1014.9130859375, 3633.641357421875, -33.0532112121582031, 3.446614503860473632, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%) (possible waypoints or random movement)
(@CGUID+27, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 981.15618896484375, 3682.564453125, -19.0644397735595703, 4.116047382354736328, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+28, 132607, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 944.62255859375, 3798.0615234375, 97.56170654296875, 3.317355632781982421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Lightlock (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+29, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1019.1668701171875, 3661.51171875, -13.770939826965332, 6.200845241546630859, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%) (possible waypoints or random movement)
(@CGUID+30, 111367, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1047.0867919921875, 3661.334228515625, 2.699288129806518554, 0.483656674623489379, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+31, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1081.0863037109375, 3618.494384765625, 35.60659027099609375, 1.938999056816101074, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1082.146728515625, 3615.208984375, 35.60659027099609375, 1.890948176383972167, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+33, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 965.17340087890625, 3599.05322265625, -15.1824865341186523, 1.756219744682312011, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%) (possible waypoints or random movement)
(@CGUID+34, 111367, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1043.967041015625, 3596.9931640625, 0.77798539400100708, 2.405573844909667968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+35, 132605, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 806.30035400390625, 3660.1494140625, 92.08333587646484375, 0.78539818525314331, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Phaseshifting Platform (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+36, 107564, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1057.4322509765625, 3457.68310546875, 19.344390869140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Conversation Stalker (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+37, 104215, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1289.8209228515625, 3527.37939453125, 20.02589988708496093, 0.601503908634185791, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Patrol Captain Gerdo (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 227147 - Area Secured, 210143 - Command, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+38, 107324, 1571, 8079, 8182, '8,23,2,24', '0', 0, 0, 0, 1191.96533203125, 3283.007080078125, 20.08359336853027343, 5.436266899108886718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61188), -- Suramar Child (Area: The Gilded Market - Difficulty: Mythic) CreateObject1 (Auras: 220629 - Star Augur Etraeus)
(@CGUID+39, 111372, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1039.998291015625, 3601.96875, 0.770405232906341552, 5.252469062805175781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+40, 111367, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1039.5711669921875, 3596.6640625, 0.788564324378967285, 0.709064483642578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+41, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1086.6961669921875, 3612.4296875, 35.60659027099609375, 3.195720911026000976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 107324, 1571, 8079, 8182, '8,23,2,24', '0', 0, 0, 0, 1194.43408203125, 3280.9375, 20.08359336853027343, 2.58937239646911621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61188), -- Suramar Child (Area: The Gilded Market - Difficulty: Mythic) CreateObject1 (Auras: 220629 - Star Augur Etraeus)
(@CGUID+43, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 999.3316650390625, 3582.216064453125, -30.7752666473388671, 5.118092536926269531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%) (possible waypoints or random movement)
(@CGUID+44, 104247, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1110.88623046875, 3585.3994140625, 35.596282958984375, 2.464668750762939453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Arcanist (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 209438 - Arcane Hands) (possible waypoints or random movement)
(@CGUID+45, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1113.52783203125, 3587.04541015625, 35.58663558959960937, 2.444829225540161132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 105699, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1109.5321044921875, 3582.57177734375, 35.58382415771484375, 2.44612884521484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+47, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1010.4136962890625, 3561.289306640625, -12.5748224258422851, 4.396013259887695312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+48, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 901.87567138671875, 3602.616455078125, -13.78326416015625, 2.766869068145751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+49, 104696, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1054.8228759765625, 3551.63720703125, 3.961915254592895507, 6.224385738372802734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+50, 105705, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1059.0347900390625, 3553.201416015625, 3.961902141571044921, 3.071385383605957031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Bound Energy (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+51, 104696, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1056.0989990234375, 3546.33154296875, 3.961903095245361328, 0.521446943283081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+52, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1058.7222900390625, 3548.572021484375, 3.961897134780883789, 2.98988509178161621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+53, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1061.65625, 3549.94970703125, 3.961889505386352539, 3.054193973541259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+54, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 913.420654296875, 3590.5283203125, -24.9273624420166015, 4.53980255126953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%) (possible waypoints or random movement)
(@CGUID+55, 105705, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1060.6771240234375, 3546.061767578125, 3.961892366409301757, 2.965099573135375976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Bound Energy (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+56, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1000.954345703125, 3537.97509765625, -19.1263713836669921, 4.401997566223144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+57, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 928.24578857421875, 3573.00390625, -42.349609375, 3.598300695419311523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+58, 104247, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1138.9913330078125, 3564.561767578125, 19.92155647277832031, 4.349344730377197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Arcanist (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 209438 - Arcane Hands)
(@CGUID+59, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 964.99957275390625, 3553.943359375, -23.1774063110351562, 4.069565773010253906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+60, 104695, 1571, 8079, 8183, '8,23,2,24', '0', 0, 0, 0, 1089.7257080078125, 3190.8603515625, 41.69280242919921875, 4.521906852722167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61188), -- Suramar Merchant (Area: Midnight Court - Difficulty: Mythic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+61, 104270, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1167.8289794921875, 3581.972900390625, 19.83821487426757812, 3.10057234764099121, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+62, 104251, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1077.671630859375, 3513.090087890625, 13.13418388366699218, 5.643853664398193359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Sentry (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 227148 - Spotlight)
(@CGUID+63, 104251, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1150.10693359375, 3545.47607421875, 19.83822250366210937, 2.182369709014892578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Sentry (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 227148 - Spotlight) (possible waypoints or random movement)
(@CGUID+64, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1163.8055419921875, 3551.514892578125, 19.92155075073242187, 0.297112911939620971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+65, 104696, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1043.236083984375, 3524.2666015625, 3.96191263198852539, 4.302118778228759765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+66, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1102.93408203125, 3530.954833984375, 20.89313316345214843, 2.700201272964477539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+67, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1136.4461669921875, 3545.600830078125, 19.83822250366210937, 5.51631021499633789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+68, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1170.76220703125, 3553.4306640625, 19.92155075073242187, 0.297112911939620971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+69, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1138.9581298828125, 3548.658203125, 19.83822250366210937, 4.006217479705810546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+70, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1138.85546875, 3546.344970703125, 19.83822250366210937, 4.001894950866699218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+71, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1185.1666259765625, 3591.1650390625, 20.66722488403320312, 0.882036805152893066, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+72, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1041.060791015625, 3519.006103515625, 3.9619140625, 1.135475993156433105, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+73, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1141.28515625, 3549.457275390625, 19.83822250366210937, 5.417225837707519531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+74, 105157, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1187.8055419921875, 3593.913330078125, 22.8934173583984375, 4.543270587921142578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Power Conduit (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 208274 - Arcane Power Conduit)
(@CGUID+75, 104251, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1192.4444580078125, 3583.960205078125, 20.97496986389160156, 4.640855312347412109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Sentry (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 227148 - Spotlight)
(@CGUID+76, 105699, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1103.795166015625, 3535.861083984375, 20.89313125610351562, 2.700201272964477539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+77, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1141.47216796875, 3545.8544921875, 19.83822250366210937, 0.824510753154754638, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+78, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1053.4478759765625, 3516.593017578125, 6.222970008850097656, 3.054193973541259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+79, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1164.6944580078125, 3553.3447265625, 19.92155075073242187, 0.297112911939620971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+80, 104247, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1061.920166015625, 3523.63720703125, 8.403567314147949218, 2.594107866287231445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Arcanist (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 209438 - Arcane Hands)
(@CGUID+81, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1167.0989990234375, 3553.455810546875, 19.92155075073242187, 4.48543405532836914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+82, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1138.7900390625, 3547.3486328125, 19.83822250366210937, 5.594341278076171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+83, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1139.6739501953125, 3545.566650390625, 19.83822250366210937, 0.006895370781421661, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+84, 104270, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1192.9879150390625, 3601.03466796875, 21.00896263122558593, 3.295732498168945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+85, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1165.6632080078125, 3550.02685546875, 19.92155075073242187, 0.297112911939620971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+86, 105704, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1135.8819580078125, 3559.90966796875, 19.9215545654296875, 0.606564760208129882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Manifestation (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+87, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1166.8194580078125, 3551.19970703125, 19.92155075073242187, 0.297112911939620971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+88, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1141.9976806640625, 3548.624267578125, 19.83822250366210937, 4.415277004241943359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 104270, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1118.1597900390625, 3512.19189453125, 25.71492385864257812, 4.149870872497558593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+90, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1167.7708740234375, 3549.63623046875, 19.92155075073242187, 2.255112648010253906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+91, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1169.2291259765625, 3550.701416015625, 19.92155075073242187, 0.297112911939620971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+92, 104275, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1088.8785400390625, 3306.01220703125, 25.0570068359375, 1.431016087532043457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Imacu'tya (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 209712 - Bond of Cunning)
(@CGUID+93, 104274, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1083.045166015625, 3307.55810546875, 25.0532379150390625, 0.779110431671142578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Baalgar the Watchful (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 209717 - Bond of Cruelty)
(@CGUID+94, 104273, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1081.217041015625, 3313.442626953125, 25.05779838562011718, 0.232142418622970581, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Jazshariu (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 207819 - Bond of Strength)
(@CGUID+95, 104245, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1174.748291015625, 3557.614501953125, 19.84367942810058593, 5.432530403137207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Beacon (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 212480 - Watchpost Vicinity, 206309 - Spotlight)
(@CGUID+96, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 940.92486572265625, 3512.153076171875, -46.8673095703125, 5.529219627380371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+97, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1171.595458984375, 3549.276123046875, 19.9215545654296875, 0.297112911939620971, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+98, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 921.905029296875, 3529.7734375, -19.8721218109130859, 0.567449808120727539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+99, 104217, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1088.27783203125, 3313.548583984375, 25.059478759765625, 3.985519170761108398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Talixae Flamewreath (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 209723 - Bond of Flame, 209435 - Flame Hands, 355784 - [DNT] Send Event <Points> On Enter Combat, 42459 - Dual Wield)
(@CGUID+100, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 977.9283447265625, 3493.818115234375, -20.4134502410888671, 4.083504676818847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+101, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1097.7958984375, 3485.9169921875, 19.83822250366210937, 2.038482666015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+102, 111572, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 945.69854736328125, 3497.3076171875, -28.0512104034423828, 4.234539985656738281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Engorged Manafeeder (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+103, 104270, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1157.01220703125, 3527.70751953125, 20.89313125610351562, 2.846056222915649414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+104, 111563, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1042.595458984375, 3463.47314453125, 3.89881134033203125, 2.654634714126586914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+105, 105703, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1092.983154296875, 3482.192138671875, 19.83822250366210937, 5.20264434814453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+106, 104251, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1095.6295166015625, 3483.604736328125, 19.83822250366210937, 5.202686309814453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Sentry (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+107, 113617, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 966.484375, 3470.705810546875, 1.984411120414733886, 4.722817897796630859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Dusk Lily Agent (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 188236 - Mod Scale 125%, 86603 - Stealth)
(@CGUID+108, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1181.7916259765625, 3541.3046875, 21.57190895080566406, 0.064398430287837982, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+109, 105699, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1190.2708740234375, 3538.484375, 21.96455764770507812, 2.725588798522949218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+110, 104245, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1121.673583984375, 3479.85498046875, 19.97371292114257812, 3.439042568206787109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Beacon (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 212480 - Watchpost Vicinity, 206309 - Spotlight)
(@CGUID+111, 105699, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1187.5989990234375, 3541.94970703125, 21.96455764770507812, 3.285552024841308593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+112, 104694, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1050.1353759765625, 3452.599853515625, 23.02750205993652343, 0.906226813793182373, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+113, 104246, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 1, 1120.795166015625, 3471.067626953125, 19.92155647277832031, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+114, 105699, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1124.7603759765625, 3469.189208984375, 19.92155647277832031, 2.501321792602539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+115, 105699, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1124.0867919921875, 3473.0087890625, 19.92155647277832031, 4.147412300109863281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+116, 104270, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1102.439208984375, 3451.764892578125, 19.71983528137207031, 1.162247180938720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+117, 107324, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1070.8992919921875, 3439.109375, 20.19599533081054687, 6.261688232421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Child (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 220629 - Star Augur Etraeus)
(@CGUID+118, 107324, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1073.6458740234375, 3440.40625, 20.19813919067382812, 4.521906852722167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Child (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 220629 - Star Augur Etraeus)
(@CGUID+119, 111575, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 927.928955078125, 3451.501708984375, -26.7596969604492187, 2.031063079833984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Overgrown Eel (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+120, 107486, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 956.576416015625, 3239.397705078125, 52.25292587280273437, 5.404879093170166015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Chatty Rumormonger (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+121, 107324, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1073.513916015625, 3437.185791015625, 20.19775772094726562, 1.675011634826660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Child (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 220629 - Star Augur Etraeus)
(@CGUID+122, 104270, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1107.046875, 3450.970458984375, 19.71983528137207031, 1.456243157386779785, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+123, 107486, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 879.40106201171875, 3246.396728515625, 12.94004154205322265, 1.930042862892150878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Chatty Rumormonger (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+124, 107486, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 996.23785400390625, 3224.904541015625, 25.266693115234375, 5.518571376800537109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Chatty Rumormonger (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+125, 107470, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1046.404541015625, 3421.584228515625, 45.888916015625, 5.40294504165649414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+126, 104695, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1044.375, 3419.90966796875, 45.88892364501953125, 5.593165397644042968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+127, 111366, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 959.65802001953125, 3413.817626953125, 1.163244485855102539, 2.224967718124389648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@CGUID+128, 107472, 1571, 8079, 8079, '8,23,2,24', 0, 0, 0, 0, 1040.0833740234375, 3415.09814453125, 45.888916015625, 1.168970584869384765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Court of Stars - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+129, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 947.08856201171875, 3204.845458984375, 22.65813827514648437, 5.062984466552734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213105 - Costume 13)
(@CGUID+130, 104246, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 1141.673583984375, 3447.544189453125, 21.19290924072265625, 0.011567173525691032, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+131, 111367, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 916.38543701171875, 3424.322998046875, 2.197149515151977539, 0.577750980854034423, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+132, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 903.015625, 3420.809814453125, 1.985494613647460937, 0.7992631196975708, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+133, 105715, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1062.999755859375, 3404.1943359375, 19.83822250366210937, 3.581779718399047851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Watchful Inquisitor (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 211861 - Grim Guard)
(@CGUID+134, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 945.25, 3202.018310546875, 22.65815162658691406, 0.266589879989624023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213089 - Costume 09)
(@CGUID+135, 104300, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1068.6942138671875, 3402.436767578125, 19.83822059631347656, 3.575153112411499023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Shadow Mistress (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+136, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 947.33856201171875, 3199.68310546875, 22.6585693359375, 1.400842905044555664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213100 - Costume 07)
(@CGUID+137, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 946.76214599609375, 3409.4619140625, 1.73459780216217041, 0.066784091293811798, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+138, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 918.451416015625, 3424.979248046875, 1.98488616943359375, 0.62040257453918457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+139, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 950.40625, 3203.10595703125, 22.65869903564453125, 3.287701845169067382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213103 - Costume 11)
(@CGUID+140, 105699, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1147.9722900390625, 3453.0234375, 21.192718505859375, 4.233991146087646484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+141, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1052.99853515625, 3387.95751953125, 19.83822441101074218, 1.042262673377990722, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+142, 111372, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 917.21319580078125, 3414.585693359375, 2.222991943359375, 2.151359319686889648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+143, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1051.806640625, 3388.55908203125, 19.838226318359375, 1.026305794715881347, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+144, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1050.9937744140625, 3389.618408203125, 19.838226318359375, 0.993684291839599609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+145, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1056.398681640625, 3389.517578125, 19.83822250366210937, 0.838018834590911865, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+146, 111367, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 955.7047119140625, 3398.781005859375, 1.224353909492492675, 0.571012258529663085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 221834 - Delivery)
(@CGUID+147, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1050.720947265625, 3390.92529296875, 19.838226318359375, 0.950969994068145751, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+148, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1053.8072509765625, 3395.528564453125, 19.838226318359375, 0.761377155780792236, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+149, 111367, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 953.70269775390625, 3380.42724609375, 1.68359839916229248, 2.701940536499023437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+150, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1063.0577392578125, 3398.997314453125, 19.83822059631347656, 0.82604217529296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+151, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1061.883544921875, 3399.175048828125, 19.83822059631347656, 0.853162050247192382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+152, 107472, 1571, 8079, 8183, '8,23,2,24', '0', 0, 0, 0, 1086.9791259765625, 3189.5634765625, 41.69279861450195312, 6.261688232421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61188), -- Fancy Noble (Area: Midnight Court - Difficulty: Mythic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+153, 111372, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 917.76214599609375, 3403.6875, 2.19714975357055664, 4.809373855590820312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+154, 107442, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 966.97393798828125, 3190.618896484375, 24.79620933532714843, 0.746301352977752685, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Suramar Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+155, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 971.98956298828125, 3168.02001953125, 22.65829086303710937, 5.931212425231933593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213097 - Costume 04)
(@CGUID+156, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1062.671875, 3387.6337890625, 19.9215545654296875, 3.04657745361328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+157, 111366, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 955.1319580078125, 3390.982666015625, 0.891268908977508544, 2.613809585571289062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+158, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 906.09027099609375, 3417.134521484375, 1.984887480735778808, 5.912750244140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+159, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 968.296875, 3166.591064453125, 22.6581573486328125, 4.80464792251586914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213099 - Costume 06)
(@CGUID+160, 107471, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1115.4722900390625, 3421.588623046875, 19.92155647277832031, 5.422792911529541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Wealthy Elite (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+161, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1117.9132080078125, 3419.4853515625, 19.92155647277832031, 2.575898408889770507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+162, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 974.49652099609375, 3169.763916015625, 22.65840530395507812, 4.56578826904296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213104 - Costume 12, 227258 - Truthguard Area Trigger)
(@CGUID+163, 111366, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 921.77777099609375, 3397.887939453125, 2.197150230407714843, 0.125099331140518188, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+164, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 919.2882080078125, 3396.022705078125, 1.984887480735778808, 0.411687403917312622, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+165, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 958.467041015625, 3385.34716796875, 1.655904889106750488, 5.280086994171142578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 191779 - Mod Scale 200%)
(@CGUID+166, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 919.94964599609375, 3398.90966796875, 1.984887242317199707, 0.465317100286483764, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+167, 105699, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1147.046875, 3446.9853515625, 21.5193328857421875, 2.957120895385742187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+168, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 960.94793701171875, 3395.376708984375, 0.888137102127075195, 2.309258460998535156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+169, 104277, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1136.0850830078125, 3427.556396484375, 19.92155647277832031, 0.102556198835372924, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Legion Hound (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+170, 111367, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 957.35589599609375, 3396.405517578125, 0.914359629154205322, 0.157877519726753234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+171, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 977.279541015625, 3169.0009765625, 22.65814399719238281, 3.509423017501831054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213108 - Costume 16)
(@CGUID+172, 107471, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 992.87152099609375, 3366.74560546875, 20.20120620727539062, 3.379978418350219726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Wealthy Elite (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+173, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 901.45660400390625, 3399.216064453125, 1.669305682182312011, 5.417256832122802734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+174, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1059.54345703125, 3388.401123046875, 19.9215545654296875, 5.893472194671630859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+175, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 920.859375, 3402.935791015625, 1.984887480735778808, 0.506236016750335693, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+176, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 903.76214599609375, 3380.622314453125, 1.166505217552185058, 2.086670398712158203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+177, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 929.47393798828125, 3171.3984375, 49.6672515869140625, 6.063186168670654296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213106 - Costume 14)
(@CGUID+178, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 933.96527099609375, 3169.98876953125, 49.65668487548828125, 2.668368101119995117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213095 - Costume 02)
(@CGUID+179, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 932.80902099609375, 3172.71435546875, 49.67452239990234375, 4.084759712219238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213080 - Costume 01)
(@CGUID+180, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 931.00177001953125, 3169.212646484375, 49.64630889892578125, 0.99915093183517456, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213102 - Costume 10)
(@CGUID+181, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1107.939208984375, 3394.5478515625, 19.92155647277832031, 5.727507591247558593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+182, 104300, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1140.765625, 3426.1884765625, 19.92155647277832031, 2.383524417877197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Shadow Mistress (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 206888 - Shadow Channelling)
(@CGUID+183, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1116.478515625, 3399.8017578125, 19.83822250366210937, 4.8655242919921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+184, 111372, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 934.234375, 3358.958251953125, 1.71234130859375, 4.311729907989501953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+185, 105715, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1035.5989990234375, 3362.001708984375, 19.92155647277832031, 3.837875127792358398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Watchful Inquisitor (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 211861 - Grim Guard)
(@CGUID+186, 107471, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1110.9635009765625, 3394.2666015625, 19.92155647277832031, 3.987726211547851562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Wealthy Elite (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+187, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 949.7257080078125, 3359.51123046875, 1.71234130859375, 1.064851045608520507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 191779 - Mod Scale 200%)
(@CGUID+188, 104300, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1030.7447509765625, 3362.442626953125, 19.92155647277832031, 4.994899272918701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Shadow Mistress (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+189, 111366, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 942.83331298828125, 3359.837646484375, 1.712347984313964843, 1.547960281372070312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+190, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 939.68231201171875, 3354.68408203125, 1.71234130859375, 2.092706203460693359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+191, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 884.75518798828125, 3376.200439453125, 1.734588503837585449, 0.066784091293811798, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+192, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1109.2100830078125, 3391.559814453125, 19.92155647277832031, 1.1408311128616333, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+193, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 882.546875, 3365.8125, 1.114659667015075683, 0.066784091293811798, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+194, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 933.18231201171875, 3349.95654296875, 1.71234130859375, 1.959243416786193847, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 191779 - Mod Scale 200%)
(@CGUID+195, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 939.0625, 3144.712646484375, 52.33255386352539062, 1.804817914962768554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213098 - Costume 05)
(@CGUID+196, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 940.58160400390625, 3147.038330078125, 52.332550048828125, 3.247924566268920898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213096 - Costume 03)
(@CGUID+197, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 936.64581298828125, 3146.403564453125, 52.33255386352539062, 0.215407118201255798, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213107 - Costume 15)
(@CGUID+198, 111372, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 913.720947265625, 3360.50634765625, 1.629007935523986816, 0.46364760398864746, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+199, 107435, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 938.45489501953125, 3149.05908203125, 52.33254623413085937, 4.759170055389404296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suspicious Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 213101 - Costume 08)
(@CGUID+200, 107486, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1012.91668701171875, 3145.677978515625, 52.35065460205078125, 4.030371665954589843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Chatty Rumormonger (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+201, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 885.33856201171875, 3353.484375, 1.127669095993041992, 5.34716796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+202, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 909.25518798828125, 3342.795166015625, 1.767609596252441406, 0.345842361450195312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+203, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 913.72222900390625, 3346.775146484375, 1.71234130859375, 1.465738892555236816, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+204, 111367, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 886.3055419921875, 3358.82470703125, 1.093651771545410156, 4.416262149810791015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+205, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 997.85418701171875, 3334.630126953125, 41.84537124633789062, 2.575898408889770507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+206, 107486, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1017.95660400390625, 3130.875, 14.86775875091552734, 1.350157141685485839, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Chatty Rumormonger (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+207, 107471, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 995.4132080078125, 3336.732666015625, 41.83689117431640625, 5.422792911529541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Wealthy Elite (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+208, 111372, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 906.390625, 3346.9296875, 1.7676239013671875, 5.414724349975585937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Dockworker (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+209, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 908.45489501953125, 3346.6025390625, 1.71234130859375, 0.234383746981620788, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+210, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 965.53643798828125, 3322.12060546875, 41.69279098510742187, 1.675011634826660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+211, 104277, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1066.1275634765625, 3337.522216796875, 25.019866943359375, 3.170467615127563476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Legion Hound (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+212, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 870.71527099609375, 3347.33935546875, 0.410056084394454956, 1.213256239891052246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+213, 107471, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1175.9461669921875, 3461.243896484375, 1.886977195739746093, 5.422792911529541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Wealthy Elite (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+214, 105715, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1059.9595947265625, 3334.514404296875, 24.97960472106933593, 3.170523405075073242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Watchful Inquisitor (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 211861 - Grim Guard)
(@CGUID+215, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1178.38720703125, 3459.140625, 1.886976957321166992, 2.575898408889770507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+216, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 965.66839599609375, 3325.341064453125, 41.69279098510742187, 4.521906852722167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+217, 104270, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1066.3787841796875, 3331.870361328125, 25.019866943359375, 3.170469284057617187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+218, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 962.921875, 3324.044189453125, 41.6927947998046875, 6.261688232421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+219, 107470, 1571, 8079, 8183, '8,23,2,24', '0', 0, 0, 0, 1089.59375, 3187.639892578125, 41.69279861450195312, 1.675011634826660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61188), -- Haughty Aristocrat (Area: Midnight Court - Difficulty: Mythic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629
(@CGUID+220, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 873.78472900390625, 3338.165771484375, 1.149950504302978515, 5.555798053741455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+221, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 890.795166015625, 3328.712646484375, 1.146821022033691406, 0.066784091293811798, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+222, 111365, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 894.11114501953125, 3327.51904296875, 1.103038311004638671, 1.817663311958312988, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+223, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 892.98089599609375, 3331.015625, 1.235060691833496093, 1.227236866950988769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+224, 104218, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 882.0399169921875, 3106.670166015625, 54.92871856689453125, 2.745999336242675781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Advisor Melandrus (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 210140 - Wind Hands, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+225, 132599, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1017.96527099609375, 3397.178955078125, 21.66677474975585937, 4.975153446197509765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Lady Chaton (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+226, 132601, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1024.3394775390625, 3400.094970703125, 22.76436614990234375, 0.39255949854850769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Bella (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+227, 132600, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1013.06329345703125, 3400.26953125, 21.62924003601074218, 1.857938170433044433, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mew (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+228, 132604, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1018.74652099609375, 3406.197021484375, 21.6819000244140625, 5.385565757751464843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Shadow (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+229, 132603, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1012.58050537109375, 3392.478759765625, 21.35901260375976562, 4.36566925048828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mrs. Fluffymuffins (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+230, 132602, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1022.8592529296875, 3393.990234375, 21.629241943359375, 3.537362337112426757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Ash (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+231, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 903.12847900390625, 3273.3828125, 12.94778823852539062, 2.025770902633666992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+232, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 890.07989501953125, 3271.22998046875, 12.94778728485107421, 4.02282571792602539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+233, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1010.87152099609375, 3250.6337890625, 25.34271240234375, 5.577304840087890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+234, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 888.2882080078125, 3268.637939453125, 12.94778823852539062, 1.061839580535888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+235, 104270, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1181.9896240234375, 3378.65185546875, 20.64130020141601562, 5.660922527313232421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+236, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1144.46435546875, 3315.3134765625, 23.14523124694824218, 0.638760089874267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+237, 104277, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1180.240966796875, 3376.214111328125, 20.77300262451171875, 5.693570137023925781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Legion Hound (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+238, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1143.76611328125, 3316.468505859375, 23.127410888671875, 0.63766336441040039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+239, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1143.515380859375, 3317.785400390625, 23.04190444946289062, 0.641040980815887451, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+240, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1163.5419921875, 3347.9169921875, 20.0002593994140625, 3.141592741012573242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+241, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1146.3902587890625, 3315.824951171875, 22.87165451049804687, 0.72077953815460205, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+242, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1143.8707275390625, 3319.105712890625, 22.88505363464355468, 0.647402882575988769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+243, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1145.5462646484375, 3314.661865234375, 23.07248497009277343, 0.641610145568847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+244, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1144.79833984375, 3320.197021484375, 22.68187332153320312, 0.655482769012451171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+245, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1163.917724609375, 3336.09765625, 20.00026130676269531, 1.277021408081054687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+246, 105715, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1182.255859375, 3382.15283203125, 20.83790969848632812, 2.519306182861328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Watchful Inquisitor (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 211861 - Grim Guard)
(@CGUID+247, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1203.9461669921875, 3439.993896484375, 60.57309341430664062, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+248, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1208.30908203125, 3442.684814453125, 41.66801834106445312, 3.11079573631286621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+249, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1206.3316650390625, 3438.841064453125, 60.57309722900390625, 2.501321792602539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+250, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1204.001708984375, 3436.783935546875, 60.57337570190429687, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+251, 104246, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 1205.6597900390625, 3442.66064453125, 60.57309722900390625, 4.147412300109863281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+252, 104277, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1188.7430419921875, 3361.76220703125, 20.203948974609375, 6.028510570526123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Legion Hound (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+253, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1206.029541015625, 3435.59814453125, 60.57378387451171875, 1.081137418746948242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+254, 104300, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1193.5555419921875, 3360.98095703125, 20.203948974609375, 3.170395851135253906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Shadow Mistress (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 206888 - Shadow Channelling)
(@CGUID+255, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1208.73095703125, 3434.240478515625, 60.57394027709960937, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+256, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1219.251708984375, 3481.8291015625, 28.24153327941894531, 4.279143810272216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+257, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1216.6024169921875, 3479.50439453125, 28.24153709411621093, 0.064364343881607055, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+258, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1209.3038330078125, 3440.71435546875, 60.57309722900390625, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+259, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1209.5711669921875, 3436.905517578125, 60.57341766357421875, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+260, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1219.3177490234375, 3475.811767578125, 28.24153900146484375, 2.293932437896728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+261, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1223.15283203125, 3389.28564453125, 20.08359336853027343, 1.504487872123718261, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+262, 104251, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 1209.9722900390625, 3564.29833984375, 25.15229606628417968, 2.918368339538574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Sentry (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 227148 - Spotlight)
(@CGUID+263, 105715, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1223.2899169921875, 3392.598876953125, 20.08359336853027343, 3.327443361282348632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Watchful Inquisitor (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 211861 - Grim Guard)
(@CGUID+264, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1226.15625, 3395.978271484375, 20.08359336853027343, 4.029421329498291015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+265, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1145.6927490234375, 3302.338623046875, 23.80930137634277343, 0.987731814384460449, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+266, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1147.8350830078125, 3304.739501953125, 23.8792877197265625, 3.834627151489257812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+267, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1225.2725830078125, 3434.272705078125, 23.4805908203125, 2.935921907424926757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+268, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1220.1492919921875, 3394.2197265625, 20.08359336853027343, 5.806706428527832031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+269, 104246, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 1206.0526123046875, 3568.108154296875, 23.21313667297363281, 2.951365470886230468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+270, 104295, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1226.001708984375, 3390.029541015625, 20.08359336853027343, 2.299895286560058593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Blazing Imp (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+271, 107471, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1187.3021240234375, 3327.673583984375, 20.08359336853027343, 4.521906852722167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Wealthy Elite (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+272, 107472, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1184.5555419921875, 3326.377685546875, 20.08359336853027343, 6.261688709259033203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+273, 107470, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1187.170166015625, 3324.453125, 20.08359336853027343, 1.675011634826660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+274, 105699, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1211.2119140625, 3570.166015625, 25.24074554443359375, 2.946103334426879882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+275, 104694, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1245.4271240234375, 3413.536376953125, 53.94661331176757812, 4.951724529266357421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+276, 107324, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1251.123291015625, 3439.26904296875, 53.9466094970703125, 0.433009743690490722, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Child (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 220633 - Spellblade Aluriel)
(@CGUID+277, 107324, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1253.93408203125, 3440.595458984375, 53.9466094970703125, 3.591018915176391601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Child (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 220633 - Spellblade Aluriel)
(@CGUID+278, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1246.96533203125, 3412.6025390625, 53.94661331176757812, 3.833367824554443359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+279, 111366, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1242.0399169921875, 3381.2890625, 50.94984817504882812, 6.216056346893310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+280, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1266.69970703125, 3474.6953125, 32.69947052001953125, 3.5670318603515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+281, 104694, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1259.2864990234375, 3457.194580078125, 53.94662094116210937, 4.60131072998046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+282, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1263.9947509765625, 3472.943603515625, 32.69947052001953125, 0.720137953758239746, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+283, 105699, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1258.3072509765625, 3524.8603515625, 20.95030403137207031, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+284, 104694, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1255.3809814453125, 3412.986328125, 54.05886459350585937, 1.717898488044738769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+285, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1246.232666015625, 3376.830810546875, 50.94780731201171875, 5.037354469299316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+286, 105705, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1262.2725830078125, 3522.981689453125, 20.9481658935546875, 2.501321792602539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Bound Energy (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+287, 104246, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 1261.6007080078125, 3526.80126953125, 20.9490509033203125, 4.147412300109863281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+288, 105719, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1268.046875, 3441.7744140625, 28.90901756286621093, 5.816802978515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 207221 - Sleeping)
(@CGUID+289, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1246.5555419921875, 3375.1171875, 50.96729278564453125, 2.700884103775024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+290, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1252.3524169921875, 3386.30810546875, 50.94330596923828125, 1.426083922386169433, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+291, 104247, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 1271.3233642578125, 3504.3408203125, 20.93594932556152343, 3.089721918106079101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Arcanist (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 209438 - Arcane Hands)
(@CGUID+292, 105704, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1274.6104736328125, 3501.646240234375, 21.06694412231445312, 3.225257635116577148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Manifestation (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+293, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1271.654541015625, 3431.45751953125, 31.04861259460449218, 1.033959507942199707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+294, 104246, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 1273.4169921875, 3507.515380859375, 21.13595199584960937, 3.226984024047851562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+295, 104245, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1272.984375, 3513.677978515625, 20.81209754943847656, 0.612732648849487304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Beacon (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 212480 - Watchpost Vicinity, 206309 - Spotlight)
(@CGUID+296, 111364, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1248.298583984375, 3374.108642578125, 50.95247650146484375, 4.330551624298095703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+297, 105719, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1273.79345703125, 3418.420166015625, 31.048614501953125, 6.0662078857421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 207221 - Sleeping)
(@CGUID+298, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1256.1875, 3380.09716796875, 50.94763946533203125, 4.837884426116943359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+299, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1254.279541015625, 3375.87841796875, 50.95412445068359375, 4.799234390258789062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+300, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1272.390625, 3416.213623046875, 53.782867431640625, 2.973190546035766601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+301, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1263.2552490234375, 3402.439208984375, 53.98181915283203125, 1.926502466201782226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+302, 111363, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1255.25, 3377.979248046875, 50.94635772705078125, 4.799234390258789062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Nightborne Supplies (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+303, 104246, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 1, 1268.0711669921875, 3559.00439453125, 20.10921287536621093, 3.124333143234252929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+304, 107324, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1280.6807861328125, 3425.4892578125, 29.23463630676269531, 0.117108747363090515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Child (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 220633 - Spellblade Aluriel)
(@CGUID+305, 104694, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1283.6961669921875, 3438.65625, 28.90901756286621093, 1.161963820457458496, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+306, 104270, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1270.234375, 3554.54248046875, 20.10921287536621093, 2.939685583114624023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+307, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1283.6146240234375, 3447.856689453125, 28.90901756286621093, 5.422792911529541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+308, 105705, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1266.689208984375, 3551.77001953125, 20.10921287536621093, 2.779246091842651367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Bound Energy (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+309, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1286.0555419921875, 3445.75341796875, 28.90901756286621093, 2.575898408889770507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+310, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1281.9444580078125, 3397.84375, 53.38484954833984375, 4.61902475357055664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel) (possible waypoints or random movement)
(@CGUID+311, 107324, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1288.84375, 3411.932373046875, 28.90868949890136718, 1.948044419288635253, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Child (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 220633 - Spellblade Aluriel)
(@CGUID+312, 104270, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1297.3472900390625, 3478.897705078125, 30.38802146911621093, 1.406916618347167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Guardian Construct (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+313, 105117, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1311.1492919921875, 3538.150146484375, 22.37365531921386718, 3.230719804763793945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Flask of the Solemn Night (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 208182 - Flask of the Solemn Night)
(@CGUID+314, 104694, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1305.5694580078125, 3419.65966796875, 28.90901374816894531, 2.746130228042602539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel)
(@CGUID+315, 104696, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1315.7430419921875, 3461.986083984375, 32.69945526123046875, 5.422792911529541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+316, 105719, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1297.892333984375, 3414.111083984375, 28.90868949890136718, 2.966633558273315429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 207221 - Sleeping)
(@CGUID+317, 104245, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1303.7691650390625, 3586.33154296875, 20.10921287536621093, 0.230074748396873474, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Beacon (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 212480 - Watchpost Vicinity, 206309 - Spotlight)
(@CGUID+318, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1326.795166015625, 3504.6796875, 20.109283447265625, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+319, 104695, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1320.4461669921875, 3454.55029296875, 32.699462890625, 1.893446326255798339, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+320, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1325.1597900390625, 3508.615478515625, 20.109283447265625, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+321, 105703, 1571, 8079, 8181, '8,23,2,24', 0, 0, 0, 0, 1326.7396240234375, 3507.889892578125, 20.109283447265625, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@CGUID+322, 104695, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1324.592041015625, 3462.05810546875, 32.69945144653320312, 3.056497097015380859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+323, 104247, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 1, 1307.064208984375, 3603.998291015625, 20.10920906066894531, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Arcanist (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 209438 - Arcane Hands)
(@CGUID+324, 104246, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 1, 1328.453125, 3510.556396484375, 20.10928153991699218, 4.147412300109863281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+325, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1329.125, 3506.737060546875, 20.10928153991699218, 2.501321792602539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+326, 105699, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1311.029541015625, 3602.119873046875, 20.10920906066894531, 2.501321792602539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+327, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1331.5242919921875, 3502.13623046875, 20.10928153991699218, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+328, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1332.0972900390625, 3508.6103515625, 20.10928153991699218, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+329, 105704, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1310.357666015625, 3605.939208984375, 20.10920906066894531, 4.147412300109863281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Manifestation (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+330, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1332.3646240234375, 3504.80126953125, 20.10928153991699218, 6.116658687591552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+331, 105699, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1332.73974609375, 3541.91455078125, 20.43062782287597656, 1.690235853195190429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Saber (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+332, 104247, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 1, 1313.3367919921875, 3617.197998046875, 20.02587127685546875, 5.999364376068115234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Arcanist (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 209438 - Arcane Hands)
(@CGUID+333, 104247, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 1, 1335.420166015625, 3544.756103515625, 20.31041908264160156, 1.690303921699523925, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Arcanist (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 209438 - Arcane Hands)
(@CGUID+334, 105705, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1312.2376708984375, 3620.6435546875, 20.02587318420410156, 2.85782933235168457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Bound Energy (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+335, 104246, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 1, 1338.3988037109375, 3545.11376953125, 20.20904159545898437, 1.690282583236694335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+336, 104245, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1358.9617919921875, 3566.57470703125, 20.86802864074707031, 3.663928031921386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Arcane Beacon (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 212480 - Watchpost Vicinity, 206309 - Spotlight)
(@CGUID+337, 104247, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 1, 1351.017333984375, 3603.3994140625, 35.79409027099609375, 0.990858793258666992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Arcanist (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 209438 - Arcane Hands)
(@CGUID+338, 104246, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 1, 1348.5078125, 3605.043212890625, 35.79409027099609375, 0.990889906883239746, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+339, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1363.3245849609375, 3638.94921875, 35.60659027099609375, 2.824796915054321289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+340, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1364.3531494140625, 3633.766357421875, 35.60659027099609375, 3.733639240264892578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+341, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1362.525146484375, 3635.6435546875, 35.60659027099609375, 3.580141305923461914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+342, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1370.18212890625, 3635.32080078125, 35.60659027099609375, 0.359031498432159423, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+343, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1371.510498046875, 3636.66552734375, 35.60659027099609375, 0.512643635272979736, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+344, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1373.759033203125, 3635.42529296875, 35.60659027099609375, 0.622158408164978027, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+345, 104246, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 1, 1367.4033203125, 3640.42724609375, 35.60659027099609375, 1.685955643653869628, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Duskwatch Guard (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+346, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1368.1324462890625, 3634.3330078125, 35.60659027099609375, 5.111124038696289062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+347, 105703, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1370.38134765625, 3640.194091796875, 35.60659027099609375, 2.045228958129882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Mana Wyrm (Area: The Gilded Market - Difficulty: Heroic) CreateObject1
(@CGUID+348, 108419, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1285.34619140625, 3441.0986328125, 28.99721527099609375, 4.192057609558105468, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Automated Sweeper (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 215252 - Automated Sweeper) (possible waypoints or random movement)
(@CGUID+349, 108419, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1286.6053466796875, 3421.017822265625, 28.99721527099609375, 1.738482832908630371, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Automated Sweeper (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 215252 - Automated Sweeper)
(@CGUID+350, 108419, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1235.0416259765625, 3435.201416015625, 55.6065826416015625, 5.340324878692626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Automated Sweeper (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 215252 - Automated Sweeper)
(@CGUID+351, 108419, 1571, 8079, 8182, '8,23,2,24', 0, 0, 0, 0, 1260.2581787109375, 3412.93701171875, 54.00823593139648437, 4.340746402740478515, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61122), -- Automated Sweeper (Area: The Gilded Market - Difficulty: Heroic) CreateObject1 (Auras: 215252 - Automated Sweeper)
(@CGUID+352, 107472, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1113.6334228515625, 3221.805419921875, 41.81005096435546875, 0.922288477420806884, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+353, 105715, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1166.359130859375, 3250.1357421875, 20.0002593994140625, 5.187047004699707031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Watchful Inquisitor (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 211861 - Grim Guard)
(@CGUID+354, 104277, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1163.693115234375, 3248.7021484375, 20.0002593994140625, 5.195637226104736328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Legion Hound (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+355, 104694, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1167.0667724609375, 3263.880126953125, 20.0002593994140625, 5.278775215148925781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+356, 104278, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 1, 1162.0458984375, 3257.782958984375, 20.0002593994140625, 5.3427276611328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Felbound Enforcer (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+357, 104300, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1168.9671630859375, 3251.528564453125, 20.0002593994140625, 5.20075845718383789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Shadow Mistress (Area: Midnight Court - Difficulty: Heroic) CreateObject1
(@CGUID+358, 107472, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1167.09375, 3266.411376953125, 20.08359336853027343, 4.521906852722167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+359, 104695, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1178.6163330078125, 3275.02001953125, 53.9959869384765625, 0.302034437656402587, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+360, 107470, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1202.75, 3259.475830078125, 53.99750518798828125, 2.130797624588012695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+361, 107472, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1178.8228759765625, 3262.3212890625, 53.99659347534179687, 3.556530237197875976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+362, 107470, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1182.625, 3276.39501953125, 53.9959869384765625, 2.999290227890014648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+363, 104695, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1164.3472900390625, 3265.115478515625, 20.08359336853027343, 6.261688232421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+364, 104695, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1178.6163330078125, 3275.02001953125, 53.9959869384765625, 0.302034437656402587, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+365, 104694, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1157.94287109375, 3264.407470703125, 20.0002593994140625, 4.772639274597167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+366, 107472, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1175.1319580078125, 3270.572998046875, 53.99639129638671875, 2.716312408447265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Fancy Noble (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+367, 104696, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1169.4940185546875, 3254.9833984375, 20.0002593994140625, 5.675541877746582031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Civilian (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+368, 107470, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1166.9617919921875, 3263.19091796875, 20.08359336853027343, 1.675011634826660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Haughty Aristocrat (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus)
(@CGUID+369, 104695, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1200.15283203125, 3261.55126953125, 53.99741363525390625, 0.522720992565155029, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Merchant (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%, 202427 - Mod Scale 150%)
(@CGUID+370, 104694, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1154.265625, 3257.31103515625, 20.0002593994140625, 4.994930267333984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122), -- Suramar Citizen (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
(@CGUID+371, 104695, 1571, 8079, 8183, '8,23,2,24', 0, 0, 0, 0, 1161.307373046875, 3251.192626953125, 20.0002593994140625, 5.4977874755859375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61122); -- Suramar Merchant (Area: Midnight Court - Difficulty: Heroic) CreateObject1 (Auras: 196285 - Mod Scale 85-100%)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+371;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+129, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213105'), -- Suspicious Noble - 213105 - Costume 13
(@CGUID+131, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '123168'), -- Suramar Dockworker - 123168 - Mod Scale 115-120%
(@CGUID+134, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213089'), -- Suspicious Noble - 213089 - Costume 09
(@CGUID+136, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213100'), -- Suspicious Noble - 213100 - Costume 07
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213103'), -- Suspicious Noble - 213103 - Costume 11
(@CGUID+153, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '123168'), -- Suramar Dockworker - 123168 - Mod Scale 115-120%
(@CGUID+155, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213097'), -- Suspicious Noble - 213097 - Costume 04
(@CGUID+156, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285 220629'), -- Fancy Noble - 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus
(@CGUID+159, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213099'), -- Suspicious Noble - 213099 - Costume 06
(@CGUID+162, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213104 227258'), -- Suspicious Noble - 213104 - Costume 12, 227258 - Truthguard Area Trigger
(@CGUID+170, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '123168'), -- Suramar Dockworker - 123168 - Mod Scale 115-120%
(@CGUID+171, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213108'), -- Suspicious Noble - 213108 - Costume 16
(@CGUID+177, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213106'), -- Suspicious Noble - 213106 - Costume 14
(@CGUID+178, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213095'), -- Suspicious Noble - 213095 - Costume 02
(@CGUID+179, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213080'), -- Suspicious Noble - 213080 - Costume 01
(@CGUID+180, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213102'), -- Suspicious Noble - 213102 - Costume 10
(@CGUID+195, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213098'), -- Suspicious Noble - 213098 - Costume 05
(@CGUID+196, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213096'), -- Suspicious Noble - 213096 - Costume 03
(@CGUID+197, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213107'), -- Suspicious Noble - 213107 - Costume 15
(@CGUID+199, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213101'), -- Suspicious Noble - 213101 - Costume 08
(@CGUID+204, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '123168'), -- Suramar Dockworker - 123168 - Mod Scale 115-120%
(@CGUID+208, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '123168'), -- Suramar Dockworker - 123168 - Mod Scale 115-120%
(@CGUID+231, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '196285'), -- Fancy Noble - 196285 - Mod Scale 85-100%
(@CGUID+248, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 3, '196285 220633'), -- Suramar Civilian - 196285 - Mod Scale 85-100%, 220633 - Spellblade Aluriel
(@CGUID+273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285 220629'), -- Haughty Aristocrat - 196285 - Mod Scale 85-100%, 220629 - Star Augur Etraeus
(@CGUID+297, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285 207221'), -- Mana Saber - 196285 - Mod Scale 85-100%, 207221 - Sleeping
(@CGUID+312, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- Guardian Construct - 18950 - Invisibility and Stealth Detectiont
(@CGUID+316, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285 207221'); -- Mana Saber - 196285 - Mod Scale 85-100%, 207221 - Sleeping

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+89;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 249386, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1003.1146240234375, 3809.075439453125, 6.770661354064941406, 6.031605243682861328, 0, 0, -0.1254587173461914, 0.992098808288574218, 7200, 255, 1, 61122), -- Arcane Barrier (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+1, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 951.86114501953125, 3819.104248046875, 85.21477508544921875, 5.497788906097412109, -0.0990457534790039, -0.23911762237548828, -0.36964321136474609, 0.892399370670318603, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+2, 253955, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1002.6956787109375, 3856.19873046875, 11.44763565063476562, 3.795100688934326171, 0, 0, -0.94708919525146484, 0.320970475673675537, 7200, 255, 1, 61122), -- Meeting Stone (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+3, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 988.39239501953125, 3829.474853515625, 85.0572509765625, 2.356193065643310546, 0.239117622375488281, -0.0990457534790039, 0.892398834228515625, 0.369644463062286376, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+4, 280905, 1571, 8079, 8079, '8,23,2,24', 0, 0, 989.90802001953125, 3843.788330078125, 85.44903564453125, 0.787178754806518554, 0, 0, 0.383505821228027343, 0.923538446426391601, 7200, 255, 1, 61122), -- Magical Door (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+5, 252245, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1017.8524169921875, 3827.853271484375, 9.486422538757324218, 4.531371593475341796, 0, 0, -0.76812458038330078, 0.640300452709197998, 7200, 255, 1, 61122), -- Instance Portal (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+6, 249386, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1024.15283203125, 3805.538330078125, 7.176135540008544921, 6.126031875610351562, 0, 0, -0.07849597930908203, 0.996914446353912353, 7200, 255, 1, 61122), -- Arcane Barrier (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+7, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 939.935791015625, 3781.1103515625, 85.0572509765625, 2.356193065643310546, 0.239117622375488281, -0.0990457534790039, 0.892398834228515625, 0.369644463062286376, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+8, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 975.435791015625, 3842.592041015625, 85.0572509765625, 5.497788906097412109, -0.0990457534790039, -0.23911762237548828, -0.36964321136474609, 0.892399370670318603, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+9, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1045.44970703125, 3847.236083984375, 85.38779449462890625, 1.886277556419372558, 0, 0, 0.809405326843261718, 0.587250351905822753, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+10, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 965.59027099609375, 3806.57470703125, 85.21477508544921875, 2.356193065643310546, 0.239117622375488281, -0.0990457534790039, 0.892398834228515625, 0.369644463062286376, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+11, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1019.72918701171875, 3842.80810546875, 84.6025390625, 1.640053153038024902, 0, 0, 0.731163978576660156, 0.682201802730560302, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+12, 249386, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1008.24652099609375, 3779.6650390625, 4.419987678527832031, 4.521422386169433593, 0, 0, -0.77130031585693359, 0.636471390724182128, 7200, 255, 1, 61122), -- Arcane Barrier (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+13, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1005.55377197265625, 3913.520751953125, 84.48506927490234375, 5.405158042907714843, 0, 0, -0.42504692077636718, 0.905171334743499755, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+14, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 884.09893798828125, 3719.66064453125, 96.12912750244140625, 2.126750469207763671, 0, 0, 0.87400054931640625, 0.48592492938041687, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+15, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 917.62152099609375, 3751.6728515625, 84.06383514404296875, 2.264113426208496093, 0, 0, 0.905287742614746093, 0.424798876047134399, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+16, 280937, 1571, 8079, 8079, '8,23,2,24', 0, 0, 861.56597900390625, 3715.39404296875, 97.12969970703125, 0.785396814346313476, 0.115075111389160156, -0.27781581878662109, 0.364971160888671875, 0.881119847297668457, 7200, 255, 1, 61122), -- Ramp (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+17, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 862.921875, 3734.764892578125, 96.12912750244140625, 1.736371636390686035, 0, 0, 0.763157844543457031, 0.646212100982666015, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+18, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 881.045166015625, 3716.663330078125, 96.12912750244140625, 2.120093345642089843, 0, 0, 0.872378349304199218, 0.488831281661987304, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+19, 280939, 1571, 8079, 8079, '8,23,2,24', 0, 0, 891.029541015625, 3764.265625, 98.1026763916015625, 5.653137683868408203, 0, 0, -0.30983924865722656, 0.95078897476196289, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+20, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1059.7760009765625, 3858.858642578125, 84.59186553955078125, 2.426459789276123046, 0, 0, 0.936751365661621093, 0.349995583295822143, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+21, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 873.75, 3692.122314453125, 98.0908660888671875, 3.388229846954345703, 0, 0, -0.99240589141845703, 0.123006179928779602, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+22, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1066.2569580078125, 3879.232666015625, 83.9866485595703125, 3.283058643341064453, 0, 0, -0.99749946594238281, 0.070673964917659759, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+23, 280939, 1571, 8079, 8079, '8,23,2,24', 0, 0, 910.14581298828125, 3745.27001953125, 98.09719085693359375, 5.341836929321289062, 0, 0, -0.45348739624023437, 0.891262710094451904, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+24, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 865.640625, 3738.346435546875, 96.12912750244140625, 2.540265083312988281, 0, 0, 0.955140113830566406, 0.296154260635375976, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+25, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1024.4583740234375, 3920.064208984375, 84.29038238525390625, 4.720674991607666015, 0, 0, -0.70417118072509765, 0.710030257701873779, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+26, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 864.0867919921875, 3711.857666015625, 89.3632965087890625, 0.13552771508693695, -0.27059793472290039, -0.65328121185302734, -0.27059745788574218, 0.653282046318054199, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+27, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 994.03643798828125, 3901.854248046875, 83.68239593505859375, 5.882889270782470703, 0, 0, -0.19881439208984375, 0.980037152767181396, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+28, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 862.64239501953125, 3734.9453125, 96.12912750244140625, 5.684318065643310546, 0, 0, -0.29497909545898437, 0.955503702163696289, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+29, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 880.16839599609375, 3717.47314453125, 96.12912750244140625, 1.322858691215515136, 0, 0, 0.614245414733886718, 0.789115071296691894, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+30, 280940, 1571, 8079, 8079, '8,23,2,24', 0, 0, 872.36456298828125, 3701.552978515625, 97.65866851806640625, 0.484137892723083496, 0, 0, 0.239711761474609375, 0.970844089984893798, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+31, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 988.578125, 3873.475830078125, 84.2935943603515625, 6.249570846557617187, 0, 0, -0.01680660247802734, 0.999858736991882324, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+32, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 860.13543701171875, 3715.63623046875, 89.3632965087890625, 1.180659413337707519, 0.653281211853027343, -0.27059745788574218, 0.653281211853027343, 0.270599901676177978, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+33, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 876.01739501953125, 3715.443603515625, 96.12912750244140625, 5.243314266204833984, 0, 0, -0.49682426452636718, 0.867851197719573974, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+34, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 897.685791015625, 3771.2578125, 82.9209136962890625, 5.613436698913574218, 0, 0, -0.32865047454833984, 0.944451630115509033, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+35, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1028.6822509765625, 3854.703125, 82.31735992431640625, 5.4977874755859375, -0.49792289733886718, -0.50206756591796875, -0.49792289733886718, 0.502069473266601562, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+36, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 859.935791015625, 3731.239501953125, 96.12914276123046875, 5.656827449798583984, 0, 0, -0.30808448791503906, 0.951359033584594726, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+37, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1053.8038330078125, 3905.490478515625, 83.68235015869140625, 3.90700697898864746, 0, 0, -0.92765712738037109, 0.373433083295822143, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+38, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 926.9913330078125, 3794.192626953125, 85.0572509765625, 5.497788906097412109, -0.0990457534790039, -0.23911762237548828, -0.36964321136474609, 0.892399370670318603, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+39, 280905, 1571, 8079, 8079, '8,23,2,24', 0, 0, 893.50347900390625, 3747.329833984375, 98.07750701904296875, 0.792171061038970947, 0, 0, 0.385809898376464843, 0.922578334808349609, 7200, 255, 1, 61122), -- Magical Door (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+40, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 870.3663330078125, 3706.54248046875, 97.0458984375, 0, 0, 0, 0, 1, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+41, 252551, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1078.2882080078125, 3451.626708984375, 32.40755081176757812, 0, 0, 0, 0, 1, 7200, 255, 1, 61122), -- Cylinder Collision (8.0 scale) (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+42, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 772.935791015625, 3645.271728515625, 96.12912750244140625, 5.309874534606933593, 0, 0, -0.46767234802246093, 0.883901894092559814, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+43, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 779.9913330078125, 3673.526123046875, 98.0999755859375, 0.24907366931438446, -0.02754783630371093, 0.0031280517578125, 0.124341964721679687, 0.991852045059204101, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+44, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 789.310791015625, 3646.662353515625, 89.3632965087890625, 1.180659413337707519, 0.653281211853027343, -0.27059745788574218, 0.653281211853027343, 0.270599901676177978, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+45, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 770.68402099609375, 3644.335205078125, 96.12911224365234375, 5.243314266204833984, 0, 0, -0.49682426452636718, 0.867851197719573974, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+46, 265469, 1571, 8079, 8079, '8,23,2,24', 0, 0, 817.164306640625, 3901.79638671875, 0.101563811302185058, 1.203346967697143554, 0, 0, 0.566022872924804687, 0.824389517307281494, 7200, 255, 24, 61122), -- Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath003 (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+47, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 792.08160400390625, 3644.010498046875, 89.3632965087890625, 0.13552771508693695, -0.27059793472290039, -0.65328121185302734, -0.27059745788574218, 0.653282046318054199, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+48, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 784.04864501953125, 3694.12060546875, 98.09995269775390625, 5.895446300506591796, 0, 0, -0.192657470703125, 0.9812660813331604, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+49, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 803.1649169921875, 3638.6484375, 98.0999755859375, 0.599891424179077148, 0, 0, 0.295468330383300781, 0.955352544784545898, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+50, 280940, 1571, 8079, 8079, '8,23,2,24', 0, 0, 847.154541015625, 3727.09033203125, 97.65866851806640625, 4.282427310943603515, 0, 0, -0.8416757583618164, 0.539983272552490234, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+51, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 825.75, 3728.4462890625, 98.610137939453125, 4.873485565185546875, 0, 0, -0.6479196548461914, 0.761708676815032958, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+52, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 778.765625, 3648.552001953125, 96.12912750244140625, 2.126750469207763671, 0, 0, 0.87400054931640625, 0.48592492938041687, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+53, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 760.06427001953125, 3619.958251953125, 97.50475311279296875, 3.920455455780029296, 0, 0, -0.9251251220703125, 0.379662364721298217, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+54, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 849.14581298828125, 3641.9921875, 99.29076385498046875, 2.097330570220947265, 0, 0, 0.866758346557617187, 0.498728334903717041, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+55, 252551, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1117.8958740234375, 3437.365478515625, 38.9958648681640625, 0, 0, 0, 0, 1, 7200, 255, 1, 61122), -- Cylinder Collision (8.0 scale) (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+56, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 766.08856201171875, 3613.374267578125, 97.38225555419921875, 0.803893268108367919, 0, 0, 0.391210556030273437, 0.920301198959350585, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+57, 266919, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1235.945556640625, 4205.98046875, -65.1804656982421875, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 7200, 255, 1, 61122), -- The Nighthold Portcullis (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+58, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 819.6319580078125, 3635.546875, 98.0999908447265625, 1.339267730712890625, 0, 0, 0.620698928833007812, 0.784049034118652343, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+59, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 795.02606201171875, 3631.520751953125, 96.12912750244140625, 2.649946451187133789, 0, 0, 0.969937324523925781, 0.243354812264442443, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+60, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 870.185791015625, 3669.0400390625, 100.3794174194335937, 2.854562759399414062, 0, 0, 0.989719390869140625, 0.143022865056991577, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+61, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 852.078125, 3724.770751953125, 97.0458984375, 3.798290252685546875, 0, 0, -0.94657611846923828, 0.322480469942092895, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+62, 280938, 1571, 8079, 8079, '8,23,2,24', 0, 0, 790.1336669921875, 3623.8291015625, 96.12912750244140625, 5.766509532928466796, 0, 0, -0.25547409057617187, 0.966815888881683349, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+63, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 763.03125, 3616.734375, 97.32089996337890625, 0, 0, 0, 0, 1, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+64, 280940, 1571, 8079, 8079, '8,23,2,24', 0, 0, 782.375, 3661.80810546875, 97.65866851806640625, 3.56963968276977539, 0, 0, -0.97718429565429687, 0.212393224239349365, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+65, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 792.045166015625, 3625.6650390625, 96.1291351318359375, 2.547976970672607421, 0, 0, 0.956274986267089843, 0.292469054460525512, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+66, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 784.09027099609375, 3656.718017578125, 97.0458984375, 3.08545851707458496, 0, 0, 0.999606132507324218, 0.02806343138217926, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+67, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 837.98614501953125, 3728.201416015625, 96.950347900390625, 4.420878410339355468, 0, 0, -0.80230903625488281, 0.596908926963806152, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+68, 253922, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1219.917724609375, 3433.73876953125, 62.22258377075195312, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 7200, 255, 1, 61122), -- Apprentice's Door (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+69, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 792.717041015625, 3627.661376953125, 96.12912750244140625, 1.846054434776306152, 0, 0, 0.79743194580078125, 0.603408873081207275, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+70, 252551, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1083.3853759765625, 3445.4853515625, 30.71670913696289062, 0, 0, 0, 0, 1, 7200, 255, 1, 61122), -- Cylinder Collision (8.0 scale) (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+71, 251846, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1294.680419921875, 3467.20068359375, 30.56838798522949218, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 7200, 255, 1, 61122), -- House Door (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+72, 252551, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1129.1632080078125, 3440.124267578125, 38.3105621337890625, 0, 0, 0, 0, 1, 7200, 255, 1, 61122), -- Cylinder Collision (8.0 scale) (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+73, 251849, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1100.499755859375, 3435.92578125, 20.76276779174804687, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 7200, 255, 1, 61122), -- Waypoint Door (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+74, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1106.5, 3960.748291015625, 85.0572357177734375, 0.774228334426879882, 0, 0, 0.3775177001953125, 0.926002383232116699, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+75, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 762.88543701171875, 3616.5078125, 97.57572174072265625, 0.798714756965637207, 0, 0, 0.388826370239257812, 0.921311080455780029, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+76, 249386, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1205.78125, 3531.568603515625, 1.452853798866271972, 1.46751868724822998, 0, 0, 0.669666290283203125, 0.742662131786346435, 7200, 255, 1, 61122), -- Arcane Barrier (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+77, 280941, 1571, 8079, 8079, '8,23,2,24', 0, 0, 774.8350830078125, 3646.364501953125, 96.12912750244140625, 1.322858691215515136, 0, 0, 0.614245414733886718, 0.789115071296691894, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+78, 280936, 1571, 8079, 8079, '8,23,2,24', 0, 0, 797.66668701171875, 3712.7587890625, 98.0999908447265625, 5.576823234558105468, 0, 0, -0.34588432312011718, 0.938277184963226318, 7200, 255, 1, 61122), -- Collision (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+79, 280940, 1571, 8079, 8079, '8,23,2,24', 0, 0, 807.953125, 3636.0546875, 98.09996795654296875, 1.084030508995056152, 0, 0, 0.515863418579101562, 0.856670856475830078, 7200, 255, 1, 61122), -- Fence (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+80, 261535, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1726.179443359375, 4608.02685546875, 116.931854248046875, 2.09438943862915039, 0, 0, 0.866024017333984375, 0.500002384185791015, 7200, 255, 1, 61122), -- Doodad_7DU_SuramarCatacombs_ToggleLight003 (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+81, 265470, 1571, 8079, 8079, '8,23,2,24', 0, 0, 638.8380126953125, 4056.74462890625, 0.101563811302185058, 3.835367918014526367, 0, 0, -0.94043540954589843, 0.339972376823425292, 7200, 255, 24, 61122), -- Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath004 (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+82, 261534, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1776.9173583984375, 4638.84423828125, 128.9010772705078125, 5.248200893402099609, 0, 0, -0.49470233917236328, 0.869062483310699462, 7200, 255, 1, 61122), -- Doodad_7DU_SuramarCatacombs_ToggleLight002 (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+83, 261533, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1677.0089111328125, 4577.84375, 128.9010772705078125, 2.09438943862915039, 0, 0, 0.866024017333984375, 0.500002384185791015, 7200, 255, 1, 61122), -- Doodad_7DU_SuramarCatacombs_ToggleLight001 (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+84, 265435, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1725.245361328125, 4608.9443359375, 116.2399139404296875, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 7200, 255, 1, 61122), -- Ancient Seed Holder (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+85, 251847, 1571, 8079, 8079, '8,23,2,24', 0, 0, 1027.24560546875, 3251.447998046875, 25.12713432312011718, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61122), -- Manor Door (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+86, 251848, 1571, 8079, 8079, '8,23,2,24', 0, 0, 906.86505126953125, 3131.031494140625, 54.84539413452148437, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61122), -- Skyward Terrace (Area: Court of Stars - Difficulty: Heroic) CreateObject1
(@OGUID+87, 252968, 1571, 8079, 8181, '8,23,2,24', 0, 0, 1250.763916015625, 3390.033935546875, 51.76242446899414062, 1.670762419700622558, 0, 0, 0.741552352905273437, 0.670895040035247802, 7200, 255, 1, 61122), -- Nightborne Goods (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@OGUID+88, 252966, 1571, 8079, 8181, '8,23,2,24', 0, 0, 1252.8541259765625, 3387.861083984375, 50.780975341796875, 1.234492182731628417, 0, 0, 0.578791618347167968, 0.8154754638671875, 7200, 255, 1, 61122), -- Nightborne Bazaar (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
(@OGUID+89, 252967, 1571, 8079, 8181, '8,23,2,24', 0, 0, 1255.34375, 3388.5869140625, 51.80642318725585937, 1.013432264328002929, 0, 0, 0.485308647155761718, 0.874342918395996093, 7200, 255, 1, 61122); -- Nightborne Goods (Area: Moonlit Landing - Difficulty: Heroic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+89;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+1, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+2, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Meeting Stone
(@OGUID+3, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+7, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+8, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+9, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+10, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+11, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+13, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+14, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+15, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+16, 0, 0, 0, 1, 0, 9192), -- Ramp
(@OGUID+17, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+18, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+19, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+20, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+21, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+22, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+23, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+24, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+25, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+26, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+27, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+28, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+29, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+30, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+31, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+32, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+33, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+34, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+35, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+36, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+37, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+38, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+40, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+42, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+43, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+44, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+45, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+46, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath003
(@OGUID+47, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+48, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+49, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+50, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+51, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+52, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+53, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+54, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+56, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+57, 0, 0, -0.86602526903152465, 0.500000238418579101, 0, 0), -- The Nighthold Portcullis
(@OGUID+58, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+59, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+60, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+61, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+62, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+63, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+64, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+65, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+66, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+67, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+68, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Apprentice's Door
(@OGUID+69, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+71, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- House Door
(@OGUID+73, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Waypoint Door
(@OGUID+74, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+75, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+77, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+78, 0, 0, 0, 1, 0, 9192), -- Collision
(@OGUID+79, 0, 0, 0, 1, 0, 9192), -- Fence
(@OGUID+80, 0, 0, 0.866024374961853027, 0.500001966953277587, 0, 0), -- Doodad_7DU_SuramarCatacombs_ToggleLight003
(@OGUID+81, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Doodad_7NB_NIGHTBORN_GONDOLA_LARGE_LongPath004
(@OGUID+82, 0, 0, 0.866024374961853027, 0.500001966953277587, 0, 0), -- Doodad_7DU_SuramarCatacombs_ToggleLight002
(@OGUID+83, 0, 0, 0.866024374961853027, 0.500001966953277587, 0, 0), -- Doodad_7DU_SuramarCatacombs_ToggleLight001
(@OGUID+84, 0, 0, 0.866024374961853027, 0.500001966953277587, 0, 0), -- Ancient Seed Holder
(@OGUID+85, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Manor Door
(@OGUID+86, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0); -- Skyward Terrace

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (108419 /*108419 (Automated Sweeper) - Automated Sweeper*/, 105117 /*105117 (Flask of the Solemn Night) - Flask of the Solemn Night*/, 105719 /*105719 (Mana Saber) - Mod Scale 85-100%, Sleeping*/, 132602 /*132602 (Ash) - Mod Scale 85-100%*/, 132603 /*132603 (Mrs. Fluffymuffins) - Mod Scale 85-100%*/, 132604 /*132604 (Shadow) - Mod Scale 85-100%*/, 132600 /*132600 (Mew) - Mod Scale 85-100%*/, 132601 /*132601 (Bella) - Mod Scale 85-100%*/, 104218 /*104218 (Advisor Melandrus) - Wind Hands, [DNT] Send Event <Points> On Enter Combat*/, 105765 /*105765 (Gale Stalker) - Ride Vehicle Hardcoded*/, 104277 /*104277 (Legion Hound) - Invisibility and Stealth Detection*/, 107471 /*107471 (Wealthy Elite) - Mod Scale 85-100%, Star Augur Etraeus*/, 107442 /*107442 (Suspicious Suramar Noble)*/, 111362 /*111362 (Nightborne Boat)*/, 104295 /*104295 (Blazing Imp)*/, 111363 /*111363 (Nightborne Supplies)*/, 111364 /*111364 (Nightborne Supplies)*/, 104300 /*104300 (Shadow Mistress)*/, 105715 /*105715 (Watchful Inquisitor) - Grim Guard*/, 111365 /*111365 (Nightborne Supplies)*/, 107435 /*107435 (Suspicious Noble) - Costume 13*/, 107472 /*107472 (Fancy Noble) - Mod Scale 85-100%, Mod Scale 150%*/, 111366 /*111366 (Nightborne Supplies)*/, 104695 /*104695 (Suramar Merchant) - Mod Scale 85-100%, Mod Scale 150%*/, 107470 /*107470 (Haughty Aristocrat) - Mod Scale 85-100%, Mod Scale 150%*/, 107486 /*107486 (Chatty Rumormonger)*/, 107324 /*107324 (Suramar Child) - Star Augur Etraeus*/, 104694 /*104694 (Suramar Citizen) - Mod Scale 85-100%*/, 113617 /*113617 (Dusk Lily Agent) - Mod Scale 125%, Stealth*/, 111563 /*111563 (Duskwatch Guard)*/, 104217 /*104217 (Talixae Flamewreath) - Bond of Flame, Flame Hands, [DNT] Send Event <Points> On Enter Combat, Dual Wield*/, 104245 /*104245 (Arcane Beacon) - Watchpost Vicinity, Spotlight*/, 104273 /*104273 (Jazshariu) - Bond of Strength*/, 104274 /*104274 (Baalgar the Watchful) - Bond of Cruelty*/, 104275 /*104275 (Imacu'tya) - Bond of Cunning*/, 105704 /*105704 (Arcane Manifestation)*/, 105157 /*105157 (Arcane Power Conduit) - Arcane Power Conduit*/, 104251 /*104251 (Duskwatch Sentry) - Spotlight*/, 104270 /*104270 (Guardian Construct) - Invisibility and Stealth Detection*/, 105705 /*105705 (Bound Energy)*/, 104696 /*104696 (Suramar Civilian) - Mod Scale 85-100%*/, 105699 /*105699 (Mana Saber) - Invisibility and Stealth Detection*/, 104247 /*104247 (Duskwatch Arcanist) - Arcane Hands*/, 105296 /*105296 (Ly'leth Lunastre)*/, 107141 /*107141 (Nightborne Boat)*/, 107151 /*107151 (Suramar Noble) - Ride Vehicle Hardcoded, Mod Scale 125%*/, 104215 /*104215 (Patrol Captain Gerdo) - Area Secured, Command, [DNT] Send Event <Points> On Enter Combat*/, 107564 /*107564 (Conversation Stalker)*/, 132605 /*132605 (Phaseshifting Platform)*/, 132607 /*132607 (Lightlock)*/, 104246 /*104246 (Duskwatch Guard)*/, 111372 /*111372 (Suramar Dockworker) - Mod Scale 115-120%*/, 105703 /*105703 (Mana Wyrm)*/, 111367 /*111367 (Suramar Dockworker) - Mod Scale 115-120%*/, 111572 /*111572 (Engorged Manafeeder) - Mod Scale 70-130%*/, 105729 /*105729 (Signal Lantern) - Lantern*/, 111575 /*111575 (Overgrown Eel) - Mod Scale 70-130%*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(108419, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '215252'), -- 108419 (Automated Sweeper) - Automated Sweeper
(105117, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '208182'), -- 105117 (Flask of the Solemn Night) - Flask of the Solemn Night
(105719, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285'), -- 105719 (Mana Saber) - Mod Scale 85-100%, Sleeping
(132602, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '196285'), -- 132602 (Ash) - Mod Scale 85-100%
(132603, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '196285'), -- 132603 (Mrs. Fluffymuffins) - Mod Scale 85-100%
(132604, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '196285'), -- 132604 (Shadow) - Mod Scale 85-100%
(132600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '196285'), -- 132600 (Mew) - Mod Scale 85-100%
(132601, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '196285'), -- 132601 (Bella) - Mod Scale 85-100%
(104218, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '210140 355784'), -- 104218 (Advisor Melandrus) - Wind Hands, [DNT] Send Event <Points> On Enter Combat
(105765, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 105765 (Gale Stalker) - Ride Vehicle Hardcoded
(104277, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 104277 (Legion Hound) - Invisibility and Stealth Detection
(107471, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285 220629'), -- 107471 (Wealthy Elite) - Mod Scale 85-100%, Star Augur Etraeus
(107442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 107442 (Suspicious Suramar Noble)
(111362, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 111362 (Nightborne Boat)
(104295, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 104295 (Blazing Imp)
(111363, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 111363 (Nightborne Supplies)
(111364, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 111364 (Nightborne Supplies)
(104300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 104300 (Shadow Mistress)
(105715, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '211861'), -- 105715 (Watchful Inquisitor) - Grim Guard
(111365, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 111365 (Nightborne Supplies)
(107435, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '213105'), -- 107435 (Suspicious Noble) - Costume 13
(107472, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285'), -- 107472 (Fancy Noble) - Mod Scale 85-100%, Mod Scale 150%
(111366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 111366 (Nightborne Supplies)
(104695, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285'), -- 104695 (Suramar Merchant) - Mod Scale 85-100%, Mod Scale 150%
(107470, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285'), -- 107470 (Haughty Aristocrat) - Mod Scale 85-100%, Mod Scale 150%
(107486, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 107486 (Chatty Rumormonger)
(107324, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '220629'), -- 107324 (Suramar Child) - Star Augur Etraeus
(104694, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285'), -- 104694 (Suramar Citizen) - Mod Scale 85-100%
(113617, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '188236 86603'), -- 113617 (Dusk Lily Agent) - Mod Scale 125%, Stealth
(111563, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 111563 (Duskwatch Guard)
(104217, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '209723 209435 355784 42459'), -- 104217 (Talixae Flamewreath) - Bond of Flame, Flame Hands, [DNT] Send Event <Points> On Enter Combat, Dual Wield
(104245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '212480 206309'), -- 104245 (Arcane Beacon) - Watchpost Vicinity, Spotlight
(104273, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '207819'), -- 104273 (Jazshariu) - Bond of Strength
(104274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '209717'), -- 104274 (Baalgar the Watchful) - Bond of Cruelty
(104275, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '209712'), -- 104275 (Imacu'tya) - Bond of Cunning
(105704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 105704 (Arcane Manifestation)
(105157, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '208274'), -- 105157 (Arcane Power Conduit) - Arcane Power Conduit
(104251, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '227148'), -- 104251 (Duskwatch Sentry) - Spotlight
(104270, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 104270 (Guardian Construct) - Invisibility and Stealth Detection
(105705, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 105705 (Bound Energy)
(104696, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '196285'), -- 104696 (Suramar Civilian) - Mod Scale 85-100%
(105699, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '18950'), -- 105699 (Mana Saber) - Invisibility and Stealth Detection
(104247, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, '209438'), -- 104247 (Duskwatch Arcanist) - Arcane Hands
(105296, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 105296 (Ly'leth Lunastre)
(107141, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 107141 (Nightborne Boat)
(107151, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 107151 (Suramar Noble) - Ride Vehicle Hardcoded, Mod Scale 125%
(104215, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '227147 210143 355784'), -- 104215 (Patrol Captain Gerdo) - Area Secured, Command, [DNT] Send Event <Points> On Enter Combat
(107564, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''), -- 107564 (Conversation Stalker)
(132605, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 132605 (Phaseshifting Platform)
(132607, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 132607 (Lightlock)
(104246, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 104246 (Duskwatch Guard)
(111372, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 111372 (Suramar Dockworker) - Mod Scale 115-120%
(105703, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 105703 (Mana Wyrm)
(111367, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 111367 (Suramar Dockworker) - Mod Scale 115-120%
(111572, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '151051'), -- 111572 (Engorged Manafeeder) - Mod Scale 70-130%
(105729, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '209519'), -- 105729 (Signal Lantern) - Lantern
(111575, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '151051'); -- 111575 (Overgrown Eel) - Mod Scale 70-130%

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (252966 /*Nightborne Bazaar*/, 252968 /*Nightborne Goods*/, 233778 /*Collision PC Size*/, 251848 /*Skyward Terrace*/, 251847 /*Manor Door*/, 265435 /*Ancient Seed Holder*/, 251849 /*Waypoint Door*/, 251846 /*House Door*/, 253922 /*Apprentice's Door*/, 252551 /*Cylinder Collision (8.0 scale)*/, 280940 /*Fence*/, 280939 /*Fence*/, 280941 /*Fence*/, 280937 /*Ramp*/, 280938 /*Fence*/, 280905 /*Magical Door*/, 280936 /*Collision*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(252966, 1375, 0x2000, 0, 0), -- Nightborne Bazaar
(252968, 1375, 0x2000, 0, 0), -- Nightborne Goods
(233778, 190, 0x0, 0, 0), -- Collision PC Size
(251848, 0, 0x22, 0, 0), -- Skyward Terrace
(251847, 1375, 0x20, 0, 0), -- Manor Door
(265435, 0, 0x24, 0, 0), -- Ancient Seed Holder
(251849, 1375, 0x20, 0, 0), -- Waypoint Door
(251846, 1375, 0x20, 0, 0), -- House Door
(253922, 1375, 0x20, 0, 0), -- Apprentice's Door
(252551, 0, 0x20, 0, 0), -- Cylinder Collision (8.0 scale)
(280940, 1375, 0x20, 0, 9192), -- Fence
(280939, 1375, 0x20, 0, 9192), -- Fence
(280941, 1375, 0x20, 0, 9192), -- Fence
(280937, 1375, 0x20, 0, 9192), -- Ramp
(280938, 1375, 0x20, 0, 9192), -- Fence
(280905, 0, 0x20, 0, 0), -- Magical Door
(280936, 1375, 0x20, 0, 9192); -- Collision

-- Template
UPDATE `creature_template` SET `faction`=190, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x80000, `VehicleId`=4711 WHERE `entry`=105264; -- Nightborne Boat
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000, `VehicleId`=5780 WHERE `entry`=132605; -- Phaseshifting Platform
UPDATE `creature_template` SET `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x4000800, `unit_flags3`=0x1000001, `VehicleId`=5781 WHERE `entry`=132607; -- Lightlock
UPDATE `creature_template` SET `faction`=2735, `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `VehicleId`=4821 WHERE `entry`=108422; -- Automated Sweeper
UPDATE `creature_template` SET `faction`=2735, `speed_walk`=0.400000005960464477, `speed_run`=0.142857149243354797, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800 WHERE `entry`=108421; -- Mana Kitten
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` = 107559;

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (105719,132602,132603,132604,132600,132601,132599,107471,111362,111363,111364,111365,107472,111366,104695,107470,107324,104694,113617,104245,104696,105296,105264,107141,107151,107564,132605,132607,111372,111367,111572,105729,111575));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(105719, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 105719 (Mana Saber) - CanSwim
(132602, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 132602 (Ash) - CanSwim
(132603, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 132603 (Mrs. Fluffymuffins) - CanSwim
(132604, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 132604 (Shadow) - CanSwim
(132600, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 132600 (Mew) - CanSwim
(132601, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 132601 (Bella) - CanSwim
(132599, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 132599 (Lady Chaton) - CanSwim
(107471, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 107471 (Wealthy Elite) - CanSwim
(111362, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 111362 (Nightborne Boat) - CanSwim
(111363, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 111363 (Nightborne Supplies) - CanSwim
(111364, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 111364 (Nightborne Supplies) - CanSwim
(111365, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 111365 (Nightborne Supplies) - CanSwim
(107472, 2, 0, 0, 628, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 107472 (Fancy Noble) - CanSwim
(111366, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 111366 (Nightborne Supplies) - CanSwim
(104695, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 104695 (Suramar Merchant) - CanSwim
(107470, 2, 0, 0, 628, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 107470 (Haughty Aristocrat) - CanSwim
(107324, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 107324 (Suramar Child) - CanSwim
(104694, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 104694 (Suramar Citizen) - CanSwim
(113617, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 113617 (Dusk Lily Agent) - CanSwim
(104245, 2, 0, 0, 1162, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 104245 (Arcane Beacon) - Sessile, CanSwim, Floating
(104696, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 104696 (Suramar Civilian) - CanSwim
(105296, 2, 0, 0, 1162, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 105296 (Ly'leth Lunastre) - Sessile, CanSwim, Floating
(105264, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 105264 (Nightborne Boat) - CanSwim
(107141, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 107141 (Nightborne Boat) - CanSwim
(107151, 2, 0, 0, 1162, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 107151 (Suramar Noble) - Sessile, CanSwim, Floating
(107564, 2, 2, 2, 1162, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 107564 (Conversation Stalker) - 
(132605, 2, 0, 0, 776, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 132605 (Phaseshifting Platform) - Sessile, Floating
(132607, 2, 0, 0, 776, 0x20000000, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 132607 (Lightlock) - Floating - CannotTurn
(111372, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 111372 (Suramar Dockworker) - CanSwim
(111367, 2, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 111367 (Suramar Dockworker) - CanSwim
(111572, 2, 0, 0, 1162, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 111572 (Engorged Manafeeder) - CanSwim, Floating
(105729, 2, 0, 0, 1162, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61122), -- 105729 (Signal Lantern) - Sessile, Floating - CannotTurn
(111575, 2, 0, 0, 1162, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61122); -- 111575 (Overgrown Eel) - CanSwim, Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=106929, `TypeFlags`=0x200048 WHERE (`Entry`=105719 AND `DifficultyID`=2); -- Mana Saber
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=138533, `TypeFlags`=0x200048 WHERE (`Entry`=132603 AND `DifficultyID`=2); -- Mrs. Fluffymuffins
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=138532, `TypeFlags`=0x200048 WHERE (`Entry`=132602 AND `DifficultyID`=2); -- Ash
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=138534, `TypeFlags`=0x200048 WHERE (`Entry`=132604 AND `DifficultyID`=2); -- Shadow
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=138531, `TypeFlags`=0x200048 WHERE (`Entry`=132601 AND `DifficultyID`=2); -- Bella
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=138530, `TypeFlags`=0x200048 WHERE (`Entry`=132600 AND `DifficultyID`=2); -- Mew
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=138529, `TypeFlags`=0x200048 WHERE (`Entry`=132599 AND `DifficultyID`=2); -- Lady Chaton
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.75, `CreatureDifficultyID`=113558, `TypeFlags`=0x200048 WHERE (`Entry`=111362 AND `DifficultyID`=2); -- Nightborne Boat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=108909, `TypeFlags`=0x200048 WHERE (`Entry`=107471 AND `DifficultyID`=2); -- Wealthy Elite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.75, `CreatureDifficultyID`=113561, `TypeFlags`=0x200048 WHERE (`Entry`=111365 AND `DifficultyID`=2); -- Nightborne Supplies
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.75, `CreatureDifficultyID`=113560, `TypeFlags`=0x200048 WHERE (`Entry`=111364 AND `DifficultyID`=2); -- Nightborne Supplies
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.75, `CreatureDifficultyID`=113559, `TypeFlags`=0x200048 WHERE (`Entry`=111363 AND `DifficultyID`=2); -- Nightborne Supplies
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.75, `CreatureDifficultyID`=113562, `TypeFlags`=0x200048 WHERE (`Entry`=111366 AND `DifficultyID`=2); -- Nightborne Supplies
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=108910, `TypeFlags`=0x200048 WHERE (`Entry`=107472 AND `DifficultyID`=2); -- Fancy Noble
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=108908, `TypeFlags`=0x200048 WHERE (`Entry`=107470 AND `DifficultyID`=2); -- Haughty Aristocrat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=105818, `TypeFlags`=0x200048 WHERE (`Entry`=104695 AND `DifficultyID`=2); -- Suramar Merchant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=108762, `TypeFlags`=0x200048 WHERE (`Entry`=107324 AND `DifficultyID`=2); -- Suramar Child
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=105817, `TypeFlags`=0x200048 WHERE (`Entry`=104694 AND `DifficultyID`=2); -- Suramar Citizen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=116858, `TypeFlags`=0x48 WHERE (`Entry`=113617 AND `DifficultyID`=2); -- Dusk Lily Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.75, `CreatureDifficultyID`=105348, `TypeFlags`=0x60200048, `TypeFlags2`=6 WHERE (`Entry`=104245 AND `DifficultyID`=2); -- Arcane Beacon
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=105819, `TypeFlags`=0x200048 WHERE (`Entry`=104696 AND `DifficultyID`=2); -- Suramar Civilian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=1.649999976158142089, `CreatureDifficultyID`=106491, `TypeFlags`=0x48 WHERE (`Entry`=105296 AND `DifficultyID`=2); -- Ly'leth Lunastre
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.75, `CreatureDifficultyID`=106459, `TypeFlags`=0x200048 WHERE (`Entry`=105264 AND `DifficultyID`=2); -- Nightborne Boat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=2.75, `CreatureDifficultyID`=108495, `TypeFlags`=0x200048 WHERE (`Entry`=107141 AND `DifficultyID`=2); -- Nightborne Boat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=108505, `TypeFlags`=0x200048 WHERE (`Entry`=107151 AND `DifficultyID`=2); -- Suramar Noble
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=109002 WHERE (`Entry`=107564 AND `DifficultyID`=2); -- Conversation Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=138535, `TypeFlags`=0x61000410, `TypeFlags2`=22 WHERE (`Entry`=132605 AND `DifficultyID`=2); -- Phaseshifting Platform
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=113572, `TypeFlags`=0x200048 WHERE (`Entry`=111372 AND `DifficultyID`=2); -- Suramar Dockworker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=113563, `TypeFlags`=0x200048 WHERE (`Entry`=111367 AND `DifficultyID`=2); -- Suramar Dockworker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=7, `CreatureDifficultyID`=138537, `TypeFlags`=0x60000010, `TypeFlags2`=6 WHERE (`Entry`=132607 AND `DifficultyID`=2); -- Lightlock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=113808 WHERE (`Entry`=111575 AND `DifficultyID`=2); -- Overgrown Eel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=113805 WHERE (`Entry`=111572 AND `DifficultyID`=2); -- Engorged Manafeeder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.550000011920928955, `CreatureDifficultyID`=106941, `TypeFlags`=0x60000010, `TypeFlags2`=6 WHERE (`Entry`=105729 AND `DifficultyID`=2); -- Signal Lantern

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=108419 AND `DifficultyID`=2); -- 108419 (Automated Sweeper) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61122 WHERE (`Entry`=105117 AND `DifficultyID`=2); -- 105117 (Flask of the Solemn Night) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104218 AND `DifficultyID`=2); -- 104218 (Advisor Melandrus) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61122 WHERE (`Entry`=105765 AND `DifficultyID`=2); -- 105765 (Gale Stalker) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104277 AND `DifficultyID`=2); -- 104277 (Legion Hound) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=107442 AND `DifficultyID`=2); -- 107442 (Suspicious Suramar Noble) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104295 AND `DifficultyID`=2); -- 104295 (Blazing Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104300 AND `DifficultyID`=2); -- 104300 (Shadow Mistress) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=105715 AND `DifficultyID`=2); -- 105715 (Watchful Inquisitor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=107435 AND `DifficultyID`=2); -- 107435 (Suspicious Noble) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=107486 AND `DifficultyID`=2); -- 107486 (Chatty Rumormonger) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=111563 AND `DifficultyID`=2); -- 111563 (Duskwatch Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104217 AND `DifficultyID`=2); -- 104217 (Talixae Flamewreath) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104273 AND `DifficultyID`=2); -- 104273 (Jazshariu) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104274 AND `DifficultyID`=2); -- 104274 (Baalgar the Watchful) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104275 AND `DifficultyID`=2); -- 104275 (Imacu'tya) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=105704 AND `DifficultyID`=2); -- 105704 (Arcane Manifestation) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61122 WHERE (`Entry`=105157 AND `DifficultyID`=2); -- 105157 (Arcane Power Conduit) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104251 AND `DifficultyID`=2); -- 104251 (Duskwatch Sentry) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104270 AND `DifficultyID`=2); -- 104270 (Guardian Construct) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=105705 AND `DifficultyID`=2); -- 105705 (Bound Energy) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=105699 AND `DifficultyID`=2); -- 105699 (Mana Saber) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104247 AND `DifficultyID`=2); -- 104247 (Duskwatch Arcanist) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104215 AND `DifficultyID`=2); -- 104215 (Patrol Captain Gerdo) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=104246 AND `DifficultyID`=2); -- 104246 (Duskwatch Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61122 WHERE (`Entry`=105703 AND `DifficultyID`=2); -- 105703 (Mana Wyrm) - CanSwim

-- Difficulty (Mythic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (106024,106110,105296,105264,132605,107564,111372,111367,132607,111572,105729,111575));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(106024, 23, 0, 0, 1162, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 106024 (Magical Lantern) - Sessile, Floating - CannotTurn
(106110, 23, 0, 0, 1162, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 106110 (Waterlogged Scroll) - Sessile, Floating - CannotTurn
(105296, 23, 0, 0, 1162, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 105296 (Ly'leth Lunastre) - Sessile, CanSwim, Floating
(105264, 23, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 105264 (Nightborne Boat) - CanSwim
(132605, 23, 0, 0, 776, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 132605 (Phaseshifting Platform) - Sessile, Floating
(107564, 23, 2, 2, 1162, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 107564 (Conversation Stalker) - 
(111372, 23, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 111372 (Suramar Dockworker) - CanSwim
(111367, 23, 0, 0, 1162, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 111367 (Suramar Dockworker) - CanSwim
(132607, 23, 0, 0, 776, 0x20000000, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 132607 (Lightlock) - Floating - CannotTurn
(111572, 23, 0, 0, 1162, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 111572 (Engorged Manafeeder) - CanSwim, Floating
(105729, 23, 0, 0, 1162, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61188), -- 105729 (Signal Lantern) - Sessile, Floating - CannotTurn
(111575, 23, 0, 0, 1162, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61188); -- 111575 (Overgrown Eel) - CanSwim, Floating

UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=108406 AND `DifficultyID`=23); -- 108406 (Arcane Custodian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=110960 AND `DifficultyID`=23); -- 110960 (Haughty Aristocrat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=110959 AND `DifficultyID`=23); -- 110959 (Wealthy Elite) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=112697 AND `DifficultyID`=23); -- 112697 (Suspicious Noble) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=112699 AND `DifficultyID`=23); -- 112699 (Suspicious Noble) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107756 AND `DifficultyID`=23); -- 107756 (Estate Attendant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=110958 AND `DifficultyID`=23); -- 110958 (Fancy Noble) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61188 WHERE (`DifficultyID`=23 AND `Entry` IN (111374,111936,107559));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=105410 AND `DifficultyID`=23); -- 105410 (Suramar Musician) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=110560 AND `DifficultyID`=23); -- 110560 (Vanthir) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=106296 AND `DifficultyID`=23); -- 106296 (Dusk Lily Agent) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=111937 AND `DifficultyID`=23); -- 111937 (Dusk Lily Agent) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61188 WHERE (`Entry`=105249 AND `DifficultyID`=23); -- 105249 (Nightshade Refreshments) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104278 AND `DifficultyID`=23); -- 104278 (Felbound Enforcer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61188 WHERE (`Entry`=104400 AND `DifficultyID`=23); -- 104400 (Resonant Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=108419 AND `DifficultyID`=23); -- 108419 (Automated Sweeper) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61188 WHERE (`Entry`=105117 AND `DifficultyID`=23); -- 105117 (Flask of the Solemn Night) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=105719 AND `DifficultyID`=23); -- 105719 (Mana Saber) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=132601 AND `DifficultyID`=23); -- 132601 (Bella) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=132602 AND `DifficultyID`=23); -- 132602 (Ash) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=132603 AND `DifficultyID`=23); -- 132603 (Mrs. Fluffymuffins) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=132599 AND `DifficultyID`=23); -- 132599 (Lady Chaton) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61188 WHERE (`Entry`=105765 AND `DifficultyID`=23); -- 105765 (Gale Stalker) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104218 AND `DifficultyID`=23); -- 104218 (Advisor Melandrus) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=132604 AND `DifficultyID`=23); -- 132604 (Shadow) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=132600 AND `DifficultyID`=23); -- 132600 (Mew) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104295 AND `DifficultyID`=23); -- 104295 (Blazing Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=105715 AND `DifficultyID`=23); -- 105715 (Watchful Inquisitor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104300 AND `DifficultyID`=23); -- 104300 (Shadow Mistress) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104277 AND `DifficultyID`=23); -- 104277 (Legion Hound) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=111362 AND `DifficultyID`=23); -- 111362 (Nightborne Boat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107442 AND `DifficultyID`=23); -- 107442 (Suspicious Suramar Noble) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=111365 AND `DifficultyID`=23); -- 111365 (Nightborne Supplies) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107471 AND `DifficultyID`=23); -- 107471 (Wealthy Elite) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=111364 AND `DifficultyID`=23); -- 111364 (Nightborne Supplies) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=111363 AND `DifficultyID`=23); -- 111363 (Nightborne Supplies) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107435 AND `DifficultyID`=23); -- 107435 (Suspicious Noble) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107472 AND `DifficultyID`=23); -- 107472 (Fancy Noble) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104695 AND `DifficultyID`=23); -- 104695 (Suramar Merchant) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107470 AND `DifficultyID`=23); -- 107470 (Haughty Aristocrat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=111366 AND `DifficultyID`=23); -- 111366 (Nightborne Supplies) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107486 AND `DifficultyID`=23); -- 107486 (Chatty Rumormonger) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107324 AND `DifficultyID`=23); -- 107324 (Suramar Child) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104694 AND `DifficultyID`=23); -- 104694 (Suramar Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=111563 AND `DifficultyID`=23); -- 111563 (Duskwatch Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=113617 AND `DifficultyID`=23); -- 113617 (Dusk Lily Agent) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104217 AND `DifficultyID`=23); -- 104217 (Talixae Flamewreath) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104273 AND `DifficultyID`=23); -- 104273 (Jazshariu) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104274 AND `DifficultyID`=23); -- 104274 (Baalgar the Watchful) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104275 AND `DifficultyID`=23); -- 104275 (Imacu'tya) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61188 WHERE (`Entry`=104245 AND `DifficultyID`=23); -- 104245 (Arcane Beacon) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104270 AND `DifficultyID`=23); -- 104270 (Guardian Construct) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=105704 AND `DifficultyID`=23); -- 105704 (Arcane Manifestation) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104251 AND `DifficultyID`=23); -- 104251 (Duskwatch Sentry) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=105705 AND `DifficultyID`=23); -- 105705 (Bound Energy) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104696 AND `DifficultyID`=23); -- 104696 (Suramar Civilian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=105699 AND `DifficultyID`=23); -- 105699 (Mana Saber) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104247 AND `DifficultyID`=23); -- 104247 (Duskwatch Arcanist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104246 AND `DifficultyID`=23); -- 104246 (Duskwatch Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=107141 AND `DifficultyID`=23); -- 107141 (Nightborne Boat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61188 WHERE (`Entry`=107151 AND `DifficultyID`=23); -- 107151 (Suramar Noble) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=104215 AND `DifficultyID`=23); -- 104215 (Patrol Captain Gerdo) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61188 WHERE (`Entry`=105703 AND `DifficultyID`=23); -- 105703 (Mana Wyrm) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=749, `StaticFlags1`=0x20000100, `VerifiedBuild`=61188 WHERE (`Entry`=171322 AND `DifficultyID`=23); -- 171322 (Global Affix Stalker) - Sessile, Floating

-- Path for Suramar Dockworker
SET @MOVERGUID := @CGUID+146;
SET @ENTRY := 111367;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Suramar Dockworker - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 946.4566, 3391.3743, 1.1221664, NULL, 0),
(@PATH, 1, 953.7205, 3396.8342, 1.222992, NULL, 0),
(@PATH, 2, 959, 3400.8977, 1.1514082, NULL, 0),
(@PATH, 3, 967.5243, 3407.9697, 1.0523263, NULL, 0),
(@PATH, 4, 972.04517, 3409.3298, 1.019867, NULL, 0),
(@PATH, 5, 948.6441, 3398.2388, 1.1913905, NULL, 0),
(@PATH, 6, 940.98615, 3393.1301, 1.1535335, NULL, 0),
(@PATH, 7, 934.4132, 3388.6484, 1.1055443, NULL, 0),
(@PATH, 8, 925.30383, 3385.4133, 1.1091588, NULL, 0),
(@PATH, 9, 919.71875, 3382.9688, 1.1386957, NULL, 0),
(@PATH, 10, 901.4757, 3375.2197, 1.1071782, NULL, 0),
(@PATH, 11, 893.93054, 3369.1987, 1.0919963, NULL, 0),
(@PATH, 12, 892.0156, 3357.861, 1.0968958, NULL, 0),
(@PATH, 13, 892.5677, 3346.5713, 1.1484905, NULL, 0),
(@PATH, 14, 893.9965, 3333.77, 1.222992, NULL, 0),
(@PATH, 15, 897.5625, 3343.2466, 1.09991, NULL, 0),
(@PATH, 16, 905.0382, 3353.698, 1.8323671, NULL, 0),
(@PATH, 17, 913.61456, 3360.751, 1.6290079, NULL, 0),
(@PATH, 18, 917.75867, 3367.0737, 1.2768503, NULL, 0),
(@PATH, 19, 921.4809, 3374.6953, 1.0849832, NULL, 0),
(@PATH, 20, 928.26044, 3383.0781, 1.0647078, NULL, 0),
(@PATH, 21, 934.38196, 3386.1614, 1.0732692, NULL, 0),
(@PATH, 22, 940.88544, 3389.4956, 1.1064484, NULL, 0);

UPDATE `creature` SET `position_x`=946.4566, `position_y`=3391.3743, `position_z`=1.1221664, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '123168');

-- Path for Suramar Dockworker
SET @MOVERGUID := @CGUID+149;
SET @ENTRY := 111367;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Suramar Dockworker - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 956.96875, 3380.38, 1.8117166, NULL, 5804),
(@PATH, 1, 946, 3382.336, 1.1900349, NULL, 0),
(@PATH, 2, 940.47394, 3386.3845, 1.066654, NULL, 0),
(@PATH, 3, 933.55206, 3394.1848, 1.1788461, NULL, 0),
(@PATH, 4, 926.9583, 3402.2483, 2.222992, NULL, 0),
(@PATH, 5, 922.84204, 3403.079, 2.222992, NULL, 4676),
(@PATH, 6, 914.9097, 3416.3108, 2.2229917, NULL, 0),
(@PATH, 7, 910.13367, 3417.4922, 2.222992, NULL, 6202),
(@PATH, 8, 922.7309, 3407.5754, 2.222992, NULL, 0),
(@PATH, 9, 926.2674, 3400.4011, 2.222992, NULL, 0),
(@PATH, 10, 926.0243, 3391.5425, 1.7602212, NULL, 0),
(@PATH, 11, 929.7066, 3383.1797, 1.0513182, NULL, 0),
(@PATH, 12, 935.85767, 3377.4463, 1.019867, NULL, 0),
(@PATH, 13, 947.2639, 3379.4106, 1.832367, NULL, 0);

UPDATE `creature` SET `position_x`=956.96875, `position_y`=3380.38, `position_z`=1.8117166, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '123168');

-- Path for Suramar Dockworker
SET @MOVERGUID := @CGUID+198;
SET @ENTRY := 111372;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Suramar Dockworker - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 896.0955, 3348.612, 1.0955436, NULL, 0),
(@PATH, 1, 903.66144, 3357.8923, 1.832367, NULL, 0),
(@PATH, 2, 915.2153, 3361.625, 1.6290079, NULL, 0),
(@PATH, 3, 924.3889, 3366.7483, 1.8323671, NULL, 0),
(@PATH, 4, 932.85767, 3368.6355, 1.6290078, NULL, 0),
(@PATH, 5, 943.1406, 3363.6008, 1.6291595, NULL, 5536),
(@PATH, 6, 929.5018, 3369.289, 1.6290078, NULL, 0),
(@PATH, 7, 921.85767, 3368.0696, 1.832367, NULL, 0),
(@PATH, 8, 915.52954, 3368.197, 1.0246826, NULL, 0),
(@PATH, 9, 909.8507, 3372.4446, 1.040474, NULL, 0),
(@PATH, 10, 908.0833, 3375.8047, 1.0596911, NULL, 0),
(@PATH, 11, 903.9549, 3377.77, 1.131175, NULL, 5472),
(@PATH, 12, 899.69965, 3367.52, 1.1718214, NULL, 0),
(@PATH, 13, 895.2222, 3360.6042, 1.0565851, NULL, 0),
(@PATH, 14, 897.58856, 3353.2249, 1.0572159, NULL, 0),
(@PATH, 15, 894.26215, 3346.2222, 1.128704, NULL, 0),
(@PATH, 16, 891.69446, 3338.067, 1.2145565, NULL, 4151);

UPDATE `creature` SET `position_x`=896.0955, `position_y`=3348.612, `position_z`=1.0955436, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '123168');

-- Path for Suramar Dockworker
SET @MOVERGUID := @CGUID+142;
SET @ENTRY := 111372;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Suramar Dockworker - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 923.8715, 3404.4358, 2.222992, NULL, 0),
(@PATH, 1, 916.35767, 3415.89, 2.2229917, NULL, 0),
(@PATH, 2, 911.6285, 3425.2388, 2.222992, NULL, 0),
(@PATH, 3, 904.06964, 3436.8423, 2.8967474, NULL, 0),
(@PATH, 4, 910.8264, 3425.803, 2.222992, NULL, 0),
(@PATH, 5, 916.69446, 3415.6685, 2.2229917, NULL, 0),
(@PATH, 6, 920.09375, 3407.8438, 2.222992, NULL, 0),
(@PATH, 7, 929.65625, 3397.3586, 2.222992, NULL, 0),
(@PATH, 8, 939.816, 3396.0618, 1.1934654, NULL, 0),
(@PATH, 9, 955.86633, 3405.3447, 1.1373311, NULL, 0),
(@PATH, 10, 967.4583, 3417.3298, 1.186859, NULL, 0),
(@PATH, 11, 944.1528, 3398.3655, 1.2166302, NULL, 0),
(@PATH, 12, 931.40106, 3393.467, 1.2122455, NULL, 0);

UPDATE `creature` SET `position_x`=923.8715, `position_y`=3404.4358, `position_z`=2.222992, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '123168');

-- Path for Suramar Dockworker
SET @MOVERGUID := @CGUID+18;
SET @ENTRY := 111372;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Suramar Dockworker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1154.6007, 3683.9817, 1.0416986, NULL, 0),
(@PATH, 1, 1158.7483, 3693.2874, 2.7940903, NULL, 0),
(@PATH, 2, 1159.9028, 3700.5798, 2.7940903, NULL, 0),
(@PATH, 3, 1158.7483, 3693.2874, 2.7940903, NULL, 0),
(@PATH, 4, 1154.6007, 3683.9817, 1.0416986, NULL, 0),
(@PATH, 5, 1143.7048, 3682.7864, 0.9972153, NULL, 0),
(@PATH, 6, 1130.9774, 3678.1301, 0.9972153, NULL, 0),
(@PATH, 7, 1123.4966, 3670.427, 0.9972152, NULL, 0),
(@PATH, 8, 1105.5781, 3657.4653, 0.99721533, NULL, 0),
(@PATH, 9, 1092.8079, 3660.6228, 0.9053659, NULL, 0),
(@PATH, 10, 1080.0226, 3662.395, 0.7940903, NULL, 0),
(@PATH, 11, 1069.408, 3659.1597, 0.7940902, NULL, 0),
(@PATH, 12, 1061.5764, 3655.1597, 0.8323669, NULL, 0),
(@PATH, 13, 1054.3195, 3650.507, 0.832367, NULL, 0),
(@PATH, 14, 1045.5521, 3641.9167, 1.0510575, NULL, 0),
(@PATH, 15, 1040.974, 3634.4097, 0.9129939, NULL, 0),
(@PATH, 16, 1038.9305, 3626.0608, 0.83236694, NULL, 0),
(@PATH, 17, 1040.0591, 3615.506, 0.83236694, NULL, 0),
(@PATH, 18, 1040.3594, 3607.4688, 0.83236694, NULL, 0),
(@PATH, 19, 1036.0834, 3606.606, 0.83236694, NULL, 0),
(@PATH, 20, 1040.0591, 3615.506, 0.83236694, NULL, 0),
(@PATH, 21, 1038.9305, 3626.0608, 0.83236694, NULL, 0),
(@PATH, 22, 1040.974, 3634.4097, 0.9129939, NULL, 0),
(@PATH, 23, 1045.5217, 3641.8667, 1.0966605, NULL, 0),
(@PATH, 24, 1054.3195, 3650.507, 0.832367, NULL, 0),
(@PATH, 25, 1061.5764, 3655.1597, 0.8323669, NULL, 0),
(@PATH, 26, 1069.408, 3659.1597, 0.7940902, NULL, 0),
(@PATH, 27, 1080.0226, 3662.395, 0.7940903, NULL, 0),
(@PATH, 28, 1092.7673, 3660.6328, 0.9054329, NULL, 0),
(@PATH, 29, 1105.5781, 3657.4653, 0.99721533, NULL, 0),
(@PATH, 30, 1123.4966, 3670.427, 0.9972152, NULL, 0),
(@PATH, 31, 1130.9774, 3678.1301, 0.9972153, NULL, 0),
(@PATH, 32, 1143.7048, 3682.7864, 0.9972153, NULL, 0),
(@PATH, 33, 1154.6007, 3683.9817, 1.0416986, NULL, 0),
(@PATH, 34, 1155.9846, 3687.0867, 0.9982608, NULL, 0),
(@PATH, 35, 1156.4404, 3688.1094, 1.5715766, NULL, 0),
(@PATH, 36, 1156.5798, 3688.422, 1.7791824, NULL, 0),
(@PATH, 37, 1157.2632, 3689.9553, 2.7902584, NULL, 0),
(@PATH, 38, 1157.6471, 3690.8167, 2.7940903, NULL, 0),
(@PATH, 39, 1157.7993, 3691.1582, 2.8008041, NULL, 0),
(@PATH, 40, 1158.7483, 3693.2874, 2.7940903, NULL, 0),
(@PATH, 41, 1159.9028, 3700.5798, 2.7940903, NULL, 0),
(@PATH, 42, 1158.7483, 3693.2874, 2.7940903, NULL, 0);

UPDATE `creature` SET `position_x`=1154.6007, `position_y`=3683.9817, `position_z`=1.0416986, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '123168');

-- Path for Duskwatch Sentry
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+106;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+106, @CGUID+106, 0, 0, 515, 0, 0),
(@CGUID+106, @CGUID+105, 3, 90, 515, 3, 6),
(@CGUID+106, @CGUID+101, 3, 270, 515, 3, 6);

SET @MOVERGUID := @CGUID+106;
SET @ENTRY := 104251;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Sentry - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1102.8923, 3466.2292, 19.838223, NULL, 4071),
(@PATH, 1, 1098.9966, 3475.0938, 19.838223, NULL, 0),
(@PATH, 2, 1097.8872, 3479.375, 19.838223, NULL, 0),
(@PATH, 3, 1095.1493, 3484.5044, 19.838223, NULL, 4082),
(@PATH, 4, 1097.8872, 3479.375, 19.838223, NULL, 0),
(@PATH, 5, 1098.9966, 3475.0938, 19.838223, NULL, 0),
(@PATH, 6, 1102.3854, 3470.501, 19.838223, NULL, 0);

UPDATE `creature` SET `position_x`=1102.8923, `position_y`=3466.2292, `position_z`=19.838223, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path Duskwatch Sentry
SET @MOVERGUID := @CGUID+62;
SET @ENTRY := 104251;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Sentry - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1072.0938, 3521.125, 10.412374, NULL, 0),
(@PATH, 1, 1072.1094, 3528.8281, 10.60659, NULL, 0),
(@PATH, 2, 1073.6649, 3534.4368, 10.518183, NULL, 0),
(@PATH, 3, 1079.5, 3538.8352, 10.555336, NULL, 0),
(@PATH, 4, 1086.4288, 3540.4504, 12.759179, NULL, 0),
(@PATH, 5, 1092.5173, 3538.0815, 15.977039, NULL, 0),
(@PATH, 6, 1097.6111, 3535.8196, 18.493307, NULL, 4743),
(@PATH, 7, 1092.5173, 3538.0815, 15.977039, NULL, 0),
(@PATH, 8, 1086.4288, 3540.4504, 12.759179, NULL, 0),
(@PATH, 9, 1086.2317, 3540.4045, 12.663812, NULL, 0),
(@PATH, 10, 1085.8575, 3540.3171, 12.65579, NULL, 0),
(@PATH, 11, 1085.2908, 3540.185, 12.209287, NULL, 0),
(@PATH, 12, 1081.7421, 3539.358, 10.579187, NULL, 0),
(@PATH, 13, 1079.5, 3538.8352, 10.555336, NULL, 0),
(@PATH, 14, 1073.6649, 3534.4368, 10.518183, NULL, 0),
(@PATH, 15, 1072.1094, 3528.8281, 10.60659, NULL, 0),
(@PATH, 16, 1072.0939, 3521.1875, 10.450166, NULL, 0),
(@PATH, 17, 1075.5173, 3514.692, 11.740021, NULL, 0),
(@PATH, 18, 1079.9271, 3511.4133, 14.427653, NULL, 0),
(@PATH, 19, 1084.1041, 3509.4375, 16.67013, NULL, 4269),
(@PATH, 20, 1079.9271, 3511.4133, 14.427653, NULL, 0),
(@PATH, 21, 1075.5173, 3514.692, 11.740021, NULL, 0);

UPDATE `creature` SET `position_x`=1072.0938, `position_y`=3521.125, `position_z`=10.412374, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Duskwatch Sentry
SET @MOVERGUID := @CGUID+63;
SET @ENTRY := 104251;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Sentry - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1157.4966, 3560.4705, 19.838223, NULL, 0),
(@PATH, 1, 1150.0817, 3555.1545, 19.838223, NULL, 0),
(@PATH, 2, 1149.507, 3546.3315, 19.838223, NULL, 0),
(@PATH, 3, 1154.1545, 3539.704, 19.838223, NULL, 0),
(@PATH, 4, 1149.0278, 3525.7969, 20.997217, NULL, 4178),
(@PATH, 5, 1154.1545, 3539.704, 19.838223, NULL, 0),
(@PATH, 6, 1149.507, 3546.3315, 19.838223, NULL, 0),
(@PATH, 7, 1150.0817, 3555.1545, 19.838223, NULL, 0),
(@PATH, 8, 1157.4966, 3560.4705, 19.838223, NULL, 0),
(@PATH, 9, 1165.9132, 3565.2388, 19.838219, NULL, 0),
(@PATH, 10, 1177.5209, 3567.007, 19.838215, NULL, 4119),
(@PATH, 11, 1165.9132, 3565.2388, 19.838219, NULL, 0);

UPDATE `creature` SET `position_x`=1157.4966, `position_y`=3560.4705, `position_z`=19.838223, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Guardian Construct
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+235;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+235, @CGUID+235, 0, 0, 515, 0, 0),
(@CGUID+235, @CGUID+237, 3, 90, 515, 2, 8),
(@CGUID+235, @CGUID+246, 3, 270, 515, 2, 8);

SET @MOVERGUID := @CGUID+235;
SET @ENTRY := 104270;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Guardian Construct - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1148.1632, 3399.2058, 26.70579, NULL, 0),
(@PATH, 1, 1137.9185, 3404.79, 22.183548, NULL, 0),
(@PATH, 2, 1128.7448, 3409.4229, 20.403465, NULL, 4573),
(@PATH, 3, 1137.9185, 3404.79, 22.183548, NULL, 0),
(@PATH, 4, 1148.1632, 3399.2058, 26.70579, NULL, 0),
(@PATH, 5, 1156.5781, 3394.802, 29.044132, NULL, 0),
(@PATH, 6, 1165.1979, 3389.3489, 27.230335, NULL, 0),
(@PATH, 7, 1176.5382, 3382.5625, 22.017279, NULL, 0),
(@PATH, 8, 1181.9896, 3378.6519, 20.6413, NULL, 4554),
(@PATH, 9, 1176.5382, 3382.5625, 22.017279, NULL, 0),
(@PATH, 10, 1165.1979, 3389.3489, 27.230335, NULL, 0),
(@PATH, 11, 1156.5781, 3394.802, 29.044132, NULL, 0);

UPDATE `creature` SET `position_x`=1148.1632, `position_y`=3399.2058, `position_z`=26.70579 WHERE `guid` IN (@CGUID+237, @CGUID+246);
UPDATE `creature` SET `position_x`=1148.1632, `position_y`=3399.2058, `position_z`=26.70579, `orientation`=2.611570, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '18950');

-- Path for Guardian Construct
SET @MOVERGUID := @CGUID+61;
SET @ENTRY := 104270;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Guardian Construct - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1157.4185, 3579.7102, 19.83823, NULL, 0),
(@PATH, 1, 1151.8854, 3576.1145, 19.83823, NULL, 0),
(@PATH, 2, 1147.474, 3571.5347, 19.838223, NULL, 0),
(@PATH, 3, 1142.993, 3563.5972, 19.838223, NULL, 0),
(@PATH, 4, 1138.8993, 3557.6519, 19.838223, NULL, 0),
(@PATH, 5, 1134.3195, 3552.039, 19.838223, NULL, 0),
(@PATH, 6, 1129.8368, 3548.8472, 19.841436, NULL, 8503),
(@PATH, 7, 1134.3195, 3552.039, 19.838223, NULL, 0),
(@PATH, 8, 1138.8993, 3557.6519, 19.838223, NULL, 0),
(@PATH, 9, 1142.993, 3563.5972, 19.838223, NULL, 0),
(@PATH, 10, 1147.474, 3571.5347, 19.838223, NULL, 0),
(@PATH, 11, 1151.8854, 3576.1145, 19.83823, NULL, 0),
(@PATH, 12, 1157.4185, 3579.7102, 19.83823, NULL, 0),
(@PATH, 13, 1165.3716, 3582.0737, 19.838217, NULL, 0),
(@PATH, 14, 1169.8507, 3581.89, 19.838215, NULL, 8473);

UPDATE `creature` SET `position_x`=1157.4185, `position_y`=3579.7102, `position_z`=19.83823, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '18950');

-- Path for Duskwatch Guard
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+269;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+269, @CGUID+269, 0, 0, 515, 0, 0),
(@CGUID+269, @CGUID+274, 3, 90, 515, 1, 4),
(@CGUID+269, @CGUID+262, 3, 270, 515, 1, 4);

SET @MOVERGUID := @CGUID+269;
SET @ENTRY := 104246;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Guard - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1203.3317, 3568.632, 21.999928, NULL, 0),
(@PATH, 1, 1195.8334, 3570.1892, 20.403465, NULL, 4337),
(@PATH, 2, 1203.3317, 3568.632, 21.999928, NULL, 0),
(@PATH, 3, 1214.2726, 3566.5251, 26.481989, NULL, 0),
(@PATH, 4, 1225.3368, 3563.8152, 28.997213, NULL, 4358),
(@PATH, 5, 1214.2726, 3566.5251, 26.481989, NULL, 0);

UPDATE `creature` SET `position_x`=1203.3317, `position_y`=3568.632, `position_z`=21.999928, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Duskwatch Arcanist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+44;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+44, @CGUID+44, 0, 0, 515, 0, 0),
(@CGUID+44, @CGUID+46, 3, 90, 515, 4, 9),
(@CGUID+44, @CGUID+45, 3, 270, 515, 4, 9);

SET @MOVERGUID := @CGUID+44;
SET @ENTRY := 104247;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Arcanist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1116.1476, 3580.6926, 32.671223, NULL, 0),
(@PATH, 1, 1119.6997, 3577.6719, 30.487623, NULL, 0),
(@PATH, 2, 1123.4375, 3574.4827, 28.10457, NULL, 0),
(@PATH, 3, 1127.2466, 3572.1328, 25.927095, NULL, 0),
(@PATH, 4, 1130.4323, 3571.1406, 24.360699, NULL, 8554),
(@PATH, 5, 1123.4375, 3574.4827, 28.10457, NULL, 0),
(@PATH, 6, 1119.6997, 3577.6719, 30.487623, NULL, 0),
(@PATH, 7, 1116.1476, 3580.6926, 32.671223, NULL, 0),
(@PATH, 8, 1112.3767, 3584.2014, 35.19587, NULL, 0),
(@PATH, 9, 1108.2517, 3587.5166, 35.665005, NULL, 8502),
(@PATH, 10, 1112.3767, 3584.2014, 35.19587, NULL, 0);

UPDATE `creature` SET `position_x`=1116.1476, `position_y`=3580.6926, `position_z`=32.671223, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Duskwatch Arcanist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+291;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+291, @CGUID+291, 0, 0, 515, 0, 0),
(@CGUID+291, @CGUID+292, 3, 90, 515, 2, 5),
(@CGUID+291, @CGUID+294, 3, 270, 515, 2, 5);

SET @MOVERGUID := @CGUID+291;
SET @ENTRY := 104247;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Arcanist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1265.9791, 3504.6182, 20.794088, NULL, 0),
(@PATH, 1, 1275.3351, 3504.1328, 21.060762, NULL, 0),
(@PATH, 2, 1284.1233, 3505.9253, 20.997215, NULL, 4629),
(@PATH, 3, 1275.3351, 3504.1328, 21.060762, NULL, 0),
(@PATH, 4, 1265.9791, 3504.6182, 20.794088, NULL, 0),
(@PATH, 5, 1256.3455, 3504.5435, 20.794088, NULL, 4646);

UPDATE `creature` SET `position_x`=1265.9791, `position_y`=3504.6182, `position_z`=20.794088, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Dukswatch Arcanist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+332;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+332, @CGUID+332, 0, 0, 515, 0, 0),
(@CGUID+332, @CGUID+334, 3, 90, 515, 2, 8);

SET @MOVERGUID := @CGUID+332;
SET @ENTRY := 104247;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Arcanist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1289.0435, 3601.8186, 20.025875, NULL, 0),
(@PATH, 1, 1291.5312, 3587.4514, 20.025879, NULL, 0),
(@PATH, 2, 1294.7587, 3578.3447, 20.025879, NULL, 8773),
(@PATH, 3, 1291.5312, 3587.4514, 20.025879, NULL, 0),
(@PATH, 4, 1289.0435, 3601.8186, 20.025875, NULL, 0),
(@PATH, 5, 1290.5973, 3617.1528, 20.025873, NULL, 0),
(@PATH, 6, 1303.3317, 3620.1165, 20.025873, NULL, 0),
(@PATH, 7, 1313.3368, 3617.198, 20.025871, NULL, 0),
(@PATH, 8, 1316.066, 3623.08, 20.025873, NULL, 0),
(@PATH, 9, 1303.3317, 3620.1165, 20.025873, NULL, 0),
(@PATH, 10, 1290.5973, 3617.1528, 20.025873, NULL, 0);

UPDATE `creature` SET `position_x`=1289.0435, `position_y`=3601.8186, `position_z`=20.025875, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Duskwatch Arcanist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+337;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+337, @CGUID+337, 0, 0, 515, 0, 0),
(@CGUID+337, @CGUID+338, 3, 270, 515, 6, 0);

SET @MOVERGUID := @CGUID+337;
SET @ENTRY := 104247;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Arcanist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1332.4567, 3577.6736, 21.809761, NULL, 8079),
(@PATH, 1, 1335.7118, 3581.6926, 24.250366, NULL, 0),
(@PATH, 2, 1339.3733, 3586.2466, 26.831863, NULL, 0),
(@PATH, 3, 1342.3716, 3590.179, 29.372635, NULL, 0),
(@PATH, 4, 1345.7448, 3594.5295, 32.057007, NULL, 0),
(@PATH, 5, 1347.8716, 3598.5972, 34.32086, NULL, 0),
(@PATH, 6, 1351.0173, 3603.3994, 35.79409, NULL, 9088),
(@PATH, 7, 1347.8716, 3598.5972, 34.32086, NULL, 0),
(@PATH, 8, 1345.7448, 3594.5295, 32.057007, NULL, 0),
(@PATH, 9, 1342.3716, 3590.179, 29.372635, NULL, 0),
(@PATH, 10, 1339.3733, 3586.2466, 26.831863, NULL, 0),
(@PATH, 11, 1335.7118, 3581.6926, 24.250366, NULL, 0);

UPDATE `creature` SET `position_x`=1332.4567, `position_y`=3577.6736, `position_z`=21.809761 WHERE `guid`= @CGUID+338;
UPDATE `creature` SET `position_x`=1332.4567, `position_y`=3577.6736, `position_z`=21.809761, `orientation`=4.1085, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Duskwatch Arcanist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+333;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+333, @CGUID+333, 0, 0, 515, 0, 0),
(@CGUID+333, @CGUID+335, 3, 90, 515, 3, 7),
(@CGUID+333, @CGUID+331, 3, 270, 515, 3, 7);

SET @MOVERGUID := @CGUID+333;
SET @ENTRY := 104247;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Duskwatch Arcanist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1340.4774, 3520.3464, 20.025948, NULL, 0),
(@PATH, 1, 1333.4774, 3528.9263, 20.200338, NULL, 0),
(@PATH, 2, 1336.4427, 3536.2388, 20.299612, NULL, 0),
(@PATH, 3, 1335.4202, 3544.756, 20.31042, NULL, 8547),
(@PATH, 4, 1336.4427, 3536.2388, 20.299612, NULL, 0),
(@PATH, 5, 1333.4774, 3528.9263, 20.200338, NULL, 0),
(@PATH, 6, 1340.4774, 3520.3464, 20.025948, NULL, 0),
(@PATH, 7, 1337.4427, 3512.3855, 20.025948, NULL, 8763);

UPDATE `creature` SET `position_x`=1340.4774, `position_y`=3520.3464, `position_z`=20.025948, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Patrol Captain Gerdo
SET @MOVERGUID := @CGUID+37;
SET @ENTRY := 104215;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Patrol Captain Gerdo - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1291.507, 3521.2925, 20.02589, NULL, 0),
(@PATH, 1, 1288.5243, 3526.4895, 20.025902, NULL, 0),
(@PATH, 2, 1293.5348, 3536.5894, 20.20034, NULL, 0),
(@PATH, 3, 1296.3455, 3547.7979, 20.20034, NULL, 0),
(@PATH, 4, 1296.6927, 3555.1511, 20.025879, NULL, 0),
(@PATH, 5, 1297.0382, 3562.2578, 20.025879, NULL, 0),
(@PATH, 6, 1300.7882, 3568.4097, 20.025879, NULL, 0),
(@PATH, 7, 1305.0278, 3572.1025, 20.025879, NULL, 0),
(@PATH, 8, 1315.6041, 3571.9106, 20.025879, NULL, 0),
(@PATH, 9, 1321.4062, 3570.804, 20.025879, NULL, 0),
(@PATH, 10, 1326.7344, 3567.6997, 20.025879, NULL, 0),
(@PATH, 11, 1330.3976, 3562.131, 20.025948, NULL, 0),
(@PATH, 12, 1332.0156, 3552.3784, 20.221144, NULL, 0),
(@PATH, 13, 1337.191, 3544.3003, 20.261215, NULL, 0),
(@PATH, 14, 1337.9725, 3537.149, 20.20034, NULL, 0),
(@PATH, 15, 1335.6562, 3529.6294, 20.025948, NULL, 0),
(@PATH, 16, 1330.1476, 3522.1814, 20.20034, NULL, 0),
(@PATH, 17, 1321.5243, 3516.6433, 20.02597, NULL, 0),
(@PATH, 18, 1309.6442, 3516.7422, 20.20034, NULL, 0),
(@PATH, 19, 1301.8473, 3517.934, 20.02595, NULL, 0),
(@PATH, 20, 1296.0469, 3519.9714, 20.025948, NULL, 0);

UPDATE `creature` SET `position_x`=1291.507, `position_y`=3521.2925, `position_z`=20.02589, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 4, '227147 210143 355784');

-- Path for Fancy Noble
SET @MOVERGUID := @CGUID+240;
SET @ENTRY := 107472;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Fancy Noble - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1163.542, 3347.917, 20.00026, NULL, 4134),
(@PATH, 1, 1171.4202, 3356.25, 20.00026, NULL, 0),
(@PATH, 2, 1178.4045, 3362.251, 20.00026, NULL, 0),
(@PATH, 3, 1184.1163, 3367.2527, 20.00026, NULL, 0),
(@PATH, 4, 1191.8021, 3373.494, 20.00026, NULL, 0),
(@PATH, 5, 1195.3541, 3381.5574, 20.00026, NULL, 0),
(@PATH, 6, 1201.967, 3385.2761, 20.00026, NULL, 0),
(@PATH, 7, 1210.2622, 3385.2673, 20.00026, NULL, 0),
(@PATH, 8, 1219.4368, 3382.0247, 20.061054, NULL, 0),
(@PATH, 9, 1227.4098, 3380.5183, 20.13496, NULL, 5181),
(@PATH, 10, 1219.6111, 3381.9653, 20.06441, NULL, 0),
(@PATH, 11, 1210.2622, 3385.2673, 20.00026, NULL, 0),
(@PATH, 12, 1201.967, 3385.2761, 20.00026, NULL, 0),
(@PATH, 13, 1195.3541, 3381.5574, 20.00026, NULL, 0),
(@PATH, 14, 1191.8021, 3373.494, 20.00026, NULL, 0),
(@PATH, 15, 1184.1163, 3367.2527, 20.00026, NULL, 0),
(@PATH, 16, 1178.4045, 3362.251, 20.00026, NULL, 0),
(@PATH, 17, 1171.4202, 3356.25, 20.00026, NULL, 0);

UPDATE `creature` SET `position_x`=1163.542, `position_y`=3347.917, `position_z`=20.00026, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Fancy Noble
SET @MOVERGUID := @CGUID+352;
SET @ENTRY := 107472;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Fancy Noble - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1117.0035, 3234.4307, 37.778275, NULL, 0),
(@PATH, 1, 1117.4098, 3244.2952, 33.238564, NULL, 0),
(@PATH, 2, 1114.6285, 3250.9036, 29.959545, NULL, 0),
(@PATH, 3, 1110.6476, 3257.079, 26.674599, NULL, 0),
(@PATH, 4, 1103.8091, 3264.7588, 24.997213, NULL, 5608),
(@PATH, 5, 1110.5875, 3257.1465, 26.643147, NULL, 0),
(@PATH, 6, 1114.6285, 3250.9036, 29.959545, NULL, 0),
(@PATH, 7, 1117.4098, 3244.2952, 33.238564, NULL, 0),
(@PATH, 8, 1117.0035, 3234.4307, 37.778275, NULL, 0),
(@PATH, 9, 1116.5625, 3225.6707, 41.389088, NULL, 0),
(@PATH, 10, 1113.0192, 3220.9949, 41.828197, NULL, 7993),
(@PATH, 11, 1116.5625, 3225.6702, 41.36741, NULL, 0);

UPDATE `creature` SET `position_x`=1117.0035, `position_y`=3234.4307, `position_z`=37.778275, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Haughty Aristocrat
SET @MOVERGUID := @CGUID+183;
SET @ENTRY := 107470;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Haughty Aristocrat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1115.3959, 3406.816, 19.838223, NULL, 0),
(@PATH, 1, 1117.7812, 3415.7283, 19.838223, NULL, 0),
(@PATH, 2, 1123.8802, 3418.5425, 19.838223, NULL, 0),
(@PATH, 3, 1131.9584, 3426.5764, 19.838223, NULL, 7291),
(@PATH, 4, 1123.8802, 3418.5425, 19.838223, NULL, 0),
(@PATH, 5, 1117.7812, 3415.7283, 19.838223, NULL, 0),
(@PATH, 6, 1115.3959, 3406.816, 19.838223, NULL, 0),
(@PATH, 7, 1116.7969, 3397.7388, 19.838223, NULL, 7283);

UPDATE `creature` SET `position_x`=1115.3959, `position_y`=3406.816, `position_z`=19.838223, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Watchful Inquisitor
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+353;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+353, @CGUID+353, 0, 0, 515, 0, 0),
(@CGUID+353, @CGUID+354, 3, 90, 515, 1, 7),
(@CGUID+353, @CGUID+357, 3, 270, 515, 1, 7);

SET @MOVERGUID := @CGUID+353;
SET @ENTRY := 105715;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Watchful Inquisitor - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1169.7795, 3239.1753, 20.00026, NULL, 0),
(@PATH, 1, 1176.974, 3240.3862, 20.00026, NULL, 4228),
(@PATH, 2, 1169.7795, 3239.1753, 20.00026, NULL, 0),
(@PATH, 3, 1168.2812, 3246.395, 20.00026, NULL, 0),
(@PATH, 4, 1164.0573, 3254.6155, 20.00026, NULL, 0),
(@PATH, 5, 1156.3142, 3261.9817, 20.00026, NULL, 0),
(@PATH, 6, 1149.6163, 3266.007, 20.00026, NULL, 0),
(@PATH, 7, 1147.0017, 3273.4236, 20.00026, NULL, 4203),
(@PATH, 8, 1149.6163, 3266.007, 20.00026, NULL, 0),
(@PATH, 9, 1156.3142, 3261.9817, 20.00026, NULL, 0),
(@PATH, 10, 1164.0573, 3254.6155, 20.00026, NULL, 0),
(@PATH, 11, 1168.2812, 3246.395, 20.00026, NULL, 0);

UPDATE `creature` SET `position_x`=1169.7795, `position_y`=3239.1753, `position_z`=20.00026, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Watchful Inquisitor
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+133;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+133, @CGUID+133, 0, 0, 515, 0, 0),
(@CGUID+133, @CGUID+135, 3, 270, 515, 1, 10);

SET @MOVERGUID := @CGUID+133;
SET @ENTRY := 105715;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Watchful Inquisitor - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1056.7673, 3401.2588, 19.838223, NULL, 0),
(@PATH, 1, 1048.7448, 3392.4392, 19.842218, NULL, 4683),
(@PATH, 2, 1056.7673, 3401.2588, 19.838223, NULL, 0),
(@PATH, 3, 1068.4791, 3406.7751, 19.838223, NULL, 0),
(@PATH, 4, 1079.0192, 3411.6077, 19.838223, NULL, 0),
(@PATH, 5, 1088.3298, 3410.6172, 19.83822, NULL, 0),
(@PATH, 6, 1097.9531, 3401.2744, 19.838223, NULL, 0),
(@PATH, 7, 1101.8385, 3392.5947, 19.838223, NULL, 0),
(@PATH, 8, 1100.6754, 3385.0608, 20.857374, NULL, 0),
(@PATH, 9, 1094.8177, 3377.6355, 21.81226, NULL, 0),
(@PATH, 10, 1089.9688, 3370.7422, 22.975187, NULL, 4677),
(@PATH, 11, 1094.8177, 3377.6355, 21.81226, NULL, 0),
(@PATH, 12, 1100.6754, 3385.0608, 20.857374, NULL, 0),
(@PATH, 13, 1101.8385, 3392.5947, 19.838223, NULL, 0),
(@PATH, 14, 1097.9531, 3401.2744, 19.838223, NULL, 0),
(@PATH, 15, 1088.3298, 3410.6172, 19.83822, NULL, 0),
(@PATH, 16, 1079.0192, 3411.6077, 19.838223, NULL, 0),
(@PATH, 17, 1068.4791, 3406.7751, 19.838223, NULL, 0);

UPDATE `creature` SET `position_x`=1056.7673, `position_y`=3401.2588, `position_z`=19.838223, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Watchful Inquisitor
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+214;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+214, @CGUID+214, 0, 0, 515, 0, 0),
(@CGUID+214, @CGUID+211, 3, 90, 515, 2, 10),
(@CGUID+214, @CGUID+217, 3, 270, 515, 2, 10);

SET @MOVERGUID := @CGUID+214;
SET @ENTRY := 105715;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Watchful Inquisitor - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1080.3993, 3335.105, 24.991903, NULL, 0),
(@PATH, 1, 1061.9497, 3334.572, 25.019867, NULL, 0),
(@PATH, 2, 1045.4236, 3334.0938, 25.019867, NULL, 0),
(@PATH, 3, 1061.2639, 3335.659, 25.050657, NULL, 0),
(@PATH, 4, 1077.3889, 3335.3801, 24.974337, NULL, 0),
(@PATH, 5, 1090.7448, 3329.093, 24.997215, NULL, 0),
(@PATH, 6, 1099.1702, 3320.5269, 25.004446, NULL, 0),
(@PATH, 7, 1105.5817, 3311.861, 25.059704, NULL, 0),
(@PATH, 8, 1107.231, 3298.1926, 24.997217, NULL, 0),
(@PATH, 9, 1108.1649, 3287.3958, 24.997215, NULL, 0),
(@PATH, 10, 1106.1476, 3274.612, 24.909708, NULL, 5242),
(@PATH, 11, 1108.1649, 3287.3958, 24.997215, NULL, 0),
(@PATH, 12, 1107.231, 3298.1926, 24.997217, NULL, 0),
(@PATH, 13, 1105.5817, 3311.861, 25.059704, NULL, 0),
(@PATH, 14, 1099.1702, 3320.5269, 25.004446, NULL, 0),
(@PATH, 15, 1090.7448, 3329.093, 24.997215, NULL, 0);

UPDATE `creature` SET `position_x`=1080.3993, `position_y`=3335.105, `position_z`=24.991903, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Felbound Enforcer
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+356;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+356, @CGUID+356, 0, 0, 515, 0, 0),
(@CGUID+356, @CGUID+367, 8, 210, 515, 3, 10),
(@CGUID+356, @CGUID+371, 8, 130, 515, 3, 10),
(@CGUID+356, @CGUID+355, 8, 310, 515, 3, 10),
(@CGUID+356, @CGUID+370, 8, 60, 515, 3, 10),
(@CGUID+356, @CGUID+365, 8, 0, 515, 3, 10);

SET @MOVERGUID := @CGUID+356;
SET @ENTRY := 104278;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Felbound Enforcer - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1170.3663, 3235.665, 20.00026, NULL, 0),
(@PATH, 1, 1160.3785, 3228.2952, 20.00026, NULL, 0),
(@PATH, 2, 1145.4983, 3221.6892, 20.00026, NULL, 0),
(@PATH, 3, 1145.1844, 3214.0205, 20.403465, NULL, 8206),
(@PATH, 4, 1145.4983, 3221.6892, 20.00026, NULL, 0),
(@PATH, 5, 1160.3785, 3228.2952, 20.00026, NULL, 0),
(@PATH, 6, 1170.3663, 3235.665, 20.00026, NULL, 0),
(@PATH, 7, 1167.8646, 3249.808, 20.00026, NULL, 0),
(@PATH, 8, 1159.6562, 3261.058, 20.00026, NULL, 0),
(@PATH, 9, 1161.0973, 3270.6094, 20.00026, NULL, 0),
(@PATH, 10, 1165.7291, 3279.7327, 20.00026, NULL, 9190),
(@PATH, 11, 1161.0973, 3270.6094, 20.00026, NULL, 0),
(@PATH, 12, 1159.6562, 3261.058, 20.00026, NULL, 0),
(@PATH, 13, 1167.8646, 3249.808, 20.00026, NULL, 0);

UPDATE `creature` SET `position_x`=1170.3663, `position_y`=3235.665, `position_z`=20.00026, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Blazing Imp
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+151;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+151, @CGUID+151, 0, 0, 515, 0, 0),
(@CGUID+151, @CGUID+143, 4, 0, 515, 0, 0),
(@CGUID+151, @CGUID+141, 4, 20, 515, 0, 0),
(@CGUID+151, @CGUID+145, 4, 40, 515, 0, 0),
(@CGUID+151, @CGUID+150, 4, 60, 515, 0, 0),
(@CGUID+151, @CGUID+144, 4, 340, 515, 0, 0),
(@CGUID+151, @CGUID+147, 4, 320, 515, 0, 0),
(@CGUID+151, @CGUID+148, 4, 300, 515, 0, 0);

SET @MOVERGUID := @CGUID+151;
SET @ENTRY := 104295;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Blazing Imp - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1067.0695, 3408.1685, 19.838223, NULL, 0),
(@PATH, 1, 1085.5452, 3416.6328, 19.83822, NULL, 0),
(@PATH, 2, 1099.0209, 3421.5513, 19.83822, NULL, 0),
(@PATH, 3, 1111.6267, 3417.462, 19.838223, NULL, 0),
(@PATH, 4, 1109.5903, 3398.6946, 19.838223, NULL, 0),
(@PATH, 5, 1107.1267, 3387.8247, 20.30516, NULL, 0),
(@PATH, 6, 1099.092, 3377.079, 21.567942, NULL, 0),
(@PATH, 7, 1087.757, 3364.1858, 23.870749, NULL, 0),
(@PATH, 8, 1080.7986, 3347.882, 24.619238, NULL, 0),
(@PATH, 9, 1070.4774, 3345.6519, 24.997215, NULL, 0),
(@PATH, 10, 1056.2916, 3353.3958, 21.983883, NULL, 0),
(@PATH, 11, 1049.8334, 3363.5356, 19.838223, NULL, 0),
(@PATH, 12, 1053.4132, 3374.3723, 19.838223, NULL, 0),
(@PATH, 13, 1053.8073, 3395.5286, 19.838226, NULL, 0);

UPDATE `creature` SET `position_x`=1067.0695, `position_y`=3408.1685, `position_z`=19.838223, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Blazing Imp
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+245;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+245, @CGUID+245, 0, 0, 515, 0, 0),
(@CGUID+245, @CGUID+238, 4, 0, 515, 0, 0),
(@CGUID+245, @CGUID+236, 4, 20, 515, 0, 0),
(@CGUID+245, @CGUID+243, 4, 40, 515, 0, 0),
(@CGUID+245, @CGUID+241, 4, 60, 515, 0, 0),
(@CGUID+245, @CGUID+239, 4, 340, 515, 0, 0),
(@CGUID+245, @CGUID+242, 4, 320, 515, 0, 0),
(@CGUID+245, @CGUID+244, 4, 300, 515, 0, 0);

SET @MOVERGUID := @CGUID+245;
SET @ENTRY := 104295;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Blazing Imp - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1161.9785, 3329.6875, 20.00026, NULL, 0),
(@PATH, 1, 1165.408, 3341.0234, 20.000261, NULL, 0),
(@PATH, 2, 1179.6805, 3353.5051, 20.00026, NULL, 0),
(@PATH, 3, 1197.4062, 3346.2864, 20.145628, NULL, 0),
(@PATH, 4, 1203.5192, 3339.2473, 20.20034, NULL, 0),
(@PATH, 5, 1223.1094, 3322.394, 20.20034, NULL, 0),
(@PATH, 6, 1235.0851, 3315.5781, 20.20034, NULL, 0),
(@PATH, 7, 1233.467, 3305.9783, 20.00026, NULL, 0),
(@PATH, 8, 1221.0729, 3290.515, 20.00026, NULL, 0),
(@PATH, 9, 1202.5122, 3276.9055, 20.00026, NULL, 0),
(@PATH, 10, 1192.0868, 3289.1233, 20.00026, NULL, 0),
(@PATH, 11, 1180.2379, 3288.2004, 20.00026, NULL, 0),
(@PATH, 12, 1170.724, 3282.1736, 20.00026, NULL, 0),
(@PATH, 13, 1155.757, 3274.119, 20.00026, NULL, 0),
(@PATH, 14, 1136.9149, 3274.5686, 20.00026, NULL, 0),
(@PATH, 15, 1128.7865, 3282.4192, 22.948824, NULL, 0),
(@PATH, 16, 1122.8073, 3295.2847, 24.997217, NULL, 0),
(@PATH, 17, 1131.6372, 3306.5564, 24.239536, NULL, 0),
(@PATH, 18, 1150.1632, 3318.0625, 22.218328, NULL, 0);

UPDATE `creature` SET `position_x`=1161.9785, `position_y`=3329.6875, `position_z`=20.00026, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Automated Sweeper
SET @MOVERGUID := @CGUID+350;
SET @ENTRY := 108419;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Automated Sweeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1235.0416, 3435.2014, 55.606583, NULL, 0),
(@PATH, 1, 1236.5504, 3433.1233, 55.606586, NULL, 0),
(@PATH, 2, 1235.0416, 3435.2014, 55.606583, NULL, 0),
(@PATH, 3, 1229.7448, 3436.9219, 52.36971, NULL, 0);

UPDATE `creature` SET `position_x`=1235.0416, `position_y`=3435.2014, `position_z`=55.606583, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '215252');
