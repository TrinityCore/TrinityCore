UPDATE 
    `arena_team_member` AS `a`, 
    (SELECT
        `attq1`.`guid` AS `b_guid`,
        `atid`, `atpr`
        FROM 
        (SELECT 
            `guid`, 
            `name`, 
            SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',1545),' ',-1) AS `atid`,
            SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',1550),' ',-1) AS `atpr` 
        FROM 
        `characters`) AS `attq1` 
    INNER JOIN 
        `arena_team_member` ON `arenateamid` = `atid` AND 
        `arena_team_member`.`guid` = `attq1`.`guid` 
    WHERE 
        `atid` <> 0) 
    AS `b` 
SET 
    `a`.`personal_rating` = `b`.`atpr` 
WHERE 
    `a`.`arenateamid` = `b`.`atid` AND 
    `a`.`guid` = `b`.`b_guid`;
	
UPDATE 
    `arena_team_member` AS `a`, 
    (SELECT
        `attq1`.`guid` AS `b_guid`,
        `atid`, `atpr`
        FROM 
        (SELECT 
            `guid`, 
            `name`, 
            SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',1551),' ',-1) AS `atid`,
            SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',1556),' ',-1) AS `atpr` 
        FROM 
        `characters`) AS `attq1` 
    INNER JOIN 
        `arena_team_member` ON `arenateamid` = `atid` AND 
        `arena_team_member`.`guid` = `attq1`.`guid` 
    WHERE 
        `atid` <> 0) 
    AS `b` 
SET 
    `a`.`personal_rating` = `b`.`atpr` 
WHERE 
    `a`.`arenateamid` = `b`.`atid` AND 
    `a`.`guid` = `b`.`b_guid`;
	
UPDATE 
    `arena_team_member` AS `a`, 
    (SELECT
        `attq1`.`guid` AS `b_guid`,
        `atid`, `atpr`
        FROM 
        (SELECT 
            `guid`, 
            `name`, 
            SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',1557),' ',-1) AS `atid`,
            SUBSTRING_INDEX(SUBSTRING_INDEX(`data`,' ',1562),' ',-1) AS `atpr` 
        FROM 
        `characters`) AS `attq1` 
    INNER JOIN 
        `arena_team_member` ON `arenateamid` = `atid` AND 
        `arena_team_member`.`guid` = `attq1`.`guid` 
    WHERE 
        `atid` <> 0) 
    AS `b` 
SET 
    `a`.`personal_rating` = `b`.`atpr` 
WHERE 
    `a`.`arenateamid` = `b`.`atid` AND 
    `a`.`guid` = `b`.`b_guid`;

