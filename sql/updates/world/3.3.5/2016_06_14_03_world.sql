SET @CGUID:= 145427; -- 69 GUIDs required
SET @OGUID:= 73587; -- 13 GUIDs required
SET @OG_PORTAL:= 193206;
SET @OG_TELEPORTSPELL:= 59064;
SET @UCTELEPORTSPELL:= 59439;
SET @HORDE_BUILDING1:= 193219;
SET @HORDE_BUILDING2:= 193217;
SET @HORDE_BUILDING3:= 193218;
SET @HORDE_BUILDING4:= 193216;
SET @HORDE_BUILDING5:= 193215;
SET @REFUGEE1:= 31437;
SET @REFUGEE2:= 31467;
SET @MOUNTEDORC:= 31564; -- mounted on frostwolf
SET @MOUNTEDORC2:= 31563; -- mounted on brown wolf
SET @KORKRONGUARDS:= 31417; -- guards within thrall building
SET @NPC_GRYSHKA:= 31433;
SET @NPC_OVERLORD_RUNTHAK:= 31431;
SET @NPC_OLVIA:= 31425;
SET @NPC_SANA:= 31429;
SET @NPC_FELIKA:= 31427;
SET @NPC_THUNG:= 31430;
SET @NPC_KAJA:= 31423;
SET @NPC_GAMON:= 31424;
SET @NPC_COMMONER:= 31434;
SET @NPC_THRALL:= 31412;
SET @PORTAL_STORMWIND:= 31640;
SET @NPC_SYLVANAS:= 31419;
SET @NPC_JAINA:= 31418;
SET @UC_THRALL:= 31650;
SET @UC_SYLVANAS:= 31651;
SET @VOLJIN:= 31649;
SET @UCPORTAL:= 193425; -- orgrimmar

