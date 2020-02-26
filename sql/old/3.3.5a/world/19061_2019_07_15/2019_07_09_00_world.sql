--
SET @GUID := 9867;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @GUID AND @GUID+22;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation2`, `rotation3`, `spawntimesecs`, `state`) VALUES
(@GUID   , 187675, 571, 3567.028, 5530.725, 86.75361, -2.91469, -0.9935713, 0.1132084, -60, 1),
(@GUID+1 , 187676, 571, 3558.709, 5530.077, 75.47846, 2.82743, 0.9876881, 0.1564362, -60, 1),
(@GUID+2 , 187676, 571, 3562.421, 5538.395, 75.21444, -1.553341, -0.7009087, 0.7132511, -60, 1),
(@GUID+3 , 187676, 571, 3581.925, 5524.272, 86.65974, 1.396262, 0.642787, 0.766045, -60, 1),
(@GUID+4 , 187676, 571, 3565.865, 5514.692, 85.72919, 2.059488, 0.8571672, 0.5150382, -60, 1),
(@GUID+5 , 187676, 571, 3551.815, 5537.208, 85.85419, 0.5934101, 0.2923708, 0.956305, -60, 1),
(@GUID+6 , 187676, 571, 3571.787, 5544.2, 87.26057, 0.383971, 0.1908083, 0.9816273, -60, 1),
(@GUID+7 , 187676, 571, 3580.394, 5536.65, 86.5073, 1.134463, 0.5372992, 0.8433917, -60, 1),
(@GUID+8 , 187676, 571, 3573.253, 5517.944, 86.92722, 2.024579, 0.8480473, 0.5299206, -60, 1),
(@GUID+9 , 187676, 571, 3560.757, 5544.268, 87.7508, -0.5061446, -0.2503796, 0.9681478, -60, 1),
(@GUID+10, 187676, 571, 3571.316, 5533.095, 74.98383, -1.239183, -0.5807028, 0.8141156, -60, 1),
(@GUID+11, 187675, 571, 3590.992, 5631.12, 75.53494, 1.186823, 0.5591927, 0.8290377, -60, 1),
(@GUID+12, 187676, 571, 3595.712, 5626.938, 65.27551, -3.124123, -0.9999619, 0.008734641, -60, 1),
(@GUID+13, 187676, 571, 3594.721, 5637.131, 65.02226, 0.95993, 0.4617481, 0.8870111, -60, 1),
(@GUID+14, 187676, 571, 3607.263, 5631.061, 75.13552, -1.099556, -0.5224981, 0.8526405, -60, 1),
(@GUID+15, 187676, 571, 3601.689, 5621.226, 75.40459, -1.221729, -0.573576, 0.8191524, -60, 1),
(@GUID+16, 187676, 571, 3592.143, 5614.887, 75.2258, 2.862335, 0.9902678, 0.1391754, -60, 1),
(@GUID+17, 187676, 571, 3580.775, 5620.292, 75.61076, 1.06465, 0.5075378, 0.8616294, -60, 1),
(@GUID+18, 187676, 571, 3575.896, 5629.07, 75.41689, -2.007128, -0.8433914, 0.5372996, -60, 1),
(@GUID+19, 187676, 571, 3579.39, 5642.362, 77.59373, -1.012289, -0.4848089, 0.8746201, -60, 1),
(@GUID+20, 187676, 571, 3591.921, 5646.228, 75.15994, 2.042035, 0.8526402, 0.5224986, -60, 1),
(@GUID+21, 187676, 571, 3601.01, 5642.266, 75.64725, 1.483528, 0.6755896, 0.7372779, -60, 1),
(@GUID+22, 187676, 571, 3586.417, 5635.277, 65.31032, 1.815142, 0.7880106, 0.6156617, -60, 1);

UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id` IN (25441, 25442, 25443);
UPDATE `creature` SET `position_z`=66.0809 WHERE `id`=25441;
UPDATE `creature` SET `position_z`=75.99450 WHERE `id`=25443;
UPDATE `gameobject` SET `spawntimesecs`=-60 WHERE `id` IN (187675, 187676);

UPDATE `smart_scripts` SET `link`=1 WHERE `entryorguid` IN (25441, 25442, 25443) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25441, 25442, 25443) AND `source_type`=0 AND `id` IN (1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25441, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 15, 187675, 50, 0, 0, 0, 0, 0, 0, "North Platform - On Spellhit 'Throw Gnomish Grenade' - Respawn Nearby Gameobjects 'Borean Tundra Fire Large'"),
(25441, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 15, 187676, 50, 0, 0, 0, 0, 0, 0, "North Platform - On Spellhit 'Throw Gnomish Grenade' - Respawn Nearby Gameobjects 'Borean Tundra Fire Small'"),
(25442, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 15, 187675, 50, 0, 0, 0, 0, 0, 0, "East Platform - On Spellhit 'Throw Gnomish Grenade' - Respawn Nearby Gameobjects 'Borean Tundra Fire Large'"),
(25442, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 15, 187676, 50, 0, 0, 0, 0, 0, 0, "East Platform - On Spellhit 'Throw Gnomish Grenade' - Respawn Nearby Gameobjects 'Borean Tundra Fire Small'"),
(25443, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 15, 187675, 50, 0, 0, 0, 0, 0, 0, "West Platform - On Spellhit 'Throw Gnomish Grenade' - Respawn Nearby Gameobjects 'Borean Tundra Fire Large'"),
(25443, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 70, 60, 0, 0, 0, 0, 0, 15, 187676, 50, 0, 0, 0, 0, 0, 0, "West Platform - On Spellhit 'Throw Gnomish Grenade' - Respawn Nearby Gameobjects 'Borean Tundra Fire Small'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=45583;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 45583, 0, 0, 29, 0, 25441, 40, 0, 0, 0, 0, "", "Throw Gnomish Grenade can be used within 40 yards of North Platform OR"),
(17, 0, 45583, 0, 1, 29, 0, 25442, 40, 0, 0, 0, 0, "", "Throw Gnomish Grenade can be used within 40 yards of East Platform OR"),
(17, 0, 45583, 0, 2, 29, 0, 25443, 40, 0, 0, 0, 0, "", "Throw Gnomish Grenade can be used within 40 yards of West Platform");
