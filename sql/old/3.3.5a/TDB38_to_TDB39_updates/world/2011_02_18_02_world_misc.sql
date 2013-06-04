-- Jeeves should be a vendor and a banker (to Engineers).
SET @Jeeves = 35642;
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`npcflag`=`npcflag`|4225|131072,`unit_flags`=`unit_flags`|768,`gossip_menu_id`=10667,`AIName`='' WHERE `entry`=@Jeeves; -- template updates
-- Jeeves gets the (player) faction of its summoner, 35 by default
UPDATE `creature_model_info` SET `bounding_radius`=0.31,`combat_reach`=0,`gender`=2 WHERE `modelid`=30076; -- addon data
DELETE FROM `creature_template_addon` WHERE `entry`=@Jeeves;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@Jeeves,0,33554432,1,0, '68054 0'); -- Aura: Pressing Engagement, bytes1: hover mode

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=10667 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,10667,0,0,7,202,350,0,0, '', 'Jeeves: Bank requires Engineering 350');

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10667 AND `id` IN (0,1);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(10667,0,6,'I would like to check my deposit box.',9,131072), -- banker
(10667,1,1,'Let me browse your goods.',3,128); -- vendor

DELETE FROM `npc_vendor` WHERE `entry`=@Jeeves;
INSERT INTO `npc_vendor` (`entry`,`slot`,`item`,`maxcount`,`incrtime`,`ExtendedCost`) VALUES
(@Jeeves,1,41584,0,0,0), -- Frostbite Bullets
(@Jeeves,2,41586,0,0,0), -- Terrorshaft Arrow
(@Jeeves,3,44605,0,0,0), -- Wild Spineleaf
(@Jeeves,4,44614,0,0,0), -- Starleaf Seed
(@Jeeves,5,44615,0,0,0), -- Devout Candle
(@Jeeves,6,16583,0,0,0), -- Demonic Figurine
(@Jeeves,7,21177,0,0,0), -- Symbol of Kings
(@Jeeves,8,17020,0,0,0), -- Arcane Powder
(@Jeeves,9,37201,0,0,0), -- Corpse Dust
(@Jeeves,10,5565,0,0,0), -- Infernal Stone
(@Jeeves,11,17032,0,0,0), -- Rune of Portals
(@Jeeves,12,17030,0,0,0), -- Ankh
(@Jeeves,13,17033,0,0,0), -- Symbol of Divinity
(@Jeeves,14,17031,0,0,0); -- Rune of Teleportation

DELETE FROM `creature_ai_scripts` WHERE `id`=3564201; -- remove unneed EventAI script
