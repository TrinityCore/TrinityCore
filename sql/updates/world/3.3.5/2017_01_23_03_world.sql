DELETE FROM `spell_proc` WHERE `SpellId`=13234;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(13234, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x0, 0x403, 0x2, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_item_harm_prevention_belt';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(13234, 'spell_item_harm_prevention_belt');
