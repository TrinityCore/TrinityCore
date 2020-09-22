DELETE FROM `creature_text` WHERE `CreatureID`= 55869;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(55869, 0, 0, 'How I HATE this place. My captors may be long-dead, but don''t think I won''t take it all out on you miserable treasure-hunters.', 14, 0, 100, 0, 0, 25779, 56331, 'Alizabal - Intro'),
(55869, 1, 0, 'I hate adventurers.', 14, 0, 100, 0, 0, 25777, 56322, 'Alizabal - Aggro'),
(55869, 2, 0, 'Feel my hatred!', 14, 0, 100, 0, 0, 25787, 56326, 'Alizabal - Seething Hate 1'),
(55869, 2, 1, 'My hate will consume you!', 14, 0, 100, 0, 0, 25789, 56328, 'Alizabal - Seething Hate 2'),
(55869, 2, 2, 'My hatred burns!', 14, 0, 100, 0, 0, 25788, 56327, 'Alizabal - Seething Hate 3'),
(55869, 3, 0, 'Alizabal skewers $n to the ground.', 41, 0, 100, 0, 0, 0, 56367, 'Alizabal - Announce Skewer'),
(55869, 4, 0, 'I hate martyrs.', 14, 0, 100, 0, 0, 25786, 56330, 'Alizabal - Skewer 1'),
(55869, 4, 1, 'I hate armor.', 14, 0, 100, 0, 0, 25785, 56329, 'Alizabal - Skewer 2'),
(55869, 5, 0, 'I hate standing still.', 14, 0, 100, 0, 0, 25791, 56325, 'Alizabal - Blade Dance 1'),
(55869, 5, 1, 'I hate you all!', 14, 0, 100, 0, 0, 25790, 56324, 'Alizabal - Blade Dance 2'),
(55869, 6, 0, 'I hate mercy.', 14, 0, 100, 0, 0, 25783, 56320, 'Alizabal - Slay 1'),
(55869, 6, 1, 'I still hate you.', 14, 0, 100, 0, 0, 25781, 56318, 'Alizabal - Slay 2'),
(55869, 6, 2, 'Do you hate me? Good.', 14, 0, 100, 0, 0, 25782, 56319, 'Alizabal - Slay 3'),
(55869, 6, 3, 'I didn''t hate that.', 14, 0, 100, 0, 0, 25784, 56321, 'Alizabal - Slay 4'),
(55869, 7, 0, 'I hate... every one of you...', 14, 0, 100, 0, 0, 25778, 56323, 'Alizabal - Death'),
(55869, 8, 0, 'I hate incompetent raiders.', 14, 0, 100, 0, 0, 25780, 56317, 'Alizabal - Disengage');

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_alizabal_seething_hate',
'spell_alizabal_blade_dance');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(105065, 'spell_alizabal_seething_hate'),
(108090, 'spell_alizabal_seething_hate');

DELETE FROM `spell_custom_attr` WHERE `entry` IN (105069, 108094);
INSERT INTO `spell_custom_attr` (`entry`, `attributes`) VALUES
(105069, 0x8),
(108094, 0x8);
