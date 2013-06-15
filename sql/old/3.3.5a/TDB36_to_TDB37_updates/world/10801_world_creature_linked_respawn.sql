ALTER table `creature_linked_respawn`
RENAME TO `linked_respawn`,
ADD COLUMN linkType tinyint(3) UNSIGNED NOT NULL DEFAULT '0',
DROP PRIMARY KEY,
ADD PRIMARY KEY(`guid`, `linkType`);
