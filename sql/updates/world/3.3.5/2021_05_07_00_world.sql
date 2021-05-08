--
UPDATE `gossip_menu_option` SET `ActionMenuID`=10505,`BoxBroadcastTextID`=34569,`BoxText`='You may choose to care for an Oracle orphan or a Wolvar orphan, but you will not be able to help both.' WHERE  `MenuID`=10502 AND `OptionID`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE  `entryorguid`=34365 AND `source_type`=0 AND `id`=1 AND `link`=4;
