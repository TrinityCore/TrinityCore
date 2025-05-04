DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_evo_burnout';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(375801,'spell_evo_burnout');

DELETE FROM `spell_proc` WHERE `SpellId` IN (375801,375802);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(375801,0x00,224,0x00000000,0x00000008,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x00,0x0,0,0,0,0), -- Burnout
(375802,0x00,224,0x00000000,0x00100000,0x00000000,0x00000000,0x0,0x4,0x0,0x0,0x0,0x18,0x0,0,0,0,0); -- Burnout
