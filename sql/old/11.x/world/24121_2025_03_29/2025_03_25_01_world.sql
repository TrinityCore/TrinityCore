DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_artifact_gathering_storms','spell_sha_unrelenting_storms','spell_sha_converging_storms','spell_sha_converging_storms_buff','spell_sha_ice_strike','spell_sha_swirling_maelstrom','spell_sha_molten_thunder','spell_sha_molten_thunder_sundering');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(187874,'spell_sha_artifact_gathering_storms'),
(187874,'spell_sha_unrelenting_storms'),
(187874,'spell_sha_converging_storms'),
(198300,'spell_sha_converging_storms_buff'),
(342240,'spell_sha_ice_strike'),
(384359,'spell_sha_swirling_maelstrom'),
(469344,'spell_sha_molten_thunder'),
(197214,'spell_sha_molten_thunder_sundering');

DELETE FROM `spell_proc` WHERE `SpellId` IN (384359,198300,469346);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(384359,0x00,11,0x88000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x4,0x0,0x0,0x0,0,0,0,0), -- Swirling Maelstrom
(198300,0x00,11,0x00000000,0x00000000,0x00001000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x10,0x0,0,0,0,1), -- Converging Storms
(469346,0x00,11,0x00000000,0x00000000,0x00000000,0x04000000,0x1010,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Molten Thunder
