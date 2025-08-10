SET @CGUID := 5000026;
SET @OGUID := 5000031;

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 81695, 1265, 7025, 7037, '0', 3763, 0, 0, 0, 4167.15478515625, -2268.663330078125, 64.09075927734375, 4.695687770843505859, 120, 0, 0, 52000, 16679, 0, NULL, NULL, 50791), -- Cho'gall (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166539 - Fel Prison)
(@CGUID+1, 81696, 1265, 7025, 7037, '0', 3764, 0, 0, 0, 3964.171142578125, -2271.989501953125, 64.63409423828125, 4.712769985198974609, 120, 0, 0, 3200, 3191, 0, NULL, NULL, 50791); -- Teron'gor (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 166539 - Fel Prison)

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 233906, 1265, 7025, 7037, '0', 3946, 0, 4067.341064453125, -2431.785400390625, 129.8704376220703125, 1.579530119895935058, 0, 0, 0.710187911987304687, 0.704012155532836914, 120, 255, 1, 50791), -- Doodad_6TJ_DarkPortal_FX_Wrap001 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+1, 234622, 1265, 7025, 7037, '0', 3947, 0, 4067.34033203125, -2431.7900390625, 129.8699951171875, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 120, 255, 1, 50791), -- Dark Portal Door (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+2, 234623, 1265, 7025, 7037, '0', 3948, 0, 4067.34033203125, -2431.7900390625, 129.8699951171875, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 120, 255, 1, 50791), -- Dark Portal Door (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+3, 236690, 1265, 7025, 7037, '0', 4142, 0, 4066.552490234375, -2371.4560546875, 94.5568695068359375, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 50791), -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Right001 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+4, 236691, 1265, 7025, 7037, '0', 4143, 0, 4066.552490234375, -2371.4560546875, 94.5568695068359375, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 50791), -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Left001 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+5, 236913, 1265, 7025, 7037, '0', 4150, 0, 4066.55029296875, -2371.460205078125, 94.5569000244140625, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 50791), -- Soul Crystal R (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+6, 236914, 1265, 7025, 7037, '0', 4151, 0, 4066.55029296875, -2371.460205078125, 94.5569000244140625, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 50791), -- Soul Crystal L (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+7, 233057, 1265, 7025, 7037, '0', 3764, 0, 3964.796142578125, -2283.616455078125, 59.87628173828125, 4.719363689422607421, 0, 0, -0.7046365737915039, 0.709568381309509277, 120, 255, 1, 50791), -- Mark of the Bleeding Hollow (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+8, 233056, 1265, 7025, 7037, '0', 3763, 0, 4167.3662109375, -2281.59375, 59.876708984375, 4.756856441497802734, 0, 0, -0.69121170043945312, 0.722652316093444824, 120, 255, 1, 50791), -- Mark of the Shadowmoon (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+9, 237667, 1265, 7025, 7044, '0', 4201, 0, 4064.077392578125, -2338.022705078125, 129.8704376220703125, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 50791), -- Dark Portal (Area: The Path of Glory - Difficulty: 0) CreateObject1
(@OGUID+10, 229598, 1265, 7025, 7037, '0', 3248, 0, 4099.78125, -2402.88720703125, 69.81522369384765625, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 50791), -- Mark of the Burning Blade (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+11, 229599, 1265, 7025, 7037, '0', 3249, 0, 4067.1728515625, -2435.338623046875, 69.09592437744140625, 1.620948672294616699, 0, 0, 0.724614143371582031, 0.689154803752899169, 120, 255, 1, 50791), -- Mark of the Shattered Hand (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+12, 229600, 1265, 7025, 7037, '0', 3250, 0, 4033.49658203125, -2403.375, 69.8154754638671875, 6.269019603729248046, 0, 0, -0.00708293914794921, 0.99997490644454956, 120, 255, 1, 50791), -- Mark of the Blackrock (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+13, 233614, 1265, 7025, 7037, '0', 3880, 0, 3964.389892578125, -2311.460205078125, 63.83720016479492187, 4.711029052734375, -0.24200916290283203, -0.24167919158935546, -0.66491508483886718, 0.664011061191558837, 120, 255, 1, 50791), -- Chamber Door (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+14, 233614, 1265, 7025, 7037, '0', 3880, 0, 4167.580078125, -2309.510498046875, 63.83720016479492187, 4.671691417694091796, -0.24671554565429687, -0.23687267303466796, -0.67784595489501953, 0.650805354118347167, 120, 255, 1, 50791); -- Chamber Door (Area: The Dark Portal - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+14;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.999990463256835937, -0.0043673813343048, 0, 1483), -- Doodad_6TJ_DarkPortal_FX_Wrap001
(@OGUID+3, 0, 0, 0.999990463256835937, -0.0043673813343048, 0, 0), -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Right001
(@OGUID+4, 0, 0, 0.999990463256835937, -0.0043673813343048, 0, 0), -- Doodad_6TJ_DARKPORTAL_Souls_FXWRAP_Left001
(@OGUID+5, 0, 0, 0, 1, 0, 7254), -- Soul Crystal R
(@OGUID+6, 0, 0, 0, 1, 0, 7254), -- Soul Crystal L
(@OGUID+9, 0, 0, 0, 1, 0, 0); -- Dark Portal

