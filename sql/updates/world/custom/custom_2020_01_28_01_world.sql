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
(8372, 3.141592, 0, 0, 0, 0, 0), -- Ozumat
(8426, 3.141592, 0, 0, 0, 0, 0), -- Ozumat
(8450, 3.141592, 0, 0, 0, 0, 0), -- Ozumat
(8451, 3.141592, 0, 0, 0, 0, 0), -- Ozumat
(8453, 3.141592, 0, 0, 0, 0, 0), -- Ozumat
(8030, 0, -9618.6875, -1030.1104, 41.684166, 4.847490787, 2), -- Stormwind Charger Seat 1
(7936, 0, -311.4653, -48.59722, 212.8065, 1.064651, 2), -- Magmaw Seat 3
(8104, 0, -311.4653, -48.59722, 212.8065, 1.064651, 2), -- Magmaw' Pincer Seat 1
(7909, 0, -311.4653, -48.59722, 212.8065, 1.064651, 2), -- Magmaw' Pincer Seat 1
(2764, 0, -2, 2, 0, 0, 1), -- Traveler's Tundra Mammoth Seat 2
(2765, 0, -2, -2, 0, 0, 1), -- Traveler's Tundra Mammoth Seat 3
(2767, 0, -2, 2, 0, 0, 1), -- Traveler's Tundra Mammoth Seat 2
(2768, 0, -2, -2, 0, 0, 1); -- Traveler's Tundra Mammoth Seat 3
