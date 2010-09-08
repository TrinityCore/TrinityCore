-- Remove by script name in case someone ever applied these names to other stuff
UPDATE `instance_template` SET `script`='' WHERE `script`='instance_blackrock_spire';
UPDATE `creature_template` SET `ScriptName`='' WHERE `ScriptName`='npc_rookey_whelp';
UPDATE `gameobject_template` SET `ScriptName`='' WHERE `ScriptName`='go_rookey_egg';