-- GameObject Template
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry` IN (234623, 234622); -- Dark Portal Door
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32, `AIAnimKitID`=1483 WHERE `entry`=233906; -- Doodad_6TJ_DarkPortal_FX_Wrap001
UPDATE `gameobject_template_addon` SET `flags`=32, `AIAnimKitID`=7254 WHERE `entry`=236914; -- Soul Crystal L
UPDATE `gameobject_template_addon` SET `flags`=32, `AIAnimKitID`=7254 WHERE `entry`=236913; -- Soul Crystal R
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=233057; -- Mark of the Bleeding Hollow
UPDATE `gameobject_template_addon` SET `faction`=35 WHERE `entry`=233056; -- Mark of the Shadowmoon

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (81695 /*81695 (Cho'gall) - Fel Prison*/, 81696 /*81696 (Teron'gor) - Fel Prison*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(81695, 0, 0, 0, 3, 0, 1, 0, 0, 6591, 0, 0, 0, '166539'), -- 81695 (Cho'gall) - Fel Prison
(81696, 0, 0, 0, 3, 0, 1, 0, 0, 6592, 0, 0, 0, '166539'); -- 81696 (Teron'gor) - Fel Prison

-- Creature Movement data
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (81695, 81696);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(81695, 0, 0, 1, 0, 0, 0, NULL),
(81696, 0, 0, 1, 0, 0, 0, NULL);

-- Areatrigger
DELETE FROM `areatrigger_template` WHERE (`Id`=7371 AND `IsServerSide`=0);
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(7371, 0, 0, 4, 5, 5, 0, 0, 0, 0, 0, 0, 50791);

DELETE FROM `areatrigger_create_properties` WHERE `Id`=2757;
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(2757, 7371, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 50791); -- Spell: 166539 (Fel Prison)

-- Quest
UPDATE `quest_poi` SET `VerifiedBuild`=50791 WHERE (`QuestID`=34392 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=34392 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=34392 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=34392 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=50791 WHERE (`QuestID`=34392 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=34392 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=34392 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=34392 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=50791 WHERE `ID`=34392;
UPDATE `creature_queststarter` SET `VerifiedBuild`=50791 WHERE (`id`=78558 AND `quest`=34392);

-- Phases
DELETE FROM `phase_name` WHERE `ID` IN (3946, 3947, 3948, 4142, 4143, 4150, 4151, 3763, 3764);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(3946, 'Cosmetic - Dark Portal State - (Both Spires enabled)'),
(3947, 'Cosmetic - Dark Portal State - (One Spire enabled)'),
(3948, 'Cosmetic - Dark Portal State - (Spires disabled)'),
(4142, 'Cosmetic - Northern Fel Spire enabled'),
(4143, 'Cosmetic - Southern Fel Spire enabled'),
(4150, 'Cosmetic - Northern Fel Spire disabled'),
(4151, 'Cosmetic - Southern Fel Spire disabled'),
(3763, 'Cosmetic - Cho\'gall in Fel Prison'),
(3764, 'Cosmetic - Teron\'gor in Fel Prison');

DELETE FROM `phase_area` WHERE `AreaId` IN (7025, 7037) AND `PhaseId` IN (3946, 3947, 3948, 4142, 4143, 4150, 4151, 3763, 3764);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7025, 3946, 'See Dark Portal opened (Assault on the Dark Portal)'),
(7025, 3947, 'See Dark Portal half opened (Assault on the Dark Portal)'),
(7025, 3948, 'See Dark Portal almost closed (Assault on the Dark Portal)'),
(7025, 4142, 'See Northern Fel Spire enabled (Assault on the Dark Portal)'),
(7025, 4143, 'See Southern Fel Spire enabled (Assault on the Dark Portal)'),
(7025, 4150, 'See Northern Fel Spire disabled (Assault on the Dark Portal)'),
(7025, 4151, 'See Southern Fel Spire disabled (Assault on the Dark Portal)'),
(7037, 3763, 'See Cho\'gall in Fel Prison (Assault on the Dark Portal)'),
(7037, 3764, 'See Teron\'gor in Fel Prison (Assault on the Dark Portal)');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3946 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3946, 0, 0, 0, 47, 0, 34392, 2 | 64, 0, 1, 'Apply Phase 3946 if Quest 34392 is not complete | rewarded'),
(26, 3946, 0, 0, 0, 48, 0, 272621, 0, 1, 1, 'Apply Phase 3946 if QuestObjective 272621 is not complete'),
(26, 3946, 0, 0, 0, 48, 0, 273946, 0, 1, 1, 'Apply Phase 3946 if QuestObjective 273946 is not complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3947 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3947, 0, 0, 0, 47, 0, 34392, 8, 0, 0, 'Apply Phase 3947 if Quest 34392 is in progress'),
(26, 3947, 0, 0, 0, 48, 0, 272621, 0, 1, 0, 'Apply Phase 3947 if QuestObjective 272621 is not complete'),
(26, 3947, 0, 0, 0, 48, 0, 273946, 0, 1, 1, 'Apply Phase 3947 if QuestObjective 273946 is complete'),
(26, 3947, 0, 0, 1, 48, 0, 272621, 0, 1, 1, 'Apply Phase 3947 if QuestObjective 272621 is complete'),
(26, 3947, 0, 0, 1, 48, 0, 273946, 0, 1, 0, 'Apply Phase 3947 if QuestObjective 273946 is not complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3948 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3948, 0, 0, 0, 47, 0, 34392, 2 | 64, 0, 0, 'Apply Phase 3948 if Quest 34392 is complete | rewarded'),
(26, 3948, 0, 0, 0, 47, 0, 34393, 2 | 64, 0, 1, 'Apply Phase 3948 if Quest 34393 is not complete | rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4142 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4142, 0, 0, 0, 47, 0, 34392, 2 | 64, 0, 1, 'Apply Phase 4142 if Quest 34392 is not complete | rewarded'),
(26, 4142, 0, 0, 0, 48, 0, 272621, 0, 1, 1, 'Apply Phase 4142 if QuestObjective 272621 is not complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4143 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4143, 0, 0, 0, 47, 0, 34392, 2 | 64, 0, 1, 'Apply Phase 4143 if Quest 34392 is not complete | rewarded'),
(26, 4143, 0, 0, 0, 48, 0, 273946, 0, 1, 1, 'Apply Phase 4143 if QuestObjective 273946 is not complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4150 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4150, 0, 0, 0, 47, 0, 34392, 2 | 8 | 64, 0, 0, 'Apply Phase 4150 if Quest 34392 is in progress | complete | rewarded'),
(26, 4150, 0, 0, 0, 48, 0, 272621, 0, 1, 0, 'Apply Phase 4150 if QuestObjective 272621 is complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4151 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4151, 0, 0, 0, 47, 0, 34392, 2 | 8 | 64, 0, 0, 'Apply Phase 4151 if Quest 34392 is in progress | complete | rewarded'),
(26, 4151, 0, 0, 0, 48, 0, 273946, 0, 1, 0, 'Apply Phase 4151 if QuestObjective 273946 is complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3763 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3763, 0, 0, 0, 47, 0, 34392, 2 | 64, 0, 1, 'Apply Phase 3763 if Quest 34392 is not in progress | complete | rewarded'),
(26, 3763, 0, 0, 0, 48, 0, 272621, 0, 1, 1, 'Apply Phase 3763 if QuestObjective 272621 is not complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3764 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3764, 0, 0, 0, 47, 0, 34392, 2 | 64, 0, 1, 'Apply Phase 3764 if Quest 34392 is not in progress | complete | rewarded'),
(26, 3764, 0, 0, 0, 48, 0, 273946, 0, 1, 1, 'Apply Phase 3764 if QuestObjective 273946 is not complete');
