ALTER TABLE `characters` CHANGE `talentTree` `talentTree` varchar(10) NOT NULL DEFAULT '0 0 ' AFTER `resettalents_time`;
UPDATE `characters` SET `talentTree`='0 0 ';
