--
SET @Deathguards:= 44795;
SET @CreditKill := 44175;
SET @Dummy      := 44794;

UPDATE `creature_template` SET `AIName`='SmartAI', `scriptName`='' WHERE `entry`=@Dummy;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (@Deathguards, @CreditKill);

DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dummy  AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Dummy*100  AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Deathguards  AND `source_type` = 0;

INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@Deathguards, 0, 0, 0, 8, 0, 100, 0, 2061, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Deathguards - On spellHit - CreditKill'), -- Priest
(@Dummy, 0, 0, 0, 8, 0, 100, 0, 56641, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- hunter
(@Dummy, 0, 1, 0, 8, 0, 100, 0, 5143, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- Mage
(@Dummy, 0, 2, 0, 8, 0, 100, 0, 2098, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- Rogue
(@Dummy, 0, 3, 0, 8, 0, 100, 0, 348, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- Warlock
(@Dummy, 0, 4, 0, 8, 0, 100, 0, 100, 0, 0, 0, 33, @CreditKill, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On spellHit - CreditKill'), -- Warrior
(@Dummy, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 80, @Dummy*100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dummy - On reset - action list'),
(@Dummy*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' Argent - action list - react passif'),
(@Dummy*100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 42, 0, 100, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ' Argent - action list - set invinsible');
