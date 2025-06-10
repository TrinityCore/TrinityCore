-- SpellArea
DELETE FROM `spell_area` WHERE `area` = 7581 AND `spell` = 224240;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(224240, 7502, 44184, 0, 0, 0, 2, 0x03, 64, 11);

-- ScriptName
DELETE FROM `spell_script_names` WHERE `spell_id` = 224240;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(224240, 'spell_dalaran_order_campaign_intro_aura');
