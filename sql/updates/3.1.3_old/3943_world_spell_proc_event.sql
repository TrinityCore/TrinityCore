DELETE FROM `spell_proc_event` WHERE `entry` IN (52610);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(52610,	0x00,	7,	0x80000000,	0x00000000,	0x00000000,	0x00004000,	0x00000000,	0,	0,	0); -- Savage roar

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (52610, -52610);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 52610, 62071, 0, 'Savage Roar'),
( -52610, -62071, 0, 'Savage Roar');
