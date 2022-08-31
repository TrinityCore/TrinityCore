-- Denounce Talent
DELETE FROM `spell_proc` WHERE `SpellId`= -31825;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask1`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(-31825, 10, 0x2, 0x1, 0x2, 0x0);

-- Speed of Light Talent
DELETE FROM `spell_proc` WHERE `SpellId`= -85495;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(-85495, 10, 0x400000, 0x4, 0x1, 0x0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_speed_of_light';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-85495, 'spell_pal_speed_of_light');
