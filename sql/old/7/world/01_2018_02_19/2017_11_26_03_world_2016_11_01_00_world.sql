UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE  `entry`IN(8530,8531,8532,11064);
-- UPDATE `spell_dbc` SET `Effect1`=28,`EffectMiscValueB1`=64 WHERE  `Id`IN(17310);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(8530,8531,8532,11064);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(8530, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 17310, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Cannibal Ghoul - On Death - Cast Summon Darrowshire Spirit'),
(8531, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 17310, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gibbering Ghoul - On Death - Cast Summon Darrowshire Spirit'),
(8532, 0, 0, 0, 6, 0, 100, 0, 0, 0, 0, 0, 11, 17310, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Diseased Flayer - On Death - Cast Summon Darrowshire Spirit'),
(11064, 0, 0, 0, 1, 0, 100, 0, 60000, 60000, 60000, 60000, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darrowshire Spirit - OOC - Despawn'),
(11064, 0, 1, 2, 11, 0, 100, 0, 0, 0, 0, 0, 11, 17321, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darrowshire Spirit - On Reset - Cast Spirit Spawn-in'),
(11064, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darrowshire Spirit - On Reset - Remove Unit Flag Not selectable'),
(11064, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 17327, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darrowshire Spirit - On Reset - Cast Spirit Particles'),
(11064, 0, 4, 5, 64, 0, 100, 1, 0, 0, 0, 0, 33, 11064, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Darrowshire Spirit - On Gossip Hello - Kill Credit'),
(11064, 0, 5, 0, 61, 0, 100, 1, 0, 0, 0, 0, 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Darrowshire Spirit - On Gossip Hello - Despawn after 10 seconds');
