-- Avalanche cooldown
UPDATE `spell_proc` SET `ProcFlags`= 0, `Cooldown`= 10000 WHERE `SpellId`= 95472;
-- Hurricane Proc flags correction
UPDATE `spell_proc` SET `ProcFlags`= 0 WHERE `SpellId`= 94747;

-- Elemental Slayer
DELETE FROM `spell_enchant_proc_data` WHERE `EnchantID`= 4074;
INSERT INTO `spell_enchant_proc_data` (`EnchantID`, `Chance`, `ProcsPerMinute`, `HitMask`, `AttributesMask`) VALUES
(4074, 0, 2.5, 0, 0);
