UPDATE `character_queststatus` SET `rewarded`='1' WHERE `completed_once`='1';
ALTER TABLE `character_queststatus` DROP `completed_once`;