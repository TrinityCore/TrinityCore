-- Bloodmaul Brute
SET @ENTRY := 19991;
UPDATE `creature_template` SET `AIName`='',`ScriptName`= 'npc_bloodmaul_brute' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@ENTRY;
