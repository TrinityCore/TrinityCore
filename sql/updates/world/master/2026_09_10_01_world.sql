-- Template
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857193946838378, `unit_flags2`=0x800 WHERE `entry` IN (53648, 53102); -- Inferno Hawk
UPDATE `creature_template` SET `speed_walk`=1, `unit_flags2`=0x800 WHERE `entry`=53115; -- Molten Lord
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=53185; -- Flamewaker Overseer
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=53119; -- Flamewaker Forward Guard
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=53120; -- Flamewaker Pathfinder
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry` IN (53639, 53121); -- Flamewaker Cauterizer

-- Template Addon
UPDATE `creature_template_addon` SET `visibilityDistanceType`=3 WHERE `entry`=53185; -- 53185 (Flamewaker Overseer)

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=69587 WHERE (`Entry`=53102 AND `DifficultyID`=14); -- 53102 (Inferno Hawk) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `StaticFlags4`=0x2000000, `VerifiedBuild`=69587 WHERE (`Entry`=53185 AND `DifficultyID`=14); -- 53185 (Flamewaker Overseer) - HideInCombatLog
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `StaticFlags4`=0x2000000, `VerifiedBuild`=69587 WHERE (`Entry`=53119 AND `DifficultyID`=14); -- 53119 (Flamewaker Forward Guard) - HideInCombatLog
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `StaticFlags4`=0x2000000, `VerifiedBuild`=69587 WHERE (`Entry`=53120 AND `DifficultyID`=14); -- 53120 (Flamewaker Pathfinder) - HideInCombatLog
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `StaticFlags4`=0x2000000, `VerifiedBuild`=69587 WHERE (`Entry`=53121 AND `DifficultyID`=14); -- 53121 (Flamewaker Cauterizer) - HideInCombatLog

-- Update static Inferno Hawk
DELETE FROM `creature_addon` WHERE `guid` = 338952;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(338952, 0, 0, 0, 3, 0, 1, 0, 0, 1370, 0, 0, 4, '100712'); -- Inferno Hawk - 100712 - Fire Hawk Smoke Cosmetic

-- Path for Inferno Hawk
SET @MOVERGUID := 291069;
SET @ENTRY := 53102;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 16.6634, 'Inferno Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -187.58507, 69.85764, 108.72202, NULL, 0),
(@PATH, 1, -123.41493, 56.789932, 103.73234, NULL, 0),
(@PATH, 2, -31.809029, 71.27952, 94.00635, NULL, 0),
(@PATH, 3, 16.989584, 144.96529, 87.82775, NULL, 0),
(@PATH, 4, -8.736112, 202.73611, 83.17997, NULL, 0),
(@PATH, 5, -154.40973, 229.63889, 91.23218, NULL, 0),
(@PATH, 6, -199.87674, 179.47223, 92.43323, NULL, 0),
(@PATH, 7, -251.21701, 127.33681, 101.27931, NULL, 0),
(@PATH, 8, -352.75174, 96.45139, 111.51559, NULL, 0),
(@PATH, 9, -423.03473, 42.828125, 114.04733, NULL, 0),
(@PATH, 10, -434.5764, -34.421875, 76.9772, NULL, 0),
(@PATH, 11, -383.34723, -99.28993, 83.18089, NULL, 0),
(@PATH, 12, -304.93057, -114.51736, 84.19317, NULL, 0),
(@PATH, 13, -232.88542, -90.885414, 86.93888, NULL, 0),
(@PATH, 14, -224.79861, -27.65625, 92.15595, NULL, 0),
(@PATH, 15, -237.92708, 16.69618, 98.831276, NULL, 0),
(@PATH, 16, -237.09895, 42.321182, 101.04194, NULL, 0),
(@PATH, 17, -228.8802, 70.06771, 96.63481, NULL, 0);

UPDATE `creature` SET `position_x`=-187.58507, `position_y`=69.85764, `position_z`=108.72202, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, '100712'); -- Inferno Hawk - 100712 - Fire Hawk Smoke Cosmetic

-- Path for Inferno Hawk
SET @MOVERGUID := 317639;
SET @ENTRY := 53102;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 17.6096, 'Inferno Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -379.54514, 14.345487, 93.36171, NULL, 0),
(@PATH, 1, -435.27258, 82.52604, 86.383026, NULL, 0),
(@PATH, 2, -417.97916, 179.56944, 94.782555, NULL, 0),
(@PATH, 3, -311.4462, 208.6007, 98.90543, NULL, 0),
(@PATH, 4, -240.99306, 216.14236, 101.02347, NULL, 0),
(@PATH, 5, -181.5868, 161.6632, 104.66615, NULL, 0),
(@PATH, 6, -154.90625, 109.53646, 105.26603, NULL, 0),
(@PATH, 7, -128.81944, 18.371529, 101.2021, NULL, 0),
(@PATH, 8, -183.375, -65.33854, 104.22858, NULL, 0),
(@PATH, 9, -285.14062, -70.15278, 104.78761, NULL, 0),
(@PATH, 10, -309.02432, 0.5069445, 87.620255, NULL, 0);

UPDATE `creature` SET `position_x`=-379.54514, `position_y`=14.345487, `position_z`=93.36171, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, '100712'); -- Inferno Hawk - 100712 - Fire Hawk Smoke Cosmetic

-- Path for Inferno Hawk
SET @MOVERGUID := 338765;
SET @ENTRY := 53102;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.0481, 'Inferno Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -370.74655, 87.586815, 253.17334, NULL, 0),
(@PATH, 1, -346.4148, 103.84477, 253.17334, NULL, 0),
(@PATH, 2, -317.71356, 109.55382, 253.17334, NULL, 0),
(@PATH, 3, -289.01227, 103.84479, 253.17334, NULL, 0),
(@PATH, 4, -264.68054, 87.58684, 253.17334, NULL, 0),
(@PATH, 5, -248.42256, 63.25508, 253.17334, NULL, 0),
(@PATH, 6, -242.71353, 34.553825, 253.17334, NULL, 0),
(@PATH, 7, -248.42256, 5.8525677, 253.17334, NULL, 0),
(@PATH, 8, -264.68054, -18.479187, 253.17334, NULL, 0),
(@PATH, 9, -289.01227, -34.73714, 253.17334, NULL, 0),
(@PATH, 10, -317.71353, -40.44618, 253.17334, NULL, 0),
(@PATH, 11, -346.4148, -34.73714, 253.17334, NULL, 0),
(@PATH, 12, -370.74655, -18.479187, 253.17334, NULL, 0),
(@PATH, 13, -387.0045, 5.85256, 253.17334, NULL, 0),
(@PATH, 14, -392.71353, 34.55381, 253.17334, NULL, 0),
(@PATH, 15, -387.00452, 63.255066, 253.17334, NULL, 0);

UPDATE `creature` SET `position_x`=-370.74655, `position_y`=87.586815, `position_z`=253.17334, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, '100712'); -- Inferno Hawk - 100712 - Fire Hawk Smoke Cosmetic

-- Path for Inferno Hawk
SET @MOVERGUID := 338775;
SET @ENTRY := 53102;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 16.4846, 'Inferno Hawk - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -290.71008, 242.69098, 150.3136, NULL, 0),
(@PATH, 1, -340.41495, 212.16841, 150.3136, NULL, 0),
(@PATH, 2, -407.93576, 179.28645, 150.3136, NULL, 0),
(@PATH, 3, -437.7639, 129.31598, 150.3136, NULL, 0),
(@PATH, 4, -438.2587, 62.807293, 150.3136, NULL, 0),
(@PATH, 5, -450.50522, 0.9826389, 150.3136, NULL, 0),
(@PATH, 6, -351.14236, -123.26389, 150.3136, NULL, 0),
(@PATH, 7, -232.70139, -155.29861, 150.3136, NULL, 0),
(@PATH, 8, -121.59375, -101.25694, 150.3136, NULL, 0),
(@PATH, 9, -14.28993, 0.7013889, 150.3136, NULL, 0),
(@PATH, 10, -21.034723, 107.16146, 150.3136, NULL, 0),
(@PATH, 11, -14.145833, 200.58855, 150.3136, NULL, 0),
(@PATH, 12, -138.92014, 214.69792, 150.3136, NULL, 0),
(@PATH, 13, -226.5382, 276.592, 150.3136, NULL, 0),
(@PATH, 14, -247.55904, 262.90277, 150.3136, NULL, 0);

UPDATE `creature` SET `position_x`=-290.71008, `position_y`=242.69098, `position_z`=150.3136, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, '100712'); -- Inferno Hawk - 100712 - Fire Hawk Smoke Cosmetic

-- Path for Ancient Corehound
SET @MOVERGUID := 339376;
SET @ENTRY := 53134;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ancient Core Hound - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -269.29883, 140.44922, 46.433746, NULL, 0),
(@PATH, 1, -246.91145, 164.11111, 47.020195, NULL, 0),
(@PATH, 2, -223.70486, 186.59549, 46.91439, NULL, 0),
(@PATH, 3, -216.15279, 222.00868, 46.089764, NULL, 0),
(@PATH, 4, -217.02083, 242.7691, 45.46096, NULL, 10367),
(@PATH, 5, -236.55035, 248.4757, 45.842255, NULL, 0),
(@PATH, 6, -244.29514, 231.78645, 45.540344, NULL, 0),
(@PATH, 7, -235.46529, 220.54688, 45.463303, NULL, 0),
(@PATH, 8, -223.80208, 186.4757, 46.91303, NULL, 0),
(@PATH, 9, -247.1927, 163.63368, 47.05446, NULL, 0),
(@PATH, 10, -269.9453, 139.7207, 46.31019, NULL, 0),
(@PATH, 11, -304.20834, 139.03473, 45.59674, NULL, 0),
(@PATH, 12, -317.63022, 131.51216, 45.02671, NULL, 0),
(@PATH, 13, -329.93057, 113.80556, 44.87132, NULL, 0),
(@PATH, 14, -327.88715, 102.86806, 44.793533, NULL, 0),
(@PATH, 15, -321.74133, 95.734375, 45.575184, NULL, 11070),
(@PATH, 16, -288.5764, 117.42188, 45.528694, NULL, 0);

UPDATE `creature` SET `position_x`=-269.29883, `position_y`=140.44922, `position_z`=46.433746, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Ancient Core Hound

-- Path for Ancient Corehound
SET @MOVERGUID := 338776;
SET @ENTRY := 53134;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ancient Core Hound - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -334.09897, -10.506945, 44.97738, NULL, 0),
(@PATH, 1, -328.90625, 10.89757, 44.999626, NULL, 0),
(@PATH, 2, -342.73438, 34.987846, 45.428356, NULL, 0),
(@PATH, 3, -350.9045, 56.208332, 45.66429, NULL, 0),
(@PATH, 4, -351.85416, 71.229164, 44.76207, NULL, 12399),
(@PATH, 5, -381.57465, 39.149307, 45.5442, NULL, 0),
(@PATH, 6, -387.68402, 13.482639, 45.17363, NULL, 0),
(@PATH, 7, -402.6379, 9.138029, 46.836395, NULL, 0),
(@PATH, 8, -419.64932, 12.298612, 45.387985, NULL, 0),
(@PATH, 9, -421.3125, 42.133682, 44.84632, NULL, 0),
(@PATH, 10, -403.17188, 71.92014, 46.169132, NULL, 0),
(@PATH, 11, -379.79166, 93.65799, 44.829037, NULL, 0),
(@PATH, 12, -357.09897, 79.989586, 44.846954, NULL, 0),
(@PATH, 13, -379.0295, 39.984375, 45.516674, NULL, 0),
(@PATH, 14, -372.42014, 12.979167, 45.56502, NULL, 0),
(@PATH, 15, -348.02432, 1.6979166, 45.37395, NULL, 0),
(@PATH, 16, -342.9236, -10.376737, 45.094284, NULL, 0);

UPDATE `creature` SET `position_x`=-334.09897, `position_y`=-10.506945, `position_z`=44.97738, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Ancient Core Hound

-- Path for Hell Hound
DELETE FROM `creature_formations` WHERE `leaderGUID` = 338985;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(338985, 338985, 0, 0, 515, 0, 0),
(338985, 338986, 6, 320, 515, 0, 0),
(338985, 338984, 6, 40, 515, 0, 0);

SET @MOVERGUID := 338985;
SET @ENTRY := 53206;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Hell Hound - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -253.43056, -66.27952, 44.80947, NULL, 0),
(@PATH, 1, -289.79166, -84.76215, 45.5307, NULL, 0),
(@PATH, 2, -329.04514, -87.35069, 44.78282, NULL, 0),
(@PATH, 3, -344.44446, -81.59549, 47.942726, NULL, 7650),
(@PATH, 4, -310.1979, -39.925346, 45.40067, NULL, 0),
(@PATH, 5, -323.8611, -2.2239583, 45.064796, NULL, 0),
(@PATH, 6, -325.54166, 25.831598, 44.89184, NULL, 0),
(@PATH, 7, -306.83682, 58.578125, 44.84175, NULL, 0),
(@PATH, 8, -296.02173, 89.71497, 44.93142, NULL, 0),
(@PATH, 9, -281.92188, 113.42361, 45.22332, NULL, 0),
(@PATH, 10, -266.9896, 135.02951, 46.730312, NULL, 0),
(@PATH, 11, -247.92708, 178.85764, 46.5634, NULL, 20),
(@PATH, 12, -234.56598, 139.64062, 49.07814, NULL, 0),
(@PATH, 13, -224.90973, 104.74132, 47.799488, NULL, 0),
(@PATH, 14, -219.48264, 71.833336, 45.747032, NULL, 0),
(@PATH, 15, -190.1927, 40.42014, 46.40939, NULL, 0),
(@PATH, 16, -189.64236, 13.420139, 48.0884, NULL, 0),
(@PATH, 17, -210.9618, -28.019098, 44.7593, NULL, 0),
(@PATH, 18, -237.64757, -43.40278, 45.455124, NULL, 0);

UPDATE `creature` SET `position_x`=-253.43056, `position_y`=-66.27952, `position_z`=44.80947, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature` SET `position_x`=-203.90975, `position_y`=-11.27357, `position_z`=47.57920 WHERE `guid`=338986;
UPDATE `creature` SET `position_x`=-213.09686, `position_y`=-29.25050, `position_z`=44.86603 WHERE `guid`=338984;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Hell Hound

