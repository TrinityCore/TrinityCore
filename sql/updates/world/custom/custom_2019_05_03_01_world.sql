DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dru_empowered_touch',
'spell_dru_empowered_touch_script');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-33879, 'spell_dru_empowered_touch'),
(88433, 'spell_dru_empowered_touch_script');

SET @FAMILY_FLAGS0 := 0 | 0x00000020 | 0x00000040;
SET @FAMILY_FLAGS1 := 0 | 0x02000000;

DELETE FROM `spell_proc` WHERE `SpellId` IN (-33879);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-33879, 7, @FAMILY_FLAGS0, @FAMILY_FLAGS1, 0, 0x00004000, 2, 2, 0, 16, 0, 0, 100);
