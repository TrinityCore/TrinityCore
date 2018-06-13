DELETE FROM `spell_proc` WHERE `SpellId` IN (32065, 36659);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(32065, 0x0, 0, 0x00000000, 0x00000000, 0x00000000, 0x80000, 0x1, 0x0, 0x0, 0x0, 0, 0, 0, 0),
(36659, 0x0, 0, 0x00000000, 0x00000000, 0x00000000, 0x80000, 0x1, 0x0, 0x0, 0x0, 0, 0, 0, 0);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_decay_over_time_fungal_decay','spell_gen_decay_over_time_tail_sting');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32065, 'spell_gen_decay_over_time_fungal_decay'),
(36659, 'spell_gen_decay_over_time_tail_sting');
