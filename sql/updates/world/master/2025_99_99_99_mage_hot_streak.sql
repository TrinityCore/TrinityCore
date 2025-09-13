DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_hot_streak', 'spell_mage_hot_streak_remove');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44448, 'spell_mage_hot_streak'),
(11366, 'spell_mage_hot_streak_remove'),
(2120, 'spell_mage_hot_streak_remove');

DELETE FROM `spell_proc` WHERE `SpellId` IN (44448);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(44448,0x04,3,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x2,0x0,0x0,0,0,500,0); -- Pyroblast Clearcasting Driver
