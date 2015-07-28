UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry` IN (18305,18306,18307);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (18305,18306,18307) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18305,0,0,0,8,0,100,0,32205,0,0,0,33,18305,0,0,0,0,0,7,0,0,0,0,0,0,0,'Burning Blade Pyre (01) - On Spell Hit (Place Maghar Battle Standard)- Give Quest Credit'),
(18306,0,0,0,8,0,100,0,32205,0,0,0,33,18306,0,0,0,0,0,7,0,0,0,0,0,0,0,'Burning Blade Pyre (02) - On Spell Hit (Place Maghar Battle Standard)- Give Quest Credit'),
(18307,0,0,0,8,0,100,0,32205,0,0,0,33,18307,0,0,0,0,0,7,0,0,0,0,0,0,0,'Burning Blade Pyre (03) - On Spell Hit (Place Maghar Battle Standard)- Give Quest Credit');

UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=23439;
DELETE FROM `smart_scripts` WHERE `entryorguid`= 23439 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23439,0,0,1,38,0,100,0,1,1,0,0,45,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Hungry Nether Ray - On Data set - Set Data'),
(23439,0,1,0,61,0,100,0,0,0,0,0,11,41427,0,0,0,0,0,23,0,0,0,0,0,0,0,'Hungry Nether Ray - Linked with Previous Event - Cast Lucille Feed Credit Trigger');

DELETE FROM  `smart_scripts`  WHERE  `entryorguid`=23219 AND  `id`=6;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(23219, 0, 6, 0, 6, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 23439, 0, 50, 0, 0, 0, 0, 'Blackwind Warp Chaser - On Death - Set Data Hungry Nether Ray');
