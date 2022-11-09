UPDATE `spell_proc` SET `Cooldown`= 8 WHERE `SpellId`= -29074; -- Master of Elements
UPDATE `spell_proc` SET `Cooldown`= 8 WHERE `SpellId`= 10400; -- Flametongue (Passive)
UPDATE `spell_proc` SET `Cooldown`= 100 WHERE `SpellId`= 56835; -- Reaping (Passive)
UPDATE `spell_proc` SET `Cooldown`= 500 WHERE `SpellId`= 16164; -- Elemental Focus
UPDATE `spell_proc` SET `Cooldown`= 500 WHERE `SpellId`= 56821; -- Glyph of Sinister Strike

-- Arcane Concentration
DELETE FROM `spell_proc` WHERE `SpellId` IN (11213, 12574, 12575, -11213);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellTypeMask`, `SpellPhaseMask`, `Cooldown`) VALUES
(-11213, 3, 1, 2, 15000);
