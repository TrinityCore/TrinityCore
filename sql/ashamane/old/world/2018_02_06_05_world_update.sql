
 --       AshamaneCore        --
-- // World update 0.3 by Nexon // --
  --       Legion 7.3.2       --

-- Thanks : STARRHELD & HannibalRoG

  
 -- Table `access_requirement`
INSERT IGNORE INTO `access_requirement` VALUES (1753, 2, 110, 0, 0, 0, 0, 0, 0, NULL, 'Siège du triumvirat (Entrée) - Héroique');
INSERT IGNORE INTO `access_requirement` VALUES (1753, 23, 110, 0, 0, 0, 0, 0, 0, NULL, 'Siège du triumvirat (Entrée) - Mythique');
INSERT IGNORE INTO `access_requirement` VALUES (1712, 14, 110, 0, 0, 0, 0, 0, 0, NULL, 'Antorus, le Trône ardent (Entrée) - 30 Normal');
INSERT IGNORE INTO `access_requirement` VALUES (1712, 15, 110, 0, 0, 0, 0, 0, 0, NULL, 'Antorus, le Trône ardent (Entrée) - 30 Héroique');
INSERT IGNORE INTO `access_requirement` VALUES (1712, 16, 110, 0, 0, 0, 0, 0, 0, NULL, 'Antorus, le Trône ardent (Entrée) - 20 Mythique');
INSERT IGNORE INTO `access_requirement` VALUES (1712, 17, 110, 0, 0, 0, 0, 0, 0, NULL, 'Antorus, le Trône ardent (Entrée) - 20 LFR');
  
  
-- Table `creature_template`
UPDATE `creature_template` SET `unit_flags` = 33570944 WHERE (entry = 54638);
UPDATE `creature_template` SET `unit_flags` = 33555200 WHERE (entry = 99501);
UPDATE `creature_template` SET `HealthModifier` = 8 WHERE (entry = 86969);
UPDATE `creature_template` SET `HealthModifier` = 1.8 WHERE (entry = 93619);
UPDATE `creature_template` SET `HealthModifier` = 3 WHERE (entry = 93619);


-- Table `creature_onkill_reputation`
DELETE FROM `creature_onkill_reputation` WHERE `RewOnKillRepFaction1`=1850;
INSERT INTO `creature_onkill_reputation` (`creature_id`, `RewOnKillRepFaction1`, `RewOnKillRepFaction2`, `MaxStanding1`, `IsTeamAward1`, `RewOnKillRepValue1`, `MaxStanding2`, `IsTeamAward2`, `RewOnKillRepValue2`, `TeamDependent`) VALUES 
(89746, 1850, 0, 7, 0, 25, 0, 0, 0, 0),
(92466, 1850, 0, 7, 0, 25, 0, 0, 0, 0),
(92481, 1850, 0, 7, 0, 25, 0, 0, 0, 0),
(89695, 1850, 0, 7, 0, 25, 0, 0, 0, 0),
(89747, 1850, 0, 7, 0, 25, 0, 0, 0, 0),
(92508, 1850, 0, 7, 0, 500, 0, 0, 0, 0),
(92517, 1850, 0, 7, 0, 500, 0, 0, 0, 0),
(92495, 1850, 0, 7, 0, 500, 0, 0, 0, 0),
(92465, 1850, 0, 7, 0, 500, 0, 0, 0, 0);


-- Table `creature_addon` 
INSERT IGNORE INTO `creature_addon` (`guid`) VALUES ('20556170');
UPDATE `creature_addon` SET `emote` = 469 WHERE (guid = 20556170);
UPDATE `creature_addon` SET `auras` = 104939 WHERE (guid = 20556170);


-- Table `creature_queststarter`
DELETE FROM `creature_queststarter` WHERE `id`=915 AND `quest`=26915;
DELETE FROM `creature_questender` WHERE `id`=915 AND `quest`=26915;


-- //  HannibalRoG fix // --

-- QuarterMaster factions vendors
DELETE FROM conditions WHERE SourceGroup IN (50323, 50488, 50477, 50309, 50308, 49877, 50305, 50307, 50306, 50483, 50484, 50304);
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorType, ErrorTextId, ScriptName, Comment) VALUES
(23, 50323, 67525, 0, 0, 5, 0, 1133, 64, 0, 0, 0, 0, '', ''),
(23, 50488, 67533, 0, 0, 5, 0, 76, 64, 0, 0, 0, 0, '', ''),
(23, 50477, 67536, 0, 0, 5, 0, 530, 64, 0, 0, 0, 0, '', ''),
(23, 50309, 67528, 0, 0, 5, 0, 47, 64, 0, 0, 0, 0, '', ''),
(23, 50308, 67530, 0, 0, 5, 0, 54, 64, 0, 0, 0, 0, '', ''),
(23, 49877, 67531, 0, 0, 5, 0, 72, 64, 0, 0, 0, 0, '', ''),
(23, 50305, 67526, 0, 0, 5, 0, 69, 64, 0, 0, 0, 0, '', ''),
(23, 50307, 67532, 0, 0, 5, 0, 1134, 64, 0, 0, 0, 0, '', ''),
(23, 50306, 67527, 0, 0, 5, 0, 930, 64, 0, 0, 0, 0, '', ''),
(23, 50483, 67534, 0, 0, 5, 0, 81, 64, 0, 0, 0, 0, '', ''),
(23, 50484, 67525, 0, 0, 5, 0, 1133, 64, 0, 0, 0, 0, '', ''),
(23, 50304, 67529, 0, 0, 5, 0, 68, 64, 0, 0, 0, 0, '', '');

