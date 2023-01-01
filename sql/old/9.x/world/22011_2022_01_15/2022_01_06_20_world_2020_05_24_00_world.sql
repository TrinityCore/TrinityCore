-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=19656 AND `SourceGroup`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (181582) AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19656) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18158200,18158201, 1965600,1965601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(181582, 1, 0 ,0, 70, 0, 100, 0, 2, 0, 0,0,87,18158200,18158201,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Kaliri Nest - On State Changed - Random Action list'),
(18158200, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,11,29396,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Kaliri Nest - Action list - Cast summon Kaliri female'),
(18158200, 9, 1 ,0, 0, 0, 100, 0, 3000, 3000, 0,0,41,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Kaliri Nest - Action list - Despawn'),
(18158201, 9, 0 ,0, 0, 0, 100, 0, 0, 0, 0,0,11,29397,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Kaliri Nest - Action list - Cast summon Kaliri male'),
(18158201, 9, 1 ,0, 0, 0, 100, 0, 3000, 3000, 0,0,41,0,0,0,0,0,0,1,0,0,0,0, 0, 0, 0, 'Kaliri Nest - Action list - Despawn');
