DELETE FROM spell_script_names WHERE ScriptName IN ('spell_pri_premonition_passive', 'spell_pri_premonition_of_insight', 'spell_pri_premonition_of_piety', 'spell_pri_premonition_of_solace', 'spell_pri_premonition_of_insight_aura', 'spell_pri_premonition_of_piety_aura', 'spell_pri_premonition_of_piety_heal', 'spell_pri_premonition_of_solace_aura', 'spell_pri_premonition_of_solace_absorb');
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES
(443056, 'spell_pri_premonition_passive'),
(428933, 'spell_pri_premonition_of_insight'),
(428930, 'spell_pri_premonition_of_piety'),
(428934, 'spell_pri_premonition_of_solace'),
(428933, 'spell_pri_premonition_of_insight_aura'),
(428930, 'spell_pri_premonition_of_piety_aura'),
(443126, 'spell_pri_premonition_of_piety_heal'),
(428934, 'spell_pri_premonition_of_solace_aura'),
(443526, 'spell_pri_premonition_of_solace_absorb');

DELETE FROM `spell_proc` WHERE `SpellId` IN (428933);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(428933,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x10,0x0,0,0,0,0); -- Premonition of Insight

DELETE FROM `spell_proc` WHERE `SpellId` IN (428934);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(428934,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x10,0x0,0,0,0,0); -- Premonition of Solace
