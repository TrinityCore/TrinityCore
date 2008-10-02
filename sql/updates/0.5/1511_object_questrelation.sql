ALTER TABLE `object_questrelation` 
    RENAME TO `gameobject_questrelation`,
    DROP PRIMARY KEY,
    DROP `Id`,
    CHANGE `objectId` `id` int(11) unsigned NOT NULL default '0',
    CHANGE `questId` `quest` int(11) unsigned NOT NULL default '0' COMMENT 'Quest Identifier' AFTER `id`,
    ADD PRIMARY KEY  (`id`,`quest`);
