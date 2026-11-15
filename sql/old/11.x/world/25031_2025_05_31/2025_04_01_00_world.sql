UPDATE `spell_script_names` SET `ScriptName`='spell_sha_chain_lightning_energize' WHERE `ScriptName`='spell_sha_chain_lightning';

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_chain_lightning_crash_lightning';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(188443,'spell_sha_chain_lightning_crash_lightning');

DELETE FROM `spell_proc` WHERE `SpellId` IN (187878,333964);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(187878,0x00,11,0x00000000,0x00000010,0x00000804,0x00000000,0x0,0x0,0x5,0x1,0x0,0x0,0x0,0,0,0,0), -- Crash Lightning
(333964,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x8,0x0,0,0,0,1); -- Crash Lightning
