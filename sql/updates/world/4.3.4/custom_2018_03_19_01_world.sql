DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_sha_ancestral_resolve',
'spell_sha_resurgence',
'spell_sha_ancestral_healing',
'spell_sha_cleanse_spirit');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-77829, 'spell_sha_ancestral_resolve'),
(-16180, 'spell_sha_resurgence'),
(-16176, 'spell_sha_ancestral_healing'),
(51886, 'spell_sha_cleanse_spirit');

DELETE FROM `spell_proc` WHERE `SpellId` IN (-16180, 16188, -16176, -82984);
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(-16180, 0x00004000, 0x00000002, 0x00000002, 0x00000002, 0),
(-16176, 0x00055550, 0x00000002, 0x00000002, 0x00000002, 0),
(-82984, 0x00010000, 0x00000001, 0x00000002, 0x00000000, 0);

INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(16188, 8, 0x00015550, 0x00000001|0x00000002, 0x00000001, 0, 0);
