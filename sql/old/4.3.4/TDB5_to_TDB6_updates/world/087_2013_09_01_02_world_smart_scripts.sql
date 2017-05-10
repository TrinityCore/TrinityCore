UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (25510,25511,25512,25513);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25510,25511,25512,25513) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25510, 0, 0, 0, 8, 0, 100, 1, 45692, 0, 0, 0, 33, 25510, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '1st Kvaldir Vessel (The Serpent''s Maw) - On Spellhit "Use Tuskarr Torch" - Give Quest Credit'),
(25511, 0, 0, 0, 8, 0, 100, 1, 45692, 0, 0, 0, 33, 25511, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '2nd Kvaldir Vessel (The Kur Drakkar) - On Spellhit "Use Tuskarr Torch" - Give Quest Credit'),
(25512, 0, 0, 0, 8, 0, 100, 1, 45692, 0, 0, 0, 33, 25512, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '3rd Kvaldir Vessel (Bor''s Hammer) - On Spellhit "Use Tuskarr Torch" - Give Quest Credit'),
(25513, 0, 0, 0, 8, 0, 100, 1, 45692, 0, 0, 0, 33, 25513, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, '4th Kvaldir Vessel (Bor''s Anvil) - On Spellhit "Use Tuskarr Torch" - Give Quest Credit');
