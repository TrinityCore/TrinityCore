ALTER TABLE `mail`
  ADD COLUMN `stationery` tinyint(3) NOT NULL DEFAULT '41' AFTER `messageType`;