ALTER TABLE `account`
  MODIFY `last_ip` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1' AFTER `joindate`,
  MODIFY `last_attempt_ip` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1' AFTER `last_ip`;

ALTER TABLE `battlenet_accounts` 
  MODIFY `last_ip` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1' AFTER `joindate`;

ALTER TABLE `ip_banned` 
  MODIFY `ip` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1' FIRST;

ALTER TABLE `logs_ip_actions` 
  MODIFY `ip` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '127.0.0.1' AFTER `type`;
