DELETE FROM `creature_loot_template` WHERE `entry` IN (36597, 39167) AND `Item`= 51315; -- Delete Sealed Chest from 10 difficulties loot list
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceEntry`=51315;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`Scriptname`,`Comment`) VALUES
-- Lich King 25N
(1,39166,51315,0,0,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,0,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,0,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39166,51315,0,0,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
--
(1,39166,51315,0,1,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,1,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,1,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39166,51315,0,1,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
--
(1,39166,51315,0,2,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,2,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,2,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39166,51315,0,2,8,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" rewarded'),
--
(1,39166,51315,0,3,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,3,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,3,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39166,51315,0,3,8,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" rewarded'),

--
(1,39166,51315,0,4,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,4,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,4,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39166,51315,0,4,28,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" Completed'),

(1,39166,51315,0,5,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39166,51315,0,5,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39166,51315,0,5,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39166,51315,0,5,28,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" Completed'),
-- Lich King 25H
(1,39168,51315,0,0,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,0,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,0,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39168,51315,0,0,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
--
(1,39168,51315,0,1,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,1,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,1,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39168,51315,0,1,9,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" in their quest log'),
--
(1,39168,51315,0,2,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,2,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,2,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39168,51315,0,2,8,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" rewarded'),
--
(1,39168,51315,0,3,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,3,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,3,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39168,51315,0,3,8,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" rewarded'),
--
(1,39168,51315,0,4,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,4,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,4,28,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log completed'),
(1,39168,51315,0,4,28,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" Completed'),
--
(1,39168,51315,0,5,2,0,51315,1,1,1,0 ,'' , 'Sealed Chest will drop only if the player doesn''t have it already'),
(1,39168,51315,0,5,3,0,49623,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player is wielding Shadowmourne'),
(1,39168,51315,0,5,8,0,24914,0,0,1,0 ,'' , 'Sealed Chest will drop only if the player hasn''t "Personal Property" in their quest log Rewarded'),
(1,39168,51315,0,5,28,0,24748,0,0,0,0 ,'' , 'Sealed Chest will drop only if the player has "The Lich King''s Last Stand" Completed');
