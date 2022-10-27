-- Warlord Breka Grimaxe Entry: 140350
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=166827;

DELETE FROM `spell_target_position` WHERE `ID`=325131;
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(325131,3,2175,-462.4,-2619.8,0.4,45745);

DELETE FROM `scene_template` WHERE `SceneId`=2487;
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2487,16,2708,0,'scene_alliance_and_horde_crash');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=-305445;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-305445,344889,0,'Knocked Down (DNT) removal triggers Knocked Down (DNT)');

DELETE FROM `spell_script_names` WHERE `spell_id`=325131;
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(325131,'spell_q59928_spell_ship_crash_teleport');

DELETE FROM `spell_area` WHERE `spell`=346799;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_end`,`aura_spell`,`racemask`,`gender`,`flags`,`quest_start_status`,`quest_end_status`) VALUES
(346799,10453,59928,0,325131,0,2,1,64,0);
