-- Keep only the highest guid PvE or PvP (not bones) corpse per player guid
DELETE c FROM `corpse` c LEFT JOIN
(
    SELECT MAX(`corpseGuid`) AS id
    FROM `corpse`
    WHERE `corpseType` IN (1,2)
    GROUP BY `guid`
) corpsetemp
ON c.`corpseGuid` = corpsetemp.`id`
WHERE corpsetemp.`id` IS NULL;

-- Remove corpseGUID and set key to player guid
ALTER TABLE `corpse`
  DROP `corpseGuid`,
  DROP INDEX `idx_player`,
  ADD PRIMARY KEY (`guid`);
