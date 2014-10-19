-- Add cpp script to Harrison Jones Entry: 24358
-- UPDATE `creature_template` SET `AIName`= '', `ScriptName`= 'npc_harrison_jones' WHERE `entry`=24358; 4.x removed
-- Remove cpp script from Strange Gong
UPDATE `gameobject_template` SET `AIName`= '', `ScriptName`= '' WHERE `entry`=187359;
