-- Creature Gossip_menu_option Update from sniff
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9511,9590,9592,9780,10220) AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9821,9784,9785) AND `id`=1;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9511,0,0, 'I am ready to be teleported to Dalaran.',1,1,0,0,0,0, ''),
(9590,0,0, 'Why would I want to ride a shredder?',1,1,9592,0,0,0, ''),
(9592,0,0, 'Where can I get a Refurbished Shredder Key?',1,1,9591,0,0,0, ''),
(9780,0,0, 'I am ready to be teleported to Dalaran.',1,1,0,0,0,0, ''),
(9821,1,1, 'I''m looking for a lost companion.',3,128,0,0,0,0, ''),
(9784,1,0, 'I wish to travel to Light''s Breach.',1,1,0,0,0,0, ''),
(9785,1,0, 'I wish to travel to Light''s Breach.',1,1,0,0,0,0, ''),
(10220,0,0, 'I am ready to return to the realm of the living.',1,1,0,0,0,0, '');

-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9431 AND `text_id`=12694;
DELETE FROM `gossip_menu` WHERE `entry`=9590 AND `text_id`=12943;
DELETE FROM `gossip_menu` WHERE `entry`=9591 AND `text_id`=12945;
DELETE FROM `gossip_menu` WHERE `entry`=9592 AND `text_id`=12944;
DELETE FROM `gossip_menu` WHERE `entry`=10220 AND `text_id`=14208;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9431,12694),
(9590,12943),
(9591,12945),
(9592,12944),
(10220,14208);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9431 WHERE `entry`=26814; -- Harrison Jones
UPDATE `creature_template` SET `gossip_menu_id`=10220, `AIName`='SmartAI' WHERE `entry`=26924; -- Gan'jo
UPDATE `creature_template` SET `gossip_menu_id`=9590 WHERE `entry`=27565; -- Gurtor
UPDATE `creature_template` SET `gossip_menu_id`=9780 WHERE `entry` IN (29155,29159,29160,29162); -- Magistrix Kaelana, Magister Varenthas, Magistrix Phaelista, Magister Tyr'ganal
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=29250; -- Tim Street

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9511,9513,9780,10220) AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` IN (9785,9784) AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10220,0,0,9,12137,0,0,0,'','Gan''jo - Show gossip option only if player has taken quest 12137'),
(15,9513,0,0,28,12791,0,0,0,'','Show gossip option only if player has complete quest 12791'),
(15,9511,0,0,28,12794,0,0,0,'','Show gossip option only if player has complete quest 12794'),
(15,9780,0,0,28,12791,0,0,0,'','Show gossip option only if player has complete quest 12791'),
(15,9780,0,1,28,12794,0,0,0,'','Show gossip option only if player has complete quest 12794'),
(15,9780,0,2,28,12796,0,0,0,'','Show gossip option only if player has complete quest 12796'),
(15,9784,1,0,28,12770,0,0,0,'','Samuel Clearbook - Show gossip option only if player has complete quest 12770'),
(15,9785,1,0,28,12763,0,0,0,'','Makki Wintergale - Show gossip option only if player has complete quest 12763');

-- SmartAIs
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry` IN (23729,26471,26673,27158,29155,29158,29159,29160,29161,29162,29169);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26853,26876) AND `source_type`=0 AND `id` IN (3,4); -- these npcs already had a SmartAI assigned so deleting the new ids only
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23729,26471,26673,26924,27158,29155,29158,29159,29160,29161,29162,29169) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23729,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Baron Ulrik von Stromhearth - On gossip select - Spellcast'),
(23729,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Baron Ulrik von Stromhearth - On gossip select - Close gossip'),
(26471,0,0,1,62,0,100,0,9513,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Archmage Aethas Sunreaver - On gossip select - Spellcast'),
(26471,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Archmage Aethas Sunreaver - On gossip select - Close gossip'),
(26673,0,0,1,62,0,100,0,9511,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Archmage Modera - On gossip select - Spellcast'),
(26673,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Image of Archmage Modera - On gossip select - Close gossip'),
(26853,0,3,4,62,0,100,0,9785,1,0,0,11,53288,0,0,0,0,0,7,0,0,0,0,0,0,0,'Makki Wintergale - On gossip select - Close gossip'),
(26853,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Makki Wintergale - On gossip select - Close gossip'),
(26876,0,3,4,62,0,100,0,9784,1,0,0,11,53311,0,0,0,0,0,7,0,0,0,0,0,0,0,'Samuel Clearbook - On gossip select - Close gossip'),
(26876,0,4,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Samuel Clearbook - On gossip select - Close gossip'),
(26924,0,0,1,62,0,100,0,10220,0,0,0,11,61613,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gan''jo - On gossip select - Close gossip'),
(26924,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Gan''jo - On gossip select - Close gossip'),
(27158,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Vas the Unstable - On gossip select - Spellcast'),
(27158,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Vas the Unstable - On gossip select - Close gossip'),
(29155,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magistrix Kaelana - On gossip select - Spellcast'),
(29155,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magistrix Kaelana - On gossip select - Close gossip'),
(29158,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magister Dath''omere - On gossip select - Spellcast'),
(29158,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magister Dath''omere - On gossip select - Close gossip'),
(29159,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magister Varenthas - On gossip select - Spellcast'),
(29159,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magister Varenthas - On gossip select - Close gossip'),
(29160,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magistrix Phaelista - On gossip select - Spellcast'),
(29160,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magistrix Phaelista - On gossip select - Close gossip'),
(29161,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magistrix Haelenai - On gossip select - Spellcast'),
(29161,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magistrix Haelenai - On gossip select - Close gossip'),
(29162,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magister Tyr''ganal - On gossip select - Spellcast'),
(29162,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magister Tyr''ganal - On gossip select - Close gossip'),
(29169,0,0,1,62,0,100,0,9780,0,0,0,11,30719,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magister Teronus III - On gossip select - Spellcast'),
(29169,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Magister Teronus III - On gossip select - Close gossip');

DELETE FROM `spell_target_position` WHERE `id`=30719;
INSERT INTO `spell_target_position` (`id`,`target_map`,`target_position_x`,`target_position_y`,`target_position_z`,`target_orientation`) VALUES
(30719,571,5807.83,587.96,660.939,1.663); -- Teleport to Dalaran

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (53288,53311);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(53288,53289,1,'Flight - Onequah to Light''s Breach trigger Flight - Onequah to Light''s Breach'),
(53311,53310,1,'Flight - Westfall to Light''s Breach trigger Flight - Westfall to Light''s Breach');
