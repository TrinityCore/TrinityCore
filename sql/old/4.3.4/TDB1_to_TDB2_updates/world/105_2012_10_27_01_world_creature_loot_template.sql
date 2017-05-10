DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=51315;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`Scriptname`,`Comment`) VALUES
-- Lich King 10N
(1,36597,51315,0,1,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,36597,51315,0,1,3,0,49623,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,36597,51315,0,1,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
(1,36597,51315,0,1,14,0,24914,0,0,0,0,'' , 'Sealed Chest will drop only if the player has not completed the quest Personal Property'),
-- Lich King 25N
(1,39166,51315,0,1,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,1,3,0,49623,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,1,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
(1,39166,51315,0,1,14,0,24914,0,0,0,0,'' , 'Sealed Chest will drop only if the player has not completed the quest Personal Property'),
-- Lich King 10H
(1,39167,51315,0,1,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39167,51315,0,1,3,0,49623,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39167,51315,0,1,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
(1,39167,51315,0,1,14,0,24914,0,0,0,0,'' , 'Sealed Chest will drop only if the player has not completed the quest Personal Property'),
-- Lich King 25H
(1,39168,51315,0,1,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,1,3,0,49623,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,1,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
(1,39168,51315,0,1,14,0,24914,0,0,0,0,'' , 'Sealed Chest will drop only if the player has not completed the quest Personal Property');
