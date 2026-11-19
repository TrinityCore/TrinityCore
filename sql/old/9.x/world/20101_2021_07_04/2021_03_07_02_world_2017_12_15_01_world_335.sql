DELETE FROM `spell_proc` WHERE `SpellId` IN (35321, 38363, 39215);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(35321, 0x0, 0, 0x00000000, 0x00000000, 0x00000000, 0x0, 0x2, 0x0, 0x0, 0x0, 0, 0, 0, 0),
(38363, 0x0, 0, 0x00000000, 0x00000000, 0x00000000, 0x0, 0x2, 0x0, 0x0, 0x0, 0, 0, 0, 0),
(39215, 0x0, 0, 0x00000000, 0x00000000, 0x00000000, 0x0, 0x2, 0x0, 0x0, 0x0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_remove_on_health_pct','spell_gen_remove_on_full_health','spell_gen_remove_on_full_health_pct','spell_trash_npc_glacial_strike','spell_iron_ring_guard_impale');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(38772, 'spell_gen_remove_on_health_pct'),
(43937, 'spell_gen_remove_on_health_pct'),
(62331, 'spell_gen_remove_on_health_pct'),
(62418, 'spell_gen_remove_on_health_pct'),
(31956, 'spell_gen_remove_on_full_health'),
(38801, 'spell_gen_remove_on_full_health'),
(43093, 'spell_gen_remove_on_full_health'),
(58517, 'spell_gen_remove_on_full_health'),
(59262, 'spell_gen_remove_on_full_health'),
(70292, 'spell_gen_remove_on_full_health_pct'),
(71316, 'spell_gen_remove_on_full_health_pct');
-- (71317, 'spell_gen_remove_on_full_health_pct');
