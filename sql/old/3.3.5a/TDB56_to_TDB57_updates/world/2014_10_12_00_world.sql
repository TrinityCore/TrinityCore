-- Spectral Stable Hand SAI
SET @ENTRY := 15551;
UPDATE `smart_scripts` SET `event_chance`=50 WHERE `entryorguid`=@ENTRY AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=5;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 5, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Stable Hand - On Aggro - Talk');

-- Spectral Apprentice SAI
SET @ENTRY := 16389;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (0, 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Apprentice - On Aggro - Talk'), 
(@ENTRY, 0, 1, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Apprentice - On Death - Talk');

-- Phantom Attendant SAI
SET @ENTRY := 16406;
UPDATE `smart_scripts` SET `event_chance`=100, `event_flags`=0 WHERE `entryorguid`=@ENTRY AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (4, 5);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 4, 0, 4, 0, 10, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Attendant - On Aggro - Talk'),
(@ENTRY, 0, 5, 0, 6, 0, 10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Attendant - On Death - Talk');

-- Spectral Servant SAI
SET @ENTRY := 16407;
UPDATE `smart_scripts` SET `event_chance`=50 WHERE `entryorguid`=@ENTRY AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 3, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Servant - On Aggro - Talk');

-- Phantom Valet SAI
SET @ENTRY := 16408;
UPDATE `smart_scripts` SET `event_chance`=50 WHERE `entryorguid`=@ENTRY AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 2, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Valet - On Aggro - Talk');

-- Phantom Guest SAI
SET @ENTRY := 16409;
UPDATE `smart_scripts` SET `event_chance`=10, `event_flags`=0 WHERE `entryorguid`=@ENTRY AND `id`=6;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=7;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 7, 0, 4, 0, 10, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guest - On Aggro - Talk');

-- Spectral Retainer SAI
SET @ENTRY := 16410;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (0, 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Retainer - On Aggro - Talk'), 
(@ENTRY, 0, 1, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Retainer - On Death - Talk');

-- Spectral Chef SAI
SET @ENTRY := 16411;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (2, 3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 2, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Chef - On Aggro - Talk'), 
(@ENTRY, 0, 3, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Chef - On Death - Talk');

-- Ghostly Baker SAI
SET @ENTRY := 16412;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (0, 1);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostly Baker - On Aggro - Talk'), 
(@ENTRY, 0, 1, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostly Baker - On Death - Talk');

-- Spectral Sentry SAI
SET @ENTRY := 16424;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (1, 2);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 1, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Sentry - On Aggro - Talk'), 
(@ENTRY, 0, 2, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Sentry - On Death - Talk');

-- Phantom Guardsman SAI
SET @ENTRY := 16425;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (2, 3);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 2, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guardsman - On Aggro - Talk'), 
(@ENTRY, 0, 3, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Guardsman - On Death - Talk');

-- Wanton Hostess SAI
SET @ENTRY := 16459;
UPDATE `smart_scripts` SET `event_flags`=1 WHERE `entryorguid`=@ENTRY AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (5, 6, 7, 8);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 5, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wanton Hostess - On Aggro - Talk'), 
(@ENTRY, 0, 6, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wanton Hostess - On Death - Talk'),
(@ENTRY, 0, 7, 0, 2, 0, 100, 1, 0, 50, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wanton Hostess - On Transform - Talk'),
(@ENTRY, 0, 8, 0, 1, 0, 50, 0, 0, 40000, 45000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Wanton Hostess -  Out of Combat - Talk');

-- Night Mistress SAI
SET @ENTRY := 16460;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (4, 5, 6, 7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 4, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Night Mistress - On Aggro - Talk'), 
(@ENTRY, 0, 5, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Night Mistress - On Death - Talk'),
(@ENTRY, 0, 6, 0, 2, 0, 100, 1, 0, 50, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Night Mistress - On Transform - Talk'),
(@ENTRY, 0, 7, 0, 1, 0, 50, 0, 0, 40000, 45000, 120000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Night Mistress -  Out of Combat - Talk');

-- Concubine SAI
SET @ENTRY := 16461;
UPDATE `smart_scripts` SET `action_param1`=2, `comment`='Concubine - Death - Talk' WHERE `entryorguid`=@ENTRY AND `id`=3;
UPDATE `smart_scripts` SET `event_flags`=0, `event_param2`=40000, `event_param3`=45000, `event_param4`=120000, `action_param1`=0, `comment`='Concubine - Out of Combat - Talk' WHERE `entryorguid`=@ENTRY AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (6, 7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 6, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Concubine - On Aggro - Talk'), 
(@ENTRY, 0, 7, 0, 2, 0, 100, 1, 0, 50, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Concubine - On Transform - Talk');

-- Spectral Patron SAI
SET @ENTRY := 16468;
UPDATE `smart_scripts` SET `event_chance`=10 WHERE `entryorguid`=@ENTRY AND `id`=2; -- comment tbh
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 3, 0, 4, 0, 10, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Patron - On Aggro - Talk');

-- Ghostly Philanthropist SAI
SET @ENTRY := 16470;
UPDATE `smart_scripts` SET `event_chance`=50 WHERE `entryorguid`=@ENTRY AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 3, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghostly Philanthropist - On Aggro - Talk');

-- Skeletal Usher SAI
SET @ENTRY := 16471;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 3, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Usher - On Aggro - Talk'), 
(@ENTRY, 0, 4, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Skeletal Usher - On Death - Talk');

-- Phantom Stagehand SAI
SET @ENTRY := 16472;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 3, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Stagehand - On Aggro - Talk'), 
(@ENTRY, 0, 4, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Phantom Stagehand - On Death - Talk');

-- Phantom Guardsman SAI
SET @ENTRY := 16473;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id` IN (3, 4);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 3, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Performer - On Aggro - Talk'), 
(@ENTRY, 0, 4, 0, 6, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spectral Performer - On Death - Talk');

-- Ghastly Haunt SAI
SET @ENTRY := 16481;
UPDATE `smart_scripts` SET `event_chance`=50 WHERE `entryorguid`=@ENTRY AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 3, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ghastly Haunt - On Aggro - Talk');

-- Trapped Soul SAI
SET @ENTRY := 16482;
UPDATE `smart_scripts` SET `event_chance`=50 WHERE `entryorguid`=@ENTRY AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=3;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 3, 0, 4, 0, 50, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Trapped Soul - On Aggro - Talk');


UPDATE `creature_text` SET `type`=12 WHERE `entry`=16414 AND `groupid`=0 AND `id`=2; -- Ghostly Steward
UPDATE `creature_text` SET `type`=12 WHERE `entry`=16470 AND `groupid`=0 AND `id`=1; -- Ghostly Philanthropist

DELETE FROM `creature_text` WHERE (`entry`=15551 AND `groupid`=1 AND `id`=0) OR (`entry`=15551 AND `groupid`=1 AND `id`=1) OR (`entry`=16389 AND `groupid`=0 AND `id`=0) OR (`entry`=16389 AND `groupid`=0 AND `id`=1) OR (`entry`=16389 AND `groupid`=1 AND `id`=0) OR (`entry`=16389 AND `groupid`=1 AND `id`=1) OR (`entry`=16406 AND `groupid`=0 AND `id`=2) OR (`entry`=16406 AND `groupid`=1 AND `id`=0) OR (`entry`=16406 AND `groupid`=1 AND `id`=1) OR (`entry`=16406 AND `groupid`=1 AND `id`=2) OR (`entry`=16407 AND `groupid`=1 AND `id`=0) OR (`entry`=16407 AND `groupid`=1 AND `id`=1) OR (`entry`=16407 AND `groupid`=1 AND `id`=2) OR (`entry`=16408 AND `groupid`=0 AND `id`=1) OR (`entry`=16408 AND `groupid`=0 AND `id`=2) OR (`entry`=16408 AND `groupid`=1 AND `id`=0) OR (`entry`=16408 AND `groupid`=1 AND `id`=1) OR (`entry`=16408 AND `groupid`=1 AND `id`=2) OR (`entry`=16408 AND `groupid`=1 AND `id`=3) OR (`entry`=16408 AND `groupid`=1 AND `id`=4) OR (`entry`=16409 AND `groupid`=0 AND `id`=1) OR (`entry`=16409 AND `groupid`=0 AND `id`=2) OR (`entry`=16409 AND `groupid`=1 AND `id`=0) OR (`entry`=16409 AND `groupid`=1 AND `id`=1) OR (`entry`=16409 AND `groupid`=1 AND `id`=2) OR (`entry`=16410 AND `groupid`=0 AND `id`=0) OR (`entry`=16410 AND `groupid`=0 AND `id`=1) OR (`entry`=16410 AND `groupid`=0 AND `id`=2) OR (`entry`=16410 AND `groupid`=1 AND `id`=0) OR (`entry`=16410 AND `groupid`=1 AND `id`=1) OR (`entry`=16410 AND `groupid`=1 AND `id`=2) OR (`entry`=16411 AND `groupid`=0 AND `id`=0) OR (`entry`=16411 AND `groupid`=0 AND `id`=1) OR (`entry`=16411 AND `groupid`=0 AND `id`=2) OR (`entry`=16411 AND `groupid`=1 AND `id`=0) OR (`entry`=16411 AND `groupid`=1 AND `id`=1) OR (`entry`=16411 AND `groupid`=1 AND `id`=2) OR (`entry`=16412 AND `groupid`=0 AND `id`=0) OR (`entry`=16412 AND `groupid`=0 AND `id`=1) OR (`entry`=16412 AND `groupid`=0 AND `id`=2) OR (`entry`=16412 AND `groupid`=1 AND `id`=0) OR (`entry`=16412 AND `groupid`=1 AND `id`=1) OR (`entry`=16412 AND `groupid`=1 AND `id`=2) OR (`entry`=16414 AND `groupid`=0 AND `id`=3) OR (`entry`=16414 AND `groupid`=1 AND `id`=0) OR (`entry`=16414 AND `groupid`=1 AND `id`=1) OR (`entry`=16414 AND `groupid`=1 AND `id`=2) OR (`entry`=16424 AND `groupid`=0 AND `id`=0) OR (`entry`=16424 AND `groupid`=0 AND `id`=1) OR (`entry`=16424 AND `groupid`=0 AND `id`=2) OR (`entry`=16424 AND `groupid`=1 AND `id`=0) OR (`entry`=16424 AND `groupid`=1 AND `id`=1) OR (`entry`=16424 AND `groupid`=1 AND `id`=2) OR (`entry`=16425 AND `groupid`=0 AND `id`=0) OR (`entry`=16425 AND `groupid`=0 AND `id`=1) OR (`entry`=16425 AND `groupid`=0 AND `id`=2) OR (`entry`=16425 AND `groupid`=1 AND `id`=0) OR (`entry`=16425 AND `groupid`=1 AND `id`=1) OR (`entry`=16425 AND `groupid`=1 AND `id`=2) OR (`entry`=16459 AND `groupid`=0 AND `id`=0) OR (`entry`=16459 AND `groupid`=0 AND `id`=1) OR (`entry`=16459 AND `groupid`=0 AND `id`=2) OR (`entry`=16459 AND `groupid`=0 AND `id`=3) OR (`entry`=16459 AND `groupid`=1 AND `id`=0) OR (`entry`=16459 AND `groupid`=1 AND `id`=1) OR (`entry`=16459 AND `groupid`=1 AND `id`=2) OR (`entry`=16459 AND `groupid`=2 AND `id`=0) OR (`entry`=16459 AND `groupid`=2 AND `id`=1) OR (`entry`=16459 AND `groupid`=2 AND `id`=2) OR (`entry`=16459 AND `groupid`=2 AND `id`=3) OR (`entry`=16459 AND `groupid`=2 AND `id`=4) OR (`entry`=16459 AND `groupid`=3 AND `id`=0) OR (`entry`=16459 AND `groupid`=3 AND `id`=1) OR (`entry`=16459 AND `groupid`=3 AND `id`=2) OR (`entry`=16459 AND `groupid`=3 AND `id`=3) OR (`entry`=16459 AND `groupid`=3 AND `id`=4) OR (`entry`=16459 AND `groupid`=3 AND `id`=5) OR (`entry`=16459 AND `groupid`=3 AND `id`=6) OR (`entry`=16460 AND `groupid`=0 AND `id`=3) OR (`entry`=16460 AND `groupid`=1 AND `id`=0) OR (`entry`=16460 AND `groupid`=1 AND `id`=1) OR (`entry`=16460 AND `groupid`=1 AND `id`=2) OR (`entry`=16460 AND `groupid`=2 AND `id`=0) OR (`entry`=16460 AND `groupid`=2 AND `id`=1) OR (`entry`=16460 AND `groupid`=2 AND `id`=2) OR (`entry`=16460 AND `groupid`=2 AND `id`=3) OR (`entry`=16460 AND `groupid`=2 AND `id`=4) OR (`entry`=16460 AND `groupid`=3 AND `id`=0) OR (`entry`=16460 AND `groupid`=3 AND `id`=1) OR (`entry`=16460 AND `groupid`=3 AND `id`=2) OR (`entry`=16460 AND `groupid`=3 AND `id`=3) OR (`entry`=16460 AND `groupid`=3 AND `id`=4) OR (`entry`=16460 AND `groupid`=3 AND `id`=5) OR (`entry`=16460 AND `groupid`=3 AND `id`=6) OR (`entry`=16461 AND `groupid`=0 AND `id`=0) OR (`entry`=16461 AND `groupid`=0 AND `id`=1) OR (`entry`=16461 AND `groupid`=0 AND `id`=2) OR (`entry`=16461 AND `groupid`=0 AND `id`=3) OR (`entry`=16461 AND `groupid`=1 AND `id`=0) OR (`entry`=16461 AND `groupid`=1 AND `id`=1) OR (`entry`=16461 AND `groupid`=1 AND `id`=2) OR (`entry`=16461 AND `groupid`=2 AND `id`=0) OR (`entry`=16461 AND `groupid`=2 AND `id`=1) OR (`entry`=16461 AND `groupid`=2 AND `id`=2) OR (`entry`=16461 AND `groupid`=2 AND `id`=3) OR (`entry`=16461 AND `groupid`=2 AND `id`=4) OR (`entry`=16461 AND `groupid`=3 AND `id`=0) OR (`entry`=16461 AND `groupid`=3 AND `id`=1) OR (`entry`=16461 AND `groupid`=3 AND `id`=2) OR (`entry`=16461 AND `groupid`=3 AND `id`=3) OR (`entry`=16461 AND `groupid`=3 AND `id`=4) OR (`entry`=16461 AND `groupid`=3 AND `id`=5) OR (`entry`=16461 AND `groupid`=3 AND `id`=6) OR (`entry`=16468 AND `groupid`=1 AND `id`=0) OR (`entry`=16468 AND `groupid`=1 AND `id`=1) OR (`entry`=16470 AND `groupid`=1 AND `id`=0) OR (`entry`=16470 AND `groupid`=1 AND `id`=1) OR (`entry`=16471 AND `groupid`=0 AND `id`=0) OR (`entry`=16471 AND `groupid`=0 AND `id`=1) OR (`entry`=16471 AND `groupid`=0 AND `id`=2) OR (`entry`=16471 AND `groupid`=0 AND `id`=3) OR (`entry`=16471 AND `groupid`=0 AND `id`=4) OR (`entry`=16471 AND `groupid`=1 AND `id`=0) OR (`entry`=16471 AND `groupid`=1 AND `id`=1) OR (`entry`=16472 AND `groupid`=0 AND `id`=0) OR (`entry`=16472 AND `groupid`=0 AND `id`=1) OR (`entry`=16472 AND `groupid`=1 AND `id`=0) OR (`entry`=16472 AND `groupid`=1 AND `id`=1) OR (`entry`=16473 AND `groupid`=0 AND `id`=0) OR (`entry`=16473 AND `groupid`=0 AND `id`=1) OR (`entry`=16473 AND `groupid`=1 AND `id`=0) OR (`entry`=16473 AND `groupid`=1 AND `id`=1) OR (`entry`=16481 AND `groupid`=1 AND `id`=0) OR (`entry`=16481 AND `groupid`=1 AND `id`=1) OR (`entry`=16482 AND `groupid`=1 AND `id`=0) OR (`entry`=16482 AND `groupid`=1 AND `id`=1);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `probability`, `sound`, `BroadcastTextId`, `comment`) VALUES
(15551, 1, 0, 'Intruder!', 12, 100, 0, 13773, 'Spectral Stable Hand - On Aggro'),
(15551, 1, 1, 'You are not welcome here!', 12, 100, 0, 13774, 'Spectral Stable Hand - On Aggro'),
(16389, 0, 0, 'You are not welcome here!', 12, 100, 0, 13774, 'Spectral Apprentice - On Aggro'),
(16389, 0, 1, 'You, hold there!', 12, 100, 0, 13798, 'Spectral Apprentice - On Aggro'),
(16389, 1, 0, 'I am lost...', 12, 100, 0, 13801, 'Spectral Apprentice - On Death'),
(16389, 1, 1, 'Why...?', 12, 100, 0, 13802, 'Spectral Apprentice - On Death'),
(16406, 0, 2, 'I mustn''t be afraid....', 12, 100, 0, 13849, 'Phantom Attendant - On Death'),
(16406, 1, 0, 'You''ll ruin everything!', 12, 100, 0, 13844, 'Phantom Attendant - On Aggro'),
(16406, 1, 1, 'Off with you!', 12, 100, 0, 13845, 'Phantom Attendant - On Aggro'),
(16406, 1, 2, 'We do not wish to be disturbed!', 12, 100, 0, 13846, 'Phantom Attendant - On Aggro'),
(16407, 1, 0, 'What is this?', 12, 100, 0, 13820, 'Spectral Servant - On Aggro'),
(16407, 1, 1, 'Invaders in the tower!', 12, 100, 0, 13821, 'Spectral Servant - On Aggro'),
(16407, 1, 2, 'Stop them!', 12, 100, 0, 13822, 'Spectral Servant - On Aggro'),
(16408, 0, 1, 'My time is done.', 12, 100, 0, 13857, 'Phantom Valet - On Death'),
(16408, 0, 2, 'No, not now! Not like this!', 12, 100, 0, 13858, 'Phantom Valet - On Death'),
(16408, 1, 0, 'Hey! Where do you think you are going, sneaking around like that?', 12, 100, 0, 13398, 'Phantom Valet - On Aggro'),
(16408, 1, 1, 'Excuse me, are you trying to sneak by without an invitation?', 12, 100, 0, 13399, 'Phantom Valet - On Aggro'),
(16408, 1, 2, 'Begone, outsider!', 12, 100, 0, 13851, 'Phantom Valet - On Aggro'),
(16408, 1, 3, 'You''ll not ruin the celebration!', 12, 100, 0, 13852, 'Phantom Valet - On Aggro'),
(16408, 1, 4, 'We are besieged!', 12, 100, 0, 13853, 'Phantom Valet - On Aggro'),
(16409, 0, 1, 'It''s not my time, not yet!', 12, 100, 0, 13842, 'Phantom Guest - On Death'),
(16409, 0, 2, 'All good things must come to an end.', 12, 100, 0, 13843, 'Phantom Guest - On Death'),
(16409, 1, 0, 'How dare you interfere?!', 12, 100, 0, 13838, 'Phantom Guest - On Aggro'),
(16409, 1, 1, 'You do not belong here!', 12, 100, 0, 13839, 'Phantom Guest - On Aggro'),
(16409, 1, 2, 'Leave us alone! Let us be!', 12, 100, 0, 13840, 'Phantom Guest - On Aggro'),
(16410, 0, 0, 'You''ll ruin everything!', 12, 100, 0, 13844, 'Spectral Retainer - On Aggro'),
(16410, 0, 1, 'Off with you!', 12, 100, 0, 13845, 'Spectral Retainer - On Aggro'),
(16410, 0, 2, 'We do not wish to be disturbed!', 12, 100, 0, 13846, 'Spectral Retainer - On Aggro'),
(16410, 1, 0, 'Where am I? What--', 12, 100, 0, 13847, 'Spectral Retainer - On Death'),
(16410, 1, 1, 'What is happening?', 12, 100, 0, 13848, 'Spectral Retainer - On Death'),
(16410, 1, 2, 'I mustn''t be afraid....', 12, 100, 0, 13849, 'Spectral Retainer - On Death'),
(16411, 0, 0, 'I''ll chop you into minced meat!', 12, 100, 0, 13861, 'Spectral Chef - On Aggro'),
(16411, 0, 1, 'I''ll gut you like a fish!', 12, 100, 0, 13862, 'Spectral Chef - On Aggro'),
(16411, 0, 2, 'I''ll carve the meat from your bones!', 12, 100, 0, 13863, 'Spectral Chef - On Aggro'),
(16411, 1, 0, 'I have served to the last....', 12, 100, 0, 13864, 'Spectral Chef - On Death'),
(16411, 1, 1, 'This isn''t the end; it can''t be!', 12, 100, 0, 13865, 'Spectral Chef - On Death'),
(16411, 1, 2, 'I tried, master. I tried.', 12, 100, 0, 13866, 'Spectral Chef - On Death'),
(16412, 0, 0, 'I''ll chop you into minced meat!', 12, 100, 0, 13861, 'Ghostly Baker - On Aggro'),
(16412, 0, 1, 'I''ll gut you like a fish!', 12, 100, 0, 13862, 'Ghostly Baker - On Aggro'),
(16412, 0, 2, 'I''ll carve the meat from your bones!', 12, 100, 0, 13863, 'Ghostly Baker - On Aggro'),
(16412, 1, 0, 'I have served to the last....', 12, 100, 0, 13864, 'Ghostly Baker - On Death'),
(16412, 1, 1, 'This isn''t the end; it can''t be!', 12, 100, 0, 13865, 'Ghostly Baker - On Death'),
(16412, 1, 2, 'I tried, master. I tried.', 12, 100, 0, 13866, 'Ghostly Baker - On Death'),
(16414, 0, 3, 'How dare you spill the master''s wine!', 12, 100, 0, 13435, 'Ghostly Steward - On Death'),
(16414, 1, 0, 'Impudent outsiders!', 12, 100, 0, 13876, 'Ghostly Steward - On Aggro'),
(16414, 1, 1, 'Meddling fools! You will pay with your lives!', 12, 100, 0, 13877, 'Ghostly Steward - On Aggro'),
(16414, 1, 2, 'You''ll never make it out alive....', 12, 100, 0, 13879, 'Ghostly Steward - On Aggro'),
(16424, 0, 0, 'What is this?', 12, 100, 0, 13820, 'Spectral Sentry - On Aggro'),
(16424, 0, 1, 'Invaders in the tower!', 12, 100, 0, 13821, 'Spectral Sentry - On Aggro'),
(16424, 0, 2, 'Stop them!', 12, 100, 0, 13822, 'Spectral Sentry - On Aggro'),
(16424, 1, 0, 'You will be punished!', 12, 100, 0, 13835, 'Spectral Sentry - On Death'),
(16424, 1, 1, 'You... will... pay.', 12, 100, 0, 13836, 'Spectral Sentry - On Death'),
(16424, 1, 2, 'I have failed....', 12, 100, 0, 13834, 'Spectral Sentry - On Death'),
(16425, 0, 0, 'To arms!', 12, 100, 0, 13829, 'Phantom Guardsman - On Aggro'),
(16425, 0, 1, 'Protect the tower!', 12, 100, 0, 13830, 'Phantom Guardsman - On Aggro'),
(16425, 0, 2, 'Have at them!', 12, 100, 0, 13831, 'Phantom Guardsman - On Aggro'),
(16425, 1, 0, 'You will be punished!', 12, 100, 0, 13835, 'Phantom Guardsman - On Death'),
(16425, 1, 1, 'You... will... pay.', 12, 100, 0, 13836, 'Phantom Guardsman - On Death'),
(16425, 1, 2, 'I have failed....', 12, 100, 0, 13834, 'Phantom Guardsman - On Death'),
(16459, 0, 0, 'So I said, "Yeah, but that''ll cost you extra."', 12, 100, 0, 13883, 'Wanton Hostess - Out of Combat'),
(16459, 0, 1, 'Five seconds. I''m not kidding!', 12, 100, 0, 13884, 'Wanton Hostess - Out of Combat'),
(16459, 0, 2, 'He asked if the imp could join in--can you believe it? Actually, it wasn''t half bad....', 12, 100, 0, 13885, 'Wanton Hostess - Out of Combat'),
(16459, 0, 3, 'They fall asleep after. Me, I fall asleep during....', 12, 100, 0, 13886, 'Wanton Hostess - Out of Combat'),
(16459, 1, 0, 'Come play with me!', 12, 100, 0, 13880, 'Wanton Hostess - On Aggro'),
(16459, 1, 1, 'You WILL be mine.', 12, 100, 0, 13881, 'Wanton Hostess - On Aggro'),
(16459, 1, 2, 'Come here, pretty. You have what I need!', 12, 100, 0, 13882, 'Wanton Hostess - On Aggro'),
(16459, 2, 0, 'It was fun while it lasted....', 12, 100, 0, 13889, 'Wanton Hostess - On Death'),
(16459, 2, 1, '<sigh> It''s always over too soon.', 12, 100, 0, 13890, 'Wanton Hostess - On Death'),
(16459, 2, 2, 'Just when things were getting interesting.', 12, 100, 0, 13897, 'Wanton Hostess - On Death'),
(16459, 2, 3, 'We could have had so much fun!', 12, 100, 0, 13898, 'Wanton Hostess - On Death'),
(16459, 3, 0, 'Come any closer, and I''ll scream.', 12, 100, 0, 13887, 'Wanton Hostess - On Transform'),
(16459, 3, 1, 'I want to show you a different side of me....', 12, 100, 0, 13888, 'Wanton Hostess - On Transform'),
(16459, 3, 2, 'I want you to be with me... forever and ever.', 12, 100, 0, 13891, 'Wanton Hostess - On Transform'),
(16459, 3, 3, 'Shhh... I have a little secret I''ve been keeping.\n', 12, 100, 0, 13892, 'Wanton Hostess - On Transform'),
(16459, 3, 4, 'I''ve been very, very naughty....', 12, 100, 0, 13895, 'Wanton Hostess - On Transform'),
(16459, 3, 5, 'Enough foreplay. Let''s get down to business.', 12, 100, 0, 13896, 'Wanton Hostess - On Transform'),
(16460, 0, 3, 'They fall asleep after. Me, I fall asleep during....', 12, 100, 0, 13886, 'Night Mistress - Out of Combat'),
(16460, 1, 0, 'Come play with me!', 12, 100, 0, 13880, 'Night Mistress - On Aggro'),
(16460, 1, 1, 'You WILL be mine.', 12, 100, 0, 13881, 'Night Mistress - On Aggro'),
(16460, 1, 2, 'Come here, pretty. You have what I need!', 12, 100, 0, 13882, 'Night Mistress - On Aggro'),
(16460, 2, 0, 'It was fun while it lasted....', 12, 100, 0, 13889, 'Night Mistress - On Death'),
(16460, 2, 1, '<sigh> It''s always over too soon.', 12, 100, 0, 13890, 'Night Mistress - On Death'),
(16460, 2, 2, 'Just when things were getting interesting.', 12, 100, 0, 13897, 'Night Mistress - On Death'),
(16460, 2, 3, 'We could have had so much fun!', 12, 100, 0, 13898, 'Night Mistress - On Death'),
(16460, 3, 0, 'Come any closer, and I''ll scream.', 12, 100, 0, 13887, 'Night Mistress - On Transform'),
(16460, 3, 1, 'I want to show you a different side of me....', 12, 100, 0, 13888, 'Night Mistress - On Transform'),
(16460, 3, 2, 'I want you to be with me... forever and ever.', 12, 100, 0, 13891, 'Night Mistress - On Transform'),
(16460, 3, 3, 'Shhh... I have a little secret I''ve been keeping.\n', 12, 100, 0, 13892, 'Night Mistress - On Transform'),
(16460, 3, 4, 'I''ve been very, very naughty....', 12, 100, 0, 13895, 'Night Mistress - On Transform'),
(16460, 3, 5, 'Enough foreplay. Let''s get down to business.', 12, 100, 0, 13896, 'Night Mistress - On Transform'),
(16461, 0, 0, 'So I said, "Yeah, but that''ll cost you extra."', 12, 100, 0, 13883, 'Concubine - Out of Combat'),
(16461, 0, 1, 'Five seconds. I''m not kidding!', 12, 100, 0, 13884, 'Concubine - Out of Combat'),
(16461, 0, 2, 'He asked if the imp could join in--can you believe it? Actually, it wasn''t half bad....', 12, 100, 0, 13885, 'Concubine - Out of Combat'),
(16461, 0, 3, 'They fall asleep after. Me, I fall asleep during....', 12, 100, 0, 13886, 'Concubine - Out of Combat'),
(16461, 1, 0, 'Come play with me!', 12, 100, 0, 13880, 'Concubine - On Aggro'),
(16461, 1, 1, 'You WILL be mine.', 12, 100, 0, 13881, 'Concubine - On Aggro'),
(16461, 1, 2, 'Come here, pretty. You have what I need!', 12, 100, 0, 13882, 'Concubine - On Aggro'),
(16461, 2, 0, 'It was fun while it lasted....', 12, 100, 0, 13889, 'Concubine - On Death'),
(16461, 2, 1, '<sigh> It''s always over too soon.', 12, 100, 0, 13890, 'Concubine - On Death'),
(16461, 2, 2, 'Just when things were getting interesting.', 12, 100, 0, 13897, 'Concubine - On Death'),
(16461, 2, 3, 'We could have had so much fun!', 12, 100, 0, 13898, 'Concubine - On Death'),
(16461, 3, 0, 'Come any closer, and I''ll scream.', 12, 100, 0, 13887, 'Concubine - On Transform'),
(16461, 3, 1, 'I want to show you a different side of me....', 12, 100, 0, 13888, 'Concubine - On Transform'),
(16461, 3, 2, 'I want you to be with me... forever and ever.', 12, 100, 0, 13891, 'Concubine - On Transform'),
(16461, 3, 3, 'Shhh... I have a little secret I''ve been keeping.\n', 12, 100, 0, 13892, 'Concubine - On Transform'),
(16461, 3, 4, 'I''ve been very, very naughty....', 12, 100, 0, 13895, 'Concubine - On Transform'),
(16461, 3, 5, 'Enough foreplay. Let''s get down to business.', 12, 100, 0, 13896, 'Concubine - On Transform'),
(16468, 1, 0, 'You must not interfere!', 12, 100, 0, 13916, 'Spectral Patron - On Aggro'),
(16468, 1, 1, 'What are you doing? Be off!', 12, 100, 0, 13917, 'Spectral Patron - On Aggro'),
(16470, 1, 0, 'You were not invited!', 12, 100, 0, 13943, 'Ghostly Philanthropist - On Aggro'),
(16470, 1, 1, 'Your insolence will not be tolerated!', 12, 100, 0, 13942, 'Ghostly Philanthropist - On Aggro'),
(16471, 0, 0, 'Clear the area!', 12, 100, 0, 13920, 'Skeletal Usher - On Aggro'),
(16471, 0, 1, 'Where''s your ticket?', 12, 100, 0, 13921, 'Skeletal Usher - On Aggro'),
(16471, 0, 2, 'The show is for guests only!', 12, 100, 0, 13922, 'Skeletal Usher - On Aggro'),
(16471, 0, 3, 'You should not have come here!', 12, 100, 0, 13923, 'Skeletal Usher - On Aggro'),
(16471, 0, 4, 'You''ll be joining the other guests now....', 12, 100, 0, 13924, 'Skeletal Usher - On Aggro'),
(16471, 1, 0, 'You cannot stop us all!', 12, 100, 0, 13925, 'Skeletal Usher - On Death'),
(16471, 1, 1, 'Your death will soon follow....', 12, 100, 0, 13926, 'Skeletal Usher - On Death'),
(16472, 0, 0, 'You''re not allowed here!', 12, 100, 0, 13928, 'Phantom Stagehand - On Aggro'),
(16472, 0, 1, 'You''re not a guest!', 12, 100, 0, 13929, 'Phantom Stagehand - On Aggro'),
(16472, 1, 0, 'Am I released from my duties?', 12, 100, 0, 13930, 'Phantom Stagehand - On Death'),
(16472, 1, 1, 'At last, my work is done.', 12, 100, 0, 13931, 'Phantom Stagehand - On Death'),
(16473, 0, 0, 'I will not be upstaged by amateurs!', 12, 100, 0, 13938, 'Spectral Performer - On Aggro'),
(16473, 0, 1, 'The show must go on!', 12, 100, 0, 13939, 'Spectral Performer - On Aggro'),
(16473, 1, 0, 'It''s so cold, so dark.... I''m not overacting, am I?', 12, 100, 0, 13940, 'Spectral Performer - On Death'),
(16473, 1, 1, 'Make sure my name is spelled correctly on the tombst--', 12, 100, 0, 13941, 'Spectral Performer - On Death'),
(16481, 1, 0, 'You will find no reward here, only death!', 12, 100, 0, 13946, 'Ghastly Haunt - On Aggro'),
(16481, 1, 1, 'Visitors are forbidden!', 12, 100, 0, 13947, 'Ghastly Haunt - On Aggro'),
(16482, 1, 0, 'You will find no reward here, only death!', 12, 100, 0, 13946, 'Trapped Soul - On Aggro'),
(16482, 1, 1, 'Visitors are forbidden!', 12, 100, 0, 13947, 'Trapped Soul - On Aggro');
