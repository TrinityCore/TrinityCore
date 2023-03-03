INSERT IGNORE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `unkInt32`, `WDBVerified`) VALUES
(211991, 0, 11638, 'Challenge Mode - Start Door (Line 3.0)', '', '', '', 3, 0, 0, 0, 0, 0, 17898), -- 211991
(212972, 0, 11638, 'Challenge Mode - Start Door (Line 3.5)', '', '', '', 3.5, 0, 0, 0, 0, 0, 17898), -- 212972
(211988, 0, 11638, 'Challenge Mode - Start Door (Line 1.0)', '', '', '', 1, 0, 0, 0, 0, 0, 17898),
(211989, 0, 11638, 'Challenge Mode - Start Door (Line 2.0)', '', '', '', 2, 0, 0, 0, 0, 0, 17898);


UPDATE `gameobject_template` SET `type`=10, `displayId`=11554, `name`='Сфера испытания', `IconName`='', `castBarCaption`='', `unk1`='', `size`=1.5, `questItem1`=0, `questItem2`=0, `questItem3`=0, `questItem4`=0, `unkInt32`=0, data19 = 13872, `WDBVerified`=17898 WHERE `entry`=211674; -- 211674
UPDATE `gameobject_template` SET `type`=0, `displayId`=11638, `name`='Challenge Mode - Start Door (Line 3.0)', `IconName`='', `castBarCaption`='', `unk1`='', `size`=3, `questItem1`=0, `questItem2`=0, `questItem3`=0, `questItem4`=0, `unkInt32`=0, `WDBVerified`=17898 WHERE `entry`=211991; -- 211991
UPDATE `gameobject_template` SET `type`=0, `displayId`=11638, `name`='Challenge Mode - Start Door (Line 3.5)', `IconName`='', `castBarCaption`='', `unk1`='', `size`=3.5, `questItem1`=0, `questItem2`=0, `questItem3`=0, `questItem4`=0, `unkInt32`=0, `WDBVerified`=17898 WHERE `entry`=212972; -- 212972
UPDATE `gameobject_template` SET `type`=0, `displayId`=11638, `name`='Challenge Mode - Start Door (Line 2.0)', `IconName`='', `castBarCaption`='', `unk1`='', `size`=2, `questItem1`=0, `questItem2`=0, `questItem3`=0, `questItem4`=0, `unkInt32`=0, `WDBVerified`=17898 WHERE `entry`=211989; -- 211989
UPDATE `gameobject_template` SET `type`=0, `displayId`=11638, `name`='Challenge Mode - Start Door (Line 1.5)', `IconName`='', `castBarCaption`='', `unk1`='', `size`=1.5, `questItem1`=0, `questItem2`=0, `questItem3`=0, `questItem4`=0, `unkInt32`=0, `WDBVerified`=17898 WHERE `entry`=211992; -- 211992
UPDATE `gameobject_template` SET `type`=0, `displayId`=11638, `name`='Challenge Mode - Start Door (Line 1.0)', `IconName`='', `castBarCaption`='', `unk1`='', `size`=1, `questItem1`=0, `questItem2`=0, `questItem3`=0, `questItem4`=0, `unkInt32`=0, `WDBVerified`=17898 WHERE `entry`=211988;
UPDATE `gameobject_template` SET `faction`=1375, `size`=1.5, `flags`=22 WHERE `entry`=211992;
UPDATE `gameobject_template` SET `faction`=1375, `size`=3, `flags`=22 WHERE `entry`=211991;


DELETE FROM `gameobject` WHERE map in(960, 961, 962, 1001, 1004, 1007, 959, 1011) AND id in (211674, 211991, 211992);
INSERT INTO `gameobject` (`id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `isActive`) VALUES
-- 960
(211992, 960, 5956, 5956, 256, 1, 942.458, -2520.94, 180.515, 1.26818, 0, 0, 0, 1, 7200, 0, 1, 0),
(211991, 960, 5956, 5956, 256, 1, 968.566, -2507.68, 180.504, 2.82069, 0, 0, 0, 1, 7200, 0, 1, 0),
(211991, 960, 5956, 5956, 256, 1, 929.503, -2492.96, 180.504, 2.82069, 0, 0, 0, 1, 7200, 0, 1, 0),
(211674, 960, 5956, 5956, 256, 1, 949.17, -2501.26, 180.609, 1.27584, 0, 0, 0, 1, 7200, 0, 1, 0),
-- 961
(211674, 961, 0, 0, 256, 1, -734.7257, 1275.575, 116.108, 5.002464, 0, 0, 0, 1, 7200, 0, 1, 0),
-- 962
(211674, 962, 0, 0, 256, 1, 721.8177, 2119.168, 402.9071, 0, 0, 0, 0, 1, 7200, 0, 1, 0),
-- 1001
(211674, 1001, 0, 0, 256, 1, 837.1649, 608.5746, 12.81151, 4.681327, 0, 0, 0, 1, 7200, 0, 1, 0),
-- 1004
(211674, 1004, 0, 0, 256, 1, 1124.576, 518.5104, 0.6547356, 0, 0, 0, 0, 1, 7200, 0, 1, 0),
-- 1007
(211674, 1007, 0, 0, 256, 1, 200.1042, 121.5174, 138.4295, 3.127782, 0, 0, 0, 1, 7200, 0, 1, 0),
-- 959
(211674, 959, 0, 0, 256, 1, 3664.662, 2555.559, 766.9572, 5.191139, 0, 0, 0, 1, 7200, 0, 1, 0),
-- 1011
(211674, 1011, 0, 0, 256, 1, 1477.424, 5115.783, 161.7399, 4.792697, 0, 0, 0, 1, 7200, 0, 1, 0);
UPDATE `version` SET  `cache_id` = `cache_id` + 1;