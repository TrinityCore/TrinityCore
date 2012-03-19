DELETE FROM `spell_script_names` WHERE `spell_id` IN (62552,62719,66482);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(62552,'spell_gen_defend'),
(62719,'spell_gen_defend'),
(66482,'spell_gen_defend');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62874,62960,63661,62563,63003,63010,64591,66481,68282,68284,68321,68498,68501);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(62874,'spell_gen_mounted_charge'),
(62960,'spell_gen_mounted_charge'),
(63661,'spell_gen_mounted_charge'),
(62563,'spell_gen_mounted_charge'),
(63003,'spell_gen_mounted_charge'),
(63010,'spell_gen_mounted_charge'),
(64591,'spell_gen_mounted_charge'),
(66481,'spell_gen_mounted_charge'),
(68282,'spell_gen_mounted_charge'),
(68284,'spell_gen_mounted_charge'),
(68321,'spell_gen_mounted_charge'),
(68498,'spell_gen_mounted_charge'),
(68501,'spell_gen_mounted_charge');
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62575,62626,64342,64507,64590,64595,64686,65147,66480,68504);
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(62575,'spell_gen_break_shield'),
(62626,'spell_gen_break_shield'),
(64342,'spell_gen_break_shield'),
(64507,'spell_gen_break_shield'),
(64590,'spell_gen_break_shield'),
(64595,'spell_gen_break_shield'),
(64686,'spell_gen_break_shield'),
(65147,'spell_gen_break_shield'),
(66480,'spell_gen_break_shield'),
(68504,'spell_gen_break_shield');
DELETE FROM `spell_script_names` WHERE `spell_id`=62863;
INSERT INTO `spell_script_names`(`spell_id`,`ScriptName`) VALUES
(62863 ,'spell_gen_tournament_duel');