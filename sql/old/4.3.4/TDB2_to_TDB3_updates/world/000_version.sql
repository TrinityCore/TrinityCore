UPDATE `version` SET
    `db_version` = 'TDB 434.03',
    `cache_id` = 3
WHERE
    `db_version` = 'TDB 434.02'
LIMIT 1;
