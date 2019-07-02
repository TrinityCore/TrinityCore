-- 
UPDATE `creature` SET `position_x`=4552.66992, `position_y`= -1322.802979, `position_z`= 156.710373, `Orientation`=1.908695,`MovementType`=0, `spawndist`=0 WHERE `guid`=102100;
UPDATE `creature` SET `position_x`=4576.567871, `position_y`= -1362.49987, `position_z`= 156.881149,`MovementType`=0, `spawndist`=0 WHERE `guid`=102098;
UPDATE `creature_addon` SET `emote`=398 WHERE `guid` IN (102099,102098,102100);
UPDATE `creature_template` SET `unit_flags` = 32768, `flags_extra`=`flags_extra`|2 WHERE `entry` = 26965 ;
UPDATE `creature` SET `unit_flags`=0 WHERE `guid` IN (103527,103528,103531,103532,103533,52283,52284,52288,52293,52296,52297,52300,52304,52310,52312);
UPDATE `creature` SET `unit_flags`=33536, `dynamicflags`=0 WHERE `guid` IN (103482,103483,103485,103488,103563,103564);
UPDATE `creature_template_addon` SET `auras`="" WHERE `entry` IN (26965);
DELETE FROM `creature_addon` WHERE `guid` IN (103482,103483,103485,103488,103563,103564,103527,103528,103531,103532,103533,52283,52284,52288,52293,52296,52297,52300,52304,52310,52312);
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(103482, '31261'),
(103483, '31261'),
(103485, '31261'),
(103488, '31261'),
(103563, '31261'),
(103564, '31261');
