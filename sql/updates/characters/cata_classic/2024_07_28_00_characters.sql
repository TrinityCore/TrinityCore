ALTER TABLE `character_glyphs` 
ADD COLUMN `glyphSlot` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `talentGroup`,
DROP PRIMARY KEY,
ADD PRIMARY KEY (`guid`, `talentGroup`, `glyphSlot`, `glyphId`);
