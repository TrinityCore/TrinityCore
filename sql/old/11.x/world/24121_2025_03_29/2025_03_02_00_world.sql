ALTER TABLE `gossip_menu_option` MODIFY `BoxMoney` bigint unsigned NOT NULL DEFAULT 0;

UPDATE `gameobject_template` SET `data4`=0x43,`VerifiedBuild`=-ABS(`VerifiedBuild`) WHERE `type`=32 AND `data4`=0;
UPDATE `gameobject_template` SET `data4`=0x10,`VerifiedBuild`=-ABS(`VerifiedBuild`) WHERE `type`=32 AND `data4`=1;
