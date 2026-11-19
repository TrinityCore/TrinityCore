ALTER TABLE `item_sparse` MODIFY `InstanceBound` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `TotemCategoryID`;
ALTER TABLE `item_sparse` MODIFY `LimitCategory` int(11) NOT NULL DEFAULT '0' AFTER `DmgVariance`;
