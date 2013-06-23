-- Move Blackhand Incarcerator to core scripting
UPDATE `creature_template` SET `AIName`= '',`ScriptName`= 'npc_blackhand_incarcerator' WHERE `entry`=10316;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10316;