-- Path for Molten Lord
SET @MOVERGUID := 317633;
SET @ENTRY := 53115;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Molten Lord - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -161.52083, 118.00347, 44.833763, NULL, 0),
(@PATH, 1, -140.34029, 140.48611, 45.964245, NULL, 0),
(@PATH, 2, -122.82291, 143.38889, 44.671448, NULL, 0),
(@PATH, 3, -99.34028, 144.25, 44.56655, NULL, 0),
(@PATH, 4, -96.322914, 163.86632, 44.111725, NULL, 0),
(@PATH, 5, -131.09549, 174.97223, 44.75879, NULL, 0),
(@PATH, 6, -144.27779, 171.89236, 44.75879, NULL, 0),
(@PATH, 7, -172.96355, 160.79514, 45.06458, NULL, 0),
(@PATH, 8, -181.00868, 137.5677, 45.598732, NULL, 0),
(@PATH, 9, -188.93924, 118.16666, 45.560024, NULL, 0),
(@PATH, 10, -211.27605, 98.95139, 45.931118, NULL, 0),
(@PATH, 11, -228.51736, 75.62327, 45.605175, NULL, 0),
(@PATH, 12, -249.9566, 59.17882, 45.133327, NULL, 0),
(@PATH, 13, -280.1684, 58.69097, 44.76927, NULL, 0),
(@PATH, 14, -295.86285, 55.90972, 44.75879, NULL, 0),
(@PATH, 15, -300.033, 47.921875, 44.75879, NULL, 0),
(@PATH, 16, -294.22223, 35.95486, 44.75879, NULL, 0),
(@PATH, 17, -287.48264, 28.71007, 44.764893, NULL, 0),
(@PATH, 18, -264.28473, 14.418403, 45.06316, NULL, 0),
(@PATH, 19, -265.0486, -7.6059027, 45.523006, NULL, 0),
(@PATH, 20, -273.0879, -34.45703, 45.13822, NULL, 0),
(@PATH, 21, -288.57812, -47.095486, 45.46196, NULL, 0),
(@PATH, 22, -282.9132, -67.24132, 44.843987, NULL, 0),
(@PATH, 23, -269.34897, -84.74306, 44.742496, NULL, 0),
(@PATH, 24, -244.1007, -74.798615, 45.259842, NULL, 0),
(@PATH, 25, -212.66145, -77.53819, 45.4755, NULL, 0),
(@PATH, 26, -204.9427, -42.199654, 44.75879, NULL, 0),
(@PATH, 27, -230.06076, -13.524305, 44.782715, NULL, 0),
(@PATH, 28, -230.3993, 30.640625, 47.78005, NULL, 0),
(@PATH, 29, -198.85764, 41.519096, 46.41644, NULL, 0),
(@PATH, 30, -184.0573, 54.47222, 45.85771, NULL, 0),
(@PATH, 31, -179.37848, 95.07639, 44.817406, NULL, 13044);

