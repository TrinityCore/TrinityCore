DELIMITER ;;
CREATE PROCEDURE item_instance_deprecated_columns_2024_04_09_00() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='item_instance' AND `column_name`='transmogrification') THEN

    ALTER TABLE `item_instance` 
      DROP `transmogrification`,
      DROP `enchantIllusion`;

  END IF;
END;;

DELIMITER ;
CALL item_instance_deprecated_columns_2024_04_09_00();

DROP PROCEDURE IF EXISTS item_instance_deprecated_columns_2024_04_09_00;
