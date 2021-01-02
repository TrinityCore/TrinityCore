-- 
UPDATE `smart_scripts` SET `action_param3`=1, `target_type`=7 WHERE `entryorguid` IN (28609) AND `id`=0;
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE  `entry`=190769;
DELETE FROM `smart_scripts` WHERE `entryorguid`=190769 AND `source_type`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=19076900 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`,  `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(190769, 1, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, 80, 19076900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 'Gift of the Harvester- On Just Summoned - Action list'),
(19076900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 99, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 'Gift of the Harvester- Action list - Set gob state'),
(19076900, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 93, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 'Gift of the Harvester- Action list - play custum anim'),
(19076900, 9, 2, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 0, 99, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 'Gift of the Harvester- Action list - Set gob state'),
(19076900, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,  0, 'Gift of the Harvester- Action list - Despawn');
