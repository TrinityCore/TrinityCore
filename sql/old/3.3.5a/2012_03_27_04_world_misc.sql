ALTER TABLE `spell_dbc` CHANGE `StackAmount` `StackAmount` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `waypoint_data` CHANGE `action_chance` `action_chance` smallint(6) NOT NULL DEFAULT '100';
ALTER TABLE `item_loot_template` CHANGE `maxcount` `maxcount` tinyint(3) unsigned NOT NULL DEFAULT '1';