UPDATE `creature` SET `position_x`=-161.52083, `position_y`=118.00347, `position_z`=44.833763, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- Molten Lord

-- Path for Molten Lord
SET @MOVERGUID := 339374;
SET @ENTRY := 53115;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Molten Lord - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -423.11633, 254.58507, 70.235374, NULL, 0),
(@PATH, 1, -413.00174, 239.80904, 61.6244, NULL, 0),
(@PATH, 2, -398.46527, 219.07118, 52.759968, NULL, 10416),
(@PATH, 3, -406.63715, 233.98264, 58.387093, NULL, 0),
(@PATH, 4, -421.91602, 252.90625, 69.60487, NULL, 0),
(@PATH, 5, -435.47223, 281.68576, 81.20213, NULL, 10426);

UPDATE `creature` SET `position_x`=-423.11633, `position_y`=254.58507, `position_z`=70.235374, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- Molten Lord

-- Path for Flamewake Overseer
SET @MOVERGUID := 339283;
SET @ENTRY := 53185;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Flamewaker Overseer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -62.32639, -59.302082, 57.501553, NULL, 0),
(@PATH, 1, -55.520832, -33.572918, 57.2892, NULL, 0),
(@PATH, 2, -49.78125, -10.953125, 56.64165, NULL, 0),
(@PATH, 3, -41.9375, 29.54514, 56.63441, NULL, 0),
(@PATH, 4, -38.87847, 52.18403, 56.15011, NULL, 0),
(@PATH, 5, -26.256945, 75.13194, 56.674206, NULL, 0),
(@PATH, 6, -15.3125, 91.484375, 56.731693, NULL, 0),
(@PATH, 7, -8.697917, 103.00868, 56.22521, NULL, 0),
(@PATH, 8, -15.3125, 91.484375, 56.731693, NULL, 0),
(@PATH, 9, -26.256945, 75.13194, 56.674206, NULL, 0),
(@PATH, 10, -38.87847, 52.18403, 56.15011, NULL, 0),
(@PATH, 11, -41.9375, 29.54514, 56.63441, NULL, 0),
(@PATH, 12, -49.78125, -10.953125, 56.64165, NULL, 0),
(@PATH, 13, -55.520832, -33.572918, 57.2892, NULL, 0),
(@PATH, 14, -62.32639, -59.302082, 57.501553, NULL, 0),
(@PATH, 15, -72.03299, -99.0191, 56.75902, NULL, 0),
(@PATH, 16, -89.97049, -132.20139, 56.8467, NULL, 0),
(@PATH, 17, -72.03299, -99.0191, 56.75902, NULL, 0);

