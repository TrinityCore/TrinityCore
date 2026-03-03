DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_evangelism','spell_pri_power_word_radiance_evangelism');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(472433,'spell_pri_evangelism'),
(194509,'spell_pri_power_word_radiance_evangelism');

DELETE FROM `spell_proc` WHERE `SpellId` IN (472433);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(472433,0x00,6,0x00400000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x0,0x0,0x10,0x0,0,0,0,0); -- Evangelism
