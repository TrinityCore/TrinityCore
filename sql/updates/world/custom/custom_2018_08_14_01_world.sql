-- Template Updates
-- Commander Ulthok
UPDATE `creature_template` SET `ScriptName`= 'boss_commander_ulthok', `DamageModifier`= 30, `BaseVariance`= 0.5 WHERE `entry`= 40765;
UPDATE `creature_template` SET `DamageModifier`= 60, `BaseVariance`= 0.5 WHERE `entry`= 49064;
UPDATE `creature_template` SET `mingold`= 19800, `maxgold`= 20000, `unit_flags`= `unit_flags` & ~0x00000100, `mechanic_immune_mask`= 667893631 WHERE `entry` IN (40765, 49064);
-- Dark Fissure
UPDATE `creature_template` SET `difficulty_entry_1`= 49065, `unit_flags`= 33554432, `unit_flags2`= 33556480, `flags_extra`= 128 WHERE `entry`= 40784;
UPDATE `creature_template` SET `minlevel`= 86, `maxlevel`= 86, `exp`= 3, `faction`= 14, `unit_flags`= 33554432, `unit_flags2`= 33556480, `flags_extra`= 128 WHERE `entry`= 49065;

-- Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (40784, 49065);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(40784, '76066'),
(49065, '91371');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 40765;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(40765, 0, 0, 'Iilth vwah, uhn''agth fhssh za.', 14, 0, 100, 0, 0, 18543, 50522, 'Commander Ulthok - Aggro'),
(40765, 1, 0, 'Where one falls, many shall take its place...', 15, 0, 100, 0, 0, 0, 32608, 'Commander Ulthok - Aggro Whisper'),
(40765, 2, 0, 'Gul''kafh an''shel.', 14, 0, 100, 0, 0, 18544, 50525, 'Commander Ulthok - Slay'),
(40765, 3, 0, 'Gaze into the void.', 15, 0, 100, 0, 0, 0, 50526, 'Commander Ulthok - Slay Whisper'),
(40765, 4, 0, 'Ywaq maq oou.', 14, 0, 100, 0, 0, 18542, 50529, 'Commander Ulthok - Death'),
(40765, 5, 0, 'They do not die.', 15, 0, 100, 0, 0, 0, 50527, 'Commander Ulthok to Player');

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_ulthok_dark_fissure';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(91371, 'spell_ulthok_dark_fissure');
