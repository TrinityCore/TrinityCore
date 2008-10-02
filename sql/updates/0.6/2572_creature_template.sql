ALTER TABLE `creature_template`
    CHANGE  `modelid` `modelid_m` int(11) unsigned default '0',
    ADD `modelid_f` int(11) unsigned default '0' AFTER `modelid_m`;
