DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_hun_viper_sting';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warl_drain_mana';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_skull_of_impending_doom';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(3034, 'spell_hun_viper_sting'),
(5138, 'spell_warl_drain_mana'),
(5024, 'spell_item_skull_of_impending_doom');
