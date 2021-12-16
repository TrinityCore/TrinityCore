--
UPDATE `creature` SET `position_x` = -4115.65, `position_y` = 1112.75, `position_z` = 44.66, `VerifiedBuild` = 15595 WHERE `guid` = 69888 AND `id` = 19504;
UPDATE `creature` SET `position_z` = 44.6498, `VerifiedBuild` = 15595 WHERE `guid` = 69891 AND `id` = 19504;
UPDATE `creature` SET `position_z` = 43.3165, `orientation` = 5.55015, `VerifiedBuild` = 15595 WHERE `guid` = 69886 AND `id` = 19504;
UPDATE `creature` SET `position_x` = -4085.29, `position_y` = 1129.76, `position_z` = 43.3142, `VerifiedBuild` = 15595 WHERE `guid` = 69887 AND `id` = 19504;
UPDATE `creature` SET `position_z` = 41.0155, `VerifiedBuild` = 15595 WHERE `guid` = 69885 AND `id` = 19504;
UPDATE `creature` SET `VerifiedBuild` = 15595 WHERE `guid` IN (69892,69883,69884,69894,69890) AND `id` = 19504;
UPDATE `creature` SET `position_z` = 43.1093, `VerifiedBuild` = 15595 WHERE `guid` = 76071 AND `id` = 21766;
UPDATE `creature` SET `VerifiedBuild` = 15595 WHERE `id` IN (21744,21954,21955,22066,22070,22211,23434,19628,19627,19626,19625,19521,19520,19518,19517);

UPDATE `creature` SET `position_x` = -4107.694, `position_y` = 1146.9323, `position_z` = 44.67322 WHERE `guid` = 69889 AND `id` = 19504;
DELETE FROM `waypoint_data` WHERE `id` = 698890;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(698890,1,-4107.694,1146.9323,44.67322,0,0,0,0,0,0),
(698890,2,-4100.3315,1129.8108,43.024086,0,0,0,0,0,0),
(698890,3,-4107.694,1146.9323,44.67322,0,0,0,0,0,0),
(698890,4,-4112.916,1159.9209,48.367924,0,0,0,0,0,0),
(698890,5,-4121.213,1166.361,49.742924,0,0,0,0,0,0),
(698890,6,-4126.148,1173.9186,49.673985,0,0,0,0,0,0),
(698890,7,-4121.213,1166.361,49.742924,0,0,0,0,0,0),
(698890,8,-4113.244,1160.3164,48.367924,0,0,0,0,0,0);
