DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pal_long_arm_of_the_law',
'spell_pal_communion');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-87168, 'spell_pal_long_arm_of_the_law'),
(31876, 'spell_pal_communion');

DELETE FROM `spell_proc` WHERE `SpellId` IN (-87168, 31876, 85285);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-87168, 10, 0x00800000, 0, 0, 0x00000110, 1, 1, 0, 0, 0, 0, 100),
(31876, 10, 0x00800000, 0, 0, 0x00000110, 1, 1, 0, 0, 0, 0, 100),
(85285, 0, 0, 0, 0, 0, 1, 0, 0, 0, 60000, 0, 0);
