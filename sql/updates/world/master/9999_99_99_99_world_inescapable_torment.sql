DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_inescapable_torment', 'spell_pri_inescapable_torment_aura', 'spell_pri_inescapable_torment_damage');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(8092, 'spell_pri_inescapable_torment'),
(32379, 'spell_pri_inescapable_torment'),
(47758, 'spell_pri_inescapable_torment_aura'),
(373129, 'spell_pri_inescapable_torment_aura'),
(373442, 'spell_pri_inescapable_torment_damage');
