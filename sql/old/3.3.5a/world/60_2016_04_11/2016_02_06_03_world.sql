-- 
-- Warsong Recruitment Officer gives dublicate quest
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND (`SourceEntry`=11586 OR `SourceEntry`=11585);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES 
(19, 11586, 14, 10172, "Accept quest 11586 - Quest 10172 needs to be incomplete"),
(19, 11585, 8, 10172, "Accept quest 11585 - Quest 10172 needs to be rewarded");