UPDATE `creature` SET `position_x`=-62.32639, `position_y`=-59.302082, `position_z`=57.501553, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Flamewaker Overseer

-- Path for Flamewake Overseer
SET @MOVERGUID := 339349;
SET @ENTRY := 53185;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Flamewaker Overseer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -163.8073, -237.04514, 55.67593, NULL, 0),
(@PATH, 1, -145.29514, -224.3073, 57.124306, NULL, 0),
(@PATH, 2, -124.01041, -208.98264, 57.11754, NULL, 0),
(@PATH, 3, -118.19965, -188.20833, 57.102245, NULL, 0),
(@PATH, 4, -112.50868, -162.23958, 56.94825, NULL, 0),
(@PATH, 5, -108.31944, -153.77083, 57.12131, NULL, 10178),
(@PATH, 6, -112.75347, -164.55904, 56.931587, NULL, 0),
(@PATH, 7, -114.36285, -181.35417, 56.94776, NULL, 0),
(@PATH, 8, -116.83681, -200.87326, 57.116814, NULL, 0),
(@PATH, 9, -135.22917, -216.57639, 57.117954, NULL, 0),
(@PATH, 10, -164.93404, -233.4132, 55.62241, NULL, 0),
(@PATH, 11, -184.27083, -237.15279, 55.690792, NULL, 0),
(@PATH, 12, -195.88889, -225.3368, 54.914135, NULL, 0),
(@PATH, 13, -209.89583, -208.23438, 54.40889, NULL, 0),
(@PATH, 14, -227.24306, -190.42188, 54.40889, NULL, 10146),
(@PATH, 15, -216.33507, -204.88716, 54.40889, NULL, 0),
(@PATH, 16, -199.7691, -225.3941, 54.625725, NULL, 0),
(@PATH, 17, -186.4375, -237.24132, 55.689682, NULL, 0);

