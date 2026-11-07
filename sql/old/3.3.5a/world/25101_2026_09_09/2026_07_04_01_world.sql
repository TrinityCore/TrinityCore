ALTER TABLE `quest_request_items` 
  ADD `EmoteOnCompleteDelay` int unsigned NOT NULL DEFAULT 0 AFTER `EmoteOnIncomplete`,
  ADD `EmoteOnIncompleteDelay` int unsigned NOT NULL DEFAULT 0 AFTER `EmoteOnCompleteDelay`;
