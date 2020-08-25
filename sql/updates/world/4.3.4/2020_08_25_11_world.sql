DELETE FROM `gossip_menu_option` WHERE `MenuId`=9123;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES 
(9123, 0, 5, 'Make this inn your home.', 2822, 8, 65536, 15595),
(9123, 1, 1, 'I want to browse your goods.', 3370, 3, 128, 15595),
(9123, 2, 0, 'Trick or Treat!', 10693, 1, 1, 0);

UPDATE `conditions` SET `SourceEntry`=2 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9123 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=12 AND `ConditionTarget`=0 AND `ConditionValue1`=12 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `SourceEntry`=2 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9123 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=1 AND `ConditionTarget`=0 AND `ConditionValue1`=24755 AND `ConditionValue2`=0 AND `ConditionValue3`=0;

DELETE FROM `gossip_menu_option` WHERE `MenuId`=6620;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES 
(6620, 0, 5, 'Make this inn your home.', 2822, 8, 65536, 15595),
(6620, 1, 1, 'I want to browse your goods.', 3370, 3, 128, 15595),
(6620, 2, 0, 'Trick or Treat!', 10693, 1, 1, 0);

UPDATE `conditions` SET `SourceEntry`=2 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6620 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=12 AND `ConditionTarget`=0 AND `ConditionValue1`=12 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
UPDATE `conditions` SET `SourceEntry`=2 WHERE  `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6620 AND `SourceEntry`=0 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=1 AND `ConditionTarget`=0 AND `ConditionValue1`=24755 AND `ConditionValue2`=0 AND `ConditionValue3`=0;

DELETE FROM `gossip_menu_option` WHERE `MenuId`=9546;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`, `VerifiedBuild`) VALUES 
(9546, 0, 2, 'Where would you like to fly to?', 10753, 4, 8192, 15595),
(9546, 1, 0, 'Greer, I need a gryphon to ride and some bombs to drop on New Agamand!', 23112, 1, 1, 15595),
(9546, 2, 0, 'I need to get to Wintergarde Keep fast!', 26697, 1, 1, 0);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=9546 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(9546, 1, 8926, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9546 AND `SourceEntry`=1 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=28 AND `ConditionTarget`=0 AND `ConditionValue1`=12298 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (15, 9546, 2, 0, 0, 28, 0, 12298, 0, 0, 0, 0, 0, '', 'Greer Orehammer - Show gossip option only if player has taken quest 12298');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9546 AND `SourceEntry`=2 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=9 AND `ConditionTarget`=0 AND `ConditionValue1`=11332 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES (15, 9546, 1, 0, 0, 9, 0, 11332, 0, 0, 0, 0, 0, '', 'Greer Orehammer - Show gossip option only if player has taken quest 11332');

UPDATE `gossip_menu_option` SET `OptionText`='<Nod>.', `VerifiedBuild`=15354 WHERE (`MenuId`=5702 AND `OptionIndex`=0);
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=3532, `ActionPoiId`=0 WHERE  `MenuId`=3506 AND `OptionIndex`=6;

UPDATE `gossip_menu_option_action` SET `ActionMenuId`=12255, `ActionPoiId`=0 WHERE  `MenuId`=10767 AND `OptionIndex`=1;
UPDATE `gossip_menu_option_action` SET `ActionMenuId`=7659, `ActionPoiId`=373 WHERE  `MenuId`=7667 AND `OptionIndex`=6;

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=12977 AND `OptionIndex`=0) OR (`MenuId`=12833 AND `OptionIndex`=0) OR (`MenuId`=12278 AND `OptionIndex`=0) OR (`MenuId`=12279 AND `OptionIndex`=0) OR (`MenuId`=12275 AND `OptionIndex`=0) OR (`MenuId`=12276 AND `OptionIndex`=0) OR (`MenuId`=12273 AND `OptionIndex`=0) OR (`MenuId`=10937 AND `OptionIndex`=0) OR (`MenuId`=10935 AND `OptionIndex`=0) OR (`MenuId`=1141 AND `OptionIndex`=0) OR (`MenuId`=11607 AND `OptionIndex`=0) OR (`MenuId`=1290 AND `OptionIndex`=0) OR (`MenuId`=12790 AND `OptionIndex`=0) OR (`MenuId`=10780 AND `OptionIndex`=2) OR (`MenuId`=10786 AND `OptionIndex`=0) OR (`MenuId`=10785 AND `OptionIndex`=0) OR (`MenuId`=10784 AND `OptionIndex`=0) OR (`MenuId`=10783 AND `OptionIndex`=0) OR (`MenuId`=10782 AND `OptionIndex`=0) OR (`MenuId`=10781 AND `OptionIndex`=0) OR (`MenuId`=10780 AND `OptionIndex`=0) OR (`MenuId`=12015 AND `OptionIndex`=1) OR (`MenuId`=13357 AND `OptionIndex`=0) OR (`MenuId`=13411 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(12977, 0, 12978, 0),
(12833, 0, 12977, 0),
(12278, 0, 12277, 0),
(12279, 0, 12278, 0),
(12275, 0, 12274, 0),
(12276, 0, 12275, 0),
(12273, 0, 12272, 0),
(10937, 0, 10938, 0),
(10935, 0, 10937, 0),
(1141, 0, 1289, 0),
(11607, 0, 11820, 0),
(1290, 0, 1221, 0),
(12790, 0, 12983, 0),
(10780, 2, 10796, 0),
(10786, 0, 10788, 0),
(10785, 0, 10786, 0),
(10784, 0, 10785, 0),
(10783, 0, 10784, 0),
(10782, 0, 10783, 0),
(10781, 0, 10782, 0),
(10780, 0, 10781, 0),
(12015, 1, 12016, 0),
(13357, 0, 13358, 0),
(13411, 0, 13357, 0);