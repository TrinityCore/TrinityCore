DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_intervene','spell_warr_intervene_charge');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(3411,'spell_warr_intervene'),
(316531,'spell_warr_intervene_charge');

DELETE FROM `spell_proc` WHERE `SpellId` IN (147833);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(147833,0x00,4,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x2,0x0,0,0,0,0); -- Intervene
