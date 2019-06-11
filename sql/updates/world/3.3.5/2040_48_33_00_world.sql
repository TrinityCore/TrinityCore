UPDATE `creature_template` SET `ScriptName`='npc_entrance_faction_leader' WHERE `entry`IN (39371,39372);
DELETE FROM `spell_area` WHERE `spell`=73822 AND `area`=4812;
DELETE FROM `spell_area` WHERE `spell`=73828 AND `area`=4812;
