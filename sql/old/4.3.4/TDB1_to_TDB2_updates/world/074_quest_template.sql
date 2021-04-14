-- Chain data for some quests in Valley of Trials
UPDATE `quest_template` SET `PrevQuestId`=25152 WHERE `Id`=25126; -- "Your place in the world" and "Cutting Teeth"
UPDATE `quest_template` SET `PrevQuestId`=25126 WHERE `Id`=25172; -- "Cutting Theeth" and "Invaders in our Home"
UPDATE `quest_template` SET `PrevQuestId`=25126 WHERE `Id`=25136; -- "Cutting Theeth" and "Galgar's Cactus Apple Surprise"

-- Class-specific quests
UPDATE `quest_template` SET `PrevQuestId`=25126 WHERE `Id`=2383; -- "Cutting Theeth" and "Simple Parchment" (Warrior)


UPDATE `quest_template` SET `PrevQuestId`=25172 WHERE `Id`=25127; -- "Invaders in our home" and "Sting of the Scorpid"
UPDATE `quest_template` SET `PrevQuestId`=25127 WHERE `Id`=25131; -- "Sting of the Scorpid" and "Vile Familiars"
UPDATE `quest_template` SET `PrevQuestId`=25131 WHERE `Id`=25132; -- "Vile Familiars" and "Burning Blade Medallion"
UPDATE `quest_template` SET `PrevQuestId`=25132 WHERE `Id`=25133; -- "Burning Blade Medallion" and "Report to Sen'jin Village"
UPDATE `quest_template` SET `PrevQuestId`=25127 WHERE `Id`=25128; -- "Sting of the Scorpid" and "Hana'Zua"
UPDATE `quest_template` SET `PrevQuestId`=25128 WHERE `Id`=25129; -- "Hana'zua" and "Sarkoth"
UPDATE `quest_template` SET `PrevQuestId`=25129 WHERE `Id`=25130; -- "Sarkoth" and "Back to the Den"
