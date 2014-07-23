--
-- Add missing gossip menus for horde npcs
DELETE FROM `gossip_menu` WHERE `entry`  in (10419,10420,10421,10425,10426);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10419, 14458),-- Thunder Bluff
(10420, 14459), -- Undercity
(10421, 14460), -- Ogrimmar
(10425, 14464), -- Sen'Jin
(10426, 14465); -- Silvermoon

-- add missing gossip options to horde vendors and remove a duplicate menu option from one of the alliance vendors which all have same text and this option is never displayed to players anyway its just for the condition for vendor.
DELETE FROM `gossip_menu_option` WHERE  `menu_id`=10417 AND `id`=1 OR `menu_id` in (10419,10420,10421,10425,10426);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(10419, 0, 1, 'I want to browse your goods.', 3, 128, 0, 0, 0, 0, ''),
(10420, 0, 1, 'I want to browse your goods.', 3, 128, 0, 0, 0, 0, ''),
(10421, 0, 1, 'I want to browse your goods.', 3, 128, 0, 0, 0, 0, ''),
(10425, 0, 1, 'I want to browse your goods.', 3, 128, 0, 0, 0, 0, ''),
(10426, 0, 1, 'I want to browse your goods.', 3, 128, 0, 0, 0, 0, '');

-- Update creature template with missing gossip menu ids for horde vendors
UPDATE `creature_template` SET `gossip_menu_id`=10426 WHERE  `entry`=33557;
UPDATE `creature_template` SET `gossip_menu_id`=10420 WHERE  `entry`=33555;
UPDATE `creature_template` SET `gossip_menu_id`=10421 WHERE  `entry`=33553;
UPDATE `creature_template` SET `gossip_menu_id`=10419 WHERE  `entry`=33556;
UPDATE `creature_template` SET `gossip_menu_id`=10425 WHERE  `entry`=33554;

-- Conditions for argent tournament vendors so they will not allow player to use vendor until they are a champion of that faction
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN(10417,10418,10422,10423,10424);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10419, 0, 0, 0, 17, 0, 2786, 0, 0, 0, 0, 0, '', 'Only allow champions of Thunderbluff to access vendor'),
(15, 10420, 0, 0, 0, 17, 0, 2787, 0, 0, 0, 0, 0, '', 'Only allow champions of Undercity to access vendor'),
(15, 10421, 0, 0, 0, 17, 0, 2783, 0, 0, 0, 0, 0, '', 'Only allow champions of Ogrimmar to access vendor'),
(15, 10425, 0, 0, 0, 17, 0, 2784, 0, 0, 0, 0, 0, '', 'Only allow champions of Sen Jin to access vendor'),
(15, 10426, 0, 0, 0, 17, 0, 2785, 0, 0, 0, 0, 0, '', 'Only allow champions of Silvermoon to access vendor'),
(15, 10417, 0, 0, 0, 17, 0, 2781, 0, 0, 0, 0, 0, '', 'Only allow champions of Stowmwind to access vendor'),
(15, 10418, 0, 0, 0, 17, 0, 2780, 0, 0, 0, 0, 0, '', 'Only allow champions of Ironforge to access vendor'),
(15, 10422, 0, 0, 0, 17, 0, 2778, 0, 0, 0, 0, 0, '', 'Only allow champions of Exodar to access vendor'),
(15, 10423, 0, 0, 0, 17, 0, 2779, 0, 0, 0, 0, 0, '', 'Only allow champions of Gnomeregan to access vendor'),
(15, 10424, 0, 0, 0, 17, 0, 2777, 0, 0, 0, 0, 0, '', 'Only allow champions of Darnassus to access vendor');

