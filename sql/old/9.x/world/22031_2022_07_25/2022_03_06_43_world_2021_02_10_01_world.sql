--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 4 AND `SourceGroup` = 13574 AND `SourceEntry` = 12812;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(4,13574,12812,0,0,7,0,164,275,0,0,0,0,"","Group 0: Item 'Unfired Plate Gauntlets' can be looted if player does have Blacksmithing with skill level 275");

UPDATE `gameobject_loot_template` SET `QuestRequired` = 0 WHERE `Item` = 12812 AND `Reference` = 0;
