DELETE FROM `playercreateinfo_spell` WHERE (`race`='24') AND (`class`='3') AND (`Spell`='114355');
DELETE FROM `playercreateinfo_spell` WHERE (`race`='24') AND (`class`='4') AND (`Spell`='114355');
DELETE FROM `playercreateinfo_spell` WHERE (`race`='25') AND (`class`='3') AND (`Spell`='114355');
DELETE FROM `playercreateinfo_spell` WHERE (`race`='25') AND (`class`='4') AND (`Spell`='114355');
DELETE FROM `playercreateinfo_spell` WHERE (`race`='26') AND (`class`='3') AND (`Spell`='114355');


DELETE FROM `spell_proc_event` WHERE `entry` IN (124489);
INSERT INTO `spell_proc_event` VALUES (124489, 0, 53, 64+128, 0, 0, 0, 1024+4096, 0, 0, 100, 0, 7);


DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='31224') AND (`spell_effect`='81549') AND (`type`='0') AND (`hastalent`='0') AND (`actiontype`='0');