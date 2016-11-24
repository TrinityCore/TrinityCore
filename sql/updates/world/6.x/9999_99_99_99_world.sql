DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 152150;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (152150, 163786, 0, 'Rogue - Talent Death From Above Damage Mods');

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry` = 156327;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0, 156327, 64, '', '', 'Ignore LOS on Death from Above Jump');

DELETE FROM `spell_script_names` WHERE `ScriptName` LIKE 'spell_rog_death_from_above%';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(152150, 'spell_rog_death_from_above'),
(156327, 'spell_rog_death_from_above_jump_target'),
(178070, 'spell_rog_death_from_above_damage'),
(163786, 'spell_rog_death_from_above_dmg_aura'),
(178236, 'spell_rog_death_from_above_pre_jump');
