--
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry` IN (28086, 28085);
UPDATE `smart_scripts` SET `target_type`=21, `target_param1`=8 WHERE `entryorguid` IN (32639, 32638, 32641, 32642) AND `id`=2; -- fix text target for Traveler's Tundra Mammoth's npcs