UPDATE `creature` SET `PhaseMask` = 65 WHERE `GUID` IN (6565, 10351, 3390, 3387, 10450, 8526, 6564, 8522, 6560, 11792, 7395, 6557, 6548, 3373, 3372, 6550, 6555, 3371, 6552, 6556, 6551, 3378, 7396, 3380, 3376, 3379, 3375, 6553);
UPDATE `creature_template` SET `unit_flags` = 788 WHERE `entry` = @NPC_GAMON;
UPDATE `creature_template` SET `ScriptName` = 'npc_overlord_runthak_orgrimmar' WHERE `entry` = @NPC_OVERLORD_RUNTHAK;
UPDATE `creature_template` SET `ScriptName` = 'npc_thrall_herald_of_war' WHERE `entry` = @NPC_THRALL;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = @NPC_SYLVANAS;
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` = @NPC_JAINA;

DELETE FROM `smart_scripts` WHERE `entryorguid` = @NPC_SYLVANAS;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@NPC_SYLVANAS, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - on reset - set byte kneel'),
(@NPC_SYLVANAS, 0, 1, 0, 34, 0, 100, 0, 8, 2, 0, 0, 90, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sylvanas - on movement inform - set byte kneel');

DELETE FROM `areatrigger_scripts` WHERE `entry` = 5279;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5279, "areatrigger_orgrimmar_herald_of_war");

DELETE FROM `creature_text` WHERE `entry` IN (@NPC_GRYSHKA, @NPC_OLVIA, @NPC_FELIKA, @NPC_THUNG, @NPC_SANA, @NPC_KAJA, @NPC_OVERLORD_RUNTHAK, @NPC_THRALL, @NPC_SYLVANAS, @NPC_JAINA);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@NPC_GRYSHKA, 0, 0, "When can we reopen our shops? I'm losing gold here!", 12, 0, 100, 0, 0, 0, 32237, 0, "inkeeper gryshka - herald of war"),
(@NPC_GRYSHKA, 1, 0, "This is an outrage!", 12, 0, 100, 0, 0, 0, 32238, 0, "inkeeper gryshka - herald of war"),

(@NPC_OLVIA, 0, 0, "Where is the Warchief?", 12, 0, 100, 0, 0, 0, 32236, 0, "olvia - herald of war"),
(@NPC_OLVIA, 1, 0, "What are all these Forsaken doing here?", 12, 0, 100, 0, 0, 0, 32233, 0, "olvia - herald of war"),

(@NPC_FELIKA, 0, 0, "What is going on?", 12, 0, 100, 0, 0, 0, 45914, 0, "felika - herald of war"),
(@NPC_FELIKA, 1, 0, "This is an outrage!", 12, 0, 100, 0, 0, 0, 46620, 0, "felika - herald of war"),

(@NPC_THUNG, 0, 0, "What is going on?", 12, 0, 100, 0, 0, 0, 32232, 0, "auctioneer thathung - herald of war"),

(@NPC_KAJA, 0, 0, "Why is Thrall allowing this to happen to our city?", 12, 0, 100, 0, 0, 0, 32239, 0, "Kaja - herald of war"),

(@NPC_SANA, 0, 0, "We demand answers!", 12, 0, 100, 0, 0, 0, 32235, 0, "Sana - herald of war"),

(@NPC_OVERLORD_RUNTHAK, 0, 0, "SILENCE!", 12, 0, 100, 0, 0, 0, 32240, 0, "Overlord runthak - herald of war"),
(@NPC_OVERLORD_RUNTHAK, 1, 0, "We are on the brink of all out war with the Alliance!", 12, 0, 100, 0, 0, 0, 32241, 0, "Overlord runthak - herald of war"),
(@NPC_OVERLORD_RUNTHAK, 2, 0, "Tragic events have unfolded in Northrend. The Warchief is doing all that he can to keep us safe.", 12, 0, 100, 0, 0, 0, 32242, 0, "Overlord runthak - herald of war"),
(@NPC_OVERLORD_RUNTHAK, 3, 0, "All services and shops are to remain closed until further notice! That is all!", 12, 0, 100, 0, 0, 0, 32243, 0, "Overlord runthak - herald of war"),

(@NPC_THRALL, 0, 0, "Kor'kron, stand down!", 12, 0, 100, 0, 0, 16222, 32286, 0, "Thrall - herald of war"),
(@NPC_THRALL, 1, 0, "Jaina...", 12, 0, 100, 0, 0, 16223, 32287, 0, "Thrall - herald of war"),
(@NPC_THRALL, 2, 0, "Jaina, what happened at the Wrathgate. It was a betrayal from within...", 12, 0, 100, 0, 0, 16224, 32289, 0, "Thrall - herald of war"),
(@NPC_THRALL, 3, 0, "The Horde has lost the Undercity.", 12, 0, 100, 1, 0, 16225, 32292, 0, "Thrall - herald of war"),
(@NPC_THRALL, 4, 0, "We now prepare to lay siege to the city and bring the perpetrators of this unforgivable crime to justice.", 12, 0, 100, 378, 0, 16226, 32293, 0, "Thrall - herald of war"),
(@NPC_THRALL, 5, 0, "If we are forced into a conflict, the Lich King will destroy our divided forces in Northrend.", 12, 0, 100, 378, 0, 16227, 32294, 0, "Thrall - herald of war"),
(@NPC_THRALL, 6, 0, "We will make this right, Jaina. Tell your king all that you have learned here.", 12, 0, 100, 378, 0, 16228, 32295, 0, "Thrall - herald of war"),
(@NPC_THRALL, 7, 0, "Kor'kron, prepare transport to the Undercity.", 12, 0, 100, 378, 0, 16229, 32300, 0, "Thrall - herald of war"),

(@NPC_SYLVANAS, 0, 0, "Lady Proudmoore, the Warchief speaks the truth. This subterfuge was set in motion by Varimathras and Grand Apothecary Putress. It was not the Horde's doing.", 12, 0, 100, 0, 0, 16315, 32290, 0, "Sylvanas - herald of war"),
(@NPC_SYLVANAS, 1, 0, "As the combined Horde and Alliance forces began their assault upon the Wrath Gate, an uprising broke out in the Undercity. Varimathras and hordes of his demonic brethren attacked. Hundreds of my people were slain in the coup. I barely managed to escape with my life.", 12, 0, 100, 0, 0, 16316, 32291, 0, "Sylvanas - herald of war"),

(@NPC_JAINA, 0, 0, "Thrall, what has happened? The King is preparing for war...", 12, 0, 100, 0, 0, 16129, 32288, 0, "Jaina - herald of war"),
(@NPC_JAINA, 1, 0, "I will deliver this information to King Wrynn, Thrall, but...", 12, 0, 100, 378, 0, 16130, 32296, 0, "Jaina - herald of war"),
(@NPC_JAINA, 2, 0, "Bolvar was like a brother to him. In the King's absence, Bolvar kept the Alliance united. He found strength for our people in our darkest hours. He watched over Anduin, raising him as his own.", 12, 0, 100, 378, 0, 16131, 32297, 0, "Jaina - herald of war"),
(@NPC_JAINA, 3, 0, "I fear that the rage will consume him, Thrall. I remain hopeful that reason will prevail, but we must prepare for the worst... for war.", 12, 0, 100, 378, 0, 16132, 32298, 0, "Jaina - herald of war"),
(@NPC_JAINA, 4, 0, "Farewell, Warchief. I pray that the next time we meet it will be as allies.", 12, 0, 100, 0, 0, 16133, 32299, 0, "Jaina - herald of war");

DELETE FROM `gameobject` WHERE `id` IN (@OG_PORTAL, @HORDE_BUILDING5, @HORDE_BUILDING4, @HORDE_BUILDING2, @HORDE_BUILDING3, @UCPORTAL);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID, @OG_PORTAL, 571, 3537, 4129, 1, 1, 2830.01, 6179.37, 84.66, 4.16, 0, 0, 0.715875, -0.698228, 120, 100, 1, 0),
(@OGUID + 1, @HORDE_BUILDING5, 1, 14, 14, 1, 64, 1339.00, -4413.98, 27.25, 2.29, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 2, @HORDE_BUILDING5, 1, 1637, 1637, 1, 64, 1508.90, -4429.49, 21.95, 6.13, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 3, @HORDE_BUILDING4, 1, 14, 14, 1, 64, 1290.05, -4417.47, 26.61, 0.72, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 4, @HORDE_BUILDING4, 1, 14, 14, 1, 64, 1346.67, -4343.90, 27.23, 4.48, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 5, @HORDE_BUILDING2, 1, 14, 14, 1, 64, 1376.69, -4355.44, 26.24, 1.15, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 6, @HORDE_BUILDING2, 1, 1637, 1637, 1, 64, 1437.96, -4365.91, 25.46, 0.41, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 7, @HORDE_BUILDING3, 1, 1637, 1637, 1, 64, 1425.65, -4356.49, 25.46, 4.84, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 8, @HORDE_BUILDING3, 1, 1637, 1637, 1, 64, 1441.50, -4432.17, 25.46, 0.05, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 9, @HORDE_BUILDING2, 1, 1637, 1637, 1, 64, 1429.12, -4423.08, 25.46, 3.28, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 10, @HORDE_BUILDING4, 1, 1637, 1637, 1, 64, 1501.42, -4392.46, 22.69, 4.83, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 11, @UCPORTAL, 1, 1637, 1637, 1, 64, 1912.070923, -4151.778809, 40.637005, 1.635784, 0, 0, 0, 0, 600, 0, 1, 0),
(@OGUID + 12, @UCPORTAL, 1, 1637, 1637, 1, 64, 1931.545288, -4149.240723, 40.600616, 1.804645, 0, 0, 0, 0, 600, 0, 1, 0);

DELETE FROM `creature` WHERE `GUID` BETWEEN @CGUID AND @CGUID + 68;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1313.62, -4504.06, 22.9198, 1.60753, 300, 0, 0, 1, 0, 2, 0, 0, 0, 0),
(@CGUID + 1, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1317.69, -4499.57, 25.0943, 1.60753, 300, 0, 0, 1, 0, 2, 0, 0, 0, 0),
(@CGUID + 2, @REFUGEE2, 1, 14, 14, 1, 64, 0, 0, 1310.69, -4504.17, 22.2043, 1.60753, 300, 0, 0, 1, 0, 2, 0, 0, 0, 0),
(@CGUID + 3, @REFUGEE2, 1, 14, 14, 1, 64, 0, 0, 1311.13, -4518.5, 22.2047, 1.55255, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting

(@CGUID + 4, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1345.48, -4419.18, 27.4299, 2.28297, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 5, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1343.1, -4411.76, 27.6054, 2.31831, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 6, @REFUGEE2, 1, 14, 14, 1, 64, 0, 0, 1338.59, -4416.07, 27.143, 2.25548, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting

(@CGUID + 7, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1348.62, -4339.38, 27.2402, 5.19288, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 8, @REFUGEE2, 1, 14, 14, 1, 64, 0, 0, 1344.26, -4341.66, 27.2953, 5.19288, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting

(@CGUID + 9, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1373.44, -4354.1, 26.3845, 4.51351, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 10, @REFUGEE2, 1, 14, 14, 1, 64, 0, 0, 1377.47, -4355.02, 26.2234, 4.48603, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),

(@CGUID + 11, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1426.94, -4355.01, 25.4626, 4.82374, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID + 12, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1439.5, -4368.21, 25.4626, 3.35504, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID + 13, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1423.99, -4355.34, 25.4626, 4.82374, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 14, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1438.59, -4363.16, 25.4626, 3.44536, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),

(@CGUID + 15, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1442.41, -4382.73, 28.0943, 3.24115, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 16, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1418.21, -4354.67, 28.1022, 4.91012, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping

(@CGUID + 17, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1425.6, -4423.85, 25.4629, 6.16282, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 18, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1428.84, -4420.12, 25.4629, 6.16282, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 19, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1440.43, -4431.69, 25.4629, 1.87456, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 20, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1428.35, -4424.18, 25.4629, 6.16282, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 21, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1425.12, -4421.19, 25.4629, 6.16282, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 22, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1444.34, -4433.12, 25.4629, 1.87456, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting

(@CGUID + 23, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1506.86, -4436.01, 23.113, 1.97747, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 24, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1503.98, -4392.84, 21.9971, 5.36252, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 25, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1499.08, -4393.03, 23.3294, 5.3154, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 26, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1513.89, -4429.5, 20.4131, 1.76542, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 27, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1508.19, -4430.54, 22.2681, 1.89108, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 28, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1499.22, -4387.96, 23.339, 5.07193, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 29, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1503.9, -4386.66, 22.0753, 5.31148, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 30, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1512.58, -4435.7, 21.1882, 1.85966, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping

(@CGUID + 31, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1345.22, -4407.99, 27.9504, 1.99711, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sleeping
(@CGUID + 32, @REFUGEE2, 1, 14, 14, 1, 64, 0, 0, 1336.65, -4409.31, 27.3459, 1.86359, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 33, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1290.52, -4419.55, 26.6016, 1.35857, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 34, @REFUGEE1, 1, 14, 14, 1, 64, 0, 0, 1286.92, -4415.25, 26.5606, 1.23683, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID + 35, @REFUGEE2, 1, 14, 14, 1, 64, 0, 0, 1287.15, -4418.59, 26.5876, 1.29181, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0), -- sitting
(@CGUID + 36, @REFUGEE2, 1, 14, 14, 1, 64, 0, 0, 1294.74, -4416.27, 26.6432, 3.06289, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),

(@CGUID + 37, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1655.2, -4416.18, 16.7609, 3.19012, 300, 0, 0, 1, 0, 2, 0, 0, 0, 0),
(@CGUID + 38, @REFUGEE1, 1, 1637, 1637, 1, 64, 0, 0, 1550.75, -4411.13, 9.02373, 3.24117, 300, 0, 0, 1, 0, 2, 0, 0, 0, 0),
(@CGUID + 39, @REFUGEE2, 1, 1637, 1637, 1, 64, 0, 0, 1588.68, -4440.77, 5.6737, 2.90345, 300, 0, 0, 1, 0, 2, 0, 0, 0, 0),
(@CGUID + 40, @NPC_THRALL, 1, 1637, 1637, 1, 64, 0, 0, 1913.81, -4127.87, 43.23, 0.147480, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID + 41, @NPC_SYLVANAS, 1, 1637, 1637, 1, 64, 0, 0, 1920.589233, -4130.980469, 43.090080, 1.741838, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(@CGUID + 42, @KORKRONGUARDS, 1, 1637, 1637, 1, 64, 0, 1, 1944.779541, -4136.510254, 41.157078, 3.683755, 300, 0, 0, 63000, 0, 0, 0, 0, 0, 0),
(@CGUID + 43, @KORKRONGUARDS, 1, 1637, 1637, 1, 64, 0, 1, 1938.338501, -4215.597168, 42.321674, 3.534525, 300, 0, 0, 63000, 0, 0, 0, 0, 0, 0),
(@CGUID + 44, @KORKRONGUARDS, 1, 1637, 1637, 1, 64, 0, 1, 1926.85, -4134.75, 40.6305, 4.6753, 300, 0, 0, 63000, 0, 0, 0, 0, 0, 0),
(@CGUID + 45, @KORKRONGUARDS, 1, 1637, 1637, 1, 64, 0, 1, 1913.69, -4135.14, 40.6359, 4.79468, 300, 0, 0, 63000, 0, 0, 0, 0, 0, 0),
(@CGUID + 46, @KORKRONGUARDS, 1, 1637, 1637, 1, 64, 0, 1, 1913.99, -4122.2, 43.2624, 4.84964, 300, 0, 0, 63000, 0, 0, 0, 0, 0, 0),
(@CGUID + 47, @KORKRONGUARDS, 1, 1637, 1637, 1, 64, 0, 1, 1925.71, -4121.88, 43.2014, 4.73577, 300, 0, 0, 63000, 0, 0, 0, 0, 0, 0),

(@CGUID + 48, @MOUNTEDORC, 1, 1637, 1637, 1, 64, 0, 0, 1527.04, -4398.42, 14.4175, 3.54668, 300, 0, 0, 31905, 0, 2, 0, 0, 0, 0),
(@CGUID + 49, @MOUNTEDORC, 1, 1637, 1637, 1, 64, 0, 0, 1434.51, -4399.44, 25.4631, 1.64601, 300, 0, 0, 31905, 0, 2, 0, 0, 0, 0),

(@CGUID + 50, @MOUNTEDORC2, 1, 14, 14, 1, 64, 0, 1, 1370.59, -4377.64, 26.0629, 3.47206, 300, 0, 0, 42540, 0, 2, 0, 0, 0, 0),
(@CGUID + 51, @MOUNTEDORC2, 1, 1637, 1637, 1, 64, 0, 1, 1539.24, -4435.88, 12.4312, 1.64208, 300, 0, 0, 42540, 0, 2, 0, 0, 0, 0),

(@CGUID + 52, @NPC_GAMON, 1, 1637, 1637, 1, 64, 0, 0, 1596.91, -4398.47, 7.63585, 0.605362, 300, 0, 0, 247, 0, 0, 0, 0, 0, 0),
(@CGUID + 53, @NPC_OLVIA, 1, 1637, 1637, 1, 64, 0, 1, 1599.6, -4399.69, 8.52417, 0.687829, 300, 0, 0, 2769, 0, 0, 0, 0, 0, 0),
(@CGUID + 54, @NPC_KAJA, 1, 1637, 1637, 1, 64, 0, 1, 1598.06, -4400.97, 7.78653, 0.687829, 300, 0, 0, 1003, 0, 0, 0, 0, 0, 0),
(@CGUID + 55, @NPC_FELIKA, 1, 1637, 1637, 1, 64, 0, 1, 1601.15, -4401.67, 9.1794, 0.801712, 300, 0, 0, 1003, 0, 0, 0, 0, 0, 0),
(@CGUID + 56, @NPC_SANA, 1, 1637, 1637, 1, 64, 0, 0, 1598.94, -4397.32, 8.49337, 0.664267, 300, 0, 0, 1003, 0, 0, 0, 0, 0, 0),
(@CGUID + 57, @NPC_GRYSHKA, 1, 1637, 1637, 1, 64, 0, 1, 1597.02, -4395.84, 8.61465, 0.664267, 300, 0, 0, 1003, 0, 0, 0, 0, 0, 0),
(@CGUID + 58, @NPC_THUNG, 1, 1637, 1637, 1, 64, 0, 0, 1594.9, -4395.75, 8.23313, 0.664267, 300, 0, 0, 126, 0, 0, 0, 0, 0, 0),
(@CGUID + 59, @NPC_COMMONER, 1, 1637, 1637, 1, 64, 0, 0, 1596.92, -4404.38, 7.44287, 0.664267, 300, 0, 0, 1395, 0, 0, 0, 0, 0, 0),
(@CGUID + 60, @NPC_COMMONER, 1, 1637, 1637, 1, 64, 0, 0, 1599.55, -4403.68, 8.18324, 0.664267, 300, 0, 0, 2292, 0, 0, 0, 0, 0, 0),
(@CGUID + 61, @NPC_COMMONER, 1, 1637, 1637, 1, 64, 0, 0, 1595.14, -4402.1, 6.89729, 0.664267, 300, 0, 0, 1110, 0, 0, 0, 0, 0, 0),
(@CGUID + 62, @NPC_COMMONER, 1, 1637, 1637, 1, 64, 0, 0, 1594.08, -4399.7, 6.717, 0.664267, 300, 0, 0, 955, 0, 0, 0, 0, 0, 0),
(@CGUID + 63, @NPC_COMMONER, 1, 1637, 1637, 1, 64, 0, 0, 1592.45, -4397.61, 7.12726, 0.664267, 300, 0, 0, 247, 0, 0, 0, 0, 0, 0),
(@CGUID + 64, @NPC_COMMONER, 1, 1637, 1637, 1, 64, 0, 0, 1592.86, -4394.45, 7.90426, 0.218946, 300, 0, 0, 71, 0, 0, 0, 0, 0, 0),
(@CGUID + 65, @NPC_OVERLORD_RUNTHAK, 1, 1637, 1637, 1, 64, 0, 1, 1606.09, -4396.1, 10.1268, 3.7446, 300, 0, 0, 48832, 0, 0, 0, 0, 0, 0),
(@CGUID + 66, @UC_SYLVANAS, 0, 85, 153, 1, 64, 0, 1, 1943.76, 237.566, 44.276, 3.09834, 300, 0, 0, 6972500, 0, 0, 0, 0, 0, 0),
(@CGUID + 67, @VOLJIN, 0, 85, 153, 1, 64, 0, 1, 1944.09, 245.315, 44.2522, 3.09834, 300, 0, 0, 3585186, 0, 0, 0, 134217728, 0, 0),
(@CGUID + 68, @UC_THRALL, 0, 85, 153, 1, 64, 0, 1, 1943.59, 233.699, 44.3204, 3.09834, 300, 0, 0, 7925544, 0, 0, 0, 134217728, 0, 0);

-- pathing is pure guess, there is no sniff of this event. Seen lots of videos and everybody ignores those fuckers ;[
DELETE FROM `waypoint_data` WHERE `id` IN ((@CGUID + 37) * 10, (@CGUID + 38) * 10, (@CGUID + 39) * 10, @CGUID * 10, (@CGUID + 2) * 10, (@CGUID + 1) * 10, (@CGUID + 51) * 10, (@CGUID + 49) * 10, (@CGUID + 48) * 10, (@CGUID + 50) * 10, (@CGUID + 65) * 10, (@CGUID + 40) * 10);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
((@CGUID + 37) * 10, 1, 1636.727661, -4419.891113, 15.754716, 3.374689, 0, 0, 0, 100, 0),
((@CGUID + 37) * 10, 2, 1597.315430, -4436.729004, 6.685284, 3.547476, 0, 0, 0, 100, 0),
((@CGUID + 37) * 10, 3, 1532.198364, -4418.569824, 12.707468, 2.803703, 0, 0, 0, 100, 0),
((@CGUID + 37) * 10, 4, 1439.670654, -4423.134277, 25.462461, 3.070738, 0, 0, 0, 100, 0),
((@CGUID + 37) * 10, 5, 1428.224976, -4366.074707, 25.462461, 1.739488, 0, 0, 0, 100, 0),
((@CGUID + 37) * 10, 6, 1359.062012, -4372.103516, 26.125994, 3.259234, 0, 0, 0, 100, 0),
((@CGUID + 37) * 10, 7, 1301.137085, -4391.241699, 26.268190, 3.479145, 0, 0, 0, 100, 0),
((@CGUID + 37) * 10, 8, 1359.062012, -4372.103516, 26.125994, 3.259234, 0, 0, 0, 100, 0), -- 6
((@CGUID + 37) * 10, 9, 1428.224976, -4366.074707, 25.462461, 1.739488, 0, 0, 0, 100, 0), -- 5
((@CGUID + 37) * 10, 10, 1439.670654, -4423.134277, 25.462461, 3.070738, 0, 0, 0, 100, 0), -- 4
((@CGUID + 37) * 10, 11, 1532.198364, -4418.569824, 12.707468, 2.803703, 0, 0, 0, 100, 0), -- 3
((@CGUID + 37) * 10, 12, 1597.315430, -4436.729004, 6.685284, 3.547476, 0, 0, 0, 100, 0), -- 2
((@CGUID + 37) * 10, 13, 1636.727661, -4419.891113, 15.754716, 3.374689, 0, 0, 0, 100, 0), -- 1
((@CGUID + 37) * 10, 14, 1661.776733, -4411.652832, 17.281466, 0.494632, 0, 0, 0, 100, 0),

((@CGUID + 38) * 10, 1, 1510.770508, -4415.110840, 19.337944, 3.245882, 0, 0, 0, 100, 0),
((@CGUID + 38) * 10, 2, 1440.086914, -4422.711426, 25.462467, 3.249809, 0, 0, 0, 100, 0),
((@CGUID + 38) * 10, 3, 1424.909790, -4370.168457, 25.462467, 2.820196, 0, 0, 0, 100, 0),
((@CGUID + 38) * 10, 4, 1360.981689, -4377.626953, 26.084114, 3.323637, 0, 0, 0, 100, 0),
((@CGUID + 38) * 10, 5, 1341.317139, -4405.867188, 27.853329, 4.383916, 0, 0, 0, 100, 0),
((@CGUID + 38) * 10, 6, 1312.769043, -4491.074707, 22.622589, 4.560626, 3000, 0, 0, 100, 0),
((@CGUID + 38) * 10, 7, 1341.317139, -4405.867188, 27.853329, 4.383916, 0, 0, 0, 100, 0), -- 5
((@CGUID + 38) * 10, 8, 1360.981689, -4377.626953, 26.084114, 3.323637, 0, 0, 0, 100, 0), -- 4
((@CGUID + 38) * 10, 9, 1424.909790, -4370.168457, 25.462467, 2.820196, 0, 0, 0, 100, 0), -- 3
((@CGUID + 38) * 10, 10, 1440.086914, -4422.711426, 25.462467, 3.249809, 0, 0, 0, 100, 0), -- 2
((@CGUID + 38) * 10, 11, 1510.770508, -4415.110840, 19.337944, 3.245882, 0, 0, 0, 100, 0), -- 1

((@CGUID + 39) * 10, 1, 1519.227173, -4420.032715, 17.018894, 2.832764, 0, 0, 0, 100, 0),
((@CGUID + 39) * 10, 2, 1504.174561, -4397.063477, 21.904577, 1.835307, 4000, 0, 0, 100, 0),
((@CGUID + 39) * 10, 3, 1475.047607, -4416.577637, 25.462658, 3.688848, 0, 0, 0, 100, 0),
((@CGUID + 39) * 10, 4, 1432.220093, -4422.998535, 25.462658, 3.321281, 2500, 0, 0, 100, 0),
((@CGUID + 39) * 10, 5, 1427.358276, -4369.822754, 25.462658, 1.896568, 0, 0, 0, 100, 0),
((@CGUID + 39) * 10, 6, 1378.408691, -4357.613281, 26.151247, 2.623062, 3000, 0, 0, 100, 0),
((@CGUID + 39) * 10, 7, 1352.227661, -4360.893066, 26.748661, 1.684511, 0, 0, 0, 100, 0),
((@CGUID + 39) * 10, 8, 1348.345459, -4345.072754, 27.216478, 1.818029, 2000, 0, 0, 100, 0),
((@CGUID + 39) * 10, 9, 1362.780273, -4367.947266, 26.153179, 5.547090, 0, 0, 0, 100, 0),
((@CGUID + 39) * 10, 10, 1424.892334, -4363.779785, 25.462536, 0.076789, 0, 0, 0, 100, 0),
((@CGUID + 39) * 10, 11, 1449.072754, -4425.893555, 25.462536, 5.519594, 0, 0, 0, 100, 0),
((@CGUID + 39) * 10, 12, 1496.059570, -4419.106445, 23.187777, 0.163175, 0, 0, 0, 100, 0),
((@CGUID + 39) * 10, 13, 1564.113159, -4412.110352, 7.560035, 0.171029, 0, 0, 0, 100, 0),

(@CGUID * 10, 1, 1314.228394, -4472.458496, 23.983208, 1.540771, 0, 0, 0, 100, 0),
(@CGUID * 10, 2, 1315.020996, -4391.339355, 26.246040, 1.591822, 0, 0, 0, 100, 0),
(@CGUID * 10, 3, 1381.445679, -4373.530762, 26.022976, 0.193814, 0, 0, 0, 100, 0),
(@CGUID * 10, 4, 1425.371216, -4371.731445, 25.462433, 5.196810, 0, 0, 0, 100, 0),
(@CGUID * 10, 5, 1437.288330, -4423.067383, 25.462433, 5.133973, 0, 0, 0, 100, 0),
(@CGUID * 10, 6, 1488.331787, -4418.357422, 24.094090, 0.166324, 0, 0, 0, 100, 0),
(@CGUID * 10, 7, 1599.124756, -4407.760742, 7.388023, 0.376025, 10000, 0, 0, 100, 0),
(@CGUID * 10, 8, 1488.331787, -4418.357422, 24.094090, 0.166324, 0, 0, 0, 100, 0), -- 6
(@CGUID * 10, 9, 1437.288330, -4423.067383, 25.462433, 5.133973, 0, 0, 0, 100, 0), -- 5
(@CGUID * 10, 10, 1425.371216, -4371.731445, 25.462433, 5.196810, 0, 0, 0, 100, 0), -- 4
(@CGUID * 10, 11, 1381.445679, -4373.530762, 26.022976, 0.193814, 0, 0, 0, 100, 0), -- 3
(@CGUID * 10, 12, 1315.020996, -4391.339355, 26.246040, 1.591822, 0, 0, 0, 100, 0), -- 2
(@CGUID * 10, 13, 1314.228394, -4472.458496, 23.983208, 1.540771, 0, 0, 0, 100, 0),

((@CGUID + 2) * 10, 1, 1311.382813, -4472.563477, 24.082273, 1.557264, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 2, 1314.851563, -4387.514160, 26.244619, 1.616169, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 3, 1381.291992, -4370.146484, 26.023146, 1.616169, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 4, 1429.167358, -4371.299805, 25.462433, 4.840226, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 5, 1438.546509, -4419.699707, 25.462433, 6.037951, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 6, 1488.069946, -4415.084961, 23.924955, 0.084631, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 7, 1594.640869, -4406.261719, 6.956670,0.752219, 10500, 0, 0, 100, 0),
((@CGUID + 2) * 10, 8, 1488.069946, -4415.084961, 23.924955, 0.084631, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 9, 1438.546509, -4419.699707, 25.462433, 6.037951, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 10, 1429.167358, -4371.299805, 25.462433, 4.840226, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 11, 1381.291992, -4370.146484, 26.023146, 1.616169, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 12, 1314.851563, -4387.514160, 26.244619, 1.616169, 0, 0, 0, 100, 0),
((@CGUID + 2) * 10, 13, 1311.382813, -4472.563477, 24.082273, 1.557264, 0, 0, 0, 100, 0),

((@CGUID + 1) * 10, 1, 1324.306641, -4474.051758, 25.471981, 1.623239, 1000, 0, 0, 100, 0),
((@CGUID + 1) * 10, 2, 1294.313599, -4423.655762, 26.651222, 2.200507, 2000, 0, 0, 100, 0),
((@CGUID + 1) * 10, 3, 1336.517456, -4413.115723, 27.156092, 0.119199, 2000, 0, 0, 100, 0),
((@CGUID + 1) * 10, 4, 1350.187622, -4346.205078, 27.194891, 1.474011, 2000, 0, 0, 100, 0),
((@CGUID + 1) * 10, 5, 1325.687866, -4406.854980, 27.066034, 4.489942, 0, 0, 0, 100, 0),
((@CGUID + 1) * 10, 6, 1312.286133, -4514.444336, 22.207296, 4.427111, 3000, 0, 0, 100, 0),

((@CGUID + 48) * 10, 1, 1503.223022, -4413.273926, 21.462757, 3.743015, 0, 0, 0, 100, 0),
((@CGUID + 48) * 10, 2, 1551.767456, -4439.213867, 10.344376, 5.917779, 0, 0, 0, 100, 0),
((@CGUID + 48) * 10, 3, 1571.801270, -4415.120605, 7.094321, 0.950135, 0, 0, 0, 100, 0),
((@CGUID + 48) * 10, 4, 1530.485962, -4394.278809, 14.629207, 2.725135, 0, 0, 0, 100, 0),

((@CGUID + 49) * 10, 1, 1428.319946, -4368.334961, 25.462538, 1.801508, 0, 0, 0, 100, 0),
((@CGUID + 49) * 10, 2, 1379.236084, -4371.864258, 26.023857, 3.317327, 0, 0, 0, 100, 0),
((@CGUID + 49) * 10, 3, 1317.712158, -4389.084473, 26.241236, 3.439064, 0, 0, 0, 100, 0),
((@CGUID + 49) * 10, 4, 1312.412354, -4495.200684, 22.253731, 4.683920, 0, 0, 0, 100, 0),
((@CGUID + 49) * 10, 5, 1317.712158, -4389.084473, 26.241236, 3.439064, 0, 0, 0, 100, 0),
((@CGUID + 49) * 10, 6, 1379.236084, -4371.864258, 26.023857, 3.317327, 0, 0, 0, 100, 0),
((@CGUID + 49) * 10, 7, 1428.319946, -4368.334961, 25.462538, 1.801508, 0, 0, 0, 100, 0),

((@CGUID + 50) * 10, 1, 1350.657959, -4349.023926, 27.158371, 2.154161, 2000, 0, 0, 100, 0),
((@CGUID + 50) * 10, 2, 1328.607300, -4387.384277, 26.224094, 3.992004, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 3, 1298.629150, -4412.804688, 26.687563, 3.768165, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 4, 1292.821533, -4392.992188, 26.284231, 1.781106, 4000, 0, 0, 100, 0),
((@CGUID + 50) * 10, 5, 1379.779419, -4372.537598, 26.023079, 0.182821, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 6, 1423.772461, -4367.567871, 25.462664, 0.061084, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 7, 1438.552124, -4420.987793, 25.462664, 4.926629, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 8, 1524.945923, -4410.342285, 14.457470, 0.163185, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 9, 1582.459229, -4406.155273, 6.063486, 0.602228, 10000, 0, 0, 100, 0),
((@CGUID + 50) * 10, 10, 1524.945923, -4410.342285, 14.457470, 0.163185, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 11, 1438.552124, -4420.987793, 25.462664, 4.926629, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 12, 1423.772461, -4367.567871, 25.462664, 0.061084, 0, 0, 0, 100, 0),
((@CGUID + 50) * 10, 13, 1379.779419, -4372.537598, 26.023079, 0.182821, 0, 0, 0, 100, 0),

((@CGUID + 51) * 10, 1, 1535.931396, -4416.078125, 11.668506, 1.755966, 0, 0, 0, 100, 0),
((@CGUID + 51) * 10, 2, 1580.108887, -4405.557617, 5.750760, 0.267636, 0, 0, 0, 100, 0),
((@CGUID + 51) * 10, 3, 1651.950684, -4417.000488, 16.760706, 6.232729, 0, 0, 0, 100, 0),
((@CGUID + 51) * 10, 4, 1556.471802, -4436.006348, 8.810843, 3.083283, 0, 0, 0, 100, 0),

((@CGUID + 65) * 10, 1, 1601.677856, -4390.092773, 10.024803, 3.693547, 0, 0, 0, 100, 0),
((@CGUID + 65) * 10, 2, 1607.239624, -4397.162109, 10.247937, 2.237402, 0, 0, 0, 100, 0),

((@CGUID + 40) * 10, 1, 1923.388672, -4126.897949, 43.180893, 6.057603, 0, 0, 0, 100, 0),
((@CGUID + 40) * 10, 2, 1916.156494, -4127.158691, 43.197136, 3.186971, 0, 0, 0, 100, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID + 4, @CGUID + 6, @CGUID + 8, @CGUID + 10, @CGUID + 11 , @CGUID + 12, @CGUID + 14, @CGUID + 18, @CGUID + 19, @CGUID + 21, @CGUID + 22, @CGUID + 23, @CGUID + 25, @CGUID + 27, @CGUID + 29, @CGUID + 32, @CGUID + 5, @CGUID + 7, @CGUID + 9, @CGUID + 13, @CGUID + 15, @CGUID + 16, @CGUID + 17, @CGUID + 20, @CGUID + 24, @CGUID + 26, @CGUID + 28, @CGUID + 30, @CGUID + 31, @CGUID + 35, @CGUID + 33, @CGUID + 34, @CGUID + 3);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
-- sitting
(@CGUID + 4, 0, 0, 1, 0, 0, ""),
(@CGUID + 6, 0, 0, 1, 0, 0, ""),
(@CGUID + 8, 0, 0, 1, 0, 0, ""),
(@CGUID + 10, 0, 0, 1, 0, 0, ""),
(@CGUID + 11, 0, 0, 1, 0, 0, ""),
(@CGUID + 12, 0, 0, 1, 0, 0, ""),
(@CGUID + 14, 0, 0, 1, 0, 0, ""),
(@CGUID + 18, 0, 0, 1, 0, 0, ""),
(@CGUID + 19, 0, 0, 1, 0, 0, ""),
(@CGUID + 21, 0, 0, 1, 0, 0, ""),
(@CGUID + 22, 0, 0, 1, 0, 0, ""),
(@CGUID + 23, 0, 0, 1, 0, 0, ""),
(@CGUID + 25, 0, 0, 1, 0, 0, ""),
(@CGUID + 27, 0, 0, 1, 0, 0, ""),
(@CGUID + 29, 0, 0, 1, 0, 0, ""),
(@CGUID + 32, 0, 0, 1, 0, 0, ""),
(@CGUID + 35, 0, 0, 1, 0, 0, ""),
(@CGUID + 33, 0, 0, 1, 0, 0, ""),
(@CGUID + 3, 0, 0, 1, 0, 0, ""),

-- sleeping
(@CGUID + 5, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 7, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 9, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 13, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 15, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 16, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 17, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 20, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 24, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 26, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 28, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 30, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 31, 0, 0, 3, 0, 0, "42648"),
(@CGUID + 34, 0, 0, 3, 0, 0, "42648");

-- pathing and mounts
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID + 37, @CGUID + 38, @CGUID + 39, @CGUID, @CGUID + 2, @CGUID + 1, @CGUID + 51, @CGUID + 48, @CGUID + 49, @CGUID + 50);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID + 37, (@CGUID + 37) * 10, 0, 0, 0, 0, ""),
(@CGUID + 38, (@CGUID + 38) * 10, 0, 0, 0, 0, ""),
(@CGUID + 39, (@CGUID + 39) * 10, 0, 0, 0, 0, ""),
(@CGUID, @CGUID * 10, 0, 0, 0, 0, ""),
(@CGUID + 2, (@CGUID + 2) * 10, 0, 0, 0, 0, ""),
(@CGUID + 1, (@CGUID + 1) * 10, 0, 0, 0, 0, ""),
(@CGUID + 51, (@CGUID + 51) * 10, 29283, 0, 0, 0, ""),
(@CGUID + 50, (@CGUID + 50) * 10, 29283, 0, 0, 0, ""),
(@CGUID + 48, (@CGUID + 48) * 10, 29260, 0, 0, 0, ""),
(@CGUID + 49, (@CGUID + 49) * 10, 29260, 0, 0, 0, "");

DELETE FROM `gameobject_addon` WHERE `guid` IN (@OGUID, @OGUID + 11, @OGUID + 12);
INSERT INTO `gameobject_addon` (`guid`, `invisibilityType`, `invisibilityValue`) VALUES
(@OGUID, 7, 1000),
(@OGUID + 11, 7, 1000),
(@OGUID + 12, 7, 1000);

DELETE FROM `spell_area` WHERE `spell` IN (60943, 59062);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(60943, 4129, 13257, 13257, 0, 690, 2, 1, 2, 2),
(59062, 14, 13257, 13267, 0, 690, 2, 1, 66, 11),
(59062, 1637, 13257, 13267, 0, 690, 2, 1, 66, 11),
(60943, 1637, 13266, 0, 0, 690, 2, 1, 2, 0),

(59062, 85, 13257, 13267, 0, 690, 2, 1, 64, 11), -- tirisfal glades
(59062, 1497, 13257, 13267, 0, 690, 2, 1, 64, 11); -- undercity

DELETE FROM `spell_script_names` WHERE `spell_id` IN (@OG_TELEPORTSPELL, @UCTELEPORTSPELL);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(@OG_TELEPORTSPELL, 'spell_59064_59439_portals'),
(@UCTELEPORTSPELL, 'spell_59064_59439_portals');

-- Its not sniff verified, if anyone got any info about it, you're more than welcome to correct it
DELETE FROM `spell_target_position` WHERE `ID` IN (58419, 59448);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(58419, 0, 1, 1336.34, -4374.32, 26.19, 0.09, 0),
(59448, 0, 0, 1962.69, 235.92, 39.77, 3.09, 0);
