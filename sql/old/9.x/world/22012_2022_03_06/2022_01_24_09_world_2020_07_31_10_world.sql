--
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=27910;

DELETE FROM `smart_scripts` WHERE `entryorguid`IN(27909,27910) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` between 2791000 AND 2791005 AND `source_type`=9;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2791000, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 127416, 27909, 0, 0, 0, 0, 0, 0, 'Drak Tharon Cocoon Bunny - Script 1 - Set Data to Darkweb Cocoon #1'),
(2791001, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 127417, 27909, 0, 0, 0, 0, 0, 0, 'Drak Tharon Cocoon Bunny - Script 2 - Set Data to Darkweb Cocoon #2'),
(2791002, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 127418, 27909, 0, 0, 0, 0, 0, 0, 'Drak Tharon Cocoon Bunny - Script 3 - Set Data to Darkweb Cocoon #3'),
(2791003, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 127419, 27909, 0, 0, 0, 0, 0, 0, 'Drak Tharon Cocoon Bunny - Script 4 - Set Data to Darkweb Cocoon #4'),
(2791004, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 127420, 27909, 0, 0, 0, 0, 0, 0, 'Drak Tharon Cocoon Bunny - Script 5 - Set Data to Darkweb Cocoon #5'),
(2791005, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 10, 127421, 27909, 0, 0, 0, 0, 0, 0, 'Drak Tharon Cocoon Bunny - Script 6 - Set Data to Darkweb Cocoon #6'),
(27910, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 88, 2791000, 2791005, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Drak Tharon Cocoon Bunny - On Spawn - Run Random Script'),
(27909, 0, 0, 5, 11, 0, 100, 0, 0, 0, 0, 0, 0, 42, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On Spawn - Set Invincibility Hp'),
(27909, 0, 1, 0, 2, 2, 100, 1, 0, 1, 0, 0, 0, 80, 2790900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On 1% HP (Phase 2) - Run Script'),
(27909, 0, 2, 0, 2, 1, 100, 1, 0, 1, 0, 0, 0, 87, 2790901, 2790902, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On 1% HP (Phase 1) - Run Random script'),
(27909, 0, 3, 4, 25, 0, 100, 0, 0, 0, 0, 0, 0, 103, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On Reset - Root'),
(27909, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On Reset - Set Passive'),
(27909, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On Spawn - Set Phase 1'),
(27909, 0, 6, 0, 38, 0, 100, 0, 1, 1, 0, 0, 0, 22, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Darkweb Victim - On Data Set - Set Phase 2');
