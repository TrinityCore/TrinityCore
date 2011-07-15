DELETE FROM `spell_script_names` WHERE `spell_id` IN ('16870', '19752', '53487', '54015', '62544', '62575', '62863', '62960', '69672', '69673');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('16870', 'spell_clearcasting'),
('19752', 'spell_divine_intervention'),
('53487', 'spell_oracle_wolvar'),
('54015', 'spell_oracle_wolvar'),
('62544', 'spell_tournament_melee'),
('62575', 'spell_tournament_shield'),
('62863', 'spell_tournament_duel'),
('62960', 'spell_tournament_charge'),
('69672', 'spell_sunreaver_disguise'),
('69673', 'spell_sunreaver_disguise');

DELETE FROM `spell_script_names` WHERE `spell_id` IN ('50334', '58597');
INSERT INTO `spell_script_names` VALUES
(50334, 'spell_dru_berserk'),
(58597, 'spell_pal_sacred_shield');

