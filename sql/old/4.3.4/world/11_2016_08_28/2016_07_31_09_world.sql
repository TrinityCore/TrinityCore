--
DELETE FROM `item_template` WHERE `entry` IN (62336,62337,62312);
INSERT INTO `item_template` (`entry`, `name`) VALUES
(62336, 'Plans: <Random Jewelcrafting Design>'),
(62337, 'Plans: <Random Leatherworking Pattern>'),
(62312, 'Plans: <Random Blacksmithing Plan>');
