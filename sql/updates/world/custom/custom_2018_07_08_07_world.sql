DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_sha_unleash_elements';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(73680, 'spell_sha_unleash_elements');

DELETE FROM `spell_proc` WHERE `SpellId`= 73681;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(73681, 0, 0, 0, 0, 0, 0, 0, 12287, 0, 0, 6, 100);
