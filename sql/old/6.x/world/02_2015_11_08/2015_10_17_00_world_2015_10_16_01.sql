DELETE FROM `creature_text` WHERE `entry`=34965;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(34965, 0, 0, 'Foolish $c, you cannot stop the Kvaldir!', 12, 0, 100, 0, 0, 0, 35393, 0, 'Mistcaller Yngvar');

DELETE FROM `smart_scripts` WHERE `entryorguid`=34965 AND `source_type`=0 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(34965, 0, 4, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Mistcaller Yngvar - On Agro - Say');

UPDATE `creature_template` SET `unit_flags`=33555200, `InhabitType`=4 WHERE  `entry`=34888;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN(34852,34888) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(34852, 0, 0, 1, 8, 0, 100, 1, 66390, 0, 0, 0, 33, 34852, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Slain Tualiq Villager - On Spellhit \'Read Last Rites\' - Quest Credit \'The Light\'s Mercy\' (No Repeat)'),
(34852, 0, 1, 2, 61, 0, 100, 1, 0, 0, 0, 0, 11, 66412, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Slain Tualiq Villager - On Spellhit \'Read Last Rites\' - Cast 66412'),
(34852, 0, 2, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Slain Tualiq Villager - On Spellhit \'Read Last Rites\' - Despawn'),
(34888, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 90, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tualiq Spirit - On Just Summoned - Set Bytes 2'),
(34888, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 11, 37119, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tualiq Spirit - On Just Summoned - Cast Spirit Particles (Spawn)'),
(34888, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 11, 64462, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tualiq Spirit - On Just Summoned - Cast Feign and Drown'),
(34888, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tualiq Spirit - On Just Summoned - Set run off'),
(34888, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 114, 90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Tualiq Spirit - On Just Summoned - Rise up');

UPDATE `smart_scripts` SET `action_param1`=64100 WHERE  `entryorguid`=33429 AND `source_type`=0 AND `id`=6 AND `link`=0;
