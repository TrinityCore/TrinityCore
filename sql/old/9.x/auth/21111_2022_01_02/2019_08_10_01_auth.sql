-- 

START TRANSACTION; -- we're messing with the accounts table here, let's play it safe

DROP TABLE IF EXISTS `secret_digest`;
CREATE TABLE `secret_digest` (
  `id` int(10) unsigned not null,
  `digest` varchar(100) not null,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB;

-- ============================================== --
-- BASE32 CONVERSION STARTS HERE                  --
-- (there is another banner like this at the end, --
--  so you know how far down you need to skip)    --
-- ============================================== --

CREATE TEMPORARY TABLE `_temp_base32_lookup1`
(
    `c` char(1) not null,
    `v` tinyint unsigned not null,
    primary key (`c`)
);
INSERT INTO `_temp_base32_lookup1` (`c`,`v`) VALUES
('A',00),('B',01),('C',02),('D',03),('E',04),('F',05),('G',06),('H',07),
('I',08),('J',09),('K',10),('L',11),('M',12),('N',13),('O',14),('P',15),
('Q',16),('R',17),('S',18),('T',19),('U',20),('V',21),('W',22),('X',23),
('Y',24),('Z',25),('2',26),('3',27),('4',28),('5',29),('6',30),('7',31);

CREATE TEMPORARY TABLE `_temp_base32_lookup2` LIKE `_temp_base32_lookup1`;
INSERT INTO `_temp_base32_lookup2` SELECT * FROM `_temp_base32_lookup1`;

CREATE TEMPORARY TABLE `_temp_base32_lookup3` LIKE `_temp_base32_lookup1`;
INSERT INTO `_temp_base32_lookup3` SELECT * FROM `_temp_base32_lookup1`;

CREATE TEMPORARY TABLE `_temp_base32_lookup4` LIKE `_temp_base32_lookup1`;
INSERT INTO `_temp_base32_lookup4` SELECT * FROM `_temp_base32_lookup1`;

CREATE TEMPORARY TABLE `_temp_base32_lookup5` LIKE `_temp_base32_lookup1`;
INSERT INTO `_temp_base32_lookup5` SELECT * FROM `_temp_base32_lookup1`;

CREATE TEMPORARY TABLE `_temp_base32_lookup6` LIKE `_temp_base32_lookup1`;
INSERT INTO `_temp_base32_lookup6` SELECT * FROM `_temp_base32_lookup1`;

CREATE TEMPORARY TABLE `_temp_base32_lookup7` LIKE `_temp_base32_lookup1`;
INSERT INTO `_temp_base32_lookup7` SELECT * FROM `_temp_base32_lookup1`;

CREATE TEMPORARY TABLE `_temp_base32_lookup8` LIKE `_temp_base32_lookup1`;
INSERT INTO `_temp_base32_lookup8` SELECT * FROM `_temp_base32_lookup1`;

CREATE TEMPORARY TABLE `_temp_totp_conversion`
(
    `original_key` varchar(100) not null default '',
    `remaining_key` varchar(100) not null default '',
    `totp_secret` varbinary(128) default null,
    primary key(`original_key`),
    index (`remaining_key`)
);

INSERT INTO `_temp_totp_conversion` (`original_key`) SELECT DISTINCT `token_key` FROM `account`;
UPDATE `_temp_totp_conversion` SET `remaining_key`=TRIM(TRAILING '=' FROM `original_key`),`totp_secret`='' WHERE `original_key`!='';

-- 8 base32 chars = 5 bytes
-- ...so after 12 iterations we're done
-- mysql doesn't let us do loops, so we have to do this manually (....mysql)
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 2
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 3
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 4
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 5
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 6
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 7
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 8
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 9
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 10
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 11
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- iteration 12
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
LEFT JOIN `_temp_base32_lookup8` look8 ON look8.`c`=SUBSTR(`remaining_key`,8,1)
SET `remaining_key`=SUBSTR(`remaining_key`,9),`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 35) | (look2.`v` << 30) | (look3.`v` << 25) | (look4.`v` << 20) | (look5.`v` << 15) | (look6.`v` << 10) | (look7.`v` << 5) | (look8.`v`)),10,16),10,'0')))
WHERE LENGTH(`remaining_key`) >= 8;

-- ok, now the only things left are trailing partial bytes
-- if the trailing block had 1 byte , we have xxxxx xxx00                               (strlen = 2)
-- if the trailing block had 2 bytes, we have xxxxx xxxyy yyyyy y0000                   (strlen = 4)
-- if the trailing block had 3 bytes, we have xxxxx xxxyy yyyyy yzzzz zzzz0             (strlen = 5)
-- if the trailing block had 4 bytes, we have xxxxx xxxyy yyyyy yzzzz zzzzw wwwww ww000 (strlen = 7)

-- 1 byte case
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
SET `remaining_key`='',`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 3) | (look2.`v` >> 2)),10,16),2,'0')))
WHERE LENGTH(`remaining_key`)=2;
-- 2 byte case
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
SET `remaining_key`='',`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 11) | (look2.`v` << 6) | (look3.`v` << 1) | (look4.`v` >> 4)),10,16),4,'0')))
WHERE LENGTH(`remaining_key`)=4;
-- 3 byte case
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
SET `remaining_key`='',`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 19) | (look2.`v` << 14) | (look3.`v` << 9) | (look4.`v` << 4) | (look5.`v` >> 1)),10,16),6,'0')))
WHERE LENGTH(`remaining_key`)=5;
-- 4 byte case
UPDATE `_temp_totp_conversion`
LEFT JOIN `_temp_base32_lookup1` look1 ON look1.`c`=SUBSTR(`remaining_key`,1,1)
LEFT JOIN `_temp_base32_lookup2` look2 ON look2.`c`=SUBSTR(`remaining_key`,2,1)
LEFT JOIN `_temp_base32_lookup3` look3 ON look3.`c`=SUBSTR(`remaining_key`,3,1)
LEFT JOIN `_temp_base32_lookup4` look4 ON look4.`c`=SUBSTR(`remaining_key`,4,1)
LEFT JOIN `_temp_base32_lookup5` look5 ON look5.`c`=SUBSTR(`remaining_key`,5,1)
LEFT JOIN `_temp_base32_lookup6` look6 ON look6.`c`=SUBSTR(`remaining_key`,6,1)
LEFT JOIN `_temp_base32_lookup7` look7 ON look7.`c`=SUBSTR(`remaining_key`,7,1)
SET `remaining_key`='',`totp_secret`=CONCAT(`totp_secret`,
    UNHEX(LPAD(CONV(((look1.`v` << 27) | (look2.`v` << 22) | (look3.`v` << 17) | (look4.`v` << 12) | (look5.`v` << 7) | (look6.`v` << 2) | (look7.`v` >> 3)),10,16),8,'0')))
WHERE LENGTH(`remaining_key`)=7;

-- assert that we actually converted everything properly
SET @mode := @@session.sql_mode;
SET SESSION sql_mode='STRICT_TRANS_TABLES';
CREATE TEMPORARY TABLE `_temp_assert_check` (`v` char(1) not null);
INSERT INTO `_temp_assert_check` SELECT CONV(MAX(LENGTH(`remaining_key`)+1),10,2) FROM `_temp_totp_conversion`;
SET SESSION sql_mode=@mode;

-- =================================================== --
-- BASE32 CONVERSION ENDS HERE                         --
-- (this is the other banner i promised you, so you    --
--  can stop skipping the unnecessarily complex stuff) --
-- =================================================== --

ALTER TABLE `account` ADD COLUMN `totp_secret` VARBINARY(128) DEFAULT NULL AFTER `s`;
UPDATE `account` a LEFT JOIN `_temp_totp_conversion` c ON a.`token_key`=c.`original_key` SET a.`totp_secret`=c.`totp_secret`;
ALTER TABLE `account` DROP COLUMN `token_key`;

COMMIT; -- safety gloves off
