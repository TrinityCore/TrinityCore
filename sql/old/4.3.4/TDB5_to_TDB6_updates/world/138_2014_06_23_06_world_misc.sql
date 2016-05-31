--
UPDATE `smart_scripts` SET `target_param2`=30 WHERE `entryorguid`=22444 AND `source_type`=0 AND `id`=1;
UPDATE `gameobject_template` SET `ainame`='SmartGameObjectAI' WHERE `entry`=185298;
DELETE FROM `smart_scripts` WHERE `entryorguid`=185298 AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(185298,1,0,0,70,0,100,0,2,0,0,0,41,0,0,0,0,0,0,19,22444,5,0,0,0,0,0,'Anchorite Relic - On State Changed - Despawn Anchorite Relic Bunny');
