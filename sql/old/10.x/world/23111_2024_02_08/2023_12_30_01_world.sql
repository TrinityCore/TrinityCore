
DELIMITER ;;
CREATE PROCEDURE areatrigger_refactor() BEGIN
  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='areatrigger_create_properties' AND `column_name`='IsCustom') THEN

    ALTER TABLE `areatrigger_create_properties`
        ADD COLUMN `IsCustom` tinyint unsigned NOT NULL AFTER `Id`,
        ADD COLUMN `IsAreatriggerCustom` tinyint unsigned NOT NULL AFTER `AreaTriggerId`,
        ADD COLUMN `Flags` int unsigned NOT NULL DEFAULT '0' AFTER `IsAreatriggerCustom`,
        DROP PRIMARY KEY, ADD PRIMARY KEY (`Id`, `IsCustom`);

    ALTER TABLE `areatrigger_create_properties_orbit`
        ADD COLUMN `IsCustom` tinyint unsigned NOT NULL AFTER `AreaTriggerCreatePropertiesId`,
        DROP PRIMARY KEY, ADD PRIMARY KEY (`AreaTriggerCreatePropertiesId`, `IsCustom`);

    ALTER TABLE `areatrigger_create_properties_polygon_vertex`
        ADD COLUMN `IsCustom` tinyint unsigned NOT NULL AFTER `AreaTriggerCreatePropertiesId`,
        DROP PRIMARY KEY, ADD PRIMARY KEY (`AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`);

    ALTER TABLE `areatrigger_create_properties_spline_point`
        ADD COLUMN `IsCustom` tinyint unsigned NOT NULL AFTER `AreaTriggerCreatePropertiesId`,
        DROP PRIMARY KEY, ADD PRIMARY KEY (`AreaTriggerCreatePropertiesId`, `IsCustom`, `Idx`);

  END IF;

  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='areatrigger_template' AND `column_name`='IsCustom') THEN

    ALTER TABLE `areatrigger_template`
        DROP COLUMN `Type`,
        DROP COLUMN `Data0`,
        DROP COLUMN `Data1`,
        DROP COLUMN `Data2`,
        DROP COLUMN `Data3`,
        DROP COLUMN `Data4`,
        DROP COLUMN `Data5`,
        DROP COLUMN `Data6`,
        DROP COLUMN `Data7`,
        CHANGE COLUMN `IsServerSide` `IsCustom` tinyint unsigned NOT NULL;

    ALTER TABLE `areatrigger_template_actions`
        CHANGE COLUMN `IsServerSide` `IsCustom` tinyint unsigned NOT NULL;

  END IF;

  UPDATE `areatrigger_create_properties` SET `IsAreatriggerCustom`=1 WHERE `AreaTriggerId` IN (42,43,50);
  UPDATE `areatrigger_template` SET `IsCustom`=1 WHERE `Id` IN (42,43,50);
  UPDATE `smart_scripts` SET `source_type`=12 WHERE `source_type`=11 AND `entryorguid` IN (42,43);

  UPDATE `areatrigger_create_properties` atcp
  LEFT JOIN `areatrigger_template` att ON att.`Id`=atcp.`AreaTriggerId` and att.`IsCustom`=atcp.`IsAreatriggerCustom`
  SET atcp.`Flags`=att.`Flags`
  WHERE att.`Flags` IS NOT NULL;

  UPDATE `areatrigger_template` SET `Flags`=0x0;
  UPDATE `areatrigger_template` SET `Flags`=0x1 WHERE `Id` BETWEEN 1 AND 33;
  UPDATE `areatrigger_template` SET `Flags`=0x1 WHERE `Id` BETWEEN 42 AND 54;

  UPDATE `areatrigger_template` SET `IsCustom`=0, `Flags`=0x1 WHERE `Id`=17635;

  SET @CPC_ID := 1;
  DELETE FROM `areatrigger_create_properties` WHERE `IsCustom`=1 AND `Id` BETWEEN @CPC_ID+0 AND @CPC_ID+42;
  INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`) VALUES
  (@CPC_ID+0, 1, 1, 1, 1, 3, 1, 3, 3, 1, 3, 0, 0),
  (@CPC_ID+1, 1, 2, 1, 1, 1.25977, 1.27927, 3.70216, 1.25977, 1.27927, 3.70216, 0, 0),
  (@CPC_ID+2, 1, 3, 1, 4, 4, 4, 6, 6, 0, 0, 0, 0),
  (@CPC_ID+3, 1, 4, 1, 4, 0.5, 0.5, 3, 3, 0, 0, 0, 0),
  (@CPC_ID+4, 1, 5, 1, 4, 40, 40, 10, 10, 0, 0, 0, 0),
  (@CPC_ID+5, 1, 6, 1, 4, 0.5, 0.5, 3, 3, 0, 0, 0, 0),
  (@CPC_ID+6, 1, 7, 1, 4, 3, 3, 5, 5, 0, 0, 0, 0),
  (@CPC_ID+7, 1, 8, 1, 4, 4, 4, 4, 4, 0, 0, 0, 0),
  (@CPC_ID+8, 1, 9, 1, 4, 4, 4, 7, 7, 0, 0, 0, 0),
  (@CPC_ID+9, 1, 10, 1, 4, 5, 5, 5, 5, 0, 0, 0, 0),
  (@CPC_ID+10, 1, 11, 1, 4, 4, 4, 15, 15, 0, 0, 0, 0),
  (@CPC_ID+11, 1, 12, 1, 4, 4, 4, 5, 5, 0, 0, 0, 0),
  (@CPC_ID+12, 1, 13, 1, 4, 4, 4, 5, 5, 0, 0, 0, 0),
  (@CPC_ID+13, 1, 14, 1, 4, 4, 4, 5, 5, 0, 0, 0, 0),
  (@CPC_ID+14, 1, 15, 1, 4, 4, 4, 5, 5, 0, 0, 0, 0),
  (@CPC_ID+15, 1, 16, 1, 4, 4, 4, 5, 5, 0, 0, 0, 0),
  (@CPC_ID+16, 1, 17, 1, 4, 5, 5, 8, 8, 0, 0, 0, 0),
  (@CPC_ID+17, 1, 18, 1, 4, 5, 5, 8, 8, 0, 0, 0, 0),
  (@CPC_ID+18, 1, 19, 1, 4, 5, 5, 9, 9, 0, 0, 0, 0),
  (@CPC_ID+19, 1, 20, 1, 6, 5, 5, 8, 8, 0, 0, 0, 0),
  (@CPC_ID+20, 1, 21, 1, 4, 5, 5, 6, 6, 0, 0, 0, 0),
  (@CPC_ID+21, 1, 22, 1, 4, 5, 5, 8, 8, 0, 0, 0, 0),
  (@CPC_ID+22, 1, 23, 1, 1, 18, 18, 12, 18, 18, 12, 0, 0),
  (@CPC_ID+23, 1, 24, 1, 1, 2, 50, 30, 2, 50, 30, 0, 0),
  (@CPC_ID+24, 1, 25, 1, 1, 1, 25, 80, 1, 25, 80, 0, 0),
  (@CPC_ID+25, 1, 26, 1, 1, 1, 20, 30, 1, 20, 30, 0, 0),
  (@CPC_ID+26, 1, 27, 1, 1, 20, 50, 5, 20, 50, 5, 0, 0),
  (@CPC_ID+27, 1, 28, 1, 1, 10, 25, 1, 10, 25, 1, 0, 0),
  (@CPC_ID+28, 1, 29, 1, 0, 3, 3, 0, 0, 0, 0, 0, 0),
  (@CPC_ID+29, 1, 30, 1, 0, 5, 5, 0, 0, 0, 0, 0, 0),
  (@CPC_ID+30, 1, 31, 1, 0, 5, 5, 0, 0, 0, 0, 0, 0),
  (@CPC_ID+31, 1, 32, 1, 1, 38, 38, 25, 38, 38, 25, 0, 0),
  (@CPC_ID+32, 1, 33, 1, 0, 1.5, 1.5, 0, 0, 0, 0, 0, 0),
  (@CPC_ID+33, 1, 44, 1, 1, 30, 20, 10, 30, 20, 10, 0, 0),
  (@CPC_ID+34, 1, 45, 1, 1, 250, 250, 50, 250, 250, 50, 0, 0),
  (@CPC_ID+35, 1, 46, 1, 0, 75, 75, 0, 0, 0, 0, 0, 0),
  (@CPC_ID+36, 1, 48, 1, 1, 35, 20, 25, 35, 20, 25, 0, 0),
  (@CPC_ID+37, 1, 49, 1, 1, 30, 50, 5, 30, 50, 5, 0, 0),
  (@CPC_ID+38, 1, 51, 1, 0, 70, 70, 0, 0, 0, 0, 0, 0),
  (@CPC_ID+39, 1, 52, 1, 1, 20, 20, 10, 20, 20, 10, 0, 0),
  (@CPC_ID+40, 1, 53, 1, 1, 30, 20, 10, 30, 20, 10, 0, 0),
  (@CPC_ID+41, 1, 54, 1, 1, 4, 60, 30, 4, 60, 30, 0, 0),
  (@CPC_ID+42, 1, 17635, 0, 4, 40, 40, 10, 10, 0, 0, 0, 0);

  IF NOT EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='areatrigger' AND `column_name`='IsCustom') THEN

    UPDATE `areatrigger` SET `IsServerside`=0 WHERE `AreaTriggerId`=17635;

    UPDATE `areatrigger` att
    LEFT JOIN `areatrigger_create_properties` atcp ON att.`AreaTriggerId`=atcp.`AreaTriggerId` AND att.`IsServerSide`=atcp.`IsAreatriggerCustom`
    SET
        att.`AreaTriggerId`=atcp.`Id`,
        att.`IsServerSide`=atcp.`IsCustom`
    WHERE atcp.`Id` IS NOT NULL
    AND atcp.`IsCustom` IS NOT NULL;

    ALTER TABLE `areatrigger`
        DROP COLUMN `Shape`,
        DROP COLUMN `ShapeData0`,
        DROP COLUMN `ShapeData1`,
        DROP COLUMN `ShapeData2`,
        DROP COLUMN `ShapeData3`,
        DROP COLUMN `ShapeData4`,
        DROP COLUMN `ShapeData5`,
        DROP COLUMN `ShapeData6`,
        DROP COLUMN `ShapeData7`,
        CHANGE COLUMN `AreaTriggerId` `AreaTriggerCreatePropertiesId` int unsigned NOT NULL,
        CHANGE COLUMN `IsServerSide` `IsCustom` tinyint unsigned NOT NULL;

  END IF;
END;;

DELIMITER ;
CALL areatrigger_refactor();

DROP PROCEDURE IF EXISTS areatrigger_refactor;

DELETE FROM `trinity_string` WHERE `entry` IN (1997, 1998);
INSERT INTO `trinity_string` (`entry`, `content_default`) VALUES
(1997,'You have entered areatrigger entity %u (IsCustom: %u IsSpawn: %u GUID: %u).'),
(1998,'You have left areatrigger entity %u (IsCustom: %u IsSpawn: %u GUID: %u).');
