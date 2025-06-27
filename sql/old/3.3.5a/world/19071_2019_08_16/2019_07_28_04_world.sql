-- Nolkai's Words
UPDATE `gameobject_template` SET `AIName`="" WHERE `entry`=181758;
DELETE FROM `smart_scripts` WHERE `entryorguid`=181758 AND `source_type`=1;
UPDATE `quest_template` SET `RewardItem1`=23846, `RewardAmount1`=1 WHERE `ID`=9561;

-- Ally of the Netherwing
UPDATE `quest_template` SET `RewardChoiceItemID1`=31492, `RewardChoiceItemID2`=31491, `RewardChoiceItemID3`=31490, `RewardChoiceItemID4`=31494, `RewardChoiceItemID5`=31493, `RewardChoiceItemQuantity1`=1, `RewardChoiceItemQuantity2`=1, `RewardChoiceItemQuantity3`=1, `RewardChoiceItemQuantity4`=1, `RewardChoiceItemQuantity5`=1 WHERE `ID`=10870;

-- He Will Walk The Earth...
UPDATE `quest_template` SET `RewardChoiceItemID1`=25574, `RewardChoiceItemID2`=25575, `RewardChoiceItemID3`=25576, `RewardChoiceItemQuantity1`=1, `RewardChoiceItemQuantity2`=1, `RewardChoiceItemQuantity3`=1 WHERE `ID`=9866;

-- Hero of the Mag'har
UPDATE `quest_template` SET `RewardItem1`=28168, `RewardAmount1`=1, `RewardChoiceItemID1`=28173, `RewardChoiceItemID2`=28169, `RewardChoiceItemID3`=28172, `RewardChoiceItemID4`=28175, `RewardChoiceItemQuantity1`=1, `RewardChoiceItemQuantity2`=1, `RewardChoiceItemQuantity3`=1, `RewardChoiceItemQuantity4`=1 WHERE `ID`=10212;
