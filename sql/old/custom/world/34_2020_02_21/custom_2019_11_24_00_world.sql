UPDATE `spell_proc` SET `Cooldown`= 0 WHERE `SpellId` IN (92086, 92090, 92105, 91339, 91811);
UPDATE `spell_proc` SET `Cooldown`= 500 WHERE `SpellId` IN (90943, 90986);
UPDATE `spell_proc` SET `Cooldown`= 50000 WHERE `SpellId` IN (91814, 91193, 90848);
UPDATE `spell_proc` SET `Cooldown`= 100000 WHERE `SpellId` IN (91025, 92322, 91080, 90892, 95878);
UPDATE `spell_proc` SET `Cooldown`= 0, `ProcsPerMinute`= 0.92 WHERE `SpellId` IN (92175, 91144);
UPDATE `spell_proc` SET `Cooldown`= 0, `ProcsPerMinute`= 0.85 WHERE `SpellId`= 90899;
