--
DELETE FROM `vehicle_template_accessory` WHERE `entry`=33109 AND `accessory_entry`=33620 AND `seat_id`=2;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`) VALUES
(33109,33620,2,1,'Salvaged Demolisher - Earthen Stoneshaper');
