ALTER TABLE character_social
  CHANGE COLUMN `note` `note` varchar(48) NOT NULL DEFAULT '' COMMENT 'Friend Note';