UPDATE `creature` SET `position_x`=-163.8073, `position_y`=-237.04514, `position_z`=55.67593, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Flamewaker Overseer

-- Path for Flamewake Overseer
SET @MOVERGUID := 339286;
SET @ENTRY := 53185;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Flamewaker Overseer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -52.256947, -69.046875, 57.38034, NULL, 0),
(@PATH, 1, -38.78125, -43.27257, 55.521347, NULL, 0),
(@PATH, 2, -42.194447, -3.1302083, 55.326447, NULL, 0),
(@PATH, 3, -39.131947, 11.901042, 56.62488, NULL, 0),
(@PATH, 4, -36.01736, 41.567707, 55.44223, NULL, 0),
(@PATH, 5, -25.217014, 52.979168, 55.479782, NULL, 0),
(@PATH, 6, -53.925346, 57.87847, 55.622307, NULL, 0),
(@PATH, 7, -63.307293, 59.446182, 56.224598, NULL, 6302),
(@PATH, 8, -82.19097, 62.180557, 57.29495, NULL, 0),
(@PATH, 9, -99.770836, 46.975697, 59.551304, NULL, 0),
(@PATH, 10, -107.57291, 29.784723, 58.15261, NULL, 0),
(@PATH, 11, -95.91319, 11.324653, 57.47791, NULL, 0),
(@PATH, 12, -85.49132, 1.6371528, 56.33011, NULL, 0),
(@PATH, 13, -57.163197, 6.107639, 55.804016, NULL, 0),
(@PATH, 14, -45.243057, -4.977431, 55.507233, NULL, 0),
(@PATH, 15, -55.15278, -36.913197, 57.493076, NULL, 0),
(@PATH, 16, -61.092014, -51.560764, 57.492775, NULL, 0),
(@PATH, 17, -80.109375, -62.060764, 55.32427, NULL, 0),
(@PATH, 18, -72.33507, -84.78819, 56.82589, NULL, 0),
(@PATH, 19, -61.626736, -117.7691, 55.53306, NULL, 8367);

