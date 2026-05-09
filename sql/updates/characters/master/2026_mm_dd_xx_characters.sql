DROP PROCEDURE IF EXISTS apply_if_exists_garrison_table_rework;

DELIMITER ;;

CREATE PROCEDURE apply_if_exists_garrison_table_rework() BEGIN
    IF NOT EXISTS (SELECT * FROM information_schema.columns
            WHERE `table_schema` = SCHEMA()
            AND `table_name` = 'character_garrison' AND `column_name`='garrTypeId') THEN

        ALTER TABLE `character_garrison`
            DROP PRIMARY KEY;

        ALTER TABLE `character_garrison`
            ADD COLUMN `garrTypeId` TINYINT UNSIGNED NOT NULL DEFAULT 0 AFTER `guid`;

        ALTER TABLE `character_garrison`
            ADD PRIMARY KEY (`guid`, `garrTypeId`);

        UPDATE `character_garrison` SET `garrTypeId` = CASE
            WHEN `siteLevelId` < 500 THEN 2 -- Warlords of Draenor
            WHEN `siteLevelId` < 599 THEN 3 -- Legion
            WHEN `siteLevelId` < 800 THEN 9 -- Battle for Azeroth
            WHEN `siteLevelId` < 900 THEN 111 -- Shadowlands
            ELSE 0 -- Unknown
        END;
    END IF;
END;;

DELIMITER ;
CALL apply_if_exists_garrison_table_rework;
DROP PROCEDURE apply_if_exists_garrison_table_rework;
