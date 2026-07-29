-- Duskwood Fixes

-- Creature Spawns
SET @CGUID := 900000;
DELETE FROM `creature` WHERE `guid` = @CGUID+1246;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `phaseId`, `phaseGroup`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`) VALUES
-- Marus <The Pack Leader>
(@CGUID+1246, 45771, 0, 10, 241, 0, 0, 0, 0, 1, -11065.4, -778.968, 63.8591, 5.47845, 3600);

-- Creature Spawn Fixes
UPDATE creature
SET MovementType = 1,
    wander_distance = 8
WHERE id IN (
    889,212,628,44016,44020,210,604,948,43923,45614,
    43732,44089,44087,533,202,930,898,205,45517,217,
    48,203,206,920,3
);

-- Paths
DELETE FROM creature_template_addon WHERE Entry IN (45771);
INSERT INTO creature_template_addon (Entry, PathId) VALUES 
(45771, 4577101);
UPDATE creature SET MovementType = 2 WHERE id = 45771;

DELETE FROM waypoint_path WHERE PathId IN (4577101);
INSERT INTO waypoint_path (PathId, MoveType, Flags, Comment) VALUES (4577101, 0, 0, 'Duskwood - Marus <The Pack Leader>');

DELETE FROM waypoint_path_node WHERE PathId = 4577101;
INSERT INTO waypoint_path_node (PathId, NodeId, PositionX, PositionY, PositionZ, Orientation, Delay) VALUES
    (4577101, 1, -11212.7578, -869.8420, 78.6774, 0.7441, 0),
    (4577101, 2, -11197.7373, -856.0145, 79.3106, 0.7441, 0),
    (4577101, 3, -11188.4199, -844.9769, 77.0433, 1.0857, 0),
    (4577101, 4, -11179.8877, -821.7850, 76.3989, 1.2436, 0),
    (4577101, 5, -11170.9932, -803.4672, 71.9406, 0.9255, 0),
    (4577101, 6, -11162.1895, -786.4006, 68.8541, 1.1588, 0),
    (4577101, 7, -11161.0225, -770.9642, 67.0287, 1.8656, 0),
    (4577101, 8, -11162.0195, -753.0448, 61.2779, 1.0834, 0),
    (4577101, 9, -11158.2949, -738.2658, 60.2859, 1.1242, 0);
