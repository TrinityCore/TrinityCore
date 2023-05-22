-- SW City update - part 2 =>> Area : Stormwind Harbor ( 1 / 4 )

SET @CGUID := 850628;
SET @OGUID := 501811;

-- Delete some old spawns (Auberdine Sentinel, Nayura Dockmaster)
DELETE FROM `creature` WHERE `guid` IN (251159, 251153, 313450, 313448, 251163);

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 158512, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8284.6220703125, 1403.74658203125, 4.493558883666992187, 2.683667421340942382, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Daniel Julian (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+1, 158488, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8285.9580078125, 1403.1458740234375, 4.500016689300537109, 1.426343798637390136, 120, 0, 0, 1604, 0, 0, 0, 0, 0, 45338), -- Ty Julian (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+2, 142641, 0, 1519, 4411, 0, 0, 0, 0, 0, -8650.2451171875, 1325.2291259765625, 5.316545486450195312, 5.508950233459472656, 120, 0, 0, 22895, 0, 0, 0, 0, 0, 45745), -- Aron Kyleson - Dockmaster (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+3, 141902, 0, 1519, 4411, 0, 0, 0, 0, 0, -8643.294921875, 1308.390625, 5.3175201416015625, 5.433049201965332031, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 45745), -- Perrin Moontear (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+4, 3469, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8600.9658203125, 1199.092041015625, 5.2983856201171875, 0.866046667098999023, 120, 0, 0, 23582, 0, 0, 0, 0, 0, 45745), -- 3469 (Area: Stormwind Harbor - Difficulty: 0) (Auras: 244971 - Set Health (Random 15%-55%))
(@CGUID+5, 158589, 0, 1519, 4411, 0, 0, 0, 0, 0, -8286.9697265625, 1398.6190185546875, 4.516635417938232421, 0.180753707885742187, 120, 10, 0, 27, 0, 1, 0, 0, 0, 45338), -- Eisley (Area: Stormwind Harbor - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8531.263671875, 1211.4947509765625, 5.30043792724609375, 5.292941093444824218, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- 140253 (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+7, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8604.169921875, 1224.4427490234375, 5.313576698303222656, 0.467964798212051391, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- 140253 (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+8, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8531.544921875, 1209.607666015625, 5.378472328186035156, 0.467964798212051391, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- 140253 (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+9, 53527, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8640.830078125, 1325.7742919921875, 5.316489696502685546, 5.203694820404052734, 120, 0, 0, 4812, 0, 0, 0, 0, 0, 45745), -- Prisoner (Area: Stormwind Harbor - Difficulty: 0) (Auras: 99365 - Under Arrest)
(@CGUID+10, 68, 0, 1519, 4411, 0, 11595, 0, 0, 1, -8641.7587890625, 1327.6944580078125, 5.316112995147705078, 5.148721218109130859, 120, 10, 0, 17687, 0, 0, 0, 0, 0, 45745), -- Stormwind City Guard (Area: Stormwind Harbor - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+11, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8628.9462890625, 1269.251708984375, 5.316493034362792968, 5.351186275482177734, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- Darnassian Refugee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+12, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8630.158203125, 1267.998291015625, 5.315853118896484375, 0.199740275740623474, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- Darnassian Refugee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+13, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8595.3994140625, 1262.3802490234375, 5.313805580139160156, 4.168401241302490234, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- Darnassian Refugee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+14, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8594.720703125, 1259.40283203125, 5.313995361328125, 2.350676298141479492, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- Darnassian Refugee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+15, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8597.361328125, 1259.607666015625, 5.51643991470336914, 5.585411548614501953, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- Darnassian Refugee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+16, 140403, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8529.0107421875, 1209.4375, 5.360833168029785156, 2.649040460586547851, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- Displaced Gilnean Refugee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+17, 140403, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8601.6337890625, 1224.2725830078125, 5.313576698303222656, 2.649040460586547851, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- Displaced Gilnean Refugee (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+18, 5504, 0, 1519, 4411, 0, 0, 0, 0, 1, -8575.11328125, 1246.201416015625, 5.313568115234375, 4.729842185974121093, 120, 0, 0, 15918, 0, 0, 0, 0, 0, 45745), -- Sheldras Moontree (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+19, 141554, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8568.658203125, 1215.2691650390625, 5.206286430358886718, 0, 120, 0, 0, 186, 100, 0, 0, 0, 0, 45745), -- 141554 (Area: Stormwind Harbor - Difficulty: 0) (Auras: 52455 - PvP Vehicle Health Regen Suppression)
(@CGUID+20, 140253, 0, 1519, 4411, 0, 11595, 0, 0, 0, -8603.888671875, 1226.329833984375, 5.313576698303222656, 5.292941093444824218, 120, 0, 0, 124, 0, 0, 0, 0, 0, 45745), -- 140253 (Area: Stormwind Harbor - Difficulty: 0)
(@CGUID+21, 151187, 0, 1519, 4411, 0, 0, 0, 0, 0, -8215.2158203125, 1311.871826171875, -0.24692121148109436, 0.880308151245117187, 120, 0, 0, 4579, 1807, 0, 0, 0, 0, 45745), -- 151187 (Area: Stormwind Harbor - Difficulty: 0) (Auras: 292845 - [DNT] Ship Blessing)
(@CGUID+22, 188374, 0, 1519, 4411, 0, 0, 0, 0, 0, -8437.984375, 1225.9617919921875, 5.313569545745849609, 6.178342819213867187, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45338), -- Millbert (Area: Stormwind Harbor - Difficulty: 0) (Auras: 370841 - Cosmetic - Carry Box)
(@CGUID+23, 139088, 0, 1519, 4411, 0, 0, 0, 0, 1, -8645.2509765625, 1315.32861328125, 5.315582275390625, 0.558505356311798095, 120, 0, 0, 377265, 0, 0, 0, 0, 0, 45745), -- Boralus Guard (Area: Stormwind Harbor - Difficulty: 0) (Auras: )
(@CGUID+24, 139088, 0, 1519, 4411, 0, 0, 0, 0, 1, -8632.423828125, 1322.6668701171875, 5.315583705902099609, 3.630284786224365234, 120, 0, 0, 377265, 0, 0, 0, 0, 0, 45745), -- Boralus Guard (Area: Stormwind Harbor - Difficulty: 0) (Auras: )
(@CGUID+25, 139088, 0, 1519, 4411, 0, 0, 0, 0, 1, -8593.7890625, 1246.0025634765625, 5.313799381256103515, 4.101523876190185546, 120, 0, 0, 377265, 0, 0, 0, 0, 0, 45745), -- Boralus Guard (Area: Stormwind Harbor - Difficulty: 0) (Auras: )
(@CGUID+26, 139088, 0, 1519, 4411, 0, 0, 0, 0, 1, -8606.9775390625, 1239.413330078125, 5.314605712890625, 0.506145477294921875, 120, 0, 0, 377265, 0, 0, 0, 0, 0, 45745); -- Boralus Guard (Area: Stormwind Harbor - Difficulty: 0) (Auras: )

DELETE FROM `creature_template_movement` WHERE `CreatureId` = 44880;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(44880, 0, 0, 1, 0, 0, 0, NULL);

DELETE FROM `creature_model_info` WHERE `DisplayID`=98849;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(98849, 0.326728612184524536, 0.550000011920928955, 0, 45745);

UPDATE `creature_model_info` SET `VerifiedBuild`=45745 WHERE `DisplayID` IN (1473, 99418, 1472, 3285, 39532, 99496, 37087, 99497, 99498, 5233, 1519, 1509, 1544, 14493, 77690, 77687, 221, 39052, 49021, 93574, 28282, 28111, 72724, 22769, 33303, 37850, 262, 61764, 14492, 19670, 15921, 42276, 7996, 36758, 15594, 80, 5074, 2974, 10624, 1447, 1427, 1446, 99615, 1433, 1423, 1525, 1438, 99495, 1439, 42722, 33520, 42720, 36597, 99391, 33519, 33518, 5546, 37372, 5547, 5444, 1436, 1429, 1450, 20873, 99389, 33468, 5545, 4888, 1443, 36839, 25901, 3246, 5552, 7992, 5551, 99197, 99196, 11686, 1431, 7991, 37310, 36213, 3133, 3167, 1541, 14472, 5082, 1445, 5446, 1437, 5567, 1418, 4181, 33948, 1141, 37311, 1448, 2208, 106457, 338, 1440, 87182, 1434, 2176, 42274, 42273, 21342, 34070, 1444, 27823);
UPDATE `creature_model_info` SET `BoundingRadius`=0.326728612184524536, `CombatReach`=0.550000011920928955, `VerifiedBuild`=45745 WHERE `DisplayID`=98847;
UPDATE `creature_model_info` SET `BoundingRadius`=0.681569099426269531, `CombatReach`=1.399999976158142089, `VerifiedBuild`=45745 WHERE `DisplayID`=913;

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (139088, 5504, 29152, 29288, 29296, 26548));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(139088, 1, 158900, 0, 0, 0, 0, 0, 155816, 1, 0, 45745), -- Boralus Guard
(29152, 1, 1902, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stormwind Dock Worker
(29288, 1, 1902, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Engineer Kurtis Paddock
(29296, 1, 1117, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Justin Boehm
(26548, 1, 2715, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Leesha Tannerby
(5504, 1, 12328, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- Sheldras Moontree

DELETE FROM `creature_template_addon` WHERE `entry` IN (139088, 141554, 151187 /*151187 - [DNT] Ship Blessing*/, 29296);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(141554, 0, 0, 0, 1, 0, 0, 0, 0, 0, '52455'), -- 141554 - PvP Vehicle Health Regen Suppression
(151187, 0, 0, 0, 1, 0, 0, 0, 0, 3, '292845'), -- 151187 - [DNT] Ship Blessing
(29296, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Justin Boehm
(139088, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 139088 (Boralus Guard)

UPDATE `creature_template_addon` SET `emote` = 455 WHERE `entry` = 44880;

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+26;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, 0, '244971'), -- 3469 - 244971 - Set Health (Random 15%-55%)
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+11, 0, 0, 0, 1, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+12, 0, 0, 0, 1, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+13, 0, 0, 0, 1, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+14, 0, 0, 0, 1, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+15, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Displaced Gilnean Refugee
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Displaced Gilnean Refugee
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Darnassian Refugee
(@CGUID+23, 0, 0, 0, 257, 716, 0, 0, 0, 0, ''), -- Boralus Guard
(@CGUID+24, 0, 0, 0, 257, 716, 0, 0, 0, 0, ''), -- Boralus Guard
(@CGUID+25, 0, 0, 0, 257, 716, 0, 0, 0, 0, ''), -- Boralus Guard
(@CGUID+26, 0, 0, 0, 257, 716, 0, 0, 0, 0, ''); -- Boralus Guard

UPDATE `creature_template` SET `subname` = '', `VerifiedBuild`=45745 WHERE `entry`=11397; -- Nara Meideros
UPDATE `creature_template` SET `subname` = '', `VerifiedBuild`=45745 WHERE `entry`=5504; -- Sheldras Moontree
UPDATE `creature_template` SET `subname` = '', `VerifiedBuild`=45745 WHERE `entry`=29299; -- Serban Oprescu
UPDATE `creature_template` SET `subname` = '', `VerifiedBuild`=45745 WHERE `entry`=29296; -- Justin Boehm
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=139088; -- Boralus Guard

DELETE FROM `creature_template_model` WHERE (`Idx`=0 AND `CreatureID` = 29296 ) OR (`Idx`=0 AND `CreatureID` = 151187 ) OR (`Idx`=1 AND `CreatureID` = 151187 ) OR (`Idx`=0 AND `CreatureID` = 29152 ) OR (`Idx`=1 AND `CreatureID` = 29152 ) OR (`Idx`=2 AND `CreatureID` = 29152 ) OR (`Idx`=0 AND `CreatureID` = 140403 ) OR (`Idx`=1 AND `CreatureID` = 140403 ) OR (`Idx`=2 AND `CreatureID` = 140403 ) OR (`Idx`=3 AND `CreatureID` = 140403 ) OR (`Idx`=4 AND `CreatureID` = 140403 ) OR (`Idx`=5 AND `CreatureID` = 140403 ) OR (`Idx`=6 AND `CreatureID` = 140403 ) OR (`Idx`=7 AND `CreatureID` = 140403 ) OR (`Idx`=8 AND `CreatureID` = 140403 ) OR (`Idx`=9 AND `CreatureID` = 140403 ) OR (`Idx`=10 AND `CreatureID` = 140403 ) OR (`Idx`=11 AND `CreatureID` = 140403 ) OR (`Idx`=12 AND `CreatureID` = 140403 ) OR (`Idx`=13 AND `CreatureID` = 140403 ) OR (`Idx`=14 AND `CreatureID` = 140403 ) OR (`Idx`=15 AND `CreatureID` = 140403 );
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(140403, 15, 37112, 1, 1, 45745), -- 140403
(140403, 14, 37111, 1, 1, 45745), -- 140403
(140403, 13, 37110, 1, 1, 45745), -- 140403
(140403, 12, 37109, 1, 1, 45745), -- 140403
(140403, 11, 37116, 1, 1, 45745), -- 140403
(140403, 10, 37115, 1, 1, 45745), -- 140403
(140403, 9, 37114, 1, 1, 45745), -- 140403
(140403, 8, 37113, 1, 1, 45745), -- 140403
(140403, 7, 37124, 1, 1, 45745), -- 140403
(140403, 6, 37123, 1, 1, 45745), -- 140403
(140403, 5, 37122, 1, 1, 45745), -- 140403
(140403, 4, 37121, 1, 1, 45745), -- 140403
(140403, 3, 37120, 1, 1, 45745), -- 140403
(140403, 2, 37119, 1, 1, 45745), -- 140403
(140403, 1, 37118, 1, 1, 45745), -- 140403
(140403, 0, 37117, 1, 1, 45745), -- 140403
(151187, 1, 11686, 1, 1, 45745), -- 151187
(151187, 0, 169, 0.150000005960464477, 0, 45745), -- 151187
(29296, 0, 26115, 1, 1, 45745), -- 29296
(29152, 2, 5003, 1, 1, 45745), -- 29152
(29152, 1, 5008, 1, 1, 45745), -- 29152
(29152, 0, 99501, 1, 1, 45745); -- 29152

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` = 151187) OR (`Entry`=185696 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES 
(151187, 0, 0, 0, 464, 45745),
(185696, 0, 0, 0, 2057, 45745);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 247015, 0, 1519, 4411, 0, 11595, 0, -8284.86328125, 1402.638916015625, 4.421866416931152343, 3.831023693084716796, 0, 0, -0.94117164611816406, 0.3379288911819458, 120, 255, 1, 45745), -- Luggage (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+1, 293894, 0, 1519, 4411, 0, 0, 0, -8645.388671875, 1308.27783203125, 5.233562946319580078, 0, 0, 0, 0, 1, 120, 255, 0, 45745), -- Portal to Darnassus (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+2, 292774, 0, 1519, 4411, 0, 11595, 0, -8597.248046875, 1259.4930419921875, 5.231070518493652343, 6.091175556182861328, 0, 0, -0.09585762023925781, 0.995395064353942871, 120, 255, 1, 45745), -- Sleeping Mat B (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+3, 292774, 0, 1519, 4411, 0, 11595, 0, -8597.1220703125, 1263.3785400390625, 5.230750083923339843, 5.688809871673583984, 0, 0, -0.2928323745727539, 0.956163763999938964, 120, 255, 1, 45745), -- Sleeping Mat B (Area: Stormwind Harbor - Difficulty: 0)
(@OGUID+4, 293696, 0, 1519, 4411, 0, 11595, 0, -8657.2470703125, 1262.4896240234375, 0, 2.02551126480102539, 0, 0, 0.848294258117675781, 0.529525160789489746, 120, 255, 1, 45745); -- Darnassian Ship (Area: Stormwind Harbor - Difficulty: 0)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (293894 /*293894*/, 293696 /*293696*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(293696, 0, 1048608, 0, 0), -- 293696
(293894, 35, 0, 0, 0); -- 293894

UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=203801; -- Sack of Confectioner's Sugar

-- Engineer Kurtis
SET @WGUID := 313488;
SET @PATH := @WGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8425.372, 1299.794, 20.86869, NULL, 0),
(@PATH, 1, -8419.859, 1298.597, 20.92038, 4.73377, 39917),
(@PATH, 2, -8425.742, 1310.585, 11.35291, NULL, 10310),
(@PATH, 3, -8421.018, 1318.639, 11.20441, NULL, 8340);

UPDATE `creature` SET `position_x`= -8425.372, `position_y`= 1299.794, `position_z`= 20.86869, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @WGUID;
DELETE FROM `creature_addon` WHERE `guid`= @WGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@WGUID, @PATH, 1);

 -- Engineer Kurtis Paddock smart ai
SET @ENTRY := 29288;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY*100;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 2928800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #2928800 (update out of combat)'),
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 10, 6, 396, 273, 374, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Play random emote: 6, 396, 273, 374,'),
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 10, 6, 396, 273, 374, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15 seconds - Self: Play random emote: 6, 396, 273, 374,'),
(@ENTRY*100, 9, 2, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 10, 6, 396, 273, 374, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15 seconds - Self: Play random emote: 6, 396, 273, 374,');

-- Justin Boehm
SET @WPGUID := 313499;
SET @PATH := @WPGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8407.187, 1319.194, 6.739105, NULL, 0),
(@PATH, 1, -8402.29, 1322.5, 6.753046, NULL, 59263),
(@PATH, 2, -8427.583, 1319.495, 9.85485, NULL, 0),
(@PATH, 3, -8432.926, 1319.452, 6.907104, NULL, 56771);

UPDATE `creature` SET `position_x`= -8407.187, `position_y`= 1319.194, `position_z`= 6.739105, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @WPGUID;
DELETE FROM `creature_addon` WHERE `guid`= @WPGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@WPGUID, @PATH, 1);

 -- Justin Boehm smart ai
SET @ENTRY := 29296;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY*100;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 1, 0, 0, 80, 2929600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #2929600 (update out of combat)'),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 3, 0, 0, 80, 2929600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 3 - Self: Start timed action list id #2929600 (update out of combat)'),
(@ENTRY*100, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Set emote state to 379'),
(@ENTRY*100, 9, 1, 0, 0, 0, 100, 0, 50000, 50000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 50 seconds - Self: Set emote state to 0');

 -- Darnassian Refugee & Displaced Gilnean Refugee smart ai
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+17), -(@CGUID+7), -(@CGUID+20), -(@CGUID+6), -(@CGUID+16), -(@CGUID+8));
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (140253, 140403);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+17), 0, 0, 0, 60, 0, 100, 0, 2000, 7000, 2000, 7000, 10, 603, 25, 1, 274, 6, 273, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 7 seconds - Self: Play random emote: 603, 25, 1, 274, 6, 273'),
(-(@CGUID+7), 0, 0, 0, 60, 0, 100, 0, 2000, 7000, 2000, 7000, 10, 603, 25, 1, 274, 6, 273, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 7 seconds - Self: Play random emote: 603, 25, 1, 274, 6, 273'),
(-(@CGUID+20), 0, 0, 0, 60, 0, 100, 0, 2000, 7000, 2000, 7000, 10, 603, 25, 1, 274, 6, 273, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 7 seconds - Self: Play random emote: 603, 25, 1, 274, 6, 273'),
(-(@CGUID+6), 0, 0, 0, 60, 0, 100, 0, 2000, 7000, 2000, 7000, 10, 603, 25, 1, 274, 6, 273, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 7 seconds - Self: Play random emote: 603, 25, 1, 274, 6, 273'),
(-(@CGUID+16), 0, 0, 0, 60, 0, 100, 0, 2000, 7000, 2000, 7000, 10, 603, 25, 1, 274, 6, 273, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 7 seconds - Self: Play random emote: 603, 25, 1, 274, 6, 273'),
(-(@CGUID+8), 0, 0, 0, 60, 0, 100, 0, 2000, 7000, 2000, 7000, 10, 603, 25, 1, 274, 6, 273, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 7 seconds - Self: Play random emote: 603, 25, 1, 274, 6, 273');

-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 1519 AND `PhaseId` = 11595;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 11595, 'Cosmetic - See Darnassian and Gilnean Refugee in Stormwind');

DELETE FROM `phase_name` WHERE `ID` = 11595;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(11595, 'Cosmetic - See Darnassian and Gilnean Refugees');

-- Condition
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 11595 AND `SourceEntry` = 1519);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 11595, 1519, 0, 0, 27, 0, 50, 3, 0, 0, 'Apply Phase 11585 If Player Level is equal or higher then 50');
