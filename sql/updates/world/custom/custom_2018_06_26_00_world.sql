DELETE FROM `spell_proc` WHERE `SpellId`= 76806;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(76806, 0, 0, 0x0, 0x0, 0x0, 0x0, 1, 2, 0, 32, 0, 0,  0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_rog_main_gauche';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(76806,'spell_rog_main_gauche');
