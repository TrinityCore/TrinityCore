-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27409,27467) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2740900,2740901) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2740900, 9, 0, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Script - Inc Phase"),
(2740900, 9, 1, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 53, 1, 27409, 0, 12308, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Script - Start Waypoint"),
(2740900, 9, 2, 0, 0, 0, 100, 512, 1000, 1000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 19, 27411, 10, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Script - Set Data 1 1"),
(2740900, 9, 3, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 11, 48683, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Script - Cast 'Escape from Silverbrook Periodic'"),
(2740900, 9, 4, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Script - Store Targetlist"),
(2740901, 9, 0, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Script - Inc Phase"),
(2740901, 9, 1, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 12, 27467, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 0, 3437.23, -2795.77, 201.527, 5.81195, "Ducal's Horse - Action list - Summon creature"),
(2740901, 9, 2, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 12, 27467, 4, 20000, 0, 0, 0, 8, 0, 0, 0, 0, 3446.18, -2787.37, 201.793, 4.88692, "Ducal's Horse - Action list - Summon creature"),
(2740901, 9, 3, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 11, 48681, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - Action list - cast Summon Silverbrook Worgen"),
(2740901, 9, 4, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 11, 48681, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - Action list - cast Summon Silverbrook Worgen"),
(2740901, 9, 5, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - Action list - Set unitflag"),
(2740901, 9, 6, 0, 0, 0, 100, 512, 1000, 1000, 0, 0, 0, 11, 50630, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - Action list - Cast 'Eject All Passengers'"),
(2740901, 9, 7, 0, 0, 0, 100, 512, 2000, 2000, 0, 0, 0, 85, 50473, 2, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - Action list - Cast 'Escape from Silverbrook Credit'"),
(2740901, 9, 8, 0, 0, 0, 100, 512, 2000, 2000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 27411, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - Action list - Despawn"),
(2740901, 9, 9, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - Action list - Despawn"),
(27409, 0, 0, 0, 27, 0, 100, 512, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Passenger Boarded - Inc Phase"),
(27409, 0, 1, 0, 27, 2, 100, 512, 0, 0, 0, 0, 0, 80, 2740900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Passenger Boarded (Phase 2) - Run Script"),
(27409, 0, 2, 0, 40, 0, 100, 512, 103, 0, 0, 0, 0, 80, 2740901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Waypoint 103 Reached - Action list"),
(27409, 0, 3, 0, 40, 0, 100, 512, 37, 0, 0, 0, 0, 97, 25, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 4063.24, -2261.99, 215.989, 0, "Ducal's Horse - On Waypoint 37 Reached - Jump To Pos"),
(27409, 0, 4, 0, 40, 0, 100, 512, 75, 0, 0, 0, 0, 97, 25, 10, 0, 0, 0, 0, 1, 0, 0, 0, 0, 3900.4, -2743.33, 219.152, 0, "Ducal's Horse - On Waypoint 75 Reached - Jump To Pos"),
(27409, 0, 5, 6, 28, 4, 100, 512, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 27411, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Passenger Removed (Phase 4) - Despawn"),
(27409, 0, 6, 0, 61, 4, 100, 512, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - On Passenger Removed (Phase 4) - Despawn In 500 ms"),
(27409, 0, 7, 8, 1, 0, 100, 513, 300000, 300000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 19, 27411, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - OOC - Despawn"),
(27409, 0, 8, 0, 61, 0, 100, 512, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Ducal's Horse - OOC - Despawn"),
(27467, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 69, 0, 0, 0, 3, 0, 0, 19, 27409, 0, 0, 0, 0, 0, 0, 0, "Amberpine Hunter - On Just summoned - Move to target"),
(27467, 0, 1, 0, 1, 0, 100, 0, 3000, 3000, 2000, 2000, 0, 11, 47001, 64, 0, 0, 0, 0, 19, 27417, 0, 0, 0, 0, 0, 0, 0, "Amberpine Hunter - Ooc - Cast shot"),
(27467, 0, 2, 0, 0, 0, 100, 0, 2000, 2000, 2000, 2000, 0, 11, 47001, 64, 0, 0, 0, 0, 19, 27417, 0, 0, 0, 0, 0, 0, 0, "Amberpine Hunter - IC - Cast shot");

DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry` IN (861,862);
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(861, 0, -2, 2, 0, 0, 1),
(862, 0, -2, 3, 0, 0, 1);
