-- Trader's Gilded Brutosaur (465235): vehicle kit, passengers and their vendor npcflags
UPDATE `creature_template` SET `VehicleId`=8702 WHERE `entry`=305;
UPDATE `creature_template` SET `npcflag`=`npcflag`|0x00200000 WHERE `entry`=231085; -- Killia (Auctioneer)
UPDATE `creature_template` SET `npcflag`=`npcflag`|0x04000000 WHERE `entry`=231086; -- Melanie Morten (Mail Courier)

DELETE FROM `vehicle_template_accessory` WHERE `entry`=305;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(305, 231086, 0, 1, 'Trader''s Gilded Brutosaur - Melanie Morten', 6, 30000),
(305, 231085, 1, 1, 'Trader''s Gilded Brutosaur - Killia', 6, 30000);

DELETE FROM `vehicle_seat_addon` WHERE `SeatEntry` IN (24814, 24815);
INSERT INTO `vehicle_seat_addon` (`SeatEntry`, `SeatOrientation`, `ExitParamX`, `ExitParamY`, `ExitParamZ`, `ExitParamO`, `ExitParamValue`) VALUES
(24814, 0, -2, 2, 0, 0, 1),
(24815, 0, -2, -2, 0, 0, 1);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=305;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(305, 46598, 1, 0);
