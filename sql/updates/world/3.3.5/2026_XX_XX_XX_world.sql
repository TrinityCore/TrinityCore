ALTER TABLE `creature_template` 
  ADD `StaticFlags1` int unsigned NOT NULL DEFAULT 0 AFTER `StringId`,
  ADD `StaticFlags2` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags1`,
  ADD `StaticFlags3` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags2`,
  ADD `StaticFlags4` int unsigned NOT NULL DEFAULT 0 AFTER `StaticFlags3`;
