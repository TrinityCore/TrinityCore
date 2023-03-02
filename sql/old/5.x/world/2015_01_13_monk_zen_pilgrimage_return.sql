DELETE FROM `spell_script_names` WHERE `spell_id` IN (126892, 126895);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (126892, 'spell_monk_zen_pilgrimage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES (126895, 'spell_monk_zen_pilgrimage_return');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=126895 AND `spell_effect`=-126896;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES (126895, -126896, 1, 'Zen Pilgrimage: Return');
