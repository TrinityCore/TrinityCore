alter table `item_template`
    drop column `dmg_type3`,
    drop column `dmg_max3`,
    drop column `dmg_min3`,
    drop column `dmg_type4`,
    drop column `dmg_max4`,
    drop column `dmg_min4`,
    drop column `dmg_type5`,
    drop column `dmg_max5`,
    drop column `dmg_min5`;

alter table `creature_template`
    add column `unk1` int(11) UNSIGNED DEFAULT '0' NOT NULL after `heroic_entry`,
    add column `unk2` int(11) UNSIGNED DEFAULT '0' NOT NULL after `unk1`,
    add column `questItem1` int(11) UNSIGNED DEFAULT '0' NOT NULL after `RacialLeader`,
    add column `questItem2` int(11) UNSIGNED DEFAULT '0' NOT NULL after `questItem1`,
    add column `questItem3` int(11) UNSIGNED DEFAULT '0' NOT NULL after `questItem2`,
    add column `questItem4` int(11) UNSIGNED DEFAULT '0' NOT NULL after `questItem3`,
    add column `movementId` int(11) UNSIGNED DEFAULT '0' NOT NULL after `questItem4`;

alter table `item_template`
    add column `HolidayId` int(11) UNSIGNED DEFAULT '0' NOT NULL after `ItemLimitCategory`;

alter table `gameobject_template`
    add column `unk1` varchar(100) NOT NULL default ''            after `castBarCaption`,
    add column `questItem1` int(11) UNSIGNED DEFAULT '0' NOT NULL after `size`,
    add column `questItem2` int(11) UNSIGNED DEFAULT '0' NOT NULL after `questItem1`,
    add column `questItem3` int(11) UNSIGNED DEFAULT '0' NOT NULL after `questItem2`,
    add column `questItem4` int(11) UNSIGNED DEFAULT '0' NOT NULL after `questItem3`;

DELETE FROM `spell_bonus_data` WHERE `entry` IN (18265);

/* Blackout removed */
DELETE FROM spell_proc_event WHERE entry IN (15268, 15269, 15323, 15324, 15325, 15326);
/* Improved Wing Clip removed */
DELETE FROM spell_proc_event WHERE entry IN (19228, 19232, 19233);
/* Shadow Mastery, not have charges now */
DELETE FROM spell_proc_event WHERE entry IN (17794,17797,17798,17799,17800);
/* Lightning Overload have 3 ranks now, 2 dropped */
DELETE FROM spell_proc_event WHERE entry IN (30680,30681);
/* Unleashed Rage have 3 ranks now, 2 dropped */
DELETE FROM spell_proc_event WHERE entry IN (30806,30807,30810,30811);
/* Concussive Barrage have 2 ranks now, 1 dropped */
DELETE FROM spell_proc_event WHERE entry IN (35103);
/* Demonic Empathy, removed */
DELETE FROM spell_proc_event WHERE entry IN (47232,47234,47235);
/* Rapture have 3 ranks now, 2 dropped */
DELETE FROM spell_proc_event WHERE entry IN (47538,47539);
/* Psychic Horror have 1 rank now, 1 dropped */
DELETE FROM spell_proc_event WHERE entry IN (47572);
/* Sudden Doom have 3 ranks now, 2 dropped */
DELETE FROM spell_proc_event WHERE entry IN (49531,49532);
/* Hunting Party have 3 ranks now, 2 dropped */
DELETE FROM spell_proc_event WHERE entry IN (53293,53294);
/* Righteous Vengeance have 3 ranks now, 2 dropped */
DELETE FROM spell_proc_event WHERE entry IN (53383,53384);
/* Night of the Dead not have charges now */
DELETE FROM spell_proc_event WHERE entry IN (55620,55623);
/* Pandemic have 1 rank, 2 dropped */
DELETE FROM spell_proc_event WHERE entry IN (58436,58437);
/* Improved Holy Concentration, removed */
DELETE FROM spell_proc_event WHERE entry IN (47549,47551,47552);
/* Serendipity, replace by aanother spell ids */
DELETE FROM spell_proc_event WHERE entry IN (47555,47556,47557);
/* T.N.T. non triggring now */
DELETE FROM spell_proc_event WHERE entry IN (56333,56336,56337);
