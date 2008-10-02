ALTER TABLE `item_template` 
  ADD `Duration` int(11) NOT NULL DEFAULT '0' COMMENT 'Duration in seconds. Negative value means realtime, postive value ingame time';
