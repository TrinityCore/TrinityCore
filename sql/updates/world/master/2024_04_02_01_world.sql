SET @CGUID := 3000073;
SET @OGUID := 3001623;
SET @POOL_ID := 800009;
SET @SPAWNGROUP := 1242;

UPDATE `battleground_template` SET `Weight` = 1 WHERE `ID` = 120;

DELETE FROM `graveyard_zone` where `ID` IN (1735, 1736, 1738, 1739, 1740);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(1735, 5449, 'Battle for Gilneas - Mines'),
(1736, 5449, 'Battle for Gilneas - Lighthouse'),
(1738, 5449, 'Battle for Gilneas - Waterworks'),
(1739, 5449, 'Battle for Gilneas - Horde Start'),
(1740, 5449, 'Battle for Gilneas - Alliance Start');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (1735, 1736, 1738, 1739, 1740);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
-- Bases
(27, 1740, 5449, 0, 6, 469, 0, 'Graveyard - Battle for Gilneas - Alliance Base - Team Alliance'),
(27, 1739, 5449, 0, 6, 67, 0, 'Graveyard - Battle for Gilneas - Horde Base - Team Horde'),
-- Mines
(27, 1735, 5449, 0, 6, 469, 0, 'Graveyard - Battle for Gilneas - Mines- Team Alliance'),
(27, 1735, 5449, 0, 11, 8853, 5, 'Graveyard - Battle for Gilneas - Mines - Alliance Controlled'),
(27, 1735, 5449, 1, 6, 67, 0, 'Graveyard - Battle for Gilneas - Mines - Team Horde'),
(27, 1735, 5449, 1, 11, 8853, 4, 'Graveyard - Battle for Gilneas - Mines - Horde Controlled'),
-- Waterworks
(27, 1738, 5449, 0, 6, 469, 0, 'Graveyard - Battle for Gilneas - Waterworks - Team Alliance'),
(27, 1738, 5449, 0, 11, 8852, 5, 'Graveyard - Battle for Gilneas - Waterworks - Alliance Controlled'),
(27, 1738, 5449, 1, 6, 67, 0, 'Graveyard - Battle for Gilneas - Waterworks - Team Horde'),
(27, 1738, 5449, 1, 11, 8852, 4, 'Graveyard - Battle for Gilneas - Waterworks - Horde Controlled'),
-- Lighthouse
(27, 1736, 5449, 0, 6, 469, 0, 'Graveyard - Battle for Gilneas - Lighthouse - Team Alliance'),
(27, 1736, 5449, 0, 11, 8851, 5, 'Graveyard - Battle for Gilneas - Lighthouse - Alliance Controlled'),
(27, 1736, 5449, 1, 6, 67, 0, 'Graveyard - Battle for Gilneas - Lighthouse - Team Horde'),
(27, 1736, 5449, 1, 11, 8851, 4, 'Graveyard - Battle for Gilneas - Lighthouse - Horde Controlled');

DELETE FROM `world_state` WHERE `ID` IN (8851, 8852, 8853, 17355, 17356, 17357, 17358, 17359, 17360);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `Comment`) VALUES
(8851, 1, '761', 'Battle for Gilneas - Lighthouse control state POI'),
(8852, 1, '761', 'Battle for Gilneas - Waterworks control state POI'),
(8853, 1, '761', 'Battle for Gilneas - Mines control state POI'),
(17355, 0, '761', 'Battle for Gilneas - Lighthouse Horde control state widget'),
(17356, 0, '761', 'Battle for Gilneas - Lighthouse Alliance control state widget'),
(17358, 0, '761', 'Battle for Gilneas - Waterworks Horde control state widget'),
(17357, 0, '761', 'Battle for Gilneas - Waterworks Alliance control state widget'),
(17360, 0, '761', 'Battle for Gilneas - Mines Horde control state widget'),
(17359, 0, '761', 'Battle for Gilneas - Mines Alliance control state widget');

-- Areatrigger Scripts for buffs
DELETE FROM `areatrigger_scripts` WHERE `entry` IN (6266, 6265, 6267, 6269, 6268);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(6265, 'at_battleground_buffs'),
(6266, 'at_battleground_buffs'),
(6267, 'at_battleground_buffs'),
(6268, 'at_battleground_buffs'),
(6269, 'at_battleground_buffs');

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOL_ID+0 AND @POOL_ID+2;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL_ID+0, 1, 'Battle for Gilneas - Mines Buff'),
(@POOL_ID+1, 1, 'Battle for Gilneas - Lighthouse Buff'),
(@POOL_ID+2, 1, 'Battle for Gilneas - Waterworks Buff');

