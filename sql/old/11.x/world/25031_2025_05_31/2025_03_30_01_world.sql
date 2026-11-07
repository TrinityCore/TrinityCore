DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
  'spell_sha_artifact_stormflurry_stormstrike',
  'spell_sha_artifact_stormflurry_windstrike',
  'spell_sha_stormflurry_stormstrike',
  'spell_sha_stormflurry_windstrike',
  'spell_sha_stormflurry_damage',
  'spell_sha_stormsurge',
  'spell_sha_stormsurge_proc',
  'spell_sha_stormblast',
  'spell_sha_stormblast_proc',
  'spell_sha_stormblast_damage',
  'spell_sha_elemental_weapons'
);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(17364,'spell_sha_artifact_stormflurry_stormstrike'),
(115356,'spell_sha_artifact_stormflurry_windstrike'),
(17364,'spell_sha_stormflurry_stormstrike'),
(115356,'spell_sha_stormflurry_windstrike'),
(32175,'spell_sha_stormflurry_damage'),
(32176,'spell_sha_stormflurry_damage'),
(115357,'spell_sha_stormflurry_damage'),
(115360,'spell_sha_stormflurry_damage'),
(201845,'spell_sha_stormsurge'),
(201846,'spell_sha_stormsurge_proc'),
(319930,'spell_sha_stormblast'),
(17364,'spell_sha_stormblast_proc'),
(115356,'spell_sha_stormblast_proc'),
(32175,'spell_sha_stormblast_damage'),
(32176,'spell_sha_stormblast_damage'),
(115357,'spell_sha_stormblast_damage'),
(115360,'spell_sha_stormblast_damage'),
(384355,'spell_sha_elemental_weapons');

DELETE FROM `spell_proc` WHERE `SpellId` IN (201845,201846,319930,334046);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(201845,0x00,11,0x00800000,0x00000010,0x00200804,0x04010000,0x0,0x0,0x5,0x4,0x0,0x0,0x0,0,0,0,0), -- Stormsurge
(201846,0x00,11,0x00000000,0x00000010,0x00000000,0x00010000,0x0,0x0,0x4,0x2,0x0,0x0,0x0,0,0,0,1), -- Stormsurge
(319930,0x00,11,0x00000000,0x00000000,0x00000000,0x00040000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0), -- Stormblast
(334046,0x00,11,0x00000000,0x00000000,0x00000004,0x04000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0); -- Lashing Flames
