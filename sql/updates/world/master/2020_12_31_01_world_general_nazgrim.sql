UPDATE `creature_template` SET `gossip_menu_id`='14988', `ScriptName`='npc_general_nazgrim_55054' WHERE (`entry`='55054');
REPLACE INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES ('14988', '14988', '0');
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES ('14988', '0', '0', 'I\'m ready to go, General.', '0', '0', '3', '0');
UPDATE `gossip_menu_option` SET `OptionType`='1', `OptionNpcFlag`='1' WHERE (`MenuId`='14988') AND (`OptionIndex`='0');
