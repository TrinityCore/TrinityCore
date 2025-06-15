DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_doom_winds','spell_sha_hailstorm','spell_sha_fire_nova','spell_sha_flame_shock_fire_nova_enabler','spell_sha_ashen_catalyst');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(466772,'spell_sha_doom_winds'),
(334196,'spell_sha_hailstorm'),
(333974,'spell_sha_fire_nova'),
(466620,'spell_sha_flame_shock_fire_nova_enabler'),
(390370,'spell_sha_ashen_catalyst');

DELETE FROM `spell_proc` WHERE `SpellId` IN (334196,382888,382889,390370,390371);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(334196,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x8,0x0,0,0,0,1), -- Hailstorm
(382888,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x2,0x0,0x0,0,0,0,0), -- Flurry
(382889,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x25F7,0x0,0x0,0,0,0,0), -- Flurry
(390370,0x00,11,0x10000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0), -- Ashen Catalyst
(390371,0x00,11,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x4,0x0,0x8,0x0,0,0,0,1); -- Ashen Catalyst
