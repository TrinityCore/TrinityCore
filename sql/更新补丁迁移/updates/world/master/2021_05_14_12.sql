SET @ID = 29523;
SET @Qtype = 0;


-- ======== QUEST TYPE LIST ========
-- 0  Quest is enabled, but it is auto-completed when accepted; this skips quest objectives and quest details.
-- 1  Quest is disabled (not yet implemented in the core).
-- 2  Quest is enabled (does not auto-complete).
-- 3  Quest is a World Quest.
-- =================================


-- Do not edit below this line
UPDATE quest_template SET QuestType = @Qtype WHERE  ID = @ID;