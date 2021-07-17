-- Shards of Ahune should drop always
UPDATE `gameobject_loot_template` SET `Chance` = 100 WHERE `Item` = 35723 AND `Reference` = 0;