-- Set only one daily quest from some trainers, add some missing pools
UPDATE pool_template SET max_limit=1, description='Catherine Leland - Daily Quests' WHERE entry=369;
UPDATE pool_template SET max_limit=1 WHERE entry=368;
DELETE FROM pool_quest WHERE entry IN (26543, 26556, 26557, 26572, 26588);
INSERT INTO pool_quest (entry, pool_entry, description) VALUES
(26543, 347, 'Clammy Hands'),
(26556, 347, 'No Dumping Allowed'),
(26557, 347, 'A Staggering Effort'),
(26572, 347, 'A Golden Opportunity'),
(26588, 347, 'A Furious Catch');
UPDATE pool_template SET description='Razgar Daily quests' WHERE entry=347;

DELETE FROM pool_quest WHERE entry IN (29345, 29346, 29348, 29349, 29354);
INSERT INTO pool_quest (entry, pool_entry, description) VALUES
(29345, 346, 'Pond Predators'),
(29346, 346, 'The Rings the Thing'),
(29348, 346, 'The Race to Restock'),
(29349, 346, 'Craving Crayfish'),
(29354, 346, 'Shiny Baubles');
UPDATE pool_template SET description='Kah Mistrunner Daily quests' WHERE entry=346;

-- When you died in Mardum you appear in Westfall (Alliance) or Northern Barrens (Horde)
DELETE FROM `graveyard_zone` WHERE `GhostZone` = 7705;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES 
(5082, 7705, 0, '7.0 DH-Mardum - (01) Start'),
(5083, 7705, 0, '7.0 DH-Mardum - (03) Seat of Command'),
(5119, 7705, 0, '7.0 DH-Mardum - (04) Illidari Foothold'),
(5140, 7705, 0, '7.0 DH-Mardum - (05) Volcano'),
(5188, 7705, 0, '7.0 DH-Mardum - (06) The Fel Hammer'),
(5284, 7705, 0, '7.0 DH-Mardum - (02) Molten Shore');

-- Error in quest 39963 "On felbat wins" when you shoose Havoc spec
UPDATE `quest_template_addon` SET `NextQuestID`=39663 WHERE `ID` IN (39515, 39516);

