DELETE FROM `spell_proc` WHERE `SpellId` IN (383490);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(383490,0x00,3,0x00000000,0x04000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Wildfire

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_wildfire', 'spell_mage_wildfire_area');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(383492, 'spell_mage_wildfire_caster_crit'),
(383493, 'spell_mage_wildfire_area_crit');
