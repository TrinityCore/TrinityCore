ALTER TABLE `creature_model_info`
ADD `hostileId` mediumint(8) DEFAULT '0' NOT NULL AFTER modelid_other_gender;

ALTER TABLE `pet_stats`
ADD `damage` FLOAT DEFAULT '0' NOT NULL AFTER TYPE;


