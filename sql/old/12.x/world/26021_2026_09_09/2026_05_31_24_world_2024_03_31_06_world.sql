-- Farstrider Solanna's gossip menu text changes when the quest "Attack on Zeb'Tela" is active and changes again after it has been turned in. It allso changes when the quest "Assault on Zeb'Nowa" is rewarded
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7253 AND `TextID` IN (8570,8571,8572);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7253,8570,0),
(7253,8571,0),
(7253,8572,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7253;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7253,8569,0,0,47,0,9276,10,0,1,0,0,"","Show gossip dialog text 8569  if quest 'Attack on Zeb'Tela' (9276) is NOT taken"),
(14,7253,8570,0,0,47,0,9276,10,0,0,0,0,"","Show gossip dialog text 8570 if quest 'Attack on Zeb'Tela' (9276) is taken (active)"),
(14,7253,8571,0,0,8,0,9276,0,0,0,0,0,"","Gossip text 8571 requires quest 'Attack on Zeb'Tela' (9276) rewarded"),
(14,7253,8572,0,0,8,0,9277,0,0,0,0,0,"","Gossip text 8572 requires quest 'Attack on Zeb'Nowa' (9277) rewarded");
