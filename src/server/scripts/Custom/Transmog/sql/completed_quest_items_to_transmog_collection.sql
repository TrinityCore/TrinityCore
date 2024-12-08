-- Change all occurrences of world_database to your world database name.
-- Change all occurrences of characters_database to your characters database name.

-- This SQL will first store all quest items in a table. The table is temporary and is automatically deleted once SQL client disconnects.
-- It then selects all completed quests of a player and inserts the reward items of that quest to the player account's transmog library.

USE world_database;

CREATE TEMPORARY TABLE IF NOT EXISTS characters_database.transmog__quest_reward_items (INDEX(ID)) AS (
SELECT * FROM (
SELECT quest_template.id AS ID, RewardChoiceItemID1 AS RewardItemID FROM quest_template WHERE RewardChoiceItemID1 <> 0 AND RewardChoiceItemQuantity1 <> 0
UNION
SELECT quest_template.id AS ID, RewardChoiceItemID2 AS RewardItemID FROM quest_template WHERE RewardChoiceItemID2 <> 0 AND RewardChoiceItemQuantity2 <> 0
UNION
SELECT quest_template.id AS ID, RewardChoiceItemID3 AS RewardItemID FROM quest_template WHERE RewardChoiceItemID3 <> 0 AND RewardChoiceItemQuantity3 <> 0
UNION
SELECT quest_template.id AS ID, RewardChoiceItemID4 AS RewardItemID FROM quest_template WHERE RewardChoiceItemID4 <> 0 AND RewardChoiceItemQuantity4 <> 0
UNION
SELECT quest_template.id AS ID, RewardChoiceItemID5 AS RewardItemID FROM quest_template WHERE RewardChoiceItemID5 <> 0 AND RewardChoiceItemQuantity5 <> 0
UNION
SELECT quest_template.id AS ID, RewardChoiceItemID6 AS RewardItemID FROM quest_template WHERE RewardChoiceItemID6 <> 0 AND RewardChoiceItemQuantity6 <> 0
UNION
SELECT quest_template.id AS ID, RewardItem1 AS RewardItemID FROM quest_template WHERE RewardItem1 <> 0 AND RewardAmount1 <> 0
UNION
SELECT quest_template.id AS ID, RewardItem2 AS RewardItemID FROM quest_template WHERE RewardItem2 <> 0 AND RewardAmount2 <> 0
UNION
SELECT quest_template.id AS ID, RewardItem3 AS RewardItemID FROM quest_template WHERE RewardItem3 <> 0 AND RewardAmount3 <> 0
UNION
SELECT quest_template.id AS ID, RewardItem4 AS RewardItemID FROM quest_template WHERE RewardItem4 <> 0 AND RewardAmount4 <> 0
) x
);

USE characters_database;

REPLACE INTO custom_account_transmog (accountid, `type`, entry) SELECT c.account, 0, tqri.RewardItemID FROM transmog__quest_reward_items tqri INNER JOIN character_queststatus_rewarded cqr ON tqri.ID = cqr.quest INNER JOIN characters c ON c.guid = cqr.guid;
