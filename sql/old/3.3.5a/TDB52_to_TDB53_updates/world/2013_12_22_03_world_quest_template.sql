-- [FIX] Wrong Previous quest for 12836 Expression of Gratitude
UPDATE `quest_template` SET `PrevQuestId`=12822 WHERE `Id`=12836;
