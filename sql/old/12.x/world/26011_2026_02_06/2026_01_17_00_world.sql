-- Aysa Cloudsinger smart ai
SET @ENTRY := 54567;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
