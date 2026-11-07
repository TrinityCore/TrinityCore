DELIMITER ;;
CREATE PROCEDURE world_2026_01_28_00() BEGIN
  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='player_classlevelstats' AND `column_name`='spi') THEN
    ALTER TABLE `access_requirement` MODIFY `difficulty` int NOT NULL DEFAULT 0;
    ALTER TABLE `creature_questitem` MODIFY `DifficultyID` int NOT NULL DEFAULT 0;
    ALTER TABLE `creature_static_flags_override` MODIFY `DifficultyId` int NOT NULL DEFAULT 0;
    ALTER TABLE `creature_template_difficulty` MODIFY `DifficultyID` int NOT NULL DEFAULT 0;
    ALTER TABLE `player_classlevelstats` ADD `spi` smallint COMMENT 'spirit' AFTER `inte`;
    ALTER TABLE `player_racestats` ADD `spi` smallint COMMENT 'spirit' AFTER `inte`;
    UPDATE `player_classlevelstats` SET `spi`=0;
    UPDATE `player_racestats` SET `spi`=0;
    ALTER TABLE `player_classlevelstats` MODIFY `spi` smallint NOT NULL COMMENT 'spirit';
    ALTER TABLE `player_racestats` MODIFY `spi` smallint NOT NULL COMMENT 'spirit';
    ALTER TABLE `quest_template` ADD `RewardFavor` int NOT NULL DEFAULT 0;
    ALTER TABLE `quest_objectives` CHANGE `SecondaryAmount` `ConditionalAmount` int NOT NULL DEFAULT 0;
    ALTER TABLE `scenarios` MODIFY `difficulty` int NOT NULL DEFAULT 0;
    ALTER TABLE `serverside_spell` ADD `AttributesEx16` int UNSIGNED NOT NULL DEFAULT 0 AFTER `AttributesEx15`;
  END IF;
END;;

DELIMITER ;
CALL world_2026_01_28_00();

DROP PROCEDURE IF EXISTS world_2026_01_28_00;
