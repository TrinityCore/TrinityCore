-- Ember Tap
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_ember_tap';
-- Mastery: Wild Quiver
DELETE FROM `spell_proc_event` WHERE `entry` = 76659;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`) VALUE
(76659, 127);
-- Mastery: Illuminated Healing
DELETE FROM `spell_proc_event` WHERE `entry` = 76669;
INSERT INTO `spell_proc_event` (`entry`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`) VALUE
(76669, 10, 2147483648+1073741824, 65536, 1024+16384+512);
-- Mastery: Main Gauche
DELETE FROM `spell_proc_event` WHERE `entry` = 76806;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`) VALUES
(76806, 127);
-- Mastery: Strikes of Opportunity
DELETE FROM `spell_proc_event` WHERE `entry` = 76838;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`) VALUES
(76838, 127);
-- Mastery: Harmony
DELETE FROM `spell_proc_event` WHERE `entry` = 77495;
INSERT INTO `spell_proc_event` (`entry`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `procFlags`, `CustomChance`) VALUES
(77495, 7, 32 + 64, 2 + 33554432, 16384, 100);