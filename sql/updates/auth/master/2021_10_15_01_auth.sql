DROP TABLE IF EXISTS `battle_pet_declinedname`;
CREATE TABLE `battle_pet_declinedname` (
  `guid` bigint(20) NOT NULL,
  `genitive` varchar(12) NOT NULL DEFAULT '',
  `dative` varchar(12) NOT NULL DEFAULT '',
  `accusative` varchar(12) NOT NULL DEFAULT '',
  `instrumental` varchar(12) NOT NULL DEFAULT '',
  `prepositional` varchar(12) NOT NULL DEFAULT '',
  PRIMARY KEY (`guid`),
  CONSTRAINT fk_battle_pet__battle_pet_declinedname FOREIGN KEY (`guid`) REFERENCES `battle_pets` (`guid`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
