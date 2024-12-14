
DELETE FROM `command` WHERE `name`='reload waypoint_scripts';
DELETE FROM `command` WHERE `name`='wp event';
    
DROP PROCEDURE IF EXISTS drop_waypoint_scripts_related;

DELIMITER ;;
CREATE PROCEDURE drop_waypoint_scripts_related() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='waypoint_scripts') THEN
  
    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 2
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=0 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (0, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 468, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 468'),
    (0, 9, 1, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11.0 seconds - Self: Set emote state to 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 5
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=0 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (0, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 10'),
    (0, 9, 1, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 30.0 seconds - Self: Set emote state to 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 7
    -- AffectedPaths = 2

    DELETE FROM `creature_text` WHERE `CreatureID`=18947 AND `GroupID` BETWEEN 0 AND 1;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (18947, 0, 0, 'Gah! Every time I load something into the wagon, it reappears here within moments!', 12, 0, 100, 0, 0, 0, 0, 16099, 0, ''),
    (18947, 1, 0, 'I should have known better than to have given Silanna that tome of cantrips.', 12, 0, 100, 0, 0, 0, 0, 16100, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=1894700 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1894700, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Talk 0 (BroadcastText: 16099) to invoker'),
    (1894700, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Play emote 6'),
    (1894700, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7.0 seconds - Self: Talk 1 (BroadcastText: 16100) to invoker'),
    (1894700, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Play emote 1');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 39
    -- waypoint_scripts.id = 40
    -- waypoint_scripts.id = 41
    DELETE FROM `creature_text` WHERE `CreatureID`=10432 AND `GroupID` BETWEEN 1 AND 3;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (10432, 1, 0, 'The Lich King''s forces are building.  It is imperative that our timetable supports his plans.', 12, 0, 100, 0, 0, 0, 0, 7194, 0, ''),
    (10432, 2, 0, 'Tomorrow we will begin training of our promising dragons, so don''t forget your chew toys.', 12, 0, 100, 0, 0, 0, 0, 7193, 0, ''),
    (10432, 3, 0, 'Our oldest clutch of dragons are still far from maturity, but with patience and study, we are confident the dragonflight will soon be ready.', 12, 0, 100, 0, 0, 0, 0, 7191, 0, '');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 49
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1841900 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1841900, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 378, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 378');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 51
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3580800 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3580800, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 402, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Play emote 402');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 52
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3622300 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3622300, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 418, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Set emote state to 418'),
    (3622300, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8.0 seconds - Self: Set emote state to 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 470
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3237300 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3237300, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.3185, 'After 1.0 seconds - Self: Set orientation to 3.3185');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 471
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3237301 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3237301, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.804, 'After 1.0 seconds - Self: Set orientation to 1.804');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 472
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3237302 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3237302, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.9747, 'After 1.0 seconds - Self: Set orientation to 4.9747');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 473
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3237400 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3237400, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.9635, 'After 1.0 seconds - Self: Set orientation to 4.9635');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 474
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3237401 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3237401, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.3859, 'After 1.0 seconds - Self: Set orientation to 3.3859');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 475
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2621700 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2621700, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Play emote 1'),
    (2621700, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Play emote 25');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 476
    -- AffectedPaths = 13
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1841901 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1841901, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 69');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 477
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2621701 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2621701, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 69');

    UPDATE `waypoint_data` SET `orientation`=5.37, `action`=0 WHERE `action`=477;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 478
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2707200 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2707200, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.3516, 'After 1.0 seconds - Self: Set orientation to 5.3516');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 479
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2707201 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2707201, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.42, 'After 1.0 seconds - Self: Set orientation to 1.42');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 480
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2736100 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2736100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.2214, 'After 1.0 seconds - Self: Set orientation to 4.2214'),
    (2736100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 69');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 481
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2736101 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2736101, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.3582, 'After 1.0 seconds - Self: Set orientation to 5.3582'),
    (2736101, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 173');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 491
    -- AffectedPaths = 8
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2051200 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2051200, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.0 seconds - Self: Set emote state to 69'),
    (2051200, 9, 1, 0, 0, 0, 100, 0, 54000, 54000, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 54.0 seconds - Self: Play emote 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 492
    -- AffectedPaths = 5
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2051201 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2051201, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.0 seconds - Self: Set emote state to 69'),
    (2051201, 9, 1, 0, 0, 0, 100, 0, 14000, 14000, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 14.0 seconds - Self: Play emote 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 493
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2106500 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2106500, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Set emote state to 69'),
    (2106500, 9, 1, 0, 0, 0, 100, 0, 26000, 26000, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 26.0 seconds - Self: Play emote 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 494
    -- AffectedPaths = 4
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2106501 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2106501, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Set emote state to 69'),
    (2106501, 9, 1, 0, 0, 0, 100, 0, 11000, 11000, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 11.0 seconds - Self: Play emote 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 495
    -- AffectedPaths = 20
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1855900 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1855900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 32754, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Cast spell 32754 on Self'),
    (1855900, 9, 1, 0, 0, 0, 100, 0, 30000, 30000, 0, 0, 28, 32754, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 30.0 seconds - Self: Remove aura due to spell 32754');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1114
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2756600 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2756600, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 124, 226, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Force load EquipmentId 226'),
    (2756600, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 69');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1115
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2756601 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2756601, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 124, 2066, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Force load EquipmentId 2066'),
    (2756601, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 173');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1116
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2756602 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2756602, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 69');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1120
    -- AffectedPaths = 1
    DELETE FROM `creature_text` WHERE `CreatureID`=25235 AND `GroupID`=0;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (25235, 0, 0, 'We''re running low on iron, lads!  I don''t want to see a single bar go to waste, ye hear me now?', 12, 0, 100, 0, 0, 0, 0, 24439, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=2523500 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2523500, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 16'),
    (2523500, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5.0 seconds - Self: Set emote state to 26'),
    (2523500, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.67122, 'After 1.0 seconds - Self: Set orientation to 4.67122'),
    (2523500, 9, 3, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 5, 22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 9.0 seconds - Self: Play emote 22'),
    (2523500, 9, 4, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Talk 0 (BroadcastText: 24439) to invoker');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1121
    -- AffectedPaths = 2
    DELETE FROM `creature_text` WHERE `CreatureID`=25235 AND `GroupID`=1;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (25235, 1, 0, 'Not bad.  Try that trick I told you about when you temper the steel.', 12, 0, 100, 0, 0, 0, 0, 24443, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=2523501 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2523501, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Talk 1 (BroadcastText: 24443) to invoker');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1122
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2523502 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2523502, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 233');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1123
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2739300 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2739300, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 379');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1124
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2739301 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2739301, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 26'),
    (2739301, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 56745, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Cast spell 56745 on Self'),
    (2739301, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 11, 56745, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.0 seconds - Self: Cast spell 56745 on Self');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1125
    -- AffectedPaths = 4
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2355000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2355000, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 3, 0, 21612, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Morph to model 21612');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1126
    -- AffectedPaths = 4
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2355001 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2355001, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 3, 0, 21614, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Morph to model 21614');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1127
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2404000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2404000, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.97788, 'After 1.0 seconds - Self: Set orientation to 4.97788'),
    (2404000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 69');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1128
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2404001 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2404001, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.70399, 'After 1.0 seconds - Self: Set orientation to 5.70399'),
    (2404001, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 173, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 173');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1129
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2404002 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2404002, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.436332, 'After 1.0 seconds - Self: Set orientation to 0.436332'),
    (2404002, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Set emote state to 69');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1134
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=0.104771, `action`=0 WHERE `action`=1134;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1137
    -- AffectedPaths = 3
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2150000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2150000, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Play emote 1');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1138
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2150001 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2150001, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.79253, 'After 1.0 seconds - Self: Set orientation to 2.79253'),
    (2150001, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Play emote 1'),
    (2150001, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6.0 seconds - Self: Play emote 15');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1139
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641700 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641700, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4370.97, -4934.86, 29.1214, 0.982114, 'After 1.0 seconds - Self: Teleport to (4370.97, -4934.86, 29.1214, 0.982114) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1140
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641701 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641701, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4374.84, -4770.08, 52.848, 1.1487, 'After 1.0 seconds - Self: Teleport to (4374.84, -4770.08, 52.848, 1.1487) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1141
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641702 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641702, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4306.51, -4766.24, 56.8766, 0.465818, 'After 1.0 seconds - Self: Teleport to (4306.51, -4766.24, 56.8766, 0.465818) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1142
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641703 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641703, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4463.83, -4644.89, 84.6203, 2.40181, 'After 1.0 seconds - Self: Teleport to (4463.83, -4644.89, 84.6203, 2.40181) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1143
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641704 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641704, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4353.19, -4571.79, 118.402, 1.35635, 'After 1.0 seconds - Self: Teleport to (4353.19, -4571.79, 118.402, 1.35635) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1144
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641705 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641705, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4131.99, -4889.01, 60.1083, 0.369627, 'After 1.0 seconds - Self: Teleport to (4131.99, -4889.01, 60.1083, 0.369627) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1145
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641706 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641706, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4051.38, -5111.15, 12.6903, 0.341522, 'After 1.0 seconds - Self: Teleport to (4051.38, -5111.15, 12.6903, 0.341522) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1146
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641707 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641707, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4182.0, -4758.6, 71.2506, 6.20304, 'After 1.0 seconds - Self: Teleport to (4182.0, -4758.6, 71.2506, 6.20304) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1147
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641708 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641708, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3940.79, -4923.88, 81.667, 0.583063, 'After 1.0 seconds - Self: Teleport to (3940.79, -4923.88, 81.667, 0.583063) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1148
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641709 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641709, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4137.97, -4969.12, 36.8373, 1.16219, 'After 1.0 seconds - Self: Teleport to (4137.97, -4969.12, 36.8373, 1.16219) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1149
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641710 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641710, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4116.99, -5024.95, 30.5289, 0.607674, 'After 1.0 seconds - Self: Teleport to (4116.99, -5024.95, 30.5289, 0.607674) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1150
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641711 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641711, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4388.64, -4820.43, 41.3801, 0.994674, 'After 1.0 seconds - Self: Teleport to (4388.64, -4820.43, 41.3801, 0.994674) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1151
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641712 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641712, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3859.19, -5204.08, 71.2207, 5.69976, 'After 1.0 seconds - Self: Teleport to (3859.19, -5204.08, 71.2207, 5.69976) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1152
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641713 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641713, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3879.8, -4989.44, 85.9219, 0.275225, 'After 1.0 seconds - Self: Teleport to (3879.8, -4989.44, 85.9219, 0.275225) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1153
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641714 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641714, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3922.52, -5267.12, 7.26294, 0.90739, 'After 1.0 seconds - Self: Teleport to (3922.52, -5267.12, 7.26294, 0.90739) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1154
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641715 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641715, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3863.01, -5340.63, 4.19676, 0.484555, 'After 1.0 seconds - Self: Teleport to (3863.01, -5340.63, 4.19676, 0.484555) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1155
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641716 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641716, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3707.78, -5226.12, 125.551, 6.2721, 'After 1.0 seconds - Self: Teleport to (3707.78, -5226.12, 125.551, 6.2721) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1156
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641717 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641717, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3658.67, -5436.73, 26.487, 0.949674, 'After 1.0 seconds - Self: Teleport to (3658.67, -5436.73, 26.487, 0.949674) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1157
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641718 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641718, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3521.14, -5462.94, 168.445, 0.93554, 'After 1.0 seconds - Self: Teleport to (3521.14, -5462.94, 168.445, 0.93554) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1158
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2641719 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2641719, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 62, 571, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3632.08, -5536.6, 12.9124, 1.18737, 'After 1.0 seconds - Self: Teleport to (3632.08, -5536.6, 12.9124, 1.18737) on map 571');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1160
    -- AffectedPaths = 4
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2481200 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2481200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Remove aura due to spell 44385'),
    (2481200, 9, 1, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.31755, 'After 17.0 seconds - Self: Set orientation to 2.31755'),
    (2481200, 9, 2, 0, 0, 0, 100, 0, 18000, 18000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.33832, 'After 18.0 seconds - Self: Set orientation to 1.33832'),
    (2481200, 9, 3, 0, 0, 0, 100, 0, 48000, 48000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.41372, 'After 48.0 seconds - Self: Set orientation to 2.41372'),
    (2481200, 9, 4, 0, 0, 0, 100, 0, 35000, 35000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.52903, 'After 35.0 seconds - Self: Set orientation to 2.52903'),
    (2481200, 9, 5, 0, 0, 0, 100, 0, 61000, 61000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.18812, 'After 61.0 seconds - Self: Set orientation to 4.18812'),
    (2481200, 9, 6, 0, 0, 0, 100, 0, 51000, 51000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.9892, 'After 51.0 seconds - Self: Set orientation to 3.9892'),
    (2481200, 9, 7, 0, 0, 0, 100, 0, 75000, 75000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.95678, 'After 75.0 seconds - Self: Set orientation to 2.95678'),
    (2481200, 9, 8, 0, 0, 0, 100, 0, 71000, 71000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.742216, 'After 71.0 seconds - Self: Set orientation to 0.742216');

    UPDATE `waypoint_data` SET `orientation`=1.26624, `action`=0 WHERE `action`=1160;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1162
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2481201 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2481201, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Remove aura due to spell 44385'),
    (2481201, 9, 1, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.21163, 'After 17.0 seconds - Self: Set orientation to 1.21163'),
    (2481201, 9, 2, 0, 0, 0, 100, 0, 17000, 17000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.55871, 'After 17.0 seconds - Self: Set orientation to 1.55871');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1163
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2481202 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2481202, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 28, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Remove aura due to spell 44385'),
    (2481202, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.13962, 'After 6.0 seconds - Self: Set orientation to 1.13962');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1164
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=5.18363, `action`=0 WHERE `action`=1164;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1165
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=4.10152, `action`=0 WHERE `action`=1165;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1168
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2883200 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2883200, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.32645, 'After 1.0 seconds - Self: Set orientation to 1.32645');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1169
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2883201 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2883201, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.541052, 'After 1.0 seconds - Self: Set orientation to 0.541052');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1170
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2882800 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2882800, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.15388, 'After 1.0 seconds - Self: Set orientation to 4.15388');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1171
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2882900 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2882900, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.68265, 'After 1.0 seconds - Self: Set orientation to 3.68265');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1172
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2882901 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2882901, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.7001, 'After 1.0 seconds - Self: Set orientation to 3.7001');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1175
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2883000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2883000, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.61799, 'After 1.0 seconds - Self: Set orientation to 2.61799');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1177
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3263100 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3263100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.83456, 'After 1.0 seconds - Self: Set orientation to 4.83456'),
    (3263100, 9, 1, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.39823, 'After 13.0 seconds - Self: Set orientation to 4.39823');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1178
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3263101 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3263101, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.331613, 'After 1.0 seconds - Self: Set orientation to 0.331613');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1179
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3263102 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3263102, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.37365, 'After 1.0 seconds - Self: Set orientation to 2.37365');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1180
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3273700 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3273700, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.12414, 'After 1.0 seconds - Self: Set orientation to 3.12414');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1181
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3273701 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3273701, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.46288, 'After 1.0 seconds - Self: Set orientation to 5.46288');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1185
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3778000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3778000, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.84489, 'After 1.0 seconds - Self: Set orientation to 2.84489');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1186
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3778001 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3778001, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.72984, 'After 1.0 seconds - Self: Set orientation to 4.72984');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1187
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3778002 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3778002, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.49582, 'After 1.0 seconds - Self: Set orientation to 2.49582');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1188
    -- AffectedPaths = 130
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1868800 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1868800, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Despawn in 1.0 s');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1190
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3777600 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3777600, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.42797, 'After 1.0 seconds - Self: Set orientation to 5.42797');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1191
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3777601 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3777601, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.48353, 'After 1.0 seconds - Self: Set orientation to 1.48353');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1192
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3777602 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3777602, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.77704, 'After 1.0 seconds - Self: Set orientation to 5.77704');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1193
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2860000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2860000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Play emote 38'),
    (2860000, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 4, 6675, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Play direct sound 6675 to every player in visibility range of Self'),
    (2860000, 9, 2, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 375, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 375');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1196
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2546500 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2546500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 5.84679, 'After 1.0 seconds - Self: Set orientation to 5.84679');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1197
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2546501 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2546501, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.48722, 'After 1.0 seconds - Self: Set orientation to 1.48722');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1198
    -- AffectedPaths = 69
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2534900 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2534900, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 45612, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.0 seconds - Self: Cast spell 45612 on Self'),
    (2534900, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 45609, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Cast spell 45609 on Self');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1201
    -- AffectedPaths = 7
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2850000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2850000, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 233');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1202
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2850500 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2850500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Play emote 18');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1203
    -- AffectedPaths = 4
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2850600 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2850600, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 438, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 438');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682901
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899900 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899900, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.80998, 'After 1.0 seconds - Self: Set orientation to 2.80998');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682902
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899901 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899901, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6.02139, 'After 1.0 seconds - Self: Set orientation to 6.02139');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682903
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899902 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899902, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6.16101, 'After 1.0 seconds - Self: Set orientation to 6.16101');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682904
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899903 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899903, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6.00393, 'After 1.0 seconds - Self: Set orientation to 6.00393');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682921
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899904 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899904, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.72984, 'After 1.0 seconds - Self: Set orientation to 4.72984');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682922
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899905 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899905, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6.0912, 'After 1.0 seconds - Self: Set orientation to 6.0912');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682923
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899906 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899906, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1.81514, 'After 1.0 seconds - Self: Set orientation to 1.81514');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682924
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899907 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899907, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.56047, 'After 1.0 seconds - Self: Set orientation to 3.56047');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682961
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899908 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899908, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.37365, 'After 1.0 seconds - Self: Set orientation to 2.37365');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682962
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899909 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899909, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.16421, 'After 1.0 seconds - Self: Set orientation to 2.16421');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682963
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899910 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899910, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.349066, 'After 1.0 seconds - Self: Set orientation to 0.349066');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 682964
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1899911 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1899911, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.16421, 'After 1.0 seconds - Self: Set orientation to 2.16421');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 683081
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1900300 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1900300, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0.191986, 'After 1.0 seconds - Self: Set orientation to 0.191986');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 683091
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1900301 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1900301, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 2.32129, 'After 1.0 seconds - Self: Set orientation to 2.32129');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 684681
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=3.83972, `action`=0 WHERE `action`=684681;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 684691
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=1.5708, `action`=0 WHERE `action`=684691;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 684701
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=1.41372, `action`=0 WHERE `action`=684701;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 686261
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=1.27409, `action`=0 WHERE `action`=686261;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1128651
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=2.9147, `action`=0 WHERE `action`=1128651;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1128652
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=5.20108, `action`=0 WHERE `action`=1128652;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1128661
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=0.855211, `action`=0 WHERE `action`=1128661;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1128662
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=0.890118, `action`=0 WHERE `action`=1128662;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1128663
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=0.0698132, `action`=0 WHERE `action`=1128663;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1336191
    -- AffectedPaths = 1
    UPDATE `waypoint_data` SET `orientation`=1.46608, `action`=0 WHERE `action`=1336191;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1336192
    -- AffectedPaths = 2
    UPDATE `waypoint_data` SET `orientation`=4.63913, `action`=0 WHERE `action`=1336192;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1378561
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1089900 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1089900, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.0 seconds - Self: Set emote state to 69');

    UPDATE `waypoint_data` SET `orientation`=5.75959, `action`=0 WHERE `action`=1378561;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1378562
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1089901 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1089901, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 17, 133, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4.0 seconds - Self: Set emote state to 133'),
    (1089901, 9, 1, 0, 0, 0, 100, 0, 35000, 35000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 35.0 seconds - Self: Set emote state to 0');

    UPDATE `waypoint_data` SET `orientation`=0.715585, `action`=0 WHERE `action`=1378562;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1378563
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1089902 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1089902, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 28'),
    (1089902, 9, 1, 0, 0, 0, 100, 0, 21000, 21000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 21.0 seconds - Self: Set emote state to 0');

    UPDATE `waypoint_data` SET `orientation`=1.80131, `action`=0 WHERE `action`=1378563;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1380451
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=909700 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (909700, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Play emote 7');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 1380452
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=909701 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (909701, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7.0 seconds - Self: Set emote state to 69'),
    (909701, 9, 1, 0, 0, 0, 100, 0, 9000, 9000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 9.0 seconds - Self: Set emote state to 0');

    UPDATE `waypoint_data` SET `orientation`=3.89208, `action`=0 WHERE `action`=1380452;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 2026160
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1725900 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1725900, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 234');

    UPDATE `waypoint_data` SET `orientation`=0.907571, `action`=0 WHERE `action`=2026160;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 2026161
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1725901 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1725901, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 234');

    UPDATE `waypoint_data` SET `orientation`=3.29867, `action`=0 WHERE `action`=2026161;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 2026250
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1726400 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1726400, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 234');

    UPDATE `waypoint_data` SET `orientation`=2.33874, `action`=0 WHERE `action`=2026250;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 2026251
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1726401 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1726401, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 234');

    UPDATE `waypoint_data` SET `orientation`=0.191986, `action`=0 WHERE `action`=2026251;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 2026270
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1726402 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1726402, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 234');

    UPDATE `waypoint_data` SET `orientation`=5.11381, `action`=0 WHERE `action`=2026270;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 2026271
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1726403 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1726403, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 17, 234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Set emote state to 234');

    UPDATE `waypoint_data` SET `orientation`=4.79965, `action`=0 WHERE `action`=2026271;

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 3848250
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3964200 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3964200, 9, 0, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 5, 54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5.0 seconds - Self: Play emote 54'),
    (3964200, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Play emote 54'),
    (3964200, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 5, 54, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7.0 seconds - Self: Play emote 54');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 3853710
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3964201 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3964201, 9, 0, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4.0 seconds - Self: Play emote 381'),
    (3964201, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 5, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4.0 seconds - Self: Play emote 381');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 3853711
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3964202 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3964202, 9, 0, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 7.0 seconds - Self: Set emote state to 233'),
    (3964202, 9, 1, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6.0 seconds - Self: Set emote state to 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 3860971
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=3984300 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (3984300, 9, 0, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.0 seconds - Self: Play emote 432'),
    (3984300, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 5, 60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.0 seconds - Self: Play emote 60'),
    (3984300, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6.0 seconds - Self: Play emote 5');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 5753900
    -- AffectedPaths = 4
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1658000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1658000, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Play emote 7');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 5862800
    -- AffectedPaths = 10
    DELETE FROM `smart_scripts` WHERE `entryorguid`=1690700 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1690700, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Set emote state to 69'),
    (1690700, 9, 1, 0, 0, 0, 100, 0, 40000, 40000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 40.0 seconds - Self: Set emote state to 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 6556600
    -- AffectedPaths = 1

    DELETE FROM `creature_text` WHERE `CreatureID`=18274 AND `GroupID`=0;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (18274, 0, 0, 'Try to keep appraisal errors to a minimum.  I''d hate to tell Gezhe we''ve overpaid on another gem shipment this month.', 12, 0, 100, 0, 0, 0, 0, 16960, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=1827400 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (1827400, 9, 0, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15.0 seconds - Self: Talk 0 (BroadcastText: 16960) to invoker');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 11026002
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2850400 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2850400, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 51733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Cast spell 51733 on Self');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 11026401
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2850401 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2850401, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 51733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Cast spell 51733 on Self');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 11026402
    -- AffectedPaths = 1
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2850402 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2850402, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 51733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Cast spell 51733 on Self');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 11130700
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2730000 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2730000, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Set emote state to 69'),
    (2730000, 9, 1, 0, 0, 0, 100, 0, 15000, 15000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 15.0 seconds - Self: Set emote state to 0');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 11393600
    -- AffectedPaths = 4
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2937500 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2937500, 9, 0, 0, 0, 0, 100, 0, 13000, 13000, 0, 0, 5, 53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 13.0 seconds - Self: Play emote 53');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 11730800
    -- AffectedPaths = 4
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2940700 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2940700, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 5, 36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Play emote 36');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 12556600
    -- AffectedPaths = 2
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2604400 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2604400, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 11, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2.0 seconds - Self: Cast spell 68442 on Self'),
    (2604400, 9, 1, 0, 0, 0, 100, 0, 8000, 8000, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 8.0 seconds - Self: Play emote 1'),
    (2604400, 9, 2, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 28, 68442, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 10.0 seconds - Self: Remove aura due to spell 68442');

    -- ---------------------------------------------------------------------------------------------------------------------
    -- waypoint_scripts.id = 13036300
    -- AffectedPaths = 3
    DELETE FROM `smart_scripts` WHERE `entryorguid`=2918500 AND `source_type`=9;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (2918500, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 11, 26047, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1.0 seconds - Self: Cast spell 26047 on Self'),
    (2918500, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3.0 seconds - Self: Set emote state to 0');

    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10884320 AND `point` IN(3,9,13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5440720 AND `point` IN(6,1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28902160 AND `point` IN(9,5,2,8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4816480 AND `point` IN(11,4,8,10,3,7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3493680 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3493840 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3494320 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3638080 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3904400 AND `point` IN(2,3,4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3955680 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4507840 AND `point` IN(2,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=16144000 AND `point` IN(2,3,4,5,9,10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6639440 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6639520 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6809200 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6641760 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4696160 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5089120 AND `point` IN(16,18);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5251040 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5598960 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5599040 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5599120 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5599280 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5599440 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5599520 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5599840 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5599920 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5598240 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5598400 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5598560 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5354960 AND `point` IN(2,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5602000 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5602560 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5602960 AND `point` IN(2,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5682240 AND `point` IN(1,3,5,8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5937200 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6668000 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6766560 AND `point` IN(1,3,5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6777440 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7544720 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7546000 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7558720 AND `point` IN(1,2,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7727360 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7727520 AND `point` IN(4,5,6,7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7746000 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5676080 AND `point` IN(1,3,2,4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5777120 AND `point` IN(2,3,4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8430720 AND `point` IN(6,9,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7013520 AND `point` IN(2,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7013600 AND `point` IN(2,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7013680 AND `point` IN(3,6,9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=24565840 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9116720 AND `point` IN(1,4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10701040 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10924320 AND `point` IN(4,10,18);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5809760 AND `point` IN(3,7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5810720 AND `point` IN(8,15,19);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5810800 AND `point` IN(4,13,28);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=20031440 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=20031600 AND `point` IN(4,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5809200 AND `point` IN(7,13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5923360 AND `point` IN(4,18,24);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5923760 AND `point` IN(8,14,21);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8360080 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8360240 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8362080 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8362720 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8362800 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8371040 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8376400 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8376480 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8380960 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8381040 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8381120 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8381680 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8381920 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8382000 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8382320 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8382400 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8382560 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8382640 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8382720 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8382800 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5511840 AND `point` IN(2,4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28779840 AND `point` IN(2,5,7,8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5712400 AND `point` IN(14);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6298480 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7069600 AND `point` IN(3,9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28752720 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28755440 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28758160 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28762640 AND `point` IN(5,3,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28762720 AND `point` IN(5,3,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28762800 AND `point` IN(5,3,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28762880 AND `point` IN(5,3,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28762960 AND `point` IN(5,3,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28763040 AND `point` IN(5,3,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7070000 AND `point` IN(3,9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7070080 AND `point` IN(3,8,13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7070160 AND `point` IN(3,7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7070240 AND `point` IN(3,10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7922320 AND `point` IN(3,7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8165680 AND `point` IN(2,3,4,5,6,7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8778800 AND `point` IN(14);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9059680 AND `point` IN(3,7,13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9060080 AND `point` IN(11,22);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9060160 AND `point` IN(13,26);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9182480 AND `point` IN(3,4,8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8252880 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8253600 AND `point` IN(36);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8905200 AND `point` IN(4,11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8905520 AND `point` IN(3,4,14);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8990320 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8990720 AND `point` IN(8,16);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8779120 AND `point` IN(2,4,7,10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7662480 AND `point` IN(2,5,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7052160 AND `point` IN(8,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7052240 AND `point` IN(8,13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9633440 AND `point` IN(4,10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=16185120 AND `point` IN(2,5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=16185360 AND `point` IN(2,5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7051760 AND `point` IN(2,4,5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1630632 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6759280 AND `point` IN(3,6,10,13,14,16,19,22,28,31);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5990240 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5990320 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5990400 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5990480 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6032560 AND `point` IN(3,6,9,10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8040800 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8040880 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8040960 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041040 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041120 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041520 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041840 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8042160 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041200 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8042080 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041600 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8042240 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041760 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041360 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041920 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041280 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8041440 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8039440 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8042400 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8039040 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7936640 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9454160 AND `point` IN(65,1,66,141,140,155);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9455280 AND `point` IN(1,17,47,2,18,48);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9959760 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28902000 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28902240 AND `point` IN(2,5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28917440 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28917680 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=28919200 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8876160 AND `point` IN(2,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8843120 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8846720 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8852080 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5076000 AND `point` IN(17);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8556800 AND `point` IN(17,21,23);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=16282000 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10691920 AND `point` IN(5,15,18);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=231296 AND `point` IN(10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1147120 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1147200 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1147360 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1198160 AND `point` IN(18);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1198240 AND `point` IN(17);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1848880 AND `point` IN(21);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1973600 AND `point` IN(23);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1980880 AND `point` IN(15);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=1983520 AND `point` IN(14);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2008000 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2124720 AND `point` IN(18);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2125120 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2544560 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2546640 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=2565760 AND `point` IN(17);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3238000 AND `point` IN(23);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3238080 AND `point` IN(27);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=3616320 AND `point` IN(23);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5921440 AND `point` IN(16);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6631920 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6633200 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6753440 AND `point` IN(11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6753840 AND `point` IN(11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6754560 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6754880 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6754960 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=6755120 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7727440 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7732480 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7732560 AND `point` IN(10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7732640 AND `point` IN(10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9445120 AND `point` IN(31);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9833200 AND `point` IN(11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9836640 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9837920 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9838960 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9899040 AND `point` IN(14);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10310800 AND `point` IN(52);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10311120 AND `point` IN(41);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10311440 AND `point` IN(35);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10311520 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10311600 AND `point` IN(15);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10311840 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10311920 AND `point` IN(32);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10312080 AND `point` IN(48);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10312320 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10312400 AND `point` IN(21);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10312800 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10313520 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10313840 AND `point` IN(14);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10313920 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10314000 AND `point` IN(10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10314160 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10314720 AND `point` IN(15);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10314800 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10314880 AND `point` IN(15);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10315120 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10315680 AND `point` IN(10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10315840 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10315920 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10316560 AND `point` IN(20);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10317920 AND `point` IN(10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10318800 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10318880 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10319040 AND `point` IN(17);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10319200 AND `point` IN(27);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10319280 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10319760 AND `point` IN(13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10319840 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10319920 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10337360 AND `point` IN(15);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10361360 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10361440 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10362320 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10362400 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10362480 AND `point` IN(10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10363520 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10363680 AND `point` IN(11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10363760 AND `point` IN(18);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10428960 AND `point` IN(4,1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10429040 AND `point` IN(10,1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10429840 AND `point` IN(18,1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10430080 AND `point` IN(18);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10430320 AND `point` IN(26);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10445360 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10445600 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10448640 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10449200 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10452240 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10452880 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10452960 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10453040 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10453520 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10453680 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10454000 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10454080 AND `point` IN(14);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10454160 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10454320 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10454560 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10459440 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10460320 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10463040 AND `point` IN(11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10463120 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10463280 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10463360 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10463520 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10463680 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10463840 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464080 AND `point` IN(5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464160 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464240 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464320 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464400 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464480 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464720 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464800 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464880 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10464960 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10465040 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10465520 AND `point` IN(11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10465600 AND `point` IN(8);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10466000 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10466160 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10466320 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10466400 AND `point` IN(9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8098880 AND `point` IN(4,13,16);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9068400 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9069120 AND `point` IN(3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8569680 AND `point` IN(1,2,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7770320 AND `point` IN(1,2,3,4,5,6,7,8,9,10,11,12,13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7770400 AND `point` IN(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7770960 AND `point` IN(1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10286160 AND `point` IN(8,1,5,12,13);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10286320 AND `point` IN(1,4,5,2,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10286400 AND `point` IN(1,2,3,4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9270320 AND `point` IN(5,12,19,26);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5463200 AND `point` IN(2,5,7,9);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5463360 AND `point` IN(2,5,8,11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5463680 AND `point` IN(5,11,15,19);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5464640 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5464720 AND `point` IN(10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=11028480 AND `point` IN(2,8,11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=11043600 AND `point` IN(2,4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=16209280 AND `point` IN(4,10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=16210000 AND `point` IN(6,12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=16210160 AND `point` IN(4,10);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=30786000 AND `point` IN(1,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=30829680 AND `point` IN(2,5);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=30887760 AND `point` IN(6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4346960 AND `point` IN(2,4,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4603120 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4690240 AND `point` IN(6,12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4690560 AND `point` IN(3,12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4690800 AND `point` IN(2,6);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4690880 AND `point` IN(5,12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=4691040 AND `point` IN(3,11);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5245280 AND `point` IN(4);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8820800 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8821120 AND `point` IN(1,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=8904560 AND `point` IN(1,2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=5921360 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=7064640 AND `point` IN(7);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9114880 AND `point` IN(1);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9114960 AND `point` IN(2);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9384640 AND `point` IN(12);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=9384800 AND `point` IN(1,2,3);
    UPDATE `waypoint_data` SET `action`=0 WHERE `id`=10045280 AND `point` IN(6,25);

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=18947;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=18947 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18947, 0, 0, 0, 40, 0, 100, 0, 6, 5440720, 0, 0, 80, 1894700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 5440720 reached - Self: Start timed action list id 1894700'), -- waypoint_script.id = 7
    (18947, 0, 1, 0, 40, 0, 100, 0, 1, 5440720, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5440720 reached - Self: Play emote 16'), -- waypoint_script.id = 1078
    (18947, 0, 2, 0, 40, 0, 100, 0, 2, 5440720, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 5440720 reached - Self: Play emote 16'); -- waypoint_script.id = 1078

    DELETE FROM `smart_scripts` WHERE `entryorguid`=48228 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (48228, 0, 3, 0, 40, 0, 100, 0, 9, 28902160, 0, 0, 80, 1894700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 28902160 reached - Self: Start timed action list id 1894700'), -- waypoint_script.id = 7
    (48228, 0, 4, 0, 40, 0, 100, 0, 5, 28902160, 0, 0, 80, 2523502, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28902160 reached - Self: Start timed action list id 2523502'), -- waypoint_script.id = 1122
    (48228, 0, 5, 0, 40, 0, 100, 0, 2, 28902160, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 28902160 reached - Self: Set emote state to 69'), -- waypoint_script.id = 1166
    (48228, 0, 6, 0, 40, 0, 100, 0, 8, 28902160, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 28902160 reached - Self: Set emote state to 69'); -- waypoint_script.id = 1166

    DELETE FROM `smart_scripts` WHERE `entryorguid`=-201800 AND `source_type`=0 AND `id` >= 8;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (-201800, 0, 8, 0, 40, 0, 100, 0, 10, 16144000, 0, 0, 5, 38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 16144000 reached - Self: Play emote 38'); -- waypoint_script.id = 48

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18419 AND `source_type`=0 AND `id` >= 5;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18419, 0, 5, 0, 40, 0, 100, 0, 1, 6639440, 0, 0, 80, 1841900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 6639440 reached - Self: Start timed action list id 1841900'), -- waypoint_script.id = 49
    (18419, 0, 6, 0, 40, 0, 100, 0, 1, 6639520, 0, 0, 80, 1841900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 6639520 reached - Self: Start timed action list id 1841900'), -- waypoint_script.id = 49
    (18419, 0, 7, 0, 40, 0, 100, 0, 2, 6639440, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 6639440 reached - Self: Start timed action list id 1841901'), -- waypoint_script.id = 476
    (18419, 0, 8, 0, 40, 0, 100, 0, 2, 6639520, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 6639520 reached - Self: Start timed action list id 1841901'); -- waypoint_script.id = 476

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=35808;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=35808 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (35808, 0, 0, 0, 40, 0, 100, 0, 3, 6809200, 0, 0, 80, 3580800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 6809200 reached - Self: Start timed action list id 3580800'); -- waypoint_script.id = 51

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=36223;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=36223 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (36223, 0, 0, 0, 40, 0, 100, 0, 1, 6641760, 0, 0, 80, 3622300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 6641760 reached - Self: Start timed action list id 3622300'); -- waypoint_script.id = 52

    DELETE FROM `smart_scripts` WHERE `entryorguid`=16924 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (16924, 0, 1, 0, 40, 0, 100, 0, 7, 4696160, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 4696160 reached - Self: Talk 0 (BroadcastText: 12833) to invoker'); -- waypoint_script.id = 71

    DELETE FROM `creature_text` WHERE `CreatureID`=17901 AND `GroupID` IN(0, 1);
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (17901, 0, 0, 'The wind speaks of our enemies'' movements, Ashyen.  The naga will attack again.', 12, 0, 100, 0, 0, 0, 0, 14565, 0, ''),
    (17901, 1, 0, 'Very well.  When that decision is made, I will be ready.  Let us hope it won''t be too late.', 12, 0, 100, 0, 0, 0, 0, 14567, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=17901 AND `source_type`=0 AND `id` >= 6;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (17901, 0, 6, 0, 40, 0, 100, 0, 16, 5089120, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 16 of path 5089120 reached - Self: Talk 0 (BroadcastText: 14565) to invoker'), -- waypoint_script.id = 72
    (17901, 0, 7, 0, 40, 0, 100, 0, 18, 5089120, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 5089120 reached - Self: Talk 1 (BroadcastText: 14567) to invoker'); -- waypoint_script.id = 73

    DELETE FROM `creature_text` WHERE `CreatureID`=18302 AND `GroupID`=0;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (18302, 0, 0, 'I will do my best to take care of the children, Greatmother.', 12, 0, 100, 0, 0, 0, 0, 15144, 0, '');

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=18302;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=18302 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18302, 0, 0, 0, 40, 0, 100, 0, 1, 5251040, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5251040 reached - Self: Talk 0 (BroadcastText: 15144) to invoker'); -- waypoint_script.id = 74

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=19568;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=19568 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (19568, 0, 0, 0, 40, 0, 100, 0, 4, 5598960, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3915.08, 2111.54, 274.422, 0.0, 'On waypoint 4 of path 5598960 reached - Self: Teleport to (3915.08, 2111.54, 274.422, 0.0) on map 530'), -- waypoint_script.id = 80
    (19568, 0, 1, 0, 40, 0, 100, 0, 2, 5599040, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3887.31, 2258.43, 214.298, 0.0, 'On waypoint 2 of path 5599040 reached - Self: Teleport to (3887.31, 2258.43, 214.298, 0.0) on map 530'), -- waypoint_script.id = 81
    (19568, 0, 2, 0, 40, 0, 100, 0, 3, 5599120, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3726.48, 1961.26, 249.912, 0.0, 'On waypoint 3 of path 5599120 reached - Self: Teleport to (3726.48, 1961.26, 249.912, 0.0) on map 530'), -- waypoint_script.id = 82
    (19568, 0, 3, 0, 40, 0, 100, 0, 3, 5599280, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4044.87, 2025.38, 267.544, 0.0, 'On waypoint 3 of path 5599280 reached - Self: Teleport to (4044.87, 2025.38, 267.544, 0.0) on map 530'), -- waypoint_script.id = 83
    (19568, 0, 4, 0, 40, 0, 100, 0, 3, 5599440, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4148.98, 2042.91, 164.712, 0.0, 'On waypoint 3 of path 5599440 reached - Self: Teleport to (4148.98, 2042.91, 164.712, 0.0) on map 530'), -- waypoint_script.id = 84
    (19568, 0, 5, 0, 40, 0, 100, 0, 4, 5599520, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3827.96, 1979.83, 275.021, 0.0, 'On waypoint 4 of path 5599520 reached - Self: Teleport to (3827.96, 1979.83, 275.021, 0.0) on map 530'), -- waypoint_script.id = 85
    (19568, 0, 6, 0, 40, 0, 100, 0, 3, 5599840, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4151.25, 2042.39, 245.592, 0.0, 'On waypoint 3 of path 5599840 reached - Self: Teleport to (4151.25, 2042.39, 245.592, 0.0) on map 530'), -- waypoint_script.id = 86
    (19568, 0, 7, 0, 40, 0, 100, 0, 7, 5599920, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3957.74, 1894.36, 269.926, 0.0, 'On waypoint 7 of path 5599920 reached - Self: Teleport to (3957.74, 1894.36, 269.926, 0.0) on map 530'), -- waypoint_script.id = 87
    (19568, 0, 8, 0, 40, 0, 100, 0, 6, 5598240, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3990.15, 1735.37, 270.177, 0.0, 'On waypoint 6 of path 5598240 reached - Self: Teleport to (3990.15, 1735.37, 270.177, 0.0) on map 530'), -- waypoint_script.id = 88
    (19568, 0, 9, 0, 40, 0, 100, 0, 3, 5598400, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4001.01, 1683.55, 137.226, 0.0, 'On waypoint 3 of path 5598400 reached - Self: Teleport to (4001.01, 1683.55, 137.226, 0.0) on map 530'), -- waypoint_script.id = 89
    (19568, 0, 10, 0, 40, 0, 100, 0, 5, 5598560, 0, 0, 62, 530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 3696.55, 1954.49, 134.377, 0.0, 'On waypoint 5 of path 5598560 reached - Self: Teleport to (3696.55, 1954.49, 134.377, 0.0) on map 530'); -- waypoint_script.id = 90

    DELETE FROM `creature_text` WHERE `CreatureID`=19610 AND `GroupID`=9;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (19610, 9, 0, 'I have another reading from the nether.', 12, 0, 100, 0, 0, 0, 0, 17035, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=19610 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (19610, 0, 0, 0, 40, 0, 100, 0, 5, 5602560, 0, 0, 1, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 5602560 reached - Self: Talk 9 (BroadcastText: 17035) to invoker'); -- waypoint_script.id = 216

    DELETE FROM `creature_text` WHERE `CreatureID`=19612 AND `GroupID` IN(0, 1);
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (19612, 0, 0, 'Well hand it over and let''s see what you''ve got!', 12, 0, 100, 0, 0, 0, 0, 17045, 0, ''),
    (19612, 1, 0, 'Great Gazlowe!', 12, 0, 100, 0, 0, 0, 0, 17056, 0, '');

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=19612;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=19612 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (19612, 0, 0, 0, 40, 0, 100, 0, 2, 5602960, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 5602960 reached - Self: Talk 0 (BroadcastText: 17045) to invoker'), -- waypoint_script.id = 218
    (19612, 0, 1, 0, 40, 0, 100, 0, 3, 5602960, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 5602960 reached - Self: Talk 1 (BroadcastText: 17056) to invoker'); -- waypoint_script.id = 219

    DELETE FROM `creature_text` WHERE `CreatureID`=19882 AND `GroupID` BETWEEN 0 AND 1;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (19882, 0, 0, 'Hey, you there.  Want some candy?', 12, 0, 100, 0, 0, 0, 0, 17486, 0, ''),
    (19882, 1, 0, 'Bip!', 12, 0, 100, 0, 0, 0, 0, 17485, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=19882 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (19882, 0, 1, 0, 40, 0, 100, 0, 1, 5682240, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5682240 reached - Self: Talk 0 (BroadcastText: 17486) to invoker'), -- waypoint_script.id = 220
    (19882, 0, 2, 0, 40, 0, 100, 0, 3, 5682240, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 5682240 reached - Self: Talk 1 (BroadcastText: 17485) to invoker'), -- waypoint_script.id = 221
    (19882, 0, 3, 0, 40, 0, 100, 0, 5, 5682240, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 5682240 reached - Self: Talk 1 (BroadcastText: 17485) to invoker'), -- waypoint_script.id = 222
    (19882, 0, 4, 0, 40, 0, 100, 0, 8, 5682240, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 5682240 reached - Self: Talk 1 (BroadcastText: 17485) to invoker'); -- waypoint_script.id = 223

    DELETE FROM `creature_text` WHERE `CreatureID`=21151 AND `GroupID`=0;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (21151, 0, 0, 'Right.  We just busted our tails to haul all of this stuff up here, and you want to work more?', 12, 0, 100, 0, 0, 0, 0, 18816, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=21151 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (21151, 0, 1, 0, 40, 0, 100, 0, 5, 5937200, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 5937200 reached - Self: Talk 0 (BroadcastText: 18816) to invoker'); -- waypoint_script.id = 226

    DELETE FROM `creature_text` WHERE `CreatureID`=17222 AND `GroupID` BETWEEN 0 AND 2;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (17222, 0, 0, 'This won''t do at all! We have to secure the foundation or the entire structure will crumble!', 12, 0, 100, 0, 0, 0, 0, 13572, 0, ''),
    (17222, 1, 0, 'I have much to do! Why can they not leave me to my work?', 12, 0, 100, 0, 0, 0, 0, 13580, 0, ''),
    (17222, 2, 0, 'By the foul teat of Kil''Jaeden''s rotted torso, the entire backside is blown out! How can someone be expected to live in here? I''ve seen enough!', 12, 0, 100, 0, 0, 0, 0, 13576, 0, '');

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=17222;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=17222 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (17222, 0, 0, 0, 40, 0, 100, 0, 1, 6766560, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 6766560 reached - Self: Talk 0 (BroadcastText: 13572) to invoker'), -- waypoint_script.id = 329
    (17222, 0, 1, 0, 40, 0, 100, 0, 3, 6766560, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 6766560 reached - Self: Talk 1 (BroadcastText: 13580) to invoker'), -- waypoint_script.id = 330
    (17222, 0, 2, 0, 40, 0, 100, 0, 5, 6766560, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 6766560 reached - Self: Talk 2 (BroadcastText: 13576) to invoker'); -- waypoint_script.id = 331

    DELETE FROM `creature_text` WHERE `CreatureID`=18296 AND `GroupID`=0;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (18296, 0, 0, 'Don''t go close to the lake! It''s haunted!', 12, 0, 100, 0, 0, 0, 0, 15119, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18296 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18296, 0, 1, 0, 40, 0, 100, 0, 5, 6777440, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 6777440 reached - Self: Talk 0 (BroadcastText: 15119) to invoker'); -- waypoint_script.id = 333

    DELETE FROM `creature_text` WHERE `CreatureID`=24976 AND `GroupID`=0;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (24976, 0, 0, 'Charge!', 12, 0, 100, 0, 0, 0, 0, 24425, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=24976 AND `source_type`=0 AND `id` >= 4;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (24976, 0, 4, 0, 40, 0, 100, 0, 1, 7544720, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 7544720 reached - Self: Talk 0 (BroadcastText: 24425) to invoker'), -- waypoint_script.id = 447
    (24976, 0, 5, 0, 40, 0, 100, 0, 1, 7546000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 7546000 reached - Self: Talk 0 (BroadcastText: 24425) to invoker'); -- waypoint_script.id = 449

    DELETE FROM `creature_text` WHERE `CreatureID`=23718 AND `GroupID` BETWEEN 0 AND 2;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (23718, 0, 0, 'Ahh, my precious Ameenah! How wonderful to see you again.', 12, 0, 100, 0, 0, 0, 0, 22216, 0, ''),
    (23718, 1, 0, 'Yer wearin down, princess. I can sense it!', 12, 0, 100, 0, 0, 0, 0, 22211, 0, ''),
    (23718, 2, 0, 'Hmm, don''t mind if I do!', 12, 0, 100, 0, 0, 0, 0, 22206, 0, '');

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=23718;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=23718 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (23718, 0, 0, 0, 40, 0, 100, 0, 1, 7558720, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 7558720 reached - Self: Talk 0 (BroadcastText: 22216) to invoker'), -- waypoint_script.id = 451
    (23718, 0, 1, 0, 40, 0, 100, 0, 2, 7558720, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7558720 reached - Self: Talk 1 (BroadcastText: 22211) to invoker'), -- waypoint_script.id = 452
    (23718, 0, 2, 0, 40, 0, 100, 0, 3, 7558720, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 7558720 reached - Self: Talk 2 (BroadcastText: 22206) to invoker'); -- waypoint_script.id = 453

    DELETE FROM `smart_scripts` WHERE `entryorguid`=19475 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (19475, 0, 2, 0, 40, 0, 100, 0, 8, 7727360, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 7727360 reached - Self: Talk 0 (BroadcastText: 25086) to invoker'); -- waypoint_script.id = 455

    DELETE FROM `smart_scripts` WHERE `entryorguid`=25885 AND `source_type`=0 AND `id` >= 6;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (25885, 0, 6, 0, 40, 0, 100, 0, 4, 7727520, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 7727520 reached - Self: Talk 1 (BroadcastText: 25073) to invoker'), -- waypoint_script.id = 456
    (25885, 0, 7, 0, 40, 0, 100, 0, 5, 7727520, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 7727520 reached - Self: Talk 2 (BroadcastText: 25074) to invoker'), -- waypoint_script.id = 457
    (25885, 0, 8, 0, 40, 0, 100, 0, 6, 7727520, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 7727520 reached - Self: Talk 3 (BroadcastText: 25075) to invoker'), -- waypoint_script.id = 458
    (25885, 0, 9, 0, 40, 0, 100, 0, 7, 7727520, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 7727520 reached - Self: Talk 4 (BroadcastText: 25076) to invoker'); -- waypoint_script.id = 459

    DELETE FROM `creature_text` WHERE `CreatureID`=24688 AND `GroupID`=0;
    INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
    (24688, 0, 0, 'I''ll never stop. Never...', 12, 0, 100, 0, 0, 0, 0, 23842, 0, '');

    DELETE FROM `smart_scripts` WHERE `entryorguid`=24688 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (24688, 0, 2, 0, 40, 0, 100, 0, 2, 7746000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7746000 reached - Self: Talk 0 (BroadcastText: 23842) to invoker'); -- waypoint_script.id = 463

    DELETE FROM `smart_scripts` WHERE `entryorguid`=32373 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (32373, 0, 3, 0, 40, 0, 100, 0, 1, 5676080, 0, 0, 80, 3237300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5676080 reached - Self: Start timed action list id 3237300'), -- waypoint_script.id = 470
    (32373, 0, 4, 0, 40, 0, 100, 0, 3, 5676080, 0, 0, 80, 3237300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 5676080 reached - Self: Start timed action list id 3237300'), -- waypoint_script.id = 470
    (32373, 0, 5, 0, 40, 0, 100, 0, 2, 5676080, 0, 0, 80, 3237301, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 5676080 reached - Self: Start timed action list id 3237301'), -- waypoint_script.id = 471
    (32373, 0, 6, 0, 40, 0, 100, 0, 4, 5676080, 0, 0, 80, 3237302, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 5676080 reached - Self: Start timed action list id 3237302'); -- waypoint_script.id = 472

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=32374;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=32374 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (32374, 0, 0, 0, 40, 0, 100, 0, 2, 5777120, 0, 0, 80, 3237400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 5777120 reached - Self: Start timed action list id 3237400'), -- waypoint_script.id = 473
    (32374, 0, 1, 0, 40, 0, 100, 0, 3, 5777120, 0, 0, 80, 3237400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 5777120 reached - Self: Start timed action list id 3237400'), -- waypoint_script.id = 473
    (32374, 0, 2, 0, 40, 0, 100, 0, 4, 5777120, 0, 0, 80, 3237401, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 5777120 reached - Self: Start timed action list id 3237401'); -- waypoint_script.id = 474

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=26217;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=26217 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (26217, 0, 0, 0, 40, 0, 100, 0, 6, 8430720, 0, 0, 80, 2621700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8430720 reached - Self: Start timed action list id 2621700'), -- waypoint_script.id = 475
    (26217, 0, 1, 0, 40, 0, 100, 0, 9, 8430720, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 8430720 reached - Self: Start timed action list id 1841901'), -- waypoint_script.id = 476
    (26217, 0, 2, 0, 40, 0, 100, 0, 2, 8430720, 0, 0, 80, 2621701, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8430720 reached - Self: Start timed action list id 2621701'); -- waypoint_script.id = 477

    DELETE FROM `smart_scripts` WHERE `entryorguid`=24250 AND `source_type`=0 AND `id` >= 12;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (24250, 0, 12, 0, 40, 0, 100, 0, 2, 7013520, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7013520 reached - Self: Start timed action list id 1841901'), -- waypoint_script.id = 476
    (24250, 0, 13, 0, 40, 0, 100, 0, 6, 7013520, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 7013520 reached - Self: Start timed action list id 1841901'), -- waypoint_script.id = 476
    (24250, 0, 14, 0, 40, 0, 100, 0, 2, 7013600, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7013600 reached - Self: Start timed action list id 1841901'), -- waypoint_script.id = 476
    (24250, 0, 15, 0, 40, 0, 100, 0, 6, 7013600, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 7013600 reached - Self: Start timed action list id 1841901'), -- waypoint_script.id = 476
    (24250, 0, 16, 0, 40, 0, 100, 0, 3, 7013680, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 7013680 reached - Self: Start timed action list id 1841901'), -- waypoint_script.id = 476
    (24250, 0, 17, 0, 40, 0, 100, 0, 6, 7013680, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 7013680 reached - Self: Start timed action list id 1841901'), -- waypoint_script.id = 476
    (24250, 0, 18, 0, 40, 0, 100, 0, 9, 7013680, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 7013680 reached - Self: Start timed action list id 1841901'); -- waypoint_script.id = 476

    DELETE FROM `smart_scripts` WHERE `entryorguid`=43384 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (43384, 0, 1, 0, 40, 0, 100, 0, 5, 24565840, 0, 0, 80, 1841901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 24565840 reached - Self: Start timed action list id 1841901'); -- waypoint_script.id = 476

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=27072;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=27072 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (27072, 0, 0, 0, 40, 0, 100, 0, 1, 9116720, 0, 0, 80, 2707200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 9116720 reached - Self: Start timed action list id 2707200'), -- waypoint_script.id = 478
    (27072, 0, 1, 0, 40, 0, 100, 0, 4, 9116720, 0, 0, 80, 2707201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 9116720 reached - Self: Start timed action list id 2707201'); -- waypoint_script.id = 479

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=27361;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=27361 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (27361, 0, 0, 0, 40, 0, 100, 0, 1, 10701040, 0, 0, 80, 2736100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 10701040 reached - Self: Start timed action list id 2736100'), -- waypoint_script.id = 480
    (27361, 0, 1, 0, 40, 0, 100, 0, 2, 10701040, 0, 0, 80, 2736101, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 10701040 reached - Self: Start timed action list id 2736101'); -- waypoint_script.id = 481

    DELETE FROM `smart_scripts` WHERE `entryorguid`=20512 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (20512, 0, 3, 0, 40, 0, 100, 0, 3, 5809760, 0, 0, 80, 2051200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 5809760 reached - Self: Start timed action list id 2051200'), -- waypoint_script.id = 491
    (20512, 0, 4, 0, 40, 0, 100, 0, 7, 5809760, 0, 0, 80, 2051200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 5809760 reached - Self: Start timed action list id 2051200'), -- waypoint_script.id = 491
    (20512, 0, 5, 0, 40, 0, 100, 0, 8, 5810720, 0, 0, 80, 2051200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 5810720 reached - Self: Start timed action list id 2051200'), -- waypoint_script.id = 491
    (20512, 0, 6, 0, 40, 0, 100, 0, 4, 5810800, 0, 0, 80, 2051200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 5810800 reached - Self: Start timed action list id 2051200'), -- waypoint_script.id = 491
    (20512, 0, 7, 0, 40, 0, 100, 0, 13, 5810800, 0, 0, 80, 2051200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 5810800 reached - Self: Start timed action list id 2051200'), -- waypoint_script.id = 491
    (20512, 0, 8, 0, 40, 0, 100, 0, 28, 5810800, 0, 0, 80, 2051200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 28 of path 5810800 reached - Self: Start timed action list id 2051200'), -- waypoint_script.id = 491
    (20512, 0, 9, 0, 40, 0, 100, 0, 7, 5809200, 0, 0, 80, 2051201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 5809200 reached - Self: Start timed action list id 2051201'), -- waypoint_script.id = 492
    (20512, 0, 10, 0, 40, 0, 100, 0, 13, 5809200, 0, 0, 80, 2051201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 5809200 reached - Self: Start timed action list id 2051201'), -- waypoint_script.id = 492
    (20512, 0, 11, 0, 40, 0, 100, 0, 15, 5810720, 0, 0, 80, 2051201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 5810720 reached - Self: Start timed action list id 2051201'), -- waypoint_script.id = 492
    (20512, 0, 12, 0, 40, 0, 100, 0, 19, 5810720, 0, 0, 80, 2051201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 19 of path 5810720 reached - Self: Start timed action list id 2051201'); -- waypoint_script.id = 492

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=45210;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=45210 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (45210, 0, 0, 0, 40, 0, 100, 0, 1, 20031440, 0, 0, 80, 2051200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 20031440 reached - Self: Start timed action list id 2051200'), -- waypoint_script.id = 491
    (45210, 0, 1, 0, 40, 0, 100, 0, 4, 20031600, 0, 0, 80, 2051200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 20031600 reached - Self: Start timed action list id 2051200'), -- waypoint_script.id = 491
    (45210, 0, 2, 0, 40, 0, 100, 0, 6, 20031600, 0, 0, 80, 2051201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 20031600 reached - Self: Start timed action list id 2051201'); -- waypoint_script.id = 492

    DELETE FROM `smart_scripts` WHERE `entryorguid`=21065 AND `source_type`=0 AND `id` >= 5;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (21065, 0, 5, 0, 40, 0, 100, 0, 4, 5923360, 0, 0, 80, 2106500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 5923360 reached - Self: Start timed action list id 2106500'), -- waypoint_script.id = 493
    (21065, 0, 6, 0, 40, 0, 100, 0, 18, 5923360, 0, 0, 80, 2106500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 5923360 reached - Self: Start timed action list id 2106500'), -- waypoint_script.id = 493
    (21065, 0, 7, 0, 40, 0, 100, 0, 24, 5923360, 0, 0, 80, 2106501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 24 of path 5923360 reached - Self: Start timed action list id 2106501'), -- waypoint_script.id = 494
    (21065, 0, 8, 0, 40, 0, 100, 0, 8, 5923760, 0, 0, 80, 2106501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 5923760 reached - Self: Start timed action list id 2106501'), -- waypoint_script.id = 494
    (21065, 0, 9, 0, 40, 0, 100, 0, 14, 5923760, 0, 0, 80, 2106501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 5923760 reached - Self: Start timed action list id 2106501'), -- waypoint_script.id = 494
    (21065, 0, 10, 0, 40, 0, 100, 0, 21, 5923760, 0, 0, 80, 2106501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 21 of path 5923760 reached - Self: Start timed action list id 2106501'); -- waypoint_script.id = 494

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18559 AND `source_type`=0 AND `id` >= 6;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18559, 0, 6, 0, 40, 0, 100, 0, 2, 8360080, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8360080 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18559, 0, 7, 0, 40, 0, 100, 0, 5, 8360240, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 8360240 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18559, 0, 8, 0, 40, 0, 100, 0, 3, 8362080, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8362080 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18559, 0, 9, 0, 40, 0, 100, 0, 12, 8362720, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 8362720 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18559, 0, 10, 0, 40, 0, 100, 0, 4, 8362800, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8362800 reached - Self: Start timed action list id 1855900'); -- waypoint_script.id = 495

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18556 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18556, 0, 1, 0, 40, 0, 100, 0, 7, 8371040, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 8371040 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18556, 0, 2, 0, 40, 0, 100, 0, 6, 8376400, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8376400 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18556, 0, 3, 0, 40, 0, 100, 0, 4, 8376480, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8376480 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18556, 0, 4, 0, 40, 0, 100, 0, 7, 8380960, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 8380960 reached - Self: Start timed action list id 1855900'); -- waypoint_script.id = 495

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18557 AND `source_type`=0 AND `id` >= 4;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18557, 0, 4, 0, 40, 0, 100, 0, 8, 8381040, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8381040 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18557, 0, 5, 0, 40, 0, 100, 0, 6, 8381120, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8381120 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18557, 0, 6, 0, 40, 0, 100, 0, 2, 8381680, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8381680 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18557, 0, 7, 0, 40, 0, 100, 0, 8, 8381920, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8381920 reached - Self: Start timed action list id 1855900'); -- waypoint_script.id = 495

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18558 AND `source_type`=0 AND `id` >= 6;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18558, 0, 6, 0, 40, 0, 100, 0, 8, 8382000, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8382000 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18558, 0, 7, 0, 40, 0, 100, 0, 6, 8382320, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8382320 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18558, 0, 8, 0, 40, 0, 100, 0, 3, 8382400, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8382400 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18558, 0, 9, 0, 40, 0, 100, 0, 8, 8382560, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8382560 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18558, 0, 10, 0, 40, 0, 100, 0, 6, 8382640, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8382640 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18558, 0, 11, 0, 40, 0, 100, 0, 8, 8382720, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8382720 reached - Self: Start timed action list id 1855900'), -- waypoint_script.id = 495
    (18558, 0, 12, 0, 40, 0, 100, 0, 5, 8382800, 0, 0, 80, 1855900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 8382800 reached - Self: Start timed action list id 1855900'); -- waypoint_script.id = 495

    DELETE FROM `smart_scripts` WHERE `entryorguid`=19312 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (19312, 0, 2, 0, 40, 0, 100, 0, 2, 5511840, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 5511840 reached - Self: Play emote 1'), -- waypoint_script.id = 1023
    (19312, 0, 3, 0, 40, 0, 100, 0, 4, 5511840, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 5511840 reached - Self: Play emote 1'); -- waypoint_script.id = 1024

    DELETE FROM `smart_scripts` WHERE `entryorguid`=47310 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (47310, 0, 3, 0, 40, 0, 100, 0, 2, 28779840, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 28779840 reached - Self: Play emote 1'), -- waypoint_script.id = 1023
    (47310, 0, 4, 0, 40, 0, 100, 0, 5, 28779840, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28779840 reached - Self: Play emote 1'), -- waypoint_script.id = 1023
    (47310, 0, 5, 0, 40, 0, 100, 0, 7, 28779840, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 28779840 reached - Self: Play emote 1'), -- waypoint_script.id = 1023
    (47310, 0, 6, 0, 40, 0, 100, 0, 8, 28779840, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 28779840 reached - Self: Play emote 1'); -- waypoint_script.id = 1023

    DELETE FROM `smart_scripts` WHERE `entryorguid`=19995 AND `source_type`=0 AND `id` >= 7;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (19995, 0, 7, 0, 40, 0, 100, 0, 14, 5712400, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 5712400 reached - Self: Play emote 1'); -- waypoint_script.id = 1025

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=22396;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=22396 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (22396, 0, 0, 0, 40, 0, 100, 0, 5, 6298480, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 6298480 reached - Self: Play emote 1'); -- waypoint_script.id = 1026

    DELETE FROM `smart_scripts` WHERE `entryorguid`=5860 AND `source_type`=0 AND `id` >= 4;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (5860, 0, 4, 0, 40, 0, 100, 0, 1, 28752720, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 28752720 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (5860, 0, 5, 0, 40, 0, 100, 0, 2, 28752720, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 28752720 reached - Self: Play emote 0'); -- waypoint_script.id = 1167

    DELETE FROM `smart_scripts` WHERE `entryorguid`=5861 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (5861, 0, 3, 0, 40, 0, 100, 0, 1, 28755440, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 28755440 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (5861, 0, 4, 0, 40, 0, 100, 0, 2, 28755440, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 28755440 reached - Self: Play emote 0'); -- waypoint_script.id = 1167

    DELETE FROM `smart_scripts` WHERE `entryorguid`=5862 AND `source_type`=0 AND `id` >= 5;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (5862, 0, 5, 0, 40, 0, 100, 0, 1, 28758160, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 28758160 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (5862, 0, 6, 0, 40, 0, 100, 0, 2, 28758160, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 28758160 reached - Self: Play emote 0'); -- waypoint_script.id = 1167

    DELETE FROM `smart_scripts` WHERE `entryorguid`=8402 AND `source_type`=0 AND `id` >= 6;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (8402, 0, 6, 0, 40, 0, 100, 0, 5, 28762640, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28762640 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (8402, 0, 7, 0, 40, 0, 100, 0, 5, 28762720, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28762720 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (8402, 0, 8, 0, 40, 0, 100, 0, 5, 28762800, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28762800 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (8402, 0, 9, 0, 40, 0, 100, 0, 5, 28762880, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28762880 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (8402, 0, 10, 0, 40, 0, 100, 0, 5, 28762960, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28762960 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (8402, 0, 11, 0, 40, 0, 100, 0, 5, 28763040, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28763040 reached - Self: Play emote 69'), -- waypoint_script.id = 1027
    (8402, 0, 12, 0, 40, 0, 100, 0, 3, 28762640, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 28762640 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 13, 0, 40, 0, 100, 0, 6, 28762640, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 28762640 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 14, 0, 40, 0, 100, 0, 3, 28762720, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 28762720 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 15, 0, 40, 0, 100, 0, 6, 28762720, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 28762720 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 16, 0, 40, 0, 100, 0, 3, 28762800, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 28762800 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 17, 0, 40, 0, 100, 0, 6, 28762800, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 28762800 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 18, 0, 40, 0, 100, 0, 3, 28762880, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 28762880 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 19, 0, 40, 0, 100, 0, 6, 28762880, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 28762880 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 20, 0, 40, 0, 100, 0, 3, 28762960, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 28762960 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 21, 0, 40, 0, 100, 0, 6, 28762960, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 28762960 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 22, 0, 40, 0, 100, 0, 3, 28763040, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 28763040 reached - Self: Play emote 0'), -- waypoint_script.id = 1167
    (8402, 0, 23, 0, 40, 0, 100, 0, 6, 28763040, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 28763040 reached - Self: Play emote 0'); -- waypoint_script.id = 1167

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28706;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28706 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28706, 0, 0, 0, 40, 0, 100, 0, 3, 7922320, 0, 0, 11, 746, 0, 0, 0, 0, 0, 19, 32652, 1.0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 7922320 reached - Self: Cast spell 746 on Closest alive creature 32652 in 1.0 yards'), -- waypoint_script.id = 1038
    (28706, 0, 1, 0, 40, 0, 100, 0, 7, 7922320, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 7922320 reached - Self: Play emote 1'); -- waypoint_script.id = 1039

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=29506;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=29506 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (29506, 0, 0, 0, 40, 0, 100, 0, 2, 8165680, 0, 0, 5, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8165680 reached - Self: Play emote 233'), -- waypoint_script.id = 1040
    (29506, 0, 1, 0, 40, 0, 100, 0, 3, 8165680, 0, 0, 5, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8165680 reached - Self: Play emote 233'), -- waypoint_script.id = 1041
    (29506, 0, 2, 0, 40, 0, 100, 0, 4, 8165680, 0, 0, 5, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8165680 reached - Self: Play emote 233'), -- waypoint_script.id = 1042
    (29506, 0, 3, 0, 40, 0, 100, 0, 5, 8165680, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 8165680 reached - Self: Play emote 69'), -- waypoint_script.id = 1043
    (29506, 0, 4, 0, 40, 0, 100, 0, 6, 8165680, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8165680 reached - Self: Play emote 69'), -- waypoint_script.id = 1044
    (29506, 0, 5, 0, 40, 0, 100, 0, 7, 8165680, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 8165680 reached - Self: Play emote 69'); -- waypoint_script.id = 1045

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=32403;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=32403 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (32403, 0, 0, 0, 40, 0, 100, 0, 14, 8778800, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 8778800 reached - Self: Play emote 69'); -- waypoint_script.id = 1065

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=25271;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=25271 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (25271, 0, 0, 0, 40, 0, 100, 0, 3, 9059680, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 9059680 reached - Self: Play emote 69'), -- waypoint_script.id = 1070
    (25271, 0, 1, 0, 40, 0, 100, 0, 7, 9059680, 0, 0, 5, 381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 9059680 reached - Self: Play emote 381'), -- waypoint_script.id = 1071
    (25271, 0, 2, 0, 40, 0, 100, 0, 13, 9059680, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 9059680 reached - Self: Play emote 69'), -- waypoint_script.id = 1072
    (25271, 0, 3, 0, 40, 0, 100, 0, 11, 9060080, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 9060080 reached - Self: Play emote 69'), -- waypoint_script.id = 1073
    (25271, 0, 4, 0, 40, 0, 100, 0, 22, 9060080, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 22 of path 9060080 reached - Self: Play emote 69'), -- waypoint_script.id = 1074
    (25271, 0, 5, 0, 40, 0, 100, 0, 13, 9060160, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 9060160 reached - Self: Play emote 69'), -- waypoint_script.id = 1075
    (25271, 0, 6, 0, 40, 0, 100, 0, 26, 9060160, 0, 0, 5, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 26 of path 9060160 reached - Self: Play emote 69'); -- waypoint_script.id = 1076

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=29640;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=29640 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (29640, 0, 0, 0, 40, 0, 100, 0, 3, 9182480, 0, 0, 11, 746, 0, 0, 0, 0, 0, 19, 32651, 1.0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 9182480 reached - Self: Cast spell 746 on Closest alive creature 32651 in 1.0 yards'), -- waypoint_script.id = 1077
    (29640, 0, 1, 0, 40, 0, 100, 0, 4, 9182480, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 9182480 reached - Self: Play emote 16'), -- waypoint_script.id = 1078
    (29640, 0, 2, 0, 40, 0, 100, 0, 8, 9182480, 0, 0, 11, 746, 0, 0, 0, 0, 0, 19, 32650, 1.0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 9182480 reached - Self: Cast spell 746 on Closest alive creature 32650 in 1.0 yards'); -- waypoint_script.id = 1079

    DELETE FROM `smart_scripts` WHERE `entryorguid`=24400 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (24400, 0, 1, 0, 40, 0, 100, 0, 4, 8252880, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8252880 reached - Self: Play emote 16'), -- waypoint_script.id = 1078
    (24400, 0, 2, 0, 40, 0, 100, 0, 36, 8253600, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 36 of path 8253600 reached - Self: Play emote 16'), -- waypoint_script.id = 1078
    (24400, 0, 3, 0, 40, 0, 100, 0, 4, 8905200, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8905200 reached - Self: Play emote 16'), -- waypoint_script.id = 1078
    (24400, 0, 4, 0, 40, 0, 100, 0, 11, 8905200, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 8905200 reached - Self: Play emote 16'), -- waypoint_script.id = 1078
    (24400, 0, 5, 0, 40, 0, 100, 0, 3, 8905520, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8905520 reached - Self: Play emote 16'), -- waypoint_script.id = 1078
    (24400, 0, 6, 0, 40, 0, 100, 0, 4, 8905520, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8905520 reached - Self: Play emote 16'), -- waypoint_script.id = 1078
    (24400, 0, 7, 0, 40, 0, 100, 0, 14, 8905520, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 8905520 reached - Self: Play emote 16'); -- waypoint_script.id = 1078

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=27566;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=27566 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (27566, 0, 0, 0, 40, 0, 100, 0, 1, 8990320, 0, 0, 80, 2756600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 8990320 reached - Self: Start timed action list id 2756600'), -- waypoint_script.id = 1114
    (27566, 0, 1, 0, 40, 0, 100, 0, 2, 8990320, 0, 0, 80, 2756601, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8990320 reached - Self: Start timed action list id 2756601'), -- waypoint_script.id = 1115
    (27566, 0, 2, 0, 40, 0, 100, 0, 8, 8990720, 0, 0, 80, 2756602, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8990720 reached - Self: Start timed action list id 2756602'), -- waypoint_script.id = 1116
    (27566, 0, 3, 0, 40, 0, 100, 0, 16, 8990720, 0, 0, 80, 2756602, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 16 of path 8990720 reached - Self: Start timed action list id 2756602'); -- waypoint_script.id = 1116

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=25235;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=25235 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (25235, 0, 0, 0, 40, 0, 100, 0, 2, 8779120, 0, 0, 80, 2523500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8779120 reached - Self: Start timed action list id 2523500'), -- waypoint_script.id = 1120
    (25235, 0, 1, 0, 40, 0, 100, 0, 4, 8779120, 0, 0, 80, 2523501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8779120 reached - Self: Start timed action list id 2523501'), -- waypoint_script.id = 1121
    (25235, 0, 2, 0, 40, 0, 100, 0, 7, 8779120, 0, 0, 80, 2523501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 8779120 reached - Self: Start timed action list id 2523501'), -- waypoint_script.id = 1121
    (25235, 0, 3, 0, 40, 0, 100, 0, 10, 8779120, 0, 0, 80, 2523502, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 8779120 reached - Self: Start timed action list id 2523502'); -- waypoint_script.id = 1122

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=27393;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=27393 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (27393, 0, 0, 0, 40, 0, 100, 0, 2, 7662480, 0, 0, 80, 2739300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7662480 reached - Self: Start timed action list id 2739300'), -- waypoint_script.id = 1123
    (27393, 0, 1, 0, 40, 0, 100, 0, 5, 7662480, 0, 0, 80, 2739300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 7662480 reached - Self: Start timed action list id 2739300'), -- waypoint_script.id = 1123
    (27393, 0, 2, 0, 40, 0, 100, 0, 6, 7662480, 0, 0, 80, 2739301, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 7662480 reached - Self: Start timed action list id 2739301'); -- waypoint_script.id = 1124

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=23550;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=23550 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (23550, 0, 0, 0, 40, 0, 100, 0, 8, 7052160, 0, 0, 80, 2355000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 7052160 reached - Self: Start timed action list id 2355000'), -- waypoint_script.id = 1125
    (23550, 0, 1, 0, 40, 0, 100, 0, 8, 7052240, 0, 0, 80, 2355000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 7052240 reached - Self: Start timed action list id 2355000'), -- waypoint_script.id = 1125
    (23550, 0, 2, 0, 40, 0, 100, 0, 2, 16185360, 0, 0, 80, 2355000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 16185360 reached - Self: Start timed action list id 2355000'), -- waypoint_script.id = 1125
    (23550, 0, 3, 0, 40, 0, 100, 0, 3, 7052160, 0, 0, 80, 2355001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 7052160 reached - Self: Start timed action list id 2355001'), -- waypoint_script.id = 1126
    (23550, 0, 4, 0, 40, 0, 100, 0, 13, 7052240, 0, 0, 80, 2355001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 7052240 reached - Self: Start timed action list id 2355001'), -- waypoint_script.id = 1126
    (23550, 0, 5, 0, 40, 0, 100, 0, 5, 16185360, 0, 0, 80, 2355001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 16185360 reached - Self: Start timed action list id 2355001'); -- waypoint_script.id = 1126

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=23552;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=23552 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (23552, 0, 0, 0, 40, 0, 100, 0, 4, 9633440, 0, 0, 80, 2355000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 9633440 reached - Self: Start timed action list id 2355000'), -- waypoint_script.id = 1125
    (23552, 0, 1, 0, 40, 0, 100, 0, 10, 9633440, 0, 0, 80, 2355001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 9633440 reached - Self: Start timed action list id 2355001'); -- waypoint_script.id = 1126

    DELETE FROM `smart_scripts` WHERE `entryorguid`=24040 AND `source_type`=0 AND `id` >= 5;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (24040, 0, 5, 0, 40, 0, 100, 0, 2, 7051760, 0, 0, 80, 2404000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7051760 reached - Self: Start timed action list id 2404000'), -- waypoint_script.id = 1127
    (24040, 0, 6, 0, 40, 0, 100, 0, 4, 7051760, 0, 0, 80, 2404001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 7051760 reached - Self: Start timed action list id 2404001'), -- waypoint_script.id = 1128
    (24040, 0, 7, 0, 40, 0, 100, 0, 5, 7051760, 0, 0, 80, 2404002, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 7051760 reached - Self: Start timed action list id 2404002'); -- waypoint_script.id = 1129

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=29432;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=29432 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (29432, 0, 0, 0, 40, 0, 100, 0, 3, 1630632, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 1630632 reached - Self: Play emote 1'); -- waypoint_script.id = 1135

    DELETE FROM `smart_scripts` WHERE `entryorguid`=21501 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (21501, 0, 3, 0, 40, 0, 100, 0, 3, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 4, 0, 40, 0, 100, 0, 6, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 5, 0, 40, 0, 100, 0, 10, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 6, 0, 40, 0, 100, 0, 13, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 7, 0, 40, 0, 100, 0, 14, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 8, 0, 40, 0, 100, 0, 16, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 16 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 9, 0, 40, 0, 100, 0, 19, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 19 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 10, 0, 40, 0, 100, 0, 22, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 22 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 11, 0, 40, 0, 100, 0, 28, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 28 of path 6759280 reached - Self: Play emote 1'), -- waypoint_script.id = 1135
    (21501, 0, 12, 0, 40, 0, 100, 0, 31, 6759280, 0, 0, 5, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 31 of path 6759280 reached - Self: Play emote 1'); -- waypoint_script.id = 1135

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=21403;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=21403 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (21403, 0, 0, 0, 40, 0, 100, 0, 1, 5990240, 0, 0, 11, 36804, 0, 0, 0, 0, 0, 19, 21404, 30.0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5990240 reached - Self: Cast spell 36804 on Closest alive creature 21404 in 30.0 yards'), -- waypoint_script.id = 1136
    (21403, 0, 1, 0, 40, 0, 100, 0, 1, 5990320, 0, 0, 11, 36804, 0, 0, 0, 0, 0, 19, 21404, 30.0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5990320 reached - Self: Cast spell 36804 on Closest alive creature 21404 in 30.0 yards'), -- waypoint_script.id = 1136
    (21403, 0, 2, 0, 40, 0, 100, 0, 1, 5990400, 0, 0, 11, 36804, 0, 0, 0, 0, 0, 19, 21404, 30.0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5990400 reached - Self: Cast spell 36804 on Closest alive creature 21404 in 30.0 yards'), -- waypoint_script.id = 1136
    (21403, 0, 3, 0, 40, 0, 100, 0, 1, 5990480, 0, 0, 11, 36804, 0, 0, 0, 0, 0, 19, 21404, 30.0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5990480 reached - Self: Cast spell 36804 on Closest alive creature 21404 in 30.0 yards'); -- waypoint_script.id = 1136

    DELETE FROM `smart_scripts` WHERE `entryorguid`=21500 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (21500, 0, 3, 0, 40, 0, 100, 0, 3, 6032560, 0, 0, 80, 2150000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 6032560 reached - Self: Start timed action list id 2150000'), -- waypoint_script.id = 1137
    (21500, 0, 4, 0, 40, 0, 100, 0, 6, 6032560, 0, 0, 80, 2150000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 6032560 reached - Self: Start timed action list id 2150000'), -- waypoint_script.id = 1137
    (21500, 0, 5, 0, 40, 0, 100, 0, 9, 6032560, 0, 0, 80, 2150000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 6032560 reached - Self: Start timed action list id 2150000'), -- waypoint_script.id = 1137
    (21500, 0, 6, 0, 40, 0, 100, 0, 10, 6032560, 0, 0, 80, 2150001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 6032560 reached - Self: Start timed action list id 2150001'); -- waypoint_script.id = 1138

    DELETE FROM `smart_scripts` WHERE `entryorguid`=26417 AND `source_type`=0 AND `id` >= 5;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (26417, 0, 5, 0, 40, 0, 100, 0, 1, 8040800, 0, 0, 80, 2641700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 8040800 reached - Self: Start timed action list id 2641700'), -- waypoint_script.id = 1139
    (26417, 0, 6, 0, 40, 0, 100, 0, 3, 8040880, 0, 0, 80, 2641701, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8040880 reached - Self: Start timed action list id 2641701'), -- waypoint_script.id = 1140
    (26417, 0, 7, 0, 40, 0, 100, 0, 6, 8040960, 0, 0, 80, 2641702, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8040960 reached - Self: Start timed action list id 2641702'), -- waypoint_script.id = 1141
    (26417, 0, 8, 0, 40, 0, 100, 0, 8, 8041040, 0, 0, 80, 2641703, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8041040 reached - Self: Start timed action list id 2641703'), -- waypoint_script.id = 1142
    (26417, 0, 9, 0, 40, 0, 100, 0, 13, 8041120, 0, 0, 80, 2641704, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 8041120 reached - Self: Start timed action list id 2641704'), -- waypoint_script.id = 1143
    (26417, 0, 10, 0, 40, 0, 100, 0, 8, 8041520, 0, 0, 80, 2641705, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8041520 reached - Self: Start timed action list id 2641705'), -- waypoint_script.id = 1144
    (26417, 0, 11, 0, 40, 0, 100, 0, 4, 8041840, 0, 0, 80, 2641706, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8041840 reached - Self: Start timed action list id 2641706'), -- waypoint_script.id = 1145
    (26417, 0, 12, 0, 40, 0, 100, 0, 8, 8042160, 0, 0, 80, 2641707, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8042160 reached - Self: Start timed action list id 2641707'), -- waypoint_script.id = 1146
    (26417, 0, 13, 0, 40, 0, 100, 0, 8, 8041200, 0, 0, 80, 2641708, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8041200 reached - Self: Start timed action list id 2641708'), -- waypoint_script.id = 1147
    (26417, 0, 14, 0, 40, 0, 100, 0, 2, 8042080, 0, 0, 80, 2641709, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8042080 reached - Self: Start timed action list id 2641709'), -- waypoint_script.id = 1148
    (26417, 0, 15, 0, 40, 0, 100, 0, 6, 8041600, 0, 0, 80, 2641710, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8041600 reached - Self: Start timed action list id 2641710'), -- waypoint_script.id = 1149
    (26417, 0, 16, 0, 40, 0, 100, 0, 6, 8042240, 0, 0, 80, 2641711, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8042240 reached - Self: Start timed action list id 2641711'), -- waypoint_script.id = 1150
    (26417, 0, 17, 0, 40, 0, 100, 0, 3, 8041760, 0, 0, 80, 2641712, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8041760 reached - Self: Start timed action list id 2641712'), -- waypoint_script.id = 1151
    (26417, 0, 18, 0, 40, 0, 100, 0, 7, 8041360, 0, 0, 80, 2641713, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 8041360 reached - Self: Start timed action list id 2641713'), -- waypoint_script.id = 1152
    (26417, 0, 19, 0, 40, 0, 100, 0, 8, 8041920, 0, 0, 80, 2641714, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 8041920 reached - Self: Start timed action list id 2641714'), -- waypoint_script.id = 1153
    (26417, 0, 20, 0, 40, 0, 100, 0, 7, 8041280, 0, 0, 80, 2641715, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 8041280 reached - Self: Start timed action list id 2641715'), -- waypoint_script.id = 1154
    (26417, 0, 21, 0, 40, 0, 100, 0, 7, 8041440, 0, 0, 80, 2641716, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 8041440 reached - Self: Start timed action list id 2641716'), -- waypoint_script.id = 1155
    (26417, 0, 22, 0, 40, 0, 100, 0, 6, 8039440, 0, 0, 80, 2641717, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 8039440 reached - Self: Start timed action list id 2641717'), -- waypoint_script.id = 1156
    (26417, 0, 23, 0, 40, 0, 100, 0, 4, 8042400, 0, 0, 80, 2641718, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8042400 reached - Self: Start timed action list id 2641718'), -- waypoint_script.id = 1157
    (26417, 0, 24, 0, 40, 0, 100, 0, 5, 8039040, 0, 0, 80, 2641719, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 8039040 reached - Self: Start timed action list id 2641719'); -- waypoint_script.id = 1158

    DELETE FROM `smart_scripts` WHERE `entryorguid`=23844 AND `source_type`=0 AND `id` >= 6;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (23844, 0, 6, 0, 40, 0, 100, 0, 12, 7936640, 0, 0, 5, 66, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 7936640 reached - Self: Play emote 66'); -- waypoint_script.id = 1159

    DELETE FROM `smart_scripts` WHERE `entryorguid`=24812 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (24812, 0, 3, 0, 40, 0, 100, 0, 65, 9454160, 0, 0, 80, 2481200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 65 of path 9454160 reached - Self: Start timed action list id 2481200'), -- waypoint_script.id = 1160
    (24812, 0, 4, 0, 40, 0, 100, 0, 1, 9455280, 0, 0, 80, 2481200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 9455280 reached - Self: Start timed action list id 2481200'), -- waypoint_script.id = 1160
    (24812, 0, 5, 0, 40, 0, 100, 0, 17, 9455280, 0, 0, 80, 2481200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 17 of path 9455280 reached - Self: Start timed action list id 2481200'), -- waypoint_script.id = 1160
    (24812, 0, 6, 0, 40, 0, 100, 0, 47, 9455280, 0, 0, 80, 2481200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 47 of path 9455280 reached - Self: Start timed action list id 2481200'), -- waypoint_script.id = 1160
    (24812, 0, 7, 0, 40, 0, 100, 0, 1, 9454160, 0, 0, 11, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 9454160 reached - Self: Cast spell 44385 on Self'), -- waypoint_script.id = 1161
    (24812, 0, 8, 0, 40, 0, 100, 0, 66, 9454160, 0, 0, 11, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 66 of path 9454160 reached - Self: Cast spell 44385 on Self'), -- waypoint_script.id = 1161
    (24812, 0, 9, 0, 40, 0, 100, 0, 141, 9454160, 0, 0, 11, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 141 of path 9454160 reached - Self: Cast spell 44385 on Self'), -- waypoint_script.id = 1161
    (24812, 0, 10, 0, 40, 0, 100, 0, 2, 9455280, 0, 0, 11, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 9455280 reached - Self: Cast spell 44385 on Self'), -- waypoint_script.id = 1161
    (24812, 0, 11, 0, 40, 0, 100, 0, 18, 9455280, 0, 0, 11, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 9455280 reached - Self: Cast spell 44385 on Self'), -- waypoint_script.id = 1161
    (24812, 0, 12, 0, 40, 0, 100, 0, 48, 9455280, 0, 0, 11, 44385, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 48 of path 9455280 reached - Self: Cast spell 44385 on Self'), -- waypoint_script.id = 1161
    (24812, 0, 13, 0, 40, 0, 100, 0, 140, 9454160, 0, 0, 80, 2481201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 140 of path 9454160 reached - Self: Start timed action list id 2481201'), -- waypoint_script.id = 1162
    (24812, 0, 14, 0, 40, 0, 100, 0, 155, 9454160, 0, 0, 80, 2481202, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 155 of path 9454160 reached - Self: Start timed action list id 2481202'); -- waypoint_script.id = 1163

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=30436;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=30436 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (30436, 0, 0, 0, 40, 0, 100, 0, 1, 9959760, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 9959760 reached - Self: Set emote state to 69'), -- waypoint_script.id = 1166
    (30436, 0, 1, 0, 40, 0, 100, 0, 2, 9959760, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 9959760 reached - Self: Play emote 0'); -- waypoint_script.id = 1167

    DELETE FROM `smart_scripts` WHERE `entryorguid`=48215 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (48215, 0, 1, 0, 40, 0, 100, 0, 12, 28902000, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 28902000 reached - Self: Set emote state to 69'); -- waypoint_script.id = 1166

    DELETE FROM `smart_scripts` WHERE `entryorguid`=48235 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (48235, 0, 2, 0, 40, 0, 100, 0, 2, 28902240, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 28902240 reached - Self: Set emote state to 69'), -- waypoint_script.id = 1166
    (48235, 0, 3, 0, 40, 0, 100, 0, 5, 28902240, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 28902240 reached - Self: Set emote state to 69'); -- waypoint_script.id = 1166

    DELETE FROM `smart_scripts` WHERE `entryorguid`=48551 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (48551, 0, 1, 0, 40, 0, 100, 0, 1, 28917440, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 28917440 reached - Self: Set emote state to 69'); -- waypoint_script.id = 1166

    DELETE FROM `smart_scripts` WHERE `entryorguid`=48555 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (48555, 0, 1, 0, 40, 0, 100, 0, 4, 28917680, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 28917680 reached - Self: Set emote state to 69'); -- waypoint_script.id = 1166

    DELETE FROM `smart_scripts` WHERE `entryorguid`=48581 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (48581, 0, 1, 0, 40, 0, 100, 0, 13, 28919200, 0, 0, 17, 69, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 28919200 reached - Self: Set emote state to 69'); -- waypoint_script.id = 1166

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28832;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28832 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28832, 0, 0, 0, 40, 0, 100, 0, 2, 8876160, 0, 0, 80, 2883200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8876160 reached - Self: Start timed action list id 2883200'), -- waypoint_script.id = 1168
    (28832, 0, 1, 0, 40, 0, 100, 0, 3, 8876160, 0, 0, 80, 2883201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8876160 reached - Self: Start timed action list id 2883201'); -- waypoint_script.id = 1169

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28828;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28828 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28828, 0, 0, 0, 40, 0, 100, 0, 2, 8843120, 0, 0, 80, 2882800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8843120 reached - Self: Start timed action list id 2882800'); -- waypoint_script.id = 1170

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28829;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28829 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28829, 0, 0, 0, 40, 0, 100, 0, 1, 8846720, 0, 0, 80, 2882900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 8846720 reached - Self: Start timed action list id 2882900'), -- waypoint_script.id = 1171
    (28829, 0, 1, 0, 40, 0, 100, 0, 2, 8846720, 0, 0, 80, 2882901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8846720 reached - Self: Start timed action list id 2882901'); -- waypoint_script.id = 1172

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28830;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28830 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28830, 0, 0, 0, 40, 0, 100, 0, 9, 8852080, 0, 0, 80, 2883000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 8852080 reached - Self: Start timed action list id 2883000'); -- waypoint_script.id = 1175

    DELETE FROM `smart_scripts` WHERE `entryorguid`=17703 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (17703, 0, 1, 0, 40, 0, 100, 0, 17, 5076000, 0, 0, 5, 133, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 17 of path 5076000 reached - Self: Play emote 133'); -- waypoint_script.id = 1176

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=32631;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=32631 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (32631, 0, 0, 0, 40, 0, 100, 0, 17, 8556800, 0, 0, 80, 3263100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 17 of path 8556800 reached - Self: Start timed action list id 3263100'), -- waypoint_script.id = 1177
    (32631, 0, 1, 0, 40, 0, 100, 0, 21, 8556800, 0, 0, 80, 3263101, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 21 of path 8556800 reached - Self: Start timed action list id 3263101'), -- waypoint_script.id = 1178
    (32631, 0, 2, 0, 40, 0, 100, 0, 23, 8556800, 0, 0, 80, 3263102, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 8556800 reached - Self: Start timed action list id 3263102'); -- waypoint_script.id = 1179

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=32737;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=32737 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (32737, 0, 0, 0, 40, 0, 100, 0, 1, 16282000, 0, 0, 80, 3273700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 16282000 reached - Self: Start timed action list id 3273700'), -- waypoint_script.id = 1180
    (32737, 0, 1, 0, 40, 0, 100, 0, 2, 16282000, 0, 0, 80, 3273701, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 16282000 reached - Self: Start timed action list id 3273701'); -- waypoint_script.id = 1181

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=37780;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=37780 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (37780, 0, 0, 0, 40, 0, 100, 0, 5, 10691920, 0, 0, 80, 3778000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 10691920 reached - Self: Start timed action list id 3778000'), -- waypoint_script.id = 1185
    (37780, 0, 1, 0, 40, 0, 100, 0, 15, 10691920, 0, 0, 80, 3778001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 10691920 reached - Self: Start timed action list id 3778001'), -- waypoint_script.id = 1186
    (37780, 0, 2, 0, 40, 0, 100, 0, 18, 10691920, 0, 0, 80, 3778002, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 10691920 reached - Self: Start timed action list id 3778002'); -- waypoint_script.id = 1187

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18688 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18688, 0, 1, 0, 40, 0, 100, 0, 12, 1147120, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 1147120 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 2, 0, 40, 0, 100, 0, 13, 1147200, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 1147200 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 3, 0, 40, 0, 100, 0, 12, 1147360, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 1147360 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 4, 0, 40, 0, 100, 0, 18, 1198160, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 1198160 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 5, 0, 40, 0, 100, 0, 17, 1198240, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 17 of path 1198240 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 6, 0, 40, 0, 100, 0, 21, 1848880, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 21 of path 1848880 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 7, 0, 40, 0, 100, 0, 23, 1973600, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 1973600 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 8, 0, 40, 0, 100, 0, 15, 1980880, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 1980880 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 9, 0, 40, 0, 100, 0, 14, 1983520, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 1983520 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 10, 0, 40, 0, 100, 0, 9, 2008000, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 2008000 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 11, 0, 40, 0, 100, 0, 18, 2124720, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 2124720 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 12, 0, 40, 0, 100, 0, 6, 2125120, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 2125120 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 13, 0, 40, 0, 100, 0, 7, 2544560, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 2544560 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 14, 0, 40, 0, 100, 0, 12, 2546640, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 2546640 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 15, 0, 40, 0, 100, 0, 17, 2565760, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 17 of path 2565760 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 16, 0, 40, 0, 100, 0, 23, 3238000, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 3238000 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 17, 0, 40, 0, 100, 0, 27, 3238080, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 27 of path 3238080 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 18, 0, 40, 0, 100, 0, 23, 3616320, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 3616320 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 19, 0, 40, 0, 100, 0, 23, 3616320, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 3616320 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 20, 0, 40, 0, 100, 0, 23, 3616320, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 3616320 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 21, 0, 40, 0, 100, 0, 23, 3616320, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 3616320 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 22, 0, 40, 0, 100, 0, 23, 3616320, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 3616320 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (18688, 0, 23, 0, 40, 0, 100, 0, 23, 3616320, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 3616320 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    DELETE FROM `smart_scripts` WHERE `entryorguid`=29375 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (29375, 0, 2, 0, 40, 0, 100, 0, 16, 5921440, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 16 of path 5921440 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (29375, 0, 3, 0, 40, 0, 100, 0, 1, 5921360, 0, 0, 80, 2937500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 5921360 reached - Self: Start timed action list id 2937500'), -- waypoint_script.id = 11393600
    (29375, 0, 4, 0, 40, 0, 100, 0, 1, 9114880, 0, 0, 80, 2937500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 9114880 reached - Self: Start timed action list id 2937500'), -- waypoint_script.id = 11393600
    (29375, 0, 5, 0, 40, 0, 100, 0, 2, 9114960, 0, 0, 80, 2937500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 9114960 reached - Self: Start timed action list id 2937500'); -- waypoint_script.id = 11393600

    DELETE FROM `smart_scripts` WHERE `entryorguid`=28897 AND `source_type`=0 AND `id` >= 6;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28897, 0, 6, 0, 40, 0, 100, 0, 13, 6631920, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 6631920 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28897, 0, 7, 0, 40, 0, 100, 0, 12, 6633200, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 6633200 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28897, 0, 8, 0, 40, 0, 100, 0, 11, 6753440, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 6753440 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28897, 0, 9, 0, 40, 0, 100, 0, 11, 6753840, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 6753840 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28897, 0, 10, 0, 40, 0, 100, 0, 9, 6754560, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 6754560 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28897, 0, 11, 0, 40, 0, 100, 0, 9, 6754880, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 6754880 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28897, 0, 12, 0, 40, 0, 100, 0, 8, 6754960, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 6754960 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28897, 0, 13, 0, 40, 0, 100, 0, 8, 6755120, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 6755120 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=25115;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=25115 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (25115, 0, 0, 0, 40, 0, 100, 0, 7, 7727440, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 7727440 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (25115, 0, 1, 0, 40, 0, 100, 0, 10, 7732560, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 7732560 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    DELETE FROM `smart_scripts` WHERE `entryorguid`=24938 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (24938, 0, 2, 0, 40, 0, 100, 0, 8, 7732480, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 7732480 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (24938, 0, 3, 0, 40, 0, 100, 0, 10, 7732640, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 7732640 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=32746;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=32746 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (32746, 0, 0, 0, 40, 0, 100, 0, 31, 9445120, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 31 of path 9445120 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    DELETE FROM `smart_scripts` WHERE `entryorguid`=38048 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (38048, 0, 0, 0, 40, 0, 100, 0, 11, 9833200, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 9833200 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (38048, 0, 1, 0, 40, 0, 100, 0, 14, 9899040, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 9899040 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    DELETE FROM `smart_scripts` WHERE `entryorguid`=38047 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (38047, 0, 0, 0, 40, 0, 100, 0, 13, 9836640, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 9836640 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (38047, 0, 1, 0, 40, 0, 100, 0, 12, 9837920, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 9837920 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (38047, 0, 2, 0, 40, 0, 100, 0, 13, 9838960, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 9838960 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28822;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28822 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28822, 0, 0, 0, 40, 0, 100, 0, 52, 10310800, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 52 of path 10310800 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 1, 0, 40, 0, 100, 0, 41, 10311120, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 41 of path 10311120 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 2, 0, 40, 0, 100, 0, 35, 10311440, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 35 of path 10311440 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 3, 0, 40, 0, 100, 0, 13, 10311520, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 10311520 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 4, 0, 40, 0, 100, 0, 15, 10311600, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 10311600 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 5, 0, 40, 0, 100, 0, 13, 10311840, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 10311840 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 6, 0, 40, 0, 100, 0, 32, 10311920, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 32 of path 10311920 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 7, 0, 40, 0, 100, 0, 48, 10312080, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 48 of path 10312080 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 8, 0, 40, 0, 100, 0, 8, 10312320, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 10312320 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28822, 0, 9, 0, 40, 0, 100, 0, 21, 10312400, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 21 of path 10312400 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28576;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28576 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28576, 0, 0, 0, 40, 0, 100, 0, 9, 10312800, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 10312800 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 1, 0, 40, 0, 100, 0, 8, 10313520, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 10313520 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 2, 0, 40, 0, 100, 0, 14, 10313840, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 10313840 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 3, 0, 40, 0, 100, 0, 6, 10313920, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 10313920 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 4, 0, 40, 0, 100, 0, 10, 10314000, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 10314000 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 5, 0, 40, 0, 100, 0, 8, 10314160, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 10314160 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 6, 0, 40, 0, 100, 0, 15, 10314720, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 10314720 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 7, 0, 40, 0, 100, 0, 13, 10314800, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 10314800 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 8, 0, 40, 0, 100, 0, 15, 10314880, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 10314880 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 9, 0, 40, 0, 100, 0, 6, 10315120, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 10315120 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 10, 0, 40, 0, 100, 0, 10, 10315680, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 10315680 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 11, 0, 40, 0, 100, 0, 13, 10315840, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 10315840 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 12, 0, 40, 0, 100, 0, 9, 10315920, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 10315920 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28576, 0, 13, 0, 40, 0, 100, 0, 20, 10316560, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 20 of path 10316560 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28577;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28577 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28577, 0, 0, 0, 40, 0, 100, 0, 10, 10317920, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 10317920 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28577, 0, 1, 0, 40, 0, 100, 0, 13, 10318800, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 10318800 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28577, 0, 2, 0, 40, 0, 100, 0, 9, 10318880, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 10318880 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28577, 0, 3, 0, 40, 0, 100, 0, 17, 10319040, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 17 of path 10319040 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28577, 0, 4, 0, 40, 0, 100, 0, 27, 10319200, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 27 of path 10319200 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28577, 0, 5, 0, 40, 0, 100, 0, 13, 10319280, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 10319280 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28577, 0, 6, 0, 40, 0, 100, 0, 13, 10319760, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 10319760 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28577, 0, 7, 0, 40, 0, 100, 0, 7, 10319840, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 10319840 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (28577, 0, 8, 0, 40, 0, 100, 0, 8, 10319920, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 10319920 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    DELETE FROM `smart_scripts` WHERE `entryorguid`=-129217 AND `source_type`=0 AND `id` >= 5;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (-129217, 0, 5, 0, 40, 0, 100, 0, 15, 10337360, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 10337360 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=29185;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=29185 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (29185, 0, 0, 0, 40, 0, 100, 0, 4, 10428960, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 10428960 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (29185, 0, 1, 0, 40, 0, 100, 0, 10, 10429040, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 10429040 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (29185, 0, 2, 0, 40, 0, 100, 0, 18, 10429840, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 10429840 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (29185, 0, 3, 0, 40, 0, 100, 0, 1, 10428960, 0, 0, 80, 2918500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 10428960 reached - Self: Start timed action list id 2918500'), -- waypoint_script.id = 13036300
    (29185, 0, 4, 0, 40, 0, 100, 0, 1, 10429040, 0, 0, 80, 2918500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 10429040 reached - Self: Start timed action list id 2918500'), -- waypoint_script.id = 13036300
    (29185, 0, 5, 0, 40, 0, 100, 0, 1, 10429840, 0, 0, 80, 2918500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 10429840 reached - Self: Start timed action list id 2918500'); -- waypoint_script.id = 13036300

    DELETE FROM `smart_scripts` WHERE `entryorguid`=29186 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (29186, 0, 2, 0, 40, 0, 100, 0, 18, 10430080, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 10430080 reached - Self: Start timed action list id 1868800'), -- waypoint_script.id = 1188
    (29186, 0, 3, 0, 40, 0, 100, 0, 26, 10430320, 0, 0, 80, 1868800, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 26 of path 10430320 reached - Self: Start timed action list id 1868800'); -- waypoint_script.id = 1188

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=37776;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=37776 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (37776, 0, 0, 0, 40, 0, 100, 0, 4, 8098880, 0, 0, 80, 3777600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 8098880 reached - Self: Start timed action list id 3777600'), -- waypoint_script.id = 1190
    (37776, 0, 1, 0, 40, 0, 100, 0, 13, 8098880, 0, 0, 80, 3777601, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 8098880 reached - Self: Start timed action list id 3777601'), -- waypoint_script.id = 1191
    (37776, 0, 2, 0, 40, 0, 100, 0, 16, 8098880, 0, 0, 80, 3777602, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 16 of path 8098880 reached - Self: Start timed action list id 3777602'); -- waypoint_script.id = 1192

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28600;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28600 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28600, 0, 0, 0, 40, 0, 100, 0, 1, 9068400, 0, 0, 80, 2860000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 9068400 reached - Self: Start timed action list id 2860000'), -- waypoint_script.id = 1193
    (28600, 0, 1, 0, 40, 0, 100, 0, 3, 9069120, 0, 0, 11, 52059, 0, 0, 0, 0, 0, 19, 28387, 30.0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 9069120 reached - Self: Cast spell 52059 on Closest alive creature 28387 in 30.0 yards'); -- waypoint_script.id = 1194

    DELETE FROM `smart_scripts` WHERE `entryorguid`=25465 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (25465, 0, 2, 0, 40, 0, 100, 0, 1, 8569680, 0, 0, 5, 30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 8569680 reached - Self: Play emote 30'), -- waypoint_script.id = 1195
    (25465, 0, 3, 0, 40, 0, 100, 0, 2, 8569680, 0, 0, 80, 2546500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8569680 reached - Self: Start timed action list id 2546500'), -- waypoint_script.id = 1196
    (25465, 0, 4, 0, 40, 0, 100, 0, 3, 8569680, 0, 0, 80, 2546501, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8569680 reached - Self: Start timed action list id 2546501'); -- waypoint_script.id = 1197

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=25349;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=25349 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (25349, 0, 0, 0, 40, 0, 100, 0, 1, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 1, 0, 40, 0, 100, 0, 2, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 2, 0, 40, 0, 100, 0, 3, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 3, 0, 40, 0, 100, 0, 4, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 4, 0, 40, 0, 100, 0, 5, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 5, 0, 40, 0, 100, 0, 6, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 6, 0, 40, 0, 100, 0, 7, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 7, 0, 40, 0, 100, 0, 8, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 8, 0, 40, 0, 100, 0, 9, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 9, 0, 40, 0, 100, 0, 10, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 10, 0, 40, 0, 100, 0, 11, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 11, 0, 40, 0, 100, 0, 12, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 12, 0, 40, 0, 100, 0, 13, 7770320, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 7770320 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 13, 0, 40, 0, 100, 0, 1, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 14, 0, 40, 0, 100, 0, 2, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 15, 0, 40, 0, 100, 0, 3, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 16, 0, 40, 0, 100, 0, 4, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 17, 0, 40, 0, 100, 0, 5, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 18, 0, 40, 0, 100, 0, 6, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 19, 0, 40, 0, 100, 0, 7, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 20, 0, 40, 0, 100, 0, 8, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 21, 0, 40, 0, 100, 0, 9, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 22, 0, 40, 0, 100, 0, 10, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 23, 0, 40, 0, 100, 0, 11, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 24, 0, 40, 0, 100, 0, 12, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 25, 0, 40, 0, 100, 0, 13, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 26, 0, 40, 0, 100, 0, 14, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 27, 0, 40, 0, 100, 0, 15, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 28, 0, 40, 0, 100, 0, 16, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 16 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 29, 0, 40, 0, 100, 0, 17, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 17 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 30, 0, 40, 0, 100, 0, 18, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 31, 0, 40, 0, 100, 0, 19, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 19 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 32, 0, 40, 0, 100, 0, 20, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 20 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 33, 0, 40, 0, 100, 0, 21, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 21 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 34, 0, 40, 0, 100, 0, 22, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 22 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 35, 0, 40, 0, 100, 0, 23, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 36, 0, 40, 0, 100, 0, 24, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 24 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 37, 0, 40, 0, 100, 0, 25, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 25 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 38, 0, 40, 0, 100, 0, 26, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 26 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 39, 0, 40, 0, 100, 0, 27, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 27 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 40, 0, 40, 0, 100, 0, 28, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 28 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 41, 0, 40, 0, 100, 0, 29, 7770400, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 29 of path 7770400 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 42, 0, 40, 0, 100, 0, 1, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 43, 0, 40, 0, 100, 0, 2, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 44, 0, 40, 0, 100, 0, 3, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 45, 0, 40, 0, 100, 0, 4, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 46, 0, 40, 0, 100, 0, 5, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 47, 0, 40, 0, 100, 0, 6, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 48, 0, 40, 0, 100, 0, 7, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 49, 0, 40, 0, 100, 0, 8, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 50, 0, 40, 0, 100, 0, 9, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 51, 0, 40, 0, 100, 0, 10, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 52, 0, 40, 0, 100, 0, 11, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 53, 0, 40, 0, 100, 0, 12, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 54, 0, 40, 0, 100, 0, 13, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 55, 0, 40, 0, 100, 0, 14, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 14 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 56, 0, 40, 0, 100, 0, 15, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 57, 0, 40, 0, 100, 0, 16, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 16 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 58, 0, 40, 0, 100, 0, 17, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 17 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 59, 0, 40, 0, 100, 0, 18, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 18 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 60, 0, 40, 0, 100, 0, 19, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 19 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 61, 0, 40, 0, 100, 0, 20, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 20 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 62, 0, 40, 0, 100, 0, 21, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 21 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 63, 0, 40, 0, 100, 0, 22, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 22 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 64, 0, 40, 0, 100, 0, 23, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 23 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 65, 0, 40, 0, 100, 0, 24, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 24 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 66, 0, 40, 0, 100, 0, 25, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 25 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 67, 0, 40, 0, 100, 0, 26, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 26 of path 7770960 reached - Self: Start timed action list id 2534900'), -- waypoint_script.id = 1198
    (25349, 0, 68, 0, 40, 0, 100, 0, 27, 7770960, 0, 0, 80, 2534900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 27 of path 7770960 reached - Self: Start timed action list id 2534900'); -- waypoint_script.id = 1198

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28500;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28500 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28500, 0, 0, 0, 40, 0, 100, 0, 8, 10286160, 0, 0, 17, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 10286160 reached - Self: Set emote state to 1'), -- waypoint_script.id = 1200
    (28500, 0, 1, 0, 40, 0, 100, 0, 1, 10286160, 0, 0, 80, 2850000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 10286160 reached - Self: Start timed action list id 2850000'), -- waypoint_script.id = 1201
    (28500, 0, 2, 0, 40, 0, 100, 0, 5, 10286160, 0, 0, 80, 2850000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 10286160 reached - Self: Start timed action list id 2850000'), -- waypoint_script.id = 1201
    (28500, 0, 3, 0, 40, 0, 100, 0, 12, 10286160, 0, 0, 80, 2850000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 10286160 reached - Self: Start timed action list id 2850000'), -- waypoint_script.id = 1201
    (28500, 0, 4, 0, 40, 0, 100, 0, 13, 10286160, 0, 0, 80, 2850000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 13 of path 10286160 reached - Self: Start timed action list id 2850000'); -- waypoint_script.id = 1201

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28505;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28505 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28505, 0, 0, 0, 40, 0, 100, 0, 1, 10286320, 0, 0, 80, 2850000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 10286320 reached - Self: Start timed action list id 2850000'), -- waypoint_script.id = 1201
    (28505, 0, 1, 0, 40, 0, 100, 0, 4, 10286320, 0, 0, 80, 2850000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 10286320 reached - Self: Start timed action list id 2850000'), -- waypoint_script.id = 1201
    (28505, 0, 2, 0, 40, 0, 100, 0, 5, 10286320, 0, 0, 80, 2850000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 10286320 reached - Self: Start timed action list id 2850000'), -- waypoint_script.id = 1201
    (28505, 0, 3, 0, 40, 0, 100, 0, 2, 10286320, 0, 0, 80, 2850500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 10286320 reached - Self: Start timed action list id 2850500'), -- waypoint_script.id = 1202
    (28505, 0, 4, 0, 40, 0, 100, 0, 3, 10286320, 0, 0, 80, 2850500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 10286320 reached - Self: Start timed action list id 2850500'); -- waypoint_script.id = 1202

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=28506;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=28506 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28506, 0, 0, 0, 40, 0, 100, 0, 1, 10286400, 0, 0, 80, 2850600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 10286400 reached - Self: Start timed action list id 2850600'), -- waypoint_script.id = 1203
    (28506, 0, 1, 0, 40, 0, 100, 0, 2, 10286400, 0, 0, 80, 2850600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 10286400 reached - Self: Start timed action list id 2850600'), -- waypoint_script.id = 1203
    (28506, 0, 2, 0, 40, 0, 100, 0, 3, 10286400, 0, 0, 80, 2850600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 10286400 reached - Self: Start timed action list id 2850600'), -- waypoint_script.id = 1203
    (28506, 0, 3, 0, 40, 0, 100, 0, 4, 10286400, 0, 0, 80, 2850600, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 10286400 reached - Self: Start timed action list id 2850600'); -- waypoint_script.id = 1203

    DELETE FROM `smart_scripts` WHERE `entryorguid`=24019 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (24019, 0, 2, 0, 40, 0, 100, 0, 5, 9270320, 0, 0, 4, 7274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 9270320 reached - Self: Play direct sound 7274 to every player in visibility range of Self'), -- waypoint_script.id = 115879
    (24019, 0, 3, 0, 40, 0, 100, 0, 12, 9270320, 0, 0, 4, 7274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 9270320 reached - Self: Play direct sound 7274 to every player in visibility range of Self'), -- waypoint_script.id = 115879
    (24019, 0, 4, 0, 40, 0, 100, 0, 19, 9270320, 0, 0, 4, 7274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 19 of path 9270320 reached - Self: Play direct sound 7274 to every player in visibility range of Self'), -- waypoint_script.id = 115879
    (24019, 0, 5, 0, 40, 0, 100, 0, 26, 9270320, 0, 0, 4, 7274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 26 of path 9270320 reached - Self: Play direct sound 7274 to every player in visibility range of Self'); -- waypoint_script.id = 115879

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18999 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18999, 0, 1, 0, 40, 0, 100, 0, 2, 5463200, 0, 0, 80, 1899900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 5463200 reached - Self: Start timed action list id 1899900'), -- waypoint_script.id = 682901
    (18999, 0, 2, 0, 40, 0, 100, 0, 5, 5463200, 0, 0, 80, 1899901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 5463200 reached - Self: Start timed action list id 1899901'), -- waypoint_script.id = 682902
    (18999, 0, 3, 0, 40, 0, 100, 0, 7, 5463200, 0, 0, 80, 1899902, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 5463200 reached - Self: Start timed action list id 1899902'), -- waypoint_script.id = 682903
    (18999, 0, 4, 0, 40, 0, 100, 0, 9, 5463200, 0, 0, 80, 1899903, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 9 of path 5463200 reached - Self: Start timed action list id 1899903'), -- waypoint_script.id = 682904
    (18999, 0, 5, 0, 40, 0, 100, 0, 2, 5463360, 0, 0, 80, 1899904, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 5463360 reached - Self: Start timed action list id 1899904'), -- waypoint_script.id = 682921
    (18999, 0, 6, 0, 40, 0, 100, 0, 5, 5463360, 0, 0, 80, 1899905, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 5463360 reached - Self: Start timed action list id 1899905'), -- waypoint_script.id = 682922
    (18999, 0, 7, 0, 40, 0, 100, 0, 8, 5463360, 0, 0, 80, 1899906, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 5463360 reached - Self: Start timed action list id 1899906'), -- waypoint_script.id = 682923
    (18999, 0, 8, 0, 40, 0, 100, 0, 11, 5463360, 0, 0, 80, 1899907, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 5463360 reached - Self: Start timed action list id 1899907'), -- waypoint_script.id = 682924
    (18999, 0, 9, 0, 40, 0, 100, 0, 5, 5463680, 0, 0, 80, 1899908, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 5463680 reached - Self: Start timed action list id 1899908'), -- waypoint_script.id = 682961
    (18999, 0, 10, 0, 40, 0, 100, 0, 11, 5463680, 0, 0, 80, 1899909, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 5463680 reached - Self: Start timed action list id 1899909'), -- waypoint_script.id = 682962
    (18999, 0, 11, 0, 40, 0, 100, 0, 15, 5463680, 0, 0, 80, 1899910, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 15 of path 5463680 reached - Self: Start timed action list id 1899910'), -- waypoint_script.id = 682963
    (18999, 0, 12, 0, 40, 0, 100, 0, 19, 5463680, 0, 0, 80, 1899911, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 19 of path 5463680 reached - Self: Start timed action list id 1899911'); -- waypoint_script.id = 682964

    UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=19003;
    DELETE FROM `smart_scripts` WHERE `entryorguid`=19003 AND `source_type`=0 AND `id` >= 0;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (19003, 0, 0, 0, 40, 0, 100, 0, 2, 5464640, 0, 0, 80, 1900300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 5464640 reached - Self: Start timed action list id 1900300'), -- waypoint_script.id = 683081
    (19003, 0, 1, 0, 40, 0, 100, 0, 10, 5464720, 0, 0, 80, 1900301, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 5464720 reached - Self: Start timed action list id 1900301'); -- waypoint_script.id = 683091

    DELETE FROM `smart_scripts` WHERE `entryorguid`=10899 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (10899, 0, 3, 0, 40, 0, 100, 0, 2, 11028480, 0, 0, 80, 1089900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 11028480 reached - Self: Start timed action list id 1089900'), -- waypoint_script.id = 1378561
    (10899, 0, 4, 0, 40, 0, 100, 0, 8, 11028480, 0, 0, 80, 1089901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 8 of path 11028480 reached - Self: Start timed action list id 1089901'), -- waypoint_script.id = 1378562
    (10899, 0, 5, 0, 40, 0, 100, 0, 11, 11028480, 0, 0, 80, 1089902, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 11028480 reached - Self: Start timed action list id 1089902'); -- waypoint_script.id = 1378563

    DELETE FROM `smart_scripts` WHERE `entryorguid`=9097 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (9097, 0, 3, 0, 40, 0, 100, 0, 2, 11043600, 0, 0, 80, 909700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 11043600 reached - Self: Start timed action list id 909700'), -- waypoint_script.id = 1380451
    (9097, 0, 4, 0, 40, 0, 100, 0, 4, 11043600, 0, 0, 80, 909701, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 11043600 reached - Self: Start timed action list id 909701'); -- waypoint_script.id = 1380452

    DELETE FROM `smart_scripts` WHERE `entryorguid`=17259 AND `source_type`=0 AND `id` >= 5;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (17259, 0, 5, 0, 40, 0, 100, 0, 4, 16209280, 0, 0, 80, 1725900, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 16209280 reached - Self: Start timed action list id 1725900'), -- waypoint_script.id = 2026160
    (17259, 0, 6, 0, 40, 0, 100, 0, 10, 16209280, 0, 0, 80, 1725901, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 16209280 reached - Self: Start timed action list id 1725901'); -- waypoint_script.id = 2026161

    DELETE FROM `smart_scripts` WHERE `entryorguid`=17264 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (17264, 0, 1, 0, 40, 0, 100, 0, 6, 16210000, 0, 0, 80, 1726400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 16210000 reached - Self: Start timed action list id 1726400'), -- waypoint_script.id = 2026250
    (17264, 0, 2, 0, 40, 0, 100, 0, 12, 16210000, 0, 0, 80, 1726401, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 16210000 reached - Self: Start timed action list id 1726401'), -- waypoint_script.id = 2026251
    (17264, 0, 3, 0, 40, 0, 100, 0, 4, 16210160, 0, 0, 80, 1726402, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 16210160 reached - Self: Start timed action list id 1726402'), -- waypoint_script.id = 2026270
    (17264, 0, 4, 0, 40, 0, 100, 0, 10, 16210160, 0, 0, 80, 1726403, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 10 of path 16210160 reached - Self: Start timed action list id 1726403'); -- waypoint_script.id = 2026271

    DELETE FROM `smart_scripts` WHERE `entryorguid`=39642 AND `source_type`=0 AND `id` >= 2;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (39642, 0, 2, 0, 40, 0, 100, 0, 1, 30786000, 0, 0, 80, 3964200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 30786000 reached - Self: Start timed action list id 3964200'), -- waypoint_script.id = 3848250
    (39642, 0, 3, 0, 40, 0, 100, 0, 3, 30786000, 0, 0, 80, 3964200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 30786000 reached - Self: Start timed action list id 3964200'), -- waypoint_script.id = 3848250
    (39642, 0, 4, 0, 40, 0, 100, 0, 2, 30829680, 0, 0, 80, 3964201, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 30829680 reached - Self: Start timed action list id 3964201'), -- waypoint_script.id = 3853710
    (39642, 0, 5, 0, 40, 0, 100, 0, 5, 30829680, 0, 0, 80, 3964202, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 30829680 reached - Self: Start timed action list id 3964202'); -- waypoint_script.id = 3853711

    DELETE FROM `smart_scripts` WHERE `entryorguid`=39843 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (39843, 0, 3, 0, 40, 0, 100, 0, 6, 30887760, 0, 0, 80, 3984300, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 30887760 reached - Self: Start timed action list id 3984300'); -- waypoint_script.id = 3860971

    DELETE FROM `smart_scripts` WHERE `entryorguid`=16580 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (16580, 0, 1, 0, 40, 0, 100, 0, 2, 4603120, 0, 0, 80, 1658000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 4603120 reached - Self: Start timed action list id 1658000'); -- waypoint_script.id = 5753900

    DELETE FROM `smart_scripts` WHERE `entryorguid`=16907 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (16907, 0, 3, 0, 40, 0, 100, 0, 6, 4690240, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 4690240 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 4, 0, 40, 0, 100, 0, 12, 4690240, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 4690240 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 5, 0, 40, 0, 100, 0, 3, 4690560, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 4690560 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 6, 0, 40, 0, 100, 0, 12, 4690560, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 4690560 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 7, 0, 40, 0, 100, 0, 2, 4690800, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 4690800 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 8, 0, 40, 0, 100, 0, 6, 4690800, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 4690800 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 9, 0, 40, 0, 100, 0, 5, 4690880, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 5 of path 4690880 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 10, 0, 40, 0, 100, 0, 12, 4690880, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 4690880 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 11, 0, 40, 0, 100, 0, 3, 4691040, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 4691040 reached - Self: Start timed action list id 1690700'), -- waypoint_script.id = 5862800
    (16907, 0, 12, 0, 40, 0, 100, 0, 11, 4691040, 0, 0, 80, 1690700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 11 of path 4691040 reached - Self: Start timed action list id 1690700'); -- waypoint_script.id = 5862800

    DELETE FROM `smart_scripts` WHERE `entryorguid`=18274 AND `source_type`=0 AND `id` >= 1;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (18274, 0, 1, 0, 40, 0, 100, 0, 4, 5245280, 0, 0, 80, 1827400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 4 of path 5245280 reached - Self: Start timed action list id 1827400'); -- waypoint_script.id = 6556600

    DELETE FROM `smart_scripts` WHERE `entryorguid`=28504 AND `source_type`=0 AND `id` >= 11;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (28504, 0, 11, 0, 40, 0, 100, 0, 2, 8820800, 0, 0, 80, 2850400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8820800 reached - Self: Start timed action list id 2850400'), -- waypoint_script.id = 11026002
    (28504, 0, 12, 0, 40, 0, 100, 0, 1, 8821120, 0, 0, 80, 2850401, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 8821120 reached - Self: Start timed action list id 2850401'), -- waypoint_script.id = 11026401
    (28504, 0, 13, 0, 40, 0, 100, 0, 3, 8821120, 0, 0, 80, 2850402, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 8821120 reached - Self: Start timed action list id 2850402'); -- waypoint_script.id = 11026402

    DELETE FROM `smart_scripts` WHERE `entryorguid`=27300 AND `source_type`=0 AND `id` >= 7;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (27300, 0, 7, 0, 40, 0, 100, 0, 1, 8904560, 0, 0, 80, 2730000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 8904560 reached - Self: Start timed action list id 2730000'), -- waypoint_script.id = 11130700
    (27300, 0, 8, 0, 40, 0, 100, 0, 2, 8904560, 0, 0, 80, 2730000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 8904560 reached - Self: Start timed action list id 2730000'); -- waypoint_script.id = 11130700

    DELETE FROM `smart_scripts` WHERE `entryorguid`=29503 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (29503, 0, 3, 0, 40, 0, 100, 0, 7, 7064640, 0, 0, 80, 2937500, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 7 of path 7064640 reached - Self: Start timed action list id 2937500'); -- waypoint_script.id = 11393600

    DELETE FROM `smart_scripts` WHERE `entryorguid`=29407 AND `source_type`=0 AND `id` >= 5;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (29407, 0, 5, 0, 40, 0, 100, 0, 12, 9384640, 0, 0, 80, 2940700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 12 of path 9384640 reached - Self: Start timed action list id 2940700'), -- waypoint_script.id = 11730800
    (29407, 0, 6, 0, 40, 0, 100, 0, 1, 9384800, 0, 0, 80, 2940700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 1 of path 9384800 reached - Self: Start timed action list id 2940700'), -- waypoint_script.id = 11730800
    (29407, 0, 7, 0, 40, 0, 100, 0, 2, 9384800, 0, 0, 80, 2940700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 2 of path 9384800 reached - Self: Start timed action list id 2940700'), -- waypoint_script.id = 11730800
    (29407, 0, 8, 0, 40, 0, 100, 0, 3, 9384800, 0, 0, 80, 2940700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 9384800 reached - Self: Start timed action list id 2940700'); -- waypoint_script.id = 11730800

    DELETE FROM `smart_scripts` WHERE `entryorguid`=26044 AND `source_type`=0 AND `id` >= 3;
    INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
    (26044, 0, 3, 0, 40, 0, 100, 0, 6, 10045280, 0, 0, 80, 2604400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 6 of path 10045280 reached - Self: Start timed action list id 2604400'), -- waypoint_script.id = 12556600
    (26044, 0, 4, 0, 40, 0, 100, 0, 25, 10045280, 0, 0, 80, 2604400, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 25 of path 10045280 reached - Self: Start timed action list id 2604400'); -- waypoint_script.id = 12556600

    DROP TABLE IF EXISTS `waypoint_scripts`;
    
    ALTER TABLE `waypoint_data` 
        DROP COLUMN `action`,
        DROP COLUMN `action_chance`;
  END IF;
END;;

DELIMITER ;
CALL drop_waypoint_scripts_related();

DROP PROCEDURE IF EXISTS drop_waypoint_scripts_related;

