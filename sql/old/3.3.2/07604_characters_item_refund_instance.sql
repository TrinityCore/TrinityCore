DROP TABLE IF EXISTS `item_refund_instance`;
CREATE TABLE `item_refund_instance` (                                                     
`item_guid` int(11) unsigned NOT NULL COMMENT 'Item GUID',                                   
`player_guid` int(11) unsigned NOT NULL COMMENT 'Player GUID',
`paidMoney` int(11) unsigned NOT NULL DEFAULT '0',                                      
`paidHonor` int(11) unsigned NOT NULL DEFAULT '0',                                      
`paidArena` int(11) unsigned NOT NULL DEFAULT '0',                                      
`paidItem_1` mediumint(6) unsigned NOT NULL DEFAULT '0' COMMENT 'item_template.entry',  
`paidItemCount_1` mediumint(6) unsigned NOT NULL DEFAULT '0',                           
`paidItem_2` mediumint(6) unsigned NOT NULL DEFAULT '0',                                
`paidItemCount_2` mediumint(6) unsigned NOT NULL DEFAULT '0',                           
`paidItem_3` mediumint(6) unsigned NOT NULL DEFAULT '0',                                
`paidItemCount_3` mediumint(6) unsigned NOT NULL DEFAULT '0',                           
`paidItem_4` mediumint(6) unsigned NOT NULL DEFAULT '0',                                
`paidItemCount_4` mediumint(6) unsigned NOT NULL DEFAULT '0',                           
`paidItem_5` mediumint(6) unsigned NOT NULL DEFAULT '0',                                
`paidItemCount_5` mediumint(6) unsigned NOT NULL DEFAULT '0',                           
PRIMARY KEY (`item_guid`, `player_guid`)                                                                    
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
