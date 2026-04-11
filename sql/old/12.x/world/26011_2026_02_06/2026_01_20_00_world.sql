-- Update Thotar the Razor Hill hunter trainer
DELETE FROM `creature_template_gossip` WHERE `CreatureID` = 3171;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(3171, 14006, 65299); -- 3171

DELETE FROM `gossip_menu` WHERE `MenuID` = 14006;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(14006, 4888, 65299), -- 3171
(14006, 5002, 65299); -- 3171

-- Add conditions for If/If Not a Hunter
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 14006;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 14006, 5002, 0, 0, 15, 0, 4, 0, 0, '', 1, 0, 0, '', 'Show gossip text if player is not a Hunter'),
(14, 14006, 4888, 0, 0, 15, 0, 4, 0, 0, '', 0, 0, 0, '', 'Show gossip text if player is a Hunter');
