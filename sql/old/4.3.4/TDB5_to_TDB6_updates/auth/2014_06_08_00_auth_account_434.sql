ALTER TABLE `account`
  ADD `battlenet_index` tinyint(3) unsigned DEFAULT NULL AFTER `battlenet_account`,
  ADD UNIQUE KEY `uk_bnet_acc` (`battlenet_account`, `battlenet_index`);
