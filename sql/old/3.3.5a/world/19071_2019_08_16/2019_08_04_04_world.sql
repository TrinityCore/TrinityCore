-- 
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 28640;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (27003) AND `source_type`=0 AND `id`=3;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (28640) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(27003, 0, 3, 0, 0, 0, 100, 0, 4000, 5000, 12000, 17000, 11, 52144, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dregmar Runebrand - IC - Cast'),
(28640, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 11, 52145, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Summon Rune Trigger - Just summoned - cast Explosive Rune'),
(28640, 0, 1, 0, 60, 0, 100, 1, 4000, 4000, 0, 0, 11, 52146, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Summon Rune Trigger - On update - Cast Explosion'),
(28640, 0, 2, 0, 54, 0, 100, 0, 0, 0, 0, 0, 41, 4500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Summon Rune Trigger - Just summoned - Despawn');
