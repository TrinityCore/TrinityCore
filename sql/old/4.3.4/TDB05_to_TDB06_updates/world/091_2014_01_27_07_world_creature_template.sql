--
UPDATE `creature_template` SET `faction_A` = 83, `faction_H` = 83 WHERE `entry` = 38095; -- Sniffs confirm 37034 faction 83.
UPDATE `creature_template` SET `minlevel`=80, `maxlevel`=80, `faction_A`=83, `faction_H`=83 WHERE `entry`=35407; -- Sniffs confirm 34918 faction 83, copy level from normal mode.
