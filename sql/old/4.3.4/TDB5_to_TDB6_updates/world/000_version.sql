UPDATE `version` SET
    `db_version` = 'TDB 434.05',
    `cache_id` = 5
WHERE
    `db_version` = 'TDB 434.04'
LIMIT 1;
