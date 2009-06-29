ALTER TABLE `item_template`
    DROP COLUMN `dmg_type3`,
    DROP COLUMN `dmg_max3`,
    DROP COLUMN `dmg_min3`,
    DROP COLUMN `dmg_type4`,
    DROP COLUMN `dmg_max4`,
    DROP COLUMN `dmg_min4`,
    DROP COLUMN `dmg_type5`,
    DROP COLUMN `dmg_max5`,
    DROP COLUMN `dmg_min5`;

ALTER TABLE `creature_template`
    ADD COLUMN `unk1` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `heroic_entry`,
    ADD COLUMN `unk2` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `unk1`,
    ADD COLUMN `questItem1` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `RacialLeader`,
    ADD COLUMN `questItem2` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `questItem1`,
    ADD COLUMN `questItem3` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `questItem2`,
    ADD COLUMN `questItem4` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `questItem3`,
    ADD COLUMN `movementId` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `questItem4`;

ALTER TABLE `item_template`
    ADD COLUMN `HolidayId` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `ItemLimitCategory`;

ALTER TABLE `gameobject_template`
    ADD COLUMN `unk1` varchar(100) NOT NULL default ''            AFTER `castBarCaption`,
    ADD COLUMN `questItem1` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `size`,
    ADD COLUMN `questItem2` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `questItem1`,
    ADD COLUMN `questItem3` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `questItem2`,
    ADD COLUMN `questItem4` int(11) UNSIGNED DEFAULT '0' NOT NULL AFTER `questItem3`;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (18265);

/* Blackout removed */
DELETE FROM `spell_proc_event` WHERE `entry` IN (15268, 15269, 15323, 15324, 15325, 15326);
/* Improved Wing Clip removed */
DELETE FROM `spell_proc_event` WHERE `entry` IN (19228, 19232, 19233);
/* Shadow Mastery, not have charges now */
DELETE FROM `spell_proc_event` WHERE `entry` IN (17794,17797,17798,17799,17800);
/* Lightning Overload have 3 ranks now, 2 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (30680,30681);
/* Unleashed Rage have 3 ranks now, 2 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (30806,30807,30810,30811);
/* Concussive Barrage have 2 ranks now, 1 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (35103);
/* Demonic Empathy, removed */
DELETE FROM `spell_proc_event` WHERE `entry` IN (47232,47234,47235);
/* Rapture have 3 ranks now, 2 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (47538,47539);
/* Psychic Horror have 1 rank now, 1 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (47572);
/* Sudden Doom have 3 ranks now, 2 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (49531,49532);
/* Hunting Party have 3 ranks now, 2 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (53293,53294);
/* Righteous Vengeance have 3 ranks now, 2 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (53383,53384);
/* Night of the Dead not have charges now */
DELETE FROM `spell_proc_event` WHERE `entry` IN (55620,55623);
/* Pandemic have 1 rank, 2 dropped */
DELETE FROM `spell_proc_event` WHERE `entry` IN (58436,58437);
/* Improved Holy Concentration, removed */
DELETE FROM `spell_proc_event` WHERE `entry` IN (47549,47551,47552);
/* Serendipity, replace by aanother spell ids */
DELETE FROM `spell_proc_event` WHERE `entry` IN (47555,47556,47557);
/* T.N.T. non triggring now */
DELETE FROM `spell_proc_event` WHERE `entry` IN (56333,56336,56337);