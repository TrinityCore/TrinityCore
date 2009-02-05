ALTER TABLE `characters`
    ADD `latency` int(11) unsigned NOT NULL default '0' AFTER `taxi_path`;