UPDATE `creature` SET `position_x`=-52.256947, `position_y`=-69.046875, `position_z`=57.38034, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Flamewaker Overseer

-- Path for Flamewaker Forward Guard
DELETE FROM `creature_formations` WHERE `leaderGUID` = 339408;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(339408, 339408, 0, 0, 515, 0, 0),
(339408, 339410, 5, 270, 515, 3, 23),
(339408, 339409, 5, 90, 515, 3, 23),
(339408, 339411, 5, 0, 515, 3, 23),
(339408, 339412, 7, 320, 515, 3, 23);

SET @MOVERGUID := 339408;
SET @ENTRY := 53119;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Flamewaker Forward Guard - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -264.12326, 84.736115, 46.256065, NULL, 0),
(@PATH, 1, -279.94446, 74.68924, 46.157623, NULL, 0),
(@PATH, 2, -293.18402, 70.458336, 46.157627, NULL, 0),
(@PATH, 3, -300.21353, 69.48264, 46.157623, NULL, 54),
(@PATH, 4, -293.18402, 70.458336, 46.157627, NULL, 0),
(@PATH, 5, -279.94446, 74.68924, 46.157623, NULL, 0),
(@PATH, 6, -264.12326, 84.736115, 46.256065, NULL, 0),
(@PATH, 7, -242.3316, 96.03819, 47.2705, NULL, 0),
(@PATH, 8, -237.7552, 110.20834, 48.351738, NULL, 0),
(@PATH, 9, -240.75348, 126.30903, 49.149788, NULL, 0),
(@PATH, 10, -228.9427, 141.21875, 48.925163, NULL, 0),
(@PATH, 11, -210.38194, 154.63889, 47.452118, NULL, 0),
(@PATH, 12, -188.76736, 171.30208, 46.67384, NULL, 0),
(@PATH, 13, -171.33855, 177.07292, 46.28623, NULL, 0),
(@PATH, 14, -158.3316, 181.85938, 46.158203, NULL, 0),
(@PATH, 15, -142.91667, 191.84549, 46.157646, NULL, 0),
(@PATH, 16, -124.19791, 192.92014, 46.157646, NULL, 0),
(@PATH, 17, -108.77952, 186.25174, 45.941277, NULL, 0),
(@PATH, 18, -90.3418, 178.51758, 44.61805, NULL, 0),
(@PATH, 19, -80.2934, 173.9618, 44.574287, NULL, 0),
(@PATH, 20, -65.49306, 174.73958, 45.149876, NULL, 0),
(@PATH, 21, -55.449654, 177.64236, 45.883842, NULL, 0),
(@PATH, 22, -41.102432, 187.14583, 46.73425, NULL, 0),
(@PATH, 23, -31.026041, 196.48611, 47.372864, NULL, 0),
(@PATH, 24, -41.102432, 187.14583, 46.73425, NULL, 0),
(@PATH, 25, -55.449654, 177.64236, 45.883842, NULL, 0),
(@PATH, 26, -65.49306, 174.73958, 45.149876, NULL, 0),
(@PATH, 27, -80.2934, 173.9618, 44.574287, NULL, 0),
(@PATH, 28, -90.24653, 178.48785, 44.630108, NULL, 0),
(@PATH, 29, -108.68359, 186.22266, 45.942123, NULL, 0),
(@PATH, 30, -124.19791, 192.92014, 46.157646, NULL, 0),
(@PATH, 31, -142.91667, 191.84549, 46.157646, NULL, 0),
(@PATH, 32, -158.3316, 181.85938, 46.158203, NULL, 0),
(@PATH, 33, -171.33855, 177.07292, 46.28623, NULL, 0),
(@PATH, 34, -188.76736, 171.30208, 46.67384, NULL, 0),
(@PATH, 35, -210.38194, 154.63889, 47.452118, NULL, 0),
(@PATH, 36, -228.9427, 141.21875, 48.925163, NULL, 0),
(@PATH, 37, -240.75348, 126.30903, 49.149788, NULL, 0),
(@PATH, 38, -237.7552, 110.20834, 48.351738, NULL, 0),
(@PATH, 39, -242.3316, 96.03819, 47.2705, NULL, 0);

