UPDATE `spell_proc_event` SET `Cooldown`='0' WHERE (`entry`='108558') AND (`effectmask`='7');

UPDATE `creature_template` SET `flags_extra`='36' WHERE (`entry`='71790');
UPDATE `creature_template` SET `flags_extra`='36' WHERE (`entry`='71694');
UPDATE `creature_template` SET `flags_extra`='36' WHERE (`entry`='71751');
UPDATE `creature_template` SET `flags_extra`='36' WHERE (`entry`='71606');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES ('148467', '110618', '2', 'Deterrence');

DELETE FROM `spell_proc_event` WHERE `entry` IN (86172);

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('53385', '90174', '86172', '25', '1', 'Divine Purpose');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('53600', '90174', '86172', '25', '1', 'Divine Purpose');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('85222', '90174', '86172', '25', '1', 'Divine Purpose');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('85256', '90174', '86172', '25', '1', 'Divine Purpose');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('85673', '90174', '86172', '25', '1', 'Divine Purpose');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('113075', '90174', '86172', '25', '1', 'Divine Purpose');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('114163', '90174', '86172', '25', '1', 'Divine Purpose');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('136494', '90174', '86172', '25', '1', 'Divine Purpose');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `chance`, `hitmask`, `comment`) VALUES ('138165', '90174', '86172', '25', '1', 'Divine Purpose');

INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `comments`) VALUES ('145110', '56', '16', 'Дар Изеры');

DELETE FROM `spell_target_filter` WHERE (`spellId`='48438') AND (`targetId`='31') AND (`option`='3');
DELETE FROM `spell_target_filter` WHERE (`spellId`='48438') AND (`targetId`='31') AND (`option`='4');

INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `aura`, `count`, `addcount`, `comments`) VALUES ('48438', '31', '62970', '5', '1', 'Wild Growth');
UPDATE `spell_target_filter` SET `resizeType`='1' WHERE (`spellId`='48438') AND (`targetId`='31') AND (`option`='0');
INSERT INTO `spell_target_filter` (`spellId`, `targetId`, `option`, `aura`, `resizeType`, `count`, `comments`) VALUES ('48438', '31', '6', '62970', '1', '5', 'Wild Growth');