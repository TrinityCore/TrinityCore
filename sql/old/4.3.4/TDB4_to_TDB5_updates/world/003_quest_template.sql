-- Join the Battle!
UPDATE `quest_template` SET `RequiredClasses`=1, `RequiredRaces`=1101 WHERE `Id`=28789; -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=2, `RequiredRaces`=1101 WHERE `Id`=28785; -- Paladin
UPDATE `quest_template` SET `RequiredClasses`=4, `RequiredRaces`=1101 WHERE `Id`=28780; -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=16, `RequiredRaces`=1101 WHERE `Id`=28786; -- Priest
UPDATE `quest_template` SET `RequiredClasses`=128, `RequiredRaces`=1101 WHERE `Id`=28784; -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256, `RequiredRaces`=1101 WHERE `Id`=28788; -- Warlock

-- They Sent Assassins!
UPDATE `quest_template` SET `RequiredClasses`=1, `RequiredRaces`=1101, `PrevQuestId`=28789 WHERE `Id`=28797; -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=2, `RequiredRaces`=1101, `PrevQuestId`=28785 WHERE `Id`=28793; -- Paladin
UPDATE `quest_template` SET `RequiredClasses`=4, `RequiredRaces`=1101, `PrevQuestId`=28780 WHERE `Id`=28791; -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=16, `RequiredRaces`=1101, `PrevQuestId`=28786 WHERE `Id`=28794; -- Priest
UPDATE `quest_template` SET `RequiredClasses`=128, `RequiredRaces`=1101, `PrevQuestId`=28784 WHERE `Id`=28792; -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256, `RequiredRaces`=1101, `PrevQuestId`=28788 WHERE `Id`=28796; -- Warlock 

-- The Rear Is Clear
UPDATE `quest_template` SET `RequiredClasses`=1, `RequiredRaces`=1101, `PrevQuestId`=28797  WHERE `Id`=28823; -- Warrior
UPDATE `quest_template` SET `RequiredClasses`=2, `RequiredRaces`=1101, `PrevQuestId`=28793  WHERE `Id`=28819; -- Paladin
UPDATE `quest_template` SET `RequiredClasses`=4, `RequiredRaces`=1101, `PrevQuestId`=28791  WHERE `Id`=28817; -- Hunter
UPDATE `quest_template` SET `RequiredClasses`=16, `RequiredRaces`=1101, `PrevQuestId`=28794  WHERE `Id`=28820; -- Priest
UPDATE `quest_template` SET `RequiredClasses`=128, `RequiredRaces`=1101, `PrevQuestId`=28792  WHERE `Id`=28818; -- Mage
UPDATE `quest_template` SET `RequiredClasses`=256, `RequiredRaces`=1101, `PrevQuestId`=28796  WHERE `Id`=28822; -- Warlock 
