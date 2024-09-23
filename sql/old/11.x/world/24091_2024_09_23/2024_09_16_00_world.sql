DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_pyrogenics';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(387095, 'spell_warl_pyrogenics');

DELETE FROM `spell_proc` WHERE `SpellId` IN (387095);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(387095,0x00,5,0x00000000,0x00000000,0x10000000,0x00000000,0x50000,0x0,0x1,0x2,0x0,0x2,0x0,0,100,0,0); -- Pyrogenics
