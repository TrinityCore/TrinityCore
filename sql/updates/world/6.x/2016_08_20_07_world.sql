ALTER TABLE `creature_addon`
  ADD `aiAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `emote`,
  ADD `movementAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `aiAnimKit`,
  ADD `meleeAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `movementAnimKit`;
ALTER TABLE `creature_template_addon`
  ADD `aiAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `emote`,
  ADD `movementAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `aiAnimKit`,
  ADD `meleeAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `movementAnimKit`;