/*Add some missing loot for creatures and object PART 1*/
-- NPC 93105 Inquisitor Baleful
DELETE FROM `creature_loot_template` WHERE `entry`=93105;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`)
VALUES  (93105, 129196, 0, 0.8, 0, 1, 0, 1, 1, 'Legion Healthstone');

-- NPC 93112 Felguard Sentry
DELETE FROM `creature_loot_template` WHERE `entry`=93112;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES  
(93112, 129196, 0, 2, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(93112, 130267, 0, 88, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(93112, 130268, 0, 22, 0, 1, 2, 1, 1, 'Bone Toothpick'),     
(93112, 130317, 0, 4, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(93112, 130264, 0, 20, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(93112, 130265, 0, 2, 0, 1, 5, 1, 1, 'Sharpened Canine'),
(93112, 130266, 0, 1.2, 0, 1, 6, 1, 1, 'Trophy Spine');
UPDATE `creature_template` SET `lootid`= 93112 WHERE `Entry`=93112;

-- NPC 93221 Doom Commander Beliash
DELETE FROM `creature_loot_template` WHERE `entry`=93221;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(93221, 129196, 0, 1.7, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(93221, 130267, 0, 85, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(93221, 130268, 0, 12, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(93221, 130317, 0, 4, 0, 1, 3, 1, 1, 'Fractured Trophy');
UPDATE `creature_template` SET `lootid`=93221 WHERE `Entry`=93221;

-- NPC 93115 "Foul Felstalker"
DELETE FROM `creature_loot_template` WHERE `entry`=93115;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(93115, 130267, 0, 15, 0, 1, 0, 1, 1, 'Extinguished Demon Stone'),
(93115, 130268, 0, 6, 0, 1, 1, 1, 1, 'Bone Toothpick'),
(93115, 130317, 0, 0.8, 0, 1, 2, 1, 1, 'Fractured Trophy'),
(93115, 130264, 0, 87, 0, 1, 3, 1, 1, 'Fel-Stained Claw'),
(93115, 130265, 0, 10, 0, 1, 4, 1, 1, 'Sharpened Canine'),
(93115, 130266, 0, 4, 0, 1, 5, 1, 1, 'Trophy Spine');
UPDATE `creature_template` SET `lootid`=93115 WHERE `Entry`=93115;

-- NPC 93716 Doom Slayer
DELETE FROM `creature_loot_template` WHERE `entry`=93716;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(93716, 129196, 0, 2, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(93716, 130267, 0, 91, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(93716, 130268, 0, 19, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(93716, 130317, 0, 5, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(93716, 130264, 0, 0.5, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(93716, 130265, 0, 0.02, 0, 1, 5, 1, 1, 'Sharpened Canine');
UPDATE `creature_template` SET `lootid`=93716 WHERE `Entry`=93716;

-- NPC 93802 Brood Queen Tyranna
DELETE FROM `creature_loot_template` WHERE `entry`=93802;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(93802, 129196, 0, 7, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(93802, 130267, 0, 42, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(93802, 130268, 0, 44, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(93802, 130317, 0, 15, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(93802, 124672, 0, 97, 1, 1, 4, 1, 1, 'Sargerite Keystone');
UPDATE `creature_template` SET `lootid`=93802 WHERE `Entry`=93802;

-- NPC 94654 Doomguard Eradicator
DELETE FROM `creature_loot_template` WHERE `entry`=94654;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(94654, 129196, 0, 1.5, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(94654, 130267, 0, 86, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(94654, 130268, 0, 17, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(94654, 130317, 0, 3, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(94654, 130264, 0, 8, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(94654, 130265, 0, 1.5, 0, 1, 5, 1, 1, 'Sharpened Canine'),
(94654, 130266, 0, 0.6, 0, 1, 6, 1, 1, 'Trophy Spine');
UPDATE `creature_template` SET `lootid`=94654 WHERE `Entry`=94654;

-- NPC 95226 Anguish Jailer
DELETE FROM `creature_loot_template` WHERE `entry`=95226;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(95226, 129196, 0, 1, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(95226, 130267, 0, 87, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(95226, 130268, 0, 13, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(95226, 130317, 0, 3, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(95226, 130264, 0, 6, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(95226, 130265, 0, 1, 0, 1, 5, 1, 1, 'Sharpened Canine'),
(95226, 128227, 0, 20, 0, 1, 6, 1, 1, ''),
(95226, 130266, 0, 0.3, 0, 1, 7, 1, 1, 'Trophy Spine');
UPDATE `creature_template` SET `lootid`=95226 WHERE `Entry`=95226;

-- NPC 96277 Queen's Centurion
DELETE FROM `creature_loot_template` WHERE `entry`=96277;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(96277, 129196, 0, 1, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(96277, 130267, 0, 87, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(96277, 130268, 0, 13, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(96277, 130317, 0, 3, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(96277, 130264, 0, 6, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(96277, 130265, 0, 1, 0, 1, 5, 1, 1, 'Sharpened Canine'),
(96277, 133580, 0, 0.01, 0, 1, 6, 1, 1, 'Brutarg Sword Tip'),
(96277, 130266, 0, 0.3, 0, 1, 7, 1, 1, 'Trophy Spine'),
(96277, 130261, 0, 0.01, 0, 1, 8, 1, 1, 'Brutarg´s Sword');


UPDATE `creature_template` SET `lootid`=96277 WHERE `Entry`=96277;

-- NPC 96278 Burning Soulstalker
DELETE FROM `creature_loot_template` WHERE `entry`=96278;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(96278, 129196, 0, 1, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(96278, 128948, 0, 0.1, 0, 1, 1, 1, 1, ''),
(96278, 130268, 0, 13, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(96278, 130317, 0, 3, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(96278, 130264, 0, 6, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(96278, 130265, 0, 1, 0, 1, 5, 1, 1, 'Sharpened Canine'),
(96278, 130266, 0, 0.3, 0, 1, 7, 1, 1, 'Trophy Spine');
UPDATE `creature_template` SET `lootid`=96278 WHERE `Entry`=96278;

-- NPC 96280 Volatile Minion
DELETE FROM `creature_loot_template` WHERE `entry`=96280;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(96280, 130267, 0, 87, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(96280, 130268, 0, 13, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(96280, 130317, 0, 3, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(96280, 130264, 0, 6, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(96280, 130265, 0, 1, 0, 1, 5, 1, 1, 'Sharpened Canine'),
(96280, 130266, 0, 0.3, 0, 1, 7, 1, 1, 'Trophy Spine');
UPDATE `creature_template` SET `lootid`=96280 WHERE `Entry`=96280;

-- NPC 96402 Hulking Forgefiend
DELETE FROM `creature_loot_template` WHERE `entry`=96402;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(96402, 129196, 0, 1, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(96402, 130267, 0, 87, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(96402, 130268, 0, 13, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(96402, 130317, 0, 3, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(96402, 130264, 0, 6, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(96402, 130265, 0, 1, 0, 1, 5, 1, 1, 'Sharpened Canine'),
(96402, 133580, 0, 0.6, 0, 1, 6, 1, 1, ''),
(96402, 130261, 0, 0.6, 0, 1, 7, 1, 1, 'Brutarg´s Sword');
UPDATE `creature_template` SET `lootid`=96402 WHERE `Entry`=96402;

-- NPC 96441 Fel Lord Caza
DELETE FROM `creature_loot_template` WHERE `entry`=96441;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(96441, 129196, 0, 1.2, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(96441, 130267, 0, 80, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(96441, 130268, 0, 19, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(96441, 130317, 0, 3, 0, 1, 3, 1, 1, 'Fractured Trophy');
UPDATE `creature_template` SET `lootid`=96441 WHERE `Entry`=96441;

-- NPC 96473 Eredar Sorcerer
DELETE FROM `creature_loot_template` WHERE `entry`=96473;	
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(96473, 129196, 0, 2, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(96473, 130267, 0, 92, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(96473, 130268, 0, 15, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(96473, 130317, 0, 5, 0, 1, 3, 1, 1, 'Fractured Trophy');
UPDATE `creature_template` SET `lootid`=96473 WHERE `Entry`=96473;

-- Add some missing creature text
DELETE FROM `creature_text` WHERE `CreatureID` IN (99916, 94410, 99917, 93105, 99915, 96654, 96436, 100982);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `type`, `language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(99916, 0, 0, 'Plenty of souls were sacrificed here. The activator is powered.', 12, 0, 100, 273, 0, 55344, '101656', 'Sevis Brightflame to Player'),
(94410, 0, 0, '$n, over here.', 12, 0, 100, 0, 0, 55011, 96441, 'Allari the Souleater to Player'),
(99917, 0, 0, '$n, hurry! You don''t have much time.', 12, 0, 100, 3, 0, 55345, '101658', 'Sevis Brightflame to Player'),
(99917, 1, 0, 'Sevis looks down at the dying broken mystic.', 16, 0, 100, 0, 0, 0, '101659', 'Sevis Brightflame to Player'),
(93105, 0, 0, 'I can see your secrets...', 12, 0, 100, 0, 0, 55222, 94930, 'Inquisitor Baleful to Player'),
(93105, 1, 0, 'My eyes... My eyes!', 14, 0, 100, 0, 0, 55223, 96010, 'Inquisitor Baleful to Player'),
(93105, 2, 0, 'Enough! My colossal infernal will crush you.', 14, 0, 100, 0, 0, 55224, 99554, 'Inquisitor Baleful to Player'),
(99915, 0, 0, '$n, we have a huge problem here.', 12, 0, 100, 0, 0, 55342, '101663', 'Sevis Brightflame to Player'),
(96654, 0, 0, '$n, you made it through!', 14, 0, 100, 22, 0, 55054, 99836, 'Belath Dawnblade to Player'),
(96436, 0, 0, '$n, will you use your spectral sight on the cave entrance? Something''s not right.', 12, 0, 100, 397, 0, 55233, 98201, 'Jace Darkweaver to Player'),
(99916, 1, 0, 'I will move ahead and find Allari.', 12, 0, 100, 0, 0, 55346, 101657, 'Sevis Brightflame to Player'),
(100982, 0, 0, 'I will meet you down at the gateway on the Molten Shore.', 12, 0, 100, 0, 0, 55352, 103349, 'Sevis Brightflame to Player');


