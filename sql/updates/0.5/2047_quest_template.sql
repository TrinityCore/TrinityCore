UPDATE `quest_template`
    SET `SpecialFlags` = `SpecialFlags` | `QuestFlags`;

ALTER TABLE `quest_template`
    DROP `QuestFlags`;
