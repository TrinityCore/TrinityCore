-- Anub'Rekhan cleanup
-- areatrigger for greeting upon entering room
DELETE FROM `areatrigger_scripts` WHERE `entry`=4119;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4119,"at_anubrekhan_entrance");

-- make crypt guards aggro anub when pulled
DELETE FROM `smart_scripts` WHERE `entryorguid`=16573 AND `source_type`=0 AND `id` IN (6,7);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_chance`,`event_flags`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`target_type`,`comment`) VALUES
(16573,0, 6, 0, 4,100,0, 39,   25,    0, 0, 0, "Crypt Guard - On Aggro - Call For Help (25yd)"),
(16573,0, 7, 5,61,100,0,  1,    0,    0, 0, 0, "Crypt Guard - On Cast Frenzy - Say EMOTE_FRENZY");
UPDATE `smart_scripts` SET `link`=7 WHERE `entryorguid`=16573 AND `source_type`=0 AND `id`=5;

DELETE FROM `creature_text` WHERE `entry`=16573;
DELETE FROM `creature_text` WHERE `entry`=15956 AND `groupid`=3;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`probability`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(16573,0,0,"%s goes into a frenzy!",16,100,1191,3,"Crypt Guard EMOTE_FRENZY"),
(16573,1,0,"A Crypt Guard joins the fight!",41,100,29887,3,"Crypt Guard EMOTE_SPAWN"),
(16573,2,0,"Corpse Scarabs appear from a Crypt Guard's corpse!",41,100,32796,3,"Crypt Guard EMOTE_SCARAB"),
(15956,3,0,"Anub'Rekhan begins to unleash an insect swarm!",41,100,13443,3,"Anub'Rekhan EMOTE_LOCUST");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=15956;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`) VALUES
(15956,0,1,16573, 3300.503, -3503.574, 287.1606, 2.321288, 8),
(15956,0,1,16573, 3299.283, -3450.938, 287.1606, 3.839724, 8),
(15956,0,2,16573, 3334.41 , -3476.84 , 287.1553, 0, 8);
