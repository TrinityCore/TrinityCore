-- Arcanist Vandril gossip menu changes when quest "Delivery to Tranquillien" is active, when "Suncrown Village" is active, when Goldenmist Village is active and when "Windrunner Village" is active and after it is completed.
-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `MenuID`=7153 AND `TextID` IN (8561,8425,8426);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7153,8425,0),
(7153,8426,0),
(7153,8561,0);

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7153;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7153,8561,0,0,47,0,9148,10,0,0,0,0,"","Show gossip dialog text 8561 if Quest 'Delivery to Tranquillien' is taken (active)"),
(14,7153,8426,0,0,8,0,9140,0,0,0,0,0,"","Gossip text 8226 requires quest 'Windrunner Village' rewarded"),
(14,7153,8425,0,0,47,0,9138,10,0,0,0,0,"","Show gossip dialog text 8425 if Quest 'Suncrown Village' is taken (active)"),
(14,7153,8425,0,1,47,0,9139,10,0,0,0,0,"","Show gossip dialog text 8425 if Quest 'Goldenmist Village' is taken (active)"),
(14,7153,8425,0,2,47,0,9140,10,0,0,0,0,"","Show gossip dialog text 8425 if Quest 'Windrunner Village' is taken (active)");
