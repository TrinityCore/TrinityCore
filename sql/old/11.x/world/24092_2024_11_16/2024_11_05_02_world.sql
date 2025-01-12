-- Creature_templates
UPDATE `creature_template` SET `unit_flags3`=0x41000000 WHERE `entry`=51720; -- Wickerman Torch Point
UPDATE `creature_template` SET `unit_flags3`=0x41000000 WHERE `entry`=51703; -- Wickerman Crowd Bunny 02
UPDATE `creature_template` SET `unit_flags3`=0x41000000 WHERE `entry`=51702; -- Wickerman Crowd Bunny 01
UPDATE `creature_template` SET `unit_flags`=0x100 WHERE `entry`=54207; -- Dead Undercity Citizen
UPDATE `creature_template` SET `unit_flags`=0x100 WHERE `entry`=54169; -- Maxim the Sly
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=54043; -- Spider Summoner (Catacombs)

UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=51836; -- 51836 (Hag)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=51710; -- 51710 (Hag's Broom)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=53762; -- 53762 (Crone)
UPDATE `creature_template_addon` SET `PvpFlags`=1 WHERE `entry`=53761; -- 53761 (Crone's Broom)

UPDATE `waypoint_path` SET `Comment`='Wickerman Guardian - Cosmetic Path' WHERE `PathId`=1519500;
UPDATE `waypoint_path_node` SET `Delay`=10 WHERE `PathId`=1519500 AND `NodeId` IN (0,4);

-- Difficulties
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=57388 WHERE (`Entry`=40435 AND `DifficultyID`=0); -- 40435 (Headless Ghost) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=57388 WHERE (`Entry`=54207 AND `DifficultyID`=0); -- 54207 (Dead Undercity Citizen) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=57388 WHERE (`Entry`=54169 AND `DifficultyID`=0); -- 54169 (Maxim the Sly) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=57388 WHERE (`Entry`=53977 AND `DifficultyID`=0); -- 53977 (Darkcaller Yanka) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=57388 WHERE (`Entry`=53865 AND `DifficultyID`=0); -- 53865 (Orphan Matron Nanee) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=57388 WHERE (`Entry`=15197 AND `DifficultyID`=0); -- 15197 (Darkcaller Yanka) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10080000, `VerifiedBuild`=57388 WHERE (`Entry`=15195 AND `DifficultyID`=0); -- 15195 (Wickerman Guardian) - Amphibious, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=57388 WHERE (`Entry`=53762 AND `DifficultyID`=0); -- 53762 (Crone)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=57388 WHERE (`Entry`=51836 AND `DifficultyID`=0); -- 51836 (Hag)

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=57388 WHERE `entry` IN (209862, 191497, 191496, 191495, 191494, 191493, 191492, 191491, 191490, 191489, 191488, 191487, 191486, 186615, 186614, 175566, 1618, 293758, 293689, 202901, 202900, 293763, 205056, 202899, 1744, 1743, 105175, 105174, 212212, 195142, 58611, 58612, 208394, 180412, 190217, 184503, 180414, 208963, 58613, 259114, 207214, 52175, 40303, 58609, 208965, 195069, 180885, 195087, 37097, 209064, 209065, 209094, 180432, 180340, 101851, 101850, 208198, 182807, 180760, 180434, 195090, 208828, 195307, 195068, 195067, 195066, 195063, 180437, 180426, 58627, 34013, 113568, 113576, 52176, 36080, 36093, 58608, 36072, 58600, 190704, 177064, 36397, 58624, 58616, 204333, 98349, 205143, 176594, 77813, 58621, 36085, 36090, 136101, 58615, 58629, 36077, 58605, 58597, 170354, 98343, 58626, 98354, 36082, 204330, 36071, 113570, 113754, 58602, 36098, 58618, 36079, 113575, 36127, 98351, 153695, 58623, 58607, 36095, 58599, 58596, 33999, 177884, 36092, 113572, 204332, 58620, 288257, 34012, 36070, 113756, 98348, 58604, 177044, 36102, 204329, 113577, 33998, 58625, 36113, 113574, 36073, 36086, 113569, 58617, 113753, 98350, 58601, 36105, 36091, 204334, 58614, 175659, 58606, 170355, 175749, 267750, 180339, 180431, 3705, 175731, 175725, 186234, 180666, 267748, 208839, 212205, 244852, 187290, 3662, 180405, 267745, 208840, 267746, 180406, 180047, 267747, 180425, 193981, 207324, 208841, 205350, 244854, 180338, 180410, 180415, 208816, 175754, 267749, 180407, 208842, 208874, 208200, 103600, 267751, 180427, 175761, 205165, 208876, 267744, 20649, 20650, 20652, 58622, 58598, 36118, 36078, 36398, 113755, 36126, 36094, 20654, 20657, 58619, 20656, 20655, 204331, 36083, 20653, 58603, 36096, 98347, 20651, 113571, 113752);
UPDATE `gameobject_template` SET `displayId`=98398, `VerifiedBuild`=57388 WHERE `entry`=180428; -- G_WitchBroom_01 scale 0.5
UPDATE `gameobject_template` SET `displayId`=98398, `VerifiedBuild`=57388 WHERE `entry`=180409; -- G_WitchBroom_01
UPDATE `gameobject_template` SET `displayId`=98399, `VerifiedBuild`=57388 WHERE `entry`=180408; -- G_WitchHat_01
UPDATE `gameobject_template` SET `displayId`=98384, `VerifiedBuild`=57388 WHERE `entry`=190071; -- Candy Bucket
UPDATE `gameobject_template` SET `displayId`=98274, `VerifiedBuild`=57388 WHERE `entry`=180523; -- Apple Bob
UPDATE `gameobject_template` SET `displayId`=98401, `VerifiedBuild`=57388 WHERE `entry`=180433; -- The Wickerman
UPDATE `gameobject_template` SET `displayId`=98396, `VerifiedBuild`=57388 WHERE `entry`=180471; -- HangingSkullLight01
UPDATE `gameobject_template` SET `displayId`=98395, `VerifiedBuild`=57388 WHERE `entry`=180411; -- G_Ghost_01
UPDATE `gameobject_template` SET `displayId`=98397, `VerifiedBuild`=57388 WHERE `entry`=180472; -- HangingSkullLight02
UPDATE `gameobject_template` SET `VerifiedBuild`=57388 WHERE `entry` IN (290343, 290322, 142712, 2702, 290326, 144068, 278457, 142143, 141853, 204120, 1623, 204102, 142965, 2046, 153239, 203989, 205485, 205535, 181103, 208078, 208072, 208069, 208064, 176276, 208071, 181236, 208058, 245526, 181131, 181130, 176277, 278676, 176269, 405526, 180751, 406038, 191364, 207588, 207587, 207586, 207585, 207584, 207583, 207581, 207580, 207577, 206611, 207579, 207589, 207582, 207578, 176865, 176209, 205873, 175370, 176270, 175369, 177667, 207488, 142142, 165587, 212899, 205154, 205153, 176392, 203131, 180685, 180684, 2045, 2041, 206877, 206872, 206871, 206876, 204966, 1624, 205001, 170073, 22777, 22776, 22775, 22774, 22773, 22772, 3800, 3799, 2042, 1734, 174626, 2043, 1735, 208061, 208057, 177284, 288312, 208063, 176203, 288225, 176201, 288306, 177285, 288317, 288242, 176202, 176092, 102985, 1873, 1619, 1731, 186720, 295546, 104593, 210108, 210112, 1617, 175726, 210111, 210110, 210109, 206863, 206862, 278347, 206864, 206861, 295545, 202563, 175738);
UPDATE `gameobject_template` SET `displayId`=98384, `VerifiedBuild`=57388 WHERE `entry` IN (208148, 190108, 208156, 208149, 190066); -- Candy Bucket
UPDATE `gameobject_template` SET `displayId`=98399, `VerifiedBuild`=57388 WHERE `entry`=180429; -- G_WitchHat_01 scale 0.5
UPDATE `gameobject_template` SET `displayId`=98399, `VerifiedBuild`=57388 WHERE `entry`=207941; -- G_WitchHat_01 scale 2.0
UPDATE `gameobject_template` SET `displayId`=98395, `VerifiedBuild`=57388 WHERE `entry`=208056; -- G_Ghost_01 (Scale 0.5)
UPDATE `gameobject_template` SET `displayId`=0, `Data3`=0, `Data6`=0, `VerifiedBuild`=57388 WHERE `entry`=186249; -- Invisible Cooking Object

-- Quests
UPDATE `quest_details` SET `VerifiedBuild`=57388 WHERE `ID` IN (12139, 11449);

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=0, `CompletionText`='Have you dowsed any fires, $n?  The training area is west of Brill.', `VerifiedBuild`=57388 WHERE `ID`=11449; -- Fire Training
UPDATE `quest_request_items` SET `VerifiedBuild`=57388 WHERE `ID`=12139;

UPDATE `quest_offer_reward` SET `VerifiedBuild`=57388 WHERE `ID`=28972;
UPDATE `quest_offer_reward` SET `RewardText`='Well done, $n.  Children, take a good look at this $c.  Let $ghim:her; be a strong example to you.', `VerifiedBuild`=57388 WHERE `ID`=11449; -- Fire Training
UPDATE `quest_offer_reward` SET `RewardText`='The children love to watch heroes at their work.  It is my hope that, one day, each of these orphans will grow into a strong member of the Horde, and live their lives with pride and honor!$B$BAh, thoughts of such a fine fate brings mist to my eyes...', `VerifiedBuild`=57388 WHERE `ID`=11357; -- Masked Orphan Matron

-- Vendors
DELETE FROM `npc_vendor` WHERE (`entry`=53757 AND `item`=230042 AND `ExtendedCost`=3547 AND `type`=1) OR (`entry`=53757 AND `item`=230173 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=53757 AND `item`=226453 AND `ExtendedCost`=3546 AND `type`=1) OR (`entry`=53757 AND `item`=226427 AND `ExtendedCost`=3546 AND `type`=1) OR (`entry`=34382 AND `item`=208859 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(53757, 4, 230042, 0, 3547, 1, 0, 0, 57388), -- Prowler's Faded Shoulder Cape
(53757, 3, 230173, 0, 3545, 1, 0, 0, 57388), -- Ensemble: Prowler's Faded Headgear
(53757, 2, 226453, 0, 3546, 1, 0, 0, 57388), -- Patched Harvest Golem's Post
(53757, 1, 226427, 0, 3546, 1, 0, 0, 57388), -- Patched Harvester's Claw
(34382, 1, 208859, 0, 0, 1, 0, 0, 57388); -- Cliffside Wylderdrake: Day of the Dead Armor

UPDATE `npc_vendor` SET `slot`=26, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=204336 AND `ExtendedCost`=5797 AND `type`=1); -- Awakened Heirloom Armor Casing
UPDATE `npc_vendor` SET `slot`=25, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=187997 AND `ExtendedCost`=5797 AND `type`=1); -- Eternal Heirloom Armor Casing
UPDATE `npc_vendor` SET `slot`=24, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=167731 AND `ExtendedCost`=5797 AND `type`=1); -- Battle-Hardened Heirloom Armor Casing
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=151614 AND `ExtendedCost`=5797 AND `type`=1); -- Weathered Heirloom Armor Casing
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=122340 AND `ExtendedCost`=5797 AND `type`=1); -- Timeworn Heirloom Armor Casing
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=122338 AND `ExtendedCost`=5796 AND `type`=1); -- Ancient Heirloom Armor Casing
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=163045 AND `ExtendedCost`=3545 AND `type`=1); -- Headless Horseman's Hearthstone
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=151270 AND `ExtendedCost`=3545 AND `type`=1); -- Horse Tail Costume
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=151271 AND `ExtendedCost`=3545 AND `type`=1); -- Horse Head Costume
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=70722 AND `ExtendedCost`=3546 AND `type`=1); -- Little Wickerman
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=37011 AND `ExtendedCost`=3547 AND `type`=1); -- Magic Broom
UPDATE `npc_vendor` SET `slot`=15, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=37604 AND `ExtendedCost`=3404 AND `type`=1); -- Tooth Pick
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=37583 AND `ExtendedCost`=3404 AND `type`=1); -- G.N.E.R.D.S.
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=37584 AND `ExtendedCost`=3404 AND `type`=1); -- Soothing Spearmint Candy
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=37582 AND `ExtendedCost`=3404 AND `type`=1); -- Pyroblast Cinnamon Ball
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=37585 AND `ExtendedCost`=3404 AND `type`=1); -- Chewy Fel Taffy
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=151268 AND `ExtendedCost`=5339 AND `type`=1); -- Exquisite Costume Set: "Xavius"
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=138990 AND `ExtendedCost`=5339 AND `type`=1); -- Exquisite Costume Set: "Grommash"
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=128643 AND `ExtendedCost`=5339 AND `type`=1); -- Exquisite Costume Set: "Deathwing"
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=116828 AND `ExtendedCost`=5339 AND `type`=1); -- Exquisite Costume Set: "The Lich King"
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=33292 AND `ExtendedCost`=3546 AND `type`=1); -- Hallowed Helm
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=57388 WHERE (`entry`=53757 AND `item`=208735 AND `ExtendedCost`=3545 AND `type`=1); -- Bucket of Morbid Treats
UPDATE `npc_vendor` SET `VerifiedBuild`=57388 WHERE (`entry`=53756 AND `item`=139004 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=128644 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=128645 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=128646 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116854 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116853 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116851 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116850 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=116848 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20397 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20398 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20399 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20409 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20410 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20411 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20413 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53756 AND `item`=20414 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=49216 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=49215 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20573 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20574 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20568 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20567 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20572 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20571 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20570 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20569 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20564 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20563 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20566 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20565 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=49210 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=49212 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20391 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20392 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20561 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=20562 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=34003 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=34001 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=34002 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=34000 AND `ExtendedCost`=3404 AND `type`=1) OR (`entry`=53760 AND `item`=69195 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69194 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69193 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69192 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69190 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69189 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69188 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=53760 AND `item`=69187 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109688 AND `item`=139036 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109688 AND `item`=116812 AND `ExtendedCost`=3547 AND `type`=1) OR (`entry`=109688 AND `item`=116811 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109688 AND `item`=116810 AND `ExtendedCost`=3403 AND `type`=1) OR (`entry`=109688 AND `item`=151269 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109688 AND `item`=116801 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109688 AND `item`=116804 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109688 AND `item`=70908 AND `ExtendedCost`=3545 AND `type`=1) OR (`entry`=109688 AND `item`=33154 AND `ExtendedCost`=3545 AND `type`=1);
UPDATE `npc_vendor` SET `slot`=14, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=116890 AND `ExtendedCost`=0 AND `type`=1); -- "Santo's Sun" Contender's Costume
UPDATE `npc_vendor` SET `slot`=13, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=116891 AND `ExtendedCost`=0 AND `type`=1); -- "Snowy Owl" Contender's Costume
UPDATE `npc_vendor` SET `slot`=12, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=116856 AND `ExtendedCost`=0 AND `type`=1); -- "Blooming Rose" Contender's Costume
UPDATE `npc_vendor` SET `slot`=11, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=116889 AND `ExtendedCost`=0 AND `type`=1); -- "Purple Phantom" Contender's Costume
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=116888 AND `ExtendedCost`=0 AND `type`=1); -- "Night Demon" Contender's Costume
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=188689 AND `ExtendedCost`=0 AND `type`=1); -- Marigold Petal Offering Bowl
UPDATE `npc_vendor` SET `slot`=8, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=46861 AND `ExtendedCost`=0 AND `type`=1); -- Bouquet of Orange Marigolds
UPDATE `npc_vendor` SET `slot`=7, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=46710 AND `ExtendedCost`=0 AND `type`=1); -- Recipe: Bread of the Dead
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=79048 AND `ExtendedCost`=0 AND `type`=1); -- Whimsical Skull Mask
UPDATE `npc_vendor` SET `slot`=5, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=46860 AND `ExtendedCost`=0 AND `type`=1); -- Whimsical Skull Mask
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=46711 AND `ExtendedCost`=0 AND `type`=1); -- Spirit Candle
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=46718 AND `ExtendedCost`=0 AND `type`=1); -- Orange Marigold
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=57388 WHERE (`entry`=34382 AND `item`=46690 AND `ExtendedCost`=0 AND `type`=1); -- Candy Skull
