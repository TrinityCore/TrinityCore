SET @CGUID := 8000828;
SET @OGUID := 8000104;
SET @WORLD_SAFE_LOC_ID := 100099;
SET @SPAWN_GROUP := 1272;

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WORLD_SAFE_LOC_ID + 0 AND @WORLD_SAFE_LOC_ID + 1;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WORLD_SAFE_LOC_ID+0, 2509, 2856.63, 2329.15, 3259.74, DEGREES(4.4575706), 'Maldraxxus Coliseum - Purple Team'),
(@WORLD_SAFE_LOC_ID+1, 2509, 2854.23, 2182.54, 3259.96, DEGREES(1.860521), 'Maldraxxus Coliseum - Gold Team');

DELETE FROM `battleground_scripts` WHERE `MapId` = 2509 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(2509, 0, 'arena_maldraxxus_coliseum'); -- Maldraxxus Coliseum

DELETE FROM `battleground_template` WHERE `ID` = 1066;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(1066, @WORLD_SAFE_LOC_ID+0, @WORLD_SAFE_LOC_ID+1, 0, 1, 'Maldraxxus Coliseum');

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (358872 /*Anima Reservoir*/, 364865 /*Spike Door*/, 364864 /*Spire Door*/, 358871 /*Anima Reservoir*/, 353391 /*Cell Door*/, 353390 /*Cell Door*/, 353389 /*Cell Door*/, 352110 /*Tower Door*/, 353633 /*Sanctum Door*/, 364863 /*Tower Door*/, 353392 /*Cell Door*/, 357089 /*9NC_Necro_Covenant_PrimusArmorStand04*/, 375890 /*Maldraxxus Coliseum - Door*/, 355424 /*Door*/, 358873 /*Anima Reservoir*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(358872, 0, 0x2000, 0, 0), -- Anima Reservoir
(364865, 0, 0x20, 0, 0), -- Spike Door
(364864, 0, 0x20, 0, 0), -- Spire Door
(358871, 0, 0x2000, 0, 0), -- Anima Reservoir
(353391, 0, 0x20, 0, 0), -- Cell Door
(353390, 0, 0x20, 0, 0), -- Cell Door
(353389, 0, 0x20, 0, 0), -- Cell Door
(352110, 0, 0x20, 0, 0), -- Tower Door
(353633, 0, 0x30, 0, 0), -- Sanctum Door
(364863, 0, 0x20, 0, 0), -- Tower Door
(353392, 0, 0x20, 0, 0), -- Cell Door
(357089, 0, 0x20, 0, 0), -- 9NC_Necro_Covenant_PrimusArmorStand04
(375890, 114, 0x1, 0, 0), -- Maldraxxus Coliseum - Door
(355424, 0, 0x30, 0, 0), -- Door
(358873, 0, 0x2000, 0, 0); -- Anima Reservoir

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+28;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 358873, 2509, 13972, 13972, '0', '0', 0, 1835.9671630859375, 2231.16552734375, 3389.037841796875, 5.751413822174072265, 0, 0, -0.26276397705078125, 0.964860141277313232, 7200, 255, 1, 63305), -- Anima Reservoir (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+1, 355424, 2509, 13972, 13972, '0', '0', 0, 1029.6214599609375, 1130.5401611328125, 3066.897705078125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 63305), -- Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+2, 375890, 2509, 13972, 13972, '0', '0', 0, 2849.8759765625, 2199.532958984375, 3260.152099609375, 4.976324081420898437, 0, 0, -0.60791397094726562, 0.794002890586853027, 7200, 255, 1, 63305), -- Maldraxxus Coliseum - Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+3, 357089, 2509, 13972, 13972, '0', '0', 0, 1724.50537109375, 2252.2763671875, 3386.95947265625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- 9NC_Necro_Covenant_PrimusArmorStand04 (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+4, 353392, 2509, 13972, 13972, '0', '0', 0, 1604.9605712890625, 2940.898681640625, 3414.51123046875, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 7200, 255, 1, 63305), -- Cell Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+5, 364863, 2509, 13972, 13972, '0', '0', 0, 3794.086669921875, 3672.78125, 3192.216796875, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 63305), -- Tower Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+6, 375890, 2509, 13972, 13972, '0', '0', 0, 2850.56591796875, 2307.1875, 3259.84326171875, 1.274271011352539062, 0, 0, 0.594895362854003906, 0.803803145885467529, 7200, 255, 1, 63305), -- Maldraxxus Coliseum - Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+7, 353633, 2509, 13972, 13972, '0', '0', 0, 1056.7315673828125, 1111.6566162109375, 3078.095458984375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 63305), -- Sanctum Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+8, 352110, 2509, 13972, 13972, '0', '0', 0, 3799.587158203125, 2760.26416015625, 3291.91357421875, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 7200, 255, 1, 63305), -- Tower Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+9, 353389, 2509, 13972, 13972, '0', '0', 0, 1521.06640625, 2985.52587890625, 3414.6806640625, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 7200, 255, 1, 63305), -- Cell Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+10, 353390, 2509, 13972, 13972, '0', '0', 0, 1534.571044921875, 2978.62841796875, 3414.485595703125, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 7200, 255, 1, 63305), -- Cell Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+11, 353391, 2509, 13972, 13972, '0', '0', 0, 1610.3929443359375, 2919.251953125, 3414.51123046875, 1.064649581909179687, 0, 0, 0.507537841796875, 0.861629426479339599, 7200, 255, 1, 63305), -- Cell Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+12, 365674, 2509, 13972, 13972, '0', '0', 0, 1901.07421875, 2317.32958984375, 3398.3408203125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- Runeforge (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+13, 358871, 2509, 13972, 13972, '0', '0', 0, 1833.8687744140625, 2227.190673828125, 3390.80419921875, 2.240999937057495117, 0, 0, 0.900318145751953125, 0.435232430696487426, 7200, 255, 1, 63305), -- Anima Reservoir (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+14, 357961, 2509, 13972, 13972, '0', '0', 0, 3153.01806640625, 2657.427978515625, 3270.885986328125, 3.700104713439941406, 0, 0, -0.96126079559326171, 0.275640487670898437, 7200, 255, 1, 63305), -- Forge (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+15, 357962, 2509, 13972, 13972, '0', '0', 0, 3152.65869140625, 2648.534423828125, 3270.934326171875, 1.422442793846130371, 0, 0, 0.652759552001953125, 0.757565200328826904, 7200, 255, 1, 63305), -- Anvil (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+16, 364864, 2509, 13972, 13972, '0', '0', 0, 1433.345703125, 3309.82470703125, 3474.117919921875, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 7200, 255, 1, 63305), -- Spire Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+17, 364865, 2509, 13972, 13972, '0', '0', 0, 2422.298828125, 1226.5006103515625, 3313.175048828125, 3.143882274627685546, 0, 0.02617645263671875, -0.99965667724609375, 0.001145121059380471, 7200, 255, 1, 63305), -- Spike Door (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+18, 358872, 2509, 13972, 13972, '0', '0', 0, 1829.6005859375, 2225.300537109375, 3389.037841796875, 1.692405223846435546, 0, 0, 0.748768806457519531, 0.662831246852874755, 7200, 255, 1, 63305), -- Anima Reservoir (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+19, 355451, 2509, 13972, 13972, '0', '0', 0, 1876.8681640625, 2261.7119140625, 3388.03857421875, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 7200, 255, 1, 63305), -- Mailbox (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+20, 365672, 2509, 13972, 13972, '0', '0', 0, 1863.0126953125, 2302.8603515625, 3394.88671875, 3.010666131973266601, 0, 0, 0.997858047485351562, 0.065416477620601654, 7200, 255, 1, 63305), -- Forge (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+21, 365673, 2509, 13972, 13972, '0', '0', 0, 1860.6962890625, 2304.6025390625, 3395.022216796875, 2.521998405456542968, 0, 0, 0.952395439147949218, 0.304865479469299316, 7200, 255, 1, 63305), -- Anvil (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+22, 355452, 2509, 13972, 13972, '0', '0', 0, 1862.0068359375, 2279.3017578125, 3388.03857421875, 5.593780994415283203, 0, 0, -0.33791637420654296, 0.941176116466522216, 7200, 255, 1, 63305), -- Cauldron (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+23, 358875, 2509, 13972, 13972, '0', '0', 0, 1837.387939453125, 2232.581787109375, 3387.25927734375, 2.055546998977661132, 0, 0, 0.856150627136230468, 0.516726315021514892, 7200, 255, 1, 63305), -- Anima Crystal (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+24, 358874, 2509, 13972, 13972, '0', '0', 0, 1826.52099609375, 2225.56591796875, 3387.630126953125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- Anima Crystal (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+25, 358876, 2509, 13972, 13972, '0', '0', 0, 1824.5372314453125, 2224.138427734375, 3388.286376953125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 63305), -- Anima Crystal (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+26, 358877, 2509, 13972, 13972, '0', '0', 0, 1824.9727783203125, 2226.773193359375, 3386.77294921875, 1.099337220191955566, 0, 0, 0.522404670715332031, 0.852697670459747314, 7200, 255, 1, 63305), -- Anima Crystal (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@OGUID+27, 184663, 2509, 13972, 13972, '0', '0', 0, 2786.130126953125, 2253.369873046875, 3260.39990234375, 3.040358543395996093, 0, 0, 0.998719215393066406, 0.050595458596944808, 7200, 255, 1, 63305), -- Shadow Sight (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject2
(@OGUID+28, 184663, 2509, 13972, 13972, '0', '0', 0, 2881.690185546875, 2253.890625, 3260.489990234375, 1.710418701171875, 0, 0, 0.754708290100097656, 0.656060516834259033, 7200, 255, 1, 63305); -- Shadow Sight (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+28;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Anima Reservoir
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- 9NC_Necro_Covenant_PrimusArmorStand04
(@OGUID+4, 0, 0, -0.24192185699939727, 0.970295727252960205, 0, 0), -- Cell Door
(@OGUID+5, 0, 0, 0.382683455944061279, 0.923879563808441162, 0, 0), -- Tower Door
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 0), -- Sanctum Door
(@OGUID+8, 0, 0, 0.190808489918708801, 0.981627285480499267, 0, 0), -- Tower Door
(@OGUID+9, 0, 0, -0.24192185699939727, 0.970295727252960205, 0, 0), -- Cell Door
(@OGUID+10, 0, 0, -0.24192185699939727, 0.970295727252960205, 0, 0), -- Cell Door
(@OGUID+11, 0, 0, -0.24192185699939727, 0.970295727252960205, 0, 0), -- Cell Door
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 0, 0), -- Runeforge
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- Anima Reservoir
(@OGUID+14, 0, 0, 0.275637507438659667, 0.961261689662933349, 0, 0), -- Forge
(@OGUID+15, 0, 0, 0.275637507438659667, 0.961261689662933349, 0, 0), -- Anvil
(@OGUID+16, 0, 0, 0.984807789325714111, 0.17364811897277832, 0, 0), -- Spire Door
(@OGUID+17, 0.000000001144233374, -0.02617700770497322, 0.999657332897186279, -0.00000004369640649, 0, 0), -- Spike Door
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Anima Reservoir
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0), -- Mailbox
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Forge
(@OGUID+21, 0, 0, 1, -0.00000004371138828, 0, 0), -- Anvil
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 0), -- Cauldron
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 0), -- Anima Crystal
(@OGUID+24, 0, 0, 1, -0.00000004371138828, 0, 0), -- Anima Crystal
(@OGUID+25, 0, 0, 1, -0.00000004371138828, 0, 0), -- Anima Crystal
(@OGUID+26, 0, 0, 1, -0.00000004371138828, 0, 0); -- Anima Crystal

UPDATE `creature_template` SET `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x8001 WHERE `entry`=185764; -- Maldraxxian Gladiator
UPDATE `creature_template` SET `faction`=3171, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800 WHERE `entry`=185765; -- Arena Prospect
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000040, `unit_flags2`=0x4000800, `unit_flags3`=0x8001 WHERE `entry`=185763; -- Maldraxxian Honor Guard
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x1000000 WHERE `entry`=185659; -- Guard

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+40;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 185764, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2844.864501953125, 2303.0244140625, 3260.145751953125, 1.222661018371582031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Maldraxxian Gladiator (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+1, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2980.21435546875, 2327.197998046875, 3325.080322265625, 3.528119087219238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+2, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2949.127685546875, 2136.689208984375, 3325.735107421875, 2.204537630081176757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+3, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2778.190185546875, 2418.1875, 3327.48583984375, 5.271474838256835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+4, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2765.09375, 2259.40625, 3260.34765625, 6.067912578582763671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+5, 185763, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2859.92626953125, 2159.255126953125, 3260.470703125, 1.864421486854553222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Maldraxxian Honor Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+6, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2820.4619140625, 2092.319580078125, 3324.997802734375, 2.026699781417846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+7, 185764, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2853.896728515625, 2300.286376953125, 3260.112548828125, 1.631254911422729492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Maldraxxian Gladiator (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+8, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2950.63623046875, 2368.473876953125, 3325.936767578125, 4.388659000396728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+9, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2919.843017578125, 2127.63720703125, 3326.36572265625, 2.026699781417846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+10, 166568, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2645.6484375, 2253.796875, 3305.206298828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Hellinka (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+11, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2972.132080078125, 2353.76904296875, 3327.41015625, 4.038762569427490234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+12, 185763, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2865.01123046875, 2161.02783203125, 3260.455810546875, 1.911551356315612792, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Maldraxxian Honor Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+13, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2746.282958984375, 2389.32470703125, 3324.740966796875, 5.535057544708251953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+14, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2955.510498046875, 2254.17529296875, 3273.11962890625, 2.973686695098876953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+15, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2759.442626953125, 2095.82470703125, 3325.92236328125, 1.012931227684020996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+16, 185764, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2853.069580078125, 2207.116455078125, 3260.44677734375, 5.022103309631347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Maldraxxian Gladiator (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+17, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2981.626708984375, 2209.78125, 3324.50390625, 2.95849919319152832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+18, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2833.592041015625, 2096.46533203125, 3325.74072265625, 2.026699781417846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+19, 163041, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2832.405517578125, 2408.53466796875, 3324.990966796875, 4.695466041564941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+20, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2730.55908203125, 2180.513916015625, 3273.12060546875, 0.573603332042694091, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+21, 185763, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2865.243896484375, 2347.835205078125, 3260.531005859375, 4.423168659210205078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Maldraxxian Honor Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+22, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2981.583251953125, 2182.548583984375, 3324.583740234375, 2.95849919319152832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+23, 185764, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2843.692626953125, 2204.4775390625, 3260.367919921875, 5.16705179214477539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Maldraxxian Gladiator (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+24, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2805.757080078125, 2087.572998046875, 3325.739990234375, 2.026699781417846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+25, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2807.591064453125, 2415.717041015625, 3325.822509765625, 4.695466041564941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+26, 185763, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2860.25341796875, 2349.276123046875, 3260.49609375, 4.473968982696533203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Maldraxxian Honor Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+27, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2973.21875, 2153.032958984375, 3327.529052734375, 2.51962900161743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+28, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2755.7431640625, 2403.335205078125, 3325.030029296875, 5.536399364471435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+29, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2673.8056640625, 2279.963623046875, 3326.58251953125, 0.19043731689453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+30, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2975.866455078125, 2307.161376953125, 3329.46337890625, 3.528119087219238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+31, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2752.91064453125, 2106.0712890625, 3325.53466796875, 0.892840743064880371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+32, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2921.960205078125, 2378.98779296875, 3325.133056640625, 4.388659000396728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+33, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2730.6650390625, 2327.583251953125, 3273.122802734375, 5.533953666687011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+34, 110854, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2650.5703125, 2248.2431640625, 3305.274169921875, 0.434818565845489501, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Jared V. Hellstrike (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+35, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2683.346435546875, 2306.178955078125, 3324.8291015625, 5.737512111663818359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+36, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2980.94189453125, 2170.44970703125, 3325.765869140625, 2.95849919319152832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+37, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2777.158935546875, 2086.420166015625, 3327.418212890625, 1.262829422950744628, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+38, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2681.18310546875, 2200.842041015625, 3324.626220703125, 0.745742619037628173, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+39, 185659, 2509, 13972, 13972, '0', '0', 0, 0, 0, 2765.09375, 2251.748291015625, 3260.34765625, 0.461662709712982177, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Guard (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1
(@CGUID+40, 185765, 2509, 13972, 13972, '0', '0', 0, 0, 1, 2935.385498046875, 2375.986083984375, 3323.709716796875, 4.388659000396728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Arena Prospect (Area: Maldraxxus Coliseum - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+40;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Maldraxxian Gladiator
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Maldraxxian Gladiator
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Maldraxxian Gladiator
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 716, 0, 0, 0, 0, ''), -- Maldraxxian Gladiator
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Jared V. Hellstrike

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=163041 AND `DifficultyID`=0); -- 163041 (Arena Prospect) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=347, `VerifiedBuild`=63305 WHERE (`Entry`=110854 AND `DifficultyID`=0); -- 110854 (Jared V. Hellstrike)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=166568 AND `DifficultyID`=0); -- 166568 (Hellinka) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=969, `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=185659 AND `DifficultyID`=0); -- 185659 (Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=837, `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=185764 AND `DifficultyID`=0); -- 185764 (Maldraxxian Gladiator) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=837, `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=185765 AND `DifficultyID`=0); -- 185765 (Arena Prospect) - CanSwim

UPDATE `creature` SET `StringId` = 'arena_maldraxxus_coliseum_2' WHERE `guid` = @CGUID+0;
UPDATE `creature` SET `StringId` = 'arena_maldraxxus_coliseum_1' WHERE `guid` = @CGUID+7;
UPDATE `creature` SET `StringId` = 'arena_maldraxxus_coliseum_3' WHERE `guid` = @CGUID+16;
UPDATE `creature` SET `StringId` = 'arena_maldraxxus_coliseum_4' WHERE `guid` = @CGUID+23;

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (185763,185765,185764));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(185763, 1, 177264, 0, 0, 176718, 0, 0, 0, 0, 0, 63305), -- Maldraxxian Honor Guard
(185765, 1, 106203, 0, 0, 0, 0, 0, 155772, 0, 0, 63305), -- Arena Prospect
(185764, 1, 177260, 0, 0, 176716, 0, 0, 0, 0, 0, 63305); -- Maldraxxian Gladiator

DELETE FROM `spawn_group_template` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP, 'Maldraxxus Coliseum - Shadow sight', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` = @SPAWN_GROUP;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+27),
(@SPAWN_GROUP, 1, @OGUID+28);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` = @SPAWN_GROUP;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');
