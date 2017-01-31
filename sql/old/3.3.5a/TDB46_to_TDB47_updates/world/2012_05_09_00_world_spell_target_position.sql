DELETE FROM `spell_target_position` WHERE `id` IN (67834, 68081);
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(67834, 571, 3167.01, 5586.04, 880.067, 0),
(68081, 571, 5857.252, 516.8015, 599.82, 2.987);

UPDATE `spell_target_position` SET `target_position_x`=6136.89,`target_position_y`=4785.55,`target_position_z`=100.673 WHERE `id`=67835;
UPDATE `spell_target_position` SET `target_position_x`=8301.39,`target_position_y`=1501.34,`target_position_z`=870.555 WHERE `id`=67836;
