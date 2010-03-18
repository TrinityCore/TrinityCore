DELETE FROM `spell_proc_event` WHERE `entry` IN (42370);
INSERT INTO `spell_proc_event`
(`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) 
VALUES ( 42370, 0x00,  11, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Merciless Totem of the Third Wind
