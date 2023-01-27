DELETE FROM `spell_script_names` WHERE (`spell_id`='768') AND (`ScriptName`='spell_dru_killer_instinct');
DELETE FROM `spell_script_names` WHERE (`spell_id`='5487') AND (`ScriptName`='spell_dru_killer_instinct');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-108299', '-108300', 'Druid - Killer Instinct Remove');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-768', '-108300', 'Druid - Killer Instinct Remove');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('-5487', '-108300', 'Druid - Killer Instinct Remove');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `comment`) VALUES ('768', '108300', '108299', 'Druid - Killer Instinct');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `comment`) VALUES ('5487', '108300', '108299', 'Druid - Killer Instinct');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `comment`) VALUES ('108299', '108300', '768', 'Druid - Killer Instinct');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `comment`) VALUES ('108299', '108300', '5487', 'Druid - Killer Instinct');