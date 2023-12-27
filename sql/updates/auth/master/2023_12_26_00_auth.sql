ALTER TABLE `battlenet_accounts`
  ADD `srp_version` tinyint(3) NOT NULL DEFAULT '1' AFTER `email`,
  ADD `salt` binary(32) AFTER `srp_version`,
  ADD `verifier` blob AFTER `salt`;
