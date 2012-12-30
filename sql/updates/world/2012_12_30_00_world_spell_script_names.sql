DELETE FROM `spell_script_names` WHERE `spell_id` IN (
48792, -- spell_dk_icebound_fortitude
55233, -- spell_dk_vampiric_blood
-1850, -- spell_dru_dash
48391, -- spell_dru_owlkin_frenzy
29166, -- spell_dru_innervate
34246, -- spell_dru_idol_lifebloom
60779, -- spell_dru_idol_lifebloom
-1079, -- spell_dru_rip
1038,  -- spell_pal_hand_of_salvation
58597, -- spell_pal_sacred_shield
5246,  -- spell_warr_intimidating_shout
-772   -- spell_warr_rend
);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(48792, 'spell_dk_icebound_fortitude'),
(55233, 'spell_dk_vampiric_blood'),
(-1850, 'spell_dru_dash'),
(48391, 'spell_dru_owlkin_frenzy'),
(29166, 'spell_dru_innervate'),
(34246, 'spell_dru_idol_lifebloom'),
(60779, 'spell_dru_idol_lifebloom'),
(-1079, 'spell_dru_rip'),
(1038,  'spell_pal_hand_of_salvation'),
(58597, 'spell_pal_sacred_shield'),
(5246,  'spell_warr_intimidating_shout'),
(-772,  'spell_warr_rend');