UPDATE `creature` SET `position_x` = -264.12326, `position_y` = 84.736115, `position_z` = 46.256065, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`=@MOVERGUID;
UPDATE `creature` SET `position_x` = -238.429122924804687, `position_y` = 108.7289657592773437, `position_z` = 48.26232147216796875, `orientation` = 4.571320533752441406 WHERE `guid`=339411;
UPDATE `creature` SET `position_x` = -233.6058349609375, `position_y` = 108.0715103149414062, `position_z` = 48.2217559814453125, `orientation` = 4.598929405212402343 WHERE `guid`=339412;
UPDATE `creature` SET `position_x` = -235.029098510742187, `position_y`= 102.4858551025390625, `position_z` = 47.81554412841796875, `orientation` = 4.430493354797363281 WHERE `guid`=339410;
UPDATE `creature` SET `position_x` = -244.546722412109375, `position_y` = 105.4391326904296875, `position_z`= 47.90686798095703125, `orientation` = 4.400305747985839843 WHERE `guid`=339409;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Flamewaker Forward Guard

-- Path for Flamewaker Forward Guard
DELETE FROM `creature_formations` WHERE `leaderGUID` = 338997;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(338997, 338997, 0, 0, 515, 0, 0),
(338997, 338996, 5, 270, 515, 2, 14),
(338997, 338995, 5, 90, 515, 2, 14),
(338997, 339001, 5, 0, 515, 2, 14),
(338997, 339002, 7, 320, 515, 2, 14);

SET @MOVERGUID := 338997;
SET @ENTRY := 53119;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Flamewaker Forward Guard - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -311.52777, -62.737846, 46.15763, NULL, 0),
(@PATH, 1, -300.74652, -76.26215, 46.15763, NULL, 0),
(@PATH, 2, -299.57465, -85.62153, 46.15763, NULL, 253),
(@PATH, 3, -300.74652, -76.26215, 46.15763, NULL, 0),
(@PATH, 4, -311.52777, -62.737846, 46.15763, NULL, 0),
(@PATH, 5, -321.52258, -54.185764, 46.15763, NULL, 0),
(@PATH, 6, -321.908, -42.947918, 46.15763, NULL, 0),
(@PATH, 7, -320.408, -28.970486, 46.15763, NULL, 0),
(@PATH, 8, -318.84375, -19.440973, 46.15763, NULL, 0),
(@PATH, 9, -306.77084, -8.206597, 46.15763, NULL, 0),
(@PATH, 10, -304.7014, 7.189236, 46.15763, NULL, 0),
(@PATH, 11, -306.30383, 23.493055, 46.15763, NULL, 0),
(@PATH, 12, -318.6007, 37.14757, 46.15763, NULL, 0),
(@PATH, 13, -322.09723, 47.050346, 46.15763, NULL, 0),
(@PATH, 14, -319.8264, 54.196182, 46.15763, NULL, 192),
(@PATH, 15, -322.09723, 47.050346, 46.15763, NULL, 0),
(@PATH, 16, -318.6007, 37.14757, 46.15763, NULL, 0),
(@PATH, 17, -306.30383, 23.493055, 46.15763, NULL, 0),
(@PATH, 18, -304.7014, 7.189236, 46.15763, NULL, 0),
(@PATH, 19, -306.77084, -8.206597, 46.15763, NULL, 0),
(@PATH, 20, -318.84375, -19.440973, 46.15763, NULL, 0),
(@PATH, 21, -320.408, -28.970486, 46.15763, NULL, 0),
(@PATH, 22, -321.908, -42.947918, 46.15763, NULL, 0),
(@PATH, 23, -321.52258, -54.185764, 46.15763, NULL, 0);

UPDATE `creature` SET `position_x`=-311.52777, `position_y`=-62.737846, `position_z`=46.15763, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature` SET `position_x` = -326.732025146484375, `position_y` = -41.9380531311035156, `position_z` = 46.15763092041015625, `orientation` = 4.687672615051269531 WHERE `guid`=338996;
UPDATE `creature` SET `position_x` = -316.7747802734375, `position_y` = -42.6516342163085937, `position_z` = 46.15763092041015625, `orientation` = 4.691883087158203125 WHERE `guid`=338995;
UPDATE `creature` SET `position_x` = -327.090057373046875, `position_y`= -46.8976707458496093, `position_z` = 46.15763092041015625, `orientation` = 4.858008861541748046 WHERE `guid`=339001;
UPDATE `creature` SET `position_x` = -322.112548828125, `position_y` = -47.2613029479980468, `position_z`= 46.15763092041015625, `orientation` = 4.858008861541748046 WHERE `guid`=339002;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Flamewaker Forward Guard

