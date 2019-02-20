-- Lock and Load
UPDATE `spell_proc` SET `SpellPhaseMask`=0x2 WHERE `SpellId`=-56342;

-- Entrapment
UPDATE `spell_proc` SET `SpellPhaseMask`=0x4 WHERE `SpellId`=-19184;

-- Pet Healing
UPDATE `spell_proc` SET `AttributesMask`=0x2 WHERE `SpellId`=37381;
