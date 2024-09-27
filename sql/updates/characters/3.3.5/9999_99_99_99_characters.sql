-- Remove unsigned floats in characters database
ALTER TABLE `character_stats` MODIFY `blockPct` float NOT NULL DEFAULT '0';
ALTER TABLE `character_stats` MODIFY `dodgePct` float NOT NULL DEFAULT '0';
ALTER TABLE `character_stats` MODIFY `parryPct` float NOT NULL DEFAULT '0';
ALTER TABLE `character_stats` MODIFY `critPct` float NOT NULL DEFAULT '0';
ALTER TABLE `character_stats` MODIFY `rangedCritPct` float NOT NULL DEFAULT '0';
ALTER TABLE `character_stats` MODIFY `spellCritPct` float NOT NULL DEFAULT '0';
