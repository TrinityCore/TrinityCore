DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_divinity', 'spell_pri_divinity_aura');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1215241, 'spell_pri_divinity'),
(1216314, 'spell_pri_divinity_aura');

DELETE FROM `spell_proc` WHERE `SpellId` IN (1216314);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(1216314,0x00,6,0x00001200,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x10,0x0,0,0,0,0); -- Divinity
