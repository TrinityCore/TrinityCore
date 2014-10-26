ALTER TABLE `creature_template` CHANGE `name` `name` CHAR(200) NOT NULL DEFAULT '0';
ALTER TABLE `creature_template` CHANGE `femaleName` `femaleName` CHAR(200) NOT NULL;
ALTER TABLE `creature_template` CHANGE `subname` `subname` CHAR(200);

UPDATE `creature_template` SET `name`='Gorgrond Smokebelcher Depot NPC "Far From Invulnerable" Commander Rakish skewered Quest Kill Credit [NEVER SPAWNED]' WHERE `entry`=74403;
UPDATE `creature_template` SET `name`='Gorgrond Smokebelcher Depot NPC "Far From Invulnerable" Blademaster Kroga skewered Quest Kill Credit [NEVER SPAWNED]' WHERE `entry`=74674;
UPDATE `creature_template` SET `name`='Gorgrond Smokebelcher Depot NPC "Far From Invulnerable" Weaponsmith Garloc skewered Quest Kill Credit [NEVER SPAWNED]' WHERE `entry`=76435;
