delete from spell_target_position where id = 149322;
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(149322, 870, -445.6, -5335.91, 124.88, 0.12);

delete from areatrigger_scripts where entry = 9509;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES 
(9509, 'at_ordos_entrance');

update creature_template set AIName = '', ScriptName = 'boss_ordos' where entry = 72057;