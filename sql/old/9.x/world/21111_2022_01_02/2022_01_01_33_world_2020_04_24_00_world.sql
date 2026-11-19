-- Reliquary of Souls Combat Trigger
UPDATE `creature_template` SET `flags_extra`=`flags_extra`&~128, `ScriptName` = 'npc_reliquary_combat_trigger' WHERE `entry`=23417;
