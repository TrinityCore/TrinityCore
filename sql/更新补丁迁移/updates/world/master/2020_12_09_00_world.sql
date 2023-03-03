ALTER TABLE `gameobject_template` ADD `ContentTuningId` int(11) NOT NULL DEFAULT '0' AFTER `Data33`;
ALTER TABLE `gameobject_template` DROP `RequiredLevel`;
