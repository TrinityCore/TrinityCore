-- Thotar --> Fix Gossip Text
DELETE FROM `gossip_menu` WHERE `MenuID`=4017 AND `TextID`=4973;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(4017,4973,0);

UPDATE `conditions` SET `SourceEntry`=4973 WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=4017 AND `ConditionValue1`=1531;

-- Thotar --> Remove wrong queststart
DELETE FROM `creature_queststarter` WHERE `id`=3171 AND `quest`=6069;
