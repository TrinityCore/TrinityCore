UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE  `ID`=1144;
UPDATE `creature_template` SET `flags_extra`=64 WHERE  `entry` IN(28111,28112,28078,28079,23667, 23668, 32669,28844,28843,24199,24198,23564);
UPDATE `reference_loot_template` SET `GroupId`=2 WHERE  `Entry`=34203 AND `Item`=43959;
UPDATE `smart_scripts` SET `target_type`=12, `target_param1`=1 WHERE  `entryorguid`=2735500 AND `source_type`=9 AND `id`=5 AND `link`=0;
UPDATE `gameobject` SET `position_x`=5445.057129, `position_y`=4908.831543, `position_z`=-189.508224 WHERE  `guid`=99748;
