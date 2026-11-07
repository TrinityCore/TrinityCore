ALTER TABLE `character_aura` 
  ADD COLUMN `dstLocationMapId` int NOT NULL DEFAULT -1 AFTER `castItemLevel`,
  ADD COLUMN `dstLocationX` float NOT NULL DEFAULT 0 AFTER `dstLocationMapId`,
  ADD COLUMN `dstLocationY` float NOT NULL DEFAULT 0 AFTER `dstLocationX`,
  ADD COLUMN `dstLocationZ` float NOT NULL DEFAULT 0 AFTER `dstLocationY`,
  ADD COLUMN `dstLocationO` float NOT NULL DEFAULT 0 AFTER `dstLocationZ`;

ALTER TABLE `pet_aura` 
  ADD COLUMN `dstLocationMapId` int NOT NULL DEFAULT -1 AFTER `remainCharges`,
  ADD COLUMN `dstLocationX` float NOT NULL DEFAULT 0 AFTER `dstLocationMapId`,
  ADD COLUMN `dstLocationY` float NOT NULL DEFAULT 0 AFTER `dstLocationX`,
  ADD COLUMN `dstLocationZ` float NOT NULL DEFAULT 0 AFTER `dstLocationY`,
  ADD COLUMN `dstLocationO` float NOT NULL DEFAULT 0 AFTER `dstLocationZ`;
