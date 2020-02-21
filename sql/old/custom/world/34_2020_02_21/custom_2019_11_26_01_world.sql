-- Battle Trance
UPDATE `spell_proc` SET `SpellFamilyName`= 4, `SpellFamilyMask0`= 0x02000000, `SpellFamilyMask1`= 0x08000000 | 0x00000200, `SpellPhaseMask`= 2, `SpellTypeMask`= 1 WHERE `SpellId`= -12322;

-- Executioner
DELETE FROM `spell_proc` WHERE `SpellId`= -20502;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(-20502, 4, 0x20000000, 0, 1, 2, 0, 0);

-- Meat Cleaver
UPDATE `spell_proc` SET `ProcFlags`= 0 WHERE `SpellId`= -12329;

-- Bloodsurge 
UPDATE `spell_proc` SET  `SpellFamilyMask1`= 0x00000400, `ProcFlags`= 0 WHERE `SpellId`= -46913;
