-- Custom gossip 21257 (from 3.3.5) is used by Navarrogg (99624)
DELETE FROM `gossip_menu` WHERE (`MenuID`=21257 AND `TextID`=15846);
DELETE FROM `gossip_menu` WHERE (`MenuID`=11375 AND `TextID`=15846);
DELETE FROM `gossip_menu` WHERE (`MenuID`=11394 AND `TextID` IN (15873,15872,15871));
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11375, 15846, 53788), -- 40352 (Witch Doctor Hez'tok)
(11394, 15873, 53788), -- 40492 (Zild'jian)
(11394, 15872, 53788), -- 40492 (Zild'jian)
(11394, 15871, 53788); -- 40492 (Zild'jian)

UPDATE `gossip_menu` SET `VerifiedBuild`=53788 WHERE (`MenuID`=11341 AND `TextID`=15796) OR (`MenuID`=11345 AND `TextID`=15806) OR (`MenuID`=11391 AND `TextID`=15865);
UPDATE `gossip_menu` SET `VerifiedBuild`=53788 WHERE (`MenuID`=11397 AND `TextID`=15877) OR (`MenuID`=11398 AND `TextID`=15876);

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=21257 AND `OptionID`=0);
DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (11341,11375));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(11341, 93994, 0, 0, 'Would you call down the Spirit of the Tiger again, Vanira?', 40445, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 75186, NULL, 53788),
(11375, 94022, 0, 0, 'Let us consult the omens.', 40385, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 53788);

UPDATE `gossip_menu_option` SET `GossipOptionID`=94211, `VerifiedBuild`=53788 WHERE (`MenuID`=11398 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=94004, `OptionText`='I need to get to Razor Hill to recruit on behalf of Vol''jin.  May I borrow a bat?', `SpellID`=75421, `VerifiedBuild`=53788 WHERE (`MenuID`=11345 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `GossipOptionID`=94003, `OptionText`='I am ready to take back the Echo Isles.  Take me to the staging area!', `SpellID`=75422, `VerifiedBuild`=53788 WHERE (`MenuID`=11345 AND `OptionID`=2);
UPDATE `gossip_menu_option` SET `GossipOptionID`=94005, `SpellID`=74978, `VerifiedBuild`=53788 WHERE (`MenuID`=11345 AND `OptionID`=0);

DELETE FROM `npc_text` WHERE `ID` IN (15871,15872);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(15872, 1, 0, 0, 0, 0, 0, 0, 0, 40475, 0, 0, 0, 0, 0, 0, 0, 53788), -- 15872
(15871, 1, 0, 0, 0, 0, 0, 0, 0, 40472, 0, 0, 0, 0, 0, 0, 0, 53788); -- 15871

UPDATE `npc_text` SET `VerifiedBuild`=53788 WHERE `ID` IN (15865, 15873, 15877, 15876);
UPDATE `npc_text` SET `VerifiedBuild`=53788 WHERE `ID` IN (15806, 15846, 15796);

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=39654 AND `MenuID` IN (11397,11398)) OR (`CreatureID`=40492 AND `MenuID`=11394) OR (`CreatureID`=40352);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(40352, 11375, 53788), -- Witch Doctor Hez'tok
(39654, 11398, 53788), -- Vol'jin
(40492, 11394, 53788); -- Zild'jian

UPDATE `creature_template_gossip` SET `VerifiedBuild`=53788 WHERE (`CreatureID`=40184 AND `MenuID`=11341) OR (`CreatureID`=40204 AND `MenuID`=11345) OR (`CreatureID`=40391 AND `MenuID`=11391);

UPDATE `smart_scripts` SET `event_param1`=11375 WHERE `entryorguid`=40352 AND `source_type`=0 AND `id`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=21257;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=11375;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 11375, 0, 0, 0, 47, 0, 25480, 10, 0, 0, 0, 0, '', 'Gossip menu option requires quest 25480 taken or completed');
