UPDATE `creature_template` SET `dynamicflags`=32 WHERE `entry` IN (27457,27481,26513,26516); -- Skirmisher Corpse, Westfall Infantry Corpse, Drakkari Shaman Corpse, Drakkari Warrior Corpse

DELETE FROM `creature_template_addon` WHERE `entry` IN (27457,27481);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(27457,0,0,1,0, '29266'), -- Skirmisher Corpse (Permanent Feign Death)
(27481,0,0,1,0, '29266'); -- Westfall Infantry Corpse (Permanent Feign Death)

UPDATE `creature_template_addon` SET `bytes1`=0,`bytes2`=1,`mount`=0,`emote`=0,`auras`='29266' WHERE `entry` IN (26513,26516); -- Drakkari Shaman Corpse (Permanent Feign Death)

UPDATE `creature` SET `MovementType`=0, `spawndist`=0 WHERE `id` IN (27457,27481,26513,26516);
DELETE FROM `creature_addon` WHERE `guid` IN (102034,102035,102036,102037,102038,102041,102042,102043,102044,102045,102046,102047,103956,103957,103958,103959,103960,103972,103973,103974,103975,103976,103977,103978,103984,103985,103986,103987);

DELETE FROM `creature_ai_scripts` WHERE `creature_id`=27570;
