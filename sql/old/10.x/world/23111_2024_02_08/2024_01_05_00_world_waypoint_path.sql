--
DROP PROCEDURE IF EXISTS waypoint_data_refactor;

DELIMITER ;;
CREATE PROCEDURE waypoint_data_refactor() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='waypoint_data') THEN
    SET @ORIGINAL_PATHID := 25210800;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=3;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 6739.3, -640.189, 68.8529, 2.1293, 7000, 0, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 4 AND 5;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+2;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+2, 0, 6734.39, -637.71, 69.1504, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+2, 1, 6735.74, -633.965, 69.3596, NULL, 0, 1, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=6;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+3;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+3, 0, 6735.74, -633.965, 69.3596, 5.23599, 5000, 0, 0);

    SET @ENTRY := 33021;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 1 AND 4;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 1, 0, '', 40, 0, 100, 0, 2, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 2 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 2, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID+2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 3, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID+2, 0, 0, 53, 0, @ORIGINAL_PATHID+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+2, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 4, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+3, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+3, ' ended - Self: Start path, walk, do not repeat, Passive'));

    SET @ORIGINAL_PATHID := 25211360;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=2;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 6800.38, -772.765, 69.5648, 4.88692, 11000, 0, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=3;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+2;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+2, 0, 6805.59, -775.494, 69.2347, NULL, 0, 1, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=4;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+3;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+3, 0, 6805.59, -775.494, 69.2347, 3.24631, 11000, 0, 0);

    SET @ENTRY := 33021;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 5 AND 8;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 5, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 6, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID+2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 7, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+2, 0, 0, 53, 0, @ORIGINAL_PATHID+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+2, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 8, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+3, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+3, ' ended - Self: Start path, walk, do not repeat, Passive'));

    SET @ORIGINAL_PATHID := 25212240;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=2;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 6872.59, -770.528, 60.6597, 6.10865, 10000, 0, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=3;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+2;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+2, 0, 6876.05, -767.425, 60.8422, NULL, 0, 1, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=4;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+3;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+3, 0, 6876.05, -767.425, 60.8422, 4.43314, 10000, 0, 0);

    SET @ENTRY := 33021;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 9 AND 12;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 9, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 10, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID+2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 11, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+2, 0, 0, 53, 0, @ORIGINAL_PATHID+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+2, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 12, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+3, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+3, ' ended - Self: Start path, walk, do not repeat, Passive'));

    SET @ORIGINAL_PATHID := 5599040;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=2;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 3880.08, 2289.42, 171.062, NULL, 1000, 0, 0);

    SET @ENTRY := 19568;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 11 AND 12;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 11, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 12, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=1;

    SET @ORIGINAL_PATHID := 5599120;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 2 AND 3;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 3726.52, 1962.16, 210.778, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 1, 3726.59, 1962.2, 171.917, NULL, 1000, 0, 0);

    SET @ENTRY := 19568;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 13 AND 14;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 13, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 14, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `smart_scripts` SET `event_param1`=1, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `source_type`=0 AND `id`=2;

    SET @ORIGINAL_PATHID := 10057920;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 18 AND 19;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 2328.24, -5657.19, 385.685, NULL, 2000, 0, 0),
    (@ORIGINAL_PATHID+1, 1, 2323.35, -5656.07, 383.241, 6.24828, 120000, 0, 0);

    SET @ENTRY := 29202;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 0 AND 2;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 0, 0, '', 40, 0, 100, 0, 17, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 17 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 1, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    SET @ORIGINAL_PATHID := 10066160;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=5;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 2386.53, -5591.94, 444.349, 6.0568, 15000, 0, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 6 AND 10;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+2;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+2, 0, 2386.53, -5591.94, 444.349, 6.0568, 3000, 2, 0),
    (@ORIGINAL_PATHID+2, 1, 2396.06, -5594.14, 447.163, 0.118447, 0, 2, 0),
    (@ORIGINAL_PATHID+2, 2, 2436.67, -5610.5, 451.023, 0.118447, 0, 2, 0),
    (@ORIGINAL_PATHID+2, 3, 2473.23, -5633.96, 451.023, 6.08433, 0, 2, 0),
    (@ORIGINAL_PATHID+2, 4, 2490.76, -5638.42, 444.123, 2.14675, 15000, 2, 0);

    SET @ENTRY := 29239;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 0 AND 2;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 0, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 1, 0, '', 40, 0, 100, 0, 0, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID+2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 0 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 2, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID+2, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+2, ' ended - Self: Start path, walk, do not repeat, Passive'));

    SET @ORIGINAL_PATHID := 24502880;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 5 AND 12;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, -5243.18, -543.963, 395.151, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 1, -5242.82, -564.104, 402.526, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 2, -5239.89, -571.179, 404.987, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 3, -5232.08, -573.545, 405.555, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 4, -5227.86, -572.004, 404.709, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 5, -5226.73, -562.097, 408.56, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 6, -5226.73, -562.097, 408.56, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 7, -5226.73, -562.097, 408.56, 2.19912, 54000, 0, 0);

    SET @ENTRY := 727;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 0 AND 4;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 0, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 1, 0, '', 40, 0, 100, 0, 7, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 7 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=24743840 AND `point`=39;
    UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=20038160 AND `point`=4;
    UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=9266880 AND `point`=9;
    UPDATE `waypoint_data` SET `move_type`=1 WHERE `id`=9069120 AND `point`=5;
    DELETE FROM `waypoint_data` WHERE `id` IN(27514, 138498, 143010, 145682, 224562, 644000, 644008, 644016, 645600, 9069120, 9266880, 20038160, 24743840);

    SET @ORIGINAL_PATHID := 84103600;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 15 AND 21;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 169.672, -2436.91, 98.7116, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 1, 164.92, -2444.97, 99.9997, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 2, 158.522, -2452.3, 100.025, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 3, 151.388, -2458.89, 99.7303, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 4, 143.9, -2465, 99.673, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 5, 136.346, -2471.16, 99.0131, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 6, 126.844, -2472.12, 98.5803, NULL, 0, 1, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 22 AND 43;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+2;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+2, 0, 117.131, -2473.38, 96.9939, NULL, 2780, 0, 0),
    (@ORIGINAL_PATHID+2, 1, 94.7629, -2462.67, 91.9291, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 2, 94.0588, -2461.93, 91.8127, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 3, 91.9998, -2459.75, 91.0575, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 4, 89.9569, -2457.59, 90.3083, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 5, 87.9357, -2455.46, 89.8598, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 6, 85.9961, -2453.4, 89.745, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 7, 83.8172, -2451.1, 89.8002, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 8, 81.7462, -2448.91, 89.6886, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 9, 79.752, -2446.8, 89.995, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 10, 78.3356, -2443.88, 90.7138, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 11, 76.6504, -2441.42, 91.745, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 12, 74.9479, -2438.95, 91.9523, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 13, 73.3216, -2436.59, 92.3367, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 14, 71.6621, -2434.17, 92.87, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 15, 69.3297, -2431.92, 93.8752, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 16, 67.3804, -2429.63, 94.4126, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 17, 65.5566, -2427.48, 94.5886, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 18, 63.5159, -2425.09, 95.0666, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 19, 65.8737, -2421.51, 95.4772, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 20, 66.1056, -2418.46, 95.8154, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 21, 66.3362, -2415.45, 95.9636, NULL, 0, 0, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 44 AND 66;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+3;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+3, 0, 71.2909, -2418.11, 95.5608, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 1, 74.4699, -2418.21, 95.5642, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 2, 77.6506, -2418.31, 95.4208, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 3, 78.7806, -2418.34, 95.2809, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 4, 86.4475, -2430.92, 92.4532, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 5, 86.4587, -2430.93, 92.4489, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 6, 93.0418, -2437.55, 90.0974, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 7, 101.076, -2442.38, 92.0791, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 8, 109.424, -2446.71, 94.4404, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 9, 118.478, -2449.23, 95.2044, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 10, 127.879, -2450.98, 96.8674, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 11, 136.834, -2453.8, 98.2303, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 12, 142.355, -2459.99, 99.1255, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 13, 144.778, -2469.53, 100.545, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 14, 137.212, -2474.92, 99.7185, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 15, 128.878, -2480.15, 99.507, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 16, 120.611, -2471.24, 97.2934, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 17, 111.78, -2468.3, 95.1314, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 18, 102.492, -2465.88, 93.8291, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 19, 103.572, -2457.53, 93.9031, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 20, 106.226, -2447.99, 93.4485, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 21, 116.292, -2445.65, 94.4764, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 22, 124.852, -2448.32, 96.082, NULL, 0, 1, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 67 AND 73;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+4;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+4, 0, 133.479, -2452.5, 97.3902, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 1, 142.111, -2456.67, 99.0962, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 2, 146.63, -2459.02, 99.7303, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 3, 151.118, -2454.95, 100.127, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 4, 154.117, -2454.35, 99.8553, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 5, 157.103, -2453.76, 99.9803, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 6, 160.064, -2453.17, 100.376, NULL, 0, 0, 0);

    SET @ENTRY := 165730;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 0 AND 4;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 0, 0, '', 40, 0, 100, 0, 14, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 14 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 1, 0, '', 40, 0, 100, 0, 6, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID+2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 6 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 2, 0, '', 40, 0, 100, 0, 21, @ORIGINAL_PATHID+2, 0, 0, 53, 0, @ORIGINAL_PATHID+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 21 of path ', @ORIGINAL_PATHID+2, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 3, 0, '', 40, 0, 100, 0, 22, @ORIGINAL_PATHID+3, 0, 0, 53, 0, @ORIGINAL_PATHID+4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 22 of path ', @ORIGINAL_PATHID+3, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 4, 0, '', 40, 0, 100, 0, 6, @ORIGINAL_PATHID+4, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 6 of path ', @ORIGINAL_PATHID+4, ' ended - Self: Start path, walk, do not repeat, Passive'));

    SET @ORIGINAL_PATHID := 84126160;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 15 AND 21;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, 169.672, -2436.91, 98.7116, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 1, 164.92, -2444.97, 99.9997, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 2, 158.522, -2452.3, 100.025, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 3, 151.388, -2458.89, 99.7303, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 4, 143.9, -2465, 99.673, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 5, 136.346, -2471.16, 99.0131, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 6, 126.844, -2472.12, 98.5803, NULL, 0, 1, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 22 AND 43;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+2;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+2, 0, 117.131, -2473.38, 96.9939, NULL, 2780, 0, 0),
    (@ORIGINAL_PATHID+2, 1, 94.7629, -2462.67, 91.9291, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 2, 94.0588, -2461.93, 91.8127, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 3, 91.9998, -2459.75, 91.0575, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 4, 89.9569, -2457.59, 90.3083, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 5, 87.9357, -2455.46, 89.8598, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 6, 85.9961, -2453.4, 89.745, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 7, 83.8172, -2451.1, 89.8002, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 8, 81.7462, -2448.91, 89.6886, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 9, 79.752, -2446.8, 89.995, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 10, 78.3356, -2443.88, 90.7138, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 11, 76.6504, -2441.42, 91.745, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 12, 74.9479, -2438.95, 91.9523, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 13, 73.3216, -2436.59, 92.3367, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 14, 71.6621, -2434.17, 92.87, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 15, 69.3297, -2431.92, 93.8752, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 16, 67.3804, -2429.63, 94.4126, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 17, 65.5566, -2427.48, 94.5886, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 18, 63.5159, -2425.09, 95.0666, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 19, 65.8737, -2421.51, 95.4772, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 20, 66.1056, -2418.46, 95.8154, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 21, 66.3362, -2415.45, 95.9636, NULL, 0, 0, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 44 AND 66;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+3;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+3, 0, 71.2909, -2418.11, 95.5608, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 1, 74.4699, -2418.21, 95.5642, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 2, 77.6506, -2418.31, 95.4208, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 3, 78.7806, -2418.34, 95.2809, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 4, 86.4475, -2430.92, 92.4532, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 5, 86.4587, -2430.93, 92.4489, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 6, 93.0418, -2437.55, 90.0974, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 7, 101.076, -2442.38, 92.0791, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 8, 109.424, -2446.71, 94.4404, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 9, 118.478, -2449.23, 95.2044, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 10, 127.879, -2450.98, 96.8674, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 11, 136.834, -2453.8, 98.2303, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 12, 142.355, -2459.99, 99.1255, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 13, 144.778, -2469.53, 100.545, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 14, 137.212, -2474.92, 99.7185, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 15, 128.878, -2480.15, 99.507, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 16, 120.611, -2471.24, 97.2934, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 17, 111.78, -2468.3, 95.1314, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 18, 102.492, -2465.88, 93.8291, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 19, 103.572, -2457.53, 93.9031, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 20, 106.226, -2447.99, 93.4485, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 21, 116.292, -2445.65, 94.4764, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 22, 124.852, -2448.32, 96.082, NULL, 0, 1, 0);

    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 67 AND 73;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+4;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+4, 0, 133.479, -2452.5, 97.3902, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 1, 142.111, -2456.67, 99.0962, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 2, 146.63, -2459.02, 99.7303, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 3, 151.118, -2454.95, 100.127, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 4, 154.117, -2454.35, 99.8553, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 5, 157.103, -2453.76, 99.9803, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+4, 6, 160.064, -2453.17, 100.376, NULL, 0, 0, 0);

    SET @ENTRY := 165730;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 5 AND 9;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 5, 0, '', 40, 0, 100, 0, 14, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 14 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 6, 0, '', 40, 0, 100, 0, 6, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID+2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 6 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 7, 0, '', 40, 0, 100, 0, 21, @ORIGINAL_PATHID+2, 0, 0, 53, 0, @ORIGINAL_PATHID+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 21 of path ', @ORIGINAL_PATHID+2, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 8, 0, '', 40, 0, 100, 0, 22, @ORIGINAL_PATHID+3, 0, 0, 53, 0, @ORIGINAL_PATHID+4, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 22 of path ', @ORIGINAL_PATHID+3, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 9, 0, '', 40, 0, 100, 0, 6, @ORIGINAL_PATHID+4, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 6 of path ', @ORIGINAL_PATHID+4, ' ended - Self: Start path, walk, do not repeat, Passive'));

    SET @ORIGINAL_PATHID := 28762640;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 2 AND 6;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, -6430.58, -1267.63, 180.936, NULL, 38000, 0, 0),
    (@ORIGINAL_PATHID+1, 1, -6430.58, -1267.63, 180.936, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 2, -6459.14, -1255.75, 180.538, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 3, -6459.14, -1255.75, 180.538, NULL, 23000, 0, 0),
    (@ORIGINAL_PATHID+1, 4, -6459.14, -1255.75, 180.538, NULL, 21000, 0, 0);

    SET @ENTRY := 8402;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 24 AND 25;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 24, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 25, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `smart_scripts` SET `event_param1`=3, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=6;
    UPDATE `smart_scripts` SET `event_param1`=1, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=12;
    UPDATE `smart_scripts` SET `event_param1`=4, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=13;

    SET @ORIGINAL_PATHID := 28762720;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 2 AND 6;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, -6422.56, -1234.26, 180.939, NULL, 30000, 0, 0),
    (@ORIGINAL_PATHID+1, 1, -6422.56, -1234.26, 180.939, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 2, -6459.25, -1253.22, 180.5, NULL, 1000, 0, 0),
    (@ORIGINAL_PATHID+1, 3, -6459.25, -1253.22, 180.5, NULL, 26000, 0, 0),
    (@ORIGINAL_PATHID+1, 4, -6459.25, -1253.22, 180.5, NULL, 16000, 0, 0);

    SET @ENTRY := 8402;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 26 AND 27;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 26, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 27, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `smart_scripts` SET `event_param1`=3, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=7;
    UPDATE `smart_scripts` SET `event_param1`=1, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=14;
    UPDATE `smart_scripts` SET `event_param1`=4, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=15;

    SET @ORIGINAL_PATHID := 28762800;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 2 AND 6;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, -6432.58, -1215.31, 180.799, NULL, 42000, 0, 0),
    (@ORIGINAL_PATHID+1, 1, -6432.58, -1215.31, 180.799, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 2, -6460.12, -1252.2, 180.477, NULL, 1000, 0, 0),
    (@ORIGINAL_PATHID+1, 3, -6460.12, -1252.2, 180.477, NULL, 31000, 0, 0),
    (@ORIGINAL_PATHID+1, 4, -6460.12, -1252.2, 180.477, NULL, 27000, 0, 0);

    SET @ENTRY := 8402;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 28 AND 29;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 28, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 29, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `smart_scripts` SET `event_param1`=3, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=8;
    UPDATE `smart_scripts` SET `event_param1`=1, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=16;
    UPDATE `smart_scripts` SET `event_param1`=4, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=17;

    SET @ORIGINAL_PATHID := 28762880;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 2 AND 6;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, -6454.82, -1196.93, 180.932, NULL, 37000, 0, 0),
    (@ORIGINAL_PATHID+1, 1, -6454.82, -1196.93, 180.932, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 2, -6461.54, -1251.62, 180.455, NULL, 1000, 0, 0),
    (@ORIGINAL_PATHID+1, 3, -6461.54, -1251.62, 180.455, NULL, 25000, 0, 0),
    (@ORIGINAL_PATHID+1, 4, -6461.54, -1251.62, 180.455, NULL, 20000, 0, 0);

    SET @ENTRY := 8402;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 30 AND 31;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 30, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 31, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `smart_scripts` SET `event_param1`=3, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=9;
    UPDATE `smart_scripts` SET `event_param1`=1, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=18;
    UPDATE `smart_scripts` SET `event_param1`=4, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=19;

    SET @ORIGINAL_PATHID := 28762960;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 2 AND 6;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, -6478.13, -1212.84, 180.078, NULL, 28000, 0, 0),
    (@ORIGINAL_PATHID+1, 1, -6478.13, -1212.84, 180.078, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 2, -6463, -1251.81, 180.445, NULL, 1000, 0, 0),
    (@ORIGINAL_PATHID+1, 3, -6463, -1251.81, 180.445, NULL, 43000, 0, 0),
    (@ORIGINAL_PATHID+1, 4, -6463, -1251.81, 180.445, NULL, 13000, 0, 0);

    SET @ENTRY := 8402;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 32 AND 33;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 32, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 33, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `smart_scripts` SET `event_param1`=3, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=10;
    UPDATE `smart_scripts` SET `event_param1`=1, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=20;
    UPDATE `smart_scripts` SET `event_param1`=4, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=21;

    SET @ORIGINAL_PATHID := 28763040;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 2 AND 6;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, -6499.06, -1212.11, 180.353, NULL, 22000, 0, 0),
    (@ORIGINAL_PATHID+1, 1, -6499.06, -1212.11, 180.353, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+1, 2, -6463.88, -1252.34, 180.445, NULL, 1000, 0, 0),
    (@ORIGINAL_PATHID+1, 3, -6463.88, -1252.34, 180.445, NULL, 37000, 0, 0),
    (@ORIGINAL_PATHID+1, 4, -6463.88, -1252.34, 180.445, NULL, 15000, 0, 0);

    SET @ENTRY := 8402;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 34 AND 35;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 34, 0, '', 40, 0, 100, 0, 1, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 1 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 35, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive'));

    UPDATE `smart_scripts` SET `event_param1`=3, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=11;
    UPDATE `smart_scripts` SET `event_param1`=1, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=22;
    UPDATE `smart_scripts` SET `event_param1`=4, `event_param2`=@ORIGINAL_PATHID+1 WHERE `entryorguid`=@ENTRY AND `id`=23;

    SET @ORIGINAL_PATHID := 26780560;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 3 AND 12;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+1;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+1, 0, -9216.72, -2154.31, 64.8472, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 1, -9221.72, -2155.06, 64.3472, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 2, -9231.47, -2154.81, 64.8472, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 3, -9236.97, -2156.06, 64.8472, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 4, -9237.97, -2149.06, 64.8472, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 5, -9248.72, -2147.81, 64.3472, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 6, -9256.47, -2137.31, 64.3472, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 7, -9251.72, -2119.31, 66.0972, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 8, -9253.97, -2112.31, 66.5972, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+1, 9, -9263.29, -2104.98, 66.3404, NULL, 30000, 1, 0);

    SET @ORIGINAL_PATHID := 26780560;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 13 AND 17;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+2;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+2, 0, -9249.6, -2116.33, 66.2838, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 1, -9253.45, -2147.05, 64.0928, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 2, -9270.05, -2158.44, 61.4072, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 3, -9288.75, -2158.96, 60.973, NULL, 0, 0, 0),
    (@ORIGINAL_PATHID+2, 4, -9310.32, -2149.19, 63.4833, NULL, 30000, 0, 0);

    SET @ORIGINAL_PATHID := 26780560;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point` BETWEEN 18 AND 34;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+3;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+3, 0, -9278.82, -2159.89, 59.2255, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 1, -9258.45, -2146.43, 64.0864, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 2, -9247.44, -2116.01, 66.362, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 3, -9239.38, -2088.35, 75.5216, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 4, -9219.39, -2090.3, 81.7096, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 5, -9196.93, -2092.5, 87.8293, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 6, -9174.33, -2109.71, 88.9515, NULL, 45000, 1, 0),
    (@ORIGINAL_PATHID+3, 7, -9188.83, -2099.06, 87.9027, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 8, -9214.83, -2090.06, 83.1527, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 9, -9236.58, -2086.31, 76.4027, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 10, -9245.83, -2110.56, 68.4027, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 11, -9255.83, -2135.56, 64.4027, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 12, -9254.08, -2148.06, 64.4027, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 13, -9237.33, -2148.56, 64.6527, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 14, -9237.33, -2156.31, 64.6527, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 15, -9231.33, -2154.81, 64.6527, NULL, 0, 1, 0),
    (@ORIGINAL_PATHID+3, 16, -9218.33, -2155.06, 64.6527, NULL, 0, 1, 0);

    SET @ORIGINAL_PATHID := 26780560;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID AND `point`=35;
    DELETE FROM `waypoint_data` WHERE `id`=@ORIGINAL_PATHID+4;
    INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `wpguid`) VALUES 
    (@ORIGINAL_PATHID+4, 0, -9216.33, -2150.41, 64.3539, NULL, 0, 0, 0);

    SET @ENTRY := 850;
    DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` = @ENTRY AND `id` BETWEEN 0 AND 4;
    UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
    (@ENTRY, 0, 0, 0, '', 40, 0, 100, 0, 2, @ORIGINAL_PATHID, 0, 0, 53, 0, @ORIGINAL_PATHID+1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 2 of path ', @ORIGINAL_PATHID+0, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 1, 0, '', 40, 0, 100, 0, 9, @ORIGINAL_PATHID+1, 0, 0, 53, 0, @ORIGINAL_PATHID+2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 4 of path ', @ORIGINAL_PATHID+1, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 2, 0, '', 40, 0, 100, 0, 4, @ORIGINAL_PATHID+2, 0, 0, 53, 0, @ORIGINAL_PATHID+3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 9 of path ', @ORIGINAL_PATHID+2, ' ended - Self: Start path, walk, do not repeat, Passive')),
    (@ENTRY, 0, 3, 0, '', 40, 0, 100, 0, 16, @ORIGINAL_PATHID+3, 0, 0, 53, 0, @ORIGINAL_PATHID, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, CONCAT('On waypoint 16 of path ', @ORIGINAL_PATHID+3, ' ended - Self: Start path, walk, do not repeat, Passive'));
  
    DROP TABLE IF EXISTS `waypoint_path`;
    CREATE TABLE `waypoint_path`  (
      `PathId` int UNSIGNED NOT NULL,
      `MoveType` tinyint UNSIGNED NOT NULL DEFAULT 0,
      `Flags` tinyint UNSIGNED NOT NULL DEFAULT 0,
      `Comment` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL DEFAULT NULL,
      PRIMARY KEY (`PathId`) USING BTREE
    ) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_unicode_ci ROW_FORMAT = DYNAMIC;

    ALTER TABLE `waypoint_data` 
        CHANGE COLUMN `id` `PathId` int UNSIGNED NOT NULL DEFAULT 0 FIRST,
        CHANGE COLUMN `point` `NodeId` int UNSIGNED NOT NULL DEFAULT 0 AFTER `PathId`,
        CHANGE COLUMN `position_x` `PositionX` float NOT NULL DEFAULT 0 AFTER `NodeId`,
        CHANGE COLUMN `position_y` `PositionY` float NOT NULL DEFAULT 0 AFTER `PositionX`,
        CHANGE COLUMN `position_z` `PositionZ` float NOT NULL DEFAULT 0 AFTER `PositionY`,
        CHANGE COLUMN `orientation` `Orientation` float NULL DEFAULT NULL AFTER `PositionZ`,
        CHANGE COLUMN `delay` `Delay` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Orientation`,
        DROP COLUMN `move_type`,
        DROP COLUMN `wpguid`,
        DROP PRIMARY KEY,
        ADD PRIMARY KEY (`PathId`, `NodeId`) USING BTREE;
        
    RENAME TABLE `waypoint_data` TO `waypoint_path_node`;

    ALTER TABLE `creature_addon` CHANGE COLUMN `path_id` `PathId` int UNSIGNED NOT NULL DEFAULT 0 AFTER `guid`;
    ALTER TABLE `creature_template_addon` CHANGE COLUMN `path_id` `PathId` int UNSIGNED NOT NULL DEFAULT 0 AFTER `entry`;

    INSERT INTO `waypoint_path` (`PathId`, `Comment`) SELECT `PathId`, 'Migrated from refactor' FROM `waypoint_path_node` GROUP BY `PathId`;

    DELETE FROM `command` WHERE `name` IN('reload waypoint_data', 'reload waypoint_path');
    INSERT INTO `command` (`name`, `help`) VALUES 
    ('reload waypoint_path', 'Syntax: .reload waypoint_path will reload waypoint_path and waypoint_path_node tables.');
  END IF;
END;;

DELIMITER ;
CALL waypoint_data_refactor();

DROP PROCEDURE IF EXISTS waypoint_data_refactor;
