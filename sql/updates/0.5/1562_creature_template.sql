ALTER TABLE `creature_template` 
    ADD `mingold` int(30) unsigned NOT NULL default '0' AFTER `spell4` ,
    ADD `maxgold` int(30) unsigned NOT NULL default '0' AFTER `mingold`; 