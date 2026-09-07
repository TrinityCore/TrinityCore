DELETE FROM `creature_template_gossip` WHERE `CreatureID` IN (459, 198, 375, 43278, 925, 911, 915, 6373);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(459, 1503, 60192), -- Drusilla La Salle
(198, 4660, 60192), -- Khelden Bremen
(375, 4665, 60192), -- Priestess Anetta
(43278, 11860, 60192), -- Ashley Blank
(925, 4663, 60192), -- Brother Sammuel
(911, 4650, 60192), -- Llane Beshere
(6373, 12670, 60192), -- Dane Winslow
(915, 4659, 60192); -- Jorik Kerridan

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=11860 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(11860, 112579, 0, 3, 'I require training.', 2756, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 60192); -- OptionBroadcastTextID: 2756 - 6499 - 6501 - 6503

UPDATE `gossip_menu_option` SET `GossipOptionID`=88971, `VerifiedBuild`=60192 WHERE (`MenuID`=4650 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=89886, `OptionText`='I would like to train further in the ways of the Light.', `OptionBroadcastTextID`=5299, `VerifiedBuild`=60192 WHERE (`MenuID`=4663 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=90505, `ActionMenuID`=4660, `VerifiedBuild`=60192 WHERE (`MenuID`=4660 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `VerifiedBuild`=60192 WHERE (`MenuID`=12670 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=90504, `VerifiedBuild`=60192 WHERE (`MenuID`=4659 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=88176, `VerifiedBuild`=60192 WHERE (`MenuID`=1503 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=88973, `OptionBroadcastTextID`=7157, `ActionMenuID`=4665, `VerifiedBuild`=60192 WHERE (`MenuID`=4665 AND `OptionID`=0); -- OptionBroadcastTextID: 7157 - 7160 - 7167 - 7168 - 7169
