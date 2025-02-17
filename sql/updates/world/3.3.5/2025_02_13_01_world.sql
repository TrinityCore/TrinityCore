-- DB/Spells: Fix Blade Barrier proc flags
UPDATE `spell_proc` SET `SpellPhaseMask`=1 WHERE `SpellId`=-49182;
