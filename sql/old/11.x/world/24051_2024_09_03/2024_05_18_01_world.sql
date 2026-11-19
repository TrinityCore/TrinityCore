DELIMITER ;;
CREATE PROCEDURE 2024_05_18_01_areatrigger_spellvisual() BEGIN
  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='areatrigger_create_properties' AND `column_name`='SpellsForVisuals') THEN
    
    ALTER TABLE `areatrigger`
        DROP COLUMN `SpellForVisuals`;

    ALTER TABLE `areatrigger_create_properties`
        ADD COLUMN `SpellForVisuals` INT AFTER `DecalPropertiesId`;

  END IF;
END;;

DELIMITER ;
CALL 2024_05_18_01_areatrigger_spellvisual();

DROP PROCEDURE IF EXISTS 2024_05_18_01_areatrigger_spellvisual;
