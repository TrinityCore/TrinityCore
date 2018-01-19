UPDATE `spell_proc` SET `SpellFamilyMask0`=0x0600020E WHERE `SpellId`=-14186;
UPDATE `spell_proc` SET `SpellFamilyMask0`=0x208C0400, `SpellFamilyMask1`=0x00000208, `ProcFlags`=16 WHERE `SpellId` IN (26135, 34258, 34262, 37195, 48835, -53695);
UPDATE `spell_proc` SET `SchoolMask`=0x30 WHERE `SpellId`=53386;

DELETE FROM `spell_proc` WHERE `SpellId` IN (-16689, 71567);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-16689, 0x0, 0, 0x00000000, 0x00000000, 0x00000000, 0x0, 0x1, 0x0, 0x0, 0x0, 0, 0, 0, 0), -- Nature's Grasp
(71567,  0x0, 0, 0x00000000, 0x00000000, 0x00000000, 0x0, 0x2, 0x2, 0x0, 0x0, 0, 0, 0, 0); -- Ephemeral Snowflake

UPDATE `spell_proc` SET `AttributesMask`=`AttributesMask` & (~0x2) WHERE `SpellId` IN
(-7001, -974, -168, -324, 44543, 44545, 15286, -53380, -51634, 64890, 55689, 48504, 13234, 72059, -14892, -53290, 41350, -49200, -53486, 71406, 71545, -7302, -30482, 13159, 5118, -52127, 21084, 12328, -51682, -31226, -14186, 37381, -15337, -47230, -51625, 71756, 72782, 72783, 72784, -50880, -34753, -33150, -19184, 71571, 71573, 71865, 71868, 75490, 75495, -11185, 26135, 31801, 34258, 34262, 37195, -47516, 48835, -53569, 53651, -53695, 53736, 58677);
