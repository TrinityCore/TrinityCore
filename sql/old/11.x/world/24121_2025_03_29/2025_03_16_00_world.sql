DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_lava_lash','spell_sha_molten_assault','spell_sha_ice_strike_proc','spell_sha_hot_hand');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(60103,'spell_sha_lava_lash'),
(60103,'spell_sha_molten_assault'),
(466467,'spell_sha_ice_strike_proc'),
(201900,'spell_sha_hot_hand');

DELETE FROM `spell_proc` WHERE `SpellId` IN (384357,428071,466469);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(384357,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x8,0x0,0,0,0,0), -- Ice Strike
(428071,0x00,11,0x00000000,0x00000000,0x00001804,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0), -- Tempest Strikes
(466469,0x00,11,0x80000000,0x00000000,0x00000800,0x00000000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Ice Strike
