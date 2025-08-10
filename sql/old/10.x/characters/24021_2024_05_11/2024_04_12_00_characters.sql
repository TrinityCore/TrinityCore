ALTER TABLE `item_instance` ADD `createTime` bigint NOT NULL DEFAULT '0' AFTER `playedTime`;

UPDATE `item_instance` SET `createTime` = COALESCE(
  (SELECT LEAST(c.`logout_time`, GREATEST(c.`createTime`,  c.`logout_time` -
    ((c.`totaltime`-`playedTime`)
	/ GREATEST(c.`totaltime`, 1)
	* (c.`logout_time`-c.`createTime`)))) FROM `characters` c WHERE c.`guid`=`owner_guid`),
	UNIX_TIMESTAMP()
);
