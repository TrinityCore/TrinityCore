--
DELETE FROM `creature` WHERE `guid` IN (76265,86173,86174,97406,97407,97408,97431);
UPDATE `creature` SET `guid`=76265 WHERE `guid`=306768;
UPDATE `creature` SET `guid`=86173 WHERE `guid`=307921;
UPDATE `creature` SET `guid`=86174 WHERE `guid`=307920;
UPDATE `creature` SET `guid`=97406 WHERE `guid`=307919;
UPDATE `creature` SET `guid`=97407 WHERE `guid`=307922;
UPDATE `creature` SET `guid`=97408 WHERE `guid`=307918;
UPDATE `creature` SET `guid`=97431 WHERE `guid`=307923;
UPDATE `creature` SET `guid`=4152 WHERE `guid`=306763;
-- INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
-- (76265, 4772, 0, 1, 1, 0, 1, -5523.24, -1333.6, 398.555, 2.68781, 120, 0, 0, 0, 0, 0),
-- (86173, 12372, 0, 1, 1, 0, 0, -5509.63, -1323.89, 397.516, 2.32328, 120, 1, 0, 0, 0, 1),
-- (86174, 12373, 0, 1, 1, 0, 0, -5505.42, -1320.18, 397.516, 3.25541, 120, 1, 0, 0, 0, 1),
-- (97406, 12374, 0, 1, 1, 0, 0, -5499.52, -1322.37, 397.516, 0.224179, 120, 1, 0, 0, 0, 1),
-- (97407, 14546, 0, 1, 1, 0, 0, -5508.02, -1334.34, 397.516, 5.21587, 120, 1, 0, 0, 0, 1),
-- (97408, 14547, 0, 1, 1, 0, 0, -5497.96, -1332.61, 397.516, 0.488367, 120, 1, 0, 0, 0, 1),
-- (97431, 14548, 0, 1, 1, 0, 0, -5502.12, -1335.15, 397.516, 0.569738, 120, 1, 0, 0, 0, 1);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnDifficulties`, `phaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(4150,  4772, 0, '0', 0, 0, 1, -5521.92, -1347.17, 398.747, 4.03171, 300, 0, 0, 198, 0, 0),
(4147, 12372, 0, '0', 0, 0, 0, -5524.53, -1354.1, 398.694, 1.43896, 300, 4, 0, 55, 0, 1),
(4148, 12373, 0, '0', 0, 0, 0, -5534.72, -1349.27, 398.769, 4.74149, 300, 4, 0, 42, 0, 1),
(4154, 12374, 0, '0', 0, 0, 0, -5525.74, -1363.56, 398.694, 1.88225, 300, 4, 0, 55, 0, 1),
(4156, 14546, 0, '0', 0, 0, 0, -5529.51, -1376.1, 398.789, 3.57943, 300, 4, 0, 42, 0, 1),
(4149, 14547, 0, '0', 0, 0, 0, -5536.3, -1335.36, 398.769, 1.80959, 300, 4, 0, 55, 0, 1),
(4155, 14548, 0, '0', 0, 0, 0, -5532.46, -1358.99, 398.694, 3.04284, 300, 4, 0, 55, 0, 1);

DELETE FROM `game_event_creature` WHERE `eventEntry` IN (-25,25) AND `guid` IN (76265,86173,86174,97406,97407,97408,97431,  4149,4148,4147,4155,4154,4156,4150);	
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(25,76265),(25,86173),(25,86174),(25,97406),(25,97407),(25,97408),(25,97431),(-25,4149),(-25,4148),(-25,4147),(-25,4155),(-25,4154),(-25,4156),(-25,4150);
-- UPDATE `creature` SET `MovementType`=1, `spawndist`=4 WHERE `guid` IN(4149,4148,4147,4155,4154,4156);
UPDATE `creature` SET `Orientation`=3.172219 WHERE `guid` IN(4152);
