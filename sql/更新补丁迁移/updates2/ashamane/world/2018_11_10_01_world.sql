DROP TABLE IF EXISTS `creature_summoner_entry`;
CREATE TABLE `creature_summoner_entry`(
    `CreatureId` INT(10) UNSIGNED NOT NULL,
    `SummonerVisibleCreatureId` INT(10) UNSIGNED NOT NULL,
    PRIMARY KEY (`CreatureId`)); 

INSERT INTO `creature_summoner_entry` (`CreatureId`, `SummonerVisibleCreatureId`) VALUES (124311, 121239); 
