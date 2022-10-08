INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `comment`) VALUES ('93098', '132365', '24', 'Warrior - Vengeance');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `aura`, `comment`) VALUES ('84840', '132365', '24', '5487', 'Druid - Vengeance');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `comment`) VALUES ('84839', '132365', '24', 'Paladin - Vengeance');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `comment`) VALUES ('93099', '132365', '24', 'DK - Vengeance');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `comment`) VALUES ('120267', '132365', '24', 'Monk - Vengeance');

DELETE FROM `spell_proc_event` WHERE (`entry`='84840') AND (`effectmask`='7');
DELETE FROM `spell_proc_event` WHERE (`entry`='93098') AND (`effectmask`='7');
DELETE FROM `spell_proc_event` WHERE (`entry`='84839') AND (`effectmask`='7');
DELETE FROM `spell_proc_event` WHERE (`entry`='93099') AND (`effectmask`='7');
DELETE FROM `spell_proc_event` WHERE (`entry`='120267') AND (`effectmask`='7');

DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='-5487') AND (`spell_effect`='-84840') AND (`type`='0') AND (`hastalent`='0');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('768', '-132365', 'Remove - Vengeance');