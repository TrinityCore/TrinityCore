-- Stagger
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_monk_stagger', 'spell_monk_stagger_damage_aura', 'spell_monk_stagger_debuff_aura');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(115069, 'spell_monk_stagger'),
(124255, 'spell_monk_stagger_damage_aura'),
(124273, 'spell_monk_stagger_debuff_aura'),
(124274, 'spell_monk_stagger_debuff_aura'),
(124275, 'spell_monk_stagger_debuff_aura');
