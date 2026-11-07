DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_divinity';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(1215241,'spell_pri_divinity');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1215241,1216314);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1215241,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x8,0x0,0,0,0,0), -- Divinity
(1216314,0x00,6,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x18,0x0,0,0,0,0); -- Divinity
