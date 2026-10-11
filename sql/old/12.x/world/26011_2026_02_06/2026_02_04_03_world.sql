DELETE FROM `spell_proc` WHERE `SpellId` IN (392792);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(392792,0x00,4,0x02400400,0x00000000,0x00000000,0x08040000,0x0,0x0,0x0,0x1,0x0,0x4,0x0,0,0,0,0); -- Frothing Berserker

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_warr_frothing_berserker';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(392792,'spell_warr_frothing_berserker');
