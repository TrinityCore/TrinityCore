-- http://www.wowwiki.com/Goblin_starting_experience

-- Taking Care of Business
UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 14069, `ExclusiveGroup` = 0 WHERE `Id` = 14138;
-- Good Help is Hard to Find
DELETE FROM `creature_questrelation` WHERE `id` = 34830;
UPDATE `quest_template` SET `PrevQuestId` = 14138, `NextQuestId` = 25473, `ExclusiveGroup` = -14069 WHERE `Id` = 14069;
-- Trouble in the Mines
DELETE FROM `creature_questrelation` WHERE `id` = 34865;
UPDATE `quest_template` SET `PrevQuestId` = 14138, `NextQuestId` = 25473, `ExclusiveGroup` = -14069 WHERE `Id` = 14075;
-- Kaja'Cola
UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 28349, `ExclusiveGroup` = 0 WHERE `Id` = 25473;
-- Megs in Marketing
UPDATE `quest_template` SET `PrevQuestId` = 25473, `NextQuestId` = 14071, `ExclusiveGroup` = 0 WHERE `Id` = 28349;
-- Rolling with my Homies
UPDATE `quest_template` SET `PrevQuestId` = 28349, `NextQuestId` = 24567, `ExclusiveGroup` = 0 WHERE `Id` = 14071;
-- Report for Tryouts
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 24488, `ExclusiveGroup` = 0 WHERE `Id` = 24567;
-- The Replacements
UPDATE `quest_template` SET `PrevQuestId` = 24567, `NextQuestId` = 24502, `ExclusiveGroup` = 0 WHERE `Id` = 24488;
-- Necessary Roughness
UPDATE `quest_template` SET `PrevQuestId` = 24488, `NextQuestId` = 28414, `ExclusiveGroup` = 0 WHERE `Id` = 24502;
-- Fourth and Goal
UPDATE `quest_template` SET `PrevQuestId` = 24502, `NextQuestId` = 24520, `ExclusiveGroup` = 0 WHERE `Id` = 28414;
-- Give Sassy the News
UPDATE `quest_template` SET `PrevQuestId` = 28414, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 24520;

-- Do it Yourself
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id` = 14070;
-- Off to the Bank
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 14110, `ExclusiveGroup` = 26711 WHERE `Id` = 26711;
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 14109, `ExclusiveGroup` = 26711 WHERE `Id` = 26712;
-- The New You
UPDATE `quest_template` SET `PrevQuestId` = 26712, `NextQuestId` = 14113, `ExclusiveGroup` = 0 WHERE `Id` = 14109;
UPDATE `quest_template` SET `PrevQuestId` = 26711, `NextQuestId` = 14153, `ExclusiveGroup` = 0 WHERE `Id` = 14110;

-- Steady Shot 
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14007;
-- Frost Nova 
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14008;
-- Learning the Word 
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14009;
-- Eviscerate 
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14010;
-- Primal Strike 
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14011;
-- Corruption 
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14012;
-- Charge 
UPDATE `quest_template` SET `PrevQuestId` = 14071, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14013;

/* conditions */

/**************/

-- Life of the Party
UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 14115, `ExclusiveGroup` = 14113 WHERE `Id`= 14113;
UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 14115, `ExclusiveGroup` = 14113 WHERE `Id`= 14153;
-- Pirate Party Crashers
UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 14116, `ExclusiveGroup` = 0 WHERE `Id`= 14115;
-- The Uninvited Guest
UPDATE `quest_template` SET `PrevQuestId` = 14115, `NextQuestId` = 14120, `ExclusiveGroup` = 0 WHERE `Id`= 14116;
-- A Bazillion Macaroons?!
UPDATE `quest_template` SET `PrevQuestId` = 14116, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14120;

-- Robbing Hoods
UPDATE `quest_template` SET `PrevQuestId` = 14120, `NextQuestId` = 14125, `ExclusiveGroup` = -14124 WHERE `Id`= 14121;
-- The Great Bank Heist
UPDATE `quest_template` SET `PrevQuestId` = 14120, `NextQuestId` = 14125, `ExclusiveGroup` = -14124 WHERE `Id`= 14122;
-- Waltz Right In
UPDATE `quest_template` SET `PrevQuestId` = 14120, `NextQuestId` = 14125, `ExclusiveGroup` = -14124 WHERE `Id`= 14123;
-- Liberate the Kaja'mite
UPDATE `quest_template` SET `PrevQuestId` = 14120, `NextQuestId` = 14125, `ExclusiveGroup` = -14124 WHERE `Id`= 14124;

-- 447
UPDATE `quest_template` SET `PrevQuestId` = 0, `NextQuestId` = 14126, `ExclusiveGroup` = 0 WHERE `Id`= 14125;
-- Life Savings
UPDATE `quest_template` SET `PrevQuestId` = 14125, `NextQuestId` = 0, `ExclusiveGroup` = 0 WHERE `Id`= 14126;
