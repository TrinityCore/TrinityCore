DELETE FROM `spell_proc_check` WHERE (`entry`='145185') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='1752') AND (`hastalent`='84617') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');

DELETE FROM `spell_trigger` WHERE (`spell_id`='145185') AND (`spell_trigger`='145193') AND (`option`='1') AND (`effectmask`='7') AND (`aura`='0') AND (`check_spell_id`='1752');

DELETE FROM `spell_proc_check` WHERE (`entry`='145185') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='14189') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='145185') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='51699') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='145193') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='-84617') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');

DELETE FROM `spell_proc_event` WHERE `entry` IN (145185);
INSERT INTO `spell_proc_event` VALUES (145185, 0, 0, 2, 0, 8388608, 0, 0, 0, 0, 0, 0, 7);

DELETE FROM `spell_proc_check` WHERE (`entry`='114015') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='-86392') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='114015') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='-57841') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='114015') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='-57842') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='114015') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='-121473') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='114015') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='-2098') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');
DELETE FROM `spell_proc_check` WHERE (`entry`='114015') AND (`entry2`='0') AND (`entry3`='0') AND (`checkspell`='-121471') AND (`hastalent`='0') AND (`powertype`='-1') AND (`dmgclass`='-1') AND (`specId`='0');

DELETE FROM `spell_proc_event` WHERE `entry` IN (114015);
INSERT INTO `spell_proc_event` VALUES (114015, 0, 0, 2097152+1048576+131072, 1+8, 8192, 0, 0, 0, 0, 0, 0, 1);