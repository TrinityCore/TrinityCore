ALTER TABLE `quest_tracker`
  DROP PRIMARY KEY,
  ADD UNIQUE INDEX `idx_latest_quest_for_character`(`id`, `character_guid`, `quest_accept_time` DESC);
