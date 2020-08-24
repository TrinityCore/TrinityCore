DELETE FROM `spell_proc` WHERE `SpellId` IN (-75806, 85416);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Charges`) VALUES
(-75806, 10, 0, 0x8000 | 0x40000, 1, 2, 0, 0), -- Grand Crusader
(85416, 10, 0x4000, 0, 1, 1, 0, 1); -- Grand Crusader Proc

UPDATE `spell_proc` SET `HitMask`= 0x40 WHERE `SpellId`= -20177; -- Reckoning
UPDATE `spell_proc` SET `ProcFlags`= 0x000222A8, `HitMask`= 0x1 | 0x2 | 0x10 | 0x20, `Cooldown`= 500 WHERE `SpellId`= -49004; -- Scent of Blood
UPDATE `spell_proc` SET `Cooldown`= 5000 WHERE `SpellId`= -49027;
