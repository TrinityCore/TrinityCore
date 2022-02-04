DELETE FROM `spell_proc` WHERE `SpellId`=53576;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES 
(53576, 0, 10, 2097152, 65536, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id`=54149 AND `ScriptName`='spell_pal_infusion_of_light';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(54149, 'spell_pal_infusion_of_light');

