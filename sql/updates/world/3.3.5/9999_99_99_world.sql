-- Battle Of Mount Hyjal missing optionid
DELETE FROM gossip_menu_option WHERE MenuID=7552 AND OptionID IN (0,1,2);
DELETE FROM gossip_menu_option WHERE MenuID=7581 AND OptionID IN (0,1,2);
DELETE FROM gossip_menu_option WHERE MenuID=7706 AND OptionID=0;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7552, 0, 0, 'My companions and I are with you, Lady Proudmoore.', 14698, 0, 0, 7556, 0, 0, 0, NULL, 0, 26365),
(7552, 1, 0, 'We are ready for whatever Archimonde might send our way, Lady Proudmoore.', 15393, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(7552, 2, 0, 'Until we meet again, Lady Proudmoore.', 15416, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(7581, 0, 0, 'We have nothing to fear.', 15445, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(7581, 1, 0, 'I am with you, Thrall.', 14875, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(7581, 2, 0, 'Until we meet again, Thrall.', 15449, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(7706, 0, 0, 'I would be grateful for any aid you can provide, Priestess.', 20242, 0, 0, 0, 0, 0, 0, NULL, 0, 0);

-- Karazhan missing optionid
DELETE FROM gossip_menu_option WHERE MenuID=7421 AND OptionID=0;
DELETE FROM gossip_menu_option WHERE MenuID=7422 AND OptionID=0;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7421, 0, 0, 'I\'m not an actor.', 14052, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(7422, 0, 0, 'Ok, I\'ll give it a try, then.', 14054, 0, 0, 0, 0, 0, 0, NULL, 0, 0);

-- HallsOfStone missing optionid
DELETE FROM gossip_menu_option WHERE MenuID=9670 AND OptionID=0;
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(9670, 0, 0, 'Let\'s move Brann, enough of the history lesson!', 27616, 0, 0, 0, 0, 0, 0, NULL, 0, 0);
