-- Drain Soul
-- Disable Proc of Effect0 and Effect1
UPDATE `spell_proc` SET `AttributesMask`=`AttributesMask`|48 WHERE `SpellId`=-1120;
