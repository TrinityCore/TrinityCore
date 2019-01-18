DROP TABLE IF EXISTS `vehicle_seat_addon`;
CREATE TABLE `vehicle_seat_addon`(  
  `SeatID` MEDIUMINT(8) UNSIGNED NOT NULL COMMENT 'VehicleSeat.dbc identifier',
  `Angle` FLOAT UNSIGNED NOT NULL  COMMENT 'Seat angle override field',
  PRIMARY KEY (`SeatID`)
);

DELETE FROM `vehicle_seat_addon` WHERE `SeatID` IN (8372, 8450, 8451, 8453, 8426);
INSERT INTO `vehicle_seat_addon` (`SeatID`, `Angle`) VALUES
(8372, 180),
(8426, 180),
(8450, 180),
(8451, 180),
(8453, 180);
