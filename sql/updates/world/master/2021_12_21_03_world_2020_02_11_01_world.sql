-- 
UPDATE `smart_scripts` SET `event_param3`=3000, `event_param4`=3000, `action_type`=86, `action_param1`=69352, `action_param2`=32, `action_param3`=29, `action_param4`=0, `target_type`=21, `target_param1`=5, `target_param2`=0 WHERE `entryorguid` IN (37966,37980,36812) AND `id`=6;
UPDATE `smart_scripts` SET `action_param1`=69352 WHERE `entryorguid` IN (37966,37980,36812) AND `source_type`=0 AND `id`=7;
DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry` IN (6446, 6447, 7326, 7327, 7328, 7329);
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(6446, 0, -1, 4, 3, 0, 1),
(6447, 0, 1, 4, 3, 0, 1),
(7326, 0, -1, 4, 3, 0, 1),
(7327, 0, 1, 4, 3, 0, 1),
(7328, 0, -1, 4, 3, 0, 1),
(7329, 0, 1, 4, 3, 0, 1);
