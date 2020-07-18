-- Arcane Sphere
UPDATE `creature_template` SET `speed_run`= 0.4286, `faction`= 16, `flags_extra`= 0 WHERE `entry` IN (24708, 25543);
UPDATE `creature_template_movement` SET `Ground`=0, `Flight`=1 WHERE `CreatureId` IN (24708,25543);
UPDATE `creature_template` SET `ScriptName`= '', `AIName`= 'NullCreatureAI'  WHERE `entry`= 24708;
-- Flame Strike
UPDATE `creature_template` SET `ScriptName`= '', `AIName`= 'NullCreatureAI' WHERE `entry`= 24666;
UPDATE `creature_template` SET `flags_extra`= 2 WHERE `entry` IN (24666, 25554);
-- Phoenix
UPDATE `creature_template` SET `unit_flags`= 32768, `ScriptName`= 'npc_felblood_kaelthas_phoenix' WHERE `entry`= 24674;
-- Phoenix Egg
UPDATE `creature_template` SET `ScriptName`= '', `AIName`= 'PassiveAI' WHERE `entry`= 24675;

-- Template Addons
DELETE FROM `creature_template_addon` WHERE `entry` IN (24708, 25543);
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(24708, 0, 1, 0, 0, '44263'),
(25543, 0, 1, 0, 0, '44263');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID`= 24664;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(24664, 0, 0, 'Don\'t look so smug! I know what you\'re thinking, but Tempest Keep was merely a setback. Did you honestly believe I would trust the future to some blind, half-night elf mongrel?', 14, 0, 100, 0, 0, 12413, 25386, 'Kael\'thas Sunstrider - Intro 1'),
(24664, 1, 0, 'Oh no, he was merely an instrument, a stepping stone to a much larger plan! It has all led to this... and this time you will not interfere!', 14, 0, 100, 0, 0, 0, 25387, 'Kael\'thas Sunstrider - Intro 2'),
(24664, 2, 0, 'I\'ll turn your world... upside... down.', 14, 0, 100, 0, 0, 12418, 25390, 'Kael\'thas Sunstrider - Gravity Lapse Intro 2'),
(24664, 3, 0, 'Do not get... too comfortable.', 14, 0, 100, 0, 0, 12420, 25392, 'Kael\'thas Sunstrider to Kael\'thas Sunstrider - Gravity lapse Intro 2'),
(24664, 4, 0, 'Master, grant me strength.', 14, 0, 100, 0, 0, 12419, 25391, 'Kael\'thas Sunstrider to Kael\'thas Sunstrider - Power Feedback'),
(24664, 5, 0, 'Vengeance burns!', 14, 0, 100, 0, 0, 12415, 25388, 'Kael\'thas Sunstrider - Summon Phoenix'),
(24664, 6, 0, '%s begins to cast Pyroblast!', 41, 0, 100, 0, 0, 0, 20775, 'Kael\'thas Sunstrider - Announce Pyroblast'),
(24664, 7, 0, 'Felomin Ashal! ', 14, 0, 100, 0, 0, 12417, 25389, 'Kael\'thas Sunstrider - Flame Strike'),
(24664, 8, 0, 'My demise accomplishes nothing! The master will have you! You will drown in your own blood! The world shall burn! Aaaghh!', 14, 0, 100, 5, 0, 12421, 25393, 'Kael\'thas Sunstrider - Death');

UPDATE `spell_target_position` SET `PositionX`= 148.5, `PositionY`= 181, `PositionZ`= -16.7, `Orientation`= 4.79965 WHERE `ID`= 44218;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_felblood_kaelthas_flame_strike');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44191, 'spell_felblood_kaelthas_flame_strike');
