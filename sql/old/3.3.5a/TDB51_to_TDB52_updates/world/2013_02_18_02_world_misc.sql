-- Creature Gossip_menu_option Update from sniff
UPDATE `gossip_menu_option` SET `menu_id`=9528 WHERE `menu_id`=21250;
UPDATE `gossip_menu_option` SET `action_menu_id`=9527 WHERE `action_menu_id`=50423;
UPDATE `gossip_menu_option` SET `action_menu_id`=9521 WHERE `action_menu_id`=50424;
UPDATE `gossip_menu_option` SET `action_menu_id`=9526 WHERE `action_menu_id`=50425;
UPDATE `gossip_menu_option` SET `action_menu_id`=9525 WHERE `action_menu_id`=50426;
UPDATE `gossip_menu_option` SET `action_menu_id`=9681 WHERE `menu_id`=9680;
UPDATE `gossip_menu_option` SET `action_menu_id`=9696 WHERE `menu_id`=9695;
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (9302,9303,9304,9305,9422,9461,9462,9474,9501,9532,9536,9568,9586,9594,9595,9610,9611,9612,9653,9696) AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9302,0,0, 'Worry no more, taunka. The Horde will save and protect you and your people, but first you must swear allegiance to the Warchief by taking the blood oath of the Horde.',1,1,9305,0,0,0, ''),
(9303,0,0, 'For the Horde!\r\n\r\nArm yourself from the crates that surround us and report to Agmar''s Hammer, east of here. Your first trial as a member of the Horde is to survive the journey.\r\n\r\nLok''tar ogar!',1,1,0,0,0,0, ''),
(9304,0,0, 'Then repeat after me: "Lok''tar ogar! Victory or death - it is these words that bind me to the Horde. For they are the most sacred and fundamental of truths to any warrior of the Horde.\r\n\r\nI give my flesh and blood freely to the Warchief. I am the instrument of my Warchief''s desire. I am a weapon of my Warchief''s command.\r\n\r\nFrom this moment until the end of days I live and die - For the Horde!"',1,1,9303,0,0,0, ''),
(9305,0,0, 'Yes, taunka. Retribution is a given right of all members of the Horde.',1,1,9304,0,0,0, ''),
(9422,0,0, 'I seem to have misplaced your Shredder Control Device... might you have another?',1,1,0,0,0,0, ''),
(9461,0,0, 'Greetings High Chief. Would you do me the honor of accepting my invitation to join the Horde as an official member and leader of the Taunka?',1,1,9462,0,0,0, ''),
(9462,0,0, 'It is you who honor me, High Chief. Please read from this scroll. It is the oath of allegiance.',1,1,0,0,0,0, ''),
(9474,0,1, 'Let me browse your goods.',3,128,0,0,0,0, ''),
(9501,0,0, 'Agent Skully, I need you to use the banshee''s magic mirror on me again!',1,1,9538,0,0,0, ''),
(9532,0,0, 'Your eminence, may I have a word in private?',1,1,9536,0,0,0, ''),
(9536,0,0, 'I am ready, your grace. <kiss the ring>',1,1,9535,0,0,0, ''),
(9568,0,0, 'We need to get into the fight. Are you ready?',1,1,9569,0,0,0, ''),
(9586,0,0, 'Why have I been sent back to this particular place and time?',1,1,9594,0,0,0, ''),
(9594,0,0, 'What was this decision?',1,1,9595,0,0,0, ''),
(9595,0,0, 'So how does the Infinite Dragonflight plan to interfere?',1,1,9596,0,0,0, ''),
(9610,0,0, 'What do you think they''re up to?',1,1,9611,0,0,0, ''),
(9611,0,0, 'You want me to do what?',1,1,9612,0,0,0, ''),
(9612,0,0, 'Very well, Chromie.',1,1,9613,0,0,0, ''),
(9653,0,0, 'Yes, my Prince. We are ready.',1,1,0,0,0,0, ''),
(9696,0,0, 'For Lordaeron!',1,1,0,0,0,0, '');

