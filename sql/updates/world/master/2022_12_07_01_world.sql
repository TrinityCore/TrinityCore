SET @CGUID := 396526;
SET @OGUID := 249071;
SET @EVENT := 26;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32823, 1, 148, 4659, '0', 0, 0, 0, 0, 7418.27978515625, -252.77099609375, 7.754663467407226562, 0, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741), -- Bountiful Table (Area: Lor'danel - Difficulty: 0)
(@CGUID+1, 34653, 1, 148, 4659, '0', 0, 0, 0, 0, 7414.68994140625, -258.6820068359375, 7.745133399963378906, 4.15388345718383789, 120, 0, 0, 19343, 0, 0, 0, 0, 0, 46741); -- Bountiful Table Hostess (Area: Lor'danel - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 179968, 1, 148, 4659, '0', 0, 0, 7415.02978515625, -248.912994384765625, 7.664770126342773437, 2.076939344406127929, 0, 0, 0.861628532409667968, 0.50753939151763916, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+1, 179968, 1, 148, 4659, '0', 0, 0, 7422.0400390625, -247.716995239257812, 7.658820152282714843, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+2, 179968, 1, 148, 4659, '0', 0, 0, 7424.5, -251.968994140625, 7.652239799499511718, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+3, 179968, 1, 148, 4659, '0', 0, 0, 7420.509765625, -247.313003540039062, 7.663909912109375, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+4, 179968, 1, 148, 4659, '0', 0, 0, 7424.33984375, -253.531005859375, 7.652919769287109375, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+5, 179968, 1, 148, 4659, '0', 0, 0, 7415.64013671875, -256.634002685546875, 7.665150165557861328, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+6, 179968, 1, 148, 4659, '0', 0, 0, 7421.68017578125, -257.82598876953125, 7.661129951477050781, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+7, 179968, 1, 148, 4659, '0', 0, 0, 7414.58984375, -255.134994506835937, 7.662459850311279296, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+8, 179968, 1, 148, 4659, '0', 0, 0, 7420.02978515625, -258.31298828125, 7.666049957275390625, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+9, 179968, 1, 148, 4659, '0', 0, 0, 7413.9501953125, -250.2550048828125, 7.661439895629882812, 6.09120035171508789, 0, 0, -0.09584522247314453, 0.995396256446838378, 120, 255, 1, 46741), -- Haystack 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+10, 180353, 1, 148, 4659, '0', 0, 0, 7421.2998046875, -247.462005615234375, 7.661300182342529296, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+11, 180353, 1, 148, 4659, '0', 0, 0, 7424.490234375, -252.753005981445312, 7.652450084686279296, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+12, 180353, 1, 148, 4659, '0', 0, 0, 7414.97021484375, -256.058990478515625, 7.663310050964355468, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+13, 180353, 1, 148, 4659, '0', 0, 0, 7414.27001953125, -249.417999267578125, 7.662479877471923828, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+14, 180353, 1, 148, 4659, '0', 0, 0, 7420.8701171875, -258.191009521484375, 7.663509845733642578, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Freestanding Torch 01 (Area: Lor'danel - Difficulty: 0)
(@OGUID+15, 195164, 1, 148, 4659, '0', 0, 0, 7421.97998046875, -247.701004028320312, 8.309029579162597656, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+16, 195164, 1, 148, 4659, '0', 0, 0, 7421.81005859375, -257.7080078125, 8.310740470886230468, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+17, 195164, 1, 148, 4659, '0', 0, 0, 7420.47021484375, -247.406005859375, 8.3139495849609375, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+18, 195164, 1, 148, 4659, '0', 0, 0, 7419.990234375, -258.243011474609375, 8.316220283508300781, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+19, 195164, 1, 148, 4659, '0', 0, 0, 7414.64013671875, -255.089996337890625, 8.312640190124511718, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+20, 195164, 1, 148, 4659, '0', 0, 0, 7415.56982421875, -256.563995361328125, 8.314990043640136718, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+21, 195164, 1, 148, 4659, '0', 0, 0, 7424.41015625, -251.996994018554687, 8.302559852600097656, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+22, 195164, 1, 148, 4659, '0', 0, 0, 7415, -248.957992553710937, 8.314729690551757812, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+23, 195164, 1, 148, 4659, '0', 0, 0, 7414.0400390625, -250.300003051757812, 8.31175994873046875, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+24, 195164, 1, 148, 4659, '0', 0, 0, 7424.2001953125, -253.673995971679687, 8.303370475769042968, 0, 0, 0, 0, 1, 120, 255, 1, 46741), -- Pumpkin (Area: Lor'danel - Difficulty: 0)
(@OGUID+25, 195664, 1, 148, 4659, '0', 0, 0, 7418.27978515625, -252.77099609375, 7.671339988708496093, 0, 0, 0, 0, 1, 120, 255, 1, 46741); -- [DND] Collision Thanksgiving Table Size (Area: Lor'danel - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0), 
(@EVENT, @CGUID+1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID+0 AND @OGUID+25;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(@EVENT, @OGUID+0),
(@EVENT, @OGUID+1),
(@EVENT, @OGUID+2),
(@EVENT, @OGUID+3),
(@EVENT, @OGUID+4),
(@EVENT, @OGUID+5),
(@EVENT, @OGUID+6),
(@EVENT, @OGUID+7),
(@EVENT, @OGUID+8),
(@EVENT, @OGUID+9),
(@EVENT, @OGUID+10),
(@EVENT, @OGUID+11),
(@EVENT, @OGUID+12),
(@EVENT, @OGUID+13),
(@EVENT, @OGUID+14),
(@EVENT, @OGUID+15),
(@EVENT, @OGUID+16),
(@EVENT, @OGUID+17),
(@EVENT, @OGUID+18),
(@EVENT, @OGUID+19),
(@EVENT, @OGUID+20),
(@EVENT, @OGUID+21),
(@EVENT, @OGUID+22),
(@EVENT, @OGUID+23),
(@EVENT, @OGUID+24),
(@EVENT, @OGUID+25);
