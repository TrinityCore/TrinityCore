-- Proenitus, Azuremyst Isle
UPDATE `creature_template` SET `gossip_menu_id`=7305 WHERE `entry`=16477;
-- 8667 before quest 9280 or 9369 is completed, 8669 after quest 9280 or 9369 is completed
DELETE FROM `gossip_menu` WHERE `entry`=7305;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(7305,8667),
(7305,8669);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7305;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 7305, 8669, 0, 0, 8, 0, 9280, 0, 0, 0, 0, 0, '', 'Proenitus - Show Gossip Text only if Replenishing the Healing Crystals rewarded - or'),
(14, 7305, 8669, 0, 1, 8, 0, 9369, 0, 0, 0, 0, 0, '', 'Proenitus - Show Gossip Text only if Replenishing the Healing Crystals rewarded - or'),
(14, 7305, 8667, 0, 0, 8, 0, 9280, 0, 0, 1, 0, 0, '', 'Proenitus - Show Gossip Text only if Replenishing the Healing Crystals not rewarded - and'), 
(14, 7305, 8667, 0, 0, 8, 0, 9369, 0, 0, 1, 0, 0, '', 'Proenitus - Show Gossip Text only if Replenishing the Healing Crystals not rewarded');
