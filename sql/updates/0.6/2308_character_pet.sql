ALTER TABLE `character_pet`
    DROP `name`,
    ADD `loyalty` int(11) unsigned NOT NULL default '1',
    ADD `trainpoint` int(11) unsigned NOT NULL default '0';
