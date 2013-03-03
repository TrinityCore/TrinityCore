ALTER TABLE `item_refund_instance`
ADD `count` int(10) UNSIGNED NOT NULL DEFAULT 1 AFTER `item_guid`;
