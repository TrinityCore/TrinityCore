DELETE FROM `gameobject_loot_template` WHERE `entry`=24524 AND `item`=52676;
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(24524,52676,100,1,0,1,1);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=4 AND `SourceGroup`=24524 AND `SourceEntry`=52676;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(4,24524,52676,0,0,1,0,72221,0,0,0,0,0,'','Loot Cache of the Ley-Guardian only when aura Luck of the Draw applied');
