-- Отрицательное значение это аура.
ALTER TABLE `vehicle_template_accessory` CHANGE `entry` `EntryOrAura` MEDIUMINT(8) NOT NULL DEFAULT '0';

-- Aura Hobart''s Ingenious Cap of Mook Foolery
DELETE FROM `vehicle_template_accessory` WHERE `EntryOrAura` = -67435;
INSERT INTO `vehicle_template_accessory` (`EntryOrAura`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) 
VALUES ('-67435', '48925', '0', '1', 'Aura Hobart''s Ingenious Cap of Mook Foolery', '8', '0');