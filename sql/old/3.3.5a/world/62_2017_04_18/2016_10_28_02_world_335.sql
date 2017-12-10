DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hun_cobra_strikes', 'spell_hun_cobra_strikes_triggered');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-53256, 'spell_hun_cobra_strikes'),
(53257,  'spell_hun_cobra_strikes_triggered');

DELETE FROM `spell_proc` WHERE `SpellId`=53257;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(53257, 0, 9, 0x00000000, 0x10000000, 0x00000000, 16, 0x1, 0x2, 0x2, 0x8, 0, 0, 0, 0);
