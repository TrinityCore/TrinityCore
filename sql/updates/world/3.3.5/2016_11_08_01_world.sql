-- 
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (6066,18176) AND `source_type`= 0;
UPDATE `creature_template` SET `AIName`="", `InhabitType`=`InhabitType`|8 WHERE `entry` IN (6066,18176);
DELETE FROM `creature_template_addon` WHERE `entry`=6066;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES (6066,'31982');
UPDATE `creature_template_addon` SET `auras`='31982' WHERE `entry` IN (18176);
