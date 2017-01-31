-- DB/Item: Sealed Tome
DELETE FROM `gameobject_loot_template` WHERE `Entry`=18509;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(18509,1054,1054,100,0,1,1,1,1,NULL);

DELETE FROM `reference_loot_template` WHERE `Entry`=1054;
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(1054,23864,0,0,0,1,1,1,1,NULL), -- Torment of the Worgen
(1054,23857,0,0,0,1,1,1,1,NULL), -- Legacy of the Mountain King
(1054,23862,0,0,0,1,1,1,1,NULL), -- Redemption of the Fallen
(1054,23865,0,0,0,1,1,1,1, NULL); -- Wrath of the Titans

DELETE FROM `conditions` WHERE `SourceEntry` IN (30562, 30557, 30550, 30567) AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `Comment`) VALUES
(17,0,30562,0,0,23,0,3457,0,0,0,0,0,'Legacy of the Mountain King needs area 3457'),
(17,0,30557,0,0,23,0,3457,0,0,0,0,0,'Wrath of the Titans needs area 3457'),
(17,0,30550,0,0,23,0,3457,0,0,0,0,0,'Redemption of the Fallen needs area 3457'),
(17,0,30567,0,0,23,0,3457,0,0,0,0,0,'Torment of the Worgen needs area 3457');
