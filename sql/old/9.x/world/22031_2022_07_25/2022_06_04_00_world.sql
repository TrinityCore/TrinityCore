SET @OGUID := 239543;

UPDATE `creature` SET `zoneId`=5736, `areaId`=5834, `VerifiedBuild`=42010 WHERE `guid` IN (450133, 450140, 450155, 450136, 450263, 450141, 450120, 450151, 450220, 450266, 450267, 450214, 450189, 450192, 450207, 450213, 450197, 450235, 450244, 450230, 450243, 450239, 450236, 450231, 450221, 450196, 450187, 450215, 450228, 450092, 450104, 450108, 450114, 450115, 450118, 450119, 450121, 450124, 450127, 450139, 450145, 450148, 450150, 450154, 450162, 450169, 450179, 450181, 450183, 450186, 450195);
UPDATE `creature` SET `spawntimesecs` =60, `VerifiedBuild`=42010 WHERE (`id` IN (65470, 65471, 54586, 54587) AND `map` =860);
UPDATE `creature_template` SET `VerifiedBuild`=42010 WHERE `entry` IN (53704, 57132, 54943, 53714, 57414, 56730, 54130, 54131, 54133, 54134, 65094, 56739, 61809, 304, 305, 57164, 61411, 56479, 60183, 54567, 54568, 64439, 64440, 59649, 54855, 57873, 54586, 54587, 57748, 65011, 57752, 68986, 57753, 57205, 57754, 57619, 58169, 54611, 57769, 60244, 60245, 60248, 60253, 53273, 65469, 57797, 14505, 65058, 65470, 65471, 65060, 54786, 65061, 65063, 66298, 65065, 64929, 53565, 53566);

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry` IN (54608, 53566); -- Master Shang Xi
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=61801; -- Amberleaf Troublemaker
UPDATE `creature_template` SET `gossip_menu_id`=13037, `minlevel`=20, `maxlevel`=20 WHERE `entry`=59642; -- Aysa Cloudsinger
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry` IN (54785, 54855); -- Min Dimwind
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry` IN (57132, 65472); -- Wu-Song Villager

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57617; -- Lee Sunspark
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=20, `maxlevel`=20 WHERE `entry`=54568; -- Ji Firepaw
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57164; -- Fe-Feng Leaper
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=56739; -- Hozen Hanging Bunny
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry` IN (57205, 54131); -- Fe-Feng Hozen

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `BaseAttackTime`=667 WHERE `entry`=56730; -- Fe-Feng Brewthief
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54567; -- Aysa Cloudsinger
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=59649; -- Tushui Monk
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54943; -- Merchant Lorvo
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry` IN (57797, 53704); -- Corsac Fox

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54611; -- Jaomin Ro
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=60183; -- Trainee Nim
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=60244; -- Trainee Guang
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=64929; -- Lamplighter Deng
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65471; -- Tushui Trainee

UPDATE `creature_template` SET `unit_flags` =32768 WHERE `entry` IN (54587, 65471, 65470, 54586);

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54587; -- Tushui Trainee
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=61411; -- Instructor Zhi
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54586; -- Huojin Trainee
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65470; -- Huojin Trainee

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54130; -- Amberleaf Scamp
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57753; -- Ironfist Zhou
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57752; -- Quiet Lam
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=20, `maxlevel`=20 WHERE `entry`=57754; -- Instructor Mossthorn

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry` IN (53565, 65469); -- Aspiring Trainee
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57748; -- Instructor Qun
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `unit_flags3`=8388608 WHERE `entry`=57873; -- Training Target
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `unit_flags3`=8388624 WHERE `entry`=53714; -- Training Target

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57769; -- Shen-zin Su
UPDATE `creature_template` SET `type_flags`=1611661316 WHERE `entry`=57769;
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35 WHERE `entry`=66298; -- Green Dragon Turtle
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=20, `maxlevel`=20 WHERE `entry`=57619; -- Cheng Dawnscrive
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=20, `maxlevel`=20 WHERE `entry`=54786; -- Master Shang Xi

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=68986; -- Li the Tamer
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57414; -- Temple Guard
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65094; -- Priestess of the Dawn
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=56479; -- Legacy of Liu Lang

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=55022; -- Steam Fiend
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57709; -- Nourished Yak
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57712; -- Delivery Cart Tender
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57710; -- Delivery Cart
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57621; -- Teamaster Ren

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=55020; -- Old Man Liang
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `unit_flags`=67141632 WHERE `entry`=55292; -- Fang-she
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `HoverHeight`=1 WHERE `entry`=54976; -- Barbed Ray
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `dynamicflags`=0 WHERE `entry`=60411; -- Water Pincer
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=60454; -- Vision of Shu
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=60457; -- Vision of Young Liang

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54975; -- Aysa Cloudsinger
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65467; -- Excited Onlooker
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=55021; -- Jojo Ironbrow
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=56394; -- Mesmerized Child
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `npcflag`=4305 WHERE `entry`=57620; -- Whittler Dewei

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57626; -- Exit Pole
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry` IN (55083, 54993, 57431); -- Balance Pole
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=56869; -- Balance Pole Landing Bunny
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `faction`=2263, `unit_flags`=32768 WHERE `entry` IN (65468, 55019); -- Tushui Monk
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=55015; -- Whitefeather Crane

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=55123; -- Cursed Pool Transform Controller
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65049; -- Er
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65035; -- Summer Lily
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65055; -- Hanshi One-Eye
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=20, `maxlevel`=20 WHERE `entry`=65046; -- Lao Ma Liang

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65057; -- Fan Slowplow
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65087; -- Trader Feng
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65075; -- Hyacinth
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65056; -- Longbeard the Liar
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65086; -- Da Na

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65085; -- Jin
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65248; -- Kaydee Threesong
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65070; -- Gokan Sharphoe
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65053; -- Bai Hua
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65050; -- San

UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=20, `maxlevel`=20 WHERE `entry`=65043; -- Elder Oakpaw
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65067; -- Steepmaster Tira
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=57622; -- Lien-Hua Thunderhammer
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65064; -- Ki-Ro the Contemplative
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65059; -- Jing Stoutgut

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65039; -- Eng Dirtplow
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65052; -- Shi
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65047; -- Yi
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65062; -- Shao-Li Ironbelly
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65084; -- Crimson Butterfly

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65044; -- Gan Darkcask
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65045; -- Gao Longwagon
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65093; -- Seeress Weng Wu
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65088; -- Groundskeeper Shen
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65146; -- Zach Chow

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65147; -- Azunyan
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=65089; -- Old Yang
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=56622; -- Brazier
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry` IN (54787, 57779); -- Huo
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54734; -- Master Li Fei

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54902; -- Brazier Bunny, Blue
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54900; -- Brazier Bunny, Red
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54901; -- Brazier Bunny, Purple
UPDATE `creature_template` SET `minlevel`=35, `maxlevel`=35 WHERE `entry`=57625; -- Generic Sparkle Bunny (CSA)
UPDATE `creature_template` SET `gossip_menu_id`=13050, `minlevel`=20, `maxlevel`=20 WHERE `entry`=54135; -- Master Li Fei

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54609; -- Master Shang Xi
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=54635; -- Shrine of Air
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=60176; -- Huojin Monk
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=59626; -- Flame Spout
UPDATE `creature_template` SET `gossip_menu_id`=13038 WHERE `entry`=54568; -- Ji Firepaw

UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=60245; -- Brewer Zhen
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=60253; -- Brewer Lin
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20 WHERE `entry`=60248; -- Chia-hui Autumnleaf
UPDATE `creature_template` SET `gossip_menu_id`=13346 WHERE `entry`=57754; -- Instructor Mossthorn
UPDATE `creature_template` SET `gossip_menu_id`=14616 WHERE `entry`=64929; -- Lamplighter Deng

UPDATE `creature_template` SET `gossip_menu_id`=14674 WHERE `entry`=57619; -- Cheng Dawnscrive
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=68986; -- Li the Tamer
UPDATE `creature_template` SET `type_flags`=1611661328 WHERE `entry`=56479;

