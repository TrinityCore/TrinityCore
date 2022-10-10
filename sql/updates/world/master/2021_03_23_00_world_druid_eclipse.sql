DELETE FROM `spell_proc` WHERE `SpellId`=79577;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(79577,0,7,0x5,0,0,0,0,0,0x1,0,0,0,0,0,0,0); -- Eclipse, proc on launch of Wrath and Starfire

-- Add eclipse spell script
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_eclipse_dummy', 'spell_dru_eclipse_aura', 'spell_dru_eclipse_ooc');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79577, 'spell_dru_eclipse_dummy'),
(48517, 'spell_dru_eclipse_aura'),
(48518, 'spell_dru_eclipse_aura'),
(329910, 'spell_dru_eclipse_ooc');
