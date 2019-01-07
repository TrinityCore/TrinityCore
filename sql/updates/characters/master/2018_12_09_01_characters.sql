DROP TABLE IF EXISTS `total_honor_at_honor_level`;
CREATE TABLE `total_honor_at_honor_level` (
  `HonorLevel` int(10) UNSIGNED NOT NULL,
  `Prestige0` int(10) UNSIGNED NOT NULL,
  `Prestige1` int(10) UNSIGNED NOT NULL,
  PRIMARY KEY (`HonorLevel`) 
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

INSERT INTO `total_honor_at_honor_level` VALUES
(0,0,0),(1,350,800),(2,700,1600),(3,1050,2400),(4,1400,3200),
(5,1750,4000),(6,2100,4800),(7,2450,5600),(8,2800,6400),(9,3150,7200),
(10,3500,8000),(11,3900,8850),(12,4300,9700),(13,4700,10550),(14,5100,11400),
(15,5500,12250),(16,5900,13100),(17,6300,13950),(18,6700,14800),(19,7100,15650),
(20,7500,16500),(21,7950,17400),(22,8400,18300),(23,8850,19200),(24,9300,20100),
(25,9750,21000),(26,10200,21900),(27,10650,22800),(28,11100,23700),(29,11550,24600),
(30,12000,25500),(31,12500,26450),(32,13000,27400),(33,13500,28350),(34,14000,29300),
(35,14500,30250),(36,15000,31200),(37,15500,32150),(38,16000,33100),(39,16500,34050),
(40,17000,35000),(41,17550,36000),(42,18100,37000),(43,18650,38000),(44,19200,39000),
(45,19750,40000),(46,20300,41000),(47,20850,42000),(48,21400,43000),(49,21950,44000);

-- first compensate for prestige levels above first
UPDATE `characters` SET `honor`=`honor`+44000*(`prestigeLevel`-1) WHERE `prestigeLevel`>0;
-- compensate for honor levels in prestige for characters above first prestige
UPDATE `characters` SET `honor`=`honor`+(SELECT th.`Prestige1` FROM `total_honor_at_honor_level` th WHERE th.`HonorLevel`=(`characters`.`honorLevel`-1)) WHERE `prestigeLevel`>0;
-- compensate for honor levels in first prestige level
UPDATE `characters` SET `honor`=`honor`+(SELECT th.`Prestige0` FROM `total_honor_at_honor_level` th WHERE th.`HonorLevel`=(`characters`.`honorLevel`-1)) WHERE `prestigeLevel`=0;

-- reset honor levels, will be recalculated from refunded honor at first login (and grant achievements)
UPDATE `characters` SET `honorLevel`=1;

ALTER TABLE `characters` DROP `prestigeLevel`;
DROP TABLE IF EXISTS `total_honor_at_honor_level`;
