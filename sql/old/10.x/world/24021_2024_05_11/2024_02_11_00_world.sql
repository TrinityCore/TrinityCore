DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_train_of_thought';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(390693,'spell_pri_train_of_thought');

DELETE FROM `spell_proc` WHERE `SpellId` IN (390693);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390693,0x0,6,0x000008C0,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Train of Thought
