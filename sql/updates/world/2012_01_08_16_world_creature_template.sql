-- And this, fixes her flag so script can be started (credit to ric)
UPDATE `creature_template` SET `unit_flags`=2 WHERE `entry` IN (29281, 30809);

-- Update Svala's rank to 1 Elite, prevent corpse despawn after 1 min
UPDATE  `creature_template` SET  `rank` =  '1'  WHERE  `entry` IN (29281, 30809);

-- Set flags_extra = 1 for Svala hero difficulty
UPDATE  `creature_template` SET  `flags_extra` =  '1'  WHERE  `entry` = 30809;

-- Svala and Svala Svala Sorrowgrave
UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`
|1 -- CHARM
|2 -- DISORIENTED
|4 -- DISARM
|8 -- DISTRACT
|16 -- FEAR
|32 -- GRIP
|64 -- ROOT
|128 -- PACIFY
|256 -- SILENCE
|512 -- SLEEP
|1024 -- SNARE
|2048 -- STUN
|4096 -- FREEZE
|8192 -- KNOCKOUT
|65536 -- POLYMORPH
|131072 -- BANISH
|524288 -- SHACKLE
|4194304 -- TURN
|8388608 -- HORROR
|67108864 -- DAZE
|536870912 -- SAPPED
WHERE `entry` IN (29281, 30809, 26668, 30810);

-- "boss_svala_sorrowgrave" script is now merged with "boss_svala" script
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 26668;

-- Spectators escape script
UPDATE `creature_template` SET `ScriptName` = 'npc_spectator' WHERE `entry` = 26667;

-- Change 'mob_ritual_channeler' to 'npc_ritual_channeler'
UPDATE `creature_template` SET `ScriptName` = 'npc_ritual_channeler' WHERE `entry` = 27281;

-- Set same data on heroic ver to triggers
UPDATE `creature_template` SET `InhabitType` = 7, `flags_extra` = 130 WHERE `entry` = 30805;
UPDATE `creature_template` SET `InhabitType` = 7, `flags_extra` = 128 WHERE `entry` = 30771;

-- SmartAI for Flame Brazier's
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 27273;
UPDATE `creature_template` SET `faction_A` = 21, `faction_H` = 21 WHERE `entry` IN (27273, 30771);

-- Scourge Hulk
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 26555;
UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'npc_scourge_hulk' WHERE `entry` = 26555;
