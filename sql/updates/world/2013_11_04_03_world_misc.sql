UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry` IN (35415, 35413, 35419, 35429); -- Demolisher, Catapult, Glaive Thrower & Keep Cannon

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (35415, 35413, 35419, 35429);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(35415, 66245, 1, 0), -- Demolisher (Ride Vehicle)
(35413, 66245, 1, 0), -- Catapult (Ride Vehicle)
(35419, 68503, 1, 0), -- Glaive Thrower (Ride Vehicle)
(35429, 68458, 1, 0); -- Keep Cannon (Keep Cannon)
