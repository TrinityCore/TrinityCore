INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `hastalent`, `actiontype`, `comment`) VALUES ('115043', '134732', '-134732', '5', 'Battle Fatigue');

DELETE FROM `spell_script_names` WHERE (`spell_id`='51505') AND (`ScriptName`='spell_mastery_elemental_overload');
DELETE FROM `spell_script_names` WHERE (`spell_id`='117014') AND (`ScriptName`='spell_mastery_elemental_overload');
DELETE FROM `spell_script_names` WHERE (`spell_id`='403') AND (`ScriptName`='spell_mastery_elemental_overload');
DELETE FROM `spell_script_names` WHERE (`spell_id`='421') AND (`ScriptName`='spell_mastery_elemental_overload');

DELETE FROM `spell_proc_event` WHERE `entry` IN (77222);
INSERT INTO `spell_proc_event` VALUES (77222, 0, 0, 1+2, 4096+4, 0, 4, 0, 0, 0, 100, 0, 7);

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `effectmask`, `chance`, `check_spell_id`, `comment`) VALUES ('77222', '77451', '20', '1', '101', '51505', 'MasteryElementalOverload');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `effectmask`, `chance`, `check_spell_id`, `comment`) VALUES ('77222', '45284', '20', '1', '101', '403', 'MasteryElementalOverload');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `effectmask`, `chance`, `check_spell_id`, `comment`) VALUES ('77222', '45297', '20', '1', '101', '421', 'MasteryElementalOverload');
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `effectmask`, `chance`, `check_spell_id`, `comment`) VALUES ('77222', '120588', '20', '1', '101', '117014', 'MasteryElementalOverload');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('117014', '118515', 'Elemental Blast');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('117014', '118517', 'Elemental Blast');

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('120588', '118515', 'Elemental Blast');
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES ('120588', '118517', 'Elemental Blast');

INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `effectmask`, `chance`, `check_spell_id`, `comment`) VALUES ('77222', '114738', '20', '1', '101', '114074', 'MasteryElementalOverload');

DELETE FROM `spell_script_names` WHERE (`spell_id`='421') AND (`ScriptName`='spell_sha_rolling_thunder');
DELETE FROM `spell_script_names` WHERE (`spell_id`='45284') AND (`ScriptName`='spell_sha_rolling_thunder');
DELETE FROM `spell_script_names` WHERE (`spell_id`='403') AND (`ScriptName`='spell_sha_rolling_thunder');
DELETE FROM `spell_script_names` WHERE (`spell_id`='45297') AND (`ScriptName`='spell_sha_rolling_thunder');

DELETE FROM `spell_proc_event` WHERE `entry` IN (88764);
INSERT INTO `spell_proc_event` VALUES (88764, 0, 0, 3, 2147483648, 0, 1, 0, 0, 0, 0, 0, 7);

DELETE FROM `spell_proc_check` WHERE (`entry`='88764') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='421') AND (`hastalent`='324') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='88764') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='403') AND (`hastalent`='324') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');