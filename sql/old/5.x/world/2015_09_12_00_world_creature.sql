DELETE FROM `creature` WHERE `guid` = 26252;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `npcflag2`, `unit_flags`, `unit_flags2`, `dynamicflags`, `isActive`, `protec_anti_doublet`) VALUES
(26252, 3840, 43, 718, 718, 2, 65535, 0, 1174, -33.8376, 248.391, -93.5922, 4.77298, 300, 0, 0, 2424, 912, 0, 0, 0, 0, 0, 0, 0, NULL);

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_lady_anacondra' WHERE `entry` =3671;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_lord_pythas' WHERE `entry` =3670;

UPDATE `creature_template` SET `AIName` = '', `ScriptName` = 'boss_lord_cobrahn' WHERE `entry` =3669;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3671,3670,3669);

DELETE FROM `creature_template_addon` WHERE `entry` IN (3671,3670,3669);

DELETE FROM `creature_text` WHERE `entry` IN (3671,3670);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(3671, 0, 0, 'None can stand against the Serpent Lords!', 14, 0, 100, 0, 0, 5786, 'Lady Anacondra - SAY_AGGRO'),
(3670, 0, 0, 'The coils of death will crush you!', 14, 0, 100, 0, 0, 5787, 'Lord Pythas - SAY_AGGRO');


UPDATE `creature_text` SET `type` = '14', `comment` = 'Lord Cobrahn - SAY_AGGRO' WHERE `entry` =3669 AND `groupid` =0 AND `id` =0;
