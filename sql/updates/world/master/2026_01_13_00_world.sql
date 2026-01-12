DELETE FROM `spell_proc` WHERE `SpellId`=389711;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(389711,0x00,107,0x00100000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x2,0x2,0x0,0x0,0x0,0,0,0,0); -- Soulmonger

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_soulmonger';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(389711,'spell_dh_soulmonger');
