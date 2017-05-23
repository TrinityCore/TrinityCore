--
UPDATE `quest_template` SET `RewardBonusMoney`= 60, -- 60 copper
 `RewardChoiceItemID1`= 159, `RewardChoiceItemQuantity1`= 5, -- Refreshing Spring Water
 `RewardChoiceItemID2`= 4536, `RewardChoiceItemQuantity2`= 5, -- Shiny Red Apple
 `RewardFactionValue1`= 2, `RewardFactionOverride1`= 0 -- column values swapped
WHERE `ID`= 8350;
