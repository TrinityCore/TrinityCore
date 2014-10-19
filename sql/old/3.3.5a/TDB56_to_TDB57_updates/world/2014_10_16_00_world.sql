DELETE FROM `creature_text` WHERE `entry` IN(23439,25510,25511,25513,25512);

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`, `BroadcastTextID`) VALUES
(23439, 0, 0, '%s feeds on the freshly-killed warp chaser.', 16, 0, 100, 35, 0, 0, 'Hungry Nether Ray',21657),
(25510, 0, 0, 'The Serpent''s Maw is engulfed in tuskarr fire!', 41, 0, 100, 0, 0, 0, '1st Kvaldir Vessel (The Serpent''s Maw)',24722),
(25512, 0, 0, 'Bor''s Hammer is engulfed in tuskarr fire!', 41, 0, 100, 0, 0, 0, '3rd Kvaldir Vessel (Bor''s Hammer)',24724),
(25511, 0, 0, 'The Kur Drakkar is engulfed in tuskarr fire!', 41, 0, 100, 0, 0, 0, '2nd Kvaldir Vessel (The Kur Drakkar)',24723),
(25513, 0, 0, 'Bor''s Anvil is engulfed in tuskarr fire!', 41, 0, 100, 0, 0, 0, '4th Kvaldir Vessel (Bor''s Anvil)',24725);

UPDATE `smart_scripts` SET `link`=1 WHERE  `entryorguid` IN(25510,25511,25512,25513) AND `source_type`=0 AND `id`=0 AND `link`=0;
UPDATE `smart_scripts` SET `link`=2 WHERE  `entryorguid`=23439 AND `source_type`=0 AND `id`=1 AND `link`=0;

DELETE FROM `smart_scripts`  WHERE `entryorguid` IN(25510,25511,25512,25513) AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts`  WHERE `entryorguid` =23439 AND `source_type`=0 AND `id`=2;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(25510, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '1st Kvaldir Vessel (The Serpent\'s Maw) - On Spellhit \'Use Tuskarr Torch\' - Say'),
(25511, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit \'Use Tuskarr Torch\' - Say'),
(25512, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '3rd Kvaldir Vessel (Bor''s Hammer) - On Spellhit \'Use Tuskarr Torch\' - Say'),
(25513, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '4th Kvaldir Vessel (Bor''s Anvil) - On Spellhit \'Use Tuskarr Torch\' - Say'),
(23439, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hungry Nether Ray - On Data Set 1 1 - Cast \'Lucille Feed Credit Trigger\'');
