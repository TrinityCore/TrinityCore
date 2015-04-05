DELETE FROM `event_scripts`  WHERE `id`=8175;

UPDATE `gameobject_template` SET `AIName`= 'SmartGameObjectAI' WHERE  `entry` =179499;

DELETE FROM `smart_scripts` WHERE `entryorguid` =179499 AND `source_type`=1;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(179499,1,0,0,70,0,100,1,2,0,0,0,12,14351,1,900000,0,1,0,8,0,0,0,588.44,606.87,-4.75,5.62,'Ogre Tannin Basket - On State Changed - Spawn Gordok Bushwacker');
