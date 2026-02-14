DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_power_surge','spell_pri_power_surge_periodic_holy','spell_pri_power_surge_periodic_shadow');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(453109,'spell_pri_power_surge'),
(453112,'spell_pri_power_surge_periodic_holy'),
(453113,'spell_pri_power_surge_periodic_shadow');

DELETE FROM `spell_proc` WHERE `SpellId` IN (453109);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(453109,0x00,6,0x00000000,0x00000000,0x00000000,0x00000040,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Power Surge
