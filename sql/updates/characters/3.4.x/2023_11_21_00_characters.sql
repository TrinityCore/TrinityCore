ALTER TABLE `character_glyphs`   
	ADD COLUMN `glyphSlot` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `talentGroup`,
	CHANGE `glyphId` `glyphId` SMALLINT UNSIGNED DEFAULT 0 NOT NULL  AFTER `glyphSlot`, 
  DROP PRIMARY KEY,
  ADD PRIMARY KEY (`guid`, `talentGroup`, `glyphSlot`, `glyphId`);
