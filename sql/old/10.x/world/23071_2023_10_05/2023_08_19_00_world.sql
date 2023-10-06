SET @CGUID := 5000000;
SET @OGUID := 5000000;

-- Creatures
DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 78333, 1265, 7025, 7037, '0', 3251, 0, 0, 0, 4066.786376953125, -2402.717041015625, 78.10951995849609375, 1.470552325248718261, 120, 0, 0, 51200, 51056, 0, 0, 0, 50791); -- Gul'dan (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 178274 - Gul'dan SFX)

DELETE FROM `creature_template_addon` WHERE `entry` = 78333;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(78333, 0, 0, 0, 0, 0, 1, 0, 416, 0, 0, 0, 0, '178274'); -- 78333 (Gul'dan) - Gul'dan SFX

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 237670, 1265, 7025, 7037, '0', 4200, 0, 4064.077392578125, -2338.022705078125, 129.8704376220703125, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 50791), -- Dark Portal (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+1, 237667, 1265, 7025, 7044, '0', 4201, 0, 4064.077392578125, -2338.022705078125, 129.8704376220703125, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 50791), -- Dark Portal (Area: The Path of Glory - Difficulty: 0) CreateObject1
(@OGUID+2, 229598, 1265, 7025, 7037, '0', 3248, 0, 4099.78125, -2402.88720703125, 69.81522369384765625, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 120, 255, 1, 50791), -- Mark of the Burning Blade (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+3, 229599, 1265, 7025, 7037, '0', 3249, 0, 4067.1728515625, -2435.338623046875, 69.09592437744140625, 1.620948672294616699, 0, 0, 0.724614143371582031, 0.689154803752899169, 120, 255, 1, 50791), -- Mark of the Shattered Hand (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+4, 229600, 1265, 7025, 7037, '0', 3250, 0, 4033.49658203125, -2403.375, 69.8154754638671875, 6.269019603729248046, 0, 0, -0.00708293914794921, 0.99997490644454956, 120, 255, 1, 50791); -- Mark of the Blackrock (Area: The Dark Portal - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 0, 0), -- Dark Portal
(@OGUID+1, 0, 0, 0, 1, 0, 0); -- Dark Portal

UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=229600; -- Mark of the Blackrock
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=229599; -- Mark of the Shattered Hand
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=229598; -- Mark of the Burning Blade
UPDATE `gameobject_template_addon` SET `flags`=1048608 WHERE `entry` IN (237667, 237670); -- Dark Portal

-- Spell Area
DELETE FROM `spell_area` WHERE `spell`=163341 AND `area`=7037;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(163341, 7037, 0, 34393, 0, 0, 2, 3, 0, 11);

-- Phases
DELETE FROM `phase_name` WHERE `ID`IN (4200, 4201);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(4200, 'Cosmetic - Dark Portal Intact'),
(4201, 'Cosmetic - Dark Portal Destroyed');

DELETE FROM `phase_area` WHERE `AreaId` IN (7025, 7037) AND `PhaseId`IN (4200, 4201, 3248, 3249, 3250, 3251);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7025, 4200, 'Dark Portal Intact on Tanaan Jungle (Assault on the Dark Portal)'),
(7025, 4201, 'Dark Portal Destroyed on Tanaan Jungle (Assault on the Dark Portal)'),
(7037, 3248, 'Ganahma\'s Barb under the Dark Portal (Assault on the Dark Portal)'),
(7037, 3249, 'Rune of the Felbreakers under the Dark Portal (Assault on the Dark Portal)'),
(7037, 3250, 'Horn of Kairozdormu under the Dark Portal (Assault on the Dark Portal)'),
(7037, 3251, 'Gul\'Dan under the Dark Portal (Assault on the Dark Portal)');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3248 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3248, 0, 0, 0, 47, 0, 34393, 2 | 64, 0, 1, 'Apply Phase 3248 if Quest 34393 is not complete | rewarded'),
(26, 3248, 0, 0, 0, 48, 0, 273438, 0, 1, 1, 'Apply Phase 3248 if QuestObjective 273438 is not complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3249 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3249, 0, 0, 0, 47, 0, 34393, 2 | 64, 0, 1, 'Apply Phase 3249 if Quest 34393 is not complete | rewarded'),
(26, 3249, 0, 0, 0, 48, 0, 273556, 0, 1, 1, 'Apply Phase 3249 if QuestObjective 273556 is not complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3250 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3250, 0, 0, 0, 47, 0, 34393, 2 | 64, 0, 1, 'Apply Phase 3250 if Quest 34393 is not complete | rewarded'),
(26, 3250, 0, 0, 0, 48, 0, 273557, 0, 1, 1, 'Apply Phase 3250 if QuestObjective 273557 is not complete');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3251 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3251, 0, 0, 0, 47, 0, 34393, 2 | 64, 0, 1, 'Apply Phase 3251 if Quest 34393 is not complete | rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4200 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4200, 0, 0, 0, 47, 0, 34445, 2 | 64, 0, 1, 'Apply Phase 4200 if Quest 34445 is not complete | rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4201 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4201, 0, 0, 0, 47, 0, 34445, 2 | 64, 0, 0, 'Apply Phase 4201 if Quest 34445 is complete | rewarded');
