-- 
SET @LAMENTER := 39048;
UPDATE `creature_template` SET `AIName`='SmartAI', `InhabitType`=4 WHERE `entry`=@LAMENTER;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LAMENTER AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@LAMENTER*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@LAMENTER, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 80, @LAMENTER*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas'' Lamenter - On Summoned - Action list'),
(@LAMENTER*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 11, 37090, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas'' Lamenter - Action list - Cast Lament of the Highborne: Highborne Aura'),
(@LAMENTER*100, 9, 1, 0, 0, 0, 100,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Sylvanas'' Lamenter - Action list - Set run off"),
(@LAMENTER*100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 114, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas'' Lamenter - Action list - Rise up'),
(@LAMENTER*100, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 4, 15095, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas'' Lamenter - Action list - Play Sound Lament of the Highborne');
