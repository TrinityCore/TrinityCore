ALTER TABLE `creature_template_difficulty` 
  ADD `StaticFlags1` int unsigned NOT NULL DEFAULT 0 AFTER `GoldMax`,
  ADD `StaticFlags2` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags1`,
  ADD `StaticFlags3` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags2`,
  ADD `StaticFlags4` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags3`,
  ADD `StaticFlags5` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags4`,
  ADD `StaticFlags6` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags5`,
  ADD `StaticFlags7` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags6`,
  ADD `StaticFlags8` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags7`;
