-- pretend the broken one doesnt exist
DELETE FROM `updates` WHERE `name`='2018_02_08_00_world.sql';

DROP PROCEDURE IF EXISTS fixup_2018_02_08_00_world;

DELIMITER ';;'
CREATE PROCEDURE fixup_2018_02_08_00_world() begin
    /* try to rerun a fixed version of the old update */
    IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='race_unlock_requirement' AND `column_name`='achievementId') THEN
        ALTER TABLE `guild_rewards` ADD `RaceMask_new` bigint(20) unsigned DEFAULT '0' AFTER `RaceMask`;
        UPDATE `guild_rewards` SET `RaceMask_new`=`RaceMask` WHERE `RaceMask`>=0;
        ALTER TABLE `guild_rewards`
          DROP `RaceMask`,
          CHANGE `RaceMask_new` `RaceMask` bigint(20) unsigned DEFAULT '0';

        ALTER TABLE `playerchoice`
          ADD `UiTextureKitId` int(11) NOT NULL DEFAULT '0' AFTER `ChoiceId`,
          ADD `HideWarboardHeader` tinyint(1) NOT NULL DEFAULT '0' AFTER `Question`;

        ALTER TABLE `quest_poi` ADD `AlwaysAllowMergingBlobs` tinyint(1) unsigned NOT NULL DEFAULT '0' AFTER `WoDUnk1`;

        ALTER TABLE `quest_template`
          ADD `MaxScalingLevel` int(11) NOT NULL DEFAULT '255' AFTER `QuestLevel`,
          ADD `AllowableRaces_new` bigint(20) unsigned NOT NULL DEFAULT 0 AFTER `AllowableRaces`;
        UPDATE `quest_template` SET `AllowableRaces_new`=`AllowableRaces` WHERE `AllowableRaces`>=0;
        ALTER TABLE `quest_template`
          DROP `AllowableRaces`,
          CHANGE `AllowableRaces_new` `AllowableRaces` bigint(20) unsigned DEFAULT '0';

        RENAME TABLE `race_expansion_requirement` TO `race_unlock_requirement`;
        ALTER TABLE `race_unlock_requirement` ADD `achievementId` int(10) unsigned NOT NULL DEFAULT '0';
    END IF;
END;;

DELIMITER ';'
CALL fixup_2018_02_08_00_world();

DROP PROCEDURE IF EXISTS fixup_2018_02_08_00_world;

-- restore values broken by 2018_02_08_00_world if it did not cause an error during import
UPDATE `guild_rewards` SET `RaceMask`=0xFFFFFFFF WHERE `ItemID` IN (62023,62024,62025,62026,62027,62029,63138,69209,69210,69888,85508,85509,85510,85666,89190,89191,89192,89193,89194,89195,116666);
UPDATE `quest_template` SET `AllowableRaces`=0xFFFFFFBA WHERE `ID`=12515;
UPDATE `quest_template` SET `AllowableRaces`=0xFFFFFFFE WHERE `ID` IN (29078,29079,29080,29081,29082,29083);
UPDATE `quest_template` SET `AllowableRaces`=0xFFFFFFFF WHERE `AllowableRaces`=0 AND `ID` NOT IN (13914,13915,13916,13917,29039);
