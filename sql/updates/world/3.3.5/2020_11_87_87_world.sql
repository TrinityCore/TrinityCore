-- Disable proc of Drain Soul (will be handled by script)
UPDATE `spell_proc` SET `AttributesMask`=0, `DisableEffectsMask`=7 WHERE `SpellId`=-1120;
