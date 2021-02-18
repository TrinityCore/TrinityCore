-- Add earthwarden script
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_earthwarden';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(203974, 'spell_dru_earthwarden');

-- Proc
DELETE FROM `spell_proc` WHERE `SpellId` IN (203974);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance` , `Cooldown`, `Charges`) VALUES
(203974, 0, 7, 0x0, 0x0, 0x08000000, 0x40000000, 0x10, 1, 1, 0x403, 0, 0, 0, 0, 0, 0);
