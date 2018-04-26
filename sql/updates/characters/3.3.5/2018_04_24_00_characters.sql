--
UPDATE `worldstates` SET `value`=UNIX_TIMESTAMP() WHERE `entry`=20001 AND `value` < UNIX_TIMESTAMP();
