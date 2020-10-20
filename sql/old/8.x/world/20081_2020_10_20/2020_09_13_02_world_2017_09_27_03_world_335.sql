-- 
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|64 WHERE `entry`=17612;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (17190, 17191, 17192, 17475) AND `ConditionTypeOrReference` IN (9, 47) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 17190, 0, 0, 47, 0, 9595, 10, 0, 0, 0, 0, "", "Smart Event 0 for creature Siltfin Murloc only executes if player has quest 'Control' incomplete or complete AND"),
(22, 4, 17191, 0, 0, 47, 0, 9595, 10, 0, 0, 0, 0, "", "Smart Event 3 for creature Siltfin Oracle only executes if player has quest 'Control' incomplete or complete AND"),
(22, 3, 17192, 0, 0, 47, 0, 9595, 10, 0, 0, 0, 0, "", "Smart Event 2 for creature Siltfin Hunter only executes if player has quest 'Control' incomplete or complete AND"),
(22, 1, 17475, 0, 0, 47, 0, 9595, 10, 0, 0, 0, 0, "", "Smart Event 0 for creature Murgurgula only executes if player has quest 'Control' incomplete or complete AND");