UPDATE `gossip_menu` SET `entry`=9350 WHERE `entry`=21238;
UPDATE `gossip_menu` SET `entry`=9136 WHERE `entry`=21243;
UPDATE `gossip_menu` SET `entry`=9151 WHERE `entry`=21244;
UPDATE `gossip_menu` SET `entry`=9474 WHERE `entry`=21245;
UPDATE `gossip_menu` SET `entry`=9528 WHERE `entry`=21250;
UPDATE `gossip_menu` SET `entry`=9527 WHERE `entry`=50423;
UPDATE `gossip_menu` SET `entry`=9521 WHERE `entry`=50424;
UPDATE `gossip_menu` SET `entry`=9526 WHERE `entry`=50425;
UPDATE `gossip_menu` SET `entry`=9525 WHERE `entry`=50426;
-- Gossip Menu insert from sniff
DELETE FROM `gossip_menu` WHERE `entry`=9302 AND `text_id`=12611;
DELETE FROM `gossip_menu` WHERE `entry`=9303 AND `text_id`=12620;
DELETE FROM `gossip_menu` WHERE `entry`=9304 AND `text_id`=12619;
DELETE FROM `gossip_menu` WHERE `entry`=9305 AND `text_id`=12618;
DELETE FROM `gossip_menu` WHERE `entry`=9461 AND `text_id`=12721;
DELETE FROM `gossip_menu` WHERE `entry`=9462 AND `text_id`=12722;
DELETE FROM `gossip_menu` WHERE `entry`=9532 AND `text_id`=12846;
DELETE FROM `gossip_menu` WHERE `entry`=9535 AND `text_id`=12849;
DELETE FROM `gossip_menu` WHERE `entry`=9536 AND `text_id`=12848;
DELETE FROM `gossip_menu` WHERE `entry`=9538 AND `text_id`=12851;
DELETE FROM `gossip_menu` WHERE `entry`=9568 AND `text_id`=12899;
DELETE FROM `gossip_menu` WHERE `entry`=9569 AND `text_id`=12900;
DELETE FROM `gossip_menu` WHERE `entry`=9586 AND `text_id`=13471;
DELETE FROM `gossip_menu` WHERE `entry`=9653 AND `text_id`=13076;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9302,12611),
(9303,12620),
(9304,12619),
(9305,12618),
(9461,12721),
(9462,12722),
(9532,12846),
(9535,12849),
(9536,12848),
(9538,12851),
(9568,12899),
(9569,12900),
(9586,13471),
(9653,13076);

-- Creature Gossip_menu_id Update from sniff
UPDATE `creature_template` SET `gossip_menu_id`=9136 WHERE `entry`=25197; -- King Mrgl-Mrgl <D.E.H.T.A.>
UPDATE `creature_template` SET `gossip_menu_id`=9151 WHERE `entry`=25326; -- Overlord Bor'gorok
UPDATE `creature_template` SET `gossip_menu_id`=9474 WHERE `entry`=25736; -- Supply Master Taz'ishi <Poison & Reagents>
UPDATE `creature_template` SET `gossip_menu_id`=9302, `npcflag`=`npcflag`|1, `AIName`='SmartAI' WHERE `entry`=26179; -- Taunka''le Refugee
UPDATE `creature_template` SET `gossip_menu_id`=9302, `npcflag`=`npcflag`|1, `AIName`='SmartAI' WHERE `entry`=26184; -- Taunka''le Refugee
UPDATE `creature_template` SET `gossip_menu_id`=9350 WHERE `entry`=26538; -- Nargo Screwbore <Durotar Zeppelin Master>
UPDATE `creature_template` SET `gossip_menu_id`=9461 WHERE `entry`=26810; -- Roanauk Icemist
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=27056; -- Sentinel Sweetspring <Stable Master>
UPDATE `creature_template` SET `gossip_menu_id`=9532 WHERE `entry`=27245; -- High Abbot Landgren
UPDATE `creature_template` SET `gossip_menu_id`=9528 WHERE `entry`=27425; -- Darrok
UPDATE `creature_template` SET `gossip_menu_id`=9610 WHERE `entry`=27915; -- Chromie
UPDATE `creature_template` SET `gossip_menu_id`=9656 WHERE `entry`=28126; -- Don Carlos

