DELETE FROM `spell_proc_check` WHERE (`entry`='16188') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='0') AND (`hastalent`='-53817') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `actiontype`, `comment`) VALUES ('51505', '51505', '77762', '8', 'Lava Surge');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `actiontype`, `comment`) VALUES ('78674', '78674', '93400', '8', 'Shooting Stars');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `actiontype`, `comment`) VALUES ('8092', '8092', '124430', '8', 'Shadowy Insight');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `actiontype`, `comment`) VALUES ('77762', '51505', '8', 'Lava Surge');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `actiontype`, `comment`) VALUES ('93400', '78674', '8', 'Shooting Stars');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `actiontype`, `comment`) VALUES ('124430', '8092', '8', 'Shadowy Insight');

DELETE FROM `spell_proc` WHERE (`spellId`='144595');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES ('53385', '-144595', '5', 'remove Divine Crusader');

DELETE FROM `spell_proc` WHERE (`spellId`='90174');