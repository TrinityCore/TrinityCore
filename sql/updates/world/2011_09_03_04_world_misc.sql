UPDATE `creature_template` SET `npcflag`=`npcflag`|0x1000000 WHERE `entry` in(31770,31736);
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`npcflag`=`npcflag`|0x1000000,`VehicleId`=282,`spell1`=59643,`spell2`=4342,`spell3`=4336 WHERE `entry`=31785;
UPDATE `creature_template` SET `minlevel`=80,`maxlevel`=80,`exp`=2,`npcflag`=`npcflag`|0x1000000,`VehicleId`=282,`spell1`=4338,`spell2`=4342,`spell3`=4336 WHERE `entry`=31784;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` in (31785,31770,31736,31784);
INSERT INTO `npc_spellclick_spells` VALUES
(31785,59656,13283,1,13283,1,0,0,0),
(31770,59654,0,0,0,1,0,0,0),
(31736,59592,13280,1,13280,1,0,0,0),
(31784,59593,0,0,0,1,0,0,0);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (59643,4338);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(59643, 'spell_q13280_13283_plant_battle_standard'),
(4338, 'spell_q13280_13283_plant_battle_standard');