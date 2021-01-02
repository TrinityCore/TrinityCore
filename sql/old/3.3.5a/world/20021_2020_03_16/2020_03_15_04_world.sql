-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=28519 AND `SourceEntry` IN (38660,38673);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=12631;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1, 28519, 38660, 0, 0, 9, 0, 12238, 0, 0, 0, 0, 0, '', 'show itemloot if player has quest Cleansing Drak\'Tharon taken'),
(1, 28519, 38660, 0, 1, 28, 0, 12238, 0, 0, 0, 0, 0, '', 'show itemloot if player has quest Cleansing Drak\'Tharon completed'),
(1, 28519, 38660, 0, 2, 14, 0, 12238, 0, 0, 0, 0, 0, '', 'show itemloot if player has quest Cleansing Drak\'Tharon none'),
(1, 28519, 38673, 0, 0, 8, 0, 12238, 0, 0, 0, 0, 0, '', 'show itemloot if player has quest Cleansing Drak\'Tharon Rewarded'),
(1, 28519, 38673, 0, 0, 2, 0, 38660, 1, 1, 1, 0, 0, '', 'show itemloot if player Doesnt have the item 38660'),
(19, 0, 12631, 0, 0, 8, 0, 12238, 0, 0, 1, 0, 0, '', 'The quest An Invitation, of Sorts... requires Cleansing Drak\'Tharon Rewarded');
