/* Characters_script.sql INSC. Myendras
 * Myendras SQL script
 * Last Update: Saqirmdev
 * Thanks: Phailure, Saqirmdev
 */ 


DROP TABLE IF EXISTS `fake_items`;
CREATE TABLE `fake_items` (
  `guid` int(11) NOT NULL,
  `fakeEntry` int(11) NOT NULL,
  PRIMARY KEY (`guid`)
);