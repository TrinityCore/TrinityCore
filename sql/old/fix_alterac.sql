-- Cold Forged Hammer available earlier than retail since 1.5 release was
-- borked and the Korrak quest had no rewards associated with it
UPDATE `item_template` SET `patch` = 3 WHERE `entry` = 20648 AND `patch` = 6;

-- Likewise with the Hero of the Frostwolf/Stormpike quests
UPDATE `quest_template` 
    SET `patch` = 3, `Method` = `Method` & ~1
    WHERE `entry` IN (8271, 8272) AND `patch` = 6;

UPDATE `creature_questrelation` SET `patch` = 3 WHERE `quest` IN (8271, 8272);
UPDATE `creature_involvedrelation` SET `patch` = 3 WHERE `quest` IN (8271, 8272);

-- Remove base level Korrak rewards
UPDATE `quest_template` 
    SET `RewChoiceItemId1` = 0, `RewChoiceItemId2` = 0, `RewChoiceItemId3` = 0, 
        `RewChoiceItemCount1` = 0, `RewChoiceItemCount2` = 0, `RewChoiceItemCount3` = 0
    WHERE `entry` IN (7181, 7202) AND `patch` = 3;
