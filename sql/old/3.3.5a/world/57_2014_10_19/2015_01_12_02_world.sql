-- Add missing spawns Rook and Corvax
SET @GUID := 69711;
INSERT INTO `creature` (`guid`, `id`, `map`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `curhealth`) VALUES
(@GUID + 0, 22843, 530, 21119, -237.2198, 5444.96, 31.853, 2.59318, 4059),
(@GUID + 1, 22842, 530, 21119, -254.8032, 5443.792, 30.77559, 0.6263401, 50);

-- Update InhabitType for flying
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=22843;
UPDATE `creature_template` SET `InhabitType`=4 WHERE  `entry`=22842;

-- Pathing for Rook Entry: 22843 'TDB FORMAT' 
SET @NPC := 69711;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-253.4223,`position_y`=5430.909,`position_z`=28.92926 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-253.4223,5430.909,28.92926,0,0,1,0,100,0),
(@PATH,2,-252.2368,5429.647,28.75794,0,0,1,0,100,0),
(@PATH,3,-246.0865,5428.435,29.54239,0,0,1,0,100,0),
(@PATH,4,-239.4053,5431.095,29.54241,0,0,1,0,100,0),
(@PATH,5,-235.5483,5436.207,30.90352,0,0,1,0,100,0),
(@PATH,6,-235.0203,5442.249,30.87573,0,0,1,0,100,0),
(@PATH,7,-238.777,5445.627,32.07018,0,0,1,0,100,0),
(@PATH,8,-246.5504,5445.43,30.82018,0,0,1,0,100,0),
(@PATH,9,-254.3803,5440.281,29.67928,0,0,1,0,100,0),
(@PATH,10,-255.2896,5432.612,28.92926,0,0,1,0,100,0);
-- 0x1C39204240164EC000002C00001A411E .go -253.4223 5430.909 28.92926

-- Pathing for Corvax Entry: 22842 'TDB FORMAT' 
SET @NPC := 69712;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-231.4784,`position_y`=5442.248,`position_z`=29.75438 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-231.4784,5442.248,29.75438,0,0,1,0,100,0),
(@PATH,2,-231.9071,5441.805,29.40595,0,0,1,0,100,0),
(@PATH,3,-233.5468,5436.123,30.58605,0,0,1,0,100,0),
(@PATH,4,-235.9648,5433.313,31.33606,0,0,1,0,100,0),
(@PATH,5,-245.6634,5430.377,32.44696,0,0,1,0,100,0),
(@PATH,6,-254.214,5432.43,32.50253,0,0,1,0,100,0),
(@PATH,7,-257.6299,5440.645,31.36549,0,0,1,0,100,0),
(@PATH,8,-250.052,5446.799,30.14325,0,0,1,0,100,0),
(@PATH,9,-244.9603,5449.014,29.67106,0,0,1,0,100,0),
(@PATH,10,-237.6145,5448.882,29.75438,0,0,1,0,100,0);
-- 0x1C39204240164E8000002C00001A411E .go -231.4784 5442.248 29.75438
