DELETE FROM `spell_proc` WHERE `SpellId` IN (-84604, -80128);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-84604, 0, 0, 0, 0, 0, 0, 0, 0x00000020, 0, 0, 0, 0),
(-80128, 4, 0, 0x00000040, 0, 0x00000010, 1, 2, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_warr_devastate';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(20243, 'spell_warr_devastate');
