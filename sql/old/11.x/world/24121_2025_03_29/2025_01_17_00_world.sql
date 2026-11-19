DELETE FROM `spell_proc` WHERE `SpellId` IN (470053,470058);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(470053,0x00,11,0x00000003,0x00000000,0x00000000,0x00000800,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0), -- Voltaic Blaze
(470058,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Voltaic Blaze

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_voltaic_blaze','spell_sha_voltaic_blaze_aura','spell_sha_voltaic_blaze_talent');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(470057,'spell_sha_voltaic_blaze'),
(470058,'spell_sha_voltaic_blaze_aura'),
(470053,'spell_sha_voltaic_blaze_talent');
