DELETE FROM `spell_proc_event` WHERE `entry` IN (44544, 60503, 36032);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(36032, 0x00, 3, 0x00000800, 0x00008000, 0x00000000, 0x00000000, 0x00000000, 0, 0, 0); -- Arcane Blast

DELETE FROM `spell_affect` WHERE `entry` IN (44544);
INSERT INTO `spell_affect` (`entry`, `effectId`, `SpellClassMask0`, `SpellClassMask1`, `SpellClassMask2`) VALUES
(44544,0,685904631,1151048,0); -- Fingers of frost
