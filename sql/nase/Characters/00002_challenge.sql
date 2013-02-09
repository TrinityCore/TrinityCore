-- Character db
CREATE TABLE IF NOT EXISTS `challenge_options` (
        `guid` BIGINT NOT NULL,
        `mode` TINYINT,
        `enable` TINYINT,
        PRIMARY KEY (`guid`)
);