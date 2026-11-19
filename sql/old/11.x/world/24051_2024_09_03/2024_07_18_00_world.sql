UPDATE `creature_template` SET `ScriptName`='boss_lady_waycrest' WHERE `entry`=131545; -- Lady Waycrest
UPDATE `creature_template` SET `ScriptName`='boss_lord_waycrest' WHERE `entry`=131527; -- Lord Waycrest
UPDATE `creature_template_difficulty` SET `StaticFlags4`=8192, `VerifiedBuild`=55461 WHERE `Entry` IN (131545, 131527); -- CREATURE_STATIC_FLAG_4_IGNORE_LOS_WHEN_CASTING_ON_ME

DELETE FROM `spell_target_position` WHERE (`ID`=267082 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(267082, 0, 1862, -556.719970703125, -260.30999755859375, 185.2700042724609375, 55461); -- Spell: 267082 (Move to Arena) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

DELETE FROM `spell_script_names` WHERE `spell_id` IN (261439, 261440, 261441, 268307, 268278, 268272, 268387, 261446);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(261439, 'spell_lord_and_lady_waycrest_virulent_pathogen_selector'),
(261441, 'spell_lord_and_lady_waycrest_virulent_pathogen_selector'),
(261440, 'spell_lord_and_lady_waycrest_virulent_pathogen_damage'),
(268307, 'spell_lord_and_lady_waycrest_discordant_cadenza_selector'),
(268278, 'spell_lord_and_lady_waycrest_wracking_chord_selector'),
(268272, 'spell_lord_and_lady_waycrest_wracking_bolt_missile'),
(268387, 'spell_lord_and_lady_waycrest_contagious_remnants'),
(261446, 'spell_lord_and_lady_waycrest_vitality_transfer');

DELETE FROM `creature_text` WHERE `CreatureID` IN (131527, 131545);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(131545, 0, 0, 'Husband, please attend to our guests.', 14, 0, 50, 0, 0, 97499, 145923, 0, 'Lady Waycrest to Player'),
(131545, 0, 1, 'Oh look, husband. Your supper has arrived.', 14, 0, 50, 0, 0, 97498, 145919, 0, 'Lady Waycrest to Player'),
(131545, 1, 0, 'Simply inferior.', 14, 0, 50, 0, 0, 97491, 145952, 0, 'Lady Waycrest to Player'),
(131545, 1, 1, 'Good riddance.', 14, 0, 50, 0, 0, 97492, 145953, 0, 'Lady Waycrest to Player'),
(131545, 2, 0, '|TInterface\\ICONS\\INV_MISC_VOLATILESHADOW:20|t Lady Waycrest starts casting |cFFFF0404|Hspell:268306|h[Discordant Cadenza]|h|r!', 41, 0, 100, 0, 0, 0, 161927, 0, 'Lady Waycrest'),
(131545, 3, 0, 'No! You won\'t take him from me!', 14, 0, 33, 0, 0, 97500, 145924, 0, 'Lady Waycrest to Lord Waycrest'),
(131545, 3, 1, 'I will never let him go!', 14, 0, 33, 0, 0, 97501, 145925, 0, 'Lady Waycrest to Lord Waycrest'),
(131545, 3, 2, 'Our bond can never be broken!', 14, 0, 33, 0, 0, 97502, 145926, 0, 'Lady Waycrest to Lord Waycrest'),
(131545, 4, 0, 'We will never be parted...', 14, 0, 100, 0, 0, 97493, 145954, 0, 'Lady Waycrest to Player'),
(131527, 0, 0, 'Fester!', 14, 0, 50, 0, 0, 97465, 145959, 0, 'Lord Waycrest to Player'),
(131527, 0, 1, 'Rot!', 14, 0, 50, 0, 0, 97466, 145960, 0, 'Lord Waycrest to Player'),
(131527, 1, 0, 'Spare parts.', 14, 0, 50, 0, 0, 97467, 145961, 0, 'Lord Waycrest to Player'),
(131527, 1, 1, 'Broken.', 14, 0, 50, 0, 0, 97468, 145963, 0, 'Lord Waycrest to Player');
