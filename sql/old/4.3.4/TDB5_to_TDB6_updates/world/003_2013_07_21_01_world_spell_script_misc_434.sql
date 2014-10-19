DELETE FROM `spell_script_names` WHERE `spell_id`=-85113;
INSERT INTO `spell_script_names`(`spell_id`, `ScriptName`) VALUES
(-85113,'spell_warl_aftermath');

DELETE FROM `spell_ranks` WHERE `first_spell_id`=85113;
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(85113, 85113, 1),
(85113, 85114, 2);

DELETE FROM `spell_proc_event` WHERE `entry` IN (85113,85114);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(85113, 0, 5, 0x20, 0x800000, 0, 0, 0, 0, 0, 0),
(85114, 0, 5, 0x20, 0x800000, 0, 0, 0, 0, 0, 0);
