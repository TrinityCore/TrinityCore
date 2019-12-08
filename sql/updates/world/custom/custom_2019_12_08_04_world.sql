-- Soul Leech
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0x00000080, `SpellFamilyMask1`= 0x00000080 | 0x00020000 WHERE `SpellId`= -30293;

-- Demonic Pact
DELETE FROM `spell_pet_auras` WHERE `spell`= 47236;
INSERT INTO `spell_pet_auras` (`spell`, `effectId`, `pet`, `aura`) VALUES
(47236, 0, 0, 53646);
