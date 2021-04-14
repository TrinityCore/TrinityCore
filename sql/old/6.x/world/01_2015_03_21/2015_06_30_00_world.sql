ALTER TABLE `creature_questitem` ADD COLUMN `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0';
ALTER TABLE `gameobject_questitem` ADD COLUMN `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0';

UPDATE `creature_questitem` A INNER JOIN `creature_template` B ON A.`CreatureEntry`=B.`entry` SET A.`VerifiedBuild`=B.`VerifiedBuild`;
UPDATE `gameobject_questitem` A INNER JOIN `gameobject_template` B ON A.`GameObjectEntry`=B.`entry` SET A.`VerifiedBuild`=B.`VerifiedBuild`;
