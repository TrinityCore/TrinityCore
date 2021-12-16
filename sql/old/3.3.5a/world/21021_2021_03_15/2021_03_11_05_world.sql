-- Previously 23770 was used directly(hack), now it will be correctly triggered
UPDATE `smart_scripts` SET `link` = 0 WHERE `entryorguid` = 14822 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 14822 AND `source_type` = 0 AND `id` = 14;

-- Otherwise third effect of 30058 will be blocked since player is already on taxi
DELETE FROM `spell_custom_attr` WHERE `entry` = 32474;
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(32474,262144);

UPDATE `smart_scripts` SET `action_param1` = 30058, `comment` = "Susurrus - On Gossip Option 0 Selected - Cast 'Buffeting Winds of Susurrus'" WHERE `entryorguid` = 17435 AND `source_type` = 0 AND `id` = 0;
