DELETE FROM `smart_scripts` WHERE `entryorguid` IN(29043) AND `source_type`=0 AND `id`>1;
DELETE FROM `smart_scripts` WHERE `entryorguid` =2904301 AND `source_type`=9;
DELETE FROM `creature_text` WHERE `entry` IN(29043) AND `groupid`>3;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(29043, 0, 2, 3, 20, 1, 100, 0, 12732, 0, 0, 0, 64, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Rejek - On Quest Reward 12732 (Phase 1) - Store Target'), 
(29043, 0, 3, 0, 61, 1, 100, 0, 0, 0, 0, 0, 80, 2904301, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - On Quest Reward 12732 (Phase 1) - Run Script 2'), 
(2904301, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Set Phase 2'), -- 09:55:57.422
(2904301, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Say Line 4'), -- 09:56:00.703
(2904301, 9, 2, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Play Emote OneShotEat'), -- 09:56:05.469
(2904301, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 52968, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Cast Heartblood Rage'), -- 09:56:05.469
(2904301, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Say Line 5'), -- 09:56:07.891
(2904301, 9, 5, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Play Emote OneShotAttack1H'), -- 09:56:11.578
(2904301, 9, 6, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Play Emote OneShotAttackUnarmed'), -- 09:56:13.984
(2904301, 9, 7, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 1, 6, 0, 0, 0, 0, 0, 12, 1, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Say Line 6'), -- 09:56:16.500
(2904301, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rejek - Script 2 - Set Phase 1');

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(29043, 4, 0, 'Still warm, just the way Rejek likes it.', 12, 0, 100, 1, 0, 0, 0, 0, 'Rejek'),
(29043, 5, 0, 'Rejek feel strong! Rejek crush big-tongue skulls between his hands!', 12, 0, 100, 34, 0, 0, 0, 0, 'Rejek'),
(29043, 6, 0, 'Rejek and $n will teach the enemies of the Frenzyheart to fear us!', 12, 0, 100, 53, 0, 0, 0, 0, 'Rejek');

DELETE FROM `smart_scripts` WHERE  `entryorguid`=2816100 AND `source_type`=9 AND `id`=0 AND `link`=0;
DELETE FROM `smart_scripts` WHERE  `entryorguid`=28161 AND `source_type`=0 AND `id`=4 AND `link`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=28161 AND `source_type`=0 AND `id`=0 AND `link`=4;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(4968) AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=1 WHERE  `entryorguid`=4968 AND `source_type`=0 AND `id`=0 AND `link`=0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4968, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 23122, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Lady Jaina Proudmoore - On Gossip Select - Cast Jaina''s Autograph');
