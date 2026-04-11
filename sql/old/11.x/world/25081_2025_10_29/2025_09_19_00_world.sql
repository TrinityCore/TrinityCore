DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_mage_hot_streak', 'spell_mage_hot_streak_ignite_marker');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44448, 'spell_mage_hot_streak'),
(11366, 'spell_mage_hot_streak_ignite_marker'),
(2120, 'spell_mage_hot_streak_ignite_marker');

DELETE FROM `spell_proc` WHERE `SpellId` IN (44448,48108);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(44448,0x04,3,0x00C00013,0x00100000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x0,0x0,0x0,0,0,0,0), -- Pyroblast Clearcasting Driver
(48108,0x00,3,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x4,0x0,0x0,0x0,0x8,0x0,0,0,0,1); -- Hot Streak!
