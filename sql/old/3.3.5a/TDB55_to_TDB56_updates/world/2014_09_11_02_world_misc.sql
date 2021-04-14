-- Set Values 
-- Human
SET @HRace := 1;   
SET @HFaction := 72;   
-- Dwarf
SET @DWRace := 4;   
SET @DWFaction := 47;   
-- Orc
SET @ORace := 2;   
SET @OFaction := 76;   
-- Tauren
SET @TARace := 32;   
SET @TAFaction := 81;   
-- Night Elf
SET @NRace := 8;   
SET @NFaction := 69;   
-- Undead
SET @URace := 16;   
SET @UFaction := 68;   
-- Troll
SET @TRRace := 128;   
SET @TRFaction := 530;   
-- Gnome (Milli Featherwhistle already uses db gossip and conditions as has sai script
-- Blood Elf
SET @BRace := 512;   
SET @BFaction := 911;   
-- Dreanei
SET @DRRace := 1024;   
SET @DRFaction := 930;   

UPDATE `creature_template` SET `ScriptName`='' WHERE  `entry` IN(384,1261,1460,2357,3662,3685,4730,4731,4885,7952,16264,17584);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(14,15) AND `SourceGroup` IN(4004,4001,3161,3162,4006,4005,3185,8098,8213,3185);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 4004, 0, 0, 0, 16, 0, @HRace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Human'),
(15, 4004, 0, 0, 1, 5, 0, @HFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Stormwind'),
(15, 4001, 0, 0, 0, 16, 0, @DWRace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Dwarf'),
(15, 4001, 0, 0, 1, 5, 0, @DWFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Ironforge'),
(15, 3161, 0, 0, 0, 16, 0, @ORace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Orc'),
(15, 3161, 0, 0, 1, 5, 0, @OFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Orgrimmar'),
(15, 4006, 0, 0, 0, 16, 0, @TARace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Tauren'),
(15, 4006, 0, 0, 1, 5, 0, @TAFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Thunderbluff'),
(15, 3185, 0, 0, 0, 16, 0, @NRace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Night Elf'),
(15, 3185, 0, 0, 1, 5, 0, @NFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Darnassus'),
(15, 4005, 0, 0, 0, 16, 0, @URace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Undead'),
(15, 4005, 0, 0, 1, 5, 0, @UFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Undercity'),
(15, 3162, 0, 0, 0, 16, 0, @TRRace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Troll'),
(15, 3162, 0, 0, 1, 5, 0, @TRFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Sen Jin'),
(15, 8098, 0, 0, 0, 16, 0, @BRace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Blood Elf'),
(15, 8098, 0, 0, 1, 5, 0, @BFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Silvermoon City'),
(15, 8213, 0, 0, 0, 16, 0, @DRRace, 0, 0, 0, 0, 0, '', 'Gossip Option - Show Option if Player is Dreanei'),
(15, 8213, 0, 0, 1, 5, 0, @DRFaction, 128, 0, 0, 0, 0, '', 'Gossip Option - Show Option if player is Exalted with Exodar'),

(14, 4004, 4855, 0, 0, 16, 0, @HRace, 0, 0, 1, 0, 0, '', 'NPC Text - Show text if Player is Human'),
(14, 4004, 4855, 0, 0, 5, 0, @HFaction, 128, 0, 1, 0, 0, '', 'NPC Text - Show text if player is not Exalted with Stormwind'),
(14, 4006, 4840, 0, 0, 16, 0, @TARace, 0, 0, 1, 0, 0, '', 'NPC Text - Show text if Player is not Tauren'),
(14, 4006, 4840, 0, 0, 5, 0, @TAFaction, 128, 0, 1, 0, 0, '', 'NPC Text - Show text if player is not Exalted with Thunderbluff'),
(14, 8098, 10305, 0, 0, 16, 0, @BRace, 0, 0, 1, 0, 0, '', 'NPC Text - Show text if Player is not Blood Elf'),
(14, 8098, 10305, 0, 0, 5, 0, @BFaction, 128, 0, 1, 0, 0, '', 'NPC Text - Show text if player is not Exalted with Silvermoon'),
(14, 4005, 5840, 0, 0, 16, 0, @URace, 0, 0, 1, 0, 0, '', 'NPC Text - Show text if Player is not Undead'),
(14, 4005, 5840, 0, 0, 5, 0, @UFaction, 128, 0, 1, 0, 0, '', 'NPC Text - Show text if player is not Exalted with Undercity'),
(14, 3161, 3841, 0, 0, 16, 0, @ORace, 0, 0, 1, 0, 0, '', 'NPC Text - Show text if Player is not Orc'),
(14, 3161, 3841, 0, 0, 5, 0, @OFaction, 128, 0, 1, 0, 0, '', 'NPC Text - Show text if player is not Exalted with Ogrimmar'),
(14, 3185, 5844, 0, 0, 16, 0, @NRace, 0, 0, 1, 0, 0, '', 'NPC Text - Show text if Player is not Night Elf'),
(14, 3185, 5844, 0, 0, 5, 0, @NFaction, 128, 0, 1, 0, 0, '', 'NPC Text - Show text if player is not Exalted with Darnassus'),
(14, 3162, 5842, 0, 0, 16, 0, @TRRace, 0, 0, 1, 0, 0, '', 'NPC Text - Show text if Player is not Troll'),
(14, 3162, 5842, 0, 0, 5, 0, @TRFaction, 128, 0, 1, 0, 0, '', 'NPC Text - Show text if player is not Exalted with Darkspear Trolls'),


(14, 4004, 4859, 0, 0, 16, 0, @HRace, 0, 0, 0, 0, 0, '', 'NPC Text - Show text if Player is Human'),
(14, 4004, 4859, 0, 1, 5, 0, @HFaction, 128, 0, 0, 0, 0, '', 'NPC Text - Show text if player is Exalted with Stormwind'),
(14, 4006, 4862, 0, 0, 16, 0, @TARace, 0, 0, 0, 0, 0, '', 'NPC Text - Show text if Player is Tauren'),
(14, 4006, 4862, 0, 1, 5, 0, @TAFaction, 128, 0, 0, 0, 0, '', 'NPC Text - Show text if player is Exalted with Thunderbluff'),
(14, 8098, 10011, 0, 0, 16, 0, @BRace, 0, 0, 0, 0, 0, '', 'NPC Text - Show text if Player is Blood Elf'),
(14, 8098, 10011, 0, 1, 5, 0, @BFaction, 128, 0, 0, 0, 0, '', 'NPC Text - Show text if player is Exalted with Silvermoon'),
(14, 4005, 4869, 0, 0, 16, 0, @URace, 0, 0, 0, 0, 0, '', 'NPC Text - Show text if Player is Undead'),
(14, 4005, 4869, 0, 1, 5, 0, @UFaction, 128, 0, 0, 0, 0, '', 'NPC Text - Show text if player is Exalted with Undercity'),
(14, 3161, 3893, 0, 0, 16, 0, @ORace, 0, 0, 0, 0, 0, '', 'NPC Text - Show text if Player is Orc'),
(14, 3161, 3893, 0, 1, 5, 0, @OFaction, 128, 0, 0, 0, 0, '', 'NPC Text - Show text if player is Exalted with Ogrimmar'),
(14, 3185, 3942, 0, 0, 16, 0, @NRace, 0, 0, 0, 0, 0, '', 'NPC Text - Show text if Player is Night Elf'),
(14, 3185, 3942, 0, 1, 5, 0, @NFaction, 128, 0, 0, 0, 0, '', 'NPC Text - Show text if player is Exalted with Darnassus'),
(14, 3162, 3896, 0, 0, 16, 0, @TRRace, 0, 0, 0, 0, 0, '', 'NPC Text - Show text if Player is Troll'),
(14, 3162, 3896, 0, 1, 5, 0, @TRFaction, 128, 0, 0, 0, 0, '', 'NPC Text - Show text if player is Exalted with Darkspear Trolls');

UPDATE `creature_template` SET `gossip_menu_id`=4001 WHERE  `entry`=1261;
UPDATE `creature_template` SET `gossip_menu_id`=4004 WHERE  `entry`=2357;

DELETE FROM  `gossip_menu_option` WHERE `menu_id` IN(4004,4001,3161,3162,4006,4005,3185,8098,8213,3185);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(3185, 1, 1, 'I would like to buy from you.', 14967, 3, 128, 0, 0, 0, 0, '', 0),
(4001, 0, 1, 'I would like to buy from you.', 14967, 3, 128, 0, 0, 0, 0, '', 0),
(3161, 0, 1, 'I would like to buy from you.', 14967, 3, 128, 0, 0, 0, 0, '', 0),
(3162, 0, 1, 'I would like to buy from you.', 14967, 3, 128, 0, 0, 0, 0, '', 0),
(4004, 0, 1, 'I would like to buy from you.', 14967, 3, 128, 0, 0, 0, 0, '', 0),
(4005, 0, 1, 'I would like to buy from you.', 14967, 3, 128, 0, 0, 0, 0, '', 0),
(4006, 0, 1, 'I would like to buy from you.', 14967, 3, 128, 0, 0, 0, 0, '', 0),
(8098, 0, 1, 'I wish to purchase one of these creatures.', 17909, 3, 128, 0, 0, 0, 0, '', 0),
(8213, 0, 1, 'I wish to purchase one of these creatures.', 17909, 3, 128, 0, 0, 0, 0, '', 0);

DELETE FROM `gossip_menu` WHERE `entry`=4001;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(4001, 5856); -- 1261

DELETE FROM `gossip_menu` WHERE `entry` IN(4004,4001,3161,3162,4006,4005,3185,8098,8213,3185);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(3161, 3893),
(3161, 3841),
(3162, 3896),
(3162, 5842),
(3185, 3942),
(3185, 5844),
(4001, 5856),
(4004, 4859),
(4004, 5855),
(4005, 4869),
(4005, 5840),
(4006, 4862),
(4006, 5843),
(8098, 10011),
(8098, 10305),
(8213, 10239);

UPDATE `smart_scripts` SET `target_type`=10 WHERE `entryorguid`=2598300 AND `ID`=1;
