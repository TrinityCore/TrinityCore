DELETE FROM `conditions` WHERE `SourceEntry`=32146;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
(13,0,32146,0,18,1,18240,0,0,'','Spell Liquid Fire can only be cast at Sunspring Villager');
