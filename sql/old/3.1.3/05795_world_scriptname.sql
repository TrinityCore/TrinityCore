-- Azjol-Nerub
UPDATE `instance_template` SET `script`='instance_azjol_nerub' WHERE `map`=601;
-- Krik'thir the Gatewatcher
UPDATE creature_template SET `ScriptName`='npc_watcher_narjil' WHERE `entry`=28729;
UPDATE creature_template SET `ScriptName`='npc_watcher_silthik' WHERE `entry`=28731;
UPDATE creature_template SET `ScriptName`='npc_anub_ar_warrior' WHERE `entry`=28732;
UPDATE creature_template SET `ScriptName`='npc_watcher_gashra' WHERE `entry`=28730;
UPDATE creature_template SET `ScriptName`='boss_krik_thir' WHERE `entry`=28684;
UPDATE creature_template SET `ScriptName`='npc_skittering_infector' WHERE `entry`=28736;
UPDATE creature_template SET `ScriptName`='npc_anub_ar_skirmisher' WHERE `entry`=28734;
UPDATE creature_template SET `ScriptName`='npc_anub_ar_shadowcaster' WHERE `entry`=28733;

-- Halls of Stone
-- scripts
UPDATE `instance_template` SET `script`='instance_halls_of_stone' WHERE `map`=599;
UPDATE `creature_template` SET `ScriptName`='boss_krystallus' WHERE `entry`=27977;
UPDATE `creature_template` SET `ScriptName`='boss_sjonnir' WHERE `entry`=27978;
UPDATE `creature_template` SET `ScriptName`='mob_tribuna_controller' WHERE `entry`=28234;
UPDATE `creature_template` SET `ScriptName`='npc_brann_hos' WHERE `entry`=28070;
