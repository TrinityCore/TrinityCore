ALTER TABLE `mail_items`
    ADD COLUMN `id` int(10) unsigned NOT NULL DEFAULT '0' FIRST;
    

ALTER TABLE `mail`
    ADD COLUMN `state` int(10) unsigned NOT NULL DEFAULT '0' AFTER `checked`;