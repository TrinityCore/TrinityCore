UPDATE `version` SET
    `db_version` = 'TDB 434.08',
    `cache_id` = 8
WHERE
    `db_version` = 'TDB 434.07'
LIMIT 1;
