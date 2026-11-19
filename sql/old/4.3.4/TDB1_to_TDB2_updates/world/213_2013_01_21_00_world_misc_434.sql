-- Intro Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=7246;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7246, 'at_alizabal_intro');

UPDATE `creature_template` SET `scriptname` = 'boss_alizabal' WHERE `entry`=55869;

-- Todo: Find the Rest of the Texts and their meanings
DELETE FROM `creature_text` WHERE `entry`=55869;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(55869, 1, 0, 'How I HATE this place. My captors may be long-dead, but don\'t think I won\'t take it all out on you miserable treasure-hunters.', 14, 0, 100, 0, 0, 25779, 'Alizabal - Intro'),
(55869, 2, 0, 'I hate adventurers.', 14, 0, 100, 0, 0, 25777, 'Alizabal - Aggro'),
(55869, 3, 0, 'I hate martyrs.', 14, 0, 100, 0, 0, 25786, 'Alizabal - Seething Hate'),
(55869, 4, 0, 'I hate armor.', 14, 0, 100, 0, 0, 25785, 'Alizabal - Skewer'),
(55869, 5, 0, 'Alizabal nailed $N firmly on the ground.', 41, 0, 100, 0, 0, 0, 'Alizabal - Skewer Announce'),
(55869, 6, 0, 'I hate standing still.', 14, 0, 100, 0, 0, 25791, 'Alizabal - Blade Dance'),
(55869, 7, 0, 'Feel my hatred!', 14, 0, 100, 0, 0, 25787, 'Alizabal - ???'),
(55869, 8, 0, 'My hate will consume you!', 14, 0, 100, 0, 0, 25789, 'Alizabal - ???'),
(55869, 9, 0, 'I hate you all.', 14, 0, 100, 0, 0, 25790, 'Alizabal - ???'),
(55869, 10, 0, 'I hate mercy.', 14, 0, 100, 0, 0, 25783, 'Alizabal - Slay 1'),
(55869, 11, 0, 'My hatred burns!', 14, 0, 100, 0, 0, 25788, 'Alizabal - ???'),
(55869, 12, 0, 'I hate... every one of you...', 14, 0, 100, 0, 0, 25778, 'Alizabal - Death');
