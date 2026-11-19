ALTER TABLE `battle_pets`
  ADD `owner` bigint(20) DEFAULT NULL AFTER `nameTimestamp`,
  ADD `ownerRealmId` int(11) DEFAULT NULL AFTER `owner`;
