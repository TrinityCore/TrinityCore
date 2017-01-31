-- "A Recipe For Death" quest chain was removed in 4.0.3a
-- Following items, related to the quests, are no longer needed in loot templates
-- Grizzled Bear Heart (3253), Skittering Blood (3254), Berard's Journal (3255), Lake Skulker Moss (3256), Lake Creeper Moss (3257), Hardened Tumor (3258)
-- http://www.wowpedia.org/Quest:A_Recipe_For_Death
DELETE FROM `creature_loot_template` WHERE `item` IN (3253,3254,3256,3257,3258);
DELETE FROM `gameobject_loot_template` WHERE `entry`=1698 and`item`=3255;
UPDATE `gameobject_template` SET `questItem1`=0 WHERE `entry`=1594;
DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (447,450,451);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,447,0,0,0,'Disable quest A Recipe For Death (Removed in 4.0.3a)'),
(1,450,0,0,0,'Disable quest A Recipe For Death (Removed in 4.0.3a)'),
(1,451,0,0,0,'Disable quest A Recipe For Death (Removed in 4.0.3a)');
