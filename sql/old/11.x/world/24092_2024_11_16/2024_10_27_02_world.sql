-- Update staticflags
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=57212 WHERE (`Entry`=8198 AND `DifficultyID`=0); -- 8198 (Tick) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=57212 WHERE (`Entry`=8197 AND `DifficultyID`=0); -- 8197 (Chronalis) - Floating

-- Path for Tick
SET @MOVERGUID := 272721;
SET @ENTRY := 8198;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 6.7100, 'Tick - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8162.9233, -4600.0493, 41.603638, NULL, 0),
(@PATH, 1, -8176.898, -4613.6626, 41.603638, NULL, 0),
(@PATH, 2, -8195.019, -4620.8916, 41.603638, NULL, 0),
(@PATH, 3, -8214.525, -4620.636, 41.603638, NULL, 0),
(@PATH, 4, -8232.45, -4612.935, 41.603638, NULL, 0),
(@PATH, 5, -8246.063, -4598.961, 41.603638, NULL, 0),
(@PATH, 6, -8253.293, -4580.841, 41.603638, NULL, 0),
(@PATH, 7, -8253.037, -4561.3335, 41.603638, NULL, 0),
(@PATH, 8, -8245.336, -4543.4087, 41.603638, NULL, 0),
(@PATH, 9, -8231.361, -4529.7954, 41.603638, NULL, 0),
(@PATH, 10, -8213.241, -4522.5664, 41.603638, NULL, 0),
(@PATH, 11, -8193.734, -4522.822, 41.603638, NULL, 0),
(@PATH, 12, -8175.8096, -4530.523, 41.603638, NULL, 0),
(@PATH, 13, -8162.1963, -4544.497, 41.603638, NULL, 0),
(@PATH, 14, -8154.9673, -4562.617, 41.603638, NULL, 0),
(@PATH, 15, -8155.2227, -4582.1245, 41.603638, NULL, 0);

UPDATE `creature` SET `position_x`=-8162.9233, `position_y`=-4600.0493, `position_z`=41.603638, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 3, 1, 3);

-- Path for Chronalis
SET @MOVERGUID := 272720;
SET @ENTRY := 8197;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.9485, 'Chronalis - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -8247.571, -4570.8335, 56.85348, NULL, 0),
(@PATH, 1, -8236.452, -4554.804, 56.85348, NULL, 0),
(@PATH, 2, -8220.044, -4544.25, 56.85348, NULL, 0),
(@PATH, 3, -8200.846, -4540.779, 56.85348, NULL, 0),
(@PATH, 4, -8181.7812, -4544.918, 56.85348, NULL, 0),
(@PATH, 5, -8165.752, -4556.038, 56.85348, NULL, 0),
(@PATH, 6, -8155.1978, -4572.446, 56.85348, NULL, 0),
(@PATH, 7, -8151.7266, -4591.6436, 56.85348, NULL, 0),
(@PATH, 8, -8155.8657, -4610.7085, 56.85348, NULL, 0),
(@PATH, 9, -8166.986, -4626.738, 56.85348, NULL, 0),
(@PATH, 10, -8183.3936, -4637.292, 56.85348, NULL, 0),
(@PATH, 11, -8202.592, -4640.763, 56.85348, NULL, 0),
(@PATH, 12, -8221.656, -4636.624, 56.85348, NULL, 0),
(@PATH, 13, -8237.686, -4625.504, 56.85348, NULL, 0),
(@PATH, 14, -8248.239, -4609.096, 56.85348, NULL, 0),
(@PATH, 15, -8251.711, -4589.8984, 56.85348, NULL, 0);

UPDATE `creature` SET `position_x`=-8247.571, `position_y`=-4570.8335, `position_z`=56.85348, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 3, 1, 3);
