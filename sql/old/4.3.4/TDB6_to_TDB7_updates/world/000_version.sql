UPDATE `version` SET
    `db_version` = 'TDB 434.06',
    `cache_id` = 6
WHERE
    `db_version` = 'TDB 434.05'
LIMIT 1;
