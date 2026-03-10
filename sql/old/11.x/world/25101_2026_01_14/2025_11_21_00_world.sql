-- Jansen Sted

-- Update _addon
DELETE FROM `creature_addon` WHERE `guid` IN (276311,276250,276248,276247,276251,276253,276249,276252,276246);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(276311, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Riverpaw Gnoll
(276250, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(276248, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(276247, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable
(276251, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(276253, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(276249, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '78677'), -- Homeless Stormwind Citizen - 78677 - Cosmetic - Sleep Zzz Breakable
(276252, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Homeless Stormwind Citizen
(276246, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Homeless Stormwind Citizen

-- Update Coyote with createobject2 data
UPDATE `creature` SET `position_x` = -9917.6845703125, `position_y` = 1081.3697509765625, `position_z` = 36.32218551635742187, `orientation` = 2.059144973754882812 WHERE `guid` = 275801;
UPDATE `creature` SET `position_x` = -9763.2080078125, `position_y` = 922.89239501953125, `position_z` = 28.10507011413574218, `orientation` = 0.791334688663482666 WHERE `guid` = 290976;
UPDATE `creature` SET `position_x` = -9687.3134765625, `position_y` = 920.8468017578125, `position_z` = 36.3758392333984375, `orientation` = 0.659389615058898925 WHERE `guid` = 276301;
UPDATE `creature` SET `position_x` = -9642.0830078125, `position_y` = 954.61114501953125, `position_z` = 38.56831741333007812, `orientation` = 1.340761065483093261 WHERE `guid` = 276302;

-- Update Young Goretusk with createobject2 data
UPDATE `creature` SET `position_x` = -9884.486328125, `position_y` = 1117.4010009765625, `position_z` = 34.02967071533203125, `orientation` = 4.955043315887451171 WHERE `guid` = 275863;
UPDATE `creature` SET `position_x` = -9921.1318359375, `position_y` = 1025.029541015625, `position_z` = 37.61643600463867187, `orientation` = 3.136789798736572265 WHERE `guid` = 275800;
UPDATE `creature` SET `position_x` = -9884.44140625, `position_y` = 1052.7847900390625, `position_z` = 34.54982376098632812, `orientation` = 3.009432077407836914 WHERE `guid` = 275864;
UPDATE `creature` SET `position_x` = -9852.4462890625, `position_y` = 1085.26220703125, `position_z` = 33.44092559814453125, `orientation` = 4.958492755889892578 WHERE `guid` = 275872;
UPDATE `creature` SET `position_x` = -9753.357421875, `position_y` = 979.48956298828125, `position_z` = 27.96611785888671875, `orientation` = 0 WHERE `guid` = 290979;
UPDATE `creature` SET `position_x` = -9808.6669921875, `position_y` = 1050.5382080078125, `position_z` = 29.42996025085449218, `orientation` = 2.376167774200439453 WHERE `guid` = 276243;
UPDATE `creature` SET `position_x` = -9772.6962890625, `position_y` = 1075.6822509765625, `position_z` = 21.93062019348144531, `orientation` = 2.19959259033203125 WHERE `guid` = 276242;
UPDATE `creature` SET `position_x` = -9783.1669921875, `position_y` = 1017.80902099609375, `position_z` = 31.56409454345703125, `orientation` = 0.440666496753692626 WHERE `guid` = 276312;
UPDATE `creature` SET `position_x` = -9684.1845703125, `position_y` = 984.7996826171875, `position_z` = 35.71132278442382812, `orientation` = 1.761797666549682617 WHERE `guid` = 276308;
UPDATE `creature` SET `position_x` = -9795.453125, `position_y` = 924.109375, `position_z` = 29.6386260986328125, `orientation` = 5.600205421447753906 WHERE `guid` = 290977;
UPDATE `creature` SET `position_x` = -9715.3525390625, `position_y` = 954.574462890625, `position_z` = 33.87543869018554687, `orientation` = 0.92597585916519165 WHERE `guid` = 276306;

-- Update Young Fleshripper with createobject2 data
UPDATE `creature` SET `position_x` = -9851.62890625, `position_y` = 1084.4427490234375, `position_z` = 33.24826812744140625, `orientation` = 3.199624538421630859 WHERE `guid` = 275870;
UPDATE `creature` SET `position_x` = -9952.783203125, `position_y` = 1052.0833740234375, `position_z` = 38.6177978515625, `orientation` = 5.240733146667480468 WHERE `guid` = 275789;
UPDATE `creature` SET `position_x` = -9715.904296875, `position_y` = 932.97918701171875, `position_z` = 28.01030540466308593, `orientation` = 5.10528564453125 WHERE `guid` = 276313;

-- Update Riverpaw Riverpaw Scout/Gnoll
UPDATE `creature` SET `position_x` = -9733.669921875, `position_y` = 1030.10595703125, `position_z` = 37.41457748413085937, `orientation` = 2.036846637725830078 WHERE `guid` = 276310;
UPDATE `creature` SET `position_x` = -9691.30078125, `position_y` = 1039.6961669921875, `position_z` = 36.4819183349609375, `orientation` = 5.609239101409912109 WHERE `guid` = 276300;
UPDATE `creature` SET `position_x` = -9688.91015625, `position_y` = 1002.45489501953125, `position_z` = 34.98340606689453125, `orientation` = 1.076619505882263183 WHERE `guid` = 276303;
UPDATE `creature` SET `position_x` = -9762.58203125, `position_y` = 1049.079833984375, `position_z` = 27.1958770751953125, `orientation` = 6.046966552734375 WHERE `guid` = 276263;
UPDATE `creature` SET `position_x` = -9725.267578125, `position_y` = 998.1649169921875, `position_z` = 35.46561431884765625, `orientation` = 5.836595535278320312 WHERE `guid` = 276304;
UPDATE `creature` SET `position_x` = -9666.2900390625, `position_y` = 973.951416015625, `position_z` = 36.8608856201171875, `orientation` = 2.162456274032592773 WHERE `guid` = 276309;
UPDATE `creature` SET `position_x` = -9716.4462890625, `position_y` = 1053.1961669921875, `position_z` = 35.01248931884765625, `orientation` = 6.083646774291992187 WHERE `guid` = 276299;
UPDATE `creature` SET `position_x` = -9709.1630859375, `position_y` = 1019.9271240234375, `position_z` = 37.87211227416992187, `orientation` = 3.711378097534179687 WHERE `guid` = 276305;
UPDATE `creature` SET `position_x` = -9700.0517578125, `position_y` = 971.10418701171875, `position_z` = 36.33763504028320312, `orientation` = 2.84639286994934082 WHERE `guid` = 276307;

-- Update random movement
UPDATE `creature` SET `wander_distance` = 8, `MovementType` = 1 WHERE `guid` IN (275801,276310,276300,276303,276263,276304,276309,276299,276305,276307,290976,276301,276302);
UPDATE `creature` SET `wander_distance` = 6, `MovementType` = 1 WHERE `guid` IN (275863,275800,275864,275872,290979,276243,276242,276312,276308,290977,276306);
UPDATE `creature` SET `wander_distance` = 12, `MovementType` = 1 WHERE `guid` IN (275870,275789,276313);

-- Path for Oprhan
DELETE FROM `creature_formations` WHERE `leaderGUID` = 276244;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(276244, 276244, 0, 0, 515, 0, 0),
(276244, 276245, 4, 0, 515, 0, 0);

SET @MOVERGUID := 276244;
SET @ENTRY := 42385;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Orphan - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -9841.384, 1027.1858, 32.5746, NULL, 0),
(@PATH, 1, -9833.6045, 1032.6389, 32.766445, NULL, 0),
(@PATH, 2, -9837.156, 1040.4462, 33.696316, NULL, 0),
(@PATH, 3, -9840.221, 1032.4688, 32.690422, NULL, 0),
(@PATH, 4, -9847.531, 1035.0382, 34.118645, NULL, 0),
(@PATH, 5, -9850.639, 1036.5173, 34.118645, NULL, 0),
(@PATH, 6, -9841.384, 1027.1858, 32.5746, NULL, 0),
(@PATH, 7, -9833.6045, 1032.6389, 32.766445, NULL, 0),
(@PATH, 8, -9832.194, 1038.5104, 33.349182, NULL, 0),
(@PATH, 9, -9840.221, 1032.4688, 32.690422, NULL, 0),
(@PATH, 10, -9843.348, 1030.3281, 32.822098, NULL, 0),
(@PATH, 11, -9848.0205, 1039.0209, 34.11865, NULL, 0),
(@PATH, 12, -9845.143, 1030.208, 33.05832, NULL, 0);

UPDATE `creature` SET `position_x`=-9841.384, `position_y`=1027.1858, `position_z`=32.5746, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
