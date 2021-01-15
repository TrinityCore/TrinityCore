--
-- Removed useless conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62290,62307,62357,62489,62635);
-- Adjusted incorrect conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62363,65044,65045);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition` ,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,2,62363,0,0,31,0,3,33214,0,0,0,'','Flame Leviathan - Anti-Air Rocket'),
(13,1,65044,0,0,32,0,0x18, 0,0,0,0,'','Flame Leviathan - Flames'), -- should hit everything
(13,2,65044,0,0,31,0,3,33090,0,0,0,'','Flame Leviathan - Flames'),
(13,1,65045,0,0,32,0,0x18, 0,0,0,0,'','Flame Leviathan - Flames'), -- should hit everything
(13,2,65045,0,0,31,0,3,33090,0,0,0,'','Flame Leviathan - Flames');