-- Add missing versions of mounts for 5 champions seals and 500g to vendors, the versions which require rep to buy which are intended for player who is not member of that faction
DELETE FROM `npc_vendor` WHERE `item` IN(46758,46756,46759,46762,46763,46761,46764,46755,46760,46757);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `incrtime`, `ExtendedCost`) VALUES
(33307, 0, 46758, 0, 0, 2671), -- Stormwind (Non Human) - Human version 46752
(33657, 0, 46756, 0, 0, 2671), -- Exodar (Non Dreanei) - Dreanei version 46745
(33653, 0, 46759, 0, 0, 2671), -- Darnassus (Non Night elf) - Night elf version 46744
(33310, 0, 46762, 0, 0, 2671), -- Iron Forge (Non Dwarf) - Dwarf version 46748
(33650, 0, 46763, 0, 0, 2671), -- Gnomeregan (Non Gnome) - Gnome version 46747
(33557, 0, 46761, 0, 0, 2671), -- Silvermoon (Non Blood elf) - Blood Elf version 46751
(33555, 0, 46764, 0, 0, 2671), -- Undercity (Non Undead) - Undead version 46746
(33556, 0, 46755, 0, 0, 2671), -- Thunderbluff (Non Tauren) - Tauren version 46750
(33554, 0, 46760, 0, 0, 2671), -- Sen Jin (Non Troll) - Troll version 46743
(33553, 0, 46757, 0, 0, 2671); -- Orgrimmar (Non Orc) - Orchish version 46749

-- Conditions to specify which version of mounts to sell, no restriction if own race, requires exhalted if not this only applys to the mounts for 5 seals and 500g not the ones for 100 seals
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup` IN(33307,33657,33653,33310,33650,33557,33555,33556,33554,33555);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23, 33307, 46758, 0, 0, 16, 0, 1, 0, 0, 1, 0, 0, '', 'Only Sell to Non Humans'),
(23, 33307, 46752, 0, 0, 16, 0, 1, 0, 0, 0, 0, 0, '', 'Only Sell to Humans'),
(23, 33657, 46756, 0, 0, 16, 0, 1024, 0, 0, 1, 0, 0, '', 'Only Sell to Non Dreanei'),
(23, 33657, 46745, 0, 0, 16, 0, 1024, 0, 0, 0, 0, 0, '', 'Only Sell to Dreanei'),
(23, 33653, 46759, 0, 0, 16, 0, 8, 0, 0, 1, 0, 0, '', 'Only Sell to Non Night elf'),
(23, 33653, 46744, 0, 0, 16, 0, 8, 0, 0, 0, 0, 0, '', 'Only Sell to Night elf'),
(23, 33310, 46762, 0, 0, 16, 0, 4, 0, 0, 1, 0, 0, '', 'Only Sell to Non Dwarf'),
(23, 33310, 46748, 0, 0, 16, 0, 4, 0, 0, 0, 0, 0, '', 'Only Sell to Dwarf'),
(23, 33650, 46753, 0, 0, 16, 0, 64, 0, 0, 1, 0, 0, '', 'Only Sell to Non Gnome'),
(23, 33650, 46747, 0, 0, 16, 0, 64, 0, 0, 0, 0, 0, '', 'Only Sell to Gnome'),
(23, 33557, 46761, 0, 0, 16, 0, 512, 0, 0, 1, 0, 0, '', 'Only Sell to Non Blood elf'),
(23, 33557, 46751, 0, 0, 16, 0, 512, 0, 0, 0, 0, 0, '', 'Only Sell to Blood elf'),
(23, 33555, 46764, 0, 0, 16, 0, 16, 0, 0, 1, 0, 0, '', 'Only Sell to Non Undead'),
(23, 33555, 46746, 0, 0, 16, 0, 16, 0, 0, 0, 0, 0, '', 'Only Sell to Undead'),
(23, 33556, 46755, 0, 0, 16, 0, 32, 0, 0, 1, 0, 0, '', 'Only Sell to Non Tauren'),
(23, 33556, 46750, 0, 0, 16, 0, 32, 0, 0, 0, 0, 0, '', 'Only Sell to Tauren'),
(23, 33554, 46760, 0, 0, 16, 0, 128, 0, 0, 1, 0, 0, '', 'Only Sell to Non Troll'),
(23, 33554, 46743, 0, 0, 16, 0, 128, 0, 0, 0, 0, 0, '', 'Only Sell to Troll'),
(23, 33657, 46757, 0, 0, 16, 0, 2, 0, 0, 1, 0, 0, '', 'Only Sell to Non Orc'),
(23, 33653, 46749, 0, 0, 16, 0, 2, 0, 0, 0, 0, 0, '', 'Only Sell to Orc');
