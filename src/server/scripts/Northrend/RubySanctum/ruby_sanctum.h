/* Copyright (C) 2010 Easy for TrinityCore <http://trinity-core.ru/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*
DELETE FROM script_texts where `entry` <= -1752008 AND `entry` >= -1752016;
DELETE FROM script_texts where `entry` <= -1752001 AND `entry` >= -1752006;
DELETE FROM script_texts where `entry` <= -1752017 AND `entry` >= -1752036;

INSERT INTO script_texts (`entry`, `content_default`, `npc_entry`, `content_loc3`, `sound`, `type`, `language`) VALUES
('-1752008', 'Help! I am trapped within this tree! I require aid!', '0', '', '17490', '1', '0'),         
('-1752009', 'Thank you! I could not have held out for much longer.... A terrible thing has happened here.', '0', '', '17491', '1', '0'),         
('-1752010', 'We believed the Sanctum was well-fortified, but we were not prepared for the nature of this assault.', '0', '', '17492', '0', '0'),         
('-1752011', 'The Black dragonkin materialized from thin air, and set upon us before we could react.', '0', '', '17493', '0', '0'),     
('-1752012', 'We did not stand a chance. As my brethren perished around me, I managed to retreat here and bar the entrance.', '0', '', '17494', '0', '0'),     
('-1752013', 'They slaughtered us with cold efficiency, but the true focus of their interest seemed to be the eggs kept here in the Sanctum.', '0', '', '17495', '0', '0'),    
('-1752014', 'The commander of the forces on the ground here is a cruel brute named Zarithrian, but I fear there are greater powers at work.', '0', '', '17496', '0', '0'),    
('-1752015', 'In their initial assault, I caught a glimpse of their true leader, a fearsome full-grown twilight dragon.', '0', '', '17497', '0', '0'),    
('-1752016', 'I know not the extent of their plans, heroes, but I know this: They cannot be allowed to succeed!', '0', '', '17498', '0', '0'),

( -1752001, "Ah, the entertainment has arrived.", 0, "", 17520, 1, 0),
( -1752002, "Baltharus leaves no survivors!", 0, "", 17521, 1, 0),
( -1752003, "This world has enough heroes.", 0, "", 17522, 1, 0),
( -1752004, "I..Didn''t saw...that coming...", 0, "", 17523, 1, 0),
( -1752005, "Twice the pain and half the fun.", 0, "", 17524, 1, 0),
( -1752006, "Your power wanes, ancient one.... Soon you will join your friends.", 0, "", 17525, 1, 0),

( -1752017, "Alexstrasza has chosen capable allies... A pity that I must END YOU!", 0, "", 17512, 1, 0),
( -1752018, "You thought you stood a chance?", 0, "", 17513, 1, 0),
( -1752019, "It''s for the best.", 0, "", 17514, 1, 0),
( -1752020, "HALION! I...", 0, "", 17515, 1, 0),
( -1752021, "Turn them to ashes, minions!", 0, "", 17516, 1, 0),

( -1752022, "You will sssuffer for this intrusion!", 0, "", 17528, 1, 0),
( -1752023, "As it should be...", 0, "", 17529, 1, 0),
( -1752024, "Halion will be pleased", 0, "", 17530, 1, 0),
( -1752025, "Hhrr...Grr..", 0, "", 17531, 1, 0),
( -1752026, "Burn in the master's flame!", 0, "", 17532, 1, 0),

(-1752027, 'Insects! You''re too late. The Ruby Sanctum is lost.',NULL,NULL,17499,0,0),
(-1752028, 'Your world teeters on the brink of annihilation. You will ALL bear witness to the coming of a new age of DESTRUCTION!',NULL,NULL,17500,0,0),
(-1752029, 'Another hero falls.',NULL,NULL,17501,0,0),
(-1752030, 'Hahahahaha.',NULL,NULL,17502,0,0),
(-1752031, 'Relish this victory, mortals, for it will be your last! This world will burn with the master''s return!',NULL,NULL,17503,0,0),
(-1752032, 'Not good enough.',NULL,NULL,17504,0,0),
(-1752033, 'The heavens burn!',NULL,NULL,17505,0,0),
(-1752034, 'Beware the shadow!',NULL,NULL,17506,0,0),
(-1752035, 'You will find only suffering within the realm of twilight! Enter if you dare!',NULL,NULL,17507,0,0),
(-1752036, 'I am the light and the darkness! Cower, mortals, before the herald of Deathwing!',NULL,NULL,17508,0,0);

UPDATE `instance_template` SET `script`='instance_ruby_sanctum' WHERE (`map`='724');
UPDATE `creature_template` SET `ScriptName` = 'boss_baltharus' WHERE `entry` = '39751';
UPDATE `creature_template` SET `ScriptName` = 'boss_baltharus_summon' WHERE `entry` = '39899';
UPDATE `creature_template` SET `ScriptName` = 'npc_xerestrasza' WHERE `entry` = '40429';
UPDATE `creature_template` SET `ScriptName` = 'boss_zarithrian' WHERE `entry` = '39746';
UPDATE `creature_template` SET `ScriptName` = 'boss_ragefire' WHERE `entry` = '39747';
UPDATE `creature_template` SET `ScriptName` = 'boss_halion' WHERE `entry`= '39863';
UPDATE `creature_template` SET `ScriptName` = 'boss_twilight_halion' WHERE `entry` = '40142';
UPDATE `creature_template` SET `ScriptName` = 'npc_onyx_flamecaller' WHERE `entry` = '39814';
UPDATE `creature_template` SET `ScriptName` = 'npc_meteor_strike, `flags_extra`=128' WHERE `entry` = '40041';
UPDATE `creature_template` SET `ScriptName` = 'npc_meteor_flame', `flags_extra`=128 WHERE `entry` = '40042';
UPDATE `creature_template` SET `ScriptName` = 'npc_spell_meteor_strike', `flags_extra`=128 WHERE `entry` = '40029';
UPDATE `creature_template` SET `name`='summon halion', `ScriptName` = 'npc_summon_halion', `flags_extra`=128 WHERE `entry` = '40044';

REPLACE `spell_script_names` SET `ScriptName` = 'spell_halion_portal', `spell_id`=74812;

UPDATE `gameobject_template` SET `data10`=74807 WHERE `entry`=202794;
UPDATE `gameobject_template` SET `data10`=74812 WHERE `entry`=202796;

DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='-74562') AND (`spell_effect`='74610');
DELETE FROM `spell_linked_spell` WHERE (`spell_trigger`='-74792') AND (`spell_effect`='74800');
INSERT INTO spell_linked_spell VALUES (-74562, 74610, 0, 'Fiery Combustion removed -> Combustion');
INSERT INTO spell_linked_spell VALUES (-74792, 74800, 0, 'Soul Consumption removed -> Consumption');

DELETE FROM creature WHERE `id`=39863 and `map`=724;
INSERT INTO creature VALUES (null,39863,724,15,1,0,0,3144.93,527.233,72.8887,0.110395,300,0,0,11156000,0,0,0);
*/

