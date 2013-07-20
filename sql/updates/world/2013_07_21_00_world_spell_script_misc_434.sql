DELETE FROM `spell_script_names` WHERE `spell_id`=-19572;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-19572,'spell_hun_improved_mend_pet');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=19572;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(19572, 19572, 1),
(19572, 19573, 2);

DELETE FROM `spell_proc_event` WHERE `entry` IN (19572,19573);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(19572, 0, 9, 8388608, 0, 0, 0x4000, 0, 0, 100, 0),
(19573, 0, 9, 8388608, 0, 0, 0x4000, 0, 0, 100, 0);
