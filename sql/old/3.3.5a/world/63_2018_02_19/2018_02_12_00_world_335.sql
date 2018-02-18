UPDATE `spell_proc` SET `SpellFamilyMask0`=0, `SpellFamilyMask1`=0, `SpellFamilyMask2`=0, `AttributesMask`=(`AttributesMask` & ~0x8) WHERE `SpellId` IN (57529, 57531);
