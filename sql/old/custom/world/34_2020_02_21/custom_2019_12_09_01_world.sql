-- Tamed Pet Passive 07 (DND)
UPDATE `spell_proc` SET `SpellFamilyName`= 9, `SpellFamilyMask0`= 0x00080000, `HitMask`= 0 WHERE `SpellId`= 20784;
-- Cobra Strikes
UPDATE `spell_proc` SET `SpellFamilyName`= 9, `SpellFamilyMask0`= 0x00000800, `SpellFamilyMask1`= 0, `SpellTypeMask`= 1, `HitMask`= 0 WHERE `SpellId`= -53256;
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x00080000, `SpellFamilyMask1`= 0  WHERE `SpellId`= 53257;
-- Invigoration
UPDATE `spell_proc` SET `SpellFamilyName`= 9, `SpellFamilyMask0`= 0x00080000  WHERE `SpellId`= 53397;
