-- Spell Proc
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_holy_words');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(63733, 'spell_pri_holy_words');

-- Spell Procs
-- Make holy words Proc on the following spells:
-- 2060     Heal                0x1000
-- 2061     Flash Heal          0x0800
-- 596      Prayer of Healing   0x0200
-- 139      Renew               0x0040
-- 585      Smite               0x0080
--                              0x1AC0

DELETE FROM `spell_proc` WHERE `SpellId` IN (63733); -- Holy Words
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(63733, 0, 6, 0x1AC0, 0x0, 0x0, 0x0, 0, 7, 2, 0x403, 0x0, 0, 0, 0, 0, 0);
