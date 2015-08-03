UPDATE `version` SET
    `db_version` = 'TDB 434.04',
    `cache_id` = 4
WHERE
    `db_version` = 'TDB 434.03'
LIMIT 1;
