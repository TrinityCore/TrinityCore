DELETE FROM `creature` WHERE  `id` IN(27685,27534);

UPDATE `creature_text` SET `BroadcastTextID`=31259 WHERE  `entry`=31283;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN(27564,27749)  AND `source_type`=0 AND `id`=15;
DELETE FROM `smart_scripts` WHERE `entryorguid` =27725  AND `source_type`=0 AND `id`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(27564, 0, 15, 0, 1, 0, 100, 0, 0, 5000, 0, 10000, 11, 49329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Alliance Conscript - OOC - Cast Summon Frigid Ghoul Attacker'),
(27749, 0, 15, 0, 1, 0, 100, 0, 0, 5000, 0, 10000, 11, 49329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Horde Conscript - OOC - Cast Summon Frigid Ghoul Attacker'),
(27725, 0, 1, 0, 1, 0, 100, 0, 0, 5000, 5000, 15000, 11, 49068, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ruby Guardian - OOC - Cast Summon Frigid Ghoul');