DELETE FROM `pool_members` WHERE `poolSpawnId` BETWEEN @POOL_ID+0 AND @POOL_ID+2;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+5, @POOL_ID+0, 0, 'Battle for Gilneas - Berserker Buff - Mines'),
(1, @OGUID+26, @POOL_ID+0, 0, 'Battle for Gilneas - Food Buff - Mines'),
(1, @OGUID+32, @POOL_ID+0, 0, 'Battle for Gilneas - Speed Buff - Mines'),

(1, @OGUID+4, @POOL_ID+1, 0, 'Battle for Gilneas - Berserker Buff - Lighthouse'),
(1, @OGUID+30, @POOL_ID+1, 0, 'Battle for Gilneas - Food Buff - Lighthouse'),
(1, @OGUID+33, @POOL_ID+1, 0, 'Battle for Gilneas - Speed Buff - Lighthouse'),

(1, @OGUID+8, @POOL_ID+2, 0, 'Battle for Gilneas - Berserker Buff - Waterworks'),
(1, @OGUID+31, @POOL_ID+2, 0, 'Battle for Gilneas - Food Buff - Waterworks'),
(1, @OGUID+28, @POOL_ID+2, 0, 'Battle for Gilneas - Speed Buff - Waterworks');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+5;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'Battle for Gilneas - Mines - Horde Controlled (graveyard)', 0x20),
(@SPAWNGROUP+1, 'Battle for Gilneas - Mines - Alliance Controlled (graveyard)', 0x20),
(@SPAWNGROUP+2, 'Battle for Gilneas - Waterworks - Horde Controlled (graveyard)', 0x20),
(@SPAWNGROUP+3, 'Battle for Gilneas - Waterworks - Alliance Controlled (graveyard)', 0x20),
(@SPAWNGROUP+4, 'Battle for Gilneas - Lighthouse - Horde Controlled (graveyard)', 0x20),
(@SPAWNGROUP+5, 'Battle for Gilneas - Lighthouse - Alliance Controlled (graveyard)', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+5;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 0, @CGUID+334),
(@SPAWNGROUP+1, 0, @CGUID+500),
(@SPAWNGROUP+2, 0, @CGUID+335),
(@SPAWNGROUP+3, 0, @CGUID+501),
(@SPAWNGROUP+4, 0, @CGUID+502),
(@SPAWNGROUP+5, 0, @CGUID+55);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN @SPAWNGROUP+0 AND @SPAWNGROUP+5;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWNGROUP+0, 0, 0, 11, 0, 8853, 4, 0, 0, 0, 0, '', 'Battle for Gilneas - Mines - Horde Controlled'),
(33, 0, @SPAWNGROUP+1, 0, 0, 11, 0, 8853, 5, 0, 0, 0, 0, '', 'Battle for Gilneas - Mines - Alliance Controlled'),
(33, 0, @SPAWNGROUP+2, 0, 0, 11, 0, 8852, 4, 0, 0, 0, 0, '', 'Battle for Gilneas - Waterworks - Horde Controlled'),
(33, 0, @SPAWNGROUP+3, 0, 0, 11, 0, 8852, 5, 0, 0, 0, 0, '', 'Battle for Gilneas - Waterworks - Alliance Controlled'),
(33, 0, @SPAWNGROUP+4, 0, 0, 11, 0, 8851, 4, 0, 0, 0, 0, '', 'Battle for Gilneas - Lighthouse - Horde Controlled'),
(33, 0, @SPAWNGROUP+5, 0, 0, 11, 0, 8851, 5, 0, 0, 0, 0, '', 'Battle for Gilneas - Lighthouse - Alliance Controlled');

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+35;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 207083, 761, 5449, 5453, '0', '0', 0, 851.224853515625, 1361.31494140625, 30.00773239135742187, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 7200, 255, 1, 53989), -- Stove (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+1, 207082, 761, 5449, 5453, '0', '0', 0, 885.692138671875, 1375.1756591796875, 29.34804534912109375, 1.893678903579711914, 0, 0, 0.811573028564453125, 0.584250986576080322, 7200, 255, 1, 53989), -- Cauldron (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+2, 205495, 761, 5449, 5453, '0', '0', 0, 1395.9600830078125, 977.2569580078125, -13.7897014617919921, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 7200, 255, 1, 53989), -- Horde Gate (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+3, 205496, 761, 5449, 5453, '0', '0', 0, 918.29864501953125, 1336.4896240234375, 20.45499992370605468, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 7200, 255, 1, 53989), -- Alliance Gate (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+4, 180380, 761, 5449, 5453, '0', '0', 0, 1063.564208984375, 1308.9791259765625, 4.911691665649414062, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 90, 255, 1, 53989), -- Berserk Buff (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+5, 180382, 761, 5449, 5453, '0', '0', 0, 1195.72998046875, 1020.29998779296875, 7.978740215301513671, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 90, 255, 1, 53989), -- Berserk Buff (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+6, 180147, 761, 5449, 5453, '0', '0', 0, 1111.4305419921875, 921.6163330078125, 30.07139015197753906, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 90, 255, 1, 53989), -- Speed Buff (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+7, 180146, 761, 5449, 5453, '0', '0', 0, 966.4580078125, 1043.5699462890625, 13.14669990539550781, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 90, 255, 1, 53989), -- Speed Buff (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+8, 180148, 761, 5449, 5453, '0', '0', 0, 990.2969970703125, 983.37298583984375, 12.98260021209716796, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 90, 255, 1, 53989), -- Berserk Buff (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+9, 267985, 761, 5449, 5453, '0', '0', 0, 933.6484375, 1427.4461669921875, 28.91886138916015625, 4.066620349884033203, 0, 0, -0.89493370056152343, 0.44619917869567871, 7200, 255, 1, 53989), -- Doodad_firewoodpile-indoor-only01 (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+10, 267984, 761, 5449, 5453, '0', '0', 0, 1065.8585205078125, 1307.032470703125, 4.974267482757568359, 5.5065155029296875, 0, 0, -0.3786478042602539, 0.925540864467620849, 7200, 255, 1, 53989), -- Doodad_firewoodpile-indoor-only02 (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+11, 205045, 761, 5449, 5453, '0', '0', 0, 1196.86083984375, 1022.99267578125, 8.256913185119628906, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 7200, 255, 1, 53989), -- Cauldron (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+12, 205037, 761, 5449, 5453, '0', '0', 0, 926.920166015625, 1014.3675537109375, 19.86332321166992187, 0.226890549063682556, 0, 0, 0.113202095031738281, 0.993571996688842773, 7200, 255, 1, 53989), -- Fire (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+13, 205036, 761, 5449, 5453, '0', '0', 0, 927.24725341796875, 1015.525146484375, 19.00165557861328125, 2.783795118331909179, 0, 0, 0.984040260314941406, 0.177946031093597412, 7200, 255, 1, 53989), -- Stove (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+14, 205038, 761, 5449, 5453, '0', '0', 0, 927.7421875, 1016.9154052734375, 19.86332321166992187, 0.270525157451629638, 0, 0, 0.134850502014160156, 0.990865945816040039, 7200, 255, 1, 53989), -- Fire (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+15, 267983, 761, 5449, 5453, '0', '0', 0, 1066.7442626953125, 1307.72900390625, 4.978141307830810546, 4.476771354675292968, 0, 0, -0.78531646728515625, 0.619094550609588623, 7200, 255, 1, 53989), -- Doodad_firewoodpile-indoor-only01 (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+16, 267985, 761, 5449, 5453, '0', '0', 0, 1015.02655029296875, 929.04248046875, 14.26296329498291015, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 7200, 255, 1, 53989), -- Doodad_firewoodpile-indoor-only01 (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+17, 207177, 761, 5449, 5453, '0', '0', 0, 918.390625, 1336.640625, 27.42519950866699218, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 7200, 255, 1, 53989), -- Alliance Door (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+18, 207178, 761, 5449, 5453, '0', '0', 0, 1395.970458984375, 977.09027099609375, 7.635970115661621093, 6.274459362030029296, 0, 0, -0.00436305999755859, 0.999990463256835937, 7200, 255, 1, 53989), -- Horde Gate (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+22, 228053, 761, 5449, 5452, '0', '0', 0, 1251.0086669921875, 958.26910400390625, 5.668474674224853515, 5.86425018310546875, 0, 0, -0.20793914794921875, 0.97814178466796875, 7200, 255, 1, 53989), -- Capture Point (Area: Mines - Difficulty: 0) CreateObject2
(@OGUID+23, 228050, 761, 5449, 5452, '0', '0', 0, 1057.7396240234375, 1278.26220703125, 3.179371118545532226, 4.909808158874511718, 0, 0, -0.63397979736328125, 0.773349583148956298, 7200, 255, 1, 53989), -- Capture Point (Area: Mines - Difficulty: 0) CreateObject1
(@OGUID+24, 228052, 761, 5449, 5451, '0', '0', 0, 980.03302001953125, 948.73785400390625, 12.73535633087158203, 5.877463817596435546, 0, 0, -0.20147228240966796, 0.979494214057922363, 7200, 255, 1, 53989), -- Capture Point (Area: Waterworks - Difficulty: 0) CreateObject2
(@OGUID+26, 180145, 761, 5449, 5452, '0', '0', 0, 1195.72998046875, 1020.29998779296875, 7.978740215301513671, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 90, 255, 1, 53989), -- Food Buff (Area: Mines - Difficulty: 0) CreateObject2
(@OGUID+28, 180384, 761, 5449, 5453, '0', '0', 0, 990.2969970703125, 983.37298583984375, 12.98260021209716796, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 90, 255, 1, 53989), -- Speed Buff (Area: Horde Landing - Difficulty: 0) CreateObject1
(@OGUID+30, 180144, 761, 5449, 5451, '0', '0', 0, 1063.564208984375, 1308.9791259765625, 4.911691665649414062, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 90, 255, 1, 53989), -- Food Buff (Area: Waterworks - Difficulty: 0) CreateObject1
(@OGUID+31, 180383, 761, 5449, 5451, '0', '0', 0, 990.2969970703125, 983.37298583984375, 12.98260021209716796, 4.555310726165771484, 0, 0, -0.76040554046630859, 0.649448513984680175, 90, 255, 1, 53989), -- Food Buff (Area: Waterworks - Difficulty: 0) CreateObject2
(@OGUID+32, 180381, 761, 5449, 5451, '0', '0', 0, 1195.72998046875, 1020.29998779296875, 7.978740215301513671, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 90, 255, 1, 53989), -- Speed Buff (Area: Waterworks - Difficulty: 0) CreateObject1
(@OGUID+33, 180379, 761, 5449, 5453, '0', '0', 0, 1063.564208984375, 1308.9791259765625, 4.911691665649414062, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 90, 255, 1, 0); -- Speed Buff (Area: Horde Landing - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+35;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.465614736080169677, 0.884987533092498779, 0, 0), -- Stove
(@OGUID+1, 0, 0, 0.465614736080169677, 0.884987533092498779, 0, 0), -- Cauldron
(@OGUID+9, 0, 0, -0.70710676908493041, 0.707106769084930419, 0, 0), -- Doodad_firewoodpile-indoor-only01
(@OGUID+10, 0, 0, 0.911762058734893798, -0.41071885824203491, 0, 0), -- Doodad_firewoodpile-indoor-only02
(@OGUID+11, 0, 0, -0.27563735842704772, 0.961261689662933349, 0, 0), -- Cauldron
(@OGUID+12, 0, 0, -0.17364829778671264, 0.984807729721069335, 0, 0), -- Fire
(@OGUID+13, 0, 0, -0.17364829778671264, 0.984807729721069335, 0, 0), -- Stove
(@OGUID+14, 0, 0, -0.17364829778671264, 0.984807729721069335, 0, 0), -- Fire
(@OGUID+15, 0, 0, 0.911762058734893798, -0.41071885824203491, 0, 0), -- Doodad_firewoodpile-indoor-only01
(@OGUID+16, 0, 0, 0.927183866500854492, -0.37460660934448242, 0, 0); -- Doodad_firewoodpile-indoor-only01

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+600;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 14848, 761, 5449, 5453, '0', '0', 0, 0, 2, 1073.699951171875, 1166.6800537109375, 5.155783653259277343, 0.645771801471710205, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Herald (Area: Horde Landing - Difficulty: 0) CreateObject1
(@CGUID+55, 13116, 761, 5449, 5451, '0', '0', 0, 0, 1, 1035.8800048828125, 1341.280029296875, 11.622833251953125, 4.415682792663574218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Alliance Spirit Guide (Area: Waterworks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+56, 13117, 761, 5449, 5451, '0', '0', 0, 0, 1, 1407.4300537109375, 977.114990234375, 7.525483608245849609, 3.141592741012573242, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Horde Spirit Guide (Area: Waterworks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+57, 13116, 761, 5449, 5451, '0', '0', 0, 0, 1, 899.10198974609375, 1341.3699951171875, 27.65543365478515625, 6.038839340209960937, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Alliance Spirit Guide (Area: Waterworks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+334, 13117, 761, 5449, 5451, '0', '0', 0, 0, 1, 1252.3199462890625, 831.593994140625, 27.872833251953125, 1.48352980613708496, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Horde Spirit Guide (Area: Waterworks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+335, 13117, 761, 5449, 5451, '0', '0', 0, 0, 1, 886.45001220703125, 936.66802978515625, 24.44873428344726562, 0.453785598278045654, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 53989), -- Horde Spirit Guide (Area: Waterworks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)

(@CGUID+500, 13116, 761, 5449, 5451, '0', '0', 0, 0, 1, 1252.3199462890625, 831.593994140625, 27.872833251953125, 1.48352980613708496, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 0), -- Alliance Spirit Guide (Area: Waterworks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+501, 13116, 761, 5449, 5451, '0', '0', 0, 0, 1, 886.45001220703125, 936.66802978515625, 24.44873428344726562, 0.453785598278045654, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 0), -- Alliance Spirit Guide (Area: Waterworks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+502, 13117, 761, 5449, 5451, '0', '0', 0, 0, 1, 1035.8800048828125, 1341.280029296875, 11.622833251953125, 4.415682792663574218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 0); -- Horde Spirit Guide (Area: Waterworks - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
