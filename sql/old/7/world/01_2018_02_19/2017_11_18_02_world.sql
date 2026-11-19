-- Proc Chaos Strike only by its two damage spells and only if they are critical hits
DELETE FROM `spell_proc` WHERE `SpellId`= 197125;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Chance`, `Cooldown`, `Charges`) VALUES
(197125, 0x0, 107, 0x4000, 0x0, 0x0, 0x80000000, 0x0, 0x2, 0x2, 0x2, 0, 0, 0);

DELETE FROM `spell_script_names` WHERE `spell_id`= 197125;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(197125, 'spell_dh_chaos_strike');
