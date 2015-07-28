-- These creatures should not give quests, they are the objectives of the quests
DELETE FROM creature_questrelation WHERE id IN (49871, 49874, 50047, 42940);
