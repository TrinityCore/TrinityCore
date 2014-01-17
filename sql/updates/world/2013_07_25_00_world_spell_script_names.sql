DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_warl_banish',
'spell_dru_enrage',
'spell_pri_mana_burn',
'spell_pri_guardian_spirit',
'spell_dk_improved_blood_presence',
'spell_dk_improved_frost_presence',
'spell_dk_improved_unholy_presence',
'spell_dk_presence'
);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-710,  'spell_warl_banish'),
(5229,  'spell_dru_enrage'),
(8129,  'spell_pri_mana_burn'),
(47788, 'spell_pri_guardian_spirit'),
(-50365,'spell_dk_improved_blood_presence'),
(-50384,'spell_dk_improved_frost_presence'),
(-50391,'spell_dk_improved_unholy_presence'),
(48266, 'spell_dk_presence'),
(48263, 'spell_dk_presence'),
(48265, 'spell_dk_presence');
