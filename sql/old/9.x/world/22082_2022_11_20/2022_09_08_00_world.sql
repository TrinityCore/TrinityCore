
DROP PROCEDURE IF EXISTS apply_if_not_exists_2022_09_08_00_world;

DELIMITER ';;'
CREATE PROCEDURE apply_if_not_exists_2022_09_08_00_world() BEGIN
  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='gossip_menu_option' AND `column_name`='OptionNpc') THEN
    -- Update table `gossip_menu_option`
    ALTER TABLE `gossip_menu_option`
      DROP `OptionType`,
      CHANGE `OptionIcon` `OptionNpc` tinyint UNSIGNED NOT NULL DEFAULT 0;

    -- Update default option
    DELETE FROM `gossip_menu_option` WHERE `MenuID`=0;
    INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
    (0, 1 , 1 , 'I want to browse your goods.', 3370, 128, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 2 , 2 , 'I''d like to travel by air.', 53141, 8192, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 3 , 3 , 'Train me.', 3266, 16, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 4 , 4 , 'Return me to life.', 2547, 16384, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 5 , 5 , 'Make this inn your home.', 2822, 65536, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 6 , 6 , 'I would like to check my deposit box.', 3398, 131072, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 7 , 7 , 'How do I form a guild?', 3413, 262144, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 8 , 8 , 'I want to create a guild crest.', 3415, 524288, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 9,  9 , 'I would like to go to the battleground.', 10355, 1048576, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 10, 10, 'I''d like to browse the items up for auction.', 52635, 2097152, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 12, 12, 'I''d like to stable my pet here.', 30181, 4194304, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 18, 18, 'I''d like to check my mail.', 146045, 67108864, 0, 0, 0, 0, 0, NULL, 0, 0),
    (0, 34, 34, 'I want to transmogrify my gear.', 130510, 268435456, 0, 0, 0, 0, 0, NULL, 0, 0);

    -- Drop "npc_experience" script use
    UPDATE `creature_template` SET `ScriptName`='' WHERE `entry` IN (35364, 35365);
  END IF;
END;;

DELIMITER ';'
CALL apply_if_not_exists_2022_09_08_00_world();

DROP PROCEDURE IF EXISTS apply_if_not_exists_2022_09_08_00_world;
