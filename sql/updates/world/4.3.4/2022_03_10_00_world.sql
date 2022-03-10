UPDATE `spell_proc` SET `ProcFlags`= 0, `SpellTypeMask`= 1 WHERE `SpellId`= 79683;
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x20000000 | 0x2 | 0x1 | 0x10 | 0x200 | 0x40 | 0x20 | 0x20000 | 0x400000 | 0x1000 | 0x4 | 0x80 | 0x800000, `SpellFamilyMask1`= 0x8000 | 0x1000,  `SpellFamilyMask2`= 0x0, `ProcFlags`= 0, `SpellTypeMask`= 1 WHERE `SpellId`= 79684;
