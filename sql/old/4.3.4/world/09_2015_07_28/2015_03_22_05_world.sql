-- Pathing for Freya Entry: 32906
SET @NPC := 136554;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=2338.461,`position_y`=-52.32549,`position_z`=425.5522 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,2338.461,-52.32549,425.5522,0,0,0,0,100,0),
(@PATH,2,2327.021,-69.61578,426.0348,0,0,0,0,100,0),
(@PATH,3,2303.438,-90.47264,429.1589,0,0,0,0,100,0),
(@PATH,4,2301.615,-91.41477,429.1122,3.649395,13000,0,488,100,0),
(@PATH,5,2333.003,-57.68308,425.5663,0,0,0,0,100,0),
(@PATH,6,2342.892,-46.95139,425.5204,3.298672,60000,0,0,100,0),
(@PATH,7,2397.739,-42.16927,422.8524,0,0,0,0,100,0),
(@PATH,8,2409.762,-74.47346,420.6727,0,0,0,0,100,0),
(@PATH,9,2400.14,-96.78609,424.1808,0,0,0,0,100,0),
(@PATH,10,2399.105,-98.47173,424.2316,4.866657,13000,0,489,100,0),
(@PATH,11,2397.637,-46.43726,423.2978,0,0,0,0,100,0),
(@PATH,12,2358.936,-41.11687,425.6092,0,0,0,0,100,0),
(@PATH,13,2349.045,-40.70486,425.7578,3.176499,60000,0,0,100,0),
(@PATH,14,2403.443,-26.94002,419.8143,0,0,0,0,100,0),
(@PATH,15,2411.195,-22.77497,419.1813,0,0,0,0,100,0),
(@PATH,16,2436.248,12.27234,422.2727,0,0,0,0,100,0),
(@PATH,17,2437.145,16.83826,424.929,0,0,0,0,100,0),
(@PATH,18,2437.777,19.35069,426.0522,1.399542,13000,0,490,100,0),
(@PATH,19,2412.994,-11.56424,420.4819,0,0,0,0,100,0),
(@PATH,20,2359.694,-40.27568,425.3726,0,75000,0,0,100,0);

DELETE FROM `waypoint_scripts` WHERE `id` IN (488,489,490);
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`guid`) VALUES
(488,3,15,63295,4,33575,30,891),(489,3,15,63292,4,33575,30,892),(490,3,15,63294,4,33575,30,893);

UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0, `curhealth`=1 WHERE `id`=33575;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=33575;

-- Add spell target condition for Freya Dummy
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=2 AND `SourceEntry` IN (63292,63294,63295);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 63292, 0, 0, 31, 3, 33575, 0, 0, '', 'Freya Dummy Yellow targets Channel Stalker Freya'),
(13, 2, 63294, 0, 0, 31, 3, 33575, 0, 0, '', 'Freya Dummy Blue targets Channel Stalker Freya'),
(13, 2, 63295, 0, 0, 31, 3, 33575, 0, 0, '', 'Freya Dummy Green targets Channel Stalker Freya');
