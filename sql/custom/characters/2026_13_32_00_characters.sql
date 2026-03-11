-- ============================================================================
-- Transmog Outfit System - DoomCore SQL Migration
-- Date: 2026-03-05
-- Description: Creates/updates the character_transmog_outfits table for the
--              outfit-based transmog system (12.0.1+).
-- ============================================================================

-- Create the transmog outfits table if it doesn't already exist
CREATE TABLE IF NOT EXISTS `character_transmog_outfits` (
  `guid` bigint unsigned NOT NULL DEFAULT '0' COMMENT 'Character GUID',
  `setguid` bigint unsigned NOT NULL AUTO_INCREMENT COMMENT 'Unique outfit set GUID',
  `setindex` tinyint unsigned NOT NULL DEFAULT '0' COMMENT 'Outfit index (slot)',
  `name` varchar(128) NOT NULL COMMENT 'Outfit display name',
  `iconname` varchar(256) NOT NULL COMMENT 'Outfit icon identifier',
  `ignore_mask` int NOT NULL DEFAULT '0' COMMENT 'Bitmask of ignored equipment slots',
  `appearance0` int unsigned NOT NULL DEFAULT '0' COMMENT 'Head appearance',
  `appearance1` int unsigned NOT NULL DEFAULT '0' COMMENT 'Neck appearance',
  `appearance2` int unsigned NOT NULL DEFAULT '0' COMMENT 'Shoulder appearance',
  `appearance3` int unsigned NOT NULL DEFAULT '0' COMMENT 'Body appearance',
  `appearance4` int unsigned NOT NULL DEFAULT '0' COMMENT 'Chest appearance',
  `appearance5` int unsigned NOT NULL DEFAULT '0' COMMENT 'Waist appearance',
  `appearance6` int unsigned NOT NULL DEFAULT '0' COMMENT 'Legs appearance',
  `appearance7` int unsigned NOT NULL DEFAULT '0' COMMENT 'Feet appearance',
  `appearance8` int unsigned NOT NULL DEFAULT '0' COMMENT 'Wrists appearance',
  `appearance9` int unsigned NOT NULL DEFAULT '0' COMMENT 'Hands appearance',
  `appearance10` int unsigned NOT NULL DEFAULT '0' COMMENT 'Finger1 appearance',
  `appearance11` int unsigned NOT NULL DEFAULT '0' COMMENT 'Finger2 appearance',
  `appearance12` int unsigned NOT NULL DEFAULT '0' COMMENT 'Trinket1 appearance',
  `appearance13` int unsigned NOT NULL DEFAULT '0' COMMENT 'Trinket2 appearance',
  `appearance14` int unsigned NOT NULL DEFAULT '0' COMMENT 'Back appearance',
  `appearance15` int unsigned NOT NULL DEFAULT '0' COMMENT 'MainHand appearance',
  `appearance16` int unsigned NOT NULL DEFAULT '0' COMMENT 'OffHand appearance',
  `appearance17` int unsigned NOT NULL DEFAULT '0' COMMENT 'Ranged appearance',
  `appearance18` int unsigned NOT NULL DEFAULT '0' COMMENT 'Tabard appearance',
  `mainHandEnchant` int unsigned NOT NULL DEFAULT '0' COMMENT 'MainHand illusion enchant',
  `offHandEnchant` int unsigned NOT NULL DEFAULT '0' COMMENT 'OffHand illusion enchant',
  PRIMARY KEY (`setguid`),
  UNIQUE KEY `idx_set` (`guid`,`setguid`,`setindex`),
  KEY `Idx_setindex` (`guid`,`setindex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COMMENT='Player Transmog Outfits';
