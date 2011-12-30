-- replacement for https://github.com/TrinityCore/TrinityCore/commit/dbcccbbb44cd331ab5ad31361b2fa4a6f12990bc

-- The Thunderspike quest fix
SET @ENTRY := 184729;

-- revert to original TDB values
UPDATE `gameobject_template` SET `ScriptName` = '', `data2`=13685, `data3`=3000 WHERE `entry` = @ENTRY;

-- Add event_scripts 13685
DELETE FROM `event_scripts` WHERE `id`=13685;
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
('13685','1','10','21319','900000','0','1326.51','6691.53','-20.3344','3.29793');

-- SAI workaround untill event_scripts problem is fixed
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,1,0,0,64,0,100,1,0,0,0,0,12,21319,1,900000,0,0,0,8,0,0,0,1326.51,6691.53,-20.3344,3.29793,"The Thunderspike - On Gossip Hello - Summon Gor Grimgut");