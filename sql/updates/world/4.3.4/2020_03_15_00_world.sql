ALTER TABLE `vehicle_seat_addon`   
	ADD COLUMN `SeatOffsetX` FLOAT DEFAULT 0 NULL AFTER `SeatEntry`,
	ADD COLUMN `SeatOffsetY` FLOAT DEFAULT 0 NULL AFTER `SeatOffsetX`,
	ADD COLUMN `SeatOffsetZ` FLOAT DEFAULT 0 NULL AFTER `SeatOffsetY`,
	CHANGE `SeatOrientation` `SeatOffsetO` FLOAT DEFAULT 0 NULL COMMENT 'Seat Orientation override value';
