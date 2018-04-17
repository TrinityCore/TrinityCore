UPDATE creature_template SET scriptname = "" WHERE entry = 22990;
UPDATE creature_template SET scriptname = "boss_shade_of_akama" WHERE entry = 22841;
UPDATE creature_template SET scriptname = "npc_ashtongue_channeler" WHERE entry = 23421;
UPDATE creature_template SET scriptname = "npc_akama_shade" WHERE entry = 23191;
UPDATE creature_template SET scriptname = "npc_creature_generator_akama" WHERE entry = 23210;
UPDATE creature_template SET scriptname = "npc_ashtongue_sorcerer" WHERE entry = 23215;
UPDATE creature_template SET scriptname = "npc_ashtongue_defender" WHERE entry = 23216;
UPDATE creature_template SET scriptname = "npc_ashtongue_rogue" WHERE entry = 23318;
UPDATE creature_template SET scriptname = "npc_ashtongue_broken" WHERE entry = 23319;
UPDATE creature_template SET scriptname = "npc_ashtongue_elementalist" WHERE entry = 23523;
UPDATE creature_template SET scriptname = "npc_ashtongue_spiritbinder" WHERE entry = 23524;

DELETE FROM creature WHERE guid IN (78705, 347467);
DELETE FROM creature WHERE id IN (23319, 23191, 23421, 23524, 23523, 23318, 23215);

DELETE FROM spell_script_names WHERE scriptname IN ("spell_shade_soul_channel_serverside", "spell_shade_soul_channel");
INSERT INTO spell_script_names VALUES
(40401, "spell_shade_soul_channel_serverside"),
(40520, "spell_shade_soul_channel");

UPDATE gameobject SET isactive = 1 WHERE id = 185882;

delete from `creature_text` where `CreatureID` = 23191;
insert into `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) values
('23191','0','0','Broken of the Ashtongue tribe, your leader speaks!','14','0','100','0','0','0','21342','0','Akama SAY_BROKEN_FREE_0'),
('23191','1','0','The Betrayer no longer holds sway over us.  His dark magic over the Ashtongue soul has been destroyed!','14','0','100','0','0','0','21343','0','Akama SAY_BROKEN_FREE_1'),
('23191','2','0','Come out from the shadows!  I\'ve returned to lead you against our true enemy!  Shed your chains and raise your weapons against your Illidari masters!','14','0','100','0','0','0','21344','0','Akama SAY_BROKEN_FREE_2'),
('23191','3','0','I will not last much longer!','14','0','100','0','0','11385','21784','0','Akama SAY_LOW_HEALTH'),
('23191','4','0','No! Not yet!','14','0','100','0','0','11386','21785','0','Akama SAY_DEAD');
