DELETE FROM `spell_script_names` WHERE `spell_id`=1217788;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1217788, 'spell_hun_manhunter');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1217788);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1217788,0x00,9,0x00020000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Manhunter
