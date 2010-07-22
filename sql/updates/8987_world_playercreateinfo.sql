
ALTER TABLE `playercreateinfo`
  ADD COLUMN `orientation` float NOT NULL DEFAULT 0 AFTER `position_z`;
