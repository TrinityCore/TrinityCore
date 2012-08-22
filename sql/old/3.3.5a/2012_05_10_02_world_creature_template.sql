-- fix creauture_template loot id for infinite corruptor. could have sworn this was already in the db.
UPDATE `creature_template` SET `lootid` = 0 WHERE `entry` IN (32313,32273);
