DELETE FROM `spell_proc` WHERE `SpellId` IN (383634);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(383634,0x00,3,0x00000000,0x04000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Fiery Rush

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_fiery_rush_aura';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(190319, 'spell_mage_fiery_rush_aura');
