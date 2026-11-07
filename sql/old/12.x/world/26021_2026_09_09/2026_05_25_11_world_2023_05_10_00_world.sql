--
DELETE FROM `vehicle_template_accessory` WHERE `entry`=36794 AND `seat_id`=0;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(36794, 36658, 0, 0, 'Scourgelord Tyrannus on Scourgelord Tyrannus', 6, 300);
