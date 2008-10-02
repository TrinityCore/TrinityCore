ALTER TABLE `areatrigger_template`
    ADD COLUMN `required_item` int(11) unsigned NOT NULL default '0' AFTER `required_level`;
