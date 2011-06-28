DELETE FROM `conditions` WHERE `SourceEntry`=24311 AND `SourceTypeOrReferenceId`=13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
(13,0,24311,0,18,1,11380,0,0,'','Powerful Healing Ward - Jin\'do the Hexxer'),
(13,0,24311,0,18,1,14825,0,0,'','Powerful Healing Ward - Withered Mistress'),
(13,0,24311,0,18,1,14986,0,0,'','Powerful Healing Ward - Shade of Jin\'do'),
(13,0,24311,0,18,1,14826,0,0,'','Powerful Healing Ward - Sacrificed Troll'),
(13,0,24311,0,18,1,14883,0,0,'','Powerful Healing Ward - Voodoo Slave');
