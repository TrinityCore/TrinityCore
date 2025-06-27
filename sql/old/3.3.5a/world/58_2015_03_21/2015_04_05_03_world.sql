--
UPDATE `creature` SET `spawnMask`=1 WHERE `map`=429;
UPDATE `gameobject` SET `spawnMask`=1 WHERE `map`=429;
UPDATE `quest_template` SET `RewardChoiceItemCount1`=1, `RewardChoiceItemCount2`=1, `RewardChoiceItemCount3`=1, `RewardChoiceItemCount4`=1, `RewardChoiceItemCount5`=1, `RewardChoiceItemCount6`=1 WHERE `Id` IN (10645,10639);
