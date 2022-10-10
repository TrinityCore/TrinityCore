-- mark as dungeon finder quest

UPDATE quest_template SET SpecialFlags = SpecialFlags | 8 WHERE Id IN
(SELECT firstQuestId FROM lfg_dungeon_rewards);
UPDATE quest_template SET SpecialFlags = SpecialFlags | 8 WHERE Id IN
(SELECT otherQuestId FROM lfg_dungeon_rewards);