-- http://www.wowhead.com/quest=27674/to-the-surface
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_gnomeregan_torben' WHERE `entry` = 46293;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`= 46360 WHERE `MenuID`= 12104;
