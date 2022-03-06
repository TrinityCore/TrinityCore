-- Add CREATURE_FLAG_EXTRA_NO_COMBAT to jewelcrafting stone statues & root them, taken from CreatureDifficulty
UPDATE `creature_template` SET `flags_extra` = `flags_extra` | 0x00002000 WHERE `entry` IN (18372,18734,18735,18736,18737,18738);
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (18372,18734,18735,18736,18737,18738);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`) VALUES
(18372,1,1,0,1,0,0),
(18734,1,1,0,1,0,0),
(18735,1,1,0,1,0,0),
(18736,1,1,0,1,0,0),
(18737,1,1,0,1,0,0),
(18738,1,1,0,1,0,0);
