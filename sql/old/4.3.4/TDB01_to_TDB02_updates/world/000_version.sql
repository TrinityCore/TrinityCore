UPDATE `version` SET
    `db_version` = 'TDB 434.02',
    `cache_id` = 2
WHERE
    `db_version` = 'TDB 434.01'
LIMIT 1;
