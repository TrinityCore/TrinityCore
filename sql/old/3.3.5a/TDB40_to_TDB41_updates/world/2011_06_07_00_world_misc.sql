DELETE FROM `spell_script_names` WHERE `spell_id` IN(63018,65121,64234,63024,62791);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(63018,'spell_xt002_searing_light_spawn_life_spark'),
(65121,'spell_xt002_searing_light_spawn_life_spark'),
(64234,'spell_xt002_gravity_bomb_spawn_void_zone'),
(63024,'spell_xt002_gravity_bomb_spawn_void_zone'),
(62791,'spell_xt002_heart_overload_periodic');

DELETE FROM `spell_dbc` WHERE `Id`=62791;
INSERT INTO `spell_dbc` (`Id`,`Effect1`,`Comment`) VALUES (62791,3,'XT-002 Heart Overload Trigger Spell');

DELETE FROM `vehicle_template_accessory` WHERE `entry`=33293;
INSERT INTO `vehicle_template_accessory` (`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(33293,33329,0,1,'XT-002 Deconstructor - Heart',6,30000);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=33293;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(33293,63852,0,0,0,1,0,0,0);

-- Template updates for creature 33293 (XT-002 Deconstructor)
UPDATE `creature_template` SET `speed_run`=1.7142857142857 WHERE `entry`=33293; -- XT-002 Deconstructor
-- Model data 28611 (creature 33293 (XT-002 Deconstructor))
UPDATE `creature_model_info` SET `bounding_radius`=0.465,`combat_reach`=1,`gender`=2 WHERE `modelid`=28611; -- XT-002 Deconstructor
-- Addon data for creature 33293 (XT-002 Deconstructor)
DELETE FROM `creature_template_addon` WHERE `entry`=33293;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(33293,0,0,1,0, NULL); -- XT-002 Deconstructor
