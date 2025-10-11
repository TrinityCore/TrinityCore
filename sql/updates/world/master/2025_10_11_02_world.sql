-- Questchains
DELETE FROM `quest_template_addon` WHERE `ID` IN (14093,14098,14094,14286,14290,14288,14285,14289,14287,14291,75189,24930,28850,14154,26129,14204,14214,14293,14294,14212,14218,14221,14222);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `BreadcrumbForQuestId`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(14093, 0, 0, 0, 14091, 14099, -14093, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- All Hell Breaks Loose
(14098, 0, 0, 0, 14091, 14099, -14093, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Evacuate the Merchant Square
(14094, 0, 0, 0, 0, 14099, -14093, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Salvage the Supplies
(14286, 0, 0, 0, 14265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Safety in Numbers (Warrior)
(14290, 0, 0, 0, 14275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Safety in Numbers (Hunter)
(14288, 0, 0, 0, 14277, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Safety in Numbers (Mage)
(14285, 0, 0, 0, 14269, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Safety in Numbers (Rogue)
(14289, 0, 0, 0, 14278, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Safety in Numbers (Priest)
(14287, 0, 0, 0, 14273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Safety in Numbers (Warlock)
(14291, 0, 0, 0, 14280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Safety in Numbers (Druid)
(75189, 0, 0, 0, 75190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Safety in Numbers (Monk)
(24930, 0, 0, 0, 0, 14159, -24930, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- While You're At It
(28850, 0, 0, 0, 14157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Prison Rooftop
(14154, 0, 0, 0, 28850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- By the Skin of His Teeth
(26129, 0, 0, 0, 14154, 14159, -24930, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Brothers In Arms
(14204, 0, 0, 0, 14159, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- From the Shadows
(14214, 0, 0, 0, 14204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Message to Greymane
(14293, 0, 0, 0, 14214, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Save Krennan Aranas
(14294, 0, 0, 0, 14293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Time to Regroup
(14212, 0, 0, 0, 14294, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Sacrifices
(14218, 0, 0, 0, 14212, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- By Blood and Ash
(14221, 0, 0, 0, 14218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Never Surrender, Sometimes Retreat
(14222, 0, 0, 0, 14221, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Last Stand

-- Disable Class Quests
DELETE FROM `disables` WHERE (`sourceType` = 1 AND `entry` IN (14283,14266,14272,14274,14281,14279,14276));
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES
(1, 14283, 0, '', '', 'Deprecated quest: Moonfire'),
(1, 14266, 0, '', '', 'Deprecated quest: Charge'),
(1, 14272, 0, '', '', 'Deprecated quest: Eviscerate'),
(1, 14274, 0, '', '', 'Deprecated quest: Corruption'),
(1, 14281, 0, '', '', 'Deprecated quest: Frost Nova'),
(1, 14279, 0, '', '', 'Deprecated quest: Learning the Word'),
(1, 14276, 0, '', '', 'Deprecated quest: Steady Shot');

-- Remove Quest starter- and ender
DELETE FROM `creature_queststarter` WHERE `quest` IN (14283,14266,14272,14274,14281,14279,14276);
DELETE FROM `creature_questender` WHERE `quest` IN (14283,14266,14272,14274,14281,14279,14276);

-- Warrior
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (14265));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 14265, 0, 0, 47, 0, 14099, 64, 0, '', 0, 'Player has Royal Orders (14099) in state rewarded'),
(19, 0, 14265, 0, 0, 15, 0, 1, 0, 0, '', 0, 'Player class is part of classmask Warrior');

-- Hunter
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (14275));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 14275, 0, 0, 47, 0, 14099, 64, 0, '', 0, 'Player has Royal Orders (14099) in state rewarded'),
(19, 0, 14275, 0, 0, 15, 0, 4, 0, 0, '', 0, 'Player class is part of classmask Hunter');

-- Mage
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (14277));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 14277, 0, 0, 47, 0, 14099, 64, 0, '', 0, 'Player has Royal Orders (14099) in state rewarded'),
(19, 0, 14277, 0, 0, 15, 0, 11, 0, 0, '', 0, 'Player class is part of classmask Mage');

-- Rogue
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (14269));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 14269, 0, 0, 47, 0, 14099, 64, 0, '', 0, 'Player has Royal Orders (14099) in state rewarded'),
(19, 0, 14269, 0, 0, 15, 0, 8, 0, 0, '', 0, 'Player class is part of classmask Rogue');

-- Priest
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (14278));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 14278, 0, 0, 47, 0, 14099, 64, 0, '', 0, 'Player has Royal Orders (14099) in state rewarded'),
(19, 0, 14278, 0, 0, 15, 0, 16, 0, 0, '', 0, 'Player class is part of classmask Priest');

-- Warlock
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (14273));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 14273, 0, 0, 47, 0, 14099, 64, 0, '', 0, 'Player has Royal Orders (14099) in state rewarded'),
(19, 0, 14273, 0, 0, 15, 0, 256, 0, 0, '', 0, 'Player class is part of classmask Warlock');

-- Druid
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (14280));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 14280, 0, 0, 47, 0, 14099, 64, 0, '', 0, 'Player has Royal Orders (14099) in state rewarded'),
(19, 0, 14280, 0, 0, 15, 0, 1024, 0, 0, '', 0, 'Player class is part of classmask Druid');

-- Monk
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (75190));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 75190, 0, 0, 47, 0, 14099, 64, 0, '', 0, 'Player has Royal Orders (14099) in state rewarded'),
(19, 0, 75190, 0, 0, 15, 0, 512, 0, 0, '', 0, 'Player class is part of classmask Monk');

-- Old Divison
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (14157));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 14157, 0, 0, 8, 0, 14286, 0, 0, '', 0, 'Player has quest Safety in Numbers (14286) rewarded'),
(19, 0, 14157, 0, 1, 8, 0, 14290, 0, 0, '', 0, 'Player has quest Safety in Numbers (14290) rewarded'),
(19, 0, 14157, 0, 2, 8, 0, 14288, 0, 0, '', 0, 'Player has quest Safety in Numbers (14288) rewarded'),
(19, 0, 14157, 0, 3, 8, 0, 14285, 0, 0, '', 0, 'Player has quest Safety in Numbers (14285) rewarded'),
(19, 0, 14157, 0, 4, 8, 0, 14289, 0, 0, '', 0, 'Player has quest Safety in Numbers (14289) rewarded'),
(19, 0, 14157, 0, 5, 8, 0, 14287, 0, 0, '', 0, 'Player has quest Safety in Numbers (14287) rewarded'),
(19, 0, 14157, 0, 6, 8, 0, 14291, 0, 0, '', 0, 'Player has quest Safety in Numbers (14291) rewarded'),
(19, 0, 14157, 0, 7, 8, 0, 75189, 0, 0, '', 0, 'Player has quest Safety in Numbers (75189) rewarded');

-- While Youre At It
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 19) AND (`SourceEntry` IN (24930));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(19, 0, 24930, 0, 0, 8, 0, 14286, 0, 0, '', 0, 'Player has quest Safety in Numbers (14286) rewarded'),
(19, 0, 24930, 0, 1, 8, 0, 14290, 0, 0, '', 0, 'Player has quest Safety in Numbers (14290) rewarded'),
(19, 0, 24930, 0, 2, 8, 0, 14288, 0, 0, '', 0, 'Player has quest Safety in Numbers (14288) rewarded'),
(19, 0, 24930, 0, 3, 8, 0, 14285, 0, 0, '', 0, 'Player has quest Safety in Numbers (14285) rewarded'),
(19, 0, 24930, 0, 4, 8, 0, 14289, 0, 0, '', 0, 'Player has quest Safety in Numbers (14289) rewarded'),
(19, 0, 24930, 0, 5, 8, 0, 14287, 0, 0, '', 0, 'Player has quest Safety in Numbers (14287) rewarded'),
(19, 0, 24930, 0, 6, 8, 0, 14291, 0, 0, '', 0, 'Player has quest Safety in Numbers (14291) rewarded'),
(19, 0, 24930, 0, 7, 8, 0, 75189, 0, 0, '', 0, 'Player has quest Safety in Numbers (75189) rewarded');
