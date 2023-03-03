DELETE FROM `spell_proc_check` WHERE (`entry`='56218') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='146739') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='56218') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='348') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');

DELETE FROM `spell_proc_event` WHERE `entry` IN (56218);
INSERT INTO `spell_proc_event` VALUES (56218, 0, 0, 6, 0, 0, 0, 0, 0, 0, 100, 0, 7);

DELETE FROM `spell_script_names` WHERE (`spell_id`='131079') AND (`ScriptName`='spell_mage_glyph_of_icy_veins_damage');
DELETE FROM `spell_script_names` WHERE (`spell_id`='131080') AND (`ScriptName`='spell_mage_glyph_of_icy_veins_damage');
DELETE FROM `spell_script_names` WHERE (`spell_id`='131081') AND (`ScriptName`='spell_mage_glyph_of_icy_veins_damage');

DELETE FROM `spell_proc_check` WHERE (`entry`='76613') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='116') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='76613') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='44614') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');

DELETE FROM `spell_proc_event` WHERE `entry` IN (76613);
INSERT INTO `spell_proc_event` VALUES (76613, 0, 0, 32, 4096, 0, 32+64, 0, 0, 0, 100, 0, 7);