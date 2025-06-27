UPDATE `spell_proc` SET `AttributesMask`=`AttributesMask`|0x2 WHERE `SpellId` IN (63280, -51625);
DELETE FROM `spell_proc` WHERE `SpellId`=53651;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(53651, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0x0, 0x2, 0x0, 0x0, 0x2, 0, 0, 0, 0); -- Light's Beacon
