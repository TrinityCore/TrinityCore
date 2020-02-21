DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_vengeance_triggered';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(76691, 'spell_gen_vengeance_triggered');

DELETE FROM `spell_proc` WHERE `SpellId`= 76691;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Chance`) VALUES
(76691, 0, 0, 0, 0, 0x000A22A8, 1, 0, 0, 0x0000020 | 0x0000040, 0, 100);
