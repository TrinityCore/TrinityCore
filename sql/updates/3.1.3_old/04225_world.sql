DELETE FROM `spell_proc_event` WHERE `entry` IN (48492, 48494, 48495);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(   48492, 0x00,   7, 0x00080000, 0x00000000, 0x00000800, 0x00000400, 0x00000000,   0,   0,   0), -- King of the Jungle (Rank1)
(   48494, 0x00,   7, 0x00080000, 0x00000000, 0x00000800, 0x00000400, 0x00000000,   0,   0,   0), -- King of the Jungle (Rank2)
(   48495, 0x00,   7, 0x00080000, 0x00000000, 0x00000800, 0x00000400, 0x00000000,   0,   0,   0); -- King of the Jungle (Rank3)

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-5229);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( -5229, -51185, 0, 'King of the Jungle - remove with enrage');