DELETE FROM `creature_addon` WHERE `guid` IN (450220, 450266, 450267);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450220, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 49414 115865'), -- 53566 - 108900 - 108900, 49414 - 49414, 115865 - 115865
(450266, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 60921 114600 126160'), -- 53566 - 108900 - 108900, 60921 - 60921, 114600 - 114600, 126160 - 126160
(450267, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 82343 126160'); -- 53566 - 108900 - 108900, 82343 - 82343, 126160 - 126160

UPDATE `creature_template_addon` SET `auras`='108959' WHERE `entry`=54611; -- 54611 (Jaomin Ro) - Dizzy

DELETE FROM `creature_template_addon` WHERE `entry` IN (53566, 54786, 53565, 54608, 59642, 57164, 57205, 54131, 56730, 54567, 54943, 53704, 57797, 64929, 54130, 57769, 68986, 56479, 57709 /*57709 (Nourished Yak) - Generic Quest Invisibility 9, Generic Quest Invisibility Detection 9*/, 57710 /*57710 (Delivery Cart) - Ox Cart Hay Bales, Generic Quest Invisibility Detection 9, Generic Quest Invisibility 9*/, 57621 /*57621 (Teamaster Ren)*/, 55020 /*55020 (Old Man Liang) - Generic Quest Invisibility 5*/, 60411 /*60411 (Water Pincer) - Move Slide*/, 54975 /*54975 (Aysa Cloudsinger) - Generic Quest Invisibility 1*/, 65467 /*65467 (Excited Onlooker) - Generic Quest Invisibility 8*/, 55021 /*55021 (Jojo Ironbrow) - Generic Quest Invisibility 4*/, 56394 /*56394 (Mesmerized Child) - Generic Quest Invisibility 8*/, 57626 /*57626 (Exit Pole) - Balance Pole Visual, Short*/, 55083 /*55083 (Balance Pole) - Balance Pole Visual*/, 65468 /*65468 (Tushui Monk) - Ride Vehicle*/, 55019 /*55019 (Tushui Monk) - Ride Vehicle*/, 54993 /*54993 (Balance Pole) - Balance Pole Visual*/, 55123 /*55123 (Cursed Pool Transform Controller)*/, 57431 /*57431 (Balance Pole) - Balance Pole Visual*/, 65055 /*65055 (Hanshi One-Eye)*/, 65075 /*65075 (Hyacinth)*/, 65248 /*65248 (Kaydee Threesong) - Looping Sit Anim Kit (Special, Non-Meditating)*/, 65070 /*65070 (Gokan Sharphoe) - Looping Sit Anim Kit (Special, Non-Meditating)*/, 65043 /*65043 (Elder Oakpaw)*/, 65064 /*65064 (Ki-Ro the Contemplative) - Looping Sit Anim Kit (Special, Non-Meditating)*/, 65059 /*65059 (Jing Stoutgut) - Looping Sit Anim Kit (Special, Non-Meditating)*/, 65062 /*65062 (Shao-Li Ironbelly)*/, 65146 /*65146 (Zach Chow)*/, 65147 /*65147 (Azunyan)*/, 65089 /*65089 (Old Yang)*/, 65094 /*65094 (Priestess of the Dawn)*/, 56622 /*56622 (Brazier) - Generic Quest Invisibility 15*/, 54787 /*54787 (Huo) - Generic Quest Invisibility 11*/, 57779 /*57779 (Huo)*/, 54734 /*54734 (Master Li Fei) - Ghost Visual (Red)*/, 54902 /*54902 (Brazier Bunny, Blue) - Blessing of the Blue Flame*/, 54900 /*54900 (Brazier Bunny, Red) - Blessing of the Red Flame*/, 54901 /*54901 (Brazier Bunny, Purple) - Blessing of the Purple Flame*/, 57625 /*57625 (Generic Sparkle Bunny (CSA)) - Cosmetic - Loot Sparkles (3.00), Generic Quest Invisibility 19*/, 54135 /*54135 (Master Li Fei) - Ghost Visual, Generic Quest Invisibility 10*/, 54609 /*54609 (Master Shang Xi) - Master Shang Xi's Staff, Generic Quest Invisibility 9, Master Shang Xi's Staff*/, 59626 /*59626 (Flame Spout) - Shrink*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(53566, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 49414 115865'), -- 53566 (Master Shang Xi) - Master Shang Xi's Staff, Generic Quest Invisibility 1, Cosmetic - Sit Chair High (Lower/Upper Body - High/Low Priority) (Anim Kit)
(54786, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 49414 126160'), -- 54786 (Master Shang Xi) - Master Shang Xi's Staff, Generic Quest Invisibility 1, Master Shang Xi's Staff
(53565, 0, 0, 0, 0, 1, 510, 0, 0, 0, 0, ''), -- 53565
(54608, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '85096 126160'), -- 54608 (Master Shang Xi) - Generic Quest Invisibility 7, Master Shang Xi's Staff
(59642, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 59642 (Aysa Cloudsinger)
(57164, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '107747'), -- 57164 (Fe-Feng Leaper) - Stolen Brew
(57205, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 57205 (Fe-Feng Hozen)
(54131, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '46598'), -- 54131 (Fe-Feng Hozen) - Ride Vehicle Hardcoded
(56730, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '109084 107747'), -- 56730 (Fe-Feng Brewthief) - Drunken Boxing, Stolen Brew
(54567, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '80797'), -- 54567 (Aysa Cloudsinger) - Generic Quest Invisibility 5
(54943, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '80797'), -- 54943 (Merchant Lorvo) - Generic Quest Invisibility 5
(53704, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '75533'), -- 53704 (Corsac Fox) - Wily Wits
(57797, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '106562'), -- 57797 (Corsac Fox) - Cosmetic - Sleep Zzz Breakable
(64929, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '126968'), -- 64929 (Lamplighter Deng) - Lamplighter Aura
(54130, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '109138 109139'), -- 54130 (Amberleaf Scamp) - Drunk Keg Carry, Drunk Keg Carry
(57769, 0, 0, 0, 0, 1, 0, 0, 0, 0, 5, '114825'), -- 57769 (Shen-zin Su) - Shen-zin Su's Turtle Head Emerged
(68986, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- 68986 (Li the Tamer)
(56479, 0, 0, 0, 0, 1, 0, 0, 0, 0, 5, ''), -- 56479 (Legacy of Liu Lang)
(57709, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '84886 94570'), -- 57709 (Nourished Yak) - Generic Quest Invisibility 9, Generic Quest Invisibility Detection 9
(57710, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108692 94570 84886'), -- 57710 (Delivery Cart) - Ox Cart Hay Bales, Generic Quest Invisibility Detection 9, Generic Quest Invisibility 9
(57621, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 57621 (Teamaster Ren)
(55020, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '80797'), -- 55020 (Old Man Liang) - Generic Quest Invisibility 5
(60411, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '116552'), -- 60411 (Water Pincer) - Move Slide
(54975, 0, 0, 0, 65537, 1, 0, 0, 0, 0, 0, '49414'), -- 54975 (Aysa Cloudsinger) - Generic Quest Invisibility 1
(65467, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '78718'), -- 65467 (Excited Onlooker) - Generic Quest Invisibility 8
(55021, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '82343'), -- 55021 (Jojo Ironbrow) - Generic Quest Invisibility 4
(56394, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '78718'), -- 56394 (Mesmerized Child) - Generic Quest Invisibility 8
(57626, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '108696'), -- 57626 (Exit Pole) - Balance Pole Visual, Short
(55083, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '102728'), -- 55083 (Balance Pole) - Balance Pole Visual
(65468, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '103030'), -- 65468 (Tushui Monk) - Ride Vehicle
(55019, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '103030'), -- 55019 (Tushui Monk) - Ride Vehicle
(54993, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '102728'), -- 54993 (Balance Pole) - Balance Pole Visual
(55123, 0, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 55123 (Cursed Pool Transform Controller)
(57431, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '102728'), -- 57431 (Balance Pole) - Balance Pole Visual
(65055, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 65055 (Hanshi One-Eye)
(65075, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 65075 (Hyacinth)
(65248, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '110846'), -- 65248 (Kaydee Threesong) - Looping Sit Anim Kit (Special, Non-Meditating)
(65070, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '110846'), -- 65070 (Gokan Sharphoe) - Looping Sit Anim Kit (Special, Non-Meditating)
(65043, 0, 0, 0, 0, 1, 0, 1904, 0, 0, 0, ''), -- 65043 (Elder Oakpaw)
(65064, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '110846'), -- 65064 (Ki-Ro the Contemplative) - Looping Sit Anim Kit (Special, Non-Meditating)
(65059, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '110846'), -- 65059 (Jing Stoutgut) - Looping Sit Anim Kit (Special, Non-Meditating)
(65062, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 65062 (Shao-Li Ironbelly)
(65146, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- 65146 (Zach Chow)
(65147, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 65147 (Azunyan)
(65089, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 65089 (Old Yang)
(65094, 0, 0, 0, 8, 1, 0, 0, 0, 0, 0, ''), -- 65094 (Priestess of the Dawn)
(56622, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 3, '83080'), -- 56622 (Brazier) - Generic Quest Invisibility 15
(54787, 0, 0, 0, 50397184, 1, 0, 0, 0, 0, 0, '83305'), -- 54787 (Huo) - Generic Quest Invisibility 11
(57779, 0, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 57779 (Huo)
(54734, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '30987'), -- 54734 (Master Li Fei) - Ghost Visual (Red)
(54902, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '102509'), -- 54902 (Brazier Bunny, Blue) - Blessing of the Blue Flame
(54900, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '102508'), -- 54900 (Brazier Bunny, Red) - Blessing of the Red Flame
(54901, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '102510'), -- 54901 (Brazier Bunny, Purple) - Blessing of the Purple Flame
(57625, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '92406 84957'), -- 57625 (Generic Sparkle Bunny (CSA)) - Cosmetic - Loot Sparkles (3.00), Generic Quest Invisibility 19
(54135, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '22650 80852'), -- 54135 (Master Li Fei) - Ghost Visual, Generic Quest Invisibility 10
(54609, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 84886 126160'), -- 54609 (Master Shang Xi) - Master Shang Xi's Staff, Generic Quest Invisibility 9, Master Shang Xi's Staff
(59626, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '96112'); -- 59626 (Flame Spout) - Shrink

DELETE FROM `creature_template_model` WHERE (`Idx`=0 AND `CreatureID` IN (54608,54856,59637,61801,59642,59652,54785,56503,57132,57617,57164,54568,65472,56739,57205,54131,56730,54855,54567,59649,54943,57797,57750,54611,64440,54134,60183,60244,64929,65471,53704,54133,54130,54587,61411,65470,54586,57753,57752,53566,65469,57873,57754,57748,53714,53565,57769,68986,66298,65094,64439,57619,57414,56479,54786,65011,65065,65063,65060,65058,61809,58169,53273,28302,14505,305,65061,304)) OR (`Idx`=2 AND `CreatureID` IN (59637,61801,57132,65472,59649,57750,64440,65471,54130,54587,65470,54586,65469,53565,65094,57414)) OR (`Idx`=1 AND `CreatureID` IN (59637,61801,57132,65472,56739,57205,54131,59649,57797,57750,64440,65471,53704,54130,54587,65470,54586,65469,53565,65094,64439,57414,56479)) OR (`Idx`=3 AND `CreatureID` IN (57132,65472,59649,65471,54587,65470,54586,65469,53565,65094,57414));
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(54608, 0, 39574, 1, 1, 42010), -- 54608
(54856, 0, 39675, 1, 1, 42010), -- 54856
(59637, 2, 39801, 1, 1, 42010), -- 59637
(59637, 1, 39804, 1, 1, 42010), -- 59637
(59637, 0, 39803, 1, 1, 42010), -- 59637
(61801, 2, 39801, 1, 1, 42010), -- 61801
(61801, 1, 39804, 1, 1, 42010), -- 61801
(61801, 0, 39803, 1, 1, 42010), -- 61801
(59642, 0, 41667, 1, 1, 42010), -- 59642
(59652, 0, 41667, 1, 1, 42010), -- 59652
(54785, 0, 39674, 1, 1, 42010), -- 54785
(56503, 0, 39674, 1, 1, 42010), -- 56503
(57132, 3, 39672, 1, 1, 42010), -- 57132
(57132, 2, 39757, 1, 1, 42010), -- 57132
(57132, 1, 39756, 1, 1, 42010), -- 57132
(57132, 0, 39671, 1, 1, 42010), -- 57132
(57617, 0, 39759, 1, 1, 42010), -- 57617
(57164, 0, 39478, 1, 1, 42010), -- 57164
(54568, 0, 39637, 1, 1, 42010), -- 54568
(65472, 3, 44066, 1, 1, 42010), -- 65472
(65472, 2, 44068, 1, 1, 42010), -- 65472
(65472, 1, 44067, 1, 1, 42010), -- 65472
(65472, 0, 44065, 1, 1, 42010), -- 65472
(56739, 1, 11686, 1, 1, 42010), -- 56739
(56739, 0, 20570, 1, 0, 42010), -- 56739
(57205, 1, 39481, 1, 1, 42010), -- 57205
(57205, 0, 39479, 1, 1, 42010), -- 57205
(54131, 1, 39481, 1, 1, 42010), -- 54131
(54131, 0, 39479, 1, 1, 42010), -- 54131
(56730, 0, 39480, 1, 1, 42010), -- 56730
(54855, 0, 39674, 1, 1, 42010), -- 54855
(54567, 0, 41667, 1, 1, 42010), -- 54567
(59649, 3, 45873, 1, 1, 42010), -- 59649
(59649, 2, 45872, 1, 1, 42010), -- 59649
(59649, 1, 45875, 1, 1, 42010), -- 59649
(59649, 0, 45874, 1, 1, 42010), -- 59649
(54943, 0, 39644, 1, 1, 42010), -- 54943
(57797, 1, 39806, 1, 1, 42010), -- 57797
(57797, 0, 39807, 1, 1, 42010), -- 57797
(57750, 2, 39796, 1, 1, 42010), -- 57750
(57750, 1, 11686, 1, 0, 42010), -- 57750
(57750, 0, 21955, 1, 0, 42010), -- 57750
(54611, 0, 39755, 1, 1, 42010), -- 54611
(64440, 2, 27677, 1, 0, 42010), -- Softshell Turtle
(64440, 1, 27678, 1, 0, 42010), -- Softshell Turtle
(64440, 0, 27883, 1, 1, 42010), -- Softshell Turtle
(54134, 0, 6295, 1, 1, 42010), -- 54134
(60183, 0, 45862, 1, 1, 42010), -- 60183
(60244, 0, 45863, 1, 1, 42010), -- 60244
(64929, 0, 43682, 1, 1, 42010), -- 64929
(65471, 3, 44072, 1, 1, 42010), -- 65471
(65471, 2, 44071, 1, 1, 42010), -- 65471
(65471, 1, 44070, 1, 1, 42010), -- 65471
(65471, 0, 44069, 1, 1, 42010), -- 65471
(53704, 1, 39806, 1, 1, 42010), -- 53704
(53704, 0, 39807, 1, 1, 42010), -- 53704
(54133, 0, 28998, 1, 1, 42010), -- 54133
(54130, 2, 39803, 1, 1, 42010), -- 54130
(54130, 1, 39804, 1, 1, 42010), -- 54130
(54130, 0, 39801, 1, 1, 42010), -- 54130
(54587, 3, 39899, 1, 1, 42010), -- 54587
(54587, 2, 39898, 1, 1, 42010), -- 54587
(54587, 1, 39896, 1, 1, 42010), -- 54587
(54587, 0, 39895, 1, 1, 42010), -- 54587
(61411, 0, 42028, 1, 1, 42010), -- 61411
(65470, 3, 44081, 1, 1, 42010), -- 65470
(65470, 2, 44080, 1, 1, 42010), -- 65470
(65470, 1, 44079, 1, 1, 42010), -- 65470
(65470, 0, 44078, 1, 1, 42010), -- 65470
(54586, 3, 39905, 1, 1, 42010), -- 54586
(54586, 2, 39904, 1, 1, 42010), -- 54586
(54586, 1, 39903, 1, 1, 42010), -- 54586
(54586, 0, 39902, 1, 1, 42010), -- 54586
(57753, 0, 45925, 1, 1, 42010), -- 57753
(57752, 0, 45926, 1, 1, 42010), -- 57752
(53566, 0, 39574, 1, 1, 42010), -- 53566
(65469, 3, 44077, 1, 1, 42010), -- 65469
(65469, 2, 44076, 1, 1, 42010), -- 65469
(65469, 1, 44075, 1, 1, 42010), -- 65469
(65469, 0, 44074, 1, 1, 42010), -- 65469
(57873, 0, 38459, 1, 1, 42010), -- 57873
(57754, 0, 39795, 1, 1, 42010), -- 57754
(57748, 0, 39892, 1, 1, 42010), -- 57748
(53714, 0, 38459, 1, 1, 42010), -- 53714
(53565, 3, 44073, 1, 1, 42010), -- 53565
(53565, 2, 39890, 1, 1, 42010), -- 53565
(53565, 1, 39888, 1, 1, 42010), -- 53565
(53565, 0, 39887, 1, 1, 42010), -- 53565
(57769, 0, 39798, 1, 1, 42010), -- Shen-zin Su
(68986, 0, 47031, 1, 1, 42010), -- 68986
(66298, 0, 42250, 1, 0, 42010), -- 66298
(65094, 3, 44027, 1, 1, 42010), -- 65094
(65094, 2, 44026, 1, 1, 42010), -- 65094
(65094, 1, 44025, 1, 1, 42010), -- 65094
(65094, 0, 44024, 1, 1, 42010), -- 65094
(64439, 1, 42855, 1, 1, 42010), -- Long-Eared Mink
(64439, 0, 43391, 1, 1, 42010), -- Long-Eared Mink
(57619, 0, 39758, 1, 1, 42010), -- 57619
(57414, 3, 39661, 1, 1, 42010), -- 57414
(57414, 2, 39660, 1, 1, 42010), -- 57414
(57414, 1, 39659, 1, 1, 42010), -- 57414
(57414, 0, 39658, 1, 1, 42010), -- 57414
(56479, 1, 34260, 1, 0, 42010), -- 56479
(56479, 0, 39406, 1, 1, 42010), -- 56479
(54786, 0, 39574, 1, 1, 42010), -- 54786
(65011, 0, 43708, 1, 0, 42010), -- 65011
(65065, 0, 43721, 1, 0, 42010), -- 65065
(65063, 0, 43720, 1, 0, 42010), -- 65063
(65060, 0, 43718, 1, 0, 42010), -- 65060
(65058, 0, 43717, 1, 0, 42010), -- 65058
(61809, 0, 42250, 1, 0, 42010), -- 61809
(58169, 0, 40029, 1, 0, 42010), -- 58169
(53273, 0, 38260, 1, 0, 42010), -- 53273
(28302, 0, 25280, 1, 1, 42010), -- 28302
(14505, 0, 14554, 1, 1, 42010), -- Dreadsteed
(305, 0, 2410, 1, 1, 42010), -- White Stallion
(65061, 0, 43719, 1, 0, 42010), -- 65061
(304, 0, 2346, 1, 1, 42010); -- Felsteed

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=54130 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(54130, 0, 72071, 42010); -- 54130

UPDATE `creature_equip_template` SET `VerifiedBuild`=42010 WHERE (`ID`=1 AND `CreatureID` IN (57132,65472,57617,57205,54130));

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (54608,61801,59642,54785,57132,57617,65472,54568,57164,56739,57205,54131,56730,54855,54567,59649,54943,57797,54611,54134,64440,60183,60244,64929,65471,54587,53704,61411,54133,54586,65470,54130,57753,57752,57754,53565,57748,65469,53566,57873,53714,57769,57619,54786,68986,57414,64439,65094,56479,55022,57709,57712,57710,57621,55020,55292,54976,60411,60454,60457,54975,65467,55021,56394,57620,57626,55083,56869,65468,55019,55015,54993,55123,57431,60259,60260,65049,65035,65055,65046,65057,65087,65075,65056,65086,65085,65248,65070,65053,65050,65043,65067,57622,65064,65059,65039,65052,65047,65062,65084,65044,65045,65093,65088,65146,65147,65089,56622,54787,57779,54734,54902,54900,54901,57625,54135,54609,54635,60176,59626,60245,60253,60248));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(54608, 0, 0, 0, 80, 42010),
(61801, 0, 0, 0, 80, 42010),
(59642, 0, 0, 0, 80, 42010),
(54785, 0, 0, 0, 80, 42010),
(57132, 0, 0, 0, 80, 42010),
(57617, 0, 0, 0, 80, 42010),
(65472, 0, 0, 0, 80, 42010),
(54568, 0, 0, 0, 80, 42010),
(57164, 0, 0, 0, 80, 42010),
(56739, 0, 0, 0, 80, 42010),
(57205, 0, 0, 0, 80, 42010),
(54131, 0, 0, 0, 80, 42010),
(56730, 0, 0, 0, 80, 42010),
(54855, 0, 0, 0, 80, 42010),
(54567, 0, 0, 0, 80, 42010),
(59649, 0, 0, 0, 80, 42010),
(54943, 0, 0, 0, 80, 42010),
(57797, 0, 0, 0, 80, 42010),
(54611, 0, 0, 0, 80, 42010),
(54134, 0, 0, 0, 81, 42010),
(64440, 0, 0, 0, 81, 42010),
(60183, 0, 0, 0, 80, 42010),
(60244, 0, 0, 0, 80, 42010),
(64929, 0, 0, 0, 80, 42010),
(65471, 0, 0, 0, 80, 42010),
(54587, 0, 0, 0, 80, 42010),
(53704, 0, 0, 0, 80, 42010),
(61411, 0, 0, 0, 80, 42010),
(54133, 0, 0, 0, 81, 42010),
(54586, 0, 0, 0, 80, 42010),
(65470, 0, 0, 0, 80, 42010),
(54130, 0, 0, 0, 80, 42010),
(57753, 0, 0, 0, 80, 42010),
(57752, 0, 0, 0, 80, 42010),
(57754, 0, 0, 0, 80, 42010),
(53565, 0, 0, 0, 80, 42010),
(57748, 0, 0, 0, 80, 42010),
(65469, 0, 0, 0, 80, 42010),
(53566, 0, 0, 0, 80, 42010),
(57873, 0, 0, 0, 80, 42010),
(53714, 0, 0, 0, 80, 42010),
(57769, 0, 0, 0, 80, 42010),
(57619, 0, 0, 0, 80, 42010),
(54786, 0, 0, 0, 80, 42010),
(68986, 0, 0, 0, 80, 42010),
(57414, 0, 0, 0, 80, 42010),
(64439, 0, 0, 0, 81, 42010),
(65094, 0, 0, 0, 80, 42010),
(56479, 0, 0, 0, 80, 42010),
(55022, 0, 0, 0, 80, 42010),
(57709, 0, 0, 0, 80, 42010),
(57712, 0, 0, 0, 80, 42010),
(57710, 0, 0, 0, 80, 42010),
(57621, 0, 0, 0, 80, 42010),
(55020, 0, 0, 0, 80, 42010),
(55292, 0, 0, 0, 80, 42010),
(54976, 0, 0, 0, 80, 42010),
(60411, 0, 0, 0, 80, 42010),
(60454, 0, 0, 0, 80, 42010),
(60457, 0, 0, 0, 80, 42010),
(54975, 0, 0, 0, 80, 42010),
(65467, 0, 0, 0, 80, 42010),
(55021, 0, 0, 0, 80, 42010),
(56394, 0, 0, 0, 80, 42010),
(57620, 0, 0, 0, 80, 42010),
(57626, 0, 0, 0, 80, 42010),
(55083, 0, 0, 0, 80, 42010),
(56869, 0, 0, 0, 80, 42010),
(65468, 0, 0, 0, 80, 42010),
(55019, 0, 0, 0, 80, 42010),
(55015, 0, 0, 0, 80, 42010),
(54993, 0, 0, 0, 80, 42010),
(55123, 0, 0, 0, 80, 42010),
(57431, 0, 0, 0, 80, 42010),
(60259, 0, -3, -3, 1723, 42010),
(60260, 0, -3, -3, 1723, 42010),
(65049, 0, 0, 0, 80, 42010),
(65035, 0, 0, 0, 80, 42010),
(65055, 0, 0, 0, 80, 42010),
(65046, 0, 0, 0, 80, 42010),
(65057, 0, 0, 0, 80, 42010),
(65087, 0, 0, 0, 80, 42010),
(65075, 0, 0, 0, 80, 42010),
(65056, 0, 0, 0, 80, 42010),
(65086, 0, 0, 0, 80, 42010),
(65085, 0, 0, 0, 80, 42010),
(65248, 0, 0, 0, 80, 42010),
(65070, 0, 0, 0, 80, 42010),
(65053, 0, 0, 0, 80, 42010),
(65050, 0, 0, 0, 80, 42010),
(65043, 0, 0, 0, 80, 42010),
(65067, 0, 0, 0, 80, 42010),
(57622, 0, 0, 0, 80, 42010),
(65064, 0, 0, 0, 80, 42010),
(65059, 0, 0, 0, 80, 42010),
(65039, 0, 0, 0, 80, 42010),
(65052, 0, 0, 0, 80, 42010),
(65047, 0, 0, 0, 80, 42010),
(65062, 0, 0, 0, 80, 42010),
(65084, 0, 0, 0, 80, 42010),
(65044, 0, 0, 0, 80, 42010),
(65045, 0, 0, 0, 80, 42010),
(65093, 0, 0, 0, 80, 42010),
(65088, 0, 0, 0, 80, 42010),
(65146, 0, 0, 0, 80, 42010),
(65147, 0, 0, 0, 80, 42010),
(65089, 0, 0, 0, 80, 42010),
(56622, 0, 0, 0, 80, 42010),
(54787, 0, 0, 0, 80, 42010),
(57779, 0, 0, 0, 80, 42010),
(54734, 0, 0, 0, 80, 42010),
(54902, 0, 0, 0, 80, 42010),
(54900, 0, 0, 0, 80, 42010),
(54901, 0, 0, 0, 80, 42010),
(57625, 0, 0, 0, 657, 42010),
(54135, 0, 0, 0, 80, 42010),
(54609, 0, 0, 0, 80, 42010),
(54635, 0, 0, 0, 80, 42010),
(60176, 0, 0, 0, 80, 42010),
(59626, 0, 0, 0, 80, 42010),
(60245, 0, 0, 0, 80, 42010),
(60253, 0, 0, 0, 80, 42010),
(60248, 0, 0, 0, 80, 42010);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=42010 WHERE (`Entry`=41200 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=42010 WHERE (`Entry`=66298 AND `DifficultyID`=0);

UPDATE `creature_model_info` SET `VerifiedBuild`=42010 WHERE `DisplayID` IN (45874, 39672, 44068, 39759, 44065, 39637, 39478, 11686, 39479, 39481, 39480, 39674, 41667, 45872, 45873, 39644, 39806, 39755, 6295, 27883, 45862, 45863, 43682, 39898, 39895, 39903, 44071, 44072, 44070, 44078, 44069, 39904, 39896, 39899, 39807, 42028, 44081, 28998, 39905, 44080, 39902, 39804, 39801, 44079, 39803, 44073, 44075, 45925, 39890, 44074, 45926, 39888, 39795, 39887, 39892, 44076, 38459, 39661, 44024, 39798, 39658, 42250, 39758, 39574, 42855, 47031, 39659, 43391, 44025, 44026, 44027, 39406);

UPDATE `trainer` SET `VerifiedBuild`=42010 WHERE `Id` IN (59, 388);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=59 AND `SpellId`=264212) OR (`TrainerId`=388 AND `SpellId`=265820);
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(59, 264212, 10, 0, 0, 0, 0, 0, 5, 42010), -- No Faction found! MoneyCost not recalculated!
(388, 265820, 10, 0, 0, 0, 0, 0, 5, 42010); -- No Faction found! MoneyCost not recalculated!

UPDATE `trainer_spell` SET `ReqSkillLine`=2485, `VerifiedBuild`=42010 WHERE (`TrainerId`=59 AND `SpellId` IN (2331,3170,2332)); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=200, `ReqSkillLine`=2485, `VerifiedBuild`=42010 WHERE (`TrainerId`=59 AND `SpellId`=2334); -- No Faction found! MoneyCost not recalculated!
UPDATE `trainer_spell` SET `MoneyCost`=225, `ReqSkillLine`=2485, `VerifiedBuild`=42010 WHERE (`TrainerId`=59 AND `SpellId`=2337); -- No Faction found! MoneyCost not recalculated!

DELETE FROM `spell_area` WHERE `spell` IN (105096, 108914, 117783, 117501, 108931, 105525, 115449, 115447, 109067, 105095, 105001, 104566, 105306, 104334, 106394, 104567, 105005, 105307, 105308, 108842, 108844, 109100, 104028, 104762, 115446, 115448, 118028, 104018, 114455, 109303, 108835, 108822, 108823, 128574, 102875, 102871, 116571, 102874, 102870, 103051, 108879, 108834, 102873, 102872, 102869, 106494, 106493, 102868, 105156, 105157, 105158, 108695, 108694, 105162, 105161, 105160, 102521, 119305, 119306, 119307, 102400, 102399, 102398, 102397, 102396, 102395, 114735, 102194, 100709, 107027, 107028, 107032, 102403, 100711, 107033, 102393, 102429);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(100709, 5834, 0, 29524, 0, 0, 2, 3, 0, 9), -- See Quest Invis 1 (Master Shang bench)
(107027, 5834, 0, 29406, 0, 0, 2, 3, 0, 11), -- See Quest Invis 20 (Gate 1 - GO)
(107028, 5834, 0, 29524, 0, 0, 2, 3, 0, 9), -- See Quest Invis 21 (Master Shang's staff & barrel near bench - GO)
(107032, 5834, 29524, 0, 0, 0, 2, 3, 74, 0), -- See Quest Invis 22 (Gate 2 - GO)
(102403, 5825, 29524, 0, 0, 0, 2, 3, 8, 0), -- Force Reaction Sparring Trainees
(102403, 5834, 29524, 0, 0, 0, 2, 3, 8, 0), -- Force Reaction Sparring Trainees
(102403, 5843, 29524, 0, 0, 0, 2, 3, 8, 0), -- Force Reaction Sparring Trainees
(100711, 5834, 29524, 29409, 0, 0, 2, 3, 66, 9), -- See Quest Invis 3 (Master Shang inside)
(107033, 5834, 29409, 0, 0, 0, 2, 3, 74, 0), -- See Quest Invis 23 (Gate 3 - GO)
(102429, 5825, 29409, 0, 0, 0, 2, 3, 10, 0), -- Force Reaction Jaomin Po
(102429, 5843, 29409, 0, 0, 0, 2, 3, 10, 0), -- Force Reaction Jaomin Po
(102194, 5825, 29409, 29414, 0, 0, 2, 3, 66, 9), -- See Quest Invis 4 (Master Shang bridge)
(102194, 5834, 29409, 29414, 0, 0, 2, 3, 66, 9), -- See Quest Invis 4 (Master Shang bridge)
(102194, 5843, 29409, 29414, 0, 0, 2, 3, 66, 9), -- See Quest Invis 4 (Master Shang bridge)
(102393, 5825, 0, 29419, 0, 0, 2, 3, 0, 9), -- See Quest Invis 5 (Mechant Lorvo & Alysa mole)
(102393, 5846, 0, 29419, 0, 0, 2, 3, 0, 9), -- See Quest Invis 5 (Mechant Lorvo & Alysa mole)
(114735, 5825, 29419, 29414, 0, 0, 2, 3, 66, 1), -- See Quest Invis 10 (Alysa Cloudsinger mole)
(114735, 5846, 29419, 29414, 0, 0, 2, 3, 66, 1), -- See Quest Invis 10 (Alysa Cloudsinger mole)
(102395, 5825, 29419, 0, 0, 0, 2, 3, 66, 0), -- See Quest Invis 6 (Mechant Lorvo mole)
(102395, 5846, 29419, 0, 0, 0, 2, 3, 66, 0), -- See Quest Invis 6 (Mechant Lorvo mole)
(102396, 5825, 29414, 29417, 0, 0, 2, 3, 66, 1), -- See Quest Invis 7 (Master Shang & Alysa cave)
(102396, 5846, 29414, 29417, 0, 0, 2, 3, 66, 1), -- See Quest Invis 7 (Master Shang & Alysa cave)
(102396, 5848, 29414, 29417, 0, 0, 2, 3, 66, 1), -- See Quest Invis 7 (Master Shang & Alysa cave)
(102397, 5835, 29522, 0, 0, 0, 2, 3, 66, 0), -- See Quest Invis 8 (???)
(102398, 5835, 29523, 29423, 0, 0, 2, 3, 66, 1), -- See Quest Invis 9 (Master Shang Wu-Shong Village)
(102399, 5849, 29420, 29423, 0, 0, 2, 3, 66, 9), -- See Quest Invis 10 (Master Li Fei)
(102400, 5849, 0, 29423, 0, 0, 2, 3, 0, 1), -- See Quest Invis 11 (Huo)
(102521, 5849, 0, 29422, 0, 0, 2, 3, 0, 1), -- See Quest Invis 12 (Flame Wall - GO)
(105160, 5849, 0, 29664, 0, 0, 2, 3, 0, 9), -- See Quest Invis 16 (Red Flame - GO)
(105161, 5849, 0, 29664, 0, 0, 2, 3, 0, 9), -- See Quest Invis 17 (Blue Flame - GO)
(105162, 5849, 0, 29664, 0, 0, 2, 3, 0, 9), -- See Quest Invis 18 (Violet Flame - GO)
(108694, 5849, 29664, 0, 0, 0, 2, 3, 8, 0), -- See Quest Invis 19 (Sparkle Bunny - Flickering Flame)
(108695, 5849, 29664, 0, 0, 0, 2, 3, 8, 0), -- See Quest Invis 20 (Sparkle Bunny flames)
(105156, 5849, 29664, 29422, 0, 0, 2, 6, 74, 1), -- See Quest Invis 13 (Red Flame activated - GO)
(105157, 5849, 29664, 29422, 0, 0, 2, 6, 74, 1), -- See Quest Invis 14 (Blue Flame activated - GO)
(105158, 5849, 29664, 29422, 0, 0, 2, 6, 74, 1), -- See Quest Invis 15 (Violet Flame activated - GO)
(119305, 5849, 29422, 0, 0, 0, 2, 3, 74, 0), -- See Quest Invis 13 (Red Flame activated - GO)
(119306, 5849, 29422, 0, 0, 0, 2, 3, 74, 0), -- See Quest Invis 14 (Blue Flame activated - GO)
(119307, 5849, 29422, 0, 0, 0, 2, 3, 74, 0), -- See Quest Invis 15 (Violet Flame activated - GO)
(106493, 5820, 0, 29423, 0, 0, 2, 3, 0, 11), -- See Quest Invis 15 (Brazier temple)
(102868, 5820, 29423, 29775, 0, 0, 2, 3, 74, 9), -- See Quest Invis 1 (Master Shang temple)
(106494, 5820, 29423, 0, 0, 0, 2, 7, 66, 0), -- See Quest Invis 16 (Brazier temple - GO)
(102869, 5826, 29521, 29677, 0, 0, 2, 3, 66, 1), -- See Quest Invis 1 (Aysa in water)
(102872, 5826, 0, 29662, 0, 0, 2, 3, 0, 11), -- See Quest Invis 4 (Jojo Ironbrow)
(102873, 5826, 0, 29677, 0, 0, 2, 3, 0, 9), -- See Quest Invis 5 (Old Man Liang - Liang's Retreat)
(102873, 5860, 0, 29677, 0, 0, 2, 3, 0, 9), -- See Quest Invis 5 (Old Man Liang - Liang's Retreat)
(108834, 5826, 0, 29662, 0, 0, 2, 5, 0, 11), -- See Quest Invis 8 (Children & Onlookers)
(108879, 5826, 0, 0, 0, 0, 2, 3, 0, 0), -- See Quest Invis 9 (Cart - The Singing Pools)
(103051, 5826, 29663, 0, 0, 0, 2, 3, 8, 0), -- Force Reaction Tushui Monks
(102870, 5826, 29677, 29678, 0, 0, 2, 3, 74, 9), -- See Quest Invis 2 (Aysa near jumping rocks)
(102874, 5826, 29677, 29678, 0, 0, 2, 3, 74, 9), -- See Quest Invis 6 (Old Man Liang near jumping rocks)
(116571, 5862, 29678, 0, 0, 0, 2, 3, 74, 0), -- Blessing of the Water Strider
(102871, 5862, 29678, 29776, 0, 0, 2, 3, 66, 11), -- See Quest Invis 3 (Aysa near Shu)
(102871, 5826, 29678, 29776, 0, 0, 2, 3, 66, 11), -- See Quest Invis 3 (Aysa near Shu)
(102875, 5862, 29678, 0, 0, 0, 2, 3, 66, 0), -- See Quest Invis 7 (Old Man Liang near Shu)
(102875, 5826, 29678, 0, 0, 0, 2, 3, 66, 0), -- See Quest Invis 7 (Old Man Liang near Shu)
(128574, 5862, 29678, 29679, 0, 0, 2, 3, 66, 9), -- See Quest Invis 29 (Shu)
(104018, 5881, 29680, 29774, 0, 0, 2, 7, 64, 9), -- See Quest Invis 1 (Shu)
(108822, 5881, 29423, 29768, 0, 0, 2, 3, 64, 1), -- See Quest Invis 2 (Ji Firepaw)
(108823, 5881, 29662, 29771, 0, 0, 2, 3, 64, 11), -- See Quest Invis 3 (Jojo Ironbrow)
(108835, 5881, 29662, 29771, 0, 0, 2, 5, 64, 11), -- See Quest Invis 4 (Children & Onlookers)
(109303, 5881, 0, 29774, 0, 0, 2, 3, 0, 9), -- See Quest Invis 5 (Wugou - gong)
(114455, 5881, 0, 0, 0, 0, 2, 3, 0, 0), -- See Quest Invis 6 (Cart - The Dai-Lo Farmstead)
(118028, 5881, 29768, 29776, 0, 0, 2, 3, 74, 11), -- See Quest Invis 7 (Ji Firepaw)
(115446, 5828, 0, 29792, 0, 0, 2, 3, 0, 9), -- See Quest Invis 29 (Mandori Village Gate - GO)
(104028, 5820, 29775, 29776, 0, 0, 2, 3, 66, 11), -- See Quest Invis 2 (Master Shang)
(104762, 5886, 29786, 0, 0, 0, 2, 3, 8, 0), -- Phase Shift: Dragon Fight + Normal
(104334, 5886, 0, 29785, 0, 0, 2, 3, 0, 9), -- See Quest Invis 1 (Chamber Winds - GO)
(106394, 5859, 0, 29787, 0, 0, 2, 3, 0, 9), -- See Quest Invis 2 (Spirit Wall - GO)
(104566, 5886, 29785, 29786, 0, 0, 2, 3, 66, 1), -- See Quest Invis 4 (Aysa - near Air Spirit)
(104567, 5886, 0, 29786, 0, 0, 2, 3, 0, 1), -- See Quest Invis 5 (Dafeng)
(105005, 5830, 0, 29787, 0, 0, 2, 3, 0, 1), -- See Quest Invis 6 (Balloon)
(105005, 5946, 0, 29787, 0, 0, 2, 3, 0, 1), -- See Quest Invis 6 (Balloon)
(105307, 5830, 29776, 29787, 0, 0, 2, 3, 66, 1), -- See Quest Invis 7 (Ji Firepaw)
(105307, 5946, 29776, 29787, 0, 0, 2, 3, 66, 1), -- See Quest Invis 7 (Ji Firepaw)
(105308, 5830, 29776, 0, 0, 0, 2, 3, 66, 0), -- See Quest Invis 8 (Aysa on rope - Lake)
(105308, 5946, 29776, 0, 0, 0, 2, 3, 66, 0), -- See Quest Invis 8 (Aysa on rope - Lake)
(108842, 5830, 29771, 29782, 0, 0, 2, 3, 66, 11), -- See Quest Invis 9 (Jojo Ironbrow)
(108842, 5946, 29771, 29782, 0, 0, 2, 3, 66, 11), -- See Quest Invis 9 (Jojo Ironbrow)
(108844, 5830, 29771, 29782, 0, 0, 2, 5, 66, 11), -- See Quest Invis 10 (Children & Onlookers)
(108844, 5946, 29771, 29782, 0, 0, 2, 5, 66, 11), -- See Quest Invis 10 (Children & Onlookers)
(109100, 5829, 0, 0, 0, 0, 2, 3, 0, 0), -- See Quest Invis 11 (???)
(105306, 5831, 0, 0, 0, 0, 2, 1, 0, 0), -- Summon Ji Yuan - has conditions
(105001, 5859, 29787, 29791, 0, 0, 2, 3, 74, 9), -- See Quest Invis 1 (Ji Firepaw)
(105001, 5832, 29787, 29791, 0, 0, 2, 3, 74, 9), -- See Quest Invis 1 (Ji Firepaw)
(105095, 5820, 29791, 0, 0, 0, 2, 3, 66, 0), --  See Quest Invis 3 (Elder Shaopai)
(109067, 5820, 29776, 29791, 0, 0, 2, 3, 64, 9), --  See Quest Invis 17 (Uplifting Draft)
(115448, 5828, 29792, 0, 0, 0, 2, 3, 8, 0), -- See Quest Invis 27 (Pei-Wu Forest Gate - GO)
(115448, 5737, 29792, 0, 0, 0, 2, 3, 8, 0), -- See Quest Invis 27 (Pei-Wu Forest Gate - GO)
(115447, 5828, 29792, 0, 0, 0, 2, 3, 74, 0), -- See Quest Invis 28 (Mandori Village Gate open - GO)
(115447, 5737, 29792, 0, 0, 0, 2, 3, 74, 0), -- See Quest Invis 28 (Mandori Village Gate open - GO)
(115449, 5737, 29792, 0, 0, 0, 2, 3, 66, 0), -- See Quest Invis 26 (Pei-Wu Forest Gate open - GO)
(105525, 5833, 0, 29794, 0, 0, 2, 3, 0, 9), -- See Quest Invis 1 (Injured Sailor)
(108931, 5833, 0, 0, 0, 0, 2, 3, 0, 0), -- See Quest Invis 2 (Cart - Wreck of the Skyseeker)
(117501, 5833, 0, 29799, 0, 0, 2, 3, 0, 1), -- See Quest Invis 11 (Aysa Cloudsinger - after Vordraka fight)
(117783, 5833, 29799, 0, 0, 0, 2, 3, 8, 0), -- The Healing of Shen-zin Su - altpower
(108914, 5820, 29800, 0, 0, 0, 2, 3, 74, 0), -- See Quest Invis 5 (Delora, Aysa, Ji, Korga)
(105096, 5820, 29800, 0, 0, 0, 2, 3, 74, 0); -- See Quest Invis 4 (Spirit of Master Shang)

DELETE FROM `conversation_actors` WHERE `ConversationId`=13254 AND `Idx`=1;
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(13254, 0, 0, 1, 0, 0, 0, 1, 40120);

DELETE FROM `conversation_actors` WHERE `ConversationId`=16722 AND `Idx`=0;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`,`ActivePlayerObject`, `VerifiedBuild`) VALUES
(16722, 0, 0, 0, 0, 0, 1, 0, 42010); -- Full: 0x0

DELETE FROM `conversation_line_template` WHERE `Id` IN (42193, 42194, 42195, 42196, 42197, 42198);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(42193, 0, 0, 0, 42010),
(42194, 0, 0, 0, 42010),
(42195, 0, 0, 0, 42010),
(42196, 0, 0, 0, 42010),
(42197, 0, 0, 0, 42010),
(42198, 0, 0, 0, 42010);

DELETE FROM `conversation_template` WHERE `Id`=16722;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(16722, 42193, 0, 42010);

DELETE FROM `creature_text` WHERE `CreatureID` IN (53565, 54586, 54587, 60183, 60244, 65469, 65470, 65471);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(53565, 0, 0, 'I must train harder so I can be like you.', 12, 0, 100, 509, 0, 33645, 0, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 1, 'Such skill for a new trainee.', 12, 0, 100, 507, 0, 33643, 0, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 2, 'One day you will have to teach me your secrets.', 12, 0, 100, 509, 0, 33645, 0, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 3, 'I hope the instructors saw that!', 12, 0, 100, 0, 0, 33645, 0, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 4, 'Your form is impeccable.', 12, 0, 100, 509, 0, 33645, 0, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 5, 'That target didn´t stand a chance.', 12, 0, 100, 511, 0, 33643, 0, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 6, 'You are bound for a great things, trainee.', 12, 0, 100, 508, 0, 33645, 0, 0, 'Aspiring Trainee to Training Target'),
(53565, 0, 7, 'I must work as hard as you.', 12, 0, 100, 1, 0, 33646, 0, 0, 'Aspiring Trainee to Training Target'),
(53565, 7, 0, 'Four coppers on Zhou.', 12, 0, 100, 511, 0, 33646, 56427, 0, 'Aspiring Trainee'),
(53565, 2, 0, 'His stamina is nothing against Lam\'s strength.', 12, 0, 100, 507, 0, 33646, 56423, 0, 'Aspiring Trainee'),
(53565, 3, 0, 'He has the legs of an ox! Have you ever been kicked by him in training?', 12, 0, 100, 1, 0, 33643, 56424, 0, 'Aspiring Trainee'),
(53565, 4, 0, 'Raise you a keg of Stormstout Gold. It\'ll be your loss.', 12, 0, 100, 0, 0, 33643, 56428, 0, 'Aspiring Trainee'),
(53565, 1, 0, 'My money\'s on Lam. Did you see him take down Chu during training last week?', 12, 0, 100, 509, 0, 33645, 56420, 0, 'Aspiring Trainee'),
(53565, 5, 0, 'That\'s where you\'re mistaken, friend. Zhou is as sturdy as an oak.', 12, 0, 100, 543, 0, 33643, 56421, 0, 'Aspiring Trainee'),
(53565, 6, 0, 'Zhou has the stamina of three men, so he can out-stay most opponents.', 12, 0, 100, 543, 0, 33646, 56422, 0, 'Aspiring Trainee'),
(54586, 0, 0, 'You are an honorable opponent.', 12, 0, 100, 543, 0, 33643, 56438, 0, 'Huojin Trainee'),
(54586, 0, 1, 'That was a good match. Thank you.', 12, 0, 100, 509, 0, 33645, 56444, 0, 'Huojin Trainee'),
(54586, 0, 2, 'You fought well. I must learn more from you in the future.', 12, 0, 100, 509, 0, 33645, 56443, 0, 'Huojin Trainee'),
(54586, 0, 3, 'You fight honorably, friend.', 12, 0, 100, 543, 0, 33643, 56437, 0, 'Huojin Trainee'),
(54587, 0, 0, 'Your skills are too great. I yield.', 12, 0, 100, 1, 0, 33646, 56442, 0, 'Tushui Trainee'),
(54587, 1, 0, 'You fought well. I must learn more from you in the future.', 12, 0, 100, 1, 0, 33643, 56443, 0, 'Tushui Trainee'),
(54587, 2, 0, 'You fight honorably, friend.', 12, 0, 100, 508, 0, 33645, 56440, 0, 'Tushui Trainee'),
(54587, 3, 0, 'Thank you for reminding me that I must train more diligently.', 12, 0, 100, 1, 0, 33645, 56439, 0, 'Tushui Trainee'),
(54587, 4, 0, 'I have never seen a trainee with skills such as yours. I must tell the others.', 12, 0, 100, 1, 0, 33645, 0, 0, 'Tushui Trainee'),
(60183, 0, 0, 'I hope you\'re ready, $p. Jaomin Ro awaits you just over the bridge.', 12, 0, 100, 113, 0, 33643, 59710, 0, 'Trainee Nim to Player'),
(60244, 0, 0, 'You\'re departing so soon?  I am envious of your prowess, $c. Good luck to you.', 12, 0, 100, 2, 0, 33643, 59711, 0, 'Trainee Guang to Player'),
(65469, 0, 1, 'I must work as hard as you.', 12, 0, 100, 507, 0, 33643, 0, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 2, 'I must train harder so I can be like you.', 12, 0, 100, 507, 0, 33643, 0, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 3, 'Your form is impeccable.', 12, 0, 100, 543, 0, 33643, 0, 0, 'Aspiring Trainee to Training Target'),
(65469, 0, 4, 'One day you will have to teach me your secrets.', 12, 0, 100, 507, 0, 33643, 0, 0, 'Aspiring Trainee to Training Target'),
(65470, 0, 0, 'I have never seen a trainee with skills such as yours. I must tell the others.', 12, 0, 100, 509, 0, 33643, 0, 0, 'Huojin Trainee'),
(65471, 1, 0, 'You are an honorable opponent.', 12, 0, 100, 1, 0, 33646, 0, 0, 'Huojin Trainee'),
(65471, 2, 0, 'My skills are no match for yours. I admit defeat.', 12, 0, 100, 1, 0, 33646, 0, 0, 'Huojin Trainee'),
(65471, 3, 0, 'Thank you for reminding me that I must train more diligently.', 12, 0, 100, 1, 0, 33645, 0, 0, 'Huojin Trainee'),
(65471, 4, 0, 'That was a good match. Thank you.', 12, 0, 100, 509, 0, 33645, 0, 0, 'Huojin Trainee'),
(65471, 5, 0, 'Your skills are too great. I yield.', 12, 0, 100, 508, 0, 33644, 0, 0, 'Huojin Trainee'),
(65471, 6, 0, 'I have never seen a trainee with skills such as yours. I must tell the others.', 12, 0, 100, 509, 0, 33643, 0, 0, 'Huojin Trainee');

DELETE FROM `waypoint_data` WHERE `id` IN (4502140, 4502150, 4502160, 4502170, 4502180, 4502190, 4502200, 4502210, 4502220, 4502230, 4502240, 4502250, 4502260, 4502270, 4502280, 4502290);
SET @CGUID := 450214;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
-- Instructor Mossthorn
((@CGUID+0)*10, 1, 1456.097, 3400.327, 171.1617, 0, 30000, 0, 0, 100, 0),
((@CGUID+0)*10, 2, 1449.597, 3404.077, 171.1617, 2.186576, 10000, 0, 0, 100, 0),
((@CGUID+0)*10, 3, 1451.847, 3416.077, 171.4117, 0, 0, 0, 0, 100, 0),
((@CGUID+0)*10, 4, 1442.097, 3421.827, 171.4117, 4.621339, 15000, 0, 0, 100, 0),
((@CGUID+0)*10, 5, 1439.097, 3431.827, 171.4117, 0, 0, 0, 0, 100, 0),
((@CGUID+0)*10, 6, 1442.597, 3439.577, 171.4117, 2.51673, 28000, 0, 0, 100, 0),
((@CGUID+0)*10, 7, 1452.847, 3438.327, 171.4117, 0.8980953, 12000, 0, 0, 100, 0),
((@CGUID+0)*10, 8, 1465.597, 3434.077, 171.4117, 2.505686, 10000, 0, 0, 100, 0),
((@CGUID+0)*10, 9, 1473.347, 3433.077, 171.4117, 4.309892, 15000, 0, 0, 100, 0),
((@CGUID+0)*10, 10, 1480.347, 3439.327, 171.4117, 0.4008824, 10000, 0, 0, 100, 0),
((@CGUID+0)*10, 11, 1487.597, 3437.327, 171.4117, 1.280082, 10000, 0, 0, 100, 0),
((@CGUID+0)*10, 12, 1486.097, 3423.827, 171.4117, 0.3201315, 15000, 0, 0, 100, 0),
((@CGUID+0)*10, 13, 1482.597, 3413.827, 171.4117, 0, 12000, 0, 0, 100, 0),
((@CGUID+0)*10, 14, 1473.347, 3414.327, 171.4117, 1.860022, 10000, 0, 0, 100, 0),
((@CGUID+0)*10, 15, 1466.847, 3413.327, 171.4117, 1.157754, 10000, 0, 0, 100, 0),
((@CGUID+0)*10, 16, 1463.097, 3405.827, 171.4117, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `position_x`= 1450.597, `position_y`= 3412.327, `position_z`= 171.1617, `orientation`= 0, `spawnDifficulties`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID, @PATH, 1);

DELETE FROM `gameobject` WHERE `guid` =@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 214409, 860, 5736, 5834, 0, 0, 0, 1451.9010009765625, 3385.123291015625, 175.4787139892578125, 4.389029979705810546, 0, 0, -0.81171226501464843, 0.584057569503784179, 120, 255, 1, 43114); -- Path of the Tushui (Area: Shang Xi Training Grounds - Difficulty: 0)

UPDATE `gameobject` SET `zoneId` =5736, `areaId` =5834, `map` =860, `VerifiedBuild` =42010  WHERE `id` IN (210005, 210015, 210016, 210017, 210018, 210019, 210020, 209970, 209971, 209972, 209973, 214565, 214564, 214568, 216301);

UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=262144 WHERE `entry`=209364; -- The Dimming Flame
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry` IN (209973, 209972, 209971, 209970); -- Temple Door
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=209608; -- Training Bell
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=209900; -- Central Turtle Statue Collision
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=209466; -- Balance Pole

UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=211337; -- Master Shang Xi's Barrel
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=209363; -- Scroll Post
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=213439; -- Turtle Flipper, Left
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=209078; -- Lilly Pad

UPDATE `gameobject_template_addon` SET `flags`=65536 WHERE `entry`=210005; -- Weapon Rack
UPDATE `gameobject_template_addon` SET `flags`=65536 WHERE `entry`=210015; -- Weapon Rack
UPDATE `gameobject_template_addon` SET `flags`=65536 WHERE `entry`=210016; -- Weapon Rack
UPDATE `gameobject_template_addon` SET `flags`=65536 WHERE `entry`=210017; -- Weapon Rack
UPDATE `gameobject_template_addon` SET `flags`=65536 WHERE `entry`=210018; -- Weapon Rack
UPDATE `gameobject_template_addon` SET `flags`=65536 WHERE `entry`=210019; -- Weapon Rack

UPDATE `gameobject_template_addon` SET `flags`=65536 WHERE `entry`=210020; -- Weapon Rack
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=211336; -- Master Shang Xi's Staff
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=213532; -- Turtle Flipper, Right
UPDATE `gameobject_template_addon` SET `flags`=65572 WHERE `entry`=210122; -- Wind Stone
UPDATE `gameobject_template_addon` SET `faction`=14 WHERE `entry`=209577; -- Rock Jump C

UPDATE `gameobject_template_addon` SET `faction`=14 WHERE `entry`=209576; -- Rock Jump B
UPDATE `gameobject_template_addon` SET `faction`=14 WHERE `entry`=209575; -- Rock Jump A
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=209584; -- Ancient Clam
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=209626; -- Break Gong
UPDATE `gameobject_template_addon` SET `flags`=2375680 WHERE `entry`=1617; -- Silverleaf

UPDATE `gameobject_template_addon` SET `flags`=2375680 WHERE `entry`=1618; -- Peacebloom
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=209507; -- Hard Tearwood Reed
UPDATE `gameobject_template_addon` SET `flags`=36 WHERE `entry` IN (209661, 209660); -- Defaced Scroll of Wisdom
UPDATE `gameobject_template_addon` SET `faction`=114, `flags`=32 WHERE `entry`=209924; -- Brazier
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry` IN (209375, 209367); -- Fire Wall

UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=209373; -- Brazier of the Blue Flame
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=209374; -- Brazier of the Red Flame
UPDATE `gameobject_template_addon` SET `faction`=114 WHERE `entry`=209372; -- Brazier of the Violet Flame
UPDATE `gameobject_template_addon` SET `flags`=65540 WHERE `entry` IN (209327, 209326); -- Loose Dogwood Root

DELETE FROM `gameobject_loot_template` WHERE `Entry` IN (210005, 210015, 210016, 210017, 210018, 210019, 210020, 40856, 40859, 40860, 40861, 40862, 40863, 40864);
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(40859, 76390, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Spellblade'), -- Mage
(40859, 76392, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Hand Fan'), -- Mage
(40856, 73209, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Staff'), -- Monk
(40863, 76391, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Axe'), -- Shaman
(40863, 73213, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Shield'), -- Shaman
(40861, 73207, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Mace'), -- Priest
(40861, 76393, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Book of Prayers'), -- Priest
(40862, 73208, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Dagger'), -- Rogue
(40862, 73212, 0, 100, 1, 1, 0, 1, 1, 'Second Trainee`s Dagger'), -- Rogue
(40860, 73211, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Crossbow'), -- Hunter
(40864, 76391, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Axe'), -- Warrior
(40864, 73213, 0, 100, 1, 1, 0, 1, 1, 'Trainee`s Shield'); -- Warrior

UPDATE `gameobject_template` SET `VerifiedBuild`=42010 WHERE `entry` IN (214568, 214564, 216301, 214565, 210102, 209989, 209988, 210101, 209973, 209972, 209971, 214353, 209900, 209466, 214409, 209363, 210987, 210124, 210126, 211337, 209078, 209970, 210127, 213439, 213532, 210125, 214413, 211336, 210122);
UPDATE `gameobject_template` SET `ContentTuningId`=80, `VerifiedBuild`=42010 WHERE `entry`=209364; -- The Dimming Flame
UPDATE `gameobject_template` SET `ContentTuningId`=80, `VerifiedBuild`=42010 WHERE `entry`=209608; -- Training Bell
UPDATE `gameobject_template` SET `ContentTuningId`=80, `VerifiedBuild`=42010 WHERE `entry`=210051; -- To Be A Pandaren
UPDATE `gameobject_template` SET `ContentTuningId`=80, `Data0`=57, `Data1`=40856, `Data17`=13360, `Data26`=128680, `Data30`=40856, `VerifiedBuild`=42010 WHERE `entry`=210005; -- Weapon Rack - Monk - Data 1 manualy rewrited - default 0
UPDATE `gameobject_template` SET `ContentTuningId`=80, `Data0`=57, `Data1`=40859, `Data17`=13361, `Data26`=128680, `Data30`=40859, `VerifiedBuild`=42010 WHERE `entry`=210015; -- Weapon Rack - Mag - Data 1 manualy rewrited - default 0
UPDATE `gameobject_template` SET `ContentTuningId`=80, `Data0`=57, `Data1`=40860, `Data17`=13362, `Data26`=128680, `Data30`=40860, `VerifiedBuild`=42010 WHERE `entry`=210016; -- Weapon Rack - Hunter - Data 1 manualy rewrited - default 0
UPDATE `gameobject_template` SET `ContentTuningId`=80, `Data0`=57, `Data1`=40861, `Data17`=13363, `Data26`=128680, `Data30`=40861, `VerifiedBuild`=42010 WHERE `entry`=210017; -- Weapon Rack - Priest - Data 1 manualy rewrited - default 0
UPDATE `gameobject_template` SET `ContentTuningId`=80, `Data0`=57, `Data1`=40862, `Data17`=13365, `Data26`=128680, `Data30`=40862, `VerifiedBuild`=42010 WHERE `entry`=210018; -- Weapon Rack - Rogue - Data 1 manualy rewrited - default 0
UPDATE `gameobject_template` SET `ContentTuningId`=80, `Data0`=57, `Data1`=40863, `Data17`=13366, `Data26`=128680, `Data30`=40863, `VerifiedBuild`=42010 WHERE `entry`=210019; -- Weapon Rack - Shaman - Data 1 manualy rewrited - default 0
UPDATE `gameobject_template` SET `ContentTuningId`=80, `Data0`=57, `Data1`=40864, `Data17`=13364, `Data26`=128680, `Data30`=40864, `VerifiedBuild`=42010 WHERE `entry`=210020; -- Weapon Rack - Warrior - Data 1 manualy rewrited - default 0

DELETE FROM `gameobject_questitem` WHERE (`Idx`=0 AND `GameObjectEntry` IN (210005, 210015, 210016, 210017, 210018, 210019, 210020)) OR (`Idx`=1 AND `GameObjectEntry` IN (210015, 210017, 210018, 210019, 210020));
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(210005, 0, 73209, 42010), -- Monk
(210015, 0, 76390, 42010), -- Mage
(210015, 1, 76392, 42010),
(210016, 0, 73211, 42010), -- Hunter
(210017, 0, 73207, 42010), -- Priest
(210017, 1, 76393, 42010),
(210018, 0, 73208, 42010), -- Rogue
(210018, 1, 73212, 42010),
(210019, 0, 76391, 42010), -- Shaman
(210019, 1, 73213, 42010),
(210020, 0, 76391, 42010), -- Warrior
(210020, 1, 73213, 42010);

DELETE FROM `creature_queststarter` WHERE `id` IN (53566, 55020, 54975, 54786, 54787, 54135, 54609, 54568, 55021, 54608, 54567, 54943);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
-- Introductory training
(53566, 30033), -- Mage only
(53566, 30027), -- Monk only - The Lesson of the Iron Bough offered Master Shang Xi
(53566, 30038), -- Warrior only
(53566, 30034), -- Hunter only
(53566, 30035), -- Priest only
(53566, 30036), -- Rogue only
(53566, 30037), -- Shaman only
(55020, 29678), -- Shu, the Spirit of Water offered Old Man Liang
(55020, 29666), -- The Sting of Learning offered Old Man Liang
(55020, 29677), -- The Sun Pearl offered Old Man Liang
(54975, 29676), -- Finding an Old Friend offered Aysa Cloudsinger
(55021, 29662), -- Stronger Than Reeds offered Jojo Ironbrow
(54975, 29663), -- The Lesson of the Balanced Rock offered Aysa Cloudsinger
(54975, 29661), -- The Lesson of Dry Fur offered Aysa Cloudsinger
(54786, 29521), -- The Singing Pools offered Master Shang Xi
(54787, 29423), -- The Passion of Shen-zin Su offered Huo
(54135, 29422), -- Huo, the Spirit of Fire offered Master Li Fei
(54135, 29421), -- Only the Worthy Shall Pass offered Master Li Fei
(54135, 29664), -- The Challenger's Fires offered Master Li Fei
(54609, 29420), -- The Spirit's Guardian offered Master Shang Xi
(54568, 29523), -- Fanning the Flames offered Ji Firepaw
(54568, 29418), -- Kindling the Fire offered Ji Firepaw
(54568, 29417), -- The Way of the Huojin offered Ji Firepaw
(54608, 29522), -- Ji of the Huojin offered Master Shang Xi
(54567, 29414), -- The Way of the Tushui offered Aysa Cloudsinger
(54943, 29424), -- Items of Utmost Importance offered Merchant Lorvo
(54943, 29419), -- The Missing Driver offered Merchant Lorvo
(53566, 29410), -- Aysa of the Tushui offered Master Shang Xi
(53566, 29409), -- The Disciple's Challenge offered Master Shang Xi
(53566, 29408), -- The Lesson of the Burning Scroll offered Master Shang Xi
(53566, 29524), -- The Lesson of Stifled Pride offered Master Shang Xi
(53566, 29406); -- The Lesson of the Sandy Fist offered Master Shang Xi

DELETE FROM `creature_questender` WHERE `id` IN (53566, 54943, 54608);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
-- Introductory training
(53566, 30033), -- Mage only
(53566, 30027), -- Monk only
(53566, 30038), -- Warrior only
(53566, 30034), -- Hunter only
(53566, 30035), -- Priest only
(53566, 30036), -- Rogue only
(53566, 30037), -- Shaman only
(54608, 29414), -- 29414 ended by 54608
(54943, 29424), -- 29424 ended by 54943
(54943, 29419), -- 29419 ended by 54943
(54943, 29410), -- 29410 ended by 54943
(53566, 29409), -- 29409 ended by 53566
(53566, 29408), -- 29408 ended by 53566
(53566, 29524), -- 29524 ended by 53566
(53566, 29406); -- 29406 ended by 53566

DELETE FROM `quest_request_items` WHERE `ID`=29424;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29424, 1, 0, 0, 0, 'You needn\'t worry about hurting the sprites. They\'re really just living plants when it comes down to it - they\'ll resprout later.', 0); -- Items of Utmost Importance

DELETE FROM `quest_offer_reward` WHERE `ID` IN (29409, 29408, 29424, 29410, 29524, 29406, 30027, 30033, 30034, 30035, 30036, 30037, 30038, 29414, 29419);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(29409, 1, 0, 0, 0, 0, 0, 0, 0, 'You truly impress, $n. It seems certain that the path of the $c is indeed the path for you.', 42010), -- The Disciple's Challenge
(29408, 1, 0, 0, 0, 0, 0, 0, 0, 'The fact that you were able to snatch the flame so easily is no small feat.$B$BThe Edict of Temperance is a scroll of wisdom passed down from my elders\' elders. Wisdom from a more peaceful time.$B$BEvery lesson has its time and place, and with darkness on the horizon, the time for this particular wisdom has passed.$B$BThe burning of the scroll is an acceptance of tidings to come and a promise to action. Your hand carried the flame, and I suspect that it will continue to do so in the future.', 42010), -- The Lesson of the Burning Scroll
(29524, 1, 0, 0, 0, 0, 0, 0, 0, 'Intriguing, my young pupil.$B$BMost of the other trainees have been here for quite some time, but you are able to match them even within this first hour.$B$BThis speaks well of you, but there are yet other lessons I would see you learn.', 42010), -- The Lesson of Stifled Pride
(29406, 1, 0, 0, 0, 0, 0, 0, 0, 'Not bad, $n. You may indeed have chosen the proper path.$B$BGood. Let us continue.', 42010), -- The Lesson of the Sandy Fist
(30027, 1, 0, 0, 0, 0, 0, 0, 0, 'A fine weapon. It should suit your needs well.$B$BNow let\'s put it to use.', 42010), -- The Lesson of the Iron Bough
(30033, 1, 0, 0, 0, 0, 0, 0, 0, 'A fine weapon. It should suit your needs well.$B$BNow let\'s put it to use.', 42010), -- The Lesson of the Iron Bough
(30034, 1, 0, 0, 0, 0, 0, 0, 0, 'A fine weapon. It should suit your needs well.$B$BNow let\'s put it to use.', 42010), -- The Lesson of the Iron Bough
(30035, 1, 0, 0, 0, 0, 0, 0, 0, 'A fine weapon. It should suit your needs well.$B$BNow let\'s put it to use.', 42010), -- The Lesson of the Iron Bough
(30036, 1, 0, 0, 0, 0, 0, 0, 0, 'A fine weapon. It should suit your needs well.$B$BNow let\'s put it to use.', 42010), -- The Lesson of the Iron Bough
(30037, 1, 0, 0, 0, 0, 0, 0, 0, 'A fine weapon. It should suit your needs well.$B$BNow let\'s put it to use.', 42010), -- The Lesson of the Iron Bough
(30038, 1, 0, 0, 0, 0, 0, 0, 0, 'A fine weapon. It should suit your needs well.$B$BNow let\'s put it to use.', 42010), -- The Lesson of the Iron Bough
(29424, 1, 0, 0, 0, 0, 0, 0, 0, 'Thank you! You\'re an honorable $c. They\'ve taught you well.', 42010), -- Items of Utmost Importance
(29410, 1, 0, 0, 0, 0, 0, 0, 0, 'You came for Aysa? You... you really shouldn\'t interrupt her until she finishes her exercises. She doesn\'t speak to anyone until her routine is done.$B$BIn the meantime, could you maybe help me? I had some bad luck with forest sprites.', 42010), -- Aysa of the Tushui
(29414, 1, 0, 0, 0, 0, 0, 0, 0, 'Your path is set before you. You will be the one to rekindle the spirit of fire and bring it to the safety of the temple.$B$BThis will not be the only time you and Aysa work together. She is strong and wise. You can trust in her.', 42010), -- The Way of the Tushui
(29419, 1, 0, 0, 0, 0, 0, 0, 0, 'You are too kind, $c.', 42010); -- The Missing Driver

DELETE FROM `quest_poi` WHERE  (`QuestID`=29523 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29523 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29523 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29677 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29677 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29677 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29666 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29666 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29666 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29524 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29524 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29524 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29408 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=29408 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29408 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29408 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29410 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29410 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29524 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29524 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29524 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29406 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29406 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29406 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=30027 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=30027 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=30027 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=30027 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29409 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29409 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29409 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=30037 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=30037 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=30037 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=30037 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=30037 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=30037 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29522 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29522 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29414 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29414 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29414 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29424 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=29424 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=29424 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29424 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=29419 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=29419 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=29419 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(29408, 0, 3, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 599603, 0, 42010), -- 29408
(29408, 0, 2, 1, 252345, 59570, 860, 378, 0, 2, 0, 0, 0, 0, 0, 42010), -- 29408
(29408, 0, 1, 0, 252344, 59591, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29408
(29408, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29408
(29410, 0, 1, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 602713, 0, 42010), -- 29410
(29410, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29410
(29424, 0, 3, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 604127, 0, 42010), -- Items of Utmost Importance
(29424, 1, 2, 0, 252015, 72071, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- Items of Utmost Importance
(29424, 0, 1, 0, 252015, 72071, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- Items of Utmost Importance
(29424, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- Items of Utmost Importance
(29406, 0, 2, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 596210, 0, 42010), -- 29406
(29406, 0, 1, 0, 252339, 53714, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29406
(29406, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29406
(30027, 0, 3, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 596210, 0, 42010), -- 30027
(30027, 0, 2, 29, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30027
(30027, 0, 1, 0, 253214, 54139, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30027
(30027, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30027
(29409, 0, 2, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 599603, 0, 42010), -- 29409
(29409, 0, 1, 0, 252375, 54611, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29409
(29409, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29409
(30037, 0, 5, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 596210, 0, 42010), -- 30037
(30037, 0, 4, 29, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30037
(30037, 0, 3, 28, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30037
(30037, 0, 2, 1, 253783, 57849, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30037
(30037, 0, 1, 0, 253782, 54139, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30037
(30037, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30037
(29522, 0, 1, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 603282, 0, 42010), -- 29522
(29522, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29522
(29414, 0, 2, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 602126, 0, 42010), -- 29414
(29414, 0, 1, 0, 252376, 54856, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29414
(29414, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29414
(29419, 0, 2, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 604128, 0, 42010), -- 29419
(29419, 0, 1, 0, 252090, 54855, 860, 378, 0, 2, 0, 0, 0, 0, 0, 42010), -- 29419
(29419, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29419
(29677, 0, 2, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 604666, 0, 42010), -- The Sun Pearl
(29677, 0, 1, 0, 251732, 73184, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Sun Pearl
(29677, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Sun Pearl
(29666, 0, 2, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 605468, 0, 42010), -- The Sting of Learning
(29666, 0, 1, 0, 258382, 60411, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Sting of Learning
(29666, 0, 0, -1, 0, 0, 860, 378, 0, 2, 0, 0, 0, 0, 0, 42010), -- The Sting of Learning
(29523, 0, 2, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 602127, 0, 42010), -- Fanning the Flames
(29523, 0, 1, 0, 252231, 72112, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- Fanning the Flames
(29523, 0, 0, -1, 0, 0, 860, 378, 0, 1, 0, 0, 0, 0, 0, 42010), -- Fanning the Flames
(29524, 0, 2, 32, 0, 0, 860, 378, 0, 0, 0, 0, 0, 599603, 0, 42010), -- The Lesson of Stifled Pride
(29524, 0, 1, 0, 254896, 54586, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Lesson of Stifled Pride
(29524, 0, 0, -1, 0, 0, 860, 378, 0, 0, 0, 0, 0, 0, 0, 42010); -- The Lesson of Stifled Pride

DELETE FROM `quest_poi_points` WHERE (`QuestID`=29666 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29666 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29666 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29677 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29677 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29677 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29523 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29523 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29523 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29424 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29424 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=29424 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=29424 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=29424 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29424 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29424 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29424 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29424 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29424 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29424 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29424 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29424 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29424 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29410 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29410 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29409 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29409 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29409 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29408 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=29408 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29408 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29408 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29524 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29524 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29524 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=29406 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=29406 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=29406 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=30027 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=30027 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=30027 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=30027 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=30027 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=30027 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=30027 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=30027 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=30027 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=30037 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=30037 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=30037 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=30037 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=30037 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=30037 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=30037 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=30037 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=30037 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=30037 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=30037 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=30037 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=30037 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=30037 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=30037 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=30037 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(29666, 2, 0, 1023, 2883, 145, 42010), -- The Sting of Learning
(29666, 1, 11, 849, 2810, 0, 42010), -- The Sting of Learning
(29666, 1, 10, 824, 2865, 97, 42010), -- The Sting of Learning
(29666, 1, 9, 834, 2950, 97, 42010), -- The Sting of Learning
(29666, 1, 8, 846, 3043, 97, 42010), -- The Sting of Learning
(29666, 1, 7, 849, 3107, 97, 42010), -- The Sting of Learning
(29666, 1, 6, 946, 3105, 98, 42010), -- The Sting of Learning
(29666, 1, 5, 1054, 3082, 98, 42010), -- The Sting of Learning
(29666, 1, 4, 1100, 3040, 98, 42010), -- The Sting of Learning
(29666, 1, 3, 1119, 3004, 99, 42010), -- The Sting of Learning
(29666, 1, 2, 1131, 2964, 98, 42010), -- The Sting of Learning
(29666, 1, 1, 1010, 2884, 98, 42010), -- The Sting of Learning
(29666, 1, 0, 956, 2804, 98, 42010), -- The Sting of Learning
(29666, 0, 0, 1023, 2883, 145, 42010), -- The Sting of Learning
(29677, 2, 0, 1096, 3093, 145, 42010), -- The Sun Pearl
(29677, 1, 0, 946, 2942, 78, 42010), -- The Sun Pearl
(29677, 0, 0, 1023, 2883, 145, 42010), -- The Sun Pearl
(29523, 2, 0, 1407, 3637, 83, 42010), -- Fanning the Flames
(29523, 1, 0, 1226, 3716, 94, 42010), -- Fanning the Flames
(29523, 0, 0, 1410, 3639, 83, 42010), -- Fanning the Flames
(29424, 3, 0, 1201, 3508, 86, 42010), -- Items of Utmost Importance
(29424, 2, 3, 1172, 3564, 88, 42010), -- Items of Utmost Importance
(29424, 2, 2, 1244, 3591, 87, 42010), -- Items of Utmost Importance
(29424, 2, 1, 1249, 3565, 89, 42010), -- Items of Utmost Importance
(29424, 2, 0, 1158, 3526, 125, 42010), -- Items of Utmost Importance
(29424, 1, 7, 1336, 3451, 99, 42010), -- Items of Utmost Importance
(29424, 1, 6, 1336, 3504, 99, 42010), -- Items of Utmost Importance
(29424, 1, 5, 1353, 3562, 87, 42010), -- Items of Utmost Importance
(29424, 1, 4, 1361, 3575, 86, 42010), -- Items of Utmost Importance
(29424, 1, 3, 1415, 3573, 88, 42010), -- Items of Utmost Importance
(29424, 1, 2, 1479, 3536, 87, 42010), -- Items of Utmost Importance
(29424, 1, 1, 1506, 3506, 89, 42010), -- Items of Utmost Importance
(29424, 1, 0, 1357, 3423, 125, 42010), -- Items of Utmost Importance
(29424, 0, 0, 1201, 3508, 86, 42010), -- Items of Utmost Importance
(29410, 1, 0, 1380, 3217, 84, 42010), -- 29410
(29410, 0, 0, 1201, 3508, 86, 42010), -- 29410
(29409, 2, 0, 1445, 3385, 84, 42010), -- 29409
(29409, 1, 0, 1381, 3169, 137, 42010), -- 29409
(29409, 0, 0, 1380, 3217, 181, 42010), -- 29409
(29408, 3, 0, 1445, 3385, 84, 42010), -- 29408
(29408, 2, 0, 1422, 3377, 192, 42010), -- 29408
(29408, 1, 0, 1442, 3388, 181, 42010), -- 29408
(29408, 0, 0, 1445, 3385, 180, 42010), -- 29408
(29524, 2, 0, 1445, 3385, 84, 42010), -- 29524
(29524, 1, 11, 1336, 3277, 136, 42010), -- 29524
(29524, 1, 10, 1334, 3279, 135, 42010), -- 29524
(29524, 1, 9, 1306, 3353, 134, 42010), -- 29524
(29524, 1, 8, 1362, 3399, 128, 42010), -- 29524
(29524, 1, 7, 1436, 3389, 184, 42010), -- 29524
(29524, 1, 6, 1439, 3388, 184, 42010), -- 29524
(29524, 1, 5, 1457, 3381, 184, 42010), -- 29524
(29524, 1, 4, 1458, 3378, 184, 42010), -- 29524
(29524, 1, 3, 1462, 3294, 139, 42010), -- 29524
(29524, 1, 2, 1442, 3246, 136, 42010), -- 29524
(29524, 1, 1, 1427, 3229, 134, 42010), -- 29524
(29524, 1, 0, 1424, 3228, 134, 42010), -- 29524
(29524, 0, 0, 1445, 3385, 181, 42010), -- 29524
(29406, 2, 0, 1462, 3466, 84, 42010), -- 29406
(29406, 1, 11, 1439, 3413, 171, 42010), -- 29406
(29406, 1, 10, 1434, 3421, 171, 42010), -- 29406
(29406, 1, 9, 1433, 3423, 171, 42010), -- 29406
(29406, 1, 8, 1481, 3448, 171, 42010), -- 29406
(29406, 1, 7, 1484, 3448, 171, 42010), -- 29406
(29406, 1, 6, 1491, 3445, 171, 42010), -- 29406
(29406, 1, 5, 1494, 3439, 171, 42010), -- 29406
(29406, 1, 4, 1496, 3429, 171, 42010), -- 29406
(29406, 1, 3, 1494, 3419, 171, 42010), -- 29406
(29406, 1, 2, 1493, 3416, 171, 42010), -- 29406
(29406, 1, 1, 1471, 3400, 171, 42010), -- 29406
(29406, 1, 0, 1468, 3400, 171, 42010), -- 29406
(29406, 0, 0, 1463, 3468, 181, 42010), -- 29406
(30027, 3, 0, 1462, 3466, 84, 42010), -- 30027
(30027, 2, 5, 1430, 3429, 170, 42010), -- 30027
(30027, 2, 4, 1421, 3457, 170, 42010), -- 30027
(30027, 2, 3, 1436, 3461, 170, 42010), -- 30027
(30027, 2, 2, 1488, 3450, 170, 42010), -- 30027
(30027, 2, 1, 1495, 3412, 170, 42010), -- 30027
(30027, 2, 0, 1478, 3398, 170, 42010), -- 30027
(30027, 1, 11, 1447, 3415, 170, 42010), -- 30027
(30027, 1, 10, 1429, 3426, 170, 42010), -- 30027
(30027, 1, 9, 1423, 3439, 170, 42010), -- 30027
(30027, 1, 8, 1425, 3457, 170, 42010), -- 30027
(30027, 1, 7, 1440, 3461, 170, 42010), -- 30027
(30027, 1, 6, 1451, 3461, 170, 42010), -- 30027
(30027, 1, 5, 1467, 3457, 170, 42010), -- 30027
(30027, 1, 4, 1478, 3450, 170, 42010), -- 30027
(30027, 1, 3, 1489, 3437, 170, 42010), -- 30027
(30027, 1, 2, 1489, 3417, 170, 42010), -- 30027
(30027, 1, 1, 1482, 3410, 170, 42010), -- 30027
(30027, 1, 0, 1462, 3408, 170, 42010), -- 30027
(30027, 0, 0, 1463, 3468, 181, 42010), -- 30027
(30037, 5, 0, 1462, 3466, 84, 42010), -- 30037
(30037, 4, 5, 1430, 3429, 170, 42010), -- 30037
(30037, 4, 4, 1421, 3457, 170, 42010), -- 30037
(30037, 4, 3, 1436, 3461, 170, 42010), -- 30037
(30037, 4, 2, 1488, 3450, 170, 42010), -- 30037
(30037, 4, 1, 1495, 3412, 170, 42010), -- 30037
(30037, 4, 0, 1478, 3398, 170, 42010), -- 30037
(30037, 3, 5, 1430, 3429, 170, 42010), -- 30037
(30037, 3, 4, 1421, 3457, 170, 42010), -- 30037
(30037, 3, 3, 1436, 3461, 170, 42010), -- 30037
(30037, 3, 2, 1488, 3450, 170, 42010), -- 30037
(30037, 3, 1, 1495, 3412, 170, 42010), -- 30037
(30037, 3, 0, 1478, 3398, 170, 42010), -- 30037
(30037, 2, 11, 1451, 3408, 170, 42010), -- 30037
(30037, 2, 10, 1436, 3419, 170, 42010), -- 30037
(30037, 2, 9, 1423, 3432, 170, 42010), -- 30037
(30037, 2, 8, 1423, 3443, 170, 42010), -- 30037
(30037, 2, 7, 1429, 3459, 170, 42010), -- 30037
(30037, 2, 6, 1443, 3461, 170, 42010), -- 30037
(30037, 2, 5, 1464, 3461, 170, 42010), -- 30037
(30037, 2, 4, 1473, 3457, 170, 42010), -- 30037
(30037, 2, 3, 1486, 3443, 170, 42010), -- 30037
(30037, 2, 2, 1491, 3424, 170, 42010), -- 30037
(30037, 2, 1, 1489, 3410, 170, 42010), -- 30037
(30037, 2, 0, 1467, 3404, 170, 42010), -- 30037
(30037, 1, 11, 1460, 3417, 170, 42010), -- 30037
(30037, 1, 10, 1434, 3435, 170, 42010), -- 30037
(30037, 1, 9, 1423, 3443, 170, 42010), -- 30037
(30037, 1, 8, 1429, 3459, 170, 42010), -- 30037
(30037, 1, 7, 1438, 3461, 170, 42010), -- 30037
(30037, 1, 6, 1451, 3461, 170, 42010), -- 30037
(30037, 1, 5, 1464, 3461, 170, 42010), -- 30037
(30037, 1, 4, 1478, 3448, 170, 42010), -- 30037
(30037, 1, 3, 1489, 3437, 170, 42010), -- 30037
(30037, 1, 2, 1493, 3428, 170, 42010), -- 30037
(30037, 1, 1, 1489, 3415, 170, 42010), -- 30037
(30037, 1, 0, 1473, 3410, 170, 42010), -- 30037
(30037, 0, 0, 1463, 3468, 181, 42010); -- 30037

DELETE FROM `quest_details` WHERE `ID` IN (29410, 29414, 29424, 29409, 29408, 29406, 30027, 30033, 30034, 30035, 30036, 30037, 30038, 29524, 29522, 29419, 29678, 29666, 29677, 29676, 29662, 29663, 29661, 29521, 29423, 29422, 29421, 29664, 29420, 29523, 29418, 29417);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(29410, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29410 - Aysa of the Tushui
(29409, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29409 - The Disciple's Challenge
(29408, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29408 - The Lesson Burning Scroll
(29406, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29406 - The Lesson of the Sandy Fist
(30027, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30027 - The Lesson of the Iron Bough
(30033, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30033
(30034, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30034
(30035, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30035
(30036, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30036
(30037, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30037
(30038, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 30038
(29524, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29524 - The Lesson of Stifled Pride
(29522, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29522 - Ji of the Huojin
(29414, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29414 - The Way of the Tushui
(29424, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29424 - Items of Utmost Importance
(29419, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- 29419 - The Missing Driver
(29678, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Shu, the Spirit of Water
(29666, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Sting of Learning
(29677, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Sun Pearl
(29676, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Finding an Old Friend
(29662, 0, 0, 0, 0, 0, 0, 0, 0, 42010), -- Stronger Than Reeds
(29663, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Lesson of the Balanced Rock
(29661, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Lesson of Dry Fur
(29521, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Singing Pools
(29423, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Passion of Shen-zin Su
(29422, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Huo, the Spirit of Fire
(29421, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Only the Worthy Shall Pass
(29664, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Challenger's Fires
(29420, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- The Spirit's Guardian
(29523, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Fanning the Flames
(29418, 1, 0, 0, 0, 0, 0, 0, 0, 42010), -- Kindling the Fire
(29417, 1, 0, 0, 0, 0, 0, 0, 0, 42010); -- The Way of the Huojin

DELETE FROM `quest_template` WHERE `ID` IN (30037, 29410, 29409, 29408, 29524, 29406, 30027, 29522, 29414, 29424, 29419, 46736, 46735, 46277);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestPackageID`, `ContentTuningID`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitGiverModelSceneID`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `ManagedWorldStateID`, `QuestSessionBonus`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(29410, 2, 0, 80, 5736, 0, 0, 0, 2, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 18350080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'Aysa of the Tushui', 'Speak to Merchant Lorvo by Fu\'s Pond.', 'In such a short time, you\'ve shown me that you have the potential to be a great $c. The training grounds are behind you, but now you must prove yourself by facing a far greater challenge, one that none of my students have accomplished.$B$BI want you to return Huo, the spirit of fire, to the Temple of Five Dawns.$B$BMy two other most gifted students will help you in this task. The first is Aysa Cloudsinger. Seek her out at the pool to the west.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 29410
(29409, 2, 70, 80, 5736, 21, 0, 29410, 7, 1, 7, 1, 60, 0, 0, 0, 0, 0, 1, 0, 135790592, 0, 0, 0, 0, 39755, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'The Disciple\'s Challenge', 'Defeat Jaomin Ro.', '$n, I see great strength and great courage in you, and an unsurpassed purity of soul.$B$BThe hour is young, but I think you may be ready to face a greater challenge.$B$BGo to the bottom of the stairs, and cross the bridge. There, you will find Jaomin Ro, one of our eldest students. Challenge and defeat him in honorable combat, and this first phase of your training will be complete.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', 'Jaomin Ro', '', '', 890, 878, 42010), -- 29409
(29408, 2, 0, 80, 5736, 21, 0, 29409, 5, 1, 5, 1, 30, 0, 0, 0, 80212, 0, 1, 0, 1572864, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80212, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'The Lesson of the Burning Scroll', 'Snatch the flame from Master Shang Xi\'s palm, then burn the Edict of Temperance.', 'Every wisdom has a time and place, and times are changing for those of us living here on Shen-zin Su. For this lesson, I would ask two things of you.$B$BFor the first, I hold a flame in my hand. Gather your wits, and when you think you are ready, attempt to snatch the flame.$B$BShould you succeed, I want you to then climb to the top of this temple and burn the Edict of Temperance that you find there.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 29408
(29524, 2, 69, 80, 5736, 21, 0, 29408, 7, 1, 7, 1, 30, 93425, 0, 0, 0, 0, 1, 0, 3670016, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'The Lesson of Stifled Pride', 'Defeat 6 Huojin Trainees or Tushui Trainees.', 'Facing a living opponent is a very different thing from the stationary targets in the yard. Living opponents strike back. There is the very real fear of failure, and sometimes, even death.$B$BYou must have the courage to overcome those fears.$B$BChallenge the other trainees within the temple or down the steps below, and defeat them.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 29524
(29406, 2, 63, 80, 5736, 21, 0, 29524, 7, 1, 7, 1, 30, 107032, 0, 0, 0, 0, 1, 0, 2621440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'The Lesson of the Sandy Fist', 'Destroy 5 Training Targets.', 'I\'d like to observe you putting your new weapon to use, my young student. This will aid me in determining what degree of training will be best suited to your talents.$B$BWe have many training targets in the training grounds below. Practice your attacks upon them, and return to me once you\'re feeling comfortable with your new weapon.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 29406
(30037, 2, 0, 80, 5736, 21, 0, 29406, 5, 1, 5, 1, 0, 0, 0, 0, 0, 0, 1, 0, 524288, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73213, 76391, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'The Lesson of the Iron Bough', 'Retrieve and equip a Trainee\'s Axe and a Trainee\'s Shield.', 'First, you will need weapons suited to your talents. Retrieve an axe and a shield from one of the weapon racks below, bring them to me, and show me that you know how to hold them properly.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 30037
(30027, 2, 0, 80, 5736, 21, 0, 29406, 5, 1, 5, 1, 0, 0, 0, 0, 0, 0, 1, 0, 524288, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 73209, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'The Lesson of the Iron Bough', 'Retrieve and equip a Trainee\'s Staff.', 'First, you will need a weapon suited to your talents. Retrieve a staff from one of the weapon racks below, bring it to me, and show me that you know how to equip it properly.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 30027
(29522, 2, 0, 80, 5736, 0, 0, 29417, 2, 1, 2, 1, 0, 0, 0, 0, 0, 0, 1, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'Ji of the Huojin', 'Speak to Ji Firepaw in Wu-Song Village.', 'Another of my most talented students is awaiting you in Wu-Song Village to the northwest. He is of a different mind than Aysa, but in their differences, they bring balance to each other.$B$BJi Firepaw will instruct you on gathering the offerings for the spirit of fire. Trust in his wisdom.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 29522
(29414, 2, 72, 80, 5736, 0, 0, 29522, 5, 1, 5, 1, 30, 0, 0, 0, 0, 0, 1, 0, 1048576, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'The Way of the Tushui', 'Protect Aysa while she meditates.', 'It\'s a pleasure to meet you, $c. I am Aysa, of the Tushui.$B$BI\'ve spent much time in thought since Master Shang told me we would be searching for Huo, the spirit of fire. I know where he resides, but not how to reach him. The answers are close, however.$B$BCome with me to the Cave of Meditation nearby. It is a place of great wisdom. I will meditate there, open my mind, and the path shall find us.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 29414
(29419, 2, 0, 80, 5736, 0, 0, 0, 5, 1, 5, 1, 30, 0, 0, 0, 0, 0, 1, 0, 524288, 0, 0, 0, 0, 0, 0, 0, 0, 73223, 73241, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'The Missing Driver', 'Rescue the Cart Driver.', 'My driver went running off after the sprites just after they attacked. I don\'t think they\'ll really do him any harm, but I need him back to help me clean up the mess by the cart.$B$BHe chased them off towards the cliffs to the north. If you head that direction, you should find him quickly.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 29419
(29424, 2, 0, 80, 5736, 0, 0, 0, 5, 1, 5, 1, 30, 0, 0, 0, 0, 0, 1, 0, 524288, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1216, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 58720256, 0, 4, 0, 0, 'Items of Utmost Importance', 'Recover 6 Training Supplies from Amberleaf Scamps.', 'Amberleaf scamps swarmed my cart and stole most of the training supplies I was bringing up to the training grounds. They\'ve always been troublemakers, but they\'ve never been this aggressive before. I don\'t know what happened.$B$BPlease, help me recover my supplies.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 42010), -- 29424
(46736, 0, 0, 336, 0, 143, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 100728840, 33554432, 0, 0, 0, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 6, 0, 0, 'Contribute to Nether Disruptor', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 42010), -- 46736
(46735, 0, 0, 336, 0, 143, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 100728840, 33554432, 0, 0, 0, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 6, 0, 0, 'Contribute to Command Center', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 42010), -- 46735
(46277, 0, 0, 336, 0, 143, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 100729096, 33554432, 0, 0, 0, 0, 0, 0, 0, 152654, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2045, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 18446744073709551615, 0, 6, 0, 0, 'Contribute to Mage Tower', '', '', '', '', 1226, 0, 0, 0, 75, 0, 0, 0, '', '', '', '', 0, 0, 42010); -- 46277

UPDATE `quest_template` SET `RewardBonusMoney`=90, `VerifiedBuild`=43206 WHERE `ID`=29410; -- Aysa of the Tushui
UPDATE `quest_template` SET `RewardBonusMoney`=420, `Flags`=1572864, `VerifiedBuild`=43206 WHERE `ID`=29409; -- The Disciple's Challenge
UPDATE `quest_template` SET `RewardBonusMoney`=270, `VerifiedBuild`=43206 WHERE `ID`=29408; -- The Lesson of the Burning Scroll
UPDATE `quest_template` SET `RewardBonusMoney`=300, `VerifiedBuild`=43206 WHERE `ID`=29524; -- The Lesson of Stifled Pride
UPDATE `quest_template` SET `RewardBonusMoney`=180, `VerifiedBuild`=43206 WHERE `ID`=29406; -- The Lesson of the Sandy Fist
UPDATE `quest_template` SET `RewardBonusMoney`=120, `VerifiedBuild`=43206 WHERE `ID`=30027; -- The Lesson of the Iron Bough
UPDATE `quest_template` SET `VerifiedBuild`=43206 WHERE `ID` IN (46736, 46735, 46277);

DELETE FROM `quest_objectives` WHERE `ID` IN (252015, 252376, 252090, 253782, 253783, 252375 /*252375*/, 252345 /*252345*/, 252344 /*252344*/, 254896 /*254896*/, 252339 /*252339*/, 253214 /*253214*/, 289536 /*289536*/, 289535 /*289535*/, 289167 /*289167*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(252375, 29409, 0, 0, 0, 54611, 1, 1, 0, 0, 'Defeat Jaomin Ro', 42010), -- 252375
(252345, 29408, 0, 1, 1, 59570, 1, 0, 0, 0, 'Burn the Edict of Temperance', 42010), -- 252345
(252344, 29408, 0, 0, 0, 59591, 1, 0, 0, 0, 'Snatch the Master\'s Flame', 42010), -- 252344
(254896, 29524, 0, 0, 0, 54586, 6, 0, 0, 0, 'Sparring Trainees defeated', 42010), -- 254896
(252339, 29406, 0, 0, 0, 53714, 5, 0, 0, 0, 'Training Targets destroyed', 42010), -- 252339
(253214, 30027, 0, 0, 0, 54139, 1, 0, 0, 0, 'Loot and Equip a Trainee\'s Staff', 42010), -- 253214
(253783, 30037, 0, 1, 1, 57849, 1, 0, 0, 0, 'Loot and Equip a Trainee\'s Shield', 42010), -- 253783
(253782, 30037, 0, 0, 0, 54139, 1, 0, 0, 0, 'Loot and Equip a Trainee\'s Axe', 42010), -- 253782
(289536, 46736, 4, 0, -1, 1342, 100, 0, 0, 0, '', 42010), -- 289536
(289535, 46735, 4, 0, -1, 1342, 100, 0, 0, 0, '', 42010), -- 289535
(289167, 46277, 4, 0, -1, 1342, 100, 0, 0, 0, '', 42010), -- 289167
(252376, 29414, 0, 0, 0, 54856, 1, 0, 0, 0, 'Protect Aysa while she meditates', 42010), -- 252376
(252090, 29419, 0, 0, 0, 54855, 1, 0, 0, 0, 'Rescue the Cart Driver', 42010), -- 252090
(252015, 29424, 1, 0, 0, 72071, 6, 0, 1, 0, '', 42010); -- 252015

DELETE FROM `quest_objectives` WHERE `ID`=286629; -- Quest 30027 - 2 line is not actualy - DELETED /Text : Loot and Equip a second Trainee's Handwrap /

DELETE FROM `quest_visual_effect` WHERE (`Index`=0 AND `ID` IN (252375, 252345, 252344, 254896, 252090, 252376));
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(252375, 0, 658, 42010),
(252345, 0, 946, 42010),
(252344, 0, 1119, 42010),
(252090, 0, 569, 42010),
(254896, 0, 1052, 42010),
(252376, 0, 1192, 42010);

DELETE FROM `quest_template_addon` WHERE `ID` IN (29406, 29408, 29409, 29410, 29524, 30027, 30033, 30034, 30035, 30036, 30037, 30038, 29406);
INSERT INTO `quest_template_addon` (`ID`, `MaxLevel`, `AllowableClasses`, `SourceSpellID`, `PrevQuestID`, `NextQuestID`, `ExclusiveGroup`, `RewardMailTemplateID`, `RewardMailDelay`, `RequiredSkillID`, `RequiredSkillPoints`, `RequiredMinRepFaction`, `RequiredMaxRepFaction`, `RequiredMinRepValue`, `RequiredMaxRepValue`, `ProvidedItemCount`, `SpecialFlags`, `ScriptName`) VALUES
(30027, 0, 512, 0, 0, 29406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of the Iron Bough - Monk
(30033, 0, 128, 0, 0, 29406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of the Iron Bough - Mage
(30034, 0, 4, 0, 0, 29406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of the Iron Bough - Hunter
(30035, 0, 16, 0, 0, 29406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of the Iron Bough - Priest
(30036, 0, 8, 0, 0, 29406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of the Iron Bough - Rogue
(30037, 0, 64, 0, 0, 29406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of the Iron Bough - Shaman
(30038, 0, 1, 0, 0, 29406, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of the Iron Bough - Warrior
(29406, 0, 0, 0, 0, 29524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of the Sandy Fist
(29524, 0, 0, 0, 29406, 29408, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Lesson of Stifled Pride
(29408, 0, 0, 0, 29524, 29409, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, ''), -- The Lesson of the Burning Scroll
(29409, 0, 0, 0, 29408, 29410, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- The Disciple's Challenge
(29410, 0, 0, 0, 29409, 29424, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Aysa of the Tushui

DELETE FROM `page_text` WHERE `ID` IN (4610 /*4610*/, 4605 /*4605*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(4610, '\'Always challenge. Always question. In the pursuit of a greater good, inaction is the only wrong.\' -Master Zurong$b$bThe path of the Huojin is marked by practical and decisive action. Followers of this discipline believe that morals and ideals are not absolute, but change with circumstances.$b$bAs such, a Huojin Master must remain flexible in his or her thinking, always evaluating the greater good.', 0, 0, 0, 42010), -- 4610
(4605, '\'Discipline is not a war that is won. It is a battle, constantly fought.\' -Master Feng$b$bThe way of the Tushui is one of a principled life. Followers of this discipline  believe there is a moral certainty to the world: one correct path of right and wrong.$b$bThese values are immutable, and must be preserved no matter what the cost, even if it means self-sacrifice, or painful losses in the pursuit of a higher ideal.', 0, 0, 0, 42010); -- 4605

UPDATE `npc_text` SET `VerifiedBuild`=42010 WHERE `ID` IN (18715, 18310, 18927, 18340, 20778);

DELETE FROM `playercreateinfo_action` WHERE (`race`=24 AND `class`=10 AND `button`=9);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(24, 10, 9, 107079, 0); -- Quaking Palm

DELETE FROM `gossip_menu` WHERE (`MenuID`=13037 AND `TextID`=18310) OR (`MenuID`=13060 AND `TextID` IN (18715,18927,18340)) OR (`MenuID`=14672 AND `TextID`=20778) OR (`MenuID`=14491 AND `TextID` IN (20491,20490)) OR (`MenuID`=13102 AND `TextID`=18401) OR (`MenuID`=15125 AND `TextID`=17125) OR (`MenuID`=14674 AND `TextID`=20787) OR (`MenuID`=13050 AND `TextID`=18327) OR (`MenuID`=13038 AND `TextID`=18311) OR (`MenuID`=14616 AND `TextID`=20677) OR (`MenuID`=13346 AND `TextID`=18919);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(13037, 18310, 42010), -- 54567 (Aysa Cloudsinger)
(13060, 18715, 42010), -- 54943 (Merchant Lorvo)
(13060, 18927, 42010), -- 54943 (Merchant Lorvo)
(13060, 18340, 42010), -- 54943 (Merchant Lorvo)
(14672, 20778, 42010), -- 54567 (Aysa Cloudsinger)
(14491, 20491, 42010), -- 54975 (Aysa Cloudsinger)
(13102, 18401, 42010), -- 55020 (Old Man Liang)
(14491, 20490, 42010), -- 54975 (Aysa Cloudsinger)
(15125, 17125, 42010), -- 57620 (Whittler Dewei)
(14674, 20787, 42010), -- 57619 (Cheng Dawnscrive)
(13050, 18327, 42010), -- 54135 (Master Li Fei)
(13038, 18311, 42010), -- 54568 (Ji Firepaw)
(14616, 20677, 42010), -- 64929 (Lamplighter Deng)
(13346, 18919, 42010); -- 57754 (Instructor Mossthorn)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=13060 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(13060, 0, 1, 'What do you have for sale?', 10182, 3, 512, 0, 0, 0, 0, 0, NULL, 0, 42010); -- OptionBroadcastTextID: 10182 - 16129 - 16134 - 16135 - 16452 - 20994 - 53758 - 66614 - 117193 - 122305 - 122306

UPDATE `gossip_menu_option` SET `VerifiedBuild`=42010 WHERE (`MenuID`=12186 AND `OptionID` IN (13,15,12,16,17,18,14)) OR (`MenuID`=12188 AND `OptionID` IN (14,15,13,12)) OR (`MenuID`=12191 AND `OptionID` IN (15,14,12,13)) OR (`MenuID`=12185 AND `OptionID` IN (12,13));
UPDATE `gossip_menu_option` SET `VerifiedBuild`=42010 WHERE (`MenuID`=12185 AND `OptionID` IN (11,14)) OR (`MenuID`=12186 AND `OptionID` IN (11,19)) OR (`MenuID`=9821 AND `OptionID`=1);
UPDATE `gossip_menu_option` SET `OptionType`=5, `OptionNpcFlag`=16, `VerifiedBuild`=42010 WHERE (`MenuID`=12191 AND `OptionID`=11);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47112, `OptionType`=5, `OptionNpcFlag`=16, `VerifiedBuild`=42010 WHERE (`OptionID`=4 AND `MenuID` IN (12186,12185,12191));
UPDATE `gossip_menu_option` SET `OptionType`=5, `VerifiedBuild`=42010 WHERE (`MenuID`=12188 AND `OptionID`=11);

DELETE FROM `creature_addon` WHERE `guid` IN (450220, 450266, 450267, 563382, 563383);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450220, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 49414 115865'), -- Master Shang Xi - 108900 - Master Shang Xi's Staff, 49414 - Generic Quest Invisibility 1, 115865 - Cosmetic - Sit Chair High (Lower/Upper Body - High/Low Priority) (Anim Kit)
(450266, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 60921 114600 126160'), -- Master Shang Xi - 108900 - Master Shang Xi's Staff, 60921 - Generic Quest Invisibility 3, 114600 - Master Shang Xi's Offering, 126160 - Master Shang Xi's Staff
(450267, 0, 0, 0, 65536, 1, 0, 0, 0, 0, 0, '108900 82343 126160'), -- Master Shang Xi - 108900 - Master Shang Xi's Staff, 82343 - Generic Quest Invisibility 4; 126160 - Master Shang Xi's Staff
(563382, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''),
(563383, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 108967;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 108967, 0, 0, 31, 0, 3, 53714, 0, 0, 0, 0, '', 'Jab target only Training Target'),
(13, 1, 108967, 0, 1, 31, 0, 3, 57873, 0, 0, 0, 0, '', 'Jab target only Training Target');

-- Quiet Lam
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 57752;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 57752 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(57752, 0, 0, 1, 1, 0, 100, 0, 0, 0, 5000, 5000, 10, 507, 509, 511, 543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Quiet Lam - OOC - Play Random Emote (507, 509, 511, 543)'),
(57752, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Quiet Lam - Play Random Sound (33643, 33645, 33646)');

-- Ironfist Zhou
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 57753;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 57753 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(57753, 0, 0, 1, 1, 0, 100, 0, 0, 0, 5000, 5000, 10, 507, 509, 511, 543, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironfist Zhou - OOC - Play Random Emote (507, 509, 511, 543)'),
(57753, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33643, 33645, 33646, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Ironfist Zhou - Play Random Sound (33643, 33645, 33646)');

-- Instructor Zhi smart ai
SET @ENTRY := 61411;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 4000, 4000, 19000, 19000, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 19 seconds (4s initially) (OOC) - Self: Play emote 509'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 54587, 0, 15, 0, 0, 0, 0, 'Every 19 seconds (4s initially) (OOC) - Creature Tushui Trainee (54587) in 0 - 15 yards: Set creature data #1 to 1'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 9, 65471, 0, 15, 0, 0, 0, 0, 'Every 19 seconds (4s initially) (OOC) - Creature Tushui Trainee (65471) in 0 - 15 yards: Set creature data #1 to 1'),
(@ENTRY, 0, 3, 4, 1, 0, 100, 0, 9000, 9000, 19000, 19000, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 19 seconds (9s initially) (OOC) - Self: Play emote 543'),
(@ENTRY, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 9, 54587, 0, 15, 0, 0, 0, 0, 'Every 19 seconds (9s initially) (OOC) - Creature Tushui Trainee (54587) in 0 - 15 yards: Set creature data #1 to 2'),
(@ENTRY, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 2, 0, 0, 0, 0, 9, 65471, 0, 15, 0, 0, 0, 0, 'Every 19 seconds (9s initially) (OOC) - Creature Tushui Trainee (65471) in 0 - 15 yards: Set creature data #1 to 2'),
(@ENTRY, 0, 6, 7, 1, 0, 100, 0, 14000, 14000, 19000, 19000, 5, 511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 19 seconds (14s initially) (OOC) - Self: Play emote 511'),
(@ENTRY, 0, 7, 8, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 3, 0, 0, 0, 0, 9, 54587, 0, 15, 0, 0, 0, 0, 'Every 19 seconds (14s initially) (OOC) - Creature Tushui Trainee (54587) in 0 - 15 yards: Set creature data #1 to 3'),
(@ENTRY, 0, 8, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 3, 0, 0, 0, 0, 9, 65471, 0, 15, 0, 0, 0, 0, 'Every 19 seconds (14s initially) (OOC) - Creature Tushui Trainee (65471) in 0 - 15 yards: Set creature data #1 to 3'),
(@ENTRY, 0, 9, 10, 1, 0, 100, 0, 19000, 19000, 19000, 19000, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 19 seconds (OOC) - Self: Play emote 507'),
(@ENTRY, 0, 10, 11, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 4, 0, 0, 0, 0, 9, 54587, 0, 15, 0, 0, 0, 0, 'Every 19 seconds (OOC) - Creature Tushui Trainee (54587) in 0 - 15 yards: Set creature data #1 to 4'),
(@ENTRY, 0, 11, 0, 61, 0, 100, 0, 0, 0, 0, 0, 45, 1, 4, 0, 0, 0, 0, 9, 65471, 0, 15, 0, 0, 0, 0, 'Every 19 seconds (OOC) - Creature Tushui Trainee (65471) in 0 - 15 yards: Set creature data #1 to 4');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 61411 AND `SourceId` = 0;

-- Instructor Qun smart ai
SET @ENTRY := 57748;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (5774800);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 19000, 19000, 19000, 20000, 80, 5774800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 19 - 20 seconds (19 - 19s initially) (OOC) - Self: Start timed action list id #5774800 (update out of combat) // -inline'),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 1000, 3000, 0, 0, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 - 3 seconds - Self: Play emote 509'),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 5, 509, 0, 0, 0, 0, 0, 11, 53565, 15, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Creature Aspiring Trainee (53565) in 15 yd: Play emote 509'),
(@ENTRY * 100, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 509, 0, 0, 0, 0, 0, 11, 65469, 15, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Aspiring Trainee (65469) in 15 yd: Play emote 509'),
(@ENTRY * 100, 9, 3, 0, 0, 0, 100, 0, 100, 100, 0, 0, 115, 33646, 33645, 33646, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Play random direct sound one of: 33646, 33645, 33646, 33646 of all'),
(@ENTRY * 100, 9, 4, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Play emote 543'),
(@ENTRY * 100, 9, 5, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 5, 543, 0, 0, 0, 0, 0, 11, 53565, 15, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Creature Aspiring Trainee (53565) in 15 yd: Play emote 543'),
(@ENTRY * 100, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 543, 0, 0, 0, 0, 0, 11, 65469, 15, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Aspiring Trainee (65469) in 15 yd: Play emote 543'),
(@ENTRY * 100, 9, 7, 0, 0, 0, 100, 0, 100, 100, 0, 0, 115, 33646, 33643, 33646, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Play random direct sound one of: 33646, 33643, 33646, 33646 of all'),
(@ENTRY * 100, 9, 8, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Play emote 511'),
(@ENTRY * 100, 9, 9, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 5, 511, 0, 0, 0, 0, 0, 11, 53565, 15, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Creature Aspiring Trainee (53565) in 15 yd: Play emote 511'),
(@ENTRY * 100, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 511, 0, 0, 0, 0, 0, 11, 65469, 15, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Aspiring Trainee (65469) in 15 yd: Play emote 511'),
(@ENTRY * 100, 9, 11, 0, 0, 0, 100, 0, 100, 100, 0, 0, 115, 33646, 33645, 33646, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Play random direct sound one of: 33646, 33645, 33646, 33646 of all'),
(@ENTRY * 100, 9, 12, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6 seconds - Self: Play emote 507'),
(@ENTRY * 100, 9, 13, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 5, 507, 0, 0, 0, 0, 0, 11, 53565, 15, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Creature Aspiring Trainee (53565) in 15 yd: Play emote 507'),
(@ENTRY * 100, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 507, 0, 0, 0, 0, 0, 11, 65469, 15, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Aspiring Trainee (65469) in 15 yd: Play emote 507'),
(@ENTRY * 100, 9, 15, 0, 0, 0, 100, 0, 100, 100, 0, 0, 115, 33646, 33646, 33643, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0.1 seconds - Self: Play random direct sound one of: 33646, 33646, 33643, 33646 of all');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 57748 AND `SourceId` = 0;


-- Aspiring Trainee with guid 450192 smart ai
SET @ENTRY := -450192;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (45019200);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 53565;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 85000, 95000, 85000, 95000, 1, 1, 0, 0, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'Every 85 - 95 seconds (OOC) - Closest alive creature Aspiring Trainee (53565) in 3 yards: Talk My money\'s on Lam. Did you see him take down Chu during trai... (1) to invoker'),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 45019200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 85 - 95 seconds (OOC) - Self: Start timed action list id #45019200 (update out of combat) // -inline'),
(45019200, 9, 0, 0, 0, 0, 100, 0, 2000, 3000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 2 - 3 seconds - Closest alive creature Aspiring Trainee (53565) in 3 yards: Talk His stamina is nothing against Lam\'s strength. (2) to invoker'),
(45019200, 9, 1, 0, 0, 0, 100, 0, 4000, 5000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 4 - 5 seconds - Closest alive creature Aspiring Trainee (53565) in 3 yards: Talk He has the legs of an ox! Have you ever been kicked by him i... (3) to invoker'),
(45019200, 9, 2, 0, 0, 0, 100, 0, 1000, 2000, 0, 0, 1, 4, 0, 1, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 1 - 2 seconds - Self: Talk 4 to Closest alive creature Aspiring Trainee (53565) in 3 yards'),
(45019200, 9, 3, 0, 0, 0, 100, 0, 5000, 6000, 0, 0, 1, 5, 0, 0, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 5 - 6 seconds - Closest alive creature Aspiring Trainee (53565) in 3 yards: Talk That\'s where you\'re mistaken, friend. Zhou is as sturdy as an oak. (5) to invoker'),
(45019200, 9, 4, 0, 0, 0, 100, 0, 7000, 8000, 0, 0, 1, 6, 0, 1, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 7 - 8 seconds - Self: Talk 6 to Closest alive creature Aspiring Trainee (53565) in 3 yards'),
(45019200, 9, 5, 0, 0, 0, 100, 0, 8000, 9000, 0, 0, 1, 7, 0, 1, 0, 0, 0, 19, 53565, 3, 0, 0, 0, 0, 0, 'After 8 - 9 seconds - Self: Talk 7 to Closest alive creature Aspiring Trainee (53565) in 3 yards');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = -450192 AND `SourceId` = 0;

-- Huojin Trainee smart ai
SET @ENTRY := 54586;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 5000, 5000, 6000, 7000, 10, 509, 543, 511, 507, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (5 - 5s initially) (OOC) - Self: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 10, 509, 543, 511, 507, 0, 0, 19, 65470, 300, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (5 - 5s initially) (OOC) - Closest alive creature Huojin Trainee (65470) in 300 yards: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33646, 33643, 33645, 33646, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (5 - 5s initially) (OOC) - Self: Play random direct sound one of: 33646, 33643, 33645, 33646 of all');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 54586 AND `SourceId` = 0;

-- Huojin Trainee with guid 450130 smart ai
SET @ENTRY := -450130;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 65470;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 5000, 5000, 5000, 6000, 10, 509, 543, 511, 507, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds (5 - 5s initially) (OOC) - Self: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 10, 509, 543, 511, 507, 0, 0, 11, 65470, 300, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds (5 - 5s initially) (OOC) - Creature Huojin Trainee (65470) in 2 yd: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33646, 33643, 33645, 33643, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds (5 - 5s initially) (OOC) - Self: Play random direct sound one of: 33646, 33643, 33645, 33643 of all');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = -450130 AND `SourceId` = 0;

-- Huojin Trainee with guid 450137 smart ai
SET @ENTRY := -450137;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 65470;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 5000, 5000, 6000, 7000, 10, 509, 543, 511, 507, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (5 - 5s initially) (OOC) - Self: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 10, 509, 543, 511, 507, 0, 0, 11, 65470, 300, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (5 - 5s initially) (OOC) - Creature Huojin Trainee (65470) in 2 yd: Play random emote: 509, 543, 511, 507,'),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 115, 33646, 33643, 33645, 33643, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (5 - 5s initially) (OOC) - Self: Play random direct sound one of: 33646, 33643, 33645, 33643 of all');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = -450137 AND `SourceId` = 0;

-- Tushui Trainee with guid 450123 smart ai
SET @ENTRY := -450123;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (45012300);
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 54587;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 6000, 7000, 6000, 7000, 80, 45012300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 6 - 7 seconds (OOC) - Self: Start timed action list id #45012300 (update out of combat) // -inline'),
(45012300, 9, 0, 0, 0, 0, 100, 0, 3000, 5000, 0, 0, 5, 509, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 - 5 seconds - Self: Play emote 509'),
(45012300, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 509, 0, 0, 0, 0, 0, 9, 54587, 0, 10, 0, 0, 0, 0, 'After 0 seconds - Creature Tushui Trainee (54587) in 0 - 10 yards: Play emote 509'),
(45012300, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 509, 0, 0, 0, 0, 0, 9, 65471, 0, 10, 0, 0, 0, 0, 'After 0 seconds - Creature Tushui Trainee (65471) in 0 - 10 yards: Play emote 509'),
(45012300, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 33646, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play direct sound 33646 to Self'),
(45012300, 9, 4, 0, 0, 0, 100, 0, 3000, 5000, 0, 0, 5, 543, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 - 5 seconds - Self: Play emote 543'),
(45012300, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 543, 0, 0, 0, 0, 0, 11, 54587, 10, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Tushui Trainee (54587) in 10 yd: Play emote 543'),
(45012300, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 543, 0, 0, 0, 0, 0, 11, 65471, 10, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Tushui Trainee (65471) in 10 yd: Play emote 543'),
(45012300, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 33645, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play direct sound 33645 to Self'),
(45012300, 9, 8, 0, 0, 0, 100, 0, 3000, 5000, 0, 0, 5, 511, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 - 5 seconds - Self: Play emote 511'),
(45012300, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 511, 0, 0, 0, 0, 0, 11, 54587, 10, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Tushui Trainee (54587) in 10 yd: Play emote 511'),
(45012300, 9, 10, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 511, 0, 0, 0, 0, 0, 11, 65471, 10, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Tushui Trainee (65471) in 10 yd: Play emote 511'),
(45012300, 9, 11, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 33643, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play direct sound 33643 to Self'),
(45012300, 9, 12, 0, 0, 0, 100, 0, 3000, 5000, 0, 0, 5, 507, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 - 5 seconds - Self: Play emote 507'),
(45012300, 9, 13, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 507, 0, 0, 0, 0, 0, 11, 54587, 10, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Tushui Trainee (54587) in 10 yd: Play emote 507'),
(45012300, 9, 14, 0, 0, 0, 100, 0, 0, 0, 0, 0, 5, 507, 0, 0, 0, 0, 0, 11, 65471, 10, 0, 0, 0, 0, 0, 'After 0 seconds - Creature Tushui Trainee (65471) in 10 yd: Play emote 507'),
(45012300, 9, 15, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 33646, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play direct sound 33646 to Self');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = -450123 AND `SourceId` = 0;

DELETE FROM `vehicle_template_accessory` WHERE `entry` =56739; 
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(56739, 54131, 0, 0, 'Hozen Hanging Bunny - Fe-Feng Hozen', 0, 0); -- Hozen Hanging Bunny - Fe-Feng Hozen

UPDATE `playercreateinfo` SET `orientation` = 2.87962 WHERE `race` = 24;

UPDATE `quest_offer_reward` SET `VerifiedBuild`=43345 WHERE `ID` IN (29419, 29424, 29410, 29409, 29408, 29524, 29406, 30027);
UPDATE `quest_details` SET `VerifiedBuild`=43345 WHERE `ID` IN (29414, 29419, 29424, 29410, 29409, 29408, 29524, 29406, 30027);

DELETE FROM `quest_request_items` WHERE `ID` IN (29409 /*The Disciple's Challenge*/, 29408 /*The Lesson of the Burning Scroll*/, 30027 /*The Lesson of the Iron Bough*/, 29406 /*The Lesson of the Sandy Fist*/, 29524 /*The Lesson of Stifled Pride*/, 29419 /*The Missing Driver*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29409, 0, 1, 0, 0, 'Our greatest glory is not in never falling, but in getting up every time we do. Jaomin Ro knows this. He finds strength in every defeat.$B$BYou may yet learn that lesson.', 43345), -- The Disciple's Challenge
(29408, 0, 1, 0, 0, 'There will come time when you must trust your instincts and simply act.', 43345), -- The Lesson of the Burning Scroll
(30027, 0, 1, 0, 0, 'Picking up your first weapon is also a symbolic gesture. Every $c that leaves these training grounds must be ready to take up arms in defense of their fellow pandaren.', 43345), -- The Lesson of the Iron Bough
(29406, 0, 1, 0, 0, 'The training targets are just down the hill. Come back to me once you\'re finished.', 43345), -- The Lesson of the Sandy Fist
(29524, 0, 1, 0, 0, 'There is a time for meditation and contemplation, and there is a time for action. Diving the balance between the two is one of the greatest wisdoms we seek.', 43345), -- The Lesson of Stifled Pride
(29419, 0, 0, 0, 0, 'I should have been more careful. ', 43345); -- The Missing Driver

UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=43345 WHERE `ID`=29424; -- Items of Utmost Importance


UPDATE `creature_queststarter` SET `VerifiedBuild`=43345 WHERE (`id`=54567 AND `quest`=29414) OR (`id`=54943 AND `quest` IN (29419,29424)) OR (`id`=53566 AND `quest` IN (29410,29409,29408,29524,29406,30027));
UPDATE `creature_questender` SET `VerifiedBuild`=43345 WHERE (`id`=54943 AND `quest` IN (29419,29424,29410)) OR (`id`=53566 AND `quest` IN (29409,29408,29524,29406,30027));

UPDATE `quest_template` SET `VerifiedBuild`=43345 WHERE `ID` IN (29414, 29419, 29424, 46736, 46735, 46277);
UPDATE `quest_template` SET `RewardBonusMoney`=0, `VerifiedBuild`=43345 WHERE `ID`=29410; -- Aysa of the Tushui
UPDATE `quest_template` SET `RewardBonusMoney`=60, `VerifiedBuild`=43345 WHERE `ID`=29409; -- The Disciple's Challenge
UPDATE `quest_template` SET `RewardBonusMoney`=30, `VerifiedBuild`=43345 WHERE `ID`=29408; -- The Lesson of the Burning Scroll
UPDATE `quest_template` SET `RewardBonusMoney`=30, `VerifiedBuild`=43345 WHERE `ID`=29524; -- The Lesson of Stifled Pride
UPDATE `quest_template` SET `RewardBonusMoney`=30, `VerifiedBuild`=43345 WHERE `ID`=29406; -- The Lesson of the Sandy Fist
UPDATE `quest_template` SET `RewardBonusMoney`=0, `VerifiedBuild`=43345 WHERE `ID`=30027; -- The Lesson of the Iron Bough

UPDATE `quest_objectives` SET `VerifiedBuild`=43345 WHERE `ID` IN (252376, 252090, 252015, 252375, 252345, 252344, 254896, 252339, 253214, 289536, 289535, 289167);
UPDATE `quest_visual_effect` SET `VerifiedBuild`=43345 WHERE (`Index`=0 AND `ID` IN (252376,252090,252375,252345,252344,254896));

UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=56739; -- Hozen Hanging Bunny
UPDATE `creature_template` SET `unit_flags`=33587472 WHERE `entry`=65471; -- Tushui Trainee
UPDATE `creature_template` SET `gossip_menu_id`=13036 WHERE `entry`=53566; -- Master Shang Xi
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=56479; -- Legacy of Liu Lang
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=57769; -- Shen-zin Su
UPDATE `creature_template` SET `type_flags`=1610612740, `VerifiedBuild`=43345 WHERE `entry`=57769; -- Shen-zin Su
UPDATE `creature_template` SET `type_flags`=1610612752, `VerifiedBuild`=43345 WHERE `entry`=56479; -- Legacy of Liu Lang

-- Lamplighter Deng
SET @CGUID := 450060;
SET @PATH := @CGUID * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1278.505, 3498.188, 99.14166, 0, 0),
(@PATH, 1, 1280.545, 3488.463, 101.5287, 0, 0),
(@PATH, 2, 1281.075, 3477.09, 103.3935, 0, 0),
(@PATH, 3, 1281.365, 3467.771, 105.2131, 0, 0),
(@PATH, 4, 1284.563, 3461.186, 107.261, 0, 0),
(@PATH, 5, 1291.941, 3453.174, 110.9187, 0, 0),
(@PATH, 6, 1299.061, 3447.672, 113.3054, 0, 0),
(@PATH, 7, 1306.16, 3444.22, 115.0709, 0, 0),
(@PATH, 8, 1313.5, 3435.571, 117.8568, 0, 0),
(@PATH, 9, 1320.306, 3426.353, 120.4679, 0, 0),
(@PATH, 10, 1325.852, 3419.412, 121.8415, 0, 0),
(@PATH, 11, 1334.443, 3413.726, 123.3382, 0, 0),
(@PATH, 12, 1340.349, 3403.408, 124.4632, 0, 0),
(@PATH, 13, 1343.692, 3387.768, 125.2127, 0, 0),
(@PATH, 14, 1349.908, 3377.522, 125.5362, 0, 0),
(@PATH, 15, 1352.247, 3365.307, 126.1973, 0, 0),
(@PATH, 16, 1356.806, 3355.382, 126.989, 0, 0),
(@PATH, 17, 1360.295, 3342.948, 127.856, 0, 0),
(@PATH, 18, 1360.443, 3327.919, 129.2744, 0, 0),
(@PATH, 19, 1357.802, 3315.531, 129.8994, 0, 0),
(@PATH, 20, 1354.33, 3306.154, 130.1806, 0, 0),
(@PATH, 21, 1353.304, 3295.28, 130.9628, 0, 0),
(@PATH, 22, 1354.693, 3287.229, 131.0954, 0, 0),
(@PATH, 23, 1361.361, 3277.022, 131.4489, 0, 0),
(@PATH, 24, 1368.481, 3274.202, 131.6809, 0, 0),
(@PATH, 25, 1375.958, 3271.815, 132.3121, 0, 0),
(@PATH, 26, 1370.845, 3273.609, 131.8065, 0, 0),
(@PATH, 27, 1366.512, 3276.056, 131.3748, 0, 0),
(@PATH, 28, 1360.337, 3280.271, 131.3748, 0, 0),
(@PATH, 29, 1356.106, 3285.41, 131.3748, 0, 0),
(@PATH, 30, 1355.467, 3292.224, 131.2139, 0, 0),
(@PATH, 31, 1357.085, 3297.611, 130.7616, 0, 5806),
(@PATH, 32, 1353.778, 3304.517, 130.2744, 0, 0),
(@PATH, 33, 1355.337, 3310.563, 130.1494, 0, 0),
(@PATH, 34, 1357.983, 3317.83, 129.8222, 0, 0),
(@PATH, 35, 1360.304, 3324.479, 129.5733, 0, 0),
(@PATH, 36, 1361.196, 3331.475, 129.1494, 0, 0),
(@PATH, 37, 1360.582, 3339.856, 128.2271, 0, 0),
(@PATH, 38, 1357.241, 3342.743, 127.9493, 0, 6077),
(@PATH, 39, 1360.535, 3351.983, 127.2741, 0, 0),
(@PATH, 40, 1357.108, 3358.502, 126.8627, 0, 0),
(@PATH, 41, 1353.688, 3365.59, 126.3223, 0, 0),
(@PATH, 42, 1351.611, 3371.378, 125.9597, 0, 0),
(@PATH, 43, 1350.67, 3378.942, 125.4627, 0, 0),
(@PATH, 44, 1349.865, 3385.296, 125.2127, 0, 6110),
(@PATH, 45, 1342.198, 3395.269, 124.7178, 0, 0),
(@PATH, 46, 1339.592, 3404.035, 124.4632, 0, 0),
(@PATH, 47, 1335.146, 3413.649, 123.4176, 0, 0),
(@PATH, 48, 1329.754, 3418.934, 122.2499, 0, 0),
(@PATH, 49, 1323.12, 3423.364, 121.0395, 0, 0),
(@PATH, 50, 1318.514, 3425.088, 120.4955, 0, 0),
(@PATH, 51, 1313.938, 3426.073, 120.4435, 0, 5987),
(@PATH, 52, 1310.609, 3438.904, 116.816, 0, 0),
(@PATH, 53, 1304.125, 3446.715, 114.2256, 0, 0),
(@PATH, 54, 1298.807, 3449.3, 112.8712, 0, 0),
(@PATH, 55, 1293.134, 3453.627, 110.9211, 0, 0),
(@PATH, 56, 1289.141, 3459.107, 108.7542, 0, 0),
(@PATH, 57, 1287.535, 3464.891, 106.9646, 0, 6032),
(@PATH, 58, 1271.95, 3460.984, 105.7406, 0, 0),
(@PATH, 59, 1264.576, 3456.448, 105.4586, 0, 0),
(@PATH, 60, 1254.865, 3454.894, 104.3583, 0, 0),
(@PATH, 61, 1248.146, 3456.349, 103.4482, 0, 0),
(@PATH, 62, 1240.349, 3458.153, 102.7333, 0, 5569),
(@PATH, 63, 1249.127, 3454.832, 103.6737, 0, 0),
(@PATH, 64, 1256.859, 3455.244, 104.5521, 0, 0),
(@PATH, 65, 1264.509, 3458.412, 105.2869, 0, 0),
(@PATH, 66, 1272.019, 3462.195, 105.4585, 0, 0),
(@PATH, 67, 1278.932, 3467.925, 104.8682, 0, 0),
(@PATH, 68, 1281.521, 3473.01, 104.0294, 0, 0),
(@PATH, 69, 1281.641, 3478.479, 103.2267, 0, 0),
(@PATH, 70, 1279.991, 3489.906, 101.2307, 0, 0),
(@PATH, 71, 1277.778, 3500.26, 98.66097, 0, 0),
(@PATH, 72, 1273.719, 3503.588, 97.96664, 0, 5916),
(@PATH, 73, 1276.958, 3516.68, 95.31112, 0, 0),
(@PATH, 74, 1276.556, 3522.365, 94.5815, 0, 0),
(@PATH, 75, 1277.517, 3529.936, 93.70272, 0, 0),
(@PATH, 76, 1280.082, 3538.131, 93.59853, 0, 0),
(@PATH, 77, 1281.16, 3542.923, 93.85292, 0, 0),
(@PATH, 78, 1283.165, 3546.595, 93.86806, 0, 6232),
(@PATH, 79, 1280.934, 3554.821, 92.91847, 0, 0),
(@PATH, 80, 1283.958, 3561.626, 92.80116, 0, 0),
(@PATH, 81, 1288.576, 3567.834, 91.9909, 0, 0),
(@PATH, 82, 1293.58, 3576.056, 91.11822, 0, 0),
(@PATH, 83, 1300.774, 3585.501, 90.00536, 0, 0),
(@PATH, 84, 1305.979, 3590.016, 89.57677, 0, 0),
(@PATH, 85, 1307.564, 3594.753, 89.31615, 0, 0),
(@PATH, 86, 1303.825, 3596.184, 89.58666, 0, 10642),
(@PATH, 87, 1300.563, 3586.429, 90.05614, 0, 0),
(@PATH, 88, 1295.785, 3580.472, 90.62579, 0, 0),
(@PATH, 89, 1287.377, 3569.275, 92.05755, 0, 0),
(@PATH, 90, 1283.476, 3561.002, 92.80116, 0, 0),
(@PATH, 91, 1279.932, 3553.407, 93.17616, 0, 0),
(@PATH, 92, 1278.7, 3544.609, 93.67616, 0, 0),
(@PATH, 93, 1277.158, 3533.575, 93.67616, 0, 0),
(@PATH, 94, 1275.061, 3523.377, 94.27975, 0, 0),
(@PATH, 95, 1276.441, 3510.941, 96.07723, 0, 0);

UPDATE `creature` SET `position_x`= 1278.505, `position_y`= 3498.188, `position_z`= 99.14166, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `auras`) VALUES
(@CGUID, @PATH, 1, '126968');

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 64929;
DELETE FROM `smart_scripts` WHERE (`source_type` = 0 AND `entryOrGuid` = 64929) OR (`source_type` = 9 AND `entryOrGuid` IN (6492900, 6492901));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(64929, 0, 0, 0, 34, 0, 100, 0, 2, 31, 0, 0, 80, 6492900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 31 - start Actionlist - to self'),
(64929, 0, 1, 0, 34, 0, 100, 0, 2, 38, 0, 0, 80, 6492900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 38 - start Actionlist - to self'),
(64929, 0, 2, 0, 34, 0, 100, 0, 2, 44, 0, 0, 80, 6492900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 44 - start Actionlist - to self'),
(64929, 0, 3, 0, 34, 0, 100, 0, 2, 51, 0, 0, 80, 6492900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 51 - start Actionlist - to self'),
(64929, 0, 4, 0, 34, 0, 100, 0, 2, 57, 0, 0, 80, 6492900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 57 - start Actionlist - to self'),
(64929, 0, 5, 0, 34, 0, 100, 0, 2, 62, 0, 0, 80, 6492900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 62 - start Actionlist - to self'),
(64929, 0, 6, 0, 34, 0, 100, 0, 2, 72, 0, 0, 80, 6492900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 72 - start Actionlist - to self'),
(64929, 0, 7, 0, 34, 0, 100, 0, 2, 78, 0, 0, 80, 6492900, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 78 - start Actionlist - to self'),
(64929, 0, 8, 0, 34, 0, 100, 0, 2, 86, 0, 0, 80, 6492901, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On MovementInform PointID 86 - start Actionlist - to self'),
-- Actionlist 1
(6492900, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 128, 2704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Play AnimKit 2704 - to self'),
-- Actionlist 2
(6492901, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 5, 16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2s - Set Emote 16 (Kneel) - to self'),
(6492901, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 128, 2704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - Set AnimKit to 2704 - to self'),
(6492901, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 6s - Remove Emote kneel - to self');

-- training dummys
UPDATE `creature` SET `spawntimesecs`=20 WHERE `id`=53714;

-- ref spell 107032 
UPDATE `gameobject_addon` SET `invisibilityType`=30, `invisibilityValue`=1000 WHERE `guid`=300083;
-- ref spell 107027
UPDATE `gameobject_addon` SET `invisibilityType`=28, `invisibilityValue`=1000 WHERE `guid`=300014;

-- trainees
UPDATE `creature_template` SET `unit_flags`=(`unit_flags` & ~(0x100|0x2000000)) WHERE `entry`=65471; -- remove UNIT_FLAG_IMMUNE_TO_PC and UNIT_FLAG_UNINTERACTIBLE (they are added after 20% hp is reached, not initially)

-- jaomin ro
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=450184; -- remove random movement

-- Amberleaf scamps
DELETE FROM `creature_template_addon` WHERE `entry`=54130; -- auras 109138 109139
UPDATE `creature` SET `MovementType`=0 WHERE `guid` IN(450041,450044,450051,450055,450056,450058,450059,450061,450062,450063,450071,450072,450074,450076,450079,450080,450081,450082,450084,450089,450091,450093,450094,450095,450096,450098,450100,450101,450102,450229,450233,450234,450237,450240,450241,450242,450245,450246,450247,450248,450249,450251,450252,450253,450254,450255,450256,450259,450260,450268,450269,450270,450271,450273,450274,450276,450284,450286,450287,450289,450291,450292,450296,450297,450298,450309,450310,450383,450384,450453); -- remove random movement

DELETE FROM `creature_addon` WHERE `guid` IN(450102, 450242, 450082);
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(450102, '109138 109139'),
(450242, '109138 109139'),
(450082, '109138 109139');

UPDATE `creature` SET `MovementType`=1 WHERE `guid` IN(450102, 450242, 450082);

-- duplicates
DELETE FROM `creature` WHERE `guid` IN(450101, 450259, 450260, 450080, 450274, 450249, 450270, 450252, 450246, 450269, 450271, 450276, 450273, 450079, 450058);

-- cartdriver
UPDATE `creature` SET `PhaseId`=630 WHERE `guid`=450352;
UPDATE `creature` SET `PhaseId`=629 WHERE `guid` IN(450295, 450248, 450268, 450247, 450251, 450245);

DELETE FROM `creature_addon` WHERE `guid` IN(450295, 450248, 450251, 450245, 450247, 450268);
INSERT INTO `creature_addon` (`guid`, `emote`) VALUES 
(450295, 512),
(450248, 27),
(450251, 27),
(450245, 27),
(450247, 27),
(450268, 27);

-- duplicate foxes
DELETE FROM `creature` WHERE `guid` IN(450356, 450050);

-- unnecessary troublemaker spawns
DELETE FROM `creature` WHERE `guid` IN(450362,450363,450364,450365,450366,450367,450368,450369,450370,450371,450372,450373,450374,450375,450376,450377);

-- duplicate Edict of Temperance
DELETE FROM `gameobject` WHERE `guid` IN(300077, 300081, 300082, 300084, 300085, 300087, 300205);

-- aysa
DELETE FROM `creature_template_movement` WHERE `CreatureId`=54567;
INSERT INTO `creature_template_movement` (`CreatureId`, `Flight`, `Rooted`) VALUES
(54567, 1, 1);

-- aysa in cave
UPDATE `creature` SET `PhaseId`=838 WHERE `guid` IN(450052, 450057, 450357, 450361, 450368);
