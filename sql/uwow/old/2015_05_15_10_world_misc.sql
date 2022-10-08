DELETE FROM `spell_proc_event` WHERE `entry` IN (50034);
INSERT INTO `spell_proc_event` VALUES (50034, 0, 0, 0x00000010, 0, 0, 0, 0, 0, 0, 0, 0, 7);

DELETE FROM `spell_proc_event` WHERE `entry` IN (56835);
INSERT INTO `spell_proc_event` VALUES (56835, 0, 0, 262144+4194304+2, 65536, 512, 0, 0, 0, 0, 0, 0, 7);

DELETE FROM `spell_proc_check` WHERE (`entry`='56835') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='45902') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='56835') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='85948') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='56835') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='50842') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');

DELETE FROM `spell_script_names` WHERE (`spell_id`='45902') AND (`ScriptName`='spell_dk_blood_strike');
DELETE FROM `spell_script_names` WHERE (`spell_id`='49998') AND (`ScriptName`='spell_dk_death_strike');
DELETE FROM `spell_script_names` WHERE (`spell_id`='45477') AND (`ScriptName`='spell_dk_icy_touch');