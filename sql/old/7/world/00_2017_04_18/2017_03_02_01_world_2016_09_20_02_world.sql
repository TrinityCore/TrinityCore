-- uint8 -> uint16 for chain ID
ALTER TABLE `script_spline_chain_meta` MODIFY COLUMN `chainId` SMALLINT UNSIGNED NOT NULL;
ALTER TABLE `script_spline_chain_waypoints` MODIFY COLUMN `chainId` SMALLINT UNSIGNED NOT NULL;
