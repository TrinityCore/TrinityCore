-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=5818;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=14437;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 5818, 0, 0, 0, 15, 0, 256, 0, 0, 0, 0, 0, "", "Show gossip option if player is a Warlock"),
(23, 14437, 18629, 0, 0, 47, 0, 7631, 66, 0, 0, 0, 0, "", "Item Black Lodestone can be bought if player has quest 'Dreadsteed of Xoroth' complete or rewarded"),
(23, 14437, 18663, 0, 0, 47, 0, 7631, 66, 0, 0, 0, 0, "", "Item J'eevee's Jar can be bought if player has quest 'Dreadsteed of Xoroth' complete or rewarded"),
(23, 14437, 18670, 0, 0, 47, 0, 7631, 66, 0, 0, 0, 0, "", "Item Xorothian Glyphs can be bought if player has quest 'Dreadsteed of Xoroth' complete or rewarded");
