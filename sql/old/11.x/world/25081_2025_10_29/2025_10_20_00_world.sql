SET @CGUID := 7003715;
SET @OGUID := 7000701;
SET @SPAWN_GROUP := 1277;

DELETE FROM `battleground_scripts` WHERE `MapId` = 1825 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(1825, 0, 'arena_hook_point');

DELETE FROM `battleground_template` WHERE `ID` = 897;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(897, 6276, 6277, 0, 1, 'Hook Point');

DELETE FROM `conversation_actors` WHERE (`ConversationId`=9450 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(9450, 65852, @CGUID+15, 0, 0, 0, 0, 0, 63305); -- Full: 0x203CD0E420864E80000FF100005001DA Creature/0 R3892/S4081 Map: 1825 (Hook Point) Entry: 137530 (Daniel Poole) Low: 5243354

DELETE FROM `conversation_template` WHERE `Id`=9450;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(9450, 21373, 0, 63305);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+29;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1055.9114990234375, -329.954864501953125, 4.589642047882080078, 3.730200052261352539, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+1, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1048.223876953125, -327.40704345703125, 0.673026502132415771, 0.417364656925201416, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+2, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1040.6112060546875, -342.994293212890625, 1.437951445579528808, 6.221436023712158203, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+3, 143134, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1046.3021240234375, -314.461822509765625, 2.330190658569335937, 3.882303953170776367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Brian Holinka (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+4, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1058.015625, -335.732635498046875, 3.994848489761352539, 3.651679515838623046, 7200, 10, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1 (Auras: 152765 - Mod Scale 135-150%)
(@CGUID+5, 115087, 1825, 9279, 9279, '0', '0', 0, 0, 0, 972.47515869140625, -325.302032470703125, 0.676339328289031982, 0.20080345869064331, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rat (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+6, 143133, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1025.2783203125, -375.282012939453125, 8.534680366516113281, 1.570411920547485351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Disgusting Rat (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+7, 143245, 1825, 9279, 9279, '0', '0', 0, 0, 0, 970.734375, -298.1632080078125, 3.351326465606689453, 2.264124631881713867, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Bouncer (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+8, 143245, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1050.62158203125, -357.223968505859375, 2.02806854248046875, 5.506673336029052734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Bouncer (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+9, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1057.920166015625, -335.44964599609375, 5.155292510986328125, 3.763328790664672851, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+10, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1043.3782958984375, -338.28369140625, 0.744661152362823486, 4.770718097686767578, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+11, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1054.408447265625, -338.9747314453125, 0.875749409198760986, 4.756616115570068359, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+12, 115087, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1042.40087890625, -368.8843994140625, 1.727668046951293945, 1.458274602890014648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rat (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+13, 139068, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1020.59783935546875, -285.5479736328125, 9.021422386169433593, 2.950590133666992187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Boralus Civilian (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+14, 139060, 1825, 9279, 9279, '0', '0', 0, 0, 0, 981.1336669921875, -283.196197509765625, 3.327446699142456054, 2.183746337890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Boralus Worker (Area: Hook Point - Difficulty: 0) CreateObject1 (Auras: 244863 - 8.0 Carry Barrel New Anim)
(@CGUID+15, 137530, 1825, 9279, 9279, '0', '0', 0, 0, 1, 1001.96697998046875, -314.97222900390625, 6.313004970550537109, 3.266660451889038085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Daniel Poole (Area: Hook Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+16, 138894, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1051.1129150390625, -319.619781494140625, 3.766951560974121093, 3.732582807540893554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Chef Robinson (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+17, 115087, 1825, 9279, 9279, '0', '0', 0, 0, 0, 985.70068359375, -360.980010986328125, 0.816299378871917724, 4.237788677215576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Rat (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+18, 138899, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1033.3992919921875, -296.838531494140625, 0.654040932655334472, 4.215125083923339843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Companion (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+19, 139068, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1036.438720703125, -295.1119384765625, 0.8553619384765625, 3.244702100753784179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Boralus Civilian (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+20, 141184, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1057.609375, -359.517364501953125, 1.919618844985961914, 2.679828166961669921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Boralus Civilian (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+21, 139068, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1021.13018798828125, -286.71527099609375, 9.035974502563476562, 4.909348964691162109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Boralus Civilian (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+22, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1054.1669921875, -342.708984375, 1.413500547409057617, 1.787346601486206054, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1 (Auras: 152765 - Mod Scale 135-150%)
(@CGUID+23, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1027.39892578125, -333.947998046875, 0.555386483669281005, 1.086550831794738769, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1 (Auras: 152765 - Mod Scale 135-150%)
(@CGUID+24, 134955, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1051.02294921875, -332.5289306640625, 0.744661152362823486, 0.603641748428344726, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Chicken (Area: Hook Point - Difficulty: 0) CreateObject1 (Auras: 152765 - Mod Scale 135-150%)
(@CGUID+25, 143245, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1048.5086669921875, -358.185760498046875, 1.956497669219970703, 5.506673336029052734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Bouncer (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+26, 143122, 1825, 9279, 9279, '0', '0', 0, 0, 0, 966.6319580078125, -283.078125, 3.367653608322143554, 5.36810302734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Jay the Tavern Bard (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+27, 143245, 1825, 9279, 9279, '0', '0', 0, 0, 0, 968.95660400390625, -298.59027099609375, 3.384720325469970703, 2.266976356506347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Bouncer (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+28, 143121, 1825, 9279, 9279, '0', '0', 0, 0, 0, 966.24652099609375, -285.06597900390625, 3.742449045181274414, 1.501461982727050781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Penny (Area: Hook Point - Difficulty: 0) CreateObject1
(@CGUID+29, 143126, 1825, 9279, 9279, '0', '0', 0, 0, 0, 1056.920166015625, -333.536468505859375, 3.753514528274536132, 3.870003938674926757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Col. Tenders (Area: Hook Point - Difficulty: 0) CreateObject1

UPDATE `creature` SET `StringId` = 'hook_point_bouncer_1' WHERE `guid` = @CGUID+25;
UPDATE `creature` SET `StringId` = 'hook_point_bouncer_2' WHERE `guid` = @CGUID+8;
UPDATE `creature` SET `StringId` = 'hook_point_bouncer_3' WHERE `guid` = @CGUID+7;
UPDATE `creature` SET `StringId` = 'hook_point_bouncer_4' WHERE `guid` = @CGUID+27;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+29;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+24;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 295778, 1825, 9279, 9279, '0', '0', 0, 915.38800048828125, -290.0887451171875, 5.440062522888183593, 1.235011458396911621, 0, 0, 0.579003334045410156, 0.815325140953063964, 7200, 255, 1, 63305), -- Fire (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+1, 297144, 1825, 9279, 9279, '0', '0', 0, 1051.5054931640625, -355.92987060546875, 1.993935108184814453, 1.980946660041809082, 0, 0, 0.836285591125488281, 0.5482940673828125, 7200, 255, 1, 63305), -- Doodad_8HU_KulTiras_SlideDoor001 (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+2, 299251, 1825, 9279, 9279, '0', '0', 0, 1189.9893798828125, -580.01959228515625, 31.51054573059082031, 1.96468353271484375, 0.000000476837158203, -0.0000009536743164, 0.831799507141113281, 0.555076181888580322, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+3, 299250, 1825, 9279, 9279, '0', '0', 0, 1188.0447998046875, -577.60223388671875, 31.50738525390625, 0.094519510865211486, 0.000000953674316406, 0, 0.047242164611816406, 0.998883485794067382, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+4, 299255, 1825, 9279, 9279, '0', '0', 0, 1183.1292724609375, -581.32568359375, 31.51056671142578125, 3.773211479187011718, 0, 0.000000953674316406, -0.95054531097412109, 0.310585945844650268, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+5, 299254, 1825, 9279, 9279, '0', '0', 0, 1180.421630859375, -584.139404296875, 31.49713897705078125, 1.322223186492919921, 0.000000476837158203, -0.0000009536743164, 0.613994598388671875, 0.789310216903686523, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+6, 299253, 1825, 9279, 9279, '0', '0', 0, 1192.1790771484375, -576.419921875, 31.51056671142578125, 3.372272014617919921, 0, 0.000000953674316406, -0.99335575103759765, 0.11508401483297348, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+7, 299252, 1825, 9279, 9279, '0', '0', 0, 1188.703369140625, -575.6353759765625, 31.50739860534667968, 5.4872894287109375, 0.000000953674316406, 0, -0.3875274658203125, 0.921858131885528564, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+8, 299259, 1825, 9279, 9279, '0', '0', 0, 1066.8653564453125, -488.93096923828125, 9.716356277465820312, 4.711831092834472656, 0.000000476837158203, -0.0000009536743164, -0.70730400085449218, 0.706909477710723876, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+9, 299258, 1825, 9279, 9279, '0', '0', 0, 1068.9713134765625, -489.8668212890625, 9.71636199951171875, 3.821414947509765625, 0.000000953674316406, 0, -0.94278430938720703, 0.333403319120407104, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+10, 299257, 1825, 9279, 9279, '0', '0', 0, 1073.980224609375, -477.45977783203125, 9.744752883911132812, 4.703663349151611328, 0.000000476837158203, -0.0000009536743164, -0.71018505096435546, 0.704015016555786132, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+11, 299256, 1825, 9279, 9279, '0', '0', 0, 1178.89111328125, -581.27447509765625, 31.51056671142578125, 5.735074996948242187, 0.000000953674316406, 0, -0.27063751220703125, 0.962681293487548828, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+12, 299263, 1825, 9279, 9279, '0', '0', 0, 1131.3326416015625, -620.092041015625, 17.52761459350585937, 2.07492685317993164, 0.000000953674316406, 0, 0.861117362976074218, 0.508406221866607666, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+13, 299262, 1825, 9279, 9279, '0', '0', 0, 1135.1541748046875, -540.5263671875, 17.69433021545410156, 3.759715080261230468, 0, -0.0000009536743164, -0.95261955261230468, 0.304164439439773559, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+14, 299261, 1825, 9279, 9279, '0', '0', 0, 1130.87744140625, -514.7745361328125, 17.62218475341796875, 4.632379055023193359, 0.000000476837158203, -0.0000009536743164, -0.73482131958007812, 0.678260743618011474, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+15, 299260, 1825, 9279, 9279, '0', '0', 0, 1070.61376953125, -493.22552490234375, 9.719885826110839843, 1.346005439758300781, -0.0000009536743164, 0, 0.6233367919921875, 0.781953513622283935, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+16, 299343, 1825, 9279, 9279, '0', '0', 0, 1121.4482421875, -613.8233642578125, 18.18774604797363281, 4.83634042739868164, 0, 0, -0.66195392608642578, 0.749544501304626464, 7200, 255, 1, 63305), -- Guild Vault (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+17, 299342, 1825, 9279, 9279, '0', '0', 0, 1078.0794677734375, -488.1197509765625, 9.677967071533203125, 2.871063947677612304, 0, 0, 0.990865707397460937, 0.134852290153503417, 7200, 255, 1, 63305), -- Fire (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+18, 299344, 1825, 9279, 9279, '0', '0', 0, 1190.2392578125, -586.1121826171875, 31.48215103149414062, 2.966146230697631835, 0, 0, 0.99615478515625, 0.087610773742198944, 7200, 255, 1, 63305), -- Fire (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+19, 296728, 1825, 9279, 9279, '0', '0', 0, 1049.1458740234375, -357.236114501953125, 1.892428040504455566, 5.140336990356445312, 0, 0, -0.54083061218261718, 0.841131508350372314, 7200, 255, 1, 63305), -- Kul Tiras Arena Invis Wall (Bouncers) (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+20, 296728, 1825, 9279, 9279, '0', '0', 0, 970.201416015625, -298.84722900390625, 3.153641939163208007, 5.133892536163330078, 0, 0, -0.54353809356689453, 0.839384496212005615, 7200, 255, 1, 63305), -- Kul Tiras Arena Invis Wall (Bouncers) (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+21, 299265, 1825, 9279, 9279, '0', '0', 0, 1129.332275390625, -618.3427734375, 17.51376152038574218, 0.021999802440404891, 0, -0.0000009536743164, 0.010999679565429687, 0.999939501285552978, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+22, 299264, 1825, 9279, 9279, '0', '0', 0, 1131.2296142578125, -617.977783203125, 17.51376152038574218, 4.238804340362548828, -0.0000009536743164, 0, -0.85325241088867187, 0.521498143672943115, 7200, 255, 1, 63305), -- Chair (Area: Hook Point - Difficulty: 0) CreateObject1
(@OGUID+23, 184663, 1825, 9279, 9279, '0', '0', 0, 1001.9617919921875, -367.802093505859375, 2.291595697402954101, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 360, 255, 1, 63305), -- Shadow Sight (Area: Hook Point - Difficulty: 0) CreateObject2
(@OGUID+24, 184664, 1825, 9279, 9279, '0', '0', 0, 963.842041015625, -309.107635498046875, 1.149727106094360351, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 360, 255, 1, 63305); -- Shadow Sight (Area: Hook Point - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+24;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.59832048416137695, 0.801256895065307617, 0, 0), -- Fire
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_8HU_KulTiras_SlideDoor001
(@OGUID+2, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+3, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+4, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+5, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+6, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+7, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+8, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+9, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+10, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+11, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+12, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+13, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+14, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+15, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+16, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Guild Vault
(@OGUID+17, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Fire
(@OGUID+18, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Fire
(@OGUID+21, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0), -- Chair
(@OGUID+22, 0, 0, 0.999990463256835937, -0.00436332821846008, 0, 0); -- Chair

DELETE FROM `creature_template_addon` WHERE `entry` IN (143126 /*143126 (Col. Tenders)*/, 143121 /*143121 (Penny)*/, 143122 /*143122 (Jay the Tavern Bard)*/, 141184 /*141184 (Boralus Civilian)*/, 138899 /*138899 (Companion)*/, 139060 /*139060 (Boralus Worker) - 8.0 Carry Barrel New Anim*/, 143245 /*143245 (Bouncer)*/, 134955 /*134955 (Chicken) - Mod Scale 135-150%*/, 143134 /*143134 (Brian Holinka)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(143126, 0, 0, 0, 3, 0, 1, 1, 0, 16395, 0, 0, 0, ''), -- 143126 (Col. Tenders)
(143121, 0, 0, 0, 0, 0, 1, 0, 0, 1535, 0, 0, 0, ''), -- 143121 (Penny)
(143122, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 143122 (Jay the Tavern Bard)
(141184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 141184 (Boralus Civilian)
(138899, 0, 0, 0, 0, 0, 1, 0, 0, 13903, 0, 0, 0, ''), -- 138899 (Companion)
(139060, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244863'), -- 139060 (Boralus Worker) - 8.0 Carry Barrel New Anim
(143245, 0, 0, 0, 0, 0, 1, 0, 0, 15348, 0, 0, 0, ''), -- 143245 (Bouncer)
(134955, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '152765'), -- 134955 (Chicken) - Mod Scale 135-150%
(143134, 0, 0, 0, 0, 0, 0, 1, 0, 16396, 0, 0, 0, ''); -- 143134 (Brian Holinka)

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=63305 WHERE (`Entry`=143126 AND `DifficultyID`=0); -- 143126 (Col. Tenders) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=143121 AND `DifficultyID`=0); -- 143121 (Penny) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=143122 AND `DifficultyID`=0); -- 143122 (Jay the Tavern Bard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=141184 AND `DifficultyID`=0); -- 141184 (vtrsyBoralus Civilian) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=138899 AND `DifficultyID`=0); -- 138899 (Companion) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=138894 AND `DifficultyID`=0); -- 138894 (Chef Robinson) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=63305 WHERE (`Entry`=137530 AND `DifficultyID`=0); -- 137530 (Daniel Poole) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=139060 AND `DifficultyID`=0); -- 139060 (Boralus Worker) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=139068 AND `DifficultyID`=0); -- 139068 (Boralus Civilian) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=143245 AND `DifficultyID`=0); -- 143245 (Bouncer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=143133 AND `DifficultyID`=0); -- 143133 (Disgusting Rat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=143134 AND `DifficultyID`=0); -- 143134 (Brian Holinka) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=134955 AND `DifficultyID`=0); -- 134955 (Chicken) - CanSwim

UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=63305 WHERE `DisplayID`=85348;

UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x1000000 WHERE `entry`=143126; -- Col. Tenders
UPDATE `creature_template` SET `unit_flags`=0x2000100 WHERE `entry`=143121; -- Penny

UPDATE `creature_template` SET `unit_flags3`=0x1000000 WHERE `entry`=141184; -- Boralus Civilian
UPDATE `creature_template` SET `unit_flags`=0x2000100, `unit_flags3`=0x1000000 WHERE `entry`=138899; -- Companion
UPDATE `creature_template` SET `unit_flags`=0x2000300, `unit_flags3`=0x1000001 WHERE `entry`=138894; -- Chef Robinson
UPDATE `creature_template` SET `unit_flags`=0x2000200, `unit_flags3`=0x41000000 WHERE `entry`=137530; -- Daniel Poole
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x1000000 WHERE `entry`=139060; -- Boralus Worker
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=139068; -- Boralus Civilian
UPDATE `creature_template` SET `unit_flags3`=0x1000000 WHERE `entry`=143245; -- Bouncer
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x1000000 WHERE `entry`=143133; -- Disgusting Rat
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=115087; -- Rat
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x1000000 WHERE `entry`=143134; -- Brian Holinka
UPDATE `creature_template` SET `unit_flags`=0x2000100 WHERE `entry`=134955; -- Chicken

DELETE FROM `creature_text` WHERE `CreatureID` IN (137530);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(137530, 0, 0, 'This is a night for Kul Tiras!', 12, 0, 100, 1, 0, 104433, 153439, 3, 'Daniel Poole'),
(137530, 1, 0, 'No, no, no. Good save, good save.', 12, 0, 100, 1, 0, 104442, 153442, 3, 'Daniel Poole to Player'),
(137530, 1, 1, 'Now now, there will be blood! Have patience.', 12, 0, 100, 1, 0, 104441, 153444, 3, 'Daniel Poole to Player'),
(137530, 2, 0, 'Oopsie-daisy!', 12, 0, 100, 1, 0, 104438, 153440, 3, 'Daniel Poole to Player'),
(137530, 2, 1, 'You die... but not as a true Kul Tiran.', 12, 0, 100, 1, 0, 104439, 153441, 3, 'Daniel Poole to Player');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Hook Point - Shadow sight', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+23),
(@SPAWN_GROUP, 1, @OGUID+24);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

DELETE FROM `spell_proc` WHERE `SpellId` IN (278776);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(278776,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Arena Reaction Trigger

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_arena_reaction_trigger_low_health', 'spell_arena_reaction_trigger', 'spell_arena_low_health_dying_trigger');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(278776, 'spell_arena_reaction_trigger'),
(278775, 'spell_arena_reaction_trigger_low_health'),
(279047, 'spell_arena_low_health_dying_trigger');

SET @ENTRY := 143121;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, 7.0, 'Penny - On Arena Start');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1002.6268, -329.17535, -0.05121885, NULL, 0);

SET @ENTRY := 143121;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, 7.0, 'Penny - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1018.8993, -350.7066, 1.8962542, NULL, 0),
(@PATH, 1, 1043.9427, -335.64932, 0.74466115, NULL, 0),
(@PATH, 2, 1033.0139, -315.99478, 0.31332558, NULL, 0),
(@PATH, 3, 1004.9827, -304.06076, -0.52707595, NULL, 0),
(@PATH, 4, 988.11804, -323.31076, 0.24062353, NULL, 0),
(@PATH, 5, 999.5833, -338.9479, -0.07570532, NULL, 0);

SET @MOVERGUID := @CGUID+19;
SET @ENTRY := 139068;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Boralus Civilian - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1036.8496, -295.45276, 0.85536194, NULL, 0),
(@PATH, 1, 1036.2559, -295.13086, 0.85536194, NULL, 0),
(@PATH, 2, 1035.6621, -294.80896, 0.85536194, NULL, 0),
(@PATH, 3, 1033.4913, -293.63202, 0.85536194, NULL, 0),
(@PATH, 4, 1032.6459, -293.1736, 0.8901193, NULL, 0),
(@PATH, 5, 1029.1041, -293.6059, 1.0361143, NULL, 0),
(@PATH, 6, 1022.875, -290.9271, 1.108589, NULL, 0),
(@PATH, 7, 1018.5399, -288.98264, 0.8182485, NULL, 0),
(@PATH, 8, 1013.1771, -290.1354, 0.89820075, NULL, 0),
(@PATH, 9, 1011.191, -289.06946, 0.968675, NULL, 0),
(@PATH, 10, 1011.8559, -286.24478, 1.8783445, NULL, 0),
(@PATH, 11, 1013.5027, -283.42355, 1.4491118, NULL, 0),
(@PATH, 12, 1017.2726, -283.8854, 1.4036883, NULL, 0);

UPDATE `creature` SET `position_x`=1036.8496, `position_y`=-295.45276, `position_z`=0.85536194, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+14;
SET @ENTRY := 139060;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Boralus Worker - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 988.19965, -283.2309, 3.1939359, NULL, 0),
(@PATH, 1, 991.59375, -275.80728, 3.1649206, NULL, 0),
(@PATH, 2, 996.6649, -269.13196, 3.2029614, NULL, 0),
(@PATH, 3, 1008.0764, -262.5, 3.193937, NULL, 8266),
(@PATH, 4, 993.441, -273.1979, 3.189241, NULL, 0),
(@PATH, 5, 987.9219, -277.43228, 3.1842632, NULL, 0),
(@PATH, 6, 987.75867, -281.50174, 3.1939352, NULL, 0),
(@PATH, 7, 981.6042, -285.86807, 3.2330961, NULL, 0),
(@PATH, 8, 980.74133, -282.85764, 3.255417, NULL, 6974);

UPDATE `creature` SET `position_x`=988.19965, `position_y`=-283.2309, `position_z`=3.1939359, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+20;
SET @ENTRY := 139068;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Boralus Civilian - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1036.8496, -295.45276, 0.85536194, NULL, 0),
(@PATH, 1, 1036.2559, -295.13086, 0.85536194, NULL, 0),
(@PATH, 2, 1035.6621, -294.80896, 0.85536194, NULL, 0),
(@PATH, 3, 1033.4913, -293.63202, 0.85536194, NULL, 0),
(@PATH, 4, 1032.6459, -293.1736, 0.8901193, NULL, 0),
(@PATH, 5, 1029.1041, -293.6059, 1.0361143, NULL, 0),
(@PATH, 6, 1022.875, -290.9271, 1.108589, NULL, 0),
(@PATH, 7, 1018.5399, -288.98264, 0.8182485, NULL, 0),
(@PATH, 8, 1013.1771, -290.1354, 0.89820075, NULL, 0),
(@PATH, 9, 1011.191, -289.06946, 0.968675, NULL, 0),
(@PATH, 10, 1011.8559, -286.24478, 1.8783445, NULL, 0),
(@PATH, 11, 1013.5027, -283.42355, 1.4491118, NULL, 0),
(@PATH, 12, 1017.2726, -283.8854, 1.4036883, NULL, 0);

UPDATE `creature` SET `position_x`=1036.8496, `position_y`=-295.45276, `position_z`=0.85536194, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+21;
SET @ENTRY := 139068;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Boralus Civilian - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1011.4462, -283.67188, 8.977495, NULL, 0),
(@PATH, 1, 1008.8958, -283.1146, 9.058487, NULL, 13007),
(@PATH, 2, 1017.0538, -284.80728, 9.058487, NULL, 0),
(@PATH, 3, 1020.3698, -285.39932, 9.058487, NULL, 0),
(@PATH, 4, 1020.8663, -287.8229, 9.355321, NULL, 12581),
(@PATH, 5, 1021.1302, -286.71527, 9.111922, NULL, 15364);

UPDATE `creature` SET `position_x`=1011.4462, `position_y`=-283.67188, `position_z`=8.977495, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+25;
SET @ENTRY := 143245;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bouncer - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1045.2786, -352.85156, 2.5022535, NULL, 0),
(@PATH, 1, 1042.0286, -349.10156, 2.2522535, NULL, 0),
(@PATH, 2, 1022.52856, -354.35156, 2.5022535, NULL, 0),
(@PATH, 3, 1007.27856, -363.35156, 2.5022535, NULL, 0),
(@PATH, 4, 1003.5486, -371.01736, 2.5480092, NULL, 0);

SET @MOVERGUID := @CGUID+7;
SET @ENTRY := 143245;
SET @PATHOFFSET := 2; -- 1
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bouncer - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 977.1727, -301.1363, 0.8325119, NULL, 0),
(@PATH, 1, 984.4227, -305.1363, 0.3325119, NULL, 0),
(@PATH, 2, 997.6727, -304.1363, -0.1674881, NULL, 0),
(@PATH, 3, 1009.6727, -292.3863, 0.8325119, NULL, 0),
(@PATH, 4, 1013.4227, -283.6363, 1.8325119, NULL, 0),
(@PATH, 5, 1018.1111, -284.10938, 1.3136975, NULL, 0);

SET @MOVERGUID := @CGUID+27;
SET @ENTRY := 143245;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bouncer - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 980.68317, -304.7292, 0.09912133, NULL, 0),
(@PATH, 1, 987.93317, -308.7292, 0.34912133, NULL, 0),
(@PATH, 2, 998.68317, -302.4792, -0.15087867, NULL, 0),
(@PATH, 3, 1009.93317, -292.7292, 0.84912133, NULL, 0),
(@PATH, 4, 1013.18317, -283.4792, 1.8491213, NULL, 0),
(@PATH, 5, 1018.9097, -283.86807, 1.3135223, NULL, 0);

SET @MOVERGUID := @CGUID+8;
SET @ENTRY := 143245;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bouncer - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1041.0739, -351.52954, 2.2203364, NULL, 0),
(@PATH, 1, 1037.5739, -353.27954, 2.7203364, NULL, 0),
(@PATH, 2, 1032.0739, -355.52954, 2.7203364, NULL, 0),
(@PATH, 3, 1021.32385, -360.02954, 2.7203364, NULL, 0),
(@PATH, 4, 1013.32385, -365.52954, 2.4703364, NULL, 0),
(@PATH, 5, 1009.5261, -368.33508, 2.412604, NULL, 0);

 -- Bouncer smart ai
SET @ENTRY := 143245;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 58, 0, 100, 0, 0xFFFFFFFF, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of any path ended - Self: Despawn instantly', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 143245 AND `SourceId` = 0;

 -- Penny smart ai
SET @ENTRY := 143121;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 58, 0, 100, 0, 0, 14312100, 0, 0, 0, 53, 1, 14312101, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On any waypoint of path 14312100 ended - Self: Start path #14312101, run, repeat, Passive', ''),
(@ENTRY, 0, 1, 0, 72, 0, 100, 0, 4, 0, 0, 0, 0, 53, 0, 14312100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On action[4] - Self: Start path #14312100, run, do not repeat, Passive', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 143121 AND `SourceId` = 0;
