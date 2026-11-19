ALTER TABLE `smart_scripts`
  ADD `action_param_string` VARCHAR(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL AFTER `action_param7`,
  ADD `target_param_string` VARCHAR(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL AFTER `target_param4`;
