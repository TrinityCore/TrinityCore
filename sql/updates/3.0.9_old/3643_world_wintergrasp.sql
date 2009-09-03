DELETE FROM `spell_script_target` WHERE entry IN (54643);
INSERT INTO `spell_script_target` (`entry`, `type`, `targetEntry`) VALUES
(54643,1,23472);

DELETE FROM `game_event` WHERE `entry` IN (50,51);
INSERT INTO `game_event` (`entry`, `description`, `world_event`) VALUES
(50, 'Wintergrasp Alliance Defence', 5),
(51, 'Wintergrasp Horde Defence', 5);

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (54643);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 54643,-54643, 2, 'Wintergrasp Defender Teleport');
