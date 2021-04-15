DELETE FROM `command` WHERE `name` IN('reload vehicle_accessory','reload vehicle_template_accessory');
INSERT INTO `command` (`name`,`security`,`help`) VALUES
('reload vehicle_accessory', 3, 'Syntax: .reload vehicle_accessory\n\nReloads GUID-based vehicle accessory definitions from the database.'),
('reload vehicle_template_accessory', 3, 'Syntax: .reload vehicle_template_accessory\n\nReloads entry-based vehicle accessory definitions from the database.');
