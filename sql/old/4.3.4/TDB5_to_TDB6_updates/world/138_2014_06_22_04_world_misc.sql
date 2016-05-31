--
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (18734,18735,18736,18737);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18734,18735,18736,18737) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18734,0,0,0,1,0,100,0,0,0,0,0,11,32787,0,0,0,0,0,23,0,0,0,0,0,0,0,'Coarse Stone Statue - OOC - Cast ''Stone Healing'''),
(18735,0,0,0,1,0,100,0,0,0,0,0,11,32788,0,0,0,0,0,23,0,0,0,0,0,0,0,'Heavy Stone Statue - OOC - Cast ''Stone Healing'''),
(18736,0,0,0,1,0,100,0,0,0,0,0,11,32790,0,0,0,0,0,23,0,0,0,0,0,0,0,'Solid Stone Statue - OOC - Cast ''Stone Healing'''),
(18737,0,0,0,1,0,100,0,0,0,0,0,11,32791,0,0,0,0,0,23,0,0,0,0,0,0,0,'Dense Stone Statue - OOC - Cast ''Stone Healing''');
