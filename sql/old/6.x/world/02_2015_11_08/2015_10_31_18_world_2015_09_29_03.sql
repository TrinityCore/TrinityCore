-- 

DELETE FROM `creature` WHERE `id`=29558;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry` IN (29351, 29358);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (29358, 29351);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(29358,46598,0,0),
(29351,46598,0,0);

DELETE FROM `vehicle_template_accessory` WHERE `entry` IN (29358, 29351);
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`) VALUES
(29351,29558,0,1, 'Niffelem Frost Giant', 8),
(29351,29558,1,1, 'Niffelem Frost Giant', 8),
(29351,29558,2,1, 'Niffelem Frost Giant', 8),
(29351,29558,3,1, 'Niffelem Frost Giant', 8),
(29358,29558,0,1, 'Frostworg', 8),
(29358,29558,1,1, 'Frostworg', 8);
