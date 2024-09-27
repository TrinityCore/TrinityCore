-- Remove unsigned floats in characters database
ALTER TABLE `blockPct` MODIFY `population` float NOT NULL DEFAULT '0';
ALTER TABLE `dodgePct` MODIFY `population` float NOT NULL DEFAULT '0';
ALTER TABLE `parryPct` MODIFY `population` float NOT NULL DEFAULT '0';
ALTER TABLE `critPct` MODIFY `population` float NOT NULL DEFAULT '0';
ALTER TABLE `rangedCritPct` MODIFY `population` float NOT NULL DEFAULT '0';
ALTER TABLE `spellCritPct` MODIFY `population` float NOT NULL DEFAULT '0';
