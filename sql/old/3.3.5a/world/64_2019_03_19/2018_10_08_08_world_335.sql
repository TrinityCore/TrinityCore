-- Cyrus Therepentous
UPDATE `creature_template` SET `gossip_menu_id`=1842 WHERE `entry`=9459;

DELETE FROM `gossip_menu` WHERE `MenuID` IN (1842,1843,40060);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1842,2493,0),
(1843,2494,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (1842,1843,40060);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1842,0,0,"I present you with proof of my deeds, Cyrus.",4754,1,1,0,0,0,0,"",0,0),
(1842,1,0,"I do not possess any proof, Cyrus.",4755,1,1,1843,0,0,0,"",0,0),
(1843,0,0,"I am ready!",4759,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup` IN (40060);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (1842,1843,40060);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,1842,0,0,0,9,0,4022,0,0,0,0,0,"","Show gossip option 0 if quest 'A Taste of Flame (1)' is taken"),
(15,1842,1,0,0,9,0,4023,0,0,0,0,0,"","Show gossip option 1 if quest 'A Taste of Flame (2)' is taken"),
(15,1843,0,0,0,29,0,9461,100,0,1,0,0,"","Show gossip option if Frenzied Black Drake is not already summoned");

DELETE FROM `smart_scripts` WHERE `entryorguid`=9459 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9459,0,0,2,62,0,100,0,1843,0,0,0,0,12,9461,1,360000,0,0,0,8,0,0,0,-7656.94,-3009.47,133.206,4.83028,"Cyrus Therepentous - On Gossip Option Selected - Summon Creature 'Frenzied Black Drake'"),
(9459,0,1,2,62,0,100,0,1842,0,0,0,0,15,4022,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cyrus Therepentous - On Gossip Option Selected - Summon Creature 'Frenzied Black Drake'"),
(9459,0,2,0,61,0,100,512,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Cyrus Therepentous - On Gossip Option Selected - Close Gossip");

-- Quest "A Taste of Flame"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry` IN (4022,4023);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19,0,4022,0,0,2,0,10575,1,1,0,0,0,"","Quest 'A Taste of Flame (1)' can only be taken if player have item 'Black Dragonflight Molt'"),
(19,0,4023,0,0,2,0,10575,1,1,1,0,0,"","Quest 'A Taste of Flame (2)' can only be taken if player does not have item 'Black Dragonflight Molt'");

UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `ID`=4022;
