DELETE FROM `spell_proc` WHERE `SpellId` IN (435607);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(435607,0x01,4,0x00000000,0x00000600,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Thunder Blast

DELETE FROM `spell_proc` WHERE `SpellId` IN (435615);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(435615,0x00,4,0x00000080,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x10,0x0,0,0,0,0); -- Thunder Blast

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_thunder_blast', 'spell_warr_thunder_clap_rend', 'spell_warr_thunder_blast_energize', 'spell_warr_thunder_clap');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(6343, 'spell_warr_thunder_clap_rend'),
(6343, 'spell_warr_thunder_clap'),
(435222, 'spell_warr_thunder_clap'),
(435222, 'spell_warr_thunder_clap_rend'),
(435222, 'spell_warr_thunder_blast_energize'),
(435607,'spell_warr_thunder_blast');
