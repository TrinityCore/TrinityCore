-- Spell Place Kil'sorrow Banner can not only be cast on Warmaul Ogres
DELETE FROM `conditions` WHERE `SourceEntry` IN (32314) AND `ConditionValue2` IN (17138,18064);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,32314,0,18,1,17138,0,0,'',"Spell Place Kil'sorrow Banner can not only be cast on Warmaul Ogres"), -- Warmaul Reaver
(13,0,32314,1,18,1,18064,0,0,'',"Spell Place Kil'sorrow Banner can not only be cast on Warmaul Ogres"); -- Warmaul Shaman
