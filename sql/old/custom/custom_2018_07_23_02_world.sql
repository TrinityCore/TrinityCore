-- Creature Wind Tunnel Landing Zone 48097
SET @ENTRY := 48097;
UPDATE `creature_template` SET `AIName`="", `ScriptName`= 'npc_lct_wind_tunnel_landing_zone' WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

-- Creature Wind Tunnel 48092
SET @ENTRY := 48092;
UPDATE `creature_template` SET `AIName`="", `ScriptName`= 'npc_lct_wind_tunnel' WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;

DELETE FROM `spell_script_names` WHERE `spell_id`= 79737;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(79737, 'spell_gen_eject_all_passengers');
