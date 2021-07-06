-- Allow Arcane Missiles to proc on cast instead of on hit
UPDATE `spell_proc` SET `SpellPhaseMask`= 1 WHERE `SpellId`= 79684;
