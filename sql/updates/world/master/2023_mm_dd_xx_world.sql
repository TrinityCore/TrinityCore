DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (SELECT `ID` FROM `graveyard_zone`);
INSERT INTO
    `conditions` (
        `SourceTypeOrReferenceId`,
        `SourceEntry`,
        `ConditionTypeOrReference`,
        `ConditionValue1`,
        `Comment`
    )
SELECT
    27,
    `ID`,
    6,
    `Faction`,
    CONCAT(
        'Graveyard - ',
        `ID`,
        ' - Team ',
        CASE
            WHEN `Faction` = 469 THEN 'Alliance'
            WHEN `Faction` = 67 THEN 'Horde'
            ELSE `Faction`
        END
    )
FROM `graveyard_zone`
WHERE `Faction` <> 0
GROUP BY 1, 2, 3, 4, 5;

-- add graveyards from open world pvp
DELETE FROM `graveyard_zone` WHERE `ID` IN (969, 993);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(969, 3521, 'Graveyard - Zangarmarsh - PvP'),
(993, 3518, 'Graveyard - Nagrand (Outland), Halaa - PvP');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (969, 993);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
(27, 969, 0, 6, 469, 0, 'Graveyard - Zangarmarsh - PvP - Team Alliance'),
(27, 969, 0, 11, 2648, 1, 'Graveyard - Zangarmarsh - PvP - Alliance Controlled'),
(27, 969, 1, 6, 67, 0, 'Graveyard - Zangarmarsh - PvP - Team Horde'),
(27, 969, 1, 11, 2649, 1, 'Graveyard - Zangarmarsh - PvP - Horde Controlled'),

(27, 993, 0, 6, 469, 0, 'Graveyard - Nagrand (Outland), Halaa - PvP - Team Alliance'),
(27, 993, 0, 11, 2672, 1, 'Graveyard - Nagrand (Outland), Halaa - PvP - Alliance Controlled'),
(27, 993, 1, 6, 67, 0, 'Graveyard - Nagrand (Outland), Halaa - PvP - Team Horde'),
(27, 993, 1, 11, 2673, 1, 'Graveyard - Nagrand (Outland), Halaa - PvP - Horde Controlled');

-- commented out for easier testing
-- ALTER TABLE `graveyard_zone` DROP COLUMN `Faction`;