DELETE FROM `npc_text` WHERE `ID` IN (27307, 27421, 27624, 28106, 27622, 27623, 26129, 26832, 26676, 26592, 28000, 27999, 27770, 27954, 27998, 26813, 27773, 27768, 27772, 27545, 27283, 27471, 28886, 27771, 27206, 27769);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(27307, 1, 0, 0, 0, 0, 0, 0, 0, 99020, 0, 0, 0, 0, 0, 0, 0, 22908),
(27421, 1, 0, 0, 0, 0, 0, 0, 0, 99834, 0, 0, 0, 0, 0, 0, 0, 22908),
(27624, 1, 0, 0, 0, 0, 0, 0, 0, 100749, 0, 0, 0, 0, 0, 0, 0, 22908),
(28106, 1, 0, 0, 0, 0, 0, 0, 0, 103959, 0, 0, 0, 0, 0, 0, 0, 22908),
(27622, 1, 0, 0, 0, 0, 0, 0, 0, 100733, 0, 0, 0, 0, 0, 0, 0, 22908),
(27623, 1, 0, 0, 0, 0, 0, 0, 0, 100737, 0, 0, 0, 0, 0, 0, 0, 22908),
(26129, 1, 0, 0, 0, 0, 0, 0, 0, 92162, 0, 0, 0, 0, 0, 0, 0, 22908),
(26832, 1, 0, 0, 0, 0, 0, 0, 0, 96307, 0, 0, 0, 0, 0, 0, 0, 22908),
(26676, 1, 0, 0, 0, 0, 0, 0, 0, 95397, 0, 0, 0, 0, 0, 0, 0, 22908),
(26592, 1, 0, 0, 0, 0, 0, 0, 0, 94951, 0, 0, 0, 0, 0, 0, 0, 22908),
(28000, 1, 0, 0, 0, 0, 0, 0, 0, 103337, 0, 0, 0, 0, 0, 0, 0, 22908),
(27999, 1, 0, 0, 0, 0, 0, 0, 0, 103328, 0, 0, 0, 0, 0, 0, 0, 22908),
(27770, 1, 0, 0, 0, 0, 0, 0, 0, 101650, 0, 0, 0, 0, 0, 0, 0, 22908),
(27954, 1, 0, 0, 0, 0, 0, 0, 0, 103080, 0, 0, 0, 0, 0, 0, 0, 22908),
(27998, 1, 0, 0, 0, 0, 0, 0, 0, 103324, 0, 0, 0, 0, 0, 0, 0, 22908),
(26813, 1, 0, 0, 0, 0, 0, 0, 0, 96144, 0, 0, 0, 0, 0, 0, 0, 22908),
(27773, 1, 0, 0, 0, 0, 0, 0, 0, 101661, 0, 0, 0, 0, 0, 0, 0, 22908),
(27768, 1, 0, 0, 0, 0, 0, 0, 0, 101647, 0, 0, 0, 0, 0, 0, 0, 22908),
(27772, 1, 0, 0, 0, 0, 0, 0, 0, 101660, 0, 0, 0, 0, 0, 0, 0, 22908),
(27545, 1, 0, 0, 0, 0, 0, 0, 0, 100342, 0, 0, 0, 0, 0, 0, 0, 22908),
(27283, 1, 0, 0, 0, 0, 0, 0, 0, 98960, 0, 0, 0, 0, 0, 0, 0, 22908),
(27471, 1, 0, 0, 0, 0, 0, 0, 0, 100024, 0, 0, 0, 0, 0, 0, 0, 22908),
(28886, 1, 0, 0, 0, 0, 0, 0, 0, 108864, 0, 0, 0, 0, 0, 0, 0, 22995),
(27771, 1, 0, 0, 0, 0, 0, 0, 0, 101654, 0, 0, 0, 0, 0, 0, 0, 22995),
(27206, 1, 0, 0, 0, 0, 0, 0, 0, 98578, 0, 0, 0, 0, 0, 0, 0, 22995),
(27769, 1, 0, 0, 0, 0, 0, 0, 0, 101649, 0, 0, 0, 0, 0, 0, 0, 22995);

