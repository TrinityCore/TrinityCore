-- 
DROP PROCEDURE IF EXISTS apply_if_exists_2023_06_01_00_world;

DELIMITER ;;
CREATE PROCEDURE apply_if_exists_2023_06_01_00_world() BEGIN
  IF EXISTS (SELECT * FROM `information_schema`.`columns` WHERE `table_schema`=SCHEMA() AND `table_name`='graveyard_zone' AND `column_name`='Faction') THEN
    DELETE c FROM `conditions` c INNER JOIN `graveyard_zone` gz ON (c.`SourceEntry` = gz.`ID` AND c.`SourceGroup` = gz.`GhostZone`) WHERE (c.`SourceTypeOrReferenceId` = 27 AND gz.`GhostZone` <> 0);
    INSERT INTO
      `conditions` (
        `SourceTypeOrReferenceId`,
        `SourceEntry`,
        `SourceGroup`,
        `ConditionTypeOrReference`,
        `ConditionValue1`,
        `Comment`
      )
      SELECT
        27,
        `ID`,
        `GhostZone`,
        6,
        `Faction`,
        CONCAT(
          'Graveyard - ',
          `ID`,
          ' - ',
          `GhostZone`,
          ' - ',
          `Comment`,
          ' - Team ',
          CASE
            WHEN `Faction` = 469 THEN 'Alliance'
            WHEN `Faction` = 67 THEN 'Horde'
            ELSE `Faction`
          END
        )
      FROM `graveyard_zone`
      WHERE `Faction` <> 0;
      
    ALTER TABLE `graveyard_zone` DROP COLUMN `Faction`;
  END IF;
END;;

DELIMITER ;
CALL apply_if_exists_2023_06_01_00_world();

DROP PROCEDURE IF EXISTS apply_if_exists_2023_06_01_00_world;

-- add graveyards from open world pvp
DELETE FROM `graveyard_zone` WHERE `ID` IN (969, 993);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(969, 3521, 'Graveyard - Zangarmarsh - PvP'),
(993, 3518, 'Graveyard - Nagrand (Outland), Halaa - PvP');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (969, 993);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(27, 969, 3521, 0, 6, 469, 0, 'Graveyard - Zangarmarsh - PvP - Team Alliance'),
(27, 969, 3521, 0, 11, 2648, 1, 'Graveyard - Zangarmarsh - PvP - Alliance Controlled'),
(27, 969, 3521, 1, 6, 67, 0, 'Graveyard - Zangarmarsh - PvP - Team Horde'),
(27, 969, 3521, 1, 11, 2649, 1, 'Graveyard - Zangarmarsh - PvP - Horde Controlled'),
(27, 993, 3518, 0, 6, 469, 0, 'Graveyard - Nagrand (Outland), Halaa - PvP - Team Alliance'),
(27, 993, 3518, 0, 11, 2672, 1, 'Graveyard - Nagrand (Outland), Halaa - PvP - Alliance Controlled'),
(27, 993, 3518, 1, 6, 67, 0, 'Graveyard - Nagrand (Outland), Halaa - PvP - Team Horde'),
(27, 993, 3518, 1, 11, 2673, 1, 'Graveyard - Nagrand (Outland), Halaa - PvP - Horde Controlled');
