-- Brilliant Windfeather Smart scripts. The casting of Gust of wind is slightly broken, the npc should be locked in place for a second after casting it.
-- to stop you from getting hit with the Gust. Idk how to fix this..
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 72762;


DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 72762);

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
 (72762, 0, 0, 0, 0, 0, 100, 0, 0, 0, 12000, 15000, 11, 147306, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'cast windfeather');
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(72762, 0, 1, 0, 0, 0, 100, 0, 6000, 9000, 12000, 16000, 11, 147310, 0, 0, 0, 0, 0, 2, 87835, 20, 0, 0, 0, 0, 0, 'Cast Gust of wind');