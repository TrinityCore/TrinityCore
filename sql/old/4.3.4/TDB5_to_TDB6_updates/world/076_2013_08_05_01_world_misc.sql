UPDATE `smart_scripts` SET `event_type`=2 WHERE  `entryorguid`=7271 AND `source_type`=0 AND `id`=5 AND `link`=0;
UPDATE `creature_template` SET /*`AIName`='SmartAI', `ScriptName`='',*/ `InhabitType`=7, `faction_A`=35, `faction_H`=35, `unit_flags`=0, `type_flags`=8, `dynamicflags`=128, `flags_extra`=0, `speed_walk`=2 WHERE `entry`= 15491; -- 4.x changed
