ALTER TABLE `character_talent`   
	ADD COLUMN `talentRank` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `talentId`;
