SET @CGUID := 397104;

-- Update Creature pos.
UPDATE `creature` SET `position_x`= -8057.32666015625, `position_y` = 824.1492919921875, `position_z` = 67.3905029296875, `orientation`= 4.488709449768066406, `wander_distance` = 3 WHERE `guid` = 314390; -- Farmer Wollerton
UPDATE `creature` SET `position_x`= -8028.45556640625, `position_y` = 821.25128173828125, `position_z` = 68.54727935791015625, `orientation`= 0.633559226989746093, `wander_distance` = 3 WHERE `guid` = 314388; -- Cow
UPDATE `creature` SET `position_x`= -8060.20654296875, `position_y` = 829.30035400390625, `position_z` = 67.76078033447265625, `orientation`= 3.525565147399902343, `wander_distance` = 3 WHERE `guid` = 314387; -- Cow
UPDATE `creature` SET `position_x`= -8058.50830078125, `position_y` = 851.662353515625, `position_z` = 68.7268218994140625, `orientation`= 2.638152122497558593, `wander_distance` = 3 WHERE `guid` = 314386; -- Cow
UPDATE `creature` SET `position_x`= -8062.5048828125, `position_y` = 876.6343994140625, `position_z` = 68.29483795166015625, `orientation`= 4.69222116470336914, `wander_distance` = 3 WHERE `guid` = 314381; -- Cow
UPDATE `creature` SET `position_x`= -8025.36962890625, `position_y` = 810.4305419921875, `position_z` = 68.392181396484375, `orientation`= 3.159045934677124023, `wander_distance` = 3 WHERE `guid` = 314382; -- Cow

DELETE FROM `creature` WHERE `guid` = @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 2442, 0, 1519, 5397, '0', 0, 0, 0, 0, -8023.63330078125, 790.031005859375, 67.6014556884765625, 2.266803741455078125, 120, 3, 0, 1, 0, 1, 0, 0, 50504); -- Cow (Area: The Wollerton Stead - Difficulty: 0) CreateObject1

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` = 44807;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(44807, 0, 0, 0, 0, 0, 1, 1, 415, 0, 0, 0, 0, ''); -- Farmer Wollerton

-- Delete old GameObjects
DELETE FROM `gameobject` WHERE `guid` IN (220373, 220375);
