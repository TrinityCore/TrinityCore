--
UPDATE `gameobject_loot_template` SET `item`=31708 WHERE  `entry`=21872 AND `item`=31709;
UPDATE `gameobject_loot_template` SET `item`=31709 WHERE  `entry`=21870 AND `item`=31708;
UPDATE `smart_scripts` SET `target_type`=1 WHERE  `entryorguid`=1972300 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `smart_scripts` SET `target_type`=1 WHERE  `entryorguid`=1972400 AND `source_type`=9 AND `id`=1 AND `link`=0;
UPDATE `conditions` SET `ElseGroup`=0 WHERE `ConditionValue1` = 13105 AND `SourceEntry` = 13120;
