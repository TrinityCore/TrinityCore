INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(203286,2,3,0x5,0,0,0,0,0,0x1,0,0,0,0,0,0,0); 

-- Add spell script

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(203286, 'spell_mage_greater_pyroblast');
