-- add missing localization for item "Bamboo Cage Key" (entry: 12301)
DELETE FROM `locales_item` WHERE `entry`=12301;
INSERT INTO `locales_item` (`entry`, `name_loc2`, `name_loc3`, `name_loc6`, `name_loc7`, `name_loc8`) VALUES
(12301, 'Clé de la cage en bambou', 'Bambuskäfigschlüssel', 'Llave de jaula de bambú', 'Llave de jaula de bambú', 'Ключ от бамбуковой клетки');
