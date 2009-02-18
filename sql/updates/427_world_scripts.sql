UPDATE `instance_template` SET `script`='instance_scarlet_monastery' WHERE `map`='189';
UPDATE `gameobject_template` SET `ScriptName`='go_loosely_turned_soil' WHERE `entry`='186314';

UPDATE `creature_template` SET `ScriptName`='boss_headless_horseman',
`minlevel`=70, `maxlevel`=70, `minhealth`=67068, `maxhealth`=67068,
`minmana`=3155, `maxmana`=3155, `type`=6
 WHERE `entry` = 23682;

UPDATE `creature_template` SET `ScriptName`='mob_head',
 `minlevel`=70, `maxlevel`=70, `type`=6, `modelid_h`=21908,
`minhealth`=24300, `maxhealth`=24300,
`faction_A`=14, `faction_H`=14
WHERE `entry` = 23775;

UPDATE `creature_template` SET `ScriptName`='mob_pulsing_pumpkin',
`faction_A`=14, `faction_H`=14, `type`=6,
`minlevel`=70, `maxlevel`=70,
`minhealth`=9781, `maxhealth`=9781,
`minmana`=3155, `maxmana`=3155
WHERE `entry` = 23694;

-- helper
UPDATE `creature_template` SET `ScriptName`='mob_wisp_invis',
`faction_A`=35, `faction_H`=35,
`unit_flags`='33554434' WHERE `entry`='23686';

-- pumpkin fiend
UPDATE `creature_template` SET
 `minlevel`=70, `maxlevel`=70,
`faction_A`=14, `faction_H`=14,
`type`=6
WHERE `entry`='23545';

-- wisp
UPDATE `creature_template` SET `ScriptName`='mob_wisp_invis',
`modelid_a`=21342, `modelid_h`=21342,
`faction_A`=35, `faction_H`=35, `unit_flags`='33554434'
WHERE `entry`='24034';

UPDATE `creature_template` SET `equipment_id`=23682 WHERE `entry` = 23682;
replace into`creature_equip_template` (`entry`, `equipmodel1`, `equipmodel2`, `equipmodel3`, `equipinfo1`, `equipinfo2`, `equipinfo3`, `equipslot1`, `equipslot2`, `equipslot3`)
VALUES (23682, 50495, 0, 0, 33490690, 0, 0, 781, 0, 0);

REPLACE INTO `script_texts` VALUES
(-1189001, 'It is over, your search is done! Let fate choose now, the righteous one',0,0,0,0,0,0,0,0,11961,1,0,'Headless Horseman SAY_ENTRANCE'),

(-1189002, 'Here\'s my body, fit and pure! Now, your blackened souls I\'ll cure!',0,0,0,0,0,0,0,0,12567,1,0,'Headless Horseman SAY_REJOINED'),

(-1189003, 'Over here, you idiot!',0,0,0,0,0,0,0,0,12569,1,0,'Headless Horseman SAY_LOST_HEAD'),

(-1189004, 'Harken, cur! Tis you I spurn! Now, $N, feel the burn!',0,0,0,0,0,0,0,0,12573,1,0,'Headless Horseman SAY_CONFLAGRATION'),

(-1189005, 'Soldiers arise, stand and fight! Bring victory at last to this fallen knight!',0,0,0,0,0,0,0,0,11963,1,0,'Headless Horseman SAY_SPROUTING_PUMPKINS'),

(-1189006, 'Your body lies beaten, battered and broken. Let my curse be your own, fate has spoken',0,0,0,0,0,0,0,0,11962,0,0,'Headless Horseman SAY_PLAYER_DEATH'),

(-1189007, 'This end have I reached before. What new adventure lies in store?',0,0,0,0,0,0,0,0,11964,0,0,'Headless Horseman SAY_DEATH');

