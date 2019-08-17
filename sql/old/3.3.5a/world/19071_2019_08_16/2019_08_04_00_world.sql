-- quest pools no longer support nesting, but they also don't need it
DROP TABLE IF EXISTS `quest_pool_members`;
CREATE TABLE `quest_pool_members` (
  `questId` int(10) unsigned not null,
  `poolId` int(10) unsigned not null,
  `poolIndex` tinyint(2) unsigned not null COMMENT 'Multiple quests with the same index will always spawn together!',
  `description` varchar(255) default null,
  PRIMARY KEY (`questId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

CREATE TEMPORARY TABLE `_temp_pool_quests` (
  `sortIndex` int auto_increment not null,
  `questId` int(10) unsigned not null,
  `subPool` int(10) unsigned,
  `topPool` int(10) unsigned not null,
  `description` varchar(255) default null,
  PRIMARY KEY (`sortIndex`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- build a lookup table of questid <-> nested pool <-> toplevel pool
INSERT INTO `_temp_pool_quests` (`questId`,`subPool`,`topPool`,`description`)
SELECT pq.`entry` as `questId`, IF(pp.`poolSpawnId` is null, null, pq.`pool_entry`) as `subPool`, IFNULL(pp.`poolSpawnId`,pq.`pool_entry`) AS `topPool`, pq.`description`
FROM `pool_quest` as pq LEFT JOIN `pool_members` pp ON (pp.`type`=2) and (pp.`spawnId` = pq.`pool_entry`)
ORDER BY `topPool` ASC, `subPool` ASC;

-- delete any nested pools whose members we'll remove
DELETE FROM `pool_template` WHERE `entry` IN (SELECT DISTINCT `subPool` FROM `_temp_pool_quests` WHERE `subPool` is not null);
DELETE FROM `pool_members` WHERE `type`=2 AND `spawnId` IN (SELECT DISTINCT `subPool` FROM `_temp_pool_quests` WHERE `subPool` is not null);

-- ensure quests without a subPool have different subPool values
UPDATE `_temp_pool_quests` SET `subPool`=`sortIndex` WHERE `subPool` is null;

SET @pool_index = 0;
SET @last_pool = 0;
SET @last_subpool = 0;

-- poolIndex is chosen as follows:
--  *) if we're starting a new pool, the index is 0
--  *) if the preceding element had the same subpool, the index remains the same
--  *) if the preceding element had a different subpool, the index increases by 1
INSERT INTO `quest_pool_members` (`questId`, `poolId`, `poolIndex`, `description`)
SELECT
  `questId`,
  `topPool` as `poolId`,
  (CASE WHEN @last_subpool = `subPool` THEN @pool_index ELSE (@pool_index := (((@last_subpool := `subPool`) and 0) + (CASE WHEN @last_pool = `topPool` THEN @pool_index+1 ELSE ((@last_pool := `topPool`) and 0) END))) END) as `poolIndex`,
  `description`
FROM `_temp_pool_quests`;

-- drop the old table
DROP TABLE `pool_quest`;

DROP TABLE IF EXISTS `quest_pool_template`;
CREATE TABLE `quest_pool_template` (
  `poolId` mediumint(8) unsigned not null,
  `numActive` int(10) unsigned not null COMMENT 'Number of indices to have active at any time',
  `description` varchar(255) default null,
  PRIMARY KEY (`poolId`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- copy any quest pool templates over
INSERT INTO `quest_pool_template` (`poolId`, `numActive`, `description`)
SELECT DISTINCT pt.`entry`,pt.`max_limit`,pt.`description` FROM `quest_pool_members` qpm LEFT JOIN `pool_template` pt ON (qpm.`poolId` = pt.`entry`);

-- and delete them from the original table
DELETE pt FROM `pool_template` pt LEFT JOIN `quest_pool_template` qpt ON qpt.`poolId`=pt.`entry` WHERE qpt.`poolId` is not null;
