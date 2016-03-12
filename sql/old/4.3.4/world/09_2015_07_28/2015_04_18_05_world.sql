--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-24869, -61874, -71074, -71068, -71073, -71071)  AND `spell_effect` = 24870;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-24869, 24870, 0, 'Bobbing Apple, Bread of the Dead, Winter Veil Cookie'),
(-61874, 24870, 0, 'Noblegarden Chocolate'),
(-71074, 24870, 0, 'Buttermilk Delight'),
(-71068, 24870, 0, 'Sweet Surprise'),
(-71073, 24870, 0, 'Dark Desire'),
(-71071, 24870, 0, 'Very Berry Cream');
