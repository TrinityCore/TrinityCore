-- Move Yor from EAI to CPP
UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'npc_yor' WHERE `entry`=22930;
DELETE FROM creature_ai_scripts WHERE `creature_id`=22930;
