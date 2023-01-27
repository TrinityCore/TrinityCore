DELETE FROM `spell_script_names` WHERE (`spell_id`='85673') AND (`ScriptName`='spell_pal_word_of_glory');

DELETE FROM `spell_proc_event` WHERE `entry` IN (86172);
INSERT INTO `spell_proc_event` VALUES (86172, 0, 0, 0, 0, 0, 0, 0x00015510, 0, 0, 100, 0, 7);

DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='130552') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='136494') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='114163') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='85256') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='85673') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='85222') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='84963') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='53600') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='53385') AND (`spell_effect`='90174') AND (`type`='0') AND (`hastalent`='86172');

DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='85673') AND (`spell_effect`='-90174') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='85222') AND (`spell_effect`='-90174') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='84963') AND (`spell_effect`='-90174') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='85256') AND (`spell_effect`='-90174') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='136494') AND (`spell_effect`='-90174') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='53600') AND (`spell_effect`='-90174') AND (`type`='0') AND (`hastalent`='0');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='53385') AND (`spell_effect`='-90174') AND (`type`='0') AND (`hastalent`='0');