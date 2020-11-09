-- Demonic Pact (Patch 3.3.3 (2010-03-23): This effect now has a 45-second duration, up from 12 seconds, and a 20-second internal cooldown)
UPDATE `spell_proc` SET `Cooldown`=20000 WHERE `SpellId` IN (54909, 53646);
