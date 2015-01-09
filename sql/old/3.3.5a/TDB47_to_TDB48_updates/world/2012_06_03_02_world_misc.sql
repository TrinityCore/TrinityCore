-- Misc db updates
DELETE FROM `creature_template_addon` WHERE `entry`=30476;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES (30476,'56852');
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry` IN (30476,30599,30640,32193,30343);
-- fix Sholazar Tickbird InhabitType
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=28093;
