DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_brittle';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(374504, 'spell_dk_brittle');

DELETE FROM `spell_proc` WHERE `SpellId` IN (374504);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(374504,0x00,15,0x00000000,0x06000100,0x20000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x2,0x0,0,0,0,0); -- Brittle
