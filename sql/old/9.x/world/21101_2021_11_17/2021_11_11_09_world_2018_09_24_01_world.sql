-- Battlegear of Eternal Justice
UPDATE `spell_proc` SET `ProcFlags` = `ProcFlags` |16 WHERE `SpellId` = 26135;
-- judgement set bonus
DELETE FROM `spell_proc` WHERE `SpellId` = 23591;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(23591, 0, 10, 8388608, 0, 0, 16, 0, 2, 0, 2, 0, 0, 0, 0);
