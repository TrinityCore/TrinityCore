-- 
DELETE FROM `conditions` WHERE `SourceEntry` = 56099 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56099,0,0,31,0,3,30169,0,0,0,'','Essence of Ice target Smoldering Scrap Bunny');

DELETE FROM `creature` WHERE `guid` IN (116640, 116641, 116642); -- duplicated spawns
