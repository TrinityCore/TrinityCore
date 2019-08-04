-- we will take the old implicit equal chance method and make it explicit

-- first, we'll manually fix the values that result in non-integral chances

-- these all have three zeros and two explicit 10% chances, we change these to 8/30 and 3/30 respectively
UPDATE `pool_members` SET `chance`=3 WHERE `chance`=10 AND `poolSpawnId` BETWEEN 4400 AND 4512;
UPDATE `pool_members` SET `chance`=8 WHERE `chance`=0 AND `poolSpawnId` BETWEEN 4400 AND 4512;

-- these have three zeros and one explicit 20% chance, we change it to 4/15 and 3/15
UPDATE `pool_members` SET `chance`=3 WHERE `chance`=20 AND `poolSpawnId` IN (32,38,62,78,133,134,135,138,139,140,143,149,326,332,335,336,337,338,339,340,341,342,343,344);
UPDATE `pool_members` SET `chance`=4 WHERE `chance`=0 AND `poolSpawnId` IN (32,38,62,78,133,134,135,138,139,140,143,149,326,332,335,336,337,338,339,340,341,342,343,344);

-- the batch convert script can fix the rest
CREATE TEMPORARY TABLE `_temp_num_equal_chanced` (
  `poolId` int(10) unsigned not null,
  `count` int(10) unsigned not null,
  PRIMARY KEY (`poolId`)
) ENGINE=MyISAM;

CREATE TEMPORARY TABLE `_temp_sum_explicit_chances` (
  `poolId` int(10) unsigned not null,
  `sum` double unsigned not null,
  PRIMARY KEY (`poolId`)
) ENGINE=MyISAM;

INSERT INTO `_temp_num_equal_chanced` (`poolId`,`count`)
SELECT `poolSpawnId`,count(*) FROM `pool_members` WHERE `chance`=0.0 GROUP BY `poolSpawnId`;

INSERT INTO `_temp_sum_explicit_chances` (`poolId`,`sum`)
SELECT `poolSpawnId`,sum(`chance`) FROM `pool_members` GROUP BY `poolSpawnId`;

UPDATE `pool_members` as pm
LEFT JOIN `_temp_num_equal_chanced` as eq ON pm.`poolSpawnId`=eq.`poolId`
LEFT JOIN `_temp_sum_explicit_chances` as ex ON pm.`poolSpawnId`=ex.`poolId`
SET pm.`chance` = (CASE WHEN ex.`sum`=0 THEN 1.0 ELSE ((100-ex.`sum`)/eq.`count`) END) WHERE pm.`chance`=0;
