DELETE FROM `creature` WHERE `id` = '73184';
DELETE FROM `creature` WHERE `id` = '71645';
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399' WHERE `entry` = '71658';
UPDATE `creature_template` SET `ScriptName`='npc_shock_collar' WHERE `entry`='71645'; 
UPDATE `creature_template` SET `ScriptName`='npc_body_stalker' WHERE `entry`='71787'; 
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`ScriptName`='npc_captive_cave_bat' WHERE `entry`='73522'; 
UPDATE `creature_template` SET `mechanic_immune_mask`='650854399',`ScriptName`='npc_starved_yeti' WHERE `entry`='73184';