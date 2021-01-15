DELETE FROM `spell_script_names` WHERE `spell_id`=-47569;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-47569,'spell_pri_phantasm');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=47569;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(47569, 47569, 1),
(47569, 47570, 2);

DELETE FROM `spell_proc_event` WHERE `entry` IN (47569,47570);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(47569, 0, 6, 16384, 0, 0, 16384, 0, 0, 100, 0),
(47570, 0, 6, 16384, 0, 0, 16384, 0, 0, 100, 0);