-- Add some missing conversations
DELETE FROM `conversation_actors` WHERE (`ConversationId`=585 AND `ConversationActorId`=49935 AND `Idx`=0) OR (`ConversationId`=540 AND `Idx`=0) OR (`ConversationId`=581 AND `ConversationActorId`=49947 AND `Idx`=0) OR (`ConversationId`=486 AND `Idx`=1) OR (`ConversationId`=486 AND `Idx`=0) OR (`ConversationId`=570 AND `ConversationActorId`=49942 AND `Idx`=0) OR (`ConversationId`=747 AND `ConversationActorId`=49935 AND `Idx`=1) OR (`ConversationId`=747 AND `ConversationActorId`=49947 AND `Idx`=0) OR (`ConversationId`=705 AND `ConversationActorId`=50124 AND `Idx`=0) OR (`ConversationId`=922 AND `Idx`=2) OR (`ConversationId`=922 AND `Idx`=1) OR (`ConversationId`=922 AND `Idx`=0) OR (`ConversationId`=735 AND `Idx`=0) OR (`ConversationId`=567 AND `ConversationActorId`=49935 AND `Idx`=0) OR (`ConversationId`=576 AND `ConversationActorId`=49945 AND `Idx`=0) OR (`ConversationId`=574 AND `ConversationActorId`=49935 AND `Idx`=0) OR (`ConversationId`=736 AND `ConversationActorId`=50124 AND `Idx`=0) OR (`ConversationId`=569 AND `ConversationActorId`=47908 AND `Idx`=2) OR (`ConversationId`=569 AND `ConversationActorId`=49948 AND `Idx`=4) OR (`ConversationId`=569 AND `ConversationActorId`=49496 AND `Idx`=3) OR (`ConversationId`=569 AND `ConversationActorId`=49160 AND `Idx`=1) OR (`ConversationId`=569 AND `ConversationActorId`=49935 AND `Idx`=0) OR (`ConversationId`=558 AND `ConversationActorId`=49825 AND `Idx`=0) OR (`ConversationId`=531 AND `ConversationActorId`=49821 AND `Idx`=0) OR (`ConversationId`=555 AND `Idx`=0) OR (`ConversationId`=583 AND `ConversationActorId`=49825 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(585, 49935, 0, 25383),
(581, 49947, 0, 25383),
(570, 49942, 0, 25383),
(747, 49935, 1, 25383),
(747, 49947, 0, 25383),
(705, 50124, 0, 25383),
(567, 49935, 0, 25383),
(576, 49945, 0, 25383),
(574, 49935, 0, 25383),
(736, 50124, 0, 25383),
(569, 47908, 2, 25383),
(569, 49948, 4, 25383),
(569, 49496, 3, 25383),
(569, 49160, 1, 25383),
(569, 49935, 0, 25383),
(558, 49825, 0, 25383),
(531, 49821, 0, 25383),
(583, 49825, 0, 25383);

DELETE FROM `conversation_actor_template` WHERE `Id` IN (49935, 49947, 49942, 50124, 49945, 49948, 49496, 47908, 49160, 49825, 49821);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(49935, 93802, 65935, 25383),
(49947, 93127, 61698, 25383),
(49942, 97676, 60790, 25383),
(50124, 98075, 21135, 25383),
(49945, 96655, 60079, 25383),
(49948, 97425, 64013, 25383),
(49496, 97676, 60790, 25383),
(47908, 93127, 61698, 25383),
(49160, 96420, 63986, 25383),
(49825, 93221, 65308, 25383),
(49821, 93759, 60791, 25383);

DELETE FROM `conversation_line_template` WHERE `Id` IN (1519, 1410, 1409, 1511, 1299, 1298, 1483, 1482, 2938, 1780, 1779, 1684, 1683, 2289, 2288, 2287, 2529, 1755, 1754, 1469, 1496, 1493, 1759, 1757, 1756, 1828, 1739, 1738, 1737, 1736, 1481, 1480, 1479, 1478, 1477, 1476, 1446, 1445, 1383, 1438, 1437, 1515, 1514);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(1519, 0, 262, 0, 0, 25383),
(1410, 4131, 126507, 0, 8214, 25383),
(1409, 0, 126507, 0, 0, 25383),
(1511, 0, 119, 0, 0, 25383),
(1299, 4801, 0, 1, 0, 25383),
(1298, 0, 0, 0, 0, 25383),
(1483, 4944, 141, 0, 8214, 25383),
(1482, 0, 141, 0, 0, 25383),
(2938, 15963, 263, 1, 0, 25383),
(1780, 7855, 119, 0, 8214, 25383),
(1779, 0, 119, 0, 0, 25383),
(1684, 6896, 296, 0, 0, 25383),
(1683, 0, 296, 0, 0, 25383),
(2289, 12684, 0, 2, 0, 25383),
(2288, 5828, 0, 1, 0, 25383),
(2287, 500, 0, 1, 0, 25383),
(2529, 0, 0, 0, 0, 25383),
(1755, 6328, 0, 0, 8214, 25383),
(1754, 0, 0, 0, 0, 25383),
(1469, 0, 262, 0, 0, 25383),
(1496, 0, 120, 0, 0, 25383),
(1493, 0, 262, 0, 0, 25383),
(1759, 23571, 296, 0, 0, 25383),
(1757, 7677, 296, 0, 8214, 25383),
(1756, 0, 296, 0, 0, 25383),
(1828, 57670, 118, 2, 0, 25383),
(1739, 54265, 118, 2, 0, 25383),
(1738, 47001, 265, 4, 0, 25383),
(1737, 41124, 140, 3, 0, 25383),
(1736, 37338, 119, 2, 0, 25383),
(1481, 32188, 100, 1, 0, 25383),
(1480, 23482, 262, 0, 0, 25383),
(1479, 17365, 262, 0, 0, 25383),
(1478, 13307, 100, 1, 0, 25383),
(1477, 7630, 262, 0, 8214, 25383),
(1476, 0, 262, 0, 0, 25383),
(1446, 4567, 254, 0, 8214, 25383),
(1445, 0, 254, 0, 0, 25383),
(1383, 0, 99, 0, 0, 25383),
(1438, 6072, 0, 0, 8214, 25383),
(1437, 0, 0, 0, 0, 25383),
(1515, 3205, 254, 0, 8214, 25383),
(1514, 0, 254, 0, 0, 25383);

DELETE FROM `conversation_template` WHERE `Id` IN (540, 555, 567, 585, 570, 574, 576, 569, 486, 747, 531, 736, 735, 583, 581, 558, 922, 705);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(540, 1409, 10961, 25383),
(555, 1437, 10021, 25383),
(567, 1469, 3588, 25383),
(585, 1519, 3685, 25383),
(570, 1482, 9983, 25383),
(574, 1493, 4026, 25383),
(576, 1496, 4681, 25383),
(569, 1476, 59154, 25383),
(486, 1298, 8031, 25383),
(747, 1779, 19099, 25383),
(531, 1383, 3347, 25383),
(736, 1756, 30860, 25383),
(735, 1754, 9361, 25383),
(583, 1514, 7207, 25383),
(581, 1511, 5541, 25383),
(558, 1445, 7913, 25383),
(922, 2529, 15140, 25383),
(705, 1683, 13608, 25383);

-- Add some missing quest details
DELETE FROM `quest_details` WHERE `ID` IN (

38729 /*Return to the Black Temple*/, 
38728 /*The Keystone*/, 
39663 /*On Felbat Wings*/, 
39516 /*Cry Havoc and Let Slip the Illidari!*/, 
40051 /*Fel Secrets*/, 
40222 /*The Imp Mother's Tome*/, 
38725 /*Into the Foul Creche*/, 
38819 /*Their Numbers Are Legion*/, 
38727 /*Stop the Bombardment*/, 
39495 /*Hidden No More*/, 
39262 /*Give Me Sight Beyond Sight*/, 
38813 /*Orders for Your Captains*/, 
38766 /*Before We're Overrun*/, 
38765 /*Enter the Illidari: Shivarra*/, 
39050 /*Meeting With the Queen*/, 
39049 /*Eye On the Prize*/, 
38759 /*Set Them Free*/, 
40379 /*Enter the Illidari: Coilskar*/, 
40378 /*Enter the Illidari: Ashtongue*/, 
40077 /*The Invasion Begins*/

);

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(38729, 5, 0, 0, 0, 0, 0, 0, 0, 25383), -- Return to the Black Temple
(38728, 396, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Keystone
(39663, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- On Felbat Wings
(39516, 273, 0, 0, 0, 0, 0, 0, 0, 25383), -- Cry Havoc and Let Slip the Illidari!
(40051, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Fel Secrets
(40222, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- The Imp Mother's Tome
(38725, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Into the Foul Creche
(38819, 1, 25, 0, 0, 0, 0, 0, 0, 25383), -- Their Numbers Are Legion
(38727, 274, 0, 0, 0, 0, 0, 0, 0, 25383), -- Stop the Bombardment
(39495, 1, 25, 0, 0, 0, 0, 0, 0, 25383), -- Hidden No More
(39262, 6, 0, 0, 0, 0, 0, 0, 0, 25383), -- Give Me Sight Beyond Sight
(38813, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Orders for Your Captains
(38766, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Before We're Overrun
(38765, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Enter the Illidari: Shivarra
(39050, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Meeting With the Queen
(39049, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Eye On the Prize
(38759, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Set Them Free
(40379, 1, 0, 0, 0, 0, 0, 0, 0, 25383), -- Enter the Illidari: Coilskar
(40378, 0, 0, 0, 0, 0, 0, 0, 0, 25383), -- Enter the Illidari: Ashtongue
(40077, 0, 0, 0, 0, 0, 0, 0, 0, 25383); -- The Invasion Begins


-- NPC 97059 King Voras 
DELETE FROM `creature_loot_template` WHERE `entry`=97059;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(97059, 130264, 0, 47, 0, 1, 0, 1, 1, 'Fel-Stained Claw'),
(97059, 130265, 0, 38, 0, 1, 0, 1, 1, 'Sharpened Canine'),
(97059, 130266, 0, 18, 0, 1, 0, 1, 1, 'Trophy Spine'),
(97059, 128944, 0, 88, 0, 1, 0, 1, 1, 'Voras Silk Drape');
UPDATE `creature_template` SET `lootid`=97059 WHERE `Entry`=97059;

-- NPC 96493 Felguard Butcher
DELETE FROM `creature_loot_template` WHERE `entry`=96493;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(96493, 129196, 0, 4, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(96493, 130267, 0, 92, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(96493, 130268, 0, 24, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(96493, 130317, 0, 6, 0, 1, 3, 1, 1, 'Fractured Trophy');
UPDATE `creature_template` SET `lootid`=96493 WHERE `Entry`=96493;

-- NPC 97034 Fury Champion
DELETE FROM `creature_loot_template` WHERE `entry`=97034;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(97034, 129196, 0, 3, 0, 1, 0, 1, 1, 'Legion Healthstone'),
(97034, 130267, 0, 93, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(97034, 130268, 0, 23, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(97034, 130317, 0, 6, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(97034, 130264, 0, 0.8, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(97034, 130265, 0, 0.3, 0, 1, 5, 1, 1, 'Sharpened Canine'),
(97034, 130266, 0, 0.14, 0, 1, 6, 1, 1, 'Trophy Spine');
UPDATE `creature_template` SET `lootid`=97034 WHERE `Entry`=97034;

-- NPC 97058 Count Nefarious
DELETE FROM `creature_loot_template` WHERE `entry`=97058;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(97058, 128948, 0, 84, 0, 1, 0, 1, 1, 'Nefarious Ring'),
(97058, 130267, 0, 46, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(97058, 130268, 0, 43, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(97058, 130317, 0, 12, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(97058, 130264, 0, 5, 0, 1, 4, 1, 1, 'Fel-Stained Claw'),
(97058, 130265, 0, 0.8, 0, 1, 5, 1, 1, 'Sharpened Canine');
UPDATE `creature_template` SET `lootid`=97058 WHERE `Entry`=97058;

-- NPC 97370 General Volroth
DELETE FROM `creature_loot_template` WHERE `entry`=97370;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(97370, 128947, 0, 89, 0, 1, 0, 1, 1, 'Pit Lords Cuffs'),
(97370, 130267, 0, 49, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(97370, 130268, 0, 44, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(97370, 130317, 0, 10, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(97370, 133313, 0, 8, 0, 1, 4, 1, 1, 'Pit Lords Cuffs');
UPDATE `creature_template` SET `lootid`=97370 WHERE `Entry`=97370;

-- NPC 97057 Overseer Brutarg
DELETE FROM `creature_loot_template` WHERE `entry`=97057;
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(97057, 133580, 0, 95, 0, 1, 0, 1, 1, 'Brutargs Sword Tip'),
(97057, 130261, 0, 96, 0, 1, 0, 1, 1, 'Brutargs Sword'),
(97057, 130267, 0, 48, 0, 1, 1, 1, 1, 'Extinguished Demon Stone'),
(97057, 130268, 0, 39, 0, 1, 2, 1, 1, 'Bone Toothpick'),
(97057, 130317, 0, 15, 0, 1, 3, 1, 1, 'Fractured Trophy'),
(97057, 130264, 0, 0.7, 0, 1, 4, 1, 1, 'Fel-Stained Claw');
UPDATE `creature_template` SET `lootid`=97057 WHERE `Entry`=97057;


-- Object 244689 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=244689;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES (244689, 129210, 0, 100, 0, 1, 0, 2, 3, 'Fel Crystal Fragments');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (244689, 3, 33263, 'Cofre de Tesoros Pequeño', '', 'Abriendo', '', 1, 57, 244689, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62193, 0, 0, 98, '', '', 22566);

-- Object 244691 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=244691;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`)
VALUES (244691, 129192, 0, 100, 0, 1, 0, 1, 1, 'Inquisitor´s Menacing Eye');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (244691, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 244691, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62194, 0, 0, 98, '', '', 22566);

-- Object 244692 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=244692;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (244692, 129196, 0, 100, 0, 1, 0, 2, 4, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (244692, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 244692, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 62195, 0, 0, 98, '', '', 22566);

-- Object 244694 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=244694;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (244694, 128946, 0, 100, 0, 1, 0, 1, 1, 'Mardum Lord Signet');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (244694, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 244694, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 62196, 0, 0, 98, '', '', 22566);

-- Object 244698 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=244698;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES 
(244698, 129210, 0, 99, 0, 1,  0, 2, 2, 'Fel Crystal Fragments'),
(244698, 129196, 0, 100, 0, 1, 1, 2, 3, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (244698, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 244698, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62197, 0, 0, 98, '', '', 22566);

-- Object 244699 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=244699;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (244699, 129195, 0, 100, 0, 1,  0, 1, 1, 'Vile Stalkerskin Pouch');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (244699, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 244699, 1800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62198, 0, 0, 98, '', '', 22566);

-- Object 244700 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=244700;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (244700, 129210, 0, 100, 0, 1, 0, 2, 3, 'Fel Crystal Fragments');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (244700, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 244700, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62200, 0, 0, 98, '', '', 22566);

-- Object 244701 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=244701;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (244701, 129196, 0, 100, 0, 1, 0, 2, 3, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (244701, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 244701, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62201, 0, 0, 98, '', '', 22566);

-- Object 245316 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=245316;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (245316, 129210, 0, 100, 0, 1, 0, 1, 1, 'Fel Crystal Fragments'),
       (245316, 129196, 0, 100, 0, 1, 1, 1, 3, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (245316, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 245316, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62838, 0, 0, 98, '', '', 22566);

-- Object 245345 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=245345;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (245345, 129210, 0, 100, 0, 1, 0, 1, 3, 'Fel Crystal Fragments'),
       (245345, 129196, 0, 100, 0, 1, 1, 1, 2, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (245345, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 245345, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62839, 0, 0, 98, '', '', 22566);

-- Object 245996 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=245996;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (245996, 129210, 0, 100, 0, 1, 0, 1, 1, 'Fel Crystal Fragments'),
       (245996, 129196, 0, 100, 0, 1, 1, 2, 3, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (245996, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 245996, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1800, 64014, 1, 0, 0, '', '', 22566);

-- Object 246147 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=246147;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (246147, 129210, 0, 100, 0, 1, 0, 2, 3, 'Fel Crystal Fragments');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (246147, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 246147, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64109, 0, 0, 98, '', '', 22566);

-- Object 246249 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=246249;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (246249, 129196, 0, 100, 0, 1, 0, 1, 3, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (246249, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 246249, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64119, 0, 0, 98, '', '', 22566);

-- Object 246269 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=246269;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (246269, 129210, 0, 99, 0, 1,  0, 2, 3, 'Fel Crystal Fragments'),
       (246269, 129196, 0, 100, 0, 1, 1, 2, 4, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (246269, 3, 33263, 'Small Treasure Chest', '', 'Opening', '', 1, 57, 246269, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64137, 0, 0, 98, '', '', 22566);

-- Object 246309 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=246309;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (246309, 129210, 0, 100, 0, 1, 0, 1, 2, 'Fel Crystal Fragments'),
       (246309, 129196, 0, 100, 0, 1, 1, 1, 2, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (246309, 3, 33263, 'Cofre de Tesoros Pequeño', '', 'Abriendo', '', 1, 57, 246309, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64181, 0, 0, 98, '', '', 22566);

-- Object 246353 SmallTreasure Chest
DELETE FROM `gameobject_loot_template` WHERE `Entry`=246353;	
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`,`GroupId`, `MinCount`, `MaxCount`, `Comment`) 
VALUES (246353, 129196, 0, 100, 0, 1, 0, 2, 3, 'Legion Heartstone');
REPLACE INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES (246353, 3, 33263, 'Cofre de Tesoros Pequeño', '', 'Abriendo', '', 1, 57, 246353, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 21400, 0, 0, 0, 110, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64180, 0, 0, 98, '', '', 22566);


-- Table `graveyard_zone`

DELETE FROM `graveyard_zone` WHERE `GhostZone` = 7334;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Faction`, `Comment`) VALUES 
(4949, 7334, 0, '7.0 Azsuna - (01) Azurewing Repose'),
(4950, 7334, 0, '7.0 Azsuna - (02) Crumbled Palace'),
(4951, 7334, 0, '7.0 Azsuna - (03) Ruins of Narthalas'),
(4952, 7334, 0, '7.0 Azsuna - (04) Shipwreck Arena'),
(4953, 7334, 0, '7.0 Azsuna - (05) Oceanus Cove'),
(4954, 7334, 0, '7.0 Azsuna - (06) Illidari Stand'),
(4983, 7334, 0, '7.0 Azsuna - (07) Rhutvan Passage'),
(4984, 7334, 0, '7.0 Azsuna - (08) The Lost Orchard'),
(5010, 7334, 0, '7.0 Azsuna - (10) Makrana'),
(5011, 7334, 0, '7.0 Azsuna - (11) Eldranil Lagoon'),
(5012, 7334, 0, '7.0 Azsuna - (12) Hatecoil Warcamp'),
(5013, 7334, 0, '7.0 Azsuna - (13)  Farondale'),
(5014, 7334, 0, '7.0 Azsuna - (14) Llothien Woods'),
(5015, 7334, 0, '7.0 Azsuna - (15) Timeworn Strand North'),
(5613, 7334, 0, '7.0 Azsuna - (16) Isle of the Watchers Central'),
(5610, 7334, 0, '7.0 Azsuna - (17) Isle of the Watchers East'),
(5612, 7334, 0, '7.0 Azsuna - (18) Isle of the Watchers North'),
(5614, 7334, 0, '7.0 Azsuna - (19) Timeworn Strand South'),
(5621, 7334, 0, '7.0 Azsuna - (20) Illidari Perch'),
(5856, 7334, 0, '7.0 Azsuna - (21) Temple of a Thousand Lights'),
(5675, 7334, 0, '7.0 Azsuna - (22) Rhutvan Divide'),
(5745, 7334, 0, '7.0 Azsuna - (23) Eldranil Peak'),
(5780, 7334, 0, '7.0 Azsuna - (24) Seabreak Isle'),
(5782, 7334, 0, '7.0 Azsuna - (25) Eye of Azshara E'),
(5781, 7334, 0, '7.0 Azsuna - (26) Eye of Azshara W'),
(5652, 7334, 0, '7.0 Azsuna - (21) Timeworn Strand Underwater');

