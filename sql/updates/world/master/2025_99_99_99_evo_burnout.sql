DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_evo_burnout', 'spell_evo_burnout_proc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(375801, 'spell_evo_burnout'),
(361469, 'spell_evo_burnout_proc');

DELETE FROM `spell_proc` WHERE `SpellId` IN (375801);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(375801,0x00,224,0x00000000,0x00000008,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Burnout
