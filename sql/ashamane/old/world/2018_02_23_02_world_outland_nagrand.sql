DELETE FROM `gameobject_template_addon` WHERE `entry`=278575;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(278575, 12, 262144); -- Tableau de l’appel des héros

UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181557; -- Khorium Vein
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181271; -- Dreaming Glory
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=183294; -- The Shadow Labyrinth
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181555; -- Fel Iron Deposit
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181556; -- Adamantite Deposit
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181270; -- Felweed
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181570; -- Rich Adamantite Deposit

DELETE FROM `creature_template_addon` WHERE `entry` IN (115655 /*115655 (Ohme)*/, 121086 /*121086 (Shawn) - Poison mortel*/, 21488 /*21488 (Banro)*/, 20812 /*20812 (Corki)*/, 18208 /*18208 (Murkblood Event Controller)*/, 18204 /*18204 (Ortor of Murkblood)*/, 61325 /*Aspic*/, 22839 /*22839 (Outland Children's Week Throne of the Elements Trigger)*/, 66539 /*Prince Laverrue*/, 66537 /*Pas-Lourd*/, 66552 /*Narrok*/, 66538 /*Regarkitu*/, 18351 /*18351 (Lump) - Effet visuel personnel – Dormir jusqu’à l’annulation (DND)*/, 23268 /*23268 (Seer Jovar)*/, 18183 /*18183 (Arechron)*/, 18233 /*18233 (Elementalist Ioki)*/, 24866 /*24866 (Lakoor)*/, 24222 /*24222 (Windy Cloud)*/, 115647 /*115647 (Terra'gul)*/, 18684 /*18684 (Bro'Gaz the Clanless)*/, 62620 /*Sabot-fourchu chétif*/, 61141 /*Chien de prairie*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(115655, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115655 (Ohme)
(121086, 0, 0, 0, 1, 0, 0, 0, 0, '10022'), -- 121086 (Shawn) - Poison mortel
(21488, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 21488 (Banro)
(20812, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 20812 (Corki)
(18208, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18208 (Murkblood Event Controller)
(18204, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18204 (Ortor of Murkblood)
(61325, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Aspic
(22839, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 22839 (Outland Children's Week Throne of the Elements Trigger)
(66539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Prince Laverrue
(66537, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pas-Lourd
(66552, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Narrok
(66538, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Regarkitu
(18351, 0, 0, 3, 1, 0, 0, 0, 0, '16093'), -- 18351 (Lump) - Effet visuel personnel – Dormir jusqu’à l’annulation (DND)
(23268, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 23268 (Seer Jovar)
(18183, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 18183 (Arechron)
(18233, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18233 (Elementalist Ioki)
(24866, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 24866 (Lakoor)
(24222, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 24222 (Windy Cloud)
(115647, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 115647 (Terra'gul)
(18684, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 18684 (Bro'Gaz the Clanless)
(62620, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sabot-fourchu chétif
(61141, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Chien de prairie

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17545; -- 17545 (K'ure)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18660; -- 18660 (Subjugator Vaz'shir)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18658; -- 18658 (Kil'sorrow Ritualist)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=18662; -- 18662 (Orc Ancestor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18661; -- 18661 (Terrorguard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18411; -- 18411 (Durn the Hungerer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17981; -- 17981 (Voidspawn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17149; -- 17149 (Vir'aani Raider)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17150; -- 17150 (Vir'aani Arcanist)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18043; -- 18043 (Agitated Orc Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18590; -- 18590 (Forge Camp: Fear Quest Credit)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0, `auras`='19194' WHERE `entry`=18567; -- 18567 (Mo'arg Master Planner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19211; -- 19211 (Fel Cannon: Fear Target)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18536; -- 18536 (Xirkos, Overseer of Fear)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19210; -- 19210 (Fel Cannon: Fear)
UPDATE `creature_template_addon` SET `bytes2`=1, `emote`=0 WHERE `entry`=16945; -- 16945 (Mo'arg Engineer)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32008' WHERE `entry`=17152; -- 17152 (Felguard Legionnaire)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17151; -- 17151 (Gan'arg Tinkerer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21233; -- 21233 (Legion Fel Cannon)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18145; -- 18145 (Watoosun's Polluted Essence)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18264; -- 18264 (Nagrand Spawn Timer)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21485; -- 21485 (Aldraan)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=21487; -- 21487 (Cendrii)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18822; -- 18822 (Quartermaster Davian Vaclav)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18817; -- 18817 (Chief Researcher Kartos)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18256; -- 18256 (Alliance Halaani Guard)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17154; -- 17154 (Muck Spawn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17136; -- 17136 (Boulderfist Warrior)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17137; -- 17137 (Boulderfist Mage)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17155; -- 17155 (Lake Surger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18215; -- 18215 (Murkblood Target Dummy)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18210; -- 18210 (Mag'har Captive)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18840; -- 18840 (Sunspring Post Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18211; -- 18211 (Murkblood Brute)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=18209; -- 18209 (Kurenai Captive)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18202; -- 18202 (Murkblood Putrifier)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18203; -- 18203 (Murkblood Raider)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1, `auras`='31261' WHERE `entry`=18240; -- 18240 (Sunspring Villager)
UPDATE `creature_template_addon` SET `bytes1`=0, `bytes2`=1 WHERE `entry`=18207; -- 18207 (Murkblood Scavenger)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18414; -- 18414 (Elder Yorley)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18415; -- 18415 (Elder Ungriz)
UPDATE `creature_template_addon` SET `bytes2`=256 WHERE `entry`=18229; -- 18229 (Saurfang the Younger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18258; -- 18258 (Bach'lor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18440; -- 18440 (Warmaul Chef Bufferlo)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18444; -- 18444 (Corki Event Controller)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18445; -- 18445 (Corki)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18196; -- 18196 (Gurok Event Controller)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18428; -- 18428 (Mag'har Prisoner)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19201; -- 19201 (Mountain Gronn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18037; -- 18037 (Warmaul Warlock)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18065; -- 18065 (Warmaul Brute)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='3417' WHERE `entry`=18257; -- 18257 (Gutripper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17160; -- 17160 (Living Cyclone)
UPDATE `creature_template_addon` SET `bytes1`=7, `bytes2`=1, `auras`='29266' WHERE `entry`=17133; -- 17133 (Aged Clefthoof)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='3417' WHERE `entry`=17129; -- 17129 (Greater Windroc)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18069; -- 18069 (Mogor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18471; -- 18471 (Gurgthock)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22893; -- 22893 (Wodin the Troll-Servant)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18395; -- 18395 (Warmaul Pyre Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18841; -- 18841 (Laughing Skull Clan Ruins Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18393; -- 18393 (Warmaul Ogre Credit Marker)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18413; -- 18413 (Zorbo the Advisor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17138; -- 17138 (Warmaul Reaver)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18064; -- 18064 (Warmaul Shaman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18072; -- 18072 (Elementalist Sharvak)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18073; -- 18073 (Elementalist Lo'ap)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18071; -- 18071 (Elementalist Untrag)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18074; -- 18074 (Elementalist Morgh)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18100; -- 18100 (Incineratus)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18102; -- 18102 (Kalandrios)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18101; -- 18101 (Aborius)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='18943' WHERE `entry`=18099; -- 18099 (Gordawg)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22001; -- 22001 (Air Force Trip Wire - Rooftop (Horde))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21993; -- 21993 (Air Force Guard Post (Horde - Bat Rider))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18489; -- 18489 (Garadar Defender)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17153; -- 17153 (Lake Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19035; -- 19035 (Wazat)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19041; -- 19041 (Jump-a-tron 4000)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18354; -- 18354 (Lump's Quest Credit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18352; -- 18352 (Boulderfist Hunter)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19071; -- 19071 (Telaari Elekk Rider)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19014; -- 19014 (Ogir)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19021; -- 19021 (Nancila)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18408; -- 18408 (Warden Moi'bff Jill)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=19012; -- 19012 (Sparik)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19137; -- 19137 ("Shotgun" Jones)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18353; -- 18353 (Huntress Bintook)
UPDATE `creature_template_addon` SET `bytes2`=257, `emote`=0 WHERE `entry`=19141; -- 19141 (Kurenai Pitfighter)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19149; -- 19149 (Telaari Citizen)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19139; -- 19139 (Nagrand Target Dummy)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18416; -- 18416 (Huntress Kima)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=22003; -- 22003 (Air Force Trip Wire - Ground (Alliance))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19017; -- 19017 (Borto)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18222; -- 18222 (Otonbu the Sage)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18223; -- 18223 (Mo'mor the Breaker)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18224; -- 18224 (Poli'lukluk the Wiser)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21996; -- 21996 (Air Force Guard Post (Alliance - Gryphon))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=21999; -- 21999 (Air Force Trip Wire - Rooftop (Alliance))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19156; -- 19156 (Telaari Jailor)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19152; -- 19152 (Interrogator Khan)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20096; -- 20096 (Uriku)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18789; -- 18789 (Furgu)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20072; -- 20072 (Cobalt War Talbuk)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18914; -- 18914 (Caregiver Isel)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=19019; -- 19019 (Luftasia)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=20240; -- 20240 (Trader Narasu)
UPDATE `creature_template_addon` SET `bytes1`=3, `bytes2`=257, `auras`='16093' WHERE `entry`=19030; -- 19030 (Stabled Kurenai Panther)
UPDATE `creature_template_addon` SET `bytes1`=3, `bytes2`=257, `auras`='16093' WHERE `entry`=19027; -- 19027 (Stabled Kurenai Lion)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19151; -- 19151 (Captured Halaani Blood Knight)
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18488; -- 18488 (Telaari Watcher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17159; -- 17159 (Storm Rager)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17131; -- 17131 (Talbuk Thorngrazer)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17132; -- 17132 (Clefthoof Bull)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17157; -- 17157 (Shattered Rumbler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18062; -- 18062 (Enraged Crusher)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='16592' WHERE `entry`=18391; -- 18391 (Giselda the Crone)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18033; -- 18033 (Dark Worg)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19656; -- 19656 (Invisible Location Trigger)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18388; -- 18388 (Shadow Council Credit Marker)
UPDATE `creature_template_addon` SET `bytes1`=8, `bytes2`=1 WHERE `entry`=17146; -- 17146 (Kil'sorrow Spellbinder)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17148; -- 17148 (Kil'sorrow Deathsworn)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18305; -- 18305 (Burning Blade Pyre (01))
UPDATE `creature_template_addon` SET `bytes2`=257 WHERE `entry`=18369; -- 18369 (Corki)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18306; -- 18306 (Burning Blade Pyre (02))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18307; -- 18307 (Burning Blade Pyre (03))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18308; -- 18308 (Burning Blade Pyre (04))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17156; -- 17156 (Tortured Earth Spirit)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18205; -- 18205 (Clefthoof)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17158; -- 17158 (Dust Howler)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17135; -- 17135 (Boulderfist Mystic)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='32281' WHERE `entry`=18261; -- 18261 (Lantresor of the Blade)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17134; -- 17134 (Boulderfist Crusher)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19161; -- 19161 (Neophyte Combatant)
UPDATE `creature_template_addon` SET `bytes2`=1, `auras`='5301' WHERE `entry`=19687; -- 19687 (Shattrath City Peacekeeper)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17128; -- 17128 (Windroc)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17130; -- 17130 (Talbuk Stag)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18334; -- 18334 (Wild Elekk)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=18144; -- 18144 (Windyreed Quest Credit (Hut 03))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17141; -- 17141 (Windyreed Wretch)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=17139; -- 17139 (Windyreed Scavenger)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (17130, 17981, 17139, 17150, 17154, 18062, 16945, 17158, 17135, 17133, 18256, 17136, 17138, 17156, 18207, 18440, 18037, 18658, 18205, 23268, 18413, 18065, 17160, 17155, 18203, 17131, 24222, 18215, 17128, 17134, 18033, 21233, 18043, 18202, 19151, 18661, 17157, 17153, 18662, 18428, 17132, 12922, 18352, 17129, 18069, 17151, 17149, 17147, 18071, 18064, 17159, 18222, 17152, 18840, 18334, 18264, 17148, 17146, 18223, 18841, 17137, 18471, 18211, 19141, 19201, 18391, 18414, 20812, 18415, 17141, 18210, 66552, 18258, 18914, 18204, 19156, 18209, 18233, 18369, 19035, 19019, 18224, 18145, 121086, 115655, 19012, 19030, 18416, 115647, 20096, 18354, 22893, 18257, 18684, 18445, 18536, 18353, 20240, 19014, 18822, 19027, 18411, 19021, 18817, 18567, 19017, 18351, 17545, 18660, 18074);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(17130, 1, 25996),
(17981, 0, 25996),
(17139, 0, 25996),
(17150, 0, 25996),
(17154, 0, 25996),
(18062, 0, 25996),
(16945, -1, 25996),
(17158, 0, 25996),
(17135, 1, 25996),
(17133, 1, 25996),
(18256, 0, 25996),
(17136, -1, 25996),
(17138, 0, 25996),
(17156, 1, 25996),
(18207, 0, 25996),
(18440, 1, 25996),
(18037, 0, 25996),
(18658, 0, 25996),
(18205, 0, 25996),
(23268, 0, 25996),
(18413, 0, 25996),
(18065, 0, 25996),
(17160, 0, 25996),
(17155, 0, 25996),
(18203, -1, 25996),
(17131, 0, 25996),
(24222, 0, 25996),
(18215, 0, 25996),
(17128, 0, 25996),
(17134, 0, 25996),
(18033, -1, 25996),
(21233, 1, 25996),
(18043, -1, 25996),
(18202, 0, 25996),
(19151, 0, 25996),
(18661, 0, 25996),
(17157, 2, 25996),
(17153, 0, 25996),
(18662, 0, 25996),
(18428, 2, 25996),
(17132, 0, 25996),
(12922, 0, 25996),
(18352, 1, 25996),
(17129, -1, 25996),
(18069, 0, 25996),
(17151, 1, 25996),
(17149, 0, 25996),
(17147, 1, 25996),
(18071, 0, 25996),
(18064, 0, 25996),
(17159, -1, 25996),
(18222, 0, 25996),
(17152, 1, 25996),
(18840, 0, 25996),
(18334, 0, 25996),
(18264, 0, 25996),
(17148, 0, 25996),
(17146, -1, 25996),
(18223, 0, 25996),
(18841, 0, 25996),
(17137, 1, 25996),
(18471, 0, 25996),
(18211, 0, 25996),
(19141, 0, 25996),
(19201, 0, 25996),
(18391, 0, 25996),
(18414, 0, 25996),
(20812, 0, 25996),
(18415, 0, 25996),
(17141, -1, 25996),
(18210, 0, 25996),
(66552, 0, 25996),
(18258, 1, 25996),
(18914, 0, 25996),
(18204, 0, 25996),
(19156, 0, 25996),
(18209, 0, 25996),
(18233, 0, 25996),
(18369, 0, 25996),
(19035, 0, 25996),
(19019, 1, 25996),
(18224, 0, 25996),
(18145, 0, 25996),
(121086, 0, 25996),
(115655, 0, 25996),
(19012, 3, 25996),
(19030, -1, 25996),
(18416, 0, 25996),
(115647, 0, 25996),
(20096, 0, 25996),
(18354, 0, 25996),
(22893, 0, 25996),
(18257, 1, 25996),
(18684, 2, 25996),
(18445, 0, 25996),
(18536, 1, 25996),
(18353, 0, 25996),
(20240, 0, 25996),
(19014, 2, 25996),
(18822, 0, 25996),
(19027, 3, 25996),
(18411, 1, 25996),
(19021, 0, 25996),
(18817, 0, 25996),
(18567, 1, 25996),
(19017, 1, 25996),
(18351, 0, 25996),
(17545, 0, 25996),
(18660, 0, 25996),
(18074, 0, 25996);



UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18056;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18059;
UPDATE `creature_model_info` SET `BoundingRadius`=2.437281, `VerifiedBuild`=25996 WHERE `DisplayID`=17072;
UPDATE `creature_model_info` SET `BoundingRadius`=1.249467, `VerifiedBuild`=25996 WHERE `DisplayID`=17543;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18048;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18057;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18061;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18051;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18060;
UPDATE `creature_model_info` SET `BoundingRadius`=2.759334, `VerifiedBuild`=25996 WHERE `DisplayID`=18373;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18155;
UPDATE `creature_model_info` SET `BoundingRadius`=3.37817, `CombatReach`=7, `VerifiedBuild`=25996 WHERE `DisplayID`=75086;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18366;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18365;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20988;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17458;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17449;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17460;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17459;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=76088;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17612;
UPDATE `creature_model_info` SET `BoundingRadius`=6.003141, `VerifiedBuild`=25996 WHERE `DisplayID`=18370;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19668;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17880;
UPDATE `creature_model_info` SET `BoundingRadius`=3.075502, `VerifiedBuild`=25996 WHERE `DisplayID`=18646;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5047;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18288;
UPDATE `creature_model_info` SET `BoundingRadius`=2.676365, `VerifiedBuild`=25996 WHERE `DisplayID`=18505;
UPDATE `creature_model_info` SET `BoundingRadius`=4.16979, `VerifiedBuild`=25996 WHERE `DisplayID`=17535;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20313;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20314;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18241;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18235;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20315;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18257;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18256;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18255;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18254;
UPDATE `creature_model_info` SET `BoundingRadius`=1.042447, `VerifiedBuild`=25996 WHERE `DisplayID`=4907;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18356;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18333;
UPDATE `creature_model_info` SET `BoundingRadius`=1.198815, `VerifiedBuild`=25996 WHERE `DisplayID`=5562;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17593;
UPDATE `creature_model_info` SET `BoundingRadius`=1.24335, `VerifiedBuild`=25996 WHERE `DisplayID`=17594;
UPDATE `creature_model_info` SET `BoundingRadius`=1.24335, `VerifiedBuild`=25996 WHERE `DisplayID`=17595;
UPDATE `creature_model_info` SET `BoundingRadius`=1.16046, `VerifiedBuild`=25996 WHERE `DisplayID`=17586;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17592;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17624;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17623;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17590;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9117899, `VerifiedBuild`=25996 WHERE `DisplayID`=17583;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17621;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17591;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9117899, `VerifiedBuild`=25996 WHERE `DisplayID`=17584;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17622;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6216749, `VerifiedBuild`=25996 WHERE `DisplayID`=17589;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17768;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17769;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17611;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19223;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11536;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17788;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17791;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17789;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17790;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18645;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19909;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11576;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18383;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18404;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19581;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18378;
UPDATE `creature_model_info` SET `BoundingRadius`=1.675, `CombatReach`=2.5, `VerifiedBuild`=25996 WHERE `DisplayID`=47200;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17836;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12829;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17896;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11550;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18357;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11546;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17465;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17464;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17466;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17463;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=12129;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=15538;
UPDATE `creature_model_info` SET `BoundingRadius`=4.16979, `VerifiedBuild`=25996 WHERE `DisplayID`=13444;
UPDATE `creature_model_info` SET `BoundingRadius`=6.781233, `VerifiedBuild`=25996 WHERE `DisplayID`=17525;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18506;
UPDATE `creature_model_info` SET `BoundingRadius`=1.042447, `VerifiedBuild`=25996 WHERE `DisplayID`=5561;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=4626;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=5379;
UPDATE `creature_model_info` SET `BoundingRadius`=0.06, `CombatReach`=0.8, `VerifiedBuild`=25996 WHERE `DisplayID`=45618;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=45232;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2838;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17678;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18473;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10170;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11545;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036125, `VerifiedBuild`=25996 WHERE `DisplayID`=17956;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17560;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17616;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18462;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18469;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17763;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18460;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18536;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17690;
UPDATE `creature_model_info` SET `BoundingRadius`=1.16046, `VerifiedBuild`=25996 WHERE `DisplayID`=18538;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18549;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18553;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=16074;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17770;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=18464;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17602;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17603;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17604;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `VerifiedBuild`=25996 WHERE `DisplayID`=18571;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18561;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19333;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=22709;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9946799, `VerifiedBuild`=25996 WHERE `DisplayID`=18512;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18348;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9532348, `VerifiedBuild`=25996 WHERE `DisplayID`=18514;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18565;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5771584, `VerifiedBuild`=25996 WHERE `DisplayID`=19375;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18319;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18563;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18466;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=19497;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8745, `CombatReach`=1.65, `VerifiedBuild`=25996 WHERE `DisplayID`=599;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1977;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18564;
UPDATE `creature_model_info` SET `BoundingRadius`=1.036125, `VerifiedBuild`=25996 WHERE `DisplayID`=18513;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=22460;
UPDATE `creature_model_info` SET `BoundingRadius`=5, `CombatReach`=1.5, `VerifiedBuild`=25996 WHERE `DisplayID`=73907;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=10315;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19220;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1987;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1986;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19583;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1206;
UPDATE `creature_model_info` SET `BoundingRadius`=3.722398, `VerifiedBuild`=25996 WHERE `DisplayID`=14506;
UPDATE `creature_model_info` SET `BoundingRadius`=3.257098, `VerifiedBuild`=25996 WHERE `DisplayID`=14505;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18070;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=328;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17742;
UPDATE `creature_model_info` SET `BoundingRadius`=1.15, `CombatReach`=1.4375, `VerifiedBuild`=25996 WHERE `DisplayID`=741;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17966;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17957;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17964;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1418;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8288999, `VerifiedBuild`=25996 WHERE `DisplayID`=17705;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=2176;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17188;
UPDATE `creature_model_info` SET `BoundingRadius`=0.06, `CombatReach`=0.8, `VerifiedBuild`=25996 WHERE `DisplayID`=42575;
UPDATE `creature_model_info` SET `BoundingRadius`=2.419559, `VerifiedBuild`=25996 WHERE `DisplayID`=17461;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1072;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19582;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=1141;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=14503;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18354;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=11549;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18568;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18569;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18567;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20167;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=20168;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2186544, `VerifiedBuild`=25996 WHERE `DisplayID`=134;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=18377;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=19219;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17897;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=17200;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7246321, `VerifiedBuild`=25996 WHERE `DisplayID`=18350;
UPDATE `creature_model_info` SET `VerifiedBuild`=25996 WHERE `DisplayID`=901;
UPDATE `creature_model_info` SET `BoundingRadius`=0.6587565, `VerifiedBuild`=25996 WHERE `DisplayID`=18349;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=17149 AND `ID`=2) OR (`CreatureID`=121086 AND `ID`=1) OR (`CreatureID`=17136 AND `ID`=5) OR (`CreatureID`=17136 AND `ID`=4) OR (`CreatureID`=17136 AND `ID`=3) OR (`CreatureID`=17136 AND `ID`=2) OR (`CreatureID`=18240 AND `ID`=6) OR (`CreatureID`=18240 AND `ID`=5) OR (`CreatureID`=18240 AND `ID`=4) OR (`CreatureID`=18240 AND `ID`=3) OR (`CreatureID`=18240 AND `ID`=2) OR (`CreatureID`=18240 AND `ID`=1) OR (`CreatureID`=17138 AND `ID`=5) OR (`CreatureID`=17138 AND `ID`=4) OR (`CreatureID`=17138 AND `ID`=3) OR (`CreatureID`=17138 AND `ID`=2) OR (`CreatureID`=18489 AND `ID`=2) OR (`CreatureID`=18488 AND `ID`=4) OR (`CreatureID`=18488 AND `ID`=3) OR (`CreatureID`=18488 AND `ID`=2) OR (`CreatureID`=17147 AND `ID`=3) OR (`CreatureID`=17147 AND `ID`=2) OR (`CreatureID`=17139 AND `ID`=2);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(17149, 2, 2028, 0, 0, 10616, 0, 0, 0, 0, 0), -- Vir'aani Raider
(121086, 1, 6981, 0, 0, 6981, 0, 0, 0, 0, 0), -- Shawn
(17136, 5, 1899, 0, 0, 1895, 0, 0, 0, 0, 0), -- Boulderfist Warrior
(17136, 4, 1904, 0, 0, 1904, 0, 0, 0, 0, 0), -- Boulderfist Warrior
(17136, 3, 5282, 0, 0, 5282, 0, 0, 0, 0, 0), -- Boulderfist Warrior
(17136, 2, 1905, 0, 0, 1905, 0, 0, 0, 0, 0), -- Boulderfist Warrior
(18240, 6, 12868, 0, 0, 0, 0, 0, 0, 0, 0), -- Sunspring Villager
(18240, 5, 3362, 0, 0, 0, 0, 0, 0, 0, 0), -- Sunspring Villager
(18240, 4, 3346, 0, 0, 0, 0, 0, 0, 0, 0), -- Sunspring Villager
(18240, 3, 3351, 0, 0, 0, 0, 0, 0, 0, 0), -- Sunspring Villager
(18240, 2, 6233, 0, 0, 0, 0, 0, 0, 0, 0), -- Sunspring Villager
(18240, 1, 3367, 0, 0, 0, 0, 0, 0, 0, 0), -- Sunspring Villager
(17138, 5, 5289, 0, 0, 0, 0, 0, 0, 0, 0), -- Warmaul Reaver
(17138, 4, 5287, 0, 0, 0, 0, 0, 0, 0, 0), -- Warmaul Reaver
(17138, 3, 14475, 0, 0, 0, 0, 0, 0, 0, 0), -- Warmaul Reaver
(17138, 2, 5288, 0, 0, 0, 0, 0, 0, 0, 0), -- Warmaul Reaver
(18489, 2, 18062, 0, 0, 0, 0, 0, 5260, 0, 0), -- Garadar Defender
(18488, 4, 27852, 0, 0, 0, 0, 0, 0, 0, 0), -- Telaari Watcher
(18488, 3, 27850, 0, 0, 27851, 0, 0, 0, 0, 0), -- Telaari Watcher
(18488, 2, 27849, 0, 0, 27849, 0, 0, 0, 0, 0), -- Telaari Watcher
(17147, 3, 12742, 0, 0, 0, 0, 0, 0, 0, 0), -- Kil'sorrow Cultist
(17147, 2, 2717, 0, 0, 0, 0, 0, 0, 0, 0), -- Kil'sorrow Cultist
(17139, 2, 2023, 0, 0, 0, 0, 0, 5870, 0, 0); -- Windyreed Scavenger

UPDATE `creature_equip_template` SET `ItemID1`=1905, `ItemID2`=2558 WHERE (`CreatureID`=17136 AND `ID`=1); -- Boulderfist Warrior
UPDATE `creature_equip_template` SET `ItemID1`=14643 WHERE (`CreatureID`=17138 AND `ID`=1); -- Warmaul Reaver
UPDATE `creature_equip_template` SET `ItemID1`=17383 WHERE (`CreatureID`=18489 AND `ID`=1); -- Garadar Defender
UPDATE `creature_equip_template` SET `ItemID1`=27850, `ItemID2`=27851 WHERE (`CreatureID`=19071 AND `ID`=1); -- Telaari Elekk Rider
UPDATE `creature_equip_template` SET `ItemID1`=27850, `ItemID2`=27850 WHERE (`CreatureID`=18488 AND `ID`=1); -- Telaari Watcher
UPDATE `creature_equip_template` SET `ItemID1`=5292 WHERE (`CreatureID`=17134 AND `ID`=7); -- Boulderfist Crusher
UPDATE `creature_equip_template` SET `ItemID1`=17942 WHERE (`CreatureID`=17134 AND `ID`=6); -- Boulderfist Crusher
UPDATE `creature_equip_template` SET `ItemID1`=5293 WHERE (`CreatureID`=17134 AND `ID`=5); -- Boulderfist Crusher
UPDATE `creature_equip_template` SET `ItemID1`=5301 WHERE (`CreatureID`=17134 AND `ID`=3); -- Boulderfist Crusher
UPDATE `creature_equip_template` SET `ItemID1`=5491 WHERE (`CreatureID`=17134 AND `ID`=2); -- Boulderfist Crusher
UPDATE `creature_equip_template` SET `ItemID1`=6256 WHERE (`CreatureID`=17139 AND `ID`=1); -- Windyreed Scavenger


UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `npcflag`=0, `speed_run`=1.142857 WHERE `entry`=17545; -- K'ure
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18660; -- Subjugator Vaz'shir
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18658; -- Kil'sorrow Ritualist
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18662; -- Orc Ancestor
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18661; -- Terrorguard
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=18411; -- Durn the Hungerer
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=110, `faction`=14, `speed_walk`=2, `speed_run`=2.142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115655; -- Ohme
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17981; -- Voidspawn
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17149; -- Vir'aani Raider
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17150; -- Vir'aani Arcanist
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18043; -- Agitated Orc Spirit
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=121086; -- Shawn
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=18567; -- Mo'arg Master Planner
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=1 WHERE `entry`=19211; -- Fel Cannon: Fear Target
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=18536; -- Xirkos, Overseer of Fear
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags3`=1 WHERE `entry`=19210; -- Fel Cannon: Fear
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=16945; -- Mo'arg Engineer
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17152; -- Felguard Legionnaire
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=17151; -- Gan'arg Tinkerer
UPDATE `creature_template` SET `minlevel`=58, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=21233; -- Legion Fel Cannon
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18145; -- Watoosun's Polluted Essence
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18264; -- Nagrand Spawn Timer
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=18822; -- Quartermaster Davian Vaclav
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=18817; -- Chief Researcher Kartos
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=21488; -- Banro
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags2`=2097152 WHERE `entry`=18256; -- Alliance Halaani Guard
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=17154; -- Muck Spawn
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20812; -- Corki
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=17136; -- Boulderfist Warrior
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17137; -- Boulderfist Mage
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857, `RangeAttackTime`=2000 WHERE `entry`=17155; -- Lake Surger
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18215; -- Murkblood Target Dummy
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `npcflag`=0 WHERE `entry`=18210; -- Mag'har Captive
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18840; -- Sunspring Post Credit Marker
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18211; -- Murkblood Brute
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18204; -- Ortor of Murkblood
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `npcflag`=0, `speed_run`=1.142857 WHERE `entry`=18209; -- Kurenai Captive
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18202; -- Murkblood Putrifier
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18203; -- Murkblood Raider
UPDATE `creature_template` SET `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=18240; -- Sunspring Villager
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18207; -- Murkblood Scavenger
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=18414; -- Elder Yorley
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=18415; -- Elder Ungriz
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18229; -- Saurfang the Younger
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=18258; -- Bach'lor
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18440; -- Warmaul Chef Bufferlo
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18445; -- Corki
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18428; -- Mag'har Prisoner
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=19201; -- Mountain Gronn
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18037; -- Warmaul Warlock
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18065; -- Warmaul Brute
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=18257; -- Gutripper
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17160; -- Living Cyclone
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags`=537133824, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=17133; -- Aged Clefthoof
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=17129; -- Greater Windroc
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18069; -- Mogor
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=18471; -- Gurgthock
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=22893; -- Wodin the Troll-Servant
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18841; -- Laughing Skull Clan Ruins Credit Marker
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18413; -- Zorbo the Advisor
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17138; -- Warmaul Reaver
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18064; -- Warmaul Shaman
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=61325; -- Aspic
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=18072; -- Elementalist Sharvak
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=18073; -- Elementalist Lo'ap
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=18071; -- Elementalist Untrag
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18074; -- Elementalist Morgh
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18100; -- Incineratus
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18102; -- Kalandrios
UPDATE `creature_template` SET `unit_flags2`=2099200 WHERE `entry`=18101; -- Aborius
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags2`=2099200 WHERE `entry`=18099; -- Gordawg
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22001; -- Air Force Trip Wire - Rooftop (Horde)
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=21993; -- Air Force Guard Post (Horde - Bat Rider)
UPDATE `creature_template` SET `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=17153; -- Lake Spirit
UPDATE `creature_template` SET `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66539; -- Prince Laverrue
UPDATE `creature_template` SET `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66537; -- Pas-Lourd
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=1500, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=66552; -- Narrok
UPDATE `creature_template` SET `speed_run`=0.8571429, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66538; -- Regarkitu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=19035; -- Wazat
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18354; -- Lump's Quest Credit
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000, `unit_flags`=0, `unit_flags2`=2099200 WHERE `entry`=18351; -- Lump
UPDATE `creature_template` SET `maxlevel`=80, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=18352; -- Boulderfist Hunter
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=23268; -- Seer Jovar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=18183; -- Arechron
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18233; -- Elementalist Ioki
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19014; -- Ogir
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=19021; -- Nancila
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=18408; -- Warden Moi'bff Jill
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19012; -- Sparik
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19137; -- "Shotgun" Jones
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=18353; -- Huntress Bintook
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19141; -- Kurenai Pitfighter
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=68 WHERE `entry`=19149; -- Telaari Citizen
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `unit_flags3`=1 WHERE `entry`=19139; -- Nagrand Target Dummy
UPDATE `creature_template` SET `gossip_menu_id`=0, `maxlevel`=80 WHERE `entry`=18416; -- Huntress Kima
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=22003; -- Air Force Trip Wire - Ground (Alliance)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19017; -- Borto
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18222; -- Otonbu the Sage
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18223; -- Mo'mor the Breaker
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=18224; -- Poli'lukluk the Wiser
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70 WHERE `entry`=21999; -- Air Force Trip Wire - Rooftop (Alliance)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=19156; -- Telaari Jailor
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=20096; -- Uriku
UPDATE `creature_template` SET `gossip_menu_id`=0, `speed_run`=1.142857 WHERE `entry`=24866; -- Lakoor
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=110, `maxlevel`=110 WHERE `entry`=18789; -- Furgu
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80 WHERE `entry`=18914; -- Caregiver Isel
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `npcflag`=4194433 WHERE `entry`=19019; -- Luftasia
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_run`=1.142857 WHERE `entry`=20240; -- Trader Narasu
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=19030; -- Stabled Kurenai Panther
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61369; -- Crapaud
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=19027; -- Stabled Kurenai Lion
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=19151; -- Captured Halaani Blood Knight
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=18488; -- Telaari Watcher
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags2`=2099200 WHERE `entry`=24222; -- Windy Cloud
UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=110, `faction`=16, `speed_walk`=1.2, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=115647; -- Terra'gul
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17159; -- Storm Rager
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=17131; -- Talbuk Thorngrazer
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags`=0 WHERE `entry`=17132; -- Clefthoof Bull
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=3300; -- Adder
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_walk`=1 WHERE `entry`=17157; -- Shattered Rumbler
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `speed_walk`=1, `unit_flags`=0 WHERE `entry`=18062; -- Enraged Crusher
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `faction`=45, `unit_flags`=32832 WHERE `entry`=18684; -- Bro'Gaz the Clanless
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=18391; -- Giselda the Crone
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=18033; -- Dark Worg
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=19656; -- Invisible Location Trigger
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17146; -- Kil'sorrow Spellbinder
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80 WHERE `entry`=17147; -- Kil'sorrow Cultist
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=17148; -- Kil'sorrow Deathsworn
UPDATE `creature_template` SET `minlevel`=38, `maxlevel`=38, `unit_flags3`=1 WHERE `entry`=18305; -- Burning Blade Pyre (01)
UPDATE `creature_template` SET `gossip_menu_id`=0, `minlevel`=64, `maxlevel`=80, `faction`=1722, `speed_run`=1.142857 WHERE `entry`=18369; -- Corki
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=1 WHERE `entry`=18306; -- Burning Blade Pyre (02)
UPDATE `creature_template` SET `npcflag`=1073741824, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61366; -- Rat
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `unit_flags3`=1 WHERE `entry`=18307; -- Burning Blade Pyre (03)
UPDATE `creature_template` SET `minlevel`=3, `maxlevel`=3, `unit_flags3`=1 WHERE `entry`=18308; -- Burning Blade Pyre (04)
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62620; -- Sabot-fourchu chétif
UPDATE `creature_template` SET `faction`=31, `npcflag`=1073741824, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=61141; -- Chien de prairie
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1, `unit_flags`=0 WHERE `entry`=17156; -- Tortured Earth Spirit
UPDATE `creature_template` SET `faction`=31, `unit_flags`=0 WHERE `entry`=2620; -- Prairie Dog
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=18205; -- Clefthoof
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=17158; -- Dust Howler
UPDATE `creature_template` SET `maxlevel`=80 WHERE `entry`=17135; -- Boulderfist Mystic
UPDATE `creature_template` SET `gossip_menu_id`=0, `RangeAttackTime`=2000 WHERE `entry`=18261; -- Lantresor of the Blade
UPDATE `creature_template` SET `maxlevel`=80, `RangeAttackTime`=2000 WHERE `entry`=17134; -- Boulderfist Crusher
UPDATE `creature_template` SET `unit_flags2`=0 WHERE `entry`=19161; -- Neophyte Combatant
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=19687; -- Shattrath City Peacekeeper
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=17128; -- Windroc
UPDATE `creature_template` SET `maxlevel`=80, `unit_flags`=0 WHERE `entry`=17130; -- Talbuk Stag
UPDATE `creature_template` SET `minlevel`=64, `maxlevel`=80, `unit_flags`=32768 WHERE `entry`=18334; -- Wild Elekk
UPDATE `creature_template` SET `faction`=35, `unit_flags`=33555200 WHERE `entry`=18144; -- Windyreed Quest Credit (Hut 03)
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1 WHERE `entry`=17141; -- Windyreed Wretch
UPDATE `creature_template` SET `maxlevel`=80, `speed_walk`=1 WHERE `entry`=17139; -- Windyreed Scavenger


UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18660; -- Subjugator Vaz'shir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17545; -- K'ure
UPDATE `creature_template` SET `type`=6, `VerifiedBuild`=25996 WHERE `entry`=18662; -- Orc Ancestor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18658; -- Kil'sorrow Ritualist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18661; -- Terrorguard
UPDATE `creature_template` SET `type`=5, `VerifiedBuild`=25996 WHERE `entry`=18411; -- Durn the Hungerer
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=4, `type_flags`=2147483712, `HealthModifier`=3, `movementId`=191, `VerifiedBuild`=25996 WHERE `entry`=115655; -- Ohme
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17981; -- Voidspawn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17149; -- Vir'aani Raider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17150; -- Vir'aani Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18043; -- Agitated Orc Spirit
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=7, `HealthModifier`=10, `VerifiedBuild`=25996 WHERE `entry`=121086; -- Shawn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18590; -- Forge Camp: Fear Quest Credit
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18567; -- Mo'arg Master Planner
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19211; -- Fel Cannon: Fear Target
UPDATE `creature_template` SET `type_flags`=2147483648, `VerifiedBuild`=25996 WHERE `entry`=19210; -- Fel Cannon: Fear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18536; -- Xirkos, Overseer of Fear
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=16945; -- Mo'arg Engineer
UPDATE `creature_template` SET `modelid1`=5047, `VerifiedBuild`=25996 WHERE `entry`=17152; -- Felguard Legionnaire
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17151; -- Gan'arg Tinkerer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21233; -- Legion Fel Cannon
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18145; -- Watoosun's Polluted Essence
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21485; -- Aldraan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18264; -- Nagrand Spawn Timer
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18822; -- Quartermaster Davian Vaclav
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18817; -- Chief Researcher Kartos
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21488; -- Banro
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21487; -- Cendrii
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=15384; -- OLDWorld Trigger (DO NOT DELETE)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18256; -- Alliance Halaani Guard
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17154; -- Muck Spawn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20812; -- Corki
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17137; -- Boulderfist Mage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17136; -- Boulderfist Warrior
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17155; -- Lake Surger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18215; -- Murkblood Target Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18208; -- Murkblood Event Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18210; -- Mag'har Captive
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18209; -- Kurenai Captive
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18204; -- Ortor of Murkblood
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18840; -- Sunspring Post Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18211; -- Murkblood Brute
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=18240; -- Sunspring Villager
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18207; -- Murkblood Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18202; -- Murkblood Putrifier
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18203; -- Murkblood Raider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18415; -- Elder Ungriz
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18414; -- Elder Yorley
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18229; -- Saurfang the Younger
UPDATE `creature_template` SET `family`=151, `type_flags`=2147483649, `VerifiedBuild`=25996 WHERE `entry`=18258; -- Bach'lor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18445; -- Corki
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18444; -- Corki Event Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18440; -- Warmaul Chef Bufferlo
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18196; -- Gurok Event Controller
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18428; -- Mag'har Prisoner
UPDATE `creature_template` SET `type`=5, `VerifiedBuild`=25996 WHERE `entry`=19201; -- Mountain Gronn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=12922; -- Imp Minion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18065; -- Warmaul Brute
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18037; -- Warmaul Warlock
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18257; -- Gutripper
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17160; -- Living Cyclone
UPDATE `creature_template` SET `family`=43, `type_flags`=65537, `VerifiedBuild`=25996 WHERE `entry`=17133; -- Aged Clefthoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17129; -- Greater Windroc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22893; -- Wodin the Troll-Servant
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18471; -- Gurgthock
UPDATE `creature_template` SET `modelid1`=47200, `VerifiedBuild`=25996 WHERE `entry`=18069; -- Mogor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18395; -- Warmaul Pyre Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18841; -- Laughing Skull Clan Ruins Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18393; -- Warmaul Ogre Credit Marker
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18413; -- Zorbo the Advisor
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=17138; -- Warmaul Reaver
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=18064; -- Warmaul Shaman
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61325; -- Aspic
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=22839; -- Outland Children's Week Throne of the Elements Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18074; -- Elementalist Morgh
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18073; -- Elementalist Lo'ap
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18072; -- Elementalist Sharvak
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18071; -- Elementalist Untrag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18100; -- Incineratus
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18102; -- Kalandrios
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18101; -- Aborius
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18099; -- Gordawg
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=22001; -- Air Force Trip Wire - Rooftop (Horde)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21993; -- Air Force Guard Post (Horde - Bat Rider)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2615; -- Air Force Alarm Bot (Horde)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18489; -- Garadar Defender
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17153; -- Lake Spirit
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `VerifiedBuild`=25996 WHERE `entry`=66552; -- Narrok
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66539; -- Prince Laverrue
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66538; -- Regarkitu
UPDATE `creature_template` SET `HealthScalingExpansion`=1, `type`=12, `movementId`=121, `VerifiedBuild`=25996 WHERE `entry`=66537; -- Pas-Lourd
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19035; -- Wazat
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19041; -- Jump-a-tron 4000
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18354; -- Lump's Quest Credit
UPDATE `creature_template` SET `KillCredit2`=0, `VerifiedBuild`=25996 WHERE `entry`=18351; -- Lump
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=721; -- Lapin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18352; -- Boulderfist Hunter
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=23268; -- Seer Jovar
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18233; -- Elementalist Ioki
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18183; -- Arechron
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19071; -- Telaari Elekk Rider
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19014; -- Ogir
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19021; -- Nancila
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19012; -- Sparik
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19137; -- "Shotgun" Jones
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18408; -- Warden Moi'bff Jill
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18353; -- Huntress Bintook
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=22003; -- Air Force Trip Wire - Ground (Alliance)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19149; -- Telaari Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19141; -- Kurenai Pitfighter
UPDATE `creature_template` SET `type_flags2`=8192, `VerifiedBuild`=25996 WHERE `entry`=19139; -- Nagrand Target Dummy
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18416; -- Huntress Kima
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=19017; -- Borto
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18224; -- Poli'lukluk the Wiser
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18223; -- Mo'mor the Breaker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18222; -- Otonbu the Sage
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24866; -- Lakoor
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19156; -- Telaari Jailor
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25996 WHERE `entry`=18789; -- Furgu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20096; -- Uriku
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=21999; -- Air Force Trip Wire - Rooftop (Alliance)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=21996; -- Air Force Guard Post (Alliance - Gryphon)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19152; -- Interrogator Khan
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=2614; -- Air Force Alarm Bot (Alliance)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20240; -- Trader Narasu
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=20072; -- Cobalt War Talbuk
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19030; -- Stabled Kurenai Panther
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19027; -- Stabled Kurenai Lion
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19019; -- Luftasia
UPDATE `creature_template` SET `type`=7, `VerifiedBuild`=25996 WHERE `entry`=18914; -- Caregiver Isel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19151; -- Captured Halaani Blood Knight
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61369; -- Crapaud
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18488; -- Telaari Watcher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=24222; -- Windy Cloud
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `type`=4, `type_flags`=2147483656, `HealthModifier`=3, `movementId`=165, `VerifiedBuild`=25996 WHERE `entry`=115647; -- Terra'gul
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17159; -- Storm Rager
UPDATE `creature_template` SET `family`=151, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=17131; -- Talbuk Thorngrazer
UPDATE `creature_template` SET `family`=43, `type_flags`=65537, `VerifiedBuild`=25996 WHERE `entry`=17132; -- Clefthoof Bull
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=3300; -- Adder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17157; -- Shattered Rumbler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18062; -- Enraged Crusher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18684; -- Bro'Gaz the Clanless
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=61081; -- Ecureuil
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=61080; -- Lapin
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18033; -- Dark Worg
UPDATE `creature_template` SET `type_flags`=2147483648, `HealthModifier`=2, `VerifiedBuild`=25996 WHERE `entry`=18391; -- Giselda the Crone
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=19656; -- Invisible Location Trigger
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18388; -- Shadow Council Credit Marker
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17146; -- Kil'sorrow Spellbinder
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17147; -- Kil'sorrow Cultist
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17148; -- Kil'sorrow Deathsworn
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18369; -- Corki
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18305; -- Burning Blade Pyre (01)
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=18306; -- Burning Blade Pyre (02)
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61366; -- Rat
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=18307; -- Burning Blade Pyre (03)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18308; -- Burning Blade Pyre (04)
UPDATE `creature_template` SET `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=62620; -- Sabot-fourchu chétif
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `movementId`=100, `VerifiedBuild`=25996 WHERE `entry`=61141; -- Chien de prairie
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17156; -- Tortured Earth Spirit
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25996 WHERE `entry`=2620; -- Prairie Dog
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18261; -- Lantresor of the Blade
UPDATE `creature_template` SET `family`=43, `type_flags`=65537, `VerifiedBuild`=25996 WHERE `entry`=18205; -- Clefthoof
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17158; -- Dust Howler
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17135; -- Boulderfist Mystic
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17134; -- Boulderfist Crusher
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=1412; -- Squirrel
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17128; -- Windroc
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18334; -- Wild Elekk
UPDATE `creature_template` SET `family`=151, `type_flags`=1, `VerifiedBuild`=25996 WHERE `entry`=17130; -- Talbuk Stag
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=18144; -- Windyreed Quest Credit (Hut 03)
UPDATE `creature_template` SET `VerifiedBuild`=25996 WHERE `entry`=17141; -- Windyreed Wretch

DELETE FROM `creature_questitem` WHERE (`CreatureEntry`=115655 AND `Idx`=0) OR (`CreatureEntry`=115647 AND `Idx`=0);
INSERT INTO `creature_questitem` (`CreatureEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(115655, 0, 142271, 25996), -- Ohme
(115647, 0, 142269, 25996); -- Terra'gul

UPDATE `creature_questitem` SET `ItemId`=35229, `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18258 AND `Idx`=0); -- Bach'lor
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=17133 AND `Idx`=0); -- Aged Clefthoof
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=17131 AND `Idx`=0); -- Talbuk Thorngrazer
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=17132 AND `Idx`=0); -- Clefthoof Bull
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18033 AND `Idx`=0); -- Dark Worg
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18205 AND `Idx`=0); -- Clefthoof
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=18334 AND `Idx`=0); -- Wild Elekk
UPDATE `creature_questitem` SET `VerifiedBuild`=25996 WHERE (`CreatureEntry`=17130 AND `Idx`=0); -- Talbuk Stag

DELETE FROM `gameobject_template` WHERE `entry`=278575;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(278575, 10, 47195, 'Hero''s Call Board', '', '', '', 1, 2824, 0, 0, 0, 0, 0, 0, 0, 0, 0, 261654, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 25996); -- Tableau de l’appel des héros

UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182258; -- Oshu'gun Crystal Fragment
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184317; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183158; -- Fel Cannon Base
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182958; -- Mudfish School
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183180; -- Cookpot
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182305; -- Bomb Wagon
UPDATE `gameobject_template` SET `Data3`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182301; -- Wyvern Roost
UPDATE `gameobject_template` SET `Data3`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182300; -- Destroyed Wyvern Roost
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182210; -- Halaa Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183882; -- Bonfire
UPDATE `gameobject_template` SET `Data3`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182299; -- Destroyed Wyvern Roost
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182265; -- Bleeding Hollow Supply Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183883; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182959; -- Bluefish School
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181452; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181446; -- Bonfire
UPDATE `gameobject_template` SET `Data3`=1, `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182302; -- Wyvern Roost
UPDATE `gameobject_template` SET `Data26`=1, `VerifiedBuild`=25996 WHERE `entry`=182306; -- Bomb Wagon
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181450; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181767; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181456; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181453; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181455; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181451; -- Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183204; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182519; -- Bufferlo's Crock Pot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182182; -- Earthen Brand
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181311; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181312; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182146; -- Hut Fire (Large)
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182520; -- Telaar Supply Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181659; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181657; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182369; -- Blazing Warmaul Pyre
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181655; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181660; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181658; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181427; -- Ogre Firepit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181656; -- Bonfire
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182504; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182488; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182487; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182484; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182486; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182491; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182494; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182492; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182490; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182489; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182499; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182497; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182493; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182498; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182502; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182500; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182495; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182521; -- Corki's Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182503; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182501; -- Warmaul Prison
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182496; -- Warmaul Prison
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=182128; -- Dung
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182951; -- Pure Water
UPDATE `gameobject_template` SET `type`=50, `Data0`=38, `Data3`=0, `Data4`=400, `Data5`=450, `Data6`=30, `Data12`=75, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181557; -- Khorium Vein
UPDATE `gameobject_template` SET `Data10`=1, `VerifiedBuild`=25996 WHERE `entry`=182350; -- Corki's Prison
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184645; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183195; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183193; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183196; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183194; -- Burning Brazier
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183197; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183198; -- Cooking Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184647; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183265; -- Bonfire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183147; -- Mysterious Egg
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183821; -- Stewpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183146; -- Jump-a-tron 4000
UPDATE `gameobject_template` SET `castBarCaption`='Collecting', `VerifiedBuild`=25996 WHERE `entry`=182599; -- Telaari Frond
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184303; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183218; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182393; -- Telaar Bulletin Board
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=185136; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182955; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183272; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183271; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183273; -- Cookpot
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182161; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182160; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182158; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182157; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182156; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182162; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182159; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182155; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3933; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3930; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3928; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=408, `VerifiedBuild`=25996 WHERE `entry`=3916; -- Burning Embers
UPDATE `gameobject_template` SET `displayId`=408, `VerifiedBuild`=25996 WHERE `entry`=3914; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3844; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3843; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3842; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3841; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3840; -- Burning Embers
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3923; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=408, `VerifiedBuild`=25996 WHERE `entry`=3918; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3845; -- Burning Embers
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3922; -- Blazing Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=3839; -- Burning Embers
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3924; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=654, `VerifiedBuild`=25996 WHERE `entry`=3929; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3931; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3932; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=408, `VerifiedBuild`=25996 WHERE `entry`=3921; -- Burning Embers
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3934; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3927; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3926; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3925; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=408, `VerifiedBuild`=25996 WHERE `entry`=3920; -- Burning Embers
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3915; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=201, `VerifiedBuild`=25996 WHERE `entry`=3913; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=654, `VerifiedBuild`=25996 WHERE `entry`=3912; -- Blazing Fire
UPDATE `gameobject_template` SET `displayId`=408, `VerifiedBuild`=25996 WHERE `entry`=174953; -- Burning Embers
UPDATE `gameobject_template` SET `displayId`=408, `VerifiedBuild`=25996 WHERE `entry`=3919; -- Burning Embers
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=184741; -- Dented Footlocker
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182355; -- Kil'sorrow Armaments
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183294; -- The Shadow Labyrinth
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=340, `Data5`=390, `Data6`=30, `Data7`=0, `Data12`=59, `Data13`=1, `Data14`=28694, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181271; -- Dreaming Glory
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182263; -- First Burning Blade Pyre
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182261; -- First Burning Blade Pyre
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=181387; -- Ogre Firepit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182264; -- Second Burning Blade Pyre
UPDATE `gameobject_template` SET `type`=50, `Data0`=38, `Data3`=0, `Data4`=275, `Data5`=325, `Data6`=30, `Data12`=60, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181555; -- Fel Iron Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=182262; -- Third Burning Blade Pyre
UPDATE `gameobject_template` SET `type`=50, `Data0`=38, `Data3`=0, `Data4`=350, `Data5`=400, `Data6`=30, `Data12`=65, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181556; -- Adamantite Deposit
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183439; -- Campfire
UPDATE `gameobject_template` SET `type`=50, `Data0`=29, `Data3`=0, `Data4`=325, `Data5`=375, `Data6`=30, `Data12`=62, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181270; -- Felweed
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183783; -- Anvil
UPDATE `gameobject_template` SET `VerifiedBuild`=25996 WHERE `entry`=183782; -- Forge
UPDATE `gameobject_template` SET `type`=50, `Data0`=38, `Data3`=0, `Data4`=375, `Data5`=425, `Data6`=30, `Data12`=70, `Data13`=1, `Data18`=10, `Data19`=0, `VerifiedBuild`=25996 WHERE `entry`=181570; -- Rich Adamantite Deposit


UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182265 AND `Idx`=0); -- Bleeding Hollow Supply Crate
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182520 AND `Idx`=0); -- Telaar Supply Crate
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182128 AND `Idx`=0); -- Dung
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182599 AND `Idx`=0); -- Telaari Frond
UPDATE `gameobject_questitem` SET `VerifiedBuild`=25996 WHERE (`GameObjectEntry`=182355 AND `Idx`=0); -- Kil'sorrow Armaments

