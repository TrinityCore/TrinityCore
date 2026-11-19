DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9456;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,9456,0,0,0,9,0,12132,0,0,0,0,'','Koltira Deathweaver show gossip option if player has quest 12132'),
(15,9456,0,0,0,1,0,47740,0,0,1,0,'','Koltira Deathweaver show gossip option if player has not aura World of Shadows');
