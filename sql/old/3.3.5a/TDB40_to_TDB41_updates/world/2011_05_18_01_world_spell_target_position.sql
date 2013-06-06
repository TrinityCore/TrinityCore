-- Fix Argent Crusaders Tabard
DELETE FROM `spell_target_position` WHERE `id`=66238;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(66238,571,8480.062,1092.5375,554.4877,0.6014);
