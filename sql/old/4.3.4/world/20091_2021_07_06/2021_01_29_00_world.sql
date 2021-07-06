UPDATE `creature_template` SET `ScriptName`= 'npc_sun_touched_servant' WHERE `entry` IN (39366, 39369, 39370);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_hoo_disperse');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88097, 'spell_hoo_disperse'),
(88100, 'spell_hoo_disperse');

DELETE FROM `creature_text` WHERE `CreatureID` IN (39366, 39369);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(39366, 0, 0, '%s disperses!', 16, 0, 100, 0, 0, 0, 42481, 'Sun-Touched Servant'),
(39369, 0, 0, '%s disperses!', 16, 0, 100, 0, 0, 0, 42481, 'Sun-Touched Sprite');
