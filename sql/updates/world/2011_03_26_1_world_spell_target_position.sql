-- Fix Argent Crusader's Tabard teleport location
DELETE FROM `spell_target_position` WHERE `id`=66238;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES 
(66238,571,8491.808594,1100.631470,554.361206,0.693504);