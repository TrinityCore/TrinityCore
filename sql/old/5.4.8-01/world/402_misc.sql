REPLACE INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(77222, 0, 11, 3, 4096, 0, 4, 65536, 0, 0, 100, 0);

REPLACE INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
(77756, 0, 11, 268435456, 0, 0, 0, 262144, 1027, 0, 20, 0);

REPLACE INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES 
(45284, 0.225, -1, -1, -1, 'Shaman - Lightning Bolt for Mastery'),
(45297, 0.1, -1, -1, -1, 'Shaman - Chain Lightning for Mastery'),
(77451, 0.75, -1, -1, -1, 'Shaman - Lava Burst for Mastery'),
(120588, 1.584, -1, -1, -1, 'Shaman - Elemental Blast for Mastery');

DELETE FROM `spell_script_names` WHERE `scriptname`='spell_sha_lava_surge';
DELETE FROM `spell_script_names` WHERE `scriptname`='spell_sha_lava_burst';
DELETE FROM `spell_script_names` WHERE `scriptname`='spell_mastery_elemental_overload_damage';
DELETE FROM `spell_script_names` WHERE `scriptname`='spell_mastery_elemental_overload';