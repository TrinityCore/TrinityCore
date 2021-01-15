DELETE FROM `corpse` WHERE `corpseType`=0;

DROP PROCEDURE IF EXISTS `CheckCorpseData`;

DELIMITER $$

CREATE PROCEDURE CheckCorpseData()
BEGIN
  DECLARE max_corpses_per_player int;
  SELECT MAX(`counts`) FROM (SELECT COUNT(`corpseGuid`) AS `counts` FROM `corpse` GROUP BY `guid`) AS `counted` INTO max_corpses_per_player;

  IF max_corpses_per_player > 50000 THEN
    TRUNCATE `corpse`;
  END IF;

END$$
DELIMITER ;

CALL CheckCorpseData();
DROP PROCEDURE `CheckCorpseData`;

ALTER TABLE `corpse`
  DROP `corpseGuid`,
  DROP INDEX `idx_player`,
  ADD PRIMARY KEY (`guid`);

ALTER TABLE `corpse_phases`
  DROP PRIMARY KEY,
  DROP `Guid`,
  DROP `CorpseType`,
  DROP `Time`,
  CHANGE `OwnerGuid` `OwnerGuid` bigint(20) unsigned NOT NULL DEFAULT '0' FIRST,
  ADD PRIMARY KEY (`OwnerGuid`,`PhaseId`);