#ifndef DEF_RUBY_SANCTUM_H
#define DEF_RUBY_SANCTUM_H

static const Position SpawnPosHalion = {3144.93f, 527.233f, 72.8887f, 0.110395f};

enum eData
{
    DATA_BALTHARUS       = 0,
    DATA_RAGEFIRE        = 1,
    DATA_ZARITHRIAN      = 2,
    DATA_HALION          = 3,
    MAX_ENCOUNTER        = 4,
    DATA_XERESTRASZA     = 5,
    DATA_TWILIGHT_HALION = 6,
    DATA_DAMAGE          = 7
};

enum eAchievementData
{
    TWILIGHT_DESTROYER_NORMAL_10    = 4817,
    TWILIGHT_DESTROYER_NORMAL_25    = 4815,
    TWILIGHT_DESTROYER_HEROIC_10    = 4818,
    TWILIGHT_DESTROYER_HEROIC_25    = 4816
};

enum eCreature
{
    NPC_BALTHARUS        = 39751,
    NPC_BALTHARUS_SUMMON = 39899,
    NPC_ZARITHRIAN       = 39746,
    NPC_RAGEFIRE         = 39747,
    NPC_HALION           = 39863,
    NPC_TWILIGHT_HALION  = 40142,
    NPC_XERESTRASZA      = 40429,
    NPC_ONYX_FLAMECALLER = 39814,
    NPC_METEOR_STRIKE    = 40041,//40029
    NPC_METEOR_FLAME     = 40042,
    NPC_SUMMON_HALIOH    = 40044,
    //возгорание         = 40001
};

enum eGameObject
{
    GO_FIRE_FIELD       = 203005,
    GO_FLAME_WALLS      = 203006,
    GO_FLAME_WALLS2     = 203007,
    GO_FLAME_WALLS3     = 203624,
    GO_TWILIGHT_PORTAL1 = 202794,
    GO_TWILIGHT_PORTAL2 = 202796
};

#endif

