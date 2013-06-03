-- Spell Conditions for spell Necromantic Power 69347
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=69347;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,69347,0,31,3,37496,0,0,'','Spell 69347 targets entry 37496'),
(13,1,69347,1,31,3,37497,0,0,'','Spell 69347 targets entry 37497'),
(13,1,69347,2,31,3,37498,0,0,'','Spell 69347 targets entry 37498'),
(13,1,69347,3,31,3,37584,0,0,'','Spell 69347 targets entry 37584'),
(13,1,69347,4,31,3,37587,0,0,'','Spell 69347 targets entry 37587'),
(13,1,69347,5,31,3,37588,0,0,'','Spell 69347 targets entry 37588');

-- Spell Conditions for spell Shriek of the Highborne 70512
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=70512;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,70512,3,31,3,37584,0,0,'','Spell 70512 targets entry 37584'),
(13,1,70512,4,31,3,37587,0,0,'','Spell 70512 targets entry 37587'),
(13,1,70512,5,31,3,37588,0,0,'','Spell 70512 targets entry 37588');

-- Spell Conditions for spell Empowered Blizzard 70130
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=70130;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,70130,0,31,3,37496,0,0,'','Spell 70130 targets entry 37496'),
(13,1,70130,1,31,3,37497,0,0,'','Spell 70130 targets entry 37497'),
(13,1,70130,2,31,3,37498,0,0,'','Spell 70130 targets entry 37498');