-- Path for Flamewaker Forward Guard
DELETE FROM `creature_formations` WHERE `leaderGUID` = 339391;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(339391, 339391, 0, 0, 515, 0, 0),
(339391, 339393, 5, 270, 515, 11, 22),
(339391, 339392, 5, 90, 515, 11, 22),
(339391, 339395, 5, 0, 515, 11, 22),
(339391, 339394, 7, 320, 515, 11, 22);

SET @MOVERGUID := 339391;
SET @ENTRY := 53119;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Flamewaker Forward Guard - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -373.30557, 182.49132, 52.54513, NULL, 0),
(@PATH, 1, -372.30383, 172.09201, 51.73241, NULL, 0),
(@PATH, 2, -373.61978, 161.34549, 50.96956, NULL, 0),
(@PATH, 3, -373.06076, 150.71007, 50.148758, NULL, 0),
(@PATH, 4, -369.50522, 139.85243, 48.3003, NULL, 0),
(@PATH, 5, -367.34027, 127.98611, 47.120216, NULL, 0),
(@PATH, 6, -363.31076, 115.61285, 46.15763, NULL, 0),
(@PATH, 7, -354.1111, 104.6875, 46.157562, NULL, 0),
(@PATH, 8, -343.08853, 91.32118, 46.15763, NULL, 0),
(@PATH, 9, -336.40277, 80.28819, 46.15763, NULL, 0),
(@PATH, 10, -329.6354, 73.69618, 46.15763, NULL, 0),
(@PATH, 11, -325.94965, 71.166664, 46.15763, NULL, 13),
(@PATH, 12, -336.40277, 80.28819, 46.15763, NULL, 0),
(@PATH, 13, -343.08853, 91.32118, 46.15763, NULL, 0),
(@PATH, 14, -354.1111, 104.6875, 46.157562, NULL, 0),
(@PATH, 15, -363.31076, 115.61285, 46.15763, NULL, 0),
(@PATH, 16, -367.34027, 127.98611, 47.120216, NULL, 0),
(@PATH, 17, -369.4961, 139.79883, 48.31549, NULL, 0),
(@PATH, 18, -373.06076, 150.71007, 50.148758, NULL, 0),
(@PATH, 19, -373.61978, 161.34549, 50.96956, NULL, 0),
(@PATH, 20, -372.30383, 172.09201, 51.73241, NULL, 0),
(@PATH, 21, -373.30557, 182.49132, 52.54513, NULL, 0),
(@PATH, 22, -382.57422, 192.99219, 52.491142, NULL, 5);

UPDATE `creature` SET `position_x`=-373.30557, `position_y`=182.49132, `position_z`=52.54513, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature` SET `position_x` = -375.629638671875, `position_y` = 192.644805908203125, `position_z` = 53.07988357543945312, `orientation` = 2.28298044204711914 WHERE `guid`=339393;
UPDATE `creature` SET `position_x` = -383.15594482421875, `position_y` = 186.095611572265625, `position_z` = 53.01667022705078125, `orientation` = 2.294034004211425781 WHERE `guid`=339392;
UPDATE `creature` SET `position_x` = -378.884368896484375, `position_y`= 196.382781982421875, `position_z` = 52.36310577392578125, `orientation` = 2.298088312149047851 WHERE `guid`=339395;
UPDATE `creature` SET `position_x` = -383.340606689453125, `position_y` = 193.878204345703125, `position_z`= 52.40434646606445312, `orientation` = 2.29954695701599121 WHERE `guid`=339394;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Flamewaker Forward Guard
