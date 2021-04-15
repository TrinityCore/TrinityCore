ALTER TABLE `hotfix_blob` ADD COLUMN `VerifiedBuild` INT(11) NOT NULL DEFAULT '0' AFTER `Blob`;
ALTER TABLE `hotfix_data` ADD COLUMN `VerifiedBuild` INT(11) NOT NULL DEFAULT '0' AFTER `Deleted`;
