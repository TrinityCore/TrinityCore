UPDATE `creature_template` SET `ScriptName`= 'npc_invis_infernal_caster' WHERE `entry`=21417;
UPDATE `creature_template` SET `AIName`="", `ScriptName`= 'npc_infernal_attacker' WHERE `entry`=21419;
DELETE FROM `smart_scripts` WHERE `entryorguid`=21419 AND `source_type`=0;
