UPDATE `version` SET
    `db_version` = 'TDB 434.07',
    `cache_id` = 7
WHERE
    `db_version` = 'TDB 434.06'
LIMIT 1;
