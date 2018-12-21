DELETE FROM `creature_template_addon` WHERE `entry` IN (28596, 28569);
DELETE FROM `creature_addon` WHERE `guid` IN (313934, 313933, 313930, 313935, 313931, 313938, 313939, 314108, 314106, 314109, 314107, 314113, 314110, 314111, 314112, 313932);
INSERT INTO `creature_addon` (`guid`, `bytes2`, `emote`) VALUES
(313934, 257, 234),
(313933, 257, 234),
(313930, 257, 234),
(313935, 257, 234),
(313931, 257, 234),
(313938, 257, 234),
(313939, 257, 234),
(314108, 257, 234),
(314106, 257, 234),
(314109, 257, 234),
(314107, 257, 234),
(314113, 257, 234),
(314110, 257, 234),
(314111, 257, 234),
(314112, 257, 234),
(313932, 257, 234);

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (28596, 28569);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(28596, 1, 5292, 0, 0), -- Dwarven Construction Worker
(28569, 1, 5292, 0, 0); -- Construction Worker

UPDATE `creature` SET `equipment_id`= 1 WHERE `guid` IN (313934, 313933, 313930, 313935, 313931, 313938, 313939, 314108, 314106, 314109, 314107, 314113, 314110, 314111, 314112, 313932);

DELETE FROM `creature` WHERE `guid`= 314226;
DELETE FROM `creature_addon` WHERE `guid`= 314226;

DELETE FROM `vehicle_template_accessory` WHERE `entry`= 50523;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(50523, 50525, 0, 1, 'Kyle Radue - Chris Miller', 5, 0); -- Kyle Radue - Chris Miller

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`= 50523;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(50523, 46598, 1, 1);

UPDATE `creature_template_addon` SET `emote`= 379 WHERE `entry`= 42421;
UPDATE `gameobject` SET `rotation0`= -0.59733, `rotation1`= -0.208596, `rotation2`= -0.731095, `rotation3`= 0.255313 WHERE `guid`= 219906;
