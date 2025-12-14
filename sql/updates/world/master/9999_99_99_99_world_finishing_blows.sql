DELETE FROM `spell_proc` WHERE `SpellId` IN (400205);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(400205,0x00,4,0x00000004,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Finishing Blows

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warr_finishing_blows';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(400205,'spell_warr_finishing_blows');
