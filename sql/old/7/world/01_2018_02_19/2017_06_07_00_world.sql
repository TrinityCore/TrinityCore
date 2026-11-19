-- Quests: Those That Couldn't Be Saved (26799) / Recruitment (26800)
-- make the quest rewards selectable for all classes, not only some of them
UPDATE `quest_template` SET `RewardChoiceItemID1`= 3275, `RewardChoiceItemQuantity1`=1, `RewardChoiceItemID2`=11847, `RewardChoiceItemQuantity2`=1 WHERE `ID`=26799;
UPDATE `quest_template` SET `RewardChoiceItemID1`=11848, `RewardChoiceItemQuantity1`=1, `RewardChoiceItemID2`=11849, `RewardChoiceItemQuantity2`=1, `RewardChoiceItemID3`=11850, `RewardChoiceItemQuantity3`=1 WHERE `ID`=26800;
