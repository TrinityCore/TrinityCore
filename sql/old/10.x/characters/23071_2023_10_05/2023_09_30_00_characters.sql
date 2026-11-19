ALTER TABLE `character_stats`
  ADD `mastery` float NOT NULL DEFAULT '0' AFTER `resilience`,
  ADD `versatility` int NOT NULL DEFAULT '0' AFTER `mastery`;
