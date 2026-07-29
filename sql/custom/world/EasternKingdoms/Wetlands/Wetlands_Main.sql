-- Wetlands Fixes

-- Template Fixes
UPDATE creature_template SET unit_flags = 0 WHERE entry = 41400;
UPDATE creature_template SET unit_flags = unit_flags | 0x40000000 WHERE Entry IN (41400,41401,41419);

-- Creature Addon
DELETE FROM creature_addon WHERE guid IN (260945,261089);
INSERT INTO creature_addon (guid, emote) VALUES (260945, 1083);
INSERT INTO creature_addon (guid, emote) VALUES (261089, 1083);

-- Creature Spawn fixes
UPDATE creature SET MovementType = 1, wander_distance = 8
WHERE id IN (
    44116,41293,41343,41426,1259,41425,41419,41400,41496,41390,41391,41409,
    1032,41424,41449,41453,42043,42042,42041,41132,41137,1111,41145, 
    1036,1038,1034,1057,1035,41389,41388
);

-- Creature Path
DELETE FROM creature_addon WHERE guid = 261099;
INSERT INTO creature_addon (guid, PathId) VALUES (261099, 1299601);
UPDATE creature SET MovementType = 2 WHERE guid = 261099;

DELETE FROM waypoint_path WHERE PathId = 1299601;
INSERT INTO waypoint_path (PathId, MoveType, Flags, Comment) VALUES (1299601, 0, 0, 'Wetlands - Mounted Ironforge Mountaineer');

DELETE FROM waypoint_path_node WHERE PathId = 1299601;
INSERT INTO waypoint_path_node (PathId, NodeId, PositionX, PositionY, PositionZ, Orientation, Delay) VALUES
    (1299601, 1, -4028.7905, -1411.2633, 156.5579, 2.5225, 0),
    (1299601, 2, -4075.9536, -1408.3340, 166.3823, 3.0158, 0),
    (1299601, 3, -4117.6196, -1393.1384, 184.8659, 2.8485, 0),
    (1299601, 4, -4139.4302, -1392.8037, 194.4540, 3.3743, 0),
    (1299601, 5, -4161.4507, -1400.1250, 199.0838, 3.2010, 0),
    (1299601, 6, -4143.3887, -1395.0869, 195.7237, 0.3052, 0),
    (1299601, 7, -4116.1475, -1392.9248, 184.1326, 6.0734, 0),
    (1299601, 8, -4073.1619, -1407.5011, 165.3815, 0.0135, 0),
    (1299601, 9, -4029.1311, -1410.3866, 156.4790, 6.2734, 0);
