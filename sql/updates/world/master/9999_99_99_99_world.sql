DELIMITER ;;
CREATE PROCEDURE smart_scripts_stringid_9999_99_99_99_world() BEGIN
    IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='smart_scripts' AND `column_name`='action_param_string') THEN

    ALTER TABLE `smart_scripts`
        ADD `action_param_string` VARCHAR(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '' AFTER `action_param7`,
        ADD `target_param_string` VARCHAR(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '' AFTER `target_param4`;

    END IF;
END;;

DELIMITER ;
CALL smart_scripts_stringid_9999_99_99_99_world();

DROP PROCEDURE IF EXISTS smart_scripts_stringid_9999_99_99_99_world;
