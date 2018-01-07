DELETE FROM `instance_template` WHERE `map` = 1456;
INSERT INTO `instance_template` VALUES
(1456, 0, 'instance_eye_of_azshara', 1);

DELETE FROM `instance_encounters` WHERE `entry` IN (1810, 1811, 1812, 1813, 1814);
INSERT INTO `instance_encounters` VALUES
(1810, 0, 91784, 0, 'Warlord Parjesh'),
(1811, 0, 91789, 0, 'Lady Hatecoil'),
(1812, 0, 91797, 0, 'King Deepbeard'),
(1813, 0, 91808, 0, 'Serpentrix'),
(1814, 0, 96028, 1492, 'Wrath of Azshara');