DELETE FROM `creature_text` WHERE `entry` IN (26179,26184);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26179,0,0,'Victory or death! For the Horde!',14,1,100,15,0,0,'Taunka''le Refugee'),
(26184,0,0,'Victory or death! For the Horde!',14,1,100,15,0,0,'Taunka''le Refugee');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9568 AND `SourceEntry`=12899;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=9586 AND `SourceEntry`=13471;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9302 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9422 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9461 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9501 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9568 AND `SourceEntry`=0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=9586 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9568,12899,0,0,9,0,12372,0,0,0,0,'','Wyrmrest Defender - Show different gossip if player has taken quest Defending Wyrmrest Temple'),
(14,9586,13471,0,0,2,0,37888,1,0,0,0,'','Chromie - Show different gossip if player has item Arcane Disruptor'),
(15,9302,0,0,0,9,0,11983,0,0,0,0,'','Taunka''le Refugee - Show gossip option only if player has taken quest Blood Oath of the Horde'),
(15,9422,0,0,0,9,0,12050,0,0,0,0,'','Xink - Show gossip option only if player has taken quest Lumber Hack'),
(15,9422,0,0,0,2,0,36734,1,0,1,0,'','Xink - Show gossip option only if player has no item Xink''s Shredder Control Device'),
(15,9422,0,0,1,9,0,12052,0,0,0,0,'','Xink - Show gossip option only if player has taken quest Harp on This!'),
(15,9422,0,0,1,2,0,36734,1,0,1,0,'','Xink - Show gossip option only if player has no item Xink''s Shredder Control Device'),
(15,9461,0,0,0,9,0,12140,0,0,0,0,'','Roanauk Icemist - Show gossip option only if player has taken quest All Hail Roanauk!'),
(15,9501,0,0,0,9,0,12274,0,0,0,0,'','Agent Skully - Show gossip option only if player has taken quest A Fall From Grace'),
(15,9501,0,0,0,1,0,48761,0,0,1,0,'','Agent Skully - Show gossip option only if player has no aura Scarlet Raven Priest Image'),
(15,9501,0,0,0,1,0,48763,0,0,1,0,'','Agent Skully - Show gossip option only if player has no aura Scarlet Raven Priest Image'),
(15,9568,0,0,0,9,0,12372,0,0,0,0,'','Wyrmrest Defender - Show gossip option only if player has taken quest Defending Wyrmrest Temple'),
(15,9586,0,0,0,2,0,37888,1,0,1,0,'','Chromie - Show gossip option only if player has no item Arcane Disruptor');

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (26660,27350);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26179,26184,26660,27350) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26179*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26179,0,0,1,62,0,100,0,9303,0,0,0,11,47029,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Spellcast Taunka Sworn In'),
(26179,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Close gossip'),
(26179,0,2,3,61,0,100,0,0,0,0,0,33,26179,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Quest credit'),
(26179,0,3,4,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Remove npcflag gossip'),
(26179,0,4,5,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188252,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26179,0,5,6,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188253,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26179,0,6,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188254,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26179,0,7,0,34,0,100,0,0,1,0,0,80,26179*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On movement inform - Run script'),
(26179,0,8,9,34,0,100,0,0,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On movement inform - Despawn'),
(26179,0,9,0,61,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Add npcflag gossip'),
(26184,0,0,1,62,0,100,0,9303,0,0,0,11,47029,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Spellcast Taunka Sworn In'),
(26184,0,1,2,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Close gossip'),
(26184,0,2,3,61,0,100,0,0,0,0,0,33,26179,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Quest credit'),
(26184,0,3,4,61,0,100,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Remove npcflag gossip'),
(26184,0,4,5,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188252,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26184,0,5,6,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188253,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26184,0,6,0,61,0,100,0,0,0,0,0,69,1,0,0,0,0,0,20,188254,20,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Move to Recovered Horde Armaments'),
(26184,0,7,0,34,0,100,0,0,1,0,0,80,26179*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On movement inform - Run script'),
(26184,0,8,9,34,0,100,0,0,2,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On movement inform - Despawn'),
(26184,0,9,0,61,0,100,0,0,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee - On gossip option select - Add npcflag gossip'),
(26660,0,0,1,62,0,100,0,9422,0,0,0,11,52872,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Xink - On gossip option select - Spellcast Forceitem Xink''s Shredder'),
(26660,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Xink - On gossip option select - Close gossip'),
(27350,0,0,0,62,0,100,0,9501,0,0,0,11,48762,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Agent Skully - On gossip option select - Spellcast A Fall from Grace: Scarlet Raven Priest Image - Master'),

(26179*100,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,20,188252,20,0,0,0,0,0, 'Taunka''le Refugee script - Turn to Recovered Horde Armaments'),
(26179*100,9,1,0,0,0,100,0,1100,1100,0,0,5,381,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Play emote'),
(26179*100,9,2,0,0,0,100,0,2500,2500,0,0,5,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Cancel emote'),
(26179*100,9,3,0,0,0,100,0,0,0,0,0,11,47024,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Spellcast Taunka Transform'),
(26179*100,9,4,0,0,0,100,0,2200,2200,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Say line'),
(26179*100,9,5,0,0,0,100,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Taunka''le Refugee script - Set run'),
(26179*100,9,6,0,0,0,100,0,4700,4700,0,0,69,2,0,0,0,0,0,8,0,0,0,3680.874,2875.829,91.52616,0, 'Taunka''le Refugee script - Move to position');
