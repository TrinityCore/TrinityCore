--
DELETE FROM `spell_proc` WHERE `SpellID` IN (-11213, 11213, 12574, 12575);
INSERT INTO `spell_proc` (`SpellID`, `SpellTypeMask`, `SpellPhaseMask`, `Chance`) VALUES
(11213, 1, 2, 3),
(12574, 1, 2, 6),
(12575, 1, 2, 10);

