DELETE FROM `spell_proc_event` WHERE `entry` = 70656;

UPDATE `quest_template` SET `NextQuestId` = 3761 WHERE `id` IN (936,3784,3762);

DELETE FROM `spell_proc_event` WHERE `entry` = 63611;
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(63611,0,0,0,0,0,51154,0,0,0,0);
