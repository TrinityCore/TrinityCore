DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pal_light_s_beacon',
'spell_pal_lights_beacon');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(53651, 'spell_pal_lights_beacon');

SET @FAMILY_FLAGS0 := 0 | 0x00200000 | 0x40000000 | 0x80000000;
SET @FAMILY_FLAGS1 := 0;
SET @FAMILY_FLAGS2 := 0 | 0x00000400 | 0x00004000 | 0x00040000;

DELETE FROM `spell_proc` WHERE `SpellId`= 53651;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(53651, 10, @FAMILY_FLAGS0, @FAMILY_FLAGS1, @FAMILY_FLAGS2, 0, 2, 0, 0, 0);
