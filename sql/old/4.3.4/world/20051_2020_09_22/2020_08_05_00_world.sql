-- 
UPDATE `smart_scripts` SET `event_phase_mask`=0,`event_flags`=0 WHERE `entryorguid`=16027 AND `source_type`=0;
UPDATE `creature_template` SET `ScriptName`='npc_frogger_trigger_naxx' WHERE `entry`=16082;
UPDATE `creature_summon_groups` SET `summonerId`=16082,`summonerType`=0 WHERE `summonerId`=533 AND `summonerType`=2;
