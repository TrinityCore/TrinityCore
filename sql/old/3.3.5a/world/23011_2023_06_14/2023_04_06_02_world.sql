-- Warlock - Backlash: Should also proc with absorbs
UPDATE `spell_proc` SET `HitMask`=`HitMask`|0x00000001|0x00000002|0x00000400 WHERE `SpellId`=-34935;
