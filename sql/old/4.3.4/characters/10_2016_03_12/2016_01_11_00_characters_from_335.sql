-- Keep only the highest guid PvE or PvP (not bones) corpse per player guid
DELETE c FROM `corpse` c LEFT JOIN
(
    SELECT MAX(`guid`) AS id
    FROM `corpse`
    WHERE `corpseType` IN (1,2)
    GROUP BY `guid`
) corpsetemp
ON c.`guid` = corpsetemp.`id`
WHERE corpsetemp.`id` IS NULL;

ALTER TABLE `corpse_phases`
  DROP PRIMARY KEY,
  DROP `Guid`,
  DROP `CorpseType`,
  DROP `Time`,
  CHANGE `OwnerGuid` `OwnerGuid` int(10) unsigned NOT NULL DEFAULT '0' FIRST,
  ADD PRIMARY KEY (`OwnerGuid`, `PhaseId`);
