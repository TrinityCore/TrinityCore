DELETE FROM `spell_proc` WHERE `SpellId` IN (-18213);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-18213,  32,  5, 0x00004000, 0x00000000, 0x00000000,     2, 0x0, 0x0,    0, 0, 0, 0,      0, 0); -- Improved Drain Soul

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warl_improved_drain_soul');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-18213, 'spell_warl_improved_drain_soul');
