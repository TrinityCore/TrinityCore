DELIMITER ;;
CREATE PROCEDURE serverside_spell_2025_01_23_00() BEGIN
    IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='serverside_spell' AND `column_name`='AttributesEx15') THEN

    ALTER TABLE `serverside_spell` 
       ADD COLUMN `AttributesEx15` int unsigned NOT NULL DEFAULT '0' AFTER `AttributesEx14`;

    END IF;
END;;

DELIMITER ;
CALL serverside_spell_2025_01_23_00();

DROP PROCEDURE IF EXISTS serverside_spell_2025_01_23_00;
