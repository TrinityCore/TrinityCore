--
DROP TABLE IF EXISTS `vehicle_seat_addon`;
CREATE TABLE `vehicle_seat_addon` (  
  `SeatEntry` INT(4) UNSIGNED NOT NULL COMMENT 'VehicleSeatEntry.dbc identifier',
  `SeatOrientation` FLOAT(6) DEFAULT 0 COMMENT 'Seat Orientation override value',
  `ExitParamX` FLOAT(10) DEFAULT 0,
  `ExitParamY` FLOAT(10) DEFAULT 0,
  `ExitParamZ` FLOAT(10) DEFAULT 0,
  `ExitParamO` FLOAT(10) DEFAULT 0,
  `ExitParamValue` TINYINT(1) DEFAULT 0,
  PRIMARY KEY (`SeatEntry`)
);

INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(2764, 0, -2, 2, 0, 0, 1), -- Traveler's Tundra Mammoth Seat 2
(2765, 0, -2, -2, 0, 0, 1), -- Traveler's Tundra Mammoth Seat 3
(2767, 0, -2, 2, 0, 0, 1), -- Traveler's Tundra Mammoth Seat 2
(2768, 0, -2, -2, 0, 0, 1); -- Traveler's Tundra Mammoth Seat 3
