-- 
UPDATE `smart_scripts` SET `action_param4`=1 WHERE `entryorguid` IN (8391) AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `target_x`=-6477.161133, `target_y`=-1255.462769,  `target_z`=180.371185,  `target_o`=1.720018 WHERE `entryorguid` IN (8400) AND `source_type`=0 AND `id`=7;
UPDATE `smart_scripts` SET `target_x`=-6477.161133, `target_y`=-1255.462769,  `target_z`=180.371185,  `target_o`=1.720018 WHERE `entryorguid` IN (8400) AND `source_type`=0 AND `id`=14;

DELETE FROM `smart_scripts` WHERE `entryorguid` =8391 AND `source_type`=0 AND `id`>4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(8391, 0,5,6,11,0,100,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lathoric the Black - On Spawn - Set unit flag'),
(8391, 0,6,7,61,0,100,0,0,0,0,0,2,16,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lathoric the Black - On Spawn - Change faction'),
(8391, 0,7,0,61,0,100,0,0,0,0,0,47,0,0,0,0,0,0,19,8421,20,0,0,0,0,0,'Lathoric the Black - On Spawn - set invisible'),
(8391, 0,8,0,1,0,100,1,7000,7000,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Lathoric the Black - ooc - remove unit flag');

UPDATE `creature` SET `position_x`=-6455.95459, `position_y`=-1247.351807, `position_z`=180.441589, `orientation`=4.558472 WHERE `guid`=5809;
