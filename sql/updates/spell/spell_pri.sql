DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_atonement_triggered', 'spell_pri_power_word_radiance', 'spell_pri_shadow_mend');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(194384, 'spell_pri_atonement_triggered'),
(214206, 'spell_pri_atonement_triggered'),
(194509, 'spell_pri_power_word_radiance'),
(186263, 'spell_pri_shadow_mend');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_pri_spirit_of_redemption' WHERE `ScriptName` = 'spell_priest_spirit_of_redemption';


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
