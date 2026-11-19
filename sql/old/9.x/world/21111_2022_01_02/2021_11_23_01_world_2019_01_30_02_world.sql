-- set Rooted state for Blockade Cannon
DELETE FROM `creature_template_movement` WHERE `CreatureId`=23771;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`) VALUES
(23771, 1, 1, 0, 1);

UPDATE `creature_template` SET `flags_extra`=64 WHERE `entry` IN (23755, 23767, 23771);
