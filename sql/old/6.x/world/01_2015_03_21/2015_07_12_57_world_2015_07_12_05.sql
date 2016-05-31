--
UPDATE `smart_scripts` SET `target_type`=15, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=164911 AND `source_Type`=1 AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=164911 AND `source_Type`=1 AND `id`=1;
UPDATE `smart_scripts` SET `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=164911 AND `source_Type`=1 AND `id`=2;
UPDATE `smart_scripts` SET  `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=9537 AND `source_Type`=0 AND `id`=4;
UPDATE `smart_scripts` SET  `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=9537 AND `source_Type`=0 AND `id`=16;
UPDATE `smart_scripts` SET  `target_param1`=50  WHERE `entryorguid`=9537 AND `source_Type`=0 AND `id`=18;
UPDATE `smart_scripts` SET  `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=-71997 AND `source_Type`=0 AND `id`=10;
UPDATE `smart_scripts` SET  `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=-71997 AND `source_Type`=0 AND `id`=11;
UPDATE `smart_scripts` SET  `target_param1`=50  WHERE `entryorguid`=-71997 AND `source_Type`=0 AND `id`=13;
UPDATE `smart_scripts` SET  `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=-71998 AND `source_Type`=0 AND `id`=10;
UPDATE `smart_scripts` SET  `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=-71998 AND `source_Type`=0 AND `id`=11;
UPDATE `smart_scripts` SET  `target_param1`=50  WHERE `entryorguid`=-71998 AND source_Type=0 AND id=13;
UPDATE `smart_scripts` SET  `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=-71999 AND `source_Type`=0 AND `id`=10;
UPDATE `smart_scripts` SET  `target_type`=11, `target_param2`=50, `target_param3`=0  WHERE `entryorguid`=-71999 AND `source_Type`=0 AND `id`=11;
UPDATE `smart_scripts` SET  `target_param1`=50  WHERE `entryorguid`=-71999 AND `source_Type`=0 AND `id`=13;
UPDATE `smart_scripts` SET `action_param6`=2  WHERE `entryorguid`=9537 AND `source_Type`=0 AND `id`=7;
UPDATE `smart_scripts` SET `action_param6`=2  WHERE `entryorguid`=-71997 AND `source_Type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `action_param6`=2  WHERE `entryorguid`=-71998 AND `source_Type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `action_param6`=2  WHERE `entryorguid`=-71999 AND `source_Type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `link`=2  WHERE `entryorguid`=9537 AND `source_Type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=3  WHERE `entryorguid`=-71997 AND `source_Type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=3  WHERE `entryorguid`=-71998 AND `source_Type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `link`=3  WHERE `entryorguid`=-71999 AND `source_Type`=0 AND `id`=1; 

DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(9537) AND `id`=2;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`IN(-71997,-71998,-71999) AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9537,   0, 2 ,0, 61, 0, 100, 0, 0, 0, 0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Hurley Blackbreath - On spawn - react passif'),
(-71997, 0, 3 ,0, 61, 0, 100, 0, 0, 0, 0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On spawn- react passif'),
(-71998, 0, 3 ,0, 61, 0, 100, 0, 0, 0, 0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On spawn - react passif'),
(-71999, 0, 3 ,0, 61, 0, 100, 0, 0, 0, 0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Blackbreath Crony - On spawn - react passif');

UPDATE `creature_template` SET `unit_flags`=33344 WHERE `entry`=9543;